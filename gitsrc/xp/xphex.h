//CID://+v92bR~:                                                   //+v92bR~
//***********************************************************
//* XPHEX.H
//***********************************************************
//071006 v92b text mode vhex dump support                          //+v92bI~
//971124 v830 :split xphex from xprint                             //~v830I~
//***********************************************************
//********************************************************************
//* dump edit		v6.7a
//*   input:
//*     intc  :original char
//*     printc:printable char
//*   output:
//*     none
//********************************************************************
void printdump(UCHAR *newintc,char *newchar,ULONG offset,int len,int charlen,int lastreadc);//v7.0r
//********************************************************************//+v92bI~
void printdump3(UCHAR *Pdumpbuff,int Plen);                        //+v92bI~
