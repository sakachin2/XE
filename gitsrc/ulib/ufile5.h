//*CID://+vbByR~:                             update#=   73;       //+vbByR~
//******************************************************        //~5B11I~
//*ufile5.h                                                        //~v090R~
//******************************************************        //~5B11I~
//vbBy:241129 Windows:for EOFid(0x1a) dir size or line-ctr         //+vbByI~
//vbBu:241119 Edit/Browse /Mz option for ebc file to accept 0x0d15 as EOL//~vbBuI~
//v77b:230415 ARM;edit file                                        //~v77bI~
//v6J7:170217 add filetouch for dummy record write for ::xehosts etc if not found//~v6y1I~
//v6y1:150303 add fullpath option to fileeditname_copypath         //~v6y1I~
//v6y0:150227 add fileeditname_copypath                            //~v6y1I~
//v6xe:150113 add ufseek and uftell for common to 32 and 64 bit    //~v6xeI~
//v6xd:150113 define 4095 as maxlen of RECFM=V 2byte MF record header//~v6xdI~
//v6x2:150106 add ufgets_seek for large binfile seek to start pos  //~v6x2I~
//v6x0:150105 BUG:offset value is long long for fseek error msg    //~v6x0I~
//v6q8:131202 (BUG)Vfmt=mfh read;header line was split,cont line disappean//~v6q8I~
//v6q7:131202 (BUG)Vfmt=mfh read err after update(not mfrecord type(System, record) was not set)//~v6q7I~
//v6m4:130802 option to output vfmt hader                          //~v6m4I~
//v6m0:130710 local file recfm=V support                           //~v6m0I~
//v6hF:120906 add ufreads(read lines containing null char)         //~v6hFI~
//v68k:100719 ufgets rc;notify by rc that bin file by the reason of long line//~v68kI~
//v68h:100715 EOLID 0x15 support for ebcdic file                   //~v68hI~
//v661:100415 record mode                                          //~v661I~
//v660:100325 local EBCDIC translation support                     //~v660I~
//v62n:090915!binchk for utf8file                                  //~v62nI~
//v5kg:070530 (3270)accept long line split by fixed lrecl at put confiramtion chk//~v5kgR~
//v5jt:061113 (3270)new filecomapre option;binary null append allows//~v5jtI~
//v5js:061111 (3270)new filecomapre option;text mode and ignore trailing space//~v5jsI~
//v5j8:060915 add ufile6.c ufilecomp for 3270 update chk           //~v5j8I~
//v56y:020807 (BUG)add ufilewildcomp func;wildcomp DBCS support    //~v55yI~
//v56x:020805 (BUG)editfilename DBCS support                       //~v55xI~
//v552:020413 mac eol(0x0d) support                                //~v552I~
//v50U:010930 udoseditnameopt used for xdc even if not unix        //~v50UI~
//v388:001009 LINUX support(option of unox like wildcard process   //~v388I~
//            (no special meaning of "." as seperator))            //~v388I~
//v279:990813 ufileeditname:udoseditname interface by fullpath parm//~v279I~
//v272:990718 add udoseditname:conv filename by wild card patern   //~v272I~
//v237:990502 record split width support for optbin case           //~v237I~
//v205:981213 add option to ufgets;ignore crlf,chk bin by first block//~v205I~
//v114:971104 option for ugetvfatalias                             //~v114I~
//v105:971026 (GCC)lfn support                                     //~v105I~
//           -use int21 ah=60/7160 for ugetvfatshortname           //~v105I~
//v103:971017 W95 and GCC;ugetalias                                //~v103I~
//v095:970712 maint current pos for ufgets                         //~v095I~
//v090:970629 add ufgets function(pc/unix both support,0x1a chk support)//~v090I~
//**************************************************************** //~v083I~
//*******************************************************          //~v090I~
#define UFGETS_PC		0x01                                       //~v090I~
#define UFGETS_UNIX     0x02                                       //~v090I~
#define UFGETS_MAC      0x04    //mac eol                          //~v552I~
                                                                   //~v660I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50R~//~v660I~
#define UFGETS_EBC      0x08    //ebcdic chk                       //~v660I~
#define UFGETS_EOLID_EBC   8    //eol is 0x15                      //~v68hI~
#define UFGETS_EOLID_EBCZ 0x10  //eol is 0x15                      //~vbBuR~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~//~v660I~
                                                                   //~v660I~
#define UFGETS_BIN      0x10    //ignore line delm                 //~v205I~
#define UFGETS_OPTBIN   0x20    //if reached to binrate treate as binary//~v205I~
#define UFGETS_UTF8     0x40    //utf8 chk                         //~v62nI~
#define UFGETS_TERM     0x80    //buff free req                    //~v090I~
#define UFGETS_RECORD 0x0100    //record mode(NO EOL id,fixed LRECL)//~v661I~
#define UFGETS_EBCEOL 0x0200    //EOLID is 0x15:NL(usualy for ebcdic)//~v68hR~
#define UFGETS_RV     0x0400    //recfm=V                          //~v6m0I~
#define UFGETS_RVHDR  0x0800    //recfm=V,output record header     //~v6m4I~
#define UFGETS_RVTYPE 0x1000    //output record type of microfocus to as eolid//~v6q7I~
#define UFGETS_EBCEOLZ 0x2000    //allow 0x0d15 as EBC eolid       //~vbBuI~
#define UFGETS_VFMTMASK  0xff0000  //recfm=V, fmt type             //~v6m0R~
#define UFGETS_VFMTSHIFT 16                                        //~v6m0R~
#define UFGETS_VFMT_HWDATA  1       //2byte Big endian net data length//~vaj0I~//~v6m0I~
#define UFGETS_VFMT_HW      2       //2byte Big endian 2+data length //~vaj0I~//~v6m0I~
#define UFGETS_VFMT_FWDATA  3       //4byte bigendian  net data length//~vaj0I~//~v6m0I~
#define UFGETS_VFMT_FW      4       //4byte bigendian  4+data length //~vaj0I~//~v6m0I~
#define UFGETS_VFMT_RDW     5       //rdw fmt llllzzzz               //~vaj0I~//~v6m0I~
#define UFGETS_VFMT_MFH     6       //request code 2/4 not determined//~v6m0R~
#define UFGETS_VFMT_MFH2    UFGETS_VFMT_MFH    //microfocus 2 byte header//~v6m0R~
#define UFGETS_VFMT_MFH4    7       //microfocus 4 byte header     //~v6m0R~
#define UFGETS_VFMT_DEFAULT UFGETS_VFMT_RDW                        //~v6m0I~
#define UFGETS_MFHRT_SYSTEM    3    //microfocus record type:system//~v6m0I~
#define UFGETS_MFHRT_NORMALUD  4    //microfocus record type:system//~v6m0I~
//***                                                              //~v6m0I~
#define VFMT_MFH 		"MF"                                       //~vaj0R~//~v6m0M~
#define VFMT_RDW 		"RDW"                                      //~vaj0I~//~v6m0M~
#define VFMT_DEFAULT	VFMT_RDW                                   //~v6m0I~
#define VFMT_FW  		"F"                                        //~vaj0I~//~v6m0M~
#define VFMT_HW  		"H"                                        //~vaj0I~//~v6m0M~
#define VFMT_FWDATA 	"FD"                                       //~vaj0I~//~v6m0M~
#define VFMT_HWDATA  	"HD"                                       //~vaj0I~//~v6m0M~
#define VFMT_MAXLEN    	3                                          //~vaj0I~//~v6m0M~
#define VFMT_MAXLEN_MFH2 0xfff                                     //~v6xdI~
//*******************************************************          //~v6m0I~
int ufgetsinit(int Pmode,unsigned int Pbuffsz,int Pbinrate,int Poptbinwidth);//~v237R~
                                                                   //~v090I~
//*******************************************************          //~v090I~
#define UFGETS_ERR      -1                                         //~v090I~
#define UFGETS_ERRV     -2	//recfm=V length err                   //~v6m0I~
#define UFGETS_EOF       1                                         //~v090I~
#define UFGETS_MORE      4                                         //~v090I~
#define UFGETS_RCBIN     2                                         //~v205R~
//#define UFGETS_RCMFH2    20                                        //~v6m0I~//~v6q8R~
//#define UFGETS_RCMFH4    40                                        //~v6m0I~//~v6q8R~
#define UFGETS_RCMFH2        0x1000                                //~v6q8I~
#define UFGETS_RCMFH4        0x2000                                //~v6q8I~
#define UFGETS_RCMFH2MORE    0x1004                                //~v6q8I~
#define UFGETS_RCMFH4MORE    0x2004                                //~v6q8I~
#define UFGETS_RCMFHMASK     0xf000                                //~v6q8I~
#define UFGETS_RCBIN_NOEOL  3 //bin file by the reason of lonf line(no eol in the first 1024 byte//~v68kI~
#ifdef UNX                                                         //~v68kI~
	#define UFGETS_MAX1ST 4096  //bin if no eol found in this range//~v68kI~
#else                                                              //~v68kI~
	#define UFGETS_MAX1ST 1024  //bin if no eol found in this range//~v68kR~
#endif                                                             //~v68kI~
int ufgets(char *Pbuff,unsigned int Pbuffsz,FILE *Pfh,             //~v090I~
           unsigned int *Preadlen,int *Peolid);                    //~v090I~
                                                                   //~v095I~
//*******************************************************          //~v095I~
//unsigned int ufgetscurpos(void);                                 //~v6x0R~
FILESZT ufgetscurpos(void);                                        //~v6x0I~
                                                                   //~v095I~
//*******************************************************          //~v6hFI~
int ufreads(int Popt,FILE *Pfh,FILESZT Pfilesz,char *Pbuff,int Pbuffsz,int *Ppreadlen);//~2908R~//~v6hFM~
#define UFRO_DROPLF        0x01		//drop eol(0x0a)               //~2908I~//~v6hFM~
#define UFRO_DROPCR        0x02		//drop alos eol(0x0d0a)               //~2908I~//~v6hFI~
#define UFRO_DROPEOF       0x04		//drop DOS EOF(last 0x1a)      //~2908I~//~v6hFM~
#define UFRO_LASTNULL      0x08		//set null at end of string    //~2908I~//~v6hFM~
                                                                   //~v6hFI~
#define UFRRC_EOLSZ_MASK          0x03     //eolsz 0,1 or 2        //~v6hFI~
#define UFRRC_EOFLINE             4        //last line with no eol //~v6hFI~
//*******************************************************          //~v205M~
int ufgetsbinchk(UCHAR *Pbuff,UINT Plen,int Prate);                //~v205M~
                                                                   //~v205M~
#if defined(W32) || defined(DPMI)                                  //~v103R~
//*******************************************************          //~v103R~
int ugetvfatalias(int Popt,unsigned char *Plongname,unsigned char *Pshortname,int Plen);//~v114R~
#define UGVFA_MSG        0x01    //err msg when notfound           //~v114I~
#define UGVFA_WILDCARD   0x02    //allow wildcard wildcard         //~v114I~
#define UGVFA_NEW        0x04    //allow new file(last filename on path)//~v114I~
                                                                   //~v105I~
//*******************************************************          //~v114I~
int ufilegenshortfname(char *Plongname,char *Pshortname);          //~v114I~
                                                                   //~v114I~
//*******************************************************          //~v105I~
int ugetshortpathname(unsigned char *Plongname,unsigned char *Pshortname,int Plen);//~v105I~
#endif                                                             //~v103I~
                                                                   //~v388I~
//#ifdef UNX                                                       //~v50UR~
//*******************************************************          //~v388I~
//void udoseditnameopt(int Popt);                                  //~v55xR~
//#endif //UNX                                                     //~v50UR~
                                                                   //~v388I~
//*******************************************************          //~v272I~
int udoseditname(int Popt,UCHAR *Pin,UCHAR *Ppat,UCHAR *Pout);     //~v55yR~
#define  DEN_UNIX    0x01      //unix type wildcard edit(no special "." meaning)//~v55yM~
#define  DEN_CASE    0x02      //unix type wildcard edit(no special "." meaning)//~v55yM~
#ifdef UNX                                                         //~v55yI~
    #define DEN_DEFAULT_UNIX  	DEN_UNIX                           //~v55yI~
    #define DEN_DEFAULT_CASE	DEN_CASE                           //~v55yI~
#else                                                              //~v55yI~
    #define DEN_DEFAULT_UNIX    0                                  //~v55yI~
    #define DEN_DEFAULT_CASE	0                                  //~v55yI~
#endif                                                             //~v55yI~
//*******************************************************          //~v279I~
//int ufileeditname(UCHAR *Psource,UCHAR *Ppatern,UCHAR *Ptarget); //~v55xR~
int ufileeditname(int Popt,UCHAR *Psource,UCHAR *Ppatern,UCHAR *Ptarget);//~v55xI~
//*******************************************************          //~v55yI~
int ufilewildcomp(int Popt,UCHAR *Pin,UCHAR *Ppat,UCHAR *Pdbcsp);  //~v55yI~
#define UFWC_DOS   0x01 //"." is seperater (DOS)                   //~v55yI~
#define UFWC_CASE  0x02 //case sensitive                           //~v55yI~
#define UFWC_0BYTE 0x04 //"*" match with  over 0 byte              //~v55yI~
#ifdef UNX                                                         //~v55yI~
    #define UFWC_DOS_DEFAULT     0                                 //~v55yR~
    #define UFWC_CASE_DEFAULT    UFWC_CASE                         //~v55yM~
#else                                                              //~v55yI~
    #define UFWC_DOS_DEFAULT     UFWC_DOS                          //~v55yR~
    #define UFWC_CASE_DEFAULT    0                                 //~v55yM~
#endif                                                             //~v55yI~
//*******************************************************          //~v5j8I~
int ufilecomp(int Popt,char *Pfnm1,char *Pfnm2);                   //~v5j8R~
#define UFCO_TEXT    0x01 //textmode(ignore lf and crlf)           //~v5jsI~
#define UFCO_TSPACE  0x02 //ignore traring space                   //~v5jsI~
#define UFCO_NULLAPP 0x04 //allow binary mode compare null append for RECFM=Fx//~v5jtI~
#define UFCO_F1FIXED 0x10 //put confirm file1 is split file by fixed lrecl//~v5kgR~
#define UFCO_F2FIXED 0x20 //put confirm file2 is split file by fixed lrecl//~v5kgR~
#define UFCO_LRECL   0xffff0000 //lrecl mask                       //~v5kgR~
//*rc -nn : split line count(increased line count)                 //~v5kjR~
#define UFCRC_SIZE    4    //bin compare size unmatch              //~v5jtR~
#define UFCRC_UNMATCH 5    //unmatch (same size)                   //~v5kgR~
#define UFCRC_NULLAPP 6    //null append detected                  //~v5jtI~
//*******************************************************          //~v6m0I~
int ufile5chkvfmt(int Popt,char *Pparm,int *Pplrecl);              //~v6m0R~
//*******************************************************          //~v6m0I~
char *ufile5getVfmtstr(int Popt,int Pfmttype);                     //~v6m0I~
//*******************************************************          //~v6x2I~
void ufgets_setcurpos(int Popt,FILESZT Ppos);                      //~v6x2I~
//*********************************************************        //~v6xeI~
int ufseek(FILE *Pfh,FILESZT Pfsz,int Pbase);                      //~v6xeI~
//*********************************************************        //~v6xeI~
FILESZT uftell(FILE *Pfh);                                         //~v6xeI~
//*********************************************************        //~v6y0I~
int fileeditname_copypath(int Popt,char *Pfnm1,char *Pfnm2,char *Pout1,char *Pout2);//~v6y0I~
#define ID_SAMEPATH '='	                                           //~5227I~//~v6y0M~
#define FECO_FULLPATH 0x01                                         //~v6y1R~
//*********************************************************        //~v6y0I~
void fileeditname_copypath_err(int Popt,char *Pfnm1,char *Pfnm2);  //~v6y0R~
#define FCEO_UERREXIT 0x01                                         //~v6y0I~
//*********************************************************        //~v6y1I~
int filetouch(int Popt,char *Pfnm,char *Precord);                  //~v6y1I~
//*********************************************************        //~v77bI~
UINT ufread(void *Pbuff,UINT Psize,UINT Pctr,FILE *Pfh);           //~v77bI~
int uferror(FILE *Pfh);                                            //~v77bI~
//*********************************************************        //+vbByI~
#define UFGLEOL_NONE   0x00                                        //~4B29R~//+vbByM~
#define UFGLEOL_LF     0x01                                        //~4B29I~//+vbByM~
#define UFGLEOL_CRLF   0x02                                        //~4B29I~//+vbByM~
#define UFGLEOL_OPTLF  0x03  //crlf but remains cr by option       //~4B29I~//+vbByM~
//*                                                                //~4B29I~//+vbByI~
#define UFGLO_LFONLY   1   //allof LF(0x0a) only                   //~4B29I~//+vbByM~
//*                                                                //~4B29I~//+vbByI~
#define UFGLRC_OK      0                                           //~4B29I~//+vbByM~
#define UFGLRC_EOF    -1  //else errno                             //~4B29I~//+vbByM~
//*                                                                //+vbByI~
int ufgetline(int Popt,FILE *Pfh,char *Pbuff,int Pbuffsz,int *Ppreadlen,int *Ppeolid);//+vbByI~
