//CID://+v865R~:                                                   //~v865I~
//***********************************************************      //~v865I~
//* XPJOB.H                                                        //~v865I~
//***********************************************************      //~v865I~
//981024 v865 :(OS2)docname set by startdoc api                    //~v865I~
//**********************************************************************//~v865I~
int os2_devinit(UCHAR *Pport,int Pdestprnsw,int Pdocnamesw);       //+v865R~
//**********************************************************************//~v865I~
unsigned long os2_putline(char *Pbuff,unsigned long Plen);         //~v865R~
//**********************************************************************//~v865I~
void os2_opendoc(void);                                            //~v865R~
//**********************************************************************//~v865I~
void os2_closedoc(void);                                           //~v865I~
//**********************************************************************//~v865I~
void os2_endjob(int Pendjobsw);                                    //~v865I~
