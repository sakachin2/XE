del err
@rem @rem goto :nx1
@rem @set PATHO=%PATH%
@rem @set LIBO=%LIB%
@rem @set LIBPATHO=%LIBPATH%
@rem @set INCO=%INCLUDE%
@rem setlocal

call vcenv2017c64.bat
@rem echo 17c64-inc=%INCLUDE%
call parseenv.bat "%INCLUDE%" /I
set VCINCLUDE=%PARSEENV%

@set ULIBHDIR=g:\src\ulib
@set ICUHDIR=g:\src\ulib\icu\include

@rem goto :nx1
@rem @rem split %INCLUDE to %VCINC_nn% because concatinated value is too long as bat file
@rem call parseenv.bat "%INCLUDE%" /I VCINC
@rem echo on
@rem for /l %%j in (1,1,%PARSEENV_CTR%) do (
@rem @rem    echo v=!PARSEENV_%%j!
@rem     call set VCINC_%%j=%%PARSEENV_%%j%%
@rem     call echo %%VCINC_%%j%%
@rem     )
@rem endlocal
@rem echo vcinc7=%VCINC_7%
@rem echo vcinc_7=%VCINC_7%
@rem :nx1

@rem which nmake.exe
	nmake  "ICUHDIR=%ICUHDIR%" "ULIBHDIR=%ULIBHDIR%" "OBJULIB=%OBJULIB%" "trace=%TRACE%" "w98=vc10" "vc=17c" "x64=yes" "source=no" "debug=%DEBUG%" %* /f user17c.mak

@rem endlocal
@rem @set PATH=%PATHO%
@rem @set LIB=%LIBO%
@rem @set LIBPATH=%LIBPATHO%
@rem @set INCLUDE=%INCO%
