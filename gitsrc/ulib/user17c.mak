######################################## #~8724R~
!IF "$(trace)"=="yes"
TRACE=TRACE
!ELSE
TRACE=NOTRACE
!ENDIF

LIBDIR=$(OBJULIB)^\

INCLUDE=$(INCLUDE)

#################################################
!include user17c.inc
################################
!include user.dep
