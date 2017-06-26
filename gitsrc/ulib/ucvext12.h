//*CID://+v6BjR~:                             update#=  215;       //~v6BjR~
//******************************************************           //~v69dI~
//v6Bj:160213 (W32:BUG)UCS4 was cut to UCS2                        //~v6BjI~
//v6x5:150108 ULONG 64 bit for LNX,32 bit for WIN on 64bit cpu     //~v6x5I~
//******************************************************           //~v69dI~
//*ucvext12.h                                                      //~v69dI~
//******************************************************           //~v69dI~
typedef UINT (*ICUFUNC_TOUCS)(UConverter *Pcnv,USHORT *Pdest,UINT Pdestlen,char *Psrc,UINT Psrclen,UErrorCode *PerrorCode);
typedef UINT (*ICUFUNC_FROMUCS)(UConverter *Pcnv,char *Pdest,UINT Pdestlen,USHORT *Psrc,UINT Psrclen,UErrorCode *pErrorCode);
//*******************************************************          //~v69dI~
#define SPFNUMFLDLEN 8                                             //~v5mWI~
//*******************************************************          //~v69dI~
int ucvext12_init(int Popt,int Pextflag,PUCVEXTCFG Ppcfg,void **Pfuncs);//~v69dI~
//*******************************************************          //~v69dI~
char *ucvext_icuuerrname(UErrorCode Puerr);                        //~0815R~
//**************************************************************************//~0815I~
//int ucvext_icuucs2local1(int Popt,ULPTR Pconverter,USHORT Pucs,UCHAR *Ppmbs,int *Ppoutlen);//~v6x5R~//+v6BjR~
int ucvext_icuucs2local1(int Popt,ULPTR Pconverter,UWUCS Pucs,UCHAR *Ppmbs,int *Ppoutlen);//+v6BjI~
//**************************************************************************//~v6x5I~
#ifdef UTF8UCS4                                                    //~v6x5I~
int ucvext_iculocal2ucs1(int Popt,ULPTR Pconverter,char *Ppmbs,int Pinplen,int *Ppchklen,WUCS *Ppucs);//~v6x5R~
#else                                                              //~v6x5I~
//int ucvext_iculocal2ucs1(int Popt,ULPTR Pconverter,char *Ppmbs,int Pinplen,int *Ppchklen,USHORT *Ppucs);//~v6x5R~//~v6BjR~
int ucvext_iculocal2ucs1(int Popt,ULPTR Pconverter,char *Ppmbs,int Pinplen,int *Ppchklen,UWUCS *Ppucs);//~v6BjI~
#endif                                                             //~v6x5I~
