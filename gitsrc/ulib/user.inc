#################################################
#//v60f:071023 pre-release of utf version for xprint   Å@
#################################################
#WD4244=/Wd4244
WD4244=
TMPLST=$(TMP)^\ 
!			IF "$(w98)"=="yes"
#MSDIR=m:\MICROS~1\vc98 #~8725R~
!			ELSE          #not vc98=yes
!				IF "$(w98)"=="vc8" #~8724R~
!				ELSE #~8724R~
MSDIR=m:\msdev
!				ENDIF #~8724R~
!			ENDIF         #vc98
#INCULIBH=g:\src\ulib #~8725R~
INCULIBH=$(ULIBHDIR) #~8725I~
INCICU=$(ICUHDIR) #~8805I~
#INCREGEX=g:\src\ulib\gnuregex #~8725R~
!IF "$(os)"=="os2"	
INCREGEX=o:\gnuregex
!ELSE
INCREGEX=$(ULIBHDIR)\gnuregex #~8725I~
!ENDIF
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
#################################################
!IF "$(os)"=="dos"	

!	IF "$(dosv)"=="c6"	
EXEPATH=h:\c6\binr^\    
EXELIBPATH=h:\c6\binb^\    
GTN=/Gt64
!	ELSE
!		IF "$(dosv)"=="gcc"	
EXEPATH=h:\djgpp\bin^\        
EXELIBPATH=h:\djgpp\bin^\        
INCPATH=-I$(INCREGEX)
!		ELSE
EXEPATH=d:\ibmc2\bin^\        
EXELIBPATH=d:\ibmc2\bin^\        
!		ENDIF
!	ENDIF
!ELSE    
!	IF "$(os)"=="w95"    
!		IF "$(w95)"=="vc"    
!			IF "$(w98)"=="vc10"
EXEPATH=$(BINPATH)^\
EXELIBPATH=$(BINPATH)^\
#INCPATHWDK=/I$(WDK)\inc /I$(WDK)\inc\ddk /I$(WDK)\inc\api /I$(WDK)\inc\crt
INCPATHWDK=/I$(WDK)\inc
INCPATH=.\ /I$(SDK)\include /I$(VC)\include /I$(INCULIBH) /I$(INCREGEX) /I$(INCICU) $(INCPATHWDK)
#INCPATH=.\ $(INCPATHWDK) /I$(SDK)\include /I$(VC)\include /I$(INCULIBH) /I$(INCREGEX) /I$(INCICU)
#SHOWINCLUDE=/showIncludes
SHOWINCLUDE=
!			ELSE
EXEPATH=$(MSDIR)\bin^\ #~8724R~
EXELIBPATH=$(MSDIR)\bin^\ #~8724R~
INCPATH=$(MSDIR)\include /I$(INCULIBH) /I$(INCREGEX) /I$(INCICU) #~8805R~
!			ENDIF
#OUTPATH=m:\vculib #~8724R~
OUTPATH=$(LIBDIR) #~8724R~

#OPTWINMT=/DUTF8SUPP /DUTF8SUPPH /DUTF8UCS2 /DUTF8EBCD
#OPTWIN=/DUTF8SUPP /DUTF8SUPPH  /DUTF8UCS2  /DUTF8EBCD /DNOMT_TRACE
OPTWINMT=/DUTF8SUPPH /DUTF8UCS2 /DUTF8EBCD
OPTWIN=  /DUTF8SUPPH /DUTF8UCS2 /DUTF8EBCD /DNOMT_TRACE

!		ELSE
EXEPATH=l:\bc45\bin^\        
EXELIBPATH=h:\c6\binb^\    
INCPATH=l:\bc45\include        
OUTPATH=l:\bculib
!		ENDIF
!	ELSE    #os2
INCPATH=/I$(INCREGEX)
!	ENDIF    
!ENDIF

!IF "$(debug)"=="no"
DEBUG=    
LINKDE=
MTOPT=/MT
!ELSE         #debug yes
!	IF "$(os)"=="os2"    
DEBUG=/Ti        
LINKDE=/CO        
!	ELSE    

!		IF "$(os)"=="w95"        
!       	IF "$(W95)"=="vc"
DEBUG=/Zi
LINKDE=/DEBUG
!				IF "$(w98)"=="vc8" #~8726I~
MTOPT=/MT
!				ELSE #~8726I~
MTOPT=/MT #~8726I~
!				ENDIF #~8726I~
!			ELSE        
DEBUG=-v
LINKDE=-v
!			ENDIF
!		ELSE        
!			IF "$(dosv)"=="gcc"        
DEBUG=-g
LINKDE=
!			ELSE        
DEBUG=/Zi            
LINKDE=/CO            
!			ENDIF        
!		ENDIF        

!	ENDIF    
!ENDIF
#for VC8 #~8724R~
!IF "$(w98)"=="vc8" #~8724R~
!	IF "$(debug)"=="no" #~8724R~
VC8OPT=      /D_CRT_SECURE_NO_DEPRECATE /D_CRT_NONSTDC_NO_DEPRECATE /FR$(TMP) /D_MBCS /D_CONSOLE $(MTOPT) #~8726R~
!	ELSE #~8724R~
VC8OPT=/RTC1 /D_CRT_SECURE_NO_DEPRECATE /D_CRT_NONSTDC_NO_DEPRECATE /FR$(TMP) /D_MBCS /D_CONSOLE $(MTOPT) #~8726R~
!	ENDIF #~8724R~
!ELSE #~8724R~
!	IF "$(w95)"=="vc" #~8724R~
VC8OPT=/Fr$(TMP) #~8724R~
!	ENDIF #~8724R~
!ENDIF #~8724R~
## x86 VC10
#MACOPT=/P /C
MACOPT=
!IF "$(w98)"=="vc10"
!	IF "$(debug)"=="yes"
#VC8OPT=$(SHOWINCLUDE) $(MACOPT) /Zi /D _DEBUG /nologo /X $(WARNLVL) /WX- /Od /Oy- /D _WINDOWS /D STRICT /D _CRT_SECURE_NO_DEPRECATE /D VC10EXP /D _MBCS  /Gm /EHsc /RTC1 /MTd /GS /fp:precise /Zc:wchar_t /Zc:forScope /Gd  /J /we4700  /w34701 /wd4100 /wd4214 /wd4057 /wd4996 /wd4706 /wd4210 /wd4210 /wd4244 /wd4055 /wd4152  /wd4996 /wd4245 /wd4127 /wd4131 /wd4267 /wd4366 
#VC8OPT=$(SHOWINCLUDE) $(MACOPT) /Zi /D _DEBUG /nologo /X $(WARNLVL) /WX- /Od /Oy- /D _WINDOWS /D STRICT /D _CRT_SECURE_NO_DEPRECATE /D VC10EXP $(MBCS) /Gm /EHsc /RTC1 /MTd /GS /fp:precise /Zc:wchar_t /Zc:forScope /Gd  /J /we4700  /w34701 /wd4100 /wd4214 /wd4057 /wd4996 /wd4706 /wd4210 /wd4210 /wd4244 /wd4055 /wd4152  /wd4996 /wd4245 /wd4127 /wd4131 /wd4267 /wd4366 
VC8OPT=$(SHOWINCLUDE) $(MACOPT) /Zi /D _DEBUG /nologo /X $(WARNLVL) /WX- /Od /Oy- /D _WINDOWS /D STRICT /D _CRT_SECURE_NO_DEPRECATE /D VC10EXP $(MBCS) /Gm /EHsc /RTC1 /MTd /GS /fp:precise /Zc:wchar_t /Zc:forScope /Gd  /J /we4700  /w34701 /wd4100 /wd4214 /wd4057 /wd4996 /wd4706 /wd4210 /wd4210 $(WD4244) /wd4055 /wd4152  /wd4996 /wd4245 /wd4127 /wd4131 /wd4267 /wd4366 
!	ELSE
#VC8OPT=$(SHOWINCLUDE)     /D NDEBUG /nologo /X $(WARNLVL) /WX- /Od /Oy- /D _WINDOWS /D STRICT /D _CRT_SECURE_NO_DEPRECATE /D VC10EXP /D _MBCS  /Gm-            /MT  /GS /fp:precise /Zc:wchar_t /Zc:forScope /Gd  /J /we4700  /w34701 /wd4100 /wd4214 /wd4057 /wd4996 /wd4706 /wd4210 /wd4210 /wd4244 /wd4055 /wd4152  /wd4996 /wd4245 /wd4127 /wd4131 /wd4267 /wd4366 
#VC8OPT=$(SHOWINCLUDE)     /D NDEBUG /nologo /X $(WARNLVL) /WX- /Od /Oy- /D _WINDOWS /D STRICT /D _CRT_SECURE_NO_DEPRECATE /D VC10EXP $(MBCS)  /Gm-            /MT  /GS /fp:precise /Zc:wchar_t /Zc:forScope /Gd  /J /we4700  /w34701 /wd4100 /wd4214 /wd4057 /wd4996 /wd4706 /wd4210 /wd4210 /wd4244 /wd4055 /wd4152  /wd4996 /wd4245 /wd4127 /wd4131 /wd4267 /wd4366 
VC8OPT=$(SHOWINCLUDE)     /D NDEBUG /nologo /X $(WARNLVL) /WX- /Od /Oy- /D _WINDOWS /D STRICT /D _CRT_SECURE_NO_DEPRECATE /D VC10EXP $(MBCS)  /Gm-            /MT  /GS /fp:precise /Zc:wchar_t /Zc:forScope /Gd  /J /we4700  /w34701 /wd4100 /wd4214 /wd4057 /wd4996 /wd4706 /wd4210 /wd4210 $(WD4244) /wd4055 /wd4152  /wd4996 /wd4245 /wd4127 /wd4131 /wd4267 /wd4366 
!	ENDIF	
!ENDIF

#source output option ########
#OPTASM=/Fa$(TMPLST)
!IF "$(source)"=="no"
OPTOS2S=/Ls
LISTOS2=/Fl$(TMPLST)ul
OPTDOSS=/Fs$(TMPLST)ul

!	IF "$(w95)"=="vc"    
OPTASMW=/Fa$(TMPLST)ul
!	ELSE
#OPTASMW=-S
!	ENDIF

!ELSE     #else source(no)
!	IF "$(source)"=="nul"
OPTOS2S=
LISTOS2=
OPTDOSS=
OPTASM=
OPTASMW=
!	ELSE		#else SOURCE(null)
!		IF "$(dosv)"=="gcc"        
OPTASMG=-S
!		ELSE
OPTASMG=
!		ENDIF
LISTOS2=/Fl$(TMPLST)
OPTDOSS=/Fs$(TMPLST)
#OPTASM=/Fa$(TMPLST)
!		IF "$(w95)"=="vc"    
OPTASMW=/Fa$(TMPLST)$<
!		ELSE
OPTASMW=-S
!		ENDIF

!	ENDIF
!ENDIF
###
########################################
########################################
########################################
!IF "$(os)"=="w95"    
!	IF "$(w98)"=="vc8" #~8724I~
ALL	:$(LIBDIR)user.lib
!	ELSE #~8724I~
!		IF "$(w98)"=="vc10" #always !NOMT_TRACE
ALL	:$(LIBDIR)user.lib  $(LIBDIR)utils.obj $(LIBDIR)utrace_mt.obj
!		ELSE #~8724I~
ALL	:$(LIBDIRMT)usermt.lib	$(LIBDIR)user.lib $(LIBDIR)utils.obj
!		ENDIF #~8724I~
!	ENDIF #~8724I~
!ELSE
ALL 	:$(LIBDIR)user.lib
!ENDIF
!IF "$(os)"=="w95"    
$(LIBDIRMT)usermt.lib:  \
					$(LIBDIRMT)u3270.obj   \
					$(LIBDIRMT)u32702.obj   \
					$(LIBDIRMT)u32703.obj   \
					$(LIBDIRMT)ueh.obj   \
#	IF "$(x64)"=="yes"    
#	ELSE
					$(LIBDIRMT)uehmsg.obj   \
#   ENDIF
					$(LIBDIRMT)uabend.obj	 \
					$(LIBDIRMT)ualloc.obj   \
					$(LIBDIRMT)ucalc.obj   \
					$(LIBDIRMT)ucalc2.obj   \
					$(LIBDIRMT)ucvebc.obj \
					$(LIBDIRMT)ucvebc2.obj \
					$(LIBDIRMT)ucvebc3.obj \
					$(LIBDIRMT)ucvebc32.obj \
					$(LIBDIRMT)ucvebc4.obj \
					$(LIBDIRMT)ucvebct.obj \
					$(LIBDIRMT)ucvext.obj \
					$(LIBDIRMT)ucvext12.obj \
					$(LIBDIRMT)ucvext2.obj \
					$(LIBDIRMT)ucvucs.obj \
					$(LIBDIRMT)ucvucst.obj \
!	IF "$(x64)"=="yes"    
!	ELSE
					$(LIBDIRMT)uda.obj \
					$(LIBDIRMT)uda2.obj \
					$(LIBDIRMT)udaits.obj \
					$(LIBDIRMT)udamt.obj \
					$(LIBDIRMT)udamtf.obj \
					$(LIBDIRMT)udap.obj \
					$(LIBDIRMT)udasub.obj \
!   ENDIF
					$(LIBDIRMT)udbcschk.obj \
					$(LIBDIRMT)udbcsck2.obj \
					$(LIBDIRMT)udos.obj \
					$(LIBDIRMT)udos2.obj \
					$(LIBDIRMT)uedit.obj   \
					$(LIBDIRMT)uedit2.obj   \
!	IF "$(x64)"=="yes"    
!	ELSE
					$(LIBDIRMT)uehdump.obj   \
!   ENDIF
					$(LIBDIRMT)uerr.obj	 \
					$(LIBDIRMT)ufemsg.obj   \
					$(LIBDIRMT)ufile.obj   \
					$(LIBDIRMT)ufile12.obj   \
					$(LIBDIRMT)ufile1f.obj \
					$(LIBDIRMT)ufile2.obj   \
					$(LIBDIRMT)ufile2f.obj \
					$(LIBDIRMT)ufile3.obj   \
					$(LIBDIRMT)ufile3f.obj   \
					$(LIBDIRMT)ufile4.obj   \
					$(LIBDIRMT)ufile5.obj   \
					$(LIBDIRMT)uftp.obj   \
					$(LIBDIRMT)uftp2.obj   \
					$(LIBDIRMT)uftp3.obj   \
!IF "$(x64)"=="yes"    
!ELSE
					$(LIBDIRMT)ufuncmap.obj   \
!ENDIF
					$(LIBDIRMT)ukbd.obj   \
					$(LIBDIRMT)ukbdw.obj   \
					$(LIBDIRMT)umiscf.obj   \
					$(LIBDIRMT)uparse.obj   \
					$(LIBDIRMT)upopup.obj   \
					$(LIBDIRMT)uproc.obj   \
					$(LIBDIRMT)uproc2.obj   \
					$(LIBDIRMT)uproc22.obj   \
					$(LIBDIRMT)uproc3.obj   \
					$(LIBDIRMT)uproc4.obj   \
					$(LIBDIRMT)uque.obj     \
					$(LIBDIRMT)uregex.obj     \
					$(LIBDIRMT)ustring.obj   \
					$(LIBDIRMT)ustrcpy.obj   \
					$(LIBDIRMT)utf.obj      \
					$(LIBDIRMT)utf2.obj      \
					$(LIBDIRMT)utf22.obj     \
					$(LIBDIRMT)utf3.obj      \
					$(LIBDIRMT)utf4.obj      \
  					$(LIBDIRMT)utrace.obj   \
					$(LIBDIRMT)uvio.obj   \
					$(LIBDIRMT)uvio2.obj   \
					$(LIBDIRMT)uviom.obj   \
!		IF "$(x64)"=="yes"    
!		ELSE
					$(LIBDIRMT)uwinsp.obj   \
!       ENDIF
					$(LIBDIRMT)uwinsub.obj   \
					user.mak
  $(EXELIBPATH)LIB $(LIBDIRMT)usermt.lib /LIST:$(LIBDIRMT)usermt.map /VERBOSE
#@if     exist err  type err
!ENDIF

$(LIBDIR)user.lib:  \
!IF "$(os)"=="w95"    
  					$(LIBDIR)u3270.obj   \
  					$(LIBDIR)u32702.obj   \
  					$(LIBDIR)u32703.obj   \
!ENDIF
!IF "$(os)"=="dos"	
!	IF "$(dosv)"=="gcc"	
  					$(LIBDIR)udpmilib.obj   \
  					$(LIBDIR)udpmilb2.obj   \
  					$(LIBDIR)udpmilb3.obj   \
   					$(LIBDIR)udpmisub.obj   \
   					$(LIBDIR)udpmivio.obj   \
					$(LIBDIR)ueh.obj   \
					$(LIBDIR)uehmsg.obj   \
!	ELSE
  					$(LIBDIR)uvintbp.obj   \
   					$(LIBDIR)ukintf.obj   \
!	ENDIF
!ELSE
					$(LIBDIR)ueh.obj   \
#	IF "$(x64)"=="yes"    
#	ELSE
					$(LIBDIR)uehmsg.obj   \
#	ENDIF
!ENDIF
					$(LIBDIR)uabend.obj	 \
					$(LIBDIR)ualloc.obj   \
					$(LIBDIR)ucalc.obj   \
					$(LIBDIR)ucalc2.obj   \
!IF "$(os)"=="dos"	&&  "$(dosv)"!="gcc"	
!ELSE
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
!ENDIF
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
!	IF "$(os)"=="w95"    
					$(LIBDIR)ufilew.obj   \
!	ENDIF
					$(LIBDIR)ufile12.obj   \
!	IF "$(os)"=="w95"    
					$(LIBDIR)ufile1f.obj \
!	ENDIF
					$(LIBDIR)ufile2.obj   \
!	IF "$(os)"=="w95"    
					$(LIBDIR)ufile2f.obj \
!	ENDIF
					$(LIBDIR)ufile3.obj   \
!	IF "$(os)"=="w95"    
					$(LIBDIR)ufile3f.obj   \
!	ENDIF
					$(LIBDIR)ufile4.obj   \
					$(LIBDIR)ufile5.obj   \
!	IF "$(os)"=="w95"    
					$(LIBDIR)uftp.obj   \
					$(LIBDIR)uftp2.obj   \
					$(LIBDIR)uftp3.obj   \
!	ENDIF
!IF "$(x64)"=="yes"    
!ELSE
					$(LIBDIR)ufuncmap.obj   \
!ENDIF
					$(LIBDIR)ukbd.obj   \
!	IF "$(os)"=="w95"    
					$(LIBDIR)ukbdw.obj   \
!	ENDIF
					$(LIBDIR)umiscf.obj   \
					$(LIBDIR)uparse.obj   \
					$(LIBDIR)upopup.obj   \
					$(LIBDIR)uproc.obj   \
					$(LIBDIR)uproc2.obj   \
					$(LIBDIR)uproc22.obj   \
!	IF "$(os)"=="w95"    
					$(LIBDIR)uproc3.obj   \
					$(LIBDIR)uproc4.obj   \
!	ENDIF
					$(LIBDIR)uque.obj     \
!	IF "$(os)"=="w95"    
					$(LIBDIR)uregex.obj   \
!	ENDIF
!	IF "$(os)"=="os2"    
					$(LIBDIR)uregex.obj   \
!	ENDIF
!	IF "$(dosv)"=="gcc"    
					$(LIBDIR)uregex.obj   \
!	ENDIF
					$(LIBDIR)ustring.obj   \
					$(LIBDIR)ustrcpy.obj   \
!	IF "$(os)"=="w95"    
					$(LIBDIR)utf.obj      \
					$(LIBDIR)utf2.obj      \
					$(LIBDIR)utf22.obj      \
					$(LIBDIR)utf3.obj      \
					$(LIBDIR)utf4.obj      \
!	ENDIF
  					$(LIBDIR)utrace.obj   \
					$(LIBDIR)uvio.obj   \
					$(LIBDIR)uvio2.obj   \
!	IF "$(os)"=="w95"    
					$(LIBDIR)uviom.obj   \
!		IF "$(x64)"=="yes"    
!		ELSE
					$(LIBDIR)uwinsp.obj   \
!		ENDIF    	
					$(LIBDIR)uwinsub.obj   \
!	ENDIF
					user.mak
!IF "$(w95)"=="vc"    
  $(EXELIBPATH)LIB     $(LIBDIR)user.lib /LIST:$(LIBDIR)user.map /VERBOSE
!ELSE
!	IF "$(os)"=="dos"	
!		IF "$(dosv)"=="gcc"	
            @echo ----user.lib recreate
#  xdig /nal /21 /1$(LIBDIR)user.map //ar -tv $(LIBDIRU)user.lib
!		IF "$(VER)"==""		#from user.mak
            h:
            cd \gculib
            del user.lib
#       	h:\c6obj\xdig /pf /21 /1g:\src\ulib\err0 . *.obj //h:\djgpp\bin\ar -rv user.lib %%f%%
			h:\gcobj\xdig /pf /21 /1g:\src\ulib\err0 . *.obj //h:\djgpp\bin\ar -rv user.lib %%f%%
            ulib
!		ELSE                #from userxxx.mak<-mk0xxxg.bat<-pack0g.bat(packing)
    		cd ..\gcculib
            del user.lib
#   	    h:\c6obj\xdig /pf /21 /1..\ulib\err0 . *.obj //h:\djgpp\bin\ar -rv user.lib %%f%%
		    h:\gcobj\xdig /pf /21 /1..\ulib\err0 . *.obj //h:\djgpp\bin\ar -rv user.lib %%f%%
    		cd ..\ulib
!		ENDIF
 @if     exist err0 type err0 >> err
 @if     exist err0 type err0
        ar -tv $(LIBDIRU)user.lib >$(LIBDIR)user.map
        type   $(LIBDIR)user.map  >>err
        type   $(LIBDIR)user.map
!		ELSE
   $(EXELIBPATH)LIB $(LIBDIR)user,$(LIBDIR)user.map;
!		ENDIF
!	ELSE
  $(EXELIBPATH)LIB /LISTLEVEL:2 $(LIBDIR)user,$(LIBDIR)user.map;
!	ENDIF
!ENDIF
#@if     exist err  type err
########################################
########################################
########################################
!IF "$(dosv)"=="gcc"	            #gcc
ulibar :
   @echo create lib---user.lib
!	IF "$(VER)"==""		#from user.mak
        h:
        cd \gculib
        del user.lib
#       h:\c6obj\xdig /pf /21 /1g:\src\ulib\err0 . u*.obj //h:\djgpp\bin\ar -rv user.lib %%f%%
        h:\gcobj\xdig /pf /21 /1g:\src\ulib\err0 . u*.obj //h:\djgpp\bin\ar -rv user.lib %%f%%
        ulib
 @if     exist err0 type err0 >> err
 @if     exist err0 type err0
!	ELSE                #pack
		cd ..\gcculib
        del user.lib
#       h:\c6obj\xdig /pf /21 /1..\ulib\err0 . u*.obj //h:\djgpp\bin\ar -rv user.lib %%f%%
        h:\gcobj\xdig /pf /21 /1..\ulib\err0 . u*.obj //h:\djgpp\bin\ar -rv user.lib %%f%%
        cd ..\ulib
 @if     exist err0 type err0 >> err
 @if     exist err0 type err0
!	ENDIF               #
!ENDIF
########################################
########################################
$(LIBDIR)utils.obj:utils.c
 @echo cpl---utils.c  (NO AR to user.lib)
!	IF "$(w98)"=="vc10"	
#  $(EXEPATH)cl /c /DW32 $(VC8OPT) $(OPTWINMT) /D$(TRACE) /I$(INCPATH) $(OPTASMW) /Fo$@ utils.c >err0
   $(EXEPATH)cl /c /DW32 $(VC8OPT) $(OPTWIN)   /D$(TRACE) /I$(INCPATH) $(OPTASMW) /Fo$@ utils.c >err0
!	ELSE
   $(EXEPATH)cl /c $(WARNLVL) /Gd /J /Od /DW32 $(VC8OPT) $(DEBUG) $(OPTWIN)   /D$(TRACE) /I$(INCPATH) $(OPTASMW) /Fo$@ utils.c >err0
!	ENDIF
 @if     exist err0 type err0 >> err
 @if     exist err0 type err0
!IF "$(w98)"=="vc10"	
$(LIBDIR)utrace_mt.obj:utrace.c
 @echo cpl---utrace_mt  (NO AR to user.lib)
	$(EXEPATH)cl /c /DW32 $(VC8OPT) $(OPTWINMT) /D$(TRACE) /I$(INCPATH) $(OPTASMW) /Fo$@ utrace.c >err0
 @if     exist err0 type err0 >> err
 @if     exist err0 type err0
!ENDIF
########################################

!IF "$(os)"=="dos"	
{.}.asm{$(LIBDIR)}.obj:
	masm $<,$@,$(TMPLST);
   	$(EXELIBPATH)LIB $(LIBDIR)user-+$@;
!ENDIF
!IF "$(os)"=="w95"	
{.}.c{$(LIBDIRMT)}.obj:
 @echo cpl---mt $<
#  $(EXEPATH)cl /MT /c /W3 /G3 /Gd /J /Od /DW32 $(OPTWIN) /D$(TRACE) /I$(INCPATH) /Fr$(TMP) $(OPTASMW) /Fo$@ $< >err0
!			IF "$(w98)"=="vc10"	
   $(EXEPATH)cl /c /DW32 $(VC8OPT) $(OPTWIN) /D$(TRACE) /I$(INCPATH) $(OPTASMW) /Fo$@ $< >err0
!			ELSE
   $(EXEPATH)cl $(MTOPT) /c $(WARNLVL) /Gd /J /Od /DW32 $(VC8OPT) $(DEBUG) $(OPTWINMT) /D$(TRACE) /I$(INCPATH) $(OPTASMW) /Fo$@ $< >err0
!			ENDIF
    if     exist $(LIBDIRMT)usermt.lib $(EXELIBPATH)LIB /OUT:$(LIBDIRMT)usermt.lib $(LIBDIRMT)usermt.lib $@ >err0
    if not exist $(LIBDIRMT)usermt.lib $(EXELIBPATH)LIB /OUT:$(LIBDIRMT)usermt.lib $@ >err0
 @if     exist err0 type err0 >> err
 @if     exist err0 type err0
!ENDIF
{.}.c{$(LIBDIR)}.obj:
 @echo cpl---$<
!IF "$(os)"=="os2"	
   ICC.EXE /Ss /Sn $(DEBUG) $(INCPATH) /D$(TRACE) /DOS2 /Kabcg /C $(OPTOS2S) /Gm $(LISTOS2) $(OPTASM) /Fo$* $< >err0
!ELSE
!	IF "$(os)"=="w95"	
!		IF "$(w95)"=="vc"	
#  $(EXEPATH)cl /c /W3 /G3 /Gd /J /Od /DW32 $(DEBUG) $(OPTWIN) /D$(TRACE) /I$(INCPATH) /Fr$(TMP) $(OPTASMW) /Fo$@ $< >err0 #~8724R~
!			IF "$(w98)"=="vc10"	
#  $(EXEPATH)cl /c /DW32 $(VC8OPT) $(OPTWINMT) /D$(TRACE) /I$(INCPATH) $(OPTASMW) /Fo$@ $< >err0
   $(EXEPATH)cl /c /DW32 $(VC8OPT) $(OPTWIN)   /D$(TRACE) /I$(INCPATH) $(OPTASMW) /Fo$@ $< >err0
!			ELSE
   $(EXEPATH)cl /c $(WARNLVL) /Gd /J /Od /DW32 $(VC8OPT) $(DEBUG) $(OPTWIN) /D$(TRACE) /I$(INCPATH) $(OPTASMW) /Fo$@ $< >err0
!			ENDIF
!		ELSE
   $(EXEPATH)\bcc32 -Ig:\src\ulib;$(INCPATH) -c -W -3 -d -k- -w -DW32 -K $(DEBUG) $(OPTASMW) -n$(OUTPATH) $< >err0
!		ENDIF      # vcc  or not
!	ELSE
!		IF "$(dosv)"=="c6"	
#  $(EXEPATH)cl /DC6 /c /Os /AL /W2 /Gt1024 /G2 /Ze /Gs /DDOS /D$(TRACE) $(OPTDOSS) $(OPTASM) $(DEBUG) /Fo$* $< >err0
  cl /DC6 /c /Os /AL /W2 /J $(GTN) /G2 /Ze /Gs /DDOS /D$(TRACE) $(OPTDOSS) $(OPTASM) $(DEBUG) /Fo$* $< >err0
!		ELSE
!			IF "$(dosv)"=="gcc"	
     @echo $* >>err
!				IF "$(OPTASMG)"=="-S"
  	xdig /nal /1err0 /21 //@<<gccpf
gcc -S -funsigned-char -Wall -Wno-conversion -m386 -DDOS -DDPMI $(INCPATH) -D$(TRACE) $(DEBUG) -o $*.s $<
<<KEEP
   	xdig /nal /1err0 /21 //gcc -c $(DEBUG) -o $*.obj $*.s
!				ELSE
   	xdig /nal /1err0 /21 //@<<gccpf
gcc -c -funsigned-char -Wall -Wno-conversion -m386 -DDOS -DDPMI $(INCPATH) -D$(TRACE) $(DEBUG) -o $*.obj $<
<<KEEP
!				ENDIF
!			ELSE
   $(EXEPATH)cl /c /Os /AL /W2 $(GTN) /G2 /Ze /Gs /DDOS /D$(TRACE) $(OPTDOSS) $(OPTASM) $(DEBUG) /Fo$* $< >err0
!			ENDIF      # c6  or not
!		ENDIF      # c6  or not
!	ENDIF      # w95 or not
!ENDIF      # os2 or not
 @if     exist err0 type err0 >> err
 @if     exist err0 type err0
   @echo lib---$(@F)
!IF "$(w95)"=="vc"    
    if     exist $(LIBDIR)user.lib $(EXELIBPATH)LIB /OUT:$(LIBDIR)user.lib $(LIBDIR)user.lib $@ >err0
    if not exist $(LIBDIR)user.lib $(EXELIBPATH)LIB /OUT:$(LIBDIR)user.lib $@ >err0
!ELSE
!	IF "$(dosv)"=="gcc"	
	echo "end of cpl" $(@F)>err0
#!		IF "$(VER)"==""		#from user.mak
#   			h:
#    		cd \gculib  
#		    h:\c6obj\xdig /nal /21 /1g:\src\ulib\err0 //@<<gccpfl2
#    		h:\djgpp\bin\ar -rv user.lib $(@F)
#<<KEEP
#		   ulib
#!		ELSE                #from userxxx.mak<-mk0xxxg.bat<-pack0g.bat(packing)
#    		cd ..\gcculib
#		    h:\c6obj\xdig /nal /21 /1..\ulib\err0 //@<<gccpfl2
#    		h:\djgpp\bin\ar -rv user.lib $(@F)
#<<KEEP
#    		cd ..\ulib
#!		ENDIF
! 	ELSE
        $(EXELIBPATH)LIB $(LIBDIR)user.lib-+$*; >err0
!	ENDIF      # os2 or not
!ENDIF      # os2 or not
 @if     exist err0 type err0 >> err
 @if     exist err0 type err0
###########################
#****************************
!IF "$(os)"=="dos"	
!	IF "$(dosv)"=="gcc"	
!	ELSE
$(LIBDIR)uvintbp.obj:uvintbp.asm
$(LIBDIR)ukintf.obj:ukintf.asm
!	ENDIF      # os2 or not
!ENDIF
################################
