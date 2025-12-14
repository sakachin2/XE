//*CID://+v7fzR~:                             update#=  376;       //~v7fzR~
//*********************************************************************//~v440I~
//* wxe interface definition                                       //~v440I~
//*********************************************************************//~v440I~
//v7fz:251205 (gxe) hcopy eol option for also gxe                  //~v7fzI~
//vbDs:250730 (gxe)vbDp for gxe(split combining,vhex csr data color)//~vbDsR~
//vbDf:250705 (gxe)crash after Ctrl+H(scrprint)/Ctrl+P(fileprint) at exit gxe(print process on going and c.b such as pcw may freed)//~vbDfI~
//vbAp:240701 (gxe)  hardcopy support                              //~vbApI~
//vbAj:240619 (gxe)if LIG:ON and COMB:ON, allow expand line by large glyph when no split by cursor//~vbAjI~
//vbz5:240120 try vbz3 to XXE(apichk by char extent)               //~vbz5I~
//vbm5:180715 (gxe:Bug)lineno fld and top unprintable(":;") is same color so ligature not applied. So,cut strput by linenosize>//~vbm5I~
//vbj2:180424 popup menu on cmd history list                       //~vbj2I~
//vbdn:171125 disable filemenu depending curent pcw type           //~vbdnI~
//vbd8:171120 (WXE)stdregion by PFK(F6) should disable PAste REP/INS//~vbd8I~
//vbd2:171114 (Wxe)Add SelectAll menuitem                          //~vbd2I~
//vb4r:160811 (XXE) v4f for XXE((ULIB:v6Ei)specify ligature on/off,combine on/of line by line(used for edit/filename  panel))//~vb4rI~
//varc:140215 add resizehint option  --gh={Y|n}                    //~varcI~
//vaf5:120604 (WXE/XXE) msgbox for uerrexit by inifile version unmatch//~vaf5I~
//va8a:100926 (WXE)end wxp work at end print                       //~va8aI~
//va87:100924 (WXE)wxp cmd;**/*** vhex print corespondency of upper and lower line//~va87I~
//va7D:100830 (XXE:BUG)cap menu update err(it should not be based on Mcellcopy1 bur Gcsrposy)//~va7DI~
//va7A:100829 (WXE:EBC)handle support for mouse cap                //~va7AI~
//va6q:000623 avoid ligature for not data line(gauge, xline etc)   //~va6qI~
//va5y:100518 (WXE)Windows Clipboard translate text. It cause invalid sjis to u-30fb when CF_UNICODETEXT mode//~va5yI~
//            on the otherhand getclipboarddata with CF_TEXT option returns "?" for u2l trans err coed.//~va5yI~
//            so for EBCDIC code, SetClipboard by CF_UNICODETEXT after trans to ucs2 by bynary mode(1 byte to 1 ucs2)//~va5yI~
//va3D:100310 (WXE)Unicode direct input support(A+"+" and Uxxxx)   //~va3DI~
//va3t:100221 (WXEXXE)break also at prev char of vhex data csr pos for backspace at vhex line//~va3tI~
//va3d:100206 (LNX)toggle ligature temprary by A+";", change combine key A+"/"-->C+":"//~va3dI~
//va3b:100205 (GXE)no ligature for hex edit(HEX mode and EH cmd)   //~va3bI~
//va33:100131 (BUG)additional to va31,LeftAlt+AltGr+9(expected "Alt+]") not effective//~va33I~
//            because other function selected by scancode base     //~va33I~
//va20:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~va20I~
//va1M:091121 (LNX)ligature support;keep monospace for english lagature; Arabian ? I don't know.//~va1MI~
//va1c:091030_merge GB18030 support                                //~va1cI~
//va0U:091003!(BUG:XXE)dbcstbl should be localdbcstbl for UTF8env  //~va0UI~
//v79D:081011 (XXE) draw ime cursor                                //~v79DI~
//v79z:080916 DBCS tbl for C and K of CJK                          //~v79zI~
//v780:080212 syntaxhighlight support (SYN cmd,C+s func key)       //~v780I~
//v76j:070626 (WXEXXE)dnd by paste to utility panel                //~v76jI~
//v76g:070620 utility panel(3.14:grep and 3.12:compare);f5:open dirlist, dlcmd "^":send//~v76gI~
//v73y:070128-(WXE/XXE)Quiet-exit support                          //~v73yI~
//v71A:061030 Use HtmlHelp;Winhelp is deprecated at Vista;XP english ersion cannot read .hlp by the readson of codepage unsupported//~v71AI~
//v71s:061022 (WXE/XXE)err msg when drag canceled by mouse lb release//~v71sI~
//v70w:060903 (BUG:XXE)copy issue popuperr "settext:contain invalid data" when locale is UTF-8 and len contain null//~v70wI~
//v70e:060731 (WXEXXE)add to v69Z;copy to win clipboard thw data that is by pfkey operation//~v70aI~
//v70a:060730 (WXEXXE:BUG)word copy by mouse dblclick copy word with eolid//~v70aI~
//            because default changed to stdpaste. but word copy should be vlock mode.//~v70aI~
//v69Z:060726 (XXE)sync C&P between PFkey and mouse operation.(update enable/disable menu by also Key operation)//~v69ZI~
//v69X:060720 (XXE)line-draw support also fo gxe when OPT LINECH ON.(v69M)//~v69XI~
//v69m:060524 (WXEXXE)pass scroll ctr not by string cmd parm but thrugh gbl var to avoid cmd line input cleared//~v69mI~
//v69i:060523 (WXEXXE)use pgleft/pgright also for elecom hscroll mouse(generate VK_SCROLL+VK_LEFT/VK_RIGHT+VK_SCROLL)//~v69iI~
//v69b:060516 horizontal scroll function by Left/Right key on ScrollLock status//~v69bI~
//v686:060323 dnd support by paste                                 //~v686I~
//v682:060313 (WXE:BUG)menu enable re-evaluation requred for drag selection on dirlist;and also when reset by esc key//~v682I~
//v67C:051228 support alias cmd(save in ini file using shortcut key table position ":")//~v67CI~
//v66q:051023 (XXE) v66i of WXE;C & P;if no Clipboard data on Windows CB,get data from ::CB//~v66qI~
//v66p:051026 (XXE)std paste support(v66h of WXE)                  //~v66pI~
//vX04:050802 (BUG:WXE)hardcopy;fullpage is allways effective      //~vX04I~
//vXXE:050611 new for XXE                                          //~vXXEI~
//v63h:050504 (WXE)support DragOut                                 //~v63hI~
//v627:050309 (WXE)vhex print support                              //~v627I~
//v626:050309 (WXE)for wxp **/***(set space lineno for cont line)  //~v626I~
//v564:040326 (WIN)at cmd ignore err option "-i"                   //~v564I~
//v560:040324 (WIN)break sleep by esc*2                            //~v560I~
//v55Z:040324 (WXE)ctl multicmd by wxe to display intermediate screen//~v55ZI~
//v55W:040322 (WXE)AT cmd support;"AT(&) interval,count;cmd"       //~v55WI~
//v55G:040315 (WXE)Beep option on setup dialog                     //~v55GI~
//v55D:040307 (WXE)kick wxe.hlp by help cmd                        //~v55DI~
//v55u:040229 (WXE)add open with for dir-list                      //~v55uI~
//v55t:040229 disable "save" popup menu when not edit screen       //~v55tI~
//v55q:040228 option to scroll by csr move(CSRSCROLL option)       //~v55qI~
//v55c:040208 (WXE)distingush L-CTL/R-CTL                          //~v55cI~
//v552:040202 identify wxp ** by prefix filename like as xprint    //~v552I~
//v54y:040118 (WXE)wxp cmd support(send file to wxe for print by wxe)//~v54yI~
//v53A:031013 (WXE)double click generate push and dblclick;shift+push means paste.//~v53AI~
//            so bell sound when shift+dblclick on filename-list,dir list etc.//~v53AI~
//v51w:030615 (WXE)icon for MDOS and Explorer                      //~v51wI~
//v51h:030525 (WXE)col/row by font size specification              //~v51hI~
//v516:030223 (WXE)shortcut key for dos prompt                     //~v516I~
//v500:020827 wxe support                                          //~v440I~
//*********************************************************************//~v440I~
#define XE_GETRED(colorno)   ((((colorno)&0x04)>>1)+(((colorno)&0x20)>>5))	//l. .h..	red//~v440R~
#define XE_GETGREEN(colorno) ((((colorno)&0x02)   )+(((colorno)&0x10)>>4))	//.l ..h.	green//~v440R~
#define XE_GETBLUE(colorno)  ((((colorno)&0x01)<<1)+(((colorno)&0x08)>>3))	//.. l..h	blue//~v440R~
#define RGBUNIT  85   // 0->3 4 level 255/3=85                     //~vXXER~
#define XE2RGB(colorno) \
        (RGB_MAKE(XE_GETRED(colorno)*RGBUNIT,XE_GETGREEN(colorno)*RGBUNIT,XE_GETBLUE(colorno)*RGBUNIT))//~v440R~
#define HEXINTERMARGIN  3		//inter space between cha and hex part//~2B30I~
#define GET_HEXPARTLEN(len)	  /*get hex print part len*/\
		( \
                ((len)>>2)*9 	 /* 8 byte hex + space */\
            +   (((len)%4)<<1) /* short word 2byte for each */\
	        -   (((len)%4)==0) /* drop last space when no short word*/\
        )                                                          //~2B30I~
#define GET_HEXDISPLAYLINESZ(lrecl) ((lrecl)+HEXINTERMARGIN+GET_HEXPARTLEN(lrecl))//char+interspace+hex//~2C01R~
//*********************************************************************//~v440I~
#ifdef __cplusplus                                                 //~v440I~
extern  "C"                                                        //~v440I~
{                                                                  //~v440I~
#endif                                                             //~v440I~
//*wxe-->xe *****                                                  //~v440R~
  #ifdef WXEXEI_GLOBAL                                             //~v440I~
  	#define EXTERN                                                 //~v440R~
  #else                                                            //~v440I~
  	#define EXTERN extern                                          //~v440I~
  #endif                                                           //~v440M~
                                                                   //~v440I~
  EXTERN  int Gwxestat;                                            //~v440I~
  #define GWXES_CP932          0x01                                //~v440R~
  #define GWXES_MOUSECAPPASTE  0x02	//cut and paste by mouse       //~v440R~
  #define GWXES_CMD            0x04	//cmd from wxe                 //~v440I~
  #define GWXES_MOUSEHSCROLL   0x08	//horizontal scroll by mouse   //~v69bI~
  #define GWXES_SCROLLBYMOUSE  0x10	//scroll by mouse              //~v69mI~
  #define GWXES_MOUSECAPCOPY   0x20	//C&P copy by mouse            //~v70eI~
  #define GWXES_OPT_QEXIT      0x40	//quiet exit                   //~v73yI~
  #define GWXES_NOUTF8ERRMSG   0x80	//uerrmsgedit bypass sjis->utf8 conversion for msgbox//~v79DI~
  #define GWXES_ENVISUTF8    0x0100 //locale is utf8 g_get_charset //~v79DR~
#ifdef UTF8UCS2                                                    //~va20M~
  #define GWXES_CPDATAUCS    0x0200 //mouse paste data is unicodetext//~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va5yI~
  #define GWXES_CPDATAEBC    0x0400 //mouse paste data is unicodetext from ebcdic data//~va5yI~
#endif //UTF8EBCD raw ebcdic file support                          //~va5yI~
  #define GWXES_KBDEVENT     0x0800 //kbdevent                     //~va7DI~
  #define GWXES_SELECTALL    0x1000 //parm to func_lmark_file      //~vbd2I~
  #define GWXES_UPDATEMENU   0x2000 //update File menu enabl/disable//~vbdnI~
                                                                   //~va20M~
  EXTERN  void *Gpwxei;    //ptr t WXEINTF                         //~va20M~
#endif                                                             //~va20M~
                                                                   //~v76gI~
  EXTERN  int Gxxestat;                                            //~v76gI~
  #define GXXES_DNDUTIL        0x01	//drop on utility panel        //~v76gI~
  #define GXXES_KBDNOUTF8      0x02	//return UTF8 char byte by byte//~v79zI~
  #define GXXES_KBDUTF8        0x04	//input lang is UTF8           //~v79zI~
  #define GXXES_KBDIMEICONV    0x08	//user iconv for IME input translation//~v79zR~
  #define GXXES_DBCSREAD       0x10	//return dbcs at once          //~va1cR~
  #define GXXES_FONTLIGATURE   0x0100	//font supports ligature   //~va1MI~
  #define GXXES_DEBUGHELP      0x0200	//no set geometry hint     //~varcR~
  #define GXXES_NOGEOMETRYHINT 0x0400	//no set geometry hint     //~varcI~
//  #define GXXES_FRAMEGH        0x0800   //set geometry hint to Gpframe for test//~varcR~
//  #define GXXES_VIEWGH         0x1000   //set geometry hint to Gpview  for test//~varcR~
  #define GXXES_BASE0          0x2000	//set geometry hint basex=basey=0//~varcI~
  #define GXXES_GHATONSIZE     0x4000	//set geometry hint at onsize//~varcI~
  #define GXXES_POPUPMENU_CHL  0x8000	//popup CHL menu           //~vbj2I~
  #define GXXES_ONPRINTING   0x010000	//printing by Ctrl-H/Ctrl-P//~vbDfI~
  EXTERN  int Ggeometrybasex;           //debug parm to set set_geometry_hint//~varcI~
                                                                   //~v79zI~
  EXTERN  ULONG Gconverters;                                       //~v79zI~
  EXTERN  UCHAR *Gpxxedbcstbl;                                     //~va0UR~
  EXTERN  UCHAR Gcharset[MAXLOCALESZ];                             //~v79zI~
                                                                   //~v440I~
  EXTERN  int   Gwxecapdatalen;                                    //~v440R~
  EXTERN  int   Gwxecapdataoffs;                                   //~v440R~
  EXTERN  char *Gwxecapbuff;                                       //~v440I~
#ifdef UTF8UCS2                                                    //~va20I~
  EXTERN  char *Gwxecapdbcs;                                       //~va20I~
#endif                                                             //~va20I~
  EXTERN  int   Gwxecpposx;		//parm to cap_block(word pos on plhdata)//~3202I~
  EXTERN  int   Gwxescrollctr;                                     //~v69bI~
  EXTERN  int   Gwxecapebchandle;	//ebc handle when b2u at cap copy//~va7AI~
//**********************************                               //~v440I~
	int wxe_xecall(int Preqtype,void * /*PWXEINTF*/ Ppwxei);       //~vXXER~
	#define  WXE_REQ_PREINIT         0                             //~2B30I~
	#define  WXE_REQ_INIT            1                             //~2B30R~
	#define  WXE_REQ_KEYEVENT        2                             //~2B30R~
	#define  WXE_REQ_TERM            3                             //~2B30R~
                                                                   //~v440I~
    int wxe_kbdmsg(int Popt,UINT Pscanchar,UCHAR *Pstr,int Pstrlen);//xe called by this key//~vXXER~
	#define WXEKBDMSG_SHIFTCHANGE     1                            //~v440R~
	#define WXEKBDMSG_KEYUP           2                            //~v440R~
	#define WXEKBDMSG_KEYDOWN         4                            //~v440R~
	#define WXEKBDMSG_ONCHAR          8                            //~v440I~
	#define WXEKBDMSG_SHIFTKEY      0x10                           //~v440I~
	#define WXEKBDMSG_CTLKEY        0x20                           //~v440I~
	#define WXEKBDMSG_SYSKEY        0x80                           //~v440I~
	#define WXEKBDMSG_RCTLKEY     0x0100                           //~v55cI~
	#define WXEKBDMSG_FFKEY       0x0200  //keycode is 0xff__      //~vXXEI~
	#define WXEKBDMSG_ALTKEY      0x0400                           //~v66qI~
	#define WXEKBDMSG_SCROLLLOCKKEY  0x0400 //key down             //~v69bI~
	#define WXEKBDMSG_SCROLLLOCKON   0x0800 //toggle status        //~v69bI~
	#define WXEKBDMSG_ALTGR          0x1000 //AltGr(AltChar)       //~va33I~
	#define WXEKBDMSG_IME            0x2000 //utf8 input through IME//~va3DI~
                                                                   //~vXXEI~
	char *wxe_kbdgetname(int Pkey,int Pshift);                     //~vXXEI~
                                                                   //~v440I~
	int  wxe_onsize(int Prow,int Pcol,int Pcpchngsw);              //~v440R~
	int  wxe_editcmd(char *Pcmd,char *Pfnm);                       //~v440R~
	int  wxe_dndutil(int Popt,char *Pfnm,int Prow);                //~v76gI~
	int  wxe_strcmd(char *Pcmd,char *Pparm);                       //~3102I~
//	int  wxe_strkeyin(int Prow,int Pcol,char *Pdata,int Plen);     //~v440R~
	int  wxe_setcharset(int Pinitsw,int Pcharset);                 //~v440R~
	int  wxe_getcpdata(int Prow,int Pcol,int Pcolend,char **Pdata,char **Pdbcs,int *Pplen);//~v440R~
	int  wxe_setcsrpos(int Prow,int Pcol);                         //~v440I~
//	int  wxe_capchkprot(int Prow,int Pcol);                        //~v76jR~
 	int  wxe_capchkprot(int Popt,int Prow,int Pcol);               //~v76jI~
#define WXECCP_STDPASTE  0x01     	//std paste availability chk   //~v76jI~
#define WXECCP_DRAGED    0x02     	//box or region drawn by drag  //~v76jI~
	int  wxe_cpput(int Prow,int Pcol,char *Pbuff,int Plen);        //~v440I~
	int  wxe_movecsr(int Prow,int Pcol);                           //~v440M~
	int  wxe_capblock(int Pstaend,int Prow,int Pcol,int *Ppancopysw);//~v440R~
#define CP_DRAGOPEN  0x01   	//drag end                         //~v66pI~
#define CP_DRAGCLOSE 0x02   	//drag end                         //~v66pI~
#define CP_DRAGBLOCK 0x04   	//block mode                       //~v66pI~
	int  wxe_capcopy(int Pcutsw,int *Pplen);                       //~v440R~
#define CP_DBLCLICK 0x80		//req by dblclick id               //~3202I~
#define CP_COPYWORD 0x40		//req by dblclick of word          //~v70aI~
	int  wxe_capcopy2(int Pcutsw,int *Pplen,int Prow,int Pcol);    //~3202I~
//	int  wxe_capcopytowincb(char *Pdata,int Plen);                 //~v70wR~
	int  wxe_capcopytowincb(char *Pdata,int Plen,int *Pplen);      //~v70wI~
	int  wxe_cappaste(int Pinssw,int Prow,int Pcol,char *Pdata,int Plen);//~v440I~
#ifdef UTF8UCS2                                                    //~va20I~
	#define WXECPO_MASK 0x00ff         //see cppaste flag(PASTE_xxx)//~va20I~
//WIN  #define WXECPO_UCS  0x0100         //clipboard data is unicode//~va20R~
#endif                                                             //~va20I~
	int  wxe_cappasteposchk(int Prow,int Pcol);                    //~v53AI~
	int  wxe_dbcstextcopy(char *Pout,char *Pdata,char *Pdbcs,int Plen);//~v440I~
#ifdef UTF8UCS2                                                    //~va20R~
	int  wxe_dbcstextcopypan(int Popt,char *Pout,char *Pdata,char *Pdbcs,int Plen,int *Pplenucs);//~va20R~
    #define WXEDTCPO_GETLENGTH     0x01     //no output area       //~va20R~
#endif                                                             //~va20R~
	int  wxe_reset(void);                                          //~v440I~
	int  wxe_capreset(void);                                       //~v440I~
	int  wxe_scroll(int Pscrollctr,int Pflag,int Pdest);           //~2A13R~
	void wxe_scrollh(int Pscrollctr,UINT nChar);                   //~v69bI~
	int wxe_scrollhbar(int Pscrollctr,int Pdest);                  //~v69iR~
//  int  wxe_prtgetfnm(char *Pfnm,void **Pppfh,int *Pplnotype);    //~v627R~
    int  wxe_prtgetfnm(char *Pfnm,void **Pppcw,void **Pppfh,int *Pplnotype);//~v627I~
//  int  wxe_prtinit(void *Ppfh,int *Ppmaxlen,int *Pplinenosz,int *Pppfhwidth);//~v627R~
    int  wxe_prtinit(void *Ppcw,void *Ppfh,int *Ppmaxlen,int *Pplinenosz,int *Pppfhwidth);//~v627I~
	int  wxe_prtgetline(int Ppageno,int Pmaxcol,int Pmaxline,char *Ppdata,//~2C07R~
#ifdef UTF8UCS2                                                    //~va20I~
					char *Ppdbcs,int *Ppucslen,                    //~va20I~
#endif                                                             //~va20I~
					int *Pplen,int *Ppskiplineno,int *Ppprtlen);   //~2C07R~
//  int  wxe_prtgetmaxpage(void *Ppfh,int *Ppmaxlrecl,int *Ppmaxcol,//~v627R~
    int  wxe_prtgetmaxpage(void *Ppcw,void *Ppfh,int *Ppmaxlrecl,int *Ppmaxcol,//~v627I~
							int *Ppdatacol,int Pmaxline,int *Pptotrow);//~v51hI~
	void wxe_prtgetftime(void *Ppfh,char *Pftime,char *Psystime);  //~2B03R~
	int  wxe_iswinnt(void);                                        //~2B30~//~3102R~
	int  wxe_endprint(int Popt);                                        //~2B30~//~va8aI~
	int  wxe_preinit(int Pargc,char **Pargv);                      //~2B30I~
    int  wxe_lineselect(UINT Pflag,int Prow,int Pcol,int *Ppcapinfo);//~3202R~
#define  LSCI_LINE    1		//cap copy,line selected               //~3202I~
#define  LSCI_FIELD   2		//cap copy,field selected              //~3202I~
    int  wxe_getcurpos(int *Pprow,int *Ppcol);                     //~3103M~
//*************                                                    //~3102I~
	int  wxe_otherfunc(int Pid,char *Pparm);                       //~3102I~
#define  WXEOF_END          1                                      //~3102I~
#define  WXEOF_CANCEL       2                                      //~3102I~
#define  WXEOF_DOSPROMPT    3                                      //~v516I~
#define  WXEOF_STRCMD       4                                      //~v51wI~
	int  wxe_mouseedgechk(int Pcol,int Prow);                      //~3208I~
#define MEC_LEFT        0x01     //csr pos is left edge when lbtn down//~3208I~
#define MEC_RIGHT       0x02                                       //~3208I~
#define MEC_TOP         0x04                                       //~3208I~
#define MEC_BOTTOM      0x08                                       //~3208I~
	int wxe_getorgfnm(char *Porgfnm);                              //~v54yI~
	int wxe_getrctl(void);                                         //~v55cI~
	int wxe_setrctl(int Prctlsw);                                  //~v55cI~
	int wxe_getfreecsr(void);                                      //~v55qI~
	int wxe_setfreecsr(int Pfreecsrsw);                            //~v55qR~
	int wxe_getbeep(void);                                         //~v55GI~
	int wxe_setbeep(int Pbeepsw);                                  //~v55GI~
                                                                   //~v55tI~
	int wxe_chkendenable(int Pmenuid);                             //~v55uR~
	#define CHKST_CANCEL         1                                 //~v55tI~
	#define CHKST_END            2                                 //~v55tI~
	#define CHKST_SAVE           3                                 //~v55tI~
	#define CHKST_OPENWITH       4                                 //~v55uI~
                                                                   //~vbdnI~
	int wxe_chkEnableFileSubmenu(int Popt,int Pmenuid);            //~vbdnI~
	#define CHKSTFO_MSG          0x01  //issue errmsg              //~vbdnI~
	#define CHKSTF_SAVE          2                                 //~vbdnI~
	#define CHKSTF_SAVEAS        3                                 //~vbdnI~
	#define CHKSTF_PRINT         5  //skip over 1 seperator        //~vbdnI~
                                                                   //~vbdnI~
	int wxe_errmenuitemDisabled2(char *Pmenuid);                   //~vbdnI~
                                                                   //~vbdnI~
	int wxe_onfileopenwith(void);                                  //~v55uI~
	int wxegetdbcsmode(void);                                      //~v55DI~
	int wxe_atcmd(int Popt,int Pintvl,int Prepeat,char *Pcmd,void *Ppodelmt,int Pwordno);//~v55WR~
                                                                   //~v564I~
	int wxe_timerreset(int Popt);                                  //~v55WI~
	int wxe_atcmdctl(int *Pprc);                                   //~v55WI~
    #define  WXEAT_RESET 0x01                                      //~v55WM~
    #define  WXEAT_COMP  0x02                                      //~v55WM~
    #define  WXEAT_INIT  0x04  //mult cmd by AT CMD                //~v55ZI~
    #define  WXEAT_MCMD  0x08  //mult cmd of not by AT cmd         //~v55ZI~
    #define  WXEAT_CMDER 0x10  //multi cmd stop by cmd err         //~v55WI~
    #define  WXEAT_DRAW  0x20  //draw screen req                   //~v55WI~
    #define  WXEAT_SLEEPED     0x40  //sleep expired               //~v560R~
    #define  WXEAT_SLEEPRESET  0x80  //sleep reset                 //~v560I~
    #define  WXEAT_IGNOREERR   0x0100 //not stop by subcmd err     //~v564I~
    #define  WXEAT_ALIAS       0x0200 //alias cmd edit string      //~v67CI~
    #define  WXEAT_ALIASREP    0x0400 //alias cmd replaced multicmd//~v67CI~
    #define  WXEAT_MSGTIMER  1000  //draw msg after 1sec           //~v55WI~
    #define  WXEAT_MULTCMDTIMER  10  //schedule next multi cmd interval//~v55WI~
    #define  WXEAT_SLEEPINGINTVL 2   //sleeping msg interval       //~v560I~
	int wxe_setsleeptime(int Pintvl);                              //~v560I~
                                                                   //~v627I~
    int  wxe_dragselectchk(int Popt,UINT Pflag,int Prow,int Pcol,void **Ppcw,void **Ppplh);//~v63hR~
#define DRAGOPT_SELECT   0x00 //lbdown                             //~v63hR~
#define DRAGOPT_DRAG     0x01 //mouse move                         //~v63hR~
#define DRAGCHK_NEW      0x01 //new selection                      //~v63hR~
#define DRAGCHK_ADD      0x02 //ctrl+                              //~v63hR~
#define DRAGCHK_RANGE    0x04 //Shift+                             //~v63hR~
#define DRAGCHK_DODRAG  0x100 //dodrag when mouse move             //~v63hR~
                                                                   //~v627I~
int  wxe_isremotefile(void *Ppcw);                                 //~v71sI~
    int wxe_dragreset(void *Ppcw,int Popt);                        //~v63hR~
#define DRAG_RESETDRAW    0x01 //draw after reset                  //~v63hI~
#define DRAG_RESETMSG     0x02 //uerrmsg reset count               //~v63hI~
#define DRAG_CANCELMSG    0x04 //uerrmsg canceled                  //~vXXEI~
#define DRAG_RESETBYESC   0x08 //reset by esc key                  //~v682I~
    int wxe_dragset(void *Ppcw,void *Pplh1,void* Pplh2);           //~v63hR~
    int wxe_dragdropfilelist(int Popt,void *Ppcw,char *Pbuff,int *Pplen);//~v63hR~
#define DRAG_REDRAW       0x01 //uerrmsg reset count               //~v63hR~
#define DRAG_REMOTECOPY   0x02 //copy remote to local              //~v63hI~
                                                                   //~v55tI~
	void xxe_scrdisp(void);                                        //~vXXER~
	int  wxe_getsamplecolor(char *Pattrtbl);                       //~vXXER~
int  wxe_getpcw(void **Pppcw);                                     //~vX04I~
int wxe_dndfilecopychk(int Popt,void *Ppcw,void *Ppcwtarget,int Prow,int Pcol,char *Ptargetdir);//~v686I~
#define DROP_COPYCHKMSG  0x01                                      //~v686I~
#define DROPRC_UTIL       2                                        //~v76gI~
int wxe_dndcopyfile(int Popt,int Pseq,int Ptot,char *Psource,char *Ptarget);//~v686I~
#define DNDCOPY_REP 0x01                                           //~v686I~
                                                                   //~v69ZI~
	void wxemouse_capi(int Popt,void *Ppmain);                     //~v69ZI~
    #define WXEM_INIT      0x00        //init                      //~v69ZI~
    #define WXEM_RESET     0x01        //capreset                  //~v69ZI~
    #define WXEM_SETRGN    0x02        //region/box defined        //~v69ZI~
    #define WXEM_SETRGN2   0x04        //set Mcpcopysw=2 for SEL ALL cmd//~vbd8I~
                                                                   //~v69ZI~
	int  wxe_capchkxestat(void);                                   //~v69ZI~
	int  wxe_capchkselectall(void);                                //~vbd2I~
	int  wxe_capselectall(void);                                   //~vbd2I~
	int  wxe_getpcwsubtype(void *Ppcw);                            //~v76jI~
#define WXECWST_UCOMP   1                                          //~v76jI~
#define WXECWST_UGREP   2                                          //~v76jI~
                                                                   //~v79zI~
	int xxe_imeconv(int Popt,UCHAR *Pstr,int Pstrlen,UCHAR *Ppmbs,int Poutbuffsz,int *Ppmbslen);//~v79zI~
	void *wxe_isCHLLine(int Popt);                                 //~vbj2I~
	int  wxe_CHLcmd(int Popt,int Pcmd);                            //~vbj2I~
	int xxe_getlinenosz(int Popt,int Prow,int Pcol);               //~vbm5I~
	void xxe_mapinit(void);                                        //~vbz4I~//~vbz5I~
//  int xxe_getCellData(int Prow,int Pcol,int Plen,char *Ppdata,char *Ppdbcs);//~vbApI~//~v7fzR~//~vbDsR~//~v7fzR~
    int xxe_getCellData(int Prow,int Pcol,int Plen,char *Ppdata,char *Ppdbcs,int *Ppddlen);//+v7fzR~
                                                                   //~v69ZI~
//*****************************************************************//~v440R~
#ifdef __cplusplus                                                 //~v440I~
#else                                                              //~v440I~
//xe-->wxe                                                         //~v440I~
	int  wxe_readkbd(void * /*PKBDKEYINFO*/ Ppkeyinf,int Pwait);		//set from keyup/down WMmsg//~vXXER~
#define DMYSCANCODE 0xf000  //scancode for char code internary sent//~vXXER~
                                                                   //~vXXEI~
//  int  wxe_uviogetwork(UCHAR *Pbuffc,USHORT *Pbuffa,UCHAR *Plineupdate);//~vb4rR~
    int  wxe_uviogetwork(UCHAR *Pbuffc,USHORT *Pbuffa,UCHAR *Plineupdate,int *Plineopt);//~vb4rI~
    int  wxe_getmaxscrsize(USHORT *Ppcol,USHORT *Pprow);           //~v440I~
    int  wxe_setcurpos(int Prow,int Pcol);                         //~v440I~
    int  wxe_getcurtype(void * /*PVIOCURSORINFO*/ pviocursorInfo); //~v440R~
    int  wxe_setcurtype(void * /*PVIOCURSORINFO*/ pviocursorInfo); //~v440R~
	int xxe_beep(void);                                            //~vXXEI~
    int  wxe_uviogetstate(void *Ppreqblk);                         //~v440I~
    int  wxe_uviosetstate(void *Ppreqblk);                         //~v440I~
//    int  wxe_scrsetsplit(int Pvsplitsw,void * /*PUCLIENTWE*/ Ppcw1,void * /*PUCLIENTWE*/ Ppcw2);//~v440R~
	int  wxe_peekkbd(void * /*PINPUT_RECORD*/ Pinprec,int *Poutctr);		//set from keyup/down WMmsg//~v440R~
	int  wxe_geteventno(int *Ppeventno);		//set from keyup/down WMmsg//~v440I~
	int  wxe_uerrmsgstdo(char *Ppmsg);                             //~v440I~
	int  wxe_uerrexitstdo(char *Ppmsg);                            //~v440I~
	int  wxe_funccall(int Pfuncid,char *Pcmdparm);                 //~2A20R~
    int  wxe_cappastecallback(void *Ppfh,int Pmaxwidth,char **Ppdata,char **Ppdbcs,int *Pplen,//~3112R~
							int *Psplitsw,int *Plinectr,int *Peolid,int *Plineoffs);//~v440I~
//  int wxe_wxpreq(char *Porgfnm);                                 //~v552R~
//  int wxe_wxpreq(int Popt,char *Porgfnm);                        //~v552I~//~va87R~
	int wxe_wxpreq(int Popt,char *Porgfnm,void *Ppfh);             //~va87R~
#define WXP_PRTSCR   0x01                                          //~v552I~
#define WXP_VHEX     0x02          //wxp work from vhex mode       //~va87I~
#define WXP_PRTSCRLINENOSZMASK   0xff00                            //~v626I~
//  int wxe_helpreq(void);                                         //~v71AR~
  	int wxe_helpcall(void);                                        //~v71AI~
	int wxe_scrdraw(void);                                         //~v55WI~
	int xxe_acssetup(int Psetsw,int Pentno,UCHAR *Pacstbl);        //~v69XR~
    int wxe_capcopytowincbfromxe();                                //~v70eI~
	void xxe_setsynpalettecolor(void);                             //~v780R~
	void xxe_setsynfontface(void);                                 //~v780R~
	int xxe_kbdwcinit(int Popt,int Pkbdstat,ULONG Pcodepage,UCHAR *Pcharset);//~v79zR~
//**                                                               //~va3dI~
	int wxe_getlineopt(int Popt,int Prow,int Pcol);                //~vb4rI~
	int wxe_getPosVsplit(int Popt,int Prow);                       //~vbAjI~
	int xxe_chkcsrpos(int Popt,int Prow,int Pcol,int *Ppinfo);     //~va3bR~
	#define XXECCPO_CSRLINEBREAK	0x01	//should break at csr pos ?//~va3bI~
	#define XXECCPO_STRCHK      	0x02	//should break at csr pos ?//~va3bI~
	#define XXECCPO_NOT_RELATIVE    0x04	//for vsplit, col includes left panel width//~vbDsR~
                                                                   //~va3bI~
	#define XXECCPI_CPU8			0x01	//file at csr is cpu8 file//~va3bR~
	#define XXECCPI_BIN     		0x02	//file is bin file     //~va3bI~
	#define XXECCPI_VHEX			0x04	//csr is on vhex line  //~va3bI~
	#define XXECCPI_LINENO  		0x08	//csr is on vhex line  //~va3bI~
	#define XXECCPI_CMDLINE  		0x10	//csr is on cmdline    //~va3bI~
	#define XXECCPI_VHEXCSRPOS  	0x20	//set vhexcsr pos      //~va3tI~
	#define XXECCPI_PAN        		0x40	//panel data           //~va6qR~
	#define XXECCPI_HDRLINE    		0x80	//top/end/xline        //~va6qI~
	#define XXECCPI_VHEXCSRSHIFT	   8	//                     //~va3tI~
//  #define XXECCPI_VHEXCSRMASK   0xff00	//vhexcsr pos          //~va3tI~//~vbDsR~
    #define XXECCPI_VHEXCSRMASK   0xffff00	//vhexcsr pos  over 256//~vbDpI~//~vbDsR~
	#define XXECCPI_GETVHEXCSR(inf) (((inf) & XXECCPI_VHEXCSRMASK)>>XXECCPI_VHEXCSRSHIFT)//~va3tI~
//**                                                               //~va3dI~
	int xxe_optligature(int Popt,int Pvalue);                      //~va3dR~
	#define XXEIOLO_CHNGDIALOGOPT   0x01                           //~va3dI~
	#define XXEIOLO_INIT            0x02                           //~va3dI~
	#define XXEIOLO_ISON            0x04                           //~va3dI~
#define WXE_OPTLIGATURE (xxe_optligature(XXEIOLO_ISON,0/*pvalue*/))//~vb4rI~
#define WXE_LIGATUREMODE(opt)  (  \
                                   (   (opt & UVIOO_FORCELIGATURE)                  \
                                    || ((opt & UVIOO_LIGATURE) && WXE_OPTLIGATURE)   \
                                   )                                                 \
                               )                                   //~vb4rI~
                                                                   //~va3dI~
	int  wxe_uerrexitmsgbox(char *Ppmsg);	                       //~vaf5I~
	int wxe_chkUpdateFileMenu(int Popt);                           //~vbdnI~
    int xxe_GetCursorWidth(int Popt,ULONG Pucs);                   //~vbz5I~
#endif	// .c                                                      //~v440I~
#ifdef __cplusplus                                                 //~v440I~
}                                                                  //~v440I~
#endif                                                             //~v440I~
//*********************************************************************//~v440I~
                                                                   //~v440I~
