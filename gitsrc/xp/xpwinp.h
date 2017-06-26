//CID://+v92fR~:                                                   //+v92fR~
//***********************************************************
//* XPWINP.H
//***********************************************************
//071013 v92f (Win)auto-set maxcol/maxline when not predefined pich specified//+v92fI~
//981024 v860 :chk output is printer by enumprinter                //~v860I~
//980927 v844 :(WIN) /EW option(use Win32 API to use spool)
//**********************************************************************
int win_portchk(char *Poutid);                                     //~v860R~
//**********************************************************************//~v860I~
void win_setupfont(char *Pfontnm);                                 //~v844R~
//****************************************************************************
void win_opendoc(int Phmi,int Pvmi,char *Pdocname);                //~v844I~
//****************************************************************************
void win_newpage(void);                                            //~v844R~
//****************************************************************************
void win_putline(char *Pbuff,unsigned long Plen);
//**********************************************************************//~v844I~
void win_closedoc(void);                                           //~v844I~
//**********************************************************************
void win_endjob(int Pendsw);                                       //~v844R~
//*********************************************************************//+v92fR~
int  win_getmaxline(int Pformtype,int Ppitch);                     //+v92fR~
//*********************************************************************//+v92fR~
int  win_getmaxcol(int Pformtype,int Pnonumsw,int Ppitch);         //+v92fR~
