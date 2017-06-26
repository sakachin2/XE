@rem *** make 64bit tool with TRACE=off *****************
rem del err
rem set exepath=m:\msdev\bin\
set exe=%1
@set msdir=w:\msvs2010\VC
@set exepath=%msdir%\bin\amd64
@set BINPATH=%msdir%\bin\amd64
@set SDK=w:\mssdkw71
@set VC=%MSDIR%
@set LIB64=%msdir%\lib\amd64
@set PATHO=%PATH%
@set PATH=%BINPATH%;%PATH%
@set LIBO=%LIB%
@set LIB=%LIB64%

set OBJULIB=m:\vculib64\rel
set OBJLIB=m:\vcobj64\rel
rem for nmake  **** vc2010 name
set nmakepath=m:\micros~1\vc98\bin

rem %exepath%\nmake "os=w95" "w95=vc" "w98=yes" "source=no" "debug=no" /f mkvcxsub.mak "PGM=%1" "optflag=%2 %3 %4"
    %nmakepath%\nmake %FORCEALL% "VC=%VC%" "SDK=%SDK%" "x64=yes" "os=w95" "w95=vc" "w98=vc10" "source=no" "debug=no" "optflag=%2" "trace=no" "PGM=%exe%" /f mkvcxsub.mak
@set LIB=%LIBO%
@set PATH=%PATHO%
