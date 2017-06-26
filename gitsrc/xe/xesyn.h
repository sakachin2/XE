//*CID://+vb29R~:      update#=3                                   //~vb29R~
//****************************************************************
//xesyn.h                                                          //~vb29R~
//****************************************************************
//vb29:160116 Linux compiler warning for SYN_INVALIDATE_PFH        //~vb29I~
//v78o:080322 (SYN:BUG)reverse is not able to distingush on browse screen//~v78oI~
//v786:080301 (SYNH)"ENTERU":update line only option               //~v786I~
//v780:080212 syntaxhighlight support                              //~v780I~
//****************************************************************
#ifdef  XESYN_GLOBAL                                               //~v780I~
  #define XESYN_EXT                                                //~v780I~
  #define XESYN_INIT(value) =value                                 //~v780I~
#else                                                              //~v780I~
  #define XESYN_EXT extern                                         //~v780I~
  #define XESYN_INIT(value)                                        //~v780I~
#endif                                                             //~v780I~
//**************************************************************** //~v780I~
XESYN_EXT ULONG  Gsynopt;                                          //~v780R~
#ifdef WXEXXE                                                      //~v780I~
	XESYN_EXT UCHAR *Gsynstyletbl;                                 //~v780I~
#endif                                                             //~v780I~
//**************************************************************** //~v780I~
//*flag for UFHsynflag  4 byte                                     //~v780R~
#define UFHSF_ENTERON               0x01     //syntaxHL on by ENTER key for all line//~v786R~
#define UFHSF_ON                    0x02     //display highlight   //~v780R~
#define UFHSF_ENTERONUPDATELINEONLY 0x04     //by enter key update color for only updated line//~v786R~
#define UFHSF_ALLFOLLOWING          0x08     //update color for only following of updated line//~v780I~
#define UFHSF_VALID               0x0100     //all line valid color data//~v780I~
#define UFHSF_HASCOLORDATA        0x0200     //any line has color data//~v780R~
#define UFHSF_FAILED              0x0400     //syn onece failed flag for undo//~v780I~
#define UFHSF_VALIDUPDATELINEONLY 0x0800     //evaluation done only for update line//~v786I~
#define UFHSF_UPDATELINEONLYLANG  0x1000     //lang is update only even for all evel req//~v786I~
                                                                   //~v780I~
//*flag for ULHsynflag  byte                                       //~v780I~
#define ULHSF_VALID                 0x01     //not updated after syn done//~v780R~
#define ULHSF_REQUIRED              0x02     //re-evaluation required//~v780R~
#define ULHSF_VALIDBYEUO            0x04     //re-evaluation done by ENTERUPDATEONLY option//~v786I~
                                                                   //~v786I~
//common parm option                                               //~v786I~
#define SYNCPO_ALL          0x80000000  //evaluate all line if LANG is multiline//~v786R~
#define SYNCPO_ALLALL       0x40000000  //evaluate all line even if lang is not multiline//~v786I~
#define SYNCPO_ENTER        0x20000000  //update by enter key      //~v786R~
#define SYNCPO_ENTERU       0x10000000  //ENTERU option            //~v786R~
#define SYNCPO_OPEN         0x08000000  //at initial open          //~v786I~
#define SYNCPO_BROWSE       0x04000000  //browse open              //~v78oI~
                                                                   //~v780I~
//**************************************************************** //~v780I~
#define SYN_INVALIDATE_PFH(pfh)  \
        ULBITOFF((pfh)->UFHsynflag,UFHSF_VALID)                    //+vb29M~
//      (pfh)->UFHsynflag&=~UFHSF_VALID                            //~v780I~//~vb29R~
#define SYN_INVALIDATE_PLH(plh) \
        UCBITOFF((plh)->ULHsynflag,ULHSF_VALID)                    //~v780I~
#define SYN_INVALIDATE_PLH_REQUIRED(plh) \
        UCBITON((plh)->ULHsynflag,ULHSF_REQUIRED)                  //~v780R~
#define SYN_INVALIDATE_FL(pfh,plh) \
        SYN_INVALIDATE_PLH(plh),SYN_INVALIDATE_PFH(pfh)            //~v780I~
//**************************************************************** //~v780I~
int xesyninit(int Popt);                                           //~v780R~
//****************************************************************
int xesynterm(int Popt);                                           //~v780R~
//**************************************************************** //~v780I~
int xesynexecenter(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh);         //~v780I~
//**************************************************************** //~v780I~
int xesynsetlineattr(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH Pplh,//~v780I~
					UCHAR *Ppsddata,UCHAR *Ppsddbcs,UCHAR *Ppsdcell,PUSCRD Ppsd,int Pscrwidth,int Plinenosz);//~v780I~
#define SSLAO_VHEX      0x01                                       //~v780R~
//**************************************************************** //~v780M~
int xesynundo(int Popt,int Pundotype,PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH Pplh,void *Ppuh);//~v780R~
//**************************************************************** //~v780M~
int xesynundoprep(int Popt,int Pundotype,PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH Pplh,void *Ppuh);//~v780R~
//**************************************************************** //~v780M~
int xesynchkopen(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh);           //~v780I~
//**************************************************************** //~v780I~
int xesynsetgblstyletbl(int Popt,PUCLIENTWE Ppcw,void *Ppsd,int Pinactsw,int Prow,int Pvsplitinact1stsw);//~v780I~
//**************************************************************** //~v780M~
int syngetbgtab(int Popt);                                         //~v780M~
//**************************************************************** //~v78oI~
int xesyngetbgreverse(int Popt);                                   //~v78oI~
