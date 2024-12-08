#####################################################
INCULIBH=$(ULIBHDIR) #~8726I~
INCREGEXH=$(ULIBHDIR)\gnuregex #~8726I~
INCSH=$(INCSH)
#####################################################
#WD4244=/Wd4244
WD4244=
!IF "$(debug)"=="yes"
WARNLVL=/W4
!ELSE
WARNLVL=/W3
!ENDIF
!IF "$(os)"=="dos"
!	IF "$(dosv)"=="c6"
OSTYPE=dos
EXEPATH=h:\c6\binr^\
## segment overflow(L1049 err,default is 128)
SEGM=/SE:256
## Far data limit to set long data to far data to reduce data segment
GTN=/Gt64
DOSSTACK=14000
!	ELSE          #not c6
!		IF "$(dosv)"=="gcc"	            #gcc
OSTYPE=gcc
EXEPATH=h:\djgpp\bin^\              #gcc
GREPMOD=$(OBJDIR)xefcmd27.OBJ
INCPATH=-I$(INCREGEXH)
!		ELSE                               #gcc
OSTYPE=dos
EXEPATH=d:\ibmc2\bin^\
ULIB=g:\src\ulib^\
!		ENDIF                              #gcc
!	ENDIF         #c6 or not
!ELSE          #not dos
!	IF "$(os)"=="win"
OSTYPE=win
FTPMOD=$(OBJDIR)xeftp.obj $(OBJDIR)xetso.obj $(OBJDIR)xetso2.obj
GREPMOD=$(OBJDIR)xefcmd27.OBJ
!		IF "$(w95)"=="vc"
!			IF "$(w98)"=="vc10"
EXEPATH=$(BINPATH)^\
INCPATH=.\ /I$(SDK)\include /I$(VC)\include /I$(INCULIBH) /I$(INCREGEXH)
!			ELSE
VCDIR=$(MSDIR) #~8724I~
#LIB=$(VCDIR)\LIB;$(VCDIR)\MFC\LIB; #~8724R~
LIB=$(VCDIR)\lib
EXEPATH=$(VCDIR)\bin^\
INCPATH=$(VCDIR)\include  /I$(INCULIBH) /I$(INCREGEXH)
#OUTPATH=m:\vculib #~8724R~
WLIB=$(VCDIR)\lib
!			ENDIF
!		ELSE
EXEPATH=l:\bc45\bin^\
INCPATH=l:\bc45\include
OUTPATH=l:\ulibw95
WLIB=l:\bc45\lib
!		ENDIF
!	ELSE   #else w95
OSTYPE=os2
PMVIO=/PM:VIO
BASE=/Base:0x10000
GREPMOD=$(OBJDIR)xefcmd27.OBJ
INCPATH=/I$(INCREGEXH)
!	ENDIF
!ENDIF
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
!IF "$(os)"=="win"
EXE6=$(OBJDIR)$(PGM6).exe
EXE7=$(OBJDIR)$(PGM7).exe
EXE8=$(OBJDIR)$(PGM8).exe
#COPT8=/DUTF8SUPP
COPT8=/DUTF8UCS2
!ENDIF
MAP1=$(OBJDIR)$(PGM1)$(OSTYPE).map
MAP2=$(OBJDIR)$(PGM2).map
MAP3=$(OBJDIR)$(PGM3).map
MAP4=$(OBJDIR)$(PGM4).map
MAP5=$(OBJDIR)$(PGM5).map
MAP6=$(OBJDIR)$(PGM6).map
MAP7=$(OBJDIR)$(PGM7).map
MAP8=$(OBJDIR)$(PGM8).map
#####################################################
!IF "$(w95)"=="vc"
VCOUT1=/OUT:$(EXE1)
VCOUT2=/OUT:$(EXE2)
VCOUT3=/OUT:$(EXE3)
VCOUT4=/OUT:$(EXE4)
VCOUT5=/OUT:$(EXE5)
VCOUT6=/OUT:$(EXE6)
VCOUT7=/OUT:$(EXE7)
VCOUT8=/OUT:$(EXE8)
#MAPOPT1=/MAP:$(MAP1) /mapinfo:lines -->"internal error during EmitMap"  
MAPOPT1=/MAP:$(MAP1)
MAPOPT2=/MAP:$(MAP2)
MAPOPT3=/MAP:$(MAP3)
MAPOPT4=/MAP:$(MAP4)
MAPOPT5=/MAP:$(MAP5)
MAPOPT6=/MAP:$(MAP6)
MAPOPT7=/MAP:$(MAP7)
MAPOPT8=/MAP:$(MAP8)
#STCK=/STACK:64000      xe3270 stackoverflow, vc6,vc10 default is 1MB
STCK=""
CONCAT=
#VCLIB=user32.lib shell32.lib
#VCLIB=AdvAPI32.lib user32.lib shell32.lib
VCLIB=AdvAPI32.lib user32.lib shell32.lib ImageHlp.lib
!ELSE
!	IF "$(dosv)"=="gcc"    #gcc
GCCLNK=gcc
MAPOPT1=-Wl,-Map
MAPOPT2=-Wl,-Map
MAPOPT3=-Wl,-Map
MAPOPT4=-Wl,-Map
MAPOPT5=-Wl,-Map
MAPOPT6=-Wl,-Map
CONCAT=
OS2EXE1=-o $(EXE1)
OS2MAP1=-Wl,$(MAP1)
OS2EXE2=-o $(EXE2)
OS2MAP2=-Wl,$(MAP2)
OS2EXE3=-o $(EXE3)
OS2MAP3=-Wl,$(MAP3)
OS2EXE4=-o $(EXE4)
OS2MAP4=-Wl,$(MAP4)
OS2EXE5=-o $(EXE5)
OS2MAP5=-Wl,$(MAP5)
OS2EXE6=-o $(EXE6)
OS2MAP6=-Wl,$(MAP6)
OS2ENDM=
!	ELSE                  #!gcc
MAPOPT1=/MAP
MAPOPT2=/MAP
MAPOPT3=/MAP
MAPOPT4=/MAP
MAPOPT5=/MAP
MAPOPT6=/MAP
!IF "$(os)"=="dos"
#STCK=/ST:16000
STCK=/ST:$(DOSSTACK)
!ELSE
STCK=/ST:32000
!ENDIF
CONCAT=+
OS2EXE1=$(EXE1)
OS2MAP1=$(MAP1)
OS2EXE2=$(EXE2)
OS2MAP2=$(MAP2)
OS2EXE3=$(EXE3)
OS2MAP3=$(MAP3)
OS2EXE4=$(EXE4)
OS2MAP4=$(MAP4)
OS2EXE5=$(EXE5)
OS2MAP5=$(MAP5)
OS2EXE6=$(EXE6)
OS2MAP6=$(MAP6)
OS2ENDM=;
!	ENDIF                #gcc
!ENDIF                   #vc
###
TMPLST=$(TMP)^\
###
#source output option ########
!IF "$(source)"=="no"
#OPTOS2S=/Ls
#LISTOS2=/Fl$(TMPLST)xe0
#OPTDOSS=/Fs$(TMPLST)xe0
#OPTASM=/Fa$(TMPLST)xe0
!	IF "$(w95)"=="vc"
#OPTASMW=/Fa$(TMPLST)ul
!	ELSE
OPTASMW=-S
!	ENDIF
!ELSE       #else SOURCE(no)
!	IF "$(source)"=="nul"
OPTASMW=
!	ELSE 		#source not null and not no
!		IF "$(dosv)"=="gcc"    #gcc
OPTASMG=-S              #gcc
!		ELSE                   #gcc
OPTASMG=                #gcc
OPTOS2S=/Ls
LISTOS2=/Fl$(TMPLST)
OPTDOSS=/Fs$(TMPLST)
OPTASM=/Fa$(TMPLST)
!			IF "$(w95)"=="vc"
OPTASMW=/Fa$(TMPLST)$<
!			ELSE
OPTASMW=-S
!			ENDIF
!		ENDIF                  #gcc
!	ENDIF   	#source
!ENDIF          #source=no or else
###
#codeview/pm debugger option ########
!IF "$(debug)"=="no"
DEBUG=
LINKDE=
MTOPT=/MT #~8726I~
!ELSE      #else debug=no
!	IF "$(os)"=="os2"
DEBUG=/Ti
LINKDE=/CO
!	ELSE      #else os2
!		IF "$(os)"=="win"
DEBUG=/Zi
LINKDE=/DEBUG
!			IF "$(w98)"=="vc8"
MTOPT=/MTd
!			ELSE                        #gcc
MTOPT=/MT
!			ENDIF                       #gcc
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
!ENDIF     #endif debug=no

#for VC8 #~8724I~
!IF "$(w98)"=="vc8" #~8724I~
!	IF "$(debug)"=="no" #~8724I~
VC8OPT=      /D_CRT_SECURE_NO_DEPRECATE /FR$(TMP) /D_MBCS /D_CONSOLE 
!	ELSE #~8724I~
VC8OPT=/RTC1 /D_CRT_SECURE_NO_DEPRECATE /FR$(TMP) /D_MBCS /D_CONSOLE
!	ENDIF #~8724I~
LIBPATH=/LIBPATH:"$(MSSDK2003)\LIB" /LIBPATH:"$(MSVC8)\LIB" #~8724R~
WINOPT=/DUTF8SUPPH /DUTF8UCS2
!ELSE #~8724I~
!	IF "$(w95)"=="vc" #~8724I~
VC8OPT=/Fr$(TMP) #~8724I~
## x86 VC10
!	IF "$(w98)"=="vc10"
!		IF "$(debug)"=="yes"
#VC8OPT=/Zi /D _DEBUG /nologo /X $(WARNLVL) /WX- /Od /Oy- /D _WINDOWS /D STRICT /D _CRT_SECURE_NO_DEPRECATE /D VC10EXP /D _MBCS  /Gm /EHsc /RTC1 /MTd /GS /fp:precise /Zc:wchar_t /Zc:forScope /Gd  /J /we4700  /w34701 /wd4100 /wd4214 /wd4057 /wd4996 /wd4706 /wd4210 /wd4210 /wd4244 /wd4055 /wd4152  /wd4996 /wd4245 /wd4127 /wd4131 /wd4267 /wd4366 
#VC8OPT=/Zi /D _DEBUG /nologo /X $(WARNLVL) /WX- /Od /Oy- /D _WINDOWS /D STRICT /D _CRT_SECURE_NO_DEPRECATE /D VC10EXP  $(MBCS)   /Gm /EHsc /RTC1 /MTd /GS /fp:precise /Zc:wchar_t /Zc:forScope /Gd  /J /we4700  /w34701 /wd4100 /wd4214 /wd4057 /wd4996 /wd4706 /wd4210 /wd4210 /wd4244 /wd4055 /wd4152  /wd4996 /wd4245 /wd4127 /wd4131 /wd4267 /wd4366 
VC8OPT=/Zi /D _DEBUG /nologo /X $(WARNLVL) /WX- /Od /Oy- /D _WINDOWS /D STRICT /D _CRT_SECURE_NO_DEPRECATE /D VC10EXP  $(MBCS)   /Gm /EHsc /RTC1 /MTd /GS /fp:precise /Zc:wchar_t /Zc:forScope /Gd  /J /we4700  /w34701 /wd4100 /wd4214 /wd4057 /wd4996 /wd4706 /wd4210 /wd4210 $(WD4244) /wd4055 /wd4152  /wd4996 /wd4245 /wd4127 /wd4131 /wd4267 /wd4366 
!		ELSE
#VC8OPT=    /D NDEBUG /nologo /X $(WARNLVL) /WX- /Od /Oy- /D _WINDOWS /D STRICT /D _CRT_SECURE_NO_DEPRECATE /D VC10EXP /D _MBCS  /Gm-            /MT  /GS /fp:precise /Zc:wchar_t /Zc:forScope /Gd  /J /we4700  /w34701 /wd4100 /wd4214 /wd4057 /wd4996 /wd4706 /wd4210 /wd4210 /wd4244 /wd4055 /wd4152  /wd4996 /wd4245 /wd4127 /wd4131 /wd4267 /wd4366 
#VC8OPT=    /D NDEBUG /nologo /X $(WARNLVL) /WX- /Od /Oy- /D _WINDOWS /D STRICT /D _CRT_SECURE_NO_DEPRECATE /D VC10EXP  $(MBCS)   /Gm-            /MT  /GS /fp:precise /Zc:wchar_t /Zc:forScope /Gd  /J /we4700  /w34701 /wd4100 /wd4214 /wd4057 /wd4996 /wd4706 /wd4210 /wd4210 /wd4244 /wd4055 /wd4152  /wd4996 /wd4245 /wd4127 /wd4131 /wd4267 /wd4366 
VC8OPT=    /D NDEBUG /nologo /X $(WARNLVL) /WX- /Od /Oy- /D _WINDOWS /D STRICT /D _CRT_SECURE_NO_DEPRECATE /D VC10EXP  $(MBCS)   /Gm-            /MT  /GS /fp:precise /Zc:wchar_t /Zc:forScope /Gd  /J /we4700  /w34701 /wd4100 /wd4214 /wd4057 /wd4996 /wd4706 /wd4210 /wd4210 $(WD4244) /wd4055 /wd4152  /wd4996 /wd4245 /wd4127 /wd4131 /wd4267 /wd4366 
!		ENDIF	
!		IF "$(x64)"=="yes"
LIBPATH=/LIBPATH:"$(SDK)\lib\x64"
!		ELSE
LIBPATH=/LIBPATH:"$(SDK)\lib"
!		ENDIF
!	ENDIF
WINOPT=/DUTF8SUPPH /DUTF8UCS2 /DUTF8EBCD
!	ENDIF #~8724I~
!ENDIF #~8724I~
.SUFFIXES:

.SUFFIXES: .c

################################
################################
################################
!IF "$(w98)"=="vc10"
##   xe      xedumpp trcchk  mtrchk  kbchk   syscmd  3270    xeacb
!IF "$(x64)"=="yes"
ALL: $(EXE1)         $(EXE3) $(EXE4) $(EXE5) $(EXE6) $(EXE7) $(EXE8)
!ELSE
ALL: $(EXE1) $(EXE2) $(EXE3) $(EXE4) $(EXE5) $(EXE6) $(EXE7) $(EXE8)
!ENDIF
#ALL: $(EXE1)                         $(EXE5) $(EXE6) $(EXE7) $(EXE8)
!ELSE
ALL: $(EXE1) $(EXE2) $(EXE3) $(EXE4) $(EXE5) $(EXE6) $(EXE7) $(EXE8)
!ENDIF

$(EXE1):  \
!IF "$(dosv)"=="gcc"    #gcc
  $(LIBDIR)user.lib \
  $(OBJDIR)$(PGM1).LIB  
   @echo link---$(PGM1)
   @echo link---$(PGM1) >>err
!	IF "$(VER)"==""		#from user.mak
  		xdig /1err0 /21 /nla //@<<$(PGM1).@0
   		$(GCCLNK) $(LINKDE) $(MAPOPT1) $(OS2MAP1) $(OS2EXE1) $(OBJDIR)$(PGM1).OBJ $(OBJDIR)xe.lib $(LIBDIR)user.lib
<<KEEP
!	ELSE                #pack
      cd ..\gccxe
  		xdig /1..\xe\err0 /nal /21 //@<<$(PGM1).@0
		$(GCCLNK) $(LINKDE) $(MAPOPT1) $(OS2MAP1) $(OS2EXE1) .\$(PGM1).OBJ .\xe.lib $(LIBDIR)user.lib
<<KEEP
      cd ..\xe
!	ENDIF               #
   copy $(MAP1) $(XE)\$(PGM1)$(OSTYPE).map
 @if     exist err0  type err0>>err
 @if     exist err0  type err0
$(OBJDIR)$(PGM1).LIB : \
!ELSE                   #gcc
  $(LIBDIR)user.lib \
!ENDIF                  #gcc
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
!IF "$(os)"=="win"
  $(OBJDIR)xefcmd27.OBJ \
!ENDIF                  #win
!IF "$(os)"=="os2"
  $(OBJDIR)xefcmd27.OBJ \
!ENDIF                  #os2
!IF "$(dosv)"=="gcc"
  $(OBJDIR)xefcmd27.OBJ \
!ENDIF                  #os2
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
!IF "$(os)"=="win"
  $(OBJDIR)xefsubw.OBJ \
  $(FTPMOD) \
!ENDIF                  #win
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
!IF "$(os)"=="win"
  $(OBJDIR)xesub2.OBJ \
!ENDIF                  #win
  $(OBJDIR)xesyn.OBJ \
  $(OBJDIR)xesyn2.OBJ \
  $(OBJDIR)xeundo.OBJ \
!IF "$(os)"=="win"
     $(OBJDIR)xeopt2.OBJ \
     $(OBJDIR)xeutf.OBJ \
     $(OBJDIR)xeutf2.OBJ \
     $(OBJDIR)xeebc.OBJ \
!ENDIF                  #win
  xe.mak \
  xe.inc  
 @echo "link--" "$(EXE1)"
 @echo "link--" "$(EXE1)" >>err
!IF "$(dosv)"=="gcc"	            #gcc
## ar -tv $(OBJDIRU)xe.lib >$(OBJDIR)xelib.map
## type  $(OBJDIR)xelib.map >>err
   @echo create lib---xe.lib
   @echo create lib---xe.lib>>err
   cd
!	IF "$(VER)"==""		#from user.mak
         h:
         cd \gcobj
         del xe.lib
#protect xekbchk.obj from xe.lib
         rename xekbchk.obj xekbchk.ooo
         rename xe.obj xe.ooo
#        h:\c6obj\xdig /pf /21 /1g:\src\xe\err0 . xe*.obj //h:\djgpp\bin\ar -rv xe.lib %%f%%
         h:\gcobj\xdig /pf /21 /1g:\src\xe\err0 . xe*.obj //h:\djgpp\bin\ar -rv xe.lib %%f%%
         rename xekbchk.ooo xekbchk.obj
         rename xe.ooo xe.obj
         srcxe
!	ELSE                #pack
 		cd ..\gccxe
         del xe.lib
#        h:\c6obj\xdig /pf /21 /1..\xe\err0 . xe*.obj //h:\djgpp\bin\ar -rv xe.lib %%f%%
         h:\gcobj\xdig /pf /21 /1..\xe\err0 . xe*.obj //h:\djgpp\bin\ar -rv xe.lib %%f%%
         cd ..\xe
!	ENDIF               #
   type  err0
   type  err0>>err
 @if     exist err0  type err0>>err
 @if     exist err0  type err0
       @echo ar---xelib.map
       ar -tv $(OBJDIRU)xe.lib >$(OBJDIR)xelib.map
       type  $(OBJDIR)xelib.map >>err
       type  $(OBJDIR)xelib.map
!ELSE                               #else gcc
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
!IF "$(os)"=="win"
     $(OBJDIR)xesub2.OBJ $(CONCAT)
!ENDIF                  #win
     $(OBJDIR)xesyn.OBJ $(CONCAT)
     $(OBJDIR)xesyn2.OBJ $(CONCAT)
!IF "$(os)"=="win"
     $(OBJDIR)xeopt2.OBJ $(CONCAT)
     $(OBJDIR)xeutf.OBJ $(CONCAT)
     $(OBJDIR)xeutf2.OBJ $(CONCAT)
     $(OBJDIR)xeebc.OBJ $(CONCAT)
!ENDIF                  #win
     $(OBJDIR)xeundo.OBJ
   $(OS2EXE1)
   $(OS2MAP1)           
   $(LIBDIR)user.lib   $(VCLIB)  $(LIBPATH)
   $(OS2ENDM)
<<KEEP
!	IF "$(os)"=="os2"
   LINK386.EXE @$(PGM1).@0 >err0
!	ELSE    #else os2
!		IF "$(os)"=="win"
!			IF "$(w95)"=="vc"
   $(EXEPATH)link @$(PGM1).@0  >err0
!			ELSE
   $(EXEPATH)tlink32 -Tpe -ap $(LINKDE) -c -m -s  $(WLIB)\c0x32+%obj%\%1,$(OBJDIR)\$(PGM1),$(OBJDIR)\$(PGM1),$(WLIB)\import32 $(WLIB)\cw32 $(LIBDIR)\user.lib >err0
!			ENDIF      # vcc  or not
!		ELSE       #else w95,dos
   LINK.EXE @$(PGM1).@0 >err0
!		ENDIF      #win/dos
!	ENDIF      #os2/else
   copy $(MAP1) $(XE)\$(PGM1)$(OSTYPE).map
 @if     exist err0  type err0>>err
 @if     exist err0  type err0
!ENDIF      #gcc or else
####################################################

$(EXE2):  \
  $(LIBDIR)user.lib \
  $(OBJDIR)$(PGM2).OBJ \
  $(MAKEF)
!IF "$(dosv)"=="gcc"	            #gcc
   @echo link---$(PGM2)
   @echo link---$(PGM2) >>err
!	IF "$(VER)"==""		#from user.mak
		xdig /1..\xe\err0 /21 /nla //@<<$(PGM2).@0
   		$(GCCLNK) $(LINKDE) $(MAPOPT2) $(OS2MAP2) $(OS2EXE2) $(OBJDIR)$(PGM2).OBJ $(OBJDIR)xe.lib $(LIBDIR)user.lib
<<KEEP
!	ELSE                #pack
		cd 
		cd ..\gccxe
  		xdig /1..\xe\err0 /21 /nla //@<<$(PGM2).@0
		$(GCCLNK) $(LINKDE) $(MAPOPT2) $(OS2MAP2) $(OS2EXE2) $(PGM2).OBJ xe.lib $(LIBDIR)user.lib
<<KEEP
      cd ..\xe
!	ENDIF               #
!ELSE                               #gcc
   @REM @<<$(PGM2).@0
     $(LINKDE) $(VCOUT2) $(LIBPATH) $(MAPOPT2) $(STCK) $(PMVIO) $(BASE) $(CONCAT)
     $(OBJDIR)$(PGM2).OBJ
   $(OS2EXE2)
   $(OS2MAP2)
   $(LIBDIR)user.lib $(VCLIB)
   $(OS2ENDM)
<<KEEP

!	IF "$(os)"=="os2"
   LINK386.EXE @$(PGM2).@0 >err0
!	ELSE
!		IF "$(os)"=="win"
!			IF "$(w95)"=="vc"
   $(EXEPATH)link @$(PGM2).@0 >err0
!			ELSE
   $(EXEPATH)bcc32 -Il:\src\ulib;$(INCPATH) -c -W -3 -d -k- -w -DW32 -K $(DEBUG) $(OPTASMW) -n$(OUTPATH) $< >err0
!			ENDIF      # vcc  or not
!		ELSE       #else w95,dos
   LINK.EXE @$(PGM2).@0 >err0
!		ENDIF
!	ENDIF
!ENDIF
 @if     exist err0  type err0>>err
 @if     exist err0  type err0
####################################################

$(EXE3):  \
  $(LIBDIR)user.lib \
  $(OBJDIR)$(PGM3).OBJ \
  $(MAKEF)
!IF "$(dosv)"=="gcc"	            #gcc
   @echo link---$(PGM3)
   @echo link---$(PGM3) >>err
!	IF "$(VER)"==""		#from user.mak
		xdig /1..\xe\err0 /21 /nla //@<<$(PGM3).@0
   		$(GCCLNK) $(LINKDE) $(MAPOPT3) $(OS2MAP3) $(OS2EXE3) $(OBJDIR)$(PGM3).OBJ $(OBJDIR)xe.lib $(LIBDIR)user.lib
<<KEEP
!	ELSE                #pack
		cd 
		cd ..\gccxe
  		xdig /1..\xe\err0 /21 /nla //@<<$(PGM3).@0
		$(GCCLNK) $(LINKDE) $(MAPOPT3) $(OS2MAP3) $(OS2EXE3) $(PGM3).OBJ xe.lib $(LIBDIR)user.lib
<<KEEP
      cd ..\xe
!	ENDIF               #
!ELSE                               #gcc
   @REM @<<$(PGM3).@0
     $(LINKDE) $(VCOUT3) $(MAPOPT3) $(LIBPATH) $(STCK) $(PMVIO) $(BASE) $(CONCAT)
     $(OBJDIR)$(PGM3).OBJ
   $(OS2EXE3)
   $(OS2MAP3)
   $(LIBDIR)user.lib $(VCLIB)
   $(OS2ENDM)
<<KEEP

!	IF "$(os)"=="os2"
   LINK386.EXE @$(PGM3).@0 >err0
!	ELSE
!		IF "$(os)"=="win"
!			IF "$(w95)"=="vc"
   $(EXEPATH)link @$(PGM3).@0 >err0
!			ELSE
   $(EXEPATH)bcc32 -Il:\src\ulib;$(INCPATH) -c -W -3 -d -k- -w -DW32 -K $(DEBUG) $(OPTASMW) -n$(OUTPATH) $< >err0
!			ENDIF      # vcc  or not
!		ELSE       #else w95,dos
   LINK.EXE @$(PGM3).@0 >err0
!		ENDIF
!	ENDIF
!ENDIF
 @if     exist err0  type err0>>err
 @if     exist err0  type err0
####################################################

$(EXE4):  \
  $(LIBDIR)user.lib \
  $(OBJDIR)$(PGM4).OBJ \
  $(MAKEF)
!IF "$(dosv)"=="gcc"	            #gcc
   @echo link---$(PGM4)
   @echo link---$(PGM4) >>err
!	IF "$(VER)"==""		#from user.mak
		xdig /1..\xe\err0 /21 /nla //@<<$(PGM4).@0
   		$(GCCLNK) $(LINKDE) $(MAPOPT4) $(OS2MAP4) $(OS2EXE4) $(OBJDIR)$(PGM4).OBJ $(OBJDIR)xe.lib $(LIBDIR)user.lib
<<KEEP
!	ELSE                #pack
		cd 
		cd ..\gccxe
  		xdig /1..\xe\err0 /21 /nla //@<<$(PGM4).@0
		$(GCCLNK) $(LINKDE) $(MAPOPT4) $(OS2MAP4) $(OS2EXE4) $(PGM4).OBJ xe.lib $(LIBDIR)user.lib
<<KEEP
      cd ..\xe
!	ENDIF               #
!ELSE                               #gcc
   @REM @<<$(PGM4).@0
     $(LINKDE) $(VCOUT4) $(MAPOPT4) $(LIBPATH) $(STCK) $(PMVIO) $(BASE) $(CONCAT)
     $(OBJDIR)$(PGM4).OBJ
   $(OS2EXE4)
   $(OS2MAP4)
   $(LIBDIR)user.lib $(VCLIB)
   $(OS2ENDM)
<<KEEP

!	IF "$(os)"=="os2"
   LINK386.EXE @$(PGM4).@0 >err0
!	ELSE
!		IF "$(os)"=="win"
!			IF "$(w95)"=="vc"
   $(EXEPATH)link @$(PGM4).@0 >err0
!			ELSE
   $(EXEPATH)bcc32 -Il:\src\ulib;$(INCPATH) -c -W -3 -d -k- -w -DW32 -K $(DEBUG) $(OPTASMW) -n$(OUTPATH) $< >err0
!			ENDIF      # vcc  or not
!		ELSE       #else w95,dos
   LINK.EXE @$(PGM4).@0 >err0
!		ENDIF
!	ENDIF
!ENDIF
 @if     exist err0  type err0>>err
 @if     exist err0  type err0
####################################################

$(EXE5):  \
  $(LIBDIR)user.lib \
  $(OBJDIR)$(PGM5).OBJ \
  $(MAKEF)
!IF "$(dosv)"=="gcc"	            #gcc
   @echo link---$(PGM5)
   @echo link---$(PGM5) >>err
!	IF "$(VER)"==""		#from user.mak
		xdig /1..\xe\err0 /21 /nla //@<<$(PGM5).@0
   		$(GCCLNK) $(LINKDE) $(MAPOPT5) $(OS2MAP5) $(OS2EXE5) $(OBJDIR)$(PGM5).OBJ $(OBJDIR)xecsr.OBJ  $(OBJDIR)xeerr.OBJ $(OBJDIR)xegbl.OBJ $(OBJDIR)xekbd.OBJ $(OBJDIR)xescr.OBJ $(OBJDIR)xescr2.OBJ $(OBJDIR)xesub.OBJ $(LIBDIR)user.lib
<<KEEP
!	ELSE                #pack
		cd 
		cd ..\gccxe
  		xdig /1..\xe\err0 /21 /nla //@<<$(PGM5).@0
		$(GCCLNK) $(LINKDE) $(MAPOPT5) $(OS2MAP5) $(OS2EXE5) $(PGM5).OBJ $(LIBDIR)user.lib $(CONCAT)
     $(OBJDIR)xecsr.OBJ $(CONCAT)
     $(OBJDIR)xeerr.OBJ $(CONCAT)
     $(OBJDIR)xegbl.OBJ $(CONCAT)
     $(OBJDIR)xekbd.OBJ $(CONCAT)
     $(OBJDIR)xescr.OBJ $(CONCAT)
     $(OBJDIR)xescr2.OBJ $(CONCAT)
     $(OBJDIR)xesub.OBJ
<<KEEP
      cd ..\xe
!	ENDIF               #
!ELSE                               #gcc
   @REM @<<$(PGM5).@0
     $(LINKDE) $(VCOUT5) $(MAPOPT5) $(LIBPATH) $(STCK) $(SEGM) $(PMVIO) $(BASE) $(CONCAT)
     $(OBJDIR)$(PGM5).OBJ $(CONCAT)
     $(OBJDIR)xecsr.OBJ $(CONCAT)
     $(OBJDIR)xeerr.OBJ $(CONCAT)
     $(OBJDIR)xegbl.OBJ $(CONCAT)
     $(OBJDIR)xekbd.OBJ $(CONCAT)
     $(OBJDIR)xescr.OBJ $(CONCAT)
     $(OBJDIR)xescr2.OBJ $(CONCAT)
!IF "$(os)"=="win"
     $(OBJDIR)xesub2.OBJ $(CONCAT)
     $(OBJDIR)xeutf.OBJ $(CONCAT)
     $(OBJDIR)xeutf2.OBJ $(CONCAT)
     $(OBJDIR)xeebc.OBJ $(CONCAT)
!ENDIF                  #win
     $(OBJDIR)xefunc.OBJ $(CONCAT)
     $(OBJDIR)xesub.OBJ
   $(OS2EXE5)
   $(OS2MAP5)
   $(LIBDIR)user.lib $(VCLIB)
   $(OS2ENDM)
<<KEEP

!	IF "$(os)"=="os2"
   LINK386.EXE @$(PGM5).@0 >err0
!	ELSE
!		IF "$(os)"=="win"
!			IF "$(w95)"=="vc"
   $(EXEPATH)link @$(PGM5).@0 >err0
!			ELSE
   $(EXEPATH)bcc32 -Il:\src\ulib;$(INCPATH) -c -W -3 -d -k- -w -DW32 -K $(DEBUG) $(OPTASMW) -n$(OUTPATH) $< >err0
!			ENDIF      # vcc  or not
!		ELSE       #else w95,dos
   LINK.EXE  @$(PGM5).@0 >err0
!		ENDIF
!	ENDIF
!ENDIF
 @if     exist err0  type err0>>err
 @if     exist err0  type err0
####################################################

!IF "$(os)"=="win"

$(EXE6):  \
  $(LIBDIR)user.lib \
  $(OBJDIR)$(PGM6).OBJ \
  $(MAKEF)
!IF "$(dosv)"=="gcc"	            #gcc
   @echo link---$(PGM6)
   @echo link---$(PGM6) >>err
!	IF "$(VER)"==""		#from user.mak
		xdig /1..\xe\err0 /21 /nla //@<<$(PGM6).@0
   		$(GCCLNK) $(LINKDE) $(MAPOPT6) $(OS2MAP6) $(OS2EXE6) $(OBJDIR)$(PGM6).OBJ $(OBJDIR)xe.lib $(LIBDIR)user.lib
<<KEEP
!	ELSE                #pack
		cd 
		cd ..\gccxe
  		xdig /1..\xe\err0 /21 /nla //@<<$(PGM6).@0
		$(GCCLNK) $(LINKDE) $(MAPOPT6) $(OS2MAP6) $(OS2EXE6) $(PGM6).OBJ xe.lib $(LIBDIR)user.lib
<<KEEP
      cd ..\xe
!	ENDIF               #
!ELSE                               #gcc
   @REM @<<$(PGM6).@0
     $(LINKDE) $(VCOUT6) $(LIBPATH) $(MAPOPT6) $(STCK) $(PMVIO) $(BASE) $(CONCAT)
     $(OBJDIR)$(PGM6).OBJ
   $(OS2EXE6)
   $(OS2MAP6)
   $(LIBDIR)user.lib $(VCLIB)
   $(OS2ENDM)
<<KEEP

!	IF "$(os)"=="os2"
   LINK386.EXE @$(PGM6).@0 >err0
!	ELSE
!		IF "$(os)"=="win"
!			IF "$(w95)"=="vc"
   $(EXEPATH)link @$(PGM6).@0 >err0
!			ELSE
   $(EXEPATH)bcc32 -Il:\src\ulib;$(INCPATH) -c -W -3 -d -k- -w -DW32 -K $(DEBUG) $(OPTASMW) -n$(OUTPATH) $< >err0
!			ENDIF      # vcc  or not
!		ELSE       #else w95,dos
   LINK.EXE @$(PGM6).@0 >err0
!		ENDIF
!	ENDIF
!ENDIF
 @if     exist err0  type err0>>err
 @if     exist err0  type err0
!ENDIF
####################################################

!IF "$(os)"=="win"
#xe3270
$(EXE7):  \
  $(LIBDIRMT)$(LIBUSERMT) \
  $(OBJDIRMT)$(PGM7).OBJ \
  $(OBJDIRMT)xe3270s.OBJ \
  $(OBJDIRMT)xe3270s2.OBJ \
  $(OBJDIRMT)xe3270e.OBJ \
  $(OBJDIRMT)xe3270f.OBJ \
  $(OBJDIRMT)xe3270f2.OBJ \
!IF "$(w98)"=="vc10"	
  $(LIBDIRMT)utrace_mt.OBJ \
!ENDIF
  $(MAKEF)
   @REM @<<$(PGM7).@0
     $(LINKDE) $(VCOUT7) $(LIBPATH) $(MAPOPT7) $(STCK) $(PMVIO) $(BASE) $(CONCAT)
     $(OBJDIRMT)xe3270s.OBJ $(CONCAT)
     $(OBJDIRMT)xe3270s2.OBJ $(CONCAT)
     $(OBJDIRMT)xe3270e.OBJ $(CONCAT)
     $(OBJDIRMT)xe3270f.OBJ $(CONCAT)
     $(OBJDIRMT)xe3270f2.OBJ $(CONCAT)
!IF "$(w98)"=="vc10"	
  $(LIBDIRMT)utrace_mt.OBJ $(CONCAT)
!ENDIF
     $(OBJDIRMT)$(PGM7).OBJ
   $(LIBDIRMT)$(LIBUSERMT) $(VCLIB)
   $(OS2ENDM)
<<KEEP

 @echo link-- $(EXE7)
 @echo link-- $(EXE7) >>err
   $(EXEPATH)link @$(PGM7).@0 >err0
 @if     exist err0  type err0>>err
 @if     exist err0  type err0
#{.}$(PGM7).c{$(OBJDIR)}$(PGM7).obj:
#$(OBJDIRMT)$(PGM7).obj: #+8726R~
# @echo cpl ---7 $< #+8726R~
# @echo cpl ---7 $< >>err #+8726R~
#  $(EXEPATH)cl /MT /c /W3 /G3 /Gd /J /Od /DW32 /D$(TRACE) $(DEBUG) /I$(INCPATH) /Fr$(TMP) $(OPTASMW) /Fo$@ $< >err0 #~8724R~
#   $(EXEPATH)cl $(MTOPT) /c /W3 /Gd /J /Od $(VC8OPT) /DW32 /D$(TRACE) $(DEBUG) /I$(INCPATH) $(OPTASMW) /Fo$@ $< >err0 #+8726R~
#!ENDIF #+8726R~
!ENDIF      #win #~8726R~
################################

!IF "$(os)"=="win"
OBJACB=$(OBJDIR)xesub2.OBJ 

################################
$(EXE8):  \
  $(LIBDIR)user.lib \
  $(OBJDIR)$(PGM8).OBJ \
  $(MAKEF)
   @REM @<<$(PGM8).@0
     $(LINKDE) $(VCOUT8) $(MAPOPT8) $(LIBPATH) $(STCK) $(PMVIO) $(BASE) $(CONCAT)
     $(OBJDIR)$(PGM8).OBJ $(OBJACB)
   $(LIBDIR)user.lib $(VCLIB)
<<KEEP

   $(EXEPATH)link @$(PGM8).@0 >err0
#{.}.c{$(OBJDIR)}$(PGM8).obj:
$(OBJDIR)$(PGM8).OBJ:$(PGM8).c
#   $(EXEPATH)cl $(COPT8) /c /W3 /G3 /Gd /J /Od /DW32 /D$(TRACE) $(DEBUG) /I$(INCPATH) /Fr$(TMP) $(OPTASMW) /Fo$@ $(PGM8).c >err0 #~8724R~
	$(EXEPATH)cl $(COPT8) /c $(WARNLVL) /Gd /J /Od /DW32 $(VC8OPT) $(WINOPT) /D$(TRACE) $(DEBUG) /I$(INCPATH) $(OPTASMW) /Fo$@ $(PGM8).c >err0
################################
!ENDIF
################################
################################
################################
!IF "$(dosv)"=="gcc"	            #gcc
xear:
   @echo create lib---xe.lib
!	IF "$(VER)"==""		#from user.mak
        h:
        cd \gcobj
        del xe.lib
        rename xekbchk.obj xekbchk.ooo
        rename xe.obj xe.ooo
#       h:\c6obj\xdig /pf /21 /1g:\src\xe\err0 . xe*.obj //h:\djgpp\bin\ar -rv xe.lib %%f%%
        h:\gcobj\xdig /pf /21 /1g:\src\xe\err0 . xe*.obj //h:\djgpp\bin\ar -rv xe.lib %%f%%
        rename xekbchk.ooo xekbchk.obj
        rename xe.ooo xe.obj
        srcxe
        type err0>>err
        type err0
!	ELSE                #pack
		cd ..\gccxe
        del xe.lib
#       h:\c6obj\xdig /pf /21 /1..\xe\err0 . xe*.obj //h:\djgpp\bin\ar -rv xe.lib %%f%%
        h:\gcobj\xdig /pf /21 /1..\xe\err0 . xe*.obj //h:\djgpp\bin\ar -rv xe.lib %%f%%
        cd ..\xe
        type err0>>err
        type err0
!	ENDIF               #
!ENDIF
#######################################################
{.}.c{$(OBJDIR)}.obj:
 @echo cpl---$<
 @echo cpl---$< >>err
!IF "$(os)"=="os2"
 ICC.EXE /J /Ss /Sn $(DEBUG) $(INCPATH) /Kabc /C /DOS2 /D$(TRACE) $(LISTOS2) $(OPTASM) $(OPTOS2S) /Gm /Fo$* $< >err0
!ELSE       #else os2
!	IF "$(os)"=="win"
!		IF "$(w95)"=="vc"
#  $(EXEPATH)cl /c /W3 /G3 /Gd /J /Od /DW32 /D$(TRACE) $(DEBUG) /I$(INCPATH) /Fr$(TMP) $(OPTASMW) /Fo$@ $< >err0 #~8724R~
!			IF "$(w98)"=="vc10"	
   $(EXEPATH)cl /c /DW32 $(VC8OPT) $(WINOPT) /D$(TRACE) /I$(INCPATH) $(OPTASMW) /Fo$@ $< >err0
!			ELSE
   $(EXEPATH)cl /c $(WARNLVL) /Gd /J /Od /DW32 $(VC8OPT) $(WINOPT) /D$(TRACE) $(DEBUG) /I$(INCPATH) $(OPTASMW) /Fo$@ $< >err0
!			ENDIF
 @echo cpl end ---$<
!		ELSE
   $(EXEPATH)bcc32 -Il:\src\ulib;$(INCPATH) -c -W -3 -d -k- -w -DW32 -K $(DEBUG) $(OPTASMW) -n$(OUTPATH) $< >err0
!		ENDIF      # vcc  or not
!	ELSE       #else w95(DOS)
!		IF "$(dosv)"=="c6"
 h:\c6\binr\cl /DC6 /c /Os /AL /W2 $(GTN) /G2 /Ze /Gs /DDOS /J /D$(TRACE) $(OPTDOSS) $(OPTASM) $(DEBUG) /Fo$* $< >err0
!		ELSE
!			IF "$(dosv)"=="gcc"	           #gcc
!				IF "$(OPTASMG)"=="-S"             #gcc
  	xdig /1err0 /21 /nla //@<<gccpf
gcc -S  $(INCPATH) -funsigned-char -Wall -Wno-conversion -m386 -DDOS -DDPMI -D$(TRACE) $(DEBUG) -o $*.s $<
<<KEEP
    type err0>>err
    type err0
   	xdig /1err0 /21 /nla //gcc -c $(DEBUG) -o $*.obj $*.s
!				ELSE                              #gcc
   	xdig /1err0 /21 /nla //@<<gccpf
gcc -c $(INCPATH) -funsigned-char -Wall -Wno-conversion -m386 -DDOS -DDPMI -D$(TRACE) $(DEBUG) -o $*.obj $<
<<KEEP
!				ENDIF                             #gcc
##  type err0>>err
##  type err0
##     @echo ar---$*
##!				IF "$(VER)"==""		#from user.mak
##   h:
##   cd \gcobj   
##   h:\c6obj\xdig /nal /21 /1g:\src\xe\err0 /yx //@<<gccpfl2
##   ar -rv xe.lib $(@F)
##<<KEEP
##   srcxe
##!				ELSE                #gcc not gcc
##   cd ..\gccxe
##   h:\c6obj\xdig /nal /21 /1..\xe\err0 //@<<gccpfl2
##   h:\djgpp\bin\ar -rv xe.lib $(@F)
##<<KEEP
##   cd ..\xe
##!				ENDIF               #gcc or not gcc
!			ELSE                #gcc not gcc
 d:\ibmc2\bin\cl /c  /J /Os /AL /G2 $(GTN) /Gs /W2 /Ze /DDOS /D$(TRACE) $(OPTDOSS) $(OPTASM) $(DEBUG) /Fo$* $< >err0
!			ENDIF               #gcc or not gcc
!		ENDIF
!	ENDIF     #dos
!ENDIF     #w95/dos
 @if     exist err0  type err0>>err
 @if     exist err0  type err0
#######################################################
!IF "$(w98)"=="vc8"
!ELSE
!	IF "$(w98)"=="vc10"
!   ELSE
{.}.c{$(OBJDIRMT)}.obj:
 @echo cpl-mt--$<
 @echo cpl-mt--$< >>err
#  $(EXEPATH)cl /MT /c /W3 /G3 /Gd /J /Od /DW32 /DTRACE    $(DEBUG) /I$(INCPATH) /Fr$(TMP) $(OPTASMW) /Fo$@ $< >err0
!			IF "$(x64)"=="yes"	
   $(EXEPATH)cl /c /DW32 $(VC8OPT) $(WINOPT) /D$(TRACE) /I$(INCPATH) $(OPTASMW) /Fo$@ $< >err0
!			ELSE   		
   $(EXEPATH)cl $(MTOPT) /c $(WARNLVL) /Gd /J /Od /DW32 $(VC8OPT) $(WINOPT) /D$(TRACE) $(DEBUG) /I$(INCPATH) $(OPTASMW) /Fo$@ $< >err0
!			ENDIF
 @if     exist err0  type err0>>err
 @if     exist err0  type err0
!	ENDIF
!ENDIF
#######
