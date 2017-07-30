@echo ***mkvc17c64d *** %PGM%
set TRACE=yes
set DEBUG=yes
set OBJULIB=m:\vculib17c64
set OBJLIB=m:\vcobj17c64
set PGM=%1
shift 
@rem %* is not shifted
call .\mkvc17c64.bat %1 %2 %3 %4 %5
