//*CID://+vb49R~:                             update#=  555;       //+vb49R~
//*********************************************************************
//* xeutf2.h                                                       //~va20R~
//*********************************************************************
//vb49:160729 display copyword(Alt+W) for also editr panel if not ebc file//+vb49I~
//vb2Y:160405 by vb2U string remains on screen when split screen or exit xe if ligature mode ON//~vb2YI~
//vb2L:160314 (W32) display lang on top menu by ddfmt(for the case consolecp!=system cp,cpinfo is by system cp but display is by chcp code)//~vb2LI~
//vb2y:160212 save xelch utf8 for errmsg                           //~vb2yI~
//vb14:150613 0x00 is set for rename field display for U8-LC mixed string, set '.' for visibility//~vb14I~
//vawE:140613 (BUG)paste UTF8/EBC data to bin file,dd2l was done(lcmd copy or paste line dose not translate)//~vawEI~
//vawj:140605 (BUG:LNX)paste to rename fld;when l2f to katakana ct is 3 byte CTUTF8,it should be chked at l2fbyct//~vawjI~
//vawi:140603 (BUG)utf8 file pso2offs;offset may be 2 or 3 byte    //~vawiI~
//vawg:140603 exe cmd should use UD string for cmd from cpu8 file  //~vawgI~
//vaw1:140523 (Win:UNICODE)dbcsid:overflow for ucs4 on Windows     //~vaw1I~
//vafk:120624 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  use ULPTR(unsigned __int64/ULONG)//~vafkI~
//vaaq:111231 (BUG)errmsg attr:green(utf8) position shifted by l2f //~vaaqI~
//vaak:111229 (Bug)va5j: if traslated l2u for cmdline,coloumn pos changes. csrright will split local dbcs and rep to space.//~vaakI~
//va8f:101003 (BUG)lcmd "=" fail by tab compare(l2dd drop tab attr)//~va8fI~
//va5F:100521 dd2u nullrep option for wxe                          //~va5FI~
//va5j:100510 dispaly cmdline by dd fmt(more printable than locale code for Ctl+w(copy word to cmd lien).//~va5jI~
//va50:100324 Raw EBCDIC file support for NFS mount                //~va50I~
//va3x:100302 (LNX)UCS4 support                                    //~va3xI~
//va20:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~va20I~
#ifdef UTF8UCS2                                                    //~va20I~
                                                                   //~va20I~
#define CHAR_MAKEUCS    'U'     //by "u" key make 2 ascii to ucs   //~va20I~
//#ifdef UTF8UCS4                                                    //~va3xI~//~vaw1R~
#ifdef UTF8UCS416                                                  //~vaw1I~
	#define CHAR_MAKEUCS4   'V' //by "v" key make 3 ascii to ucs   //~va3xI~
#endif                                                             //~va3xI~
#define DBCSSPACE_UCS   0x3000	//japanese dbcs space              //~va20I~
                                                                   //~va20I~
#define PLHPOS2OFFS(opt,Pplh,pos)   xeutf_plhpos2offs(opt,Pplh,pos)//~va20R~
//#define XEUTF_PC2PCD(pcd0,pc,pc0) ((pcd0)+((ULONG)(pc)-(ULONG)(pc0)))//~va20I~//~vafkR~
#define XEUTF_PC2PCD(pcd0,pc,pc0) ((pcd0)+((ULPTR)(pc)-(ULPTR)(pc0)))//~vafkI~
#define XEUTF_PLHPC2PCD(plh,pc) XEUTF_PC2PCD((plh)->ULHdbcs,pc,(plh)->ULHdata)//~va20R~
//*********************************************************************//~va20I~
	int xeutf_getvhexpos(int Popt,PUCLIENTWE Ppcw,PULINEH Pplh,int Poffs,int *Ppdatapos,int *Ppdbcsid);//~va20R~
    #define XEUTFGVXOO_RECOFFS     0x01    //Poffs is not csr pos but recoffs//~va20I~
//*********************************************************************//~va20I~
	int xeutf_plhpos2offs(int Popt,PULINEH Pplh,int Ppos);         //~va20R~
//*********************************************************************//~va20I~
	int xeutf_chargetkbddd(int Popt,PUCLIENTWE Ppcw,UCHAR *Pdata,UCHAR *Pdbcs,int *Pplen);//~va20R~
//*********************************************************************//~va20I~
	int xeutf_chargetvhexdd(int Popt,int Pvhexmode,PUCLIENTWE Ppcw,PULINEH Pplh,int Precoffs,UCHAR *Pdata,UCHAR *Pdbcs,int *Pplen,int *Ppdatapos);//~va20R~
	#define XEUTF_VHEXRC_INSREP       0x01 //insert changed to rep because insert split ucs2//~va20I~
	#define XEUTF_VHEXRC_S2D          0x02 //rep SBCS to DBCS      //~va20I~
	#define XEUTF_VHEXRC_D2S          0x04 //rep DBCS to SBCS      //~va20I~
//#ifdef UTF8UCS4                                                    //~va3xI~//~vaw1R~
#ifdef UTF8UCS416                                                  //~vaw1I~
	#define XEUTF_VHEXRC_UCS4         0x08 //rep 3 byte on vhex line//~va3xI~
	#define XEUTF_VHEXRC_ERR_UCS4     0x80 //invalid ucs4(overflow)//~va3xI~
#endif                                                             //~va3xI~
	#define XEUTF_VHEXRC_ERR          0x40 //err                   //~va20I~
//*********************************************************************//~va20I~
	int xeutf_getvhexcsrpos(int Popt,int Pvhexpsdid,PUCLIENTWE Ppcw,PULINEH Pplh,int Pcsrpos,int *Ppdatapos,int *Pphexoffs);//~va20I~
    #define XEUTFGVXSPO_NEXT    0x01    //get next ucs offs when split//~vawiI~
//*********************************************************************//~va20I~
	int xeutf_getvhexcsrposdbcs(int Popt,		//lineid type      //~va20R~
							PUCLIENTWE Ppcw,                       //~va20I~
							PULINEH Pplh,   //data,dbcs,chof       //~va20I~
							int Pleft,       //left most column    //~va20I~
							int Ppos,        //csr pos from left side//~va20I~
							int *Ppcharpos1, //dataline pos        //~va20I~
							int *Ppcharpos2, //dataline pos for dbcs//~va20I~
							int *Pphexpos);  //hex line pos        //~va20I~
	int xeutf_getvhexcsrspan(int Popt,PUCLIENTWE Ppcw,PULINEH Pplh,int Pcsrpos1,int Pcsrpos2,int *Pphexoffs,int *Pphexspan);//~va20I~
	#define XEUTFGVXCSO_NEXT  0x01    //next when ucs split        //~vawiI~
//*********************************************************************//~va20I~
	int xeutf_getdataspan(int Popt,PUCLIENTWE Ppcw,PULINEH Pplh,int Ppos1,int Ppos2,int Pwidth,int *Pppos1,int *Pppos2);//~va20I~
    #define XEUTFGDSO_CSRPOSIN         0x01	//input  by csr pos    //~va20R~
    #define XEUTFGDSO_CSRPOSOUT        0x02	//output by csr pos    //~va20I~
//*********************************************************************//~va20I~
int xeutfgetddstr(int Popt,UCHAR *Pstr,int Pstrlen,UCHAR *Pddstr,int Pbuffsz,int *Ppddstrlen,UCHAR *Pdbcs);//~va20I~
#define XEUTFGDDS_SAVECT      0x01    //save utf8 str for errmsg   //~va50I~
//*********************************************************************//~va5jI~
int xeutfcvlf2dd(int Popt,UCHAR *Pstr,int Pstrlen,UCHAR *Pdbcs,UCHAR *Pcodetbl,int Plclen,//~va5jI~
					UCHAR **Ppdddata,UCHAR **Ppdddbcs,int Pbuffsz,int *Ppddstrlen);//~va5jR~
#define XEUTFLF2DO_PADDING  0x01   //keep column by padding for shrink by l2f//~vaakR~
#define XEUTFLF2DO_CHKLCLENBYF2L  0x02   //advance ct by the length of F2L outlen//~vawjI~
//*********************************************************************//~vaaqI~
int xeutfcvlf2dd_updatect(int Popt,UCHAR *Pstr,int Pstrlen,UCHAR *Pdbcs,UCHAR *Pcodetbl,int Plclen,//~vaaqI~
					UCHAR **Ppdddata,UCHAR **Ppdddbcs,int Pbuffsz,int *Ppddstrlen);//~vaaqI~
//*********************************************************************//~va20I~
int xeutfcvl2fdd(int Popt,UCHAR *Pstr,int Pstrlen,                 //~va20I~
					UCHAR *Poutu8,int Pu8buffsz,int *Ppu8len,      //~va20I~
					UCHAR *Poutdd,UCHAR *Pdbcs,int Pddbuffsz,int *Ppddlen);//~va20I~
//*********************************************************************//~va20I~
int xeutfcvl2dd(int Popt,UCHAR *Pdata,int Pdatalen,                //~va20I~
					UCHAR **Ppddstr,UCHAR **Ppdbcs,int *Ppddlen);  //~va20R~
#define XEUTFCVL2DDO_ERRREP      0x01  //rep by '.' if l2f err     //~vb14I~
//*********************************************************************//~vb2LI~
int xeutfcvl2dd_chcp(int Popt,UCHAR *Pdata,int Pdatalen,           //~vb2LR~
					UCHAR **Ppddstr,UCHAR **Ppdbcs,int *Ppddlen);  //~vb2LI~
//*********************************************************************//~va8fI~
int xeutfcvl2ddtab(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Pdatalen,//~va8fI~
					UCHAR **Ppddstr,UCHAR **Ppdbcs,int *Ppddlen);  //~va8fI~
//*********************************************************************//~va20I~
int xeutfcvdd2fl(int Popt,PUCLIENTWE Ppcw,UCHAR *Pdata,UCHAR *Pdbcs,int Pdatalen,//~va20R~
				UCHAR *Poutu8,int Pu8buffsz,int *Ppoutu8len,       //~va20I~
				UCHAR *Poutlc,UCHAR *Poutdbcs,UCHAR *Poutct,int Plcbuffsz,int *Ppoutlclen);//~va20R~
#define XEUTFDD2FLO_U8ERRMSG      0x01 //register utf8 code for errmsg//~va20I~
//*********************************************************************//~va20I~
int xeutfcvf2ldd(int Popt,PUCLIENTWE Ppcw,UCHAR *Pu8,int Pu8len,   //~va20I~
				UCHAR *Poutdd,UCHAR *Pdbcs,int Pddbuffsz,int *Ppoutddlen,//~va20I~
				UCHAR *Poutlc,UCHAR *Poutct,int Plcbuffsz,int *Ppoutlclen);//~va20I~
//*********************************************************************//~va20I~
int xeutfcvdd2l(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Pdatalen,   //~va20I~
					UCHAR **Pplcstr,int *Pplclen);                 //~va20I~
#define XEUTFDD2LO_CRLF          0x01 //malloc more 2 byte for crlf padding//~va20R~
#define XEUTFDD2LO_ERRRET        0x02 //return if cv err           //~va20I~
//*********************************************************************//~va20I~
int xeutfcvdd2ldbcs(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Pdatalen,//~va20I~
					UCHAR **Pplcstr,UCHAR **Ppdbcs,int *Pplclen);  //~va20I~
//*********************************************************************//~va20I~
int xeutfcvdd2f(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Pdatalen,UCHAR **Ppu8,int *Pu8len,UCHAR **Ppoutdbcs);//~va20R~
#define XEUTFDD2FO_OPTMASK       0xff00 //replace err char         //~va20R~
#define XEUTFDD2FO_SETDBCSTBL    0x0001 //setdbcstbl as bin file   //~vawER~
#define XEUTFDD2FO_OUTSTRZ       0x0002 //setdbcstbl as bin file   //+vb49I~
//*********************************************************************//~va20I~
int xeutf_dd2syn(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Pdatalen,UCHAR **Psyndata);//~va20R~
//*********************************************************************//~va20I~
int xeutfcvdd2u(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Pdatalen,WUCS **Ppucs,int *Ppucslen);//~va20I~
#define XEUTFDD2UO_NULLREP      0x01  //rep null to errch          //~va5FI~
//*********************************************************************//~va20I~
int xeutfcvu2dd(int Popt,WUCS *Pucs,int Plen,char **Ppdata,char **Ppdbcs,int *Ppoutlen);//~va20I~
//*********************************************************************//~va20I~
int xeutf_cvf2dd(int Popt,char *Pinp,int Pinplen,UCHAR **Ppout,UCHAR **Ppdbcs,int *Ppoutlen);//~va20I~//~va50R~
//*********************************************************************//~va3xI~
//#ifdef UTF8UCS4                                                    //~va3xI~//~vaw1R~
#ifdef UTF8UCS416                                                  //~vaw1I~
  #ifdef UTF8UTF16                                                 //~vaw1I~
	int xeutfddwidth4(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,UWUCS *Pucs,int *Ppwidth);//~vaw1I~
  #else                                                            //~vaw1I~
	int xeutfddwidth4(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,PWUCS Pucs,int *Ppwidth);//~va3xR~
  #endif                                                           //~vaw1I~
//*********************************************************************//~va3xI~
#ifdef UTF8UTF16                                                   //~vaw1I~
	int xeutf_charmakeucsvhexdd(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Plen,UWUCS *Ppucs);//~vaw1I~
#else                                                              //~vaw1I~
	int xeutf_charmakeucsvhexdd(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Plen,WUCS *Ppucs);//~va3xI~
#endif                                                             //~vaw1I~
	#define  XEUTFCMUVXDO_UCS4       0x01                          //~va3xI~
#endif	//UTF8UCS2                                                 //~va3xR~
//*********************************************************************//~va3xI~
#endif                                                             //~va20I~
#ifdef W32UNICODE                                                  //~vawgI~
int xeutfcvDD2UD(int Popt,UCHAR *Pdddata,UCHAR *Pdddbcs,int Pddlen,int Pbuffsz,UCHAR **Ppoutbuff,int *Ppoutlen);//~vawgR~
#endif                                                             //~vawgI~
//*********************************************************************//~vb2yI~
int xeutf_cvf2ddct(int Popt,char *Pinp,int Pinplen,UCHAR **Ppout,UCHAR **Ppdbcs,UCHAR **Ppct,int *Ppoutlen);//~vb2yR~
//*********************************************************************//~vb2YI~
int xeutfcvlchcp(int Popt,UCHAR *Pdata,int Pdatalen,UCHAR **Ppdata,UCHAR **Ppdbcs,int *Pplen);//~vb2YI~
