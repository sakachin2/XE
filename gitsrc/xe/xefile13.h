//**Fixed-CID://+v9@8R~:**                                         //+v9@8R~
//**************************************************************** //~v0d5I~
//xefile13.h                                                       //~v0d5I~
//**************************************************************** //~v0d5I~
//v9@8:080717 3270:fs mode del excluded line                       //+v9@8I~
//v9@5:080717 3270:TSO FS mode;draw update line only for performance//~v9@5I~
//v585:040823 cap performance up;skip undo data save when clipboard repl//~v585I~
//v41o:010820 cobol UFCleft=6                                      //~v41oI~
//v173:000430 ajust linenosz when num XON/XOFF                     //~v173I~
//v0fs:971109 (BUG)fullpath fail when select cmd with quatation    //~v0fsI~
//v0d5:970831 split xefile13 from xefile,fileregist etc.           //~v0d5I~
//**************************************************************** //~v0d5I~
int fileplhfail(PUFILEH Ppfh);                                     //~v0d5I~
//****************************************************************//~5118I~
int fileclosefree(PUFILEC Ppfc);                                //~5118I~
//**************************************************************** //~v0d5I~
int fileclosefree2(PUFILEH Ppfh);                                  //~v0d5I~
//**************************************************************** //~v0d5I~
int fncomp(PUQUEE Ppfnqe,PVOID Ppfname);                           //~v0d5I~
//**************************************************************** //~v0d5I~
void filefree(PUFILEH Ppfh);                                       //~v0d5I~
//**************************************************************** //~v0d5I~
PUCLIENTWE fileregist(PUCLIENTWE Ppcw,int Ppanelid,PUFILEH Ppfh,int Peditsosw);//~v0d5I~
//**************************************************************** //~v0fsI~
int filefnquate(char *Pfnm);                                       //~v0fsI~
//**************************************************************** //~v0d5I~
int filelinemallocerr(long Plineno);                               //~v0d5I~
//**************************************************************** //~v173I~
int filecalclinenosz(PUFILEH Ppfh);                                //~v173I~
//**************************************************************** //~v41oI~
int fileinitialleft(PUFILEC Ppfc,PUFILEH Ppfh);                    //~v41oI~
//**************************************************************** //~v585I~
void filefreealldataplh(PUFILEH Ppfh);                             //~v585R~
//**************************************************************** //~v9@5I~
void fileresetundoable(int Popt,PUFILEH Ppfh);                     //~v9@5R~
#define FSUO_CLEARLCMD 0x01         //clear lcmd                   //+v9@8I~
