//*CID://+vb4bR~:                             update#= 44;         //+vb4bR~
//*********************************************************************//~4325I~
//* xeutf.h                                                        //~4325I~
//*********************************************************************//~4325I~
//vb4b:160729 (BUG) err msg "Invalid FileNAme Format" when saved cmd stack contains UD format char(0x01 etc)//+vb4bI~
//vaww:140611 (W32UNICODE:BUG)retrive of 2 opd cmd,2nd displayed as dbcs//~vawwI~
//vawv:140610 (W32UNICODE)for ftp,enclose utf8 membname on UDHname //~vawvI~
//vavQ:140405 set parsed cmdlc(for xprint dcmd u8filename)         //~vavQI~
//vavF:140401 (W32UNICODE)green pos on renamefld(utf ascii mix)    //~vavFI~
//vavn:140425 (BUG of vavj)setdbcstbl required for cmdline char edit for surrogae pair 4 dbcs//~vavnI~
//vavk:140425 (BUG)cmd retrieve miss to recovery utf8 encoding     //~vavkI~
//vav0:140325 (Win)unicode support                                 //~4325I~
//*********************************************************************//~4325I~
#ifdef W32                                                         //~vav0M~
//*********************************************************************//~vav0I~
int fsubw_U82UD(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh,char *Pfnm,int Plen,char *Poutbuff,int Pbuffsz,int *Ppoutlen);//~vav0R~
//*********************************************************************//~vavkI~
//int fsubw_U8CT2UD(int Popt,char *Pu8,char *Pct,int Plen,char *Poutbuff,int Pbuffsz,int *Ppoutlen);//~vavkI~//~vawwR~
int fsubw_U8CT2UD(int Popt,char *Pu8,char *Pct,int Plen,int Pctlen,char *Poutbuff,int Pbuffsz,int *Ppoutlen);//~vawwI~
//*********************************************************************//~vavkI~
int fsubw_stripUDCT(int Popt,char *Pud,int Plen,char *Pu8,int Pbuffsz,char *Poutct,int Poutctsz,int *Ppoutlen);//~vavkI~
//*********************************************************************//~vavkI~
int fsubw_UD2LC(int Popt,char *Pud,int Plen,char *Plc,int Pbuffsz,int *Ppoutlen);//~vavkI~
#define FSWUD2LCO_NOMSG       0x01                                 //+vb4bI~
//*********************************************************************//~vavnI~
int fsubw_setdbcstblDD(int Popt,char *Pdddata,char *Pdddbcs,int Pddlen,char *Poutbuff,int Pbuffsz);//~vavnR~
//*********************************************************************//~vavnI~
int fsubw_setflddatadd(int Popt,PUCLIENTWE Ppcw,int Prow,int Pfldno,UCHAR *Pdata,UCHAR *Pdbcs,int Plen);//~vavnR~
//*********************************************************************//~vavFI~
int fsubw_UD2DD(int Popt,char *Pud,int Plen,char *Pdddata,char *Pdddbcs,int Pbuffsz,int *Ppoutlen);//~vavFI~
//*********************************************************************//~vavQI~
int fsubw_cmdopdU8CT2UD(int Popt,PUCLIENTWE Ppcw,int Popdno,char *Popd,char *Poutbuff,int Pbuffsz,int *Ppoutlen);//~vavQI~
#define FSWCOU8CT2UDO_UTF8WC  0x01  //all utf8(not f2l err only)   //~vavQI~
#define FSWCOU8CT2UDO_PARTIAL 0x02  //opd is partial of fpath      //~vawvR~
//*********************************************************************//~vavQI~
int fsubw_cmdopdU8CT2UDX(int Popt,PUCLIENTWE Ppcw,int Popdno,char *Popd,char *Poutbuff,int Pbuffsz,int *Ppoutlen);//~vavQI~
#endif	//W32                                                             //~vaubI~//~vav0R~
