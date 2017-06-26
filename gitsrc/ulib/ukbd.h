//CID://+v6BeR~:    update#=     1                                 //+v6BeR~
//******************************************************
// ukbd.h                                                          //~v592R~
//******************************************************        //~5104I~
//v6Be:160207 utf8 char input emulation                            //~v6BeI~
//v65d:100311 RAW unicode input(ucs2local fail but accept it when env is utf8)//~v65dI~
//v62U:091030_GB18030 merge                                        //~v62UI~
//v620:090506 merge UTF8 version                                   //~v620I~
//v5n8:080916 (CJK)IME support for CJK other than Japanese         //~v5n8I~
//v592:030928 (LNX)mouse support                                   //~v592I~
//v324 000813:LINUX support                                        //~v324I~
//v137:980110 (W32)split ukbdw.c from ubd ukbd.c                   //~v137I~
//v034:961008:VisualC++ support(identify by (_MSC_VER>=800))       //~v034I~
//v022:960727:WIN32(CONSOLE api)                                   //~v022I~
//******************************************************           //~v022I~
//* define same structure as OS/2
#if defined(DOS) || defined(W32) || defined(UNX)                   //~v324R~
//******************************************************
   #define IO_WAIT                    0                         //~5104I~
   #define IO_NOWAIT                  1                         //~5104I~
                                                                //~5104I~
   /* KBDTRANS.fbStatus */                                      //~5110I~
                                                                //~5110I~
   #define KBDTRF_SHIFT_KEY_IN             0x01                 //~5110I~
   #define KBDTRF_CONVERSION_REQUEST       0x20                 //~5110I~
   #define KBDTRF_FINAL_CHAR_IN            0x40                 //~5110I~
   #define KBDTRF_INTERIM_CHAR_IN          0x80                 //~5110I~
                                                                //~5110I~
   /* KBDINFO.fsMask */                                         //~5104I~
                                                                //~5104I~
   #define KEYBOARD_ECHO_ON                0x0001               //~5104I~
   #define KEYBOARD_ECHO_OFF               0x0002               //~5104I~
   #define KEYBOARD_BINARY_MODE            0x0004               //~5104I~
   #define KEYBOARD_ASCII_MODE             0x0008               //~5104I~
   #define KEYBOARD_MODIFY_STATE           0x0010               //~5104I~
   #define KEYBOARD_MODIFY_INTERIM         0x0020               //~5104I~
   #define KEYBOARD_MODIFY_TURNAROUND      0x0040               //~5104I~
   #define KEYBOARD_2B_TURNAROUND          0x0080               //~5104I~
   #define KEYBOARD_SHIFT_REPORT           0x0100               //~5104I~
                                                                //~5104I~
      /* KBDINFO.fsState/KBDKEYINFO.fsState/KBDTRANS.fsState */ //~5104I~
      #define KBDSTF_RIGHTSHIFT               0x0001            //~5104I~
      #define KBDSTF_LEFTSHIFT                0x0002            //~5104I~
      #define KBDSTF_CONTROL                  0x0004            //~5104I~
      #define KBDSTF_ALT                      0x0008            //~5104I~
      #define KBDSTF_SCROLLLOCK_ON            0x0010            //~5104I~
      #define KBDSTF_NUMLOCK_ON               0x0020            //~5104I~
      #define KBDSTF_CAPSLOCK_ON              0x0040            //~5104I~
      #define KBDSTF_INSERT_ON                0x0080            //~5104I~
      #define KBDSTF_LEFTCONTROL              0x0100            //~5104I~
      #define KBDSTF_LEFTALT                  0x0200            //~5104I~
      #define KBDSTF_RIGHTCONTROL             0x0400            //~5104I~
      #define KBDSTF_RIGHTALT                 0x0800            //~5104I~
      #define KBDSTF_SCROLLLOCK               0x1000            //~5104I~
      #define KBDSTF_NUMLOCK                  0x2000            //~5104I~
      #define KBDSTF_CAPSLOCK                 0x4000            //~5104I~
      #define KBDSTF_SYSREQ                   0x8000            //~5104I~
                                                                //~5104I~
   typedef  struct _KBDKEYINFO      /* kbci */
   {
      UCHAR    chChar;
      UCHAR    chScan;
#define KBDSCAN_IMECHAR   0x00      //ime char ID                  //~v5n8I~
      UCHAR    fbStatus;			//no support under dos
      UCHAR    bNlsShift;
#define KBDNLS_UNICODE    0x01      //unicode by ReadConsoleInputW;Char:Low,Scan:High//~v5n8R~
#define KBDNLS_F2L_DBCS1ST    0x02      //DBCS1ST byte was read for utf8 kbd env//~v5n8R~
#define KBDNLS_F2L_DBCS2ND    0x04      //DBCS2ND byte was read for UTF8 kbd env//~v5n8I~
#define KBDNLS_F2L_SBCS       0x08      //SBCS    byte was read for UTF8 kbd env//~v5n8I~
//#define KBDNLS_F2L (KBDNLS_F2L_SBCS|KBDNLS_F2L_DBCS1ST|KBDNLS_F2L_DBCS2ND)//~v5n8I~//~v65dR~
#define KBDNLS_F2L (KBDNLS_F2L_SBCS|KBDNLS_F2L_DBCS1ST|KBDNLS_F2L_DBCS2ND|KBDNLS_F2L_ERR)//~v65dI~
#define KBDNLS_SS3            0x10      //mbstr contains EUC SS3 str//~v62UR~
#define KBDNLS_GB4            0x20      //mbstr contains GB18030 4byte dbcs//~v62UR~
#define KBDNLS_DBCS           0x40      //locale dbcs 2/3/4 byte   //~v62UR~
#define KBDNLS_F2L_ERR        0x80      //UTF->LOCALE conversion failed//~v65dI~
      USHORT   fsState;
#ifdef LNX                                                         //~v592I~
      UCHAR    chMouseposx;         //mouse position               //~v592I~
      UCHAR    chMouseposy;         //mouse position               //~v592I~
#endif                                                             //~v592I~
#ifdef UTF8SUPPH                                                   //~v620I~
#ifdef WCSUPP                                                      //~v620I~
      UCHAR    u8str[UTF8_MAXCHARSZMAX+1];                         //~v620I~
      UCHAR    mbstr[MAX_MBCSLENLC];                               //~v62UR~
#endif                                                             //~v620I~
#endif                                                             //~v620I~
      ULONG    time;				//no support under dos
   }KBDKEYINFO;
   typedef KBDKEYINFO *PKBDKEYINFO;

   /* KBDINFO structure, for KbdSet/GetStatus */                //~5104I~
   typedef struct _KBDINFO         /* kbst */                   //~5104I~
   {                                                            //~5104I~
      USHORT cb;                                                //~5104I~
      USHORT fsMask;                                            //~5104I~
      USHORT chTurnAround;                                      //~5104I~
      USHORT fsInterim;                                         //~5104I~
      USHORT fsState;                                           //~5104I~
   }KBDINFO;                                                    //~5104I~
   typedef KBDINFO *PKBDINFO;                                   //~5104I~
                                                                //~5104I~
//******************************************************
	#ifdef W32                                                     //~v022I~
	#else                                                          //~v022I~
	#ifdef UNX                                                     //~v324R~
	#else                                                          //~v324I~
#define FLAGZF		0x40
int _CDECL ukintf(union REGS *, union REGS *);
	#endif                                                         //~v022I~
	#endif                                                         //~v324I~

#endif
//**************************************************
int ukbdpeek(PKBDKEYINFO Pkeyinfo);
//**************************************************
int ukbdcharin(KBDKEYINFO *Pkeyinfo,int Pwait);
//**************************************************
int ukbdsetrate(int Pdelay,int Pspeed);
//**************************************************            //~5104I~
int ukbdsetstatus(PKBDINFO Ppkbdinfo);                          //~5104R~
//**************************************************               //~v034I~
void ukbd_traceinit(int Popt);                                     //~v137R~
#ifdef WCSUPP                                                      //~v5n8R~
	int ukbd_wcinit(int Popt/*udbcschk_wcinit Popt*/,ULONG Pcodepage);//~v5n8R~
	int ukbd_u2m(int Popt,USHORT Pucs,UCHAR *Ppmbs,int *Ppoutlen); //~v5n8I~
#endif                                                             //~v5n8I~
//**************************************************               //~v6BeM~
int ukbd_simutf8_f2l(int Popt,char *Putf8,int Plen,char *Ppout,int Pbuffsz,int *Ppoutlen);//~v6BeI~
#define UKSF2LO_ERRREPCH        0xff //errrep char mask            //~v6BeI~
