UTF8 encoding ||*CID:||+v130R~:  2024/07/05                update#=  850;||~v130R~
######################################################################
[English]    v1.30                                                    ||~v130R~

This editor is fit for programmers working on both main-frame and PC.
Its operation is based on mainframe SPF editor,
and like as other editor on PC, convenient short-cut key operation is hybrid.

    .Available to Windows and Linux.
    .Supports Fixed-Length and Variable-Length record file.
    .Suppors text file encoded by UTF8 and EBCDIC(requires ICU installation).
    .Supports binary file edit. Vertical 2 line and horizontal dump format.
    .Filer fuction (apply Delete, Rename, Copy, Move, Execute, ...) is available.
    .Supports Remote file access using ftp,samba,rsh,ssh,fuse.
    .Optionally update-tag:CID(ChangeID) is automatically appended to updated lines.

LICENSE: use GNU GPL

                            By Mizumaki-machi (sakachin2@yahoo.co.jp)

                                   http://hp.vector.co.jp/authors/VA010562
                                   GitHub: sakachin2/XE

For windows, "xe.exe" is console application and "wxe.exe" is GUI application.
   wxe.exe is WTL/ATL application(requires no MFC library) compiled on vs2010Express.
   Thorse are included in w64binGit.zip.
For Linux, "xe" is console application and "gxe" is GUI application.  ||~v29WR~
   Untar gxe-x.xx.tar.gz, and make binary by ./configure && make.
For Android, install "Axe" from PlayStore.                            ||~v29WR~
Following command line tools are also included.
   xads         For Windows Only,Access to NTFS ADS(Alternative Data Stream).
   xbc          Basic calculator.
   xcfont       (Windows)change command prompt font.                  ||~129KI~
   xci          C/C++/Java text file indentation
   xcv          Code conversion.                                 ||+124FR~,
                EUC,SJIS(Japanese:Shift JIS),Unicode,UTF-8,EBCDIC,Any-Codepage.
   xcvsjisc     Convert SJIS in xe's source file to Octal-notation.
   xdc          directory compare tool
   xdd          directory delete tool
   xdig         directory walk utility
                tool apply command to all sub-directory/files.
   xds          Directory size display tool
   xfc          File compare tool
   xff          file search by size/timestamp/name.
   xfg          Binary file string search & Recursive grep.
   xfmt         FileLineFormatter. "TC FMT" for huge file.
   xfs          Split large file,it enable backup large file to
                diskets.
   xkp          (Windows) display process-id and kill process.
   xlow         Rename UpperCase file name to LowerCase.
   xmj          2 file matching.
   xpe          Display comment of errno(libc error code).
   xts          Set/Display File timestamp
   xver         Set ERRORLEVEL from OS version

   xprint       text file print program                               ||~v29WR~
   gxp          (Linux)xprint using GTKPrint

Other contents.
  xehelp:
    Html files for Help.
    put it WorkDirectory, set "xehelp=..." environment variable
    or use -hd commandline parameter.
    Under linux you can put it in /usr/local\/shareLinux(see xelnxe.txt).
  sample/doc:
    Manual text files.
      xej.txt/xee.txt
      xereadmj.txt/xereadme.txt
      xelnxj.txt/xelnxe.txt(For Linux)
      xewxej.txt/xewxee.txt(For wxe and gxe)
  sample/data:
      xehosts      setup file for remote access.
      xesynw.cfg   (Win)setup file to use syntax highlight.
      xeebc.map    setup fie for EBCDIC conversion

  sample/staff:use following external tools if you have not in hand.

      grep.exe     It is used by GREp command and =3.14 panel.

      Select one from following syntax highlight tool and specify it xesynw.cfg
      See xee.txt and xesynw.cfg for how-to-use.
        gnu-source-highlight.zip
                     (Win)GNU source-highlight v2.9 is compiled on MinGW.
        WinHighlight31.copies2.zip
                     andre simon's highlight v3.1
                     Put dll in the same folder as exe.
      putty063.zip
                     Required when use putty for remote file access.


How to execute.

  (Windows)

  ．Create WorkDirectory, default is c:\xe_wd, avoid default value when c:\ is protected.
    e.g)  "mkdir d:\xe_wd"
  ．Put zip file in the WorkDirectory, then unzip it.
      copy xehosts etc. from sample\data to the WorkDirectory if you use those function.
      Put dummy file consist of one comment line(starting by "#" when you do not use the function.
  . Put executable binary on PATH environment valiable.
      Windows10 case:ControlPanel-->System and Security-->System-->Advanced Setting-->EnvironmentVariable:PATH
  . Set WorkDirectory to environment variable xe.
      Or, prepare .bat file
      e.g) xe.bat
               set xe=d:\xe010
               xe.exe
             OR
               xe.exe /wd:\xe010
  ．Start by "xe [file-spec]".
      "xe /?" shows commandline parameters.
  . Above is also applied to wxe.

  (Linux)
  .On terminal emulator, install xe.
      tar -zxvf gxe-1.xx.tar.gz
      cd
      ./configure
      make
      sudo make install   -->install to /usr/local/bin
    See sample/READMEj.txt when install trouble occured.
    If you want, install manually other binary from src/xsub folder than installed by "make install".
  .Create WorkDirectory at home.
      mkdir ~/xe_wdnnnnn     nnnnn is uid.                            ||~v29WR~
    Copy setup files such as xehosts from sample folder to the WorkDirectory if you use the function.
    If you do not use the function, create dummy file containing one comment record starting with "#".
  ．Start xe by "xe [file-spec]
      "xe -?" shows command line parameter
      Terminal emulator defines shortcut key such as  F1, F10 and ModifierKey(Shift/Alt/Ctrl) combination.
      If you want use  such key, disable shortcut by terminal emulator settings.
  . gxe is no affected terminal emulator setting.

######################################################################
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
      .Additional DOS command(XMOve,XDD,XPRINT)
      .Native DOS,OS/2 command is available.

  .v070:(96/04/15)
      .Extended function for Native DOS,OS/2 command process.
        (&quot;&gt;&quot; command prefix,option 6 on menu screen)
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
      .DPMI(DOS PROTECT MODE INTERFACE) version added.

  .v094:(97/10/05)
      .Binary file support.
      .UNIX text file support.
      .Support  margin.
      .Support Line-Numbered file.
      .New line cmd &quot;/&quot; and &quot;+&quot;.

  .v097:(97/12/27)
      .Long File Name support.(W95/GCC version)

  .v098:(98/04/28)
      .WindowsNT support(w95 version)
      .Allow range specification to &quot;O&quot;(on),&quot;P&quot;(paste) command(&quot;OO&quot;,&quot;PP&quot;).
      .Search line range support for Find/Change command.
      .New EXClude/IX(case insensitive EXClude) cmd
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
       -SUBmit command(Execute script file).Line command &quot;=&quot;(compare).
  .v102:(99/05/01)
      .Additional Function.
       -HEX digit input mode support(toggle by HEX cmd or Alt+F12)
       -New option to Edit/Browse/Select command.
        /Mb[nn][s]:b:binary mode.nn:line width.s:save.
        /Mn       :mode of 80 column line-numbered file with no CID.
        New cmd BB/EB/SB for /Mb and BN/EN/SN for /Mn.
        Dir-list line cmd &quot;1&quot;(Browse Binary) and &quot;2&quot;(Edit Binary).
       -SORT command.
       -F6 key on dir-list. Toggle file size display by byte and lineno.

  .v103:(99/09/01)
       -Cols command.Column-gauge is displayed. Any gauge fmt can be set.
       -Option for binary file.
        Edit/Browse/Select command. /O :file input range by Hex digit offs
                                    /Mo,/Ml:Line no is hex offset or no.
        Num command. NUM XON|XOFF[,S] :line number type.S:save.
        Locate command. LOC [O|L]nn[,C] O:Hex offset,L:line number digit.
                        C:location on current status.
       -&quot;EXClude ALL&quot; hides all lines.
       -To print currently displayed file enter &quot;XPRint *&quot;.

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
       -New line cmd &quot;[&quot; and &quot;]&quot;. shift reducing intermediate space.
       -New function key, &quot;Alt+.&quot; and &quot;Alt+,&quot;.
        .Search the pair of the parenthesis (,),[,],{,},&lt;,&gt;,/* or */.
       -XBC(Basic Calc) cmd.
        .Double word calc support.(Decimal is up to 19 digit).
        .Timestamp conversion. (Mainframe HOST TOD is also supported).
       -eXclude cmd.
        .Exclude repeated lines by &quot;x *=[n] all&quot;.
       -DROp cmd.
        .Rep option replace excluded lines by a comment line
         &quot;!!  nn line excluded -----&quot;.
       -COBOL support.
        .Left most column displayed and indentation pos when line
         insert is col 7.
        .Col 73-80 is optionally CID column.

######################################################################||~v29XI~
  .v109:(2001/10/08)
       -Binary Editor.
       -New line-cmd on directory list.
        .h(Hex), i(SPFCOB-with col 1-6 seqno),j(SPFCOB w/o seqno),
         k(COB w/o seqno), L(COB with seqno), n(SPF file)
       -Find,eXclude cmd.
        .&amp;:search line containing 2 word. ex). word1 &amp; word2.
        .-an or -bn:display and exclude n lines after or before
         the line containing search word.
        .-c:keep screen to display the found word to the rightmost.
        .-d[&lt;|&gt;]n:distance of 2 word of &amp; search. n:line count.
         ex) -d&gt;n:distance is over than n lines.
         -d&lt;n:distance is lower than n lines. -dn:word2 is on the next
         n'th line. without -d option or -d0,&amp; search 2nd word only
         on the same line as 1st word found.
       -Macro pair search.
        .Search same nest level corresponding macro of #if/#ifdef/
         #ifndef/#else/#endif/#elif.
        .Use &quot;Alt+.&quot; or &quot;Alt+,&quot; when csr is on the char of &quot;#&quot;.
       -New SPLit command.
                                                                      ||~v29XI~
######################################################################||~v29XI~
  .v110:(2002/01/14)
      .Linux version BUG corection.

######################################################################||~v29XI~
  .v111:(2002/05/19)
       -&quot;OPT EOL eol-char [ON|OFF]&quot; cmd.
       -&quot;JOIn {X|NX} [all] [.lab1 .lab2]&quot; cmd.
       -Alt+F12. repeat previous cmd.
       -Find/eXclude cmd.
        Accept minus value for -ann and -bnn option.
       -(UNX)Floppy disk support.
       -Dir-list line cmd &quot;o&quot;(Open).
       -/M{P|U|M} (EndOfLIne code change) parm to CREate,REPlace,APPend
        and SAVe. P:0d0a, U:0a, M:0d.
       -String Input Shortcut key.
                                                                      ||~v29XI~
######################################################################||~v29XI~
  .v112:(2003/01/19)
       -(WIN)WXE is a new member.
       -FINd/EXClude cmd.
         -*L option.
         -*=[n](search continued same n line) option is supported
       -TC cmd.
        support &quot;==&quot;(compare) operation.
       -CV cmd.
        JSI&lt;--&gt;SJIS,JIS&lt;--&gt;EUC and Unicode conversion(SJISM&lt;--&gt;UCS2&lt;--&gt;UTF8)
        is now supported.
       -REN(or NUM RENUM) cmd.
        added function to set line number on any position of text area.

######################################################################||~v29XI~
  .v113:(2003/09/06)

       -2 word &amp;(and) search support on also dir list.
       -% edit dir list line command.
       -CV cmd.
        .EBCDIC&lt;--&gt;ASCII conversion(except DOSversion)
        .Hankaku(SBCS)katakana&lt;--&gt;English lower case letter conversion(except DOSversion)
        .HexNotation string--&gt;Char conversion(except DOSversion)
       -ROTate cmd.
       -SPAwn cmd.
       -(LNXversion)
        .supports X-Window                                            ||~v29XR~
       -(AIXversion)
        .support telnet from Linux.
        .supports X-Window.                                           ||~v29XR~
                                                                      ||~v29XI~
######################################################################||~v29XI~
  .v114:(2003/09/15)
     . binary compiled by RedHat v9 is packaged.
       (xe compiled by TurboLinux v9 will ABEND at gnome-terminal on
        RedHat v9 when Kanji input.)
                                                                      ||~v29XI~
######################################################################||~v29XI~
  .v115:(2004/03/02)
       -FTP support(remote file access).
       -(WIN) AT new command.
         AT/&amp; [-i] interval [repeat-count];command-1;command-2,...;command-n
         Repeat command-1 -- command-n repeat-count times by interval seconds.
         Without repeat-count,loops infinitly.
       -(WIN) Sleep new command.
       -EXE cmd added.
        .execute edit command in the file.
       -TC cmd.
        .&quot;~&quot; new operation to count existing record.
       -Find cmd.
        .&quot;-j&quot; option. join lines in -a and -b or -d for &amp;(and search) range.
        .search word *\n to positioning End-Of-Line.
         &quot;*&quot;\n is for search &quot;*&quot; in the EOL position.
        .eol option to search word in the EOL.
       -Opt cmd.
        .Beep [on|off]  :Beep when err.
        .RCTL [on|off]  :use Right-Ctrl key as execute function.
        .CCFUNC [on|off]:to use Ctrl+Char key as function key.
        .FREECSR [on|off]:scroll or wrap around when cursor reached to
                          edge of the screen.
                          Always wrap when cursor is on lineno column.
       -CV cmd.
        .\u  :use with u2s. convert \uxxxx unicode format.
        .-Hpre[XXpost]:use with x2c. convert between prefix and postfix.
       -JOIn cmd.
        n-b-s option:repeat b times of n lines concatination then skip s lines.
       -Alt+w function key copies word to clipboard.
       -Alt+Left(Up),Alt+Right(Down) edit/browse the file/dir on the path
        of currently displayed file/dir.
       -S+right,S+Left is supported also on dir-list screen.
       -(WIN)Start application associated with filename extension.
       -(WXE)
        .wxp cmd. print by wxe function not by xprint tool.
       -(LNX)
        .mouse support.
                                                                      ||~v29XI~
######################################################################||~v29XI~
  .v116:(2004/12/21)                                                  ||~v29XI~
       -EXE cmd.
        .ignore error of each cmd in the cmd file and continue to process.
       -RSH new cmd.
       -SORt cmd.
        .support sort by timestamp/filesize on dirlist.
       -TC cmd.
        .option to output summary(subtotal,total) line to file.
        .support copy operation.
           opd3=opd2 [INS] [RJust]
       -remote file access.
        .support print local by XPRint cmd, &quot;p&quot; dirlist line cmd.
        .% dirlist line cmd on remote dirlist is done by rsh.
       -&quot;n&quot; edit line cmd support.
       -&quot;#&quot; dirlist line cmd support.

######################################################################||~v29XI~
  .v117:(2005/04/15)
       -File on another screen of splitted.
        .&quot;^*&quot; means the file on another screen of splitted.
         &quot;^*\&quot; means path of the file or dir itself and may be used
         like as &quot;e ^*\file2&quot;.
       -3 line HEX display mode.
       -Find cmd.
        .-Llcmd option.
        .-m[n] option. keep reverse display of found word.            ||~v29XR~
        .matching function.
         *=Mn, n:key column of the other screen file.
       -remote file access.
        .support &quot;u&quot;(undo) DirList line cmd for also remote file.
       -Command Log.
        .logging option is set OPT CMDLOG [ON|OFF]. default:OFF.
       -&quot;#&quot; new edit line cmd.

######################################################################||~v29XI~
  .v118:(2005/07/04)
       -GREp cmd support.
       -(WXE)Drag &amp; Drop.
        .support Drag from dirlist screen and drop out of xe.

######################################################################||~v29XI~
  .v119:(2005/07/30)
       -(LNX)new member gxe(Gnome GUI version executable) is added.
       -OPT DELZ {ON|OFF}
       -Support wildcard path specification for Copy/Move DOS cmd and dirlist line cmd.||~v29XR~
       -(WXE)Accept Shift+PrtScr key as file print request.
       -(LNX)support OpenWith(Open by associated application)
       -(LNX)Scroll by wheel mouse middle button is supported.
       -(LNX)support child shell(terminal window) creation by &quot;DOS sh&quot; or
         &quot;&gt; sh&quot;.

######################################################################||~v29XI~
  .v120:(2005/12/12)
       -New &quot;&amp;&quot; DirList line cmd.
       -(XXE)support printer selection on Preview dialog.
       -(XXE)Help(display xe html help)support.
       -Support Windows like Cut&amp;Paste operation.

######################################################################||~v29XI~
  .v121:(2006/04/17)
       -Retrieve command of the screen.
        F12 retrieve all command input on any panel,A+F12 retrieve
        command only input on the panel.
       -Alias cmd.
        Set alias cmd on short-cut-key panel(&quot;0.1 SC-CMD&quot; of top menu).
        Add line prefixed &quot;Alias:&quot;.
       -CV command.
        support &quot;\u&quot; option(uni-code by \uxxxx format) for also conversion
        type s2u/f2u(uni-code output) and u2f(uni-code input).
       -(WXE/XXE)Drag&amp;Drop
        Copy the file into the dir if dropped on the dir-list panel.
        Inter-splitted-screen drag&amp;drop is also available.

######################################################################||~v29XI~
  .v122:(2006/12/14)
       -Display file description on dir-list panel.
       -Horizontal scrolling.
       -(WXE)Forward/Backword button click of 5 button mouse is treated
        as DPU/DPD(FilePath Up/Down) command.
       -LOCate cmd.
        .search labeled line by .label operand spcification.
       -Fix keyboad input to uppercase.
        .New command CAP.
       -Setup &quot;Line Drawing Character&quot; by the ini file.
       -SUBmit command.
       -(Win) Turnkey MVS support.
       -Edit command
        .New option Fn[-m] to force the record length to n and set
         left margin to m.
        .New TC|NOTC option to specify TAB clear(change to space at save).
       -B2A/A2B(EBCDIC&lt;==&gt;ASCII) conversion option is added.
        (Ignore 0x0e/0x0f as SO/SI of SBCS(Japanese DBCS))
       -Change command.
        IC(CaseInsensitive) and ICN(CaseInSensitive,change displayed line only)
        commands are added.
                                                                      ||~v29XI~
######################################################################||~v29XI~
  .v123:(2007/09/17)
       -(WXE/XXE)GUI version support CrossHair cursor(ruler).
       -It is configurable to popup exit-confirmation-dialog on setup dialog.
        To bypass the dialog check on QuietExit checkbox.
       -COL [on|off] ALL; command set option to display default type column gauge||~v29XR~
        line at open for all file.
       -Line cmd(_:LowerCase conversion) support.                     ||~v29XR~
       -BOUnds(BNDs) command support.
          BND [col1] [col2] [ext]
       -Text Flow function.
       -TS line command.
         Split the line at the cursor point.
       -E8/B8/S8 command.
        Open the file by Fixed LRECL=80 without line-number on col.73-80.
       -New DirList line command.
        .&quot;g&quot;:grep in the file or directory.
        .&quot;=&quot;:compare two files using tool &quot;xfc&quot; in this package.
        .&quot;3&quot;:open the file by binary mode(browse or edit depends on the dir mode)
        .&quot;8&quot;:open the file by Fixed LRECL=80 without line-number-column.
       -New panel 3.12(File/Directory compare), 3.14(Search) support.
       -ROTate cmd.
       -Fixed Record Length file.
       -Expand parameter input area for DirList line cmd &quot;#&quot;.
       -Linux version is now packaged using libtool to enable installing
        xe from source file by &quot;./configure &amp;&amp; make&quot;.
       -Remote file access.
        .Deal with the FTP server of active mode only.

######################################################################||~v29XI~
  .v124 :(2009/04/13)
       -Remote Access(FTP).
        .Support TinyFTP daemon on Windows server.
        .Support PSFTP in PuTTY. (SSH2 was tested under v060)
       -Assign Alt+g to the new function to jump cursor between Char-part and Hex-part
        when horizontal/vertical HEX display mode.
       -CRLF option of SPLit cmd
        Split lines by the width or CRLF code,used to change the display width of text mode.
       -UTF8 support version.                                         ||~124FR~,
       -Another word search function key.                             ||+124GR~,
                  CaseSensitive        CaseInsensitive
            Bwd     C+[, A+S+[           A+[
            Fwd     C+], A+S+]           A+]
       -Another word paste function key.                              ||~124GI~,
          Ctrl+w:append the word on the cursor into command line.
                 In this function the word means space delimited word.
       -EXE cmd redirect parameter.                                   ||~124GI~,
          EXE [!] { * | ^* | filename } [parm1 parm2...]  [&lt; {@parmfile | [S] wildcard  [D[+]] ]
       -SYN new cmd.                                                  ||~124GI~,
        .Using GNU source-highlight, text is optionally displayed with syntax specific color.
        .andre-simon's &quot;Highlight&quot; is also tested.
       -CUT/PASte new cmd.                                            ||~124GI~,
       -Find/Change cmd new option.
        &quot;-g&quot; (grep) support regular expression.
       -Profile function.                                             ||+124LI~,
       -3270 connection.                                              ||~124NI~,
        Now connection with S390 by tn3270 was tested.                ||~124NI~,
       -NLS Spport.
        .Support Korean and Chinese encoded file and IME imput.
       -(Win) Support ENC format(\\server\sharefolder\file) filename.
       -(Win) C:\ may protected on Vista.
       -LineDrawingCharcter input function(Default key assign ment:Alt+0 to Alt+9)

######################################################################||~v29XI~
  .v125K:(2011/02/11)                                                 ||~v29XI~
       -UTF8 Support.
         .UTF8 encoded file is processed after translated to UCS2(16bit UCS) for windows version,
          Unicode input by hex notation and unicode synthesis by &quot;u&quot; key is supported.
       -NLS support                                                   ||~v29XR~
         .(LNX).4 byte DBCS of GB18030 is displayed as 4 columns char followed by 2 column padding chars.
         .Ligature support.
       -CV(Code conVersion) cmd.                                      ||~v29XR~
        .f2e/e2f(UTF8&lt;--&gt;Japanese-EUC) option was added
       -HEX cmd new option to move cursor zigzag.                     ||~v29XM~
          HEX [ On | Off | YZ | NZ ]                                  ||~v29XM~
       -RECORD Mode Edit cmd option.                                  ||~v29XR~
        .Edit fiels with no EndOfLine ID.
       -EBCDIC file support.                                          ||~v29XR~
        .EBCDIC encoded file is maintained as it is without translation to locale codepage.
       -64bit support(Tested only by Linux version)

######################################################################||~v29XI~
  .v127S                                                  (2015/03/10)||~v29XI~
           -Symbolic Link(JunctionPoint/MountPoint also for Windows) consideration.
           -RECFM=V support.
           -(LNX)gtk3 support.
           -Supports Ctl+W(copy string to command line) also on dir-list.
           -(Win)display Filename of foreign language by unicode.
           -FINd cmd, new option &quot;U4&quot; to search not 2 byte ucs but 4 byte ucs
           -For PuTTY 0.63, additional function key by modifier+Fn key combination.
           -Expanded record display width from 9999 to 32760.
######################################################################
  .v128K                                                  (2017/03/29)||~v29XI~
       -Unicode input by Alt+n (n:1-9,h,v)                            ||~v29XI~
        use u-xxxx format in the file ::xelch{win|lnx}.ini[.locale]   ||~v29XI~
       - Find cmd new option.                                         ||~v29XI~
        . { FINd | IFInd | FNX | INX } [find-options] [-{PSP|PSF}[X|R|D]]||~v29XI~
        . PSD command                                                 ||~v29XI~
       - Utilizes Shift+Alt+Fn, Shift+Ctrl+Fn keys.                   ||~v29XI~
       - Tab cmd, new altch option.                                   ||~v29XI~
        . TAB { on [altch] | off | clear | =default | nn [asdefault] }||~v29XI~
       - Select command.                                              ||~v29XI~
        . new lineno option:  "S -lineno" (1st member if lineno is missing)||~v29XI~
       -command verb "LIG" to toggle ligature mode(A+";" key)         ||~v29XI~
        and "CMB" to toggle combine mode(A+":" key) was added.        ||~v29XI~
######################################################################||~v29XI~
  .v129X                                                  (2024/02/20)||~v29XI~
       -Shortcut pathname                                             ||~v29XI~
        .SP { edit | refresh | add sp-name { file-spec | *\\ | ^*\\ } }||~v29XI~
        .To utilize Shortcut pathname, add prefix "sp:" to file-spec. ||~v29XI~
       -SelectAll                                                     ||~v29XI~
        .SEL [all] [col1 col2] [.label1 .label2]                      ||~v29XI~
        .Select range to Cut/Copy/Paste on Edit panel.                ||~v29XI~
       -XML tag pairing searchv by Alt+"/"                            ||~v29XI~
        .It is convenient to correct html text.                       ||~v29XI~
       -CommandHistoryList.                                           ||~v29XI~
        Mouse operation support.                                      ||~v29XI~
       -TC fmt cmd -D"..." and -S"..." option                         ||~v29XI~
        Accept escape secuence such as \x, \t as Delimeter(\t(0x09) is not allowed for -S).||~v29XI~
       -COL command (Display column gauge to enable setting of tab stop position)||~v29XI~
        .COL [on|off] [ALL|type|default]                              ||~v29XI~
       -Syntax Highlight.                                             ||~v29XI~
		Supports ANSI:reverse attributes of Andre Simon's Highlight and GNU source-highlight.||~v29XI~
	   -Unicode support for CID prefix.                               ||~v29XI~
	    U-235d is a comment prefix in APL language, CID supports it.  ||~v29XI~
       -(Axe)                                                         ||~v29XI~
        .And.Android 13 (Api-33) compatible.                          ||~v29XI~
        .Shared storage support.                                      ||~v29XI~
######################################################################
  .v130 <--129X:(2024/06/30)                                          ||~v29XR~

     1.BUGs                                                           ||~v29XI~
       -(Linux) ./configure may fail by "/gth.h Not found".           ||~v29XI~
       -(Linux:gxe) When using Gtk3, the widget size is not fixed and changes at each start.||~v29XI~
       -(LNX:gxe) プリントアイコンを押すとブランクページを印刷したりクラッシュすることがある||+v130I~
                                                                      ||~v29XI~
     2.Additional function.                                           ||~v29XI~
       -Improved display of UTF-8 files                               ||~v29XI~
         .For ZWJ(u-200d), ZWNJ(u-200c), or other chars in category Cf(Format).||~v29XI~
       -Added 2 options to specify the display width of Unicode chars whose display width is ambiguous.||~v29XI~
         ./G{Y|N}{y|0|1|2}                                            ||~v29XI~
            :Specy cell width of unicode defined width is ambiguous.  ||~v29XI~
            Y:Fit to font width.                                      ||~v29XI~
              You can also specify the second option for chars in unfamiliar languages.||~v29XI~
              However, this option takes a cost, the start-up will be slightly slower.||~v29XI~
            N: Specify the display width uniformly using the second option.||~v29XI~
            The default value is /GY2.                                ||~v29XI~
            Ex.) /GN2: All ambiguous chars are displayed in two cells.||~v29XI~
                 /GYy: All ambiguous chars are adjusted according to the font.||~v29XI~
                 /GY0: Unfamiliar languages are displayed as ':;' instead.||~v29XI~
         ./F{fontname[:charset] | @font_param_filename}               ||~v29XI~
            The font name required for /G option is---                ||~v29XI~
            when running on Windows Terminal, setting.json is checked,||~v29XI~
            when running on Linux, on gnome-terminal, konsole, etc.,  ||~v29XI~
            the profile of the Home dir is checked by xeGetFont.sh.   ||~v29XI~
            But if it fails, specify this option.                     ||~v29XI~
            Use font_param_filename when specifying indirectly from a file, use font_param_filename.||~v29XI~
            See Microsoft's documentation for the appropriate charset for the font.||~v29XI~
            Ex.) /F"MS Mincho":128, /F@.\fontParm.txt.                ||~v29XI~
                 /F"\uff2d\uff33 \u660e\u671d".                       ||~v29XI~
       -XBC command supports ucs4<-->utf16 conversion.                ||~v29XI~
            Ex.) xbc 1f468/s    ==> x1f468/s:=d83ddc68                ||~v29XI~
            Ex.) xbc d83ddc68/s ==> xd83ddc68/s:=0001f468             ||~v29XI~
       -"-cont" option added to Find command.                         ||~v29XI~
          When selecting lines in a large file by the Find command in the Exe cmd file,||~v29XI~
          from a performance consideration,                           ||~v29XI~
          when NotFound occurred, the next Find will start not from the first line,||~v29XI~
          but from the last Found line.                               ||~v29XI~
          It will be better on condition that files were sorted.      ||~v29XI~
       -Screen hard copy output.                                      ||~v29XI~
          Alt+z writes a screen hard copy to ::hcopy in append mode   ||~v29XI~
          Ctrl+h is also available for except Linux Console version.  ||~v29XI~
                                                                      ||~v29XI~
     3.Miscellaneous.                                                 ||~v29XI~
       -(LNX) Gtk2 support has been discontinued, only Gtk3 is supported.||~v29XI~
       -(LNX) Install scripts to check font settings for the console version||~v29XI~
              into /usr/local/bin. Also install xprint.sh.            ||~v29XI~
                                                                      ||~v29XI~
     4.Tools                                                          ||~v29XI~
       -xbc  v1.7                                                     ||~v29XI~
          Added ucs4 <--> utf16 conversion.                           ||~v29XI~
       -xcv  v1.23                                                    ||~v29XI~
          Limits option /Yh (input in hexadecimal notation) to standard input including pipe.||~v29XI~
       -xprint.c 3.39                                                 ||~v29XI~
          (LNX)The right edge of lines may exceed the right margin and text may be cut off.||~v29XI~