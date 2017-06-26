@rem *** make 32bit tool with TRACE=on *****************
rem del err
@rem set exepath=m:\msdev\bin\
set exe=%1
@set msdir=w:\msvs2010\VC
@set BINPATH=%msdir%\bin
@set SDK=w:\mssdkw71
@set VC=%MSDIR%
@set IDE32=w:\msvs2010\common7\IDE
@set LIB32=%msdir%\lib
@set PATHO=%PATH%
@set PATH=%BINPATH%;%IDE32%;%PATH%
@set LIBO=%LIB%
@set LIB=%LIB32%

set OBJULIB=m:\vculib32
set OBJLIB=m:\vcobj32
rem for nmake  **** vc2010 name
set nmakepath=w:\msvs2010\VC\bin
rem set |grep -i PATH
rem %exepath%\nmake "os=w95" "w95=vc" "w98=yes" "source=no" "debug=no" /f mkvcxsub.mak "PGM=%1" "optflag=%2 %3 %4"
%nmakepath%\nmake %FORCEALL% "BINPATH=%BINPATH%" "VC=%VC%" "SDK=%SDK%" "os=w95" "w95=vc" "w98=vc10" "source=no" "debug=yes" "optflag=%2" "trace=y" "PGM=%exe%" /f mkvcxsub.mak
@set LIB=%LIBO%
@set PATH=%PATHO%
