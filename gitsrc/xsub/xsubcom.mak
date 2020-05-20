##############################
INCULIBH=g:\src\ulib
#WD4244=/Wd4244
WD4244=
##############################
#MSDIR=m:\micros~1\vc98
!			IF "$(w98)"=="yes"
MSDIR=m:\MICROS~1\vc98
!			ELSE          #not vc98=yes
MSDIR=m:\msdev
!			ENDIF         #vc98
OPTFLAGS=$(optflag)
##############################
!IF "$(trace)"=="no"
TRACE=NOTRACE
!ELSE
TRACE=TRACE
!ENDIF
!IF "$(debug)"=="yes"
WARNLVL="/W4"
!ELSE
WARNLVL="/W3"
!ENDIF
##############################
!IF "$(os)"=="dos"

!       IF "$(dosv)"=="c6"
LIBDIR=h:\c6ulib^\
OBJDIR=h:\c6obj^\
EXEPATH=h:\c6\binr^\
!       ELSE
!               IF "$(dosv)"=="gcc"                 #gcc
LIBDIR=h:\gculib^\
OBJDIR=h:\gcobj^\
OBJDIRU=h:/gcobj/
EXEPATH=h:\djgpp\bin^\              #gcc
!               ELSE                               #gcc else
LIBDIR=d:\ulibdos^\
OBJDIR=d:\ibmc2\obj^\
!               ENDIF                              #gcc
!       ENDIF
DOS=DOS
!ELSE           #not dos
!       IF "$(os)"=="w95"
LIBDIR=$(OBJULIB)^\
OBJDIR=$(OBJLIB)^\
!			IF "$(w98)"=="vc10"
EXEPATH=$(BINPATH)^\
INCPATH=.\ /I$(SDK)\include /I$(VC)\include /I$(INCULIBH)
!			ELSE
LIB=$(MSDIR)\LIB;$(MSDIR)\MFC\LIB;
EXEPATH=$(MSDIR)\bin^\
INCPATH=$(MSDIR)\include /I$(INCULIBH)
!			ENDIF
XDA=g:\src\xsub\xda\src

!IF "$(w98)"=="vc10"
VCLIB=AdvAPI32.lib user32.lib shell32.lib
!ELSE
VCLIB=AdvAPI32.lib user32.lib shell32.lib
!ENDIF

#UTF8SUPP=/DUTF8SUPP                              #utf8
UTF8SUPP=/DUTF8SUPPH /DUTF8EBCD /DUTF8UCS2        #use utf8 .h file

!       ELSE    #os/2
LIBDIR=f:\ulibos2^\
OBJDIR=f:\ibmcpp\obj^\
PMVIO=/PM:VIO
BASE=/Base:0x10000

!       ENDIF
!ENDIF
## x86 VC10
LIBPATH=""
!IF "$(w98)"=="vc10"
!	IF "$(debug)"=="yes"
#VC8OPT=/Zi     /D _DEBUG /nologo /X $(WARNLVL) /WX- /Od /Oy- /D _WINDOWS /D STRICT /D _CRT_SECURE_NO_DEPRECATE /D VC10EXP /D _MBCS  /Gm /EHsc /RTC1 /MTd /GS /fp:precise /Zc:wchar_t /Zc:forScope /Gd  /J /we4700  /w34701 /wd4100 /wd4214 /wd4057 /wd4996 /wd4706 /wd4210 /wd4210 /wd4244 /wd4055 /wd4152  /wd4996 /wd4245 /wd4127 /wd4131 /wd4267 /wd4366 
#VC8OPT=/Zi     /D _DEBUG /nologo /X $(WARNLVL) /WX- /Od /Oy- /D _WINDOWS /D STRICT /D _CRT_SECURE_NO_DEPRECATE /D VC10EXP /D _MBCS  /Gm /EHsc /RTC1 /MTd /GS /fp:precise /Zc:wchar_t /Zc:forScope /Gd  /J /we4700  /w34701 /wd4100 /wd4214 /wd4057 /wd4996 /wd4706 /wd4210 /wd4210 $(WD4244) /wd4055 /wd4152  /wd4996 /wd4245 /wd4127 /wd4131 /wd4267 /wd4366 
VC8OPT=/Zi     /D _DEBUG /nologo /X $(WARNLVL) /WX- /Od /Oy- /D _WINDOWS /D STRICT /D _CRT_SECURE_NO_DEPRECATE /D VC10EXP /D _MBCS       /EHsc /RTC1 /MTd /GS /fp:precise /Zc:wchar_t /Zc:forScope /Gd  /J /we4700  /w34701 /wd4100 /wd4214 /wd4057 /wd4996 /wd4706 /wd4210 /wd4210 $(WD4244) /wd4055 /wd4152  /wd4996 /wd4245 /wd4127 /wd4131 /wd4267 /wd4366 
!	ELSE
#VC8OPT=        /D NDEBUG /nologo /X $(WARNLVL) /WX- /Od /Oy- /D _WINDOWS /D STRICT /D _CRT_SECURE_NO_DEPRECATE /D VC10EXP /D _MBCS  /Gm-            /MT  /GS /fp:precise /Zc:wchar_t /Zc:forScope /Gd  /J /we4700  /w34701 /wd4100 /wd4214 /wd4057 /wd4996 /wd4706 /wd4210 /wd4210 /wd4244 /wd4055 /wd4152  /wd4996 /wd4245 /wd4127 /wd4131 /wd4267 /wd4366 
VC8OPT=        /D NDEBUG /nologo /X $(WARNLVL) /WX- /Od /Oy- /D _WINDOWS /D STRICT /D _CRT_SECURE_NO_DEPRECATE /D VC10EXP /D _MBCS  /Gm-            /MT  /GS /fp:precise /Zc:wchar_t /Zc:forScope /Gd  /J /we4700  /w34701 /wd4100 /wd4214 /wd4057 /wd4996 /wd4706 /wd4210 /wd4210 $(WD4244) /wd4055 /wd4152  /wd4996 /wd4245 /wd4127 /wd4131 /wd4267 /wd4366 
!	ENDIF	
!	IF "$(x64)"=="yes"
LIBPATH=/LIBPATH:"$(SDK)\lib\x64"
!	ELSE
#LIBPATH=/LIBPATH:"$(SDK)\lib" /LIBPATH:"$(VC)\lib"
LIBPATH=/LIBPATH:"$(SDK)\lib"
!	ENDIF
#LIBPATH=/LIBPATH:"$(SDK)\lib\x64" /LIBPATH:"$(VC)\lib\amd64"
!ENDIF	
#########################
EXENAME=$(OBJDIR)$(PGM).exe
MAPNAME=$(OBJDIR)$(PGM).map
!IF "$(os)"=="w95"
CONCAT=
!ELSE
OS2EXE=$(EXENAME)
OS2MAP=$(MAPNAME)
CONCAT=+
OS2ENDM=;
!ENDIF

##for .dep ##########
ULIB=g:^\src^\ulib^\
###
OPTASM=/Fa$(TMP)\tmp
###
#debug option ########
!IF "$(os)"=="os2"
DEBUG=/Ti
!ELSE
DEBUG=/Zi
!ENDIF

!IF "$(debug)"=="no"
DEBUG=
LINKDE=
!ELSE      #debug yes
!       IF "$(os)"=="os2"
DEBUG=/Ti
LINKDE=/CO
!       ELSE      #else os2
!               IF "$(os)"=="w95"
DEBUG=/Zi
LINKDE=/DEBUG
!               ELSE      #dos
!                       IF "$(dosv)"=="gcc"         #gcc
DEBUG=-g                     #gcc
LINKDE=-g                    #gcc
!                       ELSE                        #gcc
DEBUG=/Zi
LINKDE=/CO
!                       ENDIF                       #gcc
!               ENDIF     #endif dos
!       ENDIF     #endif else os2
!ENDIF     #debug no/yes

#source output option ########
!IF "$(source)"=="no"
!ELSE
OPTOS2S=/Ls
OPTDOSS=/Fs$(TMP)
!ENDIF

#source output option ########
!IF "$(source)"=="no"
!       IF "$(w95)"=="vc"
OPTASMW=/Fa$(TMP)\ul
!       ELSE
OPTASMW=-S
!       ENDIF
!ELSE       #else SOURCE(no)
!       IF "$(source)"=="nul"
OPTASMW=
!       ELSE            #source not null and not no
!               IF "$(dosv)"=="gcc"    #gcc
OPTASMG=-S              #gcc
!               ELSE            #else gcc
OPTASMG=                #gcc
OPTOS2S=/Ls
LISTOS2=/Fl$(TMP)\tmp
OPTDOSS=/Fs$(TMP)\tmp
OPTASM=/Fa$(TMP)\tmp
!                       IF "$(w95)"=="vc"
OPTASMW=/Fa$(TMP)$<
!                       ELSE
OPTASMW=-S
!                       ENDIF
!               ENDIF                  #gcc
!       ENDIF           #source
!ENDIF          #source=no or else

!IF "$(os)"=="os2"
STCK=/ST:16384
MAPOPT=/MAP
!ELSE
!       IF "$(os)"=="w95"
#STCK=/STACK:16384
LINKW95=$(OBJDIR)xpw95s.OBJ
VCOUT=/OUT:$(EXENAME)
MAPOPT=/MAP:$(MAPNAME)
!       ELSE
!               IF "$(dosv)"=="gcc"    #gcc
GCCLNK=gcc
STCK=/ST:16000
MAPOPT=-Wl,-Map
CONCAT=
OS2EXE=-o $(EXENAME)
OS2MAP=-Wl,$(MAPNAME)
OS2ENDM=
!               ELSE                  #else gcc=dos
LINKW95=
MAPOPT=/MAP
STCK=/ST:16384
!               ENDIF
!       ENDIF
!ENDIF

##############################
#subpgm
#!IF "$(PGM)"=="xda" 
#SUBOBJ=$(OBJDIR)xdape.obj $(OBJDIR)xdavxd.obj $(OBJDIR)xdavxdit.obj \
# $(OBJDIR)xdalx.obj $(OBJDIR)xdalxr.obj $(OBJDIR)xdane.obj
#!ENDIF
##############################

.SUFFIXES:

.SUFFIXES: .c

ALL: $(EXENAME)

$(EXENAME):  \
  $(LIBDIR)user.lib \
  $(SUBOBJ) \
  $(OBJDIR)$(PGM).OBJ \
  $(PGM).mak
   @echo ------- link--- $(PGM)
   @echo ------- link--- $(PGM) >>err
!IF "$(dosv)"=="gcc"    #gcc
   @echo link---$(PGM)
   @echo link---$(PGM) >>err
    xdig /1err0 /21 /nla //@<<$(PGM).@0
    $(GCCLNK) $(LINKDE) $(MAPOPT) $(OS2MAP) $(OS2EXE) $(OBJDIR)$(PGM).OBJ $(SUBOBJ) $(LIBDIR)user.lib
<<KEEP
   @type  err0
   @type  err0>>err
   @type  err0>>errall
   @type  err
!ELSE                               #gcc
   @REM @<<$(PGM).@0
     $(LINKDE) $(VCOUT) $(MAPOPT) $(STCK) $(PMVIO) $(BASE) $(CONCAT)
     $(OBJDIR)$(PGM).OBJ  $(SUBOBJ)
        $(OS2EXE)
        $(OS2MAP)
        $(LIBDIR)user.lib $(VCLIB)  $(LIBPATH)
    $(OS2ENDM)
<<
!       IF "$(os)"=="os2"
   LINK386.EXE @$(PGM).@0    >err0
!       ELSE
!               IF "$(os)"=="w95"
   echo "=linkp=="   $(LINKDE) $(VCOUT) $(MAPOPT) $(STCK) $(PMVIO) $(BASE) $(CONCAT)     $(OBJDIR)$(PGM).OBJ  $(SUBOBJ)        $(OS2EXE)        $(OS2MAP)        $(LIBDIR)user.lib $(VCLIB)  $(LIBPATH)    $(OS2ENDM)
   echo "=linkp=="   $(LINKDE) $(VCOUT) $(MAPOPT) $(STCK) $(PMVIO) $(BASE) $(CONCAT)     $(OBJDIR)$(PGM).OBJ  $(SUBOBJ)        $(OS2EXE)        $(OS2MAP)        $(LIBDIR)user.lib $(VCLIB)  $(LIBPATH)    $(OS2ENDM) >>err
   $(EXEPATH)LINK.EXE @$(PGM).@0    >err0 2>&1
!               ELSE       #else w95(DOS)
   LINK.EXE @$(PGM).@0   >err0
!               ENDIF     #dos
!       ENDIF
!ENDIF                                  #not gcc
  type err0>>err
  type err0>>errall
  type err0

#LIST=/Fa
{.}.c{$(OBJDIR)}.obj:
    @echo "********* cpl " $< " ************"
    @echo "********* cpl " $< " ************">>err
!IF "$(os)"=="os2"
   ICC.EXE /Ss /Sn $(DEBUG) /D$(TRACE)  /Kabc /C /DOS2 /Fl$(TMP) $(OPTASM) $(OPTOS2S) /Gm /Fo$* $< >err0
!ELSE
!       IF "$(os)"=="w95"
!			IF "$(w98)"=="vc10"	
#$(EXEPATH)cl /c /DW32 $(VC8OPT) $(UTF8SUPP) /D$(TRACE) /I$(INCPATH) $(OPTASMW) /Fo$@ $< >err0
				$(EXEPATH)cl /c /DW32 $(VC8OPT) $(UTF8SUPP) /D$(TRACE) /I$(INCPATH)            /Fo$@ $< >err0 2>&1
!			ELSE
				$(EXEPATH)cl /c $(WARNLVL) /G3 /Gd /J /Od /DW32 $(DEBUG) $(UTF8SUPP) /D$(TRACE) /I$(INCPATH) /I$(XDA) /Fr$(TMP) $(OPTASMW) $(OPTFLAGS) /Fo$@ $< >err0 2>&1
!			ENDIF
!       ELSE       #else w95(DOS)
!               IF "$(dosv)"=="gcc"                #gcc
        xdig /1err0 /21 /nla //@<<gccpf
 gcc -c -funsigned-char -Wall -Wno-conversion -m386 -DDOS -DDPMI -D$(TRACE) $(DEBUG) -o $*.obj $<
<<KEEP
!               ELSE                #gcc not gcc
   cl /c /Od /AL /W2 /Ze /DDOS /D$(TRACE) /Gt256 /DC6 $(OPTDOSS) $(OPTASM) $(DEBUG) /Fo$* $< >err0
!               ENDIF               #gcc or not gcc
!       ENDIF     #dos
!ENDIF
   type err0>>err
   type err0>>errall
   type err0
#######
!include xsub.dep
