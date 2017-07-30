//*CID://+v6L8R~:                             update#=  449;       //+v6L8R~
//*************************************************************
//*xecalc.c
//* basic calc
//*************************************************************
//v6L8:170716 (Bug:64)O calc err(addr was set as numvalue)         //+v6L8I~
//v6L7:170716 X calc err(need work clear)                          //~v6L7I~
//v6K6:170320 (BUG)calc_time, hh>0x7fff was cut                    //~v6K6I~
//v6K5:170320 output days when hour>24                             //~v6K5I~
//v6K4:170319 (BUG)time dword calc crash(operand value was not init)//~v6K4I~
//v6K3:170316 xbc:support 3 operand by "reverse polish notation"   //~v6K3I~
//            drop prefix "z" from output result string            //~v6K3I~
//            ignore intermediate residual of "/"(devide) for "X" or "O" number.//~v6K3I~
//v6Di:160625 for compiler warning,-Wformat-security(not literal printf format)//~v6DiI~
//v6xi:150115 conversion warning                                   //~v6xiI~
//v6xh:150115 (BUG)invalid dword calc;on 64bit linux long/ulong is 64bit,so DWADD dose not overflow//~v6xhI~
//v6xg:150114 guide to notation of dword xvalue                    //~v6xgI~
//v6hh:120623 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  defines ULPTR(unsigned long long)//~v6hhI~
//v6h6:120609 (WTL)avoid c4701 warning(used uninitialized variable)//~v6h6I~
//v5g5:050608 (BUG)xbc cmd;VnnR parm override on result output string//~v5g5I~
//            (BUG 0f v5fj,vrpos initialize bypassed by v5fj)      //~v5g5I~
//v5fj:050213 (BUG)VnnR parm ignored for divide(/)                 //~v5fjI~
//v5f9:041228 xbc;support $n operand                               //~v5f9I~
//v5ea:041009 (BUG)Vn operation should ignore updata if upid=0     //~v5eaI~
//v5e9:041003 xbc:"?"(compare) support                             //~v5e9I~
//v5e8:041003 (BUG)underpoint compare(?) bug                       //~v5e8I~
//v5e7:041003 unumedit:"-" for edit as minus value, "z" is for unsigned.//~v5e7I~
//v5e6:041003 xbc:allow seperated vnr specification                //~v5e6I~
//v5e5:040930 xbc:support minus Time specifiaction                 //~v5e5I~
//v5e3:040926 xbc:output precision/round option support            //~v5e3I~
//v5dx:040815 BC cmd:support dw/up                                 //~v5dxI~
//v5dw:040813 BC cmd:dword parm support fot time calc(ignore high value)//~v5dwI~
//v5dv:040811 BC cmd:cont of v5dr                                  //~v5dvI~
//v5du:040811 BC cmd:allow underpoint for opd1 of !(power)         //~v5duI~
//v5dt:040724 BC cmd:cont of v5ds                                  //~v5dtI~
//v5ds:040704 BC cmd:do dword calc for word operation if avail     //~v5dsI~
//v5dr:040627 BC cmd:accept minus value                            //~v5drI~
//v5dp:040620 support dw+point/word                                //~v5dpI~
//v5dj:040612 support dword underpoint "+"(add)/"-" operation      //~v5djI~
//v5db:040531 issue errmsg when overflow(dword mult)               //~v5dbI~
//v5a2:040102 (BUG)calc_time:hour=-1 is displayed as -32768        //~v5a2I~
//v597:031014 (BUG) just overflow data is missing at underpoint calc//~v597R~
//v58f:030830 (BUG) timeedit:hour is cut to 255H                   //~v58fI~
//v57J:030705 xbc:leave result on the line by R option to continued operation//~v57JI~
//v57u:030201 (BUG)xbc -123-->x-z123=ffffff85;-z123=ffffff85 is valid//~v57uI~
//v573:021102 display determined datatype on result msg if not explicitly specified//~v573I~
//v56v:020728 calc;display residual when output type is X or O     //~v56vI~
//v546:020330 do v543 only when unsigned specified(U or UZ)        //~v546I~
//v544:020324 dword calc for power(!)                              //~v544I~
//v543:020324 do dw calc when ovf if not underpoint data           //~v543I~
//v542:020324 (BUG)overflow when a.b/c.d patern by digit position  //~v542I~
//v541:020324 (BUG)"/" and "%" of xbc(divide) invalid for minus(0xffffff to 0x80000000)//~v541R~
//v50D:010609 (BUG)ucalc_dwdiv require 3 dword parm                //~v50DI~
//v50C:010609 a.b*c.d and a.b/c.d support                          //~v50CI~
//v50B:010602 (BUG)underpoint length calc err for timeval          //~v50BI~
//v50A:010531 devide for num with underpoint may fail by overflow  //~v50AR~
//v50t:010414 localtime may return 0 when too large seconds(before 1980)//~v50tI~
//v50s:010414 support "-" for long decimal                         //~v50sI~
//v50r:010414 support convtype uz(unsigned edit)                   //~v50rI~
//v50p:010414 allow also 0x____ for x____                          //~v50pI~
//v50n:010414 (BUG)not numeric sec data(last byte) is not err.     //~v50nI~
//v50m:010414 "z" for datatype=decimal                             //~v50mI~
//v50j:010407 chang clockid 'C' to 'L'(locval time)                //~v50jI~
//v50i:010407 (BUG)when opecode continued like as <>               //~v50iI~
//v50g:010402 calc:long decimal support                            //~v50gI~
//v50f:010402 TOD conversion                                       //~v50fI~
//v50e:010402 double word calc support                             //~v50eI~
//v328 000826:LINUX:gcc detected warning:uninitialized var         //~v328I~
//v314 000513:ucalc from xecalc for XBC cmd.                       //~v314I~
//v169:000418 add ! (power) to BC func                             //~v169I~
//v167:000418 add |,&,^ to BC                                      //~v167I~
//v155:000318 numeric calc func(NEW)
//binary operation/unary conversion command
//  conversion :  BC value /conv-option [R]                        //~v57JR~
//                  -value:Xhexnum , Ooctnum , Ttimestamp(hh:mm:ss,delm should be other than : or .)
//                   Timestamp may have unser sec data like as hh:mm:ss.xxx.
//                   if no preceding X/O/T,
//  					 assume Dec if all digit is valid decimal,
//  					        Hex if all digit is valid hex digit
//  					        time if hh:mm:ss.
//                   dddd.dddd is underpoint format for decimal only//~v50eI~
//                   xxxx..xxxx is double word value format for hex only//~v50eR~
//                              (dword is trated as unsigned)      //~v50eI~
//                  -conv-option:
//                       X:conv to Hex
//                       O:conv to Oct
//                       D:conv to Dec
//                       U:conv to unsigned decimal
//                       Z:output by zz,zzz,zz9 fmt
//                       T:hh:mm:ss.xxx fmt
//                       C:yyyy/mm/dd-hh:mm:ss     for sec from 1970//~v50eI~
//                         yyyy/mm/dd-hh:mm:ss.mmm for dowrd tod of host(from 1900)//~v50eI~
//                       if no conv-option convert to by input datatype
//                          Time,Oct,Hex is 'D'(time is by seconds)//~v50eR~
//                          dec          is 'X'
//  binary opr :  BC opd1 opr opd2 /conv-option  [R]               //~v57JR~
//                  -opd1/opd2:same as value of conversion case.
//                   decimal type may have under point data except for +,-,*,/,%.//~v50eR~
//                  -opr:+,-,*,/,%,<,>,|,&,^,!                     //~v169R~
//  					for time value only + and - is valid.
//  					when opd1<opd2 for timestamp subtraction,
//                        2 format result is displayed timestamp
//                        and - timestamp format.
//                      for time and other data type,
//                        other type value is treated as seconds.
//                  -conv-option:
//                       X:conv to Hex
//                       O:conv to Oct
//                       D:conv to Dec
//                       U:conv to unsigned decimal
//                       Z:output by zz,zzz,zz9 fmt
//                       if no conv-option output fmt is by opd1 datatype
//                       underpoint is ignored for X and O.        //~v50eR~
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#ifdef DOS
#else
	#ifdef W32
//  	#include <windows.h>
	#else
//    #define INCL_BASE
//    #include <os2.h>
	#endif
#endif
//*******************************************************
#include <ulib.h>
#include <uerr.h>
#include <uque.h>
#include <ufile.h>
#include <ualloc.h>
#include <uedit.h>
#include <uparse.h>
#define UCALC_GBL	//for ucalc.h define gbl                       //~v5f9I~
#include <ucalc.h>                                                 //~v314I~
#include <ucalc2.h>                                                //~v50eI~

//*******************************************************
#define CALC_CONV2SEC     0x0100       //time conversion to x/o/d/z
#define CALC_CONV2HMS     0x0200       //time conversion to x/o/d/z
#define CALC_OPD2SEC      0x0400       //time +/- second
#define CALC_OPD1SEC      0x0800       //time +/- second
#define CALC_CONVTYPEMASK 0x00ff       //time +/- second
                                                                   //~v5drI~
#define MINUSSIGN   '-'                                            //~v5drR~
typedef struct _OPDVALUE{                                          //~v6K3I~
			long lvt[4];                                           //~v6K3R~
            int  functype;                                         //~v6K3I~
            int datatype;                                          //~v6K3I~
            int datatyped;                                         //~v6K3I~
            int convtype;                                          //~v6K3I~
            } OPDVALUE, *POPDVALUE;                                //~v6K3I~
#define OPDVALUESZ sizeof(OPDVALUE)                                //~v6K3I~
//*******************************************************
static long Spnumtbl[MAX_POINT_NUM+1]={1,10,100,1000,10000,100000,1000000,
										10000000,100000000,1000000000};
//static char Sopcode[]="+-*/%<>|&^!";		                       //~v5e9R~
static char Sopcode[]="+-*/%<>|&^!?";                              //~v5e9I~
static int  Sresultsw=0;                                           //~v57JI~
//static int  Sdwupsw=GETLD_DWUP;                                  //~v5drR~
static int Svprec=0,Svround=0;  //output precision and round option//~v5e3R~
static int Svarno=-1;			//no of $n=                        //~v5f9R~
static int Svarno12=-1;			//no of $n= for opd1 or opd2       //~v5f9I~
static int Svarno1=-1;			//no of $n= for opd1               //~v5f9R~
static int Svarno2=-1;			//no of $n= for opd2               //~v5f9I~
#define MAX_OPDVALUE 8          //2+8                              //~v6K3I~
static int Sopdvaluectr;                                           //~v6K3R~
static OPDVALUE Sopdvalue[MAX_OPDVALUE];                           //~v6K3I~
static int SovfHH;                                                 //~v6K6I~
//*******************************************************
//int bc_opdchk(UCHAR *Pcmdstr,UCHAR *Poutcmdstr,int *Pfunctype,int *Popdtype,long *Pconstv,long *Pconstv2,char **Pdelmt);//~v5drR~
int bc_opdchk(UCHAR *Pcmdstr,UCHAR *Poutcmdstr,int *Pfunctype,int *Popdtype,long *Pconstv,long *Pconstv2,char **Pdelmt,int *Ppopt);//~v5drI~
//int bc_getvalue(char *Popd,long *Pvalue,int *Pdatatype,int *Pdatatyped);//~v597R~
//int ucalc_shiftdown(ULONG *Pupdata,int Pshift);                  //~v5drR~
int  calcuperr1(void);                                             //~v169I~
int calcuperr2(void);
int calcerrinvalid(UCHAR *Popd);                                   //~v314I~
int calcerrformat(void);                                           //~v50iR~
int calcerrminus(void);                                            //~v5dsI~
int bc_opdcopy(int Popt,LONG *Pout,LONG *Pinp);                    //~v5dtI~
#define OPDCOPY_COPY    0                                          //~v5dtI~
#define OPDCOPY_PLUS    1                                          //~v5dtI~
#define OPDCOPY_MINUS   2                                          //~v5dtI~
int bc_putwordordword(int Popt,LONG *Pout,LONG *Pnumfmt);          //~v5dtI~
int bc_expand2dword(LONG Povf,LONG *Pwordfmt);                     //~v5dtI~
int calcerrunderflow(void);                                        //~v5duI~
int ucalc_dwtime(int Popt,int Popr,long *Popd1,long *Popd2);       //~v5dwI~
int calcerrtimeop(void);                                           //~v5dxI~
int getvarname(char *Pcmdstr,int *Ppvarno,char **Pnextpos);        //~v5f9R~
int calcerrinvalid_dw(UCHAR *Popd);                                //~v6xgI~
int bc_getvalue3(int Popt,UCHAR *Popd3,UCHAR *Ppot0,PUPODELMTBL Pdelmt0,int Popdno,int *Ppminusopdctr);//~v6K3R~
int bc_setconvtype3(int Popt,int Pdatatype1,int Pdatatype2,int Pparmconvtype,int *Ppconvtype);//~v6K3R~
//****************************************************************
// calc body
//*rc   :0
//****************************************************************
//int ucalc_bcmain(UCHAR *Pcmdstr)                                 //~v57JR~
int ucalc_bcmain(UCHAR *Pcmdstr,UCHAR *Presultstr)                 //~v57JI~
{
    int rc,functype,convtype,timeopt,len,timecal;
    int opt;                                                       //~v546I~
    int opt2;                                                      //~v6K6I~
//  long lvt1[3],lvt2[3];                                          //~v5djR~
//  long lvt3[3];       //for divide residual                      //~v5djR~
    long lvt1[4],lvt2[4];                                          //~v5djR~
    long lvt3[4];       //for divide residual                      //~v5djR~
//  char rval[32];                                                 //~v5f9R~
    char rval[UCALC_MAXRESULTLEN];                                 //~v5f9I~
    char varval[256];                                              //~v5f9I~
    char *pdelmt,*pc;
    UCHAR outcmdstr[256];                                          //~v573I~
    UCHAR outdays[32];                                             //~v6K5I~
    int parmopt;                                                   //~v5drI~
    int xresdispsw=0;                                              //~v5duR~
    int vropt;                                                     //~v5e3I~
    int opd3ctr=0;                                                 //~v6K3R~
    int datatype;                                                  //~v6K3I~
    POPDVALUE pov;                                                 //~v6K3I~
//*********************************
	if (!Pcmdstr||!*Pcmdstr)		//no operand                   //~v314R~
        return 12;                                                 //~v314R~
    memset(lvt1,0,sizeof(lvt1)); 	//for unaly "-"                //~v50sI~
    memset(lvt2,0,sizeof(lvt2));                                   //~v50sI~
//  rc=bc_opdchk(Pcmdstr,&functype,&convtype,lvt1,lvt2,&pdelmt);   //~v573R~
//  rc=bc_opdchk(Pcmdstr,outcmdstr,&functype,&convtype,lvt1,lvt2,&pdelmt);//~v5drR~
    rc=bc_opdchk(Pcmdstr,outcmdstr,&functype,&convtype,lvt1,lvt2,&pdelmt,&parmopt);//~v5drI~
    if (pdelmt)
        ufree(pdelmt);
    if (rc)
    {
    	if (rc==8)
			calcerrformat();                                       //~v50iR~
    	return rc;
	}
  for (opd3ctr=0;opd3ctr<=Sopdvaluectr;opd3ctr++)                  //~v6K3M~
  {                                                                //~v6K3M~
    timeopt=0;
    if (convtype & CALC_CONV2SEC)
	    timeopt|=CALC_TIME_CONV2SEC;
    if (convtype & CALC_OPD2SEC)       //+,- ope of time and second
	    timeopt|=CALC_TIME_2SEC;
    if (convtype & CALC_OPD1SEC)       //+,- ope of time and second
	    timeopt|=CALC_TIME_1SEC;
    if (convtype & CALC_CONV2HMS)         //sec to hms
	    timeopt|=CALC_TIME_CONV2HMS;

    convtype &=CALC_CONVTYPEMASK;
    timecal=timeopt||(convtype=='T');
//calc
    switch(functype)
    {
    case '=':			//conversion
    	if (timeopt)       //time calc conv to sec
            rc=                                                    //~v5dxI~
        	ucalc_time(timeopt,'=',lvt1,lvt1);    //conv to sec    //~v314R~
        break;
    case '+':
    	if (timecal)      //time calc
            rc=                                                    //~v5dxI~
	        ucalc_time(timeopt,'+',lvt1,lvt2);                     //~v314R~
        else
            rc=                                                    //~v50eI~
//      	ucalc_binop(0,'+',lvt1,lvt2);		//+=               //~v5djR~
        	ucalc_binop(CALC_DWORDUP|parmopt,'+',lvt1,lvt2);		//+=//~v5drR~
        break;
    case '-':
    	if (timecal)
            rc=                                                    //~v5dxI~
        	ucalc_time(timeopt,'-',lvt1,lvt2);	//no sign          //~v314R~
        else
            rc=                                                    //~v50eI~
//      	ucalc_binop(0,'-',lvt1,lvt2);		//-=               //~v5djR~
        	ucalc_binop(CALC_DWORDUP|parmopt,'-',lvt1,lvt2);		//-=//~v5drR~
        break;
    case '?':                                                      //~v5e9M~
    	if (timecal)                                               //~v5e9I~
            rc=ucalc_time(timeopt,'?',lvt1,lvt2);	//no sign      //~v5e9I~
        else                                                       //~v5e9I~
            rc=ucalc_binop(CALC_DWORDUP|parmopt,'?',lvt1,lvt2);		//-=//~v5e9I~
        lvt1[0]=rc;                                                //~v5e9I~
        lvt1[1]=0;                                                 //~v5e9I~
        break;                                                     //~v5e9I~
    case '*':
//  case '!':                                                      //~v544R~
    	if (timecal)
            rc=                                                    //~v5dxI~
        	ucalc_time(timeopt,functype,lvt1,lvt2);	//no sign      //~v314R~
        else
        {                                                          //~v543I~
            if (convtype=='U'||convtype=='Y')  //U oy UZ           //~v546I~
//              opt=0;                                             //~v5dbR~
                opt=CALC_NOOVFMSG;  //no overflow errmsg           //~v5dbI~
            else                                                   //~v546I~
//              opt=CALC_SIGNED;                                   //~v5dtR~
                opt=0;                                             //~v5dtI~
            opt|=CALC_DWORDUP|parmopt;                             //~v5drR~
            rc=                                                    //~v50eI~
//          ucalc_binop(0,functype,lvt1,lvt2);		//+=           //~v546R~
            ucalc_binop(opt,functype,lvt1,lvt2);		//+=       //~v546I~
////          if (rc)                                              //~v5drR~
//            if (rc==CALC_RCWORDOVF)                              //~v5drR~
//            {                                                    //~v5drR~
//                if (!lvt1[1] && !lvt2[1])   //no underpoint no dword//~v5drR~
//                {                                                //~v5drR~
//                    lvt1[1]=UCALC_DWORDID;                       //~v5drR~
//                    lvt1[2]=lvt1[0];        //low word of dword  //~v5drR~
//                    lvt1[0]=0;              //high word of dword //~v5drR~
//                    rc=ucalc_binop(0,functype,lvt1,lvt2);//retry by dowrd//~v5drR~
//                }                                                //~v5drR~
//                else                                             //~v5drR~
//                    uerrmsg("Multiply Overflow",0);              //~v5drR~
//            }//wordovf                                           //~v5drR~
        }                                                          //~v543I~
        break;
    case '!':                                                      //~v544I~
//      rc=ucalc_binop(0,functype,lvt1,lvt2);		//+=           //~v5drR~
//      rc=ucalc_binop(parmopt,functype,lvt1,lvt2);		//+=       //~v5duR~
    	if (timecal)                                               //~v5dxI~
			return calcerrtimeop();                                //~v5dxI~
        rc=ucalc_binop(parmopt|CALC_DWORDUP,functype,lvt1,lvt2);		//+=//~v5duI~
//      if (lvt1[1])    //overflow to dword                        //~v5duR~
//      {                                                          //~v5duR~
//      	lvt1[2]=lvt1[0];		//low word of dword            //~v5duR~
//          lvt1[0]=lvt1[1];		//high word of dword           //~v5duR~
//          lvt1[1]=UCALC_DWORDID;                                 //~v5duR~
//      }                                                          //~v5duR~
        break;                                                     //~v544I~
    case '/':
        if (Svprec!=-1)    //Vnn option                            //~v5e3I~
            ucalc_vrajust(0,lvt1,Svprec);//no cut,no round         //~v5e3I~
    	if (timecal)
            rc=                                                    //~v5dxI~
        	ucalc_time(timeopt|CALC_TIME_DIVPREC,functype,lvt1,lvt2);	//no sign//~v314R~
        else
        {                                                          //~v56vI~
            xresdispsw=!((lvt1[1]|lvt2[1]) & UCALC_UPMASK);	//no up//~v5dtI~
            if (opd3ctr!=Sopdvaluectr) //not last calc             //~v6K3I~
	            xresdispsw=0;	//ignore residual                  //~v6K3I~
//      	lvt3[0]=lvt1[0];                                       //~v5dtR~
//      	lvt3[1]=lvt1[1];                                       //~v5dtR~
//      	lvt3[2]=lvt1[2];                                       //~v5dtR~
            memcpy(lvt3,lvt1,sizeof(lvt3));                        //~v5dtI~
            opt=CALC_DWORDUP|CALC_DIV_PRECUP|parmopt;              //~v5drR~
            rc=                                                    //~v50eI~
//      	ucalc_binop(CALC_DIV_PRECUP,'/',lvt1,lvt2);		//+=   //~v5drR~
        	ucalc_binop(opt,'/',lvt1,lvt2);		//+=               //~v5drI~
          if (!rc)                                                 //~v5dpI~
            if (convtype=='X'||convtype=='O')	//no underpoint display case//~v56vI~
              if (xresdispsw)                                      //~v5dtR~
//		        ucalc_binop(0,'%',lvt3,lvt2);		//+=           //~v5drR~
  		        ucalc_binop(parmopt,'%',lvt3,lvt2);		//+=       //~v5drI~
        }                                                          //~v56vI~
        break;
    case '%':
    	if (timecal)
            rc=                                                    //~v5dxI~
        	ucalc_time(timeopt,functype,lvt1,lvt2);	//no sign      //~v314R~
        else
            rc=                                                    //~v50eI~
//          ucalc_binop(0,'%',lvt1,lvt2);		//+=               //~v5drR~
            ucalc_binop(parmopt,'%',lvt1,lvt2);		//+=           //~v5drI~
        break;
    case '<':
    case '>':
    case '|':                                                      //~v167I~
    case '&':                                                      //~v167I~
    case '^':                                                      //~v167I~
    	if (timecal)
        {
//  		uerrmsg("Operation not avail for Time",                //~v5dxR~
//  				"時間にこの操作はできません");                 //~v5dxR~
//          return 4;                                              //~v5dxR~
			return calcerrtimeop();                                //~v5dxI~
        }
        rc=                                                        //~v50eI~
//      ucalc_binop(0,functype,lvt1,lvt2);                         //~v5drR~
        ucalc_binop(parmopt,functype,lvt1,lvt2);                   //~v5drI~
        break;
    }
    if (rc>=4)    //not compare result                             //~v50eR~
        return rc;                                                 //~v50eI~
  	if (opd3ctr<Sopdvaluectr)	//continue binop                   //~v6K3I~
    {                                                              //~v6K3I~
    	pov=Sopdvalue+opd3ctr;                                     //~v6K3R~
    	memcpy(lvt2,pov->lvt,sizeof(lvt2));                        //~v6K3R~
        functype=pov->functype;                                    //~v6K3I~
        datatype=convtype;  //lvt1 datatype                        //~v6K3I~
        convtype=pov->convtype;                                    //~v6K3M~
    	if (opd3ctr+1==Sopdvaluectr && !convtype)   //last         //~v6K3I~
        {                                                          //~v6K3I~
            if (datatype=='U' && (*(lvt1+1)==UCALC_DWORDID))    //long decimal//~v6K3I~
                convtype='Z';                                      //~v6K3I~
            else                                                   //~v6K3I~
            {                                                      //~v6K3I~
        		convtype=datatype;		//from 1st opd type        //~v6K3I~
                if(convtype=='D')                                  //~v6K3I~
                    convtype='Z';                                  //~v6K3I~
            }                                                      //~v6K3I~
        }                                                          //~v6K3I~
    }                                                              //~v6K3I~
  }//loop by opd3ctr                                               //~v6K3I~
 if (functype==UCALC_LISTFUNC)                                     //~v5f9I~
 {                                                                 //~v5f9I~
    strncpy(rval,Gucalc_result[Svarno],UCALC_MAXRESULTLEN);        //~v5f9R~
 }                                                                 //~v5f9I~
 else                                                              //~v5f9I~
 {                                                                 //~v5f9I~
//output conv
    rval[0]=0;      //for err case                                 //~v50tI~
    if (Svprec!=-1||Svround)    //round or Vnn option              //~v5e3I~
    {                                                              //~v5e3I~
        vropt=Svround|UCVRA_PRECDOWN;                              //~v5e3I~
    	if (convtype=='T')                                         //~v5e3I~
	        vropt|=UCVRA_TIME;                                     //~v5e3I~
        ucalc_vrajust(vropt,lvt1,Svprec);                          //~v5e3R~
    }                                                              //~v5e3I~
//if (lvt1[1]==UCALC_DWORDID || lvt2[1]==UCALC_DWORDID)            //~v5djR~
//if (lvt1[1]>=UCALC_DWORDID || lvt2[1]>=UCALC_DWORDID)            //~v5e9R~
  if (functype!='?'                                                //~v5e9I~
  &&  (lvt1[1]>=UCALC_DWORDID || lvt2[1]>=UCALC_DWORDID))          //~v5e9I~
  {                                                                //~v50eI~
  	if (bc_dweditnum(functype,convtype,lvt1,rval))                 //~v50eR~
    	return 4;                                                  //~v50eI~
   if (xresdispsw)  //residual display                             //~v5duI~
    if (functype=='/')  //divide                                   //~v56vI~
    {                                                              //~v56vI~
    	len=(int)strlen(rval);                                     //~v57uR~
    	switch(convtype)                                           //~v56vI~
        {                                                          //~v56vI~
	    case 'X':     //convert to HEX value                       //~v56vI~
	        strcpy(rval+len,"...");                                //~v56vI~
            len+=3;                                                //~v56vI~
			ucalc_editevenhex(lvt3[2],rval+len);                   //~v56vR~
        	break;                                                 //~v56vI~
	    case 'O':     //convert to OCT value                       //~v56vI~
            sprintf(rval+len,"...o%lo",lvt3[2]);                   //~v56vR~
            break;                                                 //~v56vI~
        }                                                          //~v56vI~
    }//residual output case                                        //~v56vI~
  }                                                                //~v50eI~
  else                                                             //~v50eI~
  {                                                                //~v5e9I~
	if (functype=='?')                                             //~v5e9I~
    	convtype='D';                                              //~v5e9I~
    switch(convtype)
    {
    case 'X':     //convert to HEX value
//        len=sprintf(rval,"x%lX",lvt1[0])-1;                      //~v56vR~
//        if (len%2)  //odd number with top x                      //~v56vR~
//        {                                                        //~v56vR~
//            memmove(rval+2,rval+1,(UINT)(len+1));                //~v56vR~
//            *(rval+1)='0';                                       //~v56vR~
//            len++;                                               //~v56vR~
//        }                                                        //~v56vR~
        *rval='x';                                                 //~v56vR~
		len=1+ucalc_editevenhex(lvt1[0],rval+1);                   //~v56vR~
      if (xresdispsw)                                              //~v5duI~
        if (functype=='/')  //divide                               //~v56vI~
        {                                                          //~v56vI~
	        strcpy(rval+len,"...");                                //~v56vI~
            len+=3;                                                //~v56vI~
			ucalc_editevenhex(lvt3[0],rval+len);                   //~v56vR~
        }                                                          //~v56vI~
    	break;
    case 'O':     //convert to OCT value
        len=                                                       //~v56vI~
    	sprintf(rval,"o%lo",lvt1[0]);
      if (xresdispsw)                                              //~v5duI~
        if (functype=='/')  //divide                               //~v56vI~
            sprintf(rval+len,"...o%lo",lvt3[0]);                   //~v56vI~
    	break;
    case 'U':     //convert to DEC value
        ucalc_editnum(0,rval,lvt1);                                //~v314R~
    	break;
    case 'D':     //convert to DEC value
        ucalc_editnum(CALC_ENSIGNED,rval,lvt1);                    //~v314R~
    	break;
    case 'Z':     //convert to DEC value
        ucalc_editnum(CALC_ENSIGNED|CALC_ENZ,rval,lvt1);           //~v314R~
    	break;
    case 'Y':     //convert to unsigned edit DEC                   //~v50rI~
        ucalc_editnum(CALC_ENZ,rval,lvt1);                         //~v50rI~
    	break;                                                     //~v50rI~
    case 'L':     //convert TOD                                    //~v50jR~
        if (bc_edittod(rval,lvt1))                                 //~v50tR~
        	return 4;                                              //~v50tI~
    	break;                                                     //~v50fI~
    case 'T':     //output TIME format
//      ucalc_timeedit(0,rval,lvt1);                               //~v314R~//~v6K6R~
		opt2=0;                                                    //~v6K6I~
        if (SovfHH)	                                               //~v6K6I~
        	opt2|=CALC_OVFHH;                                      //~v6K6I~
        ucalc_timeedit(opt2,rval,lvt1);                            //~v6K6I~
//      if (lvt1[0] & CALC_TIME_MINUS)                             //~v6xiR~
        if ((UINT4)lvt1[0] & CALC_TIME_MINUS)                      //~v6xiI~
        {
   		 	pc=rval+strlen(rval);
            *pc++='(';
//      	pc+=ucalc_timeedit(CALC_DAYS|CALC_DAYSONLY,pc,lvt1);	//over 24h//~v6K5I~//~v6K6R~
            opt2|=CALC_DAYS|CALC_DAYSONLY;                         //~v6K6I~
        	pc+=ucalc_timeedit(opt2,pc,lvt1);	//over 24h         //~v6K6I~
        	ucalc_time(CALC_TIME_BORROW|CALC_TIME_CONV2SEC|CALC_TIME_CONV2HMS,'=',lvt1,lvt1);	//no sign//~v314R~
   		 	ucalc_timeedit(0,pc,lvt1);                             //~v314R~
            pc+=strlen(pc);
            *pc++=')';
            *pc=0;
        }
        else                                                       //~v6K5I~
        {                                                          //~v6K6I~
        	opt2|=CALC_DAYS;                                       //~v6K6I~
//      if (ucalc_timeedit(CALC_DAYS,outdays,lvt1))	//over 24h     //~v6K5R~//~v6K6R~
        if (ucalc_timeedit(opt2,outdays,lvt1))	//over 24h         //~v6K6I~
        {                                                          //~v6K5I~
   		 	pc=rval+strlen(rval);                                  //~v6K5I~
            sprintf(pc,"(%s)",outdays);                            //~v6K5I~
        }                                                          //~v6K5I~
        }                                                          //~v6K6I~
    	break;
    }
  }//not dword                                                     //~v5e9I~
 }//not $n list func                                               //~v5f9I~
  if (Svarno1>=0||Svarno2>=0)	//opd1 or opd2=$n                  //~v5f9I~
  {                                                                //~v5f9I~
    	pc=varval;                                                 //~v5f9I~
	    if (Svarno1>=0)                                            //~v5f9I~
		    pc+=sprintf(pc," # $%d=%s",Svarno1,Gucalc_result[Svarno1]);//~v5f9I~
	    if (Svarno2>=0 && Svarno1!=Svarno2)                        //~v5f9I~
		    pc+=sprintf(pc," # $%d=%s",Svarno2,Gucalc_result[Svarno2]);//~v5f9I~
	    uerrmsg("%s:=%s  %s",0,                                    //~v5f9I~
                outcmdstr,rval,varval);                            //~v5f9I~
  }                                                                //~v5f9I~
  else                                                             //~v5f9I~
    uerrmsg("%s:=%s",0,
//  			Pcmdstr,                                           //~v573R~
                outcmdstr,                                         //~v573I~
				rval);
    if (Presultstr) //result value required                        //~v57JR~
    {                                                              //~v597R~
        if (Sresultsw) //result value required                     //~v57JI~
//          sprintf(Presultstr,rval);                              //~v6DiR~
            sprintf(Presultstr,"%s",rval);                         //~v6DiR~
        else                                                       //~v57JR~
            *Presultstr=0;  //clear                                //~v57JR~
    }                                                              //~v597R~
  if (functype!=UCALC_LISTFUNC)                                    //~v5f9I~
  {                                                                //~v5f9I~
    if (Svarno>=0)                                                 //~v5f9R~
    	strncpy(Gucalc_result[Svarno],rval,UCALC_MAXRESULTLEN);	//save to $n//~v5f9R~
  }                                                                //~v5f9I~
    strncpy(Gucalc_result[0],rval,UCALC_MAXRESULTLEN);	//save to $0//~v5f9R~
    return 0;
}//ucalc_bcmain                                                    //~v314R~
//****************************************************************
// basic calc opd chk
//parm3:by /type parm
//      default output data type:for conv;input O/X-->D,else -->X
//      binnary op from 1st opd datatype
//*rc   :0,  4:err msg issued 8:need fmt err msg
//****************************************************************
//int bc_opdchk(UCHAR *Pcmdstr,UCHAR *Poutcmdstr,int *Pfunctype,int *Pconvtype,long *Pconstv1,long *Pconstv2,char **Ppdelmt)//~v5drR~
int bc_opdchk(UCHAR *Pcmdstr,UCHAR *Poutcmdstr,int *Pfunctype,int *Pconvtype,long *Pconstv1,long *Pconstv2,char **Ppdelmt,int *Ppparmopt)//~v5drI~
{
    PUPODELMTBL pdelmt,pdelmt0;
    UCHAR *ppot0;
    char  *ppot,*popd1,*popd2,*pconvt;
    int  opdno,delm,ii,convopt,uzsw;                               //~v50rR~
	int  functype,convtype=0,datatype=0,datatype2=0;
    int rc,convt;                                                  //~v5e3R~
//  ULONG dwwk[3];                                                 //~v5drR~
//  LONG dwwk[4];                                                  //~v5dtR~
    char *pc;                                                      //~v573I~
    char *vrpos,vrchar=0;                                            //~v5e3I~//~v6h6R~
//  char *lastopd=0;                                               //~v5e3R~
    int len,datatyped1=0,datatyped2=0,opdno0;                      //~v573R~
    int parmopt=0;                                                 //~v5drI~
    int vrpno=0;                                                   //~v5e6I~
    int minusctr;                                                  //~v6K3I~
    char *parmvnr=0;                                               //~v5e6R~
    int datatyped3,parmconvtype=0;                                 //~v6K3R~
//*********************************
	Svarno=-1;		//no save option at init                       //~v5f9I~
	Svarno1=-1;		//no save option at init                       //~v5f9I~
	Svarno2=-1;		//no save option at init                       //~v5f9I~
	Sopdvaluectr=0;                                                //~v6K3I~
    *Ppdelmt=0;                                                    //~v5f9I~
	if (*Pcmdstr==UCALC_VARID)  //$n                               //~v5f9I~
    {                                                              //~v5f9I~
        if (getvarname(Pcmdstr+1,&Svarno,&pc))                     //~v5f9R~
            return 4;                                              //~v5f9I~
        if (!*pc)	//$n only                                      //~v5f9M~
        {                                                          //~v5f9M~
        	*Pfunctype=UCALC_LISTFUNC;                             //~v5f9M~
            strcpy(Poutcmdstr,Pcmdstr);                            //~v5f9I~
            return 0;                                              //~v5f9M~
        }                                                          //~v5f9M~
        if (*pc=='=')                                              //~v5f9R~
        {                                                          //~v5f9I~
        	pc++;                                                  //~v5f9R~
        	pc+=strspn(pc," \t");                                  //~v5f9R~
        	Pcmdstr=pc;                                            //~v5f9R~
            Poutcmdstr+=sprintf(Poutcmdstr,"$%d=",Svarno);         //~v5f9I~
        }                                                          //~v5f9I~
    }                                                              //~v5f9I~
    Svprec=-1;				//id of no VnnR option                 //~v5e6R~
    Svround=0;				                                       //~v5e6R~
  	if (uparse2(Pcmdstr,&pdelmt0,&ppot0,&opdno,UPARSE2SETCONTDLM2, //~v314R~
				Sopcode))	//rep space delm by next delm          //~v167R~
    {
    	*Ppdelmt=0;
    	return 8;	//need errmsg
	}
    *Ppdelmt=(char*)(void*)pdelmt0;  //need free
//back "-" delm as sign prefix                                     //~v5drI~
    if (!*ppot0 && opdno && pdelmt0->upodelm==MINUSSIGN)//start by "-"//~v5drR~
    {                                                              //~v5drI~
        *ppot0=MINUSSIGN;                                          //~v5drI~
        opdno--;                                                   //~v5drI~
//      memcpy(pdelmt0,pdelmt0+1,(UINT)(sizeof(UPODELMTBL)*opdno));//~v5drR~//~v6xiR~
        memcpy(pdelmt0,pdelmt0+1,(sizeof(UPODELMTBL)*(size_t)opdno));//~v6xiR~
    }                                                              //~v5drI~
    if (opdno>2)                                                   //~v5drI~
    {                                                              //~v5drI~
		pc=ppot0+strlen(ppot0)+1;	//2nd opd                      //~v5drR~
	    if (!*pc && (pdelmt0+1)->upodelm==MINUSSIGN)//2nd opd start by "-"//~v5drI~
        {                                                          //~v5drI~
        	*pc=MINUSSIGN;                                         //~v5drI~
        	opdno--;                                               //~v5drI~
//        	memcpy(pdelmt0+1,pdelmt0+2,(UINT)(sizeof(UPODELMTBL)*(opdno-1)));//~v5drR~//~v6xiR~
        	memcpy(pdelmt0+1,pdelmt0+2,sizeof(UPODELMTBL)*(size_t)(opdno-1));//~v6xiR~
        }                                                          //~v5drI~
    }                                                              //~v5drI~
                                                                   //~v5drI~
    Sresultsw=0;    //clear at first                               //~v57JI~
//  for (ii=0,ppot=ppot0;ii<opdno;ii++,ppot+=strlen(ppot)+1)       //~v5e3R~
//      lastopd=ppot;                                              //~v5e3R~
//  if (lastopd)                                                   //~v5e3R~
//      if (!stricmp(lastopd,"R"))  //result output option         //~v5e3R~
//        if (!memicmp(Pcmdstr+strlen(Pcmdstr)-2," R",2))  //result output option//~v5e6R~
//        {                                                        //~v5e6R~
//            Sresultsw=1;                                         //~v5e6R~
//            opdno--;                                             //~v5e6R~
//        }                                                        //~v5e6R~
    for (ii=0,ppot=ppot0,vrpno=0;ii<opdno;ii++,ppot+=strlen(ppot)+1)//~v5e6I~
    {                                                              //~v5e6I~
        if (!stricmp(ppot,"R"))  //result output option            //~v5e6I~
        {                                                          //~v5e6I~
        	vrpno++;                                               //~v5e6I~
            Sresultsw=1;                                           //~v5e6I~
        }                                                          //~v5e6I~
        else                                                       //~v5e6I~
        if (toupper(*ppot)=='V')  //result output option           //~v5e6R~
        {                                                          //~v5e6I~
	        if (rc=ucalc_chkvrparm(ppot,&Svprec,&Svround,&vrpos),rc)//~v5e6I~
    	    	return rc;                                         //~v5e6I~
        	parmvnr=ppot;                                          //~v5e6R~
        	vrpno++;                                               //~v5e6I~
        }                                                          //~v5e6I~
    }                                                              //~v5e6I~
    opdno-=vrpno;                                                  //~v5e6I~
    if (!opdno)
    	return 8;	//need errmsg
    opdno0=opdno;	//save for drop conv type                      //~v573I~
//chk conv type
	pconvt=0;
	for (ii=0,ppot=ppot0,pdelmt=pdelmt0;ii<opdno;ii++,ppot+=strlen(ppot)+1,pdelmt++)
    {                                                              //~v5e3I~
    	if (ii==opdno-2)	//last opd
        {
			if (pdelmt->upodelm=='/')
            	pconvt=ppot;
            break;
		}
    	if (ii==opdno-1)	//last opd                             //~v5e3I~
        {                                                          //~v5e3I~
			if (pdelmt->upodelm=='/')   //last opd ended with "/"  //~v5e3I~
            	return 8;                                          //~v5e3I~
		}                                                          //~v5e3I~
    }                                                              //~v5e3I~
//  Svprec=-1;				//id of no [outputtype]Vnn option      //~v5e6R~
//  Svround=0;				//id of no [outputtype][Vnn]R option   //~v5e6R~
    if (pconvt)             //may convt parm
    {
    	pconvt+=strlen(pconvt)+1;	//last opd
        vrpos=0;    //for the case Svprec!=-1                      //~v5g5I~
      if (Svprec==-1)				//id of no VnnR option;seperated VnnR not specified//~v5fjI~
      {                                                            //~v5fjI~
        if (rc=ucalc_chkvrparm(pconvt,&Svprec,&Svround,&vrpos),rc) //~v5e3R~
        	return rc;                                             //~v5e3I~
        if (vrpos)                                                 //~v5e3I~
        {                                                          //~v5e3I~
            if (vrpos==pconvt)  //without output type              //~v5e3I~
                vrpos++;        //remain V/R only                  //~v5e3I~
        	vrchar=*vrpos;	//save before nullify                  //~v5e3I~
        	*vrpos=0;                                              //~v5e3I~
        }                                                          //~v5e3I~
      }                                                            //~v5fjI~
        rc=0;                                                      //~v5e3I~
        if ((uzsw=(stricmp(pconvt,"UZ")==0)),uzsw)                 //~v50rI~
        	pconvt++;                                              //~v50rI~
        if (*pconvt && !*(pconvt+1))
        {
            convtype=toupper(*pconvt);
            if (convtype!='X'
            &&  convtype!='O'
            &&  convtype!='D'
            &&  convtype!='U'
            &&  convtype!='T'
            &&  convtype!='L'   //clock conversion                 //~v50jR~
            &&  convtype!='V'   //Vnn                              //~v5e3I~
            &&  convtype!='R'   //Round option                     //~v5e3I~
            &&  convtype!='Z')
                convtype=0;   //reset
            else
            {
                opdno--;
                pdelmt->upodelm=0;  //ignore last '/'
    		    if (!opdno)
//      			return 8;                                      //~v5e3R~
        			rc=8;                                          //~v5e3I~
                else                                               //~v5e3I~
                {                                                  //~v5e3I~
    		    	if (opdno==1)                                  //~v5e3I~
    					if (!strlen(ppot0))//opd1 null;  "/x" fmt  //~v5e3I~
		        			rc=8;                                  //~v5e3I~
                }                                                  //~v5e3I~
                if (uzsw)                                          //~v50rI~
                	convtype='Y';	//unsigned z                   //~v50rI~
                if (convtype=='V'                                  //~v5e3I~
                ||  convtype=='R')//without output type            //~v5e3I~
                    convtype=0;                                    //~v5e3I~
                parmconvtype=convtype;                             //~v6K3I~
            }
        }// /type
        if (vrpos)                                                 //~v5e3I~
        	*vrpos=vrchar;	//save before nullify                  //~v5e3R~
        if (rc)                                                    //~v5e3I~
        	return rc;                                             //~v5e3I~
    }
    popd1=ppot0;
//  if (bc_getvalue(popd1,Pconstv1,&datatype))                     //~v573R~
//  if (bc_getvalue(popd1,Pconstv1,&datatype,&datatyped1))         //~v5drR~
    if (bc_getvalue(CALC_DWORDUP,popd1,Pconstv1,&datatype,&datatyped1))//~v5drI~
    	return 4;                                                  //~v314R~
    Svarno1=Svarno12;	//opd1 varno ,output from bc_getvalue      //~v5f9R~
    if (opdno==1)
    {
    	functype='=';
        if (!convtype)		//no out parm
            switch(datatype)
            {
            case 'T':
            case 'O':
            case 'X':
//            if (*(Pconstv1+1)==UCALC_DWORDID)                    //~v50rR~
        		convtype='Z';           //unary dword              //~v50gR~
//            else                                                 //~v50rR~
//      		convtype='D';                                      //~v50rR~
                break;
            default:
            	convtype='X';           //default is decimal output
            }
	    if (datatype=='T')
        {
        	if (convtype!='T')
    	    	convtype|=CALC_CONV2SEC;	//conv to seconds
		}
        else
        	if (convtype=='T')
    	    	convtype|=CALC_CONV2HMS;	//conv to seconds
    }
    else	//bin opd
    {
    	if (!convtype)
        {                                                          //~v50gI~
            if (datatype=='U' && (*(Pconstv1+1)==UCALC_DWORDID))    //long decimal//~v50gI~
                convtype='Z';                                      //~v50gI~
            else                                                   //~v50gI~
            {                                                      //~v50rI~
        	convtype=datatype;		//from 1st opd type
                if(convtype=='D')                                  //~v50rI~
                    convtype='Z';                                  //~v50rI~
            }                                                      //~v50rI~
        }                                                          //~v50gI~
    	popd2=popd1+strlen(popd1)+1;
        if (!*popd2)	//opecode continued                        //~v50iI~
			return calcerrformat();                                //~v50iI~
//  	if (bc_getvalue(popd2,Pconstv2,&datatype2))                //~v573R~
//    	if (bc_getvalue(popd2,Pconstv2,&datatype2,&datatyped2))    //~v5drR~
      	if (bc_getvalue(CALC_DWORDUP,popd2,Pconstv2,&datatype2,&datatyped2))//~v5drI~
    		return 4;                                              //~v314R~
	    Svarno2=Svarno12;	//opd1 varno ,output from bc_getvalue  //~v5f9R~
    	delm=pdelmt0->upodelm;
//      if (delm==' ')                                             //~v5drR~
//      {                                                          //~v5drR~
//  	    delm=(pdelmt0+1)->upodelm;                             //~v5drR~
//          popd2+=strlen(popd2)+1;                                //~v5drR~
//          opdno--;                                               //~v5drR~
//      }                                                          //~v5drR~
        if (opdno!=2)
        {                                                          //~v6K3I~
          if (rc=bc_getvalue3(0,popd2+strlen(popd2)+1,ppot0,pdelmt0,opdno,&minusctr),rc)//~v6K3R~
        	return rc;                                             //~v6K3R~
            opdno-=minusctr;                                       //~v6K3I~
            opdno0-=minusctr;                                      //~v6K3I~
        }                                                          //~v6K3I~
        if (strchr(Sopcode,delm))                                  //~v167I~
            functype=delm;
		else                                                       //~v167I~
            return calcerrinvalid((char*)(void*)&delm);            //~v314R~
      if (Sopdvaluectr)                                            //~v6K3I~
      {                                                            //~v6K3I~
		if (rc=bc_setconvtype3(0,datatype,datatype2,parmconvtype,&convtype),rc)//~v6K3R~
    		return rc;                                             //~v6K3R~
      }                                                            //~v6K3I~
      else                                                         //~v6K3I~
      {                                                            //~v6K3I~
//set time conversion option
        convopt=0;
    	if (datatype=='T')
        {
			if (datatype2!='T')
	            convopt=CALC_OPD2SEC;      //+,- ope of time and second
		}
        else
    		if (datatype2=='T')
            	convopt=CALC_OPD1SEC;	//conv to seconds
            else
        		if (convtype=='T')		//output is time
	            	convopt=CALC_OPD1SEC|CALC_OPD2SEC;	//conv to seconds
        if (convtype=='T')		//output is time
        {
        	if (datatype!='T')
            	convopt|=CALC_CONV2HMS;
		}
        else
            if (convopt||datatype=='T')	//one or both operand is time
            	convopt|=CALC_CONV2SEC;
        convtype|=convopt;
      }//Sopdvaluectr==0                                           //~v6K3I~

      if (*(Pconstv2+1)!=UCALC_DWORDID)                            //~v50eI~
        if (*(Pconstv2+1))
        {                                                          //~v597R~
//      	if (strchr("*!/%<>&|^",functype))                      //~v50CR~
        	if (strchr("!<>&|^",functype))                         //~v50CI~
            	return calcuperr2();
//          else                                                   //~v5dtR~
//  			if (strchr("/%",functype))                         //~v5dtR~
//              {                                                  //~v5dtR~
//              	dwwk[0]=0;                                     //~v5dtR~
//              	dwwk[1]=(ULONG)*Pconstv2;                      //~v5dtR~
//      			ucalc_dwmult(dwwk,(ULONG)Spnumtbl[*(Pconstv2+1)]);//~v5dtR~
//oveflow supported if (dwwk[0])	//over flow                    //~v5dtR~
//                  	return calcerrinvalid(popd2);              //~v5dtR~
//              }                                                  //~v5dtR~
        }                                                          //~v597R~
      if (*(Pconstv1+1)!=UCALC_DWORDID)                            //~v50eR~
        if (*(Pconstv1+1))                                         //~v169I~
//      	if (strchr("!<>&|^",functype))                         //~v5duR~
        	if (strchr("<>&|^",functype))                          //~v5duI~
            	return calcuperr1();                               //~v169I~
    }//opdno
    *Pfunctype=functype;
    *Pconvtype=convtype;
	for (ii=0,ppot=ppot0,pdelmt=pdelmt0,pc=Poutcmdstr;ii<opdno0;ii++,pdelmt++)//~v573R~
    {                                                              //~v573I~
      if (*ppot!=UCALC_VARID)       //$n                           //~v5f9I~
      {                                                            //~v5f9I~
    	if (ii==0 && datatyped1)	//last opd                     //~v573R~
        {                                                          //~v6K3I~
          if (datatyped1!='z')                                     //~v6K3I~
        	*pc++=(UCHAR)datatyped1;                               //~v573I~
        }                                                          //~v6K3I~
        else                                                       //~v573I~
    	if (ii==1 && datatyped2)	//last opd                     //~v573R~
        {                                                          //~v6K3I~
          if (datatyped2!='z')                                     //~v6K3I~
        	*pc++=(UCHAR)datatyped2;                               //~v573I~
        }                                                          //~v6K3I~
        else                                                       //~v6K3I~
    	if (ii>1 && ii-2<Sopdvaluectr)                             //~v6K3R~
        {                                                          //~v6K3I~
		 	datatyped3=Sopdvalue[ii-2].datatyped;                  //~v6K3R~
		 	if (datatyped3 && datatyped3!='z')                     //~v6K3I~
        		*pc++=(UCHAR)datatyped3;                           //~v6K3R~
        }                                                          //~v6K3I~
      }                                                            //~v5f9I~
        len=(int)strlen(ppot);                                     //~v57uR~
      if (len)                                                     //~v57uI~
        memcpy(pc,ppot,(UINT)len);                                 //~v573I~
      else                                                         //~v57uI~
        pc--;   //override data type                               //~v57uI~
        pc+=len;                                                   //~v573I~
        if (ii==opdno-1 && opdno!=opdno0) //dropped convtype       //~v573R~
        	*pc++='/';                                             //~v573M~
        else                                                       //~v573I~
	        *pc++=(UCHAR)pdelmt->upodelm;                          //~v573R~
        ppot+=len+1;                                               //~v573I~
    }                                                              //~v573I~
    *pc=0;                                                         //~v5e6M~
    if (parmvnr)                                                   //~v5e6I~
    	pc+=sprintf(pc,"%s",parmvnr);                              //~v5e6R~
//  if (datatype=='D'||datatype2=='D')                             //~v5dtR~
//  	parmopt|=CALC_SIGNED;                                      //~v5dtR~
    if ((datatype=='X'||datatype=='O')     //x or o                //~v5dtI~
    &&   !(Pconstv1[1] & UCALC_DWORDID))   //not dword             //~v5dtI~
    	parmopt|=CALC_IGNOREOVF;           //ignore word overflow  //~v5dtI~
    *Ppparmopt=parmopt;                                            //~v5drR~
    if (Svprec!=-1||Svround)                                       //~v5e3I~
    {                                                              //~v5e3I~
	    if (Sopdvaluectr)                                          //~v6K3I~
			convtype=Sopdvalue[Sopdvaluectr-1].convtype;           //~v6K3R~
		convt=convtype & CALC_CONVTYPEMASK;                        //~v5e3R~
        if (convt!='D'                                             //~v5e3R~
        &&  convt!='U'                                             //~v5e3R~
        &&  convt!='Y'                                             //~v5e3R~
        &&  convt!='T'                                             //~v5e3R~
        &&  convt!='Z')                                            //~v5e3R~
        {                                                          //~v5e3I~
            uerrmsg("Vnn or R(ound) option is invalid for this output data type:%c",0,//~v5e3R~
					convtype);                                     //~v5e3I~
    		return CALC_RCERRMSG;                                  //~v5e3I~
        }                                                          //~v5e3I~
    }                                                              //~v5e3I~
    return 0;
}//bc_opdchk
//**************************************************************** //~v5f9I~
// get $n varname                                                  //~v5f9I~
//*rc   :4 err                                                     //~v5f9I~
//**************************************************************** //~v5f9I~
int getvarname(char *Pcmdstr,int *Ppvarno,char **Ppnextpos)        //~v5f9R~
{                                                                  //~v5f9I~
	char *pc;                                                      //~v5f9I~
    int numlen,varno;                                              //~v5f9I~
//*******************                                              //~v5f9I~
	pc=Pcmdstr;                                                    //~v5f9I~
    numlen=unumlen(pc,0,(int)strlen(pc));                          //~v5f9I~
    varno=atoi(pc);                                                //~v5f9I~
    if (varno<0||varno>UCALC_MAXRESULTNO)                          //~v5f9I~
    {                                                              //~v5f9I~
        uerrmsg("$n : n=0-9",0);                                   //~v5f9I~
    	return 4;                                                  //~v5f9I~
    }                                                              //~v5f9I~
    *Ppvarno=varno;                                                //~v5f9I~
    pc+=numlen;                                                    //~v5f9I~
    pc+=strspn(pc," \t");                                          //~v5f9I~
    if (Ppnextpos)	//output requested                             //~v5f9I~
	    *Ppnextpos=pc;                                             //~v5f9R~
    return 0;                                                      //~v5f9I~
}//getvarname                                                      //~v5f9I~
//**************************************************************** //~v5e3I~
// chk vnnr parm                                                   //~v5e3I~
//   chk /[outtype]VnnR,/[outtype]R option                         //~v5e3I~
//input parm1:string after "/"                                     //~v5e3I~
//*rc   :4 err                                                     //~v5e3I~
//**************************************************************** //~v5e3I~
int ucalc_chkvrparm(char *Pconvtype,int *Pvprec,int *Pvround,char **Ppvrpos)//~v5e3R~
{                                                                  //~v5e3I~
	char *rpos,*vpos,*vrpos,*pc;                                   //~v5e3R~
    int numlen;                                                    //~v5e3I~
//*******************                                              //~v5e3I~
    vpos=strpbrk(Pconvtype,"Vv");                                  //~v5e3I~
    if (vpos)   //                                                 //~v5e3I~
    {                                                              //~v5e3I~
    	pc=vpos+1;                                                 //~v5e3I~
    	numlen=unumlen(pc,0,(int)strlen(pc));                      //~v5e3I~
    	*Pvprec=atoi(pc);                                          //~v5e3R~
        if (*Pvprec>MAX_POINT_NUM)                                 //~v5e3I~
            return 8;       //err                                  //~v5e3I~
        vrpos=vpos;                                                //~v5e3I~
        rpos=pc+numlen;                                            //~v5e3I~
        if (*rpos!=0&&*rpos!='R'&&*rpos!='r')                      //~v5e3I~
            return 8;       //err                                  //~v5e3I~
    }                                                              //~v5e3I~
    else                                                           //~v5e3I~
    {                                                              //~v5e3I~
    	*Pvprec=-1;                                                //~v5e3I~
        vrpos=0;                                                   //~v5e3I~
        rpos=Pconvtype;                                            //~v5e3I~
    }                                                              //~v5e3I~
    rpos=strpbrk(rpos,"Rr");   //round option exist                //~v5e3I~
    if (rpos)   //round option exist                               //~v5e3I~
    {                                                              //~v5e3I~
    	*Pvround=UCVRA_ROUNDUP;                                    //~v5e3R~
        if (!vpos)                                                 //~v5e3R~
        	vrpos=rpos;                                            //~v5e3I~
        if (*Pvprec>=MAX_POINT_NUM)                                //~v5e3I~
            return 8;       //err                                  //~v5e3I~
    }                                                              //~v5e3I~
    else                                                           //~v5e3I~
    	*Pvround=0;                                                //~v5e3I~
    if (Ppvrpos)                                                   //~v5e3I~
	    *Ppvrpos=vrpos;                                            //~v5e3R~
    return 0;                                                      //~v5e3I~
}//ucalc_chkvrparm                                                 //~v5e3I~
//****************************************************************
// get const value
//   accept preceding "-" as sign                                  //~v5drI~
//*rc   :4 err
//****************************************************************
//int bc_getvalue(char *Popd,long *Pvalue,int *Pdatatype,int *Pdatatyped)//~v5drR~
int bc_getvalue(int Popt,char *Popd,long *Pvalue,int *Pdatatype,int *Pdatatyped)//~v5drI~
{
	int  len,datatype,err=0;                                       //~v50rR~
    int  rc;                                                       //~v50mR~
    char *popd;                                                    //~v50rR~
    int datatyped=0;                                               //~v573I~
	int getldopt;                                                  //~v5drI~
    int rct;                                                       //~v5e5I~
    int varno;                                                     //~v5f9I~
//*********************************
	Svarno12=-1;	//init by no $n                                //~v5f9R~
    if (*Popd==UCALC_VARID) //$n                                   //~v5f9I~
    {                                                              //~v5f9I~
        if (getvarname(Popd+1,&varno,0))                           //~v5f9R~
            return 4;                                              //~v5f9I~
        popd=Gucalc_result[varno];                                 //~v5f9R~
        if (!*popd)	//not saved                                    //~v5f9I~
        {                                                          //~v5f9I~
        	uerrmsg("$%d is not saved",0,                          //~v5f9I~
            			varno);                                    //~v5f9I~
            return 4;                                              //~v5f9I~
        }                                                          //~v5f9I~
		rc=bc_getvalue(Popt,popd,Pvalue,Pdatatype,Pdatatyped);     //~v5f9I~
        Svarno12=varno;  //output                                  //~v5f9R~
        return rc;                                                 //~v5f9I~
    }                                                              //~v5f9I~
	if (Popt & CALC_DWORDUP)                                       //~v5drR~
		getldopt=GETLD_DWUP;                                       //~v5drI~
    else                                                           //~v5drI~
		getldopt=0;                                                //~v5drI~
	Pvalue[1]=0;		//id of no under point
	len=(int)strlen(Popd);
    popd=Popd;
    if (*popd=='0' && (*(popd+1)=='x'||*(popd+1)=='X'))            //~v50pI~
    	len--,popd++;                                              //~v50pI~
    datatype=*Pdatatype;
//  switch(toupper(*Popd))                                         //~v50pR~
    switch(toupper(*popd))                                         //~v50pI~
    {
    case 'X':
    	popd++;
        if (!*popd)                                                //~v50sI~
        {                                                          //~v50sI~
            err=1;                                                 //~v50sI~
            break;                                                 //~v50sI~
        }                                                          //~v50sI~
		if (bc_getxdw(popd,Pvalue)==1)	//valid dword hex data     //~v50gR~
        {                                                          //~v50eI~
        	datatype='X';                                          //~v50eI~
        	break;                                                 //~v50eI~
        }                                                          //~v50eI~
//      if (unumlen(popd,UNUMLEN_HEX,len-1)!=len-1)   //all numeric//~v50eR~
        len--;                                                     //~v50eI~
        if (len>8 && unumlen(popd,UNUMLEN_HEX,len)==len)   //valid but too long as 4byte value//~v6xgI~
        	err=2;                                                 //~v6xgI~
        else                                                       //~v6xgI~
        if (len>8||unumlen(popd,UNUMLEN_HEX,len)!=len)   //all numeric//~v50eI~
        	err=1;
        else
        {
        	datatype='X';
            ux2l(popd,(ULONG*)(void*)Pvalue);
        }
        break;
    case 'O':
    	popd++;
        if (!*popd)                                                //~v50sI~
        {                                                          //~v50sI~
            err=1;                                                 //~v50sI~
            break;                                                 //~v50sI~
        }                                                          //~v50sI~
        if (ucalc_o2l(popd,Pvalue,0))                              //~v314R~
        	err=1;
        else
	        datatype='O';
        break;
    case 'T':
    	popd++;
        if (ucalc_gettimevalue(popd,0,Pvalue)>1)   //by strlen     //~v314R~
          	err=1;
        else
			datatype='T';
        break;
    case 'Z':                                                      //~v50mI~
    	popd++;                                                    //~v50mI~
        len--;                                                     //~v50mI~
//  	if ((rc=bc_getld(popd,Pvalue))==1)	//valid long decimal data//~v5djR~
//  	if ((rc=bc_getld(Sdwupsw,popd,Pvalue))==1)	//valid long decimal data//~v5drR~
    	if ((rc=bc_getld(getldopt,popd,Pvalue))==1)	//valid long decimal data//~v5drI~
        {                                                          //~v50mI~
//          datatype='U';                                          //~v5djR~
            datatype='D';                                          //~v5djI~
        	break;                                                 //~v50mI~
        }                                                          //~v50mI~
        if (rc)                                                    //~v50rR~
        {                                                          //~v5drI~
          if (rc!=CALC_RCERRMSG)                                   //~v5drI~
        	err=1;                                                 //~v50rI~
          else                                                     //~v5dvI~
            return 4;                                              //~v5dvI~
        }                                                          //~v5drI~
        else                                                       //~v50rI~
          	datatype='D';                                          //~v50mI~
        break;                                                     //~v50mI~
    case MINUSSIGN:                                                //~v5drM~
        datatype='D';                                              //~v5drI~
//  	if ((rc=bc_getld(Sdwupsw,popd,Pvalue))==1)	//valid long decimal data//~v5drR~
    	if ((rc=bc_getld(getldopt,popd,Pvalue))==1)	//valid long decimal data//~v5drI~
        	break;                                                 //~v5drI~
        if (rc)                                                    //~v5drI~
        {                                                          //~v5drI~
            if (*(popd+1)=='t'||*(popd+1)=='T')                    //~v5e5R~
          		rct=ucalc_gettimevalue(popd+2,0,Pvalue);  //by strlen//~v5e5I~
            else                                                   //~v5e5I~
          		rct=ucalc_gettimevalue(popd+1,0,Pvalue);  //by strlen//~v5e5R~
            if (rct<=1)                                            //~v5e5I~
          	{                                                      //~v5e5R~
              	datatyped='t';  //default display datatype         //~v5e5R~
              	datatype='T';                                      //~v5e5R~
                Pvalue[0]|=(LONG)CALC_TIME_MINUS;                  //~v5fjR~
        	  	break;                                             //~v5e5R~
          	}                                                      //~v5e5R~
          if (rc!=CALC_RCERRMSG)                                   //~v5drI~
        	err=1;                                                 //~v5drI~
          else                                                     //~v5dvI~
            return 4;                                              //~v5dvI~
        }                                                          //~v5drI~
        break;                                                     //~v5drI~
    default:        //chk num
//  	if ((rc=bc_getld(popd,Pvalue))==1)	//valid long decimal data//~v5djR~
//  	if ((rc=bc_getld(Sdwupsw,popd,Pvalue))==1)	//valid long decimal data//~v5drR~
    	if ((rc=bc_getld(getldopt,popd,Pvalue))==1)	//valid long decimal data//~v5drI~
        {                                                          //~v50gI~
//        if (Pvalue[1]>UCALC_DWORDID)  //dword underpoint         //~v5drR~
            datatype='D';                                          //~v5djI~
//        else                                                     //~v5drR~
//          datatype='U';                                          //~v5drR~
            datatyped='z';	//default display datatype             //~v573I~
        	break;                                                 //~v50gI~
        }                                                          //~v50gI~
      if (rc)                                                      //~v5drI~
      {                                                            //~v5drI~
        if (rc==CALC_RCERRMSG)                                     //~v5drI~
            return 4;                                              //~v5drI~
		if (bc_getxdw(popd,Pvalue)==1)	//valid dword hex data     //~v50gR~
        {                                                          //~v50eI~
            datatype='X';                                          //~v50eI~
            datatyped='x';	//default display datatype             //~v573I~
        	break;                                                 //~v50eI~
        }                                                          //~v50eI~
      }                                                            //~v5drI~
//        pc=strchr(popd,'.');                                     //~v50mR~
//        decsw=0;                                                 //~v50mR~
//        if (pc)                                                  //~v50mR~
//        {                                                        //~v50mR~
//            len2=(int)((ULONG)pc-(ULONG)popd);     //before point//~v50mR~
//            len3=len-len2-1;                                     //~v50mR~
//            if (len2 && unumlen(popd,UNUMLEN_DEC,len2)==len2     //~v50mR~
//            &&  len3 && unumlen(pc+1,UNUMLEN_DEC,len3)==len3)    //~v50mR~
//                decsw=2;                                         //~v50mR~
//        }                                                        //~v50mR~
//        else                                                     //~v50mR~
//            if (unumlen(popd,UNUMLEN_DEC,len)==len)              //~v50mR~
//                decsw=1;                                         //~v50mR~
//        if (decsw)                                               //~v50mR~
//        {                                                        //~v50mR~
//            datatype='D';                                        //~v50mR~
//            Pvalue[0]=atol(popd);                                //~v50mR~
//            if (decsw==2)                                        //~v50mR~
//                if (ucalc_getunderpointdata(0,pc+1,len3,Pvalue)) //~v50mR~
//                    err=1;                                       //~v50mR~
//        }                                                        //~v50mR~
//        else                                                     //~v50mR~
	  	if (!rc)                                                   //~v50rR~
        {                                                          //~v573I~
			datatype='D';                                          //~v50rR~
            datatyped='z';	//default display datatype             //~v573I~
        }                                                          //~v573I~
      	else                                                       //~v50rI~
        if (len<=8 && unumlen(popd,UNUMLEN_HEX,len)==len)   //all hex//~v50eR~
        {
            datatype='X';
            datatyped='x';	//default display datatype             //~v573I~
            ux2l(popd,(ULONG*)(void*)Pvalue);
        }
        else
        if (ucalc_gettimevalue(popd,0,Pvalue)>1)   //by strlen     //~v314R~
            err=1;
        else
        {                                                          //~v573I~
            datatyped='t';	//default display datatype             //~v573I~
            datatype='T';
        }                                                          //~v573I~
    }//top byte
    if (err==2)	//long xvalue                                      //~v6xgI~
    	return calcerrinvalid_dw(Popd);                            //~v6xgI~
    if (err)
    	return calcerrinvalid(Popd);                               //~v6xgR~
    *Pdatatype=datatype;
    *Pdatatyped=datatyped;                                         //~v573I~
    return 0;
}//bc_getvalue
//**************************************************               //~v5e3I~
//*conv opt strz to bin                                            //~v5e3I~
//*     if strz(len=0) all char must be valid,else stop at it      //~v5e3I~
//ret rc:1:value ajusted                                           //~v5e3I~
//**************************************************               //~v5e3I~
int ucalc_vrajust(int Popt,LONG *Pval,int Pvprec)                  //~v5e3R~
{                                                                  //~v5e3I~
    LONG upid,updata,newupid,ovfsw[4]={0,0,0,0},hhmmss;            //~v5e3R~
    int roundsw;                                                   //~v5e3R~
//****************************************                         //~v5e3I~
    if (Pvprec<0)	//no Vnn                                       //~v5e3R~
        Pvprec=0;                                                  //~v5e3R~
    if (Pvprec>MAX_POINT_NUM)                                      //~v5e3I~
    	Pvprec=MAX_POINT_NUM;                                      //~v5e3I~
	upid=Pval[1];                                                  //~v5e3I~
    roundsw=(Popt & UCVRA_ROUNDUP)!=0;     //roundup               //~v5e3I~
  	if (upid>=UCALC_DWORDID)                                       //~v5e3I~
    {                                                              //~v5e3I~
    	newupid=Pvprec+UCALC_DWORDID;                              //~v5e3I~
    	upid&=~UCALC_DWORDID;                                      //~v5e3I~
        updata=Pval[3];                                            //~v5e3I~
        hhmmss=Pval[2];                                            //~v5e3I~
    }                                                              //~v5e3I~
    else                                                           //~v5e3I~
    {                                                              //~v5e3I~
    	newupid=Pvprec;                                            //~v5e3I~
        updata=Pval[2];                                            //~v5e3I~
        hhmmss=Pval[0];                                            //~v5e3I~
    }                                                              //~v5e3I~
    if (!upid)                                                     //~v5eaR~
    	updata=0;                                                  //~v5eaI~
    if (upid<=Pvprec)                                              //~v5e3R~
    	updata*=Spnumtbl[Pvprec-upid];   //precision up            //~v5e3I~
    else                                                           //~v5e3I~
    {                                                              //~v5e3I~
        if (!(Popt&UCVRA_PRECDOWN))    //do also precision down    //~v5e3R~
        	return 0;	//nothing to do                            //~v5e3I~
        updata/=Spnumtbl[upid-Pvprec-roundsw];   //cut             //~v5e3R~
        if (roundsw)     //roundup                                 //~v5e3R~
        {                                                          //~v5e3R~
        	if (updata<0)                                          //~v5e3I~
            {                                                      //~v5e3I~
	            updata-=5;                                         //~v5e3I~
	            updata/=10;                                        //~v5e3I~
	            if (-updata>=Spnumtbl[Pvprec])                     //~v5e3I~
    	        {                                                  //~v5e3I~
        	    	updata+=Spnumtbl[Pvprec];                      //~v5e3I~
            	    ovfsw[0]=-1;                                   //~v5e3I~
            	}                                                  //~v5e3I~
            }                                                      //~v5e3I~
            else                                                   //~v5e3I~
            {                                                      //~v5e3I~
	            updata+=5;                                         //~v5e3R~
      		    updata/=10;                                        //~v5e3R~
            	if (updata>=Spnumtbl[Pvprec])                      //~v5e3R~
            	{                                                  //~v5e3R~
            		updata-=Spnumtbl[Pvprec];                      //~v5e3R~
                	updata=-updata;                                //~v5e3M~
    				if (Popt&UCVRA_TIME //do also precision down   //~v5e3I~
//          		&&  hhmmss & CALC_TIME_MINUS)//up data is plus for time data//~v6xiR~
            		&&  (UINT4)hhmmss & CALC_TIME_MINUS)//up data is plus for time data//~v6xiI~
	                	ovfsw[0]=-1;                               //~v5e3I~
                    else                                           //~v5e3I~
	                	ovfsw[0]=1;                                //~v5e3R~
            	}                                                  //~v5e3R~
            }                                                      //~v5e3I~
        }//roundup                                                 //~v5e3R~
    }                                                              //~v5e3I~
    Pval[1]=newupid;                                               //~v5e3I~
    if (newupid>=UCALC_DWORDID)                                    //~v5e3I~
        Pval[3]=updata;                                            //~v5e3I~
    else                                                           //~v5e3I~
        Pval[2]=updata;                                            //~v5e3I~
//  if (ovfsw)                                                     //~v5eaR~
    if (ovfsw[0])                                                  //~v5eaI~
    {                                                              //~v5e3I~
    	if (Popt&UCVRA_TIME) //do also precision down              //~v5e3I~
        	ucalc_time(CALC_TIME_2SEC,'+',Pval,ovfsw);//2nd opd is seconds//~v5e3R~
    	else                                                       //~v5e3I~
        	ucalc_binop(0,'+',Pval,ovfsw);                         //~v5e3R~
    }                                                              //~v5e3I~
    return 1;                                                      //~v5e3I~
}//ucalc_vrarange                                                  //~v5e3I~
//**************************************************
//*conv opt strz to bin
//*     if strz(len=0) all char must be valid,else stop at it
//ret rc
//**************************************************
int ucalc_o2l(char *Pdata,long *Pldata,int Plen)                   //~v314R~
{
	char *pc,*pce;
    int ch,len;
//****************************************
	len=Plen;
    if (!len)
    	len=(int)strlen(Pdata);
	for(pc=Pdata,pce=pc+len;pc<pce;pc++,len--)
    {
    	ch=*pc;
    	if (ch>='0'&&ch<='7')
        	continue;
		if (!Plen)
        	return 4;
		break;
	}
	sscanf(Pdata,"%lo",Pldata);
    return 0;
}//ucalc_o2l                                                       //~v314R~
//**************************************************
//*conv opt strz to bin   hh:mm:ss.xxx or hhmmss.xxx fmt
//parm 2:data len;0 if strz(all under point should be numeric)
//                or max len(under point stop at non numeric)
//parm 3:00hhmmss(not packed fmt)
//parm 4:under second, xxyyyyyyy xx:digit no
//rc:4:err  0: hh:mm:ss.xxx fmt  1: hhmmss.xxx fmt
//**************************************************
int ucalc_gettimevalue(char *Pdata,int Plen,long *Pvalue)          //~v314R~
{                                                             
	char *pc,*pce;
//  int ch,len,ii,ss,mm=0,hh=0,num,len6sw;                         //~v328R~//~v6h6R~
    int ch,len,ii,ss=0,mm=0,hh=0,num,len6sw;                       //~v6h6I~
    int numok;                                                     //~v50nI~
    long sign;
//****************************************
	if (!(len=Plen))
    	len=(int)strlen(Pdata);
    len6sw=0;			//hhmmss.xxx fmt
    if (*Pdata=='-')
    {
        sign=(long)CALC_TIME_MINUS;
        Pdata++;
        len--;
	}
    else
        sign=0;
    if (len==6 || (len>6 && *(Pdata+6)=='.'))
        len6sw=1;	
    else
    if (!len6sw && len<8)
    	return 4;
    pc=Pdata;
	pce=pc+len;
//  ss=-1;		//to chk err                                       //~v50nR~
    numok=0;	//to chk err                                       //~v50nI~
    for (ii=0;pc<pce && ii<8;pc++,ii++)
    {
        ch=*pc;
        if (ii==2||ii==5)
        {                                                          //~v597R~
        	if (len6sw)
                pc--;   //assume 2nd and 5th byte
            else
            	if (ch=='.'||ch==':')
					continue;
                else
					break;		//err
        }                                                          //~v597R~
        if (ch>='0'&&ch<='9')
            num=ch-'0';
        else
        if (ch==' ')
			if (ii==0||ii==3||ii==6)
            	num=0;
            else
            	break;
        else
            break;

        if (ii==0)
            hh=num*10;
        else if (ii==1)
        		hh+=num;
        else if (ii==3)
            	mm=num*10;
        else if (ii==4)
                mm+=num;
        else if (ii==6)
                ss=num*10;
        else if (ii==7)
             {                                                     //~v50nI~
                numok=1;                                           //~v50nI~
                ss+=num;
             }                                                     //~v50nI~
    }//loop
//  if (ss<0)                                                      //~v50nR~
    if (!numok)                                                    //~v50nI~
        return 4;
//  if (hh>=24||mm>=60||ss>=60)
    if (mm>=60||ss>=60)
        return 4;
//under point
	if (pc<pce-1)
        if (*pc=='.')   //under point
        {
            pc++;
            if (Plen)
//              len=(int)((ULONG)pc-(ULONG)Pdata);  //rc=0 eve if stopped at non numeric//~v50BR~
//              len=(int)((ULONG)pce-(ULONG)pc);                   //~v50BI~//~v6hhR~
                len=(int)((ULPTR)pce-(ULPTR)pc);                   //~v6hhI~
            else
                len=0;  //all should be numeric
            if (ucalc_getunderpointdata(0,pc,len,Pvalue))          //~v314R~
                return 4;
        }
        else            //no dot
            if (*pc==' ')	//strz
		    	Pvalue[1]=0;		//no under point
            else
                return 4;
    else
    	Pvalue[1]=0;		//no under point
//  Pvalue[0]=(long)(sign|((ULONG)hh<<16)|(mm<<8)|ss);             //~v6xhR~
//  Pvalue[0]=(INT4)(sign|((UINT4)hh<<16)|(mm<<8)|ss);             //~v6xiR~
    Pvalue[0]=(INT4)((UINT4)sign|((UINT4)hh<<16)|((UINT4)mm<<8)|(UINT4)ss);//~v6xiR~
    return len6sw;
}//ucalc_gettimevalue                                              //~v314R~
//**************************************************
//*get under point value
//*  output for minus set minus value
//*  parm1:signed datatype or minus specified
//*  parm2:digit data addr
//*  parm3:max data len
//*  parm4:outut [0]=overpoint value,[1]=digit len,[2]=signed value
//rc:4:err
//**************************************************
int ucalc_getunderpointdata(int Popt,char *Pdata,int Plen,long *Pvalue)//~v314R~
{                                                             
	char *pc;
    int  ch,len,ii;
    long upv=0;
//****************************************
	if (!(len=Plen))
    	len=(int)strlen(Pdata);
    if (!len)
    	return 4;
    pc=Pdata;
    for (ii=0;ii<len;pc++,ii++)
    {
        ch=*pc;
        if (!ch || ch==' ')
            break;
        if (ch<'0'||ch>'9')
            return 4;
        upv=upv*10+ch-'0';
    }
    if (ii>MAX_POINT_NUM)
        return 4;

	if (Popt & CALC_UPMINUS)		//minus specified
//  	if (Popt & CALC_UPSIGNED)		//minus specified
	        upv=-upv;       //-y.-xxx
//      else
//      {
//      	upv=Spnumtbl[ii]-upv;
//          Pvalue[0]--;			//-y+0.xxx  fmt
//      }
    Pvalue[1]=(long)ii;
    Pvalue[2]=upv;
    return 0;
}//ucalc_getunderpointdata                                         //~v314R~
//***************************************************************  //~v5dtR~
//*copy 3word opd to 4word opd,optionaly change minus to plus      //~v5dtR~
//ret:-1 if minus                                                  //~v5dsI~
//***************************************************************  //~v5dtR~
int bc_opdcopy(int Popt,LONG *Pout,LONG *Pinp)                     //~v5dtR~
{                                                                  //~v5dsI~
//********************************                                 //~v5dsI~
	if (Pinp[1] & UCALC_DWORDID)                                   //~v5dtR~
    {                                                              //~v5dtI~
    	if (IF_DWORD_ISMINUS(Pinp))                                //~v5dtR~
	    {                                                          //~v5dtR~
			if (Popt & OPDCOPY_PLUS)                               //~v5dtI~
    		{                                                      //~v5dtI~
	            SET_DWORD_MINUS(Pout,Pinp);                        //~v5dsR~
	            return -1;                                         //~v5dtI~
	        }                                                      //~v5dsI~
        }                                                          //~v5dtI~
	    else	//opd is plus                                      //~v5dtR~
        {                                                          //~v5dtI~
			if (Popt & OPDCOPY_MINUS)                              //~v5dtI~
    		{                                                      //~v5dtI~
	            SET_DWORD_MINUS(Pout,Pinp);                        //~v5dtI~
	            return 1;                                          //~v5dtI~
            }                                                      //~v5dtI~
        }//plus                                                    //~v5dtI~
        memcpy(Pout,Pinp,CALC_LONGNUMFMTSZ);                       //~v5dtI~
    }                                                              //~v5dtI~
    else //not dword                                               //~v5dtI~
    {                                                              //~v5dtI~
    	if (IF_WORD_ISMINUS(Pinp))                                 //~v5dtR~
	    {                                                          //~v5dtR~
			if (Popt & OPDCOPY_PLUS)                               //~v5dtI~
    		{                                                      //~v5dtI~
	           SET_WORD_MINUS(Pout,Pinp);                          //~v5dtR~
	            return -1;                                         //~v5dtI~
            }                                                      //~v5dtI~
	    }                                                          //~v5dtR~
        else	//plus                                             //~v5dtI~
        {                                                          //~v5dtI~
			if (Popt & OPDCOPY_MINUS)                              //~v5dtI~
    		{                                                      //~v5dtI~
	           SET_WORD_MINUS(Pout,Pinp);                          //~v5dtI~
	            return 1;                                          //~v5dtI~
            }                                                      //~v5dtI~
        }                                                          //~v5dtI~
        memcpy(Pout,Pinp,CALC_SHORTNUMFMTSZ);                      //~v5dtI~
    }//not dword                                                   //~v5dtI~
    return 0;                                                      //~v5dtR~
}//bc_opdcopy                                                      //~v5dtR~
//**************************************************               //~v5dsI~
//*word overflow chk and change fmt to dword fmt if requested      //~v5dsI~
//**************************************************               //~v5dsI~
int bc_putwordordword(int Popt,LONG *Pout,LONG *Pnumfmt)           //~v5dsI~
{                                                                  //~v5dsI~
//********************************                                 //~v5dsI~
    if (Pnumfmt[1]&UCALC_DWORDID)                                  //~v5dsR~
      if (Popt & CALC_IGNOREOVF)                                   //~v5dtI~
      {                                                            //~v5dtI~
      	Pout[0]=Pnumfmt[2];                                        //~v5dtI~
      	Pout[1]=Pnumfmt[1]&~UCALC_DWORDID;                         //~v5dtI~
      	Pout[2]=Pnumfmt[3];                                        //~v5dtI~
      }                                                            //~v5dtI~
      else                                                         //~v5dtI~
    	if (Popt & CALC_DWORDUP)                                   //~v5dsI~
	        memcpy(Pout,Pnumfmt,CALC_LONGNUMFMTSZ);                //~v5dsR~
        else                                                       //~v5dsI~
			return calcerrwordovf(Popt);                           //~v5dsR~
    else                                                           //~v5dsI~
		memcpy(Pout,Pnumfmt,CALC_SHORTNUMFMTSZ);                   //~v5dsR~
    return 0;                                                      //~v5dsI~
}//bc_putwordordword                                               //~v5dsI~
//**************************************************               //~v5dtI~
//*change to dword fmt if overflow                                 //~v5dtI~
//**************************************************               //~v5dtI~
int bc_expand2dword(LONG Povf,LONG *Pwordfmt)                      //~v5dtI~
{                                                                  //~v5dtI~
//********************************                                 //~v5dtI~
    if (!Povf)                                                     //~v5dtI~
//    if (!(Pwordfmt[0] & ULMINUSBIT))	//top bit is not minus sign//~v6xiR~
      if (!((UINT4)Pwordfmt[0] & ULMINUSBIT))	//top bit is not minus sign//~v6xiI~
    	return 0;                                                  //~v5dtI~
    Pwordfmt[3]=Pwordfmt[2];    //underpoint                       //~v5dtI~
    Pwordfmt[2]=Pwordfmt[0];    //dword low half                   //~v5dtI~
    Pwordfmt[0]=Povf;           //dword high                       //~v5dtI~
    Pwordfmt[1]|=UCALC_DWORDID;//dword id                          //~v5dtR~
    return 1;                                                      //~v5dtI~
}//bc_expand2dword                                                 //~v5dtI~
//**************************************************               //~v5dsI~
//*wrapper of ucalc_binop                                          //~v5dsI~
//* prepare 4 word operand                                         //~v5dsI~
//* minus handling                                                 //~v5dsI~
//**************************************************               //~v5dsI~
int ucalc_binop(int Popt,int Pope,long *Popd1,long *Popd2)         //~v5dsI~
{                                                                  //~v5dsI~
    LONG wopd1[4],wopd2[4];                                        //~v5dsI~
    LONG wk0[4];                                                   //~v5e9I~
    int opd1sign,opd2sign,rc,copyopt;                              //~v5dtR~
    int dwsw=0;                                                    //~v5dvI~
//****************************************                         //~v5dsI~
    if (!Popd1)     //for convenience ?(compare) with 0,0 meen long 0//~v5e9R~
    {                                                              //~v5e9I~
        memset(wk0,0,sizeof(wk0));                                 //~v5e9I~
        Popd1=wk0;                                                 //~v5e9I~
    }                                                              //~v5e9I~
//  if (*(Popd1+1)>=UCALC_DWORDID || *(Popd2+1)>=UCALC_DWORDID)		//1st opd dwid//~v5dvR~
//  	return bc_dwbinop(Popt,Pope,Popd1,Popd2);                  //~v5dvR~
    if (*(Popd1+1)>=UCALC_DWORDID)      //1st opd is dword         //~v5dvI~
    {                                                              //~v5dvI~
    	Popt|=CALC_DWORDUP;				//to copy for bc_putwordordword//~v5dvI~
    	dwsw|=1;                                                   //~v5dvI~
    }                                                              //~v5dvI~
	if (*(Popd2+1)>=UCALC_DWORDID)		//2nd opd is dword         //~v5dvI~
    	dwsw|=2;                                                   //~v5dvI~
//  signedsw=Popt&CALC_SIGNED;                                     //~v5dtR~
    switch(Pope)                                                   //~v5dsI~
    {                                                              //~v5dsI~
    case '+':                                                      //~v5dsI~
    case '-':                                                      //~v5dsI~
    case '?':                                                      //~v5dsI~
	    bc_opdcopy(OPDCOPY_COPY,wopd1,Popd1);   //no sign chng,copy//~v5dtR~
	    bc_opdcopy(OPDCOPY_COPY,wopd2,Popd2);                      //~v5dtR~
      if (dwsw)                                                    //~v5dvI~
		rc=bc_dwbinop(Popt,Pope,wopd1,wopd2);                      //~v5dvI~
      else                                                         //~v5dvI~
		rc=ucalc_binopsub(Popt,Pope,wopd1,wopd2);//4word op        //~v5dtR~
        if (rc)                                                    //~v5dsI~
        	break;                                                 //~v5dsI~
		rc=bc_putwordordword(Popt,Popd1,wopd1);//output to parm opd1//~v5dsI~
        break;                                                     //~v5dsI~
    case '*':                                                      //~v5dsI~
    case '/':                                                      //~v5dsI~
    case '%':                                                      //~v5dsI~
    	copyopt=OPDCOPY_PLUS;                                      //~v5dtR~
	    opd1sign=bc_opdcopy(copyopt,wopd1,Popd1);   //reverse if minus//~v5dtR~
	    opd2sign=bc_opdcopy(copyopt,wopd2,Popd2);   //             //~v5dtR~
      if (dwsw)                                                    //~v5dvI~
		rc=bc_dwbinop(Popt,Pope,wopd1,wopd2);                      //~v5dvI~
      else                                                         //~v5dvI~
		rc=ucalc_binopsub(Popt,Pope,wopd1,wopd2);//4word op        //~v5dtR~
        if (rc)                                                    //~v5dsI~
        	break;                                                 //~v5dsI~
		rc=bc_putwordordword(Popt,Popd1,wopd1);//output to parm opd1//~v5dsI~
        if (rc)                                                    //~v5dtI~
        	break;                                                 //~v5dtI~
    	if (Pope=='%')   //like as C-function:-8%3==>2, -8%3==>-2, 8%-3==>+2, -8%-3==>-2//~v5dtI~
        {                                                          //~v5dtI~
        	if (opd1sign<0)	//opd1 sign is  minus                  //~v5dtI~
				bc_opdcopy(OPDCOPY_MINUS,Popd1,Popd1);             //~v5dtI~
        }                                                          //~v5dtI~
        else                                                       //~v5dtI~
        {                                                          //~v5dtI~
        	if (opd1sign!=opd2sign)	//result is minus              //~v5dtR~
				bc_opdcopy(OPDCOPY_MINUS,Popd1,Popd1);             //~v5dtR~
        }                                                          //~v5dtI~
        break;                                                     //~v5dsI~
    case '!': 			//power                                    //~v5dsI~
    	copyopt=OPDCOPY_PLUS;                                      //~v5dtI~
	    opd1sign=bc_opdcopy(copyopt,wopd1,Popd1);   //reverse if minus//~v5dtR~
	    opd2sign=bc_opdcopy(copyopt,wopd2,Popd2);   //             //~v5dtR~
      if (dwsw)                                                    //~v5dvI~
		rc=bc_dwbinop(Popt,Pope,wopd1,wopd2);                      //~v5dvI~
      else                                                         //~v5dvI~
		rc=ucalc_binopsub(Popt,Pope,wopd1,wopd2);//4word op        //~v5dtR~
        if (rc)                                                    //~v5dsI~
        	break;                                                 //~v5dsI~
        if (opd2sign<0)                                            //~v5dsI~
        {                                                          //~v5dsI~
        	memcpy(wopd2,wopd1,sizeof(wopd1));                     //~v5dsI~
//          wopd1[0]=1;wopd1[1]=0;	//word 1                       //~v5duR~
            wopd1[0]=1;                                            //~v5duI~
            wopd1[1]=MAX_POINT_NUM;                                //~v5duI~
            wopd1[2]=0;                                            //~v5duI~
			rc=ucalc_binopsub(Popt,'/',wopd1,wopd2);//4word op     //~v5dtR~
    	    if (rc)                                                //~v5dsI~
        		break;                                             //~v5dsI~
        }                                                          //~v5dsI~
		rc=bc_putwordordword(Popt,Popd1,wopd1);//output to parm opd1//~v5dsI~
        if (rc)                                                    //~v5dtI~
        	break;                                                 //~v5dtI~
        if (opd1sign<0 && (wopd2[0] & 1))                          //~v5dtI~
			bc_opdcopy(OPDCOPY_MINUS,Popd1,Popd1);                 //~v5dtR~
        break;                                                     //~v5dsI~
    case '<':                                                      //~v5dsI~
    case '>':                                                      //~v5dsI~
    case '|':                                                      //~v5dsI~
    case '&':                                                      //~v5dsI~
    case '^':                                                      //~v5dsI~
	    if (bc_opdcopy(OPDCOPY_PLUS,wopd2,Popd2)<0)	//opd2 minus   //~v5dtR~
			rc=calcerrminus();                                     //~v5dsI~
        else                                                       //~v5dsI~
          if (dwsw)                                                //~v5dvI~
		    rc=bc_dwbinop(Popt,Pope,Popd1,Popd2);                  //~v5dvI~
          else                                                     //~v5dvI~
			rc=ucalc_binopsub(Popt,Pope,Popd1,Popd2);//4word op    //~v5dsI~
        break;                                                     //~v5dsI~
    default:                                                       //~v5dsI~
        return 4;                                                  //~v5dsI~
    }                                                              //~v5dsI~
    return rc;                                                     //~v5dsI~
}//ucalc_binop                                                     //~v5dsI~
//**************************************************
//*doble long calc  +,-,*,/,%,?,<,>
//* for *,/,%  opd2 underpoint ignored
//* for unsigned ? (compare)  0<...<+max<-max<-1<-0.x
//* opt:0x01:for divide,precision 1 up
//*     0x02:signed operation
//* ret :rc 4:err,    for comapre 0:opd1=opd2,1:opd1>opd2,-1:opd1<opd2
//**************************************************
//int ucalc_binop(int Popt,int Pope,long *Popd1,long *Popd2)       //~v5dsR~
int ucalc_binopsub(int Popt,int Pope,long *Popd1,long *Popd2)      //~v5dsI~
{
	int ovf=0,ii;                                                  //~v169R~
    int dn,dn2,rc;                                                 //~v5dtR~
    LONG opd1,opd2,wk;                                             //~v5dsR~
	LONG  compwk[4],compwk2[4];                                    //~v5dsR~
//  ULONG dwwk[3];                                                 //~v5drR~
    LONG dwwk[4],dwordovf=0;                                       //~v5dsR~
    int divovfsw=0;                                                //~v5dtI~
//****************************************
//low  DWORD
//  signedsw=Popt&CALC_SIGNED;                                     //~v5dtR~
    if (Pope=='?')
    {
    	memcpy(compwk,Popd1,sizeof(compwk));
        Popd1=compwk;
    }
//  if (*(Popd1+1)==UCALC_DWORDID || *(Popd2+1)==UCALC_DWORDID)		//1st opd dwid//~v5djR~
//  	return bc_dwbinop(Popt,Pope,Popd1,Popd2);                  //~v5djR~
//  if (Pope=='+' || Pope=='-' || Pope=='?')                       //~v5drR~
//      if (ucalc_underpoint(signedsw,Pope,Popd1,Popd2,&ovf))//may have sign//~v5drR~
//      	return 4;                                              //~v5drR~
//  dn=Popd1[1];                                                   //~v6xiR~
    dn=(int)Popd1[1];                                              //~v6xiI~
    if (dn>MAX_POINT_NUM)
//      return 4;                                                  //~v5duR~
        return calcerrunderflow();                                 //~v5duI~
//  dn2=Popd2[1];                                                  //~v5dsI~//~v6xiR~
    dn2=(int)Popd2[1];                                             //~v6xiI~
    if (dn2>MAX_POINT_NUM)                                         //~v5dsI~
//      return 4;                                                  //~v5duR~
        return calcerrunderflow();                                 //~v5duI~
    if (!dn)
        Popd1[2]=0;     //clear underpoint data
//high DWORD
//  opd1=Popd1[0]+ovf;                                             //~v5drR~
//  opd2=Popd2[0];                                                 //~v5drR~
    opd1=Popd1[0];                                                 //~v5drI~
    opd2=Popd2[0];                                                 //~v5drI~
    switch(Pope)
    {
    case '+':
//      opd1+=opd2;                                                //~v5drR~
//      Popd1[0]=opd1;                                             //~v5drR~
//      break;                                                     //~v5drR~
    case '-':
//      opd1-=opd2;                                                //~v5drR~
//      Popd1[0]=opd1;                                             //~v5drR~
		ucalc_dwupset(Popt,Popd1,Popd1);                           //~v5dsI~
		ucalc_dwupset(Popt,Popd2,Popd2);                           //~v5dsI~
		bc_dwbinop(Popt,Pope,Popd1,Popd2);                         //~v5dsI~
		rc=bc_dword2word(Popt,Popd1,Popd1);                        //~v5dsI~
        break;                                                     //~v5dsR~
    case '*':
//**  a.b*c.d process    12.3*4.56                                 //~v5dtR~
        if (Popd2[1]) // *  under point                            //~v50CR~
        {                                                          //~v50CI~
        	memcpy(compwk2,Popd1,sizeof(compwk2));	//save a.b     //~v50CI~
//a.b*c                  12.3*4                                    //~v5dtR~
    		compwk[1]=0;                                           //~v50CI~
    		compwk[0]=opd2;							//c.0          //~v50CI~
//          ucalc_binop(Popt,'*',Popd1,compwk);     //a.b*c        //~v5dsR~
            if (rc=ucalc_binopsub(Popt,'*',Popd1,compwk),rc)     //a.b*c//~v5dsR~
                return rc;                                         //~v5dsI~
//a.b*d                  12.3*56                                   //~v5dtR~
    		compwk[0]=Popd2[2];					    //d.0          //~v50CI~
//          ucalc_binop(Popt,'*',compwk2,compwk);   //a.b*d        //~v5dsR~
            if (rc=ucalc_binopsub(Popt,'*',compwk2,compwk),rc)   //a.b*d//~v5dsI~
                return rc;                                         //~v5dsI~
//a.b*0.d                12.3*56/100                               //~v5dtR~
//          ucalc_shiftdown((ULONG*)(void*)compwk2,(int)Popd2[1]); //~v5drR~
//          ucalc_shiftdown(CALC_SIGNED,compwk2,(int)Popd2[1]);    //~v5dtR~
            ucalc_shiftdown(Popt,compwk2,(int)Popd2[1]);           //~v5dtR~
//a.b*c+a.b*0.d          12.3*4+12.3*56/100                        //~v5dtR~
//          ucalc_binop(Popt ,'+',Popd1,compwk2);   //a.b*0.d      //~v5dsR~
//          if (rc=ucalc_binopsub(Popt ,'+',Popd1,compwk2),rc)   //a.b*0.d//~v5dxR~
            if (rc=ucalc_binop(Popt ,'+',Popd1,compwk2),rc)   //a.b*0.d may dword//~v5dxI~
                return rc;                                         //~v5dsI~
            return 0;                                              //~v50CI~
        }                                                          //~v50CI~
//a.b*c support                                                    //~v5dsI~
        if (Popd1[1]) //under point *
        {
//  		ovf=Popd1[2]*opd2;                                     //~v50AR~
//b*c                                                              //~v5dsM~
//          dwwk[0]=0; dwwk[1]=(ULONG)Popd1[2];                    //~v5drR~
            dwwk[0]=0; dwwk[1]=Popd1[2];                           //~v5dsI~
        	ucalc_dwmult(dwwk,opd2);                        //~v5dsR~
//  		Popd1[2]=ovf%Spnumtbl[Popd1[1]];                       //~v50AR~
//  		dwwk31[0]=dwwk[0];                                     //~v50DR~
//  		dwwk31[1]=UCALC_DWORDID;                               //~v50DR~
//  		dwwk31[2]=dwwk[1];                                     //~v50DR~
//  		dwwk32[0]=Spnumtbl[Popd1[1]];                          //~v50DR~
//  		dwwk32[1]=0;                                           //~v50DR~
//  		dwwk32[2]=0;                                           //~v50DR~
//      	bc_dwbinop(0,'%',dwwk31,dwwk32);                       //~v50DR~
//  		Popd1[2]=dwwk31[2];   //under point                    //~v50DR~
//  		ovf/=Spnumtbl[Popd1[1]];                               //~v50AR~
//0.b*c                                                            //~v5dsI~
        	ucalc_dwdiv(dwwk,Spnumtbl[Popd1[1]]);           //~v50AR~
            ovf=(int)dwwk[1];                                      //~v50AR~
    		Popd1[2]=(LONG)dwwk[2];   //residual:underpoint data   //~v5dsR~
        }
//      if (signedsw)                                              //~v5dsR~
//      	opd1=opd1*opd2+ovf;                                    //~v5dsR~
//      else                                                       //~v5dsR~
//      {                                                          //~v5dsR~
//0a*c                                                             //~v5dsI~
//      	opd1=(LONG)((ULONG)opd1*(ULONG)opd2+ovf);              //~v542I~
//          dwwk[0]=0; dwwk[1]=(ULONG)opd1;                        //~v5dsR~
            dwwk[0]=0; dwwk[1]=opd1;                               //~v5dsI~
//      	ucalc_dwmult(dwwk,(ULONG)opd2);                        //~v5dsR~
            ucalc_dwmult(dwwk,opd2);                               //~v5dsI~
//a*c+0.b*c                                                        //~v5dsI~
        	DWORD_ADD(dwwk[0],dwwk[1],0,ovf);                      //~v542I~
            opd1=(LONG)dwwk[1];                                    //~v5dtR~
//          if (Popt & CALC_MULTBYDIV)                             //~v5dtR~
//          	Popd2[2]=(LONG)dwwk[0];		//overflow value       //~v5dtR~
//          else                                                   //~v5dtR~
//          {                                                      //~v5dtR~
//          	if (dwwk[0])                                       //~v5dsR~
//              {                                                  //~v5dsR~
//               if (Popt & CALC_DWORDUP)	//output by dword fmt  //~v5dsR~
//               	dwordovf=dwwk[0]                               //~v5dsR~
//               else                                              //~v5dsR~
//               {                                                 //~v5dsR~
//                if (!(Popt & CALC_NOOVFMSG))                     //~v5dsR~
//  		    	uerrmsg("Word miltiply overflow",              //~v5dsR~
//          				"ワード乗算桁あふれ。");               //~v5dsR~
//              	return 4;		//overflow                     //~v5djR~
//              	return CALC_RCWORDOVF;		//overflow         //~v5dsR~
//               }                                                 //~v5dsR~
//              }                                                  //~v5dsI~
            	dwordovf=dwwk[0];                                  //~v5dsR~
//          }                                                      //~v5dtR~
//      }                                                          //~v5dsR~
        Popd1[0]=opd1;                                             //~v5drI~
        bc_expand2dword(dwordovf,Popd1);                           //~v5dtR~
        break;                                                     //~v5drR~
    case '!': 			//power                                    //~v169I~
//      wk=1;                                                      //~v544R~
//      dwwk[0]=0; dwwk[1]=1;                                      //~v5duR~
        memcpy(compwk,Popd1,sizeof(compwk));	//save a.b         //~v5duI~
//      for (ii=0;ii<opd2;ii++)                                    //~v5duR~
        for (ii=0;ii<opd2-1;ii++)                                  //~v5duI~
        {                                                          //~v544I~
//          wk*=opd1;                                              //~v544R~
//      	ucalc_dwmult(dwwk,(ULONG)opd1);                        //~v5duR~
        	rc=ucalc_binop(Popt,'*',Popd1,compwk);                 //~v5duR~
            if (rc)                                                //~v5duI~
            	return rc;                                         //~v5duI~
        }                                                          //~v544I~
//      opd1=wk;                                                   //~v544R~
//      Popd1[1]=0;                                                //~v544R~
//      opd1=(LONG)dwwk[1];                                        //~v5duR~
//      Popd1[1]=(LONG)dwwk[0];   //dword high                     //~v5dsR~
//      Popd1[0]=opd1;                                             //~v5duR~
        break;                                                     //~v169I~
    case '/':
        if (Popd2[1]) // /  under point  (a.b/c.d)                 //~v50CI~
        {                                                          //~v50CI~
//shift up c.d-->cd --->dwwk     1.2/3.45;   dwwk=3.45*100         //~v5dtR~
        	dwwk[0]=0;                                             //~v50CI~
        	dwwk[1]=Popd2[0];               		//c            //~v50CI~
        	ucalc_dwmult(dwwk,Spnumtbl[Popd2[1]]);  //c*10**(d) //~v50CI~
        	DWORD_ADD(dwwk[0],dwwk[1],0,Popd2[2]);  //c.d**(d)     //~v50CI~
            if (dwwk[0])	//over word                            //~v50CI~
//          	return 4;                                          //~v5dsR~
				return calcerrwordovf(Popt);                       //~v5dsI~
//a.b*10**(d)-->Popd1 :shiftup by dn2        Popd1=1.2*100         //~v5dtR~
            dwwk[0]=dwwk[1];                                       //~v50CI~
            dwwk[1]=0;			   //no underpoint                 //~v50CI~
//          compwk[0]=Spnumtbl[Popd2[1]];   //a.b**(d)             //~v5dtR~
//          compwk[1]=0;		//long witout underpoint           //~v5dtR~
//          compwk[2]=0;		//overflow output area when CALC_MULTBYDIV//~v5dtR~
//          ucalc_binop(Popt,'*',Popd1,compwk);   //a.b**(d)       //~v542R~
//          ucalc_binop(Popt|CALC_MULTBYDIV,'*',Popd1,compwk);   //a.b**(d)//~v5dsR~
//          ucalc_binopsub(Popt|CALC_MULTBYDIV,'*',Popd1,compwk);   //a.b**(d)//~v5dtR~
//          ucalc_binopsub(Popt,'*',Popd1,compwk);   //a.b**(d)    //~v5dtR~
//  		ucalc_shiftup(Popt,Popd1,Popd2[1]);                    //~v5g5R~
    		ucalc_shiftup(Popt,Popd1,(int)Popd2[1]);               //~v5g5I~
//          if (compwk[2])		//overflow                         //~v5dtR~
            if (Popd1[1] & UCALC_DWORDID)	//word overflow        //~v5dtI~
            {                                                      //~v542I~
                divovfsw=1;                                        //~v5dtR~
//[a.b*10**(d)]/cd -->compwk2              compwk=dword(1.2*100)/3.45*100//~v5dtR~
//  	        compwk2[0]=compwk[2];	//  high value of dw       //~v5dtR~
//      		compwk2[1]=Popd1[0];   //  low value               //~v5dtR~
    	        compwk2[0]=Popd1[0];//  high value of dw           //~v5dtI~
        		compwk2[1]=Popd1[2];   //  low value               //~v5dtI~
//  	        ucalc_dwdiv((ULONG*)(void*)compwk2,(ULONG)dwwk[0]);//~v5dxR~
    	        ucalc_dwdiv(compwk2,dwwk[0]);                      //~v5dxI~
//              if (compwk2[0])	//overflow                         //~v5dsR~
//              	return 4;                                      //~v5dsR~
                dwordovf=compwk2[0];	//for dword expanded output//~v5dsI~
//replace divided and add quotient later                           //~v5dsI~
                Popd1[1]&=~UCALC_DWORDID;	//divide  resudial with up//~v5dtM~
                Popd1[0]=compwk2[2];		//residual             //~v542R~
                Popd1[2]=Popd1[3];      	//up                   //~v5dtI~
            }                                                      //~v542I~
            if (Popt & CALC_DIVBYRES)                              //~v50CR~
            {                                                      //~v50CI~
// called from %                                                   //~v5dsI~
//              if (ucalc_binop(Popt,'%',Popd1,(LONG*)(void*)dwwk)) //a.b/c.d//~v5dsR~
//              	return 4;                                      //~v5dsR~
                if (rc=ucalc_binopsub(Popt,'%',Popd1,(LONG*)(void*)dwwk),rc) //a.b/c.d//~v5dsI~
                	return rc;                                     //~v5dsI~
//          	if (compwk[2])		//overflow                     //~v5dtR~
//                	Popd1[0]+=compwk2[1];                          //~v5dtR~
//          	ucalc_shiftdown((ULONG*)(void*)Popd1,(int)Popd2[1]);//~v5drR~
//          	ucalc_shiftdown(CALC_SIGNED,Popd1,(int)Popd2[1]);  //~v5dtR~
            	ucalc_shiftdown(Popt,Popd1,(int)Popd2[1]);         //~v5dtR~
            }                                                      //~v50CI~
            else                                                   //~v50CI~
            {                                                      //~v50CI~
//              if (ucalc_binop(Popt,'/',Popd1,(LONG*)(void*)dwwk))//a.b/c.d//~v5dsR~
//              	return 4;                                      //~v5dsI~
                if (rc=ucalc_binopsub(Popt,'/',Popd1,dwwk),rc)//a.b/c.d//~v5dsR~
                	return rc;                                     //~v5dsR~
//          	if (compwk[2])		//overflow                     //~v5dtR~
            	if (divovfsw)		//overflow                     //~v5dtI~
                	Popd1[0]+=compwk2[1];                          //~v542R~
            }                                                      //~v50CI~
	        bc_expand2dword(dwordovf,Popd1);                       //~v5dtI~
            return 0;                                              //~v50CI~
        }                                                          //~v50CI~
//divider 0 chk                                                    //~v5dsI~
    	if (!opd2)
//      	return 4;                                              //~v5dxR~
			return calcerr0div();                                  //~v5dxI~
//a.b/d               1.23/4                                       //~v5dtR~
        wk=opd1;
//      if (signedsw)                                              //~v5dtR~
//      {                       1/4  1%4                           //~v5dtR~
			opd1=opd1/opd2;
//  	    ovf=wk%opd2;                                           //~v541I~//~v6xiR~
    	    ovf=(INT4)wk%(INT4)opd2;                               //~v6xiR~
//      }                                                          //~v5dtR~
//      else                                                       //~v5dtR~
//      {                                                          //~v5dtR~
//  		opd1=(LONG)((ULONG)opd1/(ULONG)opd2);                  //~v5dtR~
//  	    ovf=(int)((ULONG)wk % (ULONG)opd2);                    //~v5dtR~
//      }                                                          //~v5dtR~
//      ovf=wk%opd2;                                               //~v541R~
//      wk=ovf*Spnumtbl[dn]+Popd1[2];                              //~v50AR~
//up calc                                                          //~v5dsI~
//res(a/c)*10**dn+b -->dwwk     dwwk=1%4*100                       //~v5dtR~
        dwwk[0]=0;                                                 //~v50AR~
        dwwk[1]=ovf;                                        //~v50AR~
        ucalc_dwmult(dwwk,Spnumtbl[dn]);                           //~v50AR~
        DWORD_ADD(dwwk[0],dwwk[1],0,Popd1[2]);                     //~v50AR~
//precidion up by 1                                                //~v5dsI~
        if (Popt & CALC_DIV_PRECUP && dn<MAX_POINT_NUM)
        {
//*     	wk*=10;                                                //~v50AR~
        	ucalc_dwmult(dwwk,10);                                 //~v50AR~
        	dn++;
		}
//*     Popd1[2]=wk/opd2;             1%4*100/4                    //~v5dtR~
        ucalc_dwdiv(dwwk,opd2);                             //~v50AR~
        Popd1[2]=(LONG)dwwk[1];                                    //~v50AR~
        Popd1[1]=dn;
        Popd1[0]=opd1;                                             //~v5drI~
        break;
    case '%':
        if (Popd2[1]) // /  under point  (a.b/c.d)                 //~v50CI~
        {                                                          //~v50CI~
            if (ucalc_binop(Popt|CALC_DIVBYRES,'/',Popd1,Popd2))   //~v50CR~
            	return 4;                                          //~v50CI~
            return 0;                                              //~v50CR~
        }                                                          //~v50CI~
        else                                                       //~v50CI~
        {                                                          //~v50CI~
    	if (!opd2)
//      	return 4;                                              //~v5dxR~
			return calcerr0div();                                  //~v5dxI~
//        if (signedsw)                                            //~v5dtR~
        	opd1%=opd2;                                            //~v541I~
//        else                                                     //~v5dtR~
//      	opd1=(LONG)((ULONG)opd1%(ULONG)opd2);                  //~v5dtR~
//          Popd1[1]=0;                                            //~v5dtR~
        }                                                          //~v50CI~
//      if (signedsw && opd2<0)                                    //~v5dtR~
//      	opd1=-opd1;                                            //~v5dtR~
//      Popd1[1]=0;                                                //~v50CR~
        Popd1[0]=opd1;                                             //~v5drI~
        break;
    case '<':
//      opd1=(LONG)((ULONG)opd1<<opd2);                            //~v6xhR~
        opd1=(INT4)((UINT4)opd1<<opd2);                            //~v6xhR~
        Popd1[1]=0;
        Popd1[0]=opd1;                                             //~v5drI~
        break;
    case '>':
//      opd1=(LONG)((ULONG)opd1>>opd2);                            //~v6xhR~
        opd1=(INT4)((UINT4)opd1>>opd2);                            //~v6xhR~
        Popd1[1]=0;
        Popd1[0]=opd1;                                             //~v5drI~
        break;
    case '|':                                                      //~v167I~
        opd1=(LONG)((ULONG)opd1|(ULONG)opd2);                      //~v167I~
        Popd1[1]=0;                                                //~v167I~
        Popd1[0]=opd1;                                             //~v5drI~
        break;                                                     //~v167I~
    case '&':                                                      //~v167I~
        opd1=(LONG)((ULONG)opd1&(ULONG)opd2);                      //~v167I~
        Popd1[1]=0;                                                //~v167I~
        Popd1[0]=opd1;                                             //~v5drI~
        break;                                                     //~v167I~
    case '^':                                                      //~v167I~
        opd1=(LONG)((ULONG)opd1^(ULONG)opd2);                      //~v167I~
        Popd1[1]=0;                                                //~v167I~
        Popd1[0]=opd1;                                             //~v5drI~
        break;                                                     //~v167I~
    case '?':
//      if (signedsw)                                              //~v5dtR~
//      {                                                          //~v5dtR~
//          if (opd1<opd2)                                         //~v5e9R~
//              return -1;                                         //~v5e9R~
//          if (opd1>opd2)                                         //~v5e9R~
//              return  1;                                         //~v5e9R~
//      }                                                          //~v5dtR~
//      else	//unsigned comp                                    //~v5dtR~
//      {                                                          //~v5dtR~
//          if ((ULONG)opd1<(ULONG)opd2)                           //~v5dtR~
//              return -1;                                         //~v5dtR~
//          if ((ULONG)opd1>(ULONG)opd2)                           //~v5dtR~
//              return  1;                                         //~v5dtR~
//      }                                                          //~v5dtR~
//      if (Popd1[2]<0)                                            //~v5e8R~
//          return -1;                                             //~v5e9R~
//      if (Popd1[2]>0)                                            //~v5e8R~
//      if (Popd1[2]>Popd2[2])                                     //~v5e9R~
//          return  1;                                             //~v5e9R~
    	memcpy(compwk,Popd1,sizeof(compwk));                       //~v5e9I~
		ucalc_binopsub(Popt,'-',compwk,Popd2);                     //~v5e9I~
        if (compwk[0]>0)                                           //~v5e9I~
        	return  1;                                             //~v5e9I~
        if (compwk[0]<0)                                           //~v5e9I~
        	return  -1;                                            //~v5e9I~
        if (!compwk[1])	//no under point                           //~v5e9I~
        	return 0;                                              //~v5e9I~
        if (compwk[2]>0)                                           //~v5e9I~
        	return  1;                                             //~v5e9I~
        if (compwk[2]<0)                                           //~v5e9I~
        	return  -1;                                            //~v5e9I~
        return 0;
    default:
        return 4;
    }
//  Popd1[0]=opd1;                                                 //~v5drR~
    return 0;
}//ucalc_binopsub                                                  //~v5dsR~
//**************************************************
//* under point calc(+/-)
//*parm1/2  opd[0]=signed over point value
//          opd[1]=digit num
//          opd[2]=signed underpoint value
//*parm3    output overflow value
//rc: err
//**************************************************
int ucalc_underpoint(int Psignedsw,int Popr,long *Popd1,long *Popd2,int *Povf)//~v314R~
{
	int  dn,dn1,dn2,ovf=0;
	LONG low1,low2,ovfchk,high1,high2;
//****************************************
	dn1=(int)Popd1[1];
	dn2=(int)Popd2[1];
    if (dn1>MAX_POINT_NUM||dn2>MAX_POINT_NUM)
    	return 4;
    if (!dn1 && !dn2)
    {
    	Popd1[1]=0;
        return 0;
    }
    high1=Popd1[0];
    high2=Popd2[0];
    low1=Popd1[2];
    low2=Popd2[2];
    if (!dn1)
    	low1=0;
    if (!dn2)
    	low2=0;

    if (Popr!='+') 		//- or ?
    {
        high2=-high2;
        low2=-low2;
	}
    if (dn1>dn2)
    {
        dn=dn1-dn2;
        low2*=Spnumtbl[dn];
        dn=dn1;
    }
    else
    if (dn1<dn2)
    {
        dn=dn2-dn1;
        low1*=Spnumtbl[dn];
        dn=dn2;
    }
    else
        dn=dn1;   //result digit

    high1+=high2;
    low1+=low2;
    ovfchk=Spnumtbl[dn];
//  if (low1>ovfchk)                                               //~v597R~
    if (low1>=ovfchk)                                              //~v597R~
    {
        ovf=1;
        low1-=ovfchk;
    }
    else
//  if (low1<-ovfchk)                                              //~v597R~
    if (low1<=-ovfchk)                                             //~v597R~
    {
        ovf=-1;
        low1+=ovfchk;
    }
    high1+=ovf;
    if (high1>0)
    {
        if (low1<0)
        {
            ovf--;
            low1+=ovfchk;
        }
    }
    else
    if (high1<0)
        if (low1>0)
        {
            ovf++;
            low1=low1-ovfchk;
        }
    *Povf=ovf;
    Popd1[1]=dn;
    Popd1[2]=low1;
    return 0;
}//ucalc_underpoint                                                //~v314R~
//**************************************************
//* edit decimal
//*parm1 :opt signed,spacez,z
//*parm2 :outarea
//*parm3 :input decimal data
//rc: err
//**************************************************
int ucalc_editnum(int Popt,char *Pout,long *Pvalue)                //~v314R~
{
    long opv,upv;
    int dn;
//*****************************
    opv=*Pvalue;
    dn=(int)*(Pvalue+1);
    upv=*(Pvalue+2);
    if (dn>MAX_POINT_NUM)
        return 4;

    if (!opv && dn && upv<0)
    {
    	memcpy(Pout,"-0",2);
        Pout+=2;
    }
    else
    	if (!(Popt & CALC_ENSIGNED))
    		Pout+=sprintf(Pout,"%lu",opv);
        else
	    	if (!(Popt & (CALC_ENSPACEZ|CALC_ENZ)))
		    	Pout+=sprintf(Pout,"%ld",opv);
            else
            {
//              unumedit((ULONG)opv,"zzz,zzz,zzz,zz9",Pout);       //~v5e7R~
                unumedit((ULONG)opv,"-zz,zzz,zzz,zz9",Pout);       //~v5e7I~
		    	if ((Popt & CALC_ENZ)) 	//drop space
                    strcpy(Pout,Pout+strspn(Pout," "));
                Pout+=strlen(Pout);
            }
	if (dn)	//underpoint
    {
    	if (upv<0)
        	upv=-upv;
    	sprintf(Pout,".%0*ld",dn,upv);
    }
    return 0;
}//ucalc_editnum                                                   //~v314R~
//**************************************************************** //~v56vI~
// edit hex for even number of digit                               //~v56vI~
//parm1:long value                                                 //~v56vI~
//parm2:output area                                                //~v56vI~
//*rc  :digit len                                                  //~v56vI~
//**************************************************************** //~v56vI~
int ucalc_editevenhex(long Pnum,char *Pout)                        //~v56vI~
{                                                                  //~v56vI~
	char editwk[12],*pc;                                           //~v56vI~
    int len;                                                       //~v56vI~
//*********************************                                //~v56vI~
	pc=editwk+1;                                                   //~v56vI~
//  len=sprintf(pc,"%lX",Pnum);                                    //~v56vR~//~v6xhR~
    len=sprintf(pc,"%X",(UINT4)Pnum);                              //~v6xhI~
    if (len%2)  //odd number with top x                            //~v56vI~
    {                                                              //~v56vI~
    	len++;                                                     //~v56vI~
        pc--;                                                      //~v56vI~
    	*pc='0';                                                   //~v56vI~
    }                                                              //~v56vI~
    strcpy(Pout,pc);                                               //~v56vI~
    return len;                                                    //~v56vI~
}//ucalc_editevenhex                                               //~v56vI~
//**************************************************               //~v5dwI~
//*process dword input format time parm                            //~v5dwI~
//rc: rc                                                           //~v5dwI~
//**************************************************               //~v5dwI~
int ucalc_dwtime(int Popt,int Popr,long *Popd1,long *Popd2)        //~v5dwI~
{                                                                  //~v5dwI~
    int rc;                                                        //~v5dwI~
    long  opd1[3],opd2[3],dwhigh1=0,dwhigh2=0;                     //~v5dwI~
//****************************************                         //~v5dwI~
  if (Popr!='=')    //opd1 is output for "="                       //~v5e5I~
  {                                                                //~v5e5I~
    if (Popd1[1] & UCALC_DWORDID)                                  //~v5dwI~
    {                                                              //~v5dwI~
    	dwhigh1=Popd1[0];    //dw high                             //~v5dwI~
    	opd1[0]=Popd1[2];    //dw low                              //~v5dwI~
        opd1[1]=Popd1[1]&~UCALC_DWORDID;                           //~v5dwI~
        opd1[2]=Popd1[3];                                          //~v5dwI~
    }                                                              //~v5dwI~
    else                                                           //~v6K4I~
    {                                                              //~v6K4I~
    	memcpy(opd1,Popd1,sizeof(opd1));                           //~v6K4I~
    }                                                              //~v6K4I~
  }                                                                //~v5e5I~
    if (Popd2[1] & UCALC_DWORDID)                                  //~v5dwI~
    {                                                              //~v5dwI~
    	dwhigh2=Popd2[0];    //dw high                             //~v5dwI~
    	opd2[0]=Popd2[2];    //dw low                              //~v5dwI~
        opd2[1]=Popd2[1]&~UCALC_DWORDID;                           //~v5dwI~
        opd2[2]=Popd2[3];                                          //~v5dwI~
    }                                                              //~v5dwI~
    else                                                           //~v6K4I~
    {                                                              //~v6K4I~
    	memcpy(opd2,Popd2,sizeof(opd2));                           //~v6K4I~
    }                                                              //~v6K4I~
    if (dwhigh1||dwhigh2)                                          //~v5dxI~
    {                                                              //~v5dxI~
        uerrmsg("Double owrd is invalid for time calc.",           //~v5dxI~
        		"時間計算でダブルワードは使えません");             //~v5dxI~
        return 8;                                                  //~v5dxI~
    }                                                              //~v5dxI~
    rc=ucalc_time(Popt,Popr,opd1,opd2);                            //~v5dwI~
    if (rc)                                                        //~v5dwI~
        return rc;                                                 //~v5dwI~
    if (Popd1[1] & UCALC_DWORDID)                                  //~v5dwI~
    {                                                              //~v5dwI~
    	Popd1[0]=0;    //dw high                                   //~v5dwI~
        Popd1[1]=opd1[1]|UCALC_DWORDID;                            //~v5dwI~
    	Popd1[2]=opd1[0];    //dw low                              //~v5dwI~
        Popd1[3]=opd1[2];                                          //~v5dwI~
    }                                                              //~v5dwI~
    else                                                           //~v6K4I~
	    memcpy(Popd1,opd1,sizeof(opd1));                           //~v6K4R~
    return 0;                                                      //~v5dwI~
}//ucalc_dwtime                                                    //~v5dwI~
//**************************************************
//*+/-/=time calc by 3 dword;value as hh:mm:ss.xxxxx fmt,
//                      digit num of under point,
//                      under point value
//parm1:1:if opd1<opd2 return absolute with sign on first bit
//      0:if opd1<opd2 borrow 24:00:00
//parm2:-/+/=(conv to sec)
//rc: rc
//**************************************************
int ucalc_time(int Popt,int Popr,long *Popd1,long *Popd2)          //~v314R~
{
	int  hh1,mm1,ss1,rc=0,opt;
	ULONG ts1,sign;
    long  opd1[3],opd2[3];
static long S240000[3]={24*3600,0,0};
    int swhhovf;                                                   //~v6K4I~
//****************************************
//  if (Popd1[1] & UCALC_DWORDID                                   //~v5e5R~
//  ||  Popd2[1] & UCALC_DWORDID)                                  //~v5e5R~
//      return ucalc_dwtime(Popt,Popr,Popd1,Popd2);                //~v5e5R~
//calc by sec value
    SovfHH=0;   //set when HH overflow                             //~v6K6I~
    if (Popr!='=')
    {
        if (Popd1[1] & UCALC_DWORDID                               //~v5e5I~
        ||  Popd2[1] & UCALC_DWORDID)                              //~v5e5I~
            return ucalc_dwtime(Popt,Popr,Popd1,Popd2);            //~v5e5I~
//conversion to sec for 2 opd
        if (Popt & CALC_TIME_1SEC)    //opd1 is timestamp
            memcpy(opd1,Popd1,sizeof(opd1));
        else
           ucalc_time(CALC_TIME_CONV2SEC,'=',opd1,Popd1);   //conv to sec//~v314R~
        if (Popt & CALC_TIME_2SEC)    //opd1 is timestamp
            memcpy(opd2,Popd2,sizeof(opd2));
        else
            ucalc_time(CALC_TIME_CONV2SEC,'=',opd2,Popd2);   //conv to sec//~v314R~

//      opt=CALC_SIGNED;                                           //~v5dtR~
        opt=0;                                                     //~v5dtI~
        if (Popt & CALC_TIME_DIVPREC)
        	opt|=CALC_DIV_PRECUP;
	    rc=ucalc_binop(opt,Popr,opd1,opd2);                        //~v314R~
        if (rc)             //overflow                             //~v6K4R~
            return rc;                                             //~v6K4I~
        if (Popt & CALC_TIME_CONV2SEC)     //sec to time stamp
            memcpy(Popd1,opd1,sizeof(opd1));
        else
        {                                                          //~v6K4I~
          rc=                                                      //~v6K4I~
            ucalc_time(CALC_TIME_CONV2HMS,'=',Popd1,opd1);         //~v314R~
        }                                                          //~v6K4I~
	}
    else	//opr=='='
    {
        if (Popd2[1] & UCALC_DWORDID)                              //~v5e5I~
            return ucalc_dwtime(Popt,Popr,Popd1,Popd2);            //~v5e5I~
        memcpy(opd1,Popd2,sizeof(opd1));
//*CALC_TIME_CONV2SEC & CONV2HMS both on when BORROW
        if (Popt & CALC_TIME_CONV2SEC)     //sec to time stamp
        {
	        sign=0;
            ts1=(ULONG)opd1[0];        //hh with sign bit
            if (ts1 & CALC_TIME_MINUS)
            {
                sign=CALC_TIME_MINUS;
                ts1 &=~CALC_TIME_MINUS;
            }
            ts1&=CALC_TIME_HMSMASK;
//          hh1=(int)(ts1>>16);                                    //~v6xhR~
            hh1=(int)((UINT4)ts1>>16);                             //~v6xhR~
//          mm1=(int)((ts1>>8)&255);                               //~v6xhR~
            mm1=(int)(((UINT4)ts1>>8)&255);                        //~v6xhR~
            ss1=(int)(ts1&255);
            opd1[0]=(long)hh1*3600+(long)mm1*60+(long)ss1;
            if (sign)
            {
                opd1[0]=-opd1[0];
                opd1[2]=-opd1[2];
            }
        }
        if (Popt & CALC_TIME_CONV2HMS)     //sec to time stamp
        {
	        sign=0;
            if (opd1[0]<0||(!opd1[0] && opd1[1] && opd1[2]<0))     //minus sec
            {                                                      //~v597R~
	        	if (Popt & CALC_TIME_BORROW)     //sec to time stamp
            		for (;;)
                    {
//  				    if (ucalc_binop(CALC_SIGNED,'+',opd1,S240000))//~v5dtR~
    				    if (ucalc_binop(0,'+',opd1,S240000))       //~v5dtI~
                        	break;
                    	if (opd1[0]>=0 && opd1[2]>=0)
                        	break;
            		}
                else
                {
                    sign=CALC_TIME_MINUS;
                    opd1[0]=-opd1[0];
                    opd1[2]=-opd1[2];
                }
            }                                                      //~v597R~
//          hh1=opd1[0]/3600%24;
//          hh1=opd1[0]/3600;                                      //~v6xiR~
            hh1=(INT4)opd1[0]/3600;                                //~v6xiI~
            if (hh1>=0)                                            //~v6K6R~
                swhhovf=hh1>0x7fff;                                //~v6K6R~
            else                                                   //~v6K6R~
                swhhovf=(-hh1)>0x7fff;                             //~v6K6R~
            if (swhhovf)                                           //~v6K6R~
            {                                                      //~v6K6I~
    			SovfHH=hh1;                                        //~v6K6R~
                if (!sign)                                         //~v6K6I~
                	hh1=0;      //avoid harf word minus value      //~v6K6I~
            }                                                      //~v6K6I~
//          mm1=opd1[0]/60%60;                                     //~v6xiR~
            mm1=(INT4)opd1[0]/60%60;                               //~v6xiI~
//          ss1=opd1[0]%60;                                        //~v6xiR~
            ss1=(INT4)opd1[0]%60;                                  //~v6xiI~
//          opd1[0]=(long)(sign|((ULONG)hh1<<16)|((ULONG)mm1<<8)|ss1);//~v6xhR~
//          opd1[0]=(INT4)(sign|((UINT4)hh1<<16)|((UINT4)mm1<<8)|ss1);//~v6xhR~//~v6xiR~
            opd1[0]=(INT4)((UINT4)sign|((UINT4)hh1<<16)|((UINT4)mm1<<8)|(UINT)ss1);//~v6xiR~
        }
        memcpy(Popd1,opd1,sizeof(opd1));
    }
    return rc;
}//ucalc_time                                                      //~v314R~
//**************************************************
//*edit time by 3 dword;value as hh:mm:ss.xxxxx fmt,
//                      digit num of under point,
//                      under point value
//rc: edit out len
//**************************************************
int ucalc_timeedit(int Popt,char *Pout,long *Pvalue)               //~v314R~
{
	ULONG hms;
	long upv;
    int  dn;
    char *pout;
    int days,hh,swminus=0;                                         //~v6K5I~
//****************************************
  if (Pvalue[1] & UCALC_DWORDID)                                   //~v5dwI~
	hms=(ULONG)Pvalue[2];                                          //~v5dwI~
  else                                                             //~v5dwI~
	hms=(ULONG)Pvalue[0];
    pout=Pout;
    if (hms & CALC_TIME_MINUS)
    {                                                              //~v5a2I~
    	hms &= ~CALC_TIME_MINUS;                                   //~v5a2I~
    	*pout++='-';	//minus
        swminus=1;                                                 //~v6K5I~
    }                                                              //~v5a2I~
	if (Popt & CALC_DAYS)                                          //~v6K5I~
    {                                                              //~v6K5I~
 	  if (Popt & CALC_OVFHH)                                       //~v6K6I~
      {                                                            //~v6K6I~
    	hh=SovfHH%24;                                              //~v6K6I~
    	days=SovfHH/24;                                            //~v6K6I~
      }                                                            //~v6K6I~
      else                                                         //~v6K6I~
      {                                                            //~v6K6I~
    	hh=(int)(hms>>16)%24;                                      //~v6K5I~
    	days=(int)(hms>>16)/24;                                    //~v6K5R~
      }                                                            //~v6K6I~
        if (swminus && (hms & 0xffff))                               //~v6K5M~//~v6K6R~
        	days++;                                                //~v6K5I~
        if (days)                                                  //~v6K5I~
        {                                                          //~v6K5I~
        	pout+=sprintf(pout,"%d_",days);                        //~v6K5R~
			if (Popt & CALC_DAYSONLY)                              //~v6K5I~
            {                                                      //~v6K5I~
			    return (int)((ULPTR)pout-(ULPTR)Pout);             //~v6K5I~
            }                                                      //~v6K5I~
            hms=((ULONG)hh<<16)|(hms&0xffff);                      //~v6K5R~
        }                                                          //~v6K5I~
        else                                                       //~v6K5I~
        {                                                          //~v6K5I~
			if (Popt & CALC_DAYSONLY)                              //~v6K5I~
				return 0;                                          //~v6K5R~
        }                                                          //~v6K5I~
    }                                                              //~v6K5I~
    else                                                           //~v6K6I~
    {                                                              //~v6K6I~
 	  if (Popt & CALC_OVFHH)                                       //~v6K6I~
    	hh=SovfHH;                                                 //~v6K6I~
      else                                                         //~v6K6I~
        hh=(int)((UINT4)hms>>16);                                  //~v6K6I~
    }                                                              //~v6K6I~
	if (Popt & CALC_TIME6)
   		pout+=sprintf(pout,"%02d%02d%02d",
//          (int)((hms>>16)&255),(int)((hms>>8)&255),(int)(hms&255));//~v58fR~
//          (int)((hms>>16)    ),(int)((hms>>8)&255),(int)(hms&255));//~v58fI~//~v6xhR~
//          (int)(((UINT4)hms>>16)    ),(int)(((UINT4)hms>>8)&255),(int)(hms&255));//~v6xhR~//~v6K6R~
            hh                         ,(int)(((UINT4)hms>>8)&255),(int)(hms&255));//~v6K6I~
    else
   		pout+=sprintf(pout,"%02d:%02d:%02d",
//          (int)((hms>>16)&255),(int)((hms>>8)&255),(int)(hms&255));//~v58fR~
//          (int)((hms>>16)    ),(int)((hms>>8)&255),(int)(hms&255));//~v58fI~//~v6xhR~
//          (int)(((UINT4)hms>>16)    ),(int)(((UINT4)hms>>8)&255),(int)(hms&255));//~v6xhR~//~v6K6R~
            hh                         ,(int)(((UINT4)hms>>8)&255),(int)(hms&255));//~v6K6I~
//  if ((dn=(int)Pvalue[1])!=0) //unser sec data                   //~v5dwR~
    if ((dn=(int)Pvalue[1]&~UCALC_DWORDID)!=0) //unser sec data    //~v5dwI~
    {
        dn=min(dn,MAX_POINT_NUM);
      if (Pvalue[1] & UCALC_DWORDID)                               //~v5dwI~
        upv=Pvalue[3];                                             //~v5dwI~
      else                                                         //~v5dwI~
        upv=Pvalue[2];
        pout+=sprintf(pout,".%0*ld",dn,upv);
    }
//  return (int)((ULONG)pout-(ULONG)Pout);                         //~v6hhR~
    return (int)((ULPTR)pout-(ULPTR)Pout);                         //~v6hhI~
}//ucalc_timeedit                                                  //~v314R~
//**************************************************               //~v50CI~
//*shift down up to max underpoint digit                           //~v50CI~
//parm1:3 DWORD underpoint data or 4 word DWUP                     //~v5dxR~
//parm2:shift count                                                //~v50CI~
//rc: 4:ovf                                                        //~v50CI~
//**************************************************               //~v50CI~
//int ucalc_shiftdown(ULONG *Pupdata,int Pshift)                   //~v5drR~
int ucalc_shiftdown(int Popt,LONG *Pupdata,int Pshift)             //~v5drI~
{                                                                  //~v50CI~
    int dn,dn2,dn3;                                                //~v5dtI~
//static  ULONG Sdivwk[3]={10,0,0};                                //~v5drR~
    LONG div10[3]={1,0,0};                                         //~v5drI~
//***********************                                          //~v50CI~
//  for (ii=0;ii<Pshift;ii++)                                      //~v5drR~
//      ucalc_binop(CALC_DIV_PRECUP,'/',(LONG*)(void*)Pupdata,(LONG*)(void*)Sdivwk);//~v5drR~
//  for (ii=0;ii<Pshift;ii++)                                      //~v5dtR~
//      div10[0]*=10;                                              //~v5dtR~
    div10[0]=Spnumtbl[Pshift];                                     //~v5dtI~
//  dn=Pupdata[1];                                                 //~v5dxR~
    dn=Pupdata[1] & UCALC_UPMASK;                                  //~v5dxI~
    dn2=dn+Pshift;                                                 //~v5dtI~
    if (dn2>MAX_POINT_NUM)                                         //~v5dtI~
    	dn2=MAX_POINT_NUM;                                         //~v5dtI~
    dn3=dn2-dn;                                                    //~v5dtI~
    if (dn3)                                                       //~v5dtI~
    {                                                              //~v5dtI~
      if (Pupdata[1] & UCALC_DWORDID)                              //~v5dxI~
      {                                                            //~v5dxI~
        Pupdata[3]*=Spnumtbl[dn3];                                 //~v5dxI~
        Pupdata[1]=dn2|UCALC_DWORDID;                              //~v5dxI~
      }                                                            //~v5dxI~
      else                                                         //~v5dxI~
      {                                                            //~v5dxI~
        Pupdata[2]*=Spnumtbl[dn3];                                 //~v5dtR~
        Pupdata[1]=dn2;                                            //~v5dtI~
      }                                                            //~v5dxI~
    }                                                              //~v5dtI~
    ucalc_binop(Popt,'/',Pupdata,div10);                           //~v5dtR~
    return 0;                                                      //~v50CI~
}//ucalc_shiftdown                                                 //~v50CR~
//**************************************************               //~v5dtI~
//*shift up digit                                                  //~v5dtI~
//parm1:3 DWORD underpoint data or 4 word DWORDUP                  //~v5dxR~
//parm2:shift count                                                //~v5dtI~
//rc: 4:ovf                                                        //~v5dtI~
//**************************************************               //~v5dtI~
int ucalc_shiftup(int Popt,LONG *Pupdata,int Pshift)               //~v5dtI~
{                                                                  //~v5dtI~
    LONG compwk[4];                                                //~v5dtI~
    int dn;                                                        //~v5dtI~
//***********************                                          //~v5dtI~
    dn=(int)Pupdata[1] & UCALC_UPMASK;                             //~v5dxR~
	compwk[0]=Spnumtbl[Pshift];   //a.b**(d)                       //~v5dtR~
    compwk[1]=0;		//long witout underpoint                   //~v5dtI~
    ucalc_binop(Popt,'*',Pupdata,compwk);   //a.b*10**shift        //~v5dxR~
    if (dn)                                                        //~v5dtI~
    {	                                                           //~v5dtI~
    	dn-=Pshift;                                                //~v5dtI~
      if (Pupdata[1] & UCALC_DWORDID)                              //~v5dxI~
      {                                                            //~v5dxI~
        Pupdata[3]/=compwk[0];  //shiftup up data                  //~v5dxI~
        if(dn<0)                                                   //~v5dxI~
            dn=0;                                                  //~v5dxI~
        Pupdata[1]=dn|UCALC_DWORDID;    //new digit count of underpoint//~v5dxI~
      }                                                            //~v5dxI~
      else                                                         //~v5dxI~
      {                                                            //~v5dxI~
        Pupdata[2]/=compwk[0];  //shiftup up data                  //~v5dxI~
        if(dn<0)                                                   //~v5dtR~
            dn=0;                                                  //~v5dtI~
        Pupdata[1]=dn;    //new digit count of underpoint          //~v5dtR~
      }                                                            //~v5dxI~
    }                                                              //~v5dtI~
    return 0;                                                      //~v5dtI~
}//ucalc_shiftup                                                   //~v5dtI~
//**************************************************               //~v5drI~
//*rc   :4                                                         //~v5drI~
//**************************************************               //~v5drI~
LONG  bc_getbase(int Pindx)                                        //~v5drI~
{                                                                  //~v5drI~
	if (Pindx>MAX_POINT_NUM)                                       //~v5dxI~
    	return 0;                                                  //~v5dxI~
	return Spnumtbl[Pindx];                                        //~v5drR~
}//bc_getbase                                                      //~v5drI~
//**************************************************               //~v169I~
//*rc   :4                                                         //~v169I~
//**************************************************               //~v169I~
int  calcuperr1(void)                                              //~v169I~
{                                                                  //~v169I~
//  uerrmsg("1st operand must be interger for !,<,>,&,|,^",        //~v5duR~
//  	    "!,<,>,&,|,^ のとき第1オペランドは整数のみ");          //~v5duR~
    uerrmsg("1st operand must be interger for <,>,&,|,^",          //~v5duI~
    	    "<,>,&,|,^ のとき第1オペランドは整数のみ");            //~v5duI~
	return 4;                                                      //~v169I~
}//calcuperr1                                                      //~v169I~
//**************************************************
//*rc   :4
//**************************************************
int  calcuperr2(void)
{
//  uerrmsg("2nd operand must be interger for *,/,%%,!",           //~v50CR~
//  	    "*,!,/,%%,<,>,&,|,^ のとき第２オペランドは整数のみ");  //~v50CR~
    uerrmsg("2nd operand must be interger for !,<,>,&,|,^",        //~v50CI~
    	    "!,<,>,&,|,^ のとき第２オペランドは整数のみ");         //~v50CI~
	return 4;
}//calcuperr2
//**************************************************               //~v6K3I~
int  calcuperr3(void)                                              //~v6K3I~
{                                                                  //~v6K3I~
    uerrmsg("multiple operator is not supported for !,<,>,&,|,^",  //~v6K3I~
    	    "!,<,>,&,|,^ は複数演算子使用の場合では使えません");   //~v6K3R~
	return 4;                                                      //~v6K3I~
}//calcuperr3                                                      //~v6K3I~
//**************************************************************** //~v314I~
// errinvalid                                                      //~v314I~
//*parm1 :operand string                                           //~v314I~
//*rc    :4                                                        //~v314I~
//**************************************************************** //~v314I~
int calcerrinvalid(UCHAR *Popd)                                    //~v314I~
{                                                                  //~v314I~
	uerrmsg("Invalid operand value(%s)",                           //~v314I~
			"オペランドの誤り(%s)",                                //~v314I~
			Popd);                                                 //~v314I~
	return 4;                                                      //~v314I~
}                                                                  //~v314I~
//**************************************************************** //~v6xgI~
int calcerrinvalid_dw(UCHAR *Popd)                                 //~v6xgI~
{                                                                  //~v6xgI~
	uerrmsg("Invalid operand value(%s),  for ex, exa9..87654321 , is double word spcification.",//~v6xgI~
			"オペランドの誤り(%s), ダブルワード数値は 例えば a9..87654321 のように指定します",//~v6xgR~
			Popd);                                                 //~v6xgI~
	return 4;                                                      //~v6xgI~
}                                                                  //~v6xgI~
//*******************************************************          //~v314I~
//!errdir(void)                                                    //~v314I~
//* parm:none                                                      //~v314I~
//* retrn:4                                                        //~v314I~
//*******************************************************          //~v314I~
int calcerrformat()                                                //~v50iR~
{                                                                  //~v314I~
//*******************                                              //~v314I~
	uerrmsg("Format error",                                        //~v314R~
			"形式エラー");                                         //~v314R~
	return 4;                                                      //~v314I~
}//errdir                                                          //~v314I~
//*******************************************************          //~v5duI~
//!word overflow                                                   //~v5duI~
//* parm:none                                                      //~v5duI~
//* retrn:4                                                        //~v5duI~
//*******************************************************          //~v5duI~
int calcerrunderflow(void)                                         //~v5duI~
{                                                                  //~v5duI~
//*******************                                              //~v5duI~
	uerrmsg("underflow(max %d under decimal point digit)",         //~v5duR~
			"小数点以下の桁あふれ(少数点以下は最大 %d 桁)",        //~v5duI~
			MAX_POINT_NUM);                                        //~v5duI~
    return CALC_RCERRMSG;                                          //~v5duI~
}//calcerrunderflow                                                //~v5duI~
//*******************************************************          //~v5dsI~
//!word overflow                                                   //~v5dsI~
//* parm:none                                                      //~v5dsI~
//* retrn:4                                                        //~v5dsI~
//*******************************************************          //~v5dsI~
int calcerrwordovf(int Popt)                                       //~v5dsR~
{                                                                  //~v5dsI~
//*******************                                              //~v5dsI~
    if (!(Popt & CALC_NOOVFMSG))                                   //~v5dsI~
		uerrmsg("word overflow",                                   //~v5dsR~
				"短精度桁あふれ");                                 //~v5dsR~
    return CALC_RCERRMSG;                                          //~v5dsI~
}//calcerrwordovf                                                  //~v5dsI~
//*******************************************************          //~v5dsI~
//!minus not avail                                                 //~v5dxR~
//* parm:none                                                      //~v5dsI~
//* retrn:4                                                        //~v5dsI~
//*******************************************************          //~v5dsI~
int calcerrminus(void)                                             //~v5dsI~
{                                                                  //~v5dsI~
//*******************                                              //~v5dsI~
	uerrmsg("minus value is invalid",                              //~v5dsI~
			"マイナスは使用できません");                           //~v5dsI~
    return CALC_RCERRMSG;                                          //~v5dsI~
}//calcerrminus                                                    //~v5dsI~
//*******************************************************          //~v5dxI~
//! 0 div err                                                      //~v5dxR~
//* parm:none                                                      //~v5dxI~
//* retrn:4                                                        //~v5dxI~
//*******************************************************          //~v5dxI~
int calcerr0div(void)                                              //~v5dxI~
{                                                                  //~v5dxI~
//*******************                                              //~v5dxI~
	uerrmsg("divide by 0",                                         //~v5dxI~
			"0-割算");                                             //~v5dxI~
    return CALC_RCERRMSG;                                          //~v5dxI~
}//calcerr0div                                                     //~v5dxI~
//*******************************************************          //~v5dxI~
//! invalid for time value                                         //~v5dxI~
//* parm:none                                                      //~v5dxI~
//* retrn:4                                                        //~v5dxI~
//*******************************************************          //~v5dxI~
int calcerrtimeop(void)                                            //~v5dxI~
{                                                                  //~v5dxI~
//*******************                                              //~v5dxI~
	uerrmsg("Operation not avail for Time",                        //~v5dxI~
			"時間にこの操作はできません");                         //~v5dxI~
    return 4;                                                      //~v5dxI~
}//calcerrtimeop                                                   //~v5dxI~
#ifdef ULIB64X                                                     //~v6hhI~
//*******************************************************          //~v6hhI~
//*long long interface                                             //~v6hhI~
//*******************************************************          //~v6hhI~
int bc_getvalueLL(int Popt,char *Popd,SLPTR *Pvalue,int *Pdatatype,int *Pdatatyped)//~v5drI~//~vafkM~//~v6hhI~
{                                                                  //~vafkM~//~v6hhI~
	int rc,ii;                                                     //~vafkI~//~v6hhI~
    long   lv[4];   //constant value                               //~vafkR~//~v6hhI~
//****************                                                 //~vafkM~//~v6hhI~
    memset(lv,0,sizeof(lv));                                       //~v6L7I~
	rc=bc_getvalue(Popt,Popd,lv,Pdatatype,Pdatatyped);//0:no dwordup//~vafkR~//~v6hhI~
    for (ii=0;ii<4;ii++)                                           //~vafkM~//~v6hhI~
    {                                                              //~vafkM~//~v6hhI~
    	Pvalue[ii]=(SLPTR)lv[ii];                                  //~vafkR~//~v6hhI~
    }                                                              //~vafkM~//~v6hhI~
    return rc;                                                     //~vafkM~//~v6hhI~
}//bc_getvalueLL                                              //~vafkM~//~v6hhI~
//*******************************************************          //~v6hhI~
int bc_getxdwLL(char *Popd,SLPTR *Pvalue)                          //~v6hhI~
{                                                                  //~v6hhI~
	int rc,ii;                                                     //~v6hhI~
    long   lv[4];   //constant value                               //~v6hhI~
//****************                                                 //~v6hhI~
    memset(lv,0,sizeof(lv));                                       //~v6L7I~
	rc=bc_getxdw(Popd,lv);//0:no dwordup                           //~v6hhI~
    for (ii=0;ii<4;ii++)                                           //~v6hhI~
    {                                                              //~v6hhI~
    	Pvalue[ii]=(SLPTR)lv[ii];                                  //~v6hhI~
    }                                                              //~v6hhI~
    return rc;                                                     //~v6hhI~
}//bc_getvalueLL                                                   //~v6hhI~
//*******************************************************          //~vafkI~//~v6hhI~
int ucalc_vrajustLL(int Popt,SLPTR *Pval,int Pvprec)                  //~v5e3R~//~vafkI~//~v6hhI~
{                                                                  //~vafkI~//~v6hhI~
	int rc,ii;                                                     //~vafkI~//~v6hhI~
    long   lv[4];   //constant value                               //~vafkI~//~v6hhI~
//****************                                                 //~vafkI~//~v6hhI~
    for (ii=0;ii<4;ii++)                                           //~vafkI~//~v6hhI~
    {                                                              //~vafkI~//~v6hhI~
    	lv[ii]=(long)Pval[ii];                                     //~vafkI~//~v6hhI~
    }                                                              //~vafkI~//~v6hhI~
	rc=ucalc_vrajust(Popt,lv,Pvprec);                              //~vafkR~//~v6hhI~
    for (ii=0;ii<4;ii++)                                           //~vafkI~//~v6hhI~
    {                                                              //~vafkI~//~v6hhI~
    	Pval[ii]=(SLPTR)lv[ii];                                    //~vafkI~//~v6hhI~
    }                                                              //~vafkI~//~v6hhI~
    return rc;                                                     //~vafkI~//~v6hhI~
}//ucalc_vrajustLL                                            //~vafkI~//~v6hhI~
//*******************************************************          //~vafkI~//~v6hhI~
int ucalc_timeLL(int Popt,int Popr,SLPTR *Popd1,SLPTR *Popd2)          //~v314R~//~vafkI~//~v6hhI~
{                                                                  //~vafkI~//~v6hhI~
	int rc,ii;                                                     //~vafkI~//~v6hhI~
    long  opd1[4],opd2[4];   //constant value                      //~vafkI~//~v6hhI~
//****************                                                 //~vafkI~//~v6hhI~
    for (ii=0;ii<4;ii++)                                           //~vafkI~//~v6hhI~
    {                                                              //~vafkI~//~v6hhI~
    	opd1[ii]=(long)Popd1[ii];                                  //~vafkI~//~v6hhI~
    	opd2[ii]=(long)Popd2[ii];                                  //~vafkI~//~v6hhI~
    }                                                              //~vafkI~//~v6hhI~
	rc=ucalc_time(Popt,Popr,opd1,opd2);                            //~vafkR~//~v6hhI~
    for (ii=0;ii<4;ii++)                                           //~vafkI~//~v6hhI~
    {                                                              //~vafkI~//~v6hhI~
    	Popd1[ii]=(SLPTR)opd1[ii];                                 //~vafkI~//~v6hhI~
    	Popd2[ii]=(SLPTR)opd2[ii];                                 //~vafkI~//~v6hhI~
    }                                                              //~vafkI~//~v6hhI~
    return rc;                                                     //~vafkI~//~v6hhI~
}//ucalc_timeLL                                               //~vafkI~//~v6hhI~
//*******************************************************          //~vafkI~//~v6hhI~
int ucalc_binopLL(int Popt,int Pope,SLPTR *Popd1,SLPTR *Popd2)         //~v5dsI~//~vafkR~//~v6hhI~
{                                                                  //~vafkI~//~v6hhI~
	int rc,ii;                                                     //~vafkI~//~v6hhI~
    long  opd1[4],opd2[4];   //constant value                      //~vafkI~//~v6hhI~
//****************                                                 //~vafkI~//~v6hhI~
    for (ii=0;ii<4;ii++)                                           //~vafkI~//~v6hhI~
    {                                                              //~vafkI~//~v6hhI~
    	opd1[ii]=(long)Popd1[ii];                                  //~vafkI~//~v6hhI~
    	opd2[ii]=(long)Popd2[ii];                                  //~vafkI~//~v6hhI~
    }                                                              //~vafkI~//~v6hhI~
	rc=ucalc_binop(Popt,Pope,opd1,opd2);                           //~vafkR~//~v6hhI~
    for (ii=0;ii<4;ii++)                                           //~vafkI~//~v6hhI~
    {                                                              //~vafkI~//~v6hhI~
    	Popd1[ii]=(SLPTR)opd1[ii];                                 //~vafkI~//~v6hhI~
    	Popd2[ii]=(SLPTR)opd2[ii];                                 //~vafkI~//~v6hhI~
    }                                                              //~vafkI~//~v6hhI~
    return rc;                                                     //~vafkI~//~v6hhI~
}//ucalc_binopLL                                              //~vafkI~//~v6hhI~
//*******************************************************          //~v6hhI~
int ucalc_o2lLL(char *Pdata,SLPTR *Pldata,int Plen)                //~v6hhR~
{                                                                  //~v6hhI~
	int rc;                                                        //~v6hhR~
    long   lv[4];   //constant value                               //~v6hhI~
//****************                                                 //~v6hhI~
	rc=ucalc_o2l(Pdata,lv,Plen);                                   //~v6hhI~
//  Pldata[0]=(SLPTR)lv;                                           //~v6hhR~//+v6L8R~
    Pldata[0]=(SLPTR)lv[0];                                        //+v6L8I~
    return rc;                                                     //~v6hhI~
}//ucalc_o2lLL                                                     //~v6hhI~
//*******************************************************          //~v6hhI~
int ucalc_gettimevalueLL(char *Pdata,int Plen,SLPTR *Pvalue)       //~v6hhI~
{                                                                  //~v6hhR~
	int rc,ii;                                                     //~v6hhI~
    long   lv[4];   //constant value                               //~v6hhI~
//****************                                                 //~v6hhI~
    memset(lv,0,sizeof(lv));                                       //~v6L7I~
	rc=ucalc_gettimevalue(Pdata,Plen,lv);                          //~v6hhI~
    for (ii=0;ii<4;ii++)                                           //~v6hhI~
    {                                                              //~v6hhI~
    	Pvalue[ii]=(SLPTR)lv[ii];                                  //~v6hhI~
    }                                                              //~v6hhI~
    return rc;                                                     //~v6hhI~
}//ucalc_gettimevalueLL                                            //~v6hhI~
//*******************************************************          //~v6hhI~
int bc_getldLL(int Popt,char *Pdata,SLPTR *Pvalue)                    //~v5djR~//~v6hhI~
{                                                                  //~v6hhI~
	int rc,ii;                                                     //~v6hhI~
    long   lv[4];   //constant value                               //~v6hhI~
//****************                                                 //~v6hhI~
    memset(lv,0,sizeof(lv));                                       //~v6L7I~
	rc=bc_getld(Popt,Pdata,lv);                                    //~v6hhR~
    for (ii=0;ii<4;ii++)                                           //~v6hhI~
    {                                                              //~v6hhI~
    	Pvalue[ii]=(SLPTR)lv[ii];                                  //~v6hhI~
    }                                                              //~v6hhI~
    return rc;                                                     //~v6hhI~
}//bc_getldLL                                                      //~v6hhI~
//*******************************************************          //~v6hhI~
int ucalc_timeeditLL(int Popt,char *Pout,SLPTR *Pvalue)            //~v6hhI~
{                                                                  //~v6hhI~
	int rc,ii;                                                     //~v6hhI~
    long  lv[4];                                                   //~v6hhI~
//****************                                                 //~v6hhI~
    for (ii=0;ii<4;ii++)                                           //~v6hhI~
    {                                                              //~v6hhI~
    	lv[ii]=(long)Pvalue[ii];                                   //~v6hhI~
    }                                                              //~v6hhI~
	rc=ucalc_timeedit(Popt,Pout,lv);                               //~v6hhI~
    return rc;                                                     //~v6hhI~
}//ucalc_timeeditLL                                                //~v6hhI~
//*******************************************************          //~v6hhI~
int bc_dweditnumLL(int Pfunctype,int Pconvtype,SLPTR *Pvalue,UCHAR *Pout)//~v6hhI~
{                                                                  //~v6hhI~
	int rc,ii;                                                     //~v6hhI~
    long  lv[4];                                                   //~v6hhI~
//****************                                                 //~v6hhI~
    for (ii=0;ii<4;ii++)                                           //~v6hhI~
    {                                                              //~v6hhI~
    	lv[ii]=(long)Pvalue[ii];                                   //~v6hhI~
    }                                                              //~v6hhI~
	rc=bc_dweditnum(Pfunctype,Pconvtype,lv,Pout);                  //~v6hhI~
    return rc;                                                     //~v6hhI~
}//bc_dweditnumLL                                                  //~v6hhI~
//*******************************************************          //~v6hhI~
int bc_edittodLL(UCHAR *Pout,SLPTR *Pvalue)                        //~v6hhI~
{                                                                  //~v6hhI~
	int rc,ii;                                                     //~v6hhI~
    long  lv[4];                                                   //~v6hhI~
//****************                                                 //~v6hhI~
    for (ii=0;ii<4;ii++)                                           //~v6hhI~
    {                                                              //~v6hhI~
    	lv[ii]=(long)Pvalue[ii];                                   //~v6hhI~
    }                                                              //~v6hhI~
	rc=bc_edittod(Pout,lv);                                        //~v6hhI~
    return rc;                                                     //~v6hhI~
}//bc_dwedittodLL                                                  //~v6hhR~
//*******************************************************          //~v6hhI~
int ucalc_editnumLL(int Popt,char *Pout,SLPTR *Pvalue)             //~v6hhI~
{                                                                  //~v6hhI~
	int rc,ii;                                                     //~v6hhI~
    long  lv[4];                                                   //~v6hhI~
//****************                                                 //~v6hhI~
    for (ii=0;ii<4;ii++)                                           //~v6hhI~
    {                                                              //~v6hhI~
    	lv[ii]=(long)Pvalue[ii];                                   //~v6hhI~
    }                                                              //~v6hhI~
	rc=ucalc_editnum(Popt,Pout,lv);                                //~v6hhR~
    return rc;                                                     //~v6hhI~
}//ucalc_editnumLL                                                 //~v6hhI~
//*******************************************************          //~v6hhI~
//*no caller by datatype                                           //~v6L7I~
//*******************************************************          //~v6L7I~
int ucalc_getunderpointdataLL(int Popt,char *Pdata,int Plen,SLPTR *Pvalue)//~v6hhI~
{                                                                  //~v6hhI~
	int rc,ii;                                                     //~v6hhI~
    long   lv[4];   //constant value                               //~v6hhI~
//****************                                                 //~v6hhI~
    memset(lv,0,sizeof(lv));                                       //~v6L7I~
	rc=ucalc_getunderpointdata(Popt,Pdata,Plen,lv);                //~v6hhI~
    for (ii=0;ii<4;ii++)                                           //~v6hhI~
    {                                                              //~v6hhI~
    	Pvalue[ii]=(SLPTR)lv[ii];                                  //~v6hhI~
    }                                                              //~v6hhI~
    return rc;                                                     //~v6hhI~
}//ucalc_getunderpointdataLL                                       //~v6hhR~
#endif                                                             //~v6hhI~
//*******************************************************          //~v6K3I~
//*get opd3,4,..                                                   //~v6K3I~
//*rc:8 fmterr, 4 errmsg issued                                    //~v6K3I~
//*******************************************************          //~v6K3I~
int bc_getvalue3(int Popt,UCHAR *Popd3,UCHAR *Ppot0,PUPODELMTBL Pdelmt0,int Popdno,int *Ppminusctr)//~v6K3R~
{                                                                  //~v6K3I~
    PUPODELMTBL pdelmt;                                            //~v6K3I~
    UCHAR *ppot;                                                   //~v6K3I~
    int  ctr3,ii,delm=0,opdno,minusctr=0;                          //~v6K3R~
    POPDVALUE pov;                                                 //~v6K3I~
//*********************                                            //~v6K3I~
	pov=Sopdvalue;                                                 //~v6K3I~
    ctr3=0;                                                        //~v6K3I~
    opdno=Popdno;                                                  //~v6K3R~
	for (ii=0,ppot=Ppot0,pdelmt=Pdelmt0;ii<opdno;ii++,ppot+=strlen(ppot)+1,pdelmt++)//~v6K3R~
    {                                                              //~v6K3I~
    	if (Popd3==ppot)                                           //~v6K3I~
        	break;                                                 //~v6K3I~
	    delm=pdelmt->upodelm;                                      //~v6K3I~
    }                                                              //~v6K3I~
    if (Popd3!=ppot)                                               //~v6K3I~
    	return 8;      //format err                                //~v6K3R~
	for (;ii<opdno;ii++,ppot+=strlen(ppot)+1,pdelmt++)             //~v6K3R~
    {                                                              //~v6K3I~
    	if (ctr3>=MAX_OPDVALUE)                                    //~v6K3I~
        {                                                          //~v6K3I~
        	uerrmsg("Max operators are %d",                        //~v6K3R~
            		"複数演算子の使用は最大 %d まで",              //~v6K3I~
            		MAX_OPDVALUE+2);                               //~v6K3I~
            return 4;                                              //~v6K3I~
        }                                                          //~v6K3I~
        if (strchr(Sopcode,delm))                                  //~v6K3I~
        {                                                          //~v6K3I~
            pov->functype=delm;                                    //~v6K3I~
        	if (strchr("!<>&|^",delm))                             //~v6K3R~
            	return calcuperr3();                               //~v6K3I~
        }                                                          //~v6K3I~
		else                                                       //~v6K3I~
            return calcerrinvalid((char*)(void*)&delm);            //~v6K3I~
    	if (!*ppot && pdelmt->upodelm==MINUSSIGN)//start by "-"    //~v6K3R~
        {                                                          //~v6K3I~
        	*ppot=MINUSSIGN;                                       //~v6K3I~
        	opdno--;                                               //~v6K3I~
            minusctr++;                                            //~v6K3I~
        	memcpy(pdelmt,pdelmt+1,sizeof(UPODELMTBL)*(size_t)(opdno-ii));//~v6K3I~
        }                                                          //~v6K3I~
      	if (bc_getvalue(CALC_DWORDUP,ppot,pov->lvt,&(pov->datatype),&(pov->datatyped)))//~v6K3R~
    		return 8;     //                                       //~v6K3R~
	    delm=pdelmt->upodelm;                                      //~v6K3I~
        ctr3++;                                                    //~v6K3I~
        pov++;                                                     //~v6K3I~
    }                                                              //~v6K3I~
	Sopdvaluectr=ctr3;;                                            //~v6K3I~
    *Ppminusctr=minusctr;                                          //~v6K3R~
    return 0;                                                      //~v6K3I~
}//bc_getvalue3                                                    //~v6K3I~
//*******************************************************          //~v6K3I~
//*set covtype bt prev data type and /X option                     //~v6K3R~
//*rc:8 fmterr, 4 errmsg issued                                    //~v6K3I~
//*******************************************************          //~v6K3I~
int bc_setconvtype3(int Popt,int Pdatatype1,int Pdatatype2,int Pparmconvtype,int *Ppconvtype)//~v6K3R~
{                                                                  //~v6K3I~
    int  ii,convtype,datatype,datatype2,convopt,swlast;            //~v6K3R~
    int lastconvtype;                                              //~v6K3I~
    POPDVALUE pov;                                                 //~v6K3I~
//*********************                                            //~v6K3I~
	datatype=Pdatatype1;                                           //~v6K3M~
	datatype2=Pdatatype2;                                          //~v6K3M~
                                                                   //~v6K3I~
    if (Pparmconvtype)                                             //~v6K3I~
        lastconvtype=Pparmconvtype;                                //~v6K3I~
    else                                                           //~v6K3I~
        lastconvtype=datatype;                                     //~v6K3I~
	convtype=datatype;                                             //~v6K3I~
    if (datatype=='T'||datatype2=='T')                             //~v6K3I~
    {                                                              //~v6K3I~
    	convopt=0;                                                 //~v6K3I~
		if (datatype!='T')                                         //~v6K3R~
            	convopt=CALC_OPD1SEC;	//conv to seconds          //~v6K3I~
		if (datatype2!='T')                                        //~v6K3I~
            	convopt=CALC_OPD2SEC;	//conv to seconds          //~v6K3I~
        convopt|=CALC_CONV2SEC;                                    //~v6K3I~
        convtype=convopt;//not "T"                                 //~v6K3R~
    }                                                              //~v6K3I~
    *Ppconvtype=convtype;                                          //~v6K3I~
    datatype=convtype & CALC_CONVTYPEMASK;                         //~v6K3I~
	for (pov=Sopdvalue,ii=0;ii<Sopdvaluectr;ii++,pov++)            //~v6K3R~
    {                                                              //~v6K3I~
    	convtype=datatype;                                         //~v6K3I~
    	swlast=(ii+1==Sopdvaluectr);                               //~v6K3I~
        if (swlast)                                                //~v6K3R~
        	convtype=lastconvtype;                                 //~v6K3R~
        else                                                       //~v6K3I~
            convtype=datatype;                                     //~v6K3I~
    	datatype2=pov->datatype;                                   //~v6K3I~
        convopt=0;                                                 //~v6K3I~
    	if (datatype2=='T')                                        //~v6K3I~
    	{                                                          //~v6K3I~
            convopt=CALC_OPD1SEC;	//skip time to sec             //~v6K3I~
            convopt|=CALC_CONV2SEC;                                //~v6K3I~
    	}                                                          //~v6K3I~
        if (convtype=='T')		//output is time                   //~v6K3I~
	        convopt=CALC_OPD1SEC|CALC_OPD2SEC;	//conv to seconds  //~v6K3I~
        convtype|=convopt;                                         //~v6K3I~
        pov->convtype=convtype;                                    //~v6K3I~
        datatype=convtype & CALC_CONVTYPEMASK;                     //~v6K3R~
    }                                                              //~v6K3I~
    return 0;                                                      //~v6K3I~
}//bc_setconvtype3                                                 //~v6K3I~
