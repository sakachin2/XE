@rem ***** make 64bit with option TRACE on **************************************************
del err
@rem cpldbg  W:\msvs2010\VC\bin\x86_amd64\CL.exe /c /Zi /nologo /W4 /WX- /Od /Oy- /D TRACE /D WIN32 /D _WINDOWS /D STRICT /D _DEBUG /D W32 /D _CRT_SECURE_NO_DEPRECATE /D WXE /D UTF8SUPPH /D UTF8UCS2 /D UTF8EBCD /D NOMT_TRACE /D VC10EXP /D _MBCS /D _ATL_STATIC_REGISTRY /Gm /EHsc /RTC1 /MTd /GS /fp:precise /Zc:wchar_t /Zc:forScope /Fo"Debug\\" /Fd"Debug\vcWindows7.1SDK.pdb" /Gd /TP /errorReport:prompt g:\src\mfc\wxe2010\MainFrm.cpp g:\src\mfc\wxe2010\stdafx.cpp g:\src\mfc\wxe2010\wxe.cpp g:\src\mfc\wxe2010\wxedlg.cpp g:\src\mfc\wxe2010\wxedoc.cpp g:\src\mfc\wxe2010\wxefile.cpp g:\src\mfc\wxe2010\wxekbd.cpp g:\src\mfc\wxe2010\wxemain.cpp g:\src\mfc\wxe2010\wxemouse.cpp g:\src\mfc\wxe2010\wxepage.cpp g:\src\mfc\wxe2010\wxeprt.cpp g:\src\mfc\wxe2010\wxescr.cpp g:\src\mfc\wxe2010\wxeview.cpp /J /we4700  /w34701 /wd4100 /wd4214 /wd4057 /wd4996 /wd4706 /wd4210 /wd4210 /wd4244 /wd4055 /wd4152  /wd4996 /wd4245 /wd4127 /wd4131 /wd4267 /wd4366 
@rem linkdbg W:\msvs2010\VC\bin\x86_amd64\link.exe /ERRORREPORT:PROMPT /OUT:"Debug\wxe.exe" /INCREMENTAL /NOLOGO Htmlhelp.Lib Imm32.Lib atlthunk.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /MANIFEST /ManifestFile:"Debug\wxe.exe.intermediate.manifest" /MANIFESTUAC:"level='asInvoker' uiAccess='false'" /DEBUG /PDB:"W:\msvs2010Projects\wxe\wxe\Debug\wxe.pdb" /MAP /SUBSYSTEM:WINDOWS /TLBID:1 /DYNAMICBASE /NXCOMPAT /IMPLIB:"Debug\wxe.lib" /MACHINE:X64 Debug\wxe.res
@set msdir=w:\msvs2010\VC

@set OBJULIB=m:\vculib64
@rem @set OBJULIBMT=m:\vculibmt64
@set ULIBHDIR=g:\src\ulib
@rem set ICUHDIR=g:\src\icuwin\include
@set ICUHDIR=g:\src\ulib\icu\include

@rem x86_amd64:cross compile(run on 32bit mode),amd64:64bit app
@set SDK=w:\mssdkw71
@set VC=%MSDIR%
@set EXEPATH64=%msdir%\bin\amd64
@set LIB64=%msdir%\lib\amd64
@set PATHO=%PATH%
@set PATH=%EXEPATH64%;%PATH%
@set LIBO=%LIB%
@set LIB=%LIB64%
@rem echo %PATH%
@set exepath=%msdir%\bin\amd64
@rem %exepath%\nmake  "ICUHDIR=%ICUHDIR%" "ULIBHDIR=%ULIBHDIR%" "OBJULIB=%OBJULIB%" "OBJULIBMT=%OBJULIBMT%" "trace=no" "os=w95" "w95=vc" "w98=yes" "source=no" "debug=yes" %1 %2 %3 /f user.mak
@rem    nmake  "BINPATH=%EXEPATH64%" "VC=%VC%" "SDK=%SDK%" "ICUHDIR=%ICUHDIR%" "ULIBHDIR=%ULIBHDIR%" "OBJULIB=%OBJULIB%" "OBJULIBMT=%OBJULIBMT%" "trace=yes" "os=w95" "w95=vc" "w98=vc10" "x64=yes" "source=no" "debug=yes" %* /f user.mak
nmake  "BINPATH=%EXEPATH64%" "VC=%VC%" "SDK=%SDK%" "ICUHDIR=%ICUHDIR%" "ULIBHDIR=%ULIBHDIR%" "OBJULIB=%OBJULIB%" "trace=yes" "os=w95" "w95=vc" "w98=vc10" "x64=yes" "source=no" "debug=yes" %1 %2 %3 /f user.mak
@set PATH=%PATHO%
@set LIB=%LIBO%
