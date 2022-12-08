@rem ***** make 64bit with option TRACE on  **************************************************
@if     exist err  del  err
@set ULIBHDIR=g:\src\ulib
@set X64=yes
@rem echo mkvc22c64:%PGM%
@rem echo mkvc22c64 parm=:%*
setlocal
call vcenv2022c64.bat
@rem echo 22c64-inc=%INCLUDE%
call parseenv.bat "%INCLUDE%" /I
set VCINCLUDE=%PARSEENV%
call parseenv.bat "%LIB%" /LIBPATH:
set VCLIBPATH=%PARSEENV%
echo VCLIBPATH=%VCLIBPATH%

     nmake "ULIBHDIR=%ULIBHDIR%" "OBJULIB=%OBJULIB%" "OBJLIB=%OBJLIB%" "trace=%TRACE%" "w98=vc10" "vc=22c" "x64=%X64%" "source=no" "debug=%DEBUG%" "PGM=%PGM%" %* /f mkvc22cxsub.mak

endlocal

