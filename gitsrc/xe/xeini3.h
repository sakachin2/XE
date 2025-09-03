//CID://+vbD2R~:            update#=   1                           //+vbD2R~
//****************************************************************
//*xeini3.h
//****************************************************************
//vbD2:250624 save funkkey/shortcut cmd to another file for save operation in multiple sessions//+vbD2I~
//v11z:990821 support filename=* (last closed file) on cmd line    //~v11zI~
//v11y:990821 support /R option to restore previous default drv/directory//~v11yI~
//****************************************************************
//****************************************************************
int inisaveopt(void);
//****************************************************************
int inigetopt(void);                                               //~v11yR~
//**************************************************************** //~v11yI~
void inisavecd(UCHAR *Pfullpath);                                  //~v11yR~
//**************************************************************** //~v11yI~
void inirestcd(void);                                              //~v11yM~
//**************************************************************** //~v11zI~
void inisavelastfile(PUFILEC Ppfc);                                //~v11zR~
//**************************************************************** //~v11zI~
UCHAR inigetlastfile(UCHAR *Pcmdstr);                              //~v11zR~
//**************************************************************** //+vbD2I~
int iniacronymwrite(FILE *Pfh);                                    //+vbD2I~
int iniacronymchk(char *Pfile,FILE *Pfh);                          //+vbD2I~
