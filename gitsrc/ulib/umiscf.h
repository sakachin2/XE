//CID://+v711R~:                                                   //~v6hqR~//~v711R~
//**************************************************
//v711:201022 ftime deprecated                                     //~v711I~
//v6hq:120707 printf format "%n" disabled by default and assetion when debug mode//~v6hqI~//~v6h9M~//~v6hqM~
//v192:980905 add uchksum func
//**************************************************
unsigned long uchksum(unsigned char *Paddr,unsigned long Poffs,    //~v192I~
				unsigned long Plen,unsigned long Pprevchksum);     //~v192I~
//**************************************************               //~v192I~
unsigned long uaddc(unsigned long Pv1,unsigned long Pv2);          //~v192I~
#ifdef VC10EXP                                                     //~v6hqI~//~v6h9M~//~v6hqM~
//**********************************************************       //~v6hqI~//~v6h9M~//~v6hqM~
int uwin_enablecountoutput(int Penable);                           //~v6hqI~//~v6h9M~//~v6hqM~
#endif                                                             //~v6hqI~//~v6h9M~//~v6hqM~
#ifdef UFTIME                                                      //+v711I~
int uftime(struct timeb* buff);                                    //~v711R~
#endif                                                             //+v711I~
