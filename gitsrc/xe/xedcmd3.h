//*CID://+v72BR~:                                                  //+v72BR~
//**************************************************************** //~v59cI~
//xedcmd3.h                                                        //~v59cI~
//**************************************************************** //~v59cI~
//v72B:061205 3270:like rsh,use =6 panel as TSO terminal screen "tso "tostid TSO"/Exit//+v72BI~
//v71N:061107 (3270)support "#"/% dlcmd for TSO file               //~v71NI~
//v59C:041120 xen command. xenv {< file| var[=[value]]}            //~v59CI~
//v59g:041107 rsh:set MOCMD screen as rlogin                       //~v59gI~
//v59c:041107 % lcmd:remote support(use rsh)                       //~v59cI~
//**************************************************************** //~v59cI~
	FTFUNC dcmd_xenv;                                              //~v59CI~
#define TSOSUBCMD    "sub"                                         //~v71NM~
//**************************************************************** //~v59CI~
int dcmdrshlocalfile(PUCLIENTWE Ppcw,PUFILEH Ppfh,char *Pcmdfile,char *Pstdofnm,char *Pstdefnm);//~v59cR~
//**************************************************************** //~v59CI~
int dcmdxenvfile(int Popt,char *Pfnm);                             //~v59CI~
#define DCMDENV_INIT 0x01                                          //~v59CI~
//**************************************************************** //~v59CI~
int dcmdenvinit(char *Postype);                                    //~v59CR~
                                                                   //+v72BI~
#ifdef FTPSUPP                                                     //+v72BI~
//**************************************************************** //+v72BI~
    int dcmdrloginlog(PUCLIENTWE Ppcw,PUFILEH Ppfh,char *Plogtext);//+v72BI~
#endif                                                             //+v72BI~
