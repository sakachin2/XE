@echo ***mkvc22c64r *** %PGM%
set TRACE=no
set DEBUG=no
set OBJULIB=m:\vculib22c64\rel
set OBJLIB=m:\vcobj22c64\rel
set PGM=%1
shift 
@rem %* is not shifted
call .\mkvc22c64.bat %1 %2 %3 %4 %5
