@rem ***** make 64bit with option TRACE on  **************************************************
del err
@set ULIBHDIR=g:\src\ulib
@set X64=yes

setlocal
call vcenv2022c64.bat
@rem echo 22c64-inc=%INCLUDE%
call parseenv.bat "%INCLUDE%" /I
set VCINCLUDE=%PARSEENV%

echo vcinc=%VCINCLUDE%
echo libpath=%LIBPATH%
echo lib=%LIB%

     nmake "utf8=yes" "ULIBHDIR=%ULIBHDIR%" "OBJULIB=%OBJULIB%" "trace=%TRACE%" "w98=vc10" "vc=22c" "x64=%X64%" "source=no" "debug=%DEBUG%" %* /f xp22c.mak   
@if exist err0    type err0
@if exist err     type err 
endlocal

