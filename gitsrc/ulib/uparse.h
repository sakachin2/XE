//CID://+v6H2R~:                                                   //+v6H2R~
//*******************************************************
//*uparse.h                                                        //~v098R~
//*******************************************************
//v6H2:170103 (BUG)uparsefname cut last 1 byte for len=259(_MAX_MATH-1)//+v6H2I~
//v5j4:060913 uparse no single quotation(') option(process double quote(") only)//~v5j4I~
//v5iz:060910 (BUG)contdelm option is not functional(change #define name to conform currentry not used)//~v5izI~
//v5h5:060224 (BUG)grep:when space containing dir for *\ or ^*\,it should not enclose wildcard by unix shell standard.//~v5h5I~
//v5f1:041113 uparse;option to treate quotation as delm.parse x"y"z to x,y,z//~v5f1I~
//v5ez:041111 parsecmd terminater option to search comment start position//~v5ezI~
//v5cx:040521 uparsegetopt support for other than unix             //~v5cxI~
//v595:031012 uparse:support flag quatation like as -d" "          //~v595I~
//v374:000929 LINUX support(func to split flag and other parm;uparsegetopt)//~v374I~
//v324 000813:LINUX support(CRLF)                                  //~v324I~
//v289:991023 change dlm from space to next delm when space+delm case for not UPARSESETCONDELM//~v289I~
//v235:990501 option to support tab for parse, it is same meaning as space.//~v235I~
//v130:971217 uparsecmdin:enclose by quatation by cmd fmt          //~v130I~
//v127:971207 new func uparsecmd(parse like as shell)              //~v127I~
//v117:971109 new function uparsefname(drop quatation);use for also v116//~v117I~
//v098:970723 split uparse fro ustring to uparse.c                 //~v098I~
//v097:970720 umemspnc,umemrspnc                                   //~v097I~
//v094:970706 umemrspn(umemspn is same meaning as ustrnspn)        //~v094I~
//            ustrnrspn must trate parm1 as string                 //~v094I~
//v093:970706 (BUG)set null out of range may corrupt naboring area(ustrnchar2,ustrnrchr2)//~v093I~
//            and conbine to umemchar2,umemrchr2)                  //~v093I~
//v092:970705 umemmem/umemmemi/umemstr/umemstri/umemrmem/umemrmemi/umemrstr/umemrstri//~v092R~
//v091:970705 add ustrnlen(max n)                                  //~v091I~
//v080:970503 add uparsein to enclabe string by quate for dlcmd to dcmd//~v080I~
//v069:970330:uparsev(output by argv format)                       //~v069I~
//v046:961123:uparse2 no malloc output area option(malloc at out of function)//~v046I~
//           :uparse:malloc only when long string                  //~6B23I~
//           :uparse:delm lost when pre/post space exist.          //~6B23I~
//                   add option to set delm except for ","         //~6B23I~
//v017:960714:add ustrchr2(strchr protecting detect dbcs 2nd byte) //~v017I~
//            add ustrnchr2=(ustrchr2 with length)                 //~v017I~
//            add ustrrchr2(search last char protecting detect dbcs 2nd byte)//~v017I~
//            add ustrnrchr2=(ustrrchr2 with length)               //~v017I~
//960324:uparse2:with delm/qaute return function                //~6324I~
//*******************************************************       //~6324I~
#define UPARSERC(pin,pout,pno,popt,pdelm)  \
		{                                            \
        	int rc_uparse;                                  \
        	if ((rc_uparse=uparse(pin,pout,pno,popt,pdelm))>4)	\
				 return rc_uparse;\
        }                                                          //~v127I~
//      if (uparse(pin,pout,pno,popt,pdelm)>4) return 8            //~v127R~
#define UPARSECMDRC(popt,pcmd,pno,pout,popdv,pdelm)  \
		{                                            \
        	int rc_uparsecmd;                                  \
			if (rc_uparsecmd=uparsecmd(popt,pcmd,pno,pout,popdv,pdelm),rc_uparsecmd)   \
				return rc_uparsecmd;                                         \
        }                                                          //~v127I~
typedef struct _UPODELMTBL		//parse out delimeter table     //~6324R~
         {                                                      //~6324I~
            UCHAR		upodelm;                                //~6324I~
            UCHAR		upoquate;                               //~6324I~
            USHORT      upodelmoffs;                            //~6324I~
         } UPODELMTBL;                                          //~6324I~
typedef UPODELMTBL *PUPODELMTBL;                                //~6324I~
#define UPODELMTBLSZ (sizeof(UPODELMTBL))                       //~6324I~
                                                                //~6324I~
                                                                //~6324I~
//******************************************************           //~v080I~
int uparsein(char *Pin,char *Pout,int Poutlen,char *Pdelmtbl,char Pquate);//~v080I~
                                                                   //~v080I~
//******************************************************           //~v5h5I~
int uparseindir(int Popt,char *Pin,char *Pout,int Poutlen);        //~v5h5R~
                                                                   //~v5h5I~
//******************************************************           //~v069I~
int uparsev(UCHAR *Pin,UCHAR ***Ppargv,int *Ppwordno,int Popt,UCHAR *Pdelmtbl);//~v069R~
                                                                   //~v130I~
//******************************************************        //~6324I~
int uparse2(UCHAR *Pin,PUPODELMTBL *Ppupodelmtbl,UCHAR **Ppupotbl, //~v046R~
			int *Ppwordno,int Popt,UCHAR *Pdelmtbl);               //~v046I~
#define UPARSE2IGNRCRLF	   0x01                                    //~6B23R~
#define UPARSE2USEAREAPARM 0x02                                    //~6B23I~
//#define UPARSE2SETCONTDELM 0x04                                  //~v5izR~
#define UPARSE2SEPCONTDELM 0x04 //seperate continued delm          //~v5izI~
#define UPARSE2TABISSPACE  0x08                                    //~v235I~
#define UPARSE2SETCONTDLM2 0x10 //for spece+delm case,change delm=spce to the delm//~v289R~
#define UPARSE2ALLOWFLAG   0x20 //allow flag fmt quatation string  //~v595I~
#define UPARSE2QUOTEDELM   0x40 //quotation is always delm(parse x"y"z to x,y,z)//~v5f1I~
#define UPARSE2NOSQUOTE    0x80 //process double quotation only    //~v5j4I~
                                                                   //~v130I~
//******************************************************        //~5430I~
int uparse(UCHAR *Pin,UCHAR *Pout,int *Ppwordno,int Popt,UCHAR *Pdelmtbl);//~5430I~
#define UPARSEIGNRCRLF 		UPARSE2IGNRCRLF                        //~6B23R~
//#define UPARSESETCONDELM 	UPARSE2SETCONTDELM                     //~v5izR~
#define UPARSESEPCONTDELM 	UPARSE2SEPCONTDELM	//each entry to cotinued delm//~v5izI~
#define UPARSETABISSPACE 	UPARSE2TABISSPACE                      //~v235I~
#define UPARSESETCONDLM2 	UPARSE2SETCONTDLM2                     //~v289I~
#define UPARSEALLOWFLAG  	UPARSE2ALLOWFLAG                       //~v595R~
#define UPARSEQUOTEDELM  	UPARSE2QUOTEDELM                       //~v5f1I~
#define UPARSENOSQUOTE   	UPARSE2NOSQUOTE                        //~v5j4I~

//*******************************************************          //~v117I~
//int uparsefname(int Popt,char *Pifname,char *Pofname,int *Pdelmpos,int *Poutlen);//+v6H2R~
int uparsefname(int Popt,char *Pifname,char *Pofname,int *Pdelmpos,int Pbuffsz,int *Poutlen);//+v6H2I~
                                                                   //~v127I~
//*******************************************************          //~v127I~
int uparsecmd(int Popt,char *Pcmd,int *Popdno,char **Ppout,char ***Ppopdv,//~v127I~
				PUPODELMTBL*Ppdelmt);                              //~v127I~
#define UPCMD_DROPQ      0                                         //~v127I~
#define UPCMD_ASIS       1                                         //~v127R~
#define UPCMD_GETENDOFFS 2  //get terminater offset                //~v5ezI~
#define UPCMD_TERMCHMASK 0xff00  //terminater char mask            //~v5ezI~
//******************************************************           //~v130I~
int uparsecmdin(char *Pin,char *Pout,int Poutarealen,int *Poutlen);//~v130I~
//******************************************************           //~v374I~
//#ifdef UNX                                                       //~v5cxR~
int uparsegetopt(int Popt,char *Pinp,int *Pctr,char *Pflag,char **Poutp,char **Pflagparm);//~v374I~
#define  UPGO_NOCASE     0x01    //flagid is case insensitive      //~v374I~
#define  UPGO_ERRMSG     0x02    //err msg when err                //~v374I~
#define  UPGO_FLAGDOS    0x04    //allow /f type                   //~v5cxR~
#define  UPGO_FLAGUNIX   0x08    //allow -f type                   //~v5cxR~
#define  UPGO_NOSPLIT    0x10    //disallow split like as "-f opt" //~v5cxI~
//#endif //UNX                                                     //~v5cxR~
