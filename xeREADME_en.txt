||*CID:||+v@@@R~:  2017/06/24                update#=  795;
######################################################################
[English]    v1.29A                                                   ||+v@@@I~

This editor is fit for programmers working on both main-frame and PC. ||+v@@@I~
Its operation is based on mainframe SPF editor,                       ||+v@@@I~
and like as other editor on PC, convenient short-cut key operation is hybrid.||+v@@@I~

    .Available to Windows and Linux.                                  ||+v@@@R~
    .Supports Fixed-Length and Variable-Length record file.           ||+v@@@R~
    .Suppors text file encoded by UTF8 and EBCDIC(requires ICU installation).||+v@@@R~
    .Supports binary file edit. Vertical 2 line and horizontal dump format.||+v@@@R~
    .Filer fuction (apply Delete, Rename, Copy, Move, Execute, ...) is available.||+v@@@R~
    .Supports Remote file access using ftp,samba,rsh,ssh,fuse.        ||+v@@@R~
    .Optionally update-tag:CID(ChangeID) is automatically appended to updated lines.||+v@@@R~

LICENSE: use GNU GPL                                                  ||+v@@@I~

                            By Mizumaki-machi (sakachin2@yahoo.co.jp) ||+v@@@I~
                                                                      ||+v@@@I~
                                   http://hp.vector.co.jp/authors/VA010562||+v@@@I~
                                   http://www.geocities.jp/sakachin2/index.htm||+v@@@I~
                                   GitHub: sakachin2/XE               ||~v@@@I~

For windows, "xe.exe" is console application and "wxe.exe" is GUI application.||+v@@@R~
   wxe.exe is WTL/ATL application(requires no MFC library) compiled on vs2010Express.||+v@@@R~
   Thorse are included in w64binGit.zip.                              ||+v@@@R~
For Linux "xe" is console application and "gxe" is GUI application.   ||+v@@@R~
   Untar gxe-x.xx.tar.gz, and make binary by ./configure && make.     ||+v@@@R~
Following command line tools are also included.                       ||+v@@@R~
   xads         For Windows Only,Access to NTFS ADS(Alternative Data Stream).||+v@@@I~
   xbc          Basic calculator.                                     ||+v@@@I~
   xci          C/C++/Java text file indentation                      ||+v@@@I~
   xcv          Code conversion.                                 ||+124FR~,||+v@@@I~
                EUC,SJIS(Japanese:Shift JIS),Unicode,UTF-8,EBCDIC,Any-Codepage.||+v@@@I~
   xcvsjisc     Convert SJIS in xe's source file to Octal-notation.   ||+v@@@I~
   xdc          directory compare tool                                ||+v@@@I~
   xdd          directory delete tool                                 ||+v@@@I~
   xdig         directory walk utility                                ||+v@@@I~
                tool apply command to all sub-directory/files.        ||+v@@@I~
   xds          Directory size display tool                           ||+v@@@I~
   xfc          File compare tool                                     ||+v@@@I~
   xff          file search by size/timestamp/name.                   ||+v@@@I~
   xfg          Binary file string search & Recursive grep.           ||+v@@@I~
   xfmt         FileLineFormatter. "TC FMT" for huge file.            ||+v@@@I~
   xfs          Split large file,it enable backup large file to       ||+v@@@I~
                diskets.                                              ||+v@@@I~
   xkp          (Windows) display process-id and kill process.        ||+v@@@I~
   xlow         Rename UpperCase file name to LowerCase.              ||+v@@@I~
   xmj          2 file matching.                                      ||+v@@@I~
   xpe          Display comment of errno(libc error code).            ||+v@@@I~
   xts          Set/Display File timestamp                            ||+v@@@I~
   xver         Set ERRORLEVEL from OS version                        ||+v@@@I~
                                                                      ||+v@@@I~

   xprint       テキストファイルプリントユーティリティ
   gxp          Linux GTKPrint版 xprint

   xprint.exe   text file print program                               ||+v@@@I~
   gxp          (Linux)xprint using GTKPrint                          ||+v@@@I~

Other contents.                                                       ||+v@@@R~
  xehelp:
    Html files for Help.                                              ||+v@@@R~
    put it WorkDirectory, set "xehelp=..." environment variable       ||+v@@@R~
    or use -hd commandline parameter.                                 ||+v@@@R~
    Under linux you can put it in /usr/local\/shareLinux(see xelnxe.txt).||+v@@@R~
  sample/doc:                                                         ||+v@@@R~
    Manual text files.                                                ||+v@@@R~
      xej.txt/xee.txt
      xereadmj.txt/xereadme.txt
      xelnxj.txt/xelnxe.txt(For Linux)                                ||+v@@@R~
      xewxej.txt/xewxee.txt(For wxe and gxe)                          ||+v@@@R~
  sample/data:                                                        ||+v@@@R~
      xehosts      setup file for remote access.                      ||+v@@@R~
      xesynw.cfg   (Win)setup file to use syntax highlight.           ||+v@@@R~
      xeebc.map    setup fie for EBCDIC conversion                    ||+v@@@R~
                                                                      ||~v@@@I~
  sample/staff:use following external tools if you have not in hand.  ||+v@@@R~
                                                                      ||~v@@@I~
      grep.exe     It is used by GREp command and =3.14 panel.        ||+v@@@R~
                                                                      ||~v@@@I~
      Select one from following syntax highlight tool and specify it xesynw.cfg||+v@@@R~
      See xee.txt and xesynw.cfg for how-to-use.                      ||+v@@@R~
        gnu-source-highlight.zip                                      ||~v@@@R~
                     (Win)GNU source-highlight v2.9 is compiled on MinGW.||+v@@@R~
        WinHighlight31.copies2.zip                                    ||~v@@@R~
                     andre simon's highlight v3.1                     ||~v@@@R~
                     Put dll in the same folder as exe.               ||+v@@@R~
      putty063.zip                                                    ||+v@@@I~
                     Required when use putty for remote file access.  ||+v@@@I~
                                                                      ||~v@@@I~

How to execute.                                                       ||+v@@@R~

  (Windows)                                                           ||+v@@@R~

  ．Create WorkDirectory, default is c:\xe_wd, avoid default value when c:\ is protected.||+v@@@R~
    e.g)  "mkdir d:\xe_wd"                                            ||+v@@@R~
  ．Put zip file in the WorkDirectory, then unzip it.                 ||+v@@@R~
      copy xehosts etc. from sample\data to the WorkDirectory if you use those function.||+v@@@R~
      Put dummy file consist of one comment line(starting by "#" when you do not use the function.||+v@@@R~
  . Put executable binary on PATH environment valiable.               ||+v@@@R~
      Windows10 case:ControlPanel-->System and Security-->System-->Advanced Setting-->EnvironmentVariable:PATH||+v@@@R~
  . Set WorkDirectory to environment variable xe.                     ||+v@@@R~
      Or, prepare .bat file                                           ||+v@@@R~
      e.g) xe.bat                                                     ||+v@@@R~
               set xe=d:\xe010                                        ||~v@@@R~
               xe.exe                                                 ||~v@@@I~
             OR                                                       ||+v@@@R~
               xe.exe /wd:\xe010                                      ||~v@@@I~
  ．Start by "xe [file-spec]".                                        ||+v@@@R~
      "xe /?" shows commandline parameters.                           ||+v@@@R~
  . Above is also applied to wxe.                                     ||+v@@@R~
                                                                      ||~v@@@I~
  (Linux)                                                             ||+v@@@R~
  .On terminal emulator, install xe.                                  ||+v@@@R~
      tar -zxvf gxe-1.xx.tar.gz                                       ||~v@@@I~
      cd                                                              ||~v@@@I~
      ./configure                                                     ||~v@@@I~
      make                                                            ||~v@@@I~
      sudo make install   -->install to /usr/local/bin                ||+v@@@R~
    See sample/READMEj.txt when install trouble occured.              ||+v@@@R~
    If you want, install manually other binary from src/xsub folder than installed by "make install".||+v@@@R~
  .Create WorkDirectory at home.                                      ||+v@@@R~
      mkdir ~/xe_wdnnnnn     nnnnn は ユーザーID番号                  ||~v@@@I~
    Copy setup files such as xehosts from sample folder to the WorkDirectory if you use the function.||+v@@@R~
    If you do not use the function, create dummy file containing one comment record starting with "#".||+v@@@R~
  ．Start xe by "xe [file-spec]                                       ||+v@@@R~
      "xe -?" shows command line parameter                            ||+v@@@R~
      Terminal emulator defines shortcut key such as  F1, F10 and ModifierKey(Shift/Alt/Ctrl) combination.||+v@@@R~
      If you want use  such key, disable shortcut by terminal emulator settings.||+v@@@R~
  . gxe is no affected terminal emulator setting.                     ||+v@@@R~
                                                                      ||~v@@@I~
######################################################################
## Change History.                                                    ||+v@@@I~
  .v010:(95/06/04)                                                    ||+v@@@I~
        initial release                                               ||+v@@@I~
######################################################################
  .v129A<--129:(2017/06/24)                                           ||+v@@@I~
                                                                      ||+v@@@I~
     1.BUGs                                                           ||+v@@@I~
       -(Windows:64)"&"(spawn executable file) dir cmd crush.         ||+v@@@I~
       -(64Bit) =3.14 crush                                           ||+v@@@I~
                                                                      ||+v@@@I~
     3.Miscellaneous.                                                 ||+v@@@I~
       -(Windows) add "msi" as executable binary extension            ||+v@@@I~
