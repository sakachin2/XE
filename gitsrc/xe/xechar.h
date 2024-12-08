//CID://+va50R~:                                                   //~v74jR~//~va0tR~//~va3SR~//~va50R~
//****************************************************************
//xchar.h
//****************************************************************
//va50:100324 Raw EBCDIC file support for NFS mount                //~va50I~
//va3S:100322 (BUG)"S" lcmd replace split dbcs to space,it should be avoid when split on vhex line//~va3SI~
//va0t:090913!maintains locale and utf8 code for panel input(cmdline,panutil)//~va0tI~
//v74j:070216 (BUG)C&P del fail by join fail for margined file.    //~v74jI~
//            (by remaining oom of 1st line;delete oom for 1stline for region cut)//~v74jI~
//v74i:070216 (BUG)C&P paste to region fail by join fail for margined file.//~v74iI~
//            (ignore space before margin when join and keep oom(ignore oom for spf but)//~v74iI~
//v74e:070215 (BUG)C&P ceare regin clear oom only for margined file//~v74eI~
//v71H:061103 (3270)for RECFM=F,set UFHlrecl                       //~v71HI~
//v42g:010929 spf join ignoreing num fld                           //~v42gI~
//v0i7:980520 line cmd split cmd('S')/join('J') support            //~v0i7I~
//v0et:970921 split char12 from char                               //~v0avI~
//v0av:970720-fixed lrecl support(mergin support,MAXLEN=nn[N])     //~v0avI~
//           -charmaxovererr has maxlen parm                       //~v0avI~
//**************************************************************** //~v0avI~
#define CHAROPREP	0		//replace
#define CHAROPINS	1		//insert
#define CHAROPDEL	2		//delete
#define CHAROPEEOL	3		//erase eol                         //~4C25R~
#define CHAROPETOL	4		//erase tol                         //~4C25I~
#define CHAROPCTOL	5		//clear tol                         //~5111I~
#define CHAROPMGET  6   	//cut middle point for cut and paste//~5125R~
#define CHAROPIMJOIN 7  	//join in margin for spf               //~v42gI~
#define CHAROPCTOLIM 8  	//clear tol (ignore margin)            //~v74eI~
#define CHAROPJOINIGM 9 	//join ignore margin(do shiftback)     //~v74iI~
#define CHAROPEEOLIGM 10  	//erase eol (ignore margin)            //~v74jI~
#define CHAROPETOLCOB 11  	//erase tol (consider cobol margin,keep col.1-6 if curcol >6)//~v74jI~
//**************************************************
int charpan(PUCLIENTWE Ppcw,int Popt);

//**************************************************
int charfile(PUCLIENTWE Ppcw,int Popt);
//**************************************************            //~5107I~
int charmaxovererr(int Pmaxlen);                                   //~v0avI~
//**************************************************               //~v71HI~
int charfixlenovererr(int Plrecl);                                 //~v71HI~
//**************************************************               //~v0avI~
int charmerginerr(int Pmaxlen);                                    //~v0avI~
//**************************************************            //~5124I~
int charfldedit(int Pmode,UCHAR *Pbuff,UCHAR *Pdbcs,            //~5124I~
				int Pcurcol,int Pstartcol,int Pendcol,int Pbuffend,//~5124I~
				PUCLIENTWE Ppcw,PULINEH Pplh);                  //~5124I~
#define CFEO_OPCODEMASK       0x00ff    //opcode mask(rep,ins,del,...)//~va0tI~
#define CFEO_VHEXMODE         0xff00    //vhexmode mask            //~va0tI~
#define CFEO_OPTMASK        0xff0000    //vhexmode mask            //~va0tI~
#define CFEO_OPTCMDLINE     0x010000    //cmdline                  //~va0tR~
#define CFEO_OPTPANUTIL     0x020000    //panutil line             //~va0tR~
#define CFEO_OPTPANFNM      0x040000    //fnm panel                //~va0tI~
#define CFEO_VHEXLCMDS    0x01000000    //split lcmd on vhex line  //~va3SI~
//**************************************************               //~va50I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	int charfldeditebc(int Pmode,UCHAR *Pbuff,UCHAR *Pdbcs,        //~va50I~
				int Pcurcol,int Pstartcol,int Pendcol,int Pbuffend,//~va50I~
				PUCLIENTWE Ppcw,PULINEH Pplh,                      //+va50R~
                PULINEH Plcmdplh2,int Pnetlen,int Pnetoomlen);     //+va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//**************************************************            //~5211I~
int chartabexp(PULINEH Pplh,UCHAR **Pdata0,UCHAR **Pdbcs0,      //~5507M~
	UCHAR **Pdata,UCHAR **Pdbcs,int Pcurcol,int Plen,int *Paddlen);//~5507M~
                                                                   //~v0i7I~
//**************************************************               //~v0i7I~
//int charlcmdjoin(PUCLIENTWE Ppcw,PULINEH Pplh1,PULINEH Pplh2);   //~v74iR~
int charlcmdjoin(int Popt,PUCLIENTWE Ppcw,PULINEH Pplh1,PULINEH Pplh2);//~v74iI~
#define CLJ_IGM     0x01 //ignore margin(keep oom) for stdpaste     //~v74iI~
//**************************************************               //~v74iI~
int charjoinchk(PUCLIENTWE Ppcw,PULINEH Pplh1,PULINEH Pplh2,int Pcol,int Popt);//~v74iI~
#define INMARGINJOIN  0x1000                                       //~v74iI~
#define IGMARGINJOIN  0x2000                                       //~v74iI~
