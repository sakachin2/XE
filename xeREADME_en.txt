||*CID:||+129JR~:  2018/05/10                update#=  809;           ||+129JR~
######################################################################
[English]    v1.29J                                                   ||+129JR~

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
                                   http://www.geocities.jp/sakachin2/index.htm
                                   GitHub: sakachin2/XE

For windows, "xe.exe" is console application and "wxe.exe" is GUI application.
   wxe.exe is WTL/ATL application(requires no MFC library) compiled on vs2010Express.
   Thorse are included in w64binGit.zip.
For Linux "xe" is console application and "gxe" is GUI application.
   Untar gxe-x.xx.tar.gz, and make binary by ./configure && make.
Following command line tools are also included.
   xads         For Windows Only,Access to NTFS ADS(Alternative Data Stream).
   xbc          Basic calculator.
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


   xprint       テキストファイルプリントユーティリティ
   gxp          Linux GTKPrint版 xprint

   xprint.exe   text file print program
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
      mkdir ~/xe_wdnnnnn     nnnnn は ユーザーID番号
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
                                                                      ||+129JI~
  .v129J<--129H:(2018/05/10)                                          ||+129JI~
                                                                      ||+129JI~
     1.BUGs                                                           ||+129JI~
                                                                      ||+129JI~
     2.Additional function.                                           ||+129JI~
       -CommandHistoryList.                                           ||+129JI~
        Mouse operation support.                                      ||+129JI~
        .R-button popups context menu.                                ||+129JI~
        .Double click works as "x" cmd(execute the command after closed the command history panel).||+129JI~
        .Click on the selected line works as "s" cmd(set to the command input line after closed the command history panel).||+129JI~
                                                                      ||+129JI~
     3.Miscellaneous.                                                 ||+129JI~
       -Add "CPU8" option to dirlist cmd "="(compare file/directory). ||+129JI~
                                                                      ||+129JI~
     4.Tool.                                                          ||+129JI~
       -xdc v2.29,xfc v1.27                                           ||+129JI~
        Add "CPU8" option.                                            ||+129JI~
                                                                      ||+129JI~
