@rem ***** make 64bit with option TRACE on  **************************************************
@if     exist err  del  err
@set ULIBHDIR=g:\src\ulib
@set X64=yes
@rem echo mkvc17c64:%PGM%
@rem echo mkvc17c64 parm=:%*
setlocal
call vcenv2017c64.bat
@rem echo 17c64-inc=%INCLUDE%
call parseenv.bat "%INCLUDE%" /I
set VCINCLUDE=%PARSEENV%
call parseenv.bat "%LIB%" /LIBPATH:
set VCLIBPATH=%PARSEENV%
echo VCLIBPATH=%VCLIBPATH%

     nmake "ULIBHDIR=%ULIBHDIR%" "OBJULIB=%OBJULIB%" "OBJLIB=%OBJLIB%" "trace=%TRACE%" "w98=vc10" "vc=17c" "x64=%X64%" "source=no" "debug=%DEBUG%" "PGM=%PGM%" %* /f mkvc17cxsub.mak

endlocal

