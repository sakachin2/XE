@rem *** make 64bit tool with TRACE=off *****************
call vcenv
del m:\vcobj\xprint.exe
del err
@set msdir=w:\msvs2010\VC
@set exepath=%msdir%\bin\amd64

@set OBJULIB=m:\vculib64\rel
@set OBJLIB=m:\vcobj64\rel

@set BINPATH=%msdir%\bin\amd64
@set PATHO=%PATH%
@set PATH=%BINPATH%;%PATH%
@set LIB64=%msdir%\lib\amd64
@set LIBO=%LIB%
@set LIB=%LIB64%
@set SDK=w:\mssdkw71
@set VC=%MSDIR%
    %exepath%\nmake "x64=yes" "BINPATH=%BINPATH%" "VC=%VC%" "SDK=%SDK%" "trace=no"  "debug=no"  "utf8=yes" "OBJULIB=%OBJULIB%" "OBJULIB=%OBJULIB%" "os=w95" "w98=vc10" "w95=vc" "source=no" %1 %2 /f xprint.mak
@set PATH=%PATHO%
@set LIB=%LIBO%
