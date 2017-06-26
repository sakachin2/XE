||*CID:||+v129R~:  2017/03/29              update#=  556;             ||+v129R~
######################################################################
[English]    v1.29                                                    ||~v128R~||+v129R~

##This editor is fit for programmers working on both main-frame and PC.
  Its operation is based on mainframe SPF editor,                     ||~v126R~
  and like as other editor on PC convenient short-cut key operation is hybrid.||~v126I~
  Each version offer common operation on the different OS, DOS,OS/2,AIX,Windows,Linux.||~v126I~
                                                                      ||~v126I~
      .Automatic updated lines tagging optionally.                    ||~v126R~
      .Sort, Formatting, code conversion,...                          ||~v126R~
      .Fixed/Variable Length Record file(wit no CR/LF) support.       ||~128DR~
      .Direct(Without code translation) edit UTF8,EBCDIC file.        ||~v126I~
      .Binary editor(Vertical or Horizontal HEX line)                 ||~v126I~
      .Filer(Folder Listing,Delete,Rename,Copy,Launch,...)            ||~v126I~
      .Remote access                                                  ||~v126I~
         ftp,samba,rsh,ssh,fuse,TSO3270                               ||~128DR~
         Access to Linux/390 using fuse(Dokan package on Windows).    ||~v126I~
         Access to Windows from Linux using samba(smbclient).         ||~128DI~
      .64 bit(Linux/Windows version only)                                     ||~v126I~||~126HR~
      .Linux/390 version is tested on Hecules emulator.               ||~v126I~
         make on Linux/390 by "./configure && make" from src.tgz.     ||~128DR~

    LICENSE: use GNU GPL
                            By Mizumaki-machi (sakachin2@yahoo.co.jp)

                            http://hp.vector.co.jp/authors/VA010562
                            http://www.geocities.jp/sakachin2/index.htm

  (note). DOS version is limitted by 640kb.
            Pgm is too fat now,DOS version may not work by 640k memory
            limitation. Please keep old version.                      ||~124FR~
            DOS version withdrawn at v1.13.  Use GCC if available.
            DOS version is contained in GCC version.
          GCC version is DOS Extender version(no 640k limit).
            It is compiled by DJGPP/GCC v2 original downloaded from
            nifty FEXT forum. It is required DPMI server.             ||~124FR~
            Windows and OS/2 is one of DPMI server. So this works
            on the DOS box. QEMM etc. is one of DPMI server under DOS.||~124FR~
            CWSDPMI is for DOS prepared from Nifty FEXT LIB-13(original)
            #449 CSDPMI3B.ZIP,download and place it on PATH.
            (CWSDPMI is by C.W.Sandamann)
          WIN version are GUI and Win32 CONSOLE application version.  ||~128DR~
            Console version works on command prompt and mouse is not supported.||~126HR~
            Set CommandPrompt to use TrueType Font.                   ||~128DR~
            WTL/ATL version(MFC is not used) is compiled on vs2010Express,||~126HR~
            32bit and 64bit version is prepared.                      ||~126HR~
          There are 2 executable for Linux,GUI version(gxe) and
            TerminalEmulator version(xe), and support floppy disk.
            Linux version is tested on RedHat v9/FedoraCore4 only.
          AIX version works through TeraTerm(*), telnet from linux
            and on aixterm and dtterm.
            Someone use puTTY(terminal emulator on Windows),I heard.
            Initial setup required,see xeaixe.doc.
            AIX version is up to v1.18.

            (*)TeraTerm is freeware by T.Teranishi.                   ||~124FR~

     Test is done mainly for Windows version and AIX version.
     Other version is just cheked to work except the function native to
     the version.

##Following files are archived in to each version.
      See also xelnxj.txt/xelnxe.txt for Linux version(xelnx___.tgz), ||~124FR~
      and xewxej.txt/xewxee.txt for gxe mouse operation.              ||~124FR~
      See xeaixj.doc/xeaixe.doc for AIX version(xeaix___.tgz).

        gnugpl.txt   Copy of GNU GPL.                                 ||~124FR~
        xereadmj.txt README for Japanese.                             ||~124FR~
        xereadme.txt this file.                                       ||~124FR~
        xej.txt      Japanese manual.                                 ||~124FR~
        xee.txt      english manual.                                  ||~124FR~
 v1.29  xe.exe       executable binary file                           ||~127SR~||~v128R~||+v129R~
 v1.29  wxe.exe      Windows GUI version.                             ||~127SR~||~v128R~||+v129R~
 v1.29  gxe.exe      Linux Xwindows version.                          ||~127SR~||~v128R~||+v129R~
        xehelp\      Help file directory for Windows/Linux version.
                     Put o workdir or specify the place by env-var "xehelp"
                     or by /hd command line parameter.                ||~124FR~
                     See xelnxe.txt for additional place for linux version.||~124FR~
        xewxej.txt   doc for Windows GUI version.(Japanese)           ||~124FR~
        xewxee.txt   doc for Windows GUI version.                     ||~124FR~
        xehosts      sample hosts file for remote file access.
        xe3270.cfg   (Win/Linux)TurnkeyMVS access config file.
        xesynw.cfg   (Win/Linux)SyntaxHighlight config file.          ||~124GR~
        /xesynl.cfg                                                   ||~124GR~
        cobol.lang   (Win/Linux)SyntaxHighlight,cobol language definition.||~124HR~
        gnu-source-highlight-mingw.tgz                                ||~124KI~
                     (Win)GNU source-highlight v2.9 compiled on MinGW.||~124KI~
                     This allows ssource-highlight execution without cygwin installation.||~124KI~
        xeshm        (Win/Linux)resident process version from gnu-source-highlight v2.9.||~124RI~
        xe.bat       sample batch file to select DOS,GCC or WIN
                     version xe.exe checking OS version.
 v1.1   XE4S001Z's   Followings are Win/Linux version only.           ||~124NR~
                     XE4S001Z is optionally used to display SPF information||~124NR~,||~124NR~
                     on the dir-list when access Turnkey-MVS PDS.
                     To install,assemble .asm file or submit .jcl to install
                     LoadModule from .aws file.
                     See also xee.txt (0)-(D)-Turnkey MVS support.    ||~124FR~
        XE4S001Z.asm HOST ASSEMBLER source
        XE4S001Z.aws AWS file created from LoadModule by awsutil.
        XE4S001Z.jcl submit jcl to install LoadModule XE4S001Z from .aws file.

 v9.34  xprint.exe   text file print program                          ||~128CR~
        xprint.sh    wrapper shell to use xprint on Linux.            ||~7A25R~
        gxp          (Linux)xprint using GTKPrint                   ||~7A25I~||~127DR~
        xpj.txt      xprint Japanese document file                    ||~124FR~
        xpe.txt      xprint english document file                     ||~124FR~

 v1.3   xeacb.exe    For Windows/Linux Only,Syntax Highlight Browser. ||~124GI~,||~124GR~||~v125R~||~126JR~||~v128R~
 v1.1   xads.exe     For Windows Only,Access to NTFS ADS(Alternative Data Stream).||~v128R~
 v1.5   xbc.exe      Basic calculator.
 v1.1   xci.exe      C/C++/Java text file indentation                 ||~126JR~||~127CR~
 v1.19  xcv.exe      Code conversion.                                 ||+124FR~,||~124QR~||~125FR~||~125GR~||~127QR~
                     EUC,SJIS(Japanese:Shift JIS),Unicode,UTF-8,EBCDIC,Any-Codepage.||~124QR~
 v1.2   xcvsjisc.exe Convert SJIS in xe's source file to Octal-notation.||~124FR~
 v2.28  xdc.exe      directory compare tool                           ||~127SR~||~v128R~
 v2.1   xdd.exe      directory delete tool                            ||~128FR~||~v128R~
 v1.12  xdig.exe     directory walk utility                           ||~124FR~||~127AR~||~127QR~||+v129R~
                     tool apply command to all sub-directory/files.
        xdig.txt     doc for xdig                                     ||~124FR~
 v1.11  xds.exe      Directory size display tool                      ||~124RR~||~126BR~||~127AR~||+v129R~
 v1.25  xfc.exe      File compare tool                                ||~127SR~||~v128R~
 v1.7   xff.exe      file search by size/timestamp/name.               ||~7B08R~||~127ER~
 v1.19  xfg.exe      Binary file string search & Recursive grep.      ||~127AR~||~128FR~||~v128R~
 v1.4   xfmt.exe     FileLineFormatter. "TC FMT" for huge file.       ||~124QR~||~v125R~
 v2.8   xfs.exe      Split large file,it enable backup large file to  ||~124RR~||~127QR~||~v128R~
                     diskets.
 v1.3   xkp.exe      (Windows) display process-id and kill process.   ||~127QR~||~v128R~
 v1.5   xlow.exe     Rename UpperCase file name to LowerCase.         ||~127AR~
 v1.2   xmj.exe      2 file matching.                                 ||~v125R~
 v1.2   xpe.exe      Display comment of errno(libc error code).
 v1.6   xts.exe      Set/Display File timestamp                       ||~124KR~||~126JR~
 v1.08  xver.exe     Set ERRORLEVEL from OS version

How to start.

  (See xelnxe.txt for Linux version,xeaixe.doc for AIX version).      ||~124FR~

  . Melt zip file on a work directory(unzip xe___)                    ||~8123R~
    Default word dir is c:\xe_wd.
  . Move .exe files to any directory specified on the PATH environment
    variable,or set PATH to the work directory.
  . Set name of the work directory to environment variable.
      Set as following in config.sys(OS/2)/autoexec.bat(DOS or Windows)
      or command file(.cmd/.bat) you created to start xe.
      ex.  xe=d:\xe010
  . Enter xe [file-name] to start this editor.
      "xe /?" help you about command line parameter.
  . XE___.DMP is written to work directory when internal err detected
    (DOS version) or when xe is ABENDed(OS/2,WIN,DJGPP version).
    I'll be very happy if you could send the file by mail when dumped.

## How to operate,How to customize parameter file.
  . See xee.txt                                                       ||~124FR~

## Change History.
  .v010:(95/06/04)
        initial release                                               
  .v020:(95/07/09)                                                    
      .fixed CID support
      .file name input panel support(MENU 1,2)                        
                                                                      
  .v021:(95/07/10)                                                    
      .Bug correction.
                                                                      
  .v050:(95/10/08)                                                    
      .Directory list support                                         
      .New DOS command(ATTrib,MKDir,RMDir,DELete,REName,XCOpy)

  .v060:(96/02/11)
      .Additional DOS command(XMOve,XDD,XPRINT)                       ||~124FR~
      .Native DOS,OS/2 command is available.

  .v070:(96/04/15)
      .Extended function for Native DOS,OS/2 command process.
        (">" command prefix,option 6 on menu screen)
      .Support valiable length of line-no field.
                                                                      
  .v080:(96/09/07)                                                    
      .Support MENU Option 0(set color)..                                         
      .Dir list line command copy function.                          
                                                                      
  .v090:(96/12/16)
      .XE(Windows 95 version) is added.
      .File partial EDIT/BROWSE function.

  .v091:(97/01/04)
      .Bug correction.

  .v092:(97/06/01)
      .DPMI(DOS PROTECT MODE INTERFACE) version added.                ||~124FR~

  .v094:(97/10/05)
      .Binary file support.                                           ||~124FR~
      .UNIX text file support.
      .Support  margin.
      .Support Line-Numbered file.
      .New line cmd "/" and "+".

  .v097:(97/12/27)
      .Long File Name support.(W95/GCC version)

  .v098:(98/04/28)
      .WindowsNT support(w95 version)
      .Allow range specification to "O"(on),"P"(paste) command("OO","PP").
      .Search line range support for Find/Change command.
      .New EXClude/IX(case insensitive EXClude) cmd                   ||~124FR~
      .New DROp cmd.

  .v099:(98/04/29)
      .Bug correction.

  .v100:(98/07/21)
      .BUGS -(W95 version only) Start fail on V4.00.950B.
        Now tested under v4.00.1111, and also Windows98 4.10.1998.
      .Additional line-command function.
       -Bundled lines function for each line command.
      .New option on Menu screen.
       -Command assignment to Fn key,Key assignment changed/display.
      .Other miscellaneous.
       -(WIN version only)Add bypass DBCS input process option on
        exe parameter(/Yn).

  .v101:(98/12/01)
      .Additional Function.
       -SUBmit command(Execute script file).Line command "="(compare).||~124FR~
  .v102:(99/05/01)                                                    
      .Additional Function.
       -HEX digit input mode support(toggle by HEX cmd or Alt+F12)    
       -New option to Edit/Browse/Select command.                     
        /Mb[nn][s]:b:binary mode.nn:line width.s:save.
        /Mn       :mode of 80 column line-numbered file with no CID.  
        New cmd BB/EB/SB for /Mb and BN/EN/SN for /Mn.
        Dir-list line cmd "1"(Browse Binary) and "2"(Edit Binary).
       -SORT command.
       -F6 key on dir-list. Toggle file size display by byte and lineno.||~124FR~

  .v103:(99/09/01)
       -Cols command.Column-gauge is displayed. Any gauge fmt can be set.||~124FR~
       -Option for binary file.
        Edit/Browse/Select command. /O :file input range by Hex digit offs||~124FR~
                                    /Mo,/Ml:Line no is hex offset or no.||~124FR~
        Num command. NUM XON|XOFF[,S] :line number type.S:save.       ||~124FR~
        Locate command. LOC [O|L]nn[,C] O:Hex offset,L:line number digit.||~124FR~
                        C:location on current status.                 ||~124FR~
       -"EXClude ALL" hides all lines.
       -To print currently displayed file enter "XPRint *".

  .v104:(99/11/27)
      . *\ support to also Edit screen cmd(Edit,Save,Repl,Copy,...).

  .v105:(00/02/26)
      .For Edit/Browse/Select with wildcard filename specification,
       display the file if only one filename is correspond to it.

  .v106:(2000/05/08)
       -Sort cmd.
        Duplicated-key check and Key-break check option is added.
       -Refresh cmd to refresh directory list.
       -Basic calculation command BC.
       -Table calculation command TC.

  .v107:(2000/12/01)
     1.Additional function.
       -CID(ChangeID:updated line tag)
        .New option on top CID line,option to maintenance update-ctr
         on top CID line and option to clear TAB at save file.
         Update counter is automaticaly 1 up at save.
       -Filename history list.
     2.Linux Console Version.
     3.AIX TeraTerm Version.
       -It works on AIX through TeraTerm(*).
        (*)TeraTerm is a freeware terminal emulator by T.Teranisi.
           I tested with Ter Term Pro version 2.3.
  .v108:(2001/10/08)
       -New line cmd "[" and "]". shift reducing intermediate space.
       -New function key, "Alt+." and "Alt+,".
        .Search the pair of the parenthesis (,),[,],{,},<,>,/* or */.
       -XBC(Basic Calc) cmd.
        .Double word calc support.(Decimal is up to 19 digit).
        .Timestamp conversion. (Mainframe HOST TOD is also supported).
       -eXclude cmd.
        .Exclude repeated lines by "x *=[n] all".
       -DROp cmd.
        .Rep option replace excluded lines by a comment line
         "!!  nn line excluded -----".
       -COBOL support.
        .Left most column displayed and indentation pos when line
         insert is col 7.
        .Col 73-80 is optionally CID column.                          ||~124NR~

  .v109:(2001/10/08)
      .Additional function.
       -Binary Editor.
        .BH(browse)/EH(edit) command display char and hex digit.
       -New line-cmd on directory list.
        .h(Hex), i(SPFCOB-with col 1-6 seqno),j(SPFCOB w/o seqno),
         k(COB w/o seqno), L(COB with seqno), n(SPF file)
        .Browse or Edit is determined by case of command char.
         Lower case is of directory list,Uppercase is opposite of     ||~124FR~
         dir-list.
       -Find,eXclude cmd.
        .&:search line containing 2 word. ex). word1 & word2.
        .-an or -bn:display and exclude n lines after or before
         the line containing search word.
        .-c:keep screen to display the found word to the rightmost.
        .-d[<|>]n:distance of 2 word of & search. n:line count.
         ex) -d>n:distance is over than n lines.
         -d<n:distance is lower than n lines. -dn:word2 is on the next
         n'th line. without -d option or -d0,& search 2nd word only   ||~124FR~
         on the same line as 1st word found.
       -Macro pair search.
        .Search same nest level corresponding macro of #if/#ifdef/
         #ifndef/#else/#endif/#elif.
        .Use "Alt+." or "Alt+," when csr is on the char of "#".
       -New SPLit command.
  .v110:(2002/01/14)
      .Linux version BUG corection.

  .v111:(2002/05/19)
      .Additional function.
       -"OPT EOL eol-char [ON|OFF]" cmd.
       -"JOIn {X|NX} [all] [.lab1 .lab2]" cmd.
        Excluded lines(X) or not excluded lines(NX) are joined to     ||~124FR~
        a line.
       -Alt+F12. repeat previous cmd.
       -(WIN/UNX)Screen height parm /Hnn.                             ||~124FR~
        Windows200 cmd prompt screen has BufferSize parameter.
        That is also screen height of xe and PgDn scroll the screen
        by that value. To ajust to the physical screen height,        ||~124FR~
        use this parameter then scroll is done by this parameter.
        If you set BufferSize=screen size,/Hnn is not needed.
        Same thing is also for TeraTerm(AIX) version.
       -Find/eXclude cmd.
        Accept minus value for -ann and -bnn option.
        Minus mean previous line for -a, following line for -b.
        When minus is used,both -a and -b is required and sum is to be
        plus value.
        For & search, base of -b is 1st word line and base of -a is
        2nd word line.
        Function specifying matching at end-of-line is added.         ||~124FR~
        For ex,"f word\n" is stop at word on end-of-line.
        Enclose by quotation if you search \n as string.
       -(UNX)Floppy disk support.
       -Dir-list line cmd "o"(Open).
       -/M{P|U|M} (EndOfLIne code change) parm to CREate,REPlace,APPend
        and SAVe. P:0d0a, U:0a, M:0d.
       -String Input Shortcut key.                                    ||~124FR~
      .Spec change.
       -COBK(col1-6 is not COBOL line seqno) file.
        Col 1-6 is now not required as space,and line length is not be
        80 if "N" option(SPF file of line length=80) is not specified.
        Default CID position is col 73.
        To renum or clear the col1-6 use /K option.
       -File is automaticaly changed EOL id and saved even if no update
        is done if the file is open as to change EOL id.

  .v112:(2003/01/19)
     1.BUGs
     2.Additional function.
       -(WIN)WXE is a new member.
        XE of windows application(not console application).
        see xewxe.doc for mouse operation.
       -FINd/EXClude cmd.
         -*L option.
          To search matched(unmatched if combined with !) line
          of the result by line cmd "=" or result of TC cmd "=="
          operation.
         -*=[n](search continued same n line) option is supported
          not only for "x all" but also for FINd,CHAnge cmd.
          "x *=" exclude from 2nd line of block of same lines,
          to exclude all same line,specify -b0 option.
       -TC cmd.
        support "=="(compare) operation.
        case sensitive string compare if data type is not specified.
        unmatch lines are marked on the delm-column of lineno field,  ||~124FR~
        these lines area searched by "f *L" cmd.
       -CV cmd.
        JSI<-->SJIS,JIS<-->EUC and Unicode conversion(SJISM<-->UCS2<-->UTF8)
        is now supported.
       -REN(or NUM RENUM) cmd.
        added function to set line number on any position of text area.
       -(WIN)"DOS CMD" or ">CMD" cmd is added.
        this create new command prompt window.
        Under Windows2000,buffsize is specified as following.
        "DOS CMD [row [col]]"
     3.Spec change.
       -DBCS determination.
        DOS/WIN/OS2:all SJIS 1st byte, LNX:JISX208, AIX:MS932(Ja_JP).
     4.Miscellaneous.
       -free space display for the disk size over 4GB.

  .v113:(2003/09/06)

     1.BUGs
     2.Added function
       -2 word &(and) search support on also dir list.                ||~124FR~
       -% edit dir list line command.
         execute cmd string entered on filename-input-column.
         Filename of the line is editted replacing "%" in the cmd string.
         (appended when % is missing)
       -CV cmd.
        .label option support to specify conversion line range.
        .NX option limit the line to be converted to not excluded line.
        .EBCDIC<-->ASCII conversion(except DOSversion)
        .Hankaku(SBCS)katakana<-->English lower case letter conversion(except DOSversion)
        .HexNotation string-->Char conversion(except DOSversion)
       -ROTate cmd.
       -SPAwn cmd.
        .Execute cmd asyncronously.                                   ||~124FR~
        .Use to start windows GUI pgm such as explorer etc.
        .SPAwn cmd-name [args]
       -SUBmit cmd.
         .support ">"(redirection). Both stdout and stderr is redirected to.
       -TC cmd.
        .accept long column up to 27(previously 16).                  ||~124FR~
        .Data type conversion function. ex) "tc 1-8/x" convert to Hex notation.||~124FR~
        .support double word calc.                                    ||~124FR~
        .option to treat not numeric data as a field.                 ||~124FR~
        .Any field seperator is specified to FMT.  D[x] x:seperator.
         Space is the sepertor when no D option, "D" means D','.      ||~124FR~
        .Error reject for the file containing split line.             ||~124FR~
       -XBC cmd.
         R option remains result string on the cmd input line for
         the convineance of continued calc input.
       -UNDO cmd
         "UND free" free saved data to get free memory for the case
         memory shortage by large file.
       -(LNXversion)
        .X-Window
          -For Slackware3,TurboLinux-6,RedHat-8.0,RedHat-9,
           sample file to execute xe on xterm,kterm and gnome-terminal
           is prepared.
          -Keymap file option change mapping of EscString to Key.     ||~124FR~
          -Option to treat 0x7f.                                      ||~124FR~
            --7{B|D|C]     B:BackSpace, D:Delete, C:as char 0x7f
          -Both metabit option=ON(0x80|char) and OFF(0x1b+char) support.
          -Detect DBCS of Japanese EUC code.
          -Force cursor type of Insert mode to reverse,blink is ignored.
           xterm/kterm      Rep:fg=black,Ins:bg=black,fg=gray.
           But,there is no difference on gnome-terminal.
       -(AIXversion)
        .support telnet from Linux.
          -Sample file is prepared for the case xe is executed on
           the telnet screen from Linux.
          -option to treat of 0x7f.                                   ||~124FR~
            --7{B|D|C]     B:BackSpace, D:Delete, C:as char 0x7f
            BackSpace of AIX is 0x08.
            When telnet from Linux where 0x7f is defined as Backspace,
            use --7B. But,in that case,telnet shell itself is controlled
            by 0x7f=Backspace. So it is better to set Linux BackSpace=0x08.
            RedHat9 gnome-terminal support these setting change.      ||~124FR~
          -Use LANG=en_US because AIX DBCS is SJIS and Linux is EUC.
        .X-Window.
          -Keymap file option is supported to map EscString to a key.
          -Force Insert mode cursor type to reverse option.
          ---x option deleteed,xe automaticaly determine X or telnet case.||~124FR~
     3.Function Change.
       -On Linux or AIX,Alt+Fn is usualy intercepted by OS.
        So Ctrl+Fn is also added for Cut&Paste operation short cut key.
        (Ins,Del,F7,F8,F9).
        You should modify or re-create xe.ini to get effect.
        To re-create,start xe by "xe -i" and use ini cmd.
       -File name extention ".java" is added to the CID group of ".c".
        CID is added by // comment format.
        You should modify or re-create xe.ini to get effect.
       -(WXEversion)
        .Allows continuous paste.
        .Scroll start when edge of screen is pushed 3 times of
         scroll interval time.
     4.tool.
       -xcv    v1.3
        .EBCDIC<-->ASCII conversion (-e2a).
        .Hankaku-katakana<-->English-lowercase-letter.
  .v114:(2003/09/15)
     . binary compiled by RedHat v9 is packaged.
       (xe compiled by TurboLinux v9 will ABEND at gnome-terminal on
        RedHat v9 when Kanji input.)
  .v115:(2004/03/02)
     1.BUGs
     2.Additional function.
       -FTP support(remote file access).
        .format "remoteid:filename" is for remote access.
         remoteid:register to xehosts on work-dir(over 2 byte string).||~124FR~
         xehosts line sample.  a1 192.168.2.15 user001 pswdpswd
         password is encripted if it is edit and saved by xe.
         File date is exchanged by GMT,but in Japan AIX is set to
         GMT=JST. So TZ=0000 should be specified in the hosts file line.
        .undo dir-list line cmd is not supported yet.
        .Windows is not supported as ftp server.
         Linux and AIX is tested as ftp server.
        .SUBmit cmd is executed on local.
        .command line parameter for ftp.                              ||~124FR~
            /Fx[t][:hosts]  :x=0:FTP is not used, x=1:FTP avail(without log)
                             x=w:output ftplog, x=a:ftplog by append mode.
                            :t:debug option not to delete temp file for ftp get.
                            :hosts:hosts filename for xe.
            Default is /F1:xehosts(xehosts on work directory)
       -(WIN) AT new command.
         AT/& [-i] interval [repeat-count];command-1;command-2,...;command-n||~124FR~
         Repeat command-1 -- command-n repeat-count times by interval seconds.||~124FR~
         Without repeat-count,loops infinitly.
         -i:ignore command error and continue to following command.
         Pressing Esc twice interrupt repeat.
       -(WIN) Sleep new command.
         SLEep interval
         Block input except Esc key while interval seconds.
         Pressing Esc twice interrupt sleep.
       -EXE cmd added.
        .execute edit command in the file.
        .this is expansion of shortcut key function which has limit of
         total command length is up to 240.
        .format: EXE [filename | *] [parm-1,...]
         *:execute command in the currently displayed file.           ||~124FR~
         for example,if SWAp is first line,following cmd is applyed to file
         on another split screen.
         parm-n replace %n in the file.
         AT and Sleep command is not avail in this file.
       -T:tail line specification on EDIt/BROwse cmd.
        ex) "e filename 100t-50t.
       -TC cmd.
        ."~" new operation to count existing record.
         use in the case all log record has start and end time
         and you want to count how many record is exist at each start time.
         ex) "TC 1-8~=10-17" "TC 20-23=T1-6~T8-13"
        .support descending and not equal over ascending for summary
         with break-key specification.
         format: fld+/key[>|!|<][/grade]
        .constant operand is supported for 2nd operand only.
         ex) tc 1-10/=1440
        .record count by break key.
         ex) tc 1+/1-16! (only case constant is used on 1st operand)
       -Find/Change cmd.
        .allk option. same as "all" but found word on excluded line
         is leaved in excluded status.
       -Find cmd.
        ."-j" option. join lines in -a and -b or -d for &(and search) range.
        .search word *\n to positioning End-Of-Line.
         "*"\n is for search "*" in the EOL position.
        .eol option to search word in the EOL.
         f "a b"\n is format err,use f "a-b" eol.
        .maxeol option to search word on the EOL of the longest lines.||~124FR~
       -Opt cmd.
        .Beep [on|off]  :Beep when err.
        .RCTL [on|off]  :use Right-Ctrl key as execute function.
        .CCFUNC [on|off]:to use Ctrl+Char key as function key.
                         use in the environment Shift+ExtendedKey is
                         not effective like as Linux.
                         C_t=S_TAB,C_b=S_BS,C_x=S_ENTER,C_a=S_INS,
                         C_d=S_DEL,C_e=S_END,C_p=S_PGUP,C_n=S_PGDN,
                         C_u=S_UP,C_f=S_DOWN,C_l=S_LEFT,C_r=S_RIGHT
        .FREECSR [on|off]:scroll or wrap around when cursor reached to
                          edge of the screen.
                          Always wrap when cursor is on lineno column.
       -CV cmd.
        .\u  :use with u2s. convert \uxxxx unicode format.
        .-Hpre[XXpost]:use with x2c. convert between prefix and postfix.
        .mult:use with x2c. continue conv even if HEX digit err detected.
        .max :use with x2c. put result on the pos of right of longest line.
        .rep :use with x2c. put result on the place of converted.
       -CREate,REPlace,APPend cmd.
        [-x|-nx] [all|.lab1 .lab2] : process excluded/not excluded lines only.
       -SAVe cmd.
        [-x|-nx] option like as CREate cmd.
       -JOIn cmd.
        n-b-s option:repeat b times of n lines concatination then skip s lines.
       -Alt+w function key copies word to clipboard.
       -Alt+Left(Up),Alt+Right(Down) edit/browse the file/dir on the path
        of currently displayed file/dir.                              ||~124FR~
        DPU and DPD command is corresponding and by mouse doubleclick
        left and right "===>" on command input line(2nd line of screen).
       -S+right,S+Left is supported also on dir-list screen.
       -Filename specification panel.                                 ||~124FR~
        .DriveID is listed and selectable.
        .Filename list is supported paging.(max 200 entry)
       -(WIN)Start application associated with filename extension.
        (Directory is associated with Explorer).
        ."!" dirlist-list/filename-history-list line cmd.
        .ASSociate new command. ex) ASS abcd.xls
        .(WXE)mouse support.
         On dirlist or filename history list panel,popup menu by
         R-button down now contains OpenWith entry.                   ||~124FR~
         Or,doubleclick on the left edge of screen,
         col.1-5 for dirlist,col.1-3 for filename history list screen.
       -(WXE)
        .wxp cmd. print by wxe function not by xprint tool.
        .RightCtrl key is optionally used as execute key.             ||~124NR~
        .Help menu added.
       -(LNX)
        .mouse support.
     3.Function changed.
       -Find,eXclude cmd.
        .search column range spcification is for both word of & search.
        .cursor is moved on the next line when -a,-b option is used.
       -(AIX)vt100 is default terminal type because env var TERM may
        change to xterm by nested telnet.
       -(WIN)Screen line count is set by screen height of DOS prompt  ||~124FR~
        not by buff size.
       -(WXE)external cmd is processed by new hidden cmd server process
        to avoid console screen is opened each time.
  .v116:(2004/12/21)
     1.BUGs
     2.Additional function.
       -Environment variable.
        .Set environment variable for external(OS native etc.) command.||~124FR~
         This is effective for MSDOS child window.
       -CV cmd.
        .DBCS support for SJIS<-->IBM-EBCDIC conversion.
       -EXE cmd.
        .ignore error of each cmd in the cmd file and continue to process.
       -FINd cmd.
        .-je option for & search.
         if 1st word found and 2nd word is not found,
         joins from 1st word line to end-of-file line.
        .scroll option.
         scroll page to display found word on the specified place.
       -RSH new cmd.
       -SORt cmd.
        .support sort by timestamp/filesize on dirlist.
       -TC cmd.
        .compare support for 3 operand format.
         result is 1(opd1>opd2),0(opd1==opd2),-1(opd1<opd2).
        .add output precision option [V[n][R]].
        .not replace but insert result.
           opd3=opd1 operation opd2 [INS]
        .option to output summary(subtotal,total) line to file.
        .support copy operation.
           opd3=opd2 [INS] [RJust]
             ex).  tc 1-8="total=" ins;  tc 20-30=""; tc z1-8=x10-18
        .countEQ option for "~"(count ACTIVE line)
         1 up for the line starttime==endtime.
         ex). tc 1-2=10-20~30-40 countEQ
        .quotation consideration for FMT operation.
        ."p"(alignment by decimal point) option for FMT operation.
       -XCOpy,XMOve cmd.
(not OS/2).-d :copy only the source file newer than target.
          .-t :text mode for FTP download/upload case.
               LF<-->CRLF conversion is done.
       -remote file access.
        .support print local by XPRint cmd, "p" dirlist line cmd.
        .% dirlist line cmd on remote dirlist is done by rsh.
       -"n" edit line cmd support.
        non-space char on copy/move source line is pasted on target line.
       -"#" dirlist line cmd support.
        .execute the file by SUBmit(local file) or RSH(remote file) cmd.
     3.Function changed.
       -dirlist is expanded according screen width.
       -expand max line width from 999 to 9,999.
       -dirlist line cmd.
        For safety,following dirlist line cmd on path entry(from root
        to current dir) is protected.
          delete(d,/,z,0),Move(m),Rename(r),change path(:).
       -XCOpy cmd,Copy DirList line cmd.
        ./C option support
            /C: When source is dir or wildcard and the dir is not
                exist in the target dir, create dir then copy member.
         Append is done to each member of target dir if target is dir.||~124FR~
         In the case target is not exist or target is file,all source
         is appended to the target file.
     4.Tools.
       -xcv     v1.5
        .display EBCDIC conversion table contents by specifying "print"
         as output-file-name.
       -xdc     v2.7
        ./Ppath parameter:subdir specification in the intermediate file.
         specify two /P parameter when both dir is by intermediate file.
       -xff     v1.2
        .accept value of 99 for mm or ss of hhmmss timestamp parameter
         to search equal match hour or hour+minutes.
       -xfs     v1.9
        .multiline record consideration.
          -S:record identifier.
             split by the start-line/end-line record identifier.
          -Yr option means size parameter is record count.

  .v117:(2005/04/15)
     1.BUGs
     2.Additional function.
       -File on another screen of split.
        ."^*" means the file on another screen of split.
         "^*\" means path of the file or dir itself and may be used
         like as "e ^*\file2".
       -3 line HEX display mode.
        .1st line after char display line display only 1st digit of hex
         digit notation and 2nd line display 2nd digit only.
        .use /Mx option of Edit/Browse cmd,or use HEX cmd after opened.
        .HEX [ON|OFF]. toggle if ON/OFF operand missing.              ||~124FR~
         Ctrl+F10 is assigned to toggle HEX display mode.
       -HELp cmd.
        .(W32)kick HelpViewer. wxe.hlp should be on PATH dir.
       -Find cmd.
        .-Llcmd option.
         set line cmd on the line-no field of the found line.
         ex) "f StartLineID -Lcc;f EndLineID -Lcc;rep partialcopyfile"
             create partialcopyfile from the line contains "StartLineID"
             to the line contains "EndLineID".
         Cursor move operation is omitted by this option and may be used
         in exe cmd file.
        .-m[n] option.
         m:not reset previous found word reverse display.             ||~124FR~
           it is effective for next r-find(PF5)
         n:do that from next r-find(PF5).
        .matching function.
         matching of 2 file on the split screen and result is seen by ||~124FR~
         reverse displayed key position. The line of 2nd file which   ||~124FR~
         no corresponding key is found on 1st file is displayed as err
         (lineno column is reversed).
         *=Mn, n:key column of the other screen file.
         ex) f *=M6 10 18.
             col.10-18 is key of the file on the current screen,
             col 6-14 is key of the file on the other screen.
       -TC cmd.
        .o FMT field alignment option is to specify the following field
         is not to be formatted. R(Right justification) or (Left
         justification) option is effective to all the following field||~124FR~
         if it is not atached to a field number,but its effect is end
         with "o" option specification.(up to first field number
         formatting is not yet done)
        .option set 1/0 for result of "=="(compare) operation.
         TF:set 1 if equal, FT:set 1 if unequal. default is set 1/0/-1.
       -remote file access.
        .support "u"(undo) DirList line cmd for also remote file.
         if undel mode(set by "OPT UND" cmd,default:ON) is ON/KEEP,
         deleted file is saved renaming to the following pattern
         at the same dir as original file.
         "..xe..orgname.._~yymmdd-hhmmss.mmm".
         (note. for local file deletion,original file is save to
         the dir xe_undel or xe_undel_xxxx xxx:userid for UNX)
         if undel mode is ON,these files are deleted at xe termination.
         if undel mode is KEEP those are remain.
       -Initial Line Locate.
        ./Lnn on xe cmd line parameter is to jump to the line nn just
         after the file is opened.
         this is for VC++ debugger to open by xe the file in question.
         to use this function,setup VC++ as following.
           register xe as tool.(Tool-->Customize-->Tool tab)
           set argument like as "$(FilePath) /L$(CurLine)"
           and also current dir as "$(CurDir)"
           shortcut key is registered by Keyboard tab selecting
           UserTool_ of Category:Tool.
        ./L is also a parameter of edit/browse cmd.
       -Command Log.
        .logging option is set OPT CMDLOG [ON|OFF]. default:OFF.
        .log file name is ::cl( filename is cl in workdir).
        .log may be used to create cmd file for exe cmd.
         (for OS/2 or GCC,once close by "OPT CMDLOG OFF",then open ::cl)
        .new edit line cmd "#" is prepared to execute the cmd on the lines.
       -"#" new edit line cmd.
        .format: #[^], ##[^]-##[!].
         1st is to execute one line. 2nd is to execute the cmd in the
         range of lines.
         excluded line is bypassed.
         the line start with "#" is comment line.
         timestamp field of command log line is also ignored.
         "^":execute on the other screen of split.
             (SWAp cmd is inserted at first).
         "!":continue multiple cmd execution even if err detected.
     3.Function changed.
       -SPLit  cmd.
        .default split type is set to ALL(previously no default).
        ."SPL [ALL] width" only is available split pattern for binary file
         and available for also under browse mode.
         this is to change the display width of binary file.

  .v118:(2005/07/04)
     1.BUGs
     2.Additional function.
       -GREp cmd support.
        .Same parameter as native cmdline tool except on browse/edit screen.
         On browse/edit screen,file/dir name parameter will not be specified,
         it search in current screen. Flaged line is searched by "F *G".||~124FR~
         On the other screen,grep result is saved to temp file "::#go".
         On cmd result screen,::#go is displayed on the screen.
         (Note)grep search on current screen is currently supported   ||~124FR~
               only for the grep utility which display lineno on top
               of line with "nnn:" format if -n option specified.
       -Find cmd.
        .support search word "*G" to search grep'ed line.
         *G is avail for also &(AND) search operand.
       -(WXE)Drag & Drop.
        .support Drag from dirlist screen and drop out of xe.
        .copy operation only.(source is not deleted)
        .file selection is by mouse left button.
         +Shift:range specification. +Ctrl:additional file selection.
        .after selected files,do drag and drop by mouse left button operation,
         or do copy and paste by floation menu.                       ||~124FR~
         a bit longer time may be requied until mouse shape change for remote file.
        .Excel may not accept drag and drop,use association(double click
          around the lineno filed of the line).
     3.Function changed.
       -Internal used temp file naming is changed to processid embedding
        name to avoid multiple session contension.
        for ex,::#go is grep result file in workdir.
        "e ::#go" is accepted but its real name is nnnn.go(nnnn:process id).
       -::cl(command log) line now contains process id.

  .v119:(2005/07/30)
     1.BUGs
     2.Additional function.
       -(LNX)new member gxe(Gnome GUI version executable) is added.
        It has same look and feel as wxe(Windows GUI version).
        The problem of key sensitivity of some combination key is resolved.
        gxe requires X environment,on console(switch by Ctrl+Alt+F1-F6<->F7)
        use xe.
        .compile environments.
          glibc-2.3.2-11.9
          glib2-2.2.1-1
          gtk2-2.2.1-4
          libgnomeprint22-2.2.1.1-3
          libgnomeprintui22-2.2.1.1-1
          pango-1.2.1-3
       -OPT DELZ {ON|OFF}
        If OFF,"z" and "0" dir-list line-cmd is not allowed.
        This is intended to avoid accidental not recoverable deletion.||~124FR~
       -Support wildcard path specification for Copy/Move DOS cmd and
        dirlist line cmd. Wild card is not for multiple path Copy/Move
        but for abbreviation.
       -(WXE)Accept Shift+PrtScr key as file print request.
        gxe assigned Ctrl+PrtScr to screen print because PrtScr key is intercepted
        by gnome,so WXE also accept Ctrl+PrtScr.
                   PrtScr     S+PrtScr     C+PrtScr
            WXE    Screen     File         Screen
            gxe    gnome      File         Screen.
       -(LNX)support OpenWith(Open by associated application)         ||~124FR~
        ASS DOS cmd, "!" dir-list line cmd and left button double click on
        dir list are works. Remote file is not supported.
       -(LNX)Scroll by wheel mouse middle button is supported.
       -(LNX)support child shell(terminal window) creation by "DOS sh" or
         "> sh".
     3.Function changed.
       -GREp cmd.
        File name parameter is required on also edit/browse screen to allow
        request to search in external file. Use "*" as filename to search||~124FR~
        on currently opened file. *\(dir opened now), ^*\(dir opened on||~124FR~
        another split screen) is supported as filename specifiaction.
       -F5(re-find) is now case-sensitive after Change cmd.

  .v120:(2005/12/12)
     1.BUGs
     2.Additional function.
       -New "&" DirList line cmd.
        .Spawn asynchronous child process.
        ."&" is changed assignment from AT cmd to SPAwn cmd as abbreviation,
         this assignment change is effective after ini file re-creation by
         INI cmd or update .ini file manualy if you are using .ini file.
       -(XXE)support printer selection on Preview dialog.
        (effective only when using CUPS)
       -(XXE)Help(display xe html help)support.
        set symbolic link to the xehelp dir appended.                 ||~124FR~
        ln -s /d/mydoc/xehelp   /usr/local/share/gnome/help/xxe
        or
        ln -s /d/mydoc/xehelp   ~/xehelp (home dir)
       -Support Windows like Cut&Paste operation.
        Previously Copy/Cut range is full line if cursor is at
        lineno field or rectangle of start/stop point if cursor is
        on file line column. From now additional range type is
        supported. The range is from later half of line of start point
        to first half of end point includeing full intermediate line.
        Windows like cut & paste range is specified by Alt+F6.
        Ctl+v is assigned to Windows like paste operation.
        This paste mode consider that last source line has            ||~124FR~
        (CR+)LF or not(if cursor is on line lineno-field assume LF for
        the last line).
		Del/BackSpce is not effective for delete the range but
        use Alt+Del.

        (WXE/XXE)Mouse operation.
        Use drag by left-button to specify the standard copy range.
        Use drag by Alt+left-button or Shift+Control+left-button to
        specify former box type range.
        (Alt+drag may intercepted by WindowManager of linux)          ||~124FR~

  .v121:(2006/04/17)
     1.BUGs
     2.Additional function.
       -Retrieve command of the screen.
        F12 retrieve all command input on any panel,A+F12 retrieve
        command only input on the panel.
        (Command Repeat is changed to C+F12)
       -RETTOL option.
        set cursor position after execute key to line-number field or
        Col1 on file display area.(opt rettol [on|off])
       -Alias cmd.
        Set alias cmd on short-cut-key panel("0.1 SC-CMD" of top menu).
        Add line prefixed "Alias:".
        Cmd is identified by top 3 byte. The line start by "*" is saved as
        comment line.
        Parameter specification and multi-command are supported like as short-cut
        key command.
        ex) ch1 s %1;c ABC xyz;end
            Use like as "ch1 file1".
       -CV command.
        support "\u" option(uni-code by \uxxxx format) for also conversion
        type s2u/f2u(uni-code output) and u2f(uni-code input).
       -(WXE/XXE)Drag&Drop
        Copy the file into the dir if dropped on the dir-list panel.
        Inter-split-screen drag&drop is also available.
        You can select target dir line on dir-list panel by mouse     ||~124FR~
        left button(default is the dir opened).
		When using Cut&Paste for Drag&Drop operation, Edit or Copy,
        is depend on the target panel type.
        In to the dir-list panel, copy override is done by PasteRep.
        Override confirmation is issued if you choosed PasteIns.
        If target is not dir-list panel the file is opened by PasteV
        menu item selection.

     3.Fnction change.
       -(WXE)Current dir is not restored when file name is specified on command
        line parameter.
       -(WXE/XXE)move text cursor by also mouse right button click.
       -Accept "Block" paste from clipboard copied by "Region" type copy.
       -edit line command parameter                                   ||~124FR~
        .break if paste source exhaust for p[n][,s][.s] pattern.      ||~124FR~
         (wrap use for pp-pp[n][,s][.s] pattern.)
        .set no reverse for not updated line by o/n paste command
        .reject n for yy pattern.
        .support rn,b.s pattern. repeat n times to repeat b lines once
         and skip s lines.                                            ||~124FR~
         set default s=0 when only b is specified for r command only.
        .accept cursor position also on 2nd line of pp/oo/nn command.
     4.Tools.
       -xcv     v1.6
        .support "\u" option for all ucs conversion case.

  .v122:(2006/12/14)
     1.BUGs

     2.Additional function.
       -Display file description on dir-list panel.                   ||~124FR~
        .Toggle this function by Shift+F10
        .EDIt/BROwse command option /Md set On at dir open.("e dir1 /Md")
        .if On,display max 48 byte.
        ."description" is gotten as following.
         For Windows version,read from top of stream named "xe-desc".
         This "stream" is one of ADS(Alternative Data Stream) of NTFS.
         ":"+47 byte stream is displayed.
         When "xe-desc" is not set up or for other than Windows version,
         read top 1024 byte of the file itself.
         If ":DID" is contained in the range of 1024 byte,display
         from the next of ":DID" string to the EndOfLine.
         If no "DID:" found,display from top to EndOfLine of 1st not null line
         of the file. Control char(<0x20) is replaced by ".".

        (Note) ADS.
               NTFS supports multiple data stream attached to each file/dir.
               Accessed by naming convention of fil-name:stream-name,
               echo command will create stream like as
               echo "text" > abc.ext:stream1 (1 byte base name may be error)
               dir command or explorer cannot display stream.
               cat command if you have display the stream contents like as
               cat abc.ext:stream1.
               To delete ADS(ADS size cannot be reduced) copy the file to
               not NTFS volume then CopyBack after deleted the file.
       -Horizontal scrolling.
        .When scroll lock is on,Left/Right arrow key scroll file contents||~124FR~
         screen by one column.
         Up/Down arrow key also scroll a line when scroll lock is on.
         This dose not work for Linux Console version.
        .GUI version(wxe,gxe) supports mouse with horizontal scroll function,
         It scrolls screen by the column specified on Setup dialog panel.
         I experienced 2 type of horizontal scroll mouse.
         Tilt wheel mouse generates WM_HSCROLL mouse message,
         another generates VK_SCROLL then VK_LEFT/VK_RIGHT keyboard message.
         wxe support both,but gxe support support VK_SCROLL type only.
         Keyboard message type dose not generate VK_SCROLL when already
         ScrollLock is on,so that shifts 1 column under that condition.
        .To scroll horizontally using simple wheel mouse,use Shift+wheel.
         Ctrl+wheel is used to jump to top/last page of file.
         These two function is supported also by Linux console version.
       -(WXE)Forward/Backword button click of 5 button mouse is treated
        as DPU/DPD(FilePath Up/Down) command.
       -LOCate cmd.
        .search labeled line by .label operand spcification.
       -Fix keyboad input to uppercase.
        .New command CAP.
          CAP [ON|OFF] [TSO|DEFAULT|CMD]
          Default is set for each TSO file and the others.
          If operand missing on file opened panel,toggles the status of the file.
          CMD means that CAP-ON is effective also on the command-input-line.
        .Use Shift-key when input lowercase letter when CAP ON.
         (Linux console version cannot detect Shift-key,so CAP-ON reverse
          upper and lower. The effect is not same as other version when
          keyboard CapsLock is on)
        .New CAP option of EDIt command set CAP ON status at open.
        .New edit line command "U" support upper-case translation.
          Ur,b.s or UU-UU,b.s format.
       -Setup "Line Drawing Character" by the ini file.
        .As a default,some code are assigned for line drawing character.
         Those are of Japanese DOS under Japanese environment.
         Or else,ECS(IBM PC Extended Character Set) is used as known as CP437.
         Hex code is displayed on =0.2 panel.
        .Code assignment is changed by the file on work directory.
         Naming convention is xelch__.ini[.locale]
           __ : version ID ex) win,gcc,wxe,lnx,gtk.
           locale: for Linux version (lnx and gtk) only.  ex) "ja_JP.eucJP"
                   It is gotten by Linux "locale" command.
           The filename is displayed on the bottom line of =0.2 panel.
        .OPT LINECH [on |off |filename | reload]
       -SUBmit command.
        .Support input redirect specification("<stdinfile").
         To avoid hung by unexpected stdin read operation issued by
         submitted shell/exe, "<NUL"(/dev/null for UNX) is appended
         in those case.
        .For 1st operand(script/exe filename),to make use of PTH
         environment variable fullpath conversion is applyed only
         when path is partialy specified.
         Special path specification format *\ , ^*\ , :: is available.
        .For 2st parameter only,support "*" specification.
         That is replaced by currently opened file name.              ||~124FR~
         ex) "SUB subtool *".
         ("*" of 1st operand means execution of the current file.)
         This is for the convenience of passing file to other script/exe.
         If the file is updated by edit operation,the contents are
         save to a temporary file and the temporary file name is passed
         to the 1st operand file. This is for the convenience of
         repeated submit with partialy modification.
        .Treat "**" as orginal filename specification regardless of   ||~124FR~
         update of the file.
         ex) "SUB subtool * ** p1" , "SUB ** p1"
        .Function key is assignable by ini file.
       -(Win) Turnkey MVS support.
        "Turnkey MVS" is MVSR38J on PC("Hercules" emulates 370 instruction).
        It is able to access TSO file on Turnkey MVS using IND$FILE
        through 3270 emulator.
        It is supported to display PDS members.
        About detail,see the session "Turnkey MVS support" in the chapter
        "(0)Introduction-(D)How to for".                              ||~124FR~
       -Edit command
        .New option Fn[-m] to force the record length to n and set
         left margin to m.
        .New TC|NOTC option to specify TAB clear(change to space at save).
       -B2A/A2B(EBCDIC<==>ASCII) conversion option is added.
        (Ignore 0x0e/0x0f as SO/SI of SBCS(Japanese DBCS))            ||~124FR~
       -Change command.
        IC(CaseInsensitive) and ICN(CaseInSensitive,change displayed line only)
        commands are added.

     3.Miscellaneous.
       -INI command skip Japanese comment output on ini file
       -For delete edit-line-command only,remove limit of repeat count 9999.
       -Reset edit line command differently for label and the other cmds.
        Esc key twice or "RESet" clear line cmd except label,
        Esc key three times or "RESet L" clear label cmd.
       -Assign also Alt+'=' to Vertical-Line as same as Alt+'^'.
        '=' on english 101 keyboard correspond to '^' on 106
        Japanese keyboard.                                            ||~124FR~
       -Separately save scroll value for the parameter setting(=0.1/2/3) panel.
       -On the screen of =0.2 command verb can be cahnged for the function
        for which function-key cannot be assigned except Edit/Browse/Select.
       -Windows Vista support.(Test by RC1 English version)
        .Correspond memory management logic change.
         (xe terminate with msg "address xxxx is not malloced")
        .WinHelp is deprecated.
         Changed to call associated application(browser:IE) and
         to call HtmlHelp for popup help.
         (Previously wxe.hlp was not able to read under English environment)
        .Default charset is changed to use windows default.
         Previously default was ShiftJIS(for Japanese user).          ||~124FR~
       -(WIN/LNX)Also console version,help command kicks browser.
       -Keep old SPF version number on the line number field of valid
        SPF line even when the line was changed by RENUM command.
        Previously renum-ed lines of error SPF file(contains short or ||~124FR~
        invalid line number line) ware changed it version number to
        the largest one.

     4.Tools.
       -xads    v1.0  For Windows Only,Access to NTFS ADS(Alternative Data Stream).
        fmt  : xads [/options] {base-name | ADS-name} [ file-spec | "TextString"]
          base-name :file/dir/wildcard of NTFS filesystem for List/Read operation.
                     Wildcard required for all directory member.
          ADS-name  :ADS name for Write operation. file-spec:stream-name format.
          file-spec :input/output file-spec for Read/Write operaetion.
          TextString:ADS contents to be written for Write operaetion.
          options   :
             /L :List all ADS name and size of the directory/file.
             /R :Read ADS then write to the file-spec specified. default is stdout.
                 If output file-spec is directory,member are created for each ADS.
             /W :Write to the ADS from file-spec or TextString.
                 ADS size is not be shorten. (To delete ADS,copy to not NTFS).
             /T :For Write operation,input is not file-spec but TextString.
             /Sn:n:subdirectory search depth for List/Read.
                 S0:directory itself, S:all descendant. default is S1.
             /F :For Read,write whole of the ADS. for stdout,default limit is 1024.
        ex)xads /Ls0 dir1; xads /rs . outdir; xads /r d:\*.doc; xads /r file1:stream1;
           xads /w file1:str1:$DATA doc.txt; xads /wt file1:str2 "descriptions";
       -xdig    v1.8
        .support %fb% parameter. It is replased by basename.
         basename:name before the first ".".                          ||~124FR~
       -xfg     v1.9
        .support unicode string search.
        .(BUG) When -i (case insensitive) option specified,
         search by uppercase is not done if search by 1st character   ||~124FR~
         of the search string failed.
       -xlow    v1.4
        .support Uppercase translation.
       -xkp     v1.0
        .(Windows) Display process-ID and kill process.
       -xpe     v1.0
        .(Windows) Display GetLastError() code description.
       -xcv     v1.7
        .B2A/A2B(EBCDIC<-->ASCII) conversion option is added

  .v123:(2007/09/17)
     1.BUGs
       -It is not avail to edit on command input line for long command re-displayed by F12.||~124FR~
        Insert is rejected by field full,delete cuts the later half beyond field width.
        (long command may be input using short-cut-key defined on =0.1 panel).
       -(Linux)F6(display linecount) on dir-list fall into infinite wait if the file's
        symbolic link source is special file like as character device.
       -(3270)xe3270 ABEND when native TSO command entered by xe's "TSO reply" command
        contains "%"(mean to restrict the DataSet to search for the CLIST).||~124FR~
       -About DBCS(Japanese) text edit.
        .NUM command.
         ..When one byte of DBCS is cleared by "NUM clear" cmd,another byte remains.
           It should be replaced by space.
         ..When DBCS is on Col.80 1st byte of DBCS remains at Col.80 after
           "renum" command for the COBOL file opened by EC command(Col.72-80 is||~124FR~
           not treated as lineno). It should be replaced by space.
        .Incorrect character displayed when DBCS is split by margin boundary||~124FR~
         for margined file such as SPF file.
        .Both byte is deleted when one of DBCS is deleted on HEX line of vertical
         HEX display mode.
        .DBCS is not displayed correctly after DBCS character is configuered by HEX digit input
         on HEX line of vertical HEX display mode or HEX part of horizontal HEX display mode.
        .Another column of DBCS is replaced to space when one of DBCS
         is updated on HEX line of vertical HEX display mode.
        .DBCS split by S+Enter(SplitLine) replace DBCS to 2 space
         also when the line is split on HEX line of vertical HEX display mode.
       -About TAB(0x09) character edit.                               ||~124FR~
        .When the file with margin contains TAB.
         ..Delete character operation may get down margin data into the text area.
         ..Change command replacing to wider string may lose the character near
           the margin boundary.
        .When editing on HEX display line of vertical HEX display mode.
         ..tab expanded space remains after TAB is replaced to other character.
           (This is valid for character line,but on hex line tab padding space
            should be deleted)
         ..for the file with margin,margin may shift to right after replacing to TAB.
        .TAB padding space remains after TAB was replaced by Change command
         as padding space(cursor jump) and not as space.
         (TAB and TAB padding space is match to space of find string)
       -Duplicated function key assignment is not detected for triangle-relation.
       -Line split("s" line cmd) was shifted data on the right of margin boundary.
        It should be kept on the margin position.
       -Line conjunction("j" line cmd) should ignore line-no on COBOL margin
        of 2nd line.
       -Column adustment by TAB generated by "cv x2c" was not done.
       -COL cmd ABEND when type parameter strlen is >=6.
       -About Cut&Paste.
        .C&P may ABEND if ::cb(clipboard file for C&P) is diplayed.
        .Data is not displayed after paste into command input line.
        .Cursor positioning err at S+F1(Undo) after C&P done.
        .Standard paste may fail by the reason of margin overflow.    ||~124FR~
        .A+w(copy word to clipboard) should ignore line-no on COBOL margin.
        .Space at the end of line of top line is dropped by Cut operation.
       -"TC FMT" command width "N" option remains invalid field delimiter.
       -For "="(Compare) line cmd,unmatch point is not displayed reversely
        if the position is DBCS.
       -SPLit cmd.
        .Replace split DBCS by space when TAIL option is used.
        .Replace TAB(0x09) by space for split or joined part of line  ||~124FR~
         to keep line length.
        .Some lines are left as not split.
        .ABEND may occurs when changed width of Binary opened file.   ||~124FR~
        .Hex offset on lineno column is left unchanged after width change
         of binary opened file.
        .Delm parameter is ignored for the file with margin.
       -ROTate cmd.
        .ABEND when specified column range parameter is larger than maximum line length.
        .TAIL option for LJ(LeftJustify) operation is ignored for the line
         which length is same as column range parameter.              ||~124FR~
       -TC cmd.
        .for opd3=opd1 pattern,operation fail for the line opd1 data start by "=".||~124FR~
        .opd3=opd1 pattern cmd is rejected if .label parameter specified.||~124FR~
       -Ctrl+v is assigned to Standard-Paste and it is not effective
        when CCFUNC option is OFF(treated as char input).
        But,accept paste function when popup menu item Paste(V) is selected.
        And,opt CCFUNC OFF is not effective when no ini file for Ctrl+v.
       -User gauge set by COL command is reset to default gauge after off/on.||~124FR~
       -(WXE/XXE)On DirList screen,file attr field is cleared after screen vertical resizing.||~125DR~
       -(Linux)Under FC5,readdir API dose not always return "." (current dir)
        as the first member. So, delete of dir or copy from dir may fail
        by "not dir" message.
       -(Linux)When started xe not from gnome-terminal (on Kubuntu),
        cursor disappear when insert mode.
        --u (default when X mode) option is added to display underline
        at the cursor position when insert mode.
       -(Linux)Kubuntu support.
        .(XXE)Child window by ">cmd" immediately disappear without waiting "Hit Any Key".
        .(XXE)Terminal program start by ">" cmd or selection of "Terminal" icon fails.
         Now terminal program is a option of ini file.
         Default is gnome-terminal if it's found,else konsole.
        .shell program called by ">" cmd is dash under (k)ubuntu.
         xe use "sh" for system() that is slink to dash under (k)ubuntu.(bash for RH9 or FC5)
         Enter key is treated as ^M not but ^J.
         Now shell program is a option of ini file.
         Default is "bash" if "dash" is found,else "sh".
       -(xe3270)Hung by dead-lock when no xe3270.cfg is found and TRACE mode is ON.
       -(XXE)Paste by mouse may hung the process if "OPT RCTL ON"
       -(LNX)Edit-Save fail for the file on floppy drive by WritePermissionError.

     2.Additional function.
       -(WXE/XXE)GUI version support CrossHair cursor(ruler).         ||~124FR~
        Trigger key is Shift+Control+F1,F2,F3 for vertical,horizontal,cross each as default
        To erase ruler use same key as to display. Key assignment is changed by Setup dialog.
        Use "Setup" dialog to change ruler color. For Windows version set Ruler checkbox to on,
        for Linux version push Ruler button of color change group.    ||~124FR~
       -It is configurable to popup exit-confirmation-dialog on setup dialog.
        To bypass the dialog check on QuietExit checkbox.
       -"COL [on|off] ALL" command set option to display default type column gauge
        line at open for all file.
       -Line cmd("_":LowerCase conversion) support.
       -BOUnds(BNDs) command support.
          BND [col1] [col2] [ext]
        Effective for Find/Change/Sort/Split/TFLow commands
        and Shift(<,>,(,),[,])/Paste(o,p,n)/
        Compare(=)/CaseConversion(u,_) line command.
        Boundary column is indicated by "<" and ">" on gauge by COLs command.
        Default can be set by Bounds parameter on the ini file for each extension-name
        (start by "."),dir-name or each filename.
        ex)
            Bounds  = "G:\src\xe" = 10  20  #  filename or dirname
            Bounds  = .cob        = 50   0  #  extension
        Using "EXT" option on the file edit panel,default by extenstion is set.
        BND cmd on the dir-list panel set default to the directory.
        After that the status is written to the ini file by INI cmd.
       -SPLit command.
        .New option.
          OOM     :width TAIL option,Ignore Bounds/Margin setting.
          STRSPACE:Split only once even when space is continued.
          SPACE1  :Shrink continued spaces to a space.(with ALL/OCER option)
        .Additional to padding char,delimiter and terminator char is
         specified on "str" parm of EXP option.
       -Text Flow function.
        .TFLow/TF command.
          {TFL | TF} [width] [SBCS] [TOL] [STRDELM] [SPACE1]
                     [In] [ALL|EACH] [Pn|NOP] [BASE1] [AWORD|SWORD]
                     ['del-chars'} [.lab1 .lab2]
            width   :right boundary after re-flowed.
            SBCS    :split DBCS on left/right boundary into 2 SBCS.
                     if SBCS option is not specified,split DBCS is
                     replaced by 2 space.
            STRDELM :treat 'delm-chars' as a string to split line.    ||~124FR~
            SPACE1  :shrink continued space chars into a space char.
            In      :Output indentation(preceding space count).
            ALL     :Process all paragraphs if Pn is not specified.
                     Overflowed data by narrow width parameter may override
                     the line of the next paragraph.
            EACH    :Process all paragraphs if Pn is not specified.
                     Do not over flow to the next paragraph but insert lines
                     between each paragraph for the case narrow width
                     parameter is specified.
            Pn      :Specify the paragraph count to be processed. n=0 means all.
            NOP     :Ignore paragraph(Assume all lines are in a paragraph||~124FR~
                     after the end of line is determined by Pn option if specified)
                     All the following lines are re-flowed with the 1st line's
                     indentation if In is not specified.
            BASE1   :Paragraph indentation base is of the 1st line.
                     The paragraph contains the following lines of the same
                     indentation as the 1st line.
                     If BASE1 is not specified, paragraph contains
                     1st line and 2nd line, and the following lines of same
                     indentation as 2nd line that may not be same as 1st line.
            AWORD   :(After Word) If space is not contained on source data
                     in the range of target field width,split the line
                     at the point of 1st space beyond the width.
            SWORD   :(Split Word) If space is not contained on source data
                     in the range of target field width,split the line
                     at the point of the width.
           'delm-chars':Line is split at the delimiter searched.
                        SPLit cmd width width parameter split only once
                        just before the boundary of the width parameter.
                        TFlow cmd split each time at the point delimiter found.
           .lab1/.lab2 :line range to be re-flowed.
                        If not specified label range,start from the line
                        cursor is placed.
                        If cursor is on the command input line start line
                        is the top of file.
        .TF/:/; line command.
           TF[m]   :[n][,m][.i]   ::[,m][.i]   ;[n][,m][.i]   ;;[,m][.i]
           ":" : same as "TFL" command,  ";" : same as "TFL NOP",
           n   : line count,             m   : target range width,
           i   : Indentation.
       -TS line command.
         Split the line at the cursor point.
         (Same as "S" line command, Shift+Enter also split line.)
       -E8/B8/S8 command.
        Open the file by Fixed LRECL=80 without line-number on col.73-80.
       -New DirList line command.
        ."g":grep in the file or directory.
        ."=":compare two files using tool "xfc" in this package.
        ."3":open the file by binary mode(browse or edit depends on the dir mode)
        ."8":open the file by Fixed LRECL=80 without line-number-column.
       -new ini file option "R-Ctrl_NewLine" to assign Right-Ctrl key to
        function NewLine. if "R-Ctrl_NewLine=1" is effective,
        Enter key is yet assigned to "Execute the NewLine".
        "R-Ctrl_NewLine=1" is effective only when "R-Ctrl_ENTER=1".
        Alternative of "R-Ctrl_ENTER=1" is -Yr command line option.
        Or use "OPT RCTL ON" command or set checkbox "R-Ctrl" to ON
        for gxe/wxe.
        Note)Typematic for Right-Ctrl key is not effective for OS/2.
        R-Ctrl is not used for Linux console version.
       -(XXE)support paste from PRIMARY clipboard(text select by mouse)
        by middle button click.
       -New panel 3.12(File/Directory compare), 3.14(Search) support.
        .ini file set command to use. default is xfc,xdc,grep.
             CompareFile_Cmd   ="xfc"  #("xfc")# File compare cmd.
             CompareDir_Cmd    ="xdc"  #("xdc")# Directory compare cmd.
             Search_Cmd        ="grep" #("grep")# String search cmd.  ||~124FR~
        .You can set filename parameter from dir-list panel on the split screen.
         Alt+i(Insert),Alt+r(Replace),Alt+d(Delete),Alt+Up(1 line up) and
         Alt+Down(1 line down) are keys to send filename.
         line cmd "^" also send filename according to Ins/Rep mode.   ||~124FR~
         wxe/gxe accept Drag&Drop,Cut&Paste from dir-list or Explorer/Nautilus.
        .Find key(default:f5) enable to open dir-list using patialy input path name.
       -FileNameList panel(=1 and =2 panel)
        .FINd/IFInd(and F5,S+F5 Function key) command support.
        .Scroll size on command input line(2nd line) is accepted.
       -ROTate cmd.
        .SBCS occupies optionally 2 column to keep same column as DBCS||~124NR~
         on the source line after rotation(R(X) or L(X) operation).
         SBCS is aligned to left or right by DBCSAL or DBCSAR option.

     3.Miscellaneous.
       -(Win/Linux)largeFile(>4GB) support.
        Large file is display on dir-list with file-size of KB unit,
        (Previous Linux version loses large file to list up)          ||~124FR~
       -It is now available to insert on HEX line of vertical HEX display mode.
       -"CID shift" command shift last CID only,it dose not delete other CIDs
        on the same line.
       -Additionally A+F10 and C+F10 are assigned to the function     ||~124FR~
        "Display file description". Command verb "DFD" is also assigned.
       -Add "-NX" option to Find/Change(search on displayed lines only) command.
        (This is same as FNX/CNX command).
       -Replace by space if DBCS is split by Shift,Paste line commands.
       -Fixed Record Length file.
        .Expand short record by space padding when save the file opened||~124FR~
         by Fxx parameter.
        .Join line by Del key at EOL or join line command cut trailer space
         of 2nd line to be joined.
        .CID line at the top of file accept Fxx option parameter.
          ex) //*CID://+dateR~:#63 option=(f80,m72,n,p0,tabclear)
       -Expand parameter input area for DirList line cmd "#".
       -Linux version is now packaged using libtool to enable installing
        xe from source file by "./configure && make".
        gz file is packaged on FC5,install test was done on RH9,Kubuntu6,Ubuntu7.
        See README in .gz file about instalation trouble.
        Seach sequence of xehelp(Help html) dir,Icon name and path was
        changed.(see xelnxe.doc).
       -(3270)IND$FILE splits long line when upload to fixed LRECL dataset.
        Upload confirmation read check consider it.
        It is assumed as successful upload even when line split detected.||~124FR~
        but error msg is issued on xe3270 prompt screen then beep twice.
       -SPLit TAIL command consider concatinated line.
        If last line of split lines is all space,space on tail of
        previous line is cut.
       -Accept replace/insert at the EndOfLine position of hex display line
        of 3 line hex display mode.
       -On filename list (=1 or =2) panel,accept paste into filename or dirname line.
       -Function Key assignment duplication check is changed from
        by Function to by Key to increase flexibility.
       -Remote file access.
        .Deal with the FTP server of active mode only.
         (error msg "no route to host" is issued after successful login)||~124FR~
         Specify ICMD=passive in xehosts file that cmd toggles active and passive mode.
        .Some FTP server such as proftpd dose not detail information for ls sub cmd.
         I heared that is by RFC,default cmd was changed from "ls -la" to "dir".
         If dir cmd is not supported by the server,specify,for ex, LS="ls -la" in xehosts file.
       -For the case of file corruption by ABEND at file writeback,
        now original file is saved at the same directory by rename.
        Renamed original file is deleted just after write operation completed.
        "NB" option of Edit cmd skip this bkup operation for the case
        of disk full for large file.

     4.Tools.
       -xdc     v2.10
        . LargeFile(>4GB) support
        . (LNX)Under FC5 "not dir" error may occur.
       -xdd     v1.7
        . LargeFile(>4GB) support
        .(Linux:BUG)wildcard is rehjected by parameter error.
       -xds     v1.5
        . LargeFile(>4GB) support
       -xfc     v1.14
        . LargeFile(>4GB) support
        . Allows to expand max line length by /L option.
        . For word compare delimiter other than space/tab is specified
          by new parameter /D'xx'.
       -xff     v1.4
        . LargeFile(>4GB) support
       -xfg     v1.10
        . accept ":"(LNX) or ";"(DOS) concatinated string for file-spec parameter
          for the case env-var is specified.
       -xfs     v2.3
        . LargeFile(>4GB) support
       -xkp     v1.1
        . Parent pid is displayed when /L option specified.
       -xcvsjisc v1.0
        . Convert SJIS(Japanese DoubleByte Code) in xe's source file
          to Octal notation for English user to see and edit source.
                                                                      ||~7A23I~
  .v124 :(2009/04/13)                                                 ||~124RR~||~124SR~||~125AR~
     1.BUGs                                                           ||~7A23I~
       -(LNX)Permission is lost after file is modified.               ||~7B08I~
       -FTP.                                                          ||~8123I~
        .When using FTP client issues message other than English,transfer fail by "LCD fail" message.||~124FR~
        .Path error was treated as FileNotFound(New-File)             ||~8123I~
        .Private files the name start by "." may not be displayed on dir-list.||~8123I~
         Try and select "ls" or "dir" which is better.                ||~124FR~
        .deal with SELinux read protection of /home.                  ||~8123I~
       -ABEND by A+i(Send Filename) on Utility panel(3.12/3.14)       ||~8123I~
       -Copy-ON may leave DBCS 2nd byte of copy source line.          ||~8123I~
       -Duplicated function key assignment checking miss error.       ||~8123I~
       -XXE(gxe)                                                      ||~8123I~
        .Screen height expand by font change.                         ||~8123I~
        .Cancelation of font change leaves corrupted font name or may cause ABEND.||~8123I~
        .The priviously selected position is lost at openning font list.||~8123I~
        .Font selection on Preview dialog issues error "corresponding gnome font not found".||~8123I~
       -TC cmd.                                                       ||~8123I~
        .for opd3=opd1 pattern,operation fail for the line opd1 data start by "=".||~124FR~
        ."P" option of "TC FMT" may be ignored.                       ||~124QR~
       -SUBmit command,"#" line-command fail.                         ||+124FI~,||~124FR~
       -DirList entry may be duplcated when remote is PSFTP.          ||~124F,||~124FI~
       -(WXEXXE)DirList rename field dose not expand according to screen resize.||~124GI~,||~124GR~
       -EXE cmd ABEND when END/CAN cmd is called from EXE cmd file.   ||~124GI~,||~124GR~
       -CV cmd.                                                       ||~124QR~
        .Trash was left on NULL line.                              ||~124GI~,||~124QR~
        .The start line of line range by .label option is not translated.||~124QR~
       -(W32:console version)Ctrl+char key is inactivated after external cmd call such as grep.||+124GR~,||~124GR~
       -(WXE)WinHelp is left in session closing logic. WinHelp is not supported in Vista.||~124GI~,||~124GR~
       -(v124H-BUG)SyntaxHL:CUI and GUI option in cfg file was influenced each other.||~124JR~
       -(v124H-BUG)SyntaxHL:revise required when tab width was changed.||~124JR~
       -(UTF8 version)                                                ||~124QR~
        .Screen was corrupted by INS key or vertical screen split.    ||~124QR~
        .ABEND by A+U(SWKBD)/UTF cmd.                                 ||~124QR~
        .Loop by u2l cmd if no operand is specified.                  ||~124QR~
        .Hang up when input from IME.                                 ||~124RI~
       -(Win version)ABEND by x(Close)-button if =1/=2 panel is opened once.||~124JI~
       -(BUG)slow response of "del x all" cmd for large file.         ||+124LI~,||~124LR~
       -(BUG)ABEND at file save if the file opend with Fxx(Fixed LRECL) and no-tabclear||+124LI~,||~124LR~
        has short line.                                               ||+124LI~,||~124LR~
       -(LinuxConsoleVersion)                                         ||~124RR~
        .err msg "RGB color not changable" was issued on =0 panel.||+124MR~,||~124RI~
        .Avoid to use A_BOLD bit when on CONSOLE1-6 because this attribute may||~124RI~
         distort charcters displayed(xe uses A_BOLD to display color yellow.||~124RI~
         Specify --B cmd line option if there is no problem at your environment.||~124RI~
         On the other hand, on X terminal emulator A_BOLD is default, ||~124RI~
         --B option now is used not to use A_BOLD.                    ||~124RI~
        .Line drawing character by ACS did not draw line on CONSOLE1-6 of FC5.||~124RI~
        .Lacking boundary line characters when screen split vertically.||~124RI~
       -(W32)SOx files,files for redirect stdout from =6 panel,was shared||~124RI~
        among multiple sessions. Now sharing is controled by lock files.||~124RI~
        And, SOx is now expanded to 16 files from 10 files.           ||~124RI~
       -(XXE)                                                         ||~124RI~
        .Disp_trans_char option of ini file was ignored               ||~124RI~
        .Disp_tr_tbl_wxe(for GUI version) was not used,               ||~124RI~
         but Disp_trans_tbl(for Console version) was used.            ||~124RI~
                                                                      ||~8123I~
     2.Additional function.                                           ||~7A23I~
       -Remote Access(FTP).                                           ||~8123I~
        .Support TinyFTP daemon on Windows server.                    ||~8123I~
        .Support PSFTP in PuTTY. (SSH2 was tested under v060)         ||~8123I~
          New statement of ::xehost.                                  ||~8123I~
            #@PSFTP=g:\src\putty060\psftp.exe                         ||~8123I~
                Use when psftp is not on PATH environment variable.   ||~8123I~
                Additional option will be specified. Default is shown on ::xeftplog.||~8123I~
                (::xeftplog is written when xe starts with -fw command line option)||~8123I~
            #@SSH=all                                                 ||~8123I~
                Set ssh=Y as default for the destination after this line.||~8123I~
            dest1 192.168.2.5  user pswd  ssh=Y                       ||~8123I~
                Specify ssh=Y(use PSFTP) or ssh=N(use FTP) for each destination.||~8123I~
                If missing,#@SSH= is applied as default.              ||~8123I~
          (Note)                                                      ||~8123I~
            .Specify like as ##@PSFTP=... to comment out.             ||~8123I~
            .At first SSH connection to the destination,use native psftp command on console window||~8123I~
             to save host-key in cache.(ex. psftp -l USER -pw PSWD)   ||~124FR~
             -xe use -batch option of psftp,but Windows version will hang up if no host-key||~8123I~
              is in cache. Linux version end with error,so xe display the error reason.||~8123I~
            .::xehost update is effective from the next session.      ||~8123I~
       -Assign Alt+g to the new function to jump cursor between Char-part and Hex-part||~8123I~
        when horizontal/vertical HEX display mode.                    ||~8123I~
       -CRLF option of SPLit cmd                                      ||~8123I~
        Split lines by the width or CRLF code,used to change the display width of text mode.||~8123I~
       -UTF8 support version.                                         ||~124FR~,||~124FR~
        See chapter "UTF8 support" of xee.txt                         ||~124FR~,||~124FR~
        UTF8 support is offered by another module(xeu/wxeu/gxeu).     ||~124FR~,||~124FR~
        Be aware that this is the 1st release of UTF8 support.(Please let me know if you found bugs)||~124FR~,||~124FR~
       -Another word search function key.                             ||+124GR~,||~124GR~
                  CaseSensitive        CaseInsensitive                ||~124HR~
            Bwd     C+[, A+S+[           A+[                          ||~124HR~
            Fwd     C+], A+S+]           A+]                          ||~124HR~
                                                                      ||~124GR~
        Search the word on cursor position,and continue to search same word as long as pressing these key.||~124GR~
        Once intercepted by other key, new word is selcted from the cursor position.||~124GR~
        Following cmd verb is assinged for each, FWB,FWF,IWB,IWF.     ||~124GR~
        And you can specify word delimiter type on cmd line(from the first if function key is used).||~124GR~
                                                                      ||~124GR~
          AN | SP | DQ | SQ | (x | x( | )x | x)                       ||~124GR~
                                                                      ||~124GR~
          AN:all puctuation(Default), SP:space, DQ:"(double quotation), SQ:'(single quotation)||~124GR~
          ( :left boundary,   (x including  x and x( excluding x.     ||~124GR~
          ) :right boundary,  )x excluding  x and x) including x.     ||~124GR~
             If "(" or ")" is delimiter,specify like as \((, \)(, \(), \)).||~124GR~
             If '"' is delimiter specify like as ""(.                 ||~124GR~
             AN dose not contains @, _, $ and locale specific as punctuation character.||~124GR~
             x may be multibyte string.                               ||~124SR~
        If the cursor is on the reversed range by mouse drag or Cut&Paste function key,||~124GR~
        the whole string in the range is searched.                    ||~124GR~
        If cursor is out of file contents area such as cmd line or lineno field,||~124GR~
        serach the same word as previously selected.                  ||~124GR~
        This allow to search in the other file in the same session.   ||~124GR~
        The word is save for next session(max 128 byte).              ||~124RI~
       -Another word paste function key.                              ||~124GI~,||~124GR~
          Ctrl+w:append the word on the cursor into command line.     ||~124GR~
                 In this function the word means space delimited word.||~124GR~
       -EXE cmd redirect parameter.                                   ||~124GI~,||~124GR~
          EXE [!] { * | ^* | filename } [parm1 parm2...]  [< {@parmfile | [S] wildcard  [D[+]] ]||~124GR~
            Parameters after "<" enable to repeat the EXE cmd until all entry are exausted.||~124GR~
            @parmfile :Repeat for each line of the parmfile.          ||~124GR~
            S         :S means select and used on the dir-list panel. ||~124GR~
                       Each filename(with out path) corresponding to the wildcard is the last parameter to the EXE cmd.||~124GR~
            wildcard  :Without "S",fullpath name corresponding to the wildcard is the last parameter||~124GR~
                       of each repetation.                            ||~124GR~
            D[+]      :By default,sub dir is not selected.            ||~124GR~
                       D : select directory entry only, D+:select all entry including directory.||~124GR~
          One supposed usage is change the word in all files in the directory at once.||~124GR~
            ex) File execmdf contains following 3 lines.              ||~124GR~
                       s "%3"                                         ||~124GR~
                       c %1 %2                                        ||~124GR~
                       end                                            ||~124GR~
                Enter  "exe ! execmdf FROM TO <s *.c" on dir-list panel.||~124GR~
                EXE cmd executes Select/Change/End to all *.c file in this directory.||~124GR~
                If "!" is not specified,repetation stop at the file which dose not contains the word FROM.||~124GR~
                To abridge cmd input,you may register this exe cmd in =0.1 panel.||~124GR~
                For ex,enter "chd exe ! execmdf %1 %2 <s *.c" on =0.1 panel.||~124GR~
                "chd FROM TO" on cmd line do the same thing.          ||~124GR~
          When setupping EXE cmd file,you should consider that file name may have embedding space.||~124GR~
          EXE cmd log remains on ::#exe.                              ||~124GR~
       -SYN new cmd.                                                  ||~124GI~,||~124GR~
        .Using GNU source-highlight, text is optionally displayed with syntax specific color.||~124NR~||~124SR~
         My derived version "xeshm" is alos offerred for perfomance gain.||~124RI~||~124SR~
         This version is resident sub-process to avoid process initialization load.||~124RI~||~124SR~
         (xeshm uses StartApp class of source-highlight version2.9.    ||~124RI~||~124SR~
          Windows version is compiled on MingW, Linux version is compiled of FC5.||~124RI~||~124SR~
          Latest version of source-highlight is v2.10.                 ||~124RI~||~124SR~
          Original source-highlight can be called from xe as one time process.||~124RI~||~124SR~
          If you use xewhm data-directory hove to be of v2.9.)         ||~124RI~||~124SR~
        .andre-simon's "Highlight" is also tested.                    ||~124SR~
         This one supports wider range of language.                   ||~124SR~
         Specify the command by SHCMD= operand in .cfg file.          ||~124SR~
       -CUT/PASte new cmd.                                            ||~124GI~,||~124GR~
        Cut&Paste by mouse use system clipboard and copyed text is pastable at the instance,||~124GR~
        but Cut&Paste by function key dose not write the clipboard until session end.||~124GR~
        These cmd save and restore each time and  allows to Cut and Paste between 2 xe session||~124GR~
        opened at same time.                                          ||~124GR~
       -Find/Change cmd new option.                                   ||~124RR~
        "-g" (grep) support regular expression.                       ||~124JR~
        Picture pattern(P'...') is supported.                         ||~124JR~
        Only "=","<",">" has special meaning for replacing picture pattern.||~124RI~
       -Profile function.                                             ||+124LI~,||~124LR~
        Following status is saved to profile record and used at next open.||+124LI~,||~124LR~
          BNDS,CAPS,TABCTR,TABCLEAR,SPF,COBOL,SyntaxHighlight options.       ||+124LI~,||~124NR~,||~124NR~
        New PROfile cmd is for displaying current status and writing to profile record.||+124LI~,||~124LR~
        Profile record for directory and extention is written by this cmd||+124LI~,||~124LR~
        and used as default for the file in the directory or the file having same extention.||+124LI~,||~124LR~
       -(UTF8 version) 2 line cmd on dir-list is added.               ||~124MI~
        Open the file with codepage option, "["(CPLC) and "]"(CPU8).  ||~124MI~
       -Optionally contines Insert-Line after edit line cmd "I".      ||~124NR~,||~124NR~
        Set option by following cmd. Default is on.                   ||~124NI~,||~124NR~
          OPT INS_LINE [on|off]                                       ||~124NI~,||~124NR~
       -CV cmd.                                                       ||~124QR~
        .New "-Sm"(multiple line) option of CV cmd allows the effect of SO||~124NI~,||~124QR~
         (Japanese KANJI Shift-out) to continue to the next line for B2S(EBC->SJIS) conversion.||~124NI~,||~124QR~
         And, X2C(hex to chars) with EBC option do so always.          ||~124NI~,||~124QR~
        .M2B/B2M(EBCDIC<->Local-CP). Translation using external converter such as ICU/iconv.||~124QR~
        .M2M(AnyToAny). Transration from /F:charset to /T:charset.    ||~124QR~
        .SBCS mapping 0xe1->0x80 for Euro currency sign was dropped SJIS table.(not yet on MS932 now)||~124QR~
        .Accept NEC PC98 Kanji(0x87xx) as SJIS.                       ||~124QR~
       -3270 connection.                                              ||~124NI~,||~124NR~
        Now connection with S390 by tn3270 was tested.                ||~124NI~,||~124NR~
        TSO cmd, CV cmd was modified.                                 ||+124NI~,||~124NR~
        =6.dest is convenient way to open remote shell to TSO.        ||+124NI~,||~124NR~
        You can change keyboard to 3270 mode by hot-key,              ||~124NR~
        that enables more easy operation on SPF panel.                ||~124NR~
        Alt+z is assigned to the hotkey,it was previously assigned to ||~124NR~
        Cut & Paste function. You have to adjust ini file to avoid    ||~124NR~
        "duplicated key assignment" error if you are using ini file.  ||~124NR~
        And,A+q key at 3270 keyboard mode cahnges to TSO keyboard mode.||~124NI~
        Typed character is sent to 3270 one by one and cursor moves bt||~124NI~
        arrow key without shift modifier.                             ||~124NI~
       -NLS Spport.                                                   ||~124RR~
        .Support Korean and Chinese encoded file and IME imput.       ||~124RI~
         Linux console version requires ncursesW(Wide char version of ncurses).||~124RI~
         So, binaly offered is changed from RH9 compiled to FC5 compiled.||~124RI~
         I can only recognize Korean/Chinese glyph but can not understand,||~124RI~
         I'm waiting your experience reports.                         ||~124RI~
        .Now 3 byte Kanji(SS3(0x8f)+xxxx) and Hankaku-Katakana(SS2(0x8e)+xx)||~124RR~
         of EUC-JP is displayed.                                      ||~124RI~
       -CID append mode.                                              ||~124RI~
        Append option of CID cmd allows CID append mode.              ||~124RI~
        In append mode, new CID replace old CID only when those are not same value.||~124RI~
       -(Win) Support ENC format(\\server\sharefolder\file) filename. ||~124RI~
                                                                      ||~124RI~
     3.Miscellaneous.                                                 ||~7A23I~
       -(XXE)                                                         ||~124RR~
        .RGB value for gxe print is changed from 0x0000 to 0x404040   ||~124RI~
        .Displays cursor on the IME window.                           ||~124RI~
       -CrossHair cursor mode is now sticky over session restart.     ||~124FR~
       -"-m" option(continued reverse disply of found word) is also sticky.||~124FR~
       -new "-NB" option(skip taking temporary backup at file save operation)||~7B08I~
        for Save command.                                             ||~7B08I~
       -(LNX)display Japanese HANKAKU-KATAKANA character by EUC codepage as invalid character.||~124FR~
             (Those are 2 byte but the display width is 1 column.)    ||~8123I~
       -Re-evaluate the DBCS on the concatinated boundary after Join line command.||~8123I~
       -*\,**\,^*\ notification is available for the external command.||~8123I~
        External cmd is issued by DOS(abridgement:">") or =6 panel.   ||~124FR~
        No conversion takes when the word is enclosed by quotation.   ||~124RR~
        BUG of V124E was corrected("*\" is not effective on Dirlist panel).||~124RI~
       -Miss-spelling was corrected, "Hex-Vertical"--->"Hex-Vertical".||+124FI~,||~124FR~
        Your will get error msg "invalid ini file line" if using old ini file.||+124GI~,||~124GR~
       -On dir-list panel,leave rename field uncleared and unprotected when line cmd failed||~124GI~,||~124GR~
        to enable over-write the error.                               ||~124GR~
       -Dir-list "%" line cmd allows multi cmd concatinated by ";".   ||+124GR~,||~124GR~
       -Executes LOCate function by typing char key on the field just after line-cmd column||~124JI~
        to before the attr column on dir-list.                        ||~124JI~
        Until other than char key such as Esc is pressed,prefixing continues.||~124JI~
       -(UTF8 version) screen draw performance tuning.                ||+124MR~,||~124MR~
       -FLIp cmd was added as alias of XX cmd(reverse excluded and not excluded lines).||+124MR~,||~124MR~
       -Shift Up to =1/=2 panel by PATH-UP cmd(A+LeftArrow key) from  ||~124NI~,||~124NR~
        dir-list panel of root directory.                             ||~124NI~,||~124NR~
       -TAB cmd was changed,then skip counter is set to each file and saved to profile record.||~124NR~,||~124NR~
    	  TAB { on| off | clear | =default | nn [asdefault] }         ||~124NI~,||~124NR~
       -Linux Console version now also supports R-Ctrl key using      ||~124NI~,||~124NR~
        xmodmap cmd and keymap file setup.                            ||~124NI~,||~124NR~
        Likely S+Insert,S+PageUp etc is also available.               ||~124NI~,||~124NR~
        Cmd line parameter /Yrr is available to assign R-ctrl to Newline.||~124NI~
       -(UTF8 Version)                                                ||~124QR~
        .END/SAVe/CRE/REP/APP cmd has now [cplc|cpu8] option(translation at writeback to the file)||~124QR~
       -Cygwin consideration.                                         ||~124RI~
        "/" of 1st commandline parameter is not flag parameter but root directory id||~124RI~
         when env-var specifies TERM=Cygwin.                          ||~124RI~
       -(Win) C:\ may protected on Vista.                             ||~124RI~
        If workdir is not specified, search available drive(previously fixed to c:\).||~124RI~
       -LineDrawingCharcter input function(Default key assign ment:Alt+0 to Alt+9)||~124RI~
        Accept also DBCS Leadbyte on Linech config file.              ||~124RI~
       -Console version was tested on Linux/390(CentOS4.6/Debian5.0) on Hercules.||~124SR~
        (This means availability test of BigEndian version)                                                               ||~124RR~||~124SR~
     4.Tools.                                                         ||~7A23I~
       -xprint  v9.13                                                 ||~124GR~
        ./Mtx option print 3 line hex-dump.                           ||~7A23I~
        .(Lnx)gxe(Gnome Print Version) was added.                     ||~7A23I~
        .(Win/Gnome version) /Mtu option prints UTF-8 encoded file.   ||~7A23I~
        .(BUG)ABEND when print hex dump for UTF-8 encoded file.       ||~124GI~,||~124GR~
       -xcv     v1.12                                               ||+124FR~,||~124QR~
        .JapaneseEUC<-->UTF8 and Locale CodePage<-->UTF8 conversion are added.||~8123I~
        .(LNX)support any CodePage<-->UTF8 conversion using iconv.    ||~8123I~
        .(LNX:BUG)ABEND when input is stdin from pipe("|").           ||+124FI~,||~124FR~
        .For S2B(Sjis2EBCDIC),-Ss optionis added.                     ||~124NI~
         Absorb line length expansion by SO/SI insertion through following spaces.||~124NI~
        .New /Fn(FixedLRECL) option for B2x(EBCDIC->).                ||~124QR~
        .New /Mseteol(Write EndOfLine-ID) option for x2B.             ||~124QR~
        .(BUG)x2B may miss to set SO/SO insertion for DBCS.           ||~124QR~
        .new M2B/B2M(EBCDIC<->LocalCP) option to translate using ICU/iconv through /MF:mapfile.||~124QR~
        .new M2M(between any charset) option to translate from /F:charset to /T:charset.||~124QR~
       -xdc     v2.14                                                 ||+124FR~,||~124QR~||~124SR~
        .New /FT option to comapre file by text mode if size is not same.||~124QR~
         Consideration of difference of EndOfLineID.                  ||~124QR~
        .Linux/390 support(intermediate file by BigEndian)            ||~124SI~
       -xfmt    v1.3                                                  ||+124FR~,||~124QR~
        .P option(algnment by decimal point) mey be ignored.          ||~124QR~
        .Use single quotation if substring(to be searched in the field) contains ":".||~124QR~
       -xfs     v2.5                                                  ||+124FR~,||~124SR~
        .Gather subfiles from the dir of the control file             ||~124SR~
         if subfiles specified in the control file is not exist.      ||~124SR~
        .(BUG)Gather fail when the filename contains space.           ||~124SR~
       -xts     v1.5                                                  ||+124KR~,||~124KR~
        .Display File Creation-date(Win) or Change-date(Linux).       ||+124KR~,||~124KR~
        .New function to display current time, display elapsed time after repeated cmd execution.||+124KI~,||~124KR~
                                                                      ||~125AI~
  .v126:(2011/02/11)==v125K                                          ||~125GR~||~125KR~||~v126R~
     1.BUGs                                                           ||~125AI~
       -(LNX)Symbolic Link entry for directory is not moved by MOVe cmd.||~125AI~
       -(LNX)Console version; Cut&Paste block start sometime when mouse pushed.||~v125R~
       -Select line cmd ABEND if fullpath name length is over 240 byte.||~125AI~
       -ABEND at save from Alias cmd setting(=0.1) panel.             ||~125AI~
       -Hung at grep search(=3.14) if filename specification is missing.||~125AI~
       -DBCS input on line cmd field on dir-list panel executes locate cmd(scroll page).||~125AI~
       -cv cmd; "?" specification as error-replacing-char is not effective and help msg issued.||~v125R~
       -"s" line cmd on filename list panel(=1/=2 panel) drop option parm specified previously.||~v125I~
       -On dirlist panel, sort order by name is incorrect when symbolic linc entry exist.||~v125R~
       -exe cmd may abend when label option specified(ex. "exe * .a .b")||~v125I~
       -C comment starter/stopper(/*...*/) search by Alt+"." may fail.||~v125I~
       -C&P:split DBCS remains at margin boundary at paste operation. ||~v125I~
       -C&P:paste may abend when target region contains header line.  ||~v125I~
       -(WXE)UTF8 filename is printed as locale code when printing dirlist.||~v125I~
       -(LNX) for Linux BigEndian other than S390                     ||~125CR~
       -keybord reports unnessesary charcter 0x03 by AltGr.           ||~125CR~
       -file can not be save after whole update is undoed by the reason of file is not updated.||~125CR~
        If once save, it should be saved to back to the original.     ||~125CR~
       -key combination of AltGr(Right-Alt) and Alt(Left-Alt) dose not work.||~125CR~
        for ex, AltGr+"9" is "]" on "DE" kbd, and Alt+AltGr+"9" is not identified as Alt+"]".||~125CR~
        So, "word search" function is not triggered.                  ||~125CR~
       -(LNX) Scroll_Lock is not avail.                               ||~125CR~
        gxe now check Scroll_Lock status. Arrow key scroll screen by 1 column/row when Scroll_Lock ON.||~125CR~
        To activate Scroll_Lock key, following setup may be required. ||~125CR~
          xmodmap -e "add mod3 = Scroll_Lock"                         ||~125CR~
        mod3 is almost standard, but you have to check it using following cmd whether mod 3 is free.||~125CR~
          xmodmap -pm                                                 ||~125CR~
          (usualy mod1 is Left-Alt, mod5 is AltGr)                    ||~125CR~
       -If pallette number of Edit-file is same as one of Browse-file, no reverse box by C&P or Find word wasn not shown.||~125DI~
       -Hex Input box on top-left is disappear by cursor move.        ||~125DI~
       -Invalid match to DBCS for IFInd cmd on dir list               ||~125DI~
       -(wxe/gxe) wxp cmd ABEND when Horizontal and vertical HEX display mode.||~125FI~
       -Word search cmd(FWF/FWB/IWF/IWB).                             ||~125FI~
          When delimiter is multibyte string( xxx of "(xxx" ),        ||~125FI~
          if xxx is not found on the cursor line, word to be searched is from top of the line.||~125FI~
          It should be up to next/previous default delimiter such as space.||~125FI~
       -Shift line cmd hove to consider COBOL lineno column(col.1-6)  ||~125FI~
       -Hung by grep cmd if "&" is contained in the exptression.      ||~125GI~
       -"Valid_Ctrl_char" option of ini file was not effective.       ||~125GI~
        And defautt for 0x1a was changed Valid now.                   ||~125GI~
        0x1a is EOF for text mode read such as "type" cmd.(xe use binaly mode to read file)||~125GI~
       -For new version of Highlight by Mr.Andre Simon.               ||~125GI~
       -Paste to cmd input line crash when cusrsor is moved by keyboard operation.||~125GI~
       -"="(Compare) line cmd shows unmatch for TAB code(0x09) when comparing UTF8 file and locale code file.||~125KR~

     2.Additional function.                                           ||~125AI~
       -UTF8 Support.                                                 ||~125AI~
         .UTF8 encoded file is processed after translated to UCS2(16bit UCS) for windows version,||~125DR~
          UCS4(currently defined up to 0x10ffff:21 bit UCS) for Linux version.||~125DI~
          So, displayable range is expanded because not utf8-->locale code translation required.||~v125R~
          Then, xeu/wxeu/gxeu was discontinued.                       ||~v125I~
          Unicode input by hex notation and unicode synthesis by "u" key is supported.||~v125I~
          "u" key on hex code display line by HEX cmd synthesis 2 byte to one unicode.||~v125I~
          "v" key synthesis 3 byte to UCS4.                           ||~125DI~
         .UTF8 encoded filename can be accessed and manipulated.      ||~125AI~
         See chapter "UTF8 Support" on xee.txt.                       ||~125AI~
       -NLS support.                                                  ||~v125R~
         .(LNX).4 byte DBCS of GB18030 is displayed as 4 columns char followed by 2 column padding chars.||~v125R~
                To cotrol DBCS padding for file print, set WWScrPrt checkbox on Preview dialog.||~v125R~
               .set "ISO88591" or "C" for default charset when on the fullscreen console.||~v125R~
         .Ligature support.                                           ||~125CR~
            added Ligature option to setup dialog.                    ||~125CR~
            Use "OPT LIGATURE" cmd for console version.               ||~125CR~
       -CID copy option.                                              ||~125AI~
        .CID [COPYON|COPYOFF] : Set default CID copy option.          ||~125AI~
              COPYON:copy source line is copyed to target file with CID.||~125AI~
         (Note) Edit line cmd "AC"/"BC" means copy width CID for each "C"/"M" line cmd.||~125AI~
       -CV(Code conVersion) cmd.                                      ||~125AI~
        .f2e/e2f(UTF8<-->Japanese-EUC) option was added               ||~125AI~
       -RECORD Mode Edit cmd option.                                  ||~125FI~
        .Edit fiels with no EndOfLine ID.                             ||~125FR~
       -EBCDIC file support.                                          ||~125FI~
        .EBCDIC encoded file is maintained as it is without translation to locale codepage.||~125FI~
        .Hex display mode displays EBCDIC code.                       ||~125FI~
     3.Miscellaneous.                                                 ||~125AI~
       -(LNX:ConsoleVersion) When "meta mode"(code generation mode for Alt+char key press) is||~125AI~
                             "0x1b+CharCode" mode(another mode returns 0x80+char-code),||~125AI~
                             some Linux distribution(ex. FC10) returns only 0x1b for read API.||~125AI~||~v125R~
                             A 0x1b alone means Esc key press.        ||~125AI~
                             So,wait next input with some timeout value when 1 byte 0x1b was read.||~125AI~
       -(LNX) Delete cmd changed not to delete target of smbolic link but delete link only.||~125AI~
              It is dangerous if target is directory. for ex, Wine set simbolic link to DOS partition.||~125AI~
       -Word search(A+[ and A+]) detects Japanese DBCS delimiter chars.||~125AI~
       -(Win:GUI version) Other CharSet is slectable from ComboBox.   ||~v125R~
       -Tested on Windows7.                                           ||~125CR~
       -"S"(split) line cmd replace DBCS to 2 space when the DBCS is split.||~125DI~
        When cursor is on the Hex line(vertical hex display mode),space replacement is not be done||~125DR~
        like as line split by Shift+Enter key.                        ||~125DI~
       -HEX cmd new option to move cursor zigzag.                     ||~125DI~
          HEX [ On | Off | YZ | NZ ]                                  ||~125DI~
            YZ:When cursor is on hex line of vertical hex display mode,||~125DI~
               cursor moves to like as upper-->lower-->upper of next column after char input.||~125DI~
               Even if CharacterInsertMode, input on lower line replace the hexdigit||~125DI~
               on the cursor without inserting new character.         ||~125DI~
            NZ:back to usual cursor move mode.                        ||~125DI~
       -END/SAVe/REPlace/CREate cmd.                                  ||~125FI~
        register CPxx（file encoding)option to profile.               ||~125FI~
       -"p"(Print) directory list line cmd get encoding from profile. ||~125FI~
       -P[0|1] (margin area protection) option of EDIt cmd is registered to profile.||~125FI~
       -64bit support(Tested only by Linux version)                   ||~125GI~
                                                                      ||~125AI~
     4.Tools.                                                         ||~125AI~
       -xeacb   v1.2                                                  ||~v125R~
        ./U option to process UTF8 encoded file.                      ||~125AI~
        .(LNX:BUG) Hankaku-Katakana(Japanese glyph) is not displayed. ||~125AI~
        .(BUG)look when long line is split by screen width at the point of invalid DBCS.||~125AI~
       -xcv     v1.15                                                 ||~125FI~||~125GR~
        .B2E/E2B/B2B(EUC,EBCDIC<-->EBCDIC) translation option is added.          ||~125FI~||~125GR~
       -xds     v1.7                                                  ||~125KR~
        .(BUG)Invalid free space percentage is shown.                 ||~125KR~
       -xfc     v1.17
        .(BUG) Miss to search unmatch when both /W (Ward compare) and /M (Margin) is specified.||~125AI~
        .(BUG) Warnig is issued when CR/LF is missing at EOF.         ||~125AI~
       -xprint  v9.20                                                 ||~125KR~
        .(Win,gxp) Add /Cmax option to get print page width by the longest line.||~125AI~
        .Use "/Mu /Mtx" option for Vertical Hex dump of UTF8 file     ||~125DR~
        .new /N8 option to print unicode hex code for 3 line hex dump mode for UTF8 file.||~125KR~
         Default(/Y8) is printing by UTF8 hex code for UTF8 file.     ||~125KR~
         Preceding x'00' of ucs code may not be printed to adjust column when /N8 option specified.||~125KR~
            ex) xprint utf8-file -mtxu -n8                            ||~125KR~
        .EBCDIC file support.                                         ||~125FI~
        .(gxp)Accept CUPS printer as destination.                     ||~125GI~
         Partial string is allowed for -q option.                     ||~125GI~
         1st matched printer is selected from CUPS printer list.      ||~125GI~
         ex). xprint file1 -qEpson-LP1400                             ||~125GI~
        .(BUG)"Invalid Name Format" err when indirect option(-Yi) is specified.||~125KR~
                                                                      ||~125AI~
######################################################################
  .v126L<--A:(2013/05/21)                                             ||~126HR~||~126LR~
     1.BUGs                                                           ||~126BR~
       -Correct Version Number.                                       ||~126BR~
       -LinuxVersion, generate core at termination weh "%"/"#" line cmd was used on dirlist.||~126BR~
       -Crash may occur when screen height is decreased under 24 lines.||~126BR~
       -Line selection by mouse double click fails for below the "3 UTILITY" line on top menu.||~126BR~
       -Edit line cmd "TF" may insert not space but null(x"00").      ||~126BR~
       -For the case wildcard character(*?) is displayed on dirlist,  ||~126BR~
        (it may be the case showing Windows VFAT partition on Linux)  ||~126BR~
        delete line cmd should be rejected for this line..            ||~126BR~
       -Crash mey occur if system dose not support CP037.             ||~126BR~
        In this case, translate using internal CP037 translation table.||~126BR~
       -Loop may occur at UTF8 translation if the file contains invalid character.||~126BR~
       -(Linux)crash when ICU mode is specified on EBCDIC trans cfg file(xeebc.map).||~126DI~
       -(Linux)command input line cursor positioning error if UTF-8 and||~126DI~
               some EUC code(hankaku-katakana, 3 byte extended code) is mixed.||~126DI~
       -FTP Remode Access                                             ||~126FI~
         .(Linux)Crash when file-spec contains wild-card.             ||~126FI~
         .(Linux)err msg of "privilege=0" for mkdir with chmod mask option.||~126FI~
         .Max string length of HostID on ::xehost was 7, changed to 8.||~126FI~
         .xdd did not delete sub-dir on remote.                       ||~126FI~
       -CV command:ASCII character remains not translated for M2F under not Japanese environment||~126GI~
       -(WXE)menu:SaveAs requests replace confirmation even for new file.||~126HR~
       -Select command without member specification fails if the only one member's name is space embeded.||~126HR~
       -EBCEDIC file conversion crashes if it contains lines with legth=0||~126HR~
       -word highligtening by FWF/BWF(Alt+"["/Alt+"]") distubed by pair search(Alt+".")||~126HR~
       -start of s3270 connection is not stable.(sleep 1 second to wait 3270 process startup)||~126HR~
       -(LNX)crash for too long path(max pathlen was expanded from 512 to 4096)||~126HR~
       -(XXE)null(0x00) is displayed by alternative char on 1,2,3.12 and 3.14 panel.||~126HR~
       -Hung by "F *u"/"F *e" cmd after "F *\n"                       ||~126JR~
       -CV B2B cmd; translation error lines ware not highlightened.   ||~126JR~
       -CV B2B cmd; DBCS translatation was not valid.                 ||~126JR~
       -SyntaxHighlight was not effective for the file contains NULL character.||~126JR~
       -Crush if file fullpath name is too long(about 4k byte over)   ||~126JR~
       -"Shift+F10" on dirlist(dispaly file contents) will cause crush.||~126JR~
       -Crush by "Ctrl+W"(copy the word to cmd input line) when the word is too long.||~126JR~
       -"Alt+W"(copy the word to clipboard) on EBCDIC file dismiss SO/SI.||~126JR~
       -(Linux)It may crash if cups is disabled                       ||~126KR~
       -It may crash if line with line cmd is deleted on screen split status.||~126LI~
                                                                      ||~126BR~
     2.Additional function.                                           ||~126BR~
       -Android version(New).                                         ||~126BR~
       -CVコマンド                                                    ||~126FI~
        .Additional conversion type of B2F/F2B(EBCDIC<-->UTF8)        ||~126FI~
        .supports ICU option for M2M translation.                     ||~126GR~
       -You can set volatile password for remote host defined on ::xehosts.||~126FI~
        command: NODe host-id password (ex. "nod ftpsvr1 CabZyx")     ||~126FI~
       -(Linux)remote access using Samba(smbclient).                  ||~126FI~
        For the case you have no privilege to mount shared resource,  ||~126FI~
        register remote (Samba or Windows) server in ::xehosts.       ||~126FI~
          ex)  "w764  192.168.8.22 usrskt pswd  share=sharename       ||~126FI~
        share parameter means to use smbclient to acess the remote system.||~126FI~
       -(Wxe)Open file dialog supports file type filter.              ||~126HR~
             menu:NewFile opens not tempfile but file dialog.         ||~126HR~
       -(Win)new WTL/ATL(without MFC) version compiled on vs2010Express(x8632 and amd64).||~126HR~
             vs2010 debugger breaks if un-initialized variables are detected,||~126HR~
             all "un-initialized valiable" warning was squeezed.      ||~126HR~
       -REDo function                                                 ||~126JR~
        Ctrl+F2 is assigned to REDo as default.                       ||~126JR~
       -SPLit/TFlow cmd                                               ||~126JR~
        supports Hex Notation for delimiter(SBCS only)                ||~126JR~
       -Edit/Browse cmd                                               ||~126JR~
        Additional option FN{U8|LC|AS} for dirlist filename encoding. ||~126JR~
        It is recorded to profile, so use FNAS to reset it            ||~126JR~
        and then command line parameter /UN{8|L} is effective.        ||~126JR~
                                                                      ||~126JR~
     3.Miscellaneous.                                                 ||~126BR~
       -(Lnx)consideration for compiler warning                       ||~126CR~
             "-Wno-pointer-sign"(from gcc v4.x), "-Wno-unused-but-set-variable"(from gcc 4.6)||~126CR~
       -Default EBCDIC mapping was changed from S3270 definition to s390-standard:IBM-37,swaplfnl(Control charcter and CR/LF)||~126DR~
        s390 standard CR/LF is  x25<->x85, x15<->x0a.                 ||~126DI~
       -ICU_DATA option is added to EBCDIC cfg file.                  ||~126DI~
        specify folder contains your specific converter(xxx.cnv file) ||~126DI~
        Create sub-folder icudt__l, copy cnv file into subfolder.     ||~126DI~
        Specify folder containis the sub-folder.                      ||~126DI~
       -(Win) "Invalid Name Format" err msg when UNC format file spec is "\\server\sharename"||~126FI~
              (assume as "\\server\sharename\*")                      ||~126FI~
       -dirlist cmd "z"/"0"                                           ||~126HR~
        When "opt delz off", not only issue warning but actualy disable to delete.||~126HR~
       -(Win:console)dirlist cursor hight is changed 10% to 15% of line height.||~126HR~
       -(Win)API:FileTimeToDosDateTime rounds up odd seconds to next even number of seconds.||~126JR~
             xe displays round down value like as command prompt                                ||~126DI~||~126JR~
       -replace by subchar for the character could not be translated by the cmd "CV B2B" uses ICU.||~126JR~
                                                                      ||~126JR~
     4.Tools.                                                         ||~126BR~
       -xcv     v1.18 :CodeConversion                                 ||~126GR~
        .B2F/F2B(EBCDIC<-->UTF8) option was added.                    ||~126DI~
        ."-ICU" was added. Alternative of mapping file option(-m:mapfile) for B2x/x2B(x:B/M/F).||~126DI~
         Specify EBCDIC codepage on "-CPEB:cp" option.                ||~126DI~
           ex) xcv x1ebc -cB2F -icu -cpeb:cp930                       ||~126DI~
        .ICU option for M2M translation.                              ||~126GI~
        .-List was added to list converters supported by ICU.         ||~126DI~
         On Windows, lists Windows codepages when ICU option is not specified.||~126DI~
       -xdc     v2.19 :Directory compare                              ||~126GR~||~126JR~
        .(BUG)/L[nn] option(Long Filename) is ignored for NTFS partition.||~126BR~
        ./FC option is added. It calles file compare tool(default:xfc) if path is same.||~126BR~
        .(Linux) Compairs userID/groupID.  -Uu option selects unmatched line of UID/GID.||~126GI~
        .(Lnt/WinNTFS)compare timestamp by precision of not 2 sec but 1 sec.||~126JR~
        .display "(" or ")" when timestamp difference<=2 seconds.     ||~126JR~
        .new Option to adjust time stamp by TimeZone                  ||~126JR~
       -xds     v1.8  :Display directory size                         ||~126BR~
        .(BUG)Error message "dword and dword" is issued at last disk usage percentage calculation.||~126BR~
       -xprint v9.23                                                  ||~126CR~||~126HR~||~126KR~
        .(Win:BUG)Font size may be decreased gradually when multi-file print.||~126CR~
        .(Win)Use not c: but %TMP for workfile for reverse page print(C: may be protected)||~126HR~
        .(Linux:BUG)It may crash when cups is disabled.               ||~126KI~
       -xts     v1.6 (display/change file's last modified time)       ||~126JR~
        .(Linux/Win NTFS)Process odd number value of seconds.         ||~126JR~
                         (For VFAT round up to next even number of seconds)||~126JR~
       -xff     v1.6 (File Search by TimeStamp/Size/Name)             ||~126JR~
        .display timestamp by not unit of 2 sec but 1 sec             ||~126JR~
       -xci     v1.0  (C/C++/Java text file indentation) was added.   ||~126JR~
######################################################################||~126BR~
  .v127S<--v127:(2015/03/10)                                          ||~127SR~
     1.BUGs                                                           ||~127AR~
       -(Axe)"sbcs tbl overflow" msg on Nexsus7(api14) by the reason of Hangle char print width.||~127AR~
       -(Axe)terminate by hardkeyboard on/off.                        ||~127AR~
       -(Axe)accept touch on background when xe keboard is up.        ||~127AR~
       -"END /Mr"(save as RECFM=F) missed to write lines of length=0. ||~127BI~
       -miss-translation at EBCDIC file with CPEB --> Locale code file.||~127BI~
       -display as translation error for lines containing DBCS at copy non-EBCDIC lines into EBCIDIC file.||~127BI~
       -Cut&Paste into non-EBCDIC file may insert SO/SI around DBCS.  ||~127BI~
       -XPRint cmd for RECFM=F, -Rnn parameter was missed.            ||~127BI~
       -For UTF8 encoded FixedLengthRecord file,when UTF8 string length exceeded recordlength by update||~127BI~
        overflowed string shifts all following lines at save.         ||~127BI~
       -Page ejected by 0x0c at "XPRint **/***"(Screen print).        ||~127BI~
       -Screen print was invalid if screen was shifted to right.      ||~127BI~
       -Screen print of hex dump of EBCDIC file, lower letter was printed as katakana on Japanese environment.||~127BI~
       -When opend RECFRM=F of profile file with /Mh(HexDump) option, display width was ones of LRECL.||~127BI~
       -COPy cmd did not translated EBCDIC DBCS if xeebc.map did not defined DBCS converetr.||~127BI~
       -(LNX)glibc implementation was changed, which exposed bug of memcpy usage||~127CR~
        in case of source area and destination area is overlap.       ||~127CR~
        It was actually safe for forward copy until the change.       ||~127CR~
       -(Axe)Display valid keycode also when flick operation on soft keyboard.||~127CR~
                                                                      ||~127AR~
       -(LNX)Could not process the file if filename contains parenthesis "(" or ")" .||~127DI~
       -Code page option such as CPU8,CPEB could not specify as command line parameter.||~127DI~
       -Dir list line cmd "%" fails if filename contains space(" ").  ||~127DI~
       -Corrupted filename on header line if filename is encoded by UTF8.||~127DI~
       -(wxe)wxp command was not effective.                           ||~127DI~
       -"xpr *", "xpr **" fails for fixed/variable record file.       ||~127DI~
       -(LNX)When Global Menu is active on Ubuntu13.4 etc.,           ||~127DI~
        window shrinks to min-size and could not be expand.           ||~127DI~
                                                                      ||~127DI~
       -Lineno mode was Hex Offset for Fixed Record Mode(/Mr) file.   ||~127ER~
       -Ctl+charkey was not effective when duplcatedly assinged for diffrent screen type.||~127ER~
       -Read failed for MicroFocus format variable record length file(-Mv -Fmf) after once savd.||~127ER~
       -Crashes when opening director having too many members.        ||~127ER~
        Max member is expanded from 3,744 to about 43,000 for 32bit version.||~127ER~
        Specify wildcard when open was rejected by too many members.  ||~127ER~
       -Target err was displayed for simbolic link of remote entry when using FTP.||~127ER~
                                                                      ||~127ER~
       -(Win)UTF8 surrogate pair range was not processed.             ||~127GI~
                                                                      ||~127GI~
       -(LNX)crash on xterm or console of runlevel:3 when displaying dir-list containing Japanese filename encoded by UTF8.||~127HI~
                                                                      ||~127HI~
       -(LNX)gxe:crash when gtk3 is selected and gtk3 version<3.6     ||~127JI~
                                                                      ||~127JI~
       -(LNX)Japanese EUC translation changs byte count for some codepoint||~127LI~
       		 for other language.                                      ||~127LI~
       		 In that case redundant space is displayed on dir-list.   ||~127LI~
       -On =3.12 (File Compare) panel,DBCS char deletion was done byte by byte.||~127LI~
        The DBCS display was corrupted.                               ||~127LI~
       -(gxe)Filename on PrintDialog was corrupted when filename encoding is not utf8.||~127LI~
       -A TC command format of "TC filed+/keyfield" (CotrolBreakSummary) may crash||~127LI~
        if duplicatedly executed.                                     ||~127LI~
       -Alt+W(copy word to clipboard) on dir-list is invalid when filename encoding is||~127LI~
        4 byte DBCS of GB18030.                                       ||~127LI~
                                                                      ||~127LI~
       -(Win:64bit)Crash when cmd operand error under UTF8 input mode(Alt+u).||~127MI~
       -(Win)UNC(\\server\share pattern) format filename.             ||~127MI~
             .open failed when pathname is missing                    ||~127MI~
             .error msg "GetDiskFreeSpace failed" was issued.         ||~127MI~
       	　　 .Timestamp on directory list was invalid for intermediate path name.||~127MI~
             .LOCate cmd on directory list failed.                    ||~127MI~
       -(Win)corrupted directory list when OPT LFN=N(8.3 filename mode)||~127MI~
       -(Win)"NoTargetExist" sign on dirlist if symbolic link target is set by relative path.||~127MI~
       -FINd cmd may fail on filename list(=1/=2) panel.              ||~127MI~
       -(wxe)PrintPreview dialog box was not redrawn when the focus was lost.||~127MI~
       -Before updated file writeback,the file is backuped in the directory for the||~127MI~
        unpredictable crash at writeback operation.                   ||~127MI~
        At writeback completion the backup file is removed.           ||~127MI~
        When writeback failed by the reason of,for ex, UAC protection,||~127MI~
        backup was remained. The  renamed backup may out of UAC, it should be removed.||~127MI~
        Check also "NB" option of EDIt cmd, "BK|NB" option of END cmd.||~127MI~
        You can control backup operation by this option.              ||~127MI~
       -UTF8/EBC data was translated to locale code when paste to file opened as binary file.||~127MI~
                                                                      ||~127MI~
       -Refresh command(S+F1) crashes when symbolic link was updated out of xe||~127PI~
        while the dirlist is opened.                                  ||~127PI~
       -(Axe)handle JNI crash.                                        ||~127PI~
       -(Win)reserved name file such as "prn","com" is now deletable. ||~127PI~
                                                                      ||~127PI~
       -For /o option of EDIt/BROwse cmd, it could not specifiy the value over 4GB.||~127QI~
       -(Win:64bit) It may crash when EBCDIC translation.             ||~127QI~
       -(Linux:64bit)errournours result for double word calc(bc cmd, tool:xbc).||~127QI~
       -(64Bit) CPEB option of CV cmd was rejected.                   ||~127QI~
       -Find key(F5 or S+F5) may cut last 2 byte of search word placed on command input line.||~127QI~
       -RECFM=V file is broken at save if there are split record.     ||~127QI~
        (LRECL over display width by /M (default is 9999) is displayed as multiple split lines.)||~127QI~
       -4 bits record type on record header of MicroFocus RECFM=V file was replaced||~127QI~
        to 4(Standard Data Record) except top header record.          ||~127QI~
       -Scroll function specified Max crashes if the file max line length < screen width.||~127QI~
       -For partial edit with offset parameter and Save command with filename parameter||~127QI~
        (EDIt file1 oxxx-yyy + SAVe file2),                           ||~127QI~
        if SAVe cmd repeated, the record at the 2nd offset boundary will be broken.||~127QI~
                                                                      ||~127QI~
     2.Additional function.                                           ||~127ER~
       -Symbolic Link(JunctionPoint/MountPoint also for Windows) consideration.||~127AR~
        Copy command copies not actual file/dir but pointer as default,||~127AR~
        actual file with -Lt option.                                  ||~127AR~
        Delete command deletes pointer only.                          ||~127AR~
       -RECFM=V support.                                              ||~127BI~
        .Supported record header format is as followings.             ||~127BI~
          2/4 byte containing/not containing header length itself, RDW(4 byte LLZZ),||~127BI~
          Microfocus format(system record on the top of file indicates 2 or 4 byte header)||~127BI~
        .Once opened with "/Mv /Fvfmt" option, it was saved to internal "profile" record,||~127BI~
         that is referred at next open.                               ||~127BI~
         You can set the option to a directory which is applied to all member.||~127BI~
         XPRint cmd also refers the profile to set xprint utility parameter setting.||~127BI~
                                                                      ||~127AR~
       -(gxe)Ligature option on Preview dialog.                       ||~127DI~
       -(gxe)Shift support on Preview dial;og.                        ||~127DI~
             ex). Top:3510 means 10mm top margin with 35mm shift to upper direction.||~127DI~
       -"$" line command on dirlist panel.                            ||~127DI~
        Async version of "%" command(xecute command on rename field with parameter of the file on the line).||~127DI~
                                                                      ||~127DI~
       -User command(shortcut,Alias) supports parameter replacing by %*, %^, %@.||~127ER~
        %*:fullpath name of currently opened                          ||~127ER~
        %^:fullpath name of currently opened on other split screen.   ||~127ER~
        %@:all remaining unused %n parameters up to the point.        ||~127ER~
                                                                      ||~127ER~
       -(LNX)gtk3 support.                                            ||~127HI~
        .make on gtk3 if gtk3 was installed.                          ||~127HI~
        .Use "./configure --enableg-gtk3=no" to make on gtk2          ||~127HI~
         under the environment of both gtk2 and gtk3 is installed.    ||~127HI~
        .(On Debian jesssi 3.12.1; libatpsi2.0-dev may be required to install additinally to gtk+-3.0)||~127HI~
                                                                      ||~127HI~
       -Supports Ctl+W(copy string to command line) also on dir-list. ||~127LI~
                                                                      ||~127LI~
       -(Win)Filename not by current locale code can be processed.    ||~127MI~
             (Glyph for the unicode over 0xffff depends your environments.)||~127MI~
             By changing to direct unicode input mode(XIN cmd:Ctrl+F11),||~127MI~
             3 byte unicode input is available by typing vxxxxxx.     ||~127MI~
       -Now available to paste to rename field on dirlist panel.      ||~127MI~
       -FINd cmd, new option "U4" to search not 2 byte ucs but 4 byte ucs||~127MI~
        This is required for each word if &(AND) serach.              ||~127MI~
          (ex). f Micro U4 UL & Vender U4 UL                          ||~127MI~
                                                                      ||~127QI~
       -Issue confirmation msg for large file when open.              ||~127QR~
        Limit is specified on ini file.                               ||~127QI~
			LargeFileSize(MB) =1    #(100)# Size of large file to issue warning when open, 0 means no limit. ||vazd||~127QI~
        Default is 100MB for 32 bit OS, 1GB for 64 bit OS.            ||~127QI~
                                                                      ||~127MI~
     3.Miscellaneous.                                                 ||~127AR~
       -(Axe)ACRA(crash report) function is added(mail to developer). ||~127AR~
       -Copy modified time for also directory by XCOpy cmd.           ||~127AR~
       -"END /F0" reset LRECL of RECFM=F of the file's profile.       ||~127BI~
       -Commandline option /F was change to /FTP to enable to specify ||~127BI~
        /F edit command option on commandline parameter.              ||~127BI~
       -For Fixed Record Length File opened with /Fxx only, replace TAB(0x09) by SPACE(0x20) at save.||~127BI~
        For Record mode file(opened with /Mr /Fxx) preserve TAB at save.||~127BI~
       -(LNX)Changed to alternative way for deprecated API(gdk_pixbuf_unref,XKeycodeToKeysym).||~127CR~
                                                                      ||~127AR~
       -(gxe)Changed API for print to use not gnomeprint but GTKprint.||~127DI~
             (debian jessie removed gnomeprint package)               ||~127DI~
                                                                      ||~127DI~
       -(Win)On dirlist,member name containing "?" may be processed with following exception.||~127ER~
        It could not be yet processed those files that could not be processed||~127ER~
        as "\\?\d:\fullpath" format on dos prompt.                    ||~127ER~
        It could not be processed if Windows settings prohibit 8.3 format filename.||~127ER~
        It could not be processed File contains "?"(0x3f) which was created on Linux.||~127ER~
        (Linux replace "?" to "_" for saving file for Undo)           ||~127ER~
       -For PuTTY 0.63.                                               ||~127ER~
        .Accepts 0x1b+(Modifier+)Fn.                                  ||~127ER~
        .Added as Default Esc string for Keyborad type:SCO.           ||~127ER~
         Shift+Fn,Ctrl+Fn is available.                               ||~127EI~
         To inactivate this setting, use --NOSCO option.              ||~127EI~
         And SCO assigns ^[Z to S+F2, it is duplicated to previous assign ment to S+Tab.||~127EI~
         Use --Z2 option to use ^[Z to S+F2.                          ||~127EI~
                                                                      ||~127ER~
       -(LNX:gxe)Labels on toolbar icons were removed.                ||~127HI~
       -(LNX:gxe)xfce4-terminal is added as terminal-emulator to execute internally linux native command on it.||~127HI~
                 Terminal-emulator is used when open child shell by "Terminal" toolbar icon.||~127HI~
                 To use other than gnome-terminal,xterm,rxvt,konsole and xfce4-terminal,||~127HI~
                 specify it on ini file option LNX_ShellTerm_gxe/LNX_CmdTerm_gxe||~127HI~
       -(LNX:gxe)Commandline option not to use geometry_hints("--gh=N") is added||~127HI~
                 This is to avoid that windows size automatically shrink to small window.||~127HI~
                 xe use gtk_window_set_geometry_hints(GTK_HINT_RESIZE_INC) to adjust window size to||~127HI~
                 multiple of char size.                               ||~127HI~
                 But some version of disto/gtk(Kubuntu 12.04:gtk 3.4.12, Kubutu 13.11;gtk 3.8.6) requires this option.||~127HI~
                                                                      ||~127GI~
       -Issue warning when executed on command-prompt with CHCP=65001(UTF8)||~127LI~
        CPU8 option enables to view UTF8 encoded file.                ||~127LI~
                                                                      ||~127LI~
       -For XCOpy /c cmd, wildcard target name was processed not as rename of each member||~127MI~
        but as rename of target top directory.                        ||~127MI~
       -(LNX)iconv:eucJP translates some part of u-80<-->u-ff to japanese-hankaku-katakana(3byte euc code),||~127MI~
             but xe translate to "?" in such case.(hankaku-katakana is assigned at u-ffxx range)||~127MI~
       -CV cmd/XCV utility outputs surrogate pair for over u-ffff when "F2U" without "UCS4" option.||~127MI~
                                                                      ||~127MI~
                                                                      ||~127QI~
       -Use not read but seek api for positioning to the specified offset by /o option when binary open mode(/Mb).||~127QI~
       -When SAVe cmd with destination filename is failed by such as Disk full,||~127QI~
        close it as to delete from out of xe session.                 ||~127QI~
       -Expanded record display width from 9999 to 32760.             ||~127QI~
       -Set margin=4095 to file of MicroFocus RECFM=V with 2byte record header.||~127QI~
       -Delete directory list cmd chk the file is opend elsewhere.    ||~127QI~
                                                                      ||~127QI~
     4.Tools.                                                         ||~127AR~
       -xprint  v9.30                                                 ||~127BI~||~127LR~||~127MR~
                                                                      ||~127DI~
          Use not xprint but gxp on Linux.                            ||~127DI~
          Sample print cmd:xprint.sh(default on Linux) was changed to use gxp.||~127DI~
                                                                      ||~127DI~
        .Symbolic Link(JunctionPoint/MountPoint for Windows) consideration.||~127MI~
        .RECFM=V support                                              ||~127BI~
        ./ICU was added to enable to use ICU converter without /BC(cfg fiel for EBCDIC translation).||~127BI~
        .(BUG:LINUX) miss-translated for EBCDIC and UTF8 files.       ||~127BI~
        .(BUG)Line length error when RECFM=F file contains 0x15(EBCDIC newline).||~127BI~
                                                                      ||~127DI~
        .(gxe)Changed API for print to use not gnomeprint but GTKprint.||~127DI~
        .(gxp)Shift parameter support. ex). -E/B5/T40.                ||~127DI~
        .(gxp)Destination parameter:"-q?" lists printers.             ||~127DI~
        .(gxp:BUG)Crash when wildcard filename is not enclosed by double quotation.||~127DI~
        .(gxp:BUG)Line was cut if it contains null(x00).              ||~127DI~
        .(gxp:BUG)Japanes EUC code was not printed.                   ||~127DI~
                                                                      ||~127DI~
        .(BUG)UCS 2nd byte was not printed for utf8 file with -n8 and -mtx options.||~127DI~
        .(BUG)For EBCDIC file,2nd line was invalid when the line is split.||~127DI~
                                                                      ||~127DI~
        .(LNX:BUG)It could not change option such as PaperSize/Orientation on print dialog by -Yd option.||~127HI~
        .(LNX:BUG)A4 was assumed as default paper for all printer.(ignored printer setting)||~127HI~
        .(LNX:BUG)Printer specification by -Q option may fail by error of multiple printer match with the parameter.||~127HI~
        .(LNX)gtk3 support.                                           ||~127HI~
        .(LNX)margin parameter is added. -E/form/M{T|B|L|R}ss[P].     ||~127HI~
                                                                      ||~127JI~
        .(LNX)Japanese help text was corrupted on xterm.              ||~127JI~
                                                                      ||~127HI~
        .(Win)accept request from xe with parameter filename of not localecode(utf8 encoded).||~127MI~
                                                                      ||~127MI~
       -xff v1.7                                                      ||~127ER~
        .Symbolic Link(JunctionPoint/MountPoint for Windows) consideration.||~127MI~
        .New -Bw option lists files which name contains wildcard id("?"/"*").||~127ER~||~127MR~
       -xfc v1.24                                                     ||~127HR~||~127QR~||~127RR~||~127SR~
        .Supports Fixed/Variable record length file.                 ||~127ER~||~127MR~
        .(Win)accept request from xe with parameter filename of not localecode(utf8 encoded).||~127MI~
                                                                      ||~127RI~
        .(BUG) miss to check unmatch of last bayte of record when record mode.||~127RI~
        .(BUG) crash when margin parameter(/M) is out of record.      ||~127RI~
        .(BUG) margin is limited to default:4096 even when max record length(/L) is specified.||~127RI~
        .convenient filename specification using character "=".       ||~127SI~
       -xdd v1.9                                                      ||~127MI~
        .(Win)accept request from xe with parameter filename of not localecode(utf8 encoded).||~127MI~
       -xdc v2.25                                                     ||~127MI~||~127SR~
        .Symbolic Link(JunctionPoint/MountPoint for Windows) consideration.||~127MI~
         Shows '@' for target name unmatch.                      ||~127AR~||~127MI~
        .(Win)accept request from xe with parameter filename of not localecode(utf8 encoded).||~127MI~
        .convenient filename specification using character "=".       ||~127SI~
       -xlow v1.5                                                     ||~127MI~
        .Symbolic Link(JunctionPoint/MountPoint for Windows) consideration.||~127MI~
       -xfg v1.12                                                     ||~127MI~
        .Symbolic Link(JunctionPoint/MountPoint for Windows) consideration.||~127MI~
       -xdig v1.10                                                    ||~127MI~
        .Symbolic Link(JunctionPoint/MountPoint for Windows) consideration.||~127MI~
       -xds v1.9                                                      ||~127MI~
        .Symbolic Link(JunctionPoint/MountPoint for Windows) consideration.||~127MI~
                                                                      ||~127QI~
       -xcv v1.19                                                     ||~127QI~
        .(BUG) /List option rejected if conbined with /ICU (listing of ICU converter)||~127QI~
######################################################################||~v128I~
      (Summary of update of V127)                                     ||~v128M~
           -Symbolic Link(JunctionPoint/MountPoint also for Windows) consideration.||~v128M~
           -RECFM=V support.                                          ||~v128M~
           -(LNX)gtk3 support.                                        ||~v128M~
           -Supports Ctl+W(copy string to command line) also on dir-list.||~v128M~
           -(Win)display Filename of foreign language by unicode.     ||~v128M~
           -FINd cmd, new option "U4" to search not 2 byte ucs but 4 byte ucs||~v128M~
           -For PuTTY 0.63, additional function key by modifier+Fn key combination.||~v128M~
           -Expanded record display width from 9999 to 32760.         ||~v128M~
                                                                      ||~v128M~
######################################################################||~v128R~
  .v128C <--v127S:                                        (2016/06/24)||~128ER~
   v128D <--v128C:                                        (2016/08/25)||~128EI~
   v128E <--v128D:                                        (2016/09/08)||~128EI~
   v128F <--v128E:                                        (2016/12/20)||~128FI~
   v128G <--v128F:                                        (2017/02/02)||~v128R~||+v129R~
   v128H <--v128G:                                        (2017/02/12)||+v129R~
   v128K <--v128H:   =v129                                (2017/03/29)||+v129R~
     1.BUGs                                                           ||~v128R~
       -(Win)Copy command(XCOpy and "c" directory line command) failes||~v128R~
        if the directory contains special file name such as prn or com1.||~v128R~
        Especially hung for AUX and COMx.                             ||~v128I~
        (Waring) xe is now able to process reserved filename,         ||~v128I~
                 but when external cmd such as grep is used on =6 panel,||~v128I~
                 you may need to break(Ctrl+C) xe session.            ||~v128I~
                 For wxe, use Ctrl+C on DOS prompt:xesyscmd           ||~v128I~
                 to break command response wait.                      ||~v128I~
                 The cmd may waiting user interaction,                ||~v128I~
                 use Ctrl+C in that case.                             ||~v128I~
       -(Win)New file created by SELect command was inserted to TOP   ||~v128I~
        of the directory list.                                        ||~v128I~
       -XMOve cmd ignores /y (replace same name)                      ||~v128I~
                                                                      ||~v128I~
       -Under not Japanese envirinment,                               ||~v128I~
        crashes for invalid line command on directory list panel.     ||~v128I~
                                                                      ||~v128I~
       -Corrupted disply on dirlist rename field if DBCS or UTF8 code is included.||~v128I~
       -On dirlist,cmd may fail if wildcard('*','?') is specified with||~v128I~
        DBCS or UTF8 code.                                            ||~v128I~
       -On dirlist, display expanded cmd("-",">") fails.              ||~v128I~
       -On dirlist, paste on rename field may cause corrupted display.||~v128I~
       -On dirlist, xe may crash/loop by rename cmd if invalid code is on rename filed.||~v128I~
                                                                      ||~v128I~
       -(wxe)Update on Setup/Preview dialog was not save if not terminate from menu.||~v128I~
       -Sort cmd on dirlist mau cause crash.                          ||~v128I~
       -Charcter and hex line position unmatch on vertical hex dump display mode of CPU8 file,||~v128I~
        (Update on hexline changes character of not corresponding posion)||~v128I~
       -Auto renumbering of SPF file dose not work in some case.      ||~v128I~
       -Line overflow error by Alt+m(move by cut & paste) even when in the same line||~v128I~
        for fixed length record file.                                 ||~v128I~
                                                                      ||~v128I~
       -(Win)Corrupted screen when the width is odd number of colomns.||~v128I~
       -(WIN)Bugs for UCS4(unicode>u-ffff)                            ||~v128I~
     (128C)                                                           ||~128DI~
       -(Lnx)Timestamp of directory list of floppy disk was invalid   ||~128DM~
        when floppy disk was not mounted and mtools was used.         ||~128DM~
       -(Win)On directory list,display column position was invalid when Ligature:Off.||~128DM~
       -LOCate cmd failed when the directory list was opened using wildcard.||~128DM~
     (128D)                                                           ||~128EI~
       - '@' of FIND P'pics' format means alphabetic, but matched to other than A-Za-z.||~128EI~
       - (WXE) Windows size at termination was not keept at next session.||~128EI~
       - Corrupted remote directory list if remote filename is not ASCII||~128EI~
         when using Samba.                                            ||~128EI~
     (128E)                                                           ||~v128R~
       -Error msg "Invalid Name Format"(::profile folder) is issued   ||~v128R~
        when filename extention is UTF8 encoded.                      ||~v128R~
       -"FINd all" cmd on dirlist loops when long filename is hidden  ||~v128R~
        by attr column.                                               ||~v128R~
     (128F)                                                           ||~128FI~
       -(LNX:Console0)Bug of v12D; ASCII string disappear when Ligature mode and not Combine mode.||~v128R~
       -(Win:Console)Invalid column position display for Japanese DBCS.||~128FI~
       -(LNX)Deprecated API may cause Link error in the recent distributuion.||~128FI~
       -(LNX)Crashes may occur when display directory list            ||~128FI~
        in the case filename is locale encoded(sush as EUC-JP) and simbolic link is UTF-8 encoded.||~128FI~
       -(LNX)gxe crashes on fedora-25.                                ||~128FI~
        (under the condition Gtk3 environment and env-var WAYLAND_DISPLAY is set)||~128FI~
     (128G)                                                           ||~v128R~
       -JOIn { X | NX | n[-b-s] } cmd was rejected by "n[-b-s]" is invalid.||~v128R~
       -(Win)When Ligature OFF, unicode of CPU8 file may be displayed by alternate chracter,||~v128R~
        for ex, "A-Umrlut" by "A".                                    ||~v128R~
       -Crushes by long file path name over limit(Windows:260,Linux:4096).||~v128R~
        (Delete line cmd moves the directory/file to the xe_undel... directory||~v128R~
         for later undelete. It may generate the status the path name is over the limit.)||~v128R~
       -(LNX)Crashes when set export LANG=C on Japanese Environment.  ||~v128R~
       -(LNX)failure on Gtk3 environment.                             ||~v128R~
         .Freeze by Drag operation on Fedora25(Wayland is default display server).||~v128R~
          ==>Set GDK_BACKEND=x11 on Fedora25.                         ||~v128R~
             export GDK_BACKEND=x11 or use command "GDK_BACKEND=x11 gxe".||~v128R~
         .File could not be copyed out by Copy & Paste.               ||~v128R~
         .Mouse wheel did not scroll contents.                        ||~v128R~
       -(LNX)Dragging a file may cause dir-list scrolling.            ||~v128R~
     (128H)                                                           ||+v129R~
       -(64Bit) Error when update on =0.1(Define shortcut key) panel. ||+v129R~
       -(Linux) Open remote file on Samba Server as New file when error was detected such as parmission error.||+v129R~
       -(Linux) Err msg was issued when open remote file through FTP client if it is symbolic link.||+v129R~
     (128K)                                                           ||+v129R~
       -XBC cmd.                                                      ||+v129R~
         .time calculation crash for large time value                 ||+v129R~
         .cancellation of significant digits at time calculation if hours>0x7fff||+v129R~
                                                                      ||~v128I~
     2.Additional function.                                           ||~v128I~
       -Unicode input by Alt+n (n:1-9,h,v)                            ||~v128I~
        use u-xxxx format in the file ::xelch{win|lnx}.ini[.locale]   ||~v128I~
            ex) 2=u-102222,41; u2550                                  ||~128ER~
     (128D)                                                           ||~128EI~
       - Find cmd new option.                                         ||~128EI~
        . { FINd | IFInd | FNX | INX } [find-options] [-{PSP|PSF}[X|R|D]]||~128EI~
            PSP:applyed to the split screen, applyed also to not split screen.||~128EI~
            PSF:applyed to the Edit/Browse file/directory panel.      ||~128EI~
            X:specify -PSPX/-PSFX alone, excecute latest PSP/PSF command.||~128EI~
            R:specify -PSPX/-PSFX alone, set latest PSP/PSF command to cmd line.||~128EI~
            D:specify -PSPX/-PSFX alone, display PSP/PSF command effective now.||~128EI~
        . PSD (no operand) command                                    ||~128EI~
            Display PSP/PSF/STD command effective now.                ||~128EI~
            STD:normal Find cmd.                                      ||~128EI~
                                                                      ||~128EI~
        . Ctrl+F5 (re)find using PSP cmd, Alt+F5 (re)find using PSF cmd.||~128EI~
          Ctrl+Shift+F5, Alt+Shift+F5 switches search direction.      ||~128EI~
          If find cmd operand is set on cmd line,                     ||~128EI~
          PSP/-PSF option is selected from cmd line regardress function key used(F5, C+F5 or A+F5).||~128EI~
          PSF cmd saved is lost when the file is closed.              ||~128EI~
          Latest two PSP cmds saved are recovered at restart as for SPLIT(1) and SPLIT(2).||~128EI~
        . On Linux, Alt+F5 may be assinged as default shortcut key.   ||~128EI~
          Inactivate it by Linux Settings-->Shortcut, chnage Function-Key assignmeny on xe =0.2 panel.||~128EI~
                                                                      ||~128EI~
        . This function enable 3 pattern's search on a file.          ||~128EI~
          After followings                                            ||~128EI~
             F abcS                                                   ||~128EI~
             F abcP -psp                                              ||~128EI~
             F abcF -psf                                              ||~128EI~
          F5 searches "abcS", Ctrl+F5 searches "abcP" and Alt+F5 searches "abcF".||~128EI~
          To continue search same pattern, use same key.              ||~128EI~
          (ex) "F abcP -psp", C+F5, C+F5, S+C+F5                      ||~128EI~
        . Change cmd is not supported.                                ||~128EI~
        . Enclose by quotation to search "-PSP" itself. (ex) F "-PSP".||~128EI~
     (128E)                                                           ||~128EI~
       - Utilizes Shift+Alt+Fn, Shift+Ctrl+Fn keys.                   ||~128EI~
        . Specify on =0.2 panel or INI file(::xe.ini).                ||~128EI~
        . Linux may define those keys as shortcut.                    ||~128EI~
          In that case, to utilize these keys change Linux Settings->Shortcut.||~128EI~
          When key widthout Shift(A+Fn,C+Fn) is defined as shortcut,  ||~128EI~
          it mey be required to set it disable.                       ||~128EI~
        . Destination(Up,Down,Left,Right), Ins, Del keys are also accepted.||~128EI~
                                                                      ||~128EI~
       - Tab cmd, new altch option.                                   ||~128EI~
        . On Windows command prompt, unicode charcter display-column-width depends its Properties-->Font setting.||~v128R~
          If you use ASCII char as alt-displaying-char of TAB and TAB padding space char.||~128EI~
          If you yet use prefered unicode for TAB and TAB padding, use this altch option.||~128EI~
          On wxe,gxe,Linux xe, it may not be occur.                   ||~128EI~
        . TAB { on [altch] | off | clear | =default | nn [asdefault] }||~128EI~
          [altch] option overrides following INI file options.        ||~v128R~
            (J)Tab_disp_char  =FFFF #(FFFF)# Tab display char for Japanese mode. (FFFF means U-21be & U-21c0)||~v128R~
            (E)Tab_disp_char  =FFFF #(FFFF)# Tab display char for English  mode. (FFFF means U-21be & U-21c0)||~v128R~
            DBCSspace_dispchar=FF #(FF)# DBCS space display char. (FF means U-2591)||~v128R~
        . "tab on 000" is used to back to default(u21be-21c0,2591) or INI settings.||~v128R~
        . ex)  tab on "^-" ,   tab on u25b8-25b9 ,  tab on "^-!" ,  tab on u25b8-25b9-21be.||~v128R~
        . When Non-ASCII is specified as altch, "xpr -tabon" cmd use the altch||~128EI~
          for printing CPU8 file and use 0x18 and 0x1a for non-CPU8 file.||~128EI~
     (128F)                                                           ||~128FI~
       - Select command.                                              ||~128FI~
        . new lineno option:  "S -lineno" (1st member if lineno is missing)||~128FI~
          ex)  "S -5" to open member of lineno=5.                     ||~128FI~
     (128G)                                                           ||~v128R~
       -Deal long path name file/directory.                           ||~v128R~
        .(Win)File system connected by "NET USE" cmd on Linux Samba Server||~v128R~
         has longer path name than windows local file.                ||~v128R~
        .(Win)Windows support long path name up to 32KB               ||~v128R~
         by using ""\\?\" prefix if set registory "NTFS long path".   ||~v128R~
        .(LNX)If available to rename directory containing long path name,||~v128R~
         delete after rename.                                         ||~v128R~
                                                                      ||~v128R~
        ==>Ini file format was changed, you need to once delete ini file||~v128R~
           by this modification.                                      ||~v128R~
           (ini file: Win=::XE!SAVE!, Linux=::xe_save_)               ||~v128R~
     (128K)                                                           ||+v129R~
       -XBC accept multiple(Max 10) operator.                         ||+v129R~
        e.g. xbc 200/3.3*35.7 , xbc 1+2+3+4+5+6+7+8+9+10              ||+v129R~
       -command verb "LIG" to toggle ligature mode(A+";" key)         ||+v129R~
        and "CMB" to toggle combine mode(A+":" key) was added.        ||+v129R~
                                                                      ||~v128I~
     3.Miscellaneous.                                                 ||~v128I~
       -On EDIt/BROwse/SELect cmd and "o" cmd on dirlist,             ||~v128I~
        translates filename encoding(UTF8<-->locale code) by FN{U8|LC} option,||~v128I~
        for the abridgement of input key mode changing by Alt+u key.  ||~v128I~
        Filename encoding is displayed on the line of "TOP-OF-LINE".  ||~v128I~
        ex).                                                          ||~v128I~
            *****|*l*t**Lu** TOP OF LINE *******************************||~v128I~
                        ^^                                            ||~v128I~
                        ||                                            ||~v128I~
                        |+--------->by IOCHARSET mount option of the directory's device.||~v128I~
                        +---------->Filename encoding(U/L/u/l)        ||~v128I~
     (128C)                                                           ||~128DI~
       -WXP cmd;option /tabon was added.                              ||~128DM~
       -(Lnx)Deafualt value of Disp_trans_tbl on ini file(non-displayable character parameter)||~128DM~
        was changed. Control character(<0x20) may be almost displayable.||~128DM~
        (Note)Font setting of CommandPrompt profile may be cause of shift of character position.||~128DM~
              Select proper font.                                     ||~128DM~
              Or set properly Display_tans_tbl/Displaytrans_char parameter of ini file.||~128DM~
     (128D)                                                           ||~128EI~
       - ::linech.ini file is used to convinient unicode input enabling graphic line character||~128EI~
         which assigned to A+1,2.. key.                               ||~128EI~
         Comment line(start width "#") is supported.                  ||~128EI~
       - Modification to displaying unicode combining character.      ||~128EI~
          Command                                                     ||~128EI~
            Linux console version.                                    ||~128EI~
              OPT UNICOMB [ COMB | SPLIT | UNPR ] [ SHADOW | ITSELF | PADDING | U-xxxx ]||~128EI~
            the other                                                 ||~128EI~
              OPT UNICOMB [ COMB | SPLIT | UNPR ] [ U-xxxx ]          ||~128EI~
        . supports U-xxxx (alternative character code to display combining character under UNPR mode).||~128EI~
          And U-00 means restore default value(':'=u-3a).             ||~128EI~
          It is applyed to Edit/Browse panel.(previously it was fixed to ':').||~128EI~
          gxe also supports UNPR mode.                                ||~128EI~
        . On 2nd(command input) line,to enable to modify command,use always SPLIT mode||~128EI~
        . On Edit/Browse panel,wxe/gxe apply ligature mode even when not COMB mode.||~128EI~
        . Select TrueType font for command prompt to use Windows console version xe.||~128EI~
       - ::xehosts(hots file for remote file access function)         ||~128EI~
         expands operand length limit to enable to spacify not IP addr but URL.||~128EI~
     (128E)                                                           ||~128EI~
       - Key A+PgDn and  A+PgUp is assigned to Top-Of-File and  End-Of-File each.||~128EI~
       - (W32)Draw Col gauge line, vertical hex line by fixed pitch even when||~v128R~
         propotional font is set to cmd prompt property.              ||~v128R~
       -(Lnx:Console) Curses string for key combination of Debian is registed.||~v128R~
        (A+F1,.. was not available on Debian previously)              ||~v128R~
     (128G)                                                           ||~v128R~
       -(LNX)For deprecated function under Gtk3.                      ||~v128R~
     (128H)                                                           ||+v129R~
       -Reduced memory allocation for directory list.                 ||+v129R~
        Windows 9000->300 Byte, Linux 450->250 Byte about.            ||+v129R~
     (128K)                                                           ||+v129R~
       -XBC time calculation output days when hors>24.                ||+v129R~
                                                                      ||~v128I~
     4.Tools.                                                         ||~v128I~
       -xfg v1.18                                                     ||~128FR~
        .new option                                                   ||~128FR~
          /F :file selection wildcard mask.                           ||~v128I~
          /X :excluding file wildcard mask.                           ||~v128I~
        .Wildcard mask is not applied to sub-dir name itself.         ||~128FI~
         To exclude th sub-dir, use -X option.                        ||~128FI~
         ex) xfg -rgt -fABC* -xAsubdir word                           ||~128FI~
        .(BUG)Crushes wby long path name.                             ||~v128R~
       -xdc v2.26                                                     ||~v128I~
        .new option                                                   ||~128FR~
          /F+ :file selection wildcard mask.                          ||~v128I~
          /X  :excluding file wildcard mask.                          ||~v128I~
       -xdd v2.1                                                      ||~128FI~||~v128R~
        .new -q[n] option.                                            ||~128FI~
         Displays msg each 10**n deletion, n=3(=1000) when n is missing.||~128FI~
        ./r option is required to delete too long path name.          ||~v128R~
       -xprint v9.34                                                  ||~128ER~
        .(Win) support UCS4(unicode>u-ffff).                          ||~v128I~
       -xdig v1.12                                                    ||+v129R~
        .(Bug)64Bit version crashes.                                  ||+v129R~
                                                                      ||+v129R~
######################################################################||+v129R~
  .v129A<--129:(2017/06/24)                                           ||+v129R~
                                                                      ||+v129R~
     1.BUGs                                                           ||+v129R~
       -(Windows:64)"&"(spawn executable file) dir cmd crush.         ||+v129R~
       -(64Bit) =3.14 crush                                           ||+v129R~
                                                                      ||+v129R~
     3.Miscellaneous.                                                 ||+v129R~
       -(Windows) add "msi" as executable binary extension            ||+v129R~
