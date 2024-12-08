//*CID://+va7xR~:                             update#=   10;       //+va7xR~
//****************************************************************
//*xefcmd.h
//****************************************************************
//va7x:100825 lcmd; no translation option for "=","C","M"          //+va7xI~
//va00:090510 merge utf8 version(enclosed by UTF8SUPPH)            //~va00I~
//          Copy:CPxx option  COPy/MOVe fnm [CPU8] [IE]            //~va00I~
//v783:080227 CUT/PASTE cmd to use another clipboard(save/restore each time)//~v783I~
//v64o:050624 (LNX)xxe support;cut & paste                         //~v64oI~
//v62t:050330 tc;wildcard rename support for -ooutfile             //~v62tI~
//v500:020929 (WXE)scr cut/paste                                   //~v500I~
//v0ib:980530 v0i9 cotinued for other than file copy               //~v0ibI~
//v0ia:980530 add APPend cmd                                       //~v0iaI~
//v06i:960310:support REPl/CREate file by ALt+l for no line-no display mode//~v06iI~
//****************************************************************
#define CUTCMD_2NDCBFNM     "::CB2"                                //~v783R~
//**************************************************************** //~v783I~
int fcmdgetcopyline(PUCLIENTWE Ppcw,PULINEH* Ppplh);
                                                                //~5128I~
//****************************************************************//~5128I~
int fcmdoutrange(PUCLIENTWE Ppcw,PULINEH Pplh1,PULINEH Pplh2);  //~5128R~
                                                                //~v06iI~
//**************************************************************** //~v0ibI~
int fcmdoutrangebs(PUCLIENTWE Ppcw,PULINEH Pplh1,PULINEH Pplh2);   //~v0ibI~
                                                                   //~v0ibI~
//****************************************************************//~v06iI~
int fcmdfileout(PUCLIENTWE Ppcw,int Pfunc);                     //~v06iI~
#define  FCMDFOSAVE   0                                         //~v06iI~
#define  FCMDFOREP    1                                         //~v06iI~
#define  FCMDFOCRE    2                                         //~v06iI~
#define  FCMDFOAPP    3                                            //~v0iaI~
#define  FCMDFOCUT    4                                            //~v783I~
//**************************************************************** //~v500I~
int fcmdaddslh(PUCLIENTWE Ppcw);                                   //~v500I~
//#ifdef WXE                                                       //~v64oR~
#ifdef WXEXXE                                                      //~v64oI~
int fcmdgetwincbdata(PUFILEH Ppfh,PULINEH *Ppplh);                 //~v500I~
#endif                                                             //~v500I~
//**************************************************************** //~v62tI~
int fcmdoutfnmedit(PUCLIENTWE Ppcw,UCHAR *Pwildfnm,UCHAR *Pfpath); //~v62tI~
#ifdef UTF8SUPPH                                                   //~va00I~
	int fcmdcvf2l(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH Pplh);//~va00I~
    #define FCCVF2LO_BIN    0x01 //binary mode copy                //+va7xI~
#endif                                                             //~va00I~
