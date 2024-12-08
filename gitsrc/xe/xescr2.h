//CID://+vbi3R~:    updateno=      1                               //+vbi3R~
//****************************************************************
//xescr2.h
//****************************************************************
//vbi3:180211 supprt command history list                          //+vbi3I~
//vbd7:171119 "SEL all" support on file panel                      //~vbd7I~
//v53m:030928 (LNX)mouse support                                   //~v53mI~
//v500:020929 (WXE)scr cut/paste                                   //~v500I~
//v09l:970518:csr wait mark in dlcmd or cmd processing             //~v09lI~
//            drop pcw parm not used on scrcsrtyperestore          //~v09lI~
//****************************************************************
int scrconfirmchk(int Preqid);

//****************************************************************//~5B23I~
void scrconfirmset(void);                                       //~5B23I~

//****************************************************************//~5B23I~
void scrconfirmreset(void);                                     //~5B23I~

//****************************************************************
void scrclearmsg(PUCLIENTWE Ppcw);

//****************************************************************
void scrclearconfirmmsg(void);
                                                                   //~6602I~
//**************************************************************** //~6602I~
void scrcsrtyperestore(void);                                      //~v09lR~
                                                                   //~v500I~
//#ifdef WXE                                                       //~v53mR~
#if defined(WXE)||defined(LNX)                                     //~v53mI~
                                                                   //~v500I~
//**************************************************************** //~v500I~
//int  scrcpgetdata(int Prow,int Pcol,int Pcolend,char **Ppdata,char **Ppdbcs,int *Pplen);//~v500R~
//**************************************************************** //~v500I~
int scrsetcsrpos(int Prow,int Pcol);                               //~v500R~
//**************************************************************** //~v500I~
//int scrcpgetpcw(int Prow,int Pcol,PUCLIENTWE *Pppcw);              //~v500M~//~vbd7R~
                                                                   //~v500I~
#endif                                                             //~v500I~
int scrcpgetpcw(int Prow,int Pcol,PUCLIENTWE *Pppcw);              //~vbd7I~
//**************************************************************** //+vbi3I~
int funcswap2(int Popt,PUCLIENTWE Ppcw);                           //+vbi3R~
