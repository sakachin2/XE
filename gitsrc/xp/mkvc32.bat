@rem *** make 32bit tool with TRACE=off *****************
call vcenv
@rem del m:\vcobj\xprint.exe
del err
@set msdir=w:\msvs2010\VC
@set exepath=%msdir%\bin

@set OBJULIB=m:\vculib32\rel
@set OBJLIB=m:\vcobj32\rel

@set BINPATH=%msdir%\bin
@set IDE32=w:\msvs2010\common7\IDE
@set PATHO=%PATH%
@set PATH=%BINPATH%;%IDE32%;%PATH%
@set LIB32=%msdir%\lib
@set LIBO=%LIB%
@set LIB=%LIB32%
@set SDK=w:\mssdkw71
@set VC=%MSDIR%
    %exepath%\nmake  "BINPATH=%BINPATH%" "VC=%VC%" "SDK=%SDK%" "trace=no"  "debug=no"  "utf8=yes" "OBJULIB=%OBJULIB%" "OBJULIB=%OBJULIB%" "os=w95" "w98=vc10" "w95=vc" "source=no" %1 %2 /f xprint.mak
@set PATH=%PATHO%
@set LIB=%LIBO%
