#  //*CID: #+dateR~:                             update#=    7; #~8724R~
######################################## #~8724R~
#v5m0:071015 (UTF)for xprint,partialy release utf function
########################################  
#os2     : nmake "os=os2"             /f ulib.mak
#w95     : nmake "os=w95" "w95=vc"    /f ulib.mak
#dos     :  make "os=dos"             /f ulib.mak
#dos msc6:  make "os=dos" "dosv=c6"   /f ulib.mak
#gcc     :  make "os=dos" "dosv=gcc"  /f ulib.mak
########################################
 #+4408I~
!IF "$(trace)"=="yes"
TRACE=TRACE
!ELSE
TRACE=NOTRACE
!ENDIF

!IF "$(os)"=="os2"	

LIBDIR=f:\ulibos2^\
ULIBHDIR=g:\src\ulib #~8B17I~
OBJULIB=f:\ulibos2 #~8B17I~

!ELSE
!	IF "$(os)"=="w95"	
!		IF "$(W95)"=="vc"	
LIBDIR=$(OBJULIB)^\
LIBDIRMT=$(OBJULIBMT)^\
!		ELSE
LIBDIR=l:\bculib^\
!		ENDIF

!	ELSE
!		IF "$(dosv)"=="c6"	
LIBDIR=h:\c6ulib^\

!		ELSE
!			IF "$(dosv)"=="gcc"	
LIBDIR=h:\gculib^\
LIBDIRU=h:/gculib/
ULIBHDIR=g:\src\ulib #~8B17I~
OBJULIB=h:\gculib #~8B17I~
!			ELSE
LIBDIR=d:\ulibdos^\
!			ENDIF

!		ENDIF
DOS=DOS

!	ENDIF
!ENDIF
#################################################
!include user.inc
################################
!include user.dep
!IF "$(os)"=="w95"	
!include usermt.dep
!ENDIF
