//*CID://+vafkR~:                                   update#=  93;  //~vafkR~
//*************************************************************
//*xecalc21.h                                                      //~va7aR~
//*************************************************************
//vafk:120624 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  use ULPTR(unsigned __int64/ULONG)//~vafkI~
//va7a:100817 split xecalc2.c                                      //~va7aI~
//va79:100809 cpeb converter parm support                          //~va79I~
//*******************************************************
//#define XECALCPARM    ULONG                                        //~va70I~//~vafkR~
#define XECALCPARM    ULPTR                                        //~vafkI~
#define MAXLABEL 4                                                 //~v17hR~
#define CMDID_FMT     "FMT"                                        //~v168I~
#define CMDID_OPD     "FLD"                                        //~v42oI~

#define  CALC_FT1     0x0100                //1 opd id

#define  CALC_SUM     (CALC_FT1+1)          //summary
#define  CALC_DIF     (CALC_FT1+2)          //differrence incleasing
#define  CALC_ACUM    (CALC_FT1+4)          //accumulation
#define  CALC_TARGET  (CALC_FT1+5)         //target operand
#define  CALC_CONV    (CALC_FT1+6)         //data type conversion  //~v51mI~
#define  CALC_COMP    '='       //compare                          //~v497I~
#define  CALC_STRINGDATA 'S'    //data type string                 //~v497I~
#define  CALC_STRINGCONST '@'    //data type string                //~v56zI~
#define  CALC_STRINGQUOTE 0x0100 //data type string by quatation(no preceding @)//~v59jI~
//#define  CALC_COUNT   'C'       //count record count             //~v535R~
#define  CALC_COUNT   '~'       //count record count               //~v535I~
#define  CALC_COPY    'C'       //opd1=opd2 fmt                    //~v56zI~
#define  CALC_COPYCV  'V'       //t:opd1=t:opd2 fmt                //~v56zI~

//#define  MAX_DATA_WIDTH 16                                       //~v51jR~
//#define  MAX_DATA_WIDTH 17                                       //~v51mR~
//#define  MAX_DATA_WIDTH 27    //" "+dword Z fmt max              //~v57JR~
#define  MAX_DATA_WIDTH 39    //" "+dword Z fmt max+underpoint max(9)//~v57JI~
#define  MAX_DATA_WIDTHS MAXCOLUMN    //string data max len        //~v56zI~
//#define  MAXKEYLEN      32                                       //~v54DR~
#define  MAXKEYLEN      256                                        //~v54DI~
//#define  DDECSZ        (sizeof(long)*3)                          //~v57JR~
//#define  DDECSZ        (sizeof(long)*4)                            //~v57JI~//~vafkR~
#define  DDECSZ        (sizeof(SLPTR)*4)                           //~vafkI~

#define  CALC_SUMMLINE   ':'		//summary line edit id
#define  CALC_SUMMFLD    '='		//set summary field id
#define  CALC_COUNTONLY  "1+/"  	//1st opd to count line by break key//~v54JI~
#define  TC_FLDNOSPECID  -1                                        //~v40RR~
#define  TC_CONSTSPECID  -2        //constant for 2nd operand      //~v53JI~
                                                                   //~v77iI~
#ifdef UTF8UCS2                                                    //~va20R~
	#define  TC_PDBCS     1        //index of pdbcs in value array //~va20R~
#endif                                                             //~va20R~

#define PARM_BREAKTYPE     0
	#define  PARM_BREAK_COUNT      1		//break by count
	#define  PARM_BREAK_KEY        2		//break by key change
	#define  PARM_BREAK_KEYGRP     3		//break by key distance
	#define  PARM_BREAK_KEY_EQ     4		//break by key change(not sorted)//~v53DI~
	#define  PARM_BREAK_KEYGRP_EQ  5		//break by key distance(not sorted)//~v53DI~
	#define  PARM_BREAK_KEY_LT     6		//break by key change(discending)//~v53DR~
	#define  PARM_BREAK_KEYGRP_LT  7		//break by key distance(discending)//~v53DI~
#define PARM_OPTION        1
	#define  PARM_SUMISRT_TOP    0x0001  //summline insert to top of file
	#define  PARM_SUMISRT_LAST   0x0002  //summline insert to last of file
	#define  PARM_SUMISRT_BEFORE 0x0003  //summline insert to before block
	#define  PARM_SUMISRT_AFTER  0x0004  //summline insert to after block
	#define  PARM_SUMISRT_MASK   0x0007  //summline insert option mask
	#define  PARM_SUMISRT_IGNORE 0x0100  //summline line ignore
	#define  PARM_SUMISRT_AVE    0x0200  //set average to summline
	#define  PARM_SUMISRT_MM     0x0400  //set min/max to summline
	#define  PARM_SUMISRT_SUMERR 0x0800  //summline is err         //~v17hI~
//  #define  PARM_PADD0          0x0100  //zero padding for result //~v56zR~
    #define  PARM_PADD0          0x1000  //zero padding for result //~v56zI~
    #define  PARM_INS            0x2000  //insert to opd3(for opd3=opd1[op opd2])//~v56zI~
//  #define  PARM_COPYREP        0x4000  //reduce target field len //~v56zR~
    #define  PARM_COUNTEQ        0x4000  //countup when starttime==endtime//~v587I~
    #define  PARM_COPYRJUST      0x8000  //left justify opd3 for CALC_COPY//~v56zR~
	#define  PARM_ROUND        0x010000  //round option            //~v58vI~
	#define  PARM_VPREC        0x020000  //Vn option               //~v58vI~
	#define  PARM_TRUEFALSE    0x040000  //set compare result 1 and 0//~v62uI~
	#define  PARM_FALSETRUE    0x080000  //set compare result 0 and 1//~v62uI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	#define  PARM_EBCFILE      0x100000  //target is ebcdic file   //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
	#define  PARM_UTF8FILE     0x200000  //target is ebcdic file   //~va5bI~
#define PARM_DATATYPE1     2
#define PARM_OPD1POS1      3
#define PARM_OPD1POS2      4
#define PARM_DATATYPE2     5
#define PARM_OPD2POS1      6
#define PARM_OPD2POS2      7
#define PARM_DATATYPE3     8
#define PARM_OPD3POS1      9
#define PARM_OPD3POS2      10
#define PARM_COUNT         11
#define PARM_KEYDATATYPE   12
#define PARM_KEYCOL1       13
#define PARM_KEYCOL2       14
#define PARM_KEYBREAKVALUE 15
#define PARM_NXSW          16                                      //~v17fR~
#define PARM_PRECNO        17                                      //~v58vR~
#define PARM_OUTFNM        18                                      //~v58zI~
#define PARM_OUTFH         19   //opened file handle               //~v58zI~
#define PARM_OUTFPATH      20                                      //~v62FI~
//#define PARM_TBLSZ         17   //last+1                         //~v58vR~
//#define PARM_TBLSZ         18   //last+1                         //~v58zR~
//#define PARM_TBLSZ         20   //last+1                         //~v62FR~
//#define PARM_TBLSZ         21   //last+1                           //~v62FI~//~va7aR~
#define PARM_CONSTVALUE    20                                      //~va7aI~
#define PARM_CONSTDATATYPE 21                                      //~va7aI~
#define PARM_CONSTADDR     22                                      //~va7aI~
#define PARM_CONSTLEN      23                                      //~va7aI~
//#define PARM_TBLSZ         24   //last+1                           //~va7aI~//~va79R~
#define PARM_EBC_HANDLE    24                                      //~va79I~
#define PARM_TBLSZ         25   //last+1                           //~va79I~
//*******************************************************
//static char Snxsw;                                               //~v17fR~
typedef struct _RCW {                                              //~v533I~
                      PULINEH RCWplh;		//alive count          //~v533R~
                      int     RCWcount;		//alive count          //~v533R~
                      char   *RCWdata1;		//opd1 data ptr        //~v533R~
                      char   *RCWdata2;		//opd2 data ptr        //~v533R~
//                    LONG    RCWdata1lv[4];//opd1 long value      //~v58wI~//~vafkR~
                      SLPTR   RCWdata1lv[4];//opd1 long value      //~vafkI~
//                    LONG    RCWdata2lv[4];//opd2 long value      //~v58wR~//~vafkR~
                      SLPTR   RCWdata2lv[4];//opd2 long value      //~vafkI~
                      char    RCWdatatype1;//opd1 datatype         //~v58wI~
                      char    RCWdatatype2;//opd2 daattype         //~v58wI~
#ifdef UTF8UCS2                                                    //~va20I~
                      char   *RCWdbcs1;		//opd1 data ptr        //~va20R~
                      char   *RCWdbcs2;		//opd2 data ptr        //~va20I~
#endif                                                             //~va20I~
                    }	RCW,*PRCW;                                 //~v533I~
#define RCWSZ (sizeof(RCW))                                        //~v533R~
//*******************************************************
//int tc_main(PUCLIENTWE Ppcw);                                    //~v17fR~
//int tc_opdchk(PUCLIENTWE Ppcw,int *Pfunctype,int *Pparm,PULINEH *Pplabplh);//~va70R~
int tc_opdchk(PUCLIENTWE Ppcw,int *Pfunctype,XECALCPARM *Pparm,PULINEH *Pplabplh);//~va70I~
//int tc_getopd(char *Pstr,int *Pvalue,char **Pnext);              //~v53JR~
//int tc_getopd(int Pconstallowsw,char *Pstr,int *Pvalue,char **Pnext);//~v59kR~
//int tc_getopd(int Pconstallowsw,char *Pstr,char *Pstrconst,int *Pvalue,char **Pnext);//~v59kI~//~va70R~
int tc_getopd(int Pconstallowsw,char *Pstr,char *Pstrconst,XECALCPARM *Pvalue,char **Pnext);//~va70I~
//int tc_opdchk2(char *Popt2,int *Pparm);                          //~va70R~
int tc_opdchk2(char *Popt2,XECALCPARM *Pparm);                     //~va70I~
//int tc_fldnochk(PUCLIENTWE Ppcw,PUFILEH Ppfh,int *Pparm,PULINEH *Pplabplh);//~v40RI~//~va70R~
int tc_fldnochk(PUCLIENTWE Ppcw,PUFILEH Ppfh,XECALCPARM *Pparm,PULINEH *Pplabplh);//~va70I~
int tc_chkdatatype(int Pdatatype);
//int tc_getnumrange_f(char *Pstr,int *Pstart,int *Pend,char **Ppcend);//~v506R~
//int tc_ft1(PUCLIENTWE Ppcw,int Pfunctype,int *Pparm,PULINEH *Plabplh);//~va70R~
int tc_ft1(PUCLIENTWE Ppcw,int Pfunctype,XECALCPARM *Pparm,PULINEH *Plabplh);//~va70I~
int tc_ft1sumdatatype(long Pdatactr,PULINEH Pplh,int *Pdatatype,int Plinedatatype,long *Pskipno);
//int tc_ft1sum(PUCLIENTWE Ppcw,PULINEH Pplh1,PULINEH Pplh2,int Ppos1,int Ppos2,int *Pparm);//~va70R~
int tc_ft1sum(PUCLIENTWE Ppcw,PULINEH Pplh1,PULINEH Pplh2,int Ppos1,int Ppos2,XECALCPARM *Pparm);//~va70I~
//int tc_ft1sumnobreak(PUCLIENTWE Ppcw,PULINEH Pplh1,PULINEH Pplh2,int Ppos1,int Ppos2,int *Pparm);//~va70R~
int tc_ft1sumnobreak(PUCLIENTWE Ppcw,PULINEH Pplh1,PULINEH Pplh2,int Ppos1,int Ppos2,XECALCPARM *Pparm);//~va70I~
//int tc_ft1sumkey(PUCLIENTWE Ppcw,PULINEH Pplh1,PULINEH Pplh2,int Ppos1,int Ppos2,int *Pparm);//~va70R~
int tc_ft1sumkey(PUCLIENTWE Ppcw,PULINEH Pplh1,PULINEH Pplh2,int Ppos1,int Ppos2,XECALCPARM *Pparm);//~va70I~
//int tc_ft1isrtsum(PUCLIENTWE Ppcw,int Psumrepsw,PULINEH Pplhprev,PULINEH Pplhbefore,//~v58zR~
//int tc_ft1isrtsum(PUCLIENTWE Ppcw,int *Pparm,int Psumrepsw,PULINEH Pplhprev,PULINEH Pplhbefore,//~v58zI~//~va70R~
int tc_ft1isrtsum(PUCLIENTWE Ppcw,XECALCPARM *Pparm,int Psumrepsw,PULINEH Pplhprev,PULINEH Pplhbefore,//~va70I~
					PULINEH *Ppplhafter,PULINEH *Pplhisrted,int Pinslen,int Ppos1,//~v170R~
//  				int Pcpos1,int Pcpos2,char *Pkey,char *Psumline,long *Pdataovfcnt);//~v589R~
#ifdef UTF8UCS2                                                    //~va20R~
    				int Pcpos1,int Pcpos2,char *Pkey,char *Pkeydbcs,int Pkeylen,char *Psumline,long *Pdataovfcnt);//~va20R~
#else                                                              //~va20R~
    				int Pcpos1,int Pcpos2,char *Pkey,int Pkeylen,char *Psumline,long *Pdataovfcnt);//~v589I~
#endif                                                             //~va20R~
#define FT1_SUMREP    0x01          //replace previous summary line
#define FT1_SUMTOT    0x02          //grand total line
#ifdef UTF8UCS2                                                    //~va20R~
//int tc_ft1outsumline(PUCLIENTWE Ppcw,int *Pparm,int Popt,int Pkeypos1,int Pkeypos2,char *Pkey,char *Pkeydbcs,char *Psumline);//~va20R~//~va70R~
int tc_ft1outsumline(PUCLIENTWE Ppcw,XECALCPARM *Pparm,int Popt,int Pkeypos1,int Pkeypos2,char *Pkey,char *Pkeydbcs,char *Psumline);//~va70I~
#else                                                              //~va20R~
int tc_ft1outsumline(PUCLIENTWE Ppcw,int *Pparm,int Popt,int Pkeypos1,int Pkeypos2,char *Pkey,char *Psumline);//~v58zR~
#endif                                                             //~va20R~
//int tc_editsumm(int Pdatatype,int Pwidth,long *Psumm,long *Pmin,long *Pmax,//+vafkR~
int tc_editsumm(int Pdatatype,int Pwidth,SLPTR *Psumm,SLPTR *Pmin,SLPTR *Pmax,//+vafkI~
//				long Pokno,long Pskipno,long Povfctr,long Pkeyerr,char *Pout,int *Pparm);//~va70R~
				long Pokno,long Pskipno,long Povfctr,long Pkeyerr,char *Pout,XECALCPARM *Pparm);//~va70I~
//int tc_ft2(PUCLIENTWE Ppcw,int Pfunctype,int *Pparm,PULINEH *Plabplt);//~va70R~
int tc_ft2(PUCLIENTWE Ppcw,int Pfunctype,XECALCPARM *Pparm,PULINEH *Plabplt);//~va70I~
//int tc_ft2count(PUCLIENTWE Ppcw,int Pfunctype,int *Pparm,PULINEH *Plabplh);//~v533I~//~va70R~
int tc_ft2count(PUCLIENTWE Ppcw,int Pfunctype,XECALCPARM *Pparm,PULINEH *Plabplh);//~va70I~
//int tc_getplhdata(int Psw1st,int *Pdatatype,PULINEH *Ppplh,PULINEH Pendplh,//~v57JR~
int tc_getplhdata(int Popt,int Psw1st,int *Pdatatype,PULINEH *Ppplh,PULINEH Pendplh,//~v57JI~
//					int Ppos1,int Ppos2,long *Pvalue,int *Pparm);  //~va70R~
//					int Ppos1,int Ppos2,long *Pvalue,XECALCPARM *Pparm);//~va70I~//~vafkR~
					int Ppos1,int Ppos2,SLPTR *Pvalue,XECALCPARM *Pparm);//~vafkR~
//#define GDO_DWUP 0x01   //accept dowrd underpoint data           //~v62ER~
#define GDO_MASK      0x0f   //ignore summ line;func=copy for target of data1=data2//~v77iI~
#define GDO_IGNSUM    0x20   //ignore summ line;func=copy for target of data1=data2//~v77iI~
                                                                   //~va50I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
#define GDO_EBC       0x40   //ebcdic file                         //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
                                                                   //~va50I~
#define GDO_EXISTCTR      0x80   //get field data for "~"(existing count calc) operation//~va2bI~
#define GDO_FWMASK    0xff0000 //field width mask for "~"(existing count calc) operation//~va2bI~
#define GDO_SHIFTCTR   16                                          //~va2bI~
                                                                   //~va79I~
//int tc_getlinedata(int *Pdatatype,char *Pdata,int len,long *Pvalue);//~v57JR~
//int tc_getlinedata(int Popt,int *Pdatatype,char *Pdata,int len,long *Pvalue);//~v62ER~
//int tc_setlinedata(PUCLIENTWE Ppcw,PULINEH Pplh,int Pundopsw,int Pdatatype,//~v58vR~
//int tc_setlinedata(PUCLIENTWE Ppcw,int *Pparm,PULINEH Pplh,int Pundopsw,int Pdatatype,//~v58vI~//~va70R~
int tc_setlinedata(PUCLIENTWE Ppcw,XECALCPARM *Pparm,PULINEH Pplh,int Pundopsw,int Pdatatype,//~va70I~
//  				int Ppos1,int Ppos2,long *Pvalue,long *Pdataovfcnt);//~vafkR~
    				int Ppos1,int Ppos2,SLPTR *Pvalue,long *Pdataovfcnt);//~vafkI~
//int tc_setlinedata3(PUCLIENTWE Ppcw,int *Pparm,PULINEH Pplh,int Pundopsw,int Pdatatype,//~v56zI~//~va70R~
int tc_setlinedata3(PUCLIENTWE Ppcw,XECALCPARM *Pparm,PULINEH Pplh,int Pundopsw,int Pdatatype,//~va70I~
//  				int Ppos1,int Ppos2,long *Pvalue,long *Pdataovfcnt);//~v56zI~//~vafkR~
    				int Ppos1,int Ppos2,SLPTR *Pvalue,long *Pdataovfcnt);//~vafkI~
//int tc_setlinedatacopy(PUCLIENTWE Ppcw,int *Pparm,PULINEH Pplh,    //~v56zI~//~va70R~
int tc_setlinedatacopy(PUCLIENTWE Ppcw,XECALCPARM *Pparm,PULINEH Pplh,//~va70I~
//					int Ppos1,int Ppos2,long *Pvalue,long *Pdataovfcnt);//~v56zI~//~vafkR~
  					int Ppos1,int Ppos2,SLPTR *Pvalue,long *Pdataovfcnt);//~vafkI~
//int tc_getlinedatanum(char *Pdata,int Plen,long *Pvalue,int Pdatatype);//~v57JR~
//int tc_getlinedatanum(int Popt,char *Pdata,int Plen,long *Pvalue,int Pdatatype);//~v62ER~
//int tc_getisrtpos(PULINEH Pplh1,PULINEH Pplh2,int *Pparm,PULINEH *Pplhbef,PULINEH *Pplhaft);//~v170R~//~va70R~
int tc_getisrtpos(PULINEH Pplh1,PULINEH Pplh2,XECALCPARM *Pparm,PULINEH *Pplhbef,PULINEH *Pplhaft);//~va70I~
int tc_getdatatype(char *Popd,int *Pdtype);
//int tc_calc(int Ptimeconvopt,int Pdatatype,int Pope,long *Pdata1,long *Pdatat2);//~vafkR~
int tc_calc(int Ptimeconvopt,int Pdatatype,int Pope,SLPTR *Pdata1,SLPTR *Pdatat2);//~vafkI~
int  tcerrdatawidth(void);
int tcerrnorec(long Precno,long Pdataerrno,long Pkeyerrno);
int tc_help(PUCLIENTWE Ppcw);                                      //~v168I~
int tc_help0(void);                                                //~v168I~
int tc_help1(void);                                                //~v168I~
int tc_help2(void);                                                //~v168I~
int tc_help3(void);                                                //~v168I~
int tc_helpf(void);                                                //~v42oI~
int tc_helpsum(void);                                              //~v168I~
int tcerrinvalidforcount(void);                                    //~v58wR~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
//int	calc_m2bconststr(int Popt,int *Pparm,long *Plvts,UCHAR *Pebc,UCHAR *Pdbcs,int Pbuffsz);//~va5bR~//~va70R~
//int	calc_m2bconststr(int Popt,XECALCPARM *Pparm,long *Plvts,UCHAR *Pebc,UCHAR *Pdbcs,int Pbuffsz);//~va70I~//~vafkR~
int	calc_m2bconststr(int Popt,XECALCPARM *Pparm,SLPTR *Plvts,UCHAR *Pebc,UCHAR *Pdbcs,int Pbuffsz);//~vafkI~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
