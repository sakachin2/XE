@rem ***** make 32bit with option TRACE off **************************************************
del err
@set msdir0=w:\msvs2010
@set msdir=%msdir0%\VC

@set OBJULIB=m:\vculib32\rel
@rem @set OBJULIBMT=m:\vculibmt32\rel
@set ULIBHDIR=g:\src\ulib
@rem set ICUHDIR=g:\src\icuwin\include
@set ICUHDIR=g:\src\ulib\icu\include

@set SDK=w:\mssdkw71
@set VC=%msdir%
@set EXEPATH32=%msdir%\bin
@set IDE32=%msdir0%\Common7\IDE
@set LIB32=%msdir%\lib
@set PATHO=%PATH%
@set PATH=%EXEPATH32%;%IDE32%;%PATH%
@set LIBO=%LIB%
@set LIB=%LIB32%
@rem %exepath%\nmake  "ICUHDIR=%ICUHDIR%" "ULIBHDIR=%ULIBHDIR%" "OBJULIB=%OBJULIB%" "OBJULIBMT=%OBJULIBMT%" "trace=no" "os=w95" "w95=vc" "w98=yes" "source=no" "debug=yes" %1 %2 %3 /f user.mak
@rem     nmake  "BINPATH=%EXEPATH32%" "VC=%VC%" "SDK=%SDK%" "ICUHDIR=%ICUHDIR%" "ULIBHDIR=%ULIBHDIR%" "OBJULIB=%OBJULIB%" "OBJULIBMT=%OBJULIBMT%" "trace=no" "os=w95" "w95=vc" "w98=vc10" "source=no" "debug=no" %1 %2 %3 /f user.mak
nmake  "BINPATH=%EXEPATH32%" "VC=%VC%" "SDK=%SDK%" "ICUHDIR=%ICUHDIR%" "ULIBHDIR=%ULIBHDIR%" "OBJULIB=%OBJULIB%" "trace=no" "os=w95" "w95=vc" "w98=vc10" "source=no" "debug=no" %1 %2 %3 /f user.mak
@set PATH=%PATHO%
@set LIB=%LIBO%
