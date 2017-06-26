//*CID://+v96eR~:                             update#=   14;       //~v96eR~
//***********************************************************      //~v831I~
//* XPINP.H                                                        //~v831I~
//***********************************************************      //~v831I~
//v96e:130724 v9.25 recfm=V(-Vvfmt) support                        //~v96eI~
//040605 v91m :additional to 90b,allow dir without wildcard        //~v91mI~
//				for also indirect file if not remote dir.          //~v91mI~
//040531 v91k (FTP)remote file print support;"<orgfname>LocalTempFile" fmt//~v91kI~
//                 on parm and indirect file.                      //~v91kI~
//010519 v907 :LINUX support(filename case sensitive)              //~v907I~
//971124 v831 :split xppf from xprint                              //~v831I~
//***********************************************************      //~v831I~
#define HDRFNM_PREFIX   '<'                                        //~v91kI~
#define HDRFNM_POSTFIX  '>'                                        //~v91kI~
#define EOL_VLINE       -2    //alternative of end of line for recfm=V//~v96eI~
//**********************************************************************//~v831I~
int getinput(void);                                                //~v831I~
#define XPGIRC_VLEN0    -2                                         //+v96eI~
//**********************************************************************//~v831I~
void 	archoff(void);                                             //~v831I~
//**********************************************************************//~v907I~
int  xpfnmcomp(char *fnm1,char *fnm2);                             //~v907I~
//**********************************************************************//~v91kI~
char *xpparsehdrfnm(char *Pfnm);                                   //~v91kI~
//**********************************************************************//~v91kI~
int findfile(char *);           //v5.8a findfirst/findnext         //~v91mR~
//**********************************************************************//~v91mI~
int findfile2(int Popt,char *parmfname);                           //~v91mR~
#define FF2OPT_DIR  0x01           //search also dir               //~v91mR~
