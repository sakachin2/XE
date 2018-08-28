@rem *** build 32bit all tools with TRACE=on *****************
del errall
del err
set p1=%1
set p2=%2
set p3=%3
call      mkvct32.bat     xads       %p1% %p2% %p3%
rem call  mkvct32.bat     xatrcchk   %p1% %p2% %p3%
rem call  mkvct32.bat     xagp       %p1% %p2% %p3%
call      mkvct32.bat     xbc        %p1% %p2% %p3%
call      mkvct32.bat     xcfont     %p1% %p2% %p3%
call      mkvct32.bat     xcv        %p1% %p2% %p3%
call      mkvct32.bat     xcvsjisc   %p1% %p2% %p3%
rem call  mkvct32.bat     xdbcsenv   %p1% %p2% %p3%
call      mkvct32.bat     xdc        %p1% %p2% %p3%
call      mkvct32.bat     xdd        %p1% %p2% %p3%
call      mkvct32.bat     xdepgen    %p1% %p2% %p3%
call      mkvct32.bat     xdig       %p1% %p2% %p3%
call      mkvct32.bat     xds        %p1% %p2% %p3%
call      mkvct32.bat     xfc        %p1% %p2% %p3%
call      mkvct32.bat     xff        %p1% %p2% %p3%
call      mkvct32.bat     xfg        %p1% %p2% %p3%
call      mkvct32.bat     xfmt       %p1% %p2% %p3%
call      mkvct32.bat     xfs        %p1% %p2% %p3%
call      mkvct32.bat     xci       %p1% %p2% %p3%
call      mkvct32.bat     xkp        %p1% %p2% %p3%
call      mkvct32.bat     xlibh      %p1% %p2% %p3%
call      mkvct32.bat     xlow       %p1% %p2% %p3%
rem call  mkvct32.bat     xmapcomp   %p1% %p2% %p3%
call      mkvct32.bat     xmj        %p1% %p2% %p3%
call      mkvct32.bat     xpe        %p1% %p2% %p3%
call      mkvct32.bat     xts        %p1% %p2% %p3%
call      mkvct32.bat     xuerpck    %p1% %p2% %p3%
call      mkvct32.bat     xutf8      %p1% %p2% %p3%
call      mkvct32.bat     xver       %p1% %p2% %p3%
echo "xeputty"
rem call      mkvct32.bat     xeputty  /DTESTMAIN /D_WINDOWS %P1% %P2% %P3%
echo "xft"
rem call      mkvct32.batxft             %P1% %P2% %P3%
type err>>errall
type errall
