//CID://+vbyxR~:        update#=    114                            //+vbyxR~
//******************************************************           //~v327I~
//*ufilel.h   UNIX version                                         //~v327I~
//******************************************************           //~v327I~
//vbyx:230725 ARM:alternative of vbyr. drop copytemp but rep // by real path if available://+vbyxI~
//vc5r 2023/07/25 try /sdcard for realpath for api<30              //~vc5rI~
//vc5n 2023/07/19 copyDoc needs copy timestamp                     //~vc5nI~
//v77Z:230718 ARM;support CD to shared storage                     //~v77ZR~
//vc5c 2023/07/04 display directory set to access by ACTION_OPEN_DOCUMENT_TREE//~vc5cI~
//v77z:230530 >=API30, support shared storage for cmd parameter. by v77W, replace sortpath by real path name on cmd parm.//~v77zI~
//vbyh:230514 (ARM)dlcmd "=" support for external storage          //~vbyhI~
//v77m:230429 ARM:try stat(fpath) by fstat(fd) for ufstat          //~v77mI~
//v77h:230424 ARM;copy                                             //~v77hI~
//v77g:230424 ARM;rename                                           //~v77gI~
//v77f:230424 ARM;rmdir                                            //~v77fI~
//v77d:230423 ARM;delete                                           //~v77dI~
//v77c:230422 ARM;mkdir                                            //~v77cI~
//v77b:230415 ARM;edit file                                        //~v77bI~
//v77a:230415 split ufile1l to ufiledoc                            //~v77aI~
//v779:230414 update v777,set uri at ulib fro shortpath            //~v779I~
//v777:230403 ARM;udirlistFD                                       //~v777I~
//******************************************************           //~v327I~
#ifdef ARMXXE                                                      //~v777R~
//*******************************************************          //~v77bM~
typedef struct _DOC_HANDLE                                         //~v77bI~
         {                                                         //~v77bI~
            UQUEE   qelem;                                         //~v77bI~
#define DOCH_ACRONYM "DOC"                                         //~v77bR~
            char acronym[4];                                       //~v77bR~
            int optRC,bufferLen,fd;                                   //~v77bI~//~v77dR~
            char *buffer;	//string mode string, udirlist for opendir//~v77dR~
            char *fpath,*strUri;                                   //~v77dI~
            char *rpath;	//real path                            //~v77zI~
            char *rpath29;	//real path for for api<30             //~vc5rI~
            FILE *privateFH;                                       //~v77bI~
            void *pde;                                             //~v77dM~
            void *pdir;      // DIR*,when ROPT_OPENDIRFD                                      //~v77dR~//~v77hR~
                                                                   //~v77bI~
            int bufferOffs;                                        //~v77bI~
            int swClosed;                                          //~v77bI~
            int err;                                               //~v77bI~
         } DOC_HANDLE;                                             //~v77bI~
typedef DOC_HANDLE *PDOC_HANDLE;                                   //~v77bI~
#define DOC_HANDLESZ sizeof(DOC_HANDLE)                            //~v77bI~
                                                                   //~v77bM~
unsigned int ufstatDoc(char *Ppfile,FILEFINDBUF3 *Ppffb3,int PswFindFirst);         //~v77aI~//~v77dR~
//int udirlistFD(int Popt,char *Palias,char* Ppath,char *Pstruri,int PdirFD,unsigned Pattr,PUDIRLIST*Pppudirlist,int Psorttype);//~v777R~
int udirlistDoc(int Popt,char *Pstruri,unsigned Pattr,PUDIRLIST*Pppudirlist,int Psorttype);//~v777R~
#define UDL_NOMSG      0x01                                        //~v777R~
                                                                   //~v777I~
int parseMemberData(char *PmemberData,int PlenData,int Popt,char *PnameDir,char *Pstruri,unsigned Pattr,UDIRLIST **Pppudirlist);//~v777R~
int makeDocPath(char *Palias/* start by '//' */,char *PstrUri,char *Pfpath);//~v777R~
int parseDocPath(char *Pfpath/* //alias:struri */,char *Palias,char **PppstrUri);//~v777R~
int upathlenDoc(int Popt,char *Pfilename,int *Pproot,int *PpswRoot,int *PplenPrefix,char *Palias);//~v777R~
void ufile_notify_shortpath(UQUEH  *Ppqhsp);                       //~v779I~
                                                                   //~v77bI~
int ufile_openDoc(int Popt,char *Pfpath,char *Popenopt,FILE **Ppfh);//~v77bI~
#define ROPT_DEPEND_FILESIZE    0x01	//return string of full file contents//~vc4sI~//~v77bI~
#define ROPT_STRING             0x02	//return string of full file contents//~vc4sI~//~v77bI~
#define ROPT_COPYPRIVATE        0x04 	//copy to private dir,then return fullpath name//~vc4sR~//~v77bI~
#define ROPT_OPEN               0x08 	//read line by following READLINE request//~vc4sR~//~v77bI~
#define ROPT_BINARY             0x10 	//binary file//~vc4sR~     //~v77bI~
#define ROPT_READLINE           0x20 	//after OPEN,read a line//~vc4sI~//~v77bI~
#define ROPT_INPUT              0x40 	//open input mode          //~v77bI~
#define ROPT_APPEND             0x80 	                           //~v77bI~
#define ROPT_OPENDIR          0x0100    //emulate DIRH(opendir/readdir:dirent),buff is udirlist//~v77dI~
#define ROPT_OPENDIRFD        0x0200    //opendir using fd,and accept readdir         //~v77dI~//~v77hR~
#define ROPT_RC_ERR_TOOBIG  0x010000      //~vc4sI~                //~v77bR~
#define ROPT_REALPATH29     0x020000    //output of getDocPath     //~vc5rI~
                                                                   //~v77bI~
//#define DOCFH_SIGN       (unsigned long)0x01    //emulate openDoc FILE* STRING mode//~v77bR~
#define IS_DOCFH(fh) ((fh) && !strcmp(DOCH_ACRONYM,((PDOC_HANDLE)(fh))->acronym))//~v77bR~
#define IS_DOCDIRH(hdir) ((hdir) && !strcmp(DOCH_ACRONYM,((PDOC_HANDLE)(hdir))->acronym))//~v77dI~
                                                                   //~v77bI~
//void ufile_openDocResult(char *Pfpath,int Popt,int PrcOpt,char *Pbuff/*utf8str or byte[]*/,int Plen);//~v77bR~
char *ufile_fgetsDoc(char *Pbuff,int Pbuffsz,void* Phandle);       //~v77dR~
//UINT ufile_freadDoc(void *Pbuff,UINT Psize,UINT Pctr,void *Phandle);//~v77bR~
size_t ufile_fwriteDoc(void *Pbuff,size_t Psize,size_t Pctr,void* Phandle);//~v77bI~
int ufile_mkdirDoc(char *Ppath,mode_t Pmode);                      //~v77cR~
int ufile_rmdirDoc(char *Ppath);                                   //~v77fI~
int ufile_unlinkDoc(char *Ppath);                                  //~v77dI~
int ufile_opendirDoc(char *Pfpath,void **Pphdir);                  //~v77dR~
struct dirent *ufile_readdirDoc(void *Ppdir);                      //~v77dR~
int ufile_renameDoc(char *Pold,char *Pnew);                        //~v77gI~
int ufile_copyDoc(int Popt,char *Psrc,char *Ptgt);                 //~v77hR~
int ufile_statDoc(char *Pfpath,void *Ppstatbuff);                  //~v77mR~
#define UFCDO_APPEND 0x01                                          //~v77hR~
int ufile_getCopyTemp(int Popt,char *Pfpath,char *Ptempfnm);       //~vbyhI~
#define UFGCTO_INIT 0x01                                           //~vbyhI~
int ufile_isGrantedAllFiles();                                     //~v77zI~
int ufile_isGrantedMemberAccess();                                 //+vbyxI~
int ufile_getRealpath(char *Pshortpath,char *Prpath,char *PstrUri);//~v77zR~
int getShortpathRootLen(char *Pshortpath);                         //~v77zR~
                                                                   //~v77zI~
void ufiledoc_notify_sp_changed();                                 //~vc5cI~
char *ufiledoc_cwd(unsigned char *Pbuff);                          //~v77ZR~
char *ufiledoc_cwdReal(unsigned char *Pbuff);                      //~vc5rI~
int ufiledoc_chdir(int Popt,unsigned char *Ppath,int *Pprc);       //~v77ZR~
int ufiledoc_utimes(char *Pfnm,struct timeval *Ptv);               //~vc5nI~
int ufiledoc_setArmPWD(int Popt,unsigned char *Ppath);             //~vc5nI~
#endif  //ARMXXE                                                   //~v777I~//~v77bR~
