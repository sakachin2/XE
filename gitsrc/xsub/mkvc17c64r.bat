@echo ***mkvc17c64r *** %PGM%
set TRACE=no
set DEBUG=no
set OBJULIB=m:\vculib17c64\rel
set OBJLIB=m:\vcobj17c64\rel
set PGM=%1
shift 
@rem %* is not shifted
call .\mkvc17c64.bat %1 %2 %3 %4 %5
