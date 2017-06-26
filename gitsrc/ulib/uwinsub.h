//CID://+v6unR~:          update#=     13                          //+v6unR~
//*************************************************************    //~v5c1I~
//v6un:140502 MultiByte2WideChar failes by 0xfdff(cp)-->f8f1+f8f3(ucs2) by MB_ERR_INVALID_CHARS;pass it not W func as is//+v6unI~
//v6ua:140410 (Win)use UNICODE Api;apply WIN32_FIND_DATAW by "#ifdef W32UNICODE"//~v6uaI~
//v6u9:140408 (Win)use UNICODE Api using special filename fmt.     //~v6u9I~
//v6kg:130629 errno=5(ioerr) when symlink created by mklink /D(dir) to a file//~v6kgI~
//v6k8:130623 junction is link to dir,so issue errmsg for junction to file//~v648I~
//v6k4:130525 (Win)Jnction(from xp) and Symlink(from Vista)        //~v64kI~
//v5c1:040321 add file association chk sub                         //~v5c1I~
//*************************************************************    //~v5c1I~
#ifdef W32                                                         //~v64kI~
int uwinreg_chkassociation(char *Pext);                            //~v5c1I~
//*************************************************************    //~v64kI~
int uwinlnk_delete(int Popt,ULONG Pattr,char *Pfnm);               //~v64kR~
//*************************************************************    //~v64kI~
//int uwinlnk_copy(int Popt,ULONG Pattr,char *Psrc,char *Pdest);     //~v64kI~//~v649R~
int uwinlnk_copy(int Popt,ULONG Pattr,char *Psrc,char *Pdest,char *Pslink);//~v649I~
//*************************************************************    //~v64kI~
int uwinlnk_gettarget(int Popt,ULONG Pattr,char *Pfnm,char *Ptarget,int Poutbuffsz,//~v64kR~
			int *Ppoutlen,ULONG *Ppattr,int *Pptag,PBYTE *Preparsebuff);//~v64kI~
#ifdef W32UNICODE                                                  //~v6uaI~
int uwinlnk_gettargetW(int Popt,ULONG Pattr,char *Pfnm,char *Ptarget,int Poutbuffsz,//~v6uaI~
			int *Ppoutlen,ULONG *Ppattr,int *Pptag,PBYTE *Preparsebuff,//~v6uaM~
			UWCH *PtargetW,int PtargetWsz,int *PptargetWctr,int *Ppudrc);//~v6uaR~
#endif                                                             //~v6uaI~
//*************************************************************    //~v64kI~
#define  UWINGTO_W32ATTR        0x01                               //~v64kR~
#define  UWINGTO_COPYOVERRIDE   0x02                               //~v64kI~
#define  UWINGTO_CHKTARGET      0x04                               //~v64kI~
#ifdef W32UNICODE                                                  //~v6uaI~
#define  UWINGTO_NOOUTUD        0x08  //no output with UDfmt       //~v6uaR~
#endif                                                             //~v6uaI~
                                                                   //~v64kI~
#define  UWINLNKERR_NOTREPARSE   -1                                //~v6k4I~//~v64kM~
#define  UWINLNKERR_NOTMF        -2     //3rd party repase point   //~v6k4I~//~v64kM~
//#define  UWINLNKERR_MOUNTPOINT   -3   //mount volume             //~v64kR~
#define  UWINLNKERR_OTHER        -4     //microsoft other than SYMLINC,Junction//~v6k4I~//~v64kM~
#define  UWINLNKERR_OTHERUNKNOWN -5     //mcrosoft unknown         //~v6k4R~//~v64kM~
#define  UWINLNKERR_BUFFOVF      -6                                //~v64kI~
#define  UWINLNKERR_MALLOCERR    -7                                //~v64kI~
#define  UWINLNKERR_NOAPISUPP    -8     //CreateSymbolicLinc is not supported on XP//~v64kI~
#define  UWINLNKERR_NOTARGET     -9     //targetfile not found     //~v64kI~
#define  UWINLNKERR_JUNCTIONTOFILE -10    //junction to file       //~v648I~
#define  UWINLNKERR_NOTNTFS        -11    //junction to file       //~v648I~
#define  UWINLNKERR_SLINKDTOFILE   -12    //slinkD to file         //~v6kgI~
//******************************************************************//~v64kI~
int outmbs(int Popt,UWCHART *Ptch,int Plen,char *Pch,int Pbuffsz,int *Ppoutlen);//~v6u0R~//~v6u9I~
#define UWSOMO_SETSUBCHRC    0x01       //return err if subchar was set//~v6u0I~//~v6u9I~
#define UWSOMO_BESTFIT       0x02       //translate to bestfit char//~v6u0I~//~v6u9I~
//******************************************************************//~v64kI~//~v6u9I~
//int mbs2wc(char *Ppmbs,int Plen,UWCHART *Pwch,int Pbuffsz,int *Ppoutlen);//~v6u0I~//~v6u9I~//+v6unR~
int mbs2wc(char *Ppmbs,int Plen,UWCHART *Pwch,int Pbuffsz,int *Ppoutlen,int Popt);//+v6unI~
#define UWSMWO_ALLOWCP2UERR      0x01   //ignore MultibyteToWideChar err//+v6unI~
//******************************************************************//~v6u9I~
#ifdef W32UNICODE                                                  //~v6uaI~
//******************************************************************//~v6uaI~
int uwinlnk_gettargetWW(int Popt,ULONG Pattr,UWCH *Pfnm,UWCH *Ptarget,int Poutbuffsz,//~v6uaI~
					int *Ppoutlen,ULONG *Ppattr,int *Pptag,PBYTE *Pprepasebuff);//~v6uaI~
#endif	//W32UNICODE                                               //~v6uaR~
#endif //W32                                                       //~v64kI~
