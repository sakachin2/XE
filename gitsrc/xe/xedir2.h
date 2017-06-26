//*CID://+vb14R~:                             update#=   40;       //~vb14R~
//****************************************************************//~5618I~
//xedir2.h                                                      //~5618I~
//****************************************************************//~5618I~
//vb14:150613 0x00 is set for rename field display for U8-LC mixed string, set '.' for visibility//~vb14I~
//vawp:140607 (BUG)ddfmt display err for expand1 wildcard          //~vawpI~
//vaw9:140531 (W32UNICODE)recover UTF8 code on also rename fld     //~vaw9I~
//vauG:140316 (BUG)rfind(f5) misses utf8 code when searchword on cmdline.//~vauGI~
//vau3:140227 copy to clipboard from dirlist;consider utf8name;copy slinkname if csr is on it.//~vau3I~
//va1c:091030_merge GB18030 support                                //~va1cI~
//va0G:090725!rename fld by codetype                               //~va0GI~
//va00:090510 merge utf8 version(enclosed by UTF8SUPPH)            //~va00I~
//          rename/move.. by filename of the codepage              //~va00I~
//v690:060418 display file-description support on dir-list panel   //~v690I~
//v59f:041107 (BUG)attr change not availe for remotefile           //~v59fI~
//v56p:040406 UCWFWAKEUP flag is cleared after filewakeup is called by scrpopup,//~v56pI~
//            so dirdraw cannot chk wakeup/resize flag when called //~v56pI~
//v56m:040404 (BUG)scroll field is not displayed when dirlist is vsplited.//~v56mI~
//v53c:030921 alt+w for C&P copy word                              //~v53cI~
//v481:020420 (BUG)dir list search required ddsetup.(not found for not displayed line)//~v481I~
//v47C:020323 disket support;mkdir,rmdir,attrib                    //~v47CI~
//v203:000930 LINUX support(new attr specification)                //~v203I~
//v0k2:980920 use ueditfattr for dirattrstr                        //~v0k2I~
//*950610 v020 dir display support                              //~5618I~
//****************************************************************//~5618I~
//*DATA TYPE *******************************                    //~5618I~
//****************************************************************//~5723I~
//PUCLIENTWE dirregist(int Popt,PUFILEH Ppfh);                     //~v690R~
PUCLIENTWE dirregist(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh);       //~v690I~
                                                                //~5731I~
//**************************************************************** //~v56mI~
int dirwakeup(PUCLIENTWE Ppcw);                                    //~v56pR~
//*******************************************************          //~v481I~
void dirddsetup2(PUCLIENTWE Ppcw,PULINEH Pplh);                    //~v481R~
//*******************************************************       //~5731I~
int dirgetfldpos(PUCLIENTWE Ppcw,PULINEH Pplh,int Pfldno,UCHAR **Pout,UCHAR **Pdbcs);//~5731I~
//*******************************************************       //~5807I~
int dirgetflddata(PUCLIENTWE Ppcw,PULINEH Pplh,int Pfldno,UCHAR *Pout);//~5807I~
//*******************************************************       //~5807I~
int dirsetflddata(PUCLIENTWE Ppcw,PULINEH Pplh,int Pfldno,UCHAR *Pdata);//~5807I~
//*******************************************************       //~5826I~
void dirsetflderr(PUCLIENTWE Ppcw,PULINEH Pplh,int Pfldno);     //~5826I~
//*******************************************************       //~6105I~
int  dirsavename(PULINEH Pplh,UCHAR *Pname);                    //~6105I~
//*******************************************************          //~v690I~
#ifdef UTF8SUPPH                                                   //~va00I~
//*******************************************************          //~va00I~
	int dirgetflddata_l2f(int Popt,PUCLIENTWE Ppcw,PULINEH Pplh,int Pfldno,UCHAR *Pout,int *Ppswl2f);//~va00R~
    #define DGFDL2FO_UD		0x01	//output UD string for utf8 data//~vaw9I~
//  int dirsetflddata_f2l(int Popt,PUCLIENTWE Ppcw,PULINEH Pplh,int Pfldno,UCHAR *Pdata);//~va00I~//~va0GR~
    int dirsetflddata_f2l(int Popt,PUCLIENTWE Ppcw,PULINEH Pplh,int Pfldno,UCHAR *Pdata,UCHAR *Pdatalc);//~va0GI~
    #define DSFDF2LO_ERRREP 0x01	//set '.' for F2L err          //+vb14I~
//*******************************************************          //~va00I~
//  int  dirsavename_byutf8(int Popt,PULINEH Pplh,UCHAR *Pplc,UCHAR *Pputf8);                 //~v690I~//~va00R~//~va0GR~
	int  dirsavename_byutf8(int Popt,PULINEH Pplh,UCHAR *Pputf8,UCHAR *Pplc,int Pplcbuffsz,int *Ppplclen);//~va0GI~
//  #define DSN2O_F2L   0x01       //cv Pputf8->locale             //~va00I~//~va0GR~
                                                                   //~va00I~
//  #define BYUTF8_dirsavename(plh,namebyutf8)                     //~va0GR~
//  	dirsavename_byutf8(DSN2O_F2L,plh,0/*locale code*/,namebyutf8)//~va00I~//~va0GR~
    #define BYUTF8_dirgetflddata(pcw,plh,fldno,out) \
		dirgetflddata_l2f(0/*opt*/,pcw,plh,fldno,out,0/*out l2fsw*/)//~va00R~
//  #define BYUTF8_dirsetflddata(pcw,plh,fldno,data)               //~va0GR~
//  	dirsetflddata_f2l(0/*opt*/,pcw,plh,fldno,data)             //~va00R~//~va0GR~
	int dirsetdbcstbl(int Popt,char *Pdata,char *Pdbcs,int Plen);  //~va1cR~
	#define DSDTO_FULLLINE           0x01 //line is split by null  //~va1cR~
#else                                                              //~va00I~
//  #define BYUTF8_dirsavename(plh,name)                           //~va0GR~
//  	dirsavename(plh,name)                                      //~va00I~//~va0GR~
    #define BYUTF8_dirgetflddata(pcw,plh,fldno,out) \
		dirgetflddata(pcw,plh,fldno,out)                           //~va00R~
//  #define BYUTF8_dirsetflddata(pcw,plh,fldno,data)               //~va0GR~
//  	dirsetflddata(pcw,plh,fldno,data)                          //~va00R~//~va0GR~
#endif                                                             //~va00I~
//*******************************************************       //~5903I~
//void dirattrstring(UCHAR Pattr,UCHAR *Pout);                     //~v0k2R~
//*******************************************************       //~5903I~
#ifdef UNX                                                         //~v203I~
                                                                   //~v203I~
ULONG dirattrbit(UCHAR **Ppattr);                                  //~v203I~
ULONG dirattrbit_mdos(UCHAR Pattrchar);                            //~v47CI~
                                                                   //~v203I~
#else  //!UNX                                                      //~v203I~
                                                                   //~v203I~
	#ifdef FTPSUPP                                                 //~v59fI~
		ULONG dirattrbitremote(UCHAR **Ppattr);                    //~v59fI~
	#endif                                                         //~v59fI~
UCHAR dirattrbit(UCHAR Pattrchar);                              //~5903I~
                                                                   //~v203I~
#endif //!UNX                                                      //~v203I~
//*******************************************************          //~v53cI~
//int dirgetword(PUCLIENTWE Ppcw,char *Pword,int Plen);              //~v53cI~//~vau3R~
//int dirgetword(PUCLIENTWE Ppcw,char *Pword,int Plen,int *Pstrtype);//~vau3I~//~vauGR~
int dirgetword(PUCLIENTWE Ppcw,char *Pword,int Plen,int *Pstrtype,char **Ppdddata,char **Ppdddbcs,int *Ppddlen);//~vauGR~
int dirsetflddataDDFMT2(PUCLIENTWE Ppcw,PULINEH Pplh,int Pfldno,char *Pdata);//~vawpI~
int dirsavenameDDFMT2(int Popt,PULINEH Pplh,UCHAR *Putf8);         //~vawpI~
