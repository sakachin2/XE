########################################
tdrv=k
tdir=\src
sdrv=g
### ##########################
MAKEDIR=
PGM1=xe
PGM2=xedumpp
PGM3=xetrcchk
PGM4=xemtrchk
PGM5=xekbchk
PGM6=xesyscmd
PGM7=xe3270
PGM8=xeacb 
PGM9=xeshm #~8A10R~
### ##########################
!IF "$(trace)"=="no"
TRACE=NOTRACE
!ELSE
TRACE=TRACE
!ENDIF

LIBDIR=$(OBJULIB)^\
OBJDIR=$(OBJXE)^\
##for .dep ##########
ULIB=$(ULIBHDIR)^\
#####################################################
!include xe17c.inc  
#######################################################
!include xe.dep
