//*CID://+v6BjR~:                             update#=  135;       //~v6BjR~
//******************************************************           //~v5mTI~
//v6Bj:160213 (W32:BUG)UCS4 was cut to UCS2                        //~v6BjI~
//v6x5:150108 (warning C4244)ULONG 64 bit for LNX,32 bit for WIN on 64bit cpu,pointr is 64bit for both LNX and WIN.//~v6x5I~
//v6uM:140606 (LNX:BUG)F2L/U2L trans 0xff>=.. 0x=>80 to hankaku katakana is iconv BUG?,back trans is ffxx for han-kana//~v6uMI~
//v6k4:130525 (Win)Jnction(from xp) and Symlink(from Vista)        //~v6k4I~
//v6hh:120623 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  defines ULPTR(unsigned long long)//~v6hhI~
//v692:100730 (BUG of ucs4 support) USHORT remaining for ucs       //~v692I~
//            ebc2ucs may be ok by USHORT ucs(icu def is USHORT),but change it.//~v692I~
//v692:100730 (BUG of ucs4 support) USHORT remaining for ucs       //~v692I~
//v5n8:080916 (CJK)IME support for CJK other than Japanese         //~v5n8I~
//v5n3:080904 cv cmd m2m support                                   //~v5n3I~
//v5n1:080822 (EBC)offer translation by Windows API MultiByteToWideChar//~v5n1I~
//v5mT:080817 EBCS translation for linux using iconv               //~v5mTI~
//******************************************************           //~v5mTI~
//*ucvext2.h                                                       //~v5mTR~
//******************************************************           //~v5mTI~
//#ifdef LNX                                                       //~v5n1R~
#ifdef WCSUPP                                                      //~v5n1I~
//******************************************************           //~v5mTI~
int ucvext_iconvmapinit(int Popt,int Pextflg,PUCVEXTCFG Ppcfg);    //~v5mTR~
//******************************************************           //~v5mTI~
//int ucvext_iconvgetstarter(int Popt,ULONG Pconverter,UCHAR *Pflags,UCHAR *Ppleadbyte);//~v6x5R~
int ucvext_iconvgetstarter(int Popt,ULPTR Pconverter,UCHAR *Pflags,UCHAR *Ppleadbyte);//~v6x5I~
//******************************************************           //~v5mTI~
//int ucvext_iconvgetconverter(int Popt,UCHAR *Pcharset,ULONG *Ppconverter);//~v5mTI~//~v6hhR~
int ucvext_iconvgetconverter(int Popt,UCHAR *Pcharset,ULPTR *Ppconverter);//~v6hhI~
//******************************************************           //~v5n1I~
//int ucvext_iconvgetconvertertype(int Popt,ULONG Pconverter,int *Pptype);//~v6x5R~
int ucvext_iconvgetconvertertype(int Popt,ULPTR Pconverter,int *Pptype);//~v6x5I~
//******************************************************           //~v5mTI~
//int ucvext_iconvebc2ucs1(int Popt,ULONG Pconverter,char *Ppebc,int Pinplen,USHORT *Ppucs);//~v5n8R~
//int ucvext_iconvebc2ucs1(int Popt,ULONG Pconverter,char *Ppebc,int Pinplen,WUCS *Ppucs);//~v6x5R~
//int ucvext_iconvebc2ucs1(int Popt,ULPTR Pconverter,char *Ppebc,int Pinplen,WUCS *Ppucs);//~v6x5I~//~v6BjR~
int ucvext_iconvebc2ucs1(int Popt,ULPTR Pconverter,char *Ppebc,int Pinplen,UWUCS *Ppucs);//~v6BjI~
//******************************************************           //~v5mTI~
//int ucvext_iconvucs2ebc1(int Popt,ULONG Pconverter,USHORT Pucs,UCHAR *Ppebc,int *Ppoutlen);//~v5mTI~//~v692R~
//int ucvext_iconvucs2ebc1(int Popt,ULONG Pconverter,WUCS Pucs,UCHAR *Ppebc,int *Ppoutlen);//~v6x5R~
//int ucvext_iconvucs2ebc1(int Popt,ULPTR Pconverter,WUCS Pucs,UCHAR *Ppebc,int *Ppoutlen);//~v6x5I~//+v6BjR~
int ucvext_iconvucs2ebc1(int Popt,ULPTR Pconverter,UWUCS Pucs,UCHAR *Ppebc,int *Ppoutlen);//+v6BjI~
//******************************************************           //~v5mTI~
//int ucvext_iconva2acont(ULONG *Pconverters,UCVUCS_FREAD *Pfread,UCVUCS_FWRITE *Pfwrite,UCVUCS_FERR *Pferr,//~v5n3M~//~v6hhR~
int ucvext_iconva2acont(ULPTR *Pconverters,UCVUCS_FREAD *Pfread,UCVUCS_FWRITE *Pfwrite,UCVUCS_FERR *Pferr,//~v6hhI~
			 ULONG Popt,UCHAR *Pibuff,int Pibuffsz,UCHAR *Pobuff,int Pobuffsz,int Perrrep);//~v5n3M~
//******************************************************           //~v5n3I~
//int ucvext_iconvgetparmconverter(int Popt,char *Pcpfrom,char *Pcpto,ULONG *Ppconverters);//~v5n3I~//~v6hhR~
int ucvext_iconvgetparmconverter(int Popt,char *Pcpfrom,char *Pcpto,ULPTR *Ppconverters);//~v6hhI~
#endif                                                             //~v5mTI~
#ifdef W32                                                         //~v6k4I~
int ucvext_winucs2cp(int Popt,ULONG Pconverter,USHORT *Ppucs,int Pucsctr,UCHAR *Ppmbs,int Pbuffsz,int *Ppoutlen);//~v6k4I~
#endif                                                             //~v6k4I~
