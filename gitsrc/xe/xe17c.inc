#####################################################
INCULIBH=$(ULIBHDIR) #~8726I~
INCREGEXH=$(ULIBHDIR)\gnuregex #~8726I~
#####################################################
VCINC=$(VCINCLUDE)
!IF "$(vc)"=="17c"
W10OPT=/DWIN10
!ENDIF
!IF "$(x64)"=="yes"    
W10OPT=$(W10OPT) /DWIN64
!ELSE 
W10OPT=$(W10OPT) /DWIN32
!ENDIF

#WD4244=/Wd4244
WD4244=
!IF "$(debug)"=="yes"
WARNLVL=/W4
!ELSE
WARNLVL=/W3
!ENDIF
OSTYPE=win
FTPMOD=$(OBJDIR)xeftp.obj $(OBJDIR)xetso.obj $(OBJDIR)xetso2.obj
GREPMOD=$(OBJDIR)xefcmd27.OBJ
INCPATH=.\ /I$(SDK)\include /I$(VC)\include /I$(INCULIBH) /I$(INCREGEXH) $(VCINC)
EXEPATH=
!IF "$(unicode)"=="yes" #+4408I~
MBCS=/D_UNICODE /DUNICODE
!ELSE #+4408I~
MBCS=/D _MBCS
!ENDIF
#####################################################
EXE1=$(OBJDIR)$(PGM1).exe
EXE2=$(OBJDIR)$(PGM2).exe
EXE3=$(OBJDIR)$(PGM3).exe
EXE4=$(OBJDIR)$(PGM4).exe
EXE5=$(OBJDIR)$(PGM5).exe
EXE6=$(OBJDIR)$(PGM6).exe
EXE7=$(OBJDIR)$(PGM7).exe
EXE8=$(OBJDIR)$(PGM8).exe
#COPT8=/DUTF8SUPP
COPT8=/DUTF8UCS2
MAP1=$(OBJDIR)$(PGM1)$(OSTYPE).map
MAP2=$(OBJDIR)$(PGM2).map
MAP3=$(OBJDIR)$(PGM3).map
MAP4=$(OBJDIR)$(PGM4).map
MAP5=$(OBJDIR)$(PGM5).map
MAP6=$(OBJDIR)$(PGM6).map
MAP7=$(OBJDIR)$(PGM7).map
MAP8=$(OBJDIR)$(PGM8).map
#####################################################
VCOUT1=/OUT:$(EXE1)
VCOUT2=/OUT:$(EXE2)
VCOUT3=/OUT:$(EXE3)
VCOUT4=/OUT:$(EXE4)
VCOUT5=/OUT:$(EXE5)
VCOUT6=/OUT:$(EXE6)
VCOUT7=/OUT:$(EXE7)
VCOUT8=/OUT:$(EXE8)

MAPOPT1=/MAP:$(MAP1)
MAPOPT2=/MAP:$(MAP2)
MAPOPT3=/MAP:$(MAP3)
MAPOPT4=/MAP:$(MAP4)
MAPOPT5=/MAP:$(MAP5)
MAPOPT6=/MAP:$(MAP6)
MAPOPT7=/MAP:$(MAP7)
MAPOPT8=/MAP:$(MAP8)

#STCK=""       default 1MB
STCK=/STACK:4194304
CONCAT=
VCLIB=AdvAPI32.lib user32.lib shell32.lib ImageHlp.lib
###
TMPLST=$(TMP)^\
###
#source output option ########
!IF "$(source)"=="no"
#OPTOS2S=/Ls
#LISTOS2=/Fl$(TMPLST)xe0
#OPTDOSS=/Fs$(TMPLST)xe0
#OPTASM=/Fa$(TMPLST)xe0
#OPTASMW=/Fa$(TMPLST)ul
!ELSE       #else SOURCE(no)
!	IF "$(source)"=="nul"
OPTASMW=
!	ELSE 		#source not null and not no
OPTASMG=                #gcc
OPTOS2S=/Ls
LISTOS2=/Fl$(TMPLST)
OPTDOSS=/Fs$(TMPLST)
OPTASM=/Fa$(TMPLST)
OPTASMW=/Fa$(TMPLST)$<
!	ENDIF   	#source
!ENDIF          #source=no or else
###
#codeview/pm debugger option ########
!IF "$(debug)"=="no"
DEBUG=
LINKDE=
MTOPT=/MT #~8726I~
!ELSE      #else debug=no
DEBUG=/Zi
LINKDE=/DEBUG
MTOPT=/MT
!ENDIF     #endif debug=no

## x86 VC10
!		IF "$(debug)"=="yes"
#VC8OPT=/Zi /D _DEBUG /nologo $(W10OPT) /X $(WARNLVL) /WX- /Od /Oy- /D _WINDOWS /D STRICT /D _CRT_SECURE_NO_DEPRECATE /D VC10EXP  $(MBCS)   /Gm /EHsc /RTC1 /MTd /GS /fp:precise /Zc:wchar_t /Zc:forScope /Gd  /J /we4700  /w34701 /wd4100 /wd4214 /wd4057 /wd4996 /wd4706 /wd4210 /wd4210 $(WD4244) /wd4055 /wd4152  /wd4996 /wd4245 /wd4127 /wd4131 /wd4267 /wd4366 
VC8OPT=/Zi /D _DEBUG /nologo $(W10OPT) /X $(WARNLVL) /WX- /Od /Oy- /D _WINDOWS /D STRICT /D _CRT_SECURE_NO_DEPRECATE /D VC10EXP  $(MBCS)       /EHsc /RTC1 /MTd /GS /fp:precise /Zc:wchar_t /Zc:forScope /Gd  /J /we4700  /w34701 /wd4100 /wd4214 /wd4057 /wd4996 /wd4706 /wd4210 /wd4210 $(WD4244) /wd4055 /wd4152  /wd4996 /wd4245 /wd4127 /wd4131 /wd4267 /wd4366 
!		ELSE
VC8OPT=    /D NDEBUG /nologo $(W10OPT) /X $(WARNLVL) /WX- /Od /Oy- /D _WINDOWS /D STRICT /D _CRT_SECURE_NO_DEPRECATE /D VC10EXP  $(MBCS)   /Gm-            /MT  /GS /fp:precise /Zc:wchar_t /Zc:forScope /Gd  /J /we4700  /w34701 /wd4100 /wd4214 /wd4057 /wd4996 /wd4706 /wd4210 /wd4210 $(WD4244) /wd4055 /wd4152  /wd4996 /wd4245 /wd4127 /wd4131 /wd4267 /wd4366 
!		ENDIF	
WINOPT=/DUTF8SUPPH /DUTF8UCS2 /DUTF8EBCD
.SUFFIXES:

.SUFFIXES: .c

################################
################################
################################
##   xe      xedumpp trcchk  mtrchk  kbchk   syscmd  3270    xeacb
!IF "$(x64)"=="yes"
ALL: $(EXE1)         $(EXE3) $(EXE4) $(EXE5) $(EXE6) $(EXE7) $(EXE8)
!ELSE
ALL: $(EXE1) $(EXE2) $(EXE3) $(EXE4) $(EXE5) $(EXE6) $(EXE7) $(EXE8)
!ENDIF
#ALL: $(EXE1)                         $(EXE5) $(EXE6) $(EXE7) $(EXE8)

$(EXE1):  \
  $(LIBDIR)user.lib \
  $(OBJDIR)$(PGM1).OBJ \
  $(OBJDIR)xecalc.OBJ \
  $(OBJDIR)xecalc2.OBJ \
  $(OBJDIR)xecalc21.OBJ \
  $(OBJDIR)xecalc22.OBJ \
  $(OBJDIR)xecalc3.OBJ \
  $(OBJDIR)xecap.OBJ \
  $(OBJDIR)xecap2.OBJ \
  $(OBJDIR)xechar.OBJ \
  $(OBJDIR)xechar12.OBJ \
  $(OBJDIR)xechar13.OBJ \
  $(OBJDIR)xechar2.OBJ \
  $(OBJDIR)xecsr.OBJ \
  $(OBJDIR)xedcmd.OBJ \
  $(OBJDIR)xedcmd2.OBJ \
  $(OBJDIR)xedcmd3.OBJ \
  $(OBJDIR)xedcmd4.OBJ \
  $(OBJDIR)xedir.OBJ \
  $(OBJDIR)xedir2.OBJ \
  $(OBJDIR)xedir3.OBJ \
  $(OBJDIR)xedir4.OBJ \
  $(OBJDIR)xedlcmd.OBJ \
  $(OBJDIR)xedlcmd2.OBJ \
  $(OBJDIR)xedlcmd3.OBJ \
  $(OBJDIR)xedlcmd4.OBJ \
  $(OBJDIR)xedlcmd5.OBJ \
  $(OBJDIR)xedlcmd6.OBJ \
  $(OBJDIR)xeerr.OBJ \
  $(OBJDIR)xefcmd.OBJ \
  $(OBJDIR)xefcmd2.OBJ \
  $(OBJDIR)xefcmd22.OBJ \
  $(OBJDIR)xefcmd23.OBJ \
  $(OBJDIR)xefcmd24.OBJ \
  $(OBJDIR)xefcmd25.OBJ \
  $(OBJDIR)xefcmd26.OBJ \
  $(OBJDIR)xefcmd27.OBJ \
  $(OBJDIR)xefcmd3.OBJ \
  $(OBJDIR)xefcmd4.OBJ \
  $(OBJDIR)xefcmd42.OBJ \
  $(OBJDIR)xefcmd43.OBJ \
  $(OBJDIR)xefcmd5.OBJ \
  $(OBJDIR)xefcmd6.OBJ \
  $(OBJDIR)xefcmd7.OBJ \
  $(OBJDIR)xefile.OBJ \
  $(OBJDIR)xefile12.OBJ \
  $(OBJDIR)xefile13.OBJ \
  $(OBJDIR)xefile14.OBJ \
  $(OBJDIR)xefile15.OBJ \
  $(OBJDIR)xefile2.OBJ \
  $(OBJDIR)xefile22.OBJ \
  $(OBJDIR)xefile23.OBJ \
  $(OBJDIR)xefile3.OBJ \
  $(OBJDIR)xefile4.OBJ \
  $(OBJDIR)xefile42.OBJ \
  $(OBJDIR)xefile43.OBJ \
  $(OBJDIR)xefile5.OBJ \
  $(OBJDIR)xefile6.OBJ \
  $(OBJDIR)xefile7.OBJ \
  $(OBJDIR)xefsub.OBJ \
  $(OBJDIR)xefsubw.OBJ \
  $(FTPMOD) \
  $(OBJDIR)xefunc.OBJ \
  $(OBJDIR)xefunc2.OBJ \
  $(OBJDIR)xefunct.OBJ \
  $(OBJDIR)xefunct2.OBJ \
  $(OBJDIR)xegbl.OBJ \
  $(OBJDIR)xeini.OBJ \
  $(OBJDIR)xeini2.OBJ \
  $(OBJDIR)xeini3.OBJ \
  $(OBJDIR)xekbd.OBJ \
  $(OBJDIR)xelcmd.OBJ \
  $(OBJDIR)xelcmd2.OBJ \
  $(OBJDIR)xelcmd3.OBJ \
  $(OBJDIR)xelcmd4.OBJ \
  $(OBJDIR)xelcmd5.OBJ \
  $(OBJDIR)xeopt.OBJ \
  $(OBJDIR)xepan.OBJ \
  $(OBJDIR)xepan2.OBJ \
  $(OBJDIR)xepan22.OBJ \
  $(OBJDIR)xepan23.OBJ \
  $(OBJDIR)xepan24.OBJ \
  $(OBJDIR)xepan3.OBJ \
  $(OBJDIR)xescr.OBJ \
  $(OBJDIR)xescr2.OBJ \
  $(OBJDIR)xesub.OBJ \
  $(OBJDIR)xesub2.OBJ \
  $(OBJDIR)xesyn.OBJ \
  $(OBJDIR)xesyn2.OBJ \
  $(OBJDIR)xeundo.OBJ \
     $(OBJDIR)xeopt2.OBJ \
     $(OBJDIR)xeutf.OBJ \
     $(OBJDIR)xeutf2.OBJ \
     $(OBJDIR)xeebc.OBJ \
  xe17c.mak \
  xe17c.inc  
 @echo "link--" "$(EXE1)"
 @echo "link--" "$(EXE1)" >>err
   @REM @<<$(PGM1).@0
     $(LINKDE) $(VCOUT1) $(MAPOPT1) $(STCK) $(SEGM) $(PMVIO) $(BASE) $(CONCAT)
     $(OBJDIR)$(PGM1).OBJ $(CONCAT)
     $(OBJDIR)xecalc.OBJ $(CONCAT)
     $(OBJDIR)xecalc2.OBJ $(CONCAT)
     $(OBJDIR)xecalc21.OBJ $(CONCAT)
     $(OBJDIR)xecalc22.OBJ $(CONCAT)
     $(OBJDIR)xecalc3.OBJ $(CONCAT)
     $(OBJDIR)xecap.OBJ $(CONCAT)
     $(OBJDIR)xecap2.OBJ $(CONCAT)
     $(OBJDIR)xechar.OBJ $(CONCAT)
     $(OBJDIR)xechar12.OBJ $(CONCAT)
     $(OBJDIR)xechar13.OBJ $(CONCAT)
     $(OBJDIR)xechar2.OBJ $(CONCAT)
     $(OBJDIR)xecsr.OBJ $(CONCAT)
     $(OBJDIR)xedcmd.OBJ $(CONCAT)
     $(OBJDIR)xedcmd2.OBJ $(CONCAT)
     $(OBJDIR)xedcmd3.OBJ $(CONCAT)
     $(OBJDIR)xedcmd4.OBJ $(CONCAT)
     $(OBJDIR)xedir.OBJ $(CONCAT)
     $(OBJDIR)xedir2.OBJ $(CONCAT)
     $(OBJDIR)xedir3.OBJ $(CONCAT)
     $(OBJDIR)xedir4.OBJ $(CONCAT)
     $(OBJDIR)xedlcmd.OBJ $(CONCAT)
     $(OBJDIR)xedlcmd2.OBJ $(CONCAT)
     $(OBJDIR)xedlcmd3.OBJ $(CONCAT)
     $(OBJDIR)xedlcmd4.OBJ $(CONCAT)
     $(OBJDIR)xedlcmd5.OBJ $(CONCAT)
     $(OBJDIR)xedlcmd6.OBJ $(CONCAT)
     $(OBJDIR)xeerr.OBJ $(CONCAT)
     $(OBJDIR)xefcmd.OBJ $(CONCAT)
     $(OBJDIR)xefcmd2.OBJ $(CONCAT)
     $(OBJDIR)xefcmd22.OBJ $(CONCAT)
     $(OBJDIR)xefcmd23.OBJ $(CONCAT)
     $(OBJDIR)xefcmd24.OBJ $(CONCAT)
     $(OBJDIR)xefcmd25.OBJ $(CONCAT)
     $(OBJDIR)xefcmd26.OBJ $(GREPMOD) $(CONCAT)
     $(OBJDIR)xefcmd3.OBJ $(CONCAT)
     $(OBJDIR)xefcmd4.OBJ $(CONCAT)
     $(OBJDIR)xefcmd42.OBJ $(CONCAT)
     $(OBJDIR)xefcmd43.OBJ $(CONCAT)
     $(OBJDIR)xefcmd5.OBJ $(CONCAT)
     $(OBJDIR)xefcmd6.OBJ $(CONCAT)
     $(OBJDIR)xefcmd7.OBJ $(CONCAT)
     $(OBJDIR)xefile.OBJ $(CONCAT)
     $(OBJDIR)xefile12.OBJ $(CONCAT)
     $(OBJDIR)xefile13.OBJ $(CONCAT)
     $(OBJDIR)xefile14.OBJ $(CONCAT)
     $(OBJDIR)xefile15.OBJ $(CONCAT)
     $(OBJDIR)xefile2.OBJ $(CONCAT)
     $(OBJDIR)xefile22.OBJ $(CONCAT)
     $(OBJDIR)xefile23.OBJ $(CONCAT)
     $(OBJDIR)xefile3.OBJ $(CONCAT)
     $(OBJDIR)xefile4.OBJ $(CONCAT)
     $(OBJDIR)xefile42.OBJ $(CONCAT)
     $(OBJDIR)xefile43.OBJ $(CONCAT)
     $(OBJDIR)xefile5.OBJ $(CONCAT)
     $(OBJDIR)xefile6.OBJ $(CONCAT)
     $(OBJDIR)xefile7.OBJ $(CONCAT)
     $(OBJDIR)xefsub.OBJ  $(FTPMOD) $(CONCAT)
     $(OBJDIR)xefsubw.OBJ  $(CONCAT)
     $(OBJDIR)xefunc.OBJ $(CONCAT)
     $(OBJDIR)xefunc2.OBJ $(CONCAT)
     $(OBJDIR)xefunct.OBJ $(CONCAT)
     $(OBJDIR)xefunct2.OBJ $(CONCAT)
     $(OBJDIR)xegbl.OBJ $(CONCAT)
     $(OBJDIR)xeini.OBJ  $(CONCAT)
     $(OBJDIR)xeini2.OBJ  $(CONCAT)
     $(OBJDIR)xeini3.OBJ  $(CONCAT)
     $(OBJDIR)xekbd.OBJ  $(CONCAT)
     $(OBJDIR)xelcmd.OBJ $(CONCAT)
     $(OBJDIR)xelcmd2.OBJ $(CONCAT)
     $(OBJDIR)xelcmd3.OBJ $(CONCAT)
     $(OBJDIR)xelcmd4.OBJ $(CONCAT)
     $(OBJDIR)xelcmd5.OBJ $(CONCAT)
     $(OBJDIR)xeopt.OBJ $(CONCAT)
     $(OBJDIR)xepan.OBJ $(CONCAT)
     $(OBJDIR)xepan2.OBJ $(CONCAT)
     $(OBJDIR)xepan22.OBJ $(CONCAT)
     $(OBJDIR)xepan23.OBJ $(CONCAT)
     $(OBJDIR)xepan24.OBJ $(CONCAT)
     $(OBJDIR)xepan3.OBJ $(CONCAT)
     $(OBJDIR)xescr.OBJ $(CONCAT)
     $(OBJDIR)xescr2.OBJ $(CONCAT)
     $(OBJDIR)xesub.OBJ $(CONCAT)
     $(OBJDIR)xesub2.OBJ $(CONCAT)
     $(OBJDIR)xesyn.OBJ $(CONCAT)
     $(OBJDIR)xesyn2.OBJ $(CONCAT)
     $(OBJDIR)xeopt2.OBJ $(CONCAT)
     $(OBJDIR)xeutf.OBJ $(CONCAT)
     $(OBJDIR)xeutf2.OBJ $(CONCAT)
     $(OBJDIR)xeebc.OBJ $(CONCAT)
     $(OBJDIR)xeundo.OBJ
   $(OS2EXE1)
   $(OS2MAP1)           
   $(LIBDIR)user.lib   $(VCLIB)
   $(OS2ENDM)
<<KEEP
   $(EXEPATH)link @$(PGM1).@0  >err0
   copy $(MAP1) $(XE)\$(PGM1)$(OSTYPE).map
 @if     exist err0  type err0>>err
 @if     exist err0  type err0
####################################################

$(EXE2):  \
  $(LIBDIR)user.lib \
  $(OBJDIR)$(PGM2).OBJ \
  $(MAKEF)
	echo --link $(EXE2)
   @REM @<<$(PGM2).@0
     $(LINKDE) $(VCOUT2) $(MAPOPT2) $(STCK) $(PMVIO) $(BASE) $(CONCAT)
     $(OBJDIR)$(PGM2).OBJ
   $(OS2EXE2)
   $(OS2MAP2)
   $(LIBDIR)user.lib $(VCLIB)
   $(OS2ENDM)
<<KEEP

   $(EXEPATH)link @$(PGM2).@0 >err0
 @if     exist err0  type err0>>err
 @if     exist err0  type err0
####################################################

$(EXE3):  \
  $(LIBDIR)user.lib \
  $(OBJDIR)$(PGM3).OBJ \
  $(MAKEF)
	echo --link $(EXE3)
   @REM @<<$(PGM3).@0
     $(LINKDE) $(VCOUT3) $(MAPOPT3) $(STCK) $(PMVIO) $(BASE) $(CONCAT)
     $(OBJDIR)$(PGM3).OBJ
   $(OS2EXE3)
   $(OS2MAP3)
   $(LIBDIR)user.lib $(VCLIB)
   $(OS2ENDM)
<<KEEP

   $(EXEPATH)link @$(PGM3).@0 >err0
 @if     exist err0  type err0>>err
 @if     exist err0  type err0
####################################################

$(EXE4):  \
  $(LIBDIR)user.lib \
  $(OBJDIR)$(PGM4).OBJ \
  $(MAKEF)
	echo --link $(EXE4)
   @REM @<<$(PGM4).@0
     $(LINKDE) $(VCOUT4) $(MAPOPT4) $(STCK) $(PMVIO) $(BASE) $(CONCAT)
     $(OBJDIR)$(PGM4).OBJ
   $(OS2EXE4)
   $(OS2MAP4)
   $(LIBDIR)user.lib $(VCLIB)
   $(OS2ENDM)
<<KEEP

   $(EXEPATH)link @$(PGM4).@0 >err0
 @if     exist err0  type err0>>err
 @if     exist err0  type err0
####################################################

$(EXE5):  \
  $(LIBDIR)user.lib \
  $(OBJDIR)$(PGM5).OBJ \
  $(MAKEF)
	echo --link $(EXE5)
   @REM @<<$(PGM5).@0
     $(LINKDE) $(VCOUT5) $(MAPOPT5) $(STCK) $(SEGM) $(PMVIO) $(BASE) $(CONCAT)
     $(OBJDIR)$(PGM5).OBJ $(CONCAT)
     $(OBJDIR)xecsr.OBJ $(CONCAT)
     $(OBJDIR)xeerr.OBJ $(CONCAT)
     $(OBJDIR)xegbl.OBJ $(CONCAT)
     $(OBJDIR)xekbd.OBJ $(CONCAT)
     $(OBJDIR)xescr.OBJ $(CONCAT)
     $(OBJDIR)xescr2.OBJ $(CONCAT)
     $(OBJDIR)xesub2.OBJ $(CONCAT)
     $(OBJDIR)xeutf.OBJ $(CONCAT)
     $(OBJDIR)xeutf2.OBJ $(CONCAT)
     $(OBJDIR)xeebc.OBJ $(CONCAT)
     $(OBJDIR)xefunc.OBJ $(CONCAT)
     $(OBJDIR)xefunct.OBJ $(CONCAT)
     $(OBJDIR)xefunct2.OBJ $(CONCAT)
     $(OBJDIR)xesub.OBJ
   $(OS2EXE5)
   $(OS2MAP5)
   $(LIBDIR)user.lib $(VCLIB)
   $(OS2ENDM)
<<KEEP

   $(EXEPATH)link @$(PGM5).@0 >err0
 @if     exist err0  type err0>>err
 @if     exist err0  type err0
####################################################


$(EXE6):  \
  $(LIBDIR)user.lib \
  $(OBJDIR)$(PGM6).OBJ \
  $(MAKEF)
	echo --link $(EXE6)
   @REM @<<$(PGM6).@0
     $(LINKDE) $(VCOUT6) $(MAPOPT6) $(STCK) $(PMVIO) $(BASE) $(CONCAT)
     $(OBJDIR)$(PGM6).OBJ
   $(OS2EXE6)
   $(OS2MAP6)
   $(LIBDIR)user.lib $(VCLIB)
   $(OS2ENDM)
<<KEEP
   $(EXEPATH)link @$(PGM6).@0 >err0
 @if     exist err0  type err0>>err
 @if     exist err0  type err0
####################################################

#xe3270
$(EXE7):  \
  $(LIBDIR)user.lib \
  $(OBJDIR)$(PGM7).OBJ \
  $(OBJDIR)xe3270s.OBJ \
  $(OBJDIR)xe3270s2.OBJ \
  $(OBJDIR)xe3270e.OBJ \
  $(OBJDIR)xe3270f.OBJ \
  $(OBJDIR)xe3270f2.OBJ \
  $(LIBDIR)utrace_mt.OBJ \
  $(MAKEF)
	echo --link $(EXE7)
   @REM @<<$(PGM7).@0
     $(LINKDE) $(VCOUT7)  $(MAPOPT7) $(STCK) $(PMVIO) $(BASE) $(CONCAT)
     $(OBJDIR)xe3270s.OBJ $(CONCAT)
     $(OBJDIR)xe3270s2.OBJ $(CONCAT)
     $(OBJDIR)xe3270e.OBJ $(CONCAT)
     $(OBJDIR)xe3270f.OBJ $(CONCAT)
     $(OBJDIR)xe3270f2.OBJ $(CONCAT)
  $(LIBDIR)utrace_mt.OBJ $(CONCAT)
     $(OBJDIR)$(PGM7).OBJ
   $(LIBDIR)user.lib $(VCLIB)
   $(OS2ENDM)
<<KEEP

 @echo link-- $(EXE7)
 @echo link-- $(EXE7) >>err
   $(EXEPATH)link @$(PGM7).@0 >err0
 @if     exist err0  type err0>>err
 @if     exist err0  type err0
################################

OBJACB=$(OBJDIR)xesub2.OBJ 

################################
$(EXE8):  \
  $(LIBDIR)user.lib \
  $(OBJDIR)$(PGM8).OBJ \
  $(MAKEF)
	echo --link $(EXE8)
   @REM @<<$(PGM8).@0
     $(LINKDE) $(VCOUT8) $(MAPOPT8) $(STCK) $(PMVIO) $(BASE) $(CONCAT)
     $(OBJDIR)$(PGM8).OBJ $(OBJACB)
   $(LIBDIR)user.lib $(VCLIB)
<<KEEP

   $(EXEPATH)link @$(PGM8).@0 >err0
#{.}.c{$(OBJDIR)}$(PGM8).obj:
$(OBJDIR)$(PGM8).OBJ:$(PGM8).c
#   $(EXEPATH)cl $(COPT8) /c /W3 /G3 /Gd /J /Od /DW32 /D$(TRACE) $(DEBUG) /I$(INCPATH) /Fr$(TMP) $(OPTASMW) /Fo$@ $(PGM8).c >err0 #~8724R~
	$(EXEPATH)cl $(COPT8) /c $(WARNLVL) /Gd /J /Od /DW32 $(VC8OPT) $(WINOPT) /D$(TRACE) $(DEBUG) /I$(INCPATH) $(OPTASMW) /Fo$@ $(PGM8).c >err0
#######################################################
{.}.c{$(OBJDIR)}.obj:
 @echo cpl---$<
 @echo cpl---$< >>err
   $(EXEPATH)cl /c /DW32 $(VC8OPT) $(WINOPT) /D$(TRACE) /I$(INCPATH) $(OPTASMW) /Fo$@ $< >err0
 @echo cpl end ---$<
 @if     exist err0  type err0>>err
 @if     exist err0  type err0
#######################################################
