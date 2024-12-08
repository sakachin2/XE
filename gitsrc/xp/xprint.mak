########################################
INCULIBH=g:\src\ulib
#WD4244=/Wd4244
WD4244=
!IF "$(debug)"=="yes"
WARNLVL="/W4"
!ELSE
WARNLVL="/W3"
!ENDIF
########################################
#MSDIR=m:\micros~1\vc98
!			IF "$(w98)"=="yes"
MSDIR=m:\MICROS~1\vc98
!			ELSE          #not vc98=yes
MSDIR=m:\msdev
!			ENDIF         #vc98
########################################
#os2     : nmake "os=os2"             /f xprint.mak
#w95     : nmake "os=w95" "w95=vc"    /f xprint.mak
#dos msc6:  make "os=dos" "dosv=c6"   /f xprint.mak
#dos gcc :  make "os=dos" "dosv=gcc"  /f xprint.mak
########################################
!IF "$(utf8)"=="yes"

PGM=xprint
#LIBDIR_WIN=m:\vcutfulib^\               #utf
LIBDIR_WIN=$(OBJULIB)^\
OBJDIR_WIN=$(OBJLIB)^\
BINDIR_WIN=$(OBJLIB)^\
ULIB=g:^\src^\ulib^\                    #utf
UTF8SUPP=/DUTF8SUPP /DUTF8SUPPH /DUTF8UCS2 /DUTF8EBCD

!ELSE      #!utf8

PGM=xprint
LIBDIR_WIN=$(OBJULIB)^\
OBJDIR_WIN=$(OBJLIB)^\
BINDIR_WIN=$(OBJLIB)^\
ULIB=g:^\src^\ulib^\                    #utf
UTF8SUPP=

!ENDIF    #!utf8

!IF "$(trace)"=="yes"
TRACE=TRACE
!ELSE
TRACE=NOTRACE
!ENDIF
ULIBICU=g:\src\ulib\icu\include
########################################
BINDIR=$(OBJDIR)
!IF "$(os)"=="dos"	

!	IF "$(dosv)"=="c6"	
LIBDIR=h:\c6ulib^\
OBJDIR=h:\c6obj^\
EXEPATH=h:\c6\binr^\
!	ELSE    
!		IF "$(dosv)"=="gcc"	            #gcc
LIBDIR=h:\gculib^\
OBJDIR=h:\gcobj^\
OBJDIRU=h:/gcobj/
EXEPATH=h:\djgpp\bin^\              #gcc
!		ELSE                               #gcc else
LIBDIR=d:\ulibdos^\
OBJDIR=d:\ibmc2\obj^\
!		ENDIF                              #gcc
!	ENDIF

DOS=DOS
!ELSE     #else DOS
!	IF "$(os)"=="w95"
LIBDIR=$(LIBDIR_WIN)                                          #utf
OBJDIR=$(OBJDIR_WIN)                                          #utf
BINDIR=$(BINDIR_WIN)                                          #utf
#VCLIB=user32.lib gdi32.lib winspool.lib shell32.lib
VCLIB=AdvAPI32.lib user32.lib gdi32.lib winspool.lib shell32.lib
!			IF "$(w98)"=="vc10"
EXEPATH=$(BINPATH)^\
INCPATH=.\ /I$(SDK)\include /I$(VC)\include /I$(INCULIBH)
!				IF "$(x64)"=="yes"
LIBPATHvc10=/LIBPATH:$(SDK)\lib\x64
!				ELSE
LIBPATHvc10=/LIBPATH:"$(SDK)\lib"
!				ENDIF
!			ELSE
LIB=$(MSDIR)\LIB;$(MSDIR)\MFC\LIB;
EXEPATH=$(MSDIR)\bin^\
INCPATH=$(MSDIR)\include
!           ENDIF
!	ELSE    #os/2

LIBDIR=f:\ulibos2^\
OBJDIR=f:\ibmcpp\obj^\
PMVIO=/PM:VIO
BASE=/Base:0x10000
!	ENDIF	# w95 or os/2
!ENDIF     #dos or else
EXENAME=$(BINDIR)$(PGM).exe
MAPNAME=$(BINDIR)$(PGM).map

!IF "$(os)"=="w95"
CONCAT=
!ELSE
OS2EXE=$(EXENAME)
OS2MAP=$(MAPNAME)
CONCAT=+
OS2ENDM=;
!ENDIF

##for .dep ##########
#ULIB=$g:^\src^\ulib^\
###
#OPTASM=/Fa$(TMP)
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
!	IF "$(os)"=="os2"
DEBUG=/Ti
LINKDE=/CO
!	ELSE      #else os2
!		IF "$(os)"=="w95"
DEBUG=/Zi
LINKDE=/DEBUG
!		ELSE      #dos
!			IF "$(dosv)"=="gcc"         #gcc
DEBUG=-g                     #gcc
LINKDE=-g                    #gcc
!			ELSE                        #gcc
DEBUG=/Zi
LINKDE=/CO
!			ENDIF                       #gcc
!		ENDIF     #endif dos
!	ENDIF     #endif else os2
!ENDIF     #debug no/yes

#source output option ########
!IF "$(source)"=="no"	
!ELSE
OPTOS2S=/Ls
OPTDOSS=/Fs$(TMP)
!ENDIF
#source output option ########
!IF "$(source)"=="no"
!	IF "$(w95)"=="vc"
OPTASMW=/Fa$(TMP)ul
!	ELSE
OPTASMW=-S
!	ENDIF
!ELSE       #else SOURCE(no)
!	IF "$(source)"=="nul"
OPTASMW=
!	ELSE 		#source not null and not no
!		IF "$(dosv)"=="gcc"    #gcc
OPTASMG=-S              #gcc
!		ELSE            #else gcc
OPTASMG=                #gcc
OPTOS2S=/Ls
LISTOS2=/Fl$(TMP)
OPTDOSS=/Fs$(TMP)
OPTASM=/Fa$(TMP)
!			IF "$(w95)"=="vc"
OPTASMW=/Fa$(TMP)$<
!			ELSE
OPTASMW=-S
!			ENDIF
!		ENDIF                  #gcc
!	ENDIF   	#source
!ENDIF          #source=no or else

!IF "$(os)"=="os2"	
STCK=/ST:32000
LINKJOB=+ $(OBJDIR)xpjob.OBJ
LINKJOB2=
MAPOPT=/MAP
!ELSE
!	IF "$(os)"=="w95"	
!		IF "$(utf8)"=="yes"	                                      #utf 
LINKW95=$(OBJDIR)xpw95s.OBJ $(OBJDIR)xpwinp.OBJ $(OBJDIR)xputf.OBJ $(OBJDIR)xpebc.OBJ
!		ELSE
LINKW95=$(OBJDIR)xpw95s.OBJ $(OBJDIR)xpwinp.OBJ $(OBJDIR)xpebc.OBJ
!		ENDIF
VCOUT=/OUT:$(EXENAME)
MAPOPT=/MAP:$(MAPNAME)
#STCK=/STACK:64000
!	ELSE
!		IF "$(dosv)"=="gcc"    #gcc
GCCLNK=gcc
MAPOPT=-Wl,-Map
CONCAT=
OS2EXE=-o $(EXENAME)
OS2MAP=-Wl,$(MAPNAME)
OS2ENDM=
!		ELSE                  # dos
LINKW95=
MAPOPT=/MAP
STCK=/ST:20000
!		ENDIF
!	ENDIF
LINKJOB=
!ENDIF
## x86 VC10
!IF "$(w98)"=="vc10"
!	IF "$(debug)"=="yes"
#VC8OPT=/Zi /D _DEBUG /nologo /X $(WARNLVL) /WX- /Od /Oy- /D _WINDOWS /D STRICT /D _CRT_SECURE_NO_DEPRECATE /D VC10EXP /D _MBCS  /Gm /EHsc /RTC1 /MTd /GS /fp:precise /Zc:wchar_t /Zc:forScope /Gd  /J /we4700  /w34701 /wd4100 /wd4214 /wd4057 /wd4996 /wd4706 /wd4210 /wd4210 /wd4244 /wd4055 /wd4152  /wd4996 /wd4245 /wd4127 /wd4131 /wd4267 /wd4366 
VC8OPT=/Zi /D _DEBUG /nologo /X $(WARNLVL) /WX- /Od /Oy- /D _WINDOWS /D STRICT /D _CRT_SECURE_NO_DEPRECATE /D VC10EXP /D _MBCS  /Gm /EHsc /RTC1 /MTd /GS /fp:precise /Zc:wchar_t /Zc:forScope /Gd  /J /we4700  /w34701 /wd4100 /wd4214 /wd4057 /wd4996 /wd4706 /wd4210 /wd4210 $(WD4244) /wd4055 /wd4152  /wd4996 /wd4245 /wd4127 /wd4131 /wd4267 /wd4366 
!	ELSE
#VC8OPT=    /D NDEBUG /nologo /X $(WARNLVL) /WX- /Od /Oy- /D _WINDOWS /D STRICT /D _CRT_SECURE_NO_DEPRECATE /D VC10EXP /D _MBCS  /Gm-            /MT  /GS /fp:precise /Zc:wchar_t /Zc:forScope /Gd  /J /we4700  /w34701 /wd4100 /wd4214 /wd4057 /wd4996 /wd4706 /wd4210 /wd4210 /wd4244 /wd4055 /wd4152  /wd4996 /wd4245 /wd4127 /wd4131 /wd4267 /wd4366 
VC8OPT=    /D NDEBUG /nologo /X $(WARNLVL) /WX- /Od /Oy- /D _WINDOWS /D STRICT /D _CRT_SECURE_NO_DEPRECATE /D VC10EXP /D _MBCS  /Gm-            /MT  /GS /fp:precise /Zc:wchar_t /Zc:forScope /Gd  /J /we4700  /w34701 /wd4100 /wd4214 /wd4057 /wd4996 /wd4706 /wd4210 /wd4210 $(WD4244) /wd4055 /wd4152  /wd4996 /wd4245 /wd4127 /wd4131 /wd4267 /wd4366 
!	ENDIF	
!ENDIF

.SUFFIXES:

.SUFFIXES: .c

ALL: $(EXENAME)

$(EXENAME):  \
!IF "$(dosv)"=="gcc"    #gcc
  $(LIBDIR)user.lib \
  $(OBJDIR)$(PGM).LIB  
   @echo link---$(PGM)
   @echo link---$(PGM) >>err
    xdig /1err0 /21 /nla //@<<$(PGM).@0
    $(GCCLNK) $(LINKDE) $(MAPOPT) $(OS2MAP) $(OS2EXE) $(OBJDIR)$(PGM).OBJ $(OBJDIR)$(PGM).lib $(LIBDIR)user.lib
<<KEEP
   @type  err0
   @type  err0>>err
   @type  err                         
$(OBJDIR)$(PGM).LIB : \
!ELSE                   #gcc
  $(LIBDIR)user.lib \
!ENDIF                  #gcc
  $(OBJDIR)xprint.OBJ \
  $(OBJDIR)xp2p.OBJ \
  $(OBJDIR)xpdesp.OBJ \
  $(OBJDIR)xpesc.OBJ \
  $(OBJDIR)xphex.OBJ \
  $(OBJDIR)xphlp.OBJ \
  $(OBJDIR)xpinp.OBJ \
!IF "$(os)"=="os2"	
  $(OBJDIR)xpjob.OBJ \
!ENDIF
  $(OBJDIR)xpmult.OBJ \
  $(OBJDIR)xppf.OBJ \
  $(OBJDIR)xpsub1.OBJ \
!IF "$(utf8)"=="yes"	            #utf
  $(OBJDIR)xputf.OBJ \
!ENDIF
!IF "$(os)"=="w95"	
  $(OBJDIR)xpw95s.OBJ \
  $(OBJDIR)xpwinp.OBJ \
  $(OBJDIR)xpebc.OBJ \
!ENDIF
  xprint.mak
!IF "$(dosv)"=="gcc"	            #gcc
   @echo create lib---$(PGM).lib
   @echo create lib---$(PGM).lib>>err
   cd
         h:
         cd \gcobj
         del $(PGM).lib
         h:\c6obj\xdig /pf /21 /1g:\src\xp\err0 . xp*.obj //h:\djgpp\bin\ar -rv $(PGM).lib %%f%%
         srcxp
   @type  err0
   @type  err0>>err
       @echo ar---xplib.map
       @echo ar---xplib.map>>err
       ar -tv $(OBJDIRU)$(PGM).lib >$(OBJDIR)xplib.map
       @type  $(OBJDIR)xplib.map >>err
       @type  $(OBJDIR)xplib.map
!ELSE                               #gcc
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
!IF "$(os)"=="os2"	
   LINK386.EXE @xprint.@0 >>err
!ELSE
!	IF "$(os)"=="w95"
   @echo link---$(PGM)
   @echo link---$(PGM) >>err
   $(EXEPATH)LINK.EXE @xprint.@0    >err0    2>&1
!	ELSE       #else w95(DOS)
   LINK.EXE @xprint.@0    >>err
!	ENDIF     #dos
!ENDIF
!ENDIF					//gcc
  type err0>>err
  type err

#LIST=/Fa
{.}.c{$(OBJDIR)}.obj:
!IF "$(os)"=="os2"	
   ICC.EXE /Ss /Sn $(DEBUG) /D$(TRACE) /Kabc /C /DOS2 /Fl$(TMP) $(OPTASM) $(OPTOS2S) /Gm /Fo$* $< >err0
!ELSE
!	IF "$(os)"=="w95"
!			IF "$(w98)"=="vc10"	
#   $(EXEPATH)cl /c /DW32 $(VC8OPT) $(UTF8SUPP) /D$(TRACE) /I$(INCPATH) $(OPTASMW) /Fo$@ $< >err0
   $(EXEPATH)cl /c /DW32 $(VC8OPT) $(UTF8SUPP) /D$(TRACE) /I$(INCPATH)            /Fo$@ $< >err0
!		ELSE
  $(EXEPATH)cl /c $(WARNLVL) /G3 /Gd /J /Od $(UTF8SUPP) /D$(TRACE) /DW32 $(DEBUG) /I$(ULIB) /I$(ULIBICU) /I$(INCPATH) /Fr$(TMP) $(OPTASMW) /Fo$@ $< >err0
!		ENDIF
!	ELSE       #else w95(DOS)
!		IF "$(dosv)"=="gcc"	           #gcc
   	xdig /1err0 /21 /nla //@<<gccpf
 gcc -c -funsigned-char -Wall -Wno-conversion -m386 -DDOS -DDPMI -D$(TRACE) $(DEBUG) -o $*.obj $<
<<KEEP
!		ELSE                #gcc not gcc
   $(EXEPATH)cl /c /Od /AL /W2 /Ze /DDOS  /D$(TRACE) $(OPTDOSS) $(OPTASM) $(DEBUG) /Fo$* $< >err0
!		ENDIF               #gcc or not gcc
!	ENDIF     #dos
!ENDIF
   type err0>>err
   type err0
#######
!include xp.dep
