@rem *** rebuild 32bit all tools with TRACE=on and option /A *****************
set FORCEALL=/A
call mkvct32all.bat %1 %2 %3
set FORCEALL=
