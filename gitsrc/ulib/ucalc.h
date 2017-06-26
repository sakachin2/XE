//*CID://+v6K6R~:                             update#=   65;       //+v6K6R~
//*******************************************************
//v6K6:170320 (BUG)calc_time, hh>0x7fff was cut                    //+v6K6I~
//v6K5:170320 output days when hour>24                             //~v6K5I~
//v6hh:120623 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  defines ULPTR(unsigned long long)//~v6hhI~
//v69C:110129 xds errmsg "dword and dword"                         //~v69CI~
//v69B:110102 ucalc:dword/dword,dword%dword support                //~v69bI~
//v5f9:041228 xbc;support $n operand                               //~v5f9I~
//v5e3:040926 xbc:output precision/round option support            //~v5e3I~
//v5dx:040815 BC cmd:support dw/up                                 //~v5dtI~
//v5dt:040724 BC cmd:cont of v5ds                                  //~v5dtI~
//v5ds:040704 BC cmd:do dword calc for word operation if avail     //~v5dsI~
//v5dr:040627 BC cmd:accept minus value                            //~v5drI~
//v5dj:040612 support dword underpoint "+"(add)/"-" operation      //~v5djI~
//v5db:040531 issue errmsg when overflow(dword mult)               //~v5dbI~
//v59a:031027 export bc_getvalur for xecalc2                       //~v59aI~
//v57J:030705 xbc:leave result on the line by R option to continued operation//~v57JI~
//v56v:020728 calc;display residual when output type is X or O     //~v56vI~
//v542:020324 (BUG)overflow when a.b/c.d patern by digit position  //~v542I~
//v50C:010609 a.b*c.d and a.b/c.d support                          //~v50CI~
//v50e:010402 double word calc support                             //~v50eI~
//v314 000513:ucalc from xecalc for XBC cmd.                       //~v314I~
//v155:000318 numeric calc func(NEW)
//*******************************************************
#define  MAX_POINT_NUM   9
#define  ULMINUS        0xffffffff                                 //~v5drR~
#define  ULMINUSBIT     0x80000000                                 //~v5drR~
//#define  UCALC_DWORDID  256	//dword id for underpoint digit len//~v5dtR~
#define  UCALC_DWORDID  0x0100	//dword id for underpoint digit len//~v5dtR~
#define  UCALC_DWUPMASK 0x010f	//over point value is minus signed //~v5dtI~
                            //dword+underpoint is 0x1xx            //~v5djI~
#define  UCALC_UPMASK   0x0f//underpoint mask                      //~v5drI~
#define  IS_ID_DOWRDUP(id) (((id) & UCALC_DWUPMASK)>UCALC_DWORDID) //~v5dtI~
#define  IS_LV_DOWRDUP(lv) (IS_ID_DWORDUP(lv[1]))                  //~v5dtI~
#define  CALC_LONGNUMFMTSZ   (sizeof(LONG)*4)                      //~v5drI~
#define  CALC_SHORTNUMFMTSZ  (sizeof(LONG)*3)                      //~v5drI~
                                                                   //~v5dsI~
#define IF_WORD_ISMINUS(wordnum) ( ((LONG)wordnum[0]<0) || (wordnum[1] && (LONG)wordnum[2]<0) )//~v5dsI~
#define SET_WORD_MINUS(wordminus,wordnum) wordminus[0]=-wordnum[0],wordminus[1]=wordnum[1],wordminus[2]=-wordnum[2]//~v5dsI~
#define IF_DWORD_ISMINUS(wordnum) ( ((LONG)wordnum[0]<0) || ((wordnum[1]&~UCALC_DWORDID) && (LONG)wordnum[3]<0) )//~v5dsR~
#define SET_DWORD_MINUS(wordminus,wordnum) wordminus[0]=-wordnum[0]-(wordnum[2]!=0),wordminus[1]=wordnum[1],wordminus[2]=-wordnum[2],wordminus[3]=-wordnum[3]//~v5dsI~
                                                                   //~v5f9I~
#define UCALC_MAXRESULTNO   9                                      //~v5f9I~
#define UCALC_MAXRESULTLEN  32                                     //~v5f9I~
#define UCALC_VARID        '$'                                     //~v5f9I~
#define UCALC_LISTFUNC     UCALC_VARID                             //~v5f9I~
#ifdef UCALC_GBL                                                   //~v5f9I~
    char Gucalc_result[UCALC_MAXRESULTNO+1][UCALC_MAXRESULTLEN];   //~v5f9R~
#else                                                              //~v5f9I~
    extern char Gucalc_result[UCALC_MAXRESULTNO+1][UCALC_MAXRESULTLEN];//~v5f9R~
#endif                                                             //~v5f9I~
//*******************************************************
//int ucalc_bcmain(UCHAR *Pcmdstr);                                //~v57JR~
int ucalc_bcmain(UCHAR *Pcmdstr,UCHAR *Presultstr);                //~v57JI~
//*******************************************************          //~v314I~
int ucalc_gettimevalue(char *Pdata,int Plen,long *Pvalue);         //~v314R~
//*******************************************************
int ucalc_time(int Popt,int Popr,long *Popd1,long *Popd2);         //~v314R~
#define CALC_TIME_SETSIGN  0x01     //set sign to bit 0 if opd1<opd2
#define CALC_TIME_CONV2SEC 0x02     //conv opd1-opd2 to seconds
#define CALC_TIME_CONV2HMS 0x04     //conv sec to HYM fmt          //~0326I~
#define CALC_TIME_1SEC     0x08     //opd1 is sec value            //~0326R~
#define CALC_TIME_2SEC     0x10     //opd2 is sec value            //~0326R~
#define CALC_TIME_BORROW   0x20                                    //~0402I~
#define CALC_TIME_DIVPREC  0x40                                    //~0416I~
#define CALC_TIME_HMSMASK  0x7fffffff     //time value mask(hhmmss or seconds)//~0402R~
#define CALC_TIME_SECMASK  0x7fffffff     //time value mask(hhmmss or seconds)
#define CALC_TIME_MINUS    0x80000000     //conv opd1-opd2 to seconds
//*******************************************************
//int ucalc_getvalue(char *Popd,long *Pvalue,int *Pdatatype);      //~v5drR~
//*******************************************************
int ucalc_timeedit(int Popt,char *Pout,long *Pvalue);              //~v314R~
#define  CALC_TIME6     0x0100       //6byte hhmmss.xxx output fmt //~0402I~
#define  CALC_DAYS      0x0200       //output days when hh>24      //~v6K5I~
#define  CALC_DAYSONLY  0x0400       //output days only            //~v6K5I~
#define  CALC_OVFHH     0x0800       //Use SovfHH                  //+v6K6I~
//*******************************************************
int ucalc_binop(int Popt,int Pope,long *Popd1,long *Popd2);        //~v314R~
#define CALC_DIV_PRECUP  		0x01	//for div result precision 1 up
//#define CALC_SIGNED      		0x02	//signed operation         //~v5dtR~
#define CALC_DIVBYRES    		0x04	//div called from % internaly//~v50CR~
//#define CALC_MULTBYDIV   		0x08	//multiply by underpont div(return overflow value)//~v5dtR~
#define CALC_NOOVFMSG    		0x10	//no unsigned multiply overflow msg//~v5dbI~
#define CALC_DWORDUP     		0x20	//result can be change to dword+underpoint//~v5djI~
#define CALC_NOERRMSG    		0x40	//result can be change to dword+underpoint//~v5drI~
#define CALC_IGNOREOVF   		0x80	//ignore overflow          //~v5dtI~
                                                                   //~v5djI~
#define CALC_RCWORDOVF   3		//r.c word overflow                //~v5djI~
#define CALC_RCERRMSG    5		//errmsg issued already            //~v5drR~
//*******************************************************
int ucalc_underpoint(int Psignedsw,int Popr,long *Popd1,long *Popd2,int *Povf);//~v314R~
//*******************************************************
int ucalc_o2l(char *Pdata,long *Pldata,int Plen);                  //~v314R~
//*******************************************************
int ucalc_getunderpointdata(int Popt,char *Pdata,int Plen,long *Pvalue);//~v314R~
#define CALC_UPSIGNED      		0x01	//signed operation         //~0401I~
#define CALC_UPMINUS       		0x02	//signed operation         //~0401I~
//*******************************************************          //~0401I~
int ucalc_editnum(int Popt,char *Pdata,long *Pvalue);              //~v314R~
#define CALC_ENSIGNED      		0x01	//signed                   //~0401I~
#define CALC_ENSPACEZ      		0x02	//z,zzz,zz9 without drop preceding space//~0401I~
#define CALC_ENZ           		0x04	//z,zzz,zz9 with dropping preceding space//~0401I~
//*******************************************************          //~v56vI~
int ucalc_editevenhex(long Pnum,char *Pout);                       //~v56vM~
//*******************************************************          //~v59aI~
//int bc_getvalue(char *Popd,long *Pvalue,int *Pdatatype,int *Pdatatyped);//~v5drR~
int bc_getvalue(int Popt,char *Popd,long *Pvalue,int *Pdatatype,int *Pdatatyped);//~v5drI~
//*******************************************************          //~v5drI~
int ucalc_shiftdown(int Popt,LONG *Pupdata,int Pshift);            //~v5drM~
//*******************************************************          //~v5dtI~
int ucalc_shiftup(int Popt,LONG *Pupdata,int Pshift);              //~v5dtI~
//*******************************************************          //~v5drI~
LONG  bc_getbase(int Pindx);                                       //~v5drI~
//*******************************************************          //~v5dsI~
int calcerrwordovf(int Popt);                                      //~v5dsI~
//*******************************************************          //~v5dtI~
int calcerr0div(void);                                             //~v5dtI~
//*******************************************************          //~v5dtI~
int ucalc_binopsub(int Popt,int Pope,long *Popd1,long *Popd2);     //~v5dtM~
//*******************************************************          //~v5e3I~
int ucalc_vrajust(int Popt,LONG *Pval,int Pvprec);                 //~v5e3I~
#define UCVRA_ROUNDUP   0x01                                       //~v5e3I~
#define UCVRA_PRECDOWN  0x02    //do also precision down           //~v5e3I~
#define UCVRA_TIME      0x04    //time format                      //~v5e3I~
//*******************************************************          //~v5e3I~
int ucalc_chkvrparm(char *Pconvtype,int *Pvprec,int *Pvround,char **Pvrpos);//~v5e3M~
//*******************************************************          //~v69BR~
int bc_dw2numfmt(int Popt,long *Pnumfmt,long *Pdw);                //~v69BR~
//*******************************************************          //~v69CI~
int bc_numfmt2dw(int Popt,long *Pnumfmt,long *Psw);                //~v69CI~
//*******************************************************          //~v6hhI~
#ifdef ULIB64X                                                     //~v6hhI~
int bc_getvalueLL(int Popt,char *Popd,SLPTR *Pvalue,int *Pdatatype,int *Pdatatyped);//~v6hhI~
//*******************************************************          //~v6hhI~
int bc_getxdwLL(char *Popd,SLPTR *Pvalue);                         //~v6hhI~
//*******************************************************          //~v6hhI~
int ucalc_vrajustLL(int Popt,SLPTR *Pval,int Pvprec);              //~v6hhI~
//*******************************************************          //~v6hhI~
int ucalc_timeLL(int Popt,int Popr,SLPTR *Popd1,SLPTR *Popd2);     //~v6hhI~
//*******************************************************          //~v6hhI~
int ucalc_binopLL(int Popt,int Pope,SLPTR *Popd1,SLPTR *Popd2);    //~v6hhI~
//*******************************************************          //~v6hhI~
int ucalc_o2lLL(char *Pdata,SLPTR *Pldata,int Plen);               //~v6hhI~
//*******************************************************          //~v6hhI~
int ucalc_gettimevalueLL(char *Pdata,int Plen,SLPTR *Pvalue);      //~v6hhI~
//*******************************************************          //~v6hhI~
int bc_getldLL(int Popt,char *Pdata,SLPTR *Pvalue);                //~v6hhI~
//*******************************************************          //~v6hhI~
int ucalc_timeeditLL(int Popt,char *Pout,SLPTR *Pvalue);           //~v6hhI~
//*******************************************************          //~v6hhI~
int bc_dweditnumLL(int Pfunctype,int Pconvtype,SLPTR *Pvalue,UCHAR *Pout);//~v6hhI~
//*******************************************************          //~v6hhI~
int bc_edittodLL(UCHAR *Pout,SLPTR *Pvalue);                       //~v6hhI~
//*******************************************************          //~v6hhI~
int ucalc_editnumLL(int Popt,char *Pout,SLPTR *Pvalue);            //~v6hhI~
//*******************************************************          //~v6hhI~
int ucalc_getunderpointdataLL(int Popt,char *Pdata,int Plen,SLPTR *Pvalue);//~v6hhI~
#endif                                                             //~v6hhI~
