//*CID://+v7arR~:                             update#=  197;       //+v7arR~
//**************************************************               //~v57cI~
//* ucvucs.h                                                       //~v57cI~
//**************************************************               //~v66DI~
//v7ar:240315 (BUG)v7a8 should not to use UTF option               //+v7arI~
//v7a9:240226 UTF_GETUTF8STR(Pucs,Pwku8,Plen) --> U2FCHAR(Pucs)    //~v7a9I~
//v6uY:140613 (LNX)f2u accept always UCS4 like as W32              //~v6uYI~
//v6uF:140529 (W32)UCVUCS_UCS4:if v6uE output is 4byte ucs,so specify only when 4byte ucs is required,else output surrogate pair for UCS4//~v6uFI~
//v6uE:140529 (W32)request explicit option UCVUCS_UCS4 for UCS4 for also Win//~v6uEI~
//v6uB:140523 (Win:UNICODE)dbcsid:overflow for ucs4 on Windows     //~v6uBI~
//v6u9:140408 (Win)use UNICODE Api using special filename fmt.     //~v6u9I~
//v6f4:120419 option to use ICU as M2M converter                   //~v6f4I~
//v69c:100809 converter parm support for each b2m/m2b translation  //~v69cI~
//v695:100804 for xcv,option of set repch when len err for f2x     //~v695I~
//v691:100730 LP64 wchar_t is 4byte on LP64                        //~v691I~
//v66D:100604 indicate not by outchar but by rc that SUBCHAR was set//~v66DI~
//v640:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~v640I~
//v62J:091008_ASCIIRET support for ucvsutf2sjis<-f2l               //~v62JI~
//v62f:090811 ucvssutf2sjis:option to advanse 1 byte for conversion err//~v62fI~
//v622:090616 option to return ALLASCII                            //~v622I~
//v5n8:080916 (CJK)IME support for CJK other than Japanese         //~v5n8I~
//v5n0:080821 partialy release UTF8SUPP for xcv                    //~v5n0I~
//v5mm:080323*xcv compile err on gcc env                           //~v5mmI~
//v61g:071222 (UTF)locale<-->utf8 conversion support               //~v61gI~
//v614:071117 (UTF)EUC<->UTF8 conversion support                   //~v614I~
//v5ic:060601 (LNX:UTF)optionaly avoid ucs2sjis for ucs=<0xff      //~v5icI~
//v5h6:060321 ucs conv:support \u option for sjis2ucs(\uxxxx format output)//~v5b6I~
//v5b3:040122 \uxxxx unicode fmt conv support                      //~v5b3I~
//v57p:030118 (AIX)display all ms932 char                          //~v57pI~
//v57m:030111 (BUG)rrmsg function:display byte                     //~v57mI~
//v57k:030106 cp943,sjis option(ucvucst is ms932)                  //~v57kR~
//v57k:030101 add termfunc(free word)                              //~v57kI~
//v57j:021231 ucs conv:err callback function support               //~v57iI~
//v57i:021231 ucs conv:set rc for ucs=-1                           //~v57iI~
//v57c:021214 unicode,utf8 conversion support                      //~v57cI~
//**************************************************               //~v57cI~
#if defined(DOS) && !defined(DPMI)                                 //~v57cI~
	#define UCVUINTERRUCS    0xffff                                //~v57cI~
#else                                                              //~v57cI~
	#define UCVUINTERRUCS    0xffffffff                            //~v57cI~
#endif                                                             //~v57cI~
#define UCVERRUCS        0xffff                                    //~v57cR~
#define UCVULONGERRUCS   0xffffffff                                //~v57cI~
//*                                                                //~v57cI~
#define UCVUCS_FMTERR   0x01                                       //~v57cR~
#define UCVUCS_LENERR   0x02                                       //~v57cR~
#define UCVUCS_CONVERR  0x04                                       //~v57cI~
#define UCVUCS_BUFFOVF  0x08                                       //~v57cR~
#define UCVUCS_ALLASCII 0x10                                       //~v622I~
#define UCVUCSRC_ASCII  0x20    //by UCVUCS_ASCIIRET option;detected ascii char//~v62JR~
#define UCVUCSRC_NOTMBDBCS1   0x40    //ebc2ucs;requested MBDBCS1 but translated not to 1 ucs//~v69cI~
                                                                   //~v62JI~
#define UCVUCS_ERRCH    0x00ff //replace char for err ucs code to sjis//~v57kR~
#define UCVUCS_LE       0x0100 //output ucs by little endian       //~v57cR~
#define UCVUCS_UCS4     0x0200 //accept ucs4                       //~v57cR~
#define UCVUCS_BOM      0x0400 //chk file BOM (Big endian if no BOM),write BOM//~v57cR~
#define UCVUCS_FULLREC  0x0800 //force conv last len err byte      //~v57cR~
#define UCVUCS_NOERRMSG 0x1000 //no err msg output option          //~v57cI~
#define UCVUCS_CP943C   0x2000 //sjis -->ucs by ibm cp943c         //~v57kR~
#define UCVUCS_CPMS932  0x4000 //sjis -->ucs by ms932              //~v57kR~
#define UCVUCS_NEC      0x8000 //sjis<-- ucs to NEC select SJIS range//~v57kR~
#define UCVUCS_STRZU8   0x8000 //strz for to utf8                  //+v7arI~
#define UCVUCS_ESCUCS 0x010000 //input is \uxxxx unicode fmt       //~v5b3R~
#define UCVUCS_LATIN  0x020000 //ucs->sjis;keep ucs<=0xff          //~v5icI~
//#ifdef UTF8SUPP                                                  //~v5mmR~
  #define UCVUCS_EUC  0x040000 //utf8<-->sjis width EUC option     //~v614I~
//#ifdef UTF8UTF16                                                   //~v6uEI~//~v6uFR~
//  #define UCVUCS_UCS4W 0x040000 //output ucs4 on Windows           //~v6uER~//~v6uFR~
//#endif                                                             //~v6uEI~//~v6uFR~
//#ifdef UTF8SUPP                                                  //~v5n0R~
#ifdef WCSUPP                                                      //~v5n0I~
  #define UCVUCS_MB    0x080000 //utf8<-->sjis width LOCALE option //~v61gR~
#endif                                                             //~v614I~
#define UCVUCS_MBDBCS  0x100000  //wincp2ucs:source is dbcs        //~v5n8I~
                                 //for winucs2cp:ucs is from dbcs(EBCDIC)//~v66DI~
#define UCVUCS_ERRSTOP 0x200000  //no breplace by subchar but returns err//~v5n8I~
#define UCVUCS_RETALLA 0x400000  //return allascii rc              //~v622I~
#define UCVUCS_UTFERR1 0x800000  //set 1byte err for ucvsutf2sjis  //~v62fI~
#define UCVUCS_ASCIIRET  0x01000000  //return if detected ascii    //~v62JI~
#define UCVUCS_SETSUBCHRC    0x02000000  //return subch was set    //~v66DI~
#define UCVUCS_LOCALCV       0x04000000  //local converter         //~v66DI~
#define UCVUCS_LENERRREP     0x08000000  //errrep if lenerr for f2x//~v695I~
#define UCVUCS_MBDBCS1       0x10000000  //err if translated count>1//~v69cI~
#define UCVUCS_MBICU         0x20000000 	//use ICU for m2m      //~v6f4I~
#define UCVUCS_BESTFIT       0x40000000 	//for winucs2cp        //~v6u0I~//~v6u9I~
//**************************************************               //~v57cI~
typedef int (UCVUCS_FREAD)(UCHAR *Preadbuff,int Pbuffsz,int *Preadlen);	//read func//~v57cI~
typedef int (UCVUCS_FWRITE)(UCHAR *Preadbuff,int Pwritelen);	//write func//~v57cI~
typedef int (UCVUCS_FERR)(int Prc,int Poffs,int Poutoffs,UCHAR *Perrbyte,int Perrbytelen);	//err callback//~v57mR~
typedef int (UCVUCS_FCONV)(UCVUCS_FREAD *Pfread,UCVUCS_FWRITE *Pfwrite,UCVUCS_FERR *Pferr,//~v57iR~
			 ULONG Popt,UCHAR *Pibuff,int Pibuffsz,UCHAR *Pobuff,int Pobuffsz);//~v57kR~
//**************************************************               //~v57cI~
int ucp932init(USHORT **Ps2u,USHORT **Pu2s);                       //~v57kI~
//**************************************************               //~v57kI~
int ucp932term(void);                                              //~v57kR~
//**************************************************               //~v57pI~
//ULONG ucp932sjis2ucs(int Psjis);                                   //~v57pI~//~v691R~
UWUCS ucp932sjis2ucs(int Psjis);                                   //~v691I~
//**************************************************               //~v57kI~
//ULONG uccvsjis2ucs(ULONG Popt,int Psjis);                          //~v57kR~//~v691R~
UWUCS uccvsjis2ucs(ULONG Popt,int Psjis);                          //~v691I~
//**************************************************               //~v57iI~
//int uccvsjis2ucss(ULONG Popt,int Psjis,UCHAR *Pucs);             //~v5b6R~
int uccvsjis2ucss(ULONG Popt,int Psjis,UCHAR *Pucs,int *Poutlen);  //~v5b6I~
//**************************************************               //~v57cI~
//int uccvucs2sjis(ULONG Popt,ULONG Pucs);                           //~v57kR~//~v691R~
int uccvucs2sjis(ULONG Popt,UWUCS Pucs);                           //~v691I~
//**************************************************               //~v57cI~
//int uccvucs2utf(ULONG Pucs,UCHAR *Putf);                           //~v57cR~//~v691R~
int uccvucs2utf(UWUCS Pucs,UCHAR *Putf);                           //~v691I~
//**************************************************               //~v57cI~
//#ifdef UTF8UTF16                                                   //~v6uBI~//~v6uYR~
int uccvucss2utf(ULONG Popt,UCHAR *Pucs,UCHAR *Putf,int *Ppucsctr);//~v6uBR~
//#else                                                              //~v6uBI~//~v6uYR~
//int uccvucss2utf(ULONG Popt,UCHAR *Ppucs,UCHAR *Putf);             //~v57kR~//~v6uYR~
//#endif                                                             //~v6uBI~//~v6uYR~
//**************************************************               //~v57cI~
int ucvsucs2utf(UCVUCS_FERR *Pferr,ULONG Popt,UCHAR *Pibuff,int Pibufflen,UCHAR *Pobuff,int Pobufflen,//~v57kR~
				int *Ppchklen,int *Ppoutlen,int *Pperrctr);        //~v57iR~
//**************************************************               //~v57cI~
//int uccvutf2ucs(ULONG Popt,UCHAR *Putf,int Plen,ULONG *Ppucs,int *Ppchklen);//~v57kR~//~v691R~
int uccvutf2ucs(ULONG Popt,UCHAR *Putf,int Plen,UWUCS *Ppucs,int *Ppchklen);//~v691I~
//**************************************************               //~v57cI~
int ucvsutf2ucs(UCVUCS_FERR *Pferr,ULONG Popt,UCHAR *Pibuff,int Pibufflen,UCHAR *Pobuff,int Pobufflen,//~v57kR~
				int *Ppchklen,int *Ppoutlen,int *Pperrctr);        //~v57iR~
//**************************************************               //~v57cI~
//int uccvutf2ucss(ULONG Popt,UCHAR *Putf,int Plen,UCHAR *Pucs,int *Ppchklen);//~v5b6R~
//int uccvutf2ucss(ULONG Popt,UCHAR *Putf,int Plen,UCHAR *Pucs,int *Ppchklen,int *Poutlen);//~v5b6I~//~v6uYR~
int uccvutf2ucss(ULONG Popt,UCHAR *Putf,int Plen,UCHAR *Pucs,int Pbuffsz,int *Ppchklen,int *Poutlen);//~v6uYI~
//**************************************************               //~v57cI~
//int uccvsjis2utf(int Psjis,UCHAR *Putf);                         //~v57iR~
//int uccvsjis2utf(int Psjis,UCHAR *Putf,int *Pplen);              //~v57kR~
int uccvsjis2utf(ULONG Popt,int Psjis,UCHAR *Putf,int *Pplen);     //~v57kR~
//**************************************************               //~v57cI~
int uccvutf2sjis(ULONG Popt,UCHAR *Putf,int Plen,int *Ppsjis,int *Ppchklen);//~v57kR~
//**************************************************               //~v57cI~
int ucvssjis2utf(UCVUCS_FERR *Pferr,ULONG Popt,UCHAR *Pibuff,int Pibufflen,UCHAR *Pobuff,int Pobufflen,//~v57kR~
				int *Ppchklen,int *Ppoutlen,int *Pperrctr);        //~v57iR~
//#ifdef UTF8SUPP                                                  //~v5n8R~
#ifdef WCSUPP                                                      //~v5n8I~
//**************************************************               //~v61gI~
int ucvsmb2utf(UCVUCS_FERR *Pferr,ULONG Popt,UCHAR *Pibuff,int Pibufflen,UCHAR *Pobuff,int Pobufflen,//~v61gI~
				int *Ppchklen,int *Ppoutlen,int *Pperrctr);        //~v61gI~
#endif                                                             //~v61gI~
//**************************************************               //~v57cI~
int ucvsutf2sjis(UCVUCS_FERR *Pferr,ULONG Popt,UCHAR *Pibuff,int Pibufflen,UCHAR *Pobuff,int Pobufflen,//~v57kR~
				int *Ppchklen,int *Ppoutlen,int *Pperrctr);        //~v57iR~
//**************************************************               //~v61gI~
//#ifdef UTF8SUPP                                                  //~v5n8R~
#ifdef WCSUPP                                                      //~v5n8I~
int ucvsutf2mb(UCVUCS_FERR *Pferr,ULONG Popt,UCHAR *Pibuff,int Pibufflen,UCHAR *Pobuff,int Pobufflen,//~v61gI~
				int *Ppchklen,int *Ppoutlen,int *Pprepctr);        //~v61gI~
#endif                                                             //~v61gI~
//**************************************************               //~v57cI~
int ucvsucs2sjis(UCVUCS_FERR *Pferr,ULONG Popt,UCHAR *Pibuff,int Pibufflen,UCHAR *Pobuff,int Pobufflen,//~v57kR~
				int *Ppchklen,int *Ppoutlen,int *Pperrctr);        //~v57iR~
//**************************************************               //~v57iI~
int ucvssjis2ucs(UCVUCS_FERR *Pferr,ULONG Popt,UCHAR *Pibuff,int Pibufflen,UCHAR *Pobuff,int Pobufflen,//~v57kR~
				int *Ppchklen,int *Ppoutlen,int *Pperrctr);        //~v57iR~
//**************************************************               //~v57cI~
UCVUCS_FCONV ucvfsjis2ucs;                                         //~v57cR~
UCVUCS_FCONV ucvfucs2sjis;                                         //~v57cI~
UCVUCS_FCONV ucvfutf2ucs;                                          //~v57cI~
UCVUCS_FCONV ucvfucs2utf;                                          //~v57cI~
UCVUCS_FCONV ucvfsjis2utf;                                         //~v57cI~
UCVUCS_FCONV ucvfutf2sjis;                                         //~v57cI~
//**************************************************               //~v57cI~
int ucvbomchk(ULONG *Ppopt,UCHAR *Putf,int Putfbufflen);           //~v57kR~
//**************************************************               //~v57cI~
int ucvbomset(ULONG Popt,UCHAR *Putf);                             //~v57kR~
//**************************************************               //~v57cI~
//int ucvsetucss(ULONG Ppopt,ULONG Pucs,UCHAR *Pucss);               //~v57kR~//~v691R~
int ucvsetucss(ULONG Ppopt,UWUCS Pucs,UCHAR *Pucss);               //~v691I~
//**************************************************               //~v57cI~
ULONG ucvgetucss(ULONG Popt,UCHAR *Pucs);                          //~v57kR~
//*****************************************************************//~v7a9I~
#define  UCV_U2F1(Pucs) ucvucs_u2f1((UWUCS)Pucs)                   //~v7a9R~
char *ucvucs_u2f1(UWUCS Ppucs);                                    //~v7a9R~
