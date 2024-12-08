//CID://+v79pR~:        update#=16                                 //+v79pR~
//*******************************************************
//*uedit.h                                                         //~v57WR~
//*******************************************************
//v79p:240203 add ux2is(get int[] from hex string 0x__,X___,u___ fmt with any spliter//+v79pI~
//v6Z0:200516 uwordrep option alternative parm sign                //~v6Z0I~
//v6T1:180210 add ueditKMG(edit Kiro,mega,Giga value)              //~v6T1I~
//v6L5:170715 msvs2017 warning;(Windows:PTR:64bit,ULONG 32bit,HWND:64bit)//~v6L5I~
//v6xk:150115 (BUG:W32)spwanxx deplicated,use _spawnxx(return intptr_t, Linux returns int pid)//~v6xkI~
//v6x3:150106 add editFILESZ                                       //~v6x3I~
//v6x0:150105 BUG:offset value is long long for fseek error msg    //~v6x0I~
//v6qg:131209 support addtional parm;%0 for filename,%@ all remaining//~v6qgI~
//v5k2:061227*(LNX/WIN)bc_dweditnum64(long long int edit func) add //~v5k2I~
//v5fx:050325 ugetnumrange3 for v5fw(copy from tc_getnumrange)     //~v5fxI~
//v5f4:041121 replace $abc,${abc},%abc% by env variable for xe set cmd//~v5f4I~
//v57W:030727 hexdump conv to bin                                  //~v57WI~
//v526:020203 Octal support of unumlen                             //~v526I~
//v301 000323:unumlen preceding space option                       //~v310I~
//v244:990606 add ugetxnumrange func                               //~v244I~
//v129:971210 use uparsecd for the uparsev in ucmdparmedit         //~v129I~
//            padding not used opd by option                       //~v129I~
//v125:971130 ucmdparmedit new option(vfmt)                        //~v125I~
//v096:970720 uatoin(uatoi with maxlen)                            //~v096I~
//v095:970720 unumlen(count digit string len)                      //~v095I~
//v066:970215:new function uwirdrep                                //~v066I~
//v047:961124:ugetnumrange (get value from nnn-mmmm format)        //~v047I~
//v025:960901:add ugethex                                          //~v025I~
//950702 add utimeedit                                          //~5702I~
//*******************************************************       //~5625I~
#ifdef W32                                                         //~v6L5I~
	#define SSCANF_UL2L(str,fmt,pnum) \
        do {                                                   \
        		ULONG _ul;                                     \
                sscanf(str,fmt,&_ul);                           \
       			*pnum=(LONG)_ul;                                \
		} while(0)                                                 //~v6L5I~
#else                                                              //~v6L5I~
	#define SSCANF_UL2L(str,fmt,pnum) \
	sscanf(str,fmt,pnum);                                          //~v6L5I~
#endif                                                             //~v6L5I~
//*******************************************************          //~v6L5I~
int unumedit(unsigned long Pnum,unsigned char *Ppatern,unsigned char *Pout);//~5702I~
//******************************************************        //~5702I~
void *utimeedit(unsigned char *Ppatern,void *Pout);             //~5702R~
#define UET_ISTRING 0 //integer 4 byte string for each date and time//~5702R~
#define UET_ILONG   1 //ineger long                             //~5702R~
#define UET_XSTRING 2 //hex 4 byte string                       //~5702R~
#define UET_XLONG   3 //hex long                                //~5702R~
#define UET_MAXID   9 //for dos,chk ulong value                 //~5702I~
                                                                //~5820I~
//*******************************************************       //~5820I~
unsigned char *uitoa10(int Pvalue);                             //~5820I~
//**************************************************************** //~v125I~
int ucmdparmedit(int Popt,char *Pcmd,char *Popd,char **Popdv,char **Presult);//~v129I~
#define CPEO_APPEND     0x01      //append remainig param to end of string//~v6qgI~
#define CPEO_FNMPARM    0x02      //Presult point filename for %0 as input parm//~v6qgI~
//**************************************************************** //~v5f4I~
int ueditenv(int Popt,char *Pinp,char *Pout);                      //~v5f4R~
#define UEE_UNIXTYPE      0x01  //unix patern env var spcification(use $)//~v5f4I~
#define UEE_PCTYPE        0x02  //pc   patern env var spcification(use %)//~v5f4I~
//**********************************************************************//~v066I~
char *uwordrep(int Popt,char *Pinp,char **Pkwd,char **Pdata,int *Prepctr,int *Pnorepctr);//~v066I~
#define WORDREP_IC  			0x01	//ignore case              //~v066I~
#define WORDREP_UNMATCHNULL  	0x02	//rep by null if unmatch kwd(%...%)//~v066I~
#define WORDREP_NODATANULL  	0x04	//rep by null if no data ptr//~v066I~
#define WORDREP_ALTSIGN     	0x08	//alternative parmsign     //~v6Z0I~
                                                                   //~v066I~
//******************************************************************//~v025I~
int ugethex(char *Phex,char *Pbin,int Plen);                       //~v025I~
//******************************************************************//~v025I~
int ux2l(char *Phex,ULONG *Ppulong);                               //~v025R~
//******************************************************************//~v6x0I~
int ux2FILESZ(char *Phex,FILESZT *Ppulong);                        //~v6x0I~
//******************************************************************//~v6x0I~
#ifdef INT64SUPP                                                   //~v5k2I~
//******************************************************************//~v025I~
int ux2ll(char *Phex,INT64 *Ppulong);                              //~v5k2R~
INT64 ua2ll(char *Pdec);                                           //~v5k2I~
//******************************************************************//~v5k2I~
#endif                                                             //~v5k2I~
//******************************************************************//~v5k2I~
int ux2s(char *Phex,USHORT *Ppuint);                               //~v025R~
//*******************************************************          //~v5fxI~
int ugetnumrange3(char *Pstr,int *Pstart,int *Pend,char **Ppcend); //~v5fxI~
//*******************************************************          //~v57WI~
int ugetnumrange2(int Popt,char *Pstr,long *Pstart,long *Pend);    //~v57WI~
#define UGNR2_MASK   0x00ff  //postfix mask to return minus value  //~v57WR~
#define UGNR2_HEX    0x0100    //call ugetxnumrange                //~v57WR~
#define UGNR2_NOCASE 0x0200    //mask char is case insensitive     //~v57WI~
//*******************************************************          //~v6x0I~
int ugetnumrange2XFILESZ(int Popt,char *Pstr,FILESZT *Pstart,FILESZT *Pend);//~v6x0R~
                                                                   //~v57WI~
//*******************************************************          //~v047I~
int ugetnumrange(char *Pstr,long *Pstart,long *Pend);              //~v047I~
//*******************************************************          //~v244I~
int ugetxnumrange(char *Pstr,long *Pstart,long *Pend);             //~v244I~
//*******************************************************          //~v6x0I~
#ifdef LFSSUPP                                                     //~v6x0I~
int ugetxnumrangeLL(char *Pstr,INT64 *Pstart,INT64 *Pend);         //~v6x0I~
#endif                                                             //~v6x0I~
//*******************************************************          //~v095I~
int unumlen(unsigned char *Pstr,int Popt,int Plen);                //~v095I~
#define UNUMLEN_DEC   0x00                                         //~v310I~
#define UNUMLEN_HEX   0x01                                         //~v310I~
#define UNUMLEN_SPACE 0x02                                         //~v310I~
#define UNUMLEN_MINUS 0x04  //return minuslen when minus value(for ex -0.xx)//~v310I~
#define UNUMLEN_OCT   0x08                                         //~v526I~
                                                                   //~v096I~
//*******************************************************          //~v096I~
int uatoin(char *Pstr,int Plen);                                   //~v096I~
//*******************************************************          //~v57WI~
int ugethexdump(int Popt,char *Phex,char *Pbin,int Plen,int *Pchklen);//~v57WI~
#define UGHD_SPACESKIP   0x01                                      //~v57WI~
//*******************************************************          //~v6x3I~
char *ueditFILESZ(int Popt,char *Pout,int Pbuffsz,char *Pfmt,FILESZT Psz);//~v6x3R~
#define UEFS_KMGT        0x01 //unit by decimal KB,MB,GB if avail  //~v6x3R~
//*******************************************************          //~v6xkI~
char *ueditLONGHANDLE(int Popt,char *Pout,int Pbuffsz,char *Pfmt,LONGHANDLE Phandle);//~v6xkI~
//*******************************************************          //~v6T1I~
char *ueditKMG(int Popt,size_t Psz);                               //~v6T1I~
//*******************************************************          //+v79pI~
int ux2is(int Popt,char *Phex,int Plen,int *Pout,int Pmaxctr,int *Ppchklen);//+v79pI~
