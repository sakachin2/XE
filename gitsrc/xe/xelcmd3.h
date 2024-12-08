//****************************************************************
//*xelcmd3.h
//****************************************************************
// paircmd
// process pair cmd(copy/move) 
//*rc   :0
//****************************************************************
int lcmdpair(PUCLIENTWE Ppcw,ULCMD *Pplcc,ULCMD *Pplcd);

//****************************************************************
// lcmdcopy
// process copy cmd(called from move and repeat)
//  parm1:PUCLIENTWE
//  parm2:range1 PULINEH
//  parm3:range2 PULINEH
//  parm4:range count
//  parm5:destination ULCMD
//*rc   :0
//****************************************************************
int lcmdcopy(PUCLIENTWE Ppcw,PULINEH Pplh1,PULINEH Pplh2,int Prepeat,ULCMD *Pplc);
                                                                //~5126I~
