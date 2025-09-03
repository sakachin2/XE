#################################################
#v7e1:250613 prevent new warinng by cl /wd5292
#################################################
#WD4244=/Wd4244
WD4244=
TMPLST=$(TMP)^\ 
INCULIBH=$(ULIBHDIR)
INCICU=$(ICUHDIR)
INCREGEX=$(ULIBHDIR)\gnuregex
!IF "$(debug)"=="yes"
WARNLVL=/W4
!ELSE
WARNLVL=/W3
!ENDIF
!IF "$(unicode)"=="yes" #+4408I~
MBCS=/D_UNICODE /DUNICODE
!ELSE #+4408I~
MBCS=/D _MBCS
!ENDIF

!IF "$(vc)"=="17c"
W10OPT=/DWIN10
!ENDIF
!IF "$(x64)"=="yes"    
W10OPT=$(W10OPT) /DWIN64
!ELSE 
W10OPT=$(W10OPT) /DWIN32
!ENDIF

VCINC=$(VCINCLUDE)
# "C:\Program Files (x86)\Windows Kits\10\include\10.0.15063.0\ucrt"
# "c:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Tools\MSVC\14.10.25017\include"
# "C:\Program Files (x86)\Windows Kits\10\include\10.0.15063.0\shared"
# "C:\Program Files (x86)\Windows Kits\10\include\10.0.15063.0\um"
# "C:\Program Files (x86)\Windows Kits\10\include\10.0.15063.0\winrt"

# "c:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Tools\MSVC\14.10.25017\ATLMFC\include"
# "C:\Program Files (x86)\Windows Kits\NETFXSDK\4.6.1\include\um"


#VCINC=$(VCINC_1) $(VCINC_2) $(VCINC_3) $(VCINC_4) $(VCINC_5) $(VCINC_6) $(VCINC_7) $(VCINC_8) $(VCINC_9)
#################################################
EXEPATH=
EXELIBPATH=
INCPATH=.\ /I$(INCULIBH) /I$(INCREGEX) /I$(INCICU) $(VCINC)
SHOWINCLUDE=
OUTPATH=$(LIBDIR) #~8724R~

OPTWINMT=/DUTF8SUPPH /DUTF8UCS2 /DUTF8EBCD
OPTWIN=  /DUTF8SUPPH /DUTF8UCS2 /DUTF8EBCD /DNOMT_TRACE


!IF "$(debug)"=="no"
DEBUG=    
LINKDE=
MTOPT=/MT
!ELSE         #debug yes

DEBUG=/Zi
LINKDE=/DEBUG
MTOPT=/MT

!ENDIF
#for VC8 #~8724R~
VC8OPT=/Fr$(TMP) #~8724R~
## x86 VC10
#MACOPT=/P /C
MACOPT=
!	IF "$(debug)"=="yes"
#VC8OPT=$(SHOWINCLUDE) $(W10OPT) $(MACOPT) /Zi /D _DEBUG /nologo /X $(WARNLVL) /WX- /Od /Oy- /D _WINDOWS /D STRICT /D _CRT_SECURE_NO_DEPRECATE /D VC10EXP $(MBCS) /Gm /EHsc /RTC1 /MTd /GS /fp:precise /Zc:wchar_t /Zc:forScope /Gd  /J /we4700  /w34701 /wd4100 /wd4214 /wd4057 /wd4996 /wd4706 /wd4210 /wd4210 $(WD4244) /wd4055 /wd4152  /wd4996 /wd4245 /wd4127 /wd4131 /wd4267 /wd4366 
#VC8OPT=$(SHOWINCLUDE) $(W10OPT) $(MACOPT) /Zi /D _DEBUG /nologo /X $(WARNLVL) /WX- /Od /Oy- /D _WINDOWS /D STRICT /D _CRT_SECURE_NO_DEPRECATE /D VC10EXP $(MBCS)     /EHsc /RTC1 /MTd /GS /fp:precise /Zc:wchar_t /Zc:forScope /Gd  /J /we4700  /w34701 /wd4100 /wd4214 /wd4057 /wd4996 /wd4706 /wd4210 /wd4210 $(WD4244) /wd4055 /wd4152  /wd4996 /wd4245 /wd4127 /wd4131 /wd4267 /wd4366 
VC8OPT=$(SHOWINCLUDE) $(W10OPT) $(MACOPT) /Zi /D _DEBUG /nologo /X $(WARNLVL) /WX- /Od /Oy- /D _WINDOWS /D STRICT /D _CRT_SECURE_NO_DEPRECATE /D VC10EXP $(MBCS)     /EHsc /RTC1 /MTd /GS /fp:precise /Zc:wchar_t /Zc:forScope /Gd  /J /we4700  /w34701 /wd4100 /wd4214 /wd4057 /wd4996 /wd4706 /wd4210 /wd4210 $(WD4244) /wd4055 /wd4152  /wd4996 /wd4245 /wd4127 /wd4131 /wd4267 /wd4366 /wd5292 
!	ELSE
#VC8OPT=$(SHOWINCLUDE) $(W10OPT)    /D NDEBUG /nologo /X $(WARNLVL) /WX- /Od /Oy- /D _WINDOWS /D STRICT /D _CRT_SECURE_NO_DEPRECATE /D VC10EXP $(MBCS)  /Gm-            /MT  /GS /fp:precise /Zc:wchar_t /Zc:forScope /Gd  /J /we4700  /w34701 /wd4100 /wd4214 /wd4057 /wd4996 /wd4706 /wd4210 /wd4210 $(WD4244) /wd4055 /wd4152  /wd4996 /wd4245 /wd4127 /wd4131 /wd4267 /wd4366 
VC8OPT=$(SHOWINCLUDE) $(W10OPT)    /D NDEBUG /nologo /X $(WARNLVL) /WX- /Od /Oy- /D _WINDOWS /D STRICT /D _CRT_SECURE_NO_DEPRECATE /D VC10EXP $(MBCS)  /Gm-            /MT  /GS /fp:precise /Zc:wchar_t /Zc:forScope /Gd  /J /we4700  /w34701 /wd4100 /wd4214 /wd4057 /wd4996 /wd4706 /wd4210 /wd4210 $(WD4244) /wd4055 /wd4152  /wd4996 /wd4245 /wd4127 /wd4131 /wd4267 /wd4366 /wd5292 
!	ENDIF	

#source output option ########
#OPTASM=/Fa$(TMPLST)
!IF "$(source)"=="no"
OPTOS2S=/Ls
LISTOS2=/Fl$(TMPLST)ul
OPTDOSS=/Fs$(TMPLST)ul
                                                                                                                  
OPTASMW=/Fa$(TMPLST)ul

!ELSE     #else source(no)
!	IF "$(source)"=="nul"
OPTOS2S=
LISTOS2=
OPTDOSS=
OPTASM=
OPTASMW=
!	ELSE		#else SOURCE(null)
OPTASMG=
LISTOS2=/Fl$(TMPLST)
OPTDOSS=/Fs$(TMPLST)
OPTASMW=/Fa$(TMPLST)$<

!	ENDIF
!ENDIF
########################################
########################################
########################################
ALL	:$(LIBDIR)user.lib  $(LIBDIR)utils.obj $(LIBDIR)utrace_mt.obj

$(LIBDIR)user.lib:  \
  					$(LIBDIR)u3270.obj   \
  					$(LIBDIR)u32702.obj   \
  					$(LIBDIR)u32703.obj   \
					$(LIBDIR)ueh.obj   \
#	IF "$(x64)"=="yes"    
#	ELSE
					$(LIBDIR)uehmsg.obj   \
#	ENDIF
					$(LIBDIR)uabend.obj	 \
					$(LIBDIR)ualloc.obj   \
					$(LIBDIR)ucalc.obj   \
					$(LIBDIR)ucalc2.obj   \
					$(LIBDIR)ucvebc.obj \
					$(LIBDIR)ucvebc2.obj \
					$(LIBDIR)ucvebc3.obj \
					$(LIBDIR)ucvebc32.obj \
					$(LIBDIR)ucvebc4.obj \
					$(LIBDIR)ucvebct.obj \
					$(LIBDIR)ucvext.obj \
					$(LIBDIR)ucvext12.obj \
					$(LIBDIR)ucvext2.obj \
					$(LIBDIR)ucvucs.obj \
					$(LIBDIR)ucvucst.obj \
!	IF "$(x64)"=="yes"    
!	ELSE
					$(LIBDIR)uda.obj \
					$(LIBDIR)uda2.obj \
					$(LIBDIR)udaits.obj \
					$(LIBDIR)udamt.obj \
					$(LIBDIR)udamtf.obj \
					$(LIBDIR)udap.obj \
					$(LIBDIR)udasub.obj \
!	ENDIF
					$(LIBDIR)udbcschk.obj \
					$(LIBDIR)udbcsck2.obj \
					$(LIBDIR)udos.obj \
					$(LIBDIR)udos2.obj \
					$(LIBDIR)uedit.obj   \
					$(LIBDIR)uedit2.obj   \
!	IF "$(x64)"=="yes"    
!	ELSE
					$(LIBDIR)uehdump.obj   \
!	ENDIF
					$(LIBDIR)uerr.obj	 \
					$(LIBDIR)ufemsg.obj   \
					$(LIBDIR)ufile.obj   \
					$(LIBDIR)ufilew.obj   \
					$(LIBDIR)ufile12.obj   \
					$(LIBDIR)ufile1f.obj \
					$(LIBDIR)ufile2.obj   \
					$(LIBDIR)ufile2f.obj \
					$(LIBDIR)ufile3.obj   \
					$(LIBDIR)ufile3f.obj   \
					$(LIBDIR)ufile4.obj   \
					$(LIBDIR)ufile5.obj   \
					$(LIBDIR)uftp.obj   \
					$(LIBDIR)uftp2.obj   \
					$(LIBDIR)uftp3.obj   \
!IF "$(x64)"=="yes"    
!ELSE
					$(LIBDIR)ufuncmap.obj   \
!ENDIF
					$(LIBDIR)ukbd.obj   \
					$(LIBDIR)ukbdw.obj   \
					$(LIBDIR)umiscf.obj   \
					$(LIBDIR)uparse.obj   \
					$(LIBDIR)upopup.obj   \
					$(LIBDIR)uproc.obj   \
					$(LIBDIR)uproc2.obj   \
					$(LIBDIR)uproc22.obj   \
					$(LIBDIR)uproc3.obj   \
					$(LIBDIR)uproc4.obj   \
					$(LIBDIR)uque.obj     \
					$(LIBDIR)uregex.obj   \
					$(LIBDIR)ustring.obj   \
					$(LIBDIR)ustrcpy.obj   \
					$(LIBDIR)utf.obj      \
					$(LIBDIR)utf2.obj      \
					$(LIBDIR)utf22.obj      \
					$(LIBDIR)utf3.obj      \
					$(LIBDIR)utf4.obj      \
  					$(LIBDIR)utrace.obj   \
					$(LIBDIR)uvio.obj   \
					$(LIBDIR)uvio2.obj   \
					$(LIBDIR)uviom.obj   \
!		IF "$(x64)"=="yes"    
!		ELSE
					$(LIBDIR)uwinsp.obj   \
!		ENDIF    	
					$(LIBDIR)uwinsub.obj   \
					user.mak
  $(EXELIBPATH)LIB     $(LIBDIR)user.lib /LIST:$(LIBDIR)user.map /VERBOSE
#@if     exist err  type err
########################################
########################################
########################################
$(LIBDIR)utils.obj:utils.c
 @echo cpl---utils.c  (NO AR to user.lib)
   $(EXEPATH)cl /c /DW32 $(VC8OPT) $(OPTWIN)   /D$(TRACE) /I$(INCPATH) $(OPTASMW) /Fo$@ utils.c >err0
 @if     exist err0 type err0 >> err
 @if     exist err0 type err0
$(LIBDIR)utrace_mt.obj:utrace.c
 @echo cpl---utrace_mt  (NO AR to user.lib)
	$(EXEPATH)cl /c /DW32 $(VC8OPT) $(OPTWINMT) /D$(TRACE) /I$(INCPATH) $(OPTASMW) /Fo$@ utrace.c >err0
 @if     exist err0 type err0 >> err
 @if     exist err0 type err0
########################################
{.}.c{$(LIBDIR)}.obj:
 @echo cpl---$<
#@echo VCINC=$(VCINC)
#@echo include =$(INCLUDE)
   $(EXEPATH)cl /c /DW32 $(VC8OPT) $(OPTWIN)   /D$(TRACE) /I$(INCPATH) $(OPTASMW) /Fo$@ $< >err0
 @if     exist err0 type err0 >> err
 @if     exist err0 type err0
   @echo lib---$(@F)
    if     exist $(LIBDIR)user.lib $(EXELIBPATH)LIB /OUT:$(LIBDIR)user.lib $(LIBDIR)user.lib $@ >err0
    if not exist $(LIBDIR)user.lib $(EXELIBPATH)LIB /OUT:$(LIBDIR)user.lib $@ >err0
 @if     exist err0 type err0 >> err
 @if     exist err0 type err0
###########################
