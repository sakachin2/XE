//*CID://+vbzJR~:         update#=      7                          //+vbzJR~
//****************************************************************//~v051I~
//xedcmd2.h                                                     //~v051I~
//****************************************************************//~v061I~
//vbzJ:240403 appendmode screen print to ::hp by Ctrl+h (hardcopy) //+vbzJI~
//vbs0:201021 compile/link err on Manjaro(duplicate definition Gdcmd2wxeshellcmd)//~vbs0I~
//vavM:140405 (W32UNICODE)xfc/xdc by spawn(because cmd propt translate filename to bestfit)//~vavMI~
//va7T:100909 cpeb converter parm support:for xprint               //~va7TI~
//va57:100429 dlcmd "p" support utf8 file using profile            //~va57I~
//va50:100324 Raw EBCDIC file support for NFS mount                //~va50I~
//v77y:080118 *\/^* support for dos cmd                            //~v77yI~
//v76t:070707 (Wine)try cmd /c for pause to create new session under wine for wxe//~v76tI~
//v765:070531 (LNX:BUG)support "Konsole" as one of X-terminal      //~v765I~
//v656:050726 (XXE)xxe support;WXP cmd                             //~v656I~
//v64r:050630 (XXE)xxe support;child shell                         //~v64rI~
//v59F:041121 chng cmd name,exp/xen-->set/env and issue dos cmd when no opd under cmd panel//~v59FI~
//v59g:041107 rsh:set MOCMD screen as rlogin                       //~v59gI~
//v593:041102 split xedcmd2-->xedcmd3(submit,rsh)                  //~v593I~
//v58D:041011 (BUG) input cmd is not displayed on cmd panel        //~v58DI~
//v54y:040118 (WXE)wxp cmd support(send file to wxe for print by wxe)//~v54yI~
//v51v:030615 add SPAwn cmd(ASYNC DOS cmd) for explorer kick       //~v51vI~
//v50M:030208 dos cmd;save/restore buffsz parm to ini file         //~v50MI~
//v07d:960624:long cmd input at cmd result screen last line        //~v07dI~
//v06z:960407:stdout work last used seqno save to xe!SAVE!            //~v06tI~
//            xe.h ini3.c dcmd2.c                                     //~v06tI~
//v06t:960406:cmd so screen:append cmd result                         //~v06tI~
//v06n:960320:menu option 6(cmd) support                        //~v06nI~
//v061:960211:SHELL cmd(CMD,COM,>>)                             //~v061I~
//****************************************************************//~v051I~
#ifdef  XEDCMD2_GLOBAL                                             //~v50MI~
  #define XEDCMD2_EXT                                              //~v50MI~
#else                                                              //~v50MI~
  #define XEDCMD2_EXT extern                                       //~v50MI~
#endif                                                             //~v50MI~
#ifdef XXE                                                         //~v64rI~
//  #define XXE_CHILDSH "gnome-terminal --disable-factory" //fork syncronouse//~v765R~
#endif                                                             //~v64rI~
//***************************************                          //~v50MI~
	XEDCMD2_EXT   int Gcmdbuffsz_row,Gcmdbuffsz_col;               //~v50MI~
#ifndef AAA                                                        //~v76tI~
//  char *Gdcmd2wxeshellcmd;                                       //~v76tI~//~vbs0R~
    XEDCMD2_EXT   char *Gdcmd2wxeshellcmd;                         //~vbs0R~
#endif                                                             //~v76tI~
//***************************************                          //~v50MI~
#ifdef UTF8UCS2                                                    //~va57I~
    #define XPUTF8OPT   "Mu"                                       //~va57I~
#endif                                                             //~va57I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50M~
	#define XPEBCOPT    "Me"                                       //~va50M~
    #define XEEBCOPTCFG  "BC"                                      //~va57I~
    #define XPEBCOPTCPEB MODE_EBC ":"                              //~va7TR~
    #define XPEBCOPTASCEOL "ASCEOL"                                //~va7TI~
#endif //UTF8EBCD raw ebcdic file support                          //~va50M~
//***************************************                          //~va50I~
	FTFUNC dcmd_xprint;                                         //~v051R~
	FTFUNC func_scrHcopy;                                          //+vbzJI~
	FTFUNC dcmd_print;                                          //~v051I~
//#ifdef WXE                                                       //~v656R~
#ifdef WXEXXE                                                      //~v656I~
	FTFUNC dcmd_wxp;                                               //~v54yM~
#endif                                                             //~v54yI~
	FTFUNC dcmd_system;                                         //~v051I~
	FTFUNC dcmd_system2;                                        //~v061I~
	FTFUNC dcmd_spawn;                                             //~v51vI~
//**************************************************************** //~v07dI~
int dcmdlongcmd(PUCLIENTWE Ppcw);                                  //~v07dI~
//****************************************************************    //~v06tI~
int dcmdgetsofname(UCHAR *Psofname,UCHAR *Pfullpath);                 //~v06tI~
//****************************************************************//~v06nI~
int dcmdterm(void);                                             //~v06nI~
//**************************************************************** //~v593I~
int dcmdredirectparmerr(void);                                     //~v593I~
//**************************************************************** //~v593I~
int dcmdsystemcall(PUCLIENTWE Ppcw,char *Pcmd,int Pflag,char *Pstdofnm,char *Pstdefnm);//~v593I~
//**************************************************************** //~v593I~
int dcmdeditredirect(int Popt,UCHAR **Ppcmd,char *Pfnm,char *Pstdefnm);//~v593I~
//**************************************************************** //~v593I~
int dcmdappendso(PUCLIENTWE Ppcw,UCHAR *Psofname,UCHAR *Pcmd);     //~v593I~
//**************************************************************** //~v593I~
int dcmdsolast(UCHAR *Psofname,UCHAR *Pfname,int Prc);             //~v593I~
//**************************************************************** //~v59gI~
int dcmdputcmdlog(PUCLIENTWE Ppcw,PULINEH Pplh,int Popt,char *Pcmd);//~v59gI~
//**************************************************************** //~v59FI~
int dcmdsystemcall_intf(PUCLIENTWE Ppcw,UCHAR *Pcmd);              //~v59FI~
//**************************************************************** //~v77yI~
int dcmdscrfnmedit(int Popt,PUCLIENTWE Ppcw,UCHAR *Pcmd,char  **Ppout);//~v77yR~
#define DCSDE_FREEINPUT    0x01    //free old input if newly alloced//~v77yR~
//**************************************************************** //~va57I~
int dcmdxpsetebcparm(int Popt,PUFILEH Ppfh,char *Poutstr);         //~va57I~
//**************************************************************** //~vavMI~
int dcmdsystemcall_spawn(int Popt,PUCLIENTWE Ppcw,char *Pcmd,int Pflag,char *Pstdofnm,char *Pstdefnm);//~vavMI~
