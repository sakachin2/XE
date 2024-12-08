########################################
#os2     : nmake "os=os2"             /f xe.mak
#win     : nmake "os=win" "w95=vc"    /f xe.mak
#dos     :  make "os=dos"             /f xe.mak
#dos msc6:  make "os=dos" "dosv=c6"   /f xe.mak
#gcc     :  make "os=dos" "dosv=gcc"  /f xe.mak
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

!IF "$(os)"=="dos"
DOS=DOS
!	IF "$(dosv)"=="c6"
LIBDIR=h:\c6ulib^\
OBJDIR=h:\c6obj^\
!	ELSE
!		IF "$(dosv)"=="gcc"
LIBDIR=h:\gculib^\
OBJDIR=h:\gcobj^\
OBJDIRU=h:/gcobj/
ULIBHDIR=g:\src\ulib
OBJULIB=h:\gculib
OBJXE=h:\gcobj
!		ELSE
LIBDIR=d:\ulibdos^\
OBJDIR=d:\ibmc2\obj^\
!		ENDIF
!	ENDIF
!ELSE     #not DOS
!	IF "$(os)"=="win"
!		IF "$(W95)"=="vc"   #vcc
!			IF "$(W98)"=="vc8" #~8724I~
LIBDIR=$(OBJULIB)^\ #~8724I~
LIBDIRMT=$(OBJULIB)^\ #~8726R~
LIBUSERMT=user.lib
OBJDIRMT=$(OBJXE)^\ #~8726R~
OBJDIR=$(OBJXE)^\ #~8726I~
!			ELSE #~8724I~
!				IF "$(W98)"=="vc10"
LIBDIR=$(OBJULIB)^\ #~8724I~
LIBDIRMT=$(OBJULIB)^\ #~8726R~
LIBUSERMT=user.lib
OBJDIRMT=$(OBJXE)^\ #~8726R~
OBJDIR=$(OBJXE)^\ #~8726I~
!				ELSE #~8724I~
LIBDIR=$(OBJULIB)^\ #~8726I~
LIBDIRMT=$(OBJULIBMT)^\ #~8726R~
LIBUSERMT=usermt.lib
OBJDIRMT=$(OBJXEMT)^\
OBJDIR=$(OBJXE)^\
!				ENDIF
!			ENDIF #~8724I~
!		ELSE                #bcc
LIBDIR=l:\ulibw95^\
OBJDIR=l:\bcobj^\
!		ENDIF
!	ELSE    #os/2
LIBDIR=f:\ulibos2^\
OBJDIR=f:\ibmcpp\obj^\
ULIBHDIR=g:\src\ulib
OBJULIB=f:\ulibos2
OBJXE=f:\ibmcpp\obj
!	ENDIF
!ENDIF
##for .dep ##########
ULIB=$(ULIBHDIR)^\
#####################################################
!include xe.inc  
#######
!include xe.dep
!include xemt.dep
