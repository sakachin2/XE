//*CID://+v7fxR~:                             update#=  423;       //+v7fxR~
//*********************************************************************//~v440I~
//* wxe interface definition                                       //~v440I~
//*********************************************************************//~v440I~
//v7fx:251205 (Wxe)addtionally to WINCON, optionally chk EOL for also Wxe.//+v7fxI~
//vbEd:251107 (WXE)hcopy by saving TextOutW to buffer              //~vbEdI~
//vbDp:250726 (WXE)color of combining char split for vhex csr was green.(ignored that xefile23 set)//~vbDpI~
//vbDg:250706 (wxe)4byte dbcs missing display tab padding          //~vbDgI~
//vbzM:240408 (WXE) support hardcopy function                      //~vbzMI~
//vbz4:240120 try vbz3 to WXE                                      //~vbz4I~
//vbj2:180424 popup menu on cmd history list                       //~vbj2I~
//vbdn:171125 disable filemenu depending curent pcw type           //~vbdnI~
//vbd8:171120 (WXE)stdregion by PFK(F6) should disable PAste REP/INS//~vbd8I~
//vbd2:171114 (Wxe)Add SelectAll menuitem                          //~vbd2I~
//vb4i:160805 vb4f for wxe(specify ligature on/off,combine on/of line by line)//~vb4iI~
//vb4g:160801 (WXE)dirlist ligature on always like as vb37         //~vb4gI~
//vb3p:160616 (BUG)when utf8 ligature on,1st colomn green is ligatured to linono//~vb3pI~
//vavz:140428 (wxe)display ucs2 filename on page dialog            //~vavzI~
//vafh:120616 for VC10:/W4 warning except C4115,C4214,C4100,C4706,C4244,C4210,C4127,C4245//~vafhI~
//va8a:100926 (WXE)end wxp work at end print                       //~va8aI~
//va87:100924 (WXE)wxp cmd;**/*** vhex print corespondency of upper and lower line//~va87I~
//va7D:100830 (XXE:BUG)cap menu update err(it should not be based on Mcellcopy1 bur Gcsrposy)//~va7DI~
//va7A:100829 (WXE:EBC)handle support for mouse cap                //~va7AI~
//va6q:000623 avoid ligature for not data line(gauge, xline etc)   //~va6qI~
//va5y:100518 (WXE)Windows Clipboard translate text. It cause invalid sjis to u-30fb when CF_UNICODETEXT mode//~va5yI~
//            0x0e,4481,0f,00,0a,00(setclipboatddata)-->0x0e00,4400,fb30,0000,0a00,0000(getclipboarddata)//~va5yI~
//            on the otherhand getclipboarddata with CF_TEXT option returns "?" for u2l trans err code of utf8 file(u-00a4(Sun)->"?").//~va5yI~
//            so for EBCDIC code, SetClipboard by CF_UNICODETEXT after trans to ucs2 by bynary mode(1 byte to 1 ucs2)//~va5yI~
//            CF_OEMTEXT will also translate such as 0x8586->0x8145(=u-30FB)//~va5yI~
//            for over session data identification set prefix at top of ebc data//~va5yI~
//va3t:100221 (WXEXXE)break also at prev char of vhex data csr pos for backspace at vhex line//~va3tI~
//va3k:100210 (BUG:WIN)vsplit line draw err(=1,=2,edit hdr line at right half)//~va3kI~
//va3h:100207 try ligature for also win32 console version          //~va3hI~
//va3g:100207 try ligature for also wxe(write ucs string at once) for arabic etc//~va3gI~
//va20:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~va20I~
//v79z:080916 DBCS tbl for C and K of CJK                          //~v79zR~
//v76j:070626 (WXEXXE)dnd by paste to utility panel                //~v76jI~
//v76g:070620 utility panel(3.14:grep and 3.12:compare);f5:open dirlist, dlcmd "^":send//~v76gI~
//v73y:070128-(WXE/XXE)Quiet-exit support                          //~v73yI~
//v71A:061030 Use HtmlHelp;Winhelp is deprecated at Vista;XP english ersion cannot read .hlp by the readson of codepage unsupported//~v71AI~
//v71s:061022 err msg when drag canceled by mouse lb release       //~v71sI~
//v70e:060731 (WXEXXE)add to v69Z;copy to win clipboard thw data that is by pfkey operation//~v70eI~
//v70a:060730 (WXEXXE:BUG)word copy by mouse dblclick copy word with eolid when its is last word(after dropped CID)//~v70aI~
//            because default changed to stdpaste. but word copy should be vlock mode.//~v70aI~
//v69Z:060726 (XXE)sync C&P between PFkey and mouse operation.(update enable/disable menu by also Key operation)//~v69ZI~
//v69m:060524 (WXEXXE)pass scroll ctr not by string cmd parm but thrugh gbl var to avoid cmd line input cleared//~v69mI~
//v69g:060521 (WXE)tilt wheel mouse generate WM_VSCROLL/WM_HSCROLL by mycrosoft spec//~v69gI~
//            if scroll bar exist.(both vertical and horizontal is requred to genarate both)//~v69gI~
//v69f:060521 (WXE)xbutton1/2 support;browser backk/forwardlock on status for up/down arrow key to scroll up/down//~v69fI~
//v69b:060516 horizontal scroll function by Left/Right key on ScrollLock status//~v69bI~
//v686:060323 dnd support by paste                                 //~v686I~
//v685:060322 dnd support "file copy into the dir slected" and even in inter-split-screen.//~v685I~
//v682:060313 (WXE:BUG)menu enable re-evaluation requred for drag selection on dirlist;and also when reset by esc key//~v682I~
//v67C:051228 support alias cmd(save in ini file using shortcut key table position ":")//~v67CI~
//v66h:051023 C & P;region mode by mouse; mouse drag->region mode,A+mouse drag->block mode//~v66hI~
//v65h:050729 (BUG:WXE)hardcopy;fullpage is allways effective      //~v65hI~
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
#define RGBUNIT  85                                                //~v440I~
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
  #define GWXES_NOUTF8ERRMSG   0x80	//uerrmsgedit bypass sjis->utf8 conversion for msgbox//~v79zR~
#ifdef UTF8UCS2                                                    //~va20I~
  #define GWXES_ENVISUTF8    0x0100 //locale is utf8 g_get_charset //~va20R~
  #define GWXES_CPDATAUCS    0x0200 //mouse paste data is unicodetext//~va20R~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50R~//~va5yI~
  #define GWXES_CPDATAEBC    0x0400 //mouse paste data is unicodetext//~va5yI~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~//~va5yI~
  #define GWXES_KBDEVENT     0x0800 //kbdevent                     //~va7DI~
  #define GWXES_SELECTALL    0x1000 //parm to func_lmark_file      //~vbd2I~
  #define GWXES_UPDATEMENU   0x2000 //update File menu enabl/disable//~vbdnI~
                                                                   //~va20I~
  EXTERN  void *Gpwxei;    //ptr t WXEINTF                         //~va20I~
  #define GPWXEI()   ((WXEINTF*)Gpwxei)                            //~va3gR~
#endif                                                             //~va20I~
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
	int wxe_xecall(int Preqtype,void * /*PWXEINTF*/ Ppwxei,int Pargc,char **Pargv);//~v440R~
	#define  WXE_REQ_PREINIT         0                             //~2B30I~
	#define  WXE_REQ_INIT            1                             //~2B30R~
	#define  WXE_REQ_KEYEVENT        2                             //~2B30R~
	#define  WXE_REQ_TERM            3                             //~2B30R~
                                                                   //~v440I~
	int  wxe_kbdmsg(int Pstat,UINT Pchar,UINT Prepctr,UINT Pflag); //~v440R~
	#define WXEKBDMSG_SHIFTCHANGE     1                            //~v440R~
	#define WXEKBDMSG_KEYUP           2                            //~v440R~
	#define WXEKBDMSG_KEYDOWN         4                            //~v440R~
	#define WXEKBDMSG_ONCHAR          8                            //~v440I~
	#define WXEKBDMSG_SHIFTKEY      0x10                           //~v440I~
	#define WXEKBDMSG_CTLKEY        0x20                           //~v440I~
	#define WXEKBDMSG_SYSKEY        0x80                           //~v440I~
	#define WXEKBDMSG_RCTLKEY     0x0100                           //~v55cI~
	#define WXEKBDMSG_ALTKEY      0x0200	                       //~v66hI~
	#define WXEKBDMSG_SCROLLLOCKKEY  0x0400 //key down             //~v69bR~
	#define WXEKBDMSG_SCROLLLOCKON   0x0800 //toggle status        //~v69bI~
	#define WXEKBDMSG_ONCHARUCS      0x8000 //unicode char input   //~v79zR~
	#define WXEKBDMSG_RAWMODE      0x010000 //onchar by Alt+"+"    //~va3tI~
                                                                   //~vb4gI~
                                                                   //~v440I~
	int  wxe_onsize(int Prow,int Pcol,int Pcpchngsw);              //~v440R~
	int  wxe_editcmd(char *Pcmd,char *Pfnm);                       //~v440R~
	int  wxe_strcmd(char *Pcmd,char *Pparm);                       //~3102I~
	int  wxe_dndutil(int Popt,char *Pfnm,int Prow);                //~v76gR~
//	int  wxe_strkeyin(int Prow,int Pcol,char *Pdata,int Plen);     //~v440R~
	int  wxe_setcharset(int Pinitsw,int Pcharset);                 //~v440R~
	int  wxe_getcpdata(int Prow,int Pcol,int Pcolend,char **Pdata,char **Pdbcs,int *Pplen);//~v440R~
	int  wxe_setcsrpos(int Prow,int Pcol);                         //~v440I~
// 	int  wxe_capchkprot(int Prow,int Pcol);                        //~v76jR~
 	int  wxe_capchkprot(int Popt,int Prow,int Pcol);               //~v76jI~
#define WXECCP_STDPASTE  0x01     	//std paste availability chk   //~v76jI~
#define WXECCP_DRAGED    0x02     	//box or region drawn by drag  //~v76jI~
	int  wxe_cpput(int Prow,int Pcol,char *Pbuff,int Plen);        //~v440I~
	int  wxe_movecsr(int Prow,int Pcol);                           //~v440M~
	int  wxe_capblock(int Pstaend,int Prow,int Pcol,int *Ppancopysw);//~v440R~
#define CP_DRAGOPEN  0x01   	//drag end                         //~v66hI~
#define CP_DRAGCLOSE 0x02   	//drag end                         //~v66hR~
#define CP_DRAGBLOCK 0x04   	//block mode                       //~v66hR~
	int  wxe_capcopy(int Pcutsw,int *Pplen);                       //~v440R~
#define CP_DBLCLICK 0x80		//req by dblclick id               //~3202I~
#define CP_COPYWORD 0x40		//req by dblclick of word          //~v70aI~
	int  wxe_capcopy2(int Pcutsw,int *Pplen,int Prow,int Pcol);    //~3202I~
    int  wxe_capcopytowincb(char *Pdata,int Plen);                 //~v70eR~
	int  wxe_cappaste(int Pinssw,int Prow,int Pcol,char *Pdata,int Plen);//~v440I~
#ifdef UTF8UCS2                                                    //~va20I~
	#define WXECPO_MASK 0x00ff         //see cppaste flag(PASTE_xxx)//~va20I~
	#define WXECPO_UCS  0x0100         //clipboard data is unicode //~va20I~
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
	int wxe_scrollhbar(int Pscrollctr,int Pdest);                  //~v69gI~
//  int  wxe_prtgetfnm(char *Pfnm,void **Pppfh,int *Pplnotype);    //~v627R~
#ifdef W32UNICODE                                                  //~vavzR~
int  wxe_prtgetfnm(char *Pfnm,void **Pppcw,void **Pppfh,int *Pplnotype,UWCH *PfnmW,int Pbuffsz,int *Ppucsctr);//~vavzR~
#else                                                              //~vavzI~
    int  wxe_prtgetfnm(char *Pfnm,void **Pppcw,void **Pppfh,int *Pplnotype);//~v627I~
#endif                                                             //~vavzI~
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
	char *wxe_uerrmsg(char *Pemsg ,char *Pjmsg,... );              //~v71sM~
	int  wxe_iswinnt(void);                                        //~2B30~//~3102R~
	int  wxe_endprint(int Popt);                                        //~2B30~//~va8aI~
	int  wxe_preinit(int Pargc,char **Pargv);                      //~2B30I~
    int  wxe_lineselect(UINT Pflag,int Prow,int Pcol,int *Ppcapinfo);//~3202R~
#define  LSCI_LINE    1		//cap copy,line selected               //~3202I~
#define  LSCI_FIELD   2		//cap copy,field selected              //~3202I~
    int  wxe_getcurpos(int *Pprow,int *Ppcol);                     //~3103M~
	int  wxe_browsercmd(int Pcmdid);                               //~v69fI~
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
#ifdef W32UNICODE                                                  //~vavzI~
	int wxe_getorgfnm(char *Porgfnm,UWCH *PorgfnmW);               //~vavzR~
#else                                                              //~vavzI~
	int wxe_getorgfnm(char *Porgfnm);                              //~v54yI~
#endif                                                             //~vavzI~
	int wxe_getrctl(void);                                         //~v55cI~
	int wxe_setrctl(int Prctlsw);                                  //~v55cI~
	int wxe_getfreecsr(void);                                      //~v55qI~
	int wxe_setfreecsr(int Pfreecsrsw);                            //~v55qR~
	int wxe_getbeep(void);                                         //~v55GI~
	int wxe_setbeep(int Pbeepsw);                                  //~v55GI~
	int wxe_getqexit(void);                                        //~v73yI~
	int wxe_setqexit(int Pbeepsw);                                 //~v73yI~
                                                                   //~v55tI~
	int wxe_chkendenable(int Pmenuid);                             //~v55uR~
	#define CHKST_CANCEL         1                                 //~v55tI~
	#define CHKST_END            2                                 //~v55tI~
	#define CHKST_SAVE           3                                 //~v55tI~
	#define CHKST_OPENWITH       4                                 //~v55uI~
                                                                   //~vbdnI~
	int wxe_chkEnableFileSubmenu(int Popt,int Pmenuid);            //~vbdnR~
	#define CHKSTFO_MSG          0x01  //issue errmsg              //~vbdnI~
	#define CHKSTF_SAVE          2                                 //~vbdnI~
	#define CHKSTF_SAVEAS        3                                 //~vbdnI~
	#define CHKSTF_PRINT         5  //skip over 1 seperator        //~vbdnR~
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
    int wxe_dragreset(void *Ppcw,int Popt);                        //~v63hR~
#define DRAG_RESETDRAW    0x01 //draw after reset                  //~v63hI~
#define DRAG_RESETMSG     0x02 //uerrmsg reset count               //~v63hI~
#define DRAG_RESETBYESC   0x04 //reset by esc key                  //~v682I~
    int wxe_dragset(void *Ppcw,void *Pplh1,void* Pplh2);           //~v63hR~
    int wxe_dragdropfilelist(int Popt,void *Ppcw,char *Pbuff,int *Pplen);//~v63hR~
#define DRAG_REDRAW       0x01 //uerrmsg reset count               //~v63hR~
#define DRAG_REMOTECOPY   0x02 //copy remote to local              //~v63hI~
int  wxe_getpcw(void **Pppcw);                                     //~v65hI~
                                                                   //~v682I~
int wxe_dndfilecopychk(int Popt,void *Ppcw,void *Ppcwtarget,int Prow,int Pcol,char *Ptargetdir);//~v686R~
#define DROP_COPYCHKMSG  0x01                                      //~v682I~
#define DROPRC_UTIL       2                                        //~v76gI~
int wxe_dndcopyfile(int Popt,int Pseq,int Ptot,char *Psource,char *Ptarget);//~v686R~
#define DNDCOPY_REP 0x01                                           //~v686I~
//int wxe_dropselectchk(int Popt);                                 //~v686R~
	void wxemouse_capi(int Popt,void *Ppmain);                     //~v69ZR~
    #define WXEM_INIT      0x00        //init                      //~v69ZI~
    #define WXEM_RESET     0x01        //capreset                  //~v69ZI~
    #define WXEM_SETRGN    0x02        //region/box defined        //~v69ZI~
    #define WXEM_SETRGN2   0x04        //set Mcpcopysw=2 for SEL ALL cmd//~vbd8R~
                                                                   //~v69ZI~
	int  wxe_capchkxestat(void);                                   //~v69ZI~
	int  wxe_capchkselectall(void);                                //~vbd2I~
	int  wxe_capselectall(void);                                   //~vbd2I~
	int  wxe_funccall(int Pfuncid,char *Pcmdparm);                 //~v71sM~
  	int wxe_helpcall(void);                                        //~v71AM~
	int  wxe_getpcwsubtype(void *Ppcw);                            //~v76jR~
#define WXECWST_UCOMP   1                                          //~v76jI~
#define WXECWST_UGREP   2                                          //~v76jI~
                                                                   //~v55tI~
	int wxe_optligature(int Popt,int Pvalue);                      //~va3gM~
#define WXEIOLO_CHNGDIALOGOPT       0x01                           //~va3gM~
#define WXEIOLO_INIT                0x02                           //~va3hI~
#define WXEIOLO_ISON                0x04                           //~va3hI~
                                                                   //~vb4gI~
//    int wxe_getligaturerows(int Popt,int *Pvalues);              //~vb4iR~
////***************                                                //~vb4iR~
////*Pvalues for ligaturerows[]                                    //~vb4iR~
//    #define LIGATURE_ROW_TOP2ND     0  //hsplit pcw2 top  row    //~vb4iR~
//    #define LIGATURE_ROW_COL2ND     1  //vsplit pcw2 left col    //~vb4iR~
//    #define LIGATURE_ROW_HDRLNO1    2  //dirlist topline of pcw1 //~vb4iR~
//    #define LIGATURE_ROW_HDRLNO2    3  //dirlist topline of pcw2 //~vb4iR~
//    #define LIGATURE_ROW_DIRENT1    4  //dirlist topline of pcw1 //~vb4iR~
//    #define LIGATURE_ROW_DIRENT2    5  //dirlist topline of pcw2 //~vb4iR~
//    #define LIGATURE_ROW_TBSZ       6                            //~vb4iR~
//                                                                 //~vb4iR~
//    #define LIGATURE_ROW_RC_HSPLIT  1                            //~vb4iR~
//    #define LIGATURE_ROW_RC_VSPLIT  2                            //~vb4iR~
////***************                                                //~vb4iR~
//    int wxe_chkligaturerow(int Popt,int *Pligaturerows,int Prow,int Pcol,int *Prelativerow);//~vb4iR~
//    #define CHKLIGATURE_RC_LIGATURE         0x01                 //~vb4iR~
//    #define CHKLIGATURE_RC_NOLIGATURE       0x02                 //~vb4iR~
//    #define CHKLIGATURE_RC_NOCOMBINE        0x04                 //~vb4iR~
	int wxe_getlineopt(int Popt,int Prow,int Pcol);                //~vb4iR~
//***************                                                  //~vb4gR~
	int xxe_chkcsrpos(int Popt,int Prow,int Pcol,int *Ppinfo);     //~va3kI~
	#define XXECCPO_CSRLINEBREAK	0x01	//should break at csr pos ?//~va3kI~
	#define XXECCPO_STRCHK      	0x02	//should break at csr pos ?//~va3kI~
	#define XXECCPO_NOT_RELATIVE    0x04	//for vsplit, col includes left panel width//~vbDpI~
                                                                   //~va3kI~
	#define XXECCPI_CPU8			0x01	//file at csr is cpu8 file//~va3kI~
	#define XXECCPI_BIN     		0x02	//file is bin file     //~va3kI~
	#define XXECCPI_VHEX			0x04	//csr is on vhex line  //~va3kI~
	#define XXECCPI_LINENO  		0x08	//csr is on vhex line  //~va3kI~
	#define XXECCPI_CMDLINE  		0x10	//csr is on cmdline    //~va3kI~
	#define XXECCPI_PAN        		0x40	//panel data           //~va6qI~
	#define XXECCPI_HDRLINE    		0x80	//top/end/xline        //~va6qI~
	#define XXECCPI_VHEXCSRPOS  	0x20	//set vhexcsr pos      //~va3tR~
	#define XXECCPI_VHEXCSRSHIFT	   8	//                     //~va3tR~
//  #define XXECCPI_VHEXCSRMASK   0xff00	//vhexcsr pos          //~vbDpR~
    #define XXECCPI_VHEXCSRMASK   0xffff00	//vhexcsr pos  over 256//~vbDpI~
	#define XXECCPI_GETVHEXCSR(inf) (((inf) & XXECCPI_VHEXCSRMASK)>>XXECCPI_VHEXCSRSHIFT)//~va3tR~
	int xxe_getlinenofldsz(int Popt,int Prow,int *Poutcols);       //~vb3pR~
	int wxe_chkUpdateFileMenu(int Popt);                           //~vbdnR~
	void *wxe_isCHLLine(int Popt);                                 //~vbj2R~
	int  wxe_CHLcmd(int Popt,int Pcmd);                            //~vbj2R~
	void wxe_mapinit(void);                                        //~vbz4I~
    //**********************************                           //~vbDgI~
	int  wxexei_getXeOpt(int Popt);                                //~vbDgR~
    #define GXEO_TABDISPLAY       1    //tab padding ucs           //~vbDgR~
    #define GXEO_TABCOLORFG       2    //tab padding fg color      //~vbDgI~
//*****************************************************************//~v440R~
#ifdef __cplusplus                                                 //~v440I~
#else                                                              //~v440I~
//xe-->wxe                                                         //~v440I~
//  int  wxe_uviogetwork(UCHAR *Pbuffc,USHORT *Pbuffa,UCHAR *Plineupdate);//~vb4iR~
    int  wxe_uviogetwork(UCHAR *Pbuffc,USHORT *Pbuffa,UCHAR *Plineupdate,int *Plineopt);//~vb4iR~
    int  wxe_getmaxscrsize(USHORT *Ppcol,USHORT *Pprow);           //~v440I~
    int  wxe_setcurpos(int Prow,int Pcol);                         //~v440I~
    int  wxe_getcurtype(void * /*PVIOCURSORINFO*/ pviocursorInfo); //~v440R~
    int  wxe_setcurtype(void * /*PVIOCURSORINFO*/ pviocursorInfo); //~v440R~
    int  wxe_uviogetstate(void *Ppreqblk);                         //~v440I~
    int  wxe_uviosetstate(void *Ppreqblk);                         //~v440I~
//    int  wxe_scrsetsplit(int Pvsplitsw,void * /*PUCLIENTWE*/ Ppcw1,void * /*PUCLIENTWE*/ Ppcw2);//~v440R~
	int  wxe_readkbd(void * /*PINPUT_RECORD*/ Pinprec,int *Polen);		//set from keyup/down WMmsg//~v440R~
	int  wxe_peekkbd(void * /*PINPUT_RECORD*/ Pinprec,int *Poutctr);		//set from keyup/down WMmsg//~v440R~
//  int  wxe_geteventno(int *Ppeventno);		//set from keyup/down WMmsg//~v440I~//~vafhR~
    int  wxe_geteventno(DWORD *Ppeventno);		//set from keyup/down WMmsg//~vafhR~
	int  wxe_uerrmsgstdo(char *Ppmsg);                             //~v71sM~
	int  wxe_uerrexitstdo(char *Ppmsg);                            //~v440I~
    int  wxe_cappastecallback(void *Ppfh,int Pmaxwidth,char **Ppdata,char **Ppdbcs,int *Pplen,//~3112R~
							int *Psplitsw,int *Plinectr,int *Peolid,int *Plineoffs);//~v440I~
//  int wxe_wxpreq(char *Porgfnm);                                 //~v552R~
//  int wxe_wxpreq(int Popt,char *Porgfnm);                        //~v552I~//~va87R~
#ifdef W32UNICODE                                                  //~vavzI~
    int wxe_wxpreq(int Popt,char *Porgfnm,void *Ppfh,void *Ppfhorg);//~vavzI~
#else                                                              //~vavzI~
    int wxe_wxpreq(int Popt,char *Porgfnm,void *Ppfh);             //~va87I~
#endif                                                             //~vavzI~
#define WXP_PRTSCR   0x01                                          //~v552I~
#define WXP_VHEX     0x02          //wxp work from vhex mode       //~va87I~
#define WXP_PRTSCRLINENOSZMASK   0xff00                            //~v626I~
//	int wxe_helpreq(void);                                         //~v71AR~
	int wxe_scrdraw(void);                                         //~v55WI~
    int wxe_capcopytowincbfromxe();                                //~v70eR~
	int wxe_kbdwcinit(int Popt,int Pkbdstat,int Pcodepage);        //~v79zR~
    int wxe_GetCursorWidth(int Popt,ULONG Pucs);                   //~vbz4I~
                                                                   //~vbzMI~
#ifdef AAA                                                         //~vbEdI~
    int wxe_m2u(int Popt,int Prow,int Pcol,UCHAR *Ppdata,UCHAR *Ppdbcs,int Plen,WUCS *Ppucs,int Pbuffsz,int *Ppucsctr);//~vbzMR~
    int wxe_u2altch(int Popt,int Prow,int Pcol,UCHAR *Ppdata,UCHAR *Ppdbcs,int Plen,WUCS *Ppucs,int Pbuffsz,int *Ppucsctr);//~vbzMR~
#else                                                              //~vbEdI~
//  void wxe_getucsHC(int Popt,int Prow,int Pmaxcol,UWCH **Ppucs,int *Ppucsctr);//+v7fxR~
	void wxe_getucsHC(int Popt,int Prow,int Pmaxcol,int PsplitVpos,UWCH **Ppucs,int *Ppucsctr);//+v7fxI~
#endif                                                             //~vbEdI~
#endif	// .c                                                      //~v440I~
    #define WXEHCO_VSPLIT_LEFT  0x01                               //~vbzMM~
    #define WXEHCO_VSPLIT_RIGHT 0x02                               //~vbzMM~
    #define WXEHCO_HSPLIT_UPPER 0x04                               //~vbzMI~
    #define WXEHCO_VSPLIT_LOWER 0x08                               //~vbzMI~
    #define WXEHCO_PCW1_FILE    0x10                               //~vbzMI~
    #define WXEHCO_PCW2_FILE    0x20                               //~vbzMI~
    #define WXEHCO_FILE1_UTF8   0x40                               //~vbzMI~
    #define WXEHCO_FILE2_UTF8   0x80                               //~vbzMI~
    #define WXEHCO_DATALINE   0x0100  //may apply lgature          //~vbzMR~
    #define WXEHCO_LIGATURE   0x0200                               //~vbzMR~
                                                                   //~vbzMI~
#ifdef __cplusplus                                                 //~v440I~
}                                                                  //~v440I~
#endif                                                             //~v440I~
//*********************************************************************//~v440I~
//#define WXE_OPTLIGATURE (((GPWXEI()->WXEIstatus & WXEIS_LIGATURE)!=0) ^ ((GPWXEI()->WXEIstatus & WXEIS_TEMPLIGATURE)!=0))//~vb4iM~
#define WXE_OPTLIGATURE (wxe_optligature(WXEIOLO_ISON,0/*pvalue*/))//~vb4iM~
#define WXE_LIGATUREMODE(opt)  (  \
                                   (   (opt & UVIOO_FORCELIGATURE)                  \
                                    || ((opt & UVIOO_LIGATURE) && WXE_OPTLIGATURE)   \
                                   )                                                 \
                               )                                   //~vb4iM~
#define WXE_COMBINEMODE(opt) COMBINEMODE(opt)	//uviom.h          //~vb4iM~
                                                                   //~v440I~
