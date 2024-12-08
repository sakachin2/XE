//CID://+vaarR~: update#=    2                                     //~vaarR~
//****************************************************************
//xchar12.h                                                        //~v0avR~
//****************************************************************
//vaar:120101 over vaap;not by padding but position for ddfmt also for locale dbcs(contains "d")//~vaarI~
//va1c:091030_merge GB18030 support                                //~va1cI~
//va0W:091007!(BUG)dir locate consider "2U" mode                   //~v0avI~
//v0et:970921 split char12 from char                               //~v0avI~
//**************************************************************** //~v0avI~
//**************************************************               //~v0avI~
int charfieldfullerr(void);                                        //~v0avI~
                                                                   //~7621I~
//**************************************************               //~v0avI~
void chartabclear(UCHAR *Pdbcs,int Plen);                          //~v0avI~
                                                                   //~v0avI~
//**************************************************               //~7621I~
int charcleartabdbcs(UCHAR *Pdbcs);                                //~7621I~
                                                                   //~7621I~
//**************************************************               //~7621I~
int chargettablen(UCHAR *Pdbcs);                                   //~7621I~
                                                                   //~v0avI~
#ifdef UTF8SUPPH                                                   //~v0avI~
//**************************************************               //~v0avI~
int chargetkbdutf8(int Popt,PUCLIENTWE Ppcw,UCHAR **Pputf8,int *Pputf8len,int *Ppcodetype);//~v0avI~
//**************************************************               //~v0avI~
int charfldeditu8(int Pmode,UCHAR *Pbuff,UCHAR *Pdbcs,             //~v0avI~
				UCHAR *Pbuffutf8,UCHAR *Pcodetype,                 //~v0avI~
				int Pcurcol,int Pstartcol,int Pendcol,int Pbuffend,int Pbuffszu8,//~v0avR~
				PUCLIENTWE Ppcw,void* /*PUPANELL*/ Ppupl);         //~v0avR~
#define CFEUO_LENPARM       0x01 //keyindatalen is input           //~va1cR~
#endif                                                             //~v0avI~
int cmdlinepos2offs(int Popt,PUCLIENTWE Ppcw,UCHAR *Pputf8,UCHAR *Ppdbcs,UCHAR *Pcodetb,int Pstartcol,int Pcurcol,int Pu8len,//~vaanI~//~vaarM~
		int *Ppu8offs,int *Ppddlen,int *Ppwidth,int *Ppaddlen);    //~vaanI~//+vaarR~
