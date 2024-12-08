//*CID://+vbveR~:                             update#=   36;       //+vbveR~
//*********************************************************************//~5216I~
//* xefunct.h                                                   //~5216I~
//*********************************************************************//~5216I~
//vbve:221126 change Default SJIS linechar from old(<0x20) to DBCS //+vbveI~
//vbvd:221125 on 0.2/0.3 display hex/sjis string by utf8 avoiding line err(lineno green)//~vbvdI~
//vbvc:221125 functbl search miss to search english linechar because same funcid//~vbvcI~
//vb2A:160212 fkt;protect buff overflow                            //~vb2AI~
//vb2u:160207 support utf8 input by xelchxxx(LineDrawChar file) by prefix uxxyy//~vb2uI~
//va1c:091030_merge GB18030 support                                //~va1cI~
//v79R:081027 (BUG)dbcs evaluation required when graphic char input specification is by hex notation//~v79RI~
//v705:060727 graphic char setup by external file(2 string for opt linech on/off)//~v705I~
//v67C:051228 support alias cmd(save in ini file using shortcut key table position ":")//~v67CI~
//v55k:040215 (LNX)uerrmsg parm of functbl err should be sjis funcname//~v55kI~
//**************************************************            //~5429I~
#define FUNCT_RELOAD  "RELOAD"                                     //~v705I~
#define MAXSTRINPUT 100                                            //~v705R~
#ifdef  GLOBAL_FUNCT                                               //~v705I~
  			UCHAR Gstrinput[MAXSTRINPUT];                          //~v705I~
  			UCHAR Gstrinputdbcs[MAXSTRINPUT];                      //~v705I~
            int   Gstrinputlen;                                    //~v705I~
#else                                                              //~v705I~
  	extern  UCHAR Gstrinput[MAXSTRINPUT];                          //~v705I~
  	extern  UCHAR Gstrinputdbcs[MAXSTRINPUT];                      //~v705I~
    extern  int   Gstrinputlen;                                    //~v705I~
#endif                                                             //~v705I~
typedef struct _LINECHSTR                                          //~v705I~
{                                                                  //~v705I~
 		int    LCSflag;                 //string length            //~v705R~
#define LCSFHEXDATA 0x01                                           //~v705I~
#define LCSFU8DATA  0x02               //utf8 data by uxxxx format input//~vb2uR~
#define LCSFSJIS    0x04               //apply only for SJIS       //+vbveI~
 		int    LCSlen;                 //string length             //~v705I~
        char   LCSdata[MAXSTRINPUT+1]; //data                      //~v705R~
        char   LCSdbcs[MAXSTRINPUT+1]; //dbcs                      //~v705R~
} LINECHSTR;                                                       //~v705I~
                                                                   //~v705I~
typedef struct _LINECHTB                                           //~v705I~
{                                                                  //~v705I~
 	LINECHSTR   LCTonoff[2];  	//0:entry for OPT LINECH ON,1:for OFF//~v705R~
} LINECHTB,*PLINECHTB;                                             //~v705I~
                                                                   //~v705I~
//**************************************************            //~5429I~
//void functinit(void);                                            //~v705R~
void functinit(char *Postype);                                     //~v705I~
//**************************************************               //~v55kI~
#ifdef UNX                                                         //~v55kI~
	void functsjis2euc(void);                                      //~v55kR~
#endif                                                             //~v55kI~
//**************************************************            //~5429M~
void functterm(void);                                           //~5429M~
                                                                //~5429M~
//**************************************************            //~5429I~
FUNCTBL *functgetcopy(void);                                    //~5501R~
                                                                //~5429I~
//**************************************************            //~5501I~
void functreset(void);                                          //~5501I~
                                                                //~5501I~
//**************************************************            //~5424M~
FUNCTBL *functblsrch(int Pfuncid);                              //~5424M~
FUNCTBL *functblsrch2nd(int Pfuncid,FUNCTBL *Ppft1st);             //~vbvcR~
                                                                //~5429I~
//**************************************************            //~5429I~
FUNCTBL *functblsrchbyname(UCHAR *Pfuncname);                   //~5429I~
                                                                   //~v67CI~
//**************************************************               //~v67CI~
FUNCTBL *functblsrchbycmd(UCHAR *Pcmd);                            //~v67CI~
//**************************************************               //~v705I~
int funct2init(int Popt,char *Plinechfile);                        //~v705R~
//**************************************************               //~v705I~
//int funct2getlinechstr(int Popt,FUNCTBL *Ppft,char *Pout);         //~v705R~//~vb2AR~
int funct2getlinechstr(int Popt,FUNCTBL *Ppft,char *Pout,int Pbuffsz);//~vb2AI~
//**************************************************               //~v705I~
int funct2getinputgc(PUCLIENTWE Ppcw,FUNCTBL *Ppft);               //~v705R~
//**************************************************               //~v705I~
int funct2getdisplaystrtb(int *Pplentb,char **Ppaddrtb);           //~v705I~
//**************************************************               //~v705I~
int funct2getfnm(char *Pout,int Plen);                             //~v705I~
//**************************************************               //~v705I~
//int funct2getnextinputgc(char *Pinput);                            //~v705I~//~v79RR~
#ifdef UTF8SUPPH                                                   //~va1cR~
int funct2getnextinputgc(PUCLIENTWE Ppcw,char *Pinput,void *Pkeyinfo);//~va1cR~
#else                                                              //~va1cR~
int funct2getnextinputgc(PUCLIENTWE Ppcw,char *Pinput);            //~v79RI~
#endif                                                             //~va1cR~
#ifdef LNX                                                         //~v705I~
//**************************************************               //~v705I~
int funct2getacsch(int Pfuncid);                                   //~v705I~
#endif                                                             //~v705I~
int funct2printlcdata(int Popt,char *Pout,char *Pinp,int Plen);    //~vbvdI~
