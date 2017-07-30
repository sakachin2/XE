||*CID:||+129BR~:  2017/06/24                update#=  798;           ||+129BR~
######################################################################
[English]    v1.29B

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
