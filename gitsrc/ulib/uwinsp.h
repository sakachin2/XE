//CID://+v190R~:   update#=     1                                  //+v190R~
//*************************************************************    //~v190I~
//v6hd:120616 for VC6:/W4 warning except C4115,C4214.C4100,C4244,C4706,C4210//+v190I~
//v190:980802 add member uwinsp.c(windows system programming)      //~v190I~
//*************************************************************    //~v190I~
void *uwinsp_gettib(void);                                         //~v190I~
//*************************************************************    //~v190I~
void *uwinsp_getpdb(void);                                         //~v190I~
//*************************************************************    //~v190I~
void *uwinsp_gethandlevalue(HANDLE Phandle);                       //~v190I~
//*************************************************************    //~v190I~
int uwinsp_getvxdhande(char *Pvxdnm,HANDLE *Pphandle);             //~v190I~
//*************************************************************    //~v190I~
int uwinsp_getvxdddb(WORD Pvxdid,char *Pvxdnm,void **Pppddb);      //~v190I~
//*************************************************************    //~v190I~
int uwinsp_getvxdservice(DWORD Pservice,void **Pppfunc);           //~v190I~
//*************************************************************    //~v190I~
int uwinsp_getvcondtop(void **Pptop);                              //~v190I~
//*************************************************************    //~v190I~
int uwinsp_getcurrenteventhdr(HANDLE Phandle,void **Ppevh);        //~v190M~
//*************************************************************    //~v190I~
//int uwinsp_getcurrentconid(HANDLE Phandle,int *Pconid);          //+v190R~
int uwinsp_getcurrentconid(HANDLE Phandle,DWORD *Pconid);          //+v190I~
