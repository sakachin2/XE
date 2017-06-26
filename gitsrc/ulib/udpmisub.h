//CID://+v151R~:                                                   //+v151R~
//******************************************************           //~v053I~
//*udpmisub.h DPMI common functions                                //~v053R~
//*************************************************************    //~v053I~
//v151:980119 (BUG:DOS/GCC)video buff direct write determined by not dbcs env//+v151I~
//            but video mode.video buff chk by int 10 ah=FE        //+v151I~
//            (none is displayed under os2 dos session when changed chev us)//+v151I~
//            add udpmiint86x(pass through es/dsetc )              //+v151I~
//v053:970107:gcc version(control by DPMI)                         //~v053R~
//******************************************************           //~v053I~
#define udpmiintdos(ireg,oreg) udpmiint86(0x21,(ireg),(oreg))      //~v053I~
                                                                   //+v151I~
//*******************************************************          //~v053I~
void udpmidosmemget(void *Pbuff,int Pdosseg,int Pdosoff,int Plen); //~v053I~
                                                                   //~v053I~
//*******************************************************          //~v053I~
void udpmidosmemput(int Pdosseg,int Pdosoff,void *Pbuff,int Plen); //~v053I~
                                                                   //~v053I~
//*******************************************************          //~v053I~
int udpmiint86(int Pint,union REGS *Pregi,union REGS *Prego);      //~v053R~
                                                                   //~v053I~
//*******************************************************          //~v053I~
int udpmiint86s(int Pint,union REGS *Pregi,union REGS *Prego,struct SREGS *Psrego);//~v053I~
                                                                   //+v151I~
//*******************************************************          //+v151I~
int udpmiint86x(int Pint,union REGS *Pregi,union REGS *Prego,struct SREGS *Psrego);//+v151I~
