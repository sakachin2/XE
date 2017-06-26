//*CID://+v6EqR~:                             update#=   57;       //+v6EqR~
//******************************************************
//v6Eq:160812 lineopt should be cleared by USDFNCELL               //+v6EqI~
//v6Ep:160812 (WXE)errmsg lineopt;strput called intermediate of errmsg string by attr change,it should not Col but msg len//~v6EpI~
//v6Eo:160811 (XXE)v6ei for XXE(specify ligature on/off,combine on/of line by line(used for edit/filename  panel)//~v6EoI~
//v6Ei:160802 (XE:vb4f)specify ligature on/off,combine on/of line by line(used for edit/filename  panel)//~v6EiI~
//v65m:100329 to print 0x14 glyph(q:0xb6),use another altchar(0xff)//~v65mI~
//v640:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~v640I~
//v62B:091003_(WIN)print width of 0x80->0x9f is 0.5 when cp is iso8859//~v62BI~
//v5n8:080916 (CJK)IME support for CJK other than Japanese         //~v5n8I~
//v5m7:080204 move internal function to header                     //~v5m7I~
//v5g6:050613 (XXE)xxe support                                     //~v570I~
//v570:020824 wxe support                                          //~v570I~
//v534:020315 (WIN/AIX)screen width parameter support              //~v534I~
//v531:020309 (WIN)screen height parameter support                 //~v531I~
//v50X:011202 force nt option for vio                              //~v50XI~
//v40p:001130 AIX support:chtype format different(char is last 2 byte)//~v40pI~
//v343:000924 LINUX support(PALNO_xx move from xe.h uvio.h for uviol)//~v343I~
//v324 000813:LINUX support(CRLF)                                  //~v324I~
//v145:980116 (W32)performance reason                              //~v145I~
//            -uvio_w95wrtcharstratt3 (2 part attr at once)        //~v145I~
//v144:980116 (W32)WINNT support                                   //~v144I~
//            -USDCELLSTR2 type support for cell write required case//~v144I~
//				uvio_w95wrtcharstratt2                             //~v144I~
//v044:961106:too large for XEDOS,split uvio.c to uvio2.c          //~v044I~
//v043:961104:(W95)write attr string function support              //~v043I~
//v042:961102:(W95)write all line to screen by one api issue for performance//~v042I~
//v022:960727:WIN32(CONSOLE api)                                   //~v022I~
//******************************************************           //~v022I~
#define UVIO_ERRREP   '.'                                          //~v5n8I~
#define UVIO_ERRREP2  '?'     //for sbcs >=x80'                    //~v62BI~
//#ifdef WXE                                                       //~v570R~
#ifdef WXEXXE                                                      //~v570I~
	#define UVIO_TEXTDATA(row,col) (Sw95buffc+(row)*Sscrwidth+(col))//~v570I~
	#define UVIO_ATTRDATA(row,col) (Sw95buffa+(row)*Sscrwidth+(col))//~v570I~
	#define UVIO_LINEUPDATE(row)   *(Swxelineupdate+row)='1';      //~v570I~
#endif                                                             //~v570I~
                                                                   //~v6EiI~
#ifdef DOS                                                         //~v044M~
	#define INT10(Ah)	Sreg.h.ah=Ah;		/*function*/	\
						int86(0x10,&Sreg,&Sreg);                   //~v044M~
	#define INT10X(Ah)	Sreg.h.ah=Ah;		/*function*/	\
						int86x(0x10,&Sreg,&Sreg,&Ssegreg);         //~v044M~
#endif                                                             //~v044M~
//* define same structure as OS/2
//*palleteno                                                       //~v343M~
#define PALNO_BLACK     0                                          //~v343M~
#define PALNO_B         1                                          //~v343M~
#define PALNO_G         2                                          //~v343M~
#define PALNO_GB        3                                          //~v343M~
#define PALNO_MMK       3   //MMK(fep) use                         //~v343M~
#define PALNO_R         4                                          //~v343M~
#define PALNO_RB        5                                          //~v343M~
#define PALNO_RG        6   //default color reg assignment:20(brown)//~v343M~
#define PALNO_RGB       7                                          //~v343M~
#define PALNO_HBLACK    8   //56(gray)                             //~v343M~
#define PALNO_HB        9   //57(light blue)                       //~v343M~
#define PALNO_HG       10   //58(light green)                      //~v343M~
#define PALNO_HGB      11   //59(light water blue)                 //~v343M~
#define PALNO_HR       12   //60(light red)                        //~v343M~
#define PALNO_HRB      13   //61(light purple)                     //~v343M~
#define PALNO_HRG      14   //62(light yellow)                     //~v343M~
#define PALNO_HRGB     15   //63(high white)                       //~v343M~
                                                                   //~v343M~
//#ifdef DOS	                                                   //~6728R~
#if defined(DOS) || defined(W32)  || defined(UNX)  //dos or win23  //~v324R~
//****************************************************
#define ERROR_VIO_INVALID_PARMS 	421     /* MSG%VIO_INVALID_PARMS */
#define ERROR_VIO_INVALID_LENGTH    438     /* MSG%VIO_INVALID_LENGTH*/
#define ERROR_VIO_EXTENDED_SG   	494     /* MSG%VIO_EXTENDED_SG */
//****************************************************             //~v343I~
#define HIGHLIGHT_BG   0x80           //0x80 for reverse when mono-color//~v40pR~
#define HIGHLIGHT_FG   0x08         		//0x08 for highlight         //~v40pR~
//****************************************************
   /* VIOMODEINFO.color constants */

   #define COLORS_2        0x0001
   #define COLORS_4        0x0002
   #define COLORS_16       0x0004
   /* fbType */	
   #define VGMT_OTHER                 0x01
   #define VGMT_GRAPHICS              0x02
   #define VGMT_DISABLEBURST          0x04

   typedef  struct _VIOMODEINFO     /* viomi */
   {
      USHORT cb;
      UCHAR  fbType;			//text or graphic
      UCHAR  color;
      USHORT col;
      USHORT row;
      USHORT hres;				//not supported under dos
      USHORT vres;				//height of char(DOS 40:85)*row if under dos//~v044R~
      UCHAR  fmt_ID;			//dispaly mode  under dos
      UCHAR  attrib;			//uvsetmode use this under dos
      ULONG  buf_addr;			//not supported under dos
      ULONG  buf_length;		//not supported under dos
      ULONG  full_length;		//not supported under dos
      ULONG  partial_length;	//not supported under dos
      PCH    ext_data_addr;		//not supported under dos
   } VIOMODEINFO;
   typedef VIOMODEINFO *PVIOMODEINFO;

   typedef struct _VIOCURSORINFO   /* vioci */
   {
      USHORT   yStart;          //W95:size                         //~v022R~
      USHORT   cEnd;
      USHORT   cx;				//not supported under dos(width)   //~v022R~
      USHORT   attr;			//not supported under dos          //~v022R~
                                //OS/2,W95 0:normal,-1:hidden      //~v022R~
   } VIOCURSORINFO;

   typedef VIOCURSORINFO *PVIOCURSORINFO;

//*for VioGetState/VioSetState **********
   typedef struct _VIOPALSTATE     /* viopal */
   {
      USHORT  cb;
      USHORT  type;
      USHORT  iFirst;
      USHORT  acolor[1];
   } VIOPALSTATE;
   typedef VIOPALSTATE *PVIOPALSTATE;

   typedef struct _VIOOVERSCAN     /* vioos */
   {
      USHORT  cb;
      USHORT  type;
      USHORT  color;
   } VIOOVERSCAN;
   typedef VIOOVERSCAN *PVIOOVERSCAN;

   typedef struct _VIOINTENSITY    /* vioint */
   {
      USHORT  cb;
      USHORT  type;
      USHORT  fs;		//0:brink  1:background hilight
   } VIOINTENSITY;
   typedef VIOINTENSITY *PVIOINTENSITY;

//******************************************************
#ifdef DOS                                                         //~v022I~
    #ifdef DPMI					//DPMI version                     //~v044I~
    #else                       //not DPMI                         //~v044I~
int _CDECL uvintbp(int, union REGS *, union REGS *, struct SREGS *);
    #endif                      //DPMI or not                      //~v044I~
#endif                                                             //~v022I~

#endif

//#ifdef W32                                                       //~v570R~
#ifdef W32XXE                                                      //~v570R~
//*******************************************************          //~v042I~
void uvio_w95buffmode(int Pbuffmode);                              //~v042R~
                                                                   //~v042I~
//*******************************************************          //~v042I~
//int  uvio_w95buffwrite(int Prow,int Pcol,int Pctr);              //~v6EiR~
int  uvio_w95buffwrite(int Popt,int Prow,int Pcol,int Pctr);       //~v6EiI~
                                                                   //~v042I~
#endif                                                             //~v570M~
#ifdef W32                                                         //~v570M~
//*******************************************************          //~v144I~
//UINT uvio_w95wrtcharstratt2(int Prow,int Pcol,int Plen,PCH Pchstr,USHORT *Pattstr);//~v6EiR~
UINT uvio_w95wrtcharstratt2(int Popt,int Prow,int Pcol,int Plen,PCH Pchstr,USHORT *Pattstr);//~v6EiI~
                                                                   //~v145I~
//*******************************************************          //~v145I~
//UINT uvio_w95wrtcharstratt3(int Prow,int Pcol,PCH Pchstr,        //~v6EiR~
UINT uvio_w95wrtcharstratt3(int Popt,int Prow,int Pcol,PCH Pchstr, //~v6EiI~
                    int Plen1,UCHAR Pattr1,int Plen2,UCHAR Pattr2);//~v145R~
                                                                   //~v144I~
//*******************************************************          //~v145I~
void uvio_w95resetconsole(void);                                   //~v145I~
                                                                   //~v145I~
#endif                                                             //~v022I~
                                                                   //~v531I~
//*******************************************************
UINT uviogetmode(PVIOMODEINFO PvioModeInfo);
                                                                   //~v531I~
//*******************************************************
UINT uviosetmode (PVIOMODEINFO pvioModeInfo);
                                                                   //~v531I~
//*******************************************************
UINT uvioreadcellstr(PCH pchCellStr,int *Pplen,int Prow,int Pcol);
                                                                   //~v531I~
//*******************************************************
//UINT uviowrtcellstr (PCH pchCellStr,int Plen,int Prow,int Pcol); //~v6EiR~
UINT uviowrtcellstr (int Popt,PCH pchCellStr,int Plen,int Prow,int Pcol);//~v6EiI~
                                                                   //~v531I~
//*******************************************************
UINT uvioreadcharstr(PCH pchStr,int *Pplen,int Prow,int Pcol);
                                                                   //~v043I~
#ifdef W32                                                         //~v043I~
//*******************************************************          //~v043I~
UINT uviowrtattrstr(USHORT *Pattr,int Plen,int Prow,int Pcol);     //~v043R~
                                                                   //~v50XI~
void uvio_winopt(int Popt);                                        //~v50XI~
#define UVIOWINFORCENT		1	//force cell mode                  //~v50XI~
                                                                   //~v5n8I~
//*******************************************************          //~v5n8I~
UINT uviowrtucsstr(WUCS *Ppucs,int Plen,int Prow,int Pcol);        //~v5n8R~
                                                                   //~v5n8I~
#endif                                                             //~v043I~
                                                                   //~v043I~
//*******************************************************
//UINT uviowrtcharstr(PCH pchStr,int Plen,int Prow,int Pcol);      //~v6EiR~
UINT uviowrtcharstr(int Popt,PCH pchStr,int Plen,int Prow,int Pcol);//~v6EiI~
                                                                   //~v531I~
//*******************************************************
//UINT uviowrtcharstratt(PCH pch,int Plen,int Prow,int Pcol,PBYTE pAttr);//~v6EiR~
UINT uviowrtcharstratt(int Popt,PCH pch,int Plen,int Prow,int Pcol,PBYTE pAttr);//~v6EiI~
                                                                   //~v531I~
//*******************************************************
UINT uviowrtnattr (PBYTE pAttr,int Plen,int Prow,int Pcol);
                                                                   //~v531I~
//*******************************************************
//UINT uviowrtncell(PBYTE pCell,int Plen,int Prow,int Pcol);       //+v6EqR~
UINT uviowrtncell(int Popt,PBYTE pCell,int Plen,int Prow,int Pcol);//+v6EqI~
                                                                   //~v531I~
//*******************************************************
UINT uviowrtnchar(PCH pchChar,int Plen,int Prow,int Pcol);
                                                                   //~v144I~
//*******************************************************          //~v531I~
//void uvio_initparm(int Pheight,int Pwidth);                      //~v534R~
void uvio_initparm(int *Pscrparm);                                 //~v534I~
//*******************************************************          //~v5n8I~
#ifdef WCSUPP                                                      //~v5n8I~
//*******************************************************          //~v5n8I~
	void uvio_init2(int Popt,UCHAR *Pdbcstbl);                     //~v5n8R~
//*******************************************************          //~v5n8I~
	int uvio_wcinit(int Popt/*udbcschk_wcinit Popt*/,ULONG Pcodepage);//~v5n8R~
//*******************************************************          //~v5n8I~
//    int uvio_m2us(int Popt,UCHAR *Ppmbs,int Plen,UCHAR *Ppdbcs,WUCS *Ppucs,int Poutbuffsz,int *Poutucsctr);//~v5n8I~//~v65mR~
//    int uvio_m2u(int Popt,UCHAR *Ppmbs,int Plen,USHORT *Ppucs,int *Ppchklen);//~v5n8R~//~v65mR~
//    #define UVIOM2UO_DBCS     0x01   //source is dbcs              //~v5n8I~//~v65mR~
//#ifdef UTF8UCS2                                                    //~v640I~//~v65mR~
//    #define UVIOM2UO_DDSTR    0x02  //source data/dbcs is ucs      //~v640I~//~v65mR~
//    #define UVIOM2UO_MBCS     0x04  //source data is locale str    //~v640I~//~v65mR~
//#endif                                                             //~v640M~//~v65mR~
#endif	//WCSUPP                                                   //~v5n8I~
//#ifdef W32                                                       //~v6EoR~
#if defined(W32) || defined(XXE)                                   //~v6EoI~
//*******************************************************          //~v6EiI~
//int uvio_getbufflineopt(int Popt,int Prow,int Plineopt);         //~v6EpR~
int uvio_getbufflineopt(int Popt,int Prow,int Plineopt,int Pcol);  //~v6EpI~
#define  UVGBLOO_TGTTOP    0x01   //need to subtract Stoplineoffs  //~v6EiI~
//*******************************************************          //~v6EiI~
//int uvio_setbufflineopt(int Popt,int Prow,int Plineopt);         //~v6EpR~
int uvio_setbufflineopt(int Popt,int Prow,int Plineopt,int Pcol,int Plen);//~v6EpR~
#endif //W32                                                       //~v6EiI~
