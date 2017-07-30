@rem ***** make 64bit with option TRACE on  **************************************************
del err
@set ULIBHDIR=g:\src\ulib

setlocal
call vcenv2017c64.bat
@rem echo 17c64-inc=%INCLUDE%
call parseenv.bat "%INCLUDE%" /I
set VCINCLUDE=%PARSEENV%
echo vcinc=%VCINCLUDE%
echo libpath=%LIBPATH%
echo lib=%LIB%
@rem echo trace=%TRACE%
@rem echo debug=%DEBUG%

echo     nmake "ULIBHDIR=%ULIBHDIR%" "OBJULIB=%OBJULIB%" "OBJXE=%OBJXE%" "trace=%TRACE%" "w98=vc10" "vc=17c" "x64=yes" "source=no" "debug=%DEBUG%" %* /f xe17c.mak   
     nmake "ULIBHDIR=%ULIBHDIR%" "OBJULIB=%OBJULIB%" "OBJXE=%OBJXE%" "trace=%TRACE%" "w98=vc10" "vc=17c" "x64=yes" "source=no" "debug=%DEBUG%" %* /f xe17c.mak   

endlocal

copy %OBJXE%\xe.exe %OBJXE%\xedbg.exe

