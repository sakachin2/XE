//CID://+vavcR~:            update#=  122221                       //~vavcR~
//*********************************************************************
//*xeerr.h
//* errmsg sub
//*********************************************************************
//vavc:140421 (Win)unicode support(UD fmt string)                  //~vavcI~
//vava:140410 (Win)unicode support(UD fmt string)                  //~vavaI~
//vaa0:110705 wildcard member display on dirlist,but disallow delete lcmd//~vaa0I~
//va79:100809 cpeb converter parm support                          //~va79I~
//va50:100324 Raw EBCDIC file support for NFS mount                //~va50I~
//va20:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~va20I~
//va0m:090811 reject CPU8/CPLC for bin file                        //~va0mI~
//v77b:071219 accept numeric only for color panel                  //~v77bI~
//v76g:070620 utility panel(3.14:grep and 3.12:compare);f5:open dirlist, dlcmd "^":send//~v76gI~
//v62Q:050419 errmsg for split width is over MAXLINEDATA           //~v62QI~
//v62f:050314 change matching specification "*= & n "-->"*=Mn"     //~v62fI~
//v60y:050202 exe cmd *2 option(use other split screen file)       //~v60yI~
//v60v:050201 virtual hex display option(/Mx,HEX on/off,prev HEX is XIN)//~v60vI~
//v50E:030126 (DOS)no TC cmd support for memory                    //~v50EI~
//v50m:030102 accept tab cmd on any screen                         //~v50mI~
//v43m:011101 conflict err msg                                     //~v43mI~
//v417:010729 allow lineno fld when not protected for spf file     //~v417I~
//v155:000318 numeric calc func                                    //~v155I~
//v10v:990326 chng browse binary mode:"2" -->"1",and add "2" as edit binary mode//~v10vI~
//v0i8:980522 move csrposerr to xeerr                              //~v0i8I~
//v098:970413:(BUG)avail update on browse line(but its is not saved)//~v098I~
//            by Shift+Ins/Del/F10(rep)/Enter(Split).              //~v098I~
//            (move errmsg to xeerr.c from xecap.c)                //~v098I~
//v05B:960104:Option commnad                                    //~v05BI~
//v03b:950730:zenkaku err msg for lineno,scroll fld etc         //~v03bI~
//*********************************************************************
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	#define XEERRMSG_MAXPARM    5  //                              //~va50R~
	#define XEERRMSG_MAXPARMLEN 80 //max string parm len           //~va50I~
	int xeerrmsg(int Popt,int Pparmctr,char *Pcodetype,char *Pemsg ,char *Pjmsg,... );//~va50I~
    #define XEERMO_EXIT          0x01    //uerrexit                //~va50I~
    #define XEERMO_CAT           0x02    //uerrmsgcat              //~va50I~
    #define XEERMO_HANDLEMASK    0x0f00  //handle mask             //~va79I~
    #define XEERMO_HANDLESHIFT   8                                 //~va79I~
    #define XEERMO_GETHANDLE(opt)    (((opt)&XEERMO_HANDLEMASK)>>XEERMO_HANDLESHIFT)//~va79I~
    #define XEERMO_SETHANDLE(handle) (((handle)<<XEERMO_HANDLESHIFT) & XEERMO_HANDLEMASK)//~va79I~
                                                                   //~va50I~
    #define XEERMPTS_NOTSTR        "0"    //parm is not string     //~va50R~
    #define XEERMPTS_UTF8          "1"    //parm is utf8           //~va50R~
    #define XEERMPTS_LC            "2"    //parm is locale code    //~va50R~
    #define XEERMPTS_EBC           "3"    //parm is ebcdic sbcs    //~va50R~
    #define XEERMPTS_EBCDBCSPARM   "4"    //parm is ebcdic and dbcstbl//~va50R~
    #define XEERMPTS_EBCDBCSALL    "5"    //parm is ebcdic without dbcs tbl//~va50R~
    #define XEERMPTS_DDFMT         "6"    //parm is dd fmt(data+dbcs)//~va50I~
    #define XEERMPTS_WITHCT        "7"    //parm is mixed and width codetbl//~va50I~
    #define XEERMPTS_CMDSTR        "8"    //parm is part of cmd str(it may be mixed)//~va50I~
                                                                   //~va50I~
    #define XEERMPT_NOTSTR        '0'    //parm is not string      //~va50I~
    #define XEERMPT_UTF8          '1'    //parm is utf8            //~va50I~
    #define XEERMPT_LC            '2'    //parm is locale code     //~va50I~
    #define XEERMPT_EBC           '3'    //parm is ebcdic sbcs     //~va50I~
    #define XEERMPT_EBCDBCSPARM   '4'    //parm is ebcdic and dbcstbl//~va50I~
    #define XEERMPT_EBCDBCSALL    '5'    //parm is ebcdic without dbcs tbl//~va50I~
    #define XEERMPT_DDFMT         '6'                              //~va50I~
    #define XEERMPT_WITHCT        '7'                              //~va50I~
    #define XEERMPT_CMDSTR        '8'                              //~va50R~
    #define XEERMCT_NOTLC       0x01     //start of not locale code//~va50R~
//  #define XEERMCT_UTF8        0x02     //                       //~va50I~//~vavcR~
//    #define XEERMCT_UTF8CODE    0x02     //   =UD_UTF8CODE       //~vavcR~
    #define XEERMCT_UTF8WC      0x04     //   =UD_UTF8WC           //+vavcI~
    #define XEERMCT_EBC         0x03     //                        //~va50R~
  #ifdef W32                                                       //~vavaR~
//  #define XEERMCT_UTF8SUBC    0x04     //                        //~vavaR~//~vavcR~
//  #define XEERMCT_UTF8WC      0x04     //   =UD_UTF8WC           //+vavcR~
    #define XEERMCT_UTF8WCSUBC  0x05     //   =UD_UTF8WCSUBC       //~vavcI~
  #endif                                                           //~vavaR~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//* FUNCTION *******************************
#define ERRMSGCLEAR(pcw) UCBITON(((PUSCRD)(pcw->UCWpsd))->USDflag2,USDF2DRAW)//~v76gI~
//**************************************************************** //~va50I~
int xeerr_seterrmsgct(int Popt,char *Pmixed,int Pmixlen,char *Pcodetype,char *Pdbcs,int Plclen,char *Poutbuff,int Pbuffsz,int *Ppoutlen);//~va50I~
//****************************************************************
int errmissing(void);
//****************************************************************
int errtoomany(void);
//****************************************************************
int errinvalid(UCHAR *Popd);
//**************************************************************//~v03bR~
int errdbcsinput(void);                                         //~v03bR~
//**************************************************************   //~v77bI~
int errnotnumeric(void);                                           //~v77bI~
//**************************************************************   //~v77bI~
int errnotascii(void);                                             //~v77bI~
//****************************************************************//~v03bI~
int errtoolong(void);                                           //~v03bI~
//****************************************************************//~v03bI~
int errlcmd(void);                                              //~v03bI~
//****************************************************************//~v05BI~
int erralready(void);                                           //~v05BR~
//*******************************************************          //~v098I~
int errbrowsemode(void);                                           //~v098I~
//*******************************************************          //~v0i8I~
int errcsrpos(void);                                               //~v0i8I~
//*******************************************************          //~v10vI~
int errdir(UCHAR *Pfnm);                                           //~v10vR~
//*******************************************************          //~v155I~
int errformat(UCHAR *Pdata);                                       //~v155I~
//*******************************************************          //~v417I~
int errprotected(void);                                            //~v417R~
//*******************************************************          //~v417I~
int errmarginboundary(void);                                       //~v417I~
//*******************************************************          //~v43mI~
int errconflict(UCHAR *Popd1,UCHAR *Popd2);                        //~v43mI~
//*******************************************************          //~v50mI~
int errscrtype(UCHAR *Pcmd);                                       //~v50mI~
//*******************************************************          //~v50EI~
int errnotsupported(UCHAR *Pcmd,UCHAR *Pcond);                     //~v50EI~
//*******************************************************          //~v60yI~
//int errscrnotsplited(void);                                      //~v62fR~
int errscrnotsplited(char *Pparm);                                 //~v62fI~
//*******************************************************          //~v60yI~
//int err2ndscrisnotfile(void);                                    //~v62fR~
int err2ndscrisnotfile(char *Pparm);                               //~v62fI~
//*******************************************************          //~v60vI~
int errnotvalidhexchar(void);                                      //~v60vI~
//*******************************************************          //~v62QI~
int errovermax(UCHAR *Pdataname,char *Pparm,char *Pcomp,LONG Pmax);//~v62QI~
#ifdef UTF8SUPPH                                                   //~va0mR~
//**************************************************************** //~va0mI~
int erroptionforbinfile(char *Poption,int Prc);                    //~va0mR~
#endif                                                             //~va0mI~
#ifdef UTF8UCS2                                                    //~va20I~
//**************************************************************** //~va20I~
int errutf8andnonutf8(char *Poption,int Prc);                      //~va20I~
#endif                                                             //~va20I~
#ifdef UNX                                                         //~vaa0I~
//**************************************************************** //~vaa0I~
int errwildnamemultiple(int Popt,char *Pfname);                    //~vaa0I~
#endif                                                             //~vaa0I~
