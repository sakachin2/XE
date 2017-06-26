//CID://+vb06R~:      update#=    11                               //~vb06R~
//*********************************************************************//~5318I~
//*xefsub.h                                                     //~5318I~
//* common routine for file                                     //~5318I~
//*********************************************************************//~v0fmI~
//vb06:150313 (BUG)others for \\.\; change strategy(del vb03 to vb05),set to UFHfilename without \\.\ ;//+vb06R~
//vazg:150112 (BUG)lrecl overflow chk was not done                 //~vazgI~
//vaz0:150105 BUG:offset value is long for fseek error msg         //~vaz0I~
//vavc:140421 (Win)unicode support(UD fmt string)                  //~vavcI~
//vagE:120918 apply cmdline option /U{N|F}{8|L} to also edit/browse cmd//~vagEI~
//va81:100920 (WXEXXE)print ebcfile by ucs for alos wxp **/*** option//~va81I~
//va7L:100905 undo support for EBC SETCP cmd                       //~va7LI~
//va1E:091116 optionaly(default) keep original value when UTF8 code err at load//~va00I~
//va00:090510 merge utf8 version(enclosed by UTF8SUPPH)            //~va00I~
//          header line filename cv f2l                            //~va00I~
//          files encoded by utf8                                  //~va00I~
//          save option "IE"(ignore translation err)               //~va00I~
//v92n:080802 (UTF)add  [cplc|cpu8] option for save cmd            //~v92nI~//~va00I~
//v76X:071107 save option [NB|BK]                                  //~v76XI~
//v76x:070820 keep bkup by rename for the case abend at save       //~v76xI~
//v66f:051021 (BUG)A+F9 abend when A+F7 on same excludeline and pos1>pos2//~v66fI~
//v55X:040318 (!UNX)update permission warning(read only chk)       //~v55XI~
//v55P:040318 (UNX)update permission warning                       //~v55PI~
//v542:031223 (WIN,UNX)remote file edit/save                       //~v542I~
//v50e:021229 dbcs conv cont line support                          //~v50eI~
//v179:000501 (BUG)when n line join is overflow,errmsg "Already one of split line"//~v179I~
//            So,join to split last line.                          //~v179I~
//v178:000430 renum support for lineno hex mode                    //~v178I~
//v13j:991029 (BUG)It should not be end when close err by disk space shortage.//~v13jI~
//            chk also close err(flush err) at save then notify and wait.//~v13jI~
//v0i0:980429 lcmd skip/bandle support                             //~v0i0I~
//v0fm:971103 new function to set filename and alias to ufh        //~v0fmI~
//v08q:961123:edit partial file(continued from v08l)-err msg by ufileapierr//~v08qI~
//*********************************************************************//~5318I~
//* MACRO **********************************                    //~5318M~
#ifdef DOS                                                      //~5318M~
	#define FPOST fpos_t                                        //~5318M~
#else                                                           //~5318M~
//  #define FPOST long                                             //~vaz0R~
    #define FPOST FILESZT                                          //~vaz0I~
#endif                                                          //~5318M~
//*******************************************************          //~v76xI~
FILE *filebkupreopen(int Popt,PUFILEH Ppfh,UCHAR *Ppopt,UCHAR *Pbkupfnm);//~v76xI~
#define FBRO_DELETE 0x01                                           //~v76xI~
#define FBRO_NB     0x02     //save cmd option                     //~v76XI~
#define FBRO_BK     0x04                                           //~v76XI~
#define FBRO_RESTORE 0x08    //restore bkup                        //~va00I~
//*******************************************************       //~5318M~
FILE *filereopen(PUFILEH Ppfh,UCHAR *Ppopt);                    //~5318M~
//*******************************************************       //~5318M~
//*file seek                                                    //~5318M~
//*******************************************************       //~5318M~
int fileseek(PUFILEH Ppfh,FPOST Ppos,int Popt);                 //~5318M~
                                                                //~5318M~
//*******************************************************          //~v08qI~
int fileread(PUFILEH Ppfh,void *Pbuff,size_t Preqlen,size_t *Ppreadlen);//~v08qR~
                                                                   //~v08qI~
//*******************************************************       //~5318M~
int filewrite(PUFILEH Ppfh,void *Pbuff,size_t Plen);               //~v08qI~
//*******************************************************          //~v92nI~//~va00I~
#ifdef UTF8SUPPH                                                   //~v92nI~//~va00R~
//int filecvwrite(int Popt,PUFILEH Ppfh,PULINEH Pplh,char *Pbuff,size_t Plen);    //~v92nI~//~va00R~
int filecvwrite(int Popt,PUFILEH Ppfh,PULINEH Pplh,UCHAR *Pbuff,size_t Plen,UCHAR *Pdbcs,int Pdbcstblen);//~va00I~//~va1ER~
#define FCWRC_CVERR   991        //conversion failed               //~va00I~
#define FCWRC_VOVF    992        //RECFM=V lrecl overflow          //~vazgI~
//*******************************************************          //~va81I~
int filecvwrite_ebcxpwk(int Popt,PUFILEH Ppfh,UCHAR *Pbuff,size_t Plen);//~va81I~
#endif                                                             //~v92nI~//~va00I~
//*******************************************************       //~5502I~
int  fileeofwrite(PUFILEH Ppfh);                                   //~v13jR~
                                                                //~5318M~
//****************************************************************//~5503I~
int fileeofchk(PUFILEH Ppfh);                                   //~5503I~
                                                                //~5503I~
//**************************************************            //~5318I~
PULINEH getdisplayline(PULINEH Pplh,int Pstep,int *Ppstep);     //~5318I~
                                                                //~5318I~
//**************************************************               //~v0i0I~
PULINEH getdisplayline2(PULINEH Pplh,int Pstep,PULINEH Pplhstop,int *Ppstep);//~v0i0I~
                                                                   //~v0i0I~
//**************************************************            //~5318I~
long lineseqchk(PULINEH Pplh1,PULINEH Pplh2);                   //~5318I~
                                                                //~5318I~
//**************************************************               //~v0fmI~
//void ufilesetfhfilename(PUFILEH Ppfh,char *Plongname);           //~v542R~
int ufilesetfhfilename(PUFILEH Ppfh,char *Plongname);              //~v542I~
#ifdef UTF8SUPPH                                                   //~va00I~
	int fsubf2l(int Popt,UCHAR *Ppfnm,int Plen,UCHAR *Ppfnmlc,UCHAR **Pppfnmlc,int *Ppoutlen,int *Ppflag);//~va00R~
    #define FSUBF2LO_ALLOC       0x01	//request malloc           //~va00I~
    #define FSUBF2LO_ALLOCFULLSZ 0x02	//alloc _MAX_PATH          //~va00I~
    #define FSUBF2LO_FREEIFNZ    0x04	//free ptr is not 0        //~va00I~
    #define FSUBF2LO_FNU8        0x08	//filename encodeing       //~vagEI~
    #define FSUBF2LO_FNLC        0x10	//filename encoding        //~vagEI~
#ifdef W32UNICODE                                                  //~vavcI~
    #define FSUBF2LO_REMOTE      0x20                              //~vavcI~
#endif                                                             //~vavcI~
#endif                                                             //~va00I~
                                                                   //~v178I~
//**************************************************               //~v178I~
int fsubseteolid(PUFILEH Ppfh,PULINEH Pplh,char *Pout);            //~v178R~
                                                                   //~v179I~
//**************************************************               //~v179I~
PULINEH fsubnextlineoversplit(int Popt,PULINEH Pplh,int Pstep,PULINEH Pplhstop);//~v179R~
#define FSNL_DISPLINE    0x01	//chk only display line            //~v179I~
                                                                   //~v179M~
//**************************************************               //~v179M~
void filerepwordsetdbcstbl(PULINEH Pplh,UCHAR *Ppdata,UCHAR *Ppdbcs,int Polen,int Pnlen);//~v179M~
//**************************************************               //~v50eI~
int fsubgetmaxlen(int Popt,PUFILEH Ppfh,int *Ppmaxlen,int *Ppmaxcont);//~v50eR~
#define FSGML_TABEXP 0x01                                          //~v50eI~
//**************************************************               //~v542I~
int xefsubupdatechk(PUCLIENTWE Ppcw,PUFILEH Ppfh);                 //~v542I~
//#ifdef UNX                                                       //~v55XR~
//**************************************************               //~v55PI~
int xefsubwritepermissionchk(PUFILEH Ppfh);                        //~v55PI~
//#endif                                                           //~v55XR~
//**************************************************               //~v66fI~
int xefsubresetcsrplh(PUCLIENTWE Ppcw,PULINEH Pplh);               //~v66fI~
//**************************************************               //~va7LI~
int fsubresetebcdbcstbl(int Popt,int Poldhandle,PUCLIENTWE Ppcw,PUFILEH Ppfh);//~va7LI~
//**************************************************               //~vb06I~
#ifdef W32                                                         //~vb06I~
int ufilesetfhfilename_reservedname(int Popt,PUFILEH Ppfh,char *Pfpath);//~vb06I~
#endif                                                             //~vb06I~
