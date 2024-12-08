//CID://+v053R~:                                                   //~v053I~
//******************************************************           //~v053I~
//*udpmivio.h DPMI vio functions                                   //~v053R~
//*************************************************************    //~v053I~
//v053:970107:gcc version(control by DPMI)                         //~v053R~
//******************************************************           //~v053I~
//*******************************************************          //~v053I~
//*udpmivio_init                                                   //~v053I~
//*get parm from uvio                                              //~v053I~
//*parm1:screen width                                              //~v053I~
//*parm2:screen height                                             //~v053I~
//*ret  :none                                                      //~v053I~
//*******************************************************          //~v053I~
void udpmivio_init(int Pwidth,int Pheight);                        //~v053I~
                                                                   //~v053I~
//********************************************************************//~v053I~
//*udpmiviogettext                                                 //~v053I~
// interface to gcc gettext(read char+attr from video buff)        //~v053I~
// parm1:output buff                                               //~v053I~
// parm2:request len                                               //~v053I~
// parm3:row                                                       //~v053I~
// parm4:col                                                       //~v053I~
//********************************************************************//~v053I~
int udpmiviogettext(PCH pchCellStr,int Pcelllen,int Prow,int Pcol);//~v053I~
                                                                   //~v053I~
//********************************************************************//~v053I~
//*udpmivioputtext                                                 //~v053I~
//*interface to gcc putettext(write char+attr to video buff)       //~v053I~
// parm1:output buff                                               //~v053I~
// parm2:request len                                               //~v053I~
// parm3:row                                                       //~v053I~
// parm4:col                                                       //~v053I~
//********************************************************************//~v053I~
int udpmivioputtext(PCH pchCellStr,int Plen,int Prow,int Pcol);    //~v053I~
                                                                   //~v053I~
