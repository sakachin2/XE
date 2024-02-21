UTF8 encoding ||*CID:||+v29XR~:  2024/02/20                update#=  837;||~v29XR~
######################################################################
[English]    v1.29X                                                   ||~v29VR~||~v29WR~||~v29XR~

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
######################################################################
  .v129A<--129:(2017/06/24)

     1.BUGs
       -(Windows:64)"&"(spawn executable file) dir cmd crush.
       -(64Bit) =3.14 crush

     3.Miscellaneous.
       -(Windows) add "msi" as executable binary extension

  .v129B<--129A:(2017/07/10)

     1.BUGs

       -(Win64) Erroneous calculation when Datatype is X(Hex),O(octal).
       -(Win64) DragDrop between split panels(file copy) crashes.

     2.Additional function.

       -Shortcut pathname
        .SP { edit | refresh | add sp-name { file-spec | *\\ | ^*\\ } }
            edit   : show edit panel of Shortcut pathname definition file(::xe.shortpath).
                     Update is enabled when restart xe,
                     or enabled if "refresh" after saved.
                     Format of the line of definition file is "Shortcut-pathname fullpath-name".
                     Put "#" at top of line to comment out.
                     e.g.) srctest1 d:\eclipse-workspace\testproject1\src\com\debug\test
                           ecws  "c:\Program Files\Android\Android Studio\gradle"
            refresh: reload  definition file of ::xe.shortpath.
                     Use after "sp edit", modify then saved or directly updated ::xe.shortpath by
                     another process.
            add    : add a line to definition file by sp-name:Shortcut pathname and file-spec:shortcut target fullpath name.
                     This definition is enabled instantly.
                     Following specifications are effective at proper situation.
                       *\ :the file currently opened on this panel.
                       ^*\:the file currently opened on another split panel.
                     e.g.) sp add srctest1 d:\eclipse-workspace\testproject1\src\com\debug\test
                           sp add ecws  "c:\Program Files\Android\Android Studio\gradle"
        .To utilize Shortcut pathname, add prefix "sp:" to file-spec.
         (If xxx of sp:xxx is not defined, "sp:xxx" is used as is.)
           e.g.) e sp:srctest1\Main.java
                 e sp:ecws
                 e "sp:ecws\space embedded name"
                 xcopy sp:ecdir\x1 sp.ecdir\x2
                 cd sp:ecdir
                                                                      ||~129CI~
  .v129C<--129B:(2017/09/04)                                          ||~129CI~
                                                                      ||~129CI~
     1.BUGs                                                           ||~129CI~
                                                                      ||~129CI~
     2.Additional function.                                           ||~129CI~
       -Find cmd                                                      ||~129CI~
          Search file attribute column on dir-list panel.             ||~129CI~
          Parameter is case insensitive.                              ||~129CI~
          Use "d" for directory, "L" for symbolic link.               ||~129CI~
          Specify "d" and "L" alone each.                             ||~129CI~
          For other attributes, on Windows, select the line having all attributes of parameter,||~129CI~
          on Linux, select the line having string of attribute parameter.||~129CI~
          Following attribute IDs are specific to Linux.              ||~129CI~
            u:setuid, g:setgid, S:setuid+setgid, t:stickey            ||~129CI~
            c:char device, b:block device, p:pipe, s:socket           ||~129CI~
          e.g.) (Windows) f SH attr ; f R attr & 17-08 ; f D attr & L attr||~129CI~
                (Linux)   f 775 attr ; f u attr                       ||~129CI~
                                                                      ||~129CI~
     3.Miscellaneous.                                                 ||~129CI~
       -(Windows)If LoadLibrary failed for EBCDIC library for ICU(libicuuc.dll),||~129CI~
        search in the directory of ICU_DATA parameter of xeebc.map and also||~129CI~
        ICU_DATA environment variable.                                ||~129CI~
        (Linex)It is need to set LD_LIBRARY_PATH if the ICU so is not on default path like as /usr/lib etc.||~129CI~
       -When ICU_DLL_SUFFIX and ICU_APP_SUFFIX  are missing,          ||~129CI~
        set both bt ICU utility  uconv(.exe).                         ||~129CI~
       -Reject /Mr(Recordmode) option for CPU8 file because string length of UTF8 code is indefinite.||~129CI~
                                                                      ||~129CI~
     4.Tool.                                                          ||~129CI~
       -xprint v9.38                                                  ||~129CI~
        ./Tabon: new parameter added                                  ||~129CI~
           Specify alternative char for DBCS space, TAB(0x09) and its following space.||~129CI~
           /Tabon:x:y:z ;Text mode alternative char for DBCS space,Tab(0x09),Tab-skip.||~129CI~
                        ;For x,y,z each, specify Char itself, Unicode or Hex notation.||~129CI~
                        ;e.g.) /Tabon:x2020:x18:x1a  /Tabon::u2191:u2192 /Tabon::u25cb||~129CI~
                        ;      /Tabon:u2750                           ||~129CI~
                        ;Default is /Tabon:u3000:x20:x20(UTF8/EBCDIC file)||~129CI~
                        ;       and /Tabon:x8140:x20:x20(other file). ||~129CI~
        .For EBCDIC file EBCDIC, if /BCfilename is missing to translate by ICU,||~129CI~
         Search ICU shared library(DLL or so) on PATH or LD_LIBRARY_PATH.||~129CI~
         If library found, supply ICU version using ICU utility uconv(.exe).||~129CI~
           e.g.) xprint x1ebc22 -cpeb=cp930 -me -icu                  ||~129CI~
       -xcv 1.20                                                      ||~129CI~
        .When translating EBCDIC file by ICU, if /BCfilename parameter is missing,||~129CI~
         Search ICU shared library(DLL or so) on PATH or LD_LIBRARY_PATH.||~129CI~
         If library found, supply ICU version using ICU utility uconv(.exe).||~129CI~
           e.g) xcv x1ebc22 x1ebc22m -b2m -cpeb=cp930 -icu            ||~129CI~
                                                                      ||~129CI~
  .v129D<--129C:(2017/12/03)                                          ||~129CI~
                                                                      ||~129CI~
     1.BUGs                                                           ||~129CI~
       -(Linux)Under GTK3 environmentt, Accelerator option on Setup dialog was not work.||~129CI~
       -(Wxe)Crash when File->New menuitem was selected.              ||~129CI~
                                                                      ||~129CI~
     2.Additional function.                                           ||~129CI~
       -SelectAll                                                     ||~129CI~
          .Command.                                                   ||~129CI~
             SEL [all] [col1 col2] [.label1 .label2]                  ||~129CI~
               label1/2:line range  col1/2:column range               ||~129CI~
               numeric specification for both label 1 and 2 are accepted as lineno.||~129CI~
               Block mode with col1/2, Range mode without col1/2.     ||~129CI~
               "Selct All" without label/column.                      ||~129CI~
               e.g.) sel; sel .a .b; sel 1 20; sel 10 20 .1 .4;       ||~129CI~
          .Select range to Cut/Copy/Paste on Edit panel.              ||~129CI~
           Under range mode, selected range itself is target of Paste Range mode.||~129CI~
          .Abridged format command "S" is not available               ||~129CI~
           "S" means "SAVe" on Browse/Edit panel.                     ||~129CI~
        (Wxe,gxe)                                                     ||~129CI~
          ."SelectAll" menuitem was added to File submenu and popup menu on edit panel.||~129CI~
          .Set shotcut key to Ctrl+A and cabnged to Ctrk+Shift+A for SaveAs.||~129CI~
                                                                      ||~129CI~
     3.Miscellaneous.                                                 ||~129CI~
       -Disable also menuitem of File submenu depending panel type.   ||~129CI~
        e.g. Save is disable for directory list panel.                ||~129CI~
                                                                      ||~129EI~
  .v129E<--129D:(2018/01/09)                                          ||~129ER~
                                                                      ||~129EI~
     1.BUGs                                                           ||~129EI~
                                                                      ||~129EI~
       -(Windows Console version) Japanese Error msg on header line may be corrupted.||~129EI~
                                                                      ||~129EI~
     2.Additional function.                                           ||~129EI~
                                                                      ||~129EI~
       -XML tag pairing search                                        ||~129EI~
          .Default shortcut key is Alt+"/"                            ||~129EI~
          .Use shortcut key on "<" or ">"                             ||~129EI~
          .Comment portion(from "<!--" to  "-->") is ignored          ||~129EI~
           and recognize nested tag.                                  ||~129EI~
           It is convenient to correct html automation tool generated.||~129EI~
                                                                      ||~129EI~
     3.Miscellaneous.                                                 ||~129EI~
                                                                      ||~129EI~
       -(Windows Console version) When ligature:on on windows10,      ||~129EI~
        UTF8 file lines of Japanese Kanji shrinks to unreadable.      ||~129EI~
        So, reject Ligature:On for from Windows7.                     ||~129EI~
                                                                      ||~129FI~
  .v129F<--129E:(2018/01/23)                                          ||~129FI~
                                                                      ||~129FI~
     1.BUGs                                                           ||~129FI~
                                                                      ||~129FI~
       -Edit/Browse Command                                           ||~129FI~
        .Shows only last record when record mode with RecordSize>4096 ||~129FI~
         and 1st record contains ControlChar(<0x20).                  ||~129FI~
         Or crashes if FileSize>128K                                  ||~129FI~
        .CPLC option registered on profile record was ignored when record mode.||~129FI~
         ("CPLC" option was required each time)                       ||~129FI~
                                                                      ||~129HI~
  .v129G<--129F:(2018/01/30)                                          ||~129GI~
                                                                      ||~129GI~
     1.BUGs                                                           ||~129GI~
                                                                      ||~129GI~
       -(Linux) On Ubuntu17.10, DirList line command:"!"(start application corresoponding to the file extension)||~129GI~
        failes by "No application defined to the MIME type".          ||~129GI~
       -(Wxe/gxe) Cut&Paste by mouse may paste trash data with length of CID of source line.||~129GI~
                                                                      ||~129GI~
     2.Additional function.                                           ||~129GI~
                                                                      ||~129GI~
     3.Miscellaneous.                                                 ||~129GI~
                                                                      ||~129GI~
       -(Linux)Adjusted configure.ac through installation to S390x on Hercules emulater.||~129GI~
               And updated TroubleShooting notes(READMEe.txt).        ||~129GI~
                                                                      ||~129FI~
  .v129H<--129G:(2018/02/22)                                          ||~129HI~
                                                                      ||~129HI~
     1.BUGs                                                           ||~129HI~
       -(gxe:GTK3)printer selection on PrintDialog is applied incorrectly.||~129HI~
       -(gxe:GTK3)screen size at termination is not recovered correctly and enlarged.||~129HI~
                                                                      ||~129HI~
     2.Additional function.                                           ||~129HI~
       -P=nn(PortNo) option in xehots                                 ||~129HI~
        .specific to the psftp destination other than default SSH portNo(22).||~129HI~
       -Command History List.                                         ||~129HI~
        .Shift+Ctrl+F12 shows CommandHistoryList, use "x" key to execute cmd on the line.||~129HI~
        .Available commands are                                       ||~129HI~
          s : set to the command input line after closed the command history panel.||~129HI~
          S : set to the command input line of the command history panel.||~129HI~
          t : set on the other panel if screen is split.              ||~129HI~
              same as "S" if not split                                ||~129HI~
          x : executhe the command after closed the command history panel.||~129HI~
          X : execute on the command history panel.                   ||~129HI~
          y : execute on the other panel if screen is split.          ||~129HI~
              same as "X" if not split.                               ||~129HI~
        .Max 40 entry is saved at xe terminate.                       ||~129HI~
                                                                      ||~129HI~
     3.Miscellaneous.                                                 ||~129HI~
       -Function:"R-Retrieve-OfTheScr"(Retrieve command of Next of the panel)||~129HI~
        had not function key assigned, assign Shift+Alt+F12.          ||~129HI~
                                                                      ||~129JI~
  .v129J<--129H:(2018/05/10)                                          ||~129JI~
                                                                      ||~129JI~
     1.BUGs                                                           ||~129JI~
                                                                      ||~129JI~
     2.Additional function.                                           ||~129JI~
       -CommandHistoryList.                                           ||~129JI~
        Mouse operation support.                                      ||~129JI~
        .R-button popups context menu.                                ||~129JI~
        .Double click works as "x" cmd(execute the command after closed the command history panel).||~129JI~
        .Click on the selected line works as "s" cmd(set to the command input line after closed the command history panel).||~129JI~
                                                                      ||~129JI~
     3.Miscellaneous.                                                 ||~129JI~
       -Add "CPU8" option to dirlist cmd "="(compare file/directory). ||~129JI~
                                                                      ||~129JI~
     4.Tool.                                                          ||~129JI~
       -xdc v2.29,xfc v1.27                                           ||~129JI~
        Add "CPU8" option.                                            ||~129JI~
                                                                      ||~129JI~
  .v129K<--129J:(2018/08/27)                                          ||~129KI~
     1.BUGs                                                           ||~129KI~
       -Around processing of UTF8 file.                               ||~129KI~
         .DisplayCellWidth was reviced.                               ||~129KI~
         .Trouble around displaying UCS4,SpacingCombiningMarks adn NonSpacingMark.||~129KI~
         .Expanded Maxmum combining up to 8 chracters.(case of Tibtan)||~129KI~
          For Linux Console version max is yet 4 characters.          ||~129KI~
         .When unicode>=U01000(Windows) or unicode>=U020000(Linux)    ||~129KI~
            -Invalid hexcode display on top-left header line.         ||~129KI~
            -Could not update on vertical hex display line.           ||~129KI~
         .(LNX)When U01000<= unicode <U020000                         ||~129KI~
            -SBCS(CellWidth=1) was changed to another character at save.||~129KI~
            -"v" line cmd on vertical hex line(cmd to accept 3 consecutive hex code as unicode) failed.||~129KI~
         .On =3.12 panel(Compare Tool) was corrupted when filename encoding is UTF8.||~129KI~
         .(WinConsole)New tool:xcfont can change font of command prompt.||~129KI~
          It enables to view foreign script suach as Devanagari.      ||~129KI~
       -When gb18030, differece of cursor position between charcter and vertical hex line||~129KI~
        occurs for characters of CelWidth=1.                          ||~129KI~
       -Consecutive Esc key clear line cmd except label,              ||~129KI~
        but cmd specified the labe get error of label not found.      ||~129KI~
       -When screen is split, it may occurs that line cmd on edit panel is ignored.||~129KI~
                                                                      ||~129KI~
     2.Additional function.                                           ||~129KI~
       -TC fmt cmd -D"..." and -S"..." option                         ||~129KI~
        Accept escape secuence such as \x, \t as Delimeter(\t(0x09) is not allowed for -S).||~129KI~
        Accept DBCS as  -S option.                                    ||~129KI~
     3.Miscellaneous.                                                 ||~129KI~
       -3.12 Panel(File/Dir compare)                                  ||~129KI~
        "-CPU8" option was added to view compare result as CPU8 file. ||~129KI~
       -Diplay hex code on top-left for also directory list except ASCII code.||~129KI~
       -Limit to SBCS for alternative character of "OPT UNICOMB U-xxxx" cmd||~129KI~
       -Explicit "Force" option is required at save when timestamp was changed from loading time.||~129KI~
        Re-enter of PF3 is not effective from now, use "SAVe -Force" or "END -force" cmd.||~129KI~
                                                                      ||~129KI~
     4.Tool.                                                          ||~129KI~
       -(Win)xkp v1.4                                                 ||~129KI~
        Exe name was not fullpath from Windows7, show fullpath.       ||~129KI~
       -xfg v1.20                                                     ||~129KI~
        grep may hungup when srach string is starting with "-".       ||~129KI~
       -(Win)New tool xcfont v1.01 (available from Windows Vista)     ||~129KI~
        It chages font of command prompt.                             ||~129KI~
        Chcp may required depending on font family.                   ||~129KI~
        For example, to view Devanagari script                        ||~129KI~
        Change font like as "xcfont Mangal" after "chcp 57002".       ||~129KI~
        You can see Devaganari(U+0900-097f) on xe.                    ||~129KI~
        For wxe or Linux version you need nothing special.            ||~129KI~
                                                                      ||~129KI~
  .v129L<--129K:(2019/09/18)                                          ||~129KI~
                                                                      ||~129KI~
     1.BUGs                                                           ||~129KI~
       -Bug of function Alt+"/" (<tag > pairing search for xml/html text)||~129KI~
                                                                      ||~129KI~
     2.Additional function.                                           ||~129KI~
       -TC fmt cmd on UTF8 file.                                      ||~129KI~
        accept unicode specification for -D:input splitter and -S:output splitter.||~129KI~
        e.g) tc fmt d\u00c1                                           ||~129KI~
                                                                      ||~129KI~
     3.Miscellaneous.                                                 ||~129KI~
       -(Linux)on debian10, gnome2 is obsoleted.                      ||~129KI~
       -(Linux)PPD api is deprecated at cups-1.6.                     ||~129KI~
       -(Windows)Last line of panel of console version was for IME on Windows95.||~129KI~
                                                                      ||~129KI~
     4.Tool.                                                          ||~129KI~
       -(Windows) xlow (covert case of filename）1.6 (bug corrected)  ||~129KI~
                                                                      ||~129MI~
  .v129M<--129L:(2020/05/17)                                          ||~129MI~
                                                                      ||~129MI~
     1.BUGs                                                           ||~129MI~
       -Function:"Search word on the cursor" (Alt/Ctrl+"["/"]")       ||~129MI~
        e.g) Search "ABC+DEFG" if cusror is on the "+" of "ABC+DEFG", ||~129MI~
        search "ABC" if on the "C".                                   ||~129MI~
        Repeating the same key finds next.                            ||~129MI~
        Intermediate PgDn/PgUp/PgLeft(F10)/PgRight(F11) key looses    ||~129MI~
        concatinated word search effect at start.                     ||~129MI~
       -exe cmd (sequencially execute cmds in the specified file) may crush.||~129MI~
        e.g) xe crush by "exe ! cmdfile" on dir list panel.           ||~129MI~
        "exe ! cmdfile <s *.html" is valid.                           ||~129MI~
       -SORt cmd on dir list panel.                                   ||~129MI~
        Descendant option(/Ot-,/Os-) works but ascendant option(/Ot,/Os) did not.||~129MI~
                                                                      ||~129MI~
     2.Additional function.                                           ||~129MI~
                                                                      ||~129MI~
     3.Miscellaneous.                                                 ||~129MI~
       -Accept Shift+Del on also excluded line(- n line excluded ---).||~129MI~
                                                                      ||~129MI~
     4.Tool.                                                          ||~129MI~
       -xfg v1.21 (Serach string in the directory)                    ||~129MI~
          ./cpu8, /cplc option is added to search by translated string.||~129MI~
          .(Win)"-e" option cause crush.(Temporally file was plased on c:\ which is protected on Windows10)||~129MI~
       -xdig v1.13 (Applay the commands to all files in the directory)||~129MI~
          .Accept parameter sign other than %.                        ||~129MI~
           e.g) By /C$, $fp$ in the cmd string is replaced to fullpath name of the file in the directory.||~129MI~
          .%rp% is added for path name relative to starting directory.||~129MI~
                                                                      ||~129PI~
  .v129N<--129M:(2020/09/23)                                          ||~129PI~
                                                                      ||~129PI~
     1.BUGs                                                           ||~129PI~
       -Cursor positioning failure on comman line for 3 bytes(EUC 8fxxyy) and 4 bytes(GB18030) DBCS.||~129PI~
       -Fails to display combining character(display width=0) on command line.||~129PI~
       -There was conflict on Flag control by Command "OPT unicomb comb" and "UTF file".||~129PI~
       -(Linux) "a"(Attrib) line command on directory list panel may cause crash.||~129PI~
                                                                      ||~129PI~
     2.Additional function.                                           ||~129PI~
                                                                      ||~129PI~
     3.Miscellaneous.                                                 ||~129PI~
       -Fix for Axe(Android version).                                 ||~129PI~
       -(Windows console version) external command (xfg, grep etc.) may freeze xe.||~129PI~
        Issues warnin when detected.                                  ||~129PI~
                                                                      ||~129PI~
     4.Tool.                                                          ||~129PI~
                                                                      ||~129PI~
  .v129P<--129N:(2020/10/28)                                          ||~129PI~
                                                                      ||~129PI~
     1.BUGs                                                           ||~129PI~
       -(Linux) GTK3 version gxe; Screen size was not kept over App restart.||~129PI~
                                                                      ||~129PR~
     2.Additional function.                                           ||~129PI~
       -COL command (Display column gauge to enable setting of tab stop position)||~129PI~
        .COL [on|off] [ALL|type|default]                              ||~129PI~
        .It can be used also on directory list panel.                 ||~129PI~
        .On directory list, "COL on type" sets default gauge type for all member of the directory.||~129PI~
         "COL off" resets it. You have to prepare following gauge file in work directory.||~129PI~
           (Win) ::xe!col!.type   (Linux) ::xe_col_.type              ||~129PI~
        .When Col type is set to a directory, use COL command for each members to set different option.||~129PI~
         "COL [on|off] [type|default]"                                ||~129PI~
            default:display default gauge for the member file.        ||~129PI~
                    This option is not for directory but file.        ||~129PI~
            on     :follows directory setting if new type is not specified.||~129PI~
            off    :hide gauge and reset type for the file,           ||~129PI~
                    and next "COL on" refers directory setting.       ||~129PI~
                                                                      ||~129PR~
     3.Miscellaneous.                                                 ||~129PI~
       -For Manjaro Linux.                                            ||~129PI~
        .Linker's spec was changed and issues error:"duplicated symbol".||~129PI~
        .Function ftime was deprecated.                               ||~129PI~
        .Accept another type of ncurses mouse event input.            ||~129PI~
        .libncursesw is provided, but /usr/include/ncursesw is not provided.||~129PI~
                                                                      ||~129PR~
  .v129Q<--129P:(2020/12/16)                                          ||~v129R~
                                                                      ||~v129R~
     1.BUGs                                                           ||~v129R~
       -(gxe) IME's output always same character.                     ||~v129R~
                                                                   //~1291I~||~v129R~
     3.Miscellaneous.                                                 ||~v129R~
       -(wxe) Handle unprintable character input of UTF8 code by 3rd party IME.||~v129R~
       -/Nm command line switch function was changed.                 ||~v129R~
		  When /Nm is specified, for UTF8 code input to CPLC(non UTF8) file||~v129R~
          set UTF8 code itself if Alt+u ON(indecated by =u=> on command input line),||~v129R~
          set translated locale code if Alt+u OFF(===>) or "?" if translation error occured.||~v129R~
                                                                      ||~v129R~
  .v129R<--129Q:(2020/12/18)                                          ||~v129I~
                                                                      ||~v129I~
     1.BUGs                                                           ||~v129I~
       -(Linux console version) Crashes by mouse drag.                ||~v129I~
                                                                      ||~v129I~
  .v129S<--129R:(2020/12/24)                                          ||~v129I~
                                                                      ||~v129I~
     1.BUGs                                                           ||~v129I~
       -(Linux:gxe) On Gnome desktop, ">"(open console window) command did not work.(gnome-terminal option parameter was deprecated)||~v129I~
       -(Linux:gxe) On Xfce desktop, following Warning may issued.    ||~v129I~
                    Gtk-Warning Calling org.xfce.Session.Manager IsInhibited failed...||~v129I~
                                                                      ||~v129I~
  .v129T<--129S:(2022/12/04)                                          ||~v29TI~
                                                                      ||~v29TI~
     1.BUGs                                                           ||~v29TI~
	   -It can't change sc line on =0.1 screen.                       ||~v29TI~
		Setting for S+C and S+A do no work, and same effect as setting of without S+.||~v29TI~
        Accodingly, Cut & Paste by mouse dose not work.               ||~v29TI~
	   -=Deleting a line on the =0.2 screen causes corrupted key binding.||~v29TI~
                                                                      ||~v29TI~
     2.Additional function.                                           ||~v29TI~
       -Syntax Highlight.                                             ||~v29TI~
		Supports ANSI:reverse attributes of Andre Simon's Highlight and GNU source-highlight.||~v29TI~
		Also, by specifying C_UNDERLINE=R/G_UNDERLINE=R in xesynl.cfg/::xesynl.cfg,||~v29TI~
        you can get reverse effect for underline attribute.           ||~v29TI~
	   -Unicode support for CID prefix.                               ||~v29TI~
	    U-235d(？) is a comment prefix in APL language, CID supports it.||~v29TI~
		You can also set the extensions to apply by specifying the following in the ::xe.ini file:||~v29TI~
          Change_ID_Type_4  = 60 = u-235d= APL                        ||~v29TI~
		With this setting, you can specify APL by CID type like as "CID on APL"||~v29TI~
        When using Unicode, the display width varies depending on the language environment,||~v29TI~
        so be careful when sharing the file.                          ||~v29TI~
        For example, if Windows displays by 2 columns and Linux displays 1 column,||~v29TI~
        the CID tagged to the update line on Windows is not recognized as CID on Linux.||~v29TI~
        So the "cid clear" command on Linux may return 0 rows.        ||~v29TI~
                                                                      ||~v29TI~
     3.Miscellaneous.                                                 ||~v29TI~
	   -Windows Terminal seems to have become the default command prompt PGM in Windows 11.||~v29TI~
        Line commands may cause problems.                             ||~v29TI~
        Use old command prompt PGM c:\Windows\System32\conhost.exe.   ||~v29TI~
	   -Added NOAPPEND option for easier resetting of APPEND in -CID command.||~v29TI~
	   -Support comment description starting with "#" on =0.1 screen. ||~v29TI~
	   -Review =0.2 and =0.3 screen.                                  ||~v29TI~
		Box-line character default is changed and added character by unicode.||~v29TI~
	   -(Win) Changed default location of work directory from C:\ to C:\users\[username]\.||~v29TI~
        If you already have C:\xe_wd, it continue to be used, it is applied from new installation.||~v29TI~
                                                                      ||~v29TI~
  .v129U<--129T:(2022/12/15)                                          ||~v29UI~
                                                                      ||~v29UI~
     1.BUGs                                                           ||~v29UI~
                                                                      ||~v29UI~
     2.Additional function.                                           ||~v29UI~
                                                                      ||~v29UI~
     3.Miscellaneous.                                                 ||~v29UI~
	   -(LNX) In ./configure Automatically detect --enable-libgnome2=yes | no.||~v29UI~
       -(WIN:Console) Supports WindowsTerminal.                       ||~v29UI~
        Corresponds to the difference between WindosTerminal and Conhost.||~v29UI~
        Distortion of the display when entering a line command, display of a binary file, etc.||~v29UI~
                                                                      ||~v29VI~
  .v129V<--129U:(2023/06/10)                                          ||~v29VI~
                                                                      ||~v29VI~
     1.BUGs                                                           ||~v29VI~
                                                                      ||~v29VI~
     2.Additional function.                                           ||~v29VI~
       -(Axe)                                                         ||~v29VI~
        .And.Android 13 (Api-33) compatible.                          ||~v29VI~
        .Shared storage support.                                      ||~v29VI~
           You can set a dedicated folder in the shared storage by "sp add //" command,||~v29VI~
           and access the folder like as "e //Axe".                   ||~v29VI~
           Also, since Android 11 (Api-30), access permission:"All files" can be set.||~v29VI~
           If permission is set, command line tools such as grep and xfg can also access Shared storage.||~v29VI~
        .Correspond to changes in usage environment of .icu library.  ||~v29VI~
                                                                      ||~v29VI~
     3.Miscellaneous.                                                 ||~v29VI~
       -Changed default value of "opt DELZ"(Allow Del line command with no backup) to Off, it is safer side.||~v29VI~
                                                                      ||~v29WR~
  .v129W<--129U:(2023/07/31)                                          ||~v29WR~
                                                                      ||~v29WR~
     1.BUGs                                                           ||~v29WR~
                                                                      ||~v29WR~
     2.Additional function.                                           ||~v29WR~
       -(Axe)                                                         ||~v29WR~
        .Utilize Android-11(R):Api30 permission options : All Files.  ||~v29WR~
        .CD command support                                           ||~v29WR~
                                                                      ||~v29WR~
     3.Miscellaneous.                                                 ||~v29WR~
       -If Shortpath is added by "sp add" command, refresh it and make it effective immediately.||~v29WR~
       -Axe                                                           ||~v29WR~
        .DOS commands (full screen shell) are now not supported.      ||~v29WR~
        ."!" line commands are now not supported.                     ||~v29WR~
                                                                      ||~v29WR~
     4.Tools                                                          ||~v29WR~
       xcv v1.21                                                      ||~v29WR~
       -xfmt v1.5                                                     ||~v29WR~
       -xfg  v1.21                                                    ||~v29WR~
       -xdc  v2.29 -Added UF option (skip print directory timestamp unmatch to unmatch list).||~v29WR~
                                                                      ||~v29XI~
  .v129X<--129W:(2024/02/20)                                          ||~v29XI~
                                                                      ||~v29XI~
     1.BUGs                                                           ||~v29XI~
       -"cv" command with \u option incorrectly converts UNicode>u-ffff.||~v29XR~
       -U+00A0 was not a base character of combining characters.      ||~v29XI~
       -(gxe) may crash.                                              ||~v29XI~
        .When displa a combining character.                           ||~v29XI~
        .When the middle mouse button is pressed.                     ||~v29XI~
        .When "preview" menu button is pressed.                       ||~v29XI~
       -(gxe) box type cursor hides character behind.                 ||~v29XI~
       -grep command (also for "g" line command on directory list).   ||~v29XI~
        .Hangs when double quotes (") in the search string are not closed.||~v29XI~
        .Fails when string contains intermediate spaces.              ||~v29XI~
                                                                      ||~v29XI~
     2.Additional function.                                           ||~v29XI~
	   -Added command line options "-Yv" (default), "-Nv" to specify Unicode display width.||~v29XI~
        "-Nv" displays all characters of ambiguous width in 2 digits. ||~v29XI~
        "-Yv" displays those in one cell for Windows console version xe,||~v29XI~
        Wxe, gxe and xe-linux versions perform internal determination.||~v29XI~
        Font:Consolas is recommended for Windows console version,     ||+v29XI~
        it is monospace and display ambiguous chars  by one cell.     ||+v29XI~
                                                                      ||~v29XI~
     3.Miscellaneous.                                                 ||~v29XI~
       -(Win:Console version) Changing the cursor shape using the Insert key||~v29XI~
        does not work on WindowsTerminal.If necessary,                ||~v29XI~
        start xe on Conhost (previous command prompt executable).     ||~v29XI~
                                                                      ||~v29XI~
     4.Tools                                                          ||~v29XI~
       -xcv  v1.22                                                    ||~v29XI~
         .Added standard input in Hex notation ("-Yh" option)         ||~v29XI~
          and output in Hex notation ("-Yx" option).                  ||~v29XI~
       -xfc  v1.28                                                    ||~v29XI~
         .Added case-insensitive comparison option ("-Nc").           ||~v29XI~
         .Compare positions can now be specified separately           ||~v29XI~
          for both files ( -Mm-n[/p-q] ).                             ||~v29XI~