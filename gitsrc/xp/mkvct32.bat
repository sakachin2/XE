@rem *** make 32bit tool with TRACE=on *****************
call vcenv
@rem del m:\vcobj32\xprint.exe
del err
@set msdir=w:\msvs2010\VC
@set exepath=%msdir%\bin

@set OBJULIB=m:\vculib32
@set OBJLIB=m:\vcobj32

@set BINPATH=%msdir%\bin
@set IDE32=w:\msvs2010\common7\IDE
@set PATHO=%PATH%
@set PATH=%BINPATH%;%IDE32%;%PATH%
@set LIB32=%msdir%\lib
@set LIBO=%LIB%
@set LIB=%LIB32%
@set SDK=w:\mssdkw71
@set VC=%MSDIR%
    %exepath%\nmake "BINPATH=%BINPATH%" "VC=%VC%" "SDK=%SDK%" "trace=yes"  "debug=yes"  "utf8=yes" "OBJULIB=%OBJULIB%" "OBJULIB=%OBJULIB%" "os=w95" "w98=vc10" "w95=vc" "source=no" %1 %2 /f xprint.mak
@set PATH=%PATHO%
@set LIB=%LIBO%
    type err
