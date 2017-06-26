//CID://+v6xiR~:              update#=    11                       //~v6xiR~//+v6xiR~
//*************************************************************
//*xecalc2.c                                                       //~v50gR~
//* basic calc:double word calc                                    //~v50gR~
//*************************************************************
//v6xi:150115 conversion warning                                   //~v6xiI~
//v6xh:150115 (BUG)invalid dword calc;on 64bit linux long/ulong is 64bit,so DWADD dose not overflow//~v6xhI~
//v6hh:120623 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  defines ULPTR(unsigned long long)//~v6hhI~
//v69C:110129 xds errmsg "dword and dword"                         //~v69CI~
//v69B:110102 ucalc:dword/dword,dword%dword support                //~v69BI~
//v5k2:061227 (LNX/WIN)bc_dweditnum64(long long int edit func) add //~v5k2I~
//v5e9:041003 xbc:"?"(compare) support                             //~v5e9I~
//v5e4:040930 (BUG)xbc:up data -0.xxxx is trated as plus           //~v5e4I~
//v5dy:040815 BC cmd:support dw%up                                 //~v5dyI~
//v5dx:040815 BC cmd:support dw/up                                 //~v5dyR~
//v5dt:040724 BC cmd:cont of v5ds                                  //~v5dtI~
//v5dr:040627 BC cmd:accept minus value                            //~v5drI~
//v5dp:040620 support dw+point/word                                //~v5dpI~
//v5dk:040612 support dword underpoint for "?"(compare)            //~v5dkI~
//v5dj:040612 support dword underpoint "+"(add)/"-" operation      //~v5djI~
//v5db:040531 issue errmsg when overflow(dword mult)               //~v5dbI~
//v5ag:040106 prevday support for calc nextday                     //~v5agI~
//v59s:031221 calc next day                                        //~v59sI~
//v57H:030615 decimal chk:return err when no digit(, or . only)    //~v56HI~
//v56w:020728 calc;OCT support for dword output                    //~v56wI~
//v50W:011019 bu xuerpck utility chk                               //~v50WI~
//v50t:010414 localtime may return 0 when too large seconds(before 1980)//~v50gI~
//v50r:010414 support convtype uz(unsigned edit)                   //~v50rI~
//v50q:010414 support output type "D" for dword                    //~v50qI~
//v50m:010414 "z" for datatype=decimal                             //~v50mI~
//v50k:010407 host time support                                    //~v50kI~
//v50h:010402 dword shift support                                  //~v50hI~
//v50g:010402 calc:long decimal support                            //~v50gR~
//v50e:010402 double word calc support
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <sys/timeb.h>
//*******************************************************
#include <ulib.h>
#include <uerr.h>
#include <ucalc.h>
#include <ucalc2.h>
#include <uedit.h>

//*******************************************************
#define WORDSZ   32
#define WORDSZSIGN   31                                            //~v5drR~
#define DWORDSZ  64                                                //~v50gI~
#define DWORDSZSIGN  63                                            //~v5drI~
#define HIGHBIT  0x80000000
#define SIGNHIGHBIT  0x40000000 //highest bit of signed            //~v5drI~
//*******************************************************
typedef struct _POWER2_TBL                                         //~v50gI~
        {int numstrlen;char *numstr;} POWER2_TBL,*PPOWER2_TBL;     //~v50gR~
#define P2TGEN(numstr) {sizeof(numstr)-1,numstr}                   //~v50gR~
static POWER2_TBL Sp2tbl[]={                                       //~v50gR~
        P2TGEN(                    "1"),   // 0                    //~v50gI~
        P2TGEN(                    "2"),   // 1                    //~v50gI~
        P2TGEN(                    "4"),   // 2                    //~v50gI~
        P2TGEN(                    "8"),   // 3                    //~v50gI~
        P2TGEN(                   "16"),   // 4                    //~v50gI~
        P2TGEN(                   "32"),   // 5                    //~v50gI~
        P2TGEN(                   "64"),   // 6                    //~v50gI~
        P2TGEN(                  "128"),   // 7                    //~v50gI~
        P2TGEN(                  "256"),   // 8                    //~v50gI~
        P2TGEN(                  "512"),   // 9                    //~v50gI~
        P2TGEN(                 "1024"),   //10                    //~v50gI~
        P2TGEN(                 "2048"),   //11                    //~v50gI~
        P2TGEN(                 "4096"),   //12                    //~v50gI~
        P2TGEN(                 "8192"),   //13                    //~v50gI~
        P2TGEN(                "16384"),   //14                    //~v50gI~
        P2TGEN(                "32768"),   //15                    //~v50gI~
                                                                   //~v50gI~
        P2TGEN(                "65536"),   //16                    //~v50gI~
        P2TGEN(               "131072"),   //17                    //~v50gI~
        P2TGEN(               "262144"),   //18                    //~v50gI~
        P2TGEN(               "524288"),   //19                    //~v50gI~
        P2TGEN(              "1048576"),   //20                    //~v50gI~
        P2TGEN(              "2097152"),   //21                    //~v50gI~
        P2TGEN(              "4194304"),   //22                    //~v50gI~
        P2TGEN(              "8388608"),   //23                    //~v50gI~
        P2TGEN(             "16777216"),   //24                    //~v50gI~
        P2TGEN(             "33554432"),   //25                    //~v50gI~
        P2TGEN(             "67108864"),   //26                    //~v50gI~
        P2TGEN(            "134217728"),   //27                    //~v50gI~
        P2TGEN(            "268435456"),   //28                    //~v50gI~
        P2TGEN(            "536870912"),   //29                    //~v50gI~
        P2TGEN(           "1073741824"),   //30                    //~v50gI~
        P2TGEN(           "2147483648"),   //31                    //~v50gI~
                                                                   //~v50gI~
        P2TGEN(           "4294967296"),   //32                    //~v50gI~
        P2TGEN(           "8589934592"),   //33                    //~v50gI~
        P2TGEN(          "17179869184"),   //34                    //~v50gI~
        P2TGEN(          "34359738368"),   //35                    //~v50gI~
        P2TGEN(          "68719476736"),   //36                    //~v50gI~
        P2TGEN(         "137438953472"),   //37                    //~v50gI~
        P2TGEN(         "274877906944"),   //38                    //~v50gI~
        P2TGEN(         "549755813888"),   //39                    //~v50gI~
        P2TGEN(        "1099511627776"),   //40                    //~v50gI~
        P2TGEN(        "2199023255552"),   //41                    //~v50gI~
        P2TGEN(        "4398046511104"),   //42                    //~v50gI~
        P2TGEN(        "8796093022208"),   //43                    //~v50gI~
        P2TGEN(       "17592186044416"),   //44                    //~v50gI~
        P2TGEN(       "35184372088832"),   //45                    //~v50gI~
        P2TGEN(       "70368744177664"),   //46                    //~v50gI~
        P2TGEN(      "140737488355328"),   //47                    //~v50gI~
                                                                   //~v50gI~
        P2TGEN(      "281474976710656"),   //48                    //~v50gI~
        P2TGEN(      "562949953421312"),   //49                    //~v50gI~
        P2TGEN(     "1125899906842624"),   //50                    //~v50gI~
        P2TGEN(     "2251799813685248"),   //51                    //~v50gI~
        P2TGEN(     "4503599627370496"),   //52                    //~v50gI~
        P2TGEN(     "9007199254740992"),   //53                    //~v50gI~
        P2TGEN(    "18014398509481984"),   //54                    //~v50gI~
        P2TGEN(    "36028797018963968"),   //55                    //~v50gI~
        P2TGEN(    "72057594037927936"),   //56                    //~v50gI~
        P2TGEN(   "144115188075855872"),   //57                    //~v50gI~
        P2TGEN(   "288230376151711744"),   //58                    //~v50gI~
        P2TGEN(   "576460752303423488"),   //59                    //~v50gI~
        P2TGEN(  "1152921504606846976"),   //60                    //~v50gI~
        P2TGEN(  "2305843009213693952"),   //61                    //~v50gI~
        P2TGEN(  "4611686018427387904"),   //62                    //~v50gI~
        P2TGEN(  "9223372036854775808"),   //63                    //~v50gI~
                                                                   //~v50gI~
        P2TGEN( "18446744073709551616")};  //64                    //~v50gI~
static ULONG S10power18[2]={0x0DE0B6B3,0xA7640000};			//dword value of 10**18//~v50gR~
                  //   1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12          //~v59sM~
static int Smday[12]={31,28,31,30,31,30,31,31,30,31,30,31};        //~v59sM~
static char *Sdwmaxval="9,223,372,036,854,775,808";   //63         //~v5dyR~
//**************************************************               //~v50gI~
int ucalc_ldedit(UCHAR *Pnumstr,UCHAR *Pnumedit);                  //~v50gI~
int bc_dwupeditnum(int Pfunctype,int Pconvtype,long *Pvalue,UCHAR *Pout);//~v5djI~
int ucalc_dw2err(int Pope);                                        //~v50hI~
int bc_twbinop(int Popt,int Pope,long *Popd1,long *Popd2);         //~v5djI~
//int ucalc_twdiv(ULONG *Pdw1,LONG *Pup1,ULONG *Pdw2,LONG *Pup2);  //~v5drR~
//int ucalc_twdiv(LONG *Pdw1,LONG *Pup1,LONG *Pdw2,LONG *Pup2);    //~v5dxR~
int ucalc_twdiv(int Popt,LONG *Pdw1,LONG *Pup1,LONG *Pdw2,LONG *Pup2);//~v5dxI~
int ucalc_twmult(int Popt,int Popd1id,LONG *Pdw1,LONG *Pup1,int Popd2id,LONG *Pdw2,LONG *Pup2);//~v5drR~
int ucalc_dwuperr(void);                                           //~v5djR~
int ucalc_dwmaxerr(void);                                          //~v5drI~
//int bc_numfmt2dw(int Popt,long *Pnumfmt,long *Psw);                //~v5drI~//~v69CR~
int ucalc_dwup2dwandup(long *Pdwup,long *Pdw,long *Pup);           //~v5drR~
int ucalc_dwshiftdown(int Popt,LONG *Pupdata,int Pshift,LONG *Pnumfmt);//~v5drR~
int ucalc_twdivbyup(int Popt,LONG *Pdw1,LONG *Pup1,LONG Pw2,LONG *Pup2);//~v5dxR~
int ucalc_twshiftup(LONG *Pdw,LONG *Pup,int Pshift);               //~v5dxI~
int ucalc_dwdiv2(int Popt,int Pope,LONG *Ppopd1,LONG *Popd2);      //~v69BI~
int ucalc_dw2errresidual(LONG *Pans,LONG *Pres);                   //~v69BI~
//**************************************************
//*get dword hex data
//ret rc:0:not dword,1:dword gotten,4:no dword,8:hex digit err     //~v50gR~
//**************************************************
int bc_getxdw(char *Pdata,long *Pvalue)
{
	char *pc;
    int len,len2,len3;
//****************************************
    pc=strchr(Pdata,'.');
    if (!pc || *(pc+1)!='.') //".." dword id
    	return 0;			//no dword specification               //~v50gR~
    len=(int)strlen(Pdata);
//  len2=(int)((ULONG)pc-(ULONG)Pdata);    //before point          //~v6hhR~
    len2=(int)((ULPTR)pc-(ULPTR)Pdata);    //before point          //~v6hhI~
    len3=len-len2-2;                       //2nd word len
    if (len3<=0)
    	return 4;
    if (len2>8 || unumlen(Pdata,UNUMLEN_HEX,len2)!=len2)   //all hex numeric
        return 8;
    sscanf(Pdata,"%lx",Pvalue);
    if (len3>8 || unumlen(pc+2,UNUMLEN_HEX,len3)!=len3)   //all hex digit
        return 8;
    Pvalue[1]=UCALC_DWORDID;
    ux2l(pc+2,(ULONG*)(void*)(Pvalue+2));
    return 1;                                                      //~v50gI~
}//bc_getxdw
//**************************************************               //~v50gI~
//*conv numstring to signed long/dword                             //~v5drR~
//ret rc:0:word,1:dword gotten                                     //~v50mR~
//**************************************************               //~v50gI~
int bc_getld(int Popt,char *Pdata,long *Pvalue)                    //~v5djR~
{                                                                  //~v50gI~
//  ULONG ulwk[2];                                                 //~v5drR~
    LONG ulwk[2];                                                  //~v5drI~
    long  upval[3]={0,0,0};                                        //~v5dkR~
    UCHAR *pc;                                                     //~v50mI~
    int rc;                                                        //~v50mI~
//****************************************                         //~v50gI~
	rc=ucalc_ld2dw(Pdata,ulwk);                                    //~v50mR~
    switch(rc)                                                     //~v50mI~
    {                                                              //~v50mI~
    case 0:			//valid word/dword                             //~v50mI~
//  	if (!ulwk[0])                                              //~v5drR~
//      {                                                          //~v5drR~
    		Pvalue[0]=(LONG)ulwk[1]; 	//word value is top        //~v50mI~
    		Pvalue[1]=0;                                           //~v50mI~
        	return 0;                                              //~v50mR~
//      }                                                          //~v5drR~
//      break;                                                     //~v5drR~
    case 1:         //valid word with "."                          //~v50mI~
    case -1:        //valid word with "." with "-"(minus)          //~v5e4I~
    	Pvalue[0]=(LONG)ulwk[1]; 	//word value is top            //~v50mI~
        pc=strchr(Pdata,'.');                                      //~v50mI~
        if (ucalc_getunderpointdata(0,pc+1,(int)strlen(pc+1),Pvalue))//~v50mI~
            return 4;                                              //~v50mI~
      	if (Pvalue[0]<0)                                           //~v5drI~
        	Pvalue[2]=-Pvalue[2];                                  //~v5drI~
        else                                                       //~v5e4I~
   		   	if (!Pvalue[0] && rc==-1) 	//-0.xxx fmt               //~v5e4I~
	        	Pvalue[2]=-Pvalue[2];                              //~v5e4I~
    	return 0;                                                  //~v50mR~
    case 2:         //dword underpoint                             //~v5djI~
        if (!(Popt & GETLD_DWUP))                                  //~v5djI~
        	return 4;                                              //~v5djI~
        pc=strchr(Pdata,'.');                                      //~v5djI~
        if (ucalc_getunderpointdata(0,pc+1,(int)strlen(pc+1),upval))//~v5djI~
            return 4;                                              //~v5djI~
      if (ulwk[0]<0)                                               //~v5drI~
        Pvalue[3]=-upval[2];                                       //~v5drI~
      else                                                         //~v5drI~
        Pvalue[3]=upval[2];                                        //~v5djR~
        break;                                                     //~v5djI~
    case 3:         //dword                                        //~v5drI~
        break;                                                     //~v5drI~
    default:                                                       //~v50mI~
//  	return 4;                                                  //~v5drR~
    	return rc;                                                 //~v5drI~
    }                                                              //~v50mI~
    Pvalue[0]=(LONG)ulwk[0];                                       //~v50mM~
//  Pvalue[1]=UCALC_DWORDID;                                       //~v5djR~
    Pvalue[1]=UCALC_DWORDID+upval[1];                              //~v5djI~
    Pvalue[2]=(LONG)ulwk[1];                                       //~v50gI~
    return 1;                                                      //~v50gR~
}//bc_getld                                                        //~v50gI~
//***************************************************************
//*dword operation                                                 //~v5djR~
//*rc:0:normal,4:no dword,8:err
//***************************************************************
int bc_dwbinop(int Popt,int Pope,long *Popd1,long *Popd2)
{

//  ULONG dwopd1[3],dwopd2[3],dwwk,opd1id,opd2id;                  //~v5drR~
    LONG dwopd1[3],dwopd2[3],dwwk,opd1id,opd2id,up2[3],dwupwk1[4],dwupwk2[4];//~v5drR~
    int dwid,rc=0,ii;                                                //~v50hR~
    int upno=0;                                                    //~v5drI~
//*****************
	opd1id=Popd1[1];                                               //~v5drR~
	opd2id=Popd2[1];                                               //~v5drR~
//if ((opd1id>UCALC_DWORDID) || (opd2id>UCALC_DWORDID))            //~v5dtR~
  if ((opd1id|opd2id)>UCALC_DWORDID) //dword and up operation      //~v5dtI~
//  dwid=4;                                                        //~v5drR~
  	return bc_twbinop(Popt,Pope,Popd1,Popd2);                      //~v5drI~
//else                                                             //~v5drR~
	dwid=(opd1id==UCALC_DWORDID)+((opd2id==UCALC_DWORDID)<<1);     //~v5djI~
//    if (dwid)                                                    //~v5djR~
//        if ((opd1id && opd1id!=UCALC_DWORDID)                    //~v5djR~
//        ||  (opd2id && opd2id!=UCALC_DWORDID))                   //~v5djR~
//        {                                                        //~v5djR~
//            uerrmsg("Dword and decimal point is mutualy exclusive.",//~v5djR~
//                    "ダブルワードと小数点は計算できません");     //~v5djR~
//            return 8;                                            //~v5djR~
//        }                                                        //~v5djR~
//  switch(dwid)                                                   //~v5drR~
//  {                                                              //~v5drR~
//  case 1:     //opd1 dw                                          //~v5drR~
//   if (Popt & CALC_SIGNED && !*Popd1 && *(Popd1+2)<0)            //~v5drR~
//      dwopd1[0]=(ULONG)*Popd1;                                   //~v5drR~
//   else                                                          //~v5drR~
//      dwopd1[0]=(ULONG)*Popd1;                                   //~v5drR~
//      dwopd1[1]=(ULONG)*(Popd1+2);                               //~v5drR~
//      dwopd2[0]=0;                                               //~v5drR~
//      dwopd2[1]=(ULONG)*Popd2;                                   //~v5drR~
//      break;                                                     //~v5drR~
//  case 2:     //opd2 dw                                          //~v5drR~
//      dwopd1[0]=0;                                               //~v5drR~
//      dwopd1[1]=(ULONG)*Popd1;                                   //~v5drR~
//   if (Popt & CALC_SIGNED && !*Popd2 && *(Popd2+2)<0)            //~v5drR~
//      dwopd2[0]=(ULONG)*Popd2;                                   //~v5drR~
//   else                                                          //~v5drR~
//      dwopd2[0]=(ULONG)*Popd2;                                   //~v5drR~
//      dwopd2[1]=(ULONG)*(Popd2+2);                               //~v5drR~
//      break;                                                     //~v5drR~
//  case 3:     //both dword                                       //~v5drR~
//   if (Popt & CALC_SIGNED && !*Popd1 && *(Popd1+2)<0)            //~v5drR~
//      dwopd1[0]=(ULONG)*Popd1;                                   //~v5drR~
//   else                                                          //~v5drR~
//      dwopd1[0]=(ULONG)*Popd1;                                   //~v5drR~
//      dwopd1[1]=(ULONG)*(Popd1+2);                               //~v5drR~
//   if (Popt & CALC_SIGNED && !*Popd2 && *(Popd2+2)<0)            //~v5drR~
//      dwopd2[0]=(ULONG)*Popd2;                                   //~v5drR~
//   else                                                          //~v5drR~
//      dwopd2[0]=(ULONG)*Popd2;                                   //~v5drR~
//      dwopd2[1]=(ULONG)*(Popd2+2);                               //~v5drR~
//      break;                                                     //~v5drR~
//  default:                                                       //~v5drR~
//  	return 4;                                                  //~v5djR~
//  	return bc_twbinop(Popt,Pope,Popd1,Popd2);                  //~v5drR~
//  }                                                              //~v5drR~
    bc_numfmt2dw(Popt,Popd1,dwopd1);    //get dword                //~v5drI~
    bc_numfmt2dw(Popt,Popd2,dwopd2);                               //~v5drI~
//binary operation                                                 //~v5drR~
    switch(Pope)
    {
    case '+':
        DWORD_ADD(dwopd1[0],dwopd1[1],dwopd2[0],dwopd2[1]);
        break;
    case '-':
        DWORD_SUB(dwopd1[0],dwopd1[1],dwopd2[0],dwopd2[1]);
        break;
    case '?':                                                      //~v5e9I~
        DWORD_SUB(dwopd1[0],dwopd1[1],dwopd2[0],dwopd2[1]);        //~v5e9I~
        if (dwopd1[0]<0)                                           //~v5e9R~
            rc=-1;                                                 //~v5e9I~
        else                                                       //~v5e9I~
        if (dwopd1[0]||dwopd1[1])                                  //~v5e9R~
            rc=1;                                                  //~v5e9I~
        break;                                                     //~v5e9I~
    case '*':
//1st opd is dword, 2nd is word with or w/o up                     //~v5drI~
    	switch(dwid)
        {
        case 1:                          //1st opd is dword
        	dwwk=dwopd2[1];
            memcpy(up2,Popd2,sizeof(up2));                         //~v5drI~
            break;
        case 2:                          //2ndst opd is dword
        	dwwk=dwopd1[1];
            memcpy(up2,Popd1,sizeof(up2));                         //~v5drI~
        	dwopd1[0]=dwopd2[0];                                   //~v5drR~
        	dwopd1[1]=dwopd2[1];                                   //~v5drR~
//  		*(Popd1+1)=UCALC_DWORDID;	//answer is dword          //~v5drR~
            break;
        default:
          if (!(Popt & CALC_NOERRMSG))                             //~v5drI~
        	uerrmsg("Dword * dword is not supported",
            		"ダブルワード同士の掛け算はできません");
            return 8;
        }
        memcpy(dwopd2,dwopd1,sizeof(dwopd1));//save for up calc    //~v5drI~
        rc=ucalc_dwmult(dwopd1,dwwk);
        if (rc)                                                    //~v5dbI~
        {                                                          //~v5drI~
//      	uerrmsg("Dword multiply overflow",                     //~v5dxR~
//          		"ダブルワード乗算の桁あふれ。");               //~v5dxR~
            ucalcerrdwordovf();                                    //~v5dxI~
            break;                                                 //~v5drI~
        }                                                          //~v5drI~
        if (!up2[1])   //2nd opd is not up                         //~v5drI~
            break;                                                 //~v5drI~
        if (rc=ucalc_dwmult(dwopd2,up2[2]),rc)                     //~v5drR~
        {                                                          //~v5dyI~
            ucalcerrdwordovf();                                    //~v5dyI~
        	break;                                                 //~v5drI~
        }                                                          //~v5dyI~
//  	if (rc=ucalc_dwshiftdown(Popt,dwopd2,up2[1],dwupwk2),rc)   //~v5k2R~
    	if (rc=ucalc_dwshiftdown(Popt,dwopd2,(int)up2[1],dwupwk2),rc)//~v5k2I~
        	break;                                                 //~v5drI~
        dwupwk1[0]=dwopd1[0];                                      //~v5drI~
        dwupwk1[1]=UCALC_DWORDID;                                  //~v5drI~
        dwupwk1[2]=dwopd1[1];                                      //~v5drR~
        bc_dwbinop(Popt,'+',dwupwk1,dwupwk2);                      //~v5drR~
        dwopd1[0]=dwupwk1[0];                                      //~v5drI~
        upno=(INT4)dwupwk1[1] & ~UCALC_DWORDID;                          //~v5drI~//~v6xiR~
        dwopd1[1]=dwupwk1[2];                                      //~v5drR~
        Popd1[3]=dwupwk1[3];    //up data                          //~v5drR~
        break;
    case '/':
    case '%':
    	if (dwid!=1)	//both dword
        {                                                          //~v69BI~
//  		return ucalc_dw2err(Pope);                             //~v50hI~//~v69BR~
            rc=ucalc_dwdiv2(Popt,Pope,dwopd1,dwopd2);              //~v69BI~
        }                                                          //~v69BI~
        else                                                       //~v69BI~
        rc=ucalc_dwdiv(dwopd1,dwopd2[1]);                          //~v5drR~
        if (Pope=='%')
        {
        	dwopd1[0]=0;
        	dwopd1[1]=dwopd1[2];	//residual
        }
        break;
    case '<':                                                      //~v50hI~
    	if (dwid!=1)	//both dword                               //~v50hI~
			return ucalc_dw2err(Pope);                             //~v50hI~
        for (ii=(int)dwopd2[1];ii;ii--)                            //~v50hI~
        	DWORD_LSHIFT(dwopd1[0],dwopd1[1]);                     //~v50hI~
        break;                                                     //~v50hI~
    case '>':                                                      //~v50hI~
    	if (dwid!=1)	//both dword                               //~v50hI~
			return ucalc_dw2err(Pope);                             //~v50hI~
        for (ii=(int)dwopd2[1];ii;ii--)                            //~v50hI~
        	DWORD_RSHIFT(dwopd1[0],dwopd1[1]);                     //~v50hI~
        break;                                                     //~v50hI~
    default:
      if (!(Popt & CALC_NOERRMSG))                                 //~v5drI~
//      uerrmsg("Dword operation is supported only for +,-,*,/,%%,<,>",//~v5e9R~
//        		"ダブルワード計算は +,-,*,/,%%,<,> だけです。");   //~v5e9R~
        uerrmsg("Dword operation is supported only for +,-,*,/,%%,<,>,?",//~v5e9I~
          		"ダブルワード計算は +,-,*,/,%%,<,>,? だけです。"); //~v5e9I~
        return 8;
    }
  if (Pope!='?')                                                   //~v5e9I~
  {                                                                //~v5e9I~
    *Popd1=(LONG)dwopd1[0];
  	*(Popd1+1)=UCALC_DWORDID+upno;	//answer is dword              //~v5drR~
    *(Popd1+2)=(LONG)dwopd1[1];
  }                                                                //~v5e9I~
    return rc;
}//bc_dwbinop
//***************************************************************  //~v5djI~
//calc for 1 of 2 is dword+underpoint                              //~v5drR~
//*rc:0:normal,4:no dword,8:err                                    //~v5djI~
//***************************************************************  //~v5djI~
int bc_twbinop(int Popt,int Pope,long *Popd1,long *Popd2)          //~v5djI~
{                                                                  //~v5djI~
                                                                   //~v5djI~
    LONG dwopd1[2],dwopd2[2],opd1id,opd2id;                        //~v5drR~
    LONG  up1[4],up2[4],upc1[3]={1,0,0};                           //~v5drR~
    LONG  compwk[4];                                               //~v5dkI~
    int ovf=0;                                                     //~v5djI~
    int rc;                                                        //~v5dpI~
//*****************                                                //~v5djI~
	opd1id=ucalc_dwup2dwandup(Popd1,dwopd1,up1);                   //~v5drR~
	opd2id=ucalc_dwup2dwandup(Popd2,dwopd2,up2);                   //~v5drR~
    switch(Pope)                                                   //~v5djI~
    {                                                              //~v5djI~
    case '+':                                                      //~v5djI~
        ucalc_underpoint(0,Pope,up1,up2,&ovf);                     //~v5djI~
        DWORD_ADD(dwopd1[0],dwopd1[1],dwopd2[0],dwopd2[1]);        //~v5djI~
        break;                                                     //~v5djI~
    case '-':                                                      //~v5djI~
        ucalc_underpoint(0,Pope,up1,up2,&ovf);                     //~v5djI~
        DWORD_SUB(dwopd1[0],dwopd1[1],dwopd2[0],dwopd2[1]);        //~v5djI~
        break;                                                     //~v5djI~
    case '?':                                                      //~v5dkI~
    	memcpy(compwk,Popd1,sizeof(compwk));                       //~v5dkI~
		bc_twbinop(Popt,'-',compwk,Popd2);                         //~v5dkI~
        if (compwk[0]<0)                                           //~v5dkI~
        	return -1;                                             //~v5dkI~
        if (compwk[0]>0)                                           //~v5dkI~
        	return  1;                                             //~v5dkI~
        if (compwk[2]<0)   //dword high=0                          //~v5drI~
        	return -1;                                             //~v5drI~
        if (compwk[2]>0)   //dword high=0                          //~v5drR~
        	return  1;                                             //~v5dkI~
        if (compwk[3]<0)                                           //~v5dkI~
        	return -1;                                             //~v5dkI~
        if (compwk[3]>0)                                           //~v5dkI~
        	return  1;                                             //~v5dkI~
        return 0;                                                  //~v5dkI~
    case '*':                                                      //~v5drI~
//  	rc=ucalc_twmult(Popt,opd1id,dwopd1,up1,opd2id,dwopd2,up2); //~v5k2R~
    	rc=ucalc_twmult(Popt,(int)opd1id,dwopd1,up1,(int)opd2id,dwopd2,up2);//~v5k2I~
        if (rc)                                                    //~v5drI~
        	return rc;                                             //~v5drI~
        ovf=0;                                                     //~v5drI~
        break;                                                     //~v5drI~
    case '/':                                                      //~v5dpI~
//  	rc=ucalc_twdiv(dwopd1,up1,dwopd2,up2);                     //~v5dxR~
    	rc=ucalc_twdiv(Popt,dwopd1,up1,dwopd2,up2);                //~v5dxI~
        if (rc)                                                    //~v5dpI~
        	return rc;                                             //~v5dpI~
        ovf=0;                                                     //~v5dpI~
        break;                                                     //~v5dpI~
    case '%':                                                      //~v5dyR~
    	rc=ucalc_twdiv(Popt|CALC_DIVBYRES,dwopd1,up1,dwopd2,up2);  //~v5dyI~
        if (rc)                                                    //~v5dyI~
        	return rc;                                             //~v5dyI~
        ovf=0;                                                     //~v5dyI~
        break;                                                     //~v5dyI~
    default:                                                       //~v5djI~
//      uerrmsg("Dword and decimal point is mutualy exclusive except for \"+\"/\"-\"/\"?\".",//~v5dpR~
//                  "ダブルワードと小数点は\"+\",\"-\",\"?\"のみできます。");//~v5dpR~
      	if (!(Popt & CALC_NOERRMSG))                               //~v5drI~
			return ucalc_dwuperr();                                //~v5drI~
        return 8;                                                  //~v5drR~
    }                                                              //~v5djI~
  if (Pope=='+'||Pope=='-')                                        //~v5drI~
  {                                                                //~v5drI~
    if (ovf<0)                                                     //~v5djI~
    	DWORD_SUB(dwopd1[0],dwopd1[1],0,1);                        //~v5djI~
    else                                                           //~v5djI~
    if (ovf>0)                                                     //~v5djI~
    	DWORD_ADD(dwopd1[0],dwopd1[1],0,1);                        //~v5djI~
    if ((LONG)dwopd1[0]<0)                                         //~v5djR~
    {                                                              //~v5djI~
		if (up1[2]>0)   //dw minus up plus                         //~v5djI~
        {                                                          //~v5djR~
            ucalc_underpoint(0,'-',up1,upc1,&ovf);  //sub 1        //~v5djR~
            DWORD_ADD(dwopd1[0],dwopd1[1],(ULONG)0,(ULONG)1);//add 1//~v5djR~
        }                                                          //~v5djR~
    }                                                              //~v5djI~
    else	//dw plus                                              //~v5djI~
//  if ((LONG)dwopd1[0]>0)  	//dw plus                          //~v5dtR~
    if (dwopd1[0]||dwopd1[1])  	//dw plus                          //~v5dtR~
    {                                                              //~v5djI~
        if (up1[2]<0)   //dw plus, up minus                        //~v5djI~
        {                                                          //~v5djI~
            ucalc_underpoint(0,'+',up1,upc1,&ovf);  //add 1        //~v5djI~
            DWORD_SUB(dwopd1[0],dwopd1[1],(ULONG)0,(ULONG)1); //sub 1//~v5djI~
        }                                                          //~v5djI~
    }                                                              //~v5djI~
  }//"+" or "-"                                                    //~v5drI~
    *Popd1=(LONG)dwopd1[0];                                        //~v5djR~
    *(Popd1+1)=UCALC_DWORDID|up1[1];                               //~v5drR~
    *(Popd1+2)=(LONG)dwopd1[1];                                    //~v5djI~
    *(Popd1+3)=up1[2];                                             //~v5djR~
    return 0;                                                      //~v5djR~
}//bc_twbinop                                                      //~v5djI~
//***************************************************************
//*edit dword value
//parm1:conv type
//parm2:3 word
//parm3:edit out area
//*rc:4:err
//***************************************************************
int bc_edittod(UCHAR *Pout,long *Pvalue)
{
	int opt,len;
    ULONG tod[3];
	UCALC_TIME uct;
//*****************
	if (Pvalue[1]==UCALC_DWORDID)	//dword TOD(host time stamp)
    {
    	opt=LTIME_HOST;         //TOD
        tod[0]=(ULONG)Pvalue[0];
        tod[1]=(ULONG)Pvalue[2];
        tod[2]=0;                                                  //~v50kI~
    }
    else                        //sec from 1970
    {
    	opt=0;                  //TOD
        tod[0]=(ULONG)Pvalue[0];
        tod[1]=0;
    }
	if (ucalc_ltime(opt,tod,&uct))
    {
	  if (Pvalue[1]==UCALC_DWORDID)	//dword TOD(host time stamp)   //~v50gI~
        uerrmsg("TOD conversion failed for %08x..%08x",            //~v50gR~
                "時刻変換できません (%08x..%08x)",                 //~v50gR~
                tod[0],tod[1]);
      else                                                         //~v50gI~
        uerrmsg("TOD conversion failed for %08x",                  //~v50gI~
                "時刻変換できません (%08x)",                       //~v50gR~
                tod[0]);                                           //~v50gI~
        return 4;
    }
    len=sprintf(Pout,"%04d/%02d/%02d-%02d:%02d:%02d",
				uct.year,
				uct.month,
				uct.day,
				uct.hour,
				uct.min,
				uct.sec);
	if (Pvalue[1]==UCALC_DWORDID)	//dword TOD(host time stamp)
		sprintf(Pout+len,".%03d",uct.milsec);
    return 0;
}//bc_edittod
#ifdef INT64SUPP                                                   //~v5k2I~
//***************************************************************  //~v5k2I~
//*edit dword value                                                //~v5k2I~
//parm1:conv type                                                  //~v5k2I~
//parm2:3 word                                                     //~v5k2I~
//parm3:edit out area                                              //~v5k2I~
//*rc:4:err                                                        //~v5k2I~
//***************************************************************  //~v5k2I~
int bc_dweditnum64(int Pfunctype,int Pconvtype,INT64 Pvalue,UCHAR *Pout)//~v5k2I~
{                                                                  //~v5k2I~
    LONG  dweditwk[3];                                             //~v5k2I~
//**********************                                           //~v5k2I~
//  dweditwk[0]=(LONG)(Pvalue>>32);                                //~v5k2R~//~v6xhR~
    dweditwk[0]=(INT4)((UINT64)Pvalue>>32);                        //~v6xhR~
    dweditwk[1]=0;                                                 //~v5k2I~
//  dweditwk[2]=(ULONG)Pvalue;                                     //~v5k2I~//~v6xhR~
    dweditwk[2]=(INT4)Pvalue;                                      //~v6xhR~
    return bc_dweditnum(Pfunctype,Pconvtype,dweditwk,Pout);        //~v5k2I~
}//bc_dweditnum64                                                  //~v5k2I~
#endif                                                             //~v5k2I~
//***************************************************************
//*edit dword value
//parm1:conv type
//parm2:3 word
//parm3:edit out area
//*rc:4:err
//***************************************************************
int bc_dweditnum(int Pfunctype,int Pconvtype,long *Pvalue,UCHAR *Pout)
{
	UCHAR ldwk[32];                                                //~v50gR~
//  ULONG ulwk[2];                                                 //+v6xiR~
    LONG  ulwk[2];                                                 //+v6xiI~
    int len;                                                       //~v56wI~
//*****************
    if (*(Pvalue+1)>UCALC_DWORDID)	//dword+underpoint             //~v5djR~
    	return bc_dwupeditnum(Pfunctype,Pconvtype,Pvalue,Pout);    //~v5djI~
    switch(Pconvtype)
    {
    case 'X':     //convert to HEX value
    	if (Pfunctype=='%')
    		sprintf(Pout,"x%08lX",Pvalue[2]);
        else
        {                                                          //~v56wI~
//  		sprintf(Pout,"x%08lX..%08lX",Pvalue[0],Pvalue[2]);     //~v56wR~
            *Pout='x';                                             //~v56wI~
			len=1+ucalc_editevenhex(Pvalue[0],Pout+1);             //~v56wI~
            sprintf(Pout+len,"..%08lX",Pvalue[2]);                 //~v56wI~
        }                                                          //~v56wI~
    	break;
    case 'O':     //convert to OCT value                           //~v56wI~
    	if (Pfunctype=='%')                                        //~v56wI~
    		sprintf(Pout,"o%lo",Pvalue[2]);                        //~v56wI~
        else                                                       //~v56wI~
    		sprintf(Pout,"o%lo..%011lo",Pvalue[0],Pvalue[2]);      //~v56wR~
    	break;                                                     //~v56wI~
    case 'U':     //convert to DEC value                           //~v50gI~
//      ucalc_dw2ld((ULONG)Pvalue[0],(ULONG)Pvalue[2],Pout);       //+v6xiR~
        ucalc_dw2ld(Pvalue[0],Pvalue[2],Pout);                     //+v6xiI~
    	break;                                                     //~v50gI~
    case 'D':     //convert to DEC value                           //~v50qI~
//      if (Pvalue[0] & HIGHBIT)                                   //~v6xhR~
        if ((UINT4)Pvalue[0] & HIGHBIT)                            //~v6xhI~
        {                                                          //~v50qI~
        	ulwk[0]=0,ulwk[1]=0;                                   //~v50qI~
            DWORD_SUB(ulwk[0],ulwk[1],(ULONG)Pvalue[0],(ULONG)Pvalue[2]);//~v50qR~
        	*Pout='-';                                             //~v50qI~
          	ucalc_dw2ld(ulwk[0],ulwk[1],Pout+1);                   //+v6xiR~
        }                                                          //~v50qI~
        else                                                       //~v50qI~
//        	ucalc_dw2ld((ULONG)Pvalue[0],(ULONG)Pvalue[2],Pout);   //+v6xiR~
          	ucalc_dw2ld(Pvalue[0],Pvalue[2],Pout);                 //+v6xiI~
    	break;                                                     //~v50qI~
    case 'Z':     //convert to DEC value                           //~v50gI~
//      ucalc_dw2ld(Pvalue[0],Pvalue[2],ldwk);                     //~v50rR~
		bc_dweditnum(Pfunctype,'D',Pvalue,ldwk);                   //~v50rR~
        ucalc_ldedit(ldwk,Pout);                                   //~v50gR~
    	break;                                                     //~v50gI~
    case 'Y':     //internal value for unsigned Z                  //~v50rI~
		bc_dweditnum(Pfunctype,'U',Pvalue,ldwk);                   //~v50rR~
        ucalc_ldedit(ldwk,Pout);                                   //~v50rI~
    	break;                                                     //~v50rI~
    case 'L':     //convert TOD                                    //~v50gR~
		bc_edittod(Pout,Pvalue);
    	break;
    default:
    	uerrmsg("Type \"%c\" is not supported for double word output.",//~v50gR~
                "\"%c\" はダブルワード出力ではサポートされてません。",//~v50gR~
				Pconvtype);                                        //~v50gI~
        return 4;
    }
    return 0;
}//bc_dweditnum
//***************************************************************  //~v5djI~
//*edit dword+underpoint value                                     //~v5djI~
//parm4:edit out area                                              //~v5djI~
//*rc:4:err                                                        //~v5djI~
//***************************************************************  //~v5djI~
int bc_dwupeditnum(int Pfunctype,int Pconvtype,long *Pvalue,UCHAR *Pout)//~v5djI~
{                                                                  //~v5djI~
	UCHAR upwk[16];                                                //~v5djI~
    long  up[3],lwk[3];                                            //~v5djI~
    int rc;                                                        //~v5djI~
//*****************                                                //~v5djI~
    lwk[0]=Pvalue[0];	//at first,edit dword only                 //~v5djI~
    lwk[1]=UCALC_DWORDID;                                          //~v5djI~
    lwk[2]=Pvalue[2];                                              //~v5djI~
    switch(Pconvtype)                                              //~v5djI~
    {                                                              //~v5djI~
    case 'U':                                                      //~v5djI~
    case 'D':                                                      //~v5djI~
    case 'Z':                                                      //~v5djI~
    case 'Y':                                                      //~v5djI~
		if (rc=bc_dweditnum(Pfunctype,Pconvtype,lwk,Pout),rc)      //~v5djI~
        	return rc;                                             //~v5djI~
    	break;                                                     //~v5djI~
    case 'X':     //convert to HEX value                           //~v5dyI~
    case 'O':     //convert to HEX value                           //~v5dyI~
    case 'L':     //convert to HEX value                           //~v5dyI~
		return bc_dweditnum(Pfunctype,Pconvtype,lwk,Pout);         //~v5dyI~
    default:                                                       //~v5djI~
    	uerrmsg("Output type \"%c\" is not supported for double with decimal point.",//~v5dyR~
                "出力タイプ\"%c\" は小数点付きダブルワードではサポートされてません。",//~v5dyR~
				Pconvtype);                                        //~v5djI~
        return 4;                                                  //~v5djI~
    }                                                              //~v5djI~
//edit underpoint                                                  //~v5djI~
	up[0]=0;                                                       //~v5djI~
	up[1]=Pvalue[1]-UCALC_DWORDID;                                 //~v5djR~
	up[2]=Pvalue[3];                                               //~v5djR~
    ucalc_editnum(0,upwk,up);                                      //~v5djI~
    if (!lwk[0] && !lwk[2])                                        //~v5djI~
        strcpy(Pout,upwk);                                         //~v5djI~
    else                                                           //~v5djI~
        if (up[2]<0)                                               //~v5djR~
            strcat(Pout,upwk+2);                                   //~v5djR~
        else                                                       //~v5djR~
            strcat(Pout,upwk+1);                                   //~v5djR~
    return 0;                                                      //~v5djI~
}//bc_dwupeditnum                                                  //~v5djI~
//***************************************************************
//*singed dword*word                                               //~v5drR~
//parm1:ptr to dword(in/out)
//parm2:word multiplyer
//*rc:4:overflow
//***************************************************************
//int ucalc_dwmult(ULONG *Ppopd1,ULONG Popd2)                      //~v5drR~
int ucalc_dwmult(LONG *Ppopd1,LONG Popd2)                          //~v5drI~
{
//  ULONG ansl=0,ansh=0,ovfwk,opd1h,opd1l,opd2;                    //~v5drR~
    LONG ansl=0,ansh=0,ovfwk,opd1h,opd1l,opd2;                     //~v5drR~
    int ii,rc=0,ovfsw=0; 
    int minussign=1;                                               //~v5drI~
//*****************
    if (Ppopd1[0]<0)                                               //~v5drI~
    {                                                              //~v5drI~
    	minussign=-minussign;                                      //~v5drI~
		DWORD_MINUS(Ppopd1[0],Ppopd1[1]);                          //~v5drI~
    }                                                              //~v5drI~
    if (Popd2<0)                                                   //~v5drI~
    {                                                              //~v5drI~
    	minussign=-minussign;                                      //~v5drI~
		Popd2=-Popd2;                                              //~v5drI~
    }                                                              //~v5drI~
    opd1h=*Ppopd1;
    opd1l=*(Ppopd1+1);
	opd2=Popd2;
//  for (ii=0;ii<WORDSZ;ii++,opd2>>=1)                             //~v5dyR~
//  for (ii=0;ii<WORDSZ;ii++,opd2=(LONG)((ULONG)opd2>>1))          //~v5dyR~//~v6xhR~
    for (ii=0;ii<WORDSZ;ii++,opd2=(INT4)((UINT4)opd2>>1))          //~v6xhI~
    {
    	if (opd2 & 1)
        {
        	if (ovfsw)                                    
            	rc=4;                                     
        	ovfwk=ansh;
			DWORD_ADD(ansh,ansl,opd1h,opd1l);
            if (ansh<ovfwk)
            	rc=4;
        }
//  	if (opd1h & HIGHBIT)                                       //~v5drR~
    	if (opd1h & SIGNHIGHBIT)                                   //~v5drI~
        	ovfsw=1;                    
    	DWORD_LSHIFT(opd1h,opd1l);	//shift answer
    }
    if (minussign<0)                                               //~v5drI~
		DWORD_MINUS(ansh,ansl);                                    //~v5drI~
    *Ppopd1=ansh;
    *(Ppopd1+1)=ansl;
	return rc;
}//ucalc_dwmult                                                    //~v5drR~
//***************************************************************  //~v5drI~
//*singed dwup*word                                                //~v5drI~
//*rc:4:overflow                                                   //~v5drI~
//***************************************************************  //~v5drI~
int ucalc_twmult(int Popt,int Popd1id,LONG *Pdw1,LONG *Pup1,int Popd2id,LONG *Pdw2,LONG *Pup2)//~v5drR~
{                                                                  //~v5drI~
    LONG dw1[2],dw2[2],up1[3],up2[3];                              //~v5drI~
    LONG dwans[2],upans[4],dwans2[2],dwup[4];                      //~v5drR~
    int opd2id,rc,minussw=1;                                       //~v5drR~
//*****************                                                //~v5drI~
//ab.c*x.y                                                         //~v5drI~
	if (Popd1id>=UCALC_DWORDID)                                    //~v5drI~
    {                                                              //~v5drI~
		if (Popd2id>=UCALC_DWORDID)//word dowrd                    //~v5drI~
        {                                                          //~v5drI~
        	uerrmsg("Dword * dword is not supported",              //~v5drI~
            		"ダブルワード同士の掛け算はできません");       //~v5drI~
            return 4;                                              //~v5drI~
        }                                                          //~v5drI~
        memcpy(dw1,Pdw1,sizeof(dw1));                              //~v5drR~
        memcpy(up1,Pup1,sizeof(up1));                              //~v5drR~
        memcpy(dw2,Pdw2,sizeof(dw2));                              //~v5drR~
        memcpy(up2,Pup2,sizeof(up2));                              //~v5drR~
        opd2id=Popd2id;                                            //~v5drI~
    }                                                              //~v5drI~
    else                                                           //~v5drI~
    {                                                              //~v5drI~
        memcpy(dw1,Pdw2,sizeof(dw1));                              //~v5drR~
        memcpy(up1,Pup2,sizeof(up1));                              //~v5drR~
        memcpy(dw2,Pdw1,sizeof(dw2));                              //~v5drR~
        memcpy(up2,Pup1,sizeof(up2));                              //~v5drR~
        opd2id=Popd1id;                                            //~v5drI~
    }                                                              //~v5drI~
    if (dw1[0]<0)                                                  //~v5drI~
    {                                                              //~v5drI~
        DWORD_MINUS(dw1[0],dw1[1]);                                //~v5drI~
        up1[2]=-up1[2];                                            //~v5drI~
        minussw=-minussw;                                          //~v5drI~
    }                                                              //~v5drI~
    if (dw2[0]<0)                                                  //~v5drI~
    {                                                              //~v5drI~
        DWORD_MINUS(dw2[0],dw2[1]);                                //~v5drI~
        up2[2]=-up2[2];                                            //~v5drI~
        minussw=-minussw;                                          //~v5drI~
    }                                                              //~v5drI~
    memcpy(dwans,dw1,sizeof(dwans));//opd1 dw   ab.                //~v5drR~
    if (rc=ucalc_dwmult(dwans,dw2[1]),rc) // ab*x                  //~v5drR~
//      return rc;                                                 //~v5dyR~
        return ucalcerrdwordovf();                                 //~v5dyI~
    memcpy(upans,up1,sizeof(upans));//opd1 up   .c                 //~v5drM~
    dwup[0]=dw2[1];  //2nd opd word        x                       //~v5drR~
    dwup[1]=0;		//word id                                      //~v5drR~
//  if (rc=ucalc_binop(CALC_SIGNED|CALC_DWORDUP,'*',upans,dwup),rc)//0.c*x//~v5dtR~
    if (rc=ucalc_binop(CALC_DWORDUP,'*',upans,dwup),rc)//0.c*x     //~v5dtI~
        return rc;                                                 //~v5drI~
    DWORD_ADD(dwans[0],dwans[1],0,upans[0]);                       //~v5drM~
    upans[0]=0;                                                    //~v5drI~
    if (opd2id)    //opd2 up                                       //~v5drI~
    {                                                              //~v5drI~
        memcpy(dwans2,dw1,sizeof(dwans2));//opd1 dw   ab           //~v5drR~
        if (rc=ucalc_dwmult(dwans2,up2[2]),rc) //ab*y              //~v5drR~
//          return rc;                                             //~v5dyR~
	        return ucalcerrdwordovf();                             //~v5dyI~
		if (rc=ucalc_dwshiftdown(Popt,dwans2,(int)up2[1],dwup),rc) //ab*0.y//~v5k2R~
        	return rc;                                             //~v5drI~
        DWORD_ADD(dwans[0],dwans[1],dwup[0],dwup[2]);              //~v5drR~
        dwup[0]=0;                                                 //~v5drI~
        dwup[1]&=~UCALC_DWORDID;                                   //~v5drR~
        dwup[2]=dwup[3];                                           //~v5drI~
        if (rc=ucalc_binop(Popt,'*',up1,up2),rc)	//0.c*0.y      //~v5drI~
            return rc;                                             //~v5drI~
        if (rc=ucalc_binop(Popt,'+',upans,up1),rc)                 //~v5drR~
            return rc;                                             //~v5drM~
        if (rc=ucalc_binop(Popt,'+',upans,dwup),rc)                //~v5drI~
            return rc;                                             //~v5drI~
        DWORD_ADD(dwans[0],dwans[1],0,upans[0]);                   //~v5drI~
        upans[0]=0;                                                //~v5drR~
    }                                                              //~v5drI~
    if (minussw<0)                                                 //~v5drI~
    {                                                              //~v5drI~
        DWORD_MINUS(dwans[0],dwans[1]);                            //~v5drI~
        upans[2]=-upans[2];                                        //~v5drI~
    }                                                              //~v5drI~
    memcpy(Pdw1,dwans,sizeof(dwans));//opd1 dw                     //~v5drI~
    memcpy(Pup1,upans,sizeof(upans));//opd1 up                     //~v5drI~
	return 0;                                                      //~v5drI~
}//ucalc_twmult                                                    //~v5drI~
//***************************************************************
//singed calc dowd/word                                            //~v5drR~
//parm1:ptr to dword(in/out) and word(residual)
//parm2:word divider
//*rc:4:0 divide
//***************************************************************
//int ucalc_dwdiv(ULONG *Ppopd1,ULONG Popd2)                       //~v5drR~
int ucalc_dwdiv(LONG *Ppopd1,LONG Popd2)                           //~v5drI~
{
//  ULONG ansl,ansh,opd1h,opd1l,opd2h,opd2l;                       //~v5drR~
    LONG ansl,ansh,opd1h,opd1l,opd2h,opd2l;                        //~v5drI~
    int minussign=1;                                               //~v5drR~
    int ii,opd2sz;
//*****************
    if (!Popd2)
//      return 4;                                                  //~v5dxR~
		return calcerr0div();                                      //~v5dxI~
    if (Ppopd1[0]<0)                                               //~v5drR~
    {                                                              //~v5drI~
    	minussign=-minussign;                                      //~v5drR~
		DWORD_MINUS(Ppopd1[0],Ppopd1[1]);                          //~v5drR~
    }                                                              //~v5drI~
    if (Popd2<0)                                                   //~v5drR~
    {                                                              //~v5drI~
    	minussign=-minussign;                                      //~v5drR~
		Popd2=-Popd2;                                              //~v5drR~
    }                                                              //~v5drI~
    for (opd2sz=WORDSZ,opd2h=Popd2;opd2sz;opd2sz--)
    {
//  	if (opd2h & HIGHBIT)                                       //~v5drR~
    	if (opd2h & SIGNHIGHBIT)                                   //~v5drI~
        	break;
//      opd2h<<=1;                                                 //~v6xhR~
        opd2h=(INT4)opd2h<<1;                                      //~v6xhI~
    }
    opd2l=0;                   //opd2 left shift
    opd1h=*Ppopd1;
    opd1l=*(Ppopd1+1);
    ansh=ansl=0;
    for (ii=WORDSZ+WORDSZ;ii>=opd2sz;ii--)
    {
    	if (DWORD_COMP(opd1h,opd1l,opd2h,opd2l)>=0)
        {
			DWORD_SUB(opd1h,opd1l,opd2h,opd2l);
            ansl|=1;
        }
    	if (ii==opd2sz)
        	break;
    	DWORD_LSHIFT(ansh,ansl);	//shift answer
	    DWORD_RSHIFT(opd2h,opd2l);	//get top opd2sz bits
    }
    if (minussign<0)                                               //~v5drR~
    {                                                              //~v5drI~
		DWORD_MINUS(ansh,ansl);                                    //~v5drI~
        opd1l=-opd1l;                                              //~v5drI~
    }                                                              //~v5drI~
    *Ppopd1=ansh;
    *(Ppopd1+1)=ansl;
    *(Ppopd1+2)=opd1l;
    return 0;
}//ucalc_dwdiv
//***************************************************************  //~v69BI~
//singed calc dowd/dword                                           //~v69BI~
//parm1:ptr to dword(in/out) and word(residual)                    //~v69BI~
//parm2:word divider                                               //~v69BI~
//*rc:4:0 divide,8:residual overflow for "%"                       //~v69BI~
//***************************************************************  //~v69BI~
int ucalc_dwdiv2(int Popt,int Pope,LONG *Ppopd1,LONG *Ppopd2)      //~v69BR~
{                                                                  //~v69BI~
    LONG opd1h,opd1l,opd2h,opd2l,wkdiv[3],wk1[4],wk1o[4],wk2[4],wk2o[4],wk2r[4];//~v69BR~
    int ii,ans,rc=0;                                               //~v69BI~
//*****************                                                //~v69BI~
	bc_dw2numfmt(Popt,wk1o,Ppopd1);                                //~v69BI~
	bc_dw2numfmt(Popt,wk2o,Ppopd2);                                //~v69BI~
	for (opd1h=Ppopd1[0],opd1l=Ppopd1[1],opd2h=Ppopd2[0],opd2l=Ppopd2[1],ii=0;;ii++)//~v69BR~
    {                                                              //~v69BI~
    	if (!opd2h && opd2l>=0)                                    //~v69BI~
        	break;                                                 //~v69BI~
	    DWORD_RSHIFT(opd1h,opd1l);                                 //~v69BI~
	    DWORD_RSHIFT(opd2h,opd2l);                                 //~v69BI~
    }                                                              //~v69BI~
    wkdiv[0]=opd1h;                                                //~v69BI~
    wkdiv[1]=opd1l;                                                //~v69BI~
    for (;;)                                                       //~v69BI~
    {                                                              //~v69BI~
		if (rc=ucalc_dwdiv(wkdiv,opd2l),rc)     //(x1/n)/(x2/n):ansh+ansl+residual//~v69BI~
        	break;                                                 //~v69BI~
		bc_dw2numfmt(Popt,wk2,wkdiv);                              //~v69BI~
        if (bc_dwbinop(Popt,'*',wk2,wk2o))   //(ansh+ansl)*x2      //~v69BR~
            break;                                                 //~v69BI~
        memcpy(wk2r,wk2,sizeof(wk2r));                             //~v69BI~
        ans=0;                                                     //~v69BI~
        rc=bc_dwbinop(Popt,'?',wk1o,wk2);                          //~v69BR~
        if (rc>0)                 //Popd1>wk2                      //~v69BI~
        {                                                          //~v69BI~
            for (;;)                                               //~v69BI~
            {                                                      //~v69BI~
                bc_dwbinop(Popt,'+',wk2,wk2o);                     //~v69BR~
                if (bc_dwbinop(Popt,'?',wk1o,wk2)<0)   //          //~v69BR~
                    break;                                         //~v69BI~
		        memcpy(wk2r,wk2,sizeof(wk2r));                     //~v69BI~
                ans++;                                             //~v69BI~
            }                                                      //~v69BI~
        }                                                          //~v69BI~
        else                                                       //~v69BI~
        if (rc<0)               //Popd1<wk2                        //~v69BI~
        {                                                          //~v69BI~
            for (;;)                                               //~v69BI~
            {                                                      //~v69BI~
                bc_dwbinop(Popt,'-',wk2,wk2o);                     //~v69BR~
                rc=bc_dwbinop(Popt,'?',wk1o,wk2);                  //~v69BR~
                if (rc>=0)                                         //~v69BI~
			        memcpy(wk2r,wk2,sizeof(wk2r));                 //~v69BI~
                if (rc>0)                                          //~v69BI~
	            	break;                                         //~v69BI~
                ans--;                                             //~v69BI~
            }                                                      //~v69BI~
        }                                                          //~v69BI~
        wkdiv[1]+=ans;                                             //~v69BI~
		memcpy(wk1,wk1o,sizeof(wk1));                              //~v69BR~
        bc_dwbinop(Popt,'-',wk1,wk2r);                             //~v69BI~
        if (wk1[0])		//dword residual                           //~v69BR~
        {                                                          //~v69BI~
        	if (Pope=='%')                                         //~v69BI~
            {                                                      //~v69BI~
				ucalc_dw2errresidual(wkdiv,wk1);                   //~v69BR~
        		rc=8;                                              //~v69BI~
	            break;                                             //~v69BR~
            }                                                      //~v69BI~
        }                                                          //~v69BI~
        rc=0;                                                      //~v69BI~
        break;                                                     //~v69BI~
    }//for                                                         //~v69BI~
    *Ppopd1=wkdiv[0];                                              //~v69BI~
    *(Ppopd1+1)=wkdiv[1];                                          //~v69BI~
    *(Ppopd1+2)=wk1[2];                                            //~v69BI~
    return rc;                                                     //~v69BI~
//  		return ucalc_dw2err(Pope);                             //~v69BI~
}//ucalc_dwdiv2                                                    //~v69BI~
//***************************************************************  //~v5dpI~
//calc dowd+point/word                                             //~v5dpI~
//parm1:dowrd                                                      //~v5dpI~
//parm2:underpoint                                                 //~v5dpI~
//*rc:4:0 divide                                                   //~v5dpI~
//***************************************************************  //~v5dpI~
//int ucalc_twdiv(ULONG *Pdw1,LONG *Pup1,ULONG *Pdw2,LONG *Pup2)   //~v5drR~
//int ucalc_twdiv(LONG *Pdw1,LONG *Pup1,LONG *Pdw2,LONG *Pup2)     //~v5dxR~
int ucalc_twdiv(int Popt,LONG *Pdw1,LONG *Pup1,LONG *Pdw2,LONG *Pup2)//~v5dxI~
{                                                                  //~v5dpI~
    LONG dw3[3];                                                   //~v5drR~
    LONG  up3[3];                                                  //~v5dpR~
    int rc;                                                        //~v5dpI~
//*****************                                                //~v5dpI~
//  if (Pdw2[0] || Pup2[1])	//divider is not word                  //~v5dxR~
//  	return ucalc_dwuperr();                                    //~v5dxI~
    if (Pdw2[0])           	//divider is dword                     //~v5dxI~
		return ucalc_dw2err('/');                                  //~v5dxI~
    if (Pup2[1])	//divider is up                                //~v5dxI~
        return ucalc_twdivbyup(Popt,Pdw1,Pup1,Pdw2[1],Pup2);       //~v5dxR~
    dw3[0]=Pdw1[0]; dw3[1]=Pdw1[1];                                //~v5dpI~
    rc=ucalc_dwdiv(dw3,Pdw2[1]);                                   //~v5dpI~
    if (rc)                                                        //~v5dpI~
    	return rc;                                                 //~v5dpI~
  if (Popt&CALC_DIVBYRES)	// % operation                         //~v5dyI~
  {                                                                //~v5dyI~
  	Pdw1[0]=0;                                                     //~v5dyI~
  	Pdw1[1]=dw3[2];                                                //~v5dyI~
  }//residual calc                                                 //~v5dyI~
  else                                                             //~v5dyI~
  {                                                                //~v5dyI~
    Pdw1[0]=dw3[0];   //divided                                    //~v5dpI~
    Pdw1[1]=dw3[1];                                                //~v5dpI~
    Pup1[0]+=dw3[2];		//divide residual                      //~v5dpI~
    up3[0]=Pdw2[1]; up3[1]=0; up3[2]=0;                            //~v5dpR~
//  rc=ucalc_binop(0,'/',Pup1,up3);                                //~v5dxR~
    rc=ucalc_binop(Popt,'/',Pup1,up3);                             //~v5dxI~
    if (rc)                                                        //~v5dpI~
    	return rc;                                                 //~v5dpI~
  }//divide                                                        //~v5dyI~
    return 0;                                                      //~v5dpI~
}//ucalc_dwdiv                                                     //~v5dpI~
//***************************************************************  //~v5dxI~
//calc dowd+point/point                                            //~v5dxI~
//parm1:dword[2]                                                   //~v5dxI~
//parm2:up[3]                                                      //~v5dxI~
//*rc:4:0 divide                                                   //~v5dxI~
//***************************************************************  //~v5dxI~
int ucalc_twdivbyup(int Popt,LONG *Pdw1,LONG *Pup1,LONG Pw2,LONG *Pup2)//~v5dxR~
{                                                                  //~v5dxI~
    int dn2,rc;                                                    //~v5dxI~
	LONG up2[3];                                                   //~v5dxI~
    LONG dwwk2[2];                                                 //~v5dxI~
//*****************                                                //~v5dxI~
//shift up c.d-->cd --->dwwk     1.2/3.45;   dwwk=3.45*100         //~v5dxI~
//	dn2=Pup2[1];                                                   //~v5dxR~//~v6xiR~
  	dn2=(int)Pup2[1];                                              //~v6xiI~
    dwwk2[0]=0;          //dw high                                 //~v5dxI~
    dwwk2[1]=Pw2;		//dw low                                   //~v5dxI~
    memcpy(up2,Pup2,sizeof(up2));                                  //~v5dxI~
    rc=ucalc_twshiftup(dwwk2,up2,dn2);                             //~v5dxI~
    if (rc)                                                        //~v5dxI~
    	return rc;                                                 //~v5dxI~
    up2[1]=0;		//no more underpint                            //~v5dxI~
    rc=ucalc_twshiftup(Pdw1,Pup1,dn2);                             //~v5dyR~
    if (rc)                                                        //~v5dxI~
    	return rc;                                                 //~v5dxI~
	rc=ucalc_twdiv(Popt,Pdw1,Pup1,dwwk2,up2);                      //~v5dyR~
    if (rc)                                                        //~v5dyI~
    	return rc;                                                 //~v5dyI~
	if (Popt&CALC_DIVBYRES)	// % operation                         //~v5dyI~
  	{                                                              //~v5dyI~
    	Pup1[0]=Pdw1[1];		//upper point value                //~v5dyI~
        ucalc_shiftdown(Popt,Pup1,dn2);                            //~v5dyI~
    	Pdw1[1]=Pup1[0];		//upper point value                //~v5dyI~
        Pup1[0]=0;				//                                 //~v5dyI~
    }                                                              //~v5dyI~
    return 0;                                                      //~v5dyI~
}//ucalc_twdivbyup                                                 //~v5dxI~
//**************************************************               //~v5dxI~
//*shift up dword up                                               //~v5dxI~
//parm1:dword[2]                                                   //~v5dxI~
//parm2:up[3]                                                      //~v5dxI~
//parm3:shift count                                                //~v5dxI~
//rc: 4:ovf                                                        //~v5dxI~
//**************************************************               //~v5dxI~
int ucalc_twshiftup(LONG *Pdw,LONG *Pup,int Pshift)                //~v5dxI~
{                                                                  //~v5dxI~
    int rc;                                                        //~v5dxI~
	LONG base10[4];                                                //~v5dxR~
//***********************                                          //~v5dxI~
	base10[0]=bc_getbase(Pshift);                                  //~v5dxR~
	base10[1]=0;            //word id                              //~v5dxI~
    rc=ucalc_dwmult(Pdw,base10[0]);    //dword shift               //~v5dxR~
    if (rc)	                                                       //~v5dxI~
        return ucalcerrdwordovf();                                 //~v5dxI~
    rc=ucalc_binopsub(0,'*',Pup,base10);	//up shift             //~v5dxI~
    if (rc)                                                        //~v5dxI~
        return ucalcerrdwordovf();                                 //~v5dxI~
    DWORD_ADD(Pdw[0],Pdw[1],0,Pup[0]);		//shift up from under point//~v5dxI~
	Pup[0]=0;			//up data only                             //~v5dxI~
    return 0;                                                      //~v5dxI~
}//ucalc_twshiftup                                                 //~v5dxI~
//**************************************************               //~v5drI~
//*shift down dword up to max underpoint digit;dwup fmt            //~v5drR~
//parm1:2 word dword value                                         //~v5drI~
//parm2:shift count                                                //~v5drI~
//parm3:4 word numfmt data                                         //~v5drI~
//rc: 4:ovf                                                        //~v5drI~
//**************************************************               //~v5drI~
int ucalc_dwshiftdown(int Popt,LONG *Pupdata,int Pshift,LONG *Pnumfmt)//~v5drR~
{                                                                  //~v5drI~
	int ii,rc;                                                     //~v5drI~
    LONG div10=1,dwdivwk[4];                                       //~v5dyR~
//***********************                                          //~v5drI~
    if (Pshift>MAX_POINT_NUM)                                      //~v5drI~
        return 16;                                                 //~v5drI~
    for (ii=0;ii<Pshift;ii++)                                      //~v5drR~
        div10*=10;                                                 //~v5drR~
    dwdivwk[0]=Pupdata[0];                                         //~v5drI~
    dwdivwk[1]=Pupdata[1];                                         //~v5drI~
    if (rc=ucalc_dwdiv(dwdivwk,div10),rc)    //ans(2) and residual(1)//~v5drI~
        return rc;                                                 //~v5drI~
    Pnumfmt[0]=dwdivwk[0];                                         //~v5drI~
    Pnumfmt[2]=dwdivwk[1];                                         //~v5drI~
    Pnumfmt[3]=dwdivwk[2];	//residual                             //~v5drR~
    if (Pnumfmt[3])                                                //~v5drR~
    	Pnumfmt[1]=UCALC_DWORDID+Pshift;                           //~v5drR~
    else                                                           //~v5drI~
    	Pnumfmt[1]=UCALC_DWORDID;                                  //~v5drI~
    return 0;                                                      //~v5drI~
}//ucalc_dwshiftdown                                               //~v5drI~
//***************************************************************
//convert sec to time
//parm1:type(PC/UNIX/IBM HOST)
//parm2:PC/UNIX(2word):WORD sec from 1970/01/01 00:00:00 and milisec
//      HOST   (3word):DWORD sec from 1900/01/01 00:00:00 and tzone(sec)//~v50kR~
//parm3:ptr to struct tm
//*rc:4:time type err,8:pc time is invalid value                   //~v50gR~
//***************************************************************
int ucalc_ltime(int Ptmtype,ULONG *Ptime,PUCALC_TIME Ppuct)
#define LTIME_PC      1
#define LTIME_UNIX    2
#define LTIME_HOST    3
{
static ULONG Stod0[2]={0xb361183f,0x48000000};		//Host TOD at 2000/01/01//~v50kR~
    struct timeb tmb;
    struct tm   *ptm;
//  ULONG  todh,todl,todwk[3],inminute,days;                       //+v6xiR~
    LONG  todh,todl,todwk[3],inminute,days;                        //+v6xiI~
    int ii,date[3],intvlsw;                                        //~v50kR~
//*****************
	switch(Ptmtype)
    {
    case 0:			//compiler native
    case LTIME_PC:			//PC
    case LTIME_UNIX:			//PC
    	if (*Ptime)			//request current
        {
        	tmb.time=(time_t)*Ptime;
        	Ppuct->milsec=(int)*(Ptime+1);
        }
    	else
        {
        	ftime(&tmb);
        	Ppuct->milsec=(int)tmb.millitm;
        }
//printf("cur time=%08x milsec=%03d\n",(ULONG)tmb.time,tmb.millitm);//~v50gR~
        ptm=localtime(&tmb.time);                                  //~v50kI~
        if (!ptm)	//before 1980                                  //~v50gI~
        {                                                          //~v50gI~
        	uerrmsg("Invalid time value",                          //~v50gI~
					"時間値が範囲外です");                         //~v50gR~
        	return 8;                                              //~v50gI~
        }                                                          //~v50gI~
        Ppuct->year  =ptm->tm_year+1900;                           //~v50kI~
        Ppuct->month =ptm->tm_mon+1;                               //~v50kI~
        Ppuct->day   =ptm->tm_mday;                                //~v50kI~
        Ppuct->hour  =ptm->tm_hour;                                //~v50kI~
        Ppuct->min   =ptm->tm_min;                                 //~v50kI~
        Ppuct->sec   =ptm->tm_sec;                                 //~v50kI~
        break;
    case LTIME_HOST:			//PC
//    	todh=*Ptime;                                               //+v6xiR~
      	todh=(LONG)*Ptime;                                         //+v6xiI~
//    	todl=*(Ptime+1);                                           //+v6xiR~
    	todl=(LONG)*(Ptime+1);                                     //+v6xiI~
        if (DWORD_COMP(todh,todl,Stod0[0],Stod0[1])>=0)            //~v50kI~
        {                                                          //~v50kI~
        	intvlsw=0;                                             //~v50kI~
	        DWORD_SUB(todh,todl,Stod0[0],Stod0[1]);	//else calc interval//~v50kR~
        }                                                          //~v50kI~
        else                                                       //~v50kI~
        	intvlsw=1;                                             //~v50kI~
        for (ii=0;ii<12;ii++)
        	DWORD_RSHIFT(todh,todl);	//micro sec unit
       todwk[0]=todh;                                              //+v6xiR~
       todwk[1]=todl;                                              //+v6xiR~
//  	ucalc_dwdiv(todwk,60000000);     //dword and residual word //~v5dyR~
//    	ucalc_dwdiv((LONG*)(LONG)todwk,60000000);     //dword and residual word//~v5dyI~//~v6hhR~
     	ucalc_dwdiv((LONG*)(ULPTR)todwk,60000000);     //dword and residual word//~v6hhI~
        inminute=todwk[2];				//residual                 //~v50kI~
//  	ucalc_dwdiv(todwk,60);     //hours                         //~v5dyR~
//    	ucalc_dwdiv((LONG*)(LONG)todwk,60);     //hours                  //~v5dyI~//~v6hhR~
    	ucalc_dwdiv((LONG*)(ULPTR)todwk,60);     //hours           //~v6hhI~
        Ppuct->min   =(int)todwk[2];    //residual                 //~v50kI~
		DWORD_ADD(todwk[0],todwk[1],0,Ptime[2]);   //ajust by tz   //~v50kI~
//  	ucalc_dwdiv(todwk,24);     //days                          //~v5dyR~
//    	ucalc_dwdiv((LONG*)(LONG)todwk,24);     //days                   //~v5dyI~//~v6hhR~
    	ucalc_dwdiv((LONG*)(ULPTR)todwk,24);     //days            //~v6hhI~
        Ppuct->hour  =(int)todwk[2]; //add tz hours                //~v50kR~
        days         =todwk[1];                                    //~v50kI~
		inminute/=1000;				//milisec                      //~v50kI~
        Ppuct->milsec=(int)(inminute%1000);      //milisec           //~v50kI~
        Ppuct->sec   =(int)(inminute/1000);      //milisec           //~v50kI~
        if (intvlsw)                                               //~v50kI~
        {                                                          //~v50kI~
        	Ppuct->year  =0;                                       //~v50kI~
        	Ppuct->month =0;                                       //~v50kI~
        	Ppuct->day   =(int)days;                               //~v50kI~
        }                                                          //~v50kI~
        else                                                       //~v50kI~
        {                                                          //~v50kI~
			ucalc_getdate((int)days,(int *)date);                  //~v50kR~
        	Ppuct->year  =date[0];                          //~v50kR~
        	Ppuct->month =date[1];                          //~v50kR~
        	Ppuct->day   =date[2];                          //~v50kR~
        }                                                          //~v50kI~
        break;
    default:
    	return 4;
    }
    return 0;
}//ucalc_ltime
//***************************************************************  //~v50kI~
//date calc from 2000/01/01                                        //~v50kI~
//parm1:days                                                       //~v50kI~
//parm2:output 3 word(yyyy,mm,dd)                                  //~v50kI~
//*rc:4:minus days                                                 //~v50kI~
//***************************************************************  //~v50kI~
int ucalc_getdate(int Pdays,int *Pdate)                            //~v50kI~
{                                                                  //~v50kI~
	int ii,leap,mday;                                              //~v50kR~
//*******************************                                  //~v50kI~
	if (Pdays<0)                                                   //~v50kI~
    	return 4;                                                  //~v50kI~
    for (ii=0,leap=0;;ii++)                                        //~v50kI~
    {                                                              //~v50kI~
        leap=((!(ii%4) && (ii%100))||!(ii%1000));                  //~v50kR~
//printf("yy=%4d,leap=%d,Pdays=%d\n",ii+2000,leap,Pdays);          //~v50kR~
        if (Pdays<(365+leap))                                      //~v50kI~
            break;                                                 //~v50kI~
        Pdays-=365+leap;                                           //~v50kI~
    }                                                              //~v50kI~
    Pdate[0]=ii+2000;		//year                                 //~v50kI~
    for (ii=0;ii<12;ii++)                                          //~v50kI~
    {                                                              //~v50kI~
        mday=Smday[ii]+(ii==1 && leap);                            //~v50kI~
        if (Pdays<mday)                                            //~v50kI~
        	break;                                                 //~v50kI~
        Pdays-=mday;                                               //~v50kI~
    }                                                              //~v50kI~
    Pdate[1]=ii+1;			//month                                //~v50kI~
    Pdate[2]=Pdays+1;		//day of month                         //~v50kI~
    return 0;                                                      //~v50kI~
}//ucalc_getdate                                                   //~v50kI~
//***************************************************************  //~v59sI~
//date calc ;nextday                                               //~v59sI~
//parm1:days                                                       //~v59sI~
//parm2:output 3 word(yyyy,mm,dd)                                  //~v59sI~
//*rc:4:minus days                                                 //~v59sI~
//***************************************************************  //~v59sI~
int ucalc_nextday(int Pdiff,int *Ppyear,int *Ppmonth,int *Ppday)   //~v5agR~
{                                                                  //~v59sI~
	int leap,yy,mm,dd,maxdd;                                       //~v59sR~
//*******************************                                  //~v59sI~
	yy=*Ppyear;                                                    //~v59sI~
	mm=*Ppmonth;                                                   //~v59sI~
//  dd=*Ppday+1;//next day                                         //~v5agR~
    dd=*Ppday+Pdiff;//tomorrow or yestaday                         //~v5agI~
  if (!dd)  //back manth                                           //~v5agI~
  {                                                                //~v5agI~
    	mm--;                                                      //~v5agI~
        if (mm)                                                    //~v5agI~
        {                                                          //~v5agI~
            dd=Smday[mm-1];                                        //~v5agI~
            if (mm==2)                                             //~v5agI~
    			dd+=((!(yy%4) && (yy%100))||!(yy%1000));           //~v5agI~
        }                                                          //~v5agI~
        else                                                       //~v5agI~
        {                                                          //~v5agI~
        	yy--;                                                  //~v5agI~
            mm=12;                                                 //~v5agI~
            dd=31;                                                 //~v5agI~
        }                                                          //~v5agI~
  }//yesterday                                                     //~v5agI~
  else                                                             //~v5agI~
  {                                                                //~v5agI~
    maxdd=Smday[mm-1];	//next month                               //~v59sI~
    leap=((!(yy%4) && (yy%100))||!(yy%1000));                      //~v59sI~
    if (mm==2 && leap)                                             //~v59sI~
    	maxdd++;	                                               //~v59sI~
    if (dd>maxdd)	//next month                                   //~v59sI~
    {                                                              //~v59sI~
    	dd-=maxdd;                                                 //~v59sI~
        mm++;                                                      //~v59sI~
        if (mm>12)                                                 //~v59sI~
        {                                                          //~v59sI~
        	mm=1;                                                  //~v59sI~
            yy++;                                                  //~v59sI~
        }                                                          //~v59sI~
    }                                                              //~v59sI~
  }//tomorrow                                                      //~v5agI~
	*Ppyear=yy;                                                    //~v59sI~
	*Ppmonth=mm;                                                   //~v59sR~
	*Ppday=dd;                                                     //~v59sI~
    return 0;                                                      //~v59sI~
}//ucalc_nextday                                                   //~v59sI~
//***************************************************************  //~v50gI~
//convert long decimal signed dword                                //~v5drR~
//      max 2**63=+-9,223,372,036,854,775,808                      //~v5drR~
//parm1:string                                                     //~v50gI~
//parm2:ULONG[2]                                                   //~v50gI~
//*rc:0:valid word,1:decimal point word data,                      //~v5drR~
//    2:dword underpoint,3:dword                                   //~v5drI~
//    4:too long decimal,8:numeric err                             //~v5drI~
//***************************************************************  //~v50gI~
//int ucalc_ld2dw(char *Pdecs,ULONG *Pdword)                       //~v5drR~
int ucalc_ld2dw(char *Pdecs,LONG *Pdword)                          //~v5drI~
{                                                                  //~v50gI~
	int len;                                                       //~v50gR~
    int digitsw,lastch=0;                                          //~v57HR~
    int digitctr=0;                                                //~v57HR~
    int rc=0;                                                      //~v5djI~
    int minussw=0;                                                 //~v5drI~
    UCHAR *pc,*pc0,*pcw,wknumstr[16],dropsep[32];                  //~v50gR~
//  ULONG  wkulh,wkulm,wkull,dwwk[2],dwwk2[2];                     //~v5drR~
    LONG  wkulh,wkulm,wkull,dwwk[2],dwwk2[2];                      //~v5drI~
//*****************                                                //~v50gI~
//drop seperator,numeric chk                                       //~v50gI~
    if (!*Pdecs)                                                   //~v50gI~
        return 8;       //null                                     //~v50gI~
	for (pc=Pdecs,pcw=dropsep,digitsw=0,pc0=pcw,len=0;*pc && len<sizeof(dropsep)-1;pc++)//~v50gR~
    {                                                              //~v50gI~
    	lastch=*pc;                                                //~v57HI~
    	if (*pc=='-')                                              //~v5drI~
        {                                                          //~v5drI~
            if (digitctr)                                          //~v5drI~
            	return 8;                                          //~v5drI~
            minussw=-1;                                            //~v5drI~
        	continue;                                              //~v5drI~
        }                                                          //~v5drI~
    	if (*pc==',')                                              //~v50gI~
        {                                                          //~v57HR~
            if (!digitctr)                                         //~v57HR~
            	return 8;                                          //~v57HR~
        	continue;                                              //~v50gI~
        }                                                          //~v57HR~
    	if (*pc=='.')   //decimal point                            //~v50mI~
        {                                                          //~v57HR~
            if (!digitctr)                                         //~v57HR~
            	return 8;                                          //~v57HR~
        	break;                                                 //~v50mI~
        }                                                          //~v57HR~
        if (*pc<'0'||*pc>'9')                                      //~v50gI~
            return 8;                                              //~v50gI~
        digitctr++;                                                //~v57HR~
        if (!digitsw)	//no effective digit                       //~v50gR~
        {                                                          //~v50gI~
            pc0=pcw;                                               //~v50gM~
        	if (*pc=='0')                                          //~v50gI~
            	continue;                                          //~v50gI~
            digitsw=1;                                             //~v50gI~
        }                                                          //~v50gI~
        *pcw++=*pc;                                                //~v50gR~
        len++;                                                     //~v50gI~
    }                                                              //~v50gI~
    if (lastch==',')                                               //~v57HI~
    	return 8;                                                  //~v57HI~
    *pcw=0;                                                        //~v50gR~
//max chk                                                          //~v50gI~
//  if (len>Sp2tbl[DWORDSZ].numstrlen) //>20                       //~v5drR~
//      return 4; 						//huge number              //~v5drI~
    if (len>Sp2tbl[DWORDSZSIGN].numstrlen) //>20                   //~v5drI~
        return ucalc_dwmaxerr();                                   //~v5drR~
//  if (len==Sp2tbl[DWORDSZ].numstrlen)  //=20                     //~v5drR~
    if (len==Sp2tbl[DWORDSZSIGN].numstrlen)  //=20                 //~v5drI~
//  	if (strcmp(pc0,Sp2tbl[DWORDSZ].numstr)>=0)                 //~v5drR~
//      	return 4; 						//huge number          //~v5drI~
    	if (strcmp(pc0,Sp2tbl[DWORDSZSIGN].numstr)>=0)             //~v5drI~
	        return ucalc_dwmaxerr();                               //~v5drI~
//word value chk                                                   //~v50gI~
//  if (len<Sp2tbl[WORDSZ].numstrlen		//in the word value    //~v5drR~
//  ||  (len==Sp2tbl[WORDSZ].numstrlen                             //~v5drR~
//    && strcmp(pc0,Sp2tbl[WORDSZ].numstr)<0))                     //~v5drR~
    if (len<Sp2tbl[WORDSZSIGN].numstrlen		//in the word value//~v5drI~
    ||  (len==Sp2tbl[WORDSZSIGN].numstrlen                         //~v5drI~
      && strcmp(pc0,Sp2tbl[WORDSZSIGN].numstr)<0))                 //~v5drI~
    {                                                              //~v50gI~
      if (minussw)                                                 //~v5drI~
      {                                                            //~v5drI~
//  	Pdword[0]=ULMINUS;                                         //~v5dyR~
    	Pdword[0]=-1;                                              //~v5dyI~
        Pdword[1]=-atol(pc0);                                      //~v5drI~
      }                                                            //~v5drI~
      else                                                         //~v5drI~
      {                                                            //~v5drI~
    	Pdword[0]=0;                                               //~v50gI~
        Pdword[1]=atol(pc0);                                //~v50gI~
      }                                                            //~v5drI~
        if (*pc=='.')                                              //~v50mI~
        {                                                          //~v5e4I~
          if (minussw)                                             //~v5e4I~
            return -1;          //deicmal point minus              //~v5e4I~
          else                                                     //~v5e4I~
            return 1;           //deicmal point                    //~v50mI~
        }                                                          //~v5e4I~
        return 0;                                                  //~v50gI~
    }                                                              //~v50gI~
    if (*pc=='.')                                                  //~v50mI~
//      return 4;           //deicmal point                        //~v5djR~
        rc=2;               //dword deicmal point                  //~v5djI~
    else                                                           //~v5drI~
    	rc=3;				//dword                                //~v5drI~
//conv to dword                                                    //~v50gI~
	wkull=atol(pc0+len-9);	//conv last 9 digit            //~v50gI~
    len-=9;                                                        //~v50gI~
    memcpy(wknumstr,pc0,(UINT)len);	//top residual digit           //~v50gI~
    *(wknumstr+len)=0;				//top residual digit           //~v50gI~
    if (len>9)                                                     //~v50gI~
    {                                                              //~v50gI~
		wkulm=atol(wknumstr+len-9);	//conv middle 9 digit  //~v50gI~
    	len-=9;                                                    //~v50gI~
    }                                                              //~v50gI~
    else                                                           //~v50gI~
    {                                                              //~v50gI~
		wkulm=atol(wknumstr);	//conv all residual digit  //~v50gI~
        len=0;                                                     //~v50gI~
    }                                                              //~v50gI~
    dwwk[0]=0;                                                     //~v50gI~
    dwwk[1]=wkulm;                                                 //~v50gI~
	ucalc_dwmult(dwwk,1000000000);		//shift middle 9 digit     //~v50gI~
	DWORD_ADD(dwwk[0],dwwk[1],0,wkull);	//by last 18 digit         //~v50gI~
    if (len)		//over 18 digit                                //~v50gI~
    {                                                              //~v50gI~
		*(wknumstr+len)=0;		//drop last 18 digit               //~v50gI~
		wkulh=atol(wknumstr);	//conv top 2 digit         //~v50gI~
	    dwwk2[0]=(LONG)S10power18[0];                                    //~v50gI~
	    dwwk2[1]=(LONG)S10power18[1];                                    //~v50gI~
		ucalc_dwmult(dwwk2,wkulh);		//shift middle 9 digit     //~v50gI~
		DWORD_ADD(dwwk[0],dwwk[1],dwwk2[0],dwwk2[1]);              //~v50gI~
    }                                                              //~v50gI~
//answer                                                           //~v50gI~
  if (minussw)                                                     //~v5drI~
  {                                                                //~v5drI~
	dwwk2[0]=0;                                                    //~v5drI~
	dwwk2[1]=0;                                                    //~v5drI~
	DWORD_SUB(dwwk2[0],dwwk2[1],dwwk[0],dwwk[1]);                  //~v5drI~
	Pdword[0]=dwwk2[0];                                            //~v5drI~
	Pdword[1]=dwwk2[1];                                            //~v5drI~
  }                                                                //~v5drI~
  else                                                             //~v5drI~
  {                                                                //~v5drI~
	Pdword[0]=dwwk[0];                                             //~v50gI~
	Pdword[1]=dwwk[1];                                             //~v50gI~
  }                                                                //~v5drI~
//  return 0;                                                      //~v5djR~
    return rc;                                                     //~v5djI~
}//ucalc_ld2dw                                                     //~v50gI~
//***************************************************************  //~v50gI~
//convert unsigned dword to long decimal digit                     //~v50gI~
//parm1:ULONG[2]                                                   //~v50gI~
//parm2:string                                                     //~v50gI~
//*rc:0;                                                           //~v50gI~
//***************************************************************  //~v50gI~
//int ucalc_dw2ld(ULONG Pdwh,ULONG Pdwl,char *Pnumstr)             //+v6xiR~
int ucalc_dw2ld(LONG Pdwh,LONG Pdwl,char *Pnumstr)                 //+v6xiI~
{                                                                  //~v50gI~
	int ii;                                                        //~v50gI~
    UCHAR  wknumstr[32]="";                                        //~v5dyR~
//*****************                                                //~v50gI~
    if (!Pdwh)                                                     //~v50gR~
    {                                                              //~v50gI~
    	sprintf(Pnumstr,"%lu",Pdwl);                               //~v50gR~
        return 0;                                                  //~v50gI~
	}                                                              //~v50gI~
	for (ii=0;ii<DWORDSZ;ii++)                                     //~v50gI~
    {                                                              //~v50gI~
        if (Pdwl & 1)                                              //~v50gR~
            ucalc_nsadd(wknumstr,Sp2tbl[ii].numstr);               //~v50gR~
        DWORD_RSHIFT(Pdwh,Pdwl);                                   //~v50gR~
    }                                                              //~v50gI~
    strcpy(Pnumstr,wknumstr);                                      //~v50gI~
    return 0;                                                      //~v50gI~
}//ucalc_dw2ld                                                     //~v50gI~
//***************************************************************  //~v50gI~
//convert unsigned dword to long decimal digit                     //~v50gI~
//parm1:ULONG[2]                                                   //~v50gI~
//parm2:string                                                     //~v50gI~
//*rc:0;1:overflow,4:strlen err,8:numeric err                      //~v50gI~
//***************************************************************  //~v50gI~
int ucalc_nsadd(char *Pnumstr1,char *Pnumstr2)                     //~v50gI~
{                                                                  //~v50gI~
#define MAXNSLEN  20	                                           //~v50gI~
	int ii,len1,len2,len,temp,ovf;                                 //~v50gR~
    UCHAR  wkns1[MAXNSLEN],wkns2[MAXNSLEN],wkns3[MAXNSLEN+1];      //~v50gI~
    UCHAR  *pc1,*pc2,*pc3;                                         //~v50gR~
//*****************                                                //~v50gI~
	len1=(int)strlen(Pnumstr1);                                    //~v50gR~
	len2=(int)strlen(Pnumstr2);                                    //~v50gR~
    len=max(len1,len2);                                            //~v50gI~
    if (len>MAXNSLEN)                                              //~v50gI~
        return 4;                                                  //~v50gI~
    memset(wkns1,'0',MAXNSLEN);                                    //~v50gR~
    memset(wkns2,'0',MAXNSLEN);                                    //~v50gR~
    *(wkns3+MAXNSLEN)=0;                                           //~v50gR~
    memcpy(wkns1+MAXNSLEN-len1,Pnumstr1,(UINT)len1);              //~v50gI~
    memcpy(wkns2+MAXNSLEN-len2,Pnumstr2,(UINT)len2);              //~v50gR~
    pc1=wkns1+MAXNSLEN-1;                                          //~v50gI~
    pc2=wkns2+MAXNSLEN-1;                                          //~v50gI~
    pc3=wkns3+MAXNSLEN-1;                                          //~v50gI~
    for (ii=0,ovf=0;ii<len;ii++,pc1--,pc2--,pc3--)                 //~v50gI~
    {                                                              //~v50gI~
    	if (*pc1<'0'||*pc1>'9')                                    //~v50gI~
        	return 8;                                              //~v50gI~
    	if (*pc2<'0'||*pc2>'9')                                    //~v50gI~
        	return 8;                                              //~v50gI~
    	temp=(*pc1-'0')+(*pc2-'0')+ovf;                            //~v50gI~
        if (temp>=10)                                              //~v50gR~
        {                                                          //~v50gI~
        	ovf=1;                                                 //~v50gI~
            *pc3=(UCHAR)(temp-10+'0');                                      //~v50gI~
        }                                                          //~v50gI~
        else                                                       //~v50gI~
        {                                                          //~v50gI~
        	ovf=0;                                                 //~v50gI~
            *pc3=(UCHAR)(temp+'0');                                         //~v50gI~
        }                                                          //~v50gI~
    }                                                              //~v50gI~
    if (ovf)                                                       //~v50gI~
    {                                                              //~v50gI~
    	if (len==MAXNSLEN)                                         //~v50gI~
        	return 1; 		//overflow                             //~v50gI~
        *pc3='1';                                                  //~v50gI~
    }                                                              //~v50gI~
    else                                                           //~v50gI~
    	pc3++;		//last digit                                   //~v50gI~
    strcpy(Pnumstr1,pc3);                                          //~v50gR~
    return 0;                                                      //~v50gI~
}//ucalc_nsadd                                                     //~v5djR~
//***************************************************************  //~v50gI~
//insert seperator ',' to digit string                             //~v50gI~
//parm1:digit string                                               //~v50gI~
//parm2:output area                                                //~v50gI~
//*rc:0;                                                           //~v50gI~
//***************************************************************  //~v50gI~
int ucalc_ldedit(UCHAR *Pnumstr,UCHAR *Pnumedit)                   //~v50gI~
{                                                                  //~v50gI~
	int len,seplen;                                                //~v50gI~
    UCHAR *pci,*pco;                                               //~v50gI~
//*****************                                                //~v50gI~
	len=(int)strlen(Pnumstr);                                      //~v50gI~
    if (*Pnumstr=='-')  //minus                                    //~v50rI~
    {                                                              //~v50rI~
        len--,Pnumstr++;                                           //~v50rI~
        *Pnumedit++='-';                                           //~v50rI~
    }                                                              //~v50rI~
	if (!(seplen=len%3))		//top group digit count            //~v50gR~
    	seplen=3;                                                  //~v50gI~
    for (pci=Pnumstr,pco=Pnumedit;;)                               //~v50gI~
    {                                                              //~v50gI~
    	memcpy(pco,pci,(UINT)seplen);                              //~v50gR~
        pci+=seplen;                                               //~v50gR~
        pco+=seplen;                                               //~v50gR~
        if ((len-=seplen)<=0)                                      //~v50gI~
        	break;                                                 //~v50gI~
        *pco++=',';                                                //~v50gR~
        seplen=3;                                                  //~v50gI~
    }                                                              //~v50gI~
    *pco=0;                                                        //~v50gI~
    return 0;                                                      //~v50gI~
}//ucalc_ldedit                                                    //~v5djR~
//***************************************************************  //~v5djI~
//0 clear dword underpoint data                                    //~v5djR~
//*rc:4                                                            //~v5djI~
//***************************************************************  //~v5djI~
void ucalc_dwupinit(long *Pdwup)                                   //~v5djI~
{                                                                  //~v5djI~
	Pdwup[0]=0;	//dw high                                          //~v5djR~
	Pdwup[1]=UCALC_DWORDID+1;	//dw and underpoint 1              //~v5djI~
	Pdwup[2]=0;	//dw low                                           //~v5djR~
	Pdwup[3]=0;	//underpoint                                       //~v5djR~
    return;                                                        //~v5djI~
}//ucalc_dwupinit                                                  //~v5djI~
//***************************************************************  //~v5djI~
//conv 3 word data(dowrd or underpoint) to 4 word data(dword with underpoint)//~v5djI~
//parm1:output 4 word                                              //~v5djI~
//parm2:input  3 word                                              //~v5djI~
//*rc:4                                                            //~v5djI~
//***************************************************************  //~v5djI~
void ucalc_dwupset(int Popt,long *Pdwup,long *Plv)                 //~v5drR~
{                                                                  //~v5djI~
	int dwid;                                                      //~v5djI~
    LONG intval,upval;                                             //~v5dtI~
//*****************                                                //~v5djI~
//  dwid=Plv[1];                                                   //~v5djI~//~v6xiR~
    dwid=(int)Plv[1];                                              //~v6xiI~
	if (dwid>UCALC_DWORDID)                                        //~v5djI~
    	memcpy(Pdwup,Plv,sizeof(long)*4);                          //~v5djI~
    else                                                           //~v5djI~
	if (dwid==UCALC_DWORDID)                                       //~v5djI~
    {                                                              //~v5djI~
		Pdwup[0]=Plv[0];	//dw high                              //~v5djI~
//  	Pdwup[1]=UCALC_DWORDID+1;	//dw and underpoint 1          //~v5drR~
    	Pdwup[1]=UCALC_DWORDID  ;	//dw and underpoint 1          //~v5drI~
		Pdwup[2]=Plv[2];	//dw low                               //~v5djI~
//  	Pdwup[3]=0;	//underpoint                                   //~v5drR~
    }                                                              //~v5djI~
    else                                                           //~v5djI~
    {                                                              //~v5drI~
        intval=Plv[0];  //save for the case inp-addr is same as out//~v5dtI~
        upval=Plv[2];  //save for the case inp-addr is same as out //~v5dtI~
//      if (Popt & CALC_SIGNED && Plv[0]<0)                        //~v5dtR~
        if (Plv[0]<0)                                              //~v5dtI~
//  		Pdwup[0]=ULMINUS;     	//dw high                      //~v5dyR~
    		Pdwup[0]=-1;          	//dw high                      //~v5dyI~
        else                                                       //~v5drI~
	        Pdwup[0]=0;         //dw high                          //~v5drI~
    	Pdwup[2]=intval;	//dw low                               //~v5dtR~
	if (dwid)	//underpoint                                       //~v5djR~
    {                                                              //~v5djI~
//  	Pdwup[0]=0;     	//dw high                              //~v5drR~
		Pdwup[1]=UCALC_DWORDID+dwid;	//dw and underpoint 1      //~v5djI~
//  	Pdwup[2]=Plv[0];	//dw low                               //~v5drR~
		Pdwup[3]=upval;	//underpoint                               //~v5dtR~
    }                                                              //~v5djI~
    else		//word                                             //~v5djI~
    {                                                              //~v5djI~
//  	Pdwup[0]=0;     	//dw high                              //~v5drR~
//  	Pdwup[1]=UCALC_DWORDID+1;	//dw and underpoint 1          //~v5drR~
    	Pdwup[1]=UCALC_DWORDID;	//dw and underpoint 1              //~v5drI~
//  	Pdwup[2]=Plv[0];	//dw low                               //~v5drR~
//  	Pdwup[3]=0;     	//underpoint                           //~v5drR~
    }                                                              //~v5djI~
    }//not dw+up                                                   //~v5drI~
    return;                                                        //~v5djI~
}//ucalc_dwupset                                                   //~v5drR~
//***************************************************************  //~v5drI~
//conv 3 word data(dowrd or underpoint) to 2 word data(dword)      //~v5drI~
//parm1:output 4 word                                              //~v5drI~
//parm2:input  3 word                                              //~v5drI~
//*rc:fmtid                                                        //~v5drI~
//***************************************************************  //~v5drI~
int bc_numfmt2dw(int Popt,long *Pnumfmt,long *Pdw)                 //~v5drR~
{                   	                                           //~v5drI~
	int dwid;                                                      //~v5drI~
//******************                                               //~v5drI~
	dwid=(int)Pnumfmt[1];                                          //~v5drI~
	if (dwid>=UCALC_DWORDID)                                       //~v5drI~
    {                                                              //~v5drI~
    	Pdw[0]=Pnumfmt[0];	//dw high                              //~v5drR~
    	Pdw[1]=Pnumfmt[2];	//dw low                               //~v5drR~
    }                                                              //~v5drI~
    else                                                           //~v5drI~
    {                                                              //~v5drI~
//   	if (Popt & CALC_SIGNED && Pnumfmt[0]<0)                    //~v5dtR~
     	if (Pnumfmt[0]<0)                                          //~v5dtI~
//      	Pdw[0]=ULMINUS;                                        //~v5dyR~
        	Pdw[0]=-1;                                             //~v5dyI~
        else                                                       //~v5drI~
	    	Pdw[0]=0;                                              //~v5drR~
    	Pdw[1]=Pnumfmt[0];	//dw low                               //~v5drR~
    }                                                              //~v5drI~
    return dwid;                                                   //~v5drI~
}//bc_numfmt2dw                                                    //~v5drI~
//***************************************************************  //~v69BI~
//dword to num fmt(no underpoint support)                          //~v69BI~
//*rc:fmtid                                                        //~v69BI~
//***************************************************************  //~v69BI~
int bc_dw2numfmt(int Popt,long *Pnumfmt,long *Pdw)                 //~v69BI~
{                                                                  //~v69BI~
	int dwid;                                                      //~v69BI~
//******************                                               //~v69BI~
    if (Pdw[0] || Pdw[1]<0)                                        //~v69BI~
    {                                                              //~v69BI~
    	Pnumfmt[0]=Pdw[0];    //H                                  //~v69BR~
    	Pnumfmt[2]=Pdw[1];    //L                                  //~v69BR~
    	Pnumfmt[1]=UCALC_DWORDID;                                  //~v69BI~
        dwid=1;                                                    //~v69BI~
    }                                                              //~v69BI~
    else                                                           //~v69BI~
    {                                                              //~v69BI~
    	Pnumfmt[0]=Pdw[1];    //L                                  //~v69BI~
    	Pnumfmt[2]=0;                                              //~v69BI~
    	Pnumfmt[1]=0;                                              //~v69BI~
        dwid=0;                                                    //~v69BI~
    }                                                              //~v69BI~
    Pnumfmt[3]=0;                                                  //~v69BI~
    return dwid;                                                   //~v69BI~
}//bc_dw2numfmt                                                    //~v69BI~
//***************************************************************  //~v5drI~
//split 4/3 word data to dword and underpoint data                 //~v5drI~
//parm1:input 4/3 word                                             //~v5drI~
//parm2:output dword                                               //~v5drI~
//parm3:output underpoint(3word)                                   //~v5drI~
//*rc:dwid                                                         //~v5drI~
//***************************************************************  //~v5drI~
int ucalc_dwup2dwandup(long *Pdwup,long *Pdw,long *Pup)            //~v5drR~
{                                                                  //~v5drI~
	int dwid;                                                      //~v5drI~
//*****************                                                //~v5drI~
//  dwid=Pdwup[1];                                                 //~v5drR~//~v6xiR~
    dwid=(int)Pdwup[1];                                            //~v6xiI~
	if (dwid>UCALC_DWORDID)	//4word data                           //~v5drI~
    {                                                              //~v5drI~
        Pdw[0]=Pdwup[0];    //dw high                              //~v5drI~
        Pdw[1]=Pdwup[2];    //dw low                               //~v5drI~
        Pup[0]=0;                                                  //~v5drI~
	    Pup[1]=dwid-UCALC_DWORDID;                                 //~v5drI~
	    Pup[2]=Pdwup[3];                                           //~v5drI~
    }                                                              //~v5drI~
    else                                                           //~v5drI~
	if (dwid==UCALC_DWORDID)	//3word data(dword)                //~v5drI~
    {                                                              //~v5drI~
        Pdw[0]=Pdwup[0];    //dw high                              //~v5drI~
        Pdw[1]=Pdwup[2];    //dw low                               //~v5drI~
        Pup[0]=0;                                                  //~v5drI~
	    Pup[1]=0;                                                  //~v5drI~
	    Pup[2]=0;                                                  //~v5drI~
    }                                                              //~v5drI~
    else                                                           //~v5drI~
    {                                                              //~v5drI~
        if (Pdwup[0]<0)                                            //~v5drR~
//          Pdw[0]=ULMINUS;    //dw high                           //~v5dyR~
            Pdw[0]=-1;         //dw high                           //~v5dyI~
        else                                                       //~v5drI~
            Pdw[0]=0;    //dw high                                 //~v5drI~
        Pdw[1]=Pdwup[0];  //dw low                                 //~v5drI~
        Pup[0]=0;          //up                                    //~v5drI~
        if (dwid)                   //3word data(up)               //~v5drI~
        {                                                          //~v5drI~
            Pup[1]=dwid;                                           //~v5drI~
            Pup[2]=Pdwup[2];  //up                                 //~v5drI~
        }                                                          //~v5drI~
        else                                                       //~v5drI~
	    {                                                          //~v5drI~
            Pup[1]=0;                                              //~v5drI~
            Pup[2]=0;                                              //~v5drI~
        }                                                          //~v5drI~
    }                                                              //~v5drI~
    return dwid;                                                   //~v5drI~
}//ucalc_dwup2dwandup                                              //~v5drI~
//***************************************************************  //~v5drM~
//*degrade dword to word                                           //~v5drM~
//*parm3:optional word output                                      //~v5drM~
//*rc: :0:degraded  1:source is dword                              //~v5drM~
//***************************************************************  //~v5drM~
int bc_dword2word(int Popt,long *Pnumfmt,long *Poutnumfmt)         //~v5drM~
{                                                                  //~v5drM~
	int rc=1;                                                      //~v5drM~
//  LONG dwh,dwl;                                                  //~v5drM~//~v6xhR~
    INT4 dwh,dwl;                                                  //~v6xhI~
//************************                                         //~v5drM~
//	dwh=Pnumfmt[0];                                                //~v5drM~//~v6xhR~
  	dwh=(INT4)Pnumfmt[0];                                          //~v6xhI~
//	dwl=Pnumfmt[2];                                                //~v5drM~//~v6xhR~
	dwl=(INT4)Pnumfmt[2];                                          //~v6xhI~
//  if (Popt & CALC_SIGNED)                                        //~v5dtR~
//  {                                                              //~v5dtR~
//      if (dwh==ULMINUS)                                          //~v5drM~
//      if (dwh==(LONG)(-1))                                       //~v6xhR~
        if (dwh==ULMINUS)   //0xffffffff                           //~v6xhI~
        {                                                          //~v5drM~
            if (dwl<0)                                             //~v5drM~
                rc=0;                                              //~v5drM~
        }                                                          //~v5drM~
        else                                                       //~v5drM~
        if (!dwh)                                                  //~v5drM~
            if (dwl>=0)                                            //~v5drM~
                rc=0;                                              //~v5drM~
//  }                                                              //~v5dtR~
//  else                                                           //~v5dtR~
//  {                                                              //~v5dtR~
//      if (!dwh)                                                  //~v5dtR~
//          rc=0;                                                  //~v5dtR~
//  }                                                              //~v5dtR~
    if (!rc)                                                       //~v5drI~
        if (Poutnumfmt)                                            //~v5drR~
        {                                                          //~v5drR~
            Poutnumfmt[0]=dwl;                                     //~v5drR~
            Poutnumfmt[1]=(Pnumfmt[1] & ~UCALC_DWORDID);	//up   //~v5drR~
            if (Poutnumfmt[1])                                     //~v5drI~
    	        Poutnumfmt[2]=Pnumfmt[3];                          //~v5drI~
        }                                                          //~v5drR~
    return rc;                                                     //~v5drM~
}//bc_dword2word                                                   //~v5drM~
//***************************************************************  //~v50hI~
//2nd opd dword err                                                //~v50hI~
//*rc:4                                                            //~v50hI~
//***************************************************************  //~v50hI~
int ucalc_dw2err(int Pope)                                         //~v50hI~
{                                                                  //~v50hI~
    uerrmsg("For \"%c\",2nd operand should not be double word",    //~v50hR~
            "\"%c\" は、第2オペランドがダブルワードのときは計算できません",//~v50hR~
			Pope);                                                 //~v50hI~
    return 4;                                                      //~v50hI~
}//ucalc_dw2err                                                    //~v50hI~
//***************************************************************  //~v69BI~
//2nd opd dword err    ans[2],res[4]                               //~v69BR~
//*rc:4                                                            //~v69BI~
//***************************************************************  //~v69BI~
int ucalc_dw2errresidual(LONG *Pans,LONG *Pres)                    //~v69BR~
{                                                                  //~v69BI~
    uerrmsg("For \"%c\" err double word residual is not supported,ans=x%x..%08x,residual=x%x..%08x",//~v69BR~
            "\"%c\" エラー、余りがダブルワードです,結果=x%x..%08x,余り=x%x..%08x",//~v69BR~
			'%',Pans[0],Pans[1],Pres[0],Pres[2]);                  //~v69BR~
    return 4;                                                      //~v69BI~
}//ucalc_dw2errresidual                                            //~v69BI~
//***************************************************************  //~v5dpI~
//2nd opd dword err                                                //~v5dpI~
//*rc:4                                                            //~v5dpI~
//***************************************************************  //~v5dpI~
int ucalc_dwuperr(void)                                            //~v5dpI~
{                                                                  //~v5dpI~
	uerrmsg("not supported operation for doubleword and decimalpoint.",//~v5dtR~
			"小数点、ダブルワードでのこの演算はサポートされていません。");//~v5dtR~
    return 8;                                                      //~v5dpI~
}//ucalc_dwuperr                                                   //~v5dpI~
//***************************************************************  //~v5drI~
//max decimax err                                                  //~v5drI~
//*rc:4                                                            //~v5drI~
//***************************************************************  //~v5drI~
int ucalc_dwmaxerr(void)                                           //~v5drI~
{                                                                  //~v5drI~
	uerrmsg("Over max value(=%s)",                                 //~v5drI~
			"数値は %s 未満。",                                    //~v5dtR~
//  		Sp2tbl[DWORDSZSIGN].numstr);                           //~v5dyR~
    		Sdwmaxval);                                            //~v5dyI~
	return CALC_RCERRMSG;	//avoid fmt err msg                    //~v5drR~
}//ucalc_dwmaxerr                                                  //~v5drI~
//***************************************************************  //~v5dxI~
//max decimax err                                                  //~v5dxI~
//*rc:4                                                            //~v5dxI~
//***************************************************************  //~v5dxI~
int ucalcerrdwordovf(void)                                         //~v5dxI~
{                                                                  //~v5dxI~
	uerrmsg("Dword overflow",                                      //~v5dxI~
			"ダブルワードの桁あふれ。");                           //~v5dxI~
	return CALC_RCERRMSG;	//avoid fmt err msg                    //~v5dxI~
}//ucalcerrdwordovf                                                //~v5dxI~
