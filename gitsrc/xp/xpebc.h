//CID://+v9e6R~:    update#=  182221                               //~v9e6R~
//***********************************************************
//* xpebc.h                                                        //~0428R~
//***********************************************************
//v9e6:170826 compiler warning samename parm and gbl               //~v9e6I~
//v996:160309 v9.32 (BUG)utfdd2u buffsize parm is not ctr but size //~v996I~
//v96w:130807 lineno field is by ascii from xe(xpr **/***) for english small letter translation//~v96wI~
//100923 v956 v9.20 (BUG) "too long line" err msg when from xe(xpr ** for ebc vhex mode. /Me oprion ignored)//~v956I~
//100909 v955 v9.19 print EBC file by TextOutW for avoid print "?" for trans err to locale code//~v955I~
//100908 v953 v9.19 EBC convertername support /CPEB:               //~v953I~
//100428 v941 v9.16 ebcdic print support                           //~0428I~
//***********************************************************      //~v765I~
#define MAX_EBC_TEXTINPLINESZ      MAXTEXTINPLINESZ   //10240>RBUFFSZ=4096(record mode)//~0428R~
#define PARM_CPEB                  "CPEB"                          //~v953I~
#define EBC_READC_EOL              -2	//eol id                   //~v953I~
//***********************************************************      //~0428I~
int xpebc_init(int Popt,char *Pcfgfnm);                                          //~0428I~//~0429R~//+v9e6R~
//**********************************************************************//~v74jI~
int xpebc_setupcp(int Popt,int **Pcharset,int **Ppcodepage,UCHAR **Pptrt);         //~0428R~//~0429R~
//**********************************************************************//~0428I~
int xpebc_fread(int Popt,char *Pbuff,int Preqlen,FILE *Pfh);       //~0428I~
//**********************************************************************//~0428I~
int xpebc_fgetc(int Popt,FILE *Pfh);                               //~0428I~
//**********************************************************************//~v956I~
int xpebc_fgets(int Popt,FILE *Pfh,char *Pbuff,int Pbuffsz,int *Ppreadlen);//~v956I~
#define XPEBCFGSO_INPUTVHEXMODE    0x01       //3line input mode   //~v956R~
#define XPEBCFGSO_VHEXLINE         0x02       //read vhex line     //~v956I~
#define XPEBCFGSO_VHEXLINE_ASCIILINENO  0x04       //vhex input dataline lineno is by ascii//~v96wI~
//**********************************************************************//~0429I~
int xpebc_freadnext(int Popt,int Poffs);                           //~0429I~
//**********************************************************************//~v953I~
int xpebc_getparmcvname(int Popt,char *Popd);                      //~v953I~
//**********************************************************************//~v953I~
int xpebc_open(int Popt);                                          //~v953I~
//**********************************************************************//~v955I~
//int xpebc_setucsline(int Popt,UCHAR *Pmbdata,WUCS *Ppucs,int Plen,int *Ppucsctr);//~v955R~//~v996R~
int xpebc_setucsline(int Popt,UCHAR *Pmbdata,WUCS *Ppucs,int Plen,int *Ppucsctr,int Pbuffsz);//~v996I~
#define XPEBCSULO_HEX      0x01       //CHARDELM appended          //~v955I~
//**********************************************************************//~v955I~
//int xpebc_setucslinesamechk(int Popt,UCHAR *Pmbdata,int Plen,UCHAR *Pebcorg,int Pebclen,WUCS *Ppucs,int *Ppucsctr);//~v955I~//~v996R~
int xpebc_setucslinesamechk(int Popt,UCHAR *Pmbdata,int Plen,UCHAR *Pebcorg,int Pebclen,WUCS *Ppucs,int *Ppucsctr,int Pbuffsz);//~v996I~
//**********************************************************************//~v955I~
