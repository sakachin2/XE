##############################
VCINC=$(VCINCLUDE)
!IF "$(vc)"=="17c"
W10OPT=/DWIN10
!ENDIF
!IF "$(x64)"=="yes"    
W10OPT=$(W10OPT) /DWIN64
!ELSE 
W10OPT=$(W10OPT) /DWIN32
!ENDIF

INCULIBH=$(ULIBHDIR)
VCLIBPATH=$(VCLIBPATH)
#WD4244=/Wd4244
WD4244=
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
LIBDIR=$(OBJULIB)^\
OBJDIR=$(OBJLIB)^\
INCPATH=/I$(INCULIBH) $(VCINC)
XDA=g:\src\xsub\xda\src

VCLIB=$(VCLIBPATH) AdvAPI32.lib user32.lib shell32.lib

UTF8SUPP=/DUTF8SUPPH /DUTF8EBCD /DUTF8UCS2        #use utf8 .h file

## x86 VC10
LIBPATH=""
!	IF "$(debug)"=="yes"
VC8OPT=/Zi     /D _DEBUG /nologo /X $(WARNLVL) /WX- /Od /Oy- /D _WINDOWS /D STRICT /D _CRT_SECURE_NO_DEPRECATE /D VC10EXP /D _MBCS  /Gm /EHsc /RTC1 /MTd /GS /fp:precise /Zc:wchar_t /Zc:forScope /Gd  /J /we4700  /w34701 /wd4100 /wd4214 /wd4057 /wd4996 /wd4706 /wd4210 /wd4210 $(WD4244) /wd4055 /wd4152  /wd4996 /wd4245 /wd4127 /wd4131 /wd4267 /wd4366 
!	ELSE
VC8OPT=        /D NDEBUG /nologo /X $(WARNLVL) /WX- /Od /Oy- /D _WINDOWS /D STRICT /D _CRT_SECURE_NO_DEPRECATE /D VC10EXP /D _MBCS  /Gm-            /MT  /GS /fp:precise /Zc:wchar_t /Zc:forScope /Gd  /J /we4700  /w34701 /wd4100 /wd4214 /wd4057 /wd4996 /wd4706 /wd4210 /wd4210 $(WD4244) /wd4055 /wd4152  /wd4996 /wd4245 /wd4127 /wd4131 /wd4267 /wd4366 
!	ENDIF	
#########################
EXENAME=$(OBJDIR)$(PGM).exe
MAPNAME=$(OBJDIR)$(PGM).map
CONCAT=

##for .dep ##########
ULIB=g:^\src^\ulib^\
###
OPTASM=/Fa$(TMP)\tmp
###
#debug option ########
DEBUG=/Zi

!IF "$(debug)"=="no"
DEBUG=
LINKDE=
!ELSE      #debug yes
DEBUG=/Zi
LINKDE=/DEBUG
!ENDIF     #debug no/yes

#source output option ########
!IF "$(source)"=="no"
!ELSE
OPTOS2S=/Ls
OPTDOSS=/Fs$(TMP)
!ENDIF

#source output option ########
!IF "$(source)"=="no"
OPTASMW=/Fa$(TMP)\ul
!ELSE       #else SOURCE(no)
!       IF "$(source)"=="nul"
OPTASMW=
!       ELSE            #source not null and not no
OPTASMG=                #gcc
OPTOS2S=/Ls
LISTOS2=/Fl$(TMP)\tmp
OPTDOSS=/Fs$(TMP)\tmp
OPTASM=/Fa$(TMP)\tmp
OPTASMW=/Fa$(TMP)$<
!       ENDIF           #source
!ENDIF          #source=no or else

VCOUT=/OUT:$(EXENAME)
MAPOPT=/MAP:$(MAPNAME)

##############################

.SUFFIXES:

.SUFFIXES: .c

ALL: $(EXENAME)

$(EXENAME):  \
  $(LIBDIR)user.lib \
  $(OBJDIR)$(PGM).OBJ
   @echo ------- link--- $(PGM)
   @echo ------- link--- $(PGM) >>err
   @REM @<<$(PGM).@0
     $(LINKDE) $(VCOUT) $(MAPOPT) $(STCK) $(PMVIO) $(BASE) $(CONCAT)
     $(OBJDIR)$(PGM).OBJ
        $(OS2EXE)
        $(OS2MAP)
        $(LIBDIR)user.lib $(VCLIB)
    $(OS2ENDM)
<<
   LINK.EXE @$(PGM).@0    >err0 2>&1
   @echo ------- link end --- $(PGM)
 @if     exist err0  type err0>>err
 @if     exist err0  type err0>>errall
 @if     exist err0  type err0                                                                                    

#LIST=/Fa
{.}.c{$(OBJDIR)}.obj:
    @echo "********* cpl " $< " ************"
    @echo "********* cpl " $< " ************">>err
		cl /c /DW32 $(VC8OPT) $(UTF8SUPP) /D$(TRACE) $(INCPATH)            /Fo$@ $< >err0 2>&1
 @if     exist err0  type err0>>err
 @if     exist err0  type err0>>errall
 @if     exist err0  type err0
#######
!include xsub.dep
