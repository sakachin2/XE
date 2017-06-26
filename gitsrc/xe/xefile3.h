//**Fixed-CID://+v55qR~:**                                         //+v55qR~
//****************************************************************
//xefile3.h
//****************************************************************
//v55q:040228 option to scroll by csr move(CSRSCROLL option)       //+v55qI~
//v137:991003 scroll down when reached to bottom line by field full on dir list//~v137I~
//v0dv:970914 spf scroll for find/change cmd                       //~v0dvI~
//*v03n:950819:initial scroll option from xe.ini                //~v03nI~
//*v013 950624 find scroll size(export calc half scroll size func)//~v013I~
//****************************************************************
int filescrollchk(PUCLIENTWE Ppcw);
//**************************************************            //~5423I~
int filecharcsr(PUCLIENTWE Ppcw);                               //~5423I~
//***********************************************               //~v013I~
int filehalfhscrollsz(PUCLIENTWE Ppcw);                         //~v013I~
//***********************************************               //~v013I~
int filehalfvscrollsz(PUCLIENTWE Ppcw);                         //~v013I~
//***********************************************               //~v013I~
int filechkscrollopd(UCHAR *Popd);                              //~v013I~
//***********************************************               //~v013I~
int filesetscrollsz(PUCLIENTWE Ppcw,UCHAR *Popd);               //~v013I~
//***********************************************               //~v03nI~
UCHAR *filegetscrollid(int Pscrollid);                          //~v03nI~
//*************************************************************    //~v0dvI~
int filepgrighthalf(PUCLIENTWE Ppcw);                              //~v0dvI~
//*************************************************************    //~v137I~
int filepgdownhalf(PUCLIENTWE Ppcw);                               //~v137M~
//*************************************************************    //+v55qI~
int filepguphalf(PUCLIENTWE Ppcw);                                 //+v55qI~
//*************************************************************    //+v55qI~
int filepglefthalf(PUCLIENTWE Ppcw);                               //+v55qI~
