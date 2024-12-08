//*CID://+v9j0R~:                             update#=  341;       //~v9j0R~
//***********************************************************
//* xphlp.c : help sub                                          //~5A10R~//~v983R~
//***********************************************************
//v9j0:240628 show Trace option on Help msg                        //~v9j0I~
//v9h1:190913 no neeed input file when query printer               //~v9h1I~
//v9e5:170826 get dll suffix by uconv --version                    //~v9e5I~
//v9e0:170807 v9.38 tabchar support(tabon:c/x__/u__)               //~v9e0I~
//v98p:140219 helpmsg print dbcs on xterm                          //~v98pI~
//v98h:140208 v98g is no effect;add margin option because origin shift may cut opposit side.//~v98hI~
//v98a:140206 simple shift parameter(previous shift function is expand papersize as custom paper size//~v98aI~
//			  to avoid printer warning of papersize unmatch)       //~v98aI~
//v983:140130 display displaynem of papersize for -e/? like as print operation dialog//~v983I~
//v97k:131104 (gxp)when no multijob(=Nj),not all page printed;projibit Nj option//~v97kI~
//v97j:131104 (gxp)prohibit fastpath(-Yf) option pagecont not determined//~v97jI~
//v97f:131104 (BUG)Order option default was not applied(issues errmsg)//~v97fI~
//v97b:131029 abandon v97a(printer do not expand paper width to landscape width)//~v97bI~
//v97a:131027 -E/A4L/P P:rotate option for printer was not set to Landscape//~v97aI~
//v979:131027 display printer list by -q?                          //~v979I~
//v977:131025 (gxp)other pagesize support by margin shift /E/pper/[T|B|L|R[nn]]//~v977I~
//v974:131011 (GtkPrint)no cmdfile support                         //~v974I~
//v973:131011 (GtkPrint)new form option(E/form[[/]L](2p is by /Y2 only)//~v973I~
//v970:130922 GtkPrint for alternative of Gnomeprint               //~v970I~
//v96i:130726 v9.25 add -EOLPRINT: option to identify eol of vfmt  //~v96iI~
//v96h:130726 v9.25 new -ICU option to support for EBC file on Windows//~v96hI~
//v96e:130724 v9.25 recfm=V(-Vvfmt) support                        //~v96eI~
//101004 v960 option of hex dump by ucs/utf8 for utf8 (/Y8,/N8)    //~v960I~
//101004 v959 correct help msg                                     //~v959I~
//100908 v953 v9.19 EBC convertername support /CPEB:               //~v953I~
//100803 v952 v9.18 japanese help for Linux                        //~v952I~
//100706 v950 v9.18 64bit compile                                  //~v950I~
//100706 v944 v9.17 (gxp)accept cups destination by -q parameter   //~v944I~
//            (use gtk because update of gpa_root by cups printer is done through asyncrronous gtk dispatching system)//~v944I~
//100428 v941 v9.16 ebcdic print support                           //~v941I~
//090728 v93v v9.14 -cmax(max coloumn(=512)) parm for 1 output line/1 input line//~v93vI~
//080130 v92t (BUG) help english spell check                       //~v92tI~
//071024 v92n (LNX)support utf8 file(conv to locale)               //~v92nI~
//            /Y3 optio to control SS3(0x8f) for EUC               //~v92nI~
//071014 v92h (GXP)color parameter                                 //~v92hI~
//071013 v92g (Win)letter size is for height                       //~v92gI~
//071006 v92d (Lnx)UTF8 support                                    //~v92dI~
//071011 v92e (Lnx:BUG)/N9 ignored for help                        //~v92eI~
//071006 v92b text mode vhex dump support                          //~v92bI~
//071006 v92a Help msg for vhex mode(/Mx + /R)                     //~v92aI~
//071005 v928 (Win)UTF8 support                                    //~v928I~
//071006 v929 (W32)helpmsg screen height;chk screen buff           //~v929I~
//050607 v924 /Yo option is duplicated with /O                     //~v924I~
//050607 v923 Doc correction                                       //~v923I~
//050606 v922 (UNX)same effect of default /yo option as oyher than UNX//~v922I~
//            (if no -Y/No is specified,sort when no /Ol and widlcard/dir input)//~v922I~
//            to sort double quation for wildcard                  //~v922I~
//050606 v921 outputfilename by -q parm only to avoid override for also other than UNX//~v921I~
//050606 v920 (UNX:BUG)help msg ostype err                         //~v920I~
//050606 v91z (BUG of v90k)help msg correct(/y2 option is not only for win)//~v91zI~
//050606 v91y (BUG of v91w)help by japanese(uhelpmsg support SJIS to EUC conversion)//~v91yI~
//050606 v91x add /Nu option to bypass set 0x0c(form feed) for linux convenience//~v91xI~
//050511 v91v (BUG)help bug,-Y/Ne option defualt is Ye for also UNX//~v91vI~
//050322 v91s help exit by 'q'                                     //~v91sI~
//040531 v91k (FTP)remote file print support;"<orgfname>LocalTempFile" fmt//~v91kI~
//                 on parm and indirect file.                      //~v91kI~
//021223 v91e missing help msg for 2p fmt                          //~v91eI~
//020720 v916 (WIN)auto set form orientation by option /Yd         //~v916I~
//020703 v910 lineno and page continue opt by /I[x]xx-xx/[nn] parm //~v910I~
//020406 v90v (WIN)Letter support for the case drive setup is not work//~v90vI~
//011227 v90s another english mode keisen                          //~v90sR~
//011209 v90n :(BUG)help msg for /Yr,default is /Yr                //~v90nI~
//011209 v90m :support stdout output                               //~v90mI~
//010526 v90j :ScrPrt support(/WN=linenosz /WS=xxx(xxx=org filename))//~v90jI~
//010522 v90h :AIX support(hline is dup with curses rtn)           //~v90hR~
//010520 v90a :LINUX support(multifile seperater change from "/" to ":")//~v90aI~
//010519 v907 :LINUX support                                       //~v907I~
//010402 v905 :newpage reset may not required when new windows version.//~v905I~
//            (Skip reset for each page when /Nr to page print speed up)//~v905I~
//010401 v904 :2 parts print suport for windows printer            //~v904I~
//            (no form parm for windows,auto pich calc by device info)//~v904I~
//001105 v902 :new sort order option "F"(fullname),not base+ext
//990918 v895 :move trt file option to /Kfxxxx from /Mmfxxxx       //~v895I~
//990918 v893 :supprt TRT by file                                  //~v893I~
//990915 v891 :EBCDIC support /M.e[k/e]                            //~v891I~
//981124 v884 :helpmsg correxct                                    //~v884I~
//981116 v883 :(WIN)calc lpi for also line numbers not specified(default)//~v883I~
//981115 v876 :(WIN)drop 18cpi because cpi can be any value and may calc by maxcol//~v876I~
//981114 v875 :(WIN)set lpi when specified maxline only(no lpi/no form specified)//~v875I~
//981114 v874 :(WIN)set cpi when specified maxcol only(no cpi/no form specified)//~v875I~
//981114 v873 :(WIN)any cpi value support min=28(14)cpi max=1cpi   //~v875I~
//981114 v872 :(WIN)133 colum support(18cpi)                       //~v875I~
//981028 v869 :docname parm support(/J)                            //~v869I~
//981024 v863 :(WIN)change keisen default                          //~v863I~
//981010 v857 :/Yk-->/Kx;x=0(through),g(graphic),k(katakana),any char//~v857I~
//981006 v853 :change default char set for hexdump mode ito 'j'(keisen by '.')//~v853I~
//981001 v846 :keisen print for non ibm(/yk,/nk)                   //~v846I~
//980927 v844 :(WIN) /EW option(use Win32 API to use spool)        //~v844I~
//971130 v838 :new option /Qoutfile to avoid positional parm for xe//~v838I~
//971129 v836 :GCC version                                         //~v836I~
//971123 v828 :(BUG) title msg err(reverse date and type)          //~v828I~
//970928 v826 :w95 version                                         //~v826I~
//             put version id for help/last line                   //~v826I~
//970214 v807:use FINDBUF3 by ufile.h                              //~v807I~
//970206 v801:/Yv option to print files in a dir conjunctly        //~v801I~
//            (dir sort mode only to avoid double confirmation)    //~v801I~
//961214 v789:char set for cannon(dbcs but x00-x1f is unprintable) //~v789I~
//961108 v785:1st page EJECT bypass option                         //~v785I~
//961106 v784:ESCP has ROMAN font                                  //~v784I~
//961106 v783:Cannon printer support(LIPS-III)                     //~v783I~
//960707 v767 :(BUG)missing help for /Yi                           //~v767I~
//960707 v765 :form feed ignore option for text mode w/o record option//~v765I~
//960113 v752 :set lpitch default to 6-lpi                      //~v752I~
//951110 v74o :page concat by '+' not by ',' for xe use         //~v74oI~
//950829 v74l :form id on /E                                    //~v74lI~
//950829 v74j :date AND/OR support                              //~v74jI~
//950829 v74i :cpi by file max col but under /C parm(not fixed) //~v74iI~
//950828 v74b :background option                                //~v74bI~
//950821 v742 :input file stdin support                         //~v742I~
//950810 v741 :reduce module size(move genaral/help/history to xp.doc)//~5A10I~
//940927 v7.291:chng parm key /= --> /E (BAT file can not accept "=")
//             :force sbcsenv /N9 option
//940826 v7.28:ESC/P kanji font style
//940820 v7.26:/Yf:fast process option(phase2 only)
//940819 v7.24 :char pitch,line pitch,font style parameter.
//940818 v7.23 :devided because too large to compile under ibmc2
//*************************************************************
#include <time.h>     //v1.1
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>    //v1.6add
#include <string.h>   //v1.3add

#ifdef DOS                           //v3.6a

    #include <dos.h>                     //v3.7a                //~v74jR~
    #include <errno.h>                   //v3.7a                //~v74jR~
    #include <bios.h>                   //av4.2                 //~v74jR~

#else 

  #ifdef W32                                                       //~v826I~
  #else                                                            //~v826I~
    #define _KEYBRD_READ        0   /* read next character from keyboard */ //v7.0a//~v74jR~
    #define _KEYBRD_READY       1   /* check for keystroke */               //v7.0a//~v74jR~
    #define INCL_BASE                                           //~v74jI~
    #include <os2.h>                                            //~v74jI~
  #endif                                                           //~v826I~

#endif

#include <ulib.h>                                               //~v74jI~
#include <ufile.h>                                                 //~v807I~
#include <ufile5.h>                                                //~v96eI~
#include <uerr.h>                                                  //~v907I~
#include <udbcschk.h>                                              //~v952I~
//*********************************************************************//~v74jI~
#include  "xp.h"                                                //~v74jI~
#include  "xpsub1.h"                                               //~v91yI~
#ifdef GXP                                                         //~v92hI~
#include  "xplnxp.h"                                               //~v92hI~
#endif                                                             //~v92hI~
#include  "xpebc.h"                                                //~v953I~
//*********************************************************************
//* global to share with xpsub
//*********************************************************************
extern char pgmid[];
extern char ver[];
extern int tabskip;      //tab skip colomn count
extern int  dbcsenv;           //dbcs environment sw
//extern int maxline;    //line   no per page                   //~v74lR~
//extern int maxcol;      //colomn no per line                  //~v74lR~
//extern int colmax1;   //maxcolomn for  pich 5cpi              //~v74lR~
//extern int colmax2;   //maxcolomn for  pich 6cpi              //~v74lR~
//extern int colmax3;   //maxcolomn for  pich 6.7cpi if over pich 7.5 cpi//~v74lR~
extern char swsw1;          //switches                          //~v74jI~

int kbdinp(USHORT);             //keyboard input wait  v5.2a v7.0r
//*********************************************************************
#ifdef AIX                                                         //~v90hR~
    #define hline xphline   //aix curses lib has same name         //~v90hR~
#endif                                                             //~v90hR~
void hline(char *);         //v6.5a help msg 1 line output
//*********************************************************************

//**********************************************************************
//* write abridge help msg  v7.23a
//**********************************************************************
void helpabridge(void)
{
//#ifdef DOS                                                       //~v920R~
//  #ifdef DPMI                 //DPMI version                     //~v920R~
//    int os='G';                                                  //~v920R~
//  #else                       //not DPMI                         //~v920R~
//    int os='D';                                                  //~v920R~
//  #endif                      //DPMI or not                      //~v920R~
//#else                                                            //~v920R~
//    #ifdef W32                                                   //~v920R~
//        int os='W';                                              //~v920R~
//    #else                                                        //~v920R~
//        int os='2';                                              //~v920R~
//    #endif                                                       //~v920R~
//#endif                                                           //~v920R~
    int os=OSTYPE;                                                 //~v920I~
    char buff[128];//sprintf work
    int dbcsmode;                                                  //~v91yI~
//*******************
#ifdef LNX                                                         //~v91yI~
  if (UCBITCHK(Guerropt,GBL_UERR_FORCEENG))                        //~v92eR~
	dbcsmode=0;                                                    //~v92eI~
  else                                                             //~v92eI~
  {                                                                //~v952I~
#ifdef AAA                                                         //~v98pI~
	dbcsmode=dbcsenvchk();				//uerrhelpmsg support SJIS->EUC conversion//~v91yI~
    if (Gudbcschk_flag & UDBCSCHK_UTF8J)                           //~v952I~
        dbcsmode=1;                                                //~v952I~
#else                                                              //~v98pI~
    hline("===\n");   //dummy to get dbcsmode                      //~v98pI~
    dbcsmode=UCBITCHK(Guerropt,GBL_UERR_DBCSMODE)!=0;              //~v98pI~
#endif                                                             //~v98pI~
  }                                                                //~v952I~
#else                                                              //~v91yI~
	dbcsmode=dbcsenv;					//same as xprint.c setting //~v91yI~
#endif                                                             //~v91yI~
//if (dbcsenv)  //DBCS mode                                        //~v91yR~
  if (dbcsmode)  //DBCS mode                                       //~v91yI~
  {
    hline((sprintf(buff,
//        "\n �`��(%s)   :  %s ���̓t�@�C���@[�o�͐�] [%c�I�v�V���� %c...]\n",//~v921R~
          "\n �`��(%s)   :  %s [%c�I�v�V���� %c...] ���̓t�@�C�� [���̓t�@�C��...]\n",//~v923R~
                                ver,pgmid,                         //~v907R~
                                CMDFLAG_PREFIX,CMDFLAG_PREFIX      //~v907I~
								),buff));                          //~v907I~
    hline((sprintf(buff,                                           //~v91kI~
//        "   ���̓t�@�C��;���C���h�J�[�h�A�f�B���N�g���[���n�j�B\n"),buff));//~v921R~
          "   ���̓t�@�C��;���C���h�J�[�h�A�f�B���N�g���[���n�j�B�����w��OK�B\n"),buff));//~v921I~
//  hline((sprintf(buff,                                           //~v921R~
//        "                �������͂� %c �ŘA���B��) dir1%cdir2�B\n",//~v921R~
//                              MULTI_SEPC,MULTI_SEPC              //~v921R~
//  							),buff));                          //~v921R~
//  hline((sprintf(buff,                                           //~v921R~
//        "   �o�͐�     ;PRN(�ȗ��l),LPTx,�t�@�C�����ȂǁB\n"),buff));//~v921R~
//  hline((sprintf(buff,                                           //~v921R~
//        "              ;OS/2�ł�QUEUE��,�v�����^�[�����w��B\n"),buff));//~v921R~
#ifdef UTF8EBCD //EBCDIC dbcs support                              //~v941I~
    hline((sprintf(buff,                                           //~v953I~
          "   %c%s    ;0x15 �ł͂Ȃ� (0x0d)0x0a �� EBCDIC �t�@�C�����s�����Ƃ���\n",//~v953R~
							CMDFLAG_PREFIX,GOO_ASCEOLS),buff));    //~v953I~
    hline((sprintf(buff,                                           //~v941I~
          "   %cBCfilenm  ;EBCIDC �ϊ�cfg�t�@�C����. xe �Ƌ��p\n",//~v941R~//~v96eR~
							CMDFLAG_PREFIX),buff));                //~v941I~
    hline((sprintf(buff,                                           //~v96eI~
          "              ;ICU���g�p����ꍇ�͑����%cICU���w�肵�Ă��ǂ�\n",//~v96eI~
							CMDFLAG_PREFIX),buff));                //~v96eI~
#ifdef W32                                                         //~v9e5I~
    hline((sprintf(buff,                                           //~v9e5I~
          "              ;���̏ꍇ�� uconv.exe, ICU .dll ��PATH ��ʂ����ƁB\n"//~v9e5R~
							              ),buff));                //~v9e5R~
#else                                                              //~v9e5I~
    hline((sprintf(buff,                                           //~v9e5I~
          "              ;���̏ꍇ�� uconv �� PATH  ICU .so �� LD_LIBRARY_PATH ��ʂ�\n"//~v9e5R~
							              ),buff));                //~v9e5R~
#endif                                                             //~v9e5I~
    hline((sprintf(buff,                                           //~v953I~
          "   %c%s=cp   ;cp : EBCDIC �R�[�h�y�[�W\n",              //~v953R~
							CMDFLAG_PREFIX,PARM_CPEB),buff));      //~v953I~
    hline((sprintf(buff,                                           //~v953I~
          "              ; ex) xprint ebcfile %cMe %c%s=CP1047 %cICU\n",//~v953I~//~v96eR~
							CMDFLAG_PREFIX,CMDFLAG_PREFIX,PARM_CPEB,CMDFLAG_PREFIX),buff));//~v953R~//~v96eR~
#endif          //EBCDIC dbcs support                              //~v941I~
    hline((sprintf(buff,
          "   %cC[-]nn[/p];1�s�̌���/�����s�b�`�B\n",              //~v907R~
          				CMDFLAG_PREFIX                             //~v907I~
						),buff));                                  //~v907I~
    hline((sprintf(buff,                                        //~v74lI~
          "              ;�ȗ��l�� A4 �̏ꍇ �t�@�C���ɂ�� %d ���� %d ���� 5 ������\n",//~v74lI~
                                COLMAX1,MAXCOL),buff));//v7.24r //~v74lI~
//#ifndef UNX                                                        //~v907I~//~v93vR~
#if defined(W32) || defined(GXP)                                   //~v93vI~
    hline((sprintf(buff,                                           //~v907I~
//        "              ;(%cEw�̏ꍇcpi,Form�̎w�肪�Ȃ��ꍇ������cpi�𖳒i�K����)\n",//~v907R~//~v93vR~
          "              ;(%cEw�̏ꍇcpi,Form�̎w�肪�Ȃ��ꍇ���̌�����cpi�𖳒i�K����\n",//~v93vR~
						CMDFLAG_PREFIX),buff));                    //~v907I~
    hline((sprintf(buff,                                           //~v93vI~
          "              ; %cCmax �Ƃ���ƍŒ��s�̌�����cpi�𒲐�����)\n",//~v93vR~
						CMDFLAG_PREFIX),buff));                    //~v93vI~
#endif                                                             //~v907I~
    hline("              ;\"-\"�� nn ���ő�l�Ƃ��� 5 �����݂Ƃ���w��\n");//~v844R~
    hline((sprintf(buff,                                           //~v907I~
          "              ;p(cpi): %cEi : 5, 6, 67,     75\n",      //~v907R~
						CMDFLAG_PREFIX),buff));                    //~v907I~
    hline((sprintf(buff,                                           //~v907I~
          "              ;        %cEe : 5, 6,         75\n",      //~v907R~
						CMDFLAG_PREFIX),buff));                    //~v907I~
    hline((sprintf(buff,                                           //~v907I~
          "              ;        %cEc : 5, 6, 67, 72, 75\n",      //~v907R~
						CMDFLAG_PREFIX),buff));                    //~v907I~
#ifndef UNX                                                        //~v907I~
    hline((sprintf(buff,                                           //~v907I~
          "              ;        %cEw : �C�ӂ̒l,15�ȏ��1/10�P�ʂƌ��Ȃ���܂�\n",//~v907R~
						CMDFLAG_PREFIX),buff));                    //~v907I~
#endif                                                             //~v907I~
    hline((sprintf(buff,                                           //~v907I~
          "   %cDccts     ;�t�@�C���̃^�C���X�^���v�ɂ��I��\n",  //~v907R~
						CMDFLAG_PREFIX),buff));                    //~v907R~
    hline("     [-|+ccts];\"-\":AND \"+\":OR ��������\n");      //~v74jI~
    hline((sprintf(buff,                                           //~v907I~
          "              ;cc:�I������,ts:�t�@�C������(yymmdd[hhmm])�B��@%cDLT931210:1230\n",//~v907R~
						CMDFLAG_PREFIX),buff));                    //~v907I~
    hline((sprintf(buff,                                           //~v953I~
          "   %c%s    ;0x15 �� EBCDIC �t�@�C�����s�����Ƃ���\n",   //~v953I~
							CMDFLAG_PREFIX,GOO_EBCEOLS),buff));    //~v953I~
    hline((sprintf(buff,                                           //~v96iI~
          "   %c%sfmt;�ϒ����R�[�h�̍s���Ƀ��R�[�h�����������printf�`��\n",//~v96iR~
							CMDFLAG_PREFIX,PARM_EOLPRINT),buff));  //~v96iI~
    hline((sprintf(buff,                                           //~v96iI~
          "              ;    ��B %c%s::  \"%c%s:%%%% 7d\"\n",    //~v96iR~//~v96eR~
						CMDFLAG_PREFIX,PARM_EOLPRINT,CMDFLAG_PREFIX,PARM_EOLPRINT),buff));//~v96iR~
#ifdef UNX                                                         //~v907I~
  #ifdef GXP                                                       //~v92bI~
   #ifdef GTKPRINT                                                 //~v970I~
    hline((sprintf(buff,                                           //~v970I~
//        "   %cE[w]/form[L];�p���T�C�Y[������]�B(�Q��/����%cY2�Ŏw��)\n",//~v973I~//~v977R~
//        "   %cE[w]/form[L][/{T|B|L|R}[ss]];�p���T�C�Y�BL:�������B\n",//~v977I~//~v97aR~
//          "   %cE[w]/form[L][/[P]{T|B|L|R}[ss]];�p���T�C�Y�BL:�������B\n",//~v97aI~//~v97bR~
//        "   %cE[w]/form[L][/{{T|B}|{L|R}}[ss]];�p���T�C�Y�BL:�������B\n",//~v98aR~
#ifdef MMM                                                         //~v98hI~
          "   %cE[w]/form[L][/[O]{{T|B}|{L|R}}[ss[P]]];�p���T�C�Y�BL:�������B\n",//~v98aI~
#else                                                              //~v98hI~
//        "   %cE[w]/form[L][/[M]{{T|B}|{L|R}}[ss[P]]];�p���T�C�Y�BL:�������B\n",//~v9h1R~
          "   %cE/form[L][/[M]{{T|B}|{L|R}}[ss[P]]];�p���T�C�Y�BL:�������B\n",//~v9h1I~
#endif                                                             //~v98hI~
						CMDFLAG_PREFIX),buff));                    //~v977I~
    hline("              ;form �� ? �Ƃ���Ǝg�p��\x94\x5c�ȗp���T�C�Y�����X�g����A\n");//~v983I~
    hline("              ;�܂����j�[�N�Ȃ畔��������ł��悢(gxp�ł̂�)\n");//~v983I~
//  hline("              ;P:�������̓v�����^�[�Őݒ肷(gxp�ł�90����]�����Ȃ�)�B\n");//~v97aI~//~v97bR~
#ifdef MMM                                                         //~v98hI~
    hline("              ;O:�㑱�̃V�t�g�p�����[�^�����W���_�̃V�t�g�ł��邱�Ƃ̎w��B\n");//~v98aI~
#else                                                              //~v98hI~
    hline("              ;M:�㑱�̃p�����[�^���}�[�W�����ł��邱�Ƃ̎w��B\n");//~v98hI~
#endif                                                             //~v98hI~
#ifdef MMM                                                         //~v98hI~
    hline("              ;\"O\"�̎w��Ȃ��̓y�[�p�[�T�C�Y���v�����^�[�̗p���T�C�Y�G���[��\n");//~v98aI~
#else                                                              //~v98hI~
    hline("              ;\"M\"�̎w��Ȃ��̓y�[�p�[�T�C�Y���v�����^�[�̗p���T�C�Y�G���[��\n");//~v98hI~
#endif                                                             //~v98hI~
    hline("              ;�����邽�߂ɗp���T�C�Y���g�����܂��B\n");//~v98aI~
//  hline("              ;{T|B}|{L|R}:�㉺���E�Bss:�V�t�g��(mm),�w��Ȃ���A4����ɃV�t�g\n");//~v98aR~
#ifdef MMM                                                         //~v98hI~
    hline("              ;{T|B}|{L|R}:�V�t�g�����A�㉺���E\n");    //~v98aI~
#else                                                              //~v98hI~
    hline("              ;{T|B}|{L|R}:�����A�c�u������ɂ����㉺���E\n");//~v98hI~
#endif                                                             //~v98hI~
    hline("              ;ss[P]:�V�t�g�� �P�ʂ�mm, \"P\" �w��Ń|�C���g\n");//~v98aI~
//  hline("              ;�v�����^�[�̗p���z���_�[���p���ƍ���Ȃ��Ƃ��Ɏ����Ă��������B\n");//~v98aR~
#ifdef MMM                                                         //~v98hI~
    hline("              ;\"O\"�����̃V�t�g�w��́A\n");           //~v98aI~
#else                                                              //~v98hI~
    hline("              ;\"M\"�����̃V�t�g�w��́A\n");           //~v98hI~
#endif                                                             //~v98hI~
    hline("              ;�v�����^�[�̗p���z���_�[���p���ƍ���Ȃ��Ƃ��Ɏ����Ă��������B\n");//~v98aI~
    hline("              ;�Ⴆ��B5���w�肷��Ɨp���̂�r������������Ă��܂��ꍇ, \n");//~v977I~
    hline((sprintf(buff,                                           //~v977I~
          "              ;\"%cE/B5/T\"�ň���J�n�s�ʒu��������ɃV�t�g����B5�ɍ��킹�܂��B\n",//~v977I~
						CMDFLAG_PREFIX),buff));                    //~v977I~
    hline("              ;ss ���w�肵�Ȃ���A4�p����Œ[�����킹������̎w��ɂȂ�܂�\n");//~v98hI~
//  hline((sprintf(buff,                                           //~v98hR~
//        "              ;(�Q��/����%cY2�Ŏw��)\n",                //~v98hR~
//						CMDFLAG_PREFIX),buff));                    //~v98hR~
   #else                                                           //~v970I~
    hline((sprintf(buff,                                           //~v92bI~
          "   %cEx[/form] ;�v�����^�[�^�C�v�Bx=i(IBM),=e(ESC/P),=c(Canon),=w(Gnome)\n",//~v92bI~
						CMDFLAG_PREFIX),buff));                    //~v92bI~
   #endif                                                          //~v970I~
  #else                                                            //~v92bI~
    hline((sprintf(buff,                                           //~v907I~
          "   %cEx[/form] ;�v�����^�[�^�C�v�Bx=i(IBM),=e(ESC/P),=c(Canon)\n",//~v907I~
						CMDFLAG_PREFIX),buff));                    //~v907I~
  #endif                                                           //~v92bI~
#else                                                              //~v907I~
    hline((sprintf(buff,                                           //~v907R~
          "   %cEx[/form] ;�v�����^�[�^�C�v�Bx=i(IBM),=e(ESC/P),=c(Canon),=w(Windows)\n",//~v907R~
						CMDFLAG_PREFIX),buff));                    //~v907R~
#endif                                                             //~v907I~
#ifdef GTKPRINT                                                    //~v970I~
    hline((sprintf(buff,                                           //~v970I~
//        "              ;��B %cEw/A4 %cE/B5 %cE/A4L %cE/LegalL/T10 %cE/b5jis/br\n",//~v973I~//~v977R~//~v9h1R~
          "              ;��B %cE/A4 %cE/B5 %cE/A4L %cE/LegalL/T10 %cE/b5jis/br\n",//~v9h1I~
						CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX),buff));//~v970I~//~v973R~//~v97aR~
#ifdef MMM                                                         //~v98hI~
    hline((sprintf(buff,
          "              ;     %cE/A4/OL18P %cE//OL10B5\n",        //~v98aI~
						CMDFLAG_PREFIX,CMDFLAG_PREFIX),buff));     //~v98aI~
#else                                                              //~v98hI~
    hline((sprintf(buff,                                           //~v98hI~
          "              ;     %cE/A4/ML18P %cE//ML10B10L10R10 %cE/B5L/r10b10Mr10t10\n",//~v98hR~
						CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX),buff));//~v98hR~
#endif                                                             //~v98hI~
#else                                                              //~v970I~
    hline("              ;form(�p��)=A4,B4,B5,A4L,B4L,B5L(L:��)�B\n");//~v907R~
    hline("              ;           A42,B42,B52,A4L2,B4L2,B5L2�B(2:2��/��)\n");//v7.291r//~v91eR~
#endif                                                             //~v970I~
#ifndef GTKPRINT                                                   //~v974I~
    hline((sprintf(buff,                                           //~v907I~
          "   %cE@cmdf    ;�v�����^�[�R�}���h�t�@�C���w��B\n",    //~v907R~
							CMDFLAG_PREFIX),buff));                //~v907R~
#endif                                                             //~v974I~
    hline((sprintf(buff,                                           //~v907I~
          "   %cFFXxx     ;���ŕ���(FormFeed=x'0c')��u�����镶��. xx �� HEX ����\n",//~v907R~
							CMDFLAG_PREFIX),buff));                //~v907R~
    hline((sprintf(buff,                                           //~v907I~
#ifdef GTKPRINT                                                    //~v970I~
          "   %cFhhh      ;�t�H���g.\n",                           //~v970I~
#else                                                              //~v970I~
          "   %cFhhh[/zzz];hhh:���p�t�H���g�^�C�v;zzz:�S�p�t�H���g�^�C�v(ESCP�̂�).\n",//~v923R~
#endif                                                             //~v970I~
							CMDFLAG_PREFIX),buff));                //~v907R~
#ifdef GXP                                                         //~v92bI~
  #ifdef GTKPRINT                                                  //~v970I~
    hline("              ;hhh�� ? �Ƃ���Ǝg�p��\x94\x5c�ȃt�H���g�����X�g����.(gxp�ł̂�)\n");//~v970I~
    hline("              ;�Ⴆ�� \"-F?abc\" �� \"abc\" ���܂ރt�H���g�����X�g����.\n");//~v970I~
  #else                                                            //~v970I~
    hline("              ;hhh�� ? �Ƃ���Ǝg�p��\x94\x5c�ȃt�H���g�����X�g����.(Gnome�ł̂�)\n");//~v92bI~
  #endif                                                           //~v970I~
#else                                                              //~v92bI~
    hline("              ;hhh�� ? �Ƃ���Ǝg�p��\x94\x5c�ȃt�H���g�����X�g����.(Win�ł̂�)\n");//~v923R~
#endif                                                             //~v92bI~
#ifndef GTKPRINT                                                   //~v970I~
    hline("              ;     IBM    :0,GOT,ELI,COU,MIN,OCB,ORE.\n");//v7.24av7.28r//~v844I~
    hline("              ;     ESC/P  :0,ROM,SAN,COU,PRE,SCR,OCB,OCA,GOT,MIN.\n");//v7.24av7.28r//~v907R~
    hline("              ;     Canon  :LIN,COU,SWI,DUT,MIN,GOT.\n");//~v844R~
#endif                                                             //~v970I~
#ifdef GXP                                                         //~v92bI~
    hline((sprintf(buff,                                           //~v92hI~
  #ifdef GTKPRINT                                                  //~v970I~
          "              ;��. %cFSans %cf\"Monospace;Italic Bold\".\n",//~v970R~
							CMDFLAG_PREFIX,CMDFLAG_PREFIX),buff)); //~v970I~
  #else                                                            //~v970I~
          "              ;     Gnome  :\"font-name\". ��. %cF\"Monospace Regular\".\n",//~v92hR~//~v953R~//~v970R~
							CMDFLAG_PREFIX),buff));                //~v92hI~
  #endif                                                           //~v970M~
#else                                                              //~v92bI~
    hline("              ;     Windows:SYS,COU,ROM,MIN,GOT,\"font-name\"\n");//~v844R~
#endif                                                             //~v92bI~
    hline((sprintf(buff,                                           //~v96eI~
          "   %cICU       ;EBCDIC �t�@�C���̕ϊ���ICU���g�p\n",    //~v96eR~
							CMDFLAG_PREFIX),buff));                //~v96eI~
    hline((sprintf(buff,                                           //~v907I~
          "   %cI[n]-[m][/pp] ;�s���ɂ�����͈́B        pp�͊J�n��No�B\n",//~v910R~
							CMDFLAG_PREFIX),buff));                //~v907R~
    hline((sprintf(buff,                                           //~v907I~
          "   %cIx[s]-[e][/pp];�I�t�Z�b�g�l�ɂ�����͈́B\n",    //~v910R~
							CMDFLAG_PREFIX),buff));                //~v907R~
#ifndef UNX                                                        //~v907R~
    hline((sprintf(buff,                                           //~v907I~
          "   %cJjobname  ;(Win��,OS/2�ł̂�)�v�����^�[ QUEUE ��̃W���u��(������)�ݒ�\n",//~v907R~
							CMDFLAG_PREFIX),buff));                //~v907R~
    hline("              ;�ȗ��l�͓��̓t�@�C������ݒ�B\n");      //~v869I~
#endif                                                             //~v910M~
    hline((sprintf(buff,                                           //~v907I~
          "   %cKx        ;�e�L�X�g���[�h�̎�,���{��DOS�̌r�������R�[�h(0x01,...)��ϊ�\n",//~v907R~
							CMDFLAG_PREFIX),buff));                //~v907R~
    hline("              ;x=0:���ϊ�\n");                          //~v90sR~
    hline("              ;x=g:ASCII��d������(0xb5,0xb6,..)�ɕϊ�\n");//~v90sR~
    hline("              ;x=k:�J�^�J�i�����Z�b�g�̌r������(0x8f,...)�ɕϊ�(cpi�ɒ���)\n");//~v90sR~
    hline("              ;x=L:ASCII��d������(0xb3,0xb4,..)�ɕϊ�\n");//~v90sR~
    hline("              ;x=(���̑� 'f' �ȊO�̔C�ӂ� 1 ����)\n");  //~v895R~
                                                                   //~v907I~
#ifdef UNX                                                         //~v907I~
    hline((sprintf(buff,                                           //~v907I~
          "              ;�ȗ��l��%cEi�ł�%cK0;���̑���%cMx,%cMta�̂Ƃ�%cK0,�ȊO%cK/.\n",//~v907I~
							CMDFLAG_PREFIX,CMDFLAG_PREFIX,         //~v907I~
							CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX,//~v907I~
							CMDFLAG_PREFIX),buff));                //~v907I~
#else                                                              //~v907I~
    hline((sprintf(buff,                                           //~v907I~
          "              ;�ȗ��l��%cEi,%cEw�ł�%cK0;���̑���%cMx,%cMta�̂Ƃ�%cK0,�ȊO%cK/.\n",//~v907R~
							CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX,//~v907I~
							CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX,//~v907I~
							CMDFLAG_PREFIX),buff));                //~v907I~
#endif                                                             //~v907I~
    hline((sprintf(buff,                                           //~v907I~
          "   %cKFfilenm  ;256�o�C�g�R�[�h�ϊ��e�[�u���t�@�C����.\n",//~v907R~
							CMDFLAG_PREFIX),buff));                //~v907R~
    hline((sprintf(buff,
          "   %cLnn[x][/p];1�ł̍s��(�ȗ��l=%d),x=d(�_�u���X�y�[�X),x=t(�g���v���X�y�[�X)\n",//~v907R~
							CMDFLAG_PREFIX,                        //~v90aI~
                                MAXLINE),buff));                   //~v90aR~
    hline((sprintf(buff,                                        //~v752I~
          "   �@�@�@�@ �@;p(lpi)=2, 3, 4, 5, 6, 75, 8.(�ȗ��l=%d)\n",//~v752R~
                                DEFAULTLPI),buff));//v7.24a     //~v752R~
#ifndef UNX                                                        //~v907I~
    hline((sprintf(buff,                                           //~v907I~
          "              ;(%cEw�ł͂���ȊO�C�ӂ̒l���w��ł��܂�,15�ȏ��1/10�P��.\n",//~v907R~
							CMDFLAG_PREFIX),buff));                //~v907R~
    hline("              ; �܂�lpi,Form�w��̂Ȃ��ꍇ�s������lpi�𖳒i�K����)\n");//~v883R~
#endif                                                             //~v907I~
    hline((sprintf(buff,                                           //~v907I~
//          "   %cMm[c][e][n];�v�����g���[�h�Bm=t:�e�L�X�g,d:�_���v,x:�w�L�T�_���v.(%cMtd)\n",//~v907R~//~v96eR~
//                            CMDFLAG_PREFIX,CMDFLAG_PREFIX),buff)); //~v907R~//~v96eR~
          "   %cMm[c][e][n];�v�����g���[�h�Bm=t:�e�L�X�g(�ȗ��l),\n",//~v96eI~
                            CMDFLAG_PREFIX),buff));                //~v96eI~
    hline("              ;  d:�_���v(����s\x94\\������\".\"��\x95\\��),\n");//~v96eI~
    hline("              ;  x:�w�L�T�_���v,\n");                   //~v96eR~
    hline("              ;  tx:�e�L�X�g���[�h�ŏc�w�L�T�_���v�R�i\x95\\��\n");//~v96eR~
//    hline((sprintf(buff,                                           //~v92bI~//~v96eR~
////        "              ;%cMx�̂Ƃ�%cR���w�肷��ƃ��R�[�h���[�h�R�i�_���v\x95\\��\n",//~v92bI~//~v96eR~
////                          CMDFLAG_PREFIX,CMDFLAG_PREFIX),buff)); //~v92bI~//~v96eR~
//          "              ;%cMx�̂Ƃ�%cR �܂��� %cV ���w�肷��ƂR�i�_���v\x95\\��\n",//~v96eR~
//                            CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX),buff));//~v96eR~
#ifdef UTF8SUPP                                                    //~v92bI~
    hline("              ;c:����Code.c=d:���{��DBCS,s:SBCS,a:ASCII,j:JIS,e:EBCDIC,u:UTF-8.\n");//~v92bR~
#else                                                              //~v92bI~
    hline("              ;c:�����Z�b�g.c=d:���{��DBCS,s:SBCS,a:ASCII,j:JIS,e:EBCDIC.\n");//~v90vR~
#endif                                                             //~v92bI~
#ifdef WCSUPP                                                      //~v941I~
//  hline("              ;   �ȗ��l�͊��ɏ]�� \n");              //~v941R~//~v959R~
    hline((sprintf(buff,                                           //~v941I~
//        "              ;     =%s\n",                             //~v941I~//~v959R~
          "              ;   �ȗ��l�͊��ɏ]��(=%s)�B\n",         //~v959R~
						Gdefaultlocalecode),buff));                //~v941I~
#else                                                              //~v941I~
    hline((sprintf(buff,                                           //~v907I~
          "              ;(�ȗ��l�� %cMx�̂Ƃ� j,�ȊO�ł� d.)\n",  //~v907R~
							CMDFLAG_PREFIX),buff));                //~v907I~
#endif                                                             //~v941I~
#ifdef UTF8EBCD //EBCDIC dbcs support                              //~v941I~
    hline("              ;e:EBCDIC�ϊ��^�C�v\n");                  //~v941R~
//  hline("              ;  c:cfg�t�@�C���w��(�ȗ��l,�t�@�C������BC�I�v�V�����Ŏw��)\n");//~v941R~//~v953R~
    hline("              ;  c:cfg�t�@�C���w��(�ȗ��l)\n");         //~v953I~
    hline((sprintf(buff,                                           //~v953I~
          "              ;   %cBC �� %c%s �̎w�肪�K�v\n",         //~v953R~
						CMDFLAG_PREFIX,CMDFLAG_PREFIX,PARM_CPEB),buff));//~v953I~
//    hline("              ;    ��B xprint ebcfile /Me /bcEbcmap.cfg\n");//~v941I~//~v96eR~
    hline((sprintf(buff,                                           //~v96eI~
          "              ;    ��B xprint ebcfile %cMte %cbcD:\\Ebcmap.cfg\n",//~v96eI~//~v96hR~//~v96eR~
						CMDFLAG_PREFIX,CMDFLAG_PREFIX),buff));     //~v96eI~
    hline((sprintf(buff,                                           //~v96eI~
          "              ;  i:ICU�g�p(%cICU�̑���Acfg�͎g�p���Ȃ�)�B%c%s �̎w�肪�K�v\n",//~v96eR~
						CMDFLAG_PREFIX,CMDFLAG_PREFIX,PARM_CPEB),buff));          //~v96hR~//~v96eR~
    hline((sprintf(buff,                                           //~v96hI~
          "              ;    ��B xprint ebcfile %cMei %c%s=cp930\n",//~v96hR~//~v96eR~
						CMDFLAG_PREFIX,CMDFLAG_PREFIX,PARM_CPEB),buff));//~v96hR~
    hline("              ;  k:���{��J�^�J�i�g��(DBCS����)\n");    //~v941R~
    hline("              ;  e:���{��p�������g��(DBCS����)\n");    //~v941R~//~v944R~
#else                                                              //~v941I~
    hline("              ;e:EBCDIC�����Z�b�g�^�C�v(e=k:�J�^�J�i(�ȗ��l),e:�p������)\n");//~v891I~
#endif                                                             //~v941I~
    hline("              ;n:�X�L�����[�h��.\n");                   //~v853R~
//  hline("              ;  ����n�ȏ�̘A����������\�����݂̂��E���Ĉ��.\n");//~v96eR~
    hline("              ;  ����n�ȏ�̘A�����������\x94\\�����݂̂��E���Ĉ��.\n");//~v96eI~
    hline((sprintf(buff,                                           //~v953I~//~v96eM~
          "              ; ex) xprint ebcf %cmtxe %cR80\n",         //~v953R~//~v96eM~
							CMDFLAG_PREFIX,CMDFLAG_PREFIX),buff)); //~v953R~//~v96eM~
    hline((sprintf(buff,                                           //~v950I~//~v953M~//~v96eM~
//        "              ;     xprint utf8file %cMtxu \n",         //~v950R~//~v953I~//~v960R~//~v96eM~
//  						CMDFLAG_PREFIX),buff));                //~v950I~//~v953M~//~v960R~//~v96eM~
          "              ;     xprint utf8file %cMu %cN8\n",     //~v960I~//~v96eR~
    						CMDFLAG_PREFIX,CMDFLAG_PREFIX),buff)); //~v960I~//~v96eM~
//  hline("   /O[[-]x]   ;���̓t�@�C���̏o�͏���(x=e:�g���q,n:���O,d:����,l:���X�g)�B(/On)\n");//~v801R~
    hline((sprintf(buff,                                           //~v907I~
          "   %cO[[-]x]   ;���̓t�@�C���̏o�͏����B\n",            //~v924R~
							CMDFLAG_PREFIX),buff));                //~v924R~
    hline("              ;x=b:�x�[�X��,e:�g���q,n:���O,d:����,l:�w�菇�B\n");//~v902R~
    hline((sprintf(buff,                                           //~v97fI~
//          "              ; �ȗ��l�� Dir/WildCard����Ȃ�%cOb,�ȊO�ł� %cOl)\n",//~v97fI~
//  						CMDFLAG_PREFIX,CMDFLAG_PREFIX),buff)); //~v97fI~
          "              ;(�ȗ��l�� Dir/WildCard����Ȃ�%cOb,�ȊO�� %cOl, %cO �� %cOE)\n",//~v97fR~
  							CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX),buff));//~v97fI~
//  hline("   /Pnn[-nn]  ;�v�����g����o�͕ł͈̔�,\"+\"�ŕ����A���\.\n");//~v836R~
    hline((sprintf(buff,                                           //~v907I~
          "   %cPnn[-nn]  ;�v�����g����o�͕ł͈̔�,\"+\"�ŕ����A����\x94\\.\n",//~v907R~
							CMDFLAG_PREFIX),buff));                //~v907R~
    hline((sprintf(buff,                                           //~v907I~
          "   %cP[nn]/[f] ;�v�����g�ĊJ����t�@�C���Ƃ��̍ĊJ�ŁB\n",//~v907R~
							CMDFLAG_PREFIX),buff));                //~v907R~
    hline((sprintf(buff,                                           //~v907I~
//        "   %cQofile    ;�o�͐�(��2�p�����[�^�̑�p)\n",         //~v921R~
#ifdef GXP                                                         //~v973I~
          "   %cQprinter  ;�o�͐� ;(�f�t�H���g�̃v�����^) \n",     //~v973I~
#else                                                              //~v973I~
          "   %cQofile    ;�o�͐� ;prn(�ȗ��l),LPTx,�t�@�C�����ȂǁB\n",//~v923R~
#endif                                                             //~v973I~
							CMDFLAG_PREFIX),buff));                //~v921I~
#ifdef GXP                                                         //~v950I~
  #ifdef GTKPRINT                                                  //~v973I~
    hline((sprintf(buff,                                           //~v973I~
          "              ;�v�����^�[�̃��X�g�� \"-Q?\" or \"lpstat -p -d\".\n"),buff));//~v973I~//~v979R~
  #else                                                            //~v973I~
    hline((sprintf(buff,                                           //~v950I~
          "              ;�f�t�H���g�ȊO��CUPS�v�����^���w�肷��ƃ|�b�v�A�b�v���o��.\n"),buff));//~v950I~
  #endif                                                           //~v973I~
    hline((sprintf(buff,                                           //~v950M~
          "              ;  ex) %cqlp1400. (CUPS�v�����^���̕���������w���OK).\n",//~v950M~
						CMDFLAG_PREFIX),buff));                    //~v950M~
#else                                                              //~v950I~
    hline((sprintf(buff,                                           //~v921I~
          "              ;OS/2�ł�QUEUE��,�v�����^�[�����w��B\n"//~v923R~
							),buff));                              //~v923R~
#endif                                                             //~v950I~
    hline((sprintf(buff,                                           //~v90mI~
          "              ;\"%cq-\",\"%cq--\"(����MSG��)�ŕW���o�͂ɏo��\n",//~v90mR~
							CMDFLAG_PREFIX,CMDFLAG_PREFIX),buff)); //~v90mI~
    hline((sprintf(buff,                                           //~v907I~
          "   %cR[recsz]  ;���R�[�h���[�h�̎w��ƃ��R�[�h��\n",    //~v907R~
							CMDFLAG_PREFIX),buff));                //~v907R~
    hline((sprintf(buff,                                           //~v96eI~
          "              ; ex) xprint frecf %cMd %cR120\n",        //~v96eR~
							CMDFLAG_PREFIX,CMDFLAG_PREFIX),buff)); //~v96eI~
#ifdef GXP                                                         //~v92hI~
    hline((sprintf(buff,                                           //~v92hI~
          "   %cRGB=rrggbb;�e�L�X�g�̃J���[RGB�l(rr/gg/bb:00->ff, default:%06X)\n",//~v92hR~
						CMDFLAG_PREFIX,(DEFAULT_PRINTCOLOR>>8)),buff));//~v92hI~
#endif                                                             //~v92hI~
    hline((sprintf(buff,
          "   %cTnn       ;�^�u�L�[�Ői�߂錅�ʒu�B(%cT%d)\n",     //~v907R~
          					CMDFLAG_PREFIX,CMDFLAG_PREFIX,	       //~v907I~
                                tabskip),buff));                   //~v9e0R~
    hline((sprintf(buff,                                           //~v9e0I~
          "   %cTabon:x:y:z ;�e�L�X�g���[�h�̂Ƃ���DBCS�X�y�[�X,�^�u����,�^�u�X�L�b�v��\n",//~v9e0R~
          					CMDFLAG_PREFIX),                       //~v9e0I~
                                buff));                            //~v9e0I~
    hline((sprintf(buff,                                           //~v9e0I~
          "                ;��ֈ�������Bx,y,z�� �����A�w�L�T�����܂��̓��j�R�[�h�B\n"),//~v9e0R~
                                buff));                            //~v9e0I~
    hline((sprintf(buff,                                           //~v9e0I~
          "                ;��) %cTabon:x2020:x18:x1a  %cTabon::u2191:u2192 %cTabon::u25cb\n",//~v9e0I~
          					CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX),//~v9e0I~
                                buff));                            //~v9e0I~
    hline((sprintf(buff,                                           //~v9e0I~
          "                ;    %cTabon:u2750\n",                  //~v9e0R~
          					CMDFLAG_PREFIX),                       //~v9e0I~
                                buff));                            //~v9e0I~
    hline((sprintf(buff,                                           //~v9e0I~
          "                ;�ȗ��l�� UTF8/EBCDIC�t�@�C�� %cTabon:u3000:x20:x20\n",//~v9e0R~
          					CMDFLAG_PREFIX),                       //~v9e0I~
                                buff));                            //~v9e0I~
    hline((sprintf(buff,                                           //~v9e0I~
          "                ;                        �ȊO %cTabon:x8140:x20:x20\n",//~v9e0R~
          					CMDFLAG_PREFIX),                       //~v9e0I~
                                buff));                            //~v9e0I~
    hline((sprintf(buff,                                           //~v96eI~
          "   %cVvfmt     ;�ϒ����R�[�h�`���B\n",                //~v96eR~
          					CMDFLAG_PREFIX),buff));                //~v96eR~
    hline((sprintf(buff,                                           //~v96eI~
          "              ;vfmt:%s,%s(MicroFocus),%s(Halfword),%s(Data��),%s(Fullword),%s\n",//~v96eR~
                                VFMT_DEFAULT,VFMT_MFH,VFMT_HW,VFMT_HWDATA,VFMT_FW,VFMT_FWDATA),buff));//~v96eR~
    hline((sprintf(buff,                                           //~v96eI~
          "              ;  ��Bxprint vrlfile %cvh %cMd %c%s:\n", //~v96eR~
						CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX,PARM_EOLPRINT),buff));//~v96eR~
    hline((sprintf(buff,                                           //~v907I~
          "   %cWdir      ;�ō~���v�����g�p���[�N�t�@�C���f�B���N�g���[�B(%s)\n",//~v907R~
							CMDFLAG_PREFIX,WKFDIR),buff));         //~v907R~
    hline((sprintf(buff,                                           //~v90jI~
          "   %cWN=n      ;�p���s�����炵�����B(%cWN=0)\n",        //~v90jI~
							CMDFLAG_PREFIX,CMDFLAG_PREFIX),buff)); //~v90jI~
//#ifdef W32                                                       //~v92dR~
#if defined(W32)||defined(GXP)                                     //~v92dI~
    hline((sprintf(buff,                                           //~v90vI~
          "   %cZHnn      ;(Win/Gnome�ł̂�)�����̈��k���Bnn %%%%�B(�ȗ��l:nn=100)�B\n",//~v92dR~
							CMDFLAG_PREFIX),buff));                //~v90vI~
    hline("               (nn=L �� nn=94�Ń��^�[�T�C�Y�p)�B\n");   //~v92gI~
    hline((sprintf(buff,                                           //~v90vI~
          "   %cZWnn      ;(Win/Gnome�ł̂�)�����̈��k���Bnn %%%%�B(�ȗ��l:nn=100)�B\n",//~v92dR~
							CMDFLAG_PREFIX),buff));                //~v90vI~
//  hline("               (nn=L �� nn=94�Ń��^�[�T�C�Y�p)�B\n");   //~v92gR~
#endif                                                             //~v90vI~
    hline((sprintf(buff,                                           //~v907I~
          "   %cYx,%cNx    ;�g�O���X�C�b�`�`���I�v�V�����B(�d���͍Ōオ�L��)\n",//~v907R~
							CMDFLAG_PREFIX,CMDFLAG_PREFIX),buff)); //~v907R~
#ifndef UNX                                                        //~v923I~
    hline((sprintf(buff,                                           //~v907I~
          "       a      ;�ۑ������I���̑I���B(%cNa)\n",           //~v91xR~
							CMDFLAG_PREFIX),buff));                //~v907R~
#endif                                                             //~v923I~
    hline((sprintf(buff,                                           //~v907I~
          "       b      ;�o�b�N�O�����h���s�B(%cNb)\n",           //~v91xR~
							CMDFLAG_PREFIX),buff));                //~v907R~
    hline((sprintf(buff,                                           //~v907I~
          "       c      ;�f�B���N�g���[,���C���h�J�[�h�w��̎��t�@�C�����̈���m�F�B(%cYc)\n",//~v923R~
							CMDFLAG_PREFIX),buff));                //~v907R~
#ifdef OS2                                                         //~v916I~
    hline((sprintf(buff,                                           //~v907I~
          "(OS/2) d      ;�o�͂̈���W���u�ɕ�������ݒ肷�邩�ۂ��B(%cYd)\n",//~v907R~
							CMDFLAG_PREFIX),buff));                //~v916R~
#endif                                                             //~v916I~
#ifdef W32                                                         //~v916I~
    hline((sprintf(buff,                                           //~v916I~
          "(Win ) d      ;�h���C�o�[�ɑ΂��p���ݒ���s���B(%cYd)\n",//~v916R~
							CMDFLAG_PREFIX),buff));                //~v916I~
#endif                                                             //~v916I~
#ifdef GTKPRINT                                                    //~v970I~
    hline((sprintf(buff,                                           //~v970I~
          "(gxp ) d      ;�|�b�v�A�b�v�_�C�A���O�Ńv�����^/�p����I��(%cNd).\n",//~v970I~
						CMDFLAG_PREFIX),buff));                    //~v970I~
#endif                                                             //~v970I~
//#ifdef UNX                                                       //~v91vR~
//    hline((sprintf(buff,                                         //~v91vR~
//          "       e      ;����/���s�s�b�`�ݒ� Esc �R�}���h�𔭍s���邩�ۂ��B(%cNe)\n",//~v91vR~
//							CMDFLAG_PREFIX),buff));                //~v91vR~
//#else                                                            //~v91vR~
    hline((sprintf(buff,                                           //~v907I~
          "       e      ;����/���s�s�b�`�ݒ� Esc �R�}���h�𔭍s���邩�ۂ��B(%cYe)\n",//~v907R~
							CMDFLAG_PREFIX),buff));                //~v907R~
//#endif                                                           //~v91vR~
#ifndef GTKPRINT                                                   //~v97jI~
    hline((sprintf(buff,                                           //~v907I~
          "       f      ;�Z���Ԏ��s���[�h�B(%cNf)\n",             //~v907R~
							CMDFLAG_PREFIX),buff));                //~v907R~
#endif                                                             //~v97jI~
    hline((sprintf(buff,                                           //~v907I~
          "       g      ;���Q�[�W�i�Q�s�ڂ̃w�b�_�[�s)���o�͂��邩�ۂ��B(%cYg)\n",//~v907R~
							CMDFLAG_PREFIX),buff));                //~v907R~
    hline((sprintf(buff,                                           //~v907I~
          "       h      ;�w�b�_�[�s�i�P�s��)���o�͂��邩�ۂ��B(%cYh)\n",//~v907R~
							CMDFLAG_PREFIX),buff));                //~v907R~
    hline((sprintf(buff,                                           //~v907I~
          "       i      ;���̓t�@�C�������Ԑڃt�@�C�����w��t�@�C���B(%cNi)\n",//~v907R~
							CMDFLAG_PREFIX),buff));                //~v907R~
#ifndef GTKPRINT                                                   //~v97kI~
    hline((sprintf(buff,                                           //~v907I~
          "       j      ;�v�����g�W���u�����B(PRN%cLPTn �̎� %cYj,����ȊO %cNj)\n",//~v907R~
							CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX),buff));//~v907R~
#endif                                                             //~v97kI~
    hline((sprintf(buff,                                           //~v907I~
          "       l      ;�_���v���[�h�̎� CR+LF �ŉ��s(%cYl)\n",  //~v907R~
							CMDFLAG_PREFIX),buff));                //~v907R~
#ifndef UNX                                                        //~v923I~
    hline((sprintf(buff,                                           //~v907I~
          "       m      ;�v�����g������ɕۑ��������I�t�ɂ���(%cNm)\n",//~v907R~
							CMDFLAG_PREFIX),buff));                //~v907R~
#endif                                                             //~v923I~
//  hline("       n      ;�s�v���t�B�N�X(�s�ԍ�/�I�t�Z�b�g�l)�\���B(/Yn)\n");//~v836R~
    hline((sprintf(buff,                                           //~v907I~
          "       n      ;�s�v���t�B�N�X(�s�ԍ�/�I�t�Z�b�g�l)\x95\\���B(%cYn)\n",//~v907R~
							CMDFLAG_PREFIX),buff));                //~v907R~
//    hline((sprintf(buff,                                         //~v924R~
//          "       o      ;�t�@�C���o�͏�\x83\\�[�g�B�����t�@�C����\x83\\�[�g���鎞�g�p�B\n"),buff));//~v924R~
//    hline((sprintf(buff,                                         //~v924R~
//          "               (%cOl�w��Ȃ�����Dir�w�肠��̂Ƃ� %cYo, �ȊO %cNo)\n",//~v924R~
//                            CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX),buff));//~v924R~
    hline((sprintf(buff,                                           //~v907I~
          "       p      ;�ł�Ŕԍ��̍~���Ƀv�����g(%cNp)\n",     //~v907R~
							CMDFLAG_PREFIX),buff));                //~v907R~
    hline((sprintf(buff,                                           //~v907I~
          "(Win)  r      ;�Ŗ��Ƀt�H���g�̍Đݒ������(%cYr)\n",   //~v90nR~
							CMDFLAG_PREFIX),buff));                //~v907R~
    hline("              ;������x�͒x����Windows�̌Â��o�[�W�����ł͕K�v�B\n");//~v90aR~//~v96eR~
    hline((sprintf(buff,                                           //~v907I~
          "       s      ;�w�L�T�_���v�ŘA��������e�s���܂Ƃߏo�́B(%cYs)\n",//~v907R~
							CMDFLAG_PREFIX),buff));                //~v907R~
    hline((sprintf(buff,                                           //~v9j0I~
          "       t      ;Trace(Internal Use, %cNt)\n",            //+v9j0R~
						CMDFLAG_PREFIX),buff));                    //~v9j0I~
    hline((sprintf(buff,                                           //~v91xI~
          "       u      ;�ł̐؂�ڂŃt�H�[���t�B�[�h�R�}���h(0x0c)�}���B(%cYu)\n",//~v91xI~
							CMDFLAG_PREFIX),buff));                //~v91xI~
    hline((sprintf(buff,                                           //~v907I~
          "       v      ;�t�@�C���̐؂�ڂŕőւ������B(%cNv)\n", //~v907R~
							CMDFLAG_PREFIX),buff));                //~v907R~
    hline((sprintf(buff,                                           //~v907I~
          "       0      ;���̓t�@�C���� stdin �� �W�����͂ƌ��Ȃ��B(%cY0)\n",//~v907R~
							CMDFLAG_PREFIX),buff));                //~v907R~
#ifdef UNX                                                         //~v907I~
    hline((sprintf(buff,                                           //~v907I~
          "       1      ;1�Ŗڂ̑O�ɕŊ��̃R�}���h�𔭍s�B(%cN1)\n",//~v907I~
							CMDFLAG_PREFIX),buff));                //~v907I~
#else                                                              //~v907I~
    hline((sprintf(buff,                                           //~v907I~
          "       1      ;1�Ŗڂ̑O�ɕŊ��̃R�}���h�𔭍s�B(%cEc��%cN1,�ȊO%cY1)\n",//~v907R~
							CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX),buff));//~v907R~
#endif                                                             //~v907I~
    hline((sprintf(buff,                                           //~v907I~
          "       2      ;2��%c1�� ����B(%cN2)\n",                //~v91zR~
							CMDFLAG_PREFIX,CMDFLAG_PREFIX),buff)); //~v907R~
#if defined(LNX) && !defined(GXP)                                  //~v92nI~
    hline((sprintf(buff,                                           //~v92nI~
          "       3      ;UTF8����EUC�ϊ������Ƃ��⏕����(SS3:0x8f�t)��F�߂邩(%cN3)\n",//~v92nI~
						CMDFLAG_PREFIX),buff));                    //~v92nI~
    hline((sprintf(buff,                                           //~v92nI~
          "              ;%cN3�Ȃ�'?'�����ɏo�͂���\n",        //~v92nI~
						CMDFLAG_PREFIX),buff));                    //~v92nI~
#endif                                                             //~v92nI~
    hline((sprintf(buff,                                           //~v907I~
          "       6      ;16 �o�C�g��  �w�L�T�_���v �B(%cN6)\n",   //~v907R~
							CMDFLAG_PREFIX),buff));                //~v907R~
    hline((sprintf(buff,                                           //~v960I~
          "       8      ;UTF-8�t�@�C���̏c�R�i HEX �_���v��UTF-8�R�[�h\x95\\���B\n"//~v960R~
							),buff));                              //~v960R~
    hline((sprintf(buff,                                           //~v960I~
          "              ;%cN8 �Ȃ�UCS�R�[�h��\x95\\���B(%cY8)\n", //~v960I~
							CMDFLAG_PREFIX,CMDFLAG_PREFIX),buff)); //~v960I~
    hline((sprintf(buff,                                           //~v907I~
          "       9      ;SBCS(%cN9)/DBCS(%cY9)���̋���(����)\n",//~v907R~
							CMDFLAG_PREFIX,CMDFLAG_PREFIX),buff)); //~v907R~
    hline((sprintf(buff,                                           //~v826I~
          "---------------(%c)-------------------------------------------------------------\n",//~v826R~
                                os),buff));                        //~v826I~
    hline((sprintf(buff,                                           //~v907I~
          "   %cH,%c?      ;�w���v�B\n",                           //~v907R~
							CMDFLAG_PREFIX,CMDFLAG_PREFIX),buff)); //~v907I~
//  hline("   /G         ;�@�\�̊T������.\n");                  //~5810R~
//  hline("   /V         ;�o�[�W�����������.\n");              //~5810R~
  }
  else          //SBCS mode
  {
    hline((sprintf(buff,
//        "\nformat(%s) : %s in-file [destination] [%coption %c...]\n",//~v921R~
          "\nformat(%s) : %s [%coption %c...] in-file [in-file...] \n",//~v923R~
                            ver,pgmid,                             //~v907I~
          					CMDFLAG_PREFIX,CMDFLAG_PREFIX),buff)); //~v907R~
    hline((sprintf(buff,                                           //~v91kI~
          "  in-file    ;File,Wildcard or Directory. multiple specification is accepted.\n"),buff));//~v921R~
//  hline((sprintf(buff,                                           //~v921R~
//        "              concatinate by %c for multiple file. ex) dir1%cdir2.\n",//~v921R~
//                              MULTI_SEPC,MULTI_SEPC              //~v921R~
//  							),buff));                          //~v921R~
//  hline((sprintf(buff,                                           //~v921R~
//        "  destination;PRN(default),LPTx,file-name etc.\n"),buff));//~v921R~
//  hline((sprintf(buff,                                           //~v921R~
//        "             ;QUEUE name or Printer name is valid for OS/2 version.\n"),buff));//~v921R~
#ifdef UTF8EBCD //EBCDIC dbcs support                              //~v941I~
    hline((sprintf(buff,                                           //~v941I~//~v953M~
          "  %c%s    ;Not 0x15 but (0x0d)0x0a is EOL of EBCDIC file\n",//~v941R~//~v953R~
							CMDFLAG_PREFIX,GOO_ASCEOLS),buff));                //~v941I~//~v953I~
    hline((sprintf(buff,                                           //~v953I~
          "  %cBCfilenm  ;EBCIDC translation cfg filename. shares with xe.\n",//~v953I~//~v96eR~
							CMDFLAG_PREFIX),buff));                //~v953I~
    hline((sprintf(buff,                                           //~v96eI~
          "             ;%cICU is alternative when using ICU\n",   //~v96eR~
							CMDFLAG_PREFIX),buff));                //~v96eI~
#ifdef W32                                                         //~v9e5I~
    hline((sprintf(buff,                                           //~v9e5I~
          "             ;set PATH to uconv.exe and ICU .dll if %cBCfilenm omitted.\n",//~v9e5I~
							CMDFLAG_PREFIX),buff));                //~v9e5I~
#else                                                              //~v9e5I~
    hline((sprintf(buff,                                           //~v9e5I~
          "              ;set PATH to uconv, LD_LIBRARY_PATH to ICU .so if %cBCfilenm omitted.\n",//~v9e5I~
							CMDFLAG_PREFIX),buff));                //~v9e5I~
#endif                                                             //~v9e5I~
    hline((sprintf(buff,                                           //~v953I~
          "  %c%s      ;EBCDIC codepage.\n",                       //~v953R~
							CMDFLAG_PREFIX,PARM_CPEB),buff));      //~v953I~
    hline((sprintf(buff,                                           //~v953I~
          "             ; ex) xprint ebcfile %cMe %c%s=CP1047 %cICU\n", //~v953R~//~v96eR~
							CMDFLAG_PREFIX,CMDFLAG_PREFIX,PARM_CPEB,CMDFLAG_PREFIX),buff));//~v953R~//~v96eR~
#endif          //EBCDIC dbcs support                              //~v941I~
    hline((sprintf(buff,                                           //~v884I~
//        "  %cC[-]nn[/p];max colomn per line / char pitch.\n",    //~v92tR~
          "  %cC[-]nn[/p];max column per line / char pitch.\n",    //~v92tI~
						CMDFLAG_PREFIX),buff));                    //~v907I~
    hline((sprintf(buff,                                        //~v74lI~
          "             ;default is,for form A4,%d to %d step by 5 depending on file.\n",//~v74lR~
                            COLMAX1,MAXCOL),buff));//v7.24r     //~v74lI~
//#ifndef UNX                                                        //~v907I~//~v93vR~
#if defined(W32) || defined(GXP)                                   //~v93vI~
    hline((sprintf(buff,                                           //~v907I~
//        "             ;(for %cEw,cpi is calc from maxcol when no cpi,font specified).\n",//~v907R~//~v93vR~
          "             ;(for %cEw,cpi is calc by this maxcol when no cpi,font specified.\n",//~v93vR~
						CMDFLAG_PREFIX),buff));                    //~v907I~
    hline((sprintf(buff,                                           //~v93vI~
          "             ; %cCmax means maxcol is of the longest line.)\n",//~v93vR~
						CMDFLAG_PREFIX),buff));                    //~v93vI~
#endif                                                             //~v907I~
    hline("             ;\"-\" means step by 5 up to the value(not fixed max col).\n");//~v74iR~//~v97kR~
    hline((sprintf(buff,                                           //~v907I~
          "             ;p(cpi): %cEi : 5, 6, 67,     75\n",       //~v907R~
							CMDFLAG_PREFIX),buff));//v7.24av7.291r //~v907R~
    hline((sprintf(buff,                                           //~v907I~
          "             ;        %cEe : 5, 6,         75\n",       //~v907R~
							CMDFLAG_PREFIX),buff));//v7.24av7.291r //~v907R~
    hline((sprintf(buff,                                           //~v907I~
          "             ;        %cEc : 5, 6, 67, 72, 75\n",       //~v907R~
							CMDFLAG_PREFIX),buff));//v7.24av7.291r //~v907R~
#ifndef UNX                                                        //~v907I~
    hline((sprintf(buff,                                           //~v907I~
          "             ;        %cEw : any value,if >=15 it is treated as unit of 1/10)\n",//~v907R~
							CMDFLAG_PREFIX),buff));                //~v907R~
#endif                                                             //~v907I~
    hline((sprintf(buff,                                           //~v907I~
          "  %cDccts     ;file selection by time stamp\n",         //~v907R~
							CMDFLAG_PREFIX),buff));                //~v907R~
    hline("    [-|+ccts];\"-\":AND \"+\":OR condition combination\n");//~v907R~
    hline((sprintf(buff,                                           //~v907I~
          "             ;cc:condition,ts:file timestamp(yymmdd[hhmm]). ex. %cDLT931210:1230\n",//~v907R~
							CMDFLAG_PREFIX),buff));                //~v907R~
    hline((sprintf(buff,                                           //~v953I~
          "  %c%s    ;EBCDIC file EndOfLine ID is 0x15\n",         //~v953R~
							CMDFLAG_PREFIX,GOO_EBCEOLS),buff));    //~v953I~
    hline((sprintf(buff,                                           //~v96iI~
          "  %c%sfmt;printf format to print record length of recfm=V file.\n",//~v96iR~
							CMDFLAG_PREFIX,PARM_EOLPRINT),buff));  //~v96iI~
    hline((sprintf(buff,                                           //~v96iI~
          "             ;    ex) %c%s::  \"%c%s:%%%% 7d\"\n",      //~v96iR~//~v96eR~
						CMDFLAG_PREFIX,PARM_EOLPRINT,CMDFLAG_PREFIX,PARM_EOLPRINT),buff));//~v96iR~
#ifdef UNX                                                         //~v907I~
  #ifdef GXP                                                       //~v92bI~
   #ifdef GTKPRINT                                                 //~v970I~
    hline((sprintf(buff,                                           //~v970I~
//        "  %cE[w]/form[L];PaperSize[Landscape]. (2-page/sheet is by %cY2)\n",              //~v970I~//~v973R~//~v977R~
//        "  %cE[w]/form[L][/[P]{T|B|L|R}[ss]];PaperSize[Landscape].\n",//~v97aI~//~v97bR~
//        "  %cE[w]/form[L][/{{T|B}|{L|R}}[ss]];PaperSize[Landscape].\n",//~v98aR~
//        "  %cE[w]/form[L][/[M]{{T|B}|{L|R}}[ss[P]]];PaperSize[Landscape].\n",//~v98aI~//~v9e5R~
          "  %cE/form[L][/[M]{{T|B}|{L|R}}[ss[P]]];PaperSize[Landscape].\n",//~v9e5I~
						CMDFLAG_PREFIX),buff));                    //~v970I~//~v973R~//~v977R~
    hline("             ;? for form is used to list available paper size,\n");//~v983I~
    hline("             ;partial string may be OK if uniquely match(gxp version only).\n");//~v983I~
//  hline("             ;P:Landscape setting is on printer.(gxp do no rotation)\n");//v7.291r//~v97aI~//~v97bR~
#ifdef MMM                                                         //~v98hI~
    hline("             ;O:following shift parameter is to shift coordinate origin.\n");//v7.291r//~v98aI~
#else                                                              //~v98hI~
    hline("             ;M:following parameter is margin width.\n");//v7.291r//~v98hI~
#endif                                                             //~v98hI~
#ifdef MMM                                                         //~v98hI~
    hline("             ;Without \"O\",expand papersize to avoid printers warning of\n");//~v98aI~
#else                                                              //~v98hI~
    hline("             ;Without \"M\",expand papersize to avoid printers warning of\n");//~v98hI~
#endif                                                             //~v98hI~
    hline("             ;invalid papersize.\n");//v7.291r          //~v98aI~
#ifdef MMM                                                         //~v98hI~
    hline("             ;{T|B}|{L|R}:Shift direction(Top/Bottom/Left/Right).\n");//v7.291r//~v977I~//~v98aR~
#else                                                              //~v98hI~
    hline("             ;{T|B}|{L|R}:direction(Top/Bottom/Left/Right of portrait form).\n");//v7.291r//~v98hR~
#endif                                                             //~v98hI~
#ifdef MMM                                                         //~v98hI~
    hline("             ;ss[P]:shift amount mm or points with \"P\" parameter.\n");//v7.291r//~v98aR~
#else                                                              //~v98hI~
    hline("             ;ss[P]:shift/margin amount by mm or points with \"P\" parameter.\n");//v7.291r//~v98hI~
#endif                                                             //~v98hI~
//  hline("             ;Try shift parameter if paper folder position is not valid.\n");//v7.291r//~v98aR~
#ifdef MMM                                                         //~v98hI~
    hline("             ;Try shift parameter without \"O\"\n");//v7.291r//~v98aI~
#else                                                              //~v98hI~
    hline("             ;Try shift parameter without \"M\"\n");//v7.291r//~v98hI~
#endif                                                             //~v98hI~
    hline("             ;if paper folder position is not valid for other than papersize=A4.\n");//v7.291r//~v98aI~
    hline("             ;For ex,1st line printed is not top of B5,\n");//v7.291r//~v977I~
    hline((sprintf(buff,
          "             ;\"%cE/B5/T\" shifts 1st line position toward top of paper.\n",//~v977I~
						CMDFLAG_PREFIX),buff));                    //~v977I~
    hline("             ;without ss,it means to adjust edge on A4 paper.\n");//v7.291r//~v98hI~
//  hline((sprintf(buff,                                           //~v98hR~
//        "             ;(2-page/sheet is by %cY2)\n",             //~v98hR~
//  					CMDFLAG_PREFIX),buff));                    //~v98hR~
   #else                                                           //~v970I~
    hline((sprintf(buff,                                           //~v92bI~
          "  %cEx[/form] ;printer type.x=i(IBM),=e(ESC/P),=c(Canon),=w(Gnome).\n",//~v92bI~
							CMDFLAG_PREFIX),buff));//v7.291r       //~v92bI~
   #endif                                                          //~v970I~
  #else                                                            //~v92bI~
    hline((sprintf(buff,                                           //~v907I~
          "  %cEx[/form] ;printer type.x=i(IBM),=e(ESC/P),=c(Canon).\n",//~v907I~
							CMDFLAG_PREFIX),buff));//v7.291r       //~v907I~
  #endif                                                           //~v92bI~
#else                                                              //~v907I~
    hline((sprintf(buff,                                           //~v907I~
          "  %cEx[/form] ;printer type.x=i(IBM),=e(ESC/P),=c(Canon),=w(Windows).\n",//~v907R~
							CMDFLAG_PREFIX),buff));//v7.291r       //~v907R~
#endif                                                             //~v907I~
#ifdef GTKPRINT                                                    //~v970I~
    hline((sprintf(buff,                                           //~v970I~
//        "             ;ex) %cEw/A4 %c/B5 %cE/A4L %cE/LegalL/T10 %cE/b5jis/br\n",        //~v970I~//~v973R~//~v977R~//~v9e5R~
          "             ;ex) %cE/A4 %c/B5 %cE/A4L %cE/LegalL/T10 %cE/b5jis/br\n",//~v9e5I~
						CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX),buff));//~v970I~//~v973R~//~v97aR~
#ifdef MMM                                                         //~v98hI~
    hline((sprintf(buff,                                           //~v98aI~
          "             ;    %cE/A4/OL18P %cE//OL10B5\n",          //~v98aR~
						CMDFLAG_PREFIX,CMDFLAG_PREFIX),buff));     //~v98aR~
#else                                                              //~v98hI~
    hline((sprintf(buff,                                           //~v98hI~
          "             ;    %cE/A4/ML18P %cE//ML10B10L10R10 %cE/B5L/r10b10Mr10t10\n",//~v98hR~
						CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX),buff));//~v98hR~
#endif                                                             //~v98hI~
#else                                                              //~v970I~
    hline("             ;form=A4,B4,B5,A4L,B4L,B5L.(L:landscape)\n");//v7.291r//~v74lI~
    hline("             ;     A42,B42,B52,A4L2,B4L2,B5L2.(2:2page/sheet)\n");//v7.291r//~v91eR~
#endif                                                             //~v970I~
#ifndef GTKPRINT                                                   //~v974I~
    hline((sprintf(buff,                                           //~v907I~
          "  %cE@cmdf    ;printer command file.\n",                //~v907R~
							CMDFLAG_PREFIX),buff));//v7.291r       //~v907R~
#endif                                                             //~v974I~
    hline((sprintf(buff,                                           //~v907I~
          "  %cFFXxx     ;char replacing FormFeed(0x'0c'). xx is Hex digit.\n",//~v907R~
							CMDFLAG_PREFIX),buff));                //~v907R~
    hline((sprintf(buff,                                           //~v907I~
#ifdef GTKPRINT                                                    //~v970I~
          "  %cFhhh      ;hhh:font name.\n",                       //~v970I~
#else                                                              //~v970I~
          "  %cFhhh[/zzz];hhh:SBCS font style; zzz:DBCS font style.\n",//~v923R~
#endif                                                             //~v970I~
							CMDFLAG_PREFIX),buff));                //~v907R~
#ifdef GXP                                                         //~v92bI~
  #ifdef GTKPRINT                                                  //~v970I~
    hline("             ; ? for hhh is used to list font name(gxp version only).\n");//~v970I~
    hline("             ; ex)\"-F?abc\" lists font names containing string \"abc\".\n");//~v970R~
  #else                                                            //~v970I~
    hline("             ; ? for hhh is used to list font style(Gnome version only).\n");//~v92bI~
  #endif                                                           //~v970I~
#else                                                              //~v92bI~
    hline("             ; ? for hhh is used to list font style(Win version only).\n");//~v923R~
#endif                                                             //~v92bI~
#ifndef GTKPRINT                                                   //~v970I~
    hline("             ;      IBM    :0,GOT,ELI,COU,MIN,OCB,ORE.\n");//v7.24av7.28r//~v844I~
    hline("             ;      ESC/P  :0,ROM,SAN,COU,PRE,SCR,OCB,OCA,GOT,MIN.\n");//v7.24av7.28r//~v907R~
    hline("             ;      Canon  :LIN,COU,SWI,DUT,MIN,GOT.\n");//~v844R~
#endif
#ifdef GXP                                                         //~v92bI~
    hline((sprintf(buff,
  #ifdef GTKPRINT                                                  //~v970I~
          "             ;ex) %cFSans %cF\"Monospace;Italic Bold\".\n",//~v970R~
							CMDFLAG_PREFIX,CMDFLAG_PREFIX),buff)); //~v970I~
  #else                                                            //~v970I~
          "             ;      Gnome  :\"font-name\". ex) %cf\"Monospace Regular\".\n",//~v92eR~//~v953R~
							CMDFLAG_PREFIX),buff));
  #endif                                                           //~v970M~
#else                                                              //~v92bI~
    hline("             ;      Windows:SYS,COU,ROM,MIN,GOT,\"font-name\".\n");//~v844R~
#endif                                                             //~v92bI~
    hline((sprintf(buff,                                           //~v96eI~
          "  %cICU       ;Use ICU for EBCDIC translation\n",       //~v96eR~
							CMDFLAG_PREFIX),buff));                //~v96eI~
    hline((sprintf(buff,                                           //~v907I~
          "  %cI[n]-[m][/pp] ;Input range by file line-No. pp:restart pageno.\n",//~v910R~
							CMDFLAG_PREFIX),buff));                //~v907R~
    hline((sprintf(buff,                                           //~v910M~
          "  %cIx[s]-[e][/pp];Input range by file offset.\n",      //~v910I~
							CMDFLAG_PREFIX),buff));                //~v910M~
#ifndef UNX                                                        //~v907R~
    hline((sprintf(buff,                                           //~v907I~
          "  %cJjobname  ;(Win,OS/2 version only) Jobname to be set on output queue.\n",//~v907R~
							CMDFLAG_PREFIX),buff));                //~v907R~
//  hline("             ;default is set from inut filename.\n");   //~v92tR~
    hline("             ;default is set from input filename.\n");  //~v92tI~
#endif                                                             //~v910M~
    hline((sprintf(buff,                                           //~v907I~
          "  %cKx        ;code conv for graphic char of Japanese DOS(0x01,..).\n",//~v907R~
							CMDFLAG_PREFIX),buff));                //~v907R~
    hline("             ;x=0:no conversion\n");                    //~v90sR~
    hline("             ;x=g:to ASCII double line char(0xb5,0xb6,...)\n");//~v90sR~
    hline("             ;x=k:to graphic char of KATAKANA set(0x8f,..).(depend on cpi)\n");//~v90sR~
//  hline("             ;x=L:to ASCII sigle line char(0xb3,0xb4,...)\n");//~v92tR~
    hline("             ;x=L:to ASCII narrow line char(0xb3,0xb4,...)\n");//~v92tI~
    hline("             ;x=(any 1 byte char other than 'f')\n");   //~v895R~
#ifdef UNX                                                         //~v907I~
    hline((sprintf(buff,                                           //~v907I~
          "             ;default:%cEi is %cK0;else %cK0 for %cMx,%cMta,else %cK/.\n",//~v907I~
          					CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX,//~v907R~
          					CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX),buff));//~v907I~
#else                                                              //~v907I~
    hline((sprintf(buff,                                           //~v907I~
          "             ;default:%cEi and %cEw is %cK0;else %cK0 for %cMx,%cMta,else %cK/.\n",//~v907R~
          					CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX,//~v907I~
          					CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX),buff));//~v907I~
#endif                                                             //~v907I~
    hline((sprintf(buff,                                           //~v907I~
          "  %cKFfilenm  ;256 byte code translation table filename.\n",//~v907R~
							CMDFLAG_PREFIX),buff));                //~v907R~
    hline((sprintf(buff,
//        "  %cLn[x][/p] ;max line per page,default=%d,x=d(double space),x=t(tripple space)\n",//~v92tR~
          "  %cLn[x][/p] ;max line per page,default=%d,x=d(double space),x=t(triple space)\n",//~v92tI~
          					CMDFLAG_PREFIX,                        //~v907I~
                            MAXLINE),buff));                    //~v74lR~
    hline((sprintf(buff,                                        //~v752I~
          "             ;p(lpi)= 2, 3, 4, 5, 6, 75 or 8.(default=%d)\n",//~v752R~
                            DEFAULTLPI),buff));                 //~v752R~
#ifndef UNX                                                        //~v907I~
    hline((sprintf(buff,                                           //~v907I~
//        "             ;(for %cEw,any lpi value is valid.grater than 15 is unit of 1/10.\n",//~v92tR~
        "             ;(for %cEw,any lpi value is valid. grater than 15 is unit of 1/10.\n",//~v92tI~
							CMDFLAG_PREFIX),buff));                //~v907R~
    hline("             ;And lpi is calc from maxline when no lpi,font specified).\n");//~v876I~
#endif                                                             //~v907I~
    hline((sprintf(buff,                                           //~v907I~
//        "  %cMm[c][e][n];print mode.m=t:Text,d:Dump,x:Hex dump.(%cMtd)\n",//~v907R~//~v96eR~
//  					CMDFLAG_PREFIX,CMDFLAG_PREFIX),buff));     //~v907R~//~v96eR~
          "  %cMm[c][e][n];print mode. m=t:Text(Default),\n",      //~v96eR~
    					CMDFLAG_PREFIX),buff));                    //~v96eI~
    hline("             ;  d:Dump(replace unprintable by \".\"),\n");//~v96eI~
    hline("             ;  x:Hex dump,\n");                        //~v96eI~
//        "             ;%cMtx means textmode 2 line vertical hex dump.\n",//~v950R~//~v96eR~
    hline("             ;  tx:textmode 2 line vertical hex dump.\n");//~v96eR~
//    hline((sprintf(buff,                                           //~v92bI~//~v96eR~
//          "             ;%cMx means vertical hex dump if %cR or %cV is specified.\n",//~v950R~//~v96eR~
//                            CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX),buff)); //~v92bI~//~v96eR~
#ifdef UTF8SUPP                                                    //~v92bI~
//  hline("             ;c:CharSet.c=d:Jpanese DOS,s:SBCS,a:ASCII,j:JIS,e:EBCDIC,u:UTF-8.\n");//~v92tR~
    hline("             ;c:CharSet.c=d:Japanese DOS,s:SBCS,a:ASCII,j:JIS,e:EBCDIC,u:UTF-8.\n");//~v92tI~
#else                                                              //~v92bI~
//  hline("             ;c:char set.c=d:jpanese DOS,s:SBCS,a:ASCII,j:JIS,e:EBCDIC.\n");//~v92tR~
    hline("             ;c:char set.c=d:Jpanese DOS,s:SBCS,a:ASCII,j:JIS,e:EBCDIC.\n");//~v92tI~
#endif                                                             //~v92bI~
#ifdef WCSUPP                                                      //~v941I~
//  hline("             ;   default is by the environment locale code\n");//~v941R~//~v959R~
    hline((sprintf(buff,                                           //~v941I~
//        "             ;     = %s\n",                             //~v941I~//~v959R~
          "             ;   default is by the env(=%s).\n",        //~v959R~
						Gdefaultlocalecode),buff));                //~v941I~
#else                                                              //~v941I~
    hline((sprintf(buff,                                           //~v907I~
          "             ;  (default is j when %cMx else d.)\n",    //~v907R~
						CMDFLAG_PREFIX),buff));                    //~v907R~
#endif                                                             //~v941I~
#ifdef UTF8EBCD //EBCDIC dbcs support                              //~v941I~
    hline("             ;e:EBCDIC translation type\n");            //~v941I~
//  hline("             ;  c:using cfg file(Default, specify filename by BC option.)\n");//~v941I~//~v953R~
    hline("             ;  c:using cfg file(Default).\n");         //~v953R~
    hline((sprintf(buff,                                           //~v953I~
          "             ;    %cBC or %c%s option is required\n",   //~v953R~
						CMDFLAG_PREFIX,CMDFLAG_PREFIX,PARM_CPEB),buff));//~v953I~
//  hline("             ;    ex) xprint ebcfile /Me /bcEbcmap.cfg\n");//~v941R~//~v96eR~
    hline((sprintf(buff,                                           //~v96eI~
          "             ;    ex) xprint ebcfile %cMte %cbcD:\\Ebcmap.cfg\n",//~v96eR~//~v96hR~//~v96eR~
						CMDFLAG_PREFIX,CMDFLAG_PREFIX),buff));     //~v96eI~
    hline((sprintf(buff,                                           //~v96eI~
          "             ;  i:same as %cICU. %c%s is required.\n",  //~v96eR~
						CMDFLAG_PREFIX,CMDFLAG_PREFIX,PARM_CPEB),buff));//~v96eI~
    hline((sprintf(buff,                                           //~v96hI~
          "             ;    ex) xprint ebcfile %cMei %c%s=cp930\n",//~v96hR~//~v96eR~
						CMDFLAG_PREFIX,CMDFLAG_PREFIX,PARM_CPEB),buff));//~v96hI~
    hline("             ;  k:Japanese Katakana-Ext(No DBCS)\n");   //~v941I~
    hline("             ;  e:Japanese English-Ext(No DBCS)\n");    //~v941I~
#else                                                              //~v941I~
    hline("             ;e:EBCDIC subtype(k:katakana(default),e:alphabet small letter).\n");//~v891I~
#endif                                                             //~v941I~
    hline("             ;n:skim mode length.\n");                  //~v789I~
    hline("             ;  print skimming printable string which length>n.\n");//~v96eR~
    hline((sprintf(buff,                                           //~v953I~//~v96eM~
          "             ; ex) xprint ebcf %cmtxe %cR80\n",          //~v953I~//~v96eM~
							CMDFLAG_PREFIX,CMDFLAG_PREFIX),buff)); //~v953R~//~v96eM~
    hline((sprintf(buff,                                           //~v950I~//~v953M~//~v96eM~
//        "             ;     xprint utf8file %cMtxu \n",          //~v950R~//~v953R~//~v960R~//~v96eM~
//  					CMDFLAG_PREFIX),buff));                    //~v950I~//~v953M~//~v960R~//~v96eM~
          "             ;     xprint utf8file %cMu %cN8\n",      //~v960I~//~v96eR~
    					CMDFLAG_PREFIX,CMDFLAG_PREFIX),buff));     //~v960R~//~v96eM~
//  hline("  /O[[-]x]   ;file output order(x=e:Extension,n:Name,d:Date,l:List).(/On)\n");//~v902R~
    hline((sprintf(buff,                                           //~v907I~
          "  %cO[[-]x]   ;file output order.\n",                   //~v924R~
						CMDFLAG_PREFIX),buff));                    //~v924R~
    hline("             ;x=b:Basename,e:Extension,n:Name,d:Date,l:parm List sequence.\n");//~v902R~
    hline((sprintf(buff,                                           //~v924I~
//          "             ;  (default is %cOb if input has dir/wildcard,else %cOl.)\n",//~v924I~//~v97fR~
//                        CMDFLAG_PREFIX,CMDFLAG_PREFIX),buff));     //~v924I~//~v97fR~
          "             ;(default is %cOb for dir/wildcard,else %cOl, %cO means %cOE.)\n",//~v97fR~
                        CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX),buff));//~v97fI~
    hline((sprintf(buff,                                           //~v907I~
//        "  %cPnn[-nn]  ;print page range,concatinate multiple by \"+\".\n",//~v92tR~
          "  %cPnn[-nn]  ;print page range,concatenate multiple by \"+\".\n",//~v92tI~
						CMDFLAG_PREFIX),buff));                    //~v907R~
    hline((sprintf(buff,                                           //~v907I~
          "  %cP[n]/[f]  ;print re-start file and its restart page.\n",//~v907R~
						CMDFLAG_PREFIX),buff));                    //~v907R~
    hline((sprintf(buff,                                           //~v907I~
//        "  %cQofile    ;destination(alternative of 2nd positional parm)\n",//~v921R~
#ifdef GTKPRINT	                                                   //~v973I~
          "  %cQprinter  ;destination; (default printer).\n",      //~v973I~
#else                                                              //~v973I~
          "  %cQofile    ;destination; prn(default),LPTx,file-name etc.\n",//~v923R~
#endif                                                             //~v973I~
						CMDFLAG_PREFIX),buff));                    //~v907R~
#ifdef GXP                                                         //~v944I~
    hline((sprintf(buff,                                           //~v944I~
#ifdef GTKPRINT                                                    //~v973I~
          "             ;Use \"-Q?\" or \"lpstat -p -d\" to list-up printer.\n"),buff));//~v973I~//~v979R~
#else                                                              //~v973I~
          "             ;reply to popup when non-default CUPS-Printer is specified.\n"),buff));//~v944I~
#endif                                                             //~v973I~
    hline((sprintf(buff,                                           //~v950M~
          "             ;  ex) %cqlp1400. (substring is OK for CUPS-printer if unique.)\n",//~v950M~
						CMDFLAG_PREFIX),buff));                    //~v950M~
#else                                                              //~v944I~
    hline((sprintf(buff,                                           //~v921I~
          "             ;QUEUE name or Printer name is valid for OS/2 version.\n"),buff));//~v921I~
#endif                                                             //~v944I~
    hline((sprintf(buff,                                           //~v90mI~
          "             ;use \"%cq-\" or \"%cq--\"(also process msg) for stdout.\n",//~v90mR~
						CMDFLAG_PREFIX,CMDFLAG_PREFIX),buff));     //~v90mI~
    hline((sprintf(buff,                                           //~v907I~
          "  %cR[recsz]  ;Record mode and record size\n",          //~v907R~
						CMDFLAG_PREFIX),buff));                    //~v907R~
    hline((sprintf(buff,                                           //~v96eI~
          "             ; ex) xprint frecf %cMd %cR120\n",         //~v96eR~
							CMDFLAG_PREFIX,CMDFLAG_PREFIX),buff)); //~v96eI~
#ifdef GXP                                                         //~v92hI~
    hline((sprintf(buff,                                           //~v92hI~
          "  %cRGB=rrggbb;RGB for text foreground color(rr/gg/bb:00->ff, defaut:%06X)\n",//~v92hR~
						CMDFLAG_PREFIX,(DEFAULT_PRINTCOLOR>>8)),buff));//~v92hR~
#endif                                                             //~v92hI~
    hline((sprintf(buff,
//        "  %cTnn       ;tab skip colomn.(%cT%d)\n",              //~v92tR~
          "  %cTnn       ;tab skip column.(%cT%d)\n",              //~v92tI~
          				CMDFLAG_PREFIX,CMDFLAG_PREFIX,             //~v907R~
                                tabskip),buff));
    hline((sprintf(buff,                                           //~v9e0I~
          "  %cTabon:x:y:z ;Text mode alternative char for DBCS space,Tab(0x09),Tab-skip.\n",//~v9e0R~
          					CMDFLAG_PREFIX),                       //~v9e0I~
                                buff));                            //~v9e0I~
    hline((sprintf(buff,                                           //~v9e0I~
          "               ;For x,y,z each, specify Char itself, Unicode or Hex notation.\n"),//~v9e0I~
                                buff));                            //~v9e0I~
    hline((sprintf(buff,                                           //~v9e0I~
          "               ;e.g.) %cTabon:x2020:x18:x1a  %cTabon::u2191:u2192 %cTabon::u25cb\n",//~v9e0I~
          					CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX),//~v9e0I~
                                buff));                            //~v9e0I~
    hline((sprintf(buff,                                           //~v9e0I~
          "               ;      %cTabon:u2750\n",                 //~v9e0R~
          					CMDFLAG_PREFIX),                       //~v9e0I~
                                buff));                            //~v9e0I~
    hline((sprintf(buff,                                           //~v9e0I~
          "               ;Default is %cTabon:u3000:x20:x20(UTF8/EBCDIC file)\n",//~v9e0R~
          					CMDFLAG_PREFIX),                       //~v9e0I~
                                buff));                            //~v9e0I~
    hline((sprintf(buff,                                           //~v9e0I~
          "               ;       and %cTabon:x8140:x20:x20(other file).\n",//~v9e0R~
          					CMDFLAG_PREFIX),                       //~v9e0I~
                                buff));                            //~v9e0I~
    hline((sprintf(buff,                                           //~v96eI~
          "  %cVvfmt     ;Variable Length Record File format.\n",  //~v96eR~
          					CMDFLAG_PREFIX),buff));                //~v96eR~
    hline((sprintf(buff,                                           //~v96eI~
          "             ;vfmt:%s,%s(MicroFocus),%s(Halfword),%s(DataLength),%s(Fullword),%s\n",//~v96eR~
                                VFMT_DEFAULT,VFMT_MFH,VFMT_HW,VFMT_HWDATA,VFMT_FW,VFMT_FWDATA),buff));//~v96eR~
    hline((sprintf(buff,                                           //~v96eI~
          "             ;  ex) xprint vrlfile %cvh %cMd %c%s:\n",  //~v96eR~
						CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX,PARM_EOLPRINT),buff));//~v96eI~
    hline((sprintf(buff,                                           //~v907I~
          "  %cWdir      ;work dir-name for page descending order print(%s)\n",//~v907R~
						CMDFLAG_PREFIX,WKFDIR),buff));             //~v907R~
    hline((sprintf(buff,                                           //~v90jI~
          "  %cWN=n      ;Indentation column for continued line.(%cWN=0)\n",//~v90jR~
							CMDFLAG_PREFIX,CMDFLAG_PREFIX),buff)); //~v90jI~
//#ifdef W32                                                       //~v92dR~
#if defined(W32)||defined(GXP)                                     //~v92dI~
    hline((sprintf(buff,                                           //~v90vI~
//        "  %cZHnn      ;(Win/Gnome version only)Page hight zoom rate, nn %%%%.(default=100).\n",//~v92tR~
          "  %cZHnn      ;(Win/Gnome version only)Page height zoom rate, nn %%%%.(default=100)\n",//~v92tI~//~v96eR~
							CMDFLAG_PREFIX),buff));                //~v90vI~
    hline("              (nn=L means nn=94 for Letter size).\n");  //~v92gI~
    hline((sprintf(buff,                                           //~v90vI~
          "  %cZWnn      ;(Win/Gnome version only)Page width zoom rate, nn %%%%.(default=100).\n",//~v92dR~
							CMDFLAG_PREFIX),buff));                //~v90vI~
//  hline("              (nn=L means nn=94 for Letter size).\n");  //~v92gR~
#endif                                                             //~v90vI~
    hline((sprintf(buff,                                           //~v907I~
          "  %cYx,%cNx    ;option Y(set) or N(reset),last is effective if duplicated\n",//~v907R~
						CMDFLAG_PREFIX,CMDFLAG_PREFIX),buff));     //~v907R~
#ifndef UNX                                                        //~v923I~
    hline((sprintf(buff,                                           //~v907I~
          "      a      ;Select archived attribute file only(%cNa)\n",//~v907R~
						CMDFLAG_PREFIX),buff));                    //~v907R~
#endif                                                             //~v923I~
    hline((sprintf(buff,                                           //~v907I~
          "      b      ;Background process(%cNb)\n",              //~v907R~
						CMDFLAG_PREFIX),buff));                    //~v907R~
    hline((sprintf(buff,                                           //~v907I~
          "      c      ;confirm print for each file when dir/wildcard input filespec(%cYc)\n",//~v923R~
						CMDFLAG_PREFIX),buff));                    //~v907R~
#ifdef OS2                                                         //~v916I~
    hline((sprintf(buff,                                           //~v907I~
          "(OS/2)d      ;set document name to output print job(%cYd).\n",//~v907R~
						CMDFLAG_PREFIX),buff));                    //~v907R~
#endif                                                             //~v916I~
#ifdef GTKPRINT                                                    //~v970I~
    hline((sprintf(buff,                                           //~v970I~
          "(gxp )d      ;popup Dialog for Printer/Paper selection(%cNd).\n",//~v970I~
						CMDFLAG_PREFIX),buff));                    //~v970I~
#endif                                                             //~v970I~
#ifdef W32                                                         //~v916I~
    hline((sprintf(buff,                                           //~v916I~
          "(Win )d      ;request to set form info to driver(%cYd).\n",//~v916R~
						CMDFLAG_PREFIX),buff));                    //~v916I~
#endif                                                             //~v916I~
//#ifdef UNX                                                       //~v90mR~
//    hline((sprintf(buff,                                         //~v90mR~
//          "      e      ;Write Esc cmd for char/line pitch(%cNe)\n",//~v90mR~
//                        CMDFLAG_PREFIX),buff));//v3.3addv3.8r    //~v90mR~
//#else                                                            //~v90mR~
    hline((sprintf(buff,                                           //~v907I~
          "      e      ;Write Esc cmd for char/line pitch(%cYe)\n",//~v907R~
						CMDFLAG_PREFIX),buff));//v3.3addv3.8r      //~v907R~
//#endif                                                           //~v90mR~
#ifndef GTKPRINT                                                   //~v97jI~
    hline((sprintf(buff,                                           //~v907I~
          "      f      ;Fast path mode.(%cNf)\n",                 //~v90aR~
						CMDFLAG_PREFIX),buff));//v7.26a            //~v907R~
#endif                                                             //~v97jI~
    hline((sprintf(buff,                                           //~v907I~
//        "      g      ;Write colomn Gauge line(2nd header line).(default=%cYg)\n",//~v92tR~
          "      g      ;Write column Gauge line(2nd header line).(default=%cYg)\n",//~v92tI~
						CMDFLAG_PREFIX),buff));                    //~v907R~
    hline((sprintf(buff,                                           //~v907I~
          "      h      ;Write Header(1st line).(default=%cYh)\n", //~v907R~
						CMDFLAG_PREFIX),buff));                    //~v907R~
    hline((sprintf(buff,                                           //~v907I~
          "      i      ;in-file is of 'I'ndirect file name specification file(%cNi)\n",//~v907R~
						CMDFLAG_PREFIX),buff));                    //~v907R~
#ifndef GTKPRINT                                                   //~v97kI~
    hline((sprintf(buff,                                           //~v907I~
          "      j      ;output to multiple print-job(%cYj for PR/LPTn,else %cNj).\n",//~v907R~
						CMDFLAG_PREFIX,CMDFLAG_PREFIX),buff));     //~v907R~
#endif                                                             //~v97kI~
    hline((sprintf(buff,                                           //~v907I~
          "      l      ;CR and LF by 0x0d0a when Dump mode(%cYl)\n",//~v907R~
						CMDFLAG_PREFIX),buff));                    //~v907R~
#ifndef UNX                                                        //~v923I~
    hline((sprintf(buff,                                           //~v907I~
          "      m      ;Clear archived attribute after print process(%cNm)\n",//~v907R~
						CMDFLAG_PREFIX),buff));                    //~v907R~
#endif                                                             //~v923I~
    hline((sprintf(buff,                                           //~v907I~
          "      n      ;Set Line Prefix(Line-No/Offset).(%cYn)\n",//~v907R~
						CMDFLAG_PREFIX),buff));                    //~v907R~
//    hline((sprintf(buff,                                         //~v924R~
//          "      o      ;file output Ordering,use to reorder multiple files(not dir).\n"),buff));//~v924R~
//    hline((sprintf(buff,                                         //~v924R~
//          "             ;(%cYo for no %cOl and dir input,else %cNo)\n",//~v924R~
//                        CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX),buff));//~v924R~
    hline((sprintf(buff,                                           //~v907I~
          "      p      ;page descending order print(%cNp)\n",     //~v907R~
						CMDFLAG_PREFIX),buff));                    //~v907R~
    hline((sprintf(buff,                                           //~v907I~
          "(Win) r      ;restore font on each page.(%cYr)\n",      //~v90nR~
						CMDFLAG_PREFIX),buff));                    //~v907R~
    hline("              slow but required for old Windows version.\n");//~v90aR~
    hline((sprintf(buff,                                           //~v907I~
          "      s      ;For hex dump, process \"same as above\"(%cYs)\n",//~v90aR~
						CMDFLAG_PREFIX),buff));                    //~v907R~
    hline((sprintf(buff,                                           //~v9j0I~
          "      t      ;Trace(Internal Use, %cNt)\n",             //~v9j0R~
						CMDFLAG_PREFIX),buff));                    //~v9j0I~
    hline((sprintf(buff,                                           //~v91xI~
          "      u      ;insert formfeed cmd(0x0c) between each page(%cYu)\n",//~v91xI~
						CMDFLAG_PREFIX),buff));                    //~v91xI~
    hline((sprintf(buff,                                           //~v907I~
          "      v      ;No page eject at end of file(%cNv)\n",    //~v907R~
						CMDFLAG_PREFIX),buff));                    //~v907R~
    hline((sprintf(buff,                                           //~v907I~
          "      0      ;assume input-file-name stdin as standard input(%cY0)\n",//~v907R~
						CMDFLAG_PREFIX),buff));                    //~v907R~
#ifdef UNX                                                         //~v907I~
    hline((sprintf(buff,                                           //~v907I~
          "      1      ;FormFeed before 1st page(%cN1)\n",        //~v907I~
						CMDFLAG_PREFIX),buff));                    //~v907R~
#else                                                              //~v907I~
    hline((sprintf(buff,                                           //~v907I~
          "      1      ;FormFeed before 1st page(%cN1 for %cEc,else %cY1)\n",//~v907R~
						CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX),buff));//~v907R~
#endif                                                             //~v907I~
    hline((sprintf(buff,                                           //~v907I~
          "      2      ;Double page print(2-page/1-sheet)(%cN2)\n",//~v91zR~
						CMDFLAG_PREFIX),buff));                    //~v907R~
#if defined(LNX) && !defined(GXP)                                  //~v92nI~
    hline((sprintf(buff,                                           //~v92nI~
          "      3      ;accept Japanese EUC SS3(0x8f) or print '?'.(%cN3)\n",//~v92nI~
						CMDFLAG_PREFIX),buff));                    //~v92nI~
#endif                                                             //~v92nI~
    hline((sprintf(buff,                                           //~v907I~
          "      6      ;16 byte width hex dump(%cN6)\n",          //~v907R~
						CMDFLAG_PREFIX),buff));                    //~v907R~
    hline((sprintf(buff,                                           //~v960I~
          "      8      ;vertical HEX dump is by UTF-8 for UTF-8 file,\n"//~v960R~
							),buff));                              //~v960R~
    hline((sprintf(buff,                                           //~v960I~
          "             ;by UCS when %cN8.(%cY8)\n",               //~v960I~
							CMDFLAG_PREFIX,CMDFLAG_PREFIX),buff)); //~v960R~
    hline((sprintf(buff,                                           //~v907I~
          "      9      ;force SBCS(%cN9) or DBCS(%cY9) environment(no default)\n",//~v907R~
						CMDFLAG_PREFIX,CMDFLAG_PREFIX),buff));     //~v907R~
    hline((sprintf(buff,                                           //~v826I~
          "--------------(%c)--------------------------------------------------------------\n",//~v826R~
                                os),buff));                        //~v826I~
    hline((sprintf(buff,                                           //~v907I~
          "  %cH,%c?      ;help message.\n",                       //~v907R~
						CMDFLAG_PREFIX,CMDFLAG_PREFIX),buff));     //~v907R~
//  hline("  %cG         ;general description.\n");                //~v907R~
//  hline("  /V         ;Version maintenance history.\n");      //~5810R~
  }//
}//helpabridge
//**********************************************************************
//* wait reply to continue v6.5a
//**********************************************************************
void hline(char *Phline)                                           //~v91kR~
{
#ifdef UNX                                                         //~v907M~
//******************:                                              //~v907I~
    uerrhelpmsg(stdout,stderr,Phline,Phline);	//may EUC conversion//~v91kR~
#else                                                              //~v907M~
    int ch;                                                        //~v91sI~
static int hlineno=0;
static int hlinemax;                   //screen maxline size v6.9a v7.0m
int    sline(void);                     //get screen size   v6.9a v7.0m
  	int dbcsmode;                                                  //~v98pI~
//******************:
#ifdef LNX                                                         //~v98pI~
  if (UCBITCHK(Guerropt,GBL_UERR_FORCEENG))                        //~v98pI~
	dbcsmode=0;                                                    //~v98pI~
  else                                                             //~v98pI~
    dbcsmode=UCBITCHK(Guerropt,GBL_UERR_DBCSMODE)!=0;              //~v98pI~
#else                                                              //~v98pI~
	dbcsmode=dbcsenv;					//same as xprint.c setting //~v98pI~
#endif                                                             //~v98pI~
//  if (dbcsenv)    //DBCS mode v6.9d
//      hlinemax=22;            v6.9d
//  else                        v6.9d
//      hlinemax=23;            v6.9d
    if (!hlineno)               //first time v7.0a
        hlinemax=sline();               //get screen size   v6.9a v7.0m

    if (hlineno++>=hlinemax   //v6.9r                           //~v74bR~
    &&  !UCBITCHK(swsw1,SW1NOKBD|SW1BACKG))                     //~v74bI~
    {
//      if (dbcsenv)    //DBCS mode                                //~v98pR~
        if (dbcsmode)   //DBCS mode                                //~v98pI~
            fprintf(stderr,"--����-- �L�[���ǂꂩ�����ĉ������D�D�D");//~v844R~
        else    
            fprintf(stderr,"continue--   Press Any Key(\"q\" to exit)"); //v7.0r//~v941R~
        fflush(stderr);         //v7.0a
        ch=                                                        //~v91sI~
        kbdinp(_KEYBRD_READ);
        if (ch=='q'||ch=='Q')                                      //~v91sM~
            exit(0);                                               //~v91sM~
        hlineno=1;
        printf("\n%s",Phline);                                     //~v91kR~
    }
    else
        printf(Phline);                                            //~v91kR~
#endif  //!UNX                                                     //~v907R~
}//hline
#ifdef UNX                                                         //~v907I~
#else                                                              //~v907I~
//**********************************************************************
//* retrieve screen line size
//**********************************************************************
int sline(void)
{
#ifdef DOS              //v7.0a
    union REGS   reg;
    int slineno=24;     //v7.1a dos,if int 10 failed
#else                   //v7.1a
    int slineno=25;     //v7.0r
#endif                  //v7.0a
//***************
#ifdef DOS  
    reg.x.ax=0x1130;
    reg.h.bh=0x01;
    reg.h.dl=0;         //clear for err case v7.1a
    int86(0x10,&reg,&reg);  

    if (reg.h.dl)           //get ok v7.1a
        slineno=reg.h.dl;   //line -1 //v7.0r contain dbcs env effect
    else                //v7.1a
        if (dbcsenv)    //DBCS mode //v7.1a
          slineno--;                //v7.1a
#else                           //v7.0a
#ifdef W32                                                         //~v929R~
    slineno=uerrscrheight();	//get screen size(-1 for query msg)//~v929R~
#endif                                                             //~v929R~
    if (dbcsenv)    //DBCS mode //v7.0a
      slineno--;                //v7.0a
#ifdef W32                                                         //~v857I~
    else                                                           //~v857I~
      slineno--;                //v7.0a                            //~v857I~
#endif                                                             //~v857I~
    
#endif
    return slineno;             //v7.0r
}//sline
#endif  //!UNX                                                     //~v907R~
//**********************************************************************//~5A10I~
//* write help msg                                              //~5A10I~
//**********************************************************************//~5A10I~
void titlemsg(int Pdbcsenv,char *Ppgmid,char *Pver)             //~5A10R~
{                                                               //~5A10I~
//#ifdef DOS                                                       //~v920R~
//  #ifdef DPMI                   //DPMI version                   //~v920R~
//    int os='G';                                                  //~v920R~
//  #else                       //not DPMI                         //~v920R~
//    int os='D';                                                  //~v920R~
//  #endif                      //DPMI or not                      //~v920R~
//#else                                                            //~v920R~
//    #ifdef W32                                                   //~v920R~
//        int os='W';                                              //~v920R~
//    #else                                                        //~v920R~
//        int os='2';                                              //~v920R~
//    #endif                                                       //~v920R~
//#endif                                                           //~v920R~
    int os=OSTYPE;                                                 //~v920I~
//*********                                                        //~v826I~
//    if (Pdbcsenv)   //DBCS mode v4.9a                            //~v91yR~
//        printf("%s:%s:(%s) =(%c)================================= by �É�܈� ===",//~v91yR~
//                Ppgmid,Pver,__DATE__,os);                        //~v91yR~
//    else                                                         //~v91yR~
//        printf("%s:%s:(%s) =(%c)================================== by KOGA-51 ===",//~v91yR~
//                Ppgmid,Pver,__DATE__,os);                        //~v91yR~
//                                                                 //~v91yR~
//#ifdef UNX                                                       //~v91yR~
//    printf("\n");                                                //~v91yR~
//#else                                                            //~v91yR~
//#endif                                                           //~v91yR~
                                                                   //~v944I~
//	uerrmsg("%s:%s:(%s) =(%c)================================= by KOGA-51 ===",//~v92nR~//~v950R~
//	        "%s:%s:(%s) =(%c)================================ by �É�܈� ===",//~v92nR~//~v950R~
//              Ppgmid,Pver,__DATE__,os);                          //~v91yI~//~v950R~
  	uerrmsg("%s:%s:(%s) =(%c%s)=============================== by KOGA-51 ===",//~v950R~
  	        "%s:%s:(%s) =(%c%s)============================== by �É�܈� ===",//~v950R~
                Ppgmid,Pver,__DATE__,os,                           //~v950R~
#ifdef ULIB64                                                      //~v950R~
	#if OSTYPE=='z'                                                //~v950R~
			""                                                     //~v950R~
    #else                                                          //~v950R~
			"64"                                                   //~v950R~
    #endif                                                         //~v950R~
#else                                                              //~v950R~
			""                                                     //~v950R~
#endif                                                             //~v950R~
                );                                                 //~v950R~
    return;                                                     //~5A10I~
}//titlemsg                                                     //~5A10I~
