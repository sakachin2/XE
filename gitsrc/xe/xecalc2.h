//*CID://+vafkR~:                             update#=   23;       //~vafkR~
//********************************************************         //~vafkR~
//vafk:120624 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  use ULPTR(unsigned __int64/ULONG)//~vafkI~
//va79:100809 cpeb converter parm support                          //~va79I~
//va20:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~va20I~
//v62E:050407 sort cmd:numeric sort support(minus consideration)   //~v62EI~
//v62p:050325 tc_getnumrange is moved to uedit.c                   //~v62pR~
//v506:021019 add "set" option for renum cmd;set num fld on specified colomn//~v506I~
//v155:000318 calc func(NEW)
//*******************************************************
//*******************************************************
int tc_blocksave(PUCLIENTWE Ppcw);
//*******************************************************
//int tc_getnumrange(char *Pstr,int *Pstart,int *Pend,char **Pendaddr);//~v62pR~
//*******************************************************
int tc_setplherr(PULINEH Pplh);
//*******************************************************          //~v506I~
int tc_getnumrange_f(char *Pstr,int *Pstart,int *Pend,char **Ppcend);//~v506I~
//*******************************************************          //~v62EI~
#ifdef UTF8UCS2                                                    //~va20I~
//int tc_getlinedata(int Popt,int *Pdatatype,char *Pdata,char *Pdbcs,int len,long *Pvalue);//~va20I~//~va79R~
//int tc_getlinedata(int Popt,int Phandle,int *Pdatatype,char *Pdata,char *Pdbcs,int len,long *Pvalue);//~va79I~//~vafkR~
int tc_getlinedata(int Popt,int Phandle,int *Pdatatype,char *Pdata,char *Pdbcs,int len,SLPTR *Pvalue);//~vafkI~
#else                                                              //~va20I~
int tc_getlinedata(int Popt,int *Pdatatype,char *Pdata,int len,long *Pvalue);//~v62EI~
#endif                                                             //~va20I~
//*******************************************************          //~v62EI~
//int tc_getlinedatanum(int Popt,char *Pdata,int Plen,long *Pvalue,int Pdatatype);//~v62EI~//~vafkR~
int tc_getlinedatanum(int Popt,char *Pdata,int Plen,SLPTR *Pvalue,int Pdatatype);//~vafkI~
#define GDO_DWUP 0x01   //accept dowrd underpoint data             //~v62EI~
#ifdef ULIB64X	//long long interface                              //~vafkR~
	#define bc_getvalue           	bc_getvalueLL                  //+vafkR~
	#define ucalc_vrajust         	ucalc_vrajustLL                //+vafkR~
	#define ucalc_time            	ucalc_timeLL                   //+vafkR~
	#define ucalc_binop          	ucalc_binopLL                  //+vafkR~
	#define ucalc_o2l             	ucalc_o2lLL                    //+vafkR~
	#define bc_getxdw             	bc_getxdwLL                    //+vafkR~
	#define ucalc_gettimevalue    	ucalc_gettimevalueLL           //+vafkR~
	#define bc_getld              	bc_getldLL                     //+vafkR~
	#define ucalc_timeedit        	ucalc_timeeditLL               //+vafkR~
	#define bc_dweditnum          	bc_dweditnumLL                 //+vafkR~
	#define bc_edittod            	bc_edittodLL                   //+vafkR~
	#define ucalc_editnum         	ucalc_editnumLL                //+vafkR~
	#define ucalc_getunderpointdata ucalc_getunderpointdataLL      //+vafkI~
#endif                                                             //~vafkM~
