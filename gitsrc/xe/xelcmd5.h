//*CID://+v74PR~:                             update#=    8;       //+v74PR~
//**************************************************************** //~8A11I~
//*xelcmd5.h                                                       //~8A11I~
//**************************************************************** //~8A11I~
//v74P:070325*BNDS support for "=" lcmd                            //+v74PI~
//v74M:070328 lcmd lower support                                   //~v74MI~
//v69L:060713 cap(CAPS LOCK On) support;add "U" lcmd(uppercase translation)//~v69LI~
//v62J:050413 new lcmd(!):execute cmd on the line                  //~v62JI~
//v497:020617 TC cmd new operation "=="(sting compare)             //~v497I~
//**************************************************************** //~v497I~
int lcmdpairs(PUCLIENTWE Ppcw,ULCMD *Pplcc,ULCMD *Pplcd);          //~8A11I~
//**************************************************************** //~v497I~
//void lcmdunmatch(int Poffs,int P1stsw,PULINEH Pplh1,PULINEH Pplh2,//+v74PR~
void lcmdunmatch(int Poffs1,int Poffs2,int P1stsw,PULINEH Pplh1,PULINEH Pplh2,//+v74PI~
                    PUFILEH Ppfh1,PUFILEH Ppfh2,int Punmathlen);   //~v497I~
//**************************************************************** //~v62JI~
int lcmdexec(PUCLIENTWE Ppcw,PULINEH Pplh1,PULINEH Pplh2,int Popt);//~v62JR~
//**************************************************************** //~v69LI~
int lcmdupper(PUCLIENTWE Ppcw,PULINEH Pplh1,PULINEH Pplh2,int Prepeat,int Pbandle,int Pskip);//~v69LR~
//**************************************************************** //~v74MI~
int lcmdlower(PUCLIENTWE Ppcw,PULINEH Pplh1,PULINEH Pplh2,int Prepeat,int Pbandle,int Pskip);//~v74MI~
