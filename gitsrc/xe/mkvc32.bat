@rem ***** make 32bit with option TRACE off **************************************************
del err
@set msdir0=w:\msvs2010
@set msdir=%msdir0%\VC

@set OBJULIB=m:\vculib32\rel
@rem set OBJULIBMT=m:\vculib32
@set OBJXE=m:\vcobj32\rel
@rem set OBJXEMT=m:\vcobj32
@set ULIBHDIR=g:\src\ulib

@rem x86_amd64:cross compile(run on 32bit mode),amd64:64bit app
@set SDK=w:\mssdkw71
@set WDK=w:\wdk710
@set VC=%MSDIR%
@set EXEPATH32=%msdir%\bin
@set IDE32=%msdir0%\Common7\IDE
@set LIB32=%msdir%\lib
@set PATHO=%PATH%
@set PATH=%EXEPATH32%;%IDE32%;%PATH%
@set LIBO=%LIB%
@set LIB=%LIB32%
@rem echo %PATH%
@set exepath=%msdir%\bin\amd64

@rem set nmakepath=%WDK%\bin\x86
@rem nmakepath=%EXEPATH32%
@rem     %nmakepath%\nmake "EXEPATH64=%EXEPATH64%" "VC=%VC%" "SDK=%SDK%" "ULIBHDIR=%ULIBHDIR%" "OBJULIB=%OBJULIB%" "OBJULIBMT=%OBJULIBMT%" "OBJXE=%OBJXE%" "OBJXEMT=%OBJXEMT%" "trace=yes" "os=win" "w95=vc" "w98=yes" "x64=yes" "source=no" "debug=yes" %1 %2 %3 /f xe.mak   
set
nmake "BINPATH=%EXEPATH32%" "VC=%VC%" "SDK=%SDK%" "ULIBHDIR=%ULIBHDIR%" "OBJULIB=%OBJULIB%" "OBJXE=%OBJXE%" "trace=no" "os=win" "w95=vc" "w98=vc10" "source=no" "debug=no" %1 %2 %3 /f xe.mak   
copy %OBJXE%\xe.exe %OBJXE%\xedbg.exe

@set PATH=%PATHO%
@set LIB=%LIBO%

