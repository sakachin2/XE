//*CID://+vbBxR~:                              update#=  854;      //+vbBxR~
//*************************************************************
//*XE.c*                                                           //~v641R~
//*************************************************************
//vbBx:241128 xe help correct                                      //+vbBxI~
//vbBt:241114 add /ebc;defaultmapeuro                              //~vbBtI~
//vbBs:241114 del vbB9(process cp931(cp300+cp037)) because m2b from sjis generates 0e0f dbcs word for byte of sjis 1st byte whichi is byte of iso-8859.//~vbBsI~
//vbBe:241005 assume /ebccfg=no when /ebc:cvtype is specified      //~vbBeI~
//vbBd:240923 change cp931(not exist in icu) to CP939L(cp300+cp037)//~vbBdI~
//vbBc:240910 support ebcidic cfg file cmdline parameter           //~vbBcI~
//vbB9:240824 add cp931(cp300+cp037)                               //~vbB9I~
//vbB8:240823 change ebc option parm /EBC[:]{kana|eng|Latin|CP930|CP939|CP037}//~vbB8I~
//vbB6:240818 add cmdline parm for ext_eng(ext_kana is default)    //~vbB6I~
//vbB5:240816 trap if UTRACE ON; xewd change to c:\ from c:\users\sakStyle//~vbB5I~
//vbAn:240627 for performance bypass glyphchk when help            //~vbAnI~
//vbzZ:240503 LNX:del vbzY because wcwidth()=1 is same as -G1      //~vbzZI~
//vbzY:240503 LNX:use wcwidth() for ambiguous when -gN and allow specification to ambig lang//~vbzyI~//~vbzYR~
//vbzx:240425 Win:related vbq6 set default debugmode:skip on, relese mode skip off(seteh);//~vbzxI~
//vbzL:240406 print pid at term to chk utrace name                 //~vbzLI~
//vbzK:240404 change default /Nn to Yn                             //~vbzKI~
//vbzF:240328 As default,chk glyph size by TextDraw additional to ExtentPoint for also not Ambiguous chars.//~vbzFI~
//vbzE:240328 /GA Option to chk glyph size by TextDraw additional to ExtentPoint for also not Ambiguous chars.//~vbzEI~
//vbzC:240323 /Ffontname parm; suuport \uxxxx specification        //~vbzCI~
//vbzA:240315 WINCON,try to get fontface from settings.json at uvio2//~vbzAI~
//vbzz:240311 arrange vbz3,vbzp:/Yv and vbzy:YL to /Gv[L]          //~vbzzI~
//vbzy:240310 /YL, optionally ambiguous chk for language by performance reason.//~vbzyI~
//vbzw:240306 try get plyph width by pango api                     //~vbzrI~
//vbzu:240302 add test option to notrace while mapinit for performance. (del prev option /Yn/Nn to winNT option)//~vbzuI~
//vbzs:240302 requied to append sepc(\ or /) to wkdir              //~vbzsI~
//vbzr:240302 chk workdir to enable to use :: for /F@fontinfofile  //~vbzrI~
//vbzq:240228 (W32:Console) /Ffontname[:charset] for WindowsTerminal//~vbzqI~
//vbzp:240210 -Yv/Nv parm for also xe console                      //~vbzpI~
//vbzn:240207 char width adjustment for console. adjust by tbl if /Yv.//~vbznI~
//vbzk:240202 finaly ccursor chk for cell width is LNX(xe,gxe) and WXE.//~vbzkI~
//vbzj:240202 Test option /UUxxxx; set unicode for debug breaking. //~vbzjI~
//vbz5:240120 try vbz3 to XXE(apichk by char extent)               //~vbz5I~
//vbz4:240120 try vbz3 to WXE                                      //~vbz4I~
//vbz3:240119 optionally chk wcwidth by cursor.  /Yv(default)      //~vbz3I~
//vc71 2023/08/20 clear *.lock of =6 when destroyed by Home+swipe  //~vc71I~
//v77Z:230718 ARM;support CD to shared storage                     //~v77ZI~
//vbvj:221130 change workdir to %USERPROFILE% (C:\Users\username) fo protection//~vbvjI~
//vbvg:221130 LNX compiler arning                                  //~vbvgI~
//vbvf:221129 drop japanese comment for =0.2/0.3 when english mode //~vbvfI~
//vbta:201214 allow -Nm for linux(abondon vbt3)                    //~vbtaI~
//vbt5:201212 (WIN)apply utf8 code input(-NM) not also DBCS env    //~vbt5I~
//vbt3:201212 (LNX)Drop -Nm option                                 //~vbt3I~
//vbt2:201211 Y/Nw default is /Yw(correct help)                    //~vbt2I~
//vbs7:201028 Debian10 compiler warning -Wformat-overflow          //~vbs7I~
//vbrc:200801 (ARM)default is CPU8 file and filename               //~vbr1I~
//vbr1:200615 ARM compiler warning                                 //~vbr1R~
//vbq7:200516 option to bypass useteh for MS visual studio exception handling(request restart visual studio)//~vbq7I~
//vbmk:180813 for test,try mk_wcwidth_cjk(ambiguous:Wide DBCS) for visibility chk. use /YJ option//~vbmkI~
//vbkm:180625 UTRACE;add option of ignore FORCE option             //~vbkmI~
//vbi9:180221 (GTK3:bug)window size recovery err                   //~vbi9I~
//vbi6:180220 stack all errmsg before init end to errmsg.<pid>     //~vbi6I~
//vbf0:180109 WriteConsoleOutputW(used for cpu8 ligaturemode) shrinks line on Windows10(OK on XP),prohibit ligature on for Windows10//~vbf0I~
//vbda:171121*(gxe)display GTK3/GTK2 on titlemsg/about dialog      //~vbdaI~
//vba2:170710 add SP cmd to register shortcut path name and use by  sp:xxx//~vba2I~
//vb8a:170218 use xe_wd when /W option is for root dir(d:\xe_wd if /wd:)//~vb8aI~
//vb7p:170119 no longname errmsg at dlcmdterm                      //~vb7pI~
//vb2X:160404 display -Ccp value on optcombine help                //~vb2XI~
//vb2V:160404 (Bug of vb2M) trace filename was changed by vb2M     //~vb2VI~
//vb27:160115 (BUG)Gotheropt is ULONG,it should be used ULBITON/OFF/CHK//~vb27I~
//vb26:160114 avoid utrace file contention                         //~vb26I~
//            open xe___.mtr.(pid),xe___.trc.(pid)(del remaining file if pid is not active.)//~vb26I~
//vawK:140624 (BUG)by uerr:vav6,display last remaining msg was printed by euc//~vawKI~
//vava:140410 (Win)unicode support(UD fmt string)                  //~vavaI~
//vauE:140316 (Win)use ddfmt for dirlist;On cmd-prompt with setcp=65001,f2l dosenot change length but Windows display line shrinked//~vauEI~
//            use ddfmt to set USDfdata                            //~vauEI~
//vau0:140223 (LNX:BUG)utf8 filename on dirlist,filename locale:de is invalid if f2l on locale=ja_jp//~vau0I~
//            use ddfmt to set USDfdata                            //~vau0I~
//vaq3:131230 (Bug of v127E:van6)rctl is not effective             //~vaq3I~
//van9:131202 Issue warning to recover RCTL enter off-->on(if on "opt rctl ON" could not be enter)//~van9I~
//vamw:131018 accept -{cplc|cpu8|cpas|cpeb[:cp]} for commandline parm//~vamwI~
//vaj8:130723 change ftp option prefix -F to -FTP to specify edit cmd option -F as cmdline parm//~vaj8I~
//vaiw:130619 (BUG)ostype for vc2010;64 is 6                       //~vaiwI~
//vai2:130525 (Axe)trace option is set at jnij2c, so do not reset at xe.c//~vai2I~
//vagE:120918 apply cmdline option /U{N|F}{8|L} to also edit/browse cmd//~vagEI~
//vafy:120707 printf format "%n" disabled by default and assetion when debug mode//~vafyI~
//vafr:120626 no need trace before wcinit(avoid utrace.out even when with no /D option)//~vafrI~
//vafq:120626 (VC10x64)no eh handling(stack trace)                 //~vafqI~
//vafp:120626 (VC10x64)malloc size is not avail when nor _DEBUG mode//~vafpI~
//vafk:120624 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  use ULPTR(unsigned __int64/ULONG)//~vafkI~
//vad0:120417 (Lnx)option to use ICU as local converter            //~vad0I~
//vabf:120127 (Axe)save/load sbcsid tbl for quick startup          //~va90I~
//va90:110520 ANDROID porting                                      //~va90I~
//va7e:100819 reject code page is null                             //~va7eI~
//va76:100806 (BUG:WXE)should be forceeng errmsg when char set is not sjis//~va76I~
//va73:100805 (BUG:WXE)/n9 option ignored te on LP64               //~va73I~
//va71:000731 LP64:display "64" on title msg                       //~va71I~
//va6G:100719 "xe *" err when /mx option appended(all enclosed by quotation by the reson of space embeding)//~va6GR~//~va71R~
//va50:100324 Raw EBCDIC file support for NFS mount                //~va50I~
//va3U:100322 no any output to trace file when NOTRACE compile optiion//~va3UI~
//va20:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~va1uI~
//            (WIN)forcewide to use wideapi(ucs kbd,vio)           //~va1uI~
//va1u:091109_cmdline helpmsg; /Yrr reuires /Yr                    //~va1uI~
//va1s:091108_(UTF8:BUG)cmdline option errchk ;missing option after /uN,/uF//~va1sI~
//va1n:091103_(UTF8)cmdline parm for filename encoding             //~va1nI~
//va1m:091102_(UTF8)cmdline parm to force "file encoding is locale code"//~va1mR~
//va1c:091030_merge GB18030 support                                //~va1cR~
//va0Q:091003!reject UTF8 as -C parameter because dbcstbl is set by iconv rc=incomplete multibyte;//~va0QI~
//va0D:090722_(WIN)accept -Nm(no utf8 process) for test width -Yw(utf8 kbd input)//~va0DI~
//va00:090510 merge utf8 version(enclosed by UTF8SUPPH)            //~va00I~
//          /U parm is /U{F} only                                  //~va00R~
//          /Ym option to force utf8->locale conversion for the case gnome=utf8 env=locale//~va00I~
//v7ah:081120 (WXE:bug)helpmsg popup for each line                 //~v7ahI~
//v7ac:081108 Japanese bit is to be reset by -C option             //~v7acI~
//v7a7:081105 change cmdline option /n8-->nm(Multibyte)            //~v7a7I~
//v7a5:081027 (BUG)dbcs evaluation required when /N8 option specified//~v7a5I~
//v7a3:081102 help for new cmdline parm                            //~v7a3I~//~va00R~
//v79T:081028 Gunxflag setup required for sedbcstbl from functinit;move to xe.c from xescr.c//~v79TI~
//v79M:081020 avoid that file spec start by '/' is treated as flag parm on cygwin//~v79MI~
//v79H:081017 (Win)Vista:for the case C:\ is protected; serch available device,if not use temp//~v79HI~
//v79z:080916 DBCS tbl for C and K of CJK                          //~v79zI~
//v79a:080808 DBCS other than Japanese                             //~v79aI~
//v793:080715 /Nrr option to reset RCT-newline                     //~v793I~
//v790:080709 RCTLNL cmd line parameter /yn                        //~v790I~
//v8@i:080619 TSO:"=6.TSOxx" support                               //~v8@iI~
//v78j:080312 (WXE)ABEND by push x on right top of window          //~v78jI~
//v781:080219 (BUG)C+c break process after system(),spawn() because it loose console mode//~v780I~
//v780:080212 syntaxhighlight support                              //~v77BI~
//v77B:080126*no locale chk before release utf8 version(udbcschk pre-release)//~v77BI~
//v71A:061030 (WXE)Use HtmlHelp;Winhelp is deprecated at Vista;XP english ersion cannot read .hlp by the readson of codepage unsupported//~v71AI~
//v716:060926 3270:"listds" cmd to chk file exist/dsorg            //~v716I~
//v714:060919 FTP option more chk                                  //~v714I~
//v705:060727 graphic char setup by external file(2 string for opt linech on/off)//~v705I~
//v69G:060710 (BUG)trace done evenif -d parm is not specified because TRACE_INIT is nop by compile NOTRACE option//~v69GI~
//v69E:060708 (LNX)errexit msg disppear;it should be printf after scr reset//~v69EI~
//v69s:060601 (LNX:FC5)utf8 not yet supported as DBCS,use english SBCS mode temporary//~v69sI~
//v69a:060429 (BUG)English version crash by IM(at first -n9 option chk timing bug;force_english should be set after PRE_INIT)//~v69aI~
//v68k:060404 (BUG)space embedding filename err for cmdline filename parameter(it is applyed for drop on icon)//~v68kI~
//v670:051224 cmd histry retrieve for each screen(A+F12)           //~v670I~
//v654:050712 (UNX:BUG) _end is end of data segment but not start of stack segment//~v654I~
//v641:050614 (LNX)xxe support                                     //~v641I~
//v61n:050301 setup ueh earlier(no dump gotten when filename list initial setup)//~v61nI~
//v59D:041120 env init file support                                //~v59DI~
//v55B:040305 (BUG)"xe /b" issue help for browse(missing filename parm)//~v55BI~
//v55d:040211 (FTP:BUG)t of -fxt option override x option          //~v55dI~
//v54x:040115 no deelte tempwd option for test                     //~v54xI~
//v54p:040106 (FTP)uftpisremote interface changed                  //~v54pI~
//v54n:040105 (FTP)support hosts filename /f                       //~v54nI~
//v53Y:031223 (WIN,UNX)ftp option parameter support                //~v53YI~
//v53U:031109 (WIN,UNX)ftp support                                 //~v53UI~
//v53u:031004 (UNX:BUG)signal handler abend                        //~v53uI~
//v53s:031004 malloc trace opt to print 2 level return addr        //~v53rI~
//v53r:030930 display debug option help by -hh or -??              //~v53rI~
//v53o:030929 (WXE:BUG)initialy english mode unprintable charset   //~v53oI~
//                     charset is considered later                 //~v53oI~
//v53h:030927 (LNX:BUG)sjis chk done for EUC under                 //~v53hI~
//v501:020928 set default work dir when no env,/w parm             //~v501I~
//v500:021130 (WXE)use same xe work dir for wxew.ini newfile dir   //~v501I~
//v500:021007 (WXE)help msg before exit                            //~v501I~
//v500:020928 (WXE)force english when not sjis mode                //~v500I~
//v500:020827 wxe support                                          //~v500I~
//v48q:020521 (UNX:BUG)chk Gcmdbuff overflow                       //~v48qI~
//v47s:020315 (WIN)drop v47r:because win use bufferwite(multiple line)//~v47sI~
//v47r:020315 screen width  parm support(/Wnn)                     //~v47rI~
//v47m:020309 screen height parm support(/Hnn)                     //~v47mI~
//v45G:011228 v45F is unx only                                     //~v45GI~
//v45F:011227 change default work  dir to ~(home)                  //~v45FI~
//v449:011202 (WIN:BUG)dbcs repl by hexinput dose not redraw Dwhen BCS change to SBCS//~v449I~
//v41y:010910 compile err when NOTRACE                             //~v41yI~
//v40e:010421 euc dbcs msg when under kon                          //~v40eI~
//v21i:010113 LINUX support:euc code dbcs support;force msg is english//~v21iI~
//v21c:010106 LINUX support:cmd line parm help                     //~v21cI~
//v21a:001209 LINUX support:lower case exe name(xe)                //~v21aI~
//v20a:000931 del trace option from help msg                       //~v20aI~
//v19T:000928 LINUX support(Global userid var;from now new grobal is on xegbl.h)//~v19TI~
//v19S:000928 LINUX support(work dir for each user as default;permission reason)//~v19SI~
//v19P:000927 no alloc16 msg for except os2                        //~v19PI~
//v19F:000925 LINUX support(XE_UNDEL_%d:add uid to undo dir name for permition)//~v19FI~
//v19D:000925 LINUX support(command flag prefix is mainly '-')     //~v19DI~
//v19x:000923 LINUX support(another main for other parm by --)     //~v19xI~
//v19j:000904 LINUX support(option parm flag change "/"-->"-")     //~v19jI~
//v19i:000904 LINUX support(kbd io)                                //~v19iI~
//v19h:000904 (BUG)title msg scroll 1 line of helpmsg              //~v19hI~
//v19b:000903 LINUX support(OSTYPE)                                //~v19bI~
//v19a:000903 LINUX support(dir path seperator)                    //~v19aI~
//v195:000902 LINUX support(drop upopup func)                      //~v195I~
//v190:000902 LINUX support(CRLF)                                  //~v190I~
//v159:000409 (win:BUG)abend msg is mixed with prev scr strings.   //~v159I~
//            normaly buffuse flag is off,but abend at draw_file/draw_pan//~v159I~
//            reave the flag then bug of uvio cased abend at ueh.  //~v159I~
//v142:000131:add w95kbdtrace option                               //~v142I~
//v141:000115 it is noisy,no beep only once for same reason(continuous from same pos)//~v141I~
//v13m:991031 no bell option support                               //~v13mI~
//v11E:990822 use helpmsg for help                                 //~v11EI~
//v11z:990821 support filename=* (last closed file) on cmd line    //~v11zI~
//v11y:990821 support /R option to restore previous default drv/directory//~v11yI~
//v10S:990605 (BUG)workdir env var may be followed with space      //~v10SI~
//            xe.c                                                 //~v10SI~
//v0jt:980724 (WIN only)option to force nt mode kbd input for future version up//~v0jtI~
//v0jc:980721 W95-->WIN                                            //~v0jcI~
//v0ja:980721 change define value by change opt start from 0.0     //~v0jaI~
//v0iw:980718 pfk cmd support(del 0.5,cmd change by ini only)      //~v0iwI~
//v0it:980717 funckey change option support                        //~v0itI~
//            write to ini when cmd/key assign changed             //~v0itI~
//v0io:980702 pfk cmd support(opt 0.4)                             //~v0ioI~
//v0im:980625 pfk cmd support(optk1 and optk2)                     //~v0imI~
//v0if:980620 pfk cmd support                                      //~v0ifI~
//v0ha:980120 need differrentiate codepage and dbcs tbl            //~v0haI~
//            w95J codepdge 437 hase dbcs table and first half of DBCS on//~v0haI~
//            rightmost column effect on first column of next line //~v0haI~
//v0h1:980111 dbcs space help msg for english help                 //~v0h1I~
//v0fw:971116 (GCC:BUG)need force chk use_lfn when change env var LFN//~v0fwI~
//                     change n to y                               //~v0fwI~
//v0fl:971103 lfn support exec option /Yl,/Nl;default is /Yl       //~v0flI~
//v0f1:971010 os2 new malloc dump logic;no need initial heap alloc //~v0f1I~
//v0bx:970728 malloc errexit option by EXE parm /DA,/DB            //~v0bxI~
//v0a3:970705:bell when ini parm err                               //~v0a3R~
//            edit/brows /Mrmode-wmode option mode=PC/UNIX         //~v09YI~
//v09Y:970629:file NULL(0x00) support                              //~v09YI~
//v09U:970628:display unprintable char by 0x0e(J) or 0x16(E)       //~v09UI~
//            call gbl after dbcs sw defined                       //~v09UI~
//v099:970420:(GCC)user harderr(gcc abort when drive not ready)    //~v099I~
//            (os/2 popup and reply(need twice when drive not ready)//~v099I~
//            w95 return err code,dos accept a/f/r)                //~v099I~
//v095:970405:DPMI version                                         //~v095I~
//            -\ of dbcs 2nd byte                                  //~v095I~
//            -exception handler,abend at uerrexit                 //~v095R~
//v08x:961208:different file name of .map/.trc/.mtr/.dmp for DOS/OS2/W95//~v08xR~
//v08u:961207:(BUG)/Y9 or /N9 is not effective for /?              //~v08tI~
//v08t:961207:exec parameter /e(browse) or /b(edit) and other option//~v08aI~
//v08a:961103:reset precize flag by other duplication parameter    //~v08aI~
//v085:961024:W95 VC                                               //~v085I~
//v07w:960920:dosdump                                              //~v07wI~
//v07l:960713:(BUG)also for other than PATHLEN(strpbrk,strchr etc) //~v07lI~
//v07i:960713:for malloc trace matching,trace option process before ini proc(parmproc0)//~v07iI~
//v07c:960624:allow xe 0/1/2/6 not as edit 0 etc.                  //~v07cI~
//v06n:960320:menu option 6(cmd) support                        //~v06nI~
//v064:960217:split inifile for Ginitscroll/Giniopt_/Ginifiletabskip//~v064I~
//v05u:951202:undelete dlcmd(rename when delete)                //~v05uI~
//v05d:951111:/N9 option to force english err msg to test       //~v05dI~
//v051:951014:print dlcmd                                       //~v051I~
//v04d:950930:malloc/calloc rc chk for dos                      //~v04dI~
//v03w:950902:upopup separate from uerr to avoid linkage(uvio/ukbd)//~v03wI~
//*v03v:950829:trace file open err process by xe(ulib only issue printf//~v03vI~
//            for other user link simplicity)                   //~v03vI~
//            trace opt reset when 2nd byte not specified for the case//~v03vI~
//            /d21 /20(duplicated)                              //~v03vI~
//*v03t:950827:for DOS,when uerrexit,map open err not displayed //~v03sI~
//            because Shandle1 of uerr.c is set 0 at loop start //~v03sI~
//*v03s:950827:for test,option to abend/uerrexit by double Esc(/DxxA or//~v03sR~
//            /DxxE)                                            //~v03sI~
//*v03m:950818:bug,when wkdir is root,err path not found for g:\\xe.ini//~v03mI~
//*v03j:950813:trac file/malloc trace file close when err       //~v03jI~
//*v03g:950808:ignore trace open err(dup open)                  //~v03gI~
//*v032:950712:UFLD for each ppc(paninit call)                  //~v032I~
//*v031:950712:move gblinit to new xegbl.c                      //~5712I~
//*v01c:950708:stack used size chk(os2 only,dos not clear memory at init)//~v01cR~
//*v01a:950705:kbd rate ini option(entry and exit value)        //~v018I~
//*v018 950702:same ver/date to xe.ini and title msg            //~v018I~
//************************************************************* //~v018I~
//*950528 display net alloc req len                             //~5528I~
//*950527 ini write at etrm                                     //~5527I~
//*950506 ASCII char option                                     //~5506I~
//*950504 save find parm                                        //~5504I~
//*950429 ini file process                                      //~5504R~
//*941204 debug mode ualloc
//*941120 ueh
//*************************************************************
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <signal.h>
//*************************************************************
#ifdef DOS
#else
    #ifdef W32                                                     //~v085I~
        #include <windows.h>                                       //~v085I~
    #else                                                          //~v085I~
        #define INCL_BASE                                          //~v085R~
        #include <os2.h>                                           //~v085R~
    #endif                                                         //~v085I~
#endif
//*******************************************************
#define  GLOBAL
#include <ulib.h>
#include <uque.h>
#include <uerr.h>
#include <upopup.h>                                             //~v03vI~
#include <ukbd.h>
#include <udbcschk.h>
#include <ualloc.h>
#include <utrace.h>                                             //~4C24I~
#include <uabend.h>                                             //~5124I~
#include <ufile.h>                                              //~5318I~
#include <ufile2.h>                                                //~v19SI~
#include <ufile4.h>     //ufileisvfat                              //~v0flI~
#include <uftp.h>                                                  //~v54pI~
#include <ustring.h>    //ustrrspn                                 //~v10SI~
#include <uvio.h>   //uvio_w95setbuffmode                          //~v159I~
#include <udos2.h>   //uvio_w95setbuffmode                         //~v79HI~
#include <utf22.h>   //uvio_w95setbuffmode                         //~va90I~
#include <uedit.h>   //uvio_w95setbuffmode                         //~vb26I~
#include <uproc2.h>   //uvio_w95setbuffmode                        //~vb26I~
#ifdef DOS                                                         //~v07wI~
    #ifdef DPMI                 //DPMI version                     //~v095M~
        #include <ueh.h>                                           //~v095M~
        #include <udos.h>       //uharderr                         //~v099I~
    #else                       //not DPMI                         //~v095M~
    #endif                      //DPMI or not                      //~v095M~
    #include <ufuncmap.h>                                          //~v07wR~
    #include <uehdump.h>                                           //~v07wI~
#else                                                              //~v07wI~
    #include <ueh.h>                                               //~v085M~
    #ifdef W32                                                     //~v085M~
        #include <ufuncmap.h>                                      //~v085M~
        #include <ukbdw.h>                                         //~v0jtI~
        #include <umiscf.h>                                        //~vafyR~
    #else                                                          //~v085M~
    #endif                                                         //~v085M~
#endif                                                             //~v07wI~
#ifdef UNX                                                         //~v79zI~
	#include <uunxsub.h>	//ugetugid                             //~v79zI~
#endif                                                             //~v79zI~
	#include <udos.h>	//ugetugid                                 //~vbf0I~
#include <utf.h>	                                               //~vbz3I~
#include <uvio2.h>                                                 //~vbzqI~
#include <ucvebc.h>                                                //~vbB6I~
                                                                   //~v19SI~
#include "xe.h"
#include "xegbl.h"                                              //~5712I~
#include "xescr.h"
#include "xepan.h"
#include "xefile.h"
#include "xefunc.h"                                             //~5104I~
#include "xefunc2.h"
#include "xekbd.h"                                                 //~v0ifM~
#include "xeini.h"                                              //~5429I~
#include "xeini3.h"                                             //~v064I~
//#include "xefcmd2.h"                                          //~v064R~
#include "xedir.h"                                              //~v05uI~
#include "xedlcmd.h"                                            //~v05uI~
#include "xedlcmd4.h"                                           //~v05uI~
#include "xedcmd.h"                                                //~v781I~
#include "xedcmd2.h"                                            //~v06nI~
#include "xedcmd3.h"                                               //~v59DI~
#ifdef WXE                                                         //~v500I~
	#include "wxedef.h"                                            //~v500I~
	#include "wxexei.h"                                            //~v500R~
#endif                                                             //~v500I~
#ifdef XXE                                                         //~v641I~
	#include <xxexei.h>                                            //~v641R~
#endif                                                             //~v641I~
#ifdef FTPSUPP                                                     //~v53UI~
	#include "xeftp.h"                                             //~v53UI~
#endif                                                             //~v53UI~
#include "xeundo.h"                                                //~v781I~
#include "xesyn.h"                                                 //~v780R~
#include "xeopt.h"                                                 //~v79zI~
#ifdef UTF8SUPPH                                                   //~va00M~
	#include "xeutf.h"                                             //~va00I~
#endif                                                             //~va00M~
#include "xeebc.h"                                                 //~va50I~
#include "xearm.h"                                                 //~va90I~
#include "xefcmd7.h"                                               //~vba2I~
#include "xesub.h"                                                 //~vbzrI~
//*******************************************************
#define NULLCOMP 256                                            //~v01cI~
#define UTRACE_FORCE_FNMSUFFIX  "_kbd"                             //~vbkmI~
//*******************************************************       //~4C19I~
UEXITFUNC uexitfunc;
//#ifdef DOS                                                       //~v095R~
#if defined(DOS) && !defined(DPMI)                                 //~v095I~
#else
void uehexit(int,PUEXREGREC);//exit func
#endif
int xecleartrcfile(int Popt,char *Pfnm);                           //~vbkmI~
#define XCTFO_COUNT_MASK           0xff                            //~vbkmR~
#define XCTFO_KBD_KEEP_COUNT       5          //keep max 5 file if not clear specified//~vbkmR~
#define HOMEDIR "USERPROFILE"                                      //~vbvjI~
//*******************************************************
#ifndef UNX                                                        //~v195I~
  #ifndef WXE                                                      //~v500I~
extern UPOPUPMSG upopupmsg;                                     //~v03wR~
  #endif //!WXE                                                    //~v500I~
#endif                                                             //~v195I~
void parmproc(int Pparmc,char *Pparmp[]) ;
int parmproc0(int Pparmc,char *Pparmp[]) ;                         //~v501R~
int  parmproc00(int Pparmc,char *Pparmp[]);                        //~v79zI~
int  xegetworkdir(void);                                           //~v79zI~
int  xetraceinit(void);                                            //~v79zI~
int numchk(UCHAR *Pnumstring);                                  //~5114I~
void help(void);
void titlemsg(void);
static  char Spgmver[16];
static  int  Smalloctrcopt=0;                                      //~v53UR~
static  int  Stesttrcopt=0;                                        //~v53UR~
#ifndef ARM                                                        //~vbr1R~
static  int  StesttrcoptClear;                                     //~vbkmI~
#endif                                                             //~vbr1R~
static  int  Sinitend;  //entered getchar loop                  //~4C27I~
static  UCHAR *Sinifile=0;    //.ini use option                    //~v53UR~
static  int Suerrmsgopt=0;                                         //~v53UR~
static  int Sdebughelp=0;                                          //~v53rI~
static char  Sallocexit=0;           //errexit when alloc err      //~v53UR~
static UCHAR Srestorecdsw=0;         //restore previous CD setting //~v53UR~
//static int Sheightparm=0;         //screen height parm           //~v47rR~
static int Sscrparm[2]={0,0};         //screen height parm         //~v47rI~
#ifdef FTPSUPP                                                     //~v53YI~
	static int Sftpopt=0;                                          //~v53YI~
	static char  *Shostsfnm=0;                                     //~v54nI~
#endif                                                             //~v53YI~
#ifdef UNX                                                         //~v19jI~
    #ifdef LNX                                                     //~v19jI~
      #ifdef ARM                                                   //~va90I~
    	char Sostype[]="arm";                                      //~va90I~
      #else                                                        //~va90I~
      #ifdef GTK                                                   //~v641R~
    	char Sostype[]="gtk";                                      //~v641I~
      #else                                                        //~v641I~
      #ifdef KDE                                                   //~v641R~
    	char Sostype[]="kde";                                      //~v641I~
      #else                                                        //~v641I~
    	char Sostype[]="lnx";                                      //~v19jI~
      #endif                                                       //~va90I~
      #endif                                                       //~v641I~
      #endif                                                       //~v641I~
    #else                                                          //~v19jI~
    	char Sostype[]="unx";                                      //~v19jI~
    #endif                                                         //~v19jI~
#else                                                              //~v19jI~
#ifdef DOS                                                         //~v08xI~
    #ifdef DPMI                 //DPMI version                     //~v095I~
        char Sostype[]="gcc";                                      //~v095I~
    #else                       //not DPMI                         //~v095I~
    char Sostype[]="dos";                                          //~v08xI~
    #endif                      //DPMI or not                      //~v095I~
#else                                                              //~v08xI~
    #ifdef W32                                                     //~v08xI~
//      char Sostype[]="w95";                                      //~v0jcR~
      #ifdef WXE                                                   //~v500I~
        char Sostype[]="wxe";                                      //~v500I~
      #else                                                        //~v500I~
        char Sostype[]="win";                                      //~v0jcI~
      #endif                                                       //~v500I~
    #else                                                          //~v08xI~
        char Sostype[]="os2";                                      //~v08xI~
    #endif                                                         //~v08xR~
#endif                                                             //~v08xI~
#endif                                                             //~v19jI~
#ifdef WCSUPP                                                      //~v79zI~
	#ifdef UTF8SUPP                                                //~v79zI~
      	static int    Swcinitopt=UDCWCIO_UTF8VERSION;              //v79zI~//
	#else                                                          //~v79zI~
      #ifdef W32                                                   //~va1cR~
       #ifdef UTF8UCS2                                             //~va1uI~
        static int    Swcinitopt=UDCWCIO_FORCEWIDE;                //~va1uI~
       #else                                                       //~va1uI~
    	static int    Swcinitopt=0;                                //~va1cR~
       #endif                                                      //~va1uI~
      #else       //LNX                                            //~va1cR~
    	static int    Swcinitopt=UDCWCIO_DBCSREAD;                 //~va1cR~
      #endif                                                       //~va1cR~
    #endif                                                         //~v79zI~
#endif                                                             //~v79zR~
#ifdef WXE                                                         //~v7ahI~
    static int  Shelpsw;                                           //~v7ahI~
#endif                                                             //~v7ahI~
#ifdef NOTRACE                                                     //~vbzxI~
    static int Sskipuseteh;                                        //~vbq7I~
#else                                                              //~vbzxI~
    static int Sskipuseteh=1;	//debug version, skip seteh        //~vbzxI~
#endif                                                             //~vbzxI~
//#ifdef WINCON                                                    //~vbzrR~
#if defined(WINCON) || defined(LNXCON)                             //~vbzrI~
    static int SswFont;                                            //~vbzqI~
    static char *SpFontParm;                                       //~vbzrI~
	void xeSetConsoleFont(char *PfontParm);                        //~vbzrI~
#endif                                                             //~vbzrI~
char *SebccfgCLP=0;                                                //~vbBcI~
//*******************************************************
//*main 
//*******************************************************
//#ifdef WXE                                                       //~v641R~
#ifdef WXEXXE                                                      //~v641I~
int xemain(int Preqtype,int parmc,char *parmp[])                   //~v500I~
#else                                                              //~v500I~
#ifdef UNX                                                         //~v19xI~
int xemain(int parmc,char *parmp[])                                //~v19xI~
#else                                                              //~v19xI~
int main(int parmc,char *parmp[]) 
#endif                                                             //~v19xI~
#endif //!WXE                                                      //~v500I~
{
#ifdef DOS
//  extern UCHAR end;       //stack seg top                     //~v01cR~
//  static UCHAR *Spstacktop=&end;                              //~v01cR~
    #ifdef DPMI                 //DPMI version                     //~v095I~
        UEXREGREC uregrec;  /*exception handler unset*/            //~v095I~
    #else                       //not DPMI                         //~v095I~
    #endif                      //DPMI or not                      //~v095I~
#else
    #ifdef W32                                                     //~v085I~
      #ifndef WXE                                                  //~v500I~
      #ifndef ULIB64X                                              //~vafqI~
        ULONG  pstacktop,pstackend;                                //~v085I~
      #endif                                                       //~vafqI~
      #endif                                                       //~v500I~
    #else                                                          //~v085I~
      #ifndef UNX                                                  //~v654I~
    extern UCHAR _end;      //stack seg top                     //~v01cI~
    static UCHAR *Spstacktop=&_end;                             //~v01cI~
    char nullcomp[NULLCOMP];                                       //~v085M~
      #endif                                                       //~v654I~
    #endif                                                         //~v085I~
  #ifndef WXE                                                      //~v500I~
    UEXREGREC uregrec;  /*exception handler unset*/
  #endif                                                           //~v500I~
#endif
#ifdef DPMI                 //DPMI version                         //~v095I~
#else                       //not DPMI                             //~v095I~
  #ifndef WXE                                                      //~v500I~
   #ifndef UNX                                                     //~v654I~
   #ifndef ULIB64X                                                 //~vafqI~
    int resstacklen;                                               //~v095I~
   #endif                                                          //~vafqI~
   #endif                                                          //~v654I~
  #endif                                                           //~v500I~
#endif                      //DPMI or not                          //~v095I~
    int rc;                                                        //~v095I~
//  char *pc,*errmsg;                                              //~v79zR~
//#ifndef UNX                                                      //~v79HR~
//    char *pc;                                                    //~v79HR~
//#endif                                                           //~v79HR~
#ifdef OS2                                                         //~v7acI~
    char *pc;                                                      //~v7acI~
#endif                                                             //~v7acI~
    char *errmsg;                                                  //~v79zI~
//  char wkfname[_MAX_PATH];                                       //~v79zR~
#ifndef WXE                                                        //~v500I~
//  char mapfname[_MAX_PATH];                                      //~vbs7R~
    char mapfname[_MAX_PATH+256];                                  //~vbs7I~
//  char dumpfname[_MAX_PATH];                                     //~vbs7R~
    char dumpfname[_MAX_PATH+256];                                 //~vbs7I~
#endif                                                             //~v500I~
//#ifdef UNX                                                       //~v79zR~
//    char fpathwk[_MAX_PATH];                                     //~v79zR~
//#endif                                                           //~v79zR~
    char *uatrcopt="Inactive";
    UALLOCD *puad;
    long reslen,resctr;                                            //~v0f1R~
//  size_t   rpos;                                                 //~v79zR~
//****************************
//#ifdef NOTRACE                                                     //~va3UI~//~vafrR~
//  utrace_init(0/*tracefilename*/,0/*notrace*/);                  //~vafrR~
//#endif                                                             //~va3UI~//~vafrR~
//#ifdef WXE                                                       //~v641R~
#ifdef WXEXXE                                                      //~v641I~
//if (Preqtype==WXE_REQ_INIT)                                      //~v53oR~
if (Preqtype==WXE_REQ_PREINIT)                                     //~v53oI~
{                                                                  //~v501I~
#endif                                                             //~v501I~
#ifdef W32UNICODE                                                  //~vavaI~
    SET_UDMODE();  //filename by UD format                         //~vavaI~
#endif                                                             //~vavaI~
#ifdef VC10EXP                                                     //~v6hqI~//~vafyI~
	uwin_enablecountoutput(1/*enable*/);                            //~v6hqI~//~vafyI~
#endif                                                             //~v6hqI~//~vafyI~
#ifndef ARM                                                        //~vai2I~
    utrace_init(0/*tracefilename*/,0/*notrace*/);                  //~vafrI~
#endif                                                             //~vai2I~
#ifdef W32                                                         //~vbf0I~
    udos_getWindowsVersion(0,&GWinMajVersion,&GWinMinVersion,&GWinInfoVersion);//~vbf0R~
#endif                                                             //~vbf0I~
#ifdef WCSUPP                                                      //~v7acI~
    udbcschk_wcinit(Swcinitopt|UDCWCIO_BEFOREINIT,0); //force english until next wcinit call//~v7acI~
#endif //WCSUPP                                                    //~v7acI~
    uerrmsg_init("",stdout,UERR_FORCE_ENGLISH);//english until wcinit msg to stdout//~v79zI~
//  xegetworkdir(); //setup workdir                                //~vbzrI~//~vbzsR~
    parmproc00(parmc,parmp); //get locale,trace option parm        //~v79zI~
//  xegetworkdir(); //setup workdir                                //~v79zI~//~vbzrR~
    xegetworkdir(); //setup workdir                                //~vbzsI~
    uerrmsg_initstart(Gworkdir);                                   //~vbi6I~
//#ifdef WINCON                                                    //~vbzrR~
#if defined(WINCON) || defined(LNXCON)                             //~vbzrI~
    if (SpFontParm)                                                //~vbzrI~
    {                                                              //~vbzrI~
    	xeSetConsoleFont(SpFontParm);                              //~vbzrR~
        ufree(SpFontParm);                                         //~vbzrR~
    }                                                              //~vbzrI~
#endif                                                             //~vbzrI~
#ifndef NOTRACE                                                    //~va3UI~
#ifndef ARM                                                        //~vai2I~
    xetraceinit();  //trace init                                   //~v79zI~
#endif                                                             //~vai2I~
#endif                                                             //~va3UI~
#ifdef WCSUPP                                                      //~v79zI~
//#ifdef UTF8SUPP                                                  //~v79zR~
//#else                                                            //~v79zR~
//  Gudbcschk_flag|=UDBCSCHK_NODBCS;	//LNX:donot localechk at udbcschk if not EUC//~v79zI~
//#endif                                                           //~v79zR~
#ifdef ARM                                                         //~va90I~
	utf22setworkdir(0,Gworkdir,0);  //load/save sbcsid tbl for startup performance//~va90R~
#endif                                                             //~va90I~
    udbcschk_wcinit(Swcinitopt,Gdefaultlocalecode); //utf8 version //~v79zR~
#endif //WCSUPP                                                    //~v79zI~
//  Gscrstatus=(UCHAR)(GSCRSDBCS*(udbcschk(0x81)!=0));             //~v0haR~
#ifdef LNX                                                         //~v21iM~
    if (udbcschkcp())                                              //~v21iI~
    {                                                              //~v53hI~
    	if (Gudbcschk_flag & UDBCSCHK_EUC)                         //~v21iI~
        	Gunxflag|=GUNX_EUC;     //euc code                     //~v21iI~
//      else                                                       //~v53hR~
    	if (!(Gudbcschk_flag & UDBCSCHK_UTF8))	//except utf8      //~v69sI~
	    	Gscrstatus=GSCRSDBCS;                                  //~v21iI~
    }                                                              //~v53hI~
    scrsetunxflag(0);  //setup KON flag                            //~v79TR~
UTRACEP("Gunxflag=%x\n",Gunxflag);                                 //~v79HI~
//  Suerrmsgopt=(Suerrmsgopt|UERR_FORCE_ENGLISH);//english for console(may not on kon)//~v40eR~
#else                                                              //~v21iI~
    Gscrstatus=(UCHAR)(GSCRSDBCS*(udbcschkcp()!=0));               //~v0haI~
//#ifdef WXE                                                       //~v53oR~
//  if (Gscrstatus)	//dbcs mode by codepage                        //~v53oR~
//  	Gscrstatus=(UCHAR)(GSCRSDBCS*((Gwxestat & GWXES_CP932))); //by charset option//~v53oR~
//#endif                                                           //~v53oR~
#endif                                                             //~v21iI~
    if ((Gscrstatus & GSCRSDBCS)||UDBCSCHK_ISDBCS())               //~v79zI~
    	Gotherstatus|=GOTHERS_DBCS;        //all DBCS(CJK) including +UTF8//~v79zR~
    if (Gscrstatus & GSCRSDBCS || Gudbcschk_flag & UDBCSCHK_UTF8J) //~v79zI~
    	Gotherstatus|=GOTHERS_DBCSJ;      //SJIS,EUC,EUC-UTF8      //~v79zI~
#ifdef WCSUPP                                                      //~v7acI~
    if (Gudbcschk_flag & UDBCSCHK_FORCEUCJ)                        //~v7acI~
    	Gotherstatus|=GOTHERS_FORCEUCJ;      //EUC-JP by /C parm   //~v7acI~
	if (Swcinitopt & UDCWCIO_KBDNOUTF8) //-Nm                      //~v7a5I~
//  	if (XE_ISDBCS()                                            //~v7a5I~//~vbt5R~
#ifdef LNX                                                         //~vbtaI~
        if (1                                                      //~vbtaR~
#else                                                              //~vbtaI~
    	if (TRUE                                                   //~vbt5I~
#endif                                                             //~vbtaI~
//  	&& Gudbcschk_flag & UDBCSCHK_UTF8                          //~v7a5I~//~va0DR~
    	&&                                                         //~va0DI~
          (                                                        //~va0DI~
    	   Gudbcschk_flag & UDBCSCHK_UTF8                          //~va0DI~
#ifdef W32                                                         //~va0DI~
           ||                                                      //~va0DI~
           Swcinitopt & UDCWCIO_FORCEWIDE                          //~va0DI~
#endif                                                             //~va0DI~
          )                                                        //~va0DI~
        )                                                          //~v7a5I~
			Gotherstatus|=GOTHERS_NOUTF8;     //no utf8 option under utf env//~v7a5I~
#endif                                                             //~v7acI~
                                                                   //~v79zI~
//#ifdef WCSUPP                                                    //~v79zR~
//    if (!UCBITCHK(Gscrstatus,GSCRSDBCS)     //not japanese       //~v79zR~
//    &&  !(Gudbcschk_flag & UDBCSCHK_UTF8))  //except utf8        //~v79zR~
//        udbcschk_wcinit(UDCWCIO_WCDBCSCHK);   //dbcschk for other than japanese//~v79zR~
//#endif                                                           //~v79zR~
//#ifdef WXE                                                       //~v53oR~
//}//init call                                                     //~v53oR~
//if (Preqtype==WXE_REQ_PREINIT)                                   //~v53oR~
//{                                                                //~v53oR~
//#endif                                                           //~v53oR~
    gblinit();          //init gbl(Version etc)                 //~v031R~
                                                                //~v018I~
//*cmd line parm process
    sprintf(Spgmver,"%s:%s ",PGMID,Gversion);                   //~5712R~
//  Gscrstatus=(UCHAR)(GSCRSDBCS*(udbcschk(0x81)!=0));             //~v09UR~
//  uerrmsg_init(Spgmver,stdout,0);//msg to stdout                 //~v21iR~
#ifdef WXE                                                         //~v500I~
    if (!(Gwxestat & GWXES_CP932))                                 //~v500I~
//      Suerrmsgopt=UERR_FORCE_ENGLISH;                            //~v501R~
    	uerrmsg_init(Spgmver,stdout,Suerrmsgopt|UERR_FORCE_ENGLISH);//msg to stdout//~v501I~
    else                                                           //~v501I~
#endif                                                             //~v500I~
    uerrmsg_init(Spgmver,stdout,Suerrmsgopt);//msg to stdout       //~v21iI~
    uerrexit_init(Spgmver,stdout,0,0,0);//stdout only,no pathmsg
    uerrexit_optinit(UERREXIT_BELL);    //force beep from uerrexit //~v13mI~
    rc=                                                            //~v501I~
    parmproc0(parmc,parmp); //get wokdir,ini option parm etc    //~5429I~
    if (Suerrmsgopt & UERR_FORCE_ENGLISH)//-n9 specified           //~v69aI~
	    uerrmsg_init(Spgmver,stdout,Suerrmsgopt);//set forceenglish before REQ_INIT//~v69aI~
    if (rc==-1)                                                    //~v501I~
        return -1;                                                 //~v501I~
////* get work dir name                                              //~v07iM~
//    if (!*Gworkdir)         //no work dir name parm             //~5118R~
//    {
//        if (!(pc=getenv(PGMID)))                                //~4C24I~
//        {                                                       //~4C24I~
//#ifdef UNX                                                         //~v19SM~
////          sprintf(Gworkdir,"/tmp/%s_wd%%",PGMID);                //~v45FR~
//            ufullpath(fpathwk,"~",_MAX_PATH);                      //~v45FI~
//            if (ROOTDIR(fpathwk))                                  //~v45FI~
//                sprintf(fpathwk,"/tmp/%s_wd%%",PGMID);             //~v45FI~
//            else                                                   //~v45FI~
//                sprintf(fpathwk,"~/%s_wd%%",PGMID);                //~v45FR~
//            ufullpath(Gworkdir,fpathwk,_MAX_PATH);                 //~v45FR~
//            pc=Gworkdir;                                           //~v19SI~
//#else //!UNX                                                       //~v19SM~
////    #ifndef WXE                                                  //~v501R~
////            uerrmsg("You need set environment variable %s",      //~v501R~
////                        "環境変数 %s の設定が必要です",          //~v501R~
////                        PGMID);                                  //~v501R~
////    #endif                                                       //~v501R~
////#if defined(DOS) || defined(W32)                                 //~v501R~
////    #ifdef WXE                                                   //~v501R~
////        sprintf(Gworkdir,"%s",WXE_WKDIR);                        //~v501R~
////        pc=Gworkdir;                                             //~v501R~
////    #else                                                        //~v501R~
////            uerrexit("Specify SET %s=xxxx on autoexec.bat or %s.bat etc.\n\ ;//~v501R~
////        Or Sspecify /Wxxxx parameter(xxxx is work dir name)",    //~v501R~
////                    "autoexec.bat または %s.bat などに SET %s=xxxx の指定をする.\n\ ;//~v501R~
////        又は/Wxxxx オプションを指定する(xxxxはワークディレクトリー名)",//~v501R~
////                    PGMID,PGMID);                                //~v501R~
////    #endif                                                       //~v501R~
////#else                                                            //~v501R~
////            uerrexit("Specify SET %s=xxxx on config.sys or %s.cmd etc(xxx is work dir name)",//~v501R~
////                    "config.sys または %s.cmd などに SET %s=xxxx の指定をする\n\ ;//~v501R~
////        又は/Wxxxx オプションを指定する(xxxxはワークディレクトリー名)",//~v501R~
////                        PGMID,PGMID);                            //~v501R~
////#endif                                                           //~v501R~
//        sprintf(Gworkdir,"%s",XE_WKDIR);                           //~v501I~
//        pc=Gworkdir;                                               //~v501I~
//#endif//!UNX                                                       //~v195I~
//        }   //env var not exist
//        pc+=strspn(pc," ");                                        //~v10SI~
//        strcpy(Gworkdir,pc);                                    //~5118R~
//        rpos=ustrrspn(Gworkdir," ");                               //~v10SI~
//        if (rpos!=(size_t)-1)                                      //~v10SR~
//            *(Gworkdir+rpos+1)=0;                                  //~v10SR~
//    }
////  if (*(Gworkdir+strlen(Gworkdir)-1)=='\\')                   //~v03mR~
////      *(Gworkdir+strlen(Gworkdir)-1)=0; //once drop to chk fullpath//~v03mR~
//                                                                //~5118I~
//    if (!ufullpath(wkfname,Gworkdir,_MAX_PATH))                 //~5118I~
//        exit(8);                                                //~5118I~
//#ifdef UNX                                                         //~v19SI~
////edit uid in workdirname and create                               //~v19SR~
//    if (pc=strchr(wkfname,'%'),pc)  //having %                     //~v19SI~
//    {                                                              //~v19SI~
//        rpos=(ULONG)pc-(ULONG)wkfname;                             //~v19SI~
//        memcpy(Gworkdir,wkfname,rpos);                             //~v19SI~
//        sprintf(Gworkdir+rpos,"%05d",Guserid);                     //~v19TR~
//        strcpy(Gworkdir+rpos+5,wkfname+rpos+1);                    //~v19SI~
//        if (ufstat(Gworkdir,0)) //not found                        //~v19SI~
//        {                                                          //~v53rI~
//            if (!umkdir(Gworkdir))                                 //~v19SI~
//                uerrmsg("WorkDir %s is now created",               //~v19SI~
//                        "ワークディレクトリー %s を作成しました",  //~v19SR~
//                        Gworkdir);                                 //~v19SI~
//            else                                                   //~v19SI~
//                exit(8);                                           //~v19SI~
//        }                                                          //~v53rI~
//    }                                                              //~v19SI~
//#else //!UNX                                                       //~v19SI~
//    strcpy(Gworkdir,wkfname);                                   //~5118I~
////  #ifdef WXE                                                     //~v501R~
//    if (ufstat(Gworkdir,0)) //not found                            //~v500I~
//        if (!umkdir(Gworkdir))                                     //~v500I~
//            uerrmsg("WorkDir %s is now created",                   //~v500I~
//                        "ワークディレクトリー %s を作成しました",  //~v500I~
//                    Gworkdir);                                     //~v500I~
//        else                                                       //~v500I~
//            exit(8);                                               //~v500I~
////  #endif                                                         //~v501R~
//#endif //!UNX                                                      //~v19SI~
////  if (*(Gworkdir+strlen(Gworkdir)-1)!='\\')//not root            //~v07lR~
//    if (PATHLEN(Gworkdir)!=(int)strlen(Gworkdir))//last is not '\\'(SBCS)//~v085R~
////  strcat(Gworkdir,"\\");                                         //~v19aR~
//    strcat(Gworkdir,DIR_SEPS);                                     //~v19aI~
#ifndef WXE                                                        //~v61nI~
//*uerrexit setup                                                  //~v61nI~
    sprintf(mapfname,"%s%s%s.map",Gworkdir,PGMID,Sostype);         //~v61nI~
  #if defined(DOS) && !defined(DPMI)                               //~v61nI~
  #else                                                            //~v61nI~
//*ueh register                                                    //~v61nI~
    sprintf(dumpfname,"%s%s%s.dmp",Gworkdir,PGMID,Sostype);        //~v61nI~
    uregrec.UERGheapsize=0;//no initial heap size                  //~v61nI~
    uregrec.UERGmapfn=mapfname;     //map file name                //~v61nI~
    uregrec.UERGdumpfn=dumpfname;       //map file name            //~v61nI~
    uregrec.UERGuxfunc=uehexit;                                    //~v61nI~
    uregrec.UERGparm=0;     //user parm to exit func               //~v61nI~
    UTRACEP("%s:Sskipuseteh=%d\n",UTT,Sskipuseteh);                //~vbzLI~
  if (!Sskipuseteh)                                                //~vbq7I~
  {                                                                //~vbq7I~
    #ifdef UNX                                                     //~v61nI~
      uregrec.UERGsys.PPrevSignalHandler=0;     //no handler,back to OS//~v61nI~
    #endif                                                         //~v61nI~
    useteh(&uregrec);/*exception handler unset*/                   //~v61nI~
  }                                                                //~vbq7I~
  #endif                                                           //~v61nI~
#endif	//!WXE                                                     //~v61nI~
////ualloc trace init                                                //~v07iM~
//    sprintf(wkfname,"%s%s%s.mtr",Gworkdir,PGMID,Sostype);          //~v08xR~
//    ualloc_init(Smalloctrcopt,wkfname);                            //~v07iM~
////utrace init                                                      //~v07iM~
//    sprintf(wkfname,"%s%s%s.trc",Gworkdir,PGMID,Sostype);          //~v08xR~
//    if (Stesttrcopt)       //specified                             //~v07iM~
//    {                                                              //~v716I~
//        Stesttrcopt=2;     //ignore open err                       //~v07iM~
//        Gotheropt|=GOTHERO_TRACEON; //notify to xe3270             //~v716I~
//    }                                                              //~v716I~
////#ifndef NOTRACE                                                  //~v69GR~
////  if (rc=UTRACE_INIT(wkfname,Stesttrcopt),rc)                    //~v69GR~
//    if (rc=utrace_init(wkfname,Stesttrcopt),rc) //to be called also to set notrace//~v69GI~
//        uerrmsg("UTRACE file(%s) open err,errno=%d",               //~v07iM~
//                "トレースファイル(%s) オープンエラー,errno=%d",    //~v07iM~
//                wkfname,rc);                                       //~v07iM~
////#endif                                                           //~v69GR~
//env init                                                         //~v59DI~
	dcmdenvinit(Sostype);                                          //~v59DR~
                                                                   //~v501I~
//#ifdef WXE                                                       //~v641R~
#ifdef WXEXXE                                                      //~v641I~
}//preinit                                                         //~v501I~
if (Preqtype==WXE_REQ_INIT)                                        //~v501I~
{                                                                  //~v501M~
#endif                                                             //~v501M~
#ifdef WXE                                                         //~v7ahM~
    if (Shelpsw)                                                   //~v7ahI~
    {                                                              //~v7ahI~
        help();                                                    //~v7ahI~
        return -1;                                                 //~v7ahI~
    }                                                              //~v7ahI~
#endif                                                             //~v7ahM~
//*get other parm                                               //~5429I~
    if (inigetparm(Sinifile))                                      //~v0a3R~
        ubell();                                                   //~v0a3R~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50M~
//  xeebc_init(XEEBCIO_INIT,0/*cfg filename*/);//call before inigetopt and after inigetparm to ebcdic cp290 init//~va50I~//~vbBcR~
    xeebc_init(XEEBCIO_INIT,SebccfgCLP/*cfg filename*/);//call before inigetopt and after inigetparm to ebcdic cp290 init//~vbBcI~
#endif //UTF8EBCS raw ebcdic file support                          //~va50M~
    inigetopt();         //get saved option                        //~v11yR~
    parmproc(parmc,parmp);  //get parm from exe parm            //~5429I~
//*uerrexit function init
#ifndef UNX                                                        //~v195I~
  #ifndef WXE                                                      //~v500I~
    if (UCBITCHK(Gopt,GOPTPOPUPERRMSG)) //popup err msgsw
    {                                                           //~v05dI~
//      uerrmsg_init(0,(FILE*)0xffffffff,0);    //popup err msg //~v03wR~
        Suerrmsgopt=(Suerrmsgopt|UERR_ATTR);                    //~v05dR~
//      uerrmsg_init(0,(FILE*)(PVOID)(ULONG)upopupmsg,Suerrmsgopt);    //popup err msg//~v05dI~//~vafpR~
        uerrmsg_init(0,(FILE*)(PVOID)(ULPTR)upopupmsg,Suerrmsgopt);    //popup err msg//~vafpI~
    }                                                           //~v05dI~
    else
  #endif //!WXE                                                    //~v500I~
#endif                                                             //~v195I~
    {                                                              //~va76I~
#ifdef WXE                                                         //~va76I~
    	if (!(Gwxestat & GWXES_CP932))                             //~va76I~
	      	Suerrmsgopt=UERR_FORCE_ENGLISH;                        //~va76I~
#endif                                                             //~va76I~
        uerrmsg_init(0,0,Suerrmsgopt);//no popup err msg,display on hdr line//~v05dR~
    }                                                              //~va76I~
#ifndef WXE                                                        //~v500I~
//*uerrexit setup
    sprintf(mapfname,"%s%s%s.map",Gworkdir,PGMID,Sostype);         //~v08xR~
    uerrexit_init(Spgmver,stdout,mapfname,uexitfunc,0);//no parm//~5118R~
#endif                                                             //~v500I~

//#ifndef WXE                                                      //~v61nR~
////#ifdef DOS                                                     //~v61nR~
//#if defined(DOS) && !defined(DPMI)                               //~v61nR~
//#else                                                            //~v61nR~
////*ueh register                                                  //~v61nR~
//    sprintf(dumpfname,"%s%s%s.dmp",Gworkdir,PGMID,Sostype);      //~v61nR~
////  uregrec.UERGheapsize=Ginitheap;//initial heap size by 64kb   //~v61nR~
//    uregrec.UERGheapsize=0;//no initial heap size                //~v61nR~
//    uregrec.UERGmapfn=mapfname;     //map file name              //~v61nR~
//    uregrec.UERGdumpfn=dumpfname;       //map file name          //~v61nR~
//    uregrec.UERGuxfunc=uehexit;                                  //~v61nR~
//    uregrec.UERGparm=0;     //user parm to exit func             //~v61nR~
//#ifdef UNX                                                       //~v61nR~
//    uregrec.UERGsys.PPrevSignalHandler=0;     //no handler,back to OS//~v61nR~
//#endif                                                           //~v61nR~
//    useteh(&uregrec);/*exception handler unset*/                 //~v61nR~
////  heapsz=uregrec.UERGheapsize<<16;                             //~v61nR~
//#endif                                                           //~v61nR~
//#endif  //!WXE                                                   //~v61nR~
                                                                   //~v099I~
#ifdef DPMI                                                        //~v099I~
    uharderr(0);    //fail if drive notready                       //~v099I~
#else                                                              //~v099I~
#endif                                                             //~v099I~
    funcsp_init(0);          //before ini recovery of cwd by Scurdir//~v77ZR~
    if (Srestorecdsw)        //restore required                    //~v11yI~
        inirestcd();         //restore saved CD                    //~v11yI~
//  funcinit();                                                    //~v705R~
    funcinit(Sostype);                                             //~v705I~
    fileinit();     //tab char init etc
//  scrinit();                                                     //~v47mR~
//  scrinit(Sheightparm);                                          //~v47rR~
    scrinit(Sscrparm);                                             //~v47rI~
    paninit();                                                  //~v032I~
    kbdinit();
//  funcsp_init(0);                                                //~vba2R~//~v77ZR~
    dcmdinit(0);                                                   //~v781R~
#ifdef UNX                                                         //~v19FI~
    dlcmdundelinit();   //undel top dirname edit by userid         //~v19FI~
#endif                                                             //~v19FI~
#ifdef FTPSUPP                                                     //~v53UI~
    xeftpinit(Sftpopt,Shostsfnm);        //undel top dirname edit by userid//~v54nR~
#endif                                                             //~v53UI~
    xesyninit(0);                                                  //~v780R~
//****************************
    Sinitend=1;                                                 //~4C27I~
    if (Sallocexit)                                                //~v0bxI~
        ualloc_init(UALLOC_ERREXIT,0);  //req return when alloc err//~v0bxI~
    else                                                           //~v0bxI~
    ualloc_init(UALLOC_ERRRETURN,0);    //req return when alloc err//~v04dI~
    ubell_init((Gopt4 & GOPT4NOBEEP)==0);   //beep if nobeep is off//~v13mI~
    ubell_init2(&Gkbdinpctr);           //for dup chk              //~v141I~
    uerrmsg_initcomp();	//issue                                    //~vbi6I~
//#ifdef WXE                                                       //~v641R~
#ifdef WXEXXE                                                      //~v641I~
}//WXE_REQ_INIT                                                    //~v500I~
#endif                                                             //~v500I~
                                                                   //~v500I~
//#ifndef WXE     //at xewxe for WXE                               //~v641R~
#ifndef WXEXXE     //at xewxe for WXE                              //~v641I~
                                                                   //~v500I~
    for (;;)    //until quit
    {
        if (!*Gcmdbuff) //no command pending
            scrdisp();
        if (kbdproc()==-1)  //quit
            break;
    }
#endif //!WXE	                                                   //~v500I~
                                                                   //~v500I~
//#ifdef WXE                                                       //~v641R~
#ifdef WXEXXE                                                      //~v641I~
if (Preqtype==WXE_REQ_TERM)                                        //~v500I~
{                                                                  //~v500I~
#endif                                                             //~v500I~
	Gufile_opt|=GFILEOPT_XETERMINATING;	//   0x0400 //xe ytermination avoid toolongname errmsg at dlterm//~vb7pI~
    ubell_init(1);   //beep restart                                //~v13mI~
    ualloc_init(UALLOC_ERREXIT,0);  //req return when alloc err //~v04dI~
    UCBITON(Gprocstatus,GPROCSTERM);    //termination in progress//~5228I~
    xesynterm(0);                                                  //~v780R~
//  fcmdwfparm();   //save find/change parmm                    //~v064R~
    inisaveopt();         //save option                         //~v064I~
                                                                //~v064I~
    if (((FUNCTBL*)Gproclastpft)->FTfuncid==FUNCID_CANCEL       //~5228R~
    ||  ((FUNCTBL*)Gproclastpft)->FTfuncid==FUNCID_QUIT)        //~5228R~
        UCBITON(Gprocstatus,GPROCSCANTERM);//cancel Clipboard file//~5228I~
//  else                                                        //~v064R~
//      if (UCBITCHK(Gprocstatus,GPROCSINIUPDATE)) //ini status updated//~v064R~
//          func_ini(0);    //update write                      //~v064R~
    if (UCBITCHK(Gprocstatus,GPROCSINIUPDATE)) //ini status updated//~v0itI~
        func_ini(0);    //update write                             //~v0itI~
    dlcmdundelterm();   //undelete housekeeping                 //~v05uI~
    dcmdterm(); //clear temporary stdout redirect file          //~v06nI~
    funcsp_term(0);                                                //~vba2I~
    fileterm(); //must before scrterm                           //~5224R~
#ifdef FTPSUPP                                                     //~v53UI~
    xeftpterm();        //undel top dirname edit by userid         //~v53UI~
#endif                                                             //~v53UI~
    kbdterm();  //restore kbd rate at entry                        //~v19iI~
    panterm();                                                     //~v78jI~
    scrterm();
//  panterm();                                                     //~v78jR~
    functerm();                                                 //~5114I~
//  kbdterm();  //restore kbd rate at entry                        //~v19iR~
#ifdef UTF8SUPPH                                                    //~v90mI~//~va00I~
    xeutf_init(XEUTFIO_RESET);                                     //~v90nR~//~va00I~
#endif //!WXE                                                      //~v90mI~//~va00I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    xeebc_term(0);                                                 //~va50I~
#endif //UTF8EBCS raw ebcdic file support                          //~va50I~
    gblterm();  //free gbl before malloc chk                    //~v051I~
#ifndef WXE                                                        //~v500I~
#ifndef UNX                                                        //~v500I~
#if defined(DOS) || defined(W32)                                   //~v085R~
#else                                                           //~5528I~
        printf("\n");   //skip hdr blue line                    //~5528I~
#endif                                                          //~5528I~
#endif //!UNX                                                      //~v500I~
#endif //!WXE                                                      //~v500I~
//  Sinitend=0;         //avoid abend at uexitfunc              //~5131R~
//  uexitfunc(0);                                               //~5131R~
//  Sinitend=1;         //abend if more free                    //~5131R~
//*malloc statistic 
    if (Smalloctrcopt)
    {
//      if (Smalloctrcopt==2)                                      //~v53sR~
        if (Smalloctrcopt==2||(Smalloctrcopt&UALLOC_TRACE2))       //~v53sR~
            uatrcopt="Active";
        puad=ugetallocdata();
        printf("malloc statistic data (trace is %s)\n"             //~v085R~
"           alloc   req: %8ld times  total %8ld byte(net %8ld)\n"  //~v085R~
"           free    req: %8ld times  total %8ld byte\n"            //~v085R~
#if defined(DOS) || defined(W32) || defined(UNX)                   //~v19PR~
#else                                                              //~v085I~
"           alloc16 req: %8ld times  total %8ld byte(net %8ld)\n"  //~v085R~
"           free16  req: %8ld times  total %8ld byte\n"            //~v085R~
#endif                                                             //~v085I~
"           %8ld times,%8ld byte free more required\n"             //~v085R~
#if defined(DOS) || defined(W32) || defined(UNX)                   //~v19PR~
"           allocated maximum is %8ld\n",                          //~v085I~
#else                                                              //~v085I~
"           allocated maximum is %8ld ,for seg16 %8ld\n",          //~v085R~
#endif                                                             //~v085I~
                uatrcopt,
                puad->allocctr,
                puad->alloclen,
                puad->netreqlen,                                //~5528I~
                puad->freectr,
                puad->freelen,
#if defined(DOS) || defined(W32) || defined(UNX)                   //~v19PR~
#else                                                              //~v085I~
                puad->alloc16ctr,
                puad->alloc16len,
                puad->netreq16len,                              //~5528I~
                puad->free16ctr,
                puad->free16len,
#endif                                                             //~v085M~
    (resctr=puad->allocctr+puad->alloc16ctr-puad->freectr-puad->free16ctr),//~5106R~
    (reslen=puad->alloclen+puad->alloc16len-puad->freelen-puad->free16len),//~5106R~
#if defined(DOS) || defined(W32) || defined(UNX)                   //~v19PR~
                puad->maxlen                                       //~v085I~
#else                                                              //~v085I~
                puad->maxlen,
                puad->max16len                                  //~5528R~
#endif                                                             //~v085I~
                );
#ifdef DOS                                                      //~5528I~
#else                                                           //~5528I~
//chk not used stack                                            //~v01cM~
    #ifdef W32                                                     //~v085I~
	  #ifndef WXE                                                  //~v500I~
       #ifndef ULIB64X                                             //~vafqI~
        ugetstackaddr(&pstacktop,&pstackend);                      //~v085R~
        resstacklen=pstackend-pstacktop;                           //~v085I~
        printf("           committed stack size is %8d\n",resstacklen);//~v085I~
	   #endif //!ULIB64X                                           //~vafqI~
	  #endif //!WXE                                                //~v500I~
    #else                                                          //~v085I~
      #ifndef UNX                                                  //~v654I~
        memset(nullcomp,0,NULLCOMP);                            //~v01cM~
        for (pc=Spstacktop,resstacklen=0;;pc+=NULLCOMP,resstacklen+=NULLCOMP)//~v01cM~
            if (memcmp(pc,nullcomp,NULLCOMP))                   //~v01cM~
                break;                                          //~v01cM~
        printf("           not used stack size is %8d\n",resstacklen);//~v01cM~
//      printf("           initial heap allocation is %8ld byte\n",//~v0f1R~
//              heapsz);                                           //~v0f1R~
      #endif                                                       //~v654I~
    #endif                                                         //~v085M~
#endif                                                          //~5528I~
#if defined(ULIB64X)&&!defined(_DEBUG)  //free size is not available//~vafpI~
        if (resctr)                                                //~vafpI~
        {                                                          //~vafpI~
            ualloc_init(0,0);   //close trace file                 //~vafpI~
            uerrexit("==========MORE %ld times free required ===\n",0,//~vafpI~
                        resctr);                                   //~vafpI~
        }                                                          //~vafpI~
#else                                                              //~vafpI~
        if (resctr || reslen)                                   //~5106I~
        {                                                       //~v03jI~
            ualloc_init(0,0);   //close trace file              //~v03jI~
            uerrexit("==========MORE %ld byete(%ld times) free required ===\n",0,//~5502R~
                        reslen,resctr);                         //~5502I~
        }                                                       //~v03jI~
#endif                                                             //~vafpI~
    }//debug option
    Sinitend=0;         //avoid abend at uexitfunc              //~5111I~
  if (!Sskipuseteh)                                                //~vbq7I~
  {                                                                //~vbq7I~
#ifdef DOS                                                      //~5111I~
    #ifdef DPMI                 //DPMI version                     //~v095I~
        ureseteh(&uregrec);/*exception handler unset*/             //~v095I~
    #else                       //not DPMI                         //~v095I~
    #endif                      //DPMI or not                      //~v095I~
#else                                                           //~5111I~
  #ifndef WXE                                                      //~v500I~
    ureseteh(&uregrec);/*exception handler unset*/              //~5111I~
  #endif //!WXE                                                    //~v500I~
#endif                                                          //~5111I~
  }                                                                //~vbq7I~
//*printf last errmsg when quit
    if (!UCBITCHK(Gopt,GOPTPOPUPERRMSG))    //not popup err msgsw
        if (errmsg=ugeterrmsg(),errmsg) //uerrmsg called
        {                                                          //~v79zI~
#ifdef WCSUPP                                                      //~v79zI~
	#ifdef LNX	                                                   //~vawKI~
            uerrfprintfutf(UERRFPUO_NOEDIT|UERRFPUO_CVL2F,0/*stdout*/,"%s\n",errmsg); //cv to utf8 if utf8 and dbcs env//~vawKR~
    #else                                                          //~vawKI~
            uerrfprintfutf(UERRFPUO_NOEDIT,0/*stdout*/,"%s\n",errmsg); //cv to utf8 if utf8 and dbcs env//~v79zR~
    #endif                                                         //~vawKI~
#else                                                              //~v79zI~
            printf("%s\n",errmsg);
#endif                                                             //~v79zI~
        }                                                          //~v79zI~
    titlemsg();                                                 //~5204R~
#ifdef DPMI                                                        //~v099I~
    uharderr(-1);   //reset hard err                               //~v099I~
#else                                                              //~v099I~
#endif                                                             //~v099I~
#ifndef XXE                                                                   //~v500I~//~vbi9R~
    utrace_term(0);  //close utrace file and stop utrace                                                //~v500I~//~vb26M~
#endif                                                             //~vbi9I~
//#ifdef WXE                                                       //~v641R~
#ifdef WXEXXE                                                      //~v641I~
}//WXE_REQ_TERM                                                    //~v500I~
#endif                                                             //~v500I~
    return 0;
}//main
//************************************************                 //~vc71I~
#ifdef ARMXXE                                                      //~vc71I~
int xemainOnDestroy()                                              //~vc71I~
{                                                                  //~vc71I~
	UTRACEP_FLUSH("%s:entry\n",UTT);                               //~vc71R~
    dcmdterm(); //clear temporary stdout redirect file,=6 lock file//~vc71I~
	UTRACEP_FLUSH("%s:exit before utrace_term\n",UTT);             //~vc71I~
    utrace_term(0);  //close utrace file and stop utrace           //~vc71I~
    return 0;
}                                                                  //~vc71I~
#endif                                                             //~vc71R~
//************************************************
//*called from uerrexit                          *
//************************************************
void uexitfunc(char * Pmsg,void * Pvoid)                           //~v07wR~
{
#ifdef DOS                                                         //~v07wI~
    #ifdef DPMI                 //DPMI version                     //~v095I~
    #else                       //not DPMI                         //~v095I~
    char *dumpfnm;                                                 //~v07wR~
    #endif                      //DPMI or not                      //~v095I~
#endif                                                             //~v07wI~
//******************
    scrreset();                                                 //~4C27I~
#ifdef UNX                                                         //~v19iR~
    kbdterm();                                                     //~v19iR~
#endif //UNX                                                       //~v19iR~
    printf("\n");                                               //~v03sM~
//#ifdef DOS                                                       //~v095R~
#if defined(DOS) && !defined(DPMI)                                 //~v095I~
    if (Pmsg!=(PVOID)(ULONG)-1) //first entry                      //~v07wR~
//  uerrmsg_init(Spgmver,stdout,0);//no title change,uehmsg to stdout//~v21iR~
    uerrmsg_init(Spgmver,stdout,Suerrmsgopt);//no title change,uehmsg to stdout//~v21iI~
    else    //return dump fname                                    //~v07wI~
    {                                                              //~v07wI~
        dumpfnm=Pvoid;  //output area                              //~v07wI~
        if (!UCBITCHK(Gopt,GOPTNOABENDIFERREXIT))                  //~v07wI~
        {                                                          //~v07wI~
            sprintf(dumpfnm,"%s%s%s.dmp",Gworkdir,PGMID,Sostype);//request dump//~v08xR~
        }                                                          //~v07wI~
        else                                                       //~v07wI~
            *dumpfnm=0;     //no dump req                          //~v07wI~
    }                                                              //~v07wI~
//  fcloseall();                                                   //~v07wR~
#else                                                           //~5204I~
//  if (Pvoid!=(PVOID)(-1)) //not from ueh                  //~4C23I~//~vafkR~
    if (Pvoid!=(PVOID)(ULPTR)(-1)) //not from ueh                  //~vafkI~
    {                                                              //~v099I~
        #ifdef DPMI                                                //~v099I~
            uharderr(-1);   //reset hard err                       //~v099I~
        #else                                                      //~v099I~
        #endif                                                     //~v099I~
#ifdef UNX                                                         //~v69EI~
        printf("uexitfunc:uerrexitmsg:%s\n",ugeterrmsg());         //~v69EI~
#endif                                                             //~v69EI~
        if (Sinitend)   //entered getchar loop                  //~4C27I~
            if (!UCBITCHK(Gopt,GOPTNOABENDIFERREXIT))           //~5430R~
            {                                                      //~vbkmI~
//  		    utrace_term(0);  //it will be closed at ueh.c      //~vbkmR~
                uabend(1,0,0,0);    //_fcloseall at ueh.c       //~v03jR~
            }                                                      //~vbkmI~
    }                                                              //~v099I~
#endif                                                          //~5204I~
    return;
}

//#ifdef DOS                                                       //~v095R~
#if defined(DOS) && !defined(DPMI)                                 //~v095I~
#else
//************************************************
//*called from ueh                                *
//************************************************
void uehexit(int Pentrytype,PUEXREGREC Ppuregrec)
{
#ifdef UTF8SUPPH   //merged version                                //~va00I~
#ifdef UNX                                                         //~va00I~
    char *errmsg;                                                  //~va00I~
#endif                                                             //~va00I~
#endif                                                             //~va00I~
//**********************
    switch(Pentrytype)
    {
    case 0:
        #ifdef DPMI                                                //~v099I~
            uharderr(-1);   //reset hard err                       //~v099I~
        #else                                                      //~v099I~
        #endif                                                     //~v099I~
        #ifdef W32                                                 //~v159I~
            uvio_w95buffmode(0);    //reset for abend msg          //~v159I~
        #endif                                                     //~v159I~
//      uerrmsg_init(Spgmver,stdout,0);//no title change,uehmsg to stdout//~v21iR~
        uerrmsg_init(Spgmver,stdout,Suerrmsgopt);//no title change,uehmsg to stdout//~v21iI~
        scrreset();                     //back to original mode //~4C23I~
#ifdef UTF8SUPPH   //merged version                                //~va00I~
#ifdef UNX                                                         //~va00I~
        if (errmsg=ugeterrmsg(),errmsg) //uerrmsg called           //~va00I~
            uerrfprintfutf(UERRFPUO_NOEDIT,0/*stdout*/,"%s\n",errmsg); //cv to utf8 if utf8 and dbcs env//~va00I~
#endif                                                             //~va00I~
#endif                                                             //~va00I~
        break;
    case 2:         //after dump taken                          //~4C23R~
//      uexitfunc(0,(PVOID)(-1));                               //~5204R~//~vafkR~
        uexitfunc(0,(PVOID)(ULPTR)(-1));                           //~vafkI~
        break;
    }//sw by entry type
    return;
}
#endif
                                                                //~5429I~
//************************************************                 //~v79HI~
//* create workdir on other than c:\ **                            //~v79HR~
//* if failed to all drive lcreate on temp dir                     //~v79HI~
//rc:0 found,1:created, 4 failed                                   //~v79HI~
//************************************************                 //~v79HI~
int xecreateworkdir(char *Pfpath,char *Pwkdir)                     //~v79HI~
{                                                                  //~v79HM~
    char didlist[32],*pc;                                          //~v79HM~
    int  didno,ii,drivetype,rc=0,pathlen;                          //~v79HM~
    char fpath[_MAX_PATH];                                         //~v79HM~
//***********************                                          //~v79HM~
	drivetype=UDDC_FIXED;                                          //~v79HM~
    didno=ugetdriveidlist(drivetype,didlist);    //get driveid list//~v79HM~
    for (ii=0,pc=didlist;ii<didno;ii++,pc++)                       //~v79HM~
    {                                                              //~v79HM~
        if (toupper(*Pwkdir)==toupper(*pc))	//c: already chked     //~v79HM~
        	continue;                                              //~v79HM~
//  	printf("drive type%d=%c\n",drivetype,*pc);                 //~v79HI~
        sprintf(fpath,"%c%s",*pc,Pwkdir+1);                        //~v79HM~
//  	printf("stat %s\n",fpath);                                 //~v79HI~
		if (!ufstat(fpath,0))   //found                            //~v79HM~
        	break;                                                 //~v79HM~
//      sprintf(rootdir,"%c:\\",*pc);                              //~v79HI~
//  		printf("mkdir %s\n",fpath);                            //~v79HI~
        if (!umkdir(fpath))                                        //~v79HR~
        {                                                          //~v79HR~
            rc=1;       //created                                  //~v79HR~
            break;                                                 //~v79HR~
        }                                                          //~v79HR~
    }                                                              //~v79HM~
    if (ii>=didno)	//not created                                  //~v79HM~
    {                                                              //~v79HM~
        if (utempnam("","",fpath) && (pathlen=PATHLEN(fpath))>0)   //~v79HM~
        {                                                          //~v79HM~
        	strcpy(fpath+pathlen,Pwkdir+3);                        //~v79HM~
			if (ufstat(fpath,0))   //not found                     //~v79HM~
            {                                                      //~v79HM~
        		if (!umkdir(fpath))                                //~v79HM~
            		rc=1;       //created                          //~v79HM~
            	else                                               //~v79HM~
                	rc=4;                                          //~v79HM~
            }                                                      //~v79HM~
        }                                                          //~v79HM~
    }                                                              //~v79HM~
    if (rc<=1)                                                     //~v79HM~
    	strcpy(Pfpath,fpath);                                      //~v79HM~
    return rc;                                                     //~v79HM~
}//createnonprotworkdir                                            //~v79HM~
#ifdef W32                                                         //~vbvjI~
//************************************************                 //~vbvjI~
//* get work dir name                                              //~vbvjI~
//************************************************                 //~vbvjI~
int getHomeDir(char *PfpathOut)                                    //~vbvjI~
{                                                                  //~vbvjI~
	char *pc;	                                                   //~vbvjI~
    int rc;                                                        //~vbvjI~
    *PfpathOut=0;                                                  //~vbvjI~
    pc=getenv(HOMEDIR);                                            //~vbvjI~
    if (pc && *pc)                                                 //~vbvjR~
    {                                                              //~vbvjI~
    	if (*(pc+1)==':')                                          //~vbvjI~
        	strcpy(PfpathOut,pc);                                  //~vbvjI~
        else                                                       //~vbvjI~
	    	if (*(pc)=='\\')                                       //~vbvjI~
	        	sprintf(PfpathOut,"c:%s",pc);                      //~vbvjI~
            else                                                   //~vbvjI~
	        	sprintf(PfpathOut,"c:\\%s",pc);                    //~vbvjI~
    }                                                              //~vbvjI~
    rc=*PfpathOut!=0;                                              //~vbvjI~
    UTRACEP("%s:rc=%d,getenv=%s,env=%s,fpath=%s\n",UTT,rc,pc,HOMEDIR,PfpathOut);//~vbB5R~
    if (rc)                                                        //~vbvjI~
        strcat(Gworkdir,XE_WKDIR+2);                               //~vbvjR~
    return rc;                                                     //~vbvjI~
}                                                                  //~vbvjI~
#endif                                                             //~vbvjI~
//************************************************                 //~v79zI~
//* get work dir name                                              //~v79zM~
//************************************************                 //~v79zI~
int  xegetworkdir(void)                                            //~v79zI~
{                                                                  //~v79zI~
    char *pc;                                                      //~v79zI~
#ifdef UNX                                                         //~v79zI~
  #ifndef ARM                                                      //~vbr1R~
    char fpathwk[_MAX_PATH];                                       //~v79zI~
  #endif                                                           //~vbr1R~
	uid_t uid;                                                     //~v79zI~
	gid_t gid;                                                     //~v79zI~
#endif                                                             //~v79zI~
//  char wkfname[_MAX_PATH];                                       //~vbs7R~
    char wkfname[_MAX_PATH+256];                                   //~vbs7I~
    size_t   rpos;                                                 //~v79zI~
#ifdef W32                                                         //~v79HI~
	int rcw;                                                       //~v79HI~
    char *wdEnv=0;                                                 //~vbzsI~
#endif                                                             //~v79HI~
//********************                                             //~v79zI~
    if (!*Gworkdir)         //no work dir name parm             //~5118R~
    {
        if (!(pc=getenv(PGMID)))                                //~4C24I~
        {                                                       //~4C24I~
#ifdef UNX                                                         //~v19SM~
    #ifdef ARM                                                     //~va90I~
        	sprintf(Gworkdir,"%s",ARM_XE_WKDIR);                   //~va90I~
    #else                                                          //~va90I~
//  		sprintf(Gworkdir,"/tmp/%s_wd%%",PGMID);                //~v45FR~
            ufullpath(fpathwk,"~",_MAX_PATH);                      //~v45FI~
            if (ROOTDIR(fpathwk))                                  //~v45FI~
				sprintf(fpathwk,"/tmp/%s_wd%%",PGMID);             //~v45FI~
            else                                                   //~v45FI~
    			sprintf(fpathwk,"~/%s_wd%%",PGMID);                //~v45FR~
            ufullpath(Gworkdir,fpathwk,_MAX_PATH);                 //~v45FR~
    #endif                                                         //~va90I~
            pc=Gworkdir;                                           //~v19SI~
#else //!UNX                                                       //~v19SM~
        sprintf(Gworkdir,"%s",XE_WKDIR);                           //~v501I~
        pc=Gworkdir;                                               //~v501I~
#endif//!UNX                                                       //~v195I~
        }   //env var not exist
#ifdef W32                                                         //~vbzsI~
        else                                                       //~vbzsI~
        	wdEnv=pc;                                              //~vbzsI~
#endif                                                             //~vbzsI~
        pc+=strspn(pc," ");                                        //~v10SI~
        strcpy(Gworkdir,pc);                                    //~5118R~
        rpos=ustrrspn(Gworkdir," ");                               //~v10SI~
        if (rpos!=(size_t)-1)                                      //~v10SR~
            *(Gworkdir+rpos+1)=0;                                  //~v10SR~
    }
                                                                //~5118I~
    if (!ufullpath(wkfname,Gworkdir,_MAX_PATH))                 //~5118I~
        exit(8);                                                //~5118I~
#ifdef UNX                                                         //~v19SI~
//edit uid in workdirname and create                               //~v19SR~
	if (pc=strchr(wkfname,'%'),pc)	//having %                     //~v19SI~
    {                                                              //~v19SI~
		ugetugid(&uid,&gid);	//get user-id                      //~v79zI~
    	rpos=(ULONG)pc-(ULONG)wkfname;                             //~v19SI~
        memcpy(Gworkdir,wkfname,rpos);                             //~v19SI~
        sprintf(Gworkdir+rpos,"%05d",uid);                         //~v79zR~
        strcpy(Gworkdir+rpos+5,wkfname+rpos+1);                    //~v19SI~
    	if (ufstat(Gworkdir,0))	//not found                        //~v19SI~
        {                                                          //~v53rI~
        	if (!umkdir(Gworkdir))	                               //~v19SI~
            	uerrmsg("WorkDir %s is now created",               //~v19SI~
                        "ワークディレクトリー %s を作成しました",  //~v19SR~
						Gworkdir);                                 //~v19SI~
            else                                                   //~v19SI~
            	exit(8);                                           //~v19SI~
        }                                                          //~v53rI~
    }                                                              //~v19SI~
#else //!UNX                                                       //~v19SI~
    strcpy(Gworkdir,wkfname);                                   //~5118I~
    UTRACEP("%s:wkfname=%s,fstat=%d\n",wkfname,ufstat(Gworkdir,0));//~vbvjI~
    if (ufstat(Gworkdir,0))	//not found                            //~v500I~
    {                                                              //~v79HI~
#ifdef W32                                                         //~v79HM~
		if (wdEnv)                                                 //~vbzsR~
        	uerrexit("Dir(%s) by Environment %s=%s\n",             //~vbzsR~
            		"%s が見つかりません。環境変数 %s=%s 不正です。",//~vbzsR~
                    Gworkdir,PGMID,wdEnv);                         //~vbzsR~
        if (getHomeDir(wkfname))	//getenv succeeded             //~vbvjR~
        	sprintf(Gworkdir,"%s%s",wkfname,XE_WKDIR+2);           //~vbvjR~
      if (ufstat(Gworkdir,0))	//not found                        //~vbvjI~
      {                                                            //~vbvjI~
#ifndef NOTRACE                                                    //~vbB5M~
        if (!strcmp(Gworkdir,XE_WKDIR)) //default                  //~vbB5I~
        	uerrexit("Trap for wkdir under ndef NOTRACE; cretae c:\xe_wd(USERPROFILE=%s)\n",0,//~vbB5I~
						    getenv(HOMEDIR));                      //~vbB5M~
#endif                                                             //~vbB5M~
        if (umkdir(Gworkdir))   //create failed                    //~v79HI~
        {                                                          //~v79HI~
            if (!strcmp(Gworkdir,XE_WKDIR)) //default              //~v79HR~
            {                                                      //~vbzzI~
            	rcw=xecreateworkdir(Gworkdir,XE_WKDIR);            //~v79HR~
                if (rcw==4)                                        //~vbzzR~
                    uerrmsg("mkdir workdir(%s) failed, environment variable %s or %s will be used if set.\n",//~vbzzI~
                    		"ワークディレクトリ(%s)の作成に失敗、環境変数 %s や %s が設定されていればそこに作さえされます。\n",//~vbzzI~
                    		Gworkdir,PGMID,HOMEDIR);               //~vbzzI~
            }                                                      //~vbzzI~
            else                                                   //~v79HI~
            	rcw=4;	//exit                                     //~v79HI~
        }                                                          //~v79HI~
        else                                                       //~v79HI~
            rcw=1;  //created                                      //~v79HI~
        if (!rcw)                                                  //~v79HI~
            ;       //already exist                                //~v79HI~
        else                                                       //~v79HI~
        if (rcw==1)                                                //~v79HI~
#else                                                              //~v79HM~
        if (!umkdir(Gworkdir))                                     //~v500I~
#endif                                                             //~v79HM~
            uerrmsg("WorkDir %s is now created",                   //~v500I~
                        "ワークディレクトリー %s を作成しました",  //~v500I~
					Gworkdir);                                     //~v500I~
        else                                                       //~v500I~
            exit(8);                                               //~v500I~
      }//fstat fail                                                //~vbvjI~
    }                                                              //~v79HI~
#endif //!UNX                                                      //~v19SI~
    if (PATHLEN(Gworkdir)!=(int)strlen(Gworkdir))//last is not '\\'(SBCS)//~v085R~
    strcat(Gworkdir,DIR_SEPS);                                     //~v19aI~
//  fprintf(stderr,"workdir=%s\n",Gworkdir);                       //~vbzyR~
    return 0;                                                      //~v79zI~
}//xegetworkdir                                                    //~v79zI~
//**********************************************************************//~vb26I~
//**********************************************************************//~vb26I~
int xecleartrcfile(int Popt,char *Pfnm)                            //~vb26R~
{                                                                  //~vb26I~
	int ii,pos,fno,len,fnook=0,fnoerr=0,rc,pathlen;                //~vb26R~
    PUDIRLIST pudl,pudl0=0;                                        //~vb26R~
    char *pname;                                                   //~vb26I~
    char fpath[_MAX_PATH];                                         //~vb26I~
    int pid;                                                       //~vb26I~
#ifdef LNX                                                         //~vb26I~
    uid_t myuid;                                                   //~vb26I~
#endif                                                             //~vb26I~
	int keepctr,keptctr=0;                                         //~vbkmI~
//*****************                                                //~vb26I~
	keepctr=Popt & XCTFO_COUNT_MASK;                               //~vbkmI~
#ifdef LNX                                                         //~vb26I~
    ugetugid(&myuid,NULL);                                         //~vb26R~
#endif                                                             //~vb26I~
    pathlen=PATHLEN(Pfnm);                                         //~vb26I~
    if (pathlen<0)                                                 //~vb26I~
    	pathlen=0;                                                 //~vb26I~
    UmemcpyZ(fpath,Pfnm,(size_t)pathlen);                          //~vb26R~
	pos=(int)strlen(Pfnm)-pathlen-1;	//except last "*"          //~vb26R~
  if (keepctr)                                                     //~vbkmR~
    fno=udirlistnomsg(Pfnm,FILE_NORMAL,&pudl0,-'D'); //date descendant order//~vbkmM~
  else                                                             //~vbkmM~
    fno=udirlistnomsg(Pfnm,FILE_NORMAL,&pudl0,0/*no sort*/);       //~vbkmI~
    for (ii=0,pudl=pudl0;ii<fno;ii++,pudl++)                       //~vb26I~
    {                                                              //~vb26I~
#ifdef LNX                                                         //~vb26I~
        if (pudl->uid!=myuid)                                      //~vb26R~
        	continue;                                              //~vb26I~
#endif                                                             //~vb26I~
		if (keepctr)	//specified                                //~vbkmI~
        {                                                          //~vbkmI~
        	keptctr++;                                             //~vbkmI~
            if (keptctr<=keepctr)                                  //~vbkmR~
            	continue;                                          //~vbkmI~
        }                                                          //~vbkmI~
    	pname=pudl->name;                                          //~vb26I~
    	len=(int)strlen(pname)-pos;                                //~vb26I~
        if (len>0                                                  //~vb26I~
        &&  unumlen(pname+pos,0/*digit*/,len)==len                 //~vb26R~
        )                                                          //~vb26I~
        {                                                          //~vb26I~
        	pid=atoi(pname+pos);                                   //~vb26R~
            strcpy(fpath+pathlen,pname);                           //~vb26I~
    		if (ufiledelifnotopened(0,fpath,pid))                  //~vb26R~
            	fnoerr++;                                          //~vb26I~
            else                                                   //~vb26I~
            	fnook++;                                           //~vb26I~
        }                                                          //~vb26I~
    }                                                              //~vb26I~
    if (fno>0)                                                     //~vb26R~
	    UDIRLIST_FREE(pudl0);                                      //~vb26R~
    if (fnoerr)                                                    //~vb26I~
    	rc=-fnoerr;                                                //~vb26I~
    else                                                           //~vb26I~
    	rc=fnook;                                                  //~vb26I~
    return rc;                                                     //~vb26I~
}//xecleartrcfile                                                  //~vb26I~
//************************************************                 //~v79zI~
//* trace init                                                     //~v79zI~
//************************************************                 //~v79zI~
int  xetraceinit(void)                                             //~v79zI~
{                                                                  //~v79zI~
    int rc;                                                        //~v79zI~
//  char wkfname[_MAX_PATH];                                       //~v79zI~//~vbs7R~
    char wkfname[_MAX_PATH+256];                                   //~vbs7I~
#ifndef ARM                                                        //~vbr1R~
//  char wkfname2[_MAX_PATH];                                      //~vbkmI~//~vbs7R~
    char wkfname2[_MAX_PATH+256];                                  //~vbs7I~
    ULONG pid;                                                     //~vb26I~
#endif  //!ARM                                                     //~vbr1R~
//********************                                             //~v79zI~
#ifdef ARM                                                         //~vb26I~
    sprintf(wkfname,"%s%s%s.mtr",Gworkdir,PGMID,Sostype);          //~vb26I~
#else                                                              //~vb26I~
    pid=ugetpid();                                                 //~vb26I~
//ualloc trace init                                                //~v07iM~
    if (Smalloctrcopt & UALLOC_TRACE)	//open mtrace file         //~vb26I~
    {                                                              //~vb26I~
		sprintf(wkfname,"%s%s%s.mtr.*",Gworkdir,PGMID,Sostype);    //~vb26I~
		xecleartrcfile(0,wkfname);                                 //~vb26R~
    }                                                              //~vb26I~
//  sprintf(wkfname,"%s%s%s.mtr",Gworkdir,PGMID,Sostype);          //~v08xR~//~vb26R~
    sprintf(wkfname,"%s%s%s.mtr.%ld",Gworkdir,PGMID,Sostype,pid);  //~vb26I~
#endif  //!ARM                                                     //~vb26I~
//  ualloc_init(Smalloctrcopt,wkfname);                            //~v07iM~//~vb26R~
    ualloc_init(Smalloctrcopt|UALLOC_NOSHARE,wkfname);             //~vb26I~
//utrace init                                                      //~v07iM~
#ifdef ARM                                                         //~vb26I~
    sprintf(wkfname,"%s%s%s.trc",Gworkdir,PGMID,Sostype);          //~vb26I~
#else                                                              //~vb26I~
	sprintf(wkfname,"%s%s%s.trc.*",Gworkdir,PGMID,Sostype);        //~vb26I~
//  if (Stesttrcopt)	//open trace file                          //~vb26I~//~vbkmR~
    if (Stesttrcopt & ~UTRACEO_NOFORCE)                            //~vbkmI~
		xecleartrcfile(0,wkfname);                                 //~vb26R~
//  sprintf(wkfname,"%s%s%s.trc",Gworkdir,PGMID,Sostype);          //~v08xR~//~vb26R~
    sprintf(wkfname,"%s%s%s.trc.%ld",Gworkdir,PGMID,Sostype,pid);  //~vb26I~
	sprintf(wkfname2,"%s%s%s.trc%s.*",Gworkdir,PGMID,Sostype,UTRACE_FORCE_FNMSUFFIX);//~vbkmR~
	if (StesttrcoptClear)                                          //~vbkmM~
		xecleartrcfile(0,wkfname2); //clear all                    //~vbkmR~
    else                                                           //~vbkmI~
		xecleartrcfile(XCTFO_KBD_KEEP_COUNT,wkfname2);             //~vbkmI~
                                                                   //~vbkmI~
    if (!(Stesttrcopt & UTRACEO_NOFORCE))                          //~vbkmM~
    {                                                              //~vbkmI~
	    sprintf(wkfname2,"%s%s%s.trc%s.%ld",Gworkdir,PGMID,Sostype,UTRACE_FORCE_FNMSUFFIX,pid);//~vbkmI~
		utrace_init(wkfname2,UTRACEO_FORCEFNM);                    //~vbkmM~
    }                                                              //~vbkmI~
#endif  //!ARM                                                     //~vb26I~
//  if (Stesttrcopt)       //specified                             //~v07iM~//~vbkmR~
    if ((Stesttrcopt & ~UTRACEO_NOFORCE))                          //~vbkmI~
    {                                                              //~v716I~
//      Stesttrcopt=2;     //ignore open err                       //~v07iM~//~vbkmR~
        Stesttrcopt=UTRACEO_IGNOREOPENERR; //   0x02               //~vbkmR~
        Gotheropt|=GOTHERO_TRACEON; //notify to xe3270             //~v716I~
    }                                                              //~v716I~
//  if (rc=utrace_init(wkfname,Stesttrcopt),rc) //to be called also to set notrace//~v69GI~//~vb26R~
    if (rc=utrace_init(wkfname,Stesttrcopt|UTRACEO_NOSHARE),rc) //to be called also to set notrace//~vb26I~
        uerrmsg("UTRACE file(%s) open err,errno=%d",               //~v07iM~
                "トレースファイル(%s) オープンエラー,errno=%d",    //~v07iM~
                wkfname,rc);                                       //~v07iM~
    return 0;                                                      //~v79zI~
}//xetraceinit                                                     //~v79zI~
//************************************************                 //~v79zI~
//*get locale code                                                 //~v79zI~
//************************************************                 //~v79zI~
int  parmproc00(int Pparmc,char *Pparmp[])                         //~v79zI~
{                                                                  //~v79zI~
    int parmno,ch;                                                 //~v79zR~
    char *cptr;                                                    //~v79zI~
//#ifdef UNX                                                       //~v79MR~
    int posparmno=0,flagsw;                                        //~v79zR~
//#endif                                                           //~v79MR~
#ifndef UNX                                                        //~v79MI~
    char *pterm;                                                   //~v79MI~
#endif                                                             //~v79MI~
//#ifdef WINCON                                                    //~vbzrR~
//    char fpath[_MAX_PATH];                                       //~vbzrR~
//#endif                                                           //~vbzrR~
//  int swNotraceMapinit=0;                                        //~vbzuM~//~vbzKR~
    int swNotraceMapinit=1;                                        //~vbzKI~
//********************                                             //~v79zI~
#ifndef UNX                                                        //~v79MI~
    pterm=getenv("TERM");                                          //~v79MI~
    if (pterm && !strcmp(pterm,"cygwin"))                          //~v79MI~
		Gotherstatus|=GOTHERS_CYGWIN;       //cygwin term          //~v79MI~
    	                                                           //~v79MI~
#endif                                                             //~v79MI~
#ifdef ARM                                                         //~vad0I~
    Swcinitopt|=UDCWCIO_LOCALICU;//use ICU:default for ARM         //~vad0I~
#endif                                                             //~vad0I~
#ifdef W32                                                         //~vbz3I~
	#ifndef WXE                                                    //~vbz3I~
		Gulibutfmode|=GULIBUTF_APICHK_CSR; //0x08000000  //Default:utfwcwidth chr cursor step//~vbz3I~
    #else                                                          //~vbz4I~
		Gulibutfmode|=GULIBUTF_APICHK_CSR; //0x08000000  //Default:utfwcwidth chr cursor step//~vbz4I~
	#endif                                                         //~vbz3I~
#else                                                              //~vbz5I~
//  #ifdef XXE                                                     //~vbz5I~//~vbzpR~
		Gulibutfmode|=GULIBUTF_APICHK_CSR; //0x08000000  //Default:utfwcwidth chr cursor step//~vbz5I~
//  #endif                                                         //~vbz5I~//~vbzpR~
#endif                                                             //~vbz3I~
#ifdef WINCON                                                      //~vbzYR~
    Guvio2Stat|=UVIO2S_DRAWTEXTALL; //0x0400  //chk by TextDraw if extent is sbcs//~vbzFI~
#endif                                                             //~vbzYR~
    for (parmno=1;parmno<Pparmc;parmno++)                          //~v79zI~
    {                                                              //~v79zI~
        cptr=Pparmp[parmno];                                       //~v79zI~
//#ifdef UNX                                                       //~v79MR~
//      flagsw=CMDFLAGCHK(*cptr,posparmno); //not flag             //~v79MR~
        flagsw=CMDFLAGCHK_AND_CYGWIN(Gotherstatus&GOTHERS_CYGWIN,*cptr,posparmno); //not flag//~v79MI~
        if (!flagsw)    //filename parm                            //~v79zI~
        	posparmno++;                                           //~v79zI~
        else			//flag parm                                //~v79zI~
//#else                                                            //~v79MR~
//      if(*cptr=='/'||*cptr=='-')                                 //~v79MR~
//#endif                                                           //~v79MR~
        {//option                                                  //~v79zI~
            ch=*(++cptr);                      //first option byte //~v79zI~
            if (*(++cptr)==':')               // /o:x format       //~v79zI~
                cptr++;                         //skip :           //~v79zI~
            switch(toupper(ch))       //option                     //~v79zI~
            {                                                      //~v79zI~
            case 'H':                                              //~vbz3I~
            case '?':                                              //~vbz3I~
#ifdef W32                                                         //~vbz3I~
	#ifndef WXE                                                    //~vbz3I~
				Gulibutfmode&=~GULIBUTF_APICHK_CSR; //for performance//~vbz3I~
    #else                                                          //~vbz4I~
				Gulibutfmode&=~GULIBUTF_APICHK_CSR; //for performance//~vbz4I~
	#endif                                                         //~vbz3I~
#else                                                              //~vbz5I~
//  #ifdef XXE                                                     //~vbz5I~//~vbzpR~
				Gulibutfmode&=~GULIBUTF_APICHK_CSR; //for performance//~vbz5I~
//  #endif                                                         //~vbz5I~//~vbzpR~
#endif                                                             //~vbz3I~
	            Guvio2Stat|=UVIO2S_NOGLYPHCHK; //                0x0800  //no glyph chk for /help option//~vbAnI~
            	break;                                             //~vbz3I~
#ifdef WCSUPP                                                      //~v79zI~
//**************************                                       //~v79zI~
//* /C: Codepage                                                   //~v79zI~
//**************************                                       //~v79zI~
            case 'C':                                              //~v79zR~
#ifdef W32                                                         //~va0QI~
                if (strstr(cptr,"65001"))                          //~va0QI~
#else                                                              //~va0QI~
                if (ustrstri(cptr,"UTF"))                          //~va0QR~
#endif                                                             //~va0QI~
                {                                                  //~va0QI~
                    uerrexit("specify charset other than UTF8",    //~va0QR~
                    		"文字セットは UTF8 以外を指定してください");//~va0QR~
                }                                                  //~va0QI~
                if (!*cptr)                                        //~va7eI~
#ifdef W32                                                         //~va7eI~
                    uerrexit("specify charset, /C? will list available codepage",//~va7eI~
                    		"文字セットを指定してください。/C? で可\x94\\なコードページをリストします。");//~va7eR~
#else                                                              //~va7eI~
                    uerrexit("specify charset",                    //~va7eI~
                    		"文字セットを指定してください");       //~va7eI~
#endif                                                             //~va7eI~
//                if (                                               //~vbB6I~//~vbB8R~
//                    !stricmp(cptr,EBC_KANA)                        //~vbB6R~//~vbB8R~
//                  ||!stricmp(cptr,EBC_ENG)                         //~vbB6R~//~vbB8R~
//                  ||!stricmp(cptr,EBC_US)                          //~vbB6I~//~vbB8R~
//                )                                                  //~vbB6I~//~vbB8R~
//                {                                                  //~vbB6I~//~vbB8R~
//                    break;                                         //~vbB6I~//~vbB8R~
//                }                                                  //~vbB6I~//~vbB8R~
                if (                                               //~vamwI~
                    !stricmp(cptr-1,MODE_UTF8)                     //~vamwR~
                  ||!stricmp(cptr-1,MODE_LOCALE)                   //~vamwR~
                  ||!stricmp(cptr-1,MODE_ASIS)                     //~vamwR~
                  ||USTRHEADIS_IC(cptr-1,MODE_EBC)                 //~vamwR~
                )                                                  //~vamwI~
                {                                                  //~vamwI~
//                  uerrexit("specify \"%s\" without \"%c\" prefix as command line parameter.",//~vamwR~//~vbB6R~
//                  		"コマンドラインでは \"%s\" の前の \"%c\" は外してください",//~vamwR~//~vbB6R~
//                          cptr-1,*(cptr-2));                     //~vamwR~//~vbB6R~
                    uerrexit("%s/%s/%s/%s is Edit/Browse cmd option, simply specify it like as %s",//~vbB6I~
                             "%s/%s/%s/%s は Edit/Browse コマンドオプションです、単に %s などと指定してください",//~vbB6I~
                    MODE_UTF8,MODE_LOCALE,MODE_ASIS,MODE_EBC,MODE_UTF8);//~vbB6I~
                }                                                  //~vamwI~
        		strncpy(Gdefaultlocalecode,cptr,MAXLOCALESZ);      //~v79zR~
        		strncpy(Gparmlocalecode,cptr,MAXLOCALESZ);         //~vb2XR~
        		Swcinitopt|=UDCWCIO_FORCELOCALE;                   //~v79zI~
                break;                                             //~v79zI~
#endif                                                             //~v79zI~
//**************************                                       //~v07iM~
//* debug trace  /D                                                //~v07iM~
//**************************                                       //~v07iM~
            case 'D':                                              //~v07iM~
                switch(*cptr)                                      //~v07iM~
                {                                                  //~v07iM~
                case '0':                                          //~v07iM~
                case '1':                                          //~v07iM~
                case '2':                                          //~v07iM~
                case '3':                                          //~v53sI~
                    UCBITOFF(Gopt3,GOPT3DOSPRECIZEMA);             //~v08aI~
                    Smalloctrcopt=*cptr-'0';                       //~v07iM~
                    if (Smalloctrcopt==3)                          //~v53sR~
                        Smalloctrcopt=UALLOC_TRACE+UALLOC_TRACE2;  //~v53sR~
                    break;                                         //~v07iM~
//              case '@':                                          //~v0bxR~
                case '`':                                          //~v0bxI~
                case 'a':                                          //~v07iM~
                case 'b':                                          //~v07iM~
                    UCBITON(Gopt3,GOPT3DOSPRECIZEMA);              //~v07iM~
//                  Smalloctrcopt=*cptr-'@';                       //~v0bxR~
                    Smalloctrcopt=*cptr-'`';                       //~v0bxI~
                    break;                                         //~v07iM~
                case '@':                                          //~v0bxI~
                case 'A':                                          //~v0bxI~
                case 'B':                                          //~v0bxI~
                    UCBITON(Gopt3,GOPT3DOSPRECIZEMA);              //~v0bxI~
                    Sallocexit=1;           //errexit when alloc err//~v0bxI~
                    Smalloctrcopt=*cptr-'@';                       //~v0bxI~
                    break;                                         //~v0bxI~
                default:                                           //~v07iM~
                    uerrexit("memory trace option parm err(%s)",   //~v07iM~
                                "メモリートレースオプションエラー(%s)",//~v07iM~
                                cptr);                             //~v07iM~
                }                                                  //~v07iM~
                UCBITOFF(Gopt3,GOPT3TESTABEND|GOPT3TESTEXIT);//abend by double Esc//~v08aI~
                switch(*(++cptr))                                  //~v07iM~
                {                                                  //~v07iM~
                case 0:                                            //~v07iM~
                    Stesttrcopt=0;                                 //~v07iM~
                    break;                                         //~v07iM~
                case '0':                                          //~v07iM~
                case '1':                                          //~v07iM~
                    Stesttrcopt=*cptr-'0';                         //~v07iM~
                    switch(*(cptr+1))                              //~v07iM~
                    {                                              //~v07iM~
                    case 0  :                                      //~v099I~
                        break;                                     //~v099I~
                    case 'A':                                      //~v07iM~
                    case 'a':                                      //~v07iM~
                        UCBITON(Gopt3,GOPT3TESTABEND);//abend by double Esc//~v07iM~
                        break;                                     //~v07iM~
#ifdef ARM                                                         //~vbkmI~
#else                                                              //~vbkmI~
                    case 'C':                                      //~vbkmI~
                    case 'c':                                      //~vbkmI~
                        StesttrcoptClear=1;    //clear utrace FORCE file//~vbkmI~
                        break;                                     //~vbkmI~
                    case 'N':      //No force                      //~vbkmI~
                    case 'n':                                      //~vbkmI~
                  		Stesttrcopt|=UTRACEO_NOFORCE;//       0x0080     //ignore UTRACEPF(put trace regardless trace option)//~vbkmR~
                        break;                                     //~vbkmI~
#endif                                                             //~vbkmI~
                    case 'E':                                      //~v07iM~
                    case 'e':                                      //~v07iM~
                        UCBITON(Gopt3,GOPT3TESTEXIT);//uerrexit by double Esc//~v07iM~
                        break;                                     //~v07iM~
#ifdef W32                                                         //~v142I~
  #ifndef WXE                                                      //~v500I~
                    case 'k':   //w95 kbdtrace                     //~v142I~
                        ukbd_w95traceinit(KBD_PTRACE);             //~v780R~
                        break;                                     //~v780R~
                    case 'K':                                      //~v142I~
                        ukbd_w95traceinit(KBD_UTRACE);             //~v142I~
                        break;                                     //~v142I~
  #endif  //!WXE                                                   //~v500I~
#endif                                                             //~v142I~
                    default:                                       //~v099I~
                        uerrexit("test trace option parm err(%s)", //~v099I~
                                "テストトレースオプションエラー(%s)",//~v099I~
                                cptr);                             //~v099I~
                    }                                              //~v07iM~
                    break;                                         //~v07iM~
                default:                                           //~v07iM~
                    uerrexit("test trace option parm err(%s)",     //~v07iM~
                                "テストトレースオプションエラー(%s)",//~v07iM~
                                cptr);                             //~v07iM~
                }                                                  //~v07iM~
                break;                                             //~v07iM~
//#ifdef WINCON                                                      //~vbzqI~//~vbzrR~
#if defined(WINCON) || defined(LNXCON)                             //~vbzrI~
            case 'F':    //fontname and charset                    //~vbzqI~
                if (*cptr=='@')                                    //~vbzrI~
                {                                                  //~vbzrI~
//  				filefullpath(fpath+1,cptr+1,sizeof(fpath)-1);//~5318M~//~vbzrR~
//                  fpath[0]='@';                                  //~vbzrR~
//                  setConsoleFont(fpath);                         //~vbzrR~
                    SpFontParm=umalloc(strlen(cptr)+1);            //~vbzrR~
                    strcpy(SpFontParm,cptr);                       //~vbzrR~
                }                                                  //~vbzrI~
                else                                               //~vbzrI~
                {                                                  //~vbzrI~
                    if (*cptr==':' && *(cptr-1)==':')              //~vbzrI~
                        uerrexit("Font parm(%s) error,maybe missing @ prefix.\n",0,Pparmp[parmno]);//~vbzrR~
//                  setConsoleFont(cptr);                              //~vbzqR~//~vbzrR~
                    SpFontParm=umalloc(strlen(cptr)+1);            //~vbzrR~
                    strcpy(SpFontParm,cptr);                       //~vbzrI~
                }                                                  //~vbzrI~
                SswFont=1;                                         //~vbzqR~
                break;                                             //~vbzqI~
#endif      //WINCON                                               //~vbzqI~
            case 'G':    //glyph width /Gv[L]                      //~vbzzI~
                ;//for err a label can only be part of a statement ...//~vbzFI~
            	int swErrGW=0;                                     //~vbzzR~
//                Guvio2Stat|=UVIO2S_USEAPI;            //default    //~vbzYI~//~vbzZR~
//                Guvio2Stat|=UVIO2S_USEAPI_AMBIGLANG;  //default    //~vbzYI~//~vbzZR~
//                if (toupper(*cptr)=='A')  //use api                //~vbzYR~//~vbzZR~
//                    Guvio2Stat|=UVIO2S_USEAPI;                     //~vbzYR~//~vbzZR~
//                else                                               //~vbzYR~//~vbzZR~
//              {                                                    //~vbzYI~//~vbzZR~
//                Guvio2Stat&=~UVIO2S_USEAPI;            //default   //~vbzYI~//~vbzZR~
//                Guvio2Stat&=~UVIO2S_USEAPI_AMBIGLANG;  //default   //~vbzYI~//~vbzZR~
                if (toupper(*cptr)=='Y')  //Yv   do glyph chk      //~vbzzR~
//                {                                                  //~vbzYI~//~vbzZR~
					Gulibutfmode|=GULIBUTF_APICHK_CSR; //0x08000000  //utfwcwidth chr cursor step//~vbzzI~
//                    Gulibutfmode|=GULIBUTFMODE_AMBIGLANG;//default when -GY, apichk for ambiguous by lang//~vbzYI~//~vbzZR~
//                }                                                  //~vbzYI~//~vbzZR~
                else                                               //~vbzzI~
                if (toupper(*cptr)=='N')  //Nv   //do not glyph chk//~vbzzR~
                    Gulibutfmode&=~GULIBUTF_APICHK_CSR; //0x08000000  //utfwcwidth chr cursor step//~vbzzI~
                else                                               //~vbzzI~
//                if (toupper(*cptr)=='A')  //Nv   //do not glyph chk//~vbzEI~//~vbzFR~
//                {                                                  //~vbzEI~//~vbzFR~
//                    Gulibutfmode|=GULIBUTF_APICHK_CSR; //0x08000000  //utfwcwidth chr cursor step//~vbzEI~//~vbzFR~
//                    Guvio2Stat|=UVIO2S_DRAWTEXTALL; //0x0400  //chk by TextDraw if extent is sbcs//~vbzEI~//~vbzFR~
//                }                                                  //~vbzEI~//~vbzFR~
//                else                                               //~vbzEI~//~vbzFR~
                	swErrGW=1;                                     //~vbzzI~
//              }                                                    //~vbzYI~//~vbzZR~
                Gulibutfmode&=~GULIBUTFMODE_AMBIGLANG;//apichk for ambiguous by lang//~vbzzI~
	            Guvio2Stat&=~(UVIO2S_AMBIG_SBCS|UVIO2S_AMBIG_UNP); //~vbzzR~
                if (!swErrGW)                                      //~vbzzI~
                {                                                  //~vbzzI~
                	switch(*(cptr+1))                              //~vbzzI~
                    {                                              //~vbzzI~
                    case 'Y':                                      //~vbzzR~
                    case 'y':                                      //~vbzzI~
//                      if (!(Gulibutfmode &GULIBUTF_APICHK_CSR))           //No ambiguous chk,alwas 2 cell//~vbzzI~//~vbzyR~//~vbzYR~
//                        if (!(Gulibutfmode & GULIBUTF_APICHK_CSR)           //No ambiguous chk,alwas 2 cell//~vbzYR~//~vbzZR~
//                        &&  !(Guvio2Stat & UVIO2S_USEAPI))         //~vbzYR~//~vbzZR~
                        if (!(Gulibutfmode &GULIBUTF_APICHK_CSR))           //No ambiguous chk,alwas 2 cell//~vbzZI~
                        {                                          //~vbzzI~//~vbzyR~
                            uerrexit("y of %cG{Y|N}{y|1|2} is valid when %cGY.\n",0,//~vbzzI~//~vbzyR~
                                    CMDFLAG_PREFIX,CMDFLAG_PREFIX);//~vbzzI~//~vbzyR~
                        }                                          //~vbzzI~//~vbzyR~
                        Gulibutfmode|=GULIBUTFMODE_AMBIGLANG;//apichk for ambiguous by lang//~vbzzI~
                    	break;                                     //~vbzzI~
                    case '0':                                      //~vbzzI~
	                    Guvio2Stat|=UVIO2S_AMBIG_UNP;   //1cell widthout glyphchk//~vbzzR~
                    	break;                                     //~vbzzI~
                    case '1':                                      //~vbzzI~
	                    Guvio2Stat|=UVIO2S_AMBIG_SBCS;   //1cell widthout glyphchk//~vbzzR~
                    	break;                                     //~vbzzI~
//                    case 'A':                                      //~vbzYR~//~vbzZR~
//                        Guvio2Stat|=UVIO2S_USEAPI_AMBIGLANG;       //~vbzYR~//~vbzZR~
//                        break;                                     //~vbzYR~//~vbzZR~
                    case '2':                                      //~vbzzI~
                    	break;                                     //~vbzzI~
                    default:                                       //~vbzzI~
					  if (Gulibutfmode & GULIBUTF_APICHK_CSR)      //~vbzZR~
						Gulibutfmode|=GULIBUTFMODE_AMBIGLANG;//default when -GY, apichk for ambiguous by lang//~vbzZI~
                      else                                         //~vbzZR~
                      {                                            //~vbAnI~
                		uerrmsg("Glyph Display Width parm(%s) 2nd option error",0,Pparmp[parmno]);//~vbAnI~
                        swErrGW=1;                                 //~vbzzI~
                      }                                            //~vbAnI~
                	}                                              //~vbzzI~
                }                                                  //~vbzzI~
                if (swErrGW)                                       //~vbzzI~
                	uerrexit("Glyph Display Width parm(%s) error",0,Pparmp[parmno]);//~vbzzI~
                break;                                             //~vbzzI~
            case 'U':                                              //~vbzjI~
              	if (toupper(*cptr)=='U')                           //~vbzjI~
              	{                                                  //~vbzjI~
                    cptr++;                                        //~vbzjI~
                    ULONG x2lucs;                                  //~vbzjI~
                    if (ux2l(cptr,&x2lucs))                        //~vbzjI~
                        uerrexit("UTF8 option err,invalid Unicode by Hex notation(%s)",0,//~vbzjI~
                                  Pparmp[parmno]);                 //~vbzjI~
                    else                                           //~vbzjI~
                        GutfTestUcs=(ULONG)x2lucs;                  //~vbzjI~
              	}                                                  //~vbzjI~
                break;                                             //~vbzjI~
//**************************                                       //~v79zI~
//* work dir      /W                                               //~v79zI~
//**************************                                       //~v79zI~
            case 'W':                                              //~v79zI~
                strcpy(Gworkdir,cptr);                             //~v79zI~
#ifdef W32                                                         //~vb8aI~
                if (ROOTDIR_LOCAL(Gworkdir))                       //~vb8aI~
                    strcpy(Gworkdir+3,XE_WKDIR+3);                 //~vb8aI~
#endif                                                             //~vb8aI~
  				if (*(Gworkdir+strlen(Gworkdir)-1)!=DIR_SEPC)      //~vbzsR~
					strcpy(Gworkdir+strlen(Gworkdir),DIR_SEPS);    //~vbzsR~
#ifdef W32      //LNX has suffix of pid                            //~vbzsI~
    			if (ufstat(Gworkdir,0))	//not found                //~vbzsI~
                	uerrexit("%s is not found\n",0,Gworkdir);      //~vbzsI~
#endif                                                             //~vbzsI~
                break;                                             //~v79zI~
//**************************                                       //~v79zI~
//* set option     */Y                                             //~v79zI~
//**************************                                       //~v79zI~
            case 'Y':                                              //~v79zI~
                while (*cptr)                                      //~v79zI~
                {                                                  //~v79zI~
                    switch (toupper(*cptr))                        //~v79zI~
                    {                                              //~v79zI~
                    case 'E':  //use ICU as local converetr        //~vbq7I~
                        Sskipuseteh=0;                             //~vbq7I~
                        break;                                     //~vbq7I~
#ifdef LNX                                                         //~vad0I~
    #if !defined(XXE) && !defined(ARM)                             //~vad0I~
                    case 'I':  //use ICU as local converetr        //~vad0I~
                        Swcinitopt|=UDCWCIO_LOCALICU;              //~vad0I~
                        break;                                     //~vad0I~
    #endif                                                         //~vad0I~
#endif                                                             //~vad0I~
//#ifdef LNX                                                         //~v7a7I~//~va0DR~
                    case 'J':  //force mk_wcwidth_cjk()            //~vbmkI~
                        Swcinitopt|=UDCWCIO_CJK;                   //~vbmkI~
                        break;                                     //~vbmkI~
//                    case 'L':  //chk by ambuguous_langs at utf4    //~vbzyI~//~vbzzR~
//                        Gulibutfmode|=GULIBUTFMODE_AMBIGLANG;//      0x4000 //chk glyph width fo ambiguous_langs//~vbzyI~//~vbzzR~
//                        break;                                     //~vbzyI~//~vbzzR~
#ifdef UTF8SUPPH                                                   //~va0DI~
//#ifdef W32                                                         //~vbt3I~//~vbtaR~
                    case 'M':  //no utf8 kbd input process         //~v7a7I~
                        Swcinitopt&=~UDCWCIO_KBDNOUTF8;            //~v7a7I~
//#ifdef UTF8SUPPH                                                   //~va00I~//~va0DR~
#ifdef LNX                                                         //~va0DI~
                        Swcinitopt|=UDCWCIO_KBDFORCEUTF8;          //~va00I~
#endif                                                             //~va00I~
                        break;                                     //~v7a7I~
//#endif //W32                                                       //~vbt3I~//~vbtaR~
#endif                                                             //~v7a7I~
                    case 'N':                                      //~vbzuI~
                        swNotraceMapinit=1;                        //~vbzuI~
                        break;                                     //~vbzuI~
#ifdef W32                                                         //~v79zI~
//    #ifndef WXE                                                    //~vbz3I~//~vbzzR~
//                    case 'V':  //kbd and vio by widechar even for Codepage=Japanese on Japanese system//~vbz3I~//~vbzzR~
//                        Gulibutfmode|=GULIBUTF_APICHK_CSR; //0x08000000  //utfwcwidth chr cursor step//~vbz3I~//~vbzzR~
//                        break;                                     //~vbz3I~//~vbzzR~
//    #else                                                          //~vbz4I~//~vbzzR~
//                    case 'V':  //kbd and vio by widechar even for Codepage=Japanese on Japanese system//~vbz4I~//~vbzzR~
//                        Gulibutfmode|=GULIBUTF_APICHK_CSR; //0x08000000  //utfwcwidth chr cursor step//~vbz4I~//~vbzzR~
//                        break;                                     //~vbz4I~//~vbzzR~
//    #endif                                                         //~vbz3I~//~vbzzR~
                    case 'W':  //kbd and vio by widechar even for Codepage=Japanese on Japanese system//~v79zI~
                        Swcinitopt|=UDCWCIO_FORCEWIDE;             //~v79zI~
                        break;                                     //~v79zI~
#else                                                              //~vbz5I~
//  #ifdef XXE                                                     //~vbz5I~//~vbzpR~
//                    case 'V':  //kbd and vio by widechar even for Codepage=Japanese on Japanese system//~vbz5I~//~vbzzR~
//                        Gulibutfmode|=GULIBUTF_APICHK_CSR; //0x08000000  //utfwcwidth chr cursor step//~vbz5I~//~vbzzR~
//                        break;                                     //~vbz5I~//~vbzzR~
//  #endif                                                         //~vbz5I~//~vbzpR~
#endif                                                             //~v79zI~
                    default:                                       //~v79zI~
                        ;                                          //~v79zI~
                    }//switch by /Yx                               //~v79zI~
                    cptr++;                                        //~v79zI~
                }//until strlen                                    //~v79zI~
                break;                                             //~v79zI~
//**************************                                       //~v79zI~
//* reset option     */N                                           //~v79zI~
//**************************                                       //~v79zI~
            case 'N':                                              //~v79zI~
                while (*cptr)                                      //~v79zI~
                {                                                  //~v79zI~
                    switch (toupper(*cptr))                        //~v79zI~
                    {                                              //~v79zI~
                    case 'E':  //use ICU as local converetr        //~vbq7I~
                        Sskipuseteh=1;                             //~vbq7I~
                        break;                                     //~vbq7I~
#ifdef LNX                                                         //~vad0I~
    #if !defined(XXE) && !defined(ARM)                             //~vad0I~
                    case 'I':  //use ICU as local converetr        //~vad0I~
                        Swcinitopt&=~UDCWCIO_LOCALICU;             //~vad0I~
                        break;                                     //~vad0I~
    #endif                                                         //~vad0I~
#endif                                                             //~vad0I~
//                    case 'L':  //chk by ambuguous_langs at utf4    //~vbzyI~//~vbzzR~
//                        Gulibutfmode&=~GULIBUTFMODE_AMBIGLANG;//      0x4000 //chk glyph width fo ambiguous_langs//~vbzyI~//~vbzzR~
//                        break;                                     //~vbzyI~//~vbzzR~
//#ifdef LNX                                                         //~v79zI~//~va0DR~
#ifdef UTF8SUPPH                                                   //~va0DI~
//#ifdef W32                                                         //~vbt3I~//~vbtaR~
                    case 'M':  //no utf8 kbd input process         //~v79zI~//~v7a7R~
//#ifdef UTF8SUPPH                                                   //~va00M~//~va0DR~
#ifdef LNX                                                         //~va0DI~
                        Swcinitopt&=~UDCWCIO_KBDFORCEUTF8;         //~va00M~
#endif                                                             //~va00M~
                        Swcinitopt|=UDCWCIO_KBDNOUTF8;             //~v79zI~
                        break;                                     //~v79zI~
//#endif //W32                                                       //~vbt3I~//~vbtaR~
#endif                                                             //~v79zI~
                    case 'N':                                      //~vbzuI~
                        swNotraceMapinit=0;                        //~vbzuI~
                        break;                                     //~vbzuI~
#ifdef W32                                                         //~vbt2I~
//    #ifndef WXE                                                    //~vbz3I~//~vbzzR~
//                    case 'V':  //kbd and vio by widechar even for Codepage=Japanese on Japanese system//~vbz3I~//~vbzzR~
//                        Gulibutfmode&=~GULIBUTF_APICHK_CSR; //0x08000000  //utfwcwidth chr cursor step//~vbz3I~//~vbzzR~
//                        break;                                     //~vbz3I~//~vbzzR~
//    #else                                                          //~vbz4I~//~vbzzR~
//                    case 'V':  //kbd and vio by widechar even for Codepage=Japanese on Japanese system//~vbz4I~//~vbzzR~
//                        Gulibutfmode&=~GULIBUTF_APICHK_CSR; //0x08000000  //utfwcwidth chr cursor step//~vbz4I~//~vbzzR~
//                        break;                                     //~vbz4I~//~vbzzR~
//    #endif                                                         //~vbz3I~//~vbzzR~
                    case 'W':  //kbd and vio by widechar even for Codepage=Japanese on Japanese system//~vbt2I~
                        Swcinitopt&=~UDCWCIO_FORCEWIDE;            //~vbt2I~
                        break;                                     //~vbt2I~
#else                                                              //~vbz5I~
//  #ifdef XXE                                                     //~vbz5I~//~vbzpR~
//                    case 'V':  //kbd and vio by widechar even for Codepage=Japanese on Japanese system//~vbz5I~//~vbzzR~
//                        Gulibutfmode&=~GULIBUTF_APICHK_CSR; //0x08000000  //utfwcwidth chr cursor step//~vbz5I~//~vbzzR~
//                        break;                                     //~vbz5I~//~vbzzR~
//  #endif                                                         //~vbz5I~//~vbzpR~
#endif                                                             //~vbt2I~
                    default:                                       //~v79zI~
                        ;                                          //~v79zI~
                    }//switch by /Nx                               //~v79zI~
                    cptr++;                                        //~v79zI~
                }//until strlen                                    //~v79zI~
                break;                                             //~v79zI~
			default:                                               //~v79zI~
                ;                                                  //~v79zI~
            }//kwd parm                                            //~v79zI~
        }//option                                                  //~v79zI~
    }//for all parm                                                //~v79zI~
    if (swNotraceMapinit)                                          //~vbzuI~
        Gulibutfmode|=GULIBUTFMODE_NOTRACEMAPINIT;                 //~vbzuI~
    return 0;                                                      //~v79zI~
}//parmproc00                                                      //~v79zI~
//************************************************              //~5429I~
//*get wkdir,ini process parameter                              //~5429I~
//************************************************              //~5429I~
int  parmproc0(int Pparmc,char *Pparmp[])                          //~v501R~
{                                                               //~5429I~
    int parmno;                                                 //~5429I~
    char *cptr,ch;                                              //~5429I~
//#ifdef UNX                                                       //~v79MR~
    int posparmno=0,flagsw;                                        //~v19DI~
//#endif                                                           //~v79MR~
#ifdef UTF8SUPPH                                                   //~va00I~
#ifdef ARM                                                         //~vbrcI~
    int utfopt=XEUTFIO_FILE|XEUTFIO_DIRU8;                         //~vbrcI~
#else                                                              //~vbrcI~
    int utfopt=0;                                                  //~va00I~
#endif                                                             //~vbrcI~
#endif                                                             //~va00I~
//********************                                          //~5429I~
    for (parmno=1;parmno<Pparmc;parmno++)                       //~5429I~
    {                                                           //~5429I~
        cptr=Pparmp[parmno];                                    //~5429I~
//#ifdef UNX                                                       //~v79MR~
//      if(*cptr=='-')                                             //~v19DR~
//      flagsw=CMDFLAGCHK(*cptr,posparmno); //not flag             //~v79MR~
        flagsw=CMDFLAGCHK_AND_CYGWIN(Gotherstatus&GOTHERS_CYGWIN,*cptr,posparmno); //not flag//~v79MI~
        if (!flagsw)    //filename parm                            //~v19DI~
        	posparmno++;                                           //~v19DR~
        else			//flag parm                                //~v19DI~
//#else                                                            //~v79MR~
//      if(*cptr=='/'||*cptr=='-')                                 //~v79MR~
//#endif                                                           //~v79MR~
        {//option                                               //~5429I~
            ch=*(++cptr);                      //first option byte//~5429I~
            if (*(++cptr)==':')               // /o:x format    //~5429I~
                cptr++;                         //skip :        //~5429I~
            switch(toupper(ch))       //option                  //~5429I~
            {                                                   //~5429I~
//**************************                                       //~v08tI~
//* terminater   //                                                //~v08tI~
//**************************                                       //~v08tI~
            case '/':                                              //~v08tI~
                parmno=Pparmc;  //loop exit                        //~v08tI~
                break;                                             //~v08tI~
#ifdef WCSUPP                                                      //~v79zI~
//**************************                                       //~v79zI~
//* Codepage      /C                                               //~v79zI~
//**************************                                       //~v79zI~
            case 'C':                                              //~v79zI~
//                if (                                               //~vbB6M~//~vbB8R~
//                    !stricmp(cptr,EBC_KANA)                        //~vbB6R~//~vbB8R~
//                  ||!stricmp(cptr,EBC_ENG)                         //~vbB6R~//~vbB8R~
//                  ||!stricmp(cptr,EBC_US)                          //~vbB6M~//~vbB8R~
//                )                                                  //~vbB6M~//~vbB8R~
//                {                                                  //~vbB6M~//~vbB8R~
//                    Gucvebc_stat|=UCVEBCS_CMDLINEOPTION; //0x0100 //xe cmdline option cp930/cp939/cp037 specified//~vbB6M~//~vbB8R~
//                    if (!stricmp(cptr,EBC_KANA))                   //~vbB6R~//~vbB8R~
//                        Gucvebc_stat|=UCVEBCS_CLO_CP930; //0x0200  //~vbB6M~//~vbB8R~
//                    else                                           //~vbB6M~//~vbB8R~
//                    if (!stricmp(cptr,EBC_ENG))                    //~vbB6R~//~vbB8R~
//                        Gucvebc_stat|=UCVEBCS_CLO_CP939; //0x0400  //~vbB6M~//~vbB8R~
//                    else                                           //~vbB6M~//~vbB8R~
//                        Gucvebc_stat|=UCVEBCS_CLO_CP037; //0x0800  //~vbB6M~//~vbB8R~
//                    UTRACEP("%s:Gucvebc_stat=0x%04x,cptr=%s\n",UTT,Gucvebc_stat,cptr);//~vbB6R~//~vbB8R~
//                    break;                                         //~vbB6M~//~vbB8R~
//                }                                                  //~vbB6M~//~vbB8R~
                break;                                             //~v79zI~
#endif                                                             //~v79zI~
//**************************                                       //~v07iM~
//* debug trace  /D                                                //~v07iM~
//**************************                                       //~v07iM~
            case 'D':                                              //~v07iM~
//                switch(*cptr)                                      //~v07iM~
//                {                                                  //~v07iM~
//                case '0':                                          //~v07iM~
//                case '1':                                          //~v07iM~
//                case '2':                                          //~v07iM~
//                case '3':                                          //~v53sI~
//                    UCBITOFF(Gopt3,GOPT3DOSPRECIZEMA);             //~v08aI~
//                    Smalloctrcopt=*cptr-'0';                       //~v07iM~
//                    if (Smalloctrcopt==3)                          //~v53sR~
//                        Smalloctrcopt=UALLOC_TRACE+UALLOC_TRACE2;  //~v53sR~
//                    break;                                         //~v07iM~
////              case '@':                                          //~v0bxR~
//                case '`':                                          //~v0bxI~
//                case 'a':                                          //~v07iM~
//                case 'b':                                          //~v07iM~
//                    UCBITON(Gopt3,GOPT3DOSPRECIZEMA);              //~v07iM~
////                  Smalloctrcopt=*cptr-'@';                       //~v0bxR~
//                    Smalloctrcopt=*cptr-'`';                       //~v0bxI~
//                    break;                                         //~v07iM~
//                case '@':                                          //~v0bxI~
//                case 'A':                                          //~v0bxI~
//                case 'B':                                          //~v0bxI~
//                    UCBITON(Gopt3,GOPT3DOSPRECIZEMA);              //~v0bxI~
//                    Sallocexit=1;           //errexit when alloc err//~v0bxI~
//                    Smalloctrcopt=*cptr-'@';                       //~v0bxI~
//                    break;                                         //~v0bxI~
//                default:                                           //~v07iM~
//                    uerrexit("memory trace option parm err(%s)",   //~v07iM~
//                                "メモリートレースオプションエラー(%s)",//~v07iM~
//                                cptr);                             //~v07iM~
//                }                                                  //~v07iM~
//                UCBITOFF(Gopt3,GOPT3TESTABEND|GOPT3TESTEXIT);//abend by double Esc//~v08aI~
//                switch(*(++cptr))                                  //~v07iM~
//                {                                                  //~v07iM~
//                case 0:                                            //~v07iM~
//                    Stesttrcopt=0;                                 //~v07iM~
//                    break;                                         //~v07iM~
//                case '0':                                          //~v07iM~
//                case '1':                                          //~v07iM~
//                    Stesttrcopt=*cptr-'0';                         //~v07iM~
//                    switch(*(cptr+1))                              //~v07iM~
//                    {                                              //~v07iM~
//                    case 0  :                                      //~v099I~
//                        break;                                     //~v099I~
//                    case 'A':                                      //~v07iM~
//                    case 'a':                                      //~v07iM~
//                        UCBITON(Gopt3,GOPT3TESTABEND);//abend by double Esc//~v07iM~
//                        break;                                     //~v07iM~
//                    case 'E':                                      //~v07iM~
//                    case 'e':                                      //~v07iM~
//                        UCBITON(Gopt3,GOPT3TESTEXIT);//uerrexit by double Esc//~v07iM~
//                        break;                                     //~v07iM~
//#ifdef W32                                                         //~v142I~
//  #ifndef WXE                                                      //~v500I~
//                    case 'k':   //w95 kbdtrace                     //~v142I~
//                        ukbd_w95traceinit(KBD_PTRACE);             //~v780R~
//                        break;                                     //~v780R~
//                    case 'K':                                      //~v142I~
//                        ukbd_w95traceinit(KBD_UTRACE);             //~v142I~
//                        break;                                     //~v142I~
//  #endif  //!WXE                                                   //~v500I~
//#endif                                                             //~v142I~
//                    default:                                       //~v099I~
//                        uerrexit("test trace option parm err(%s)", //~v099I~
//                                "テストトレースオプションエラー(%s)",//~v099I~
//                                cptr);                             //~v099I~
//                    }                                              //~v07iM~
//                    break;                                         //~v07iM~
//                default:                                           //~v07iM~
//                    uerrexit("test trace option parm err(%s)",     //~v07iM~
//                                "テストトレースオプションエラー(%s)",//~v07iM~
//                                cptr);                             //~v07iM~
//                }                                                  //~v07iM~
                break;                                             //~v07iM~
//#ifdef WINCON                                                      //~vbzqI~//~vbzrR~
            case 'E':                                              //~vbB8I~
			  	if (USTRHEADIS_IC(cptr-1,EBC_STREBC))              //~vbB8I~
              	{                                                  //~vbB8I~
                    char *ebcopt=cptr+2;                           //~vbB8I~//~vbBcM~
                    if (!isalpha(*ebcopt))                         //~vbB8I~
                        ebcopt++;                                  //~vbB8I~
                  if (memicmp(ebcopt,"cfg",3))                     //~vbBcR~//~vbBdM~
                  {                                                //~vbBeI~
                    SebccfgCLP="";//ebccfg=no                      //~vbBeR~
                    Gucvebc_stat &=~(UCVEBCS_CLO_ALL);             //~vbB9I~//~vbBdM~
					Gebcstat|=GES_CLPCFG;//     0x10        //cfg cmdline parameter//~vbBeI~
                  }                                                //~vbBeI~
                    if (!stricmp(ebcopt,EBC_STRKANA))//~vbB8I~     //~vbB9R~
                        Gucvebc_stat|=(UCVEBCS_CMDLINEOPTION | UCVEBCS_CLO_CP930); //0x0100+0x0200//~vbB8I~
                    else                                           //~vbB8I~
                    if (!stricmp(ebcopt,EBC_STRENG))//~vbB8I~      //~vbB9R~
                        Gucvebc_stat|=(UCVEBCS_CMDLINEOPTION | UCVEBCS_CLO_CP939); //0x0100+0x0400//~vbB8I~
                    else                                           //~vbB8I~
//                    if (!stricmp(ebcopt,EBC_STRLATIN))             //~vbB9I~//~vbBsR~
//                        Gucvebc_stat|=(UCVEBCS_CMDLINEOPTION | UCVEBCS_CLO_CP931); //0x0100+0x1000//~vbB9I~//~vbBsR~
//                    else                                           //~vbB9I~//~vbBsR~
                    if (!stricmp(ebcopt,EBC_STRUS))//~vbB8R~       //~vbB9R~
                        Gucvebc_stat|=(UCVEBCS_CMDLINEOPTION | UCVEBCS_CLO_CP037); //0x0100+0x0800//~vbB8I~
                    else                                           //~vbB8I~
                    if (!stricmp(ebcopt,EBC_STRUS_EURO))           //~vbBtI~
                        Gucvebc_stat|=(UCVEBCS_CMDLINEOPTION | UCVEBCS_CLO_CP037Euro); //0x0100+0x0800//~vbBtI~
                    else                                           //~vbBtI~
                    if (!memicmp(ebcopt,"cfg",3) && !isalpha(*(ebcopt+3)))//~vbBcR~
                    {                                              //~vbBcI~
                        if (Gucvebc_stat & UCVEBCS_CLO_ALL)        //~vbBeI~
                        {                                          //~vbBeI~
        	                uerrexit("ebc:cfg option and other ebc options are mutually exclusive",0);//~vbBeR~
                        }                                          //~vbBeI~
                        SebccfgCLP=strdup(ebcopt+4);               //~vbBcR~
						Gebcstat|=GES_CLPCFG;//     0x10        //cfg cmdline parameter//~vbBcR~
//                        if (!stricmp(ebcopt+4,"NO"))               //~vbBcR~//~vbBeR~
//                        {                                          //~vbBcI~//~vbBeR~
//                            UTRACEP("%s:No cfg by cfg=NO\n",UTT);  //~vbBcI~//~vbBeR~
//                            *SebccfgCLP=0;                         //~vbBcI~//~vbBeR~
//                        }                                          //~vbBcR~//~vbBeR~
                    }                                              //~vbBcI~
                    else                                           //~vbBcI~
                        uerrexit("EBC optionerr(%s)",0,            //~vbB8I~
                              cptr-1);                             //~vbB8I~
                    UTRACEP("%s:Gucvebc_stat=0x%04x,Gebcstat=0x%04x,cptr=%s\n",UTT,Gucvebc_stat,Gebcstat,cptr-1);//~vbB8I~//~vbBcR~
                    break;                                         //~vbB8I~
			  	}                                                  //~vbB8I~
                break;                                             //~vbB8I~
#if defined(WINCON) || defined(LNXCON)                             //~vbzrI~
            case 'F':    //fontname and charset                    //~vbzqI~
                break;                                             //~vbzqI~
#endif                                                             //~vbzqI~
            case 'G':    //ambig glyphchk                          //~vbzzI~
                break;                                             //~vbzzI~
//**************************                                       //~v07iM~
//* help msg      /H*                                              //~v07iM~
//**************************                                       //~v07iM~
            case '?':                                              //~v07iM~
            case 'H':                                              //~v07iM~
            	if (*cptr==*(cptr-1))	// -?? or -hh              //~v53rR~
                	Sdebughelp=1;                                  //~v53rI~
                                                                   //~v53rI~
#if defined(W32) || defined(LNX)                                   //~v71AI~
            	if (toupper(*cptr)=='D')	// -hd                 //~v71AI~
                    break;                                         //~v71AI~
#endif                                                             //~v71AI~
                                                                   //~v71AI~
//#ifdef W32                                                       //~v47rR~
//#if defined(W32) || defined(AIX)                                 //~v47sR~
#if defined(W32) || defined(UNX)                                   //~v47sI~
//#ifndef WXE                                                      //~v641R~
  #ifndef WXEXXE        //xxe not allow hnn                        //~v641I~
                if (ch!='?' && *cptr)   // -Hnn screen height parm //~v47mI~
            	if (*cptr!=*(cptr-1))	// -??  -hh                //~v53rI~
                    break;                                         //~v47mI~
  #endif  //!WXE                                                   //~v500I~
#endif                                                             //~v47mI~
//                help();                                            //~v07iM~//~v7ahR~
//#ifdef WXE                                                         //~v641R~//~v7ahR~
//                return -1;                                         //~v501I~//~v7ahR~
//#else                                                              //~v501I~//~v7ahR~
//                exit(4);                                           //~v07iM~//~v7ahR~
//#endif                                                             //~v501I~//~v7ahR~
#ifdef WXE                                                         //~v7ahI~
                Shelpsw=1;                                         //~v7ahI~
#else                                                              //~v7ahI~
                help();                                            //~v7ahI~
                exit(4);                                           //~v7ahI~
#endif                                                             //~v7ahI~
                break;                                             //~v07iM~
//**************************                                    //~5429I~
//* work dir      /I                                            //~5501R~
//**************************                                    //~5429I~
            case 'I':                                           //~5501R~
                Sinifile=cptr;                                  //~5501R~
                break;                                          //~5429I~
//**************************                                       //~v11yI~
//* restore CD   /R                                                //~v11yI~
//**************************                                       //~v11yI~
            case 'R':                                              //~v11yI~
                Srestorecdsw=1;                                    //~v11yI~
                break;                                             //~v11yI~
#ifdef UTF8SUPPH                                                   //~va00I~
//**************************                                       //~va00I~
//* UTF8 option                                                    //~va00I~
//**************************                                       //~va00I~
            case 'U':                                              //~va00I~
              if (toupper(*cptr)=='F')                             //~va1nI~
              {                                                    //~va1nI~
              	cptr++;                                            //~va1nI~
                if (!*cptr)	//missin option                        //~va1sI~
    	        	uerrexit("missing UTF8 option err(%s)",0,      //~va1sR~
                              Pparmp[parmno]);                     //~va1sI~
            	for (;*cptr;cptr++)                                //~va00I~
                {                                                  //~va00I~
                	switch(toupper(*cptr))                         //~va00I~
                    {                                              //~va00I~
//                  case 'F':	//file is encoded as utf8 by default//~va00I~//~va1mR~
                    case '8':	//file is encoded as utf8 by default//~va1mR~
                    	utfopt|=XEUTFIO_FILE;                      //~va00I~
                    	utfopt&=~XEUTFIO_FILELC;                   //~va1mR~
                        break;                                     //~va00I~
                    case 'L':	//file is encoded as utf8 by default//~va1mR~
                    	utfopt|=XEUTFIO_FILELC;                    //~va1mR~
                    	utfopt&=~XEUTFIO_FILE;                     //~va1mR~
                        break;                                     //~va1mR~
                    default:                                       //~va00I~
    	            	uerrexit("UTF8 option err(%s)",0,          //~va00I~
                              Pparmp[parmno]);                     //~va00I~
                    }                                              //~va00I~
                }                                                  //~va00I~
              }                                                    //~va1nI~
              else                                                 //~va1nI~
              if (toupper(*cptr)=='N')                             //~va1nR~
              {                                                    //~va1nI~
              	cptr++;                                            //~va1nI~
                if (!*cptr)	//missin option                        //~va1sI~
    	        	uerrexit("missing UTF8 option err(%s)",0,      //~va1sI~
                              Pparmp[parmno]);                     //~va1sI~
            	for (;*cptr;cptr++)                                //~va1nI~
                {                                                  //~va1nI~
                	switch(toupper(*cptr))                         //~va1nI~
                    {                                              //~va1nI~
                    case '8':	//file is encoded as utf8 by default//~va1nI~
                    	utfopt|=XEUTFIO_DIRU8;                     //~va1nR~
                    	utfopt&=~XEUTFIO_DIRLC;                    //~va1nI~
                        break;                                     //~va1nI~
                    case 'L':	//file is encoded as utf8 by default//~va1nI~
                    	utfopt|=XEUTFIO_DIRLC;                     //~va1nI~
                    	utfopt&=~XEUTFIO_DIRU8;                    //~va1nI~
                        break;                                     //~va1nI~
                    default:                                       //~va1nI~
    	            	uerrexit("UTF8 option err(%s)",0,          //~va1nI~
                              Pparmp[parmno]);                     //~va1nI~
                    }                                              //~va1nI~
                }                                                  //~va1nI~
              }                                                    //~va1nI~
              else                                                 //~vbzjI~
              if (toupper(*cptr)=='U')                             //~vbzjI~
              {                                                    //~vbzjI~
              	cptr++;                                            //~vbzjI~
              }                                                    //~vbzjI~
              else                                                 //~va1nI~
    	        uerrexit("UTF8 option err(%s)",0,                  //~va1nI~
                              Pparmp[parmno]);                     //~va1nI~
                break;                                             //~va00I~
#endif                                                             //~va00I~
//**************************                                       //~v47sR~
//* work dir      /W                                               //~v47sR~
//**************************                                       //~v47sR~
            case 'W':                                              //~v47sR~
////#if defined(W32) || defined(AIX)                               //~v47sR~
//#if defined(W32) || defined(UNX)                                 //~v47sR~
//                if (ISNUMSTR(cptr)) //accept as screen width     //~v47sR~
//                    break;                                       //~v47sR~
//#endif                                                           //~v47sR~
//              strcpy(Gworkdir,cptr);                             //~v79zR~
                break;                                             //~v47sR~
//**************************                                       //~v08tI~
//* set option     */Y                                             //~v08tI~
//**************************                                       //~v08tI~
            case 'Y':                                              //~v08tI~
                while (*cptr)                                      //~v08tI~
                {                                                  //~v08tI~
                    switch (toupper(*cptr))                        //~v08tI~
                    {                                              //~v08tI~
                    case '9':   //japanese errmsg if avail         //~v08tI~
                        Suerrmsgopt=(Suerrmsgopt & ~UERR_FORCE_ENGLISH);//~v08tI~
//#ifdef WXE                                                         //~va73I~//~vbvfR~
//                      UCBITOFF(Gotherstatus,GOTHERS_N9PARM);     //~va73R~//~vbvgR~
                        UIBITOFF(Gotherstatus,((UINT)(GOTHERS_N9PARM)));//~vbvgR~
//#endif                                                             //~va73I~//~vbvfR~
                        break;                                     //~v08tI~
                    }//switch by /Yx                               //~v08tI~
                    cptr++;                                        //~v08tI~
                }//until strlen                                    //~v08tI~
                break;                                             //~v08tI~
//**************************                                       //~v08tI~
//* reset option     */N                                           //~v08tI~
//**************************                                       //~v08tI~
            case 'N':                                              //~v08tI~
                while (*cptr)                                      //~v08tI~
                {                                                  //~v08tI~
                    switch (toupper(*cptr))                        //~v08tI~
                    {                                              //~v08tI~
                    case '9':   //no japanese errmsg(force english)//~v08tI~
                        Suerrmsgopt=(Suerrmsgopt|UERR_FORCE_ENGLISH);//~v08tI~
//#ifdef WXE                                                         //~va73I~//~vbvfR~
//                      UCBITON(Gotherstatus,GOTHERS_N9PARM);      //~va73I~//~vbvgR~
                        UIBITON(Gotherstatus,GOTHERS_N9PARM);      //~vbvgI~
//#endif                                                             //~va73I~//~vbvfR~
                        break;                                     //~v08tI~
                    }//switch by /Nx                               //~v08tI~
                    cptr++;                                        //~v08tI~
                }//until strlen                                    //~v08tI~
                break;                                             //~v08tI~
            }//kwd parm                                         //~5501I~
        }//option                                               //~5429I~
    }//for all parm                                             //~5429I~
#ifdef UTF8SUPPH                                                   //~va00I~
    xeutf_init(utfopt);		//gbl init                             //~va00I~
#endif                                                             //~va00I~
    return 0;                                                      //~v501R~
}//parmproc0                                                       //~v07iR~
                                                                //~5429I~
//************************************************
//*parameter process
//************************************************
void parmproc(int Pparmc,char *Pparmp[]) 
{
    int parmno,posparmno=0;                                     //~5603R~
    int posparmlen=1;       //pos parm set offset,offset 0 is for "E"/"B"//~v08aI~
    int stacksw;                                                   //~v08tR~
    char *cptr,ch;
    int lfnreq=0;                                                  //~v0flR~
    UCHAR lastfilemode;                                            //~v11zR~
    int fnmlen;                                                    //~v68kI~
#ifdef DPMI                                                        //~v0flI~
    int vfatsw;                                                    //~v0flI~
#endif                                                             //~v0flI~
#ifdef W32                                                         //~v0jtI~
  #ifndef WXE                                                      //~v500I~
//  int forcent=0;       //NT mode for kbd input process           //~v0jtR~//~vbzuR~
    int forcent2=0;      //NT mode for vio ntsw                    //~v449I~
  #endif //!WXE                                                    //~v500I~
#endif                                                             //~v0jtI~
//********************
//#ifdef LNX                                                         //~vau0I~//~vauER~
    Gotheropt|=GOTHERO_DDFMTDL;//ddfmt dirlist default             //~vau0I~
//#endif                                                             //~vau0I~//~vauER~
    for (parmno=1;parmno<Pparmc;parmno++)  
    {                                     
        cptr=Pparmp[parmno];                 
//#ifdef UNX                                                       //~v79MR~
//      if(*cptr=='-')                                             //~v19DR~
//      if (CMDFLAGCHK(*cptr,posparmno)) //flag parm               //~v79MR~
        if (CMDFLAGCHK_AND_CYGWIN(Gotherstatus&GOTHERS_CYGWIN,*cptr,posparmno)) //not flag//~v79MR~
//#else                                                            //~v79MR~
//        if(*cptr=='/'||*cptr=='-')                               //~v79MR~
//#endif                                                           //~v79MR~
        {//option                            
            ch=*(++cptr);                      //first option byte 
            if (*(++cptr)==':')               // /o:x format      
            cptr++;                         //skip :
            switch(toupper(ch))       //option     
            {                                                     
//**************************                                       //~v08tR~
//* terminater   //                                                //~v08tR~
//**************************                                       //~v08tR~
            case '/':                                              //~v08tR~
                parmno=Pparmc;  //loop exit                        //~v08tR~
                break;                                             //~v08tR~
//**************************                                       //~v08tR~
//* debug trace  /B                                                //~v08tR~
//**************************                                       //~v08tR~
            case 'B':                                              //~v08tR~
                *Gcmdbuff=ch;   //initialy browse cmd              //~v0ifR~
                break;                                             //~v08tR~
#ifdef WCSUPP                                                      //~v79zI~
//**************************                                       //~v79zI~
//* Codepage      /C                                               //~v79zI~
//**************************                                       //~v79zI~
            case 'C':                                              //~v79zI~
                break;                                             //~v79zI~
#endif                                                             //~v79zI~
//**************************                                       //~v08tR~
//* debug trace  /D                                                //~v07iI~
//**************************                                       //~v07iI~
            case 'D':                                              //~v07iI~
                break;                                             //~v07iI~
//**************************                                       //~v08tR~
//* debug trace  /E                                                //~v08tR~
//**************************                                       //~v08tR~
            case 'E':                                              //~v08tR~
			  	if (USTRHEADIS_IC(cptr-1,EBC_STREBC))              //~vbB8R~
                	break;                                         //~vbB8R~
			  	if (*cptr)                                         //~vbB8I~
                	uerrexit("optionerr(%s)",0,                    //~vbB8I~
                              cptr-1);                             //~vbB8I~
                *Gcmdbuff=ch;   //initialy browse cmd              //~v0ifR~
                break;                                             //~v08tR~
#ifdef FTPSUPP                                                     //~v53YM~
//**************************                                       //~v53YI~
//* FTP option   /F                                                //~v53YI~
//**************************                                       //~v53YI~
            case 'F':                                              //~v53YI~
                if (toupper(*cptr)!='T' || toupper(*(cptr+1))!='P')//~vaj8R~
                {                                                  //~vaj8I~
//#ifdef WINCON                                                      //~vbzqI~//~vbzrR~
#if defined(WINCON) || defined(LNXCON)                             //~vbzrI~
			        if (SswFont)                                   //~vbzqI~
	                	break;                                     //~vbzqI~
#endif                                                             //~vbzqI~
                	cptr=Pparmp[parmno];                           //~vaj8I~
                	*(Gcmdbuff+posparmlen++)=' ';   //continuation //~vaj8I~
                	strcpy(Gcmdbuff+posparmlen,cptr);              //~vaj8I~
                	posparmlen+=(int)strlen(cptr);                 //~vaj8I~
                	if (posparmlen>MAXCOLUMN)                      //~vaj8I~
                    	uerrexit("Too long parameter",0);          //~vaj8I~
                    break;                                         //~vaj8I~
                }                                                  //~vaj8I~
                cptr+=2;                                           //~vaj8I~
                switch (*cptr)                                     //~v53YR~
                {                                                  //~v53YR~
                case '0':                                          //~v53YR~
                    Sftpopt=XEFTP_NOUSE;                           //~v53YI~
                    break;                                         //~v53YR~
                case 0:         //default is "1":use ftp,no ftplog //~v53YI~
                case '1':                                          //~v53YI~
                    break;                                         //~v53YI~
                case 'w':                                          //~v53YR~
                case 'W':                                          //~v54xM~
                    Sftpopt=XEFTP_LOG;                             //~v53YR~
                    break;                                         //~v53YR~
                case 'a':                                          //~v53YR~
                case 'A':                                          //~v54xM~
                    Sftpopt=XEFTP_LOG|XEFTP_APPEND;                //~v53YR~
                    break;                                         //~v53YR~
                default:                                           //~v53YR~
                	uerrexit("FTP optionerr(%s)",0,                //~v53YM~
                              Pparmp[parmno]);                     //~v53YM~
                }                                                  //~v53YI~
                if (*cptr)                                         //~v54nI~
                {                                                  //~v54xI~
                	cptr++;                                        //~v54xI~
                                                                   //~v714I~
                	if (*cptr=='t'||*cptr=='T')                    //~v54xI~
                	{                                              //~v54xI~
                		cptr++;                                    //~v54xI~
//                  	Sftpopt=XEFTP_TEST;                        //~v55dR~
                    	Sftpopt|=XEFTP_TEST;                       //~v55dI~
                	}                                              //~v54xI~
                    if (*cptr==':')                                //~v54xR~
                    	Shostsfnm=cptr+1;                          //~v54xR~
                    else                                           //~v714I~
                    if (*cptr)                                     //~v714I~
    	            	uerrexit("FTP optionerr(%s)",0,            //~v714I~
                              Pparmp[parmno]);                     //~v714I~
                }                                                  //~v54xI~
                break;                                             //~v53YI~
#endif                                                             //~v53YM~
            case 'G':    //ambig glyphchk                          //~vbzzI~
                break;                                             //~vbzzI~
//**************************                                       //~v47mI~
//* screen height /H*                                              //~v47mI~
//**************************                                       //~v47mI~
//#ifdef W32                                                       //~v47rR~
//#if defined(W32) || defined(AIX)                                 //~v47sR~
#if defined(W32) || defined(UNX)                                   //~v47sI~
//	#ifndef WXE                                                    //~v641R~
#if defined(W32) || defined(LNX)                                   //~v71AM~
//	#ifndef WXEXXE                                                 //~v71AR~
            case 'H':                                              //~v47mI~
            	if (toupper(*cptr)=='D')	// -hd: //helpdir      //~v71AI~
                {                                                  //~v71AI~
                    strcpy(Ghelpdir,cptr+1);                       //~v71AR~
                    break;                                         //~v71AI~
                }                                                  //~v71AI~
  	#ifndef WXEXXE                                                 //~v71AI~
//              Sheightparm=numchk(cptr);                          //~v47rR~
                Sscrparm[0]=numchk(cptr);  //height                //~v47rI~
  	#endif //!WXE                                                  //~v71AI~
                break;                                             //~v47mI~
//	#endif //!WXE                                                  //~v71AR~
#endif                                                             //~v71AM~
#endif                                                             //~v47mI~
//**************************                                    //~5501I~
//* ini file     /I*                                            //~5501I~
//**************************                                    //~5501I~
            case 'I':                                           //~5501I~
                break;                                          //~5501I~
//**************************                                       //~v11yI~
//* restore CD   /R                                                //~v11yI~
//**************************                                       //~v11yI~
            case 'R':                                              //~v11yI~
                break;                                             //~v11yI~
#ifdef UTF8SUPPH                                                   //~va00I~
            case 'U':	//UTF8 option                              //~va00I~
                break;                                             //~va00I~
#endif                                                             //~va00I~
//**************************                                    //~5430I~
//* tab skip ctr  /T                                            //~5430I~
//**************************                                    //~5430I~
            case 'T':                                           //~5430I~
                Gfiletabskip=numchk(cptr);                      //~5603I~
                break;                                          //~5430I~
//**************************                                       //~v47sR~
//* work dir      /W    already processed at parmproc0             //~v47sR~
//**************************                                       //~v47sR~
            case 'W':                                              //~v47sR~
////#if defined(W32) || defined(AIX)                               //~v47sR~
//#if defined(W32) || defined(UNX)                                 //~v47sR~
//                if (!ISNUMSTR(cptr))                             //~v47sR~
//                    break;                                       //~v47sR~
//                Sscrparm[1]=numchk(cptr);  //height              //~v47sR~
//#endif                                                           //~v47sR~
                break;                                             //~v47sR~
//**************************
//* set option     */Y
//**************************
            case 'Y':
                while (*cptr)           
                {                       
                    switch (toupper(*cptr))
                    {             
                    case 'A':                                   //~5506R~
                        UCBITON(Gopt2,GOPT2REJECTCTLCHAR);      //~5506R~
                        break;                                  //~5501I~
                    case 'C':                                   //~5506I~
                        UCBITOFF(Gopt2,GOPT2NOCID);             //~5506I~
                        break;                                  //~5506I~
//#ifdef DOS                                                       //~v095R~
#if defined(DOS) && !defined(DPMI)                                 //~v095I~
#else                                                           //~5430I~
                    case 'D':           
                        UCBITOFF(Gopt,GOPTNOABENDIFERREXIT);//abend at uerrexit//~5430R~
                        break; 
#endif                                                          //~5430I~
                    case 'E':                                      //~vbq7I~
                        break;                                     //~vbq7I~
#ifdef LNX                                                         //~vad0I~
    #if !defined(XXE) && !defined(ARM)                             //~vad0I~
                    case 'I':  //use ICU as local converetr        //~vad0I~
                        break;                                     //~vad0I~
    #endif                                                         //~vad0I~
#endif                                                             //~vad0I~
                    case 'J':  //parmproc00 processed              //~vbmkI~
                        break;                                     //~vbmkI~
//                    case 'L':                                    //~vbzzR~
////                      lfnreq=1;         // /Yl requested //changed to ambiguous glyph chk        //~v0flI~//~vbzzR~
//                        break;                                   //~vbzzR~
//#ifdef LNX                                                         //~v7a7I~//~va0DR~
#ifdef UTF8SUPPH                                                   //~va0DI~
//#ifdef W32                                                         //~vbt3I~//~vbtaR~
                    case 'M':  //kbd utf8 conv to mb               //~v7a7I~
                        break;                                     //~v7a7I~
//#endif                                                             //~vbt3I~//~vbtaR~
#endif                                                             //~v7a7I~
                    case 'N':             //Yn                     //~v0jtI~
//#ifdef W32                                                         //~v0jtI~//~vbzuR~
//    #ifndef WXE                                                    //~v500I~//~vbzuR~
//                        forcent=1;        //force WindowsNT kbd proc//~v0jtI~//~vbzuR~
//    #endif                                                         //~v500I~//~vbzuR~
//#endif                                                             //~v0jtI~//~vbzuR~
                        break;                                     //~v0jtI~
                    case 'R':                                   //~5110I~
//                    if (UCBITCHK(Gopt,GOPTRCTLENTER))	//doubled "r"//~v793R~
                      if (toupper(*(cptr+1))=='R')   //Nrr         //~v793I~
                      {                                            //~v793I~
//                      UCBITON(Gotheropt,GOTHERO_CLRCTLNL);//Use R-Ctrl as Enter//~v793R~
//                      UCBITON(Gotheropt,GOTHERO_RCTLNL);//Use R-Ctrl as Enter//~vb27R~
                        ULBITON(Gotheropt,GOTHERO_RCTLNL);//Use R-Ctrl as Enter//~vb27I~
                        cptr++;                                    //~v793I~
                      }                                            //~v793I~
                      else                                         //~v790I~
                        UCBITON(Gopt,GOPTRCTLENTER);//Use R-Ctrl as Enter//~5110I~
                        break;                                  //~5110I~
                    case 'T':                                   //~4C24I~
                        UCBITON(Gopt,GOPTTABDISPLAY);//tab display//~4C24I~
                        break;                                  //~4C24I~
//#ifdef LNX                                                         //~vau0I~//~vauER~
                    case 'U':  //use dd fmt to display disrlist    //~vau0I~
                        Gotheropt|=GOTHERO_DDFMTDL;//ddfmt dirlist //~vau0I~
                        break;                                     //~vau0I~
//#endif                                                             //~vau0I~//~vauER~
                    case 'V':                                      //~vbzzM~
                        uerrexit("%cV option is deprecated, use %cG option.\n",//~vbzzI~
                                 "%cV オプションは %cG に移行しました。",//~vbzzI~
								CMDFLAG_PREFIX,CMDFLAG_PREFIX);    //~vbzzI~
                        break;                                     //~vbzzM~
#ifdef W32                                                         //~v79zR~
//    #ifndef WXE                                                    //~vbz3I~//~vbzzR~
//                    case 'V':  //kbd and vio by widechar even for Codepage=Japanese on Japanese system//~vbz3I~//~vbzzR~
//                        break;                                     //~vbz3I~//~vbzzR~
//    #else                                                          //~vbz4I~//~vbzzR~
//                    case 'V':  //kbd and vio by widechar even for Codepage=Japanese on Japanese system//~vbz4I~//~vbzzR~
//                        break;                                     //~vbz4I~//~vbzzR~
//    #endif                                                         //~vbz3I~//~vbzzR~
                    case 'W':  //kbd and vio by widechar even for Codepage=Japanese on Japanese system//~v79zI~
#ifndef UTF8SUPPH    //proc0 processed                             //~va00I~
                        udbcschk_wcinit(UDCWCIO_FORCEWIDE,0/*out locale*/);//~v79zI~//~va00R~
#endif                                                             //~va00I~
                        break;                                     //~v79zI~
#else                                                              //~vbz5I~
//  #ifdef XXE                                                     //~vbz5I~//~vbzpR~
//                    case 'V':  //kbd and vio by widechar even for Codepage=Japanese on Japanese system//~vbz5I~//~vbzzR~
//                        break;                                     //~vbz5I~//~vbzzR~
//  #endif                                                         //~vbz5I~//~vbzpR~
#endif                                                             //~v79zI~
                    case '2':             //Yn                     //~v449I~
#ifdef W32                                                         //~v449I~
  	#ifndef WXE                                                    //~v500I~
                        forcent2=1;       //force WindowsNT vio proc//~v449I~
    #endif                                                         //~v500I~
#endif                                                             //~v449I~
//#ifdef LNX                                                         //~v79zI~//~v7a7R~
//                    case '8':  //kbd utf8 conv to mb               //~v79zI~//~v7a7R~
//                        break;                                     //~v79zI~//~v7a7R~
//#endif                                                             //~v79zI~//~v7a7R~
                        break;                                     //~v449I~
                    case '9':   //japanese errmsg if avail         //~v08tR~
//                      Suerrmsgopt=(Suerrmsgopt & ~UERR_FORCE_ENGLISH);//~v08tR~
                        break;                                     //~v08tR~
                    default: 
                        uerrexit("Toggle Set parm err(%s)",     //~4C24R~
                                    "トグル設定パラメータエラー(%s)",//~4C24R~
                                    Pparmp[parmno]);
                    }//switch by /Yx
                    cptr++;
                }//until strlen
                break;
//**************************
//* reset option     */N
//**************************
            case 'N':
                while (*cptr)           
                {                       
                    switch (toupper(*cptr))
                    {             
                    case 'A':                                   //~5506I~
                        UCBITOFF(Gopt2,GOPT2REJECTCTLCHAR);     //~5506I~
                        break;                                  //~5506I~
                    case 'C':                                   //~5501I~
                        UCBITON(Gopt2,GOPT2NOCID);              //~5501I~
                        break;                                  //~5501I~
//#ifdef DOS                                                       //~v095R~
#if defined(DOS) && !defined(DPMI)                                 //~v095I~
#else                                                           //~5430I~
                    case 'D':                                   //~4C24I~
                        UCBITON(Gopt,GOPTNOABENDIFERREXIT);//abend at uerrexit//~5430R~
                        break;                                  //~4C24I~
#endif                                                          //~5430I~
                    case 'E':                                      //~vbq7I~
                        break;                                     //~vbq7I~
#ifdef LNX                                                         //~vad0I~
    #if !defined(XXE) && !defined(ARM)                             //~vad0I~
                    case 'I':  //use ICU as local converetr        //~vad0I~
                        break;                                     //~vad0I~
	#endif                                                         //~vad0I~
#endif                                                             //~vad0I~
                    case 'J':  //parmproc00 processed              //~vbmkI~
                        break;                                     //~vbmkI~
//                    case 'L':                                    //~vbzzR~
////                      lfnreq=2;         // /Nl requested         //~v0flI~//~vbzzR~
//                        break;                                   //~vbzzR~
//#ifdef LNX                                                         //~v7a7I~//~va0DR~
#ifdef UTF8SUPPH                                                   //~va0DI~
//#ifdef W32                                                         //~vbt3I~//~vbtaR~
                    case 'M':  //no utf8 kbd input process         //~v7a7I~
//                      udbcschk_wcinit(UDCWCIO_KBDNOUTF8,0/*out locale*/); //read utf encoding byte by byte//~v7acI~//~va0DR~
                        break;                                     //~v7a7I~
//#endif                                                             //~vbt3I~//~vbtaR~
#endif                                                             //~v7a7I~
                    case 'N':             //Yn                     //~v0jtI~
//#ifdef W32                                                         //~v0jtI~//~vbzuR~
//    #ifndef WXE                                                    //~v500I~//~vbzuR~
//                        forcent=0;        //not force WindowsNT kbd proc//~v0jtI~//~vbzuR~
//    #endif                                                         //~v500I~//~vbzuR~
//#endif                                                             //~v0jtI~//~vbzuR~
                        break;                                     //~v0jtI~
                    case 'R':                                   //~5110I~
                      if (toupper(*(cptr+1))=='R')   //Nrr         //~v793R~
                      {                                            //~v793I~
//                      UCBITOFF(Gotheropt,GOTHERO_RCTLNL);//Use R-Ctrl as Enter//~vb27R~
                        ULBITOFF(Gotheropt,GOTHERO_RCTLNL);//Use R-Ctrl as Enter//~vb27R~
                        cptr++;                                    //~v793I~
                      }                                            //~v793I~
                      else                                         //~v793I~
                      {                                            //~van9I~
//  					UCBITON(Gotheropt,GOTHERO_RCTLOFFCL);  //Right Ctrl off by cmdline parm//~vb27R~
    					ULBITON(Gotheropt,(ULONG)GOTHERO_RCTLOFFCL);  //Right Ctrl off by cmdline parm//~vb27R~
                        UCBITOFF(Gopt,GOPTRCTLENTER);//Not Use R-Ctrl as Enter//~5110R~
                      }                                            //~van9I~
                        break;                                  //~5110I~
                    case 'T':                                   //~4C24I~
                        UCBITOFF(Gopt,GOPTTABDISPLAY);//tab display//~4C24I~
                        break;                                  //~4C24I~
//#ifdef LNX                                                         //~vau0I~//~vauER~
                    case 'U':  //use dd fmt to display disrlist    //~vau0I~
//                      Gotheropt&=~GOTHERO_DDFMTDL;//ddfmt dirlist//~vb27R~
                        Gotheropt&=(ULONG)(~GOTHERO_DDFMTDL);//ddfmt dirlist//~vb27I~
                        break;                                     //~vau0I~
//#endif                                                             //~vau0I~//~vauER~
                    case 'V':                                      //~vbzzI~
                        uerrexit("%cV option is deprecated, use %cG option.\n",//~vbzzI~
                                 "%cV オプションは %cG に移行しました。",//~vbzzI~
								CMDFLAG_PREFIX,CMDFLAG_PREFIX);    //~vbzzI~
                        break;                                     //~vbzzI~
#ifdef W32                                                         //~v79zR~
//    #ifndef WXE                                                    //~vbz3I~//~vbzzR~
//                    case 'V':  //kbd and vio by widechar even for Codepage=Japanese on Japanese system//~vbz3I~//~vbzzR~
//                        break;                                     //~vbz3I~//~vbzzR~
//    #else                                                          //~vbz4I~//~vbzzR~
//                    case 'V':  //kbd and vio by widechar even for Codepage=Japanese on Japanese system//~vbz4I~//~vbzzR~
//                        break;                                     //~vbz4I~//~vbzzR~
//    #endif                                                         //~vbz3I~//~vbzzR~
                    case 'W':  //kbd and vio by widechar even for Codepage=Japanese on Japanese system//~v79zI~
                        break;                                     //~v79zI~
#else                                                              //~vbz5I~
//  #ifdef XXE                                                     //~vbz5I~//~vbzpR~
//                    case 'V':  //kbd and vio by widechar even for Codepage=Japanese on Japanese system//~vbz5I~//~vbzzR~
//                        break;                                     //~vbz5I~//~vbzzR~
//  #endif                                                         //~vbz5I~//~vbzpR~
#endif                                                             //~v79zI~
                    case '2':             //Yn                     //~v449I~
#ifdef W32                                                         //~v449I~
  	#ifndef WXE                                                    //~v500I~
                        forcent2=0;        //not force WindowsNT vio proc//~v449I~
	#endif                                                         //~v500I~
#endif                                                             //~v449I~
                        break;                                     //~v449I~
//#ifdef LNX                                                         //~v79zI~//~v7a7R~
//                    case '8':  //no utf8 kbd input process         //~v79zI~//~v7a7R~
//                        udbcschk_wcinit(UDCWCIO_KBDNOUTF8,0/*out locale*/); //read utf encoding byte by byte//~v79zI~//~v7a7R~
//                        break;                                     //~v79zI~//~v7a7R~
//#endif                                                             //~v79zI~//~v7a7R~
                    case '9':   //no japanese errmsg(force english)//~v08tR~
//                      Suerrmsgopt=(Suerrmsgopt|UERR_FORCE_ENGLISH);//~v08tR~
                        break;                                     //~v08tR~
                    default: 
                        uerrexit("Toggle Reset parm err(%s)",   //~4C24R~
                                    "トグル設定解除パラメータエラー(%s)",//~4C24R~
                                    Pparmp[parmno]);
                    }//switch by /Nx
                    cptr++;
                }//until strlen
                break;
//**************************
//* option err             *
//**************************
            default:                           //not option 
//              uerrexit("undefined option parm(%s)",              //~v09YR~
//                          "%s は認識できません",                 //~v09YR~
//                          Pparmp[parmno]);                       //~v09YR~
                cptr=Pparmp[parmno];                               //~v09YI~
                *(Gcmdbuff+posparmlen++)=' ';   //continuation     //~v09YI~
                strcpy(Gcmdbuff+posparmlen,cptr);                  //~v09YI~
                posparmlen+=(int)strlen(cptr);                     //~v09YI~
                if (posparmlen>MAXCOLUMN)                          //~v48qI~
                    uerrexit("Too long parameter",0);              //~v48qI~
            }//switch  by first option byte
        }//option
        else    //not / or -
        {//positional parmno
            posparmno++;
//          switch (posparmno)                                     //~v08tR~
//          {                                                      //~v08tR~
//**************************
//* edit file name
//**************************
//          case  1:          //first parm                         //~v08tR~
//              Sparmfnm=cptr;                                     //~v08tR~
//              break;                                             //~v08tR~
//************************************
//          default:                                               //~v08tR~
//              uerrexit("Too many positional parameter(%s)",      //~v08tR~
//                          "定位置パラメータが多過ぎます(%s)",    //~v08tR~
//                          cptr);                                 //~v08tR~
//          }//switch by parmno                                    //~v08tR~
            *(Gcmdbuff+posparmlen++)=' ';   //continuation         //~v08tR~
//"*" mean last file of prev session                               //~v11zI~
            lastfilemode=0;                                        //~va6GI~
            if (!strcmp(cptr,"*"))                                 //~v11zI~
            {                                                      //~v11zI~
                lastfilemode=inigetlastfile(Gcmdbuff+posparmlen);  //~v11zR~
                if (lastfilemode)   //0 if not saved               //~v11zR~
                {                                                  //~v11zI~
                    *Gcmdbuff=lastfilemode; //B or E               //~v11zR~
                    cptr=Gcmdbuff+posparmlen;                      //~v11zR~
                }                                                  //~v11zI~
            }                                                      //~v11zI~
            strcpy(Gcmdbuff+posparmlen,cptr);                      //~v08tR~
//          posparmlen+=(int)strlen(cptr);                         //~v68kR~
            fnmlen=(int)strlen(cptr);                              //~v68kI~
          if (!lastfilemode)                                       //~va6GI~
            if (strchr(cptr,' '))	//space embedding              //~v68kI~
            {                                                      //~v68kI~
            	memmove(Gcmdbuff+posparmlen+1,Gcmdbuff+posparmlen,(UINT)fnmlen);//~v68kI~
                *(Gcmdbuff+posparmlen)='"';                        //~v68kI~
                *(Gcmdbuff+posparmlen+1+fnmlen)='"';               //~v68kI~
                fnmlen+=2;                                         //~v68kI~
            }                                                      //~v68kI~
            posparmlen+=fnmlen;                                    //~v68kI~
            if (posparmlen>MAXCOLUMN)                              //~v48qI~
                uerrexit("Too long parameter",0);                  //~v48qI~

        }//option or posparm
    }//for all parm
//set EDIT/BROWSE parameter                                        //~v08tR~
    if (posparmno)  //posparm exist                                //~v08tR~
    {                                                              //~v08tR~
        stacksw=1;                                                 //~v08tR~
        if (!*Gcmdbuff)             //no /B nor /E                 //~v08tR~
        {                                                          //~v53rI~
         if (*(Gcmdbuff+2)=='=')                                   //~v8@iI~
         {                                                         //~v8@iI~
         	*Gcmdbuff=' ';  //not edit cmd                         //~v8@iI~
         }                                                         //~v8@iI~
	     else                                                      //~v8@iI~
         {                                                         //~v8@iI~
//          if (strlen(Gcmdbuff+2)==1   //openrand exist           //~v0ifR~
          if (!strcmp(Gcmdbuff+2,PANMOPARM_COLOR)                  //~v0ifR~
          ||  !strcmp(Gcmdbuff+2,PANMOPARM_KCMD)                   //~v0jaR~
          ||  !strcmp(Gcmdbuff+2,PANMOPARM_FKEY)                   //~v0jaR~
          ||  !strcmp(Gcmdbuff+2,PANMOPARM_KLIST)                  //~v0jaR~
//        ||  !strcmp(Gcmdbuff+2,PANMOPARM_FKEY4)                  //~v0iwR~
          ||(strlen(Gcmdbuff+2)==1  //openrand exist               //~v0ifI~
            &&  (*(Gcmdbuff+2)==PANMOPARM                          //~v08tR~
            ||*(Gcmdbuff+2)==PANMOBROWSE                           //~v08tR~
            ||*(Gcmdbuff+2)==PANMOEDIT                             //~v08tR~
            ||*(Gcmdbuff+2)==PANMOCMD))                            //~v08tR~
            )                                                      //~v0ifI~
            {                                                      //~v08tR~
                *Gcmdbuff=' ';  //continueation                    //~v08tR~
                *(Gcmdbuff+1)='=';                                 //~v08tR~
                stacksw=0;  //no cmd stack                         //~v08tR~
            }                                                      //~v08tR~
            else                                                   //~v08tR~
            if (*(Gcmdbuff+2)==PANMOCMD                            //~v8@iI~
            &&  *(Gcmdbuff+3)=='.')     //6.xx                     //~v8@iI~
            {                                                      //~v8@iI~
                *Gcmdbuff=' ';  //continueation                    //~v8@iI~
                *(Gcmdbuff+1)='=';                                 //~v8@iI~
                stacksw=0;  //no cmd stack                         //~v8@iI~
            }                                                      //~v8@iI~
            else                                                   //~v8@iI~
                *Gcmdbuff='E';  //edit command                     //~v08tR~
         }//=xx                                                    //~v8@iI~
        }//Gcmdbuff                                                //~v53rI~
        if (stacksw)                                               //~v08tR~
//          funccmdstack(Gcmdbuff,(int)strlen(Gcmdbuff));          //~v670R~
            funccmdstack(Gcmdbuff,(int)strlen(Gcmdbuff),1);	//seqno=1:of 1st menu//~v670I~
    }                                                              //~v08tR~
    else                                                           //~v55BI~
        if (*Gcmdbuff)             //no /B nor /E                  //~v55BI~
        	uerrexit("%cB (browse) option specified but filename parm missing",0,//~v55BR~
					CMDFLAG_PREFIX);                               //~v55BI~
                                                                   //~v08tR~
    switch(lfnreq)                                                 //~v0flR~
    {                                                              //~v0flI~
    case 0:                                                        //~v0flI~
    case 1:                                                        //~v0flI~
#ifdef DPMI                                                        //~v0flM~
        putenv("LFN=Y");                 //need for ufileisvfat    //~v0flI~
        vfatsw=ufileisvfat(ISVFAT_FORCE);                          //~v0fwR~
        if (lfnreq==1 && !vfatsw)// /Yl and no lfn support)        //~v0flI~
            uerrmsg("No Long File Name Supported",                 //~v0flI~
                    "長いファイル名は使えません");                 //~v0flI~
        break;                                                     //~v0flI~
#endif                                                             //~v0flI~
    case 2:                                                        //~v0flI~
#ifdef DPMI                                                        //~v0flI~
        putenv("LFN=N");                 //need for ufileisvfat    //~v0flI~
#endif                                                             //~v0flM~
        break;                                                     //~v0flI~
    }                                                              //~v0flI~
#ifdef W32                                                         //~v0jtI~
  #ifndef WXE                                                      //~v500I~
//    if (forcent)                                                   //~v0jtR~//~vbzuR~
//        ukbd_w95forcent();                                         //~v0jtI~//~vbzuR~
    if (forcent2)                                                  //~v449I~
        uvio_winopt(UVIOWINFORCENT);                               //~v449R~
  #endif //!WXE                                                    //~v500I~
#endif                                                             //~v0jtI~
    return;
}//parmproc
//**********************************************************************//~vbzrI~
//#ifdef WINCON                                                    //~vbzrR~
#if defined(WINCON) || defined(LNXCON)                             //~vbzrI~
void xeSetConsoleFont(char *PfontParm)                             //~vbzrI~
{                                                                  //~vbzrR~
	char fpath[_MAX_PATH+1],*pfp;                                  //~vbzrI~
//*****************                                                //~vbzrI~
    if (*PfontParm=='@' && strlen(PfontParm)>3 && !memcmp(PfontParm+1,WORKDIRPATHID,WORKDIRPATHIDLEN))//~vbzrR~
    {                                                              //~vbzrI~
        fpath[0]='@';                                              //~vbzrM~
		filefullpath(fpath+1,PfontParm+1,sizeof(fpath)-1);         //~vbzrR~
        pfp=fpath;                                                 //~vbzrI~
    }                                                              //~vbzrI~
    else                                                           //~vbzrI~
    	pfp=PfontParm;                                             //~vbzrI~
    setConsoleFont(pfp);                                           //~vbzrI~
}                                                                  //~vbzrI~
#endif                                                             //~vbzrI~
//**********************************************************************//~5114I~
//* numchk                                                      //~5114I~
//**********************************************************************//~5114I~
int numchk(UCHAR *Pnumstring)                                   //~5114I~
{                                                               //~5114I~
    if (!ISNUMSTR(Pnumstring))                                  //~5114R~
        uerrexit("numeric parm err(%s)",                        //~5114I~
                "全桁数字を指定する(%s)",                       //~5114I~
                            Pnumstring);                        //~5114I~
    return atoi(Pnumstring);                                    //~5114R~
}                                                               //~5114I~
//**********************************************************************
//* write help msg  
//**********************************************************************
void titlemsg(void)
{
#ifdef XXE                                                         //~vbdaI~
    char verdate[32];                                              //~vbdaI~
#endif                                                             //~vbdaI~
//*************************                                        //~vbdaI~
#ifdef XXE                                                         //~vbdaI~
  	#ifndef OPTGTK3                                                //~vbdaI~
	    sprintf(verdate,"%s:GTK2",Gverdate);                       //~vbdaR~
    #else                                                          //~vbdaI~
	    sprintf(verdate,"%s:GTK3",Gverdate);                       //~vbdaR~
    #endif                                                         //~vbdaI~
#endif                                                             //~vbdaI~
//  uerrmsg_init(Spgmver,stdout,0);//msg to stdout                 //~v21iR~
    uerrmsg_init(Spgmver,stdout,Suerrmsgopt);//msg to stdout       //~v21iI~
//  uerrmsg("\n(%c) === Hybrid Editor (%s) ============ by MIZUMAKI-machi ===",//~v085R~//~v7a3R~//~va71R~
//          "\n(%c) === Hybrid Editor (%s) ================== by 水巻マチ ==",//~v13mR~//~v7a3R~//~va71R~
#ifdef XXE                                                         //~vbdaI~
    uerrmsg("\n(%c%s) === Hybrid Editor (%s) ===== by MIZUMAKI-machi ===",//~vbdaI~
            "\n(%c%s) === Hybrid Editor (%s) =========== by 水巻マチ ==",//~vbdaI~
#else                                                              //~vbdaI~
    uerrmsg("\n(%c%s) === Hybrid Editor (%s) ========== by MIZUMAKI-machi ===",//~va71I~
            "\n(%c%s) === Hybrid Editor (%s) ================ by 水巻マチ ==",//~va71I~
#endif                                                             //~vbdaI~
//#ifdef DOS                                                       //~v19bR~
//    #ifdef DPMI                 //DPMI version                   //~v19bR~
//            'G',                                                 //~v19bR~
//    #else                       //not DPMI                       //~v19bR~
//            'D',                                                 //~v19bR~
//    #endif                      //DPMI or not                    //~v19bR~
//#else                                                            //~v19bR~
//    #ifdef W32                                                   //~v19bR~
//            'W',                                                 //~v19bR~
//    #else                                                        //~v19bR~
//            '2',                                                 //~v19bR~
//    #endif                                                       //~v19bR~
//#endif                                                           //~v19bR~
            OSTYPE,                                                //~v19bI~
#ifdef ULIB64                                                      //~va71I~
	#if OSTYPE=='z'                                                //~va71I~
			"",                                                    //~va71I~
    #else                                                          //~va71I~
			"64",                                                  //~va71R~
    #endif                                                         //~va71I~
#elif defined(ULIB64X)                                             //~vafrI~
//            "64",                                                //~vaiwR~
            "",                                                    //~vaiwI~
#else                                                              //~va71I~
			"",                                                    //~va71I~
#endif                                                             //~va71I~
#ifdef XXE                                                         //~vbdaI~
            verdate);                                              //~vbdaI~
#else                                                              //~vbdaI~
            Gverdate);                                          //~v031R~
#endif                                                             //~vbdaI~
#ifndef NOTRACE                                                    //~vbzLI~
    printf("end of pid:%ld\n",ugetpid());                          //~vbzLR~
#endif                                                             //~vbzLI~
    return;
}//titlemsg
//**********************************************************************
//* write help msg  
//**********************************************************************
void help(void)
{
#define HELPMSG uerrhelpmsg(stdout,stderr,                         //~v11EI~
//*******************
    uerrmsg_init(0,stdout,Suerrmsgopt);//msg to stdout             //~v11ER~
    uerrexit_init(0,stdout,0,0,0);//stdout only,no pathmsg         //~v11ER~
                                                                //~4C27I~
    HELPMSG "format ========: %s [edit-file-name|*] [%coption %c...]\n",//~v21cR~
            " 形式  ========: %s [編集ファイル名|*] [%cオプション %c...]\n",//~v21cR~
#ifdef WXE                                                         //~vb2VI~
            "w" PGMID,CMDFLAG_PREFIX,CMDFLAG_PREFIX);              //~vb2VI~
#else                                                              //~vb2VI~
            PGMID,CMDFLAG_PREFIX,CMDFLAG_PREFIX);                  //~v21cR~
#endif                                                             //~vb2VI~
        HELPMSG                                                    //~vagEI~
"*******************************************************************************\n", //80 column limit indicator//~vagEI~
"*******************************************************************************\n");//~vagEI~
    HELPMSG " edit-file-name:goto Edit screen when specified\n",   //~v11ER~
            " 編集ファイル名:指定すると直接編集画面を呼び出す\n"); //~v11ER~
    HELPMSG "                *:open last closed.\n",               //~v11ER~
            "                *:最後にクローズしたファイルをオープン\n");//~v11ER~
    HELPMSG " option        :see following(case insensitive,no seq,last effective if dup)\n",//~v11ER~
            " オプション    :以下を参照,大文字小文字の区別なし,順不同,重複は最後が有効\n");//~v11ER~
    HELPMSG "  %cB           :Browse mode open\n",                 //~v21cR~
//          "  /B           :表示モードでファイルを開く\n");       //~v11ER~
            "  %cB           :\x95\\示モードでファイルを開く\n",   //~v21cR~
			CMDFLAG_PREFIX);                                       //~v21cI~
#ifdef WCSUPP                                                      //~v79zM~
  #ifdef W32                                                       //~v79zM~
    HELPMSG "  %cC           :Kbd/Screen CodePage (other than UTF8).\n",//~v79zI~
            "  %cC           :キーボード/画面のコードページ (UTF8以外)\n",//~v79zI~
			CMDFLAG_PREFIX);                                       //~v79zM~
  #else                                                            //~v79zM~
    HELPMSG "  %cC           :Kbd/Screen CharSet (other than UTF8).\n",//~v79zI~
            "  %cC           :キーボード/画面の文字セット\n",      //~v79zI~
			CMDFLAG_PREFIX);                                       //~v79zM~
  #endif                                                           //~v79zM~
//  HELPMSG "  %cC{%s/%s/%s}   :Use EBCDIC internal mapping table.\n",//~vbB6I~//~vbB8R~
//          "  %cC{%s/%s/%s}   :EBCDIC 内部マッピングテーブル使用.\n",//~vbB6I~//~vbB8R~
//            CMDFLAG_PREFIX,EBC_KANA,EBC_ENG,EBC_US);               //~vbB6I~//~vbB8R~
#endif                                                             //~v79zM~
  if (Sdebughelp)                                                  //~v53rI~
  {                                                                //~v53rI~
//    HELPMSG "  /Dx[t]       :memory alloc trace+debug trace\n",  //~v20aR~
//            "  /Dx[t]       :メモリ－取得トレース+デバッグ用トレ－ス\n");//~v20aR~
//    HELPMSG "           x   :0:no memory trace(default),1:statistic,2:trace(%s%s.mtr)\n",//~v20aR~
//            "           x   :0:トレースなし(省略値),1:統計,2:トレ－ス(%s%s.mtr)\n",PGMID,Sostype);//~v20aR~
//    HELPMSG "           t   :0:no debug trace(default),1:write trace(%s%s.trc)\n",//~v20aR~
//            "           t   :0:デバッグ用トレースなし(省略値),1:トレ－ス(%s%s.trc)\n",PGMID,Sostype);//~v20aR~
    HELPMSG "  %cDx[t][o]    :malloc trace+debug trace+other debug option.\n",//~v53rI~
            "  %cDx[t][o]    :メモリ－トレース+デバッグトレ－ス+その他オプション。\n",//~v53rR~
			CMDFLAG_PREFIX);                                       //~v53rI~
//  HELPMSG "           x   :0:no memory trace(default),1:statistic,2:trace(%s%s%s.mtr),\n",//~v53sR~//~vaj8R~
//          "           x   :0:トレースなし(省略値),1:統計,2:トレ－ス(%s%s%s.mtr),\n",//~v53sR~//~vaj8R~
    HELPMSG "           x   :0:no memory trace(default),1:statistic,\n",//~vaj8I~
            "           x   :0:トレースなし(省略値),1:統計,\n");   //~vaj8R~
//  HELPMSG "               :2:trace(%s%s%s.mtr),\n",              //~vaj8I~//~vbkmR~
//          "               :2:トレ－ス(%s%s%s.mtr),\n",           //~vaj8I~//~vbkmR~
    HELPMSG "               :2:trace(%s%s%s.mtr.[pid]),\n",        //~vbkmI~
            "               :2:トレ－ス(%s%s%s.mtr.[pid]),\n",     //~vbkmI~
				Gworkdir,PGMID,Sostype);                           //~v53rI~
    HELPMSG "               :3:2 level return addr print on tarce file.\n",//~v53sR~
            "               :3:2階層上まで戻りアドレスをトレースファイルに書く。\n");//~v53sR~
    HELPMSG "     (DOS,WIN) :\"`\",\"a\",\"b\":alloc just request size.(default except DOS/WIN)\n",//~v53rR~
            "     (DOS,WIN) :\"`\",\"a\",\"b\":要求サイズでalloc。(DOS,WIN以外の省略値）\n");//~v53rI~
    HELPMSG "     (DOS,WIN) :DOS/WIN default is min 80 byte and expand to 32 byte boundary.\n",//~v53rR~
            "     (DOS,WIN) :DOS,WINの省略値は最小80Byteかつ次の32Byte境界に拡張。\n");//~v53rI~
    HELPMSG "               :\"@\",\"A\",\"B\":exit if alloc failed.(contains precise option)\n",//~v53rR~
            "               :\"@\",\"A\",\"B\":alloc失敗でexitする。(要求サイズallocを含む）\n");//~v53rI~
//  HELPMSG "           t   :0:no debug trace(default),1:write trace(%s%s%s.trc)\n",//~v53rI~//~vaj8R~
//          "           t   :0:デバッグ用トレースなし(省略値),1:トレ－ス(%s%s%s.trc)\n",//~v53rI~//~vaj8R~
    HELPMSG "           t   :0:no debug trace(default)\n",         //~vaj8I~
            "           t   :0:デバッグ用トレースなし(省略値)\n"); //~vaj8I~
//  HELPMSG "               :1:write trace(%s%s%s.trc)\n",         //~vaj8I~//~vbkmR~
//          "               :1:トレ－ス(%s%s%s.trc)\n",            //~vaj8I~//~vbkmR~
    HELPMSG "               :1:write trace(%s%s%s.trc.[pid])\n",   //~vbkmI~
            "               :1:トレ－ス(%s%s%s.trc.[pid])\n",      //~vbkmR~
				Gworkdir,PGMID,Sostype);                           //~v53rI~
    HELPMSG "           o   :a:abend by doubled Esc key, e:exit by doubled Esc key,\n",//~v53rR~
            "           o   :a:Escキー2回連続でabendする, e:Escキー2回連続でexitする,\n");//~v53rR~
//  HELPMSG "               :k:keyboard trace(W95 only).\n",       //~v53rR~//~vbkmR~
//          "               :k:キーボードトレースする(W95のみ)。\n");//~v53rR~//~vbkmR~
#ifdef W32                                                         //~vbkmI~
  #ifndef WXE                                                      //~vbkmI~
    HELPMSG "               :k:Write Windows keyboard trace.(xe only)\n",//~vbkmR~
            "               :k:Windowsキーボードトレースをとる(xeのみ)\n");//~vbkmR~
  #endif                                                           //~vbkmI~
#endif                                                             //~vbkmI~
    HELPMSG "               :n:NO write _kbd trace(%s%s%s.trc%s.[pid])\n",//~vbkmI~
            "               :n:_kbd トレ－ス(%s%s%s.trc%s.[pid])出力なし\n",//~vbkmI~
				Gworkdir,PGMID,Sostype,UTRACE_FORCE_FNMSUFFIX);    //~vbkmI~
    HELPMSG "               :c:remove old _kbd trace files.\n",    //~vbkmI~
            "               :c:古い_kbd トレースファイルを削除\n");//~vbkmI~
    HELPMSG "               :keep latest %d files if not specified.\n",//~vbkmR~
            "               :指定のない場合は直近の%dファイルを保持\n",//~vbkmR~
			XCTFO_KBD_KEEP_COUNT); //       5          //keep max 5 file if not clear specified//~vbkmI~
  }                                                                //~v53rI~
    HELPMSG "  %cE           :Edit mode open(default)\n",          //~v21cR~
            "  %cE           :編集モードでファイルを開く(省略値)\n",//~v21cR~
			CMDFLAG_PREFIX);                                       //~v21cI~
//    HELPMSG "  %cEBC[=]{%s|%s|%s|%s} : EBCDIC mapping table\n",//~vbB8R~//~vbB9R~//~vbBcR~
//            "  %cEBC[=]{%s|%s|%s|%s} : EBCDIC 変換\x95\\\n",//~vbB8R~//~vbB9R~//~vbBcR~
//              CMDFLAG_PREFIX,EBC_STRKANA,EBC_STRENG,EBC_STRLATIN,EBC_STRUS);//~vbB8R~//~vbB9R~//~vbBcR~
//    HELPMSG "  %cEBC[=]{%s|%s|%s|%s|cfg=[no|filepath]} : EBCDIC mapping table\n",//~vbBcR~//~vbBeR~
//            "  %cEBC[=]{%s|%s|%s|%s|cfg=[no|filepath]} : EBCDIC 変換\x95\\\n",//~vbBcR~//~vbBeR~
//    HELPMSG "  %cEBC[=]{%s|%s|%s|%s|cfg=filepath} : EBCDIC mapping table\n",//~vbBeI~//~vbBsR~
//            "  %cEBC[=]{%s|%s|%s|%s|cfg=filepath} : EBCDIC 変換\x95\\\n",//~vbBeI~//~vbBsR~
//              CMDFLAG_PREFIX,EBC_STRKANA,EBC_STRENG,EBC_STRLATIN,EBC_STRUS);//~vbBcI~//~vbBsR~
//    HELPMSG "  %cEBC[=]{%s|%s|%s|cfg=filepath} : EBCDIC mapping table\n",//~vbBsI~//~vbBtR~
//            "  %cEBC[=]{%s|%s|%s|cfg=filepath} : EBCDIC 変換\x95\\\n",//~vbBsI~//~vbBtR~
//              CMDFLAG_PREFIX,EBC_STRKANA,EBC_STRENG,EBC_STRUS);    //~vbBsI~//~vbBtR~
    HELPMSG "  %cEBC[=]{%s|%s|%s|%s|cfg=filepath} : mapping tb\n", //~vbBtR~
            "  %cEBC[=]{%s|%s|%s|%s|cfg=filepath} : 変換\x95\\\n", //~vbBtR~
              CMDFLAG_PREFIX,EBC_STRKANA,EBC_STRENG,EBC_STRUS,EBC_STRUS_EURO);//~vbBtR~
    HELPMSG "                %s(=%s=%s+%s)  : Japanese Extended,Katakana.\n",//~vbB8R~//~vbB9R~//~vbBeR~
            "                %s(=%s=%s+%s)  : 日本語拡張,カタカナ\n",//~vbB8R~//~vbB9R~//~vbBeR~
              EBC_STRKANA,EBC_KANA,EBC_SBCSKANA,EBC_DBCSJP);       //~vbB8R~
    HELPMSG "                %s(=%s=%s+%s)  : Japanese Extended,Lowercase.\n",//~vbB8R~//~vbB9R~//~vbBdR~//~vbBeR~
            "                %s(=%s=%s+%s)  : 日本語拡張,英数小文字\n",//~vbB8R~//~vbB9R~//~vbBeR~
              EBC_STRENG,EBC_ENG,EBC_SBCSENG,EBC_DBCSJP);          //~vbB8I~
//    HELPMSG "                %s(=%s=%s+%s): Japanese Extended Latin-Kanji.\n",//~vbB8R~//~vbB9R~//~vbBdR~//~vbBeR~
//            "                %s(=%s=%s+%s): 日本語拡張 Latin+漢字\n",//~vbB8R~//~vbB9R~//~vbBdR~//~vbBeR~
//    HELPMSG "                %s(=%s=%s+%s): Japanese Extended,Latin-1 and Kanji.\n",//~vbBeR~//~vbBsR~
//            "                %s(=%s=%s+%s): 日本語拡張,Latin-1+漢字\n",//~vbBeR~//~vbBsR~
//              EBC_STRLATIN,EBC_KANJI_LATIN,EBC_US,EBC_DBCSJP);     //~vbB8R~//~vbB9R~//~vbBsR~
//    HELPMSG "                %s(=%s)                 : US English, NO DBCS.\n",//~vbB8R~//~vbB9R~//~vbBcR~//~vbBeR~
//            "                %s(=%s)                 : 米国英語、日本語DBCSなし\n",   //~vbB8R~//~vbB9R~//~vbBcR~//~vbBeR~
    HELPMSG "                %s(=%s)            : to Latin-1, NO Japanese-Kanji.\n",//~vbBeR~
            "                %s(=%s)            : 全Latin-1, 漢字なし\n",//~vbBeR~
              EBC_STRUS,EBC_US);                                   //~vbB8R~
    HELPMSG "                %s(=%s+Euro).\n",                     //~vbBtI~
            "                %s(=%s+Euro)\n",                      //~vbBtI~
              EBC_STRUS_EURO,EBC_US);                              //~vbBtI~
//    HELPMSG "                cfg=[no|filepath] : Ignore or overide ini-file:EBCDIC_CFG.\n",//~vbBcR~//~vbBeR~
//            "                cfg=[no|filepath] : iniファイル:EBCDIC_cfgの無視/変更\n");//~vbBcR~//~vbBeR~
    HELPMSG "                cfg=[no|filepath] : Temporally overide EBCDIC_CFG of ini file.\n",//~vbBeR~
            "                cfg=filepath : iniファイルのEBCDIC_cfgの一時的変更\n");//~vbBeR~
#ifdef FTPSUPP                                                     //~v53YM~
  if (Sdebughelp)                                                  //~v54xI~
//  HELPMSG "  %cFx[t][:hosts]:FTP option: x=0:no use FTP func, x=1:use FTP w/o log,\n",//~v54xI~//~vaj8R~
//          "  %cFx[t][:hosts]:FTP option: x=0:FTP 不使用, x=1:FTP 使用(log無し),\n",//~v54xI~//~vaj8R~
    HELPMSG "  %cFTPx[t][:hosts]:FTP option: x=0:no use FTP func, x=1:use FTP w/o log,\n",//~vaj8I~
            "  %cFTPx[t][:hosts]:FTP option: x=0:FTP 不使用, x=1:FTP 使用(log無し),\n",//~vaj8I~
			CMDFLAG_PREFIX);                                       //~v54xI~
  else                                                             //~v54xI~
//  HELPMSG "  %cFx[:hosts]  :FTP option: x=0:no use FTP func, x=1:use FTP w/o log,\n",//~v54nR~//~vaj8R~
//          "  %cFx[:hosts]  :FTP option: x=0:FTP 不使用, x=1:FTP 使用(log無し),\n",//~v54nR~//~vaj8R~
    HELPMSG "  %cFTPx[:hosts]:FTP option: x=0:no use FTP func, x=1:use FTP w/o log,\n",//~vaj8R~
            "  %cFTPx[:hosts]:FTP option: x=0:FTP 不使用, x=1:FTP 使用(log無し),\n",//~vaj8R~
			CMDFLAG_PREFIX);                                       //~v53YI~
    HELPMSG "               :            x=w:write ftplog, x=a:append mode ftplog.\n",//~v53YR~
            "               :            x=w:ftplog 出力, x=a:追加モード ftplog。\n");//~v53YR~
  if (Sdebughelp)                                                  //~v54xI~
    HELPMSG "               :t:temporary work directory is kept for debug.\n",//~v54xI~
            "               :t:一時ワークDirを削除しない、デバッグ用オプション。\n",//~v54xR~
							FTPHOSTS);                             //~v54xI~
    HELPMSG "               :hosts: hosts file for xe.\n",         //~v54nR~
            "               :hosts: xe 用のホストファイル。\n",    //~v54nR~
							FTPHOSTS);                             //~v54nI~
//    HELPMSG "               :Default is %cF1.(hosts=\"%s\", log=\"%s\").\n",//~v53YR~//+vbBxR~
//            "               :省略値は %cF1。(hosts=\"%s\", log=\"%s\")。\n",//~v53YR~//+vbBxR~
    HELPMSG "               :Default is %cFTP1.(hosts=\"%s\", log=\"%s\").\n",//+vbBxI~
            "               :省略値は %cFTP1。(hosts=\"%s\", log=\"%s\")。\n",//+vbBxI~
			CMDFLAG_PREFIX,FTPHOSTS,FTPLOG);                       //~v53YI~
#endif                                                             //~v53YM~
#ifdef WINCON                                                      //~vbzqI~
//    HELPMSG "  %cF{[8-]fontname[:charset] | @font_param_filename}\n",//~vbzqR~//~vbzCR~
//            "  %cF{[8-]fontname[:charset] | @font_param_filename}\n",//~vbzqR~//~vbzCR~
    HELPMSG "  %cF{fontname[:charset] | @font_param_filename}\n",  //~vbzCI~
            "  %cF{fontname[:charset] | @font_param_filename}\n",  //~vbzCI~
			CMDFLAG_PREFIX);                                       //~vbzqI~
    HELPMSG "               :Font parameter when run on WindowsTerminal.\n",//~vbzqI~
            "               :WindowsTerminal 上で実行するときのフォントパラメータ\n");//~vbzqI~
//    HELPMSG "               :Refer settings of WindowsTerminal if you see misaligned char.\n",//~vbzqR~//~vbzAR~
//            "               :桁ずれが生じる場合、WindowsTerminalの設定に合わせてください。\n");//~vbzqI~//~vbzAR~
    HELPMSG "               :Specify when xe failed to get fontname from settings.json.\n",//~vbzAI~//~vbzCR~
            "               :xe は setting.json を調べるがそれが失敗する場合に指定する\n");//~vbzAR~
//  HELPMSG "               :Prefix '8-' is for UTF8 encoded fontname.\n",//~vbzqR~//~vbzCR~
//          "               :UTF8コードで指定するときは プレフィックス '8-' をつける。\n");//~vbzqI~//~vbzCR~
    HELPMSG "               :font_param_filename is for indirect specification.\n",//~vbzqR~
            "               :ファイルで間接的に指定するときは font_param_filename を使用。\n");//~vbzqR~
    HELPMSG "               :proper charset for the font? See Microsoft Documen(0-->255).\n",//~vbzqI~
            "               :フォントに合った charset は Microsoft の ドキュメント参照。\n");//~vbzqR~
//  HELPMSG "               :e.g) /F\"Times Roman:0\", /F@.\\fontParm.txt.\n",//~vbzqR~//~vbzCR~
//          "               :例) /F\"ＭＳ 明朝\":128 、/F@.\\fontParm.txt。\n");//~vbzqR~//~vbzCR~
    HELPMSG "               :e.g) /F\"Consolas:0\", /F@.\\fontParm.txt.\n",//~vbzCR~
            "               :例) /F\"ＭＳ 明朝\":128 、/F@.\\fontParm.txt。\n");//~vbzCR~
    HELPMSG "               :     /F\"\\uff2d\\uff33 \\u660e\\u671d\".\n",//~vbzCR~
            "               :    /F\"\\uff2d\\uff33 \\u660e\\u671d\"。\n");//~vbzCR~
#endif                                                             //~vbzqI~
#ifdef LNXCON                                                      //~vbzrI~
//    HELPMSG "  %cF{[8-]fontname | @font_param_filename}\n",        //~vbzrI~//~vbzCR~
//            "  %cF{[8-]fontname | @font_param_filename}\n",        //~vbzrI~//~vbzCR~
    HELPMSG "  %cF{fontname | @font_param_filename}\n",            //~vbzCI~
            "  %cF{fontname | @font_param_filename}\n",            //~vbzCI~
			CMDFLAG_PREFIX);                                       //~vbzrI~
//  HELPMSG "               :When -GY is specified, cell width of unicode chars said to be\n",//~vbzzR~//~vbAnR~
//          "               :-GY オプションの\x95\\示幅が不明瞭とされるユニコード文字の\x95\\示幅は\n");//~vbzzI~//~vbAnR~
    HELPMSG "               :Font name is required to apply -GY option for cell width.\n",//~vbAnR~
            "               :-GY オプションの適用で使用するフォント名を指定する。\n");//~vbAnI~
//  HELPMSG "               :ambiguous are adjusted using this. No fontname, no adjusting.\n",//~vbzzR~//~vbAnR~
//          "               :このフォントに従って調整する。指定がないと -GY は無視されます。\n");//~vbzzI~//~vbAnR~
    HELPMSG "               :xe tries to get it from setting files for gnome-terminal,\n",//~vbAnR~
            "               :gnome-terminal, konsole などでは設定ファイルを調べますが,\n");//~vbAnR~
//    HELPMSG "               :Specify with -GY option if you see overrapped char display.\n",//~vbzzI~//~vbzAR~
//            "               :桁ずれが生じる場合に指定してください。\n");//~vbzzI~//~vbzAR~
//  HELPMSG "               :On gnome-terminal, xe tries to get it using dconf command.\n",//~vbzAI~//~vbAnR~
//          "               :gnome-terminal の場合 xe は dconf コマンドで調べますが、\n");//~vbzAR~//~vbAnR~
    HELPMSG "               :konsole,... If it failed, specify this parameter.\n",//~vbAnR~
            "               :それが失敗する場合はここでの指定が必要です。\n");//~vbAnI~
//  HELPMSG "               :Specify this parameter if it failed.\n",//~vbzAR~//~vbAnR~
//          "               :それが失敗する場合は指定が必要です。\n");//~vbzAI~//~vbAnR~
//  HELPMSG "               :Prefix '8-' is for UTF8 encoded fontname.\n",//~vbzrI~//~vbzCR~
//          "               :UTF8コードで指定する場合は プレフ｣ックス '8-' を指定する。\n");//~vbzrI~//~vbzCR~
    HELPMSG "               :font_param_filename is for indirect specification.\n",//~vbzrI~
            "               :ファイルで間接的に指定する場合は font_param_filename を指定。\n");//~vbAnI~
//  HELPMSG "               :e.g) -F\"Times Roman 16\", -F@./fontParm.txt.\n",//~vbzrR~//~vbzCR~
//          "               :例 -F\"ＭＳ 明朝 20\" 、-F@./fontParm.txt。\n");//~vbzrR~//~vbzCR~
    HELPMSG "               :e.g) /F\"Ubuntu Mono\", /F@.\\fontParm.txt.\n",//~vbzCR~
            "               :例) /F\"Ubuntu Mono\", /F@.\\fontParm.txt.\n");//~vbzCR~
    HELPMSG "               :     /F\"\\uff2d\\uff33 \\u660e\\u671d\".\n",//~vbzCI~
            "               :    /F\"\\uff2d\\uff33 \\u660e\\u671d\"。\n");//~vbzCI~
#endif                                                             //~vbzrI~
//#ifdef LNX                                                         //~vbzyI~//~vbzZR~
//    HELPMSG "  %cG{A|Y|N}{y|0|1|2}:Adjust display width of ambiguous type of Unicode.\n",//~vbzyI~//~vbzYR~//~vbzZR~
//            "  %cG{A|Y|N}{y|0|1|2}:\x95\\示幅が曖昧とされているユニコード文字の\x95\\示幅の調整。\n",//~vbzyI~//~vbzYR~//~vbzZR~
//            CMDFLAG_PREFIX);                                       //~vbzyI~//~vbzZR~
//    HELPMSG "               :N:Use 1 or 2 cell or unprintable('0') for all ambiguous.\n",//~vbzyI~//~vbzZR~
//            "               :N:曖昧なユニコードは一律に１桁又は２桁か印刷不\x94\\扱い('0')とする\n");//~vbzyI~//~vbzZR~
//    HELPMSG "               :When %cGA/Y, {y|0|1|2} is separately for unfamiliar languages.\n",//~vbzyI~//~vbzYR~//~vbzZR~
//            "               :%cGA/Yのときの {y|0|1|2} は別途、馴染みの少ない言語についての指定\n",//~vbzyI~//~vbzYR~//~vbzZR~
//            CMDFLAG_PREFIX);                                       //~vbzyI~//~vbzZR~
//    HELPMSG "               :y:Adjust for also unfamiliar languages.\n",//~vbzyI~//~vbzZR~
//            "               :y:馴染みの少ない言語についても調整する。\n");//~vbzyI~//~vbzZR~
//    HELPMSG "               :Default is %cA. it follows API(wcwidth).\n",//~vbzYR~//~vbzZR~
//            "               :省略値は %cGA で システムの API(wcwidth) に従う。\n",//~vbzYR~//~vbzZR~
//            CMDFLAG_PREFIX);                                       //~vbzYR~//~vbzZR~
//    HELPMSG "               :e.g) %cGN2 use 2 cells for all Ambiguous.\n",//~vbzyI~//~vbzZR~
//            "               :例）%cGN2 全ての曖昧文字は２桁\x95\\示\n",//~vbzyI~//~vbzZR~
//            CMDFLAG_PREFIX);                                       //~vbzyI~//~vbzZR~
//    HELPMSG "               :     %cGYy Adjust for all Ambiguous by font used.\n",//~vbzyI~//~vbzZR~
//            "               :    %cGYy 全ての曖昧文字をフォントに従い調整する\n",//~vbzyI~//~vbzZR~
//            CMDFLAG_PREFIX);                                       //~vbzyI~//~vbzZR~
//    HELPMSG "               :     %cGY0 Display ':;' for unfamiliar languages.\n",//~vbzyI~//~vbzZR~
//            "               :    %cGY0 馴染みの少ない言語は':;' で代替\x95\\示\n",//~vbzyI~//~vbzZR~
//            CMDFLAG_PREFIX);                                       //~vbzyI~//~vbzZR~
//#else                                                              //~vbzyI~//~vbzZR~
    HELPMSG "  %cG{Y|N}{y|0|1|2}:Adjust display width of ambiguous type of Unicode.\n",//~vbzzR~//~vbzYR~
            "  %cG{Y|N}{y|0|1|2}:\x95\\示幅が曖昧とされているユニコード文字の\x95\\示幅の調整。\n",//~vbzzR~//~vbzYR~
			CMDFLAG_PREFIX);                                       //~vbzzI~
    HELPMSG "               :N:Use 1 or 2 cell or unprintable('0') for all ambiguous.\n",//~vbzzR~
//          "               :N:曖昧なユニコードは一律に１桁又は２桁か印刷不\x94\\扱い('0')とする\n");//~vbzzI~//~vbzzR~//~vbAnR~
            "               :N:曖昧なユニコードは一律１桁又は２桁か印刷不\x94\\扱い('0')とする\n");//~vbAnI~
    HELPMSG "               :When %cGY, {y|0|1|2} is separately for unfamiliar languages.\n",//~vbzzR~
            "               :%cGYのときの {y|0|1|2} は別途、馴染みの少ない言語についての指定\n",//~vbzzR~
			CMDFLAG_PREFIX);                                       //~vbzzI~
    HELPMSG "               :y:Adjust for also unfamiliar languages.\n",//~vbzzR~
            "               :y:馴染みの少ない言語についても調整する。\n");//~vbzzR~
    HELPMSG "               :Default is %cGY2.\n",                 //~vbzzR~
            "               :省略値は %cGY2。\n",                  //~vbzzR~
			CMDFLAG_PREFIX);                                       //~vbzzI~
    HELPMSG "               :e.g) %cGN2 use 2 cells for all Ambiguous.\n",//~vbzAI~
            "               :例）%cGN2 全ての曖昧文字は２桁\x95\\示\n",//~vbzAR~
			CMDFLAG_PREFIX);                                       //~vbzAI~
    HELPMSG "               :     %cGYy Adjust for all Ambiguous by font used.\n",//~vbzAR~
            "               :    %cGYy 全ての曖昧文字をフォントに従い調整する\n",//~vbzAR~
			CMDFLAG_PREFIX);                                       //~vbzAI~
    HELPMSG "               :     %cGY0 Display ':;' for unfamiliar languages.\n",//~vbzAI~
            "               :    %cGY0 馴染みの少ない言語は':;' で代替\x95\\示\n",//~vbzAR~
			CMDFLAG_PREFIX);                                       //~vbzAI~
//#endif  //else LNX                                                 //~vbzyI~//~vbzZR~
//#ifdef WINCON                                                      //~vbzzI~//~vbzAR~
//    HELPMSG "               :For WindowsTerminal, apply /GN2 if /F param is missing.\n",//~vbzzR~//~vbzAR~
//            "               :但しWindowsTerminalの場合、フォント(/F)の指定なしは /GN2 を適用\n");//~vbzzR~//~vbzAR~
//#endif                                                             //~vbzzI~//~vbzAR~
#ifdef LNXCON                                                      //~vbzzR~
//    HELPMSG "               :For console version xe, -GY requires -F parameter also.\n",//~vbzzR~//~vbzyR~
//            "               :コン\x83\\ール版では -GY のときは -F の指定が必要。\n");//~vbzzR~//~vbzyR~
//  HELPMSG "               :For console version xe may request -F parameter when -Gy.\n",//~vbzyI~//~vbAnR~
//          "               :コン\x83\\ール版では -GY のときは -F の指定が必要な場合がある\n");//~vbzyI~//~vbAnR~
#endif                                                             //~vbzzI~
    HELPMSG "  %cH,%c?        :Help\n",                            //~v21cR~
            "  %cH,%c?        :ヘルプ\n",                          //~v21cR~
			CMDFLAG_PREFIX,CMDFLAG_PREFIX);                        //~v21cI~
//#ifdef W32                                                       //~v47rR~
//#if defined(W32) || defined(AIX)                                 //~v47sR~
#if defined(W32) || defined(UNX)                                   //~v47sI~
//#ifndef WXE                                                      //~v641R~
  #ifndef WXEXXE                                                   //~v641I~
    HELPMSG "  %cHnn         :nn=screen height(row count)\n",      //~v47mR~
            "  %cHnn         :nn=画面高の行数\n",                  //~v47rR~
			CMDFLAG_PREFIX);                                       //~v47mI~
  #endif                                                           //~v500I~
#endif                                                             //~v47mI~
#if defined(W32) || defined(LNX)                                   //~v71AI~
    HELPMSG "  %cHDdirname   :dirname:directry of html file for help\n",//~v71AI~
            "  %cHDdirname   :dirname:ヘルプ用 html ファイルのディレクトリー\n",//~v71AI~
			CMDFLAG_PREFIX);                                       //~v71AI~
#endif                                                             //~v71AI~
    HELPMSG "  %cI[fname]    :ini filename to be used.if not use,specify simply %cI\n",//~v21cR~
            "  %cI[fname]    :使用する iniファイル名.使用しない時は単に %cI とする\n",//~v21cR~
			CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX);         //~v21cI~
    HELPMSG "               :default is %s.ini if missing this option.\n",//~v11ER~
            "               :無指定の時は %s.ini が使用される\n",  //~v11ER~
                            PGMID);                             //~5501I~
    HELPMSG "  %cR           :Restore default drive,current directory of prev session.\n",//~v21cR~
            "  %cR           :前のセッションの省略時ドライブ,現行ディレクトリーを復元\n",//~v21cR~
			CMDFLAG_PREFIX);                                       //~v21cI~
    HELPMSG "  %cT           :TAB skip position,default=%d\n",     //~v21cR~
            "  %cT           :タブ桁位置,省略値=%d\n",             //~v21cR~
                    CMDFLAG_PREFIX,TABSKIPCOUNT);                  //~v21cR~
#ifdef UTF8SUPPH //merged version                                  //~va00I~
//  HELPMSG "  %cU{F}        :UTF8 option;\n",                     //~va00I~//~va1mR~
//          "  %cU{F}        :UTF8 処理；\n",                      //~va00I~//~va1mR~
//  HELPMSG "  %cU{8|L}      :UTF8 option;\n",                     //~va1mR~//~va1nR~
//          "  %cU{8|L}      :UTF8 オプション;\n",                 //~va1mR~//~va1nR~
    HELPMSG "  %cU{F|N}{8|L} :Defualt encoding option.\n",         //~va1nR~
            "  %cU{F|N}{8|L} :省略時エンコーディング。\n",         //~va1nR~
                    CMDFLAG_PREFIX);                               //~va00I~
//  HELPMSG "               : F:Assume all file is UTF8 encoded\n",//~va00I~//~va1mR~
//          "               : F:ファイルは全てUTF8エンコーデッドとみなす。\n");//~va1mR~
    HELPMSG "               : N:for filename, F: for contents, 8:UTF8, L:locale code\n",//~va1mR~//~va1nR~
            "               : N:ファイル名, F:ファイル内容, 8:UTF8, L:各国語\n");//~va1mR~//~va1nR~
//  HELPMSG "               :Deafult is %cUF  if locale==UTF-8.\n",//~va00I~//~va1mR~
//          "               :省略値は locale==UTF-8のとき %cUF。\n",//~va00I~//~va1mR~
    HELPMSG "               :Deafult depends to LANG environment.\n",//~va1mR~//~va1nR~
            "               :省略値はLANG環境変数に依存。\n",       //~va1mR~//~va1nR~
                            CMDFLAG_PREFIX);                       //~va00I~
    HELPMSG "               :ex)  %cUF8 %cUNL.\n",                 //~va1nR~
            "               :ex)  %cUF8 %cUNL.\n",                 //~va1nR~
                            CMDFLAG_PREFIX,CMDFLAG_PREFIX);        //~va1nI~
    HELPMSG "               :You can specify this option for each Edit/Browse command.\n",//~va00I~//~vagEM~
            "               :各々のEdit/Browseコマンドでもオプション指定できます。\n",//~va00I~//~vagEM~
                            CMDFLAG_PREFIX);                       //~va00I~//~vagEM~
    HELPMSG "               :specify CPxx,FNxx(xx:U8/LC).\n",      //~vagEI~
            "               :その場合は CPxx,FNxx (xx:U8/LC)を指定\n");//~vagEI~
#endif                                                             //~va00I~
  if (Sdebughelp)                                                  //~vbzjI~
  {                                                                //~vbzjI~
    HELPMSG "  %cUUxxxx      :For Debug Test, xxxx:unicode breaks debugger.\n",//~vbzjI~
            "  %cUUxxxx      :デバッグ用; xxxx:デバッガーで停止するユニコード。\n",//~vbzjI~
                    CMDFLAG_PREFIX);                               //~vbzjI~
  }                                                                //~vbzjI~
#ifdef UNX                                                         //~v21cI~
    HELPMSG "  %cWxxxx       :Work dir name(alternative of export %s=xxxx)\n",//~v21cI~
            "  %cWxxxx       :ワークディレクトリ－名(環境変数設定 export %s=xxxx の代り)\n",//+v21cI~//~v21cR~
                            CMDFLAG_PREFIX,PGMID);                 //~v21cI~
    HELPMSG "               :Include char '%' to replace it by userid\n",//~v21cR~
            "               :ユーザーIDに置き換える位置に文字 '%' を含めてください\n");//~v21cR~
#else  //!UNX                                                      //~v21cI~
    HELPMSG "  %cWxxxx       :Work dir name(alternative of SET %s=xxxx)\n",//~v21cR~
            "  %cWxxxx       :ワークディレクトリ－名(環境変数設定 SET %s=xxxx の代り)\n",//~v21cR~
                            CMDFLAG_PREFIX,PGMID);                 //~v21cR~
#endif //!UNX                                                      //~v21cM~
//#if defined(W32) || defined(AIX)                                 //~v47sR~
//    HELPMSG "  %cWnn         :nn=screen width(column count)\n",  //~v47sR~
//            "  %cWnn         :nn=画面幅の桁数\n",                //~v47sR~
//            CMDFLAG_PREFIX);                                     //~v47sR~
//#endif                                                           //~v47sR~
    HELPMSG "  %cY:x and %cN:x:Toggle Set(%cY) and Reset(%cN) option\n",//~v21cR~
            "  %cY:x と %cN:x :トグルスイッチ 設定(%cY)と設定解除(%cN)\n",//~v21cR~
			CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX);//~v21cI~
    HELPMSG "               :(default is in parethesys)\n",        //~v11ER~
//          "               :(省略時の値は括弧内に表示)\n");       //~v11ER~
            "               :(省略時の値は括弧内に\x95\\示)\n");   //~v11ER~
    HELPMSG "      x=a (%cNa):ASCII only(%cYa) or Accept Ctrl char(%cNa)\n",//~v21cR~
            "      x=a (%cNa):制御文字を受付ける(%cNa)かASCII文字のみ(%cYa)か\n",//~v21cR~
			CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX);         //~v21cI~
    HELPMSG "      x=c (%cYc):add change-id-tag to modified line\n",//~v21cR~
            "      x=c (%cYc):修正行に変更タグを付与するか否か\n", //~v21cR~
			CMDFLAG_PREFIX);                                       //~v21cI~
//#ifdef DOS                                                       //~v095R~
#if defined(DOS) && !defined(DPMI)                                 //~v095I~
#else                                                           //~5430I~
    HELPMSG "      x=d (%cYd):dump when internal error detected\n", //~v11ER~//~v7a7R~
            "      x=d (%cYd):内部エラー検知の時ダンプをとる/とらない\n",//~v7a7R~
			CMDFLAG_PREFIX);                                       //~v7a7I~
#endif                                                          //~5430I~
  if (Sdebughelp)                                                  //~vbq7I~
  {                                                                //~vbq7I~
    HELPMSG "      x=e (%cYe):set exception handler.\n",           //~vbq7R~
            "      x=e (%cYe):例外ハンドラーを設定する\n",         //~vbq7R~
			CMDFLAG_PREFIX);                                       //~vbq7I~
  }                                                                //~vbq7I~
#ifdef LNX                                                         //~vad0I~
  if (Sdebughelp)                                                  //~vad0I~
  {                                                                //~vad0I~
#ifdef ARM                                                         //~vad0I~
    HELPMSG "      x=i (%cYi):use ICU as localconveter\n",         //~vad0I~
            "      x=i (%cYi):ロケールコード変換にICUを使用\n",    //~vad0I~
			CMDFLAG_PREFIX);                                       //~vad0I~
#else                                                              //~vad0I~
  #ifndef XXE                                                      //~vad0I~
    HELPMSG "      x=i (%cNi):use ICU as localconveter(test ARM on Linux)\n",//~vad0R~
            "      x=i (%cNi):ロケールコード変換にICUを使用(test ARM on Linux)\n",//~vad0R~
			CMDFLAG_PREFIX);                                       //~vad0I~
  #endif                                                           //~vad0I~
#endif                                                             //~vad0I~
  }                                                                //~vad0I~
#endif                                                             //~vad0I~
  if (Sdebughelp)                                                  //~vbmkI~
  {                                                                //~vbmkI~
    HELPMSG "      x=j (%cNj):Try CJK cell width for wide SBCS for UTF8 file\n",//~vbmkR~
            "      x=j (%cNj):UTF8ファイルの幅広SBCSにたいし CJK \x95\\示幅を試す\n",//~vbmkR~
            CMDFLAG_PREFIX);                                       //~vbmkM~
    HELPMSG "               :Use cell width of CJK env. even env. is not CJK console.\n",//~vbmkR~
            "               :文字幅をCJK コン\x83\\ール環境でないときもそれに合わせて\x95\\示\n");//~vbmkI~
    HELPMSG "               :Some char requires 2 cell to display on Console.\n",//~vbmkR~
            "               :コン\x83\\ール版ではある種の文字は2桁で\x95\\示しないと見えない\n");//~vbmkR~
  }                                                                //~vbmkI~
#ifdef DPMI                                                        //~v0flI~
    HELPMSG "      x=l (/Yl):Long filename use if avail or not\n", //~v11ER~
            "      x=l (/Yl):可\x94\\なら長いファイル名を使用する/しない\n");//~v11ER~
#endif                                                             //~v0flI~
//    HELPMSG "      x=L (%cNL):%cYL: Adjusts display width by %cYv for all languages.\n",//~vbzyR~//~vbzzR~
//            "      x=L (%cNL):%cYL: %cYv のとき全ての言語について\x95\\示幅の調整をする。\n",//~vbzyR~//~vbzzR~
//            CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX);         //~vbzyR~//~vbzzR~
//    HELPMSG "               :%cNL: fix to 1 cell for some not familiar languages.\n",//~vbzyR~//~vbzzR~
//            "               :%cNL: 馴染みの少ないいくつかの言語については１桁\x95\\示とする。\n",//~vbzyR~//~vbzzR~
//            CMDFLAG_PREFIX);                                       //~vbzyI~//~vbzzR~
#ifdef LNX                                                         //~v7a7I~
  #ifdef UTF8SUPPH                                                 //~va00I~
//#ifdef AAA                                                         //~vbt3I~//~vbtaR~
    HELPMSG "      x=m (-Ym):kbd input multibyte char translation option.\n",//~va00I~//~va0DR~
            "      x=m (-Ym):キーボード入力マルチバイト文字変換オプション\n");//~va00I~//~va0DR~
//#endif                                                             //~vbt3I~//~vbtaR~
#ifdef AAA                                                         //~va0DI~
    HELPMSG "           %cYm:force translation from UTF8 to locale codepage\n",//~va00I~
            "           %cYm:入力はUTF8とみなしロケールコードページに変換\n",//~va00I~
            CMDFLAG_PREFIX);                                       //~va00I~
    HELPMSG "           %cNm:assume kbd input is locale codepage.(no translation)\n",//~va00I~
            "           %cNm:入力はロケールコードページとみなす\n",//~va00I~
            CMDFLAG_PREFIX);                                       //~va00I~
    HELPMSG "           Default:according to LANG env-var,\n",     //~va00I~
            "           無指定:LANG 環境変数に従いロケールコード変換を\n");//~va00I~
    HELPMSG "           translate(env:UTF8) or do not translate(env:not UTF8)\n",//~va00I~//~va0DR~//~vafyR~
            "           する(env:UTF8の場合)かしない(env:UTF8でない)か決める。\n");//~va00I~
#endif                                                             //~va0DI~
//  HELPMSG "               :%cNm:Accept UTF8 code as-is base without trans.\n",//~va0DR~//~vbtaR~
//          "               :%cNm:UTF8入力を変換せず受け付ける\n", //~va0DR~//~vbtaR~
    HELPMSG "               :%cNm:Set UTF8 code to CPLC file when A+u ON.\n",//~vbtaM~
            "               :%cNm:A+u オンのときUTF8コードを無変換でセット\n",//~vbtaM~
            CMDFLAG_PREFIX);                                       //~va0DI~
  #else //UTF8SUPPH                                                //~va00I~
    HELPMSG "      x=m (%cYm):Translate UTF8 kbd input to multi-byte.\n",//~v7a7R~
            "      x=m (%cYm):UTF8キーボード入力をマルチバイト変換\n",//~v7a7R~
            CMDFLAG_PREFIX);                                       //~v7a7I~
  #endif                                                           //~va00I~
#endif                                                             //~v7a7I~
#ifdef W32                                                         //~v0jtI~
//#ifndef WXE                                                      //~v500I~//~vbt5R~
  #ifdef UTF8SUPPH                                                 //~va0DI~
//if (Sdebughelp)                                                  //~va0DI~//~vbtaR~
//{                                                                //~va0DI~//~vbtaR~
    HELPMSG "      x=m (/Ym):kbd input multibyte char translation option.\n",//~va0DR~
            "      x=m (/Ym):キーボード入力マルチバイト文字変換オプション\n");//~va0DR~
//  HELPMSG "               :%cNm:Accept UTF8 code by /Yw as-is base without trans.\n",//~va0DR~//~vbt5R~
//          "               :%cNm:/Yw による UTF8入力を無変換でコードをそのまま受け付ける\n",//~va0DR~//~vbt5R~
    HELPMSG "               :%cNm:Set UTF8 code to CPLC file when A+u ON.\n",//~vbt5I~
            "               :%cNm:A+u オンのときUTF8コードを無変換でセット\n",//~vbt5I~
            CMDFLAG_PREFIX);                                       //~va0DI~
//}                                                                //~va0DI~//~vbtaR~
  #endif                                                           //~va0DI~
//    HELPMSG "      x=n (/Nn):(WIN)NT mode kbd process(No DBCS proces under Win95/98)\n",//~v11ER~//~vbzuR~
//            "      x=n (/Nn):(WIN)NTモードキーボード処理(95/98での日本語入力スキップ)\n");//~v11ER~//~vbzuR~
#endif  //W32                                                      //~vbzLI~
if (Sdebughelp)                                                    //~vbzuI~
{                                                                  //~vbzuI~
//    HELPMSG "      x=n (/Nn):No trace while mapinit.\n",           //~vbzuI~//~vbzKR~
//            "      x=n (/Nn):mapinit中は UTRACE をスキップする\n");//~vbzuI~//~vbzKR~
    HELPMSG "      x=n (/Yn):No trace while mapinit.\n",           //~vbzKI~
            "      x=n (/Yn):mapinit中は UTRACE をスキップする\n");//~vbzKI~
}                                                                  //~vbzuI~
//#endif                                                           //~v500I~//~vbt5R~
//#endif                                                           //~vbzLR~
//#ifdef UNX                                                       //~v790R~
#ifdef AIX                                                         //~v790I~
#else                                                              //~v21cI~
//  HELPMSG "      x=r (%cNr):Use Right-Ctrl key as Execute key or Not\n",//~v793R~//~vaq3R~
//          "      x=r (%cNr):右Ctrlを実行キーとして使用する/しない\n",//~v11ER~//~vaq3R~
//          CMDFLAG_PREFIX);                                       //~vaq3R~
    HELPMSG "      x=r (%cNr):Use R-Ctrl as Execute key(Enter is for New Line).\n",//~vaq3R~
            "      x=r (%cNr):右Ctrlを実行キーとし Enter は改行キーとする\n",//~vaq3I~
            CMDFLAG_PREFIX);                                       //~vaq3I~
//  HELPMSG "      x=rr(%cNrr):Use Right-Ctrl key as NewLine key or Not\n",//~v793R~//~v7a7R~//~va1uR~
//          "      x=rr(%cNrr):右Ctrlを改行キーとして使用する/しない\n",//~v793R~//~v7a7R~//~va1uR~
//          CMDFLAG_PREFIX);                                       //~v7a7I~//~va1uR~
//  HELPMSG "      x=rr(%cNrr):Use Right-Ctrl key as NewLine key or Not,it requires also %cYr\n",//~vaq3R~
//          "      x=rr(%cNrr):右Ctrlを改行キーとして使用する/しない。%cYrも指定する。\n",//~vaq3R~
//          CMDFLAG_PREFIX,CMDFLAG_PREFIX);                        //~vaq3I~
    HELPMSG "      x=rr(%cNrr):By both %cYr and %cYrr, Enter key:Execute and R-Ctrl:New Line\n",//~vaq3R~
            "      x=rr(%cNrr):%cYr と %cYrr 両指定で Enter:実行キー, 右Ctrl:改行キー。\n",//~vaq3R~
            CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX);         //~vaq3R~
#endif                                                             //~v21cI~
//#ifdef W32                                                         //~v79zR~//~va00R~
//  if (Sdebughelp)                                                  //~v79zI~//~va00R~
//  {                                                                //~v79zI~//~va00R~
//    HELPMSG "      x=w (/Nw):KbdRead using unicode API for Japanese\n",//~v79zR~//~va00R~
//            "      x=w (/Nw):日本語キーボードをユニコード用APIで読む\n");//~v79zR~//~va00R~
//  }                                                                //~v79zI~//~va00R~
//#endif                                                             //~v79zI~//~va00R~
    HELPMSG "      x=t (%cNt):Tab display or not\n",               //~v21cR~
//          "      x=t (/Nt):タブ文字を表示する/しない\n");        //~v11ER~
            "      x=t (%cNt):タブ文字を\x95\\示する/しない\n",    //~v21cR~
			CMDFLAG_PREFIX);                                       //~v21cI~
//#ifdef LNX                                                         //~vau0I~//~vauER~
  if (Sdebughelp)                                                  //~vau0I~
  {                                                                //~vau0I~
    HELPMSG "      x=u (%cYu):For UTF8 TEST,display utf8 filename on dirlist by ddfmt.\n",//~vau0R~
    			0,                                                 //~vau0I~
			CMDFLAG_PREFIX);                                       //~vau0I~
  }                                                                //~vau0I~
//#endif                                                             //~vau0I~//~vauER~
#ifdef W32                                                         //~v7a3I~
#ifndef WXE                                                        //~v7a3I~
//    HELPMSG "      x=v (%cYv):(Windows Console version,Japanese Env) Adjust character cell width\n",//~vbz3R~//~vbzkR~
////          "      x=v (%cYv):(Windowsコンソール版,日本語環境) 文字幅が不明瞭な文字の場合\n",//~vbz3R~//~vbzjR~//~vbzkR~
//            "      x=v (%cYv):(Windowsコン\x83\\ール版,日本語環境) 文字幅が不明瞭な文字の場合\n",//~vbzjI~//~vbzkR~
//            CMDFLAG_PREFIX);                                       //~vbz3I~//~vbzkR~
//    HELPMSG "                 to the cursor width for the charcter of ambiguous width.\n",//~vbz3I~//~vbzkR~
////          "                 文字幅をカーソル幅に合わせる。\n");  //~vbz3R~//~vbzjR~//~vbzkR~
//            "                 文字幅をカー\x83\\ル幅に合わせる。\n");//~vbzjI~//~vbzkR~
//    HELPMSG "      x=v (%cYv):Adjust the width of Unicode char defined as ambiguous width.\n"//~vbznR~
//            "                Display by 2 cell for those if %cNv specified.\n",//~vbznR~
//            "      x=v (%cYv):\x95\\示幅が曖昧と定義されているユニコード文字の幅を調整する。\n"//~vbznR~
//            "                %cNvとするとそれらは全て２桁\x95\\示する。\n",//~vbznR~
//              CMDFLAG_PREFIX,CMDFLAG_PREFIX);                    //~vbznR~
//    HELPMSG "      x=v (%cYv):Adjust the width of Unicode char which width is said to be ambiguous.\n"//~vbzrR~
//            "                Use 2 cell for those if %cNv is specified.\n",//~vbznR~//~vbzrR~
//            "      x=v (%cYv):\x95\\示幅が曖昧と定義されているユニコード文字の幅を調整する。\n"//~vbzrR~
//            "                %cNvとするとそれらは全て２桁\x95\\示する。\n",//~vbznI~//~vbzrR~
//              CMDFLAG_PREFIX,CMDFLAG_PREFIX);                      //~vbznI~//~vbzrR~
//    HELPMSG "      x=v (%cYv):Adjust the display width of ambiguous type of Unicode.\n",//~vbzrR~//~vbzzR~
//            "      x=v (%cYv):\x95\\示幅が曖昧とされているユニコード文字の幅を調整する。\n",//~vbzrR~//~vbzzR~
//              CMDFLAG_PREFIX);                                     //~vbzrI~//~vbzzR~
//    HELPMSG "               :For WindowsTerminal, use 1 cell if /F parameter is missing.\n",//~vbzrR~//~vbzzR~
//            "               :但しWindowsTerminalの場合、フォントパラメータ(/F)がないと1桁\n");//~vbzrR~//~vbzzR~
//    HELPMSG "               :Use 2 cell for ambiguous Unicode if %cNv is specified.\n",//~vbzrR~//~vbzzR~
//            "               :%cNvとするとそれらは全て２桁\x95\\示する。\n",//~vbzrR~//~vbzzR~
//              CMDFLAG_PREFIX);                                     //~vbzrI~//~vbzzR~
  if (Sdebughelp)                                                  //~v7a3I~
  {                                                                //~v7a3I~
//  HELPMSG "      x=w (%cNw):For TEST,WidecharAPI for ConsoleOutput under Japanese env.\n",//~v7a3R~//~va0DR~
//          "      x=w (%cNw):日本語環境でもConsoleOutputでWidecharAPIを使用(テスト用)\n",//~v7a3I~//~va0DR~
//  HELPMSG "      x=w (%cNw):For UTF8 TEST,WidecharAPI for Console I/O under Japanese env.\n",//~va0DI~//~vbt2R~
//          "      x=w (%cNw):日本語環境でもConsole I/OでWidecharAPIを使用(UTF8 テスト用)\n",//~va0DI~//~vbt2R~
    HELPMSG "      x=w (%cYw):For UTF8 TEST,WidecharAPI for Console I/O under Japanese env.\n",//~vbt2I~
            "      x=w (%cYw):日本語環境でもConsole I/OでWidecharAPIを使用(UTF8 テスト用)\n",//~vbt2I~
			CMDFLAG_PREFIX);                                       //~v7a3I~
  }                                                                //~v7a3I~
#else                                                              //~vbz4I~
//    HELPMSG "      x=v (%cYv):(wxe) Adjust character cell width\n",//~vbz4R~//~vbz5R~//~vbzkR~//~vbznR~
//            "      x=v (%cYv):(wxe) 文字幅が不明瞭な文字の場合\n",//~vbz4R~//~vbz5R~//~vbzkR~//~vbznR~
//            CMDFLAG_PREFIX);                                       //~vbz4I~//~vbznR~
//    HELPMSG "                 to the cursor width for the charcter of ambiguous width.\n",//~vbz4I~//~vbznR~
////          "                 文字幅をカーソル幅に合わせる。\n");  //~vbz4I~//~vbzjR~//~vbznR~
//            "                 文字幅をカー\x83\\ル幅に合わせる。\n");//~vbzjI~//~vbznR~
//    HELPMSG "                 Yv takes some cost at aplication start.\n",//~vbzkR~//~vbznR~
//            "                 Yv とすると立ち上がりが少し遅れる。\n");//~vbzkR~//~vbznR~
//    HELPMSG "      x=v (%cYv):Adjust the width of Unicode char which width is said to be ambiguous.\n",//~vbznR~//~vbzrR~//~vbzzR~
//            "      x=v (%cYv):\x95\\示幅が曖昧と定義されているユニコード文字の幅を調整する。\n",//~vbznR~//~vbzzR~
//              CMDFLAG_PREFIX);                                     //~vbznI~//~vbzzR~
//    HELPMSG "                :some starting cost. Display by 2 cell for those if %cNv specified.\n",//~vbznR~//~vbzrR~//~vbzzR~
//            "                :%cNvとするとそれらは全て２桁\x95\\示し、立ち上がりが軽い。\n",//~vbznR~//~vbzrR~//~vbzzR~
//              CMDFLAG_PREFIX);                                     //~vbznI~//~vbzzR~
#endif                                                             //~v7a3I~
#else    //!W32                                                    //~vbz5I~
    #ifdef XXE                                                       //~vbz5I~//~vbzkR~//~vbzpR~
//        HELPMSG "      x=v (%cYv):Cell count for the Unicode char defined as ambiguous width.\n"//~vbzpR~//~vbzzR~
//                "                %cYv depends glyph width, %cNv always use 2 cells.\n",//~vbzpI~//~vbzzR~
//                "      x=v (%cYv):\x95\\示幅が曖昧と定義されているユニコード文字の描画桁数。\n"//~vbzpI~//~vbzzR~
//                "                %cYv はグリフのサイズに従い、%cNvとすると全て２桁\x95\\示する。\n",//~vbzpI~//~vbzzR~
//                  CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX);   //~vbzpI~//~vbzzR~
    #else                                                          //~vbzpI~
//    HELPMSG "      x=v (%cYv):Adjust character cell width\n",//~vbz5R~//~vbzkR~//~vbzpR~
//            "      x=v (%cYv):文字幅が不明瞭な文字の場合\n", //~vbz5R~//~vbzkR~//~vbzpR~
//            CMDFLAG_PREFIX);                                       //~vbz5I~//~vbzpR~
//    HELPMSG "                 to the cursor width for the charcter of ambiguous width.\n",//~vbz5I~//~vbzpR~
//            "                 文字幅をカー\x83\\ル幅に合わせる。\n");//~vbz5I~//~vbzpR~
//    HELPMSG "                 Yv takes some cost at aplication start.\n",//~vbzkR~//~vbzpR~
//            "                 Yv は立ち上がりが少し遅れる。\n");   //~vbzkI~//~vbzpR~
//        HELPMSG "      x=v (%cYv):Draw on 1 cell for the Unicode char which width is ambiguous,\n",//~vbzrR~//~vbzzR~
//                "      x=v (%cYv):\x95\\示幅が曖昧とされているユニコード文字を1桁で描画する。\n",//~vbzrI~//~vbzzR~
//                  CMDFLAG_PREFIX);                  //~vbzpI~      //~vbzrI~//~vbzzR~
//        HELPMSG "               :and additionaly adjust if fontName parameter(-F) is specified.\n",//~vbzrR~//~vbzzR~
//                "               :但しフォントパラメータ(-F)を指定すると、それに従い調整する。\n",//~vbzrI~//~vbzzR~
//                  CMDFLAG_PREFIX);                                 //~vbzrI~//~vbzzR~
//        HELPMSG "               :Use 2 cell for those if %cNv is specified.\n",//~vbzrR~//~vbzzR~
//                "               :%cNvとするとそれらは全て２桁\x95\\示する。\n",//~vbzrR~//~vbzzR~
//                  CMDFLAG_PREFIX);                                 //~vbzrI~//~vbzzR~
    #endif                                                           //~vbz5I~//~vbzkR~//~vbzpR~
#endif                                                             //~v7a3I~
//#ifdef LNX                                                         //~v79zI~//~v7a7R~
//    HELPMSG "      x=8 (%cN8):Read UTF8 kbd input byte by byte.\n",//~v79zI~//~v7a7R~
//            "      x=8 (%cN8):UTF8キーボード入力を1バイトごと読む\n",//~v79zI~//~v7a7R~
//            CMDFLAG_PREFIX);                                       //~v79zI~//~v7a7R~
//#endif                                                             //~v79zI~//~v7a7R~
  if (Sdebughelp)                                                  //~v71AI~
  {                                                                //~v71AI~
	HELPMSG "      x=9      :%cN9:Force english mode\n",           //~v71AI~
            "      x=9      :%cN9で英語モードを強制\n",            //~v71AI~
			CMDFLAG_PREFIX);                                       //~v71AI~
  }                                                                //~v71AI~
    HELPMSG "  %c/           :End of parameter(ignores string following this)\n",//~v21cR~//~vbzrR~
            "  %c/           :パラメータの終わり(これ以降は無視されます)\n",//~v21cR~
			CMDFLAG_PREFIX);                                       //~v21cI~
    HELPMSG "  Sample       : %s config.sys %cT8 %cYrt %cNc\n",    //~v21cR~
            "  入力例       : %s config.sys %cT8 %cYrt %cNc\n",    //~v21cR~
                PGMID,CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX);//~v21cR~
//  HELPMSG 0,(UCHAR*)1);  //for title msg scroll                  //~v19hI~//~vafkR~
    HELPMSG 0,(UCHAR*)(ULPTR)1);  //for title msg scroll           //~vafkI~
    titlemsg();                                                 //~4C24I~
    return;
}//help
