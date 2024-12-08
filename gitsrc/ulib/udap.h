//CID://+v262R~:                                                   //+v262R~
//*************************************************************    //~v213I~
//*udap.h                                                          //~v213I~
//*************************************************************    //~v213I~
//v262:990704 disas:set DOS int 21 comment                         //+v262I~
//v254:990626 disas:DOS MZ support(direct far call label ref)      //~v254I~
//v246:990620 disas:DOS MZ support                                 //~v246I~
//v227:990228 disas:int20 follow dword vxd id                      //~v227I~
//v213:981226 disas:adcon chk for indirect call/jump               //~v213I~
//*************************************************************    //~v213I~
    INSTPROC udap_aiajc;                                           //~v213R~
    INSTPROC udap_aiajcF;	//indirect Far Call/JMP                //~v246I~
    INSTPROC udap_directF;	//direct Far Call/JMP(use dos only)    //~v254I~
    INSTPROC udap_int;                                             //~v227I~
    INSTPROC udap_int21AX;                                         //+v262I~
