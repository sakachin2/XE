@rem ***** make 64bit with option TRACE off **************************************************
del err
@set msdir=w:\msvs2010\VC

@set OBJULIB=m:\vculib64\rel
@rem @set OBJULIBMT=m:\vculibmt64\rel
@set OBJXE=m:\vcobj64\rel
@rem @set OBJXEMT=m:\vcobjmt64\rel
@set ULIBHDIR=g:\src\ulib

@rem x86_amd64:cross compile(run on 32bit mode),amd64:64bit app
@set SDK=w:\mssdkw71
@set WDK=w:\wdk710
@set VC=%MSDIR%
@set EXEPATH64=%msdir%\bin\amd64
@set LIB64=%msdir%\lib\amd64
@set PATHO=%PATH%
@set PATH=%EXEPATH64%;%PATH%
@set LIBO=%LIB%
@set LIB=%LIB64%
@rem echo %PATH%
@set exepath=%msdir%\bin\amd64

rem for nmake  **** vc2010 name
     nmake "BINPATH=%EXEPATH64%" "VC=%VC%" "SDK=%SDK%" "ULIBHDIR=%ULIBHDIR%" "OBJULIB=%OBJULIB%" "OBJULIBMT=%OBJULIBMT%" "OBJXE=%OBJXE%" "OBJXEMT=%OBJXEMT%" "trace=no" "os=win" "w95=vc" "w98=vc10" "x64=yes" "source=no" "debug=no" %1 %2 %3 /f xe.mak   
@rem copy %OBJXE%\xe.exe %OBJXE%\xedbg.exe

@set PATH=%PATHO%
@set LIB=%LIBO%

