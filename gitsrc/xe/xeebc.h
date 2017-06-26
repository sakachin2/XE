//*CID://+vag6R~:                             update#=  139;       //+vag6R~
//*********************************************************************
//* xeebc.h                                                        //~va50R~
//*********************************************************************
//vag7:120821 (BUG)XEEBCO_ERRREP2 flag contains XEEBCO_CALLOC      //~vag7I~
//vag6:120821 rep by subchar for b2b(now keep original value)      //+vag6I~
//vaac:111211 CV cmd;add F2B/B2F because cpu8 file could not be conv at place by DBCS tbl fmt difference//~vaacI~
//            and M of M2B/B2M is current locale only              //~vaacI~
//va8w:101209 SPLIT/TFLOW:delete so/si when join dbcs string       //~va8wI~
//va8s:101026 (BUG)TFLow:head count for top dbcssplit              //~va8sI~
//va8k:101013 SPLit cmd;dbcs consideration for split ALL/OVER without SBCS option .//~va8kI~
//va8j:101013 SPLit cmd;dbcs consideration for TAIL cut without SBCS option .//~va8jI~
//va8i:101011 bnds sort;add SBCS option for BNDS sort without dbcs consideration//~va8iI~
//va8h:101010 bnds sort;set space to split dbcs except dbcs continued case//~va8hI~
//va8b:101001 dbcs consideration for C&P                           //~va8bI~
//va80:100917 (WXEXXE)print ebcfile by ucs                         //~va80I~
//va7T:100909 cpeb converter parm support:for xprint               //~va7TI~
//va7y:100823 EBC:handle support for cap                           //~va7yI~
//va7x:100825 lcmd; no translation option for "=","C","M"          //~va7xI~
//va7t:100823 EBC:handle support to file output(save/rep/..)       //~va7tI~
//va7s:100823 (BUG)searchword recover fail for EBC file(u8str saved but recovery is by simple getmixword//~va7sI~
//va79:100809 cpeb converter parm support                          //~va79I~
//va6c:100619 add SOSI option -S{i|r|d} to REP/CRE/APP/SAV/COP/MOV cmd//~va6cI~
//va5X:100529 cv control(ascii 0x<20) also                         //~va5XI~
//va5L:100523 (w)xpr cmd;print SO/SI by "?"                        //~va5LI~
//va5A:100519 Ctrl+W(copyword to cmdline);drop so/si               //~va5AI~
//va50:100324 Raw EBCDIC file support for NFS mount                //~va50I~
//*********************************************************************
//*********************************************************************//~va50R~
//*********************************************************************//~va50R~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50R~
#ifdef  XEEBC_GLOBAL                                               //~va50I~
  #define XEEBC_EXT                                                //~va50R~
  #define XEEBC_INIT(value) =value                                 //~va50R~
#else                                                              //~va50I~
  #define XEEBC_EXT extern                                         //~va50R~
  #define XEEBC_INIT(value)                                        //~va50R~
#endif                                                             //~va50I~
//*********************************************************************//~va50I~
#define XEEBC_INIFILEPARM        "EBCDIC_cfg"                      //~va50I~
#define XEEBC_DEFAULTCFGFILE     "::xeebc.map"                     //~va50R~
#                                                                  //~va50I~
XEEBC_EXT int Gebcstat;                                            //~va50R~
#define GES_INIPARM    0x01        //inifile parameter specified   //~va50I~
#define GES_CFGERR     0x02        //cfg err                       //~va50I~
#define GES_DDFMTPSD   0x04        //output dd fmt on psd          //~va50R~
#define GES_CFGOPENERR 0x08        //cfg open err, default was set //~va7TI~
#define XEEBC_ISDDFMTPSD()   (Gebcstat & GES_DDFMTPSD)       //output dd fmt on psd//~va50I~
                                                                   //~va50I~
#define XEEBCO_BIN           0x01     //bin file                   //~va50I~
#define XEEBCO_L2B           0x02                                  //~va50I~
#define XEEBCO_DD2B          0x04                                  //~va50R~
#define XEEBCO_B2DD          0x08                                  //~va50I~
#define XEEBCO_B2L           0x10                                  //~va50I~
#define XEEBCO_SOSI2SPACE    0x20                                  //~va50I~
#define XEEBCO_INITDBCST     0x40                                  //~va50I~
#define XEEBCO_ERRREP      0x0100   //rep sbcs/dbcs                //~va50I~
#define XEEBCO_B2F         0x0200   //                             //~va50R~
#define XEEBCO_EOL1        0x0400        //                        //~va50R~
#define XEEBCO_EOL2        0x0800        //                        //~va50R~
#define XEEBCO_SOSIREP     0x1000    //rep sosi to "."             //~va50R~
#define XEEBCO_SOSIREPQ    0x2000    //rep sosi to "?"             //~va50I~
#define XEEBCO_CHKDBCSTB   0x4000    //for b2f dbcstb is input for dbcs trans//~va50I~
#define XEEBCO_SETF2LERR   0x8000    //req set F2LERR to ucvebc3_b2m//~va50I~
#define XEEBCO_DROPSOSI  0x010000    //drop so/si when B2M(L or F) //~va5AI~
#define XEEBCO_SOSIREPQP 0x020000   //rep sosi to "?" as printable //~va5LI~
#define XEEBCO_CVCTL     0x040000   //translate control char also  //~va5XI~
#define XEEBCO_SOSICMDR  0x080000   //sosi cmd option REP          //~va6cR~
#define XEEBCO_SOSICMDI  0x100000   //sosi cmd option INS          //~va6cR~
#define XEEBCO_SOSICMDD  0x200000   //sosi cmd option DEL          //~va6cR~
#define XEEBCO_B2B       0x400000   //ebc codepage change          //~va7tI~
#define XEEBCO_DBCSUCSOK 0x800000   //allow dbcs for b2dd part of b2b//~va7tI~
#define XEEBCO_CALLOC    0x01000000   //dbcstbl null initialied    //~va7xR~
//#define XEEBCO_ERRREP2   0x03000000   //for xprint set ".." for err dbcs//~va80I~//~vag7R~
#define XEEBCO_ERRREP2   0x02000000   //for xprint set ".." for err dbcs//~vag7I~
#define XEEBCO_ERRREP3   0x04000000   //set subchar for conv err   //+vag6I~
                                                                   //~va50I~
XEEBC_EXT char *Gebccfgfnm;                                        //~va50I~
//*********************************************************************//~va7tI~
int xeebc_b2b(int Popt,int Poldhandle,int Pnewhandle,UCHAR *Pdata,UCHAR *Pdbcs,int Plen,UCHAR **Ppoutdata,UCHAR **Ppoutdbcs,int *Ppoutlen);//~va7tI~
//*********************************************************************//~va50R~
int xeebc_b2mpsd(int Popt,PULINEH Pplh,UCHAR *Pdata,UCHAR *Pdbcs,int Plen,int Pbinsw);//~va50I~
//*********************************************************************//~va50I~
int xeebc_init(int Popt,void *Pcfgfile);                           //~va50R~
#define XEEBCIO_CFGFILE       0x01    //from ini2.c                //~va50R~
#define XEEBCIO_INIT          0x02    //from xe.c                  //~va50I~
#define XEEBCIO_CHKCFG        0x08    //chk cfg err                //~va50I~
#define XEEBCIO_NOMSG         0x10    //chk cfg err but no errmsg  //~va50I~
#define XEEBCIO_GETDEFAULT    0x20    //get default cfg by ini parm or default filename//~va5LI~
//*********************************************************************//~va50I~
void xeebc_term(int Popt);                                         //~va50I~
//*********************************************************************//~va50I~
int xeebc_setdbcstblplh(int Popt,PUFILEH Ppfh,PULINEH Pplh,int Plen);//~va50R~
#define XEEBC_setdbcstblplh(swebc,Ppfh,Pplh) \
	if (swebc) xeebc_setdbcstblplh(0,Ppfh,Pplh,0);                 //~va5LI~
//*********************************************************************//~va50I~
//int xeebc_setdbcstbl(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Plen); //~va50I~//~va79R~
int xeebc_setdbcstbl(int Popt,int Phandle,UCHAR *Pdata,UCHAR *Pdbcs,int Plen);//~va79I~
//*********************************************************************//~va50I~
int xeebc_chargetkbd(int Popt,PUCLIENTWE Ppcw);                    //~va50I~
//*********************************************************************//~va50I~
int xeebc_filesetsosi(int Popt,int Pmode,PUFILEH Ppfh,PULINEH Pplh,int Ppos,//~va50M~
					UCHAR *Pkeyindata,int Pkeyindatalen,UCHAR *Pkeyindata_ebc,UCHAR *Pkeyindata_ebcdbcs,int *Ppkeyindatalen_ebc);//~va50M~
#define XEEBCSO_OPTMASK        0xffff    //expand chk only         //~va50R~
#define XEEBCSO_EXPANDCHK    0x010000      //expand chk only       //~va50R~
#define XEEBCSO_BIN          0x020000      //bin file              //~va50R~
#define XEEBCSO_ERRREP       0x040000      //                      //~va50R~
#define XEEBCSO_CAPINS       0x080000      //C&P insert            //~va8bR~
#define XEEBCSO_SETDBCSTBL   0x100000      //setdbcstbl after update//~va8bI~
#define XEEBCSO_BNDSSORT     0x200000      //cap for bnds sort     //~va8hI~
#define XEEBCSO_SBCS         0x400000      //no dbcs split consideration//~va8iI~
                                                                   //~va50I~
#define XEEBCSW_INSSO      0x01    //insert SO to prev column      //~va50R~
#define XEEBCSW_INSSI      0x02    //insert SI to next column                ++addlen//~va50R~
#define XEEBCSW_INSSO2     0x04    //insert SO after inserted SI   //~va50R~
#define XEEBCSW_SETDBCSTBL 0x08    //reset dbcstbl                 //~va50R~
#define XEEBCSW_KEYINDBCS  0x10    //keyindata is dbcs             //~va50R~
#define XEEBCSW_BIN        0x20    //keyindata is dbcs             //~va50R~
#define XEEBCSW_KEEPDBCSTB 0x40    //keyindata is dbcs             //~va50R~
//#define XEEBCSW_INITBIN    0x80    //init clear for bin file       //~va50I~//~va7xR~
#define XEEBCSW_INSSOTAIL   0x0100                                 //~va8bI~
#define XEEBCSW_INSSIHEAD   0x0200                                 //~va8bI~
#define XEEBCSW_PREV2SPACE  0x0400                                 //~va8bI~
#define XEEBCSW_NEXT2SPACE  0x0800                                 //~va8bI~
//*********************************************************************//~va8bI~
int xeebc_filesetsosiplh(int Popt,PUFILEH Ppfh,PULINEH Pplh,int Ppos,//~va8bI~
					UCHAR *Psrcdata,UCHAR *Psrcdbcs,int Psrclen,   //~va8bI~
                    UCHAR **Ppoutdata,UCHAR **Ppoutdbcs,int *Ppoutlen);//~va8bI~
//*********************************************************************//~va8jI~
int xeebc_setdbcssplitsetsosi(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Plen,int Prepch);//~va8jI~//~va8kR~
#define XEEBCSDSO_HALFCUTONLY      0x01   //rep half cut only      //~va8kI~
#define XEEBCSDSO_GETSPLITCTR      0x02   //count space replaced by dbcssplit//~va8sR~
#define XEEBCSDSO_PREV2ND          0x04   //left boundary is next of dbcs2nd//~va8wI~
#define XEEBCSDSO_HALFCUTONLYL     0x08   //rep half cut only on left boundary//~va8wI~
#define XEEBCSDSO_HALFCUTONLYR     0x10   //rep half cut only on right boundary//~va8wR~
//#define XEEBCSDSO_OBR1ST           0x20                          //~va8wR~
//#define XEEBCSDSO_OBL2ND           0x40                          //~va8wR~
#define XEEBCSDSO_NEXTSI           0x20                            //~va8wI~
#define XEEBCSDSO_PREVSO           0x40                            //~va8wI~
#define XEEBCSDSO_NEXT1ST          0x80   //next of right boundary is dbcs1st//~va8wR~
                                                                   //~va8wI~
#define XEEBCSDSRC_REP             0x01    //replaced              //~va8wI~
#define XEEBCSDSRC_REPSO           0x02    //DBCS2ND replaced to SO at left inner boundary//~va8wI~
#define XEEBCSDSRC_REPSI           0x04    //DBCS1ST replaced to SI at right inner boundary//~va8wI~
//*********************************************************************//~va8kI~
int xeebc_setdbcssplitsetsosiOB(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Pdatalen,int Ppos,int Prangelen,int Prepch);//~va8kR~
#define XEEBCSDSOBO_NOSOSIDBCSCONCAT          0x01                 //~va8wI~
//*********************************************************************//~va8kI~
int xeebc_dbcssplitlen(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Plen,int *Ppsplitlen);//~va8kR~
#define XEEBCDSLO_EXPANDABLE      0x01	//add SI if len is after dbcs2nd//~va8kI~
#define XEEBCDSLO_IRB2NDOK        0x02	//cuttable after dbcs2nd   //~va8wI~
#define XEEBCDSLO_SIFOLLOWS       0x04	//1 more byte-SI follows   //~va8wI~
//*********************************************************************//~va8bI~
int xeebc_filesetsosiplhupdate(int Popt,int Psosiopt,PUFILEH Ppfh,PULINEH Pplh,int Ppos,int Pdestlen,//~va8bR~
					UCHAR *Psrcdata,UCHAR *Psrcdbcs,int Psrclen);  //~va8bI~
//*********************************************************************//~va50I~
int xeebc_getdbcssplitctr(int Popt,PUFILEH Ppfh,PULINEH Pplh,int Ppos,int *Ppdelctr,int *Ppbackctr);//~va50I~
//*********************************************************************//~va50I~
//int xeebc_b2msetdbcs(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Plen,UCHAR **Poutdata,UCHAR **Poutdbcs,int *Ppoutlen);//~va50R~//~va79R~
int xeebc_b2msetdbcs(int Popt,int Phandle,UCHAR *Pdata,UCHAR *Pdbcs,int Plen,UCHAR **Poutdata,UCHAR **Poutdbcs,int *Ppoutlen);//~va79I~
//*********************************************************************//~va50I~
//int xeebc_m2bsetdbcs(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Plen,UCHAR **Poutdata,UCHAR **Poutdbcs,int *Ppoutlen);//~va50R~//~va79R~
int xeebc_m2bsetdbcs(int Popt,int Phandle,UCHAR *Pdata,UCHAR *Pdbcs,int Plen,UCHAR **Poutdata,UCHAR **Poutdbcs,int *Ppoutlen);//~va79I~
//*********************************************************************//~va7sI~
int xeebc_f2bsetdbcs(int Popt,int Phandle,UCHAR *Putf8,int Putf8len,UCHAR **Ppoutdata,UCHAR **Ppoutdbcs,int *Ppoutlen);//~va7sI~
//*********************************************************************//~va50I~
int xeebc_linechk(int Popt,PULINEH Pplh);                          //~va50I~
//*********************************************************************//~va50I~
//int xeebc_b2syn(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Pdatalen,UCHAR **Ppsyndata);//~va50I~//~va79R~
int xeebc_b2syn(int Popt,int Phandle,UCHAR *Pdata,UCHAR *Pdbcs,int Pdatalen,UCHAR **Ppsyndata);//~va79I~
//*********************************************************************//~va50I~
//int xeebc_cvdatawb(int Popt,char *Pinp,int Pinplen,UCHAR **Ppout,int *Ppoutlen,UCHAR *Pdbcs,int Pdbcstblen);//~va50R~//~va79R~
int xeebc_cvdatawb(int Popt,int Phandle,char *Pinp,int Pinplen,UCHAR **Ppout,int *Ppoutlen,UCHAR *Pdbcs,int Pdbcstblen);//~va79I~
//*********************************************************************//~va50I~
//int xeebc_b2fl(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Plen,UCHAR *Poutu8,int Pu8buffsz,int *Ppu8len,//~va50I~//~va79R~
int xeebc_b2fl(int Popt,int Phandle,UCHAR *Pdata,UCHAR *Pdbcs,int Plen,UCHAR *Poutu8,int Pu8buffsz,int *Ppu8len,//~va79I~
				UCHAR *Poutlc,UCHAR *Poutdbcs,UCHAR *Poutct,int Plcbuffsz,int *Pplclen);//~va50I~
//*********************************************************************//~va50I~
//int xeebc_modechng(int Popt,PUFILEH Ppfhd,PUFILEH Ppfhs,UCHAR *Pdata,UCHAR *Pdbcs,int Pdatalen,//~va50R~//~va7yR~
int xeebc_modechng(int Popt,PUFILEH Ppfhd,PUFILEH Ppfhs,int Psrchandle,UCHAR *Pdata,UCHAR *Pdbcs,int Pdatalen,//~va7yI~
					UCHAR **Ppoutdata,UCHAR **Ppoutdbcs,int *Ppoutlen);//~va50I~
//*********************************************************************//~va50I~
//int xeebc_ascii2b(int Popt,UCHAR *Pdata,int Plen,UCHAR **Ppoutdata);//~va50R~//~va79R~
int xeebc_ascii2b(int Popt,int Phandle,UCHAR *Pdata,int Plen,UCHAR **Ppoutdata);//~va79R~
//*********************************************************************//~va50I~
//int xeebc_m2bsrchstr(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Plen,char *Poutdata,char *Poutdbcs,int Poutbuffsz,int *Ppoutlen);//~va50R~//~va79R~
int xeebc_m2bsrchstr(int Popt,int Phandle,UCHAR *Pdata,UCHAR *Pdbcs,int Plen,char *Poutdata,char *Poutdbcs,int Poutbuffsz,int *Ppoutlen);//~va79I~
//*********************************************************************//~va50I~
//UCHAR *xeebc_umemmem_bandl(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,UCHAR *Pmbstr,int Plen,int Plenmb);//~va50I~//~va79R~
UCHAR *xeebc_umemmem_bandl(int Popt,int Phandle,UCHAR *Pdata,UCHAR *Pdbcs,UCHAR *Pmbstr,int Plen,int Plenmb);//~va79I~
//*********************************************************************//~va50I~
int xeebc_m2ddebc(int Popt,PUFILEH Ppfh,UCHAR *Pdata,int Plen,char *Poutdata,char *Poutdbcs,int Poutbuffsz,int *Ppoutlen);//~va50I~
#define XEEBCM2DEO_SAVECT     0x01                                 //~va50I~
#define XEEBCM2DEO_ERRMSG     0x02                                 //~va50I~
//*********************************************************************//~va6cI~
//int xeebc_cvmemcmp(int Popt,UCHAR *Pebcdata,UCHAR *Pebcdbcs,int Pebclen,//~va6cR~//~va79R~
int xeebc_cvmemcmp(int Popt,int Phandle,UCHAR *Pebcdata,UCHAR *Pebcdbcs,int Pebclen,//~va79I~
						UCHAR *Pdata,UCHAR *Pdbcs,int Plen,int *Pppos1,int *Ppos2);//~va6cI~
#define XEEBCMC_UTF8   0x01   //comp ebc and utf8                  //~va6cI~
//*********************************************************************//~va7xI~
int xeebc_cvmemcmpb2b(int Popt,int Phandle1,UCHAR *Pdata1,UCHAR *Pdbcs1,int Plen1,//~va7xI~
                            int Phandle2,UCHAR *Pdata2,UCHAR *Pdbcs2,int Plen2,//~va7xI~
						int *Pppos1,int *Pppos2);                  //~va7xI~
//*********************************************************************//~va79I~
int xeebc_createhandle(int Popt,PUFILEH Ppfh,char *Pcvname,int *Pphandle);//~va79I~
//*********************************************************************//~va6cI~
int xeebc_b2f(int Popt,int Pebcopt,int Phandle,UCHAR *Pdata,int Plen,UCHAR **Ppoutu8,int *Ppu8len);//~vaacR~
//*********************************************************************//~va8wI~
int xeebc_f2b(int Popt,int Pebcopt,int Phandle,UCHAR *Pdata,int Plen,UCHAR **Ppoutebc,int *Ppebclen);//~vaacR~
#endif //UTF8EBCS raw ebcdic file support                          //~va50I~
//*********************************************************************//~va6cI~
