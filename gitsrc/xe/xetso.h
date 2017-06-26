//*CID://+v9@6R~:                                                  //~v9@6R~
//****************************************************************
//xetso.h
//****************************************************************
//v9@6:080717 3270:TSO cmd initial 3270/TSO mode option            //~v9@6I~
//v9@5:080717 3270:TSO dbcs cursor(2byte reverse)                  //~v9@5I~
//v8@Z:080715 3270:TSO keyboard mode by A+q                        //~v8@ZI~
//v78Z:080708 (3270)sw key assignment by hot key                   //~v78ZI~
//v8@F:080629 3270:NUMSTD consideration when SJIS=>EBC translation(SO/SI insert case)//~v8@BI~
//v8@B:080627 3270:submit cmd support by TSO SUBMIT cmd            //~v8@BI~
//v8@s:080621 3270:dbcs conversion support                         //~v8@sI~
//            pass recfm and lrecl,convert at xe3270 the use binary mode transfer//~v8@sI~
//v8@i:080619 TSO:"=6.TSOxx" support                               //~v8@iI~
//v72B:061205 3270:like rsh,use =6 panel as TSO terminal screen "tso "tostid TSO"/Exit//~v72nI~
//v72n:061127 3270:spf cmd to update spf info                      //~v72nI~
//v71H:061103 (3270)for RECFM=F,set UFHlrecl                       //~v71HI~
//v71g:061014 3270:copy/move support                               //~v71gI~
//v71a:061005 3270:dirlist:display filesize if once downloaded from localfile//~v71aI~
//v717:060926 3270:dirlist support                                 //~v717I~
//v70z:060904 3270 ftp support
//****************************************************************
#ifdef FTPSUPP                                                     //~v70zI~
typedef struct _KBD3270 {                                          //~v78ZI~
						USHORT K3270key[4];     //normal/shift/alt/ctl//~v78ZR~
                        char  *K3270action[4];                     //~v78ZR~
                        UINT   K3270flag;                          //~v8@ZI~
#define K3270F_NOTSO       0x01000000       //reject if emulation mode//~v8@ZR~
#define K3270F_SWTSO       0x02000000       //tso mode sw key      //~v8@ZI~
#define K3270F_ACTION      0x04000000       //action cmd           //~v8@ZI~
						} KBD3270,*PKBD3270;                       //~v78ZI~
//**************************************************************** //~v78ZI~
int xetsoinit(int Popt);                                           //~v70zR~
//****************************************************************
int xetsoxcopy(int Popt,PUFTPHOST Ppuftphs,PUFTPHOST Ppuftpht,
//  		UCHAR *Psource,UCHAR *Ptarget,int Pcopyopt,unsigned Pattrmask);//~v8@sR~
    		UCHAR *Psource,UCHAR *Ptarget,int Pcopyopt,unsigned Pattrmask,/*PUTSOFTPPARM*/ void *Putsop);//~v8@sR~
#define XETSOXCOPY_GRPMASK    0xffff     //xeftpgetremotecopy option mask//~v71gI~
#define XETSOXCOPY_BIN        XEFTPO_BIN //0x010000 binary mode    //~v71gM~
#define XETSOXCOPY_SETBYSRCF  0x020000   //set ftpparm by source filename//~v8@BI~
#define XETSOXCOPY_SETBYTGTF  0x040000   //set ftpparm by target filename//~v8@BI~
//****************************************************************
int xetsoupdatechk(PUCLIENTWE Ppcw,PUFILEH Ppfh);  
//****************************************************************
int xetsofilefindcopy(int Pmsgopt,PUFTPHOST Ppuftph,UCHAR *Phostfile,
				char *Plocalfnm,FILEFINDBUF3 *Ppfstat3);
//****************************************************************
int xetsosave(int Popt,PUFILEH Ppfh,PUFTPHOST Ppuftpht,
			UCHAR *Psource,UCHAR *Ptarget,int Pcopyopt,unsigned Pattrmask);
#define XETSOSO_OUTFILE      0x01  //not output to itself          //~v72nR~
#define XETSOSO_OUTPARTIAL   0x02  //output is partial by rep/cre/app cmd//~v72nR~
#define XETSOSO_OUTNEW       0x04  //output is not exist           //~v72nI~
//****************************************************************
char *xetsofilefullpath2ndedit(char *Pfullpath,PUFILEH Ppfh,char *Pmodifier);
//****************************************************************
char *xetsofilefullpath2(char *Pfullpath,char *Ptarget,size_t Plen,char *Psource);
//**************************************************************** //~v70zI~
int xetsolocalfstat(PUFILEH Ppfh,FILEFINDBUF3 *Ppfstat3);          //~v70zI~
//**************************************************************** //~v71HI~
int xetsodefaultlrecl(PUFILEH Ppfh,FILEFINDBUF3 *Ppfstat3);        //~v71HI~
//**************************************************************** //~v717I~
int xetsogetpathlen(UCHAR *Pfilename,UCHAR *Plevel,int Pdirsw);    //~v717I~
//**************************************************************** //~v717I~
int xetsolvlfname(PUFILEH Ppfh,UCHAR *Pfullpath,int Plevel,UCHAR *Pfname,int *Plen);//~v717I~
//**************************************************************** //~v717I~
int xetsodlcgetfullname(PUFILEH Ppfh,PUDIRLH Ppdh,UCHAR *Pfname);  //~v717I~
//**************************************************************** //~v71aI~
int xetsodlcmdsetlocal(PUFILEC Ppfc,PUDIRLH Ppdh,PUFILEH Ppfh);    //~v71aI~
//**************************************************************** //~v71aI~
int xetsoconcatfilename(PUFILEH Ppfh,char *Pappendname,char *Poutfname);//~v71aI~
//**************************************************************** //~v72nI~
int xetsogetspf(PUFILEH Ppfh,FILEFINDBUF3 *Ppfstat3);              //~v72nI~
//**************************************************************** //~v72nI~
int xetsospfupdate(int Popt,PUFILEH Ppfh,PUFTPHOST Ppuftph,char *Pfpath);//~v72nR~
//**************************************************************** //~v72nI~
int xetsotsocmd(PUCLIENTWE Ppcw);                                  //~v72nI~
//**************************************************************** //~v72nI~
int xetsotsocmdlogon(int Popt,PUCLIENTWE Ppcw,PUFTPHOST Ppuftph);  //~v72nR~
#define XETSOCMDO_LOGOFF  0x01                                     //~v72nR~
#define XETSOCMDO_LOGONFS 0x02                                     //~v72nI~
#define XETSOCMDO_LOGONFS3270     0x10      //fullscreen 3270      //~v9@6I~
#define XETSOCMDO_LOGONFS3270TSO  0x20      //fullscreen 3270 TSO  //~v9@6I~
//**************************************************************** //~v8@iI~
int xetsorsh6(int Popt,char *Poutcmd,char *Pincmd);                //~v8@iI~
//**************************************************************** //~v8@sI~
int xetsosetftpparm(int Popt,PUFTPHOST Ppuftph,/*PUTSOFTPPARM*/ void *Pptsop,void *Pparm);//~v8@sR~
#define XETSOFTPO_DBCSCONV       0x01       //do DBCS conversion   //~v8@sR~
#define XETSOFTPO_FFB3           0x02       //Ppfh is not pfh but filefindbuf3//~v8@sI~
#define XETSOFTPO_FPATH          0x04       //Ppfh is not pfh but fullpathname//~v8@sI~
#define XETSOFTPO_CHKPROF        0x08       //profile will be chked only when upload by filename//~v8@BR~
//**************************************************************** //~v8@BI~
int xetsosubmit(int Popt,PUFTPHOST Ppuftph,char *Premotefpath,char *Plocaltempfnm);//~v8@BR~
//**************************************************************** //~v8@BI~
int xetsoquery(int Popt,PUFTPHOST Ppuftph,char *Pparm,char *Pvalue);//~v8@BI~
//**************************************************************** //~v78ZI~
UCHAR *xetsosetup3270keymap(void);                                 //~v78ZI~
#define  KEY3270_SHIFTMASK   0xc0      //1:shift,2:alt,3:ctl       //~v78ZR~
#define  KEY3270_INDEXMASK   0x3f      //max 63 scancode,index to  //~v78ZI~
#define  KEY3270_FLAGSHIFT    6        //flag bit shift count      //~v78ZR~
//**************************************************************** //~v78ZI~
int xetsois3270key(int Popt,PUCLIENTWE Ppcw,int Pkeytype,UCHAR *Pscanchar);//~v78ZR~
#define TI3KO_RCTLENTER     0x01                                   //~v78ZI~
#define TI3KO_RCTLNEWLINE   0x02                                   //~v78ZI~
//**************************************************************** //~v78ZI~
int xetsoupdateplh(int Popt,PUCLIENTWE Ppcw,PULINEH Pplh,char *Pdata,int Plen);//~v9@5I~
#define  XETSOUL_CMDLOG     0x01        //topline                  //~v9@5M~
#define  XETSOUL_ISRT       0x02        //insert line at first open//~v9@5I~
#define  XETSOUL_DELX       0x04        //del exclude hdr          //+v9@6I~
#endif //FTPSUPP                                                   //~v78ZR~
