@rem *** make 32bit tool with TRACE=off *****************
rem del err
rem set exepath=m:\msdev\bin\
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

set OBJULIB=m:\vculib32\rel
set OBJLIB=m:\vcobj32\rel
rem for nmake  **** vc2010 name
@rem set nmakepath=m:\micros~1\vc98\bin
set nmakepath=w:\msvs2010\VC\bin
@rem set |grep -i PATH
rem %exepath%\nmake "os=w95" "w95=vc" "w98=yes" "source=no" "debug=no" /f mkvcxsub.mak "PGM=%1" "optflag=%2 %3 %4"
%nmakepath%\nmake %FORCEALL% "BINPATH=%BINPATH%" "VC=%VC%" "SDK=%SDK%" "os=w95" "w95=vc" "w98=vc10" "source=no" "debug=no" "optflag=%2" "trace=no" "PGM=%exe%" /f mkvcxsub.mak
@set LIB=%LIBO%
@set PATH=%PATHO%
