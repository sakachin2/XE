//CID://+v9e0R~:             update#=     5                        //~v9e0R~
//***********************************************************      //~v831I~
//* XPPF.H                                                         //~v831I~
//***********************************************************      //~v831I~
//v9e0:170807 v9.38 tabchar support(tabon:c/x__/u__)               //~v9e0I~
//100706 v950 v9.18 64bit compile                                  //~v950I~
//071005 v928 (Win)UTF8 support                                    //~v928I~
//971124 v831 :split xppf from xprint                              //~v831I~
//***********************************************************      //~v831I~
//**********************************************************************//~v831I~
#define DBCSSPACE_UCS   0x3000                                     //+v9e0I~
//**********************************************************************//~v831I~
void printfile(void);                                              //~v831R~
//**********************************************************************//~v831I~
// print header v6.7a                                              //~v831I~
//**********************************************************************//~v831I~
void printhdr(void);                                               //~v831I~
//**********************************************************************//~v831I~
//* 1 line print if in specified page ***                          //~v831I~
//**********************************************************************//~v831I~
void pline(void* area,int unit,int count,FILE* file);//v3.5r       //~v831I~
//**********************************************************************//~v928I~
#ifdef UTF8SUPP                                                    //~v928I~
//  void datapline_ucs(UCHAR *Pbuff,USHORT *Ppucs,int Pcount,FILE* file);//~v928R~//~v950R~
    void datapline_ucs(UCHAR *Pbuff,WUCS *Ppucs,int Pcount,FILE* file);//~v950I~
#endif                                                             //~v928I~
int getTabon(char *Pparm);                                         //~v9e0I~
int chkTabon();                                                    //~v9e0M~
int getTabonAltch(int Ptype,int Ptype2);                           //+v9e0M~
