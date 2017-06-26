//CID://+v214R~:                                                   //~v214I~
//*************************************************************    //~8411I~
//*xua2.h                                                          //~8411I~
//*************************************************************    //~8411I~
//v214:981227 disas:use labt for 1-path disas(foward label)        //~v214I~
//*****************************************************************//~8411I~
int udisas1(PDAPARM Ppdap,UCHAR *Pplabt,PDAREQ *Pppdar,UINT *Ppstat,UCHAR *Pcaddr);//+v214R~
//*for Ppstat                                                      //~v214I~
#define DAPSTPH1     0x0001         //phase1                       //~v214I~
#define DAPSTPH2     0x0002         //phase2                       //~v214I~
//#define DAPSTLAB     0x0004         //label required             //~v214R~
//#define DAPSTABSA    0x0008         //dump absolute addr         //~v214R~
//*****************************************************************//~8411I~
