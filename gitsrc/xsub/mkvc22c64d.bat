@echo ***mkvc22c64d *** %PGM%
set TRACE=yes
set DEBUG=yes
set OBJULIB=m:\vculib22c64
set OBJLIB=m:\vcobj22c64
set PGM=%1
shift 
@rem %* is not shifted
call .\mkvc22c64.bat %1 %2 %3 %4 %5
