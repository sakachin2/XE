//*CID://+v993R~:                             update#=   81;       //~v993R~
//***************************************************************  //~v928I~
//* xputf.h                                                        //~v928I~
//***************************************************************  //~v928I~
//v993:160308 v9.32 ucs4 support                                   //~v993I~
//v97m:131104 (gxp)header print err for utf8 filename;chk utf8 encoding for filename//~v97mI~
//100909 v955 v9.19 print EBC file by TextOutW for avoid print "?" for trans err to locale code//~v955I~
//100706 v950 v9.18 64bit compile                                  //~v950I~
//071024 v92n (LNX)support utf8 file(conv to locale)               //~v92nI~
//071005 v928 (Win)UTF8 support                                    //~v928I~
//***************************************************************  //~v928I~
#ifdef UTF8SUPP                                                    //~v928I~
//***************************************************************  //~v928I~
#ifdef  GLOBAL_XPUTF                                               //~v928R~
  #define EXT_XPUTF                                                //~v928R~
#else                                                              //~v928I~
  #define EXT_XPUTF extern                                         //~v928R~
#endif                                                             //~v928I~
//***************************************************************  //~v928I~
EXT_XPUTF int Gxputfstat;                                          //~v928R~
                                                                   //~v928I~
#define GXPUS_UTF8ON    0x01     //utf8 file print                 //~v928M~
#define XPUTF8MODE()    (Gxputfstat & GXPUS_UTF8ON)                //~v928M~
#define GXPUS_UCSLINE   0x02     //parm to pline data is ucs array //~v928I~
#define GXPUS_UCSLINE_EBC   0x04     //line to be printed ebc by ucs//~v955I~
                                                                   //~v928I~
#define XPUCS_DBCS1ST   0x80000000   //1st ucs of duplicated for dbcs//~v928M~
                                                                   //~v928I~
//EXT_XPUTF USHORT Gbuffucs[MAXLINEWIDTH];                           //~v928R~//~v950R~
//EXT_XPUTF WUCS Gbuffucs[MAXLINEWIDTH];                             //~v950I~//~v993R~
EXT_XPUTF UWUCS Gbuffucs[MAXLINEWIDTH];                            //~v993I~
#ifdef W32                                                         //~v993I~
EXT_XPUTF  WUCS Gbuffucs2[MAXLINEWIDTH*(sizeof(UWUCS)/sizeof(WUCS))]; //for ebc ucs2 edit buff//+v993R~
#endif                                                             //~v993I~
EXT_XPUTF int    Gcolumnucs;                                       //~v928I~
EXT_XPUTF int Gbuffutf[MAXLINEWIDTH*UTF8_MAXCHARSZMAX];            //~v928I~
//***************************************************************  //~v928I~
#define XPsetAC_(buffucs,posucs,ch) \
    if (XPUTF8MODE()) buffucs[posucs]=(UWUCS)ch;                   //~v993I~
//  if (XPUTF8MODE()) buffucs[posucs]=(WUCS)ch;                    //~v950I~//~v993R~
//  if (XPUTF8MODE()) buffucs[posucs]=(USHORT)ch;                  //~v928R~//~v950R~
#define XPsetACa_(buffucs,posucs,ch) \
    if (XPUTF8MODE()) buffucs[posucs++]=(UWUCS)ch;                  //~v950I~//~v993R~
//  if (XPUTF8MODE()) buffucs[posucs++]=(WUCS)ch;                  //~v993I~
//  if (XPUTF8MODE()) buffucs[posucs++]=(USHORT)ch;                //~v928R~//~v950R~
#define XPsetC_(buffucs,posucs,ch) \
    if (XPUTF8MODE()) *(buffucs+posucs)=(UWUCS)ch;                 //~v993I~
//  if (XPUTF8MODE()) *(buffucs+posucs)=(WUCS)ch;                  //~v950I~//~v993R~
//  if (XPUTF8MODE()) *(buffucs+posucs)=(USHORT)ch;                //~v928R~//~v950R~
#define XPsetCa_(buffucs,posucs,ch) \
    if (XPUTF8MODE()) *(buffucs+posucs++)=(UWUCS)ch ;              //~v993I~
//  if (XPUTF8MODE()) *(buffucs+posucs++)=(WUCS)ch ;               //~v950I~//~v993R~
//  if (XPUTF8MODE()) *(buffucs+posucs++)=(USHORT)ch ;             //~v928R~//~v950R~
#define XPsetINCa(pos,ucspos)   pos++,ucspos++                     //~v928I~
#define XPsetDECa(pos,ucspos)   pos--,ucspos--                     //~v928I~
                                                                   //~v928I~
#define XPsetEQ_(ucspos,pos)    ucspos=pos;                        //~v928I~
//#define XPsetucsON_()			if (XPUTF8MODE()) Gxputfstat|=GXPUS_UCSLINE;//~v928R~//~v955R~
//#define XPsetucsOFF_()			if (XPUTF8MODE()) Gxputfstat&=~GXPUS_UCSLINE;//~v928R~//~v955R~
#define XPsetucsON_UTF()			if (XPUTF8MODE()) Gxputfstat|=GXPUS_UCSLINE;//~v955I~
#define XPsetucsOFF_UTF()			if (XPUTF8MODE()) Gxputfstat&=~GXPUS_UCSLINE;//~v955I~
#define XPsetucsON_()		if (Gxpotheropt & GOO_EBCBYUCS) Gxputfstat|=GXPUS_UCSLINE_EBC; \
                            else XPsetucsON_UTF()                  //~v955I~
#define XPsetucsOFF_()		if (Gxpotheropt & GOO_EBCBYUCS) Gxputfstat&=~GXPUS_UCSLINE_EBC; \
                            else XPsetucsOFF_UTF()                 //~v955I~
//***************************************************************  //~v928I~
int xputf_open(int Popt);                                          //~v928I~
//***************************************************************  //~v928I~
int xputf_getinput(int Popt,int Prescol,char *Putfstr,int *Pputfstrlen,int *Ppucs,int *Ppchartype,int *Ppdbcssw,long *Ppreadcnt);//~v928R~
#define XPUTFO_BIN      0x01     //record mode                     //~v928I~
//***************************************************************  //~v92nI~
#if defined(LNX) && !defined(GXP)                                  //~v92nI~
int utf_fwrite(char *Pbuff,unsigned long Plen,FILE *Ppfh);         //~v92nR~
#endif                                                             //~v92nI~
//***************************************************************  //~v928I~
#else                                                              //~v928I~
	#define XPsetAC_(buffucs,posucs,ch)                            //~v928R~
	#define XPsetACa_(buffucs,posucs,ch)                           //~v928R~
	#define XPsetC_(buffucs,posucs,ch)                             //~v928R~
	#define XPsetCa_(buffucs,posucs,ch)                            //~v928R~
	#define XPsetINCa(pos,ucspos)   pos++                          //~v928I~
	#define XPsetDECa(pos,ucspos)   pos--                          //~v928I~
                                                                   //~v928I~
	#define XPsetEQ_(ucspos,pos)                                   //~v928I~
	#define XPsetucsON_()                                          //~v928I~
	#define XPsetucsOFF_()                                         //~v928I~
	#define XPsetdatacols_(col)                                    //~v928I~
#endif //UTF8SUPP                                                  //~v928I~
#ifdef GTKPRINT                                                    //~v97mI~
	int xputf_f2u(char *Pputf8,int Plen,WUCS* Ppucs,int *Ppucsctr,int *Ppwidth);//~v97mI~
#endif                                                             //~v97mI~
