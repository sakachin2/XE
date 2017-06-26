@rem *** build 64bit all tools with TRACE=off *****************
del errall
del err
set P1=%1
set P2=%2
set P3=%3
call      mkvc64.bat     xads       %p1% %p2% %p3%
rem call  mkvc64.bat     xatrcchk   %p1% %p2% %p3%
rem call  mkvc64.bat     xagp       %p1% %p2% %p3%
call      mkvc64.bat     xbc        %p1% %p2% %p3%
call      mkvc64.bat     xcv        %p1% %p2% %p3%
call      mkvc64.bat     xcvsjisc   %p1% %p2% %p3%
rem call  mkvc64.bat     xdbcsenv   %p1% %p2% %p3%
call      mkvc64.bat     xdc        %p1% %p2% %p3%
call      mkvc64.bat     xdd        %p1% %p2% %p3%
call      mkvc64.bat     xdepgen    %p1% %p2% %p3%
call      mkvc64.bat     xdig       %p1% %p2% %p3%
call      mkvc64.bat     xds        %p1% %p2% %p3%
call      mkvc64.bat     xfc        %p1% %p2% %p3%
call      mkvc64.bat     xff        %p1% %p2% %p3%
call      mkvc64.bat     xfg        %p1% %p2% %p3%
call      mkvc64.bat     xfmt       %p1% %p2% %p3%
call      mkvc64.bat     xfs        %p1% %p2% %p3%
call      mkvc64.bat     xci       %p1% %p2% %p3%
call      mkvc64.bat     xkp        %p1% %p2% %p3%
call      mkvc64.bat     xlibh      %p1% %p2% %p3%
call      mkvc64.bat     xlow       %p1% %p2% %p3%
rem call  mkvc64.bat     xmapcomp   %p1% %p2% %p3%
call      mkvc64.bat     xmj        %p1% %p2% %p3%
call      mkvc64.bat     xpe        %p1% %p2% %p3%
call      mkvc64.bat     xts        %p1% %p2% %p3%
call      mkvc64.bat     xuerpck    %p1% %p2% %p3%
call      mkvc64.bat     xutf8      %p1% %p2% %p3%
call      mkvc64.bat     xver       %p1% %p2% %p3%
echo "xeputty"
rem call      mkvc64.bat     xeputty  /DTESTMAIN /D_WINDOWS %P1% %P2% %P3%
echo "xft"
rem call      mkvc64.batxft             %P1% %P2% %P3%
type err>>errall
type errall
