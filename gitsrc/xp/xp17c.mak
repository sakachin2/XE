########################################
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
#WD4244=/Wd4244
WD4244=
!IF "$(debug)"=="yes"
WARNLVL="/W4"
!ELSE
WARNLVL="/W3"
!ENDIF
########################################
PGM=xprint
LIBDIR_WIN=$(OBJULIB)^\
OBJDIR_WIN=$(OBJLIB)^\
ULIB=$(ULIBHDIR)^\                    #utf
ULIBICU=g:\src\ulib\icu\include

!IF "$(utf8)"=="yes"
UTF8SUPP=/DUTF8SUPP /DUTF8SUPPH /DUTF8UCS2 /DUTF8EBCD
!ELSE      #!utf8
UTF8SUPP=
!ENDIF    #!utf8

!IF "$(trace)"=="yes"
TRACE=TRACE
!ELSE
TRACE=NOTRACE
!ENDIF
########################################
BINDIR=$(OBJDIR)
LIBDIR=$(LIBDIR_WIN)                                          #utf
OBJDIR=$(OBJDIR_WIN)                                          #utf
VCLIB=AdvAPI32.lib user32.lib gdi32.lib winspool.lib shell32.lib
INCPATH=/I$(INCULIBH) $(VCINC)
EXENAME=$(BINDIR)$(PGM).exe
MAPNAME=$(BINDIR)$(PGM).map

CONCAT=

#debug option ########

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
OPTASMW=/Fa$(TMP)ul
!ELSE       #else SOURCE(no)
!	IF "$(source)"=="nul"
OPTASMW=
!	ELSE 		#source not null and not no
OPTASMG=                #gcc
OPTOS2S=/Ls
LISTOS2=/Fl$(TMP)
OPTDOSS=/Fs$(TMP)
OPTASM=/Fa$(TMP)
OPTASMW=/Fa$(TMP)$<
!	ENDIF   	#source
!ENDIF          #source=no or else

!		IF "$(utf8)"=="yes"	                                      #utf 
LINKW95=$(OBJDIR)xpw95s.OBJ $(OBJDIR)xpwinp.OBJ $(OBJDIR)xputf.OBJ $(OBJDIR)xpebc.OBJ
!		ELSE
LINKW95=$(OBJDIR)xpw95s.OBJ $(OBJDIR)xpwinp.OBJ $(OBJDIR)xpebc.OBJ
!		ENDIF
VCOUT=/OUT:$(EXENAME)
MAPOPT=/MAP:$(MAPNAME)
LINKJOB=
## x86 VC10
!	IF "$(debug)"=="yes"
VC8OPT=/Zi /D _DEBUG /nologo /X $(WARNLVL) /WX- /Od /Oy- /D _WINDOWS /D STRICT /D _CRT_SECURE_NO_DEPRECATE /D VC10EXP /D _MBCS  /Gm /EHsc /RTC1 /MTd /GS /fp:precise /Zc:wchar_t /Zc:forScope /Gd  /J /we4700  /w34701 /wd4100 /wd4214 /wd4057 /wd4996 /wd4706 /wd4210 /wd4210 $(WD4244) /wd4055 /wd4152  /wd4996 /wd4245 /wd4127 /wd4131 /wd4267 /wd4366 
!	ELSE
VC8OPT=    /D NDEBUG /nologo /X $(WARNLVL) /WX- /Od /Oy- /D _WINDOWS /D STRICT /D _CRT_SECURE_NO_DEPRECATE /D VC10EXP /D _MBCS  /Gm-            /MT  /GS /fp:precise /Zc:wchar_t /Zc:forScope /Gd  /J /we4700  /w34701 /wd4100 /wd4214 /wd4057 /wd4996 /wd4706 /wd4210 /wd4210 $(WD4244) /wd4055 /wd4152  /wd4996 /wd4245 /wd4127 /wd4131 /wd4267 /wd4366 
!	ENDIF	

.SUFFIXES:

.SUFFIXES: .c

ALL: $(EXENAME)

$(EXENAME):  \
  $(LIBDIR)user.lib \
  $(OBJDIR)xprint.OBJ \
  $(OBJDIR)xp2p.OBJ \
  $(OBJDIR)xpdesp.OBJ \
  $(OBJDIR)xpesc.OBJ \
  $(OBJDIR)xphex.OBJ \
  $(OBJDIR)xphlp.OBJ \
  $(OBJDIR)xpinp.OBJ \
  $(OBJDIR)xpmult.OBJ \
  $(OBJDIR)xppf.OBJ \
  $(OBJDIR)xpsub1.OBJ \
!IF "$(utf8)"=="yes"	            #utf
  $(OBJDIR)xputf.OBJ \
!ENDIF
  $(OBJDIR)xpw95s.OBJ \
  $(OBJDIR)xpwinp.OBJ \
  $(OBJDIR)xpebc.OBJ \
  xprint.mak
   @REM @<<xprint.@0
     $(LINKDE) $(VCOUT) $(MAPOPT) $(STCK) $(PMVIO) $(BASE) $(LIBPATHvc10) $(CONCAT)
     $(OBJDIR)xprint.OBJ  $(CONCAT)
     $(OBJDIR)xp2p.OBJ  $(CONCAT)
     $(OBJDIR)xpdesp.OBJ   $(CONCAT)
     $(OBJDIR)xpesc.OBJ   $(CONCAT)
     $(OBJDIR)xphlp.OBJ   $(CONCAT)
     $(OBJDIR)xphex.OBJ   $(CONCAT)
     $(OBJDIR)xpinp.OBJ   $(LINKJOB) $(CONCAT)
     $(OBJDIR)xpsub1.OBJ  $(CONCAT) 
     $(OBJDIR)xppf.OBJ  $(CONCAT) 
     $(OBJDIR)xpmult.OBJ  $(LINKW95)
	$(OS2EXE)
	$(OS2MAP)
	$(LIBDIR)user.lib $(VCLIB)
    $(OS2ENDM)
<<
   @echo link---$(PGM)
   @echo link---$(PGM) >>err
   LINK.EXE @xprint.@0    >err0    2>&1
  type err0>>err
  type err

#LIST=/Fa
{.}.c{$(OBJDIR)}.obj:
   cl /c /DW32 $(W10OPT) $(VC8OPT) $(UTF8SUPP) /D$(TRACE) $(INCPATH)        /Fo$@ $< >err0
   type err0>>err
   type err0
#######
!include xp.dep
