//**Fixed-CID://+vaw3R~:** update#=     9                          //~vaw3R~
//****************************************************************//~4C23I~
//xefile4.h                                                     //~4C23I~
//****************************************************************//~4C23I~
//vbw3:221205 accept cidtype by unicode fo cid on/clear cmd        //~vaw3I~
//vbv9:221124 add cid type apl for extension=.apl                  //~vav9I~
//vbv6:221121 support unicode cid (length>2)                       //~vav6I~
//va7J:100904 avoid topline cid option err("CID" was found on topline at tail of the line")//~va7JI~
//va20:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~va20I~
//v10z:990411 (BUG)pos of cid for split last line is too far.      //~v10zI~
//            it should consider prev split continued line length. //~v10zI~
//            (But probrem remain in the case cid is spritted or on prev line,//~v10zI~
//            new cid dose not replace but added.)                 //~v10zI~
//v0ef:970915 return ren same lensw instead of contlen             //~v0efI~
//v0dx:970914 split fileclear from xefile4.c                       //~v0dxI~
//v0df:970831 (BUG)cid not set if cont exist.(see also v0d3)       //~v0dfI~
//v0cz:970818 null cid //+NONE~R                                   //~v0ciI~
//v0ci:970810 (BUG)cid clear abend(oldpos is last cidpos)          //~v0ciI~
//v0cc:970803 filegetcidlen return last cidpos                     //~v0ccI~
//v0cb:970802 split allow for long rec even if at out of mergin    //~v0cbI~
//            EOL   allow for long rec even if at out of mergin    //~v0cbI~
//v0c8:970802 filecidlrecl return len in mergin if cidps<mergin    //~v0c8I~
//v0c1:970728 errornous cid shift when 2 continuous cid            //~v0c1I~
//v0bv:970728 split file4-->file42                                 //~v0bvI~
//v0be:970725 filemerginchk return lrecl witoutcid(change over v0b7)//~v0beI~
//v0b7:970725 filemerginchk return avail space(last data to mergin)//~v0b7I~
//v0av:970720-fixed lrecl support                                  //~v0avI~
//           -filetoplinecid/filegetcid return rc                  //~v0avI~
//           -charmaxovererr has maxlen parm                       //~v0avI~
//v09F:970614:CID postfix support                                  //~v09FI~
//            (change CIDTBL fmt,cidfmt conatin only prefix and postfix)//~v09FI~
//v09r:970521:arbitaly CID type by first line                      //~v09rI~
//            -filecidtypechk return cidtbl ptr not but cid for get pos//~v09rI~
//            -filegetcid parm 0:always chk first line,2 chk if sline==0//~v09rI~
//v06r:960325:cid pos for lineno field len =4 as default              //~v06rI~
//            and support CID shift(colomn re-arange)                 //~v06rI~
//*v014:950624:bug:when save not displayed line after copy file //~v014I~
//*v012:950611:fixed CID                                        //~5611I~
//****************************************************************//~5611I~
#define  	MAX_CIDPOS 	   20   //"CID" must appear in the col.1-20 of top line//~va7JI~
#define  	MAX_CIDOPTPOS  80   //OPTIONS=   appear in the col.1-80 of top line//~va7JI~
#define  	LINECIDLEN 		9   //                              //~4C23I~
#define  	LINECIDLENMAX  11   //                                 //~v09FI~
#define  	LINEPOSTFIXLEN  (LINECIDLENMAX-LINECIDLEN)             //~v09FI~
#define  	LINEPREFIXLEN   2                                      //~v09FI~
#define  	CIDEXTTBLSZ  	200   //                               //~v09FR~
typedef struct _CIDTBL {                                        //~5308I~
						UCHAR  CIDTid;		//id                //~5308I~
						UCHAR  CIDTpos; 	//cid set position  //~5528I~
                        UCHAR  CIDTcidfmt[6];	//cid prefix[2] and postfix[2]//~v09FI~
                        UCHAR  *CIDTexttbl;	//extention tbl     //~5308I~
//                      UCHAR  *CIDTcidfmt;	//cid edit format by printf//~v09FR~
                        UCHAR  *CIDTmalloc;	//malloc addr       //~5528I~
                        int    CIDTucs;                            //~vav9M~
                        UCHAR  CIDTddfmt[4];                       //~vav9M~
					  	} CIDTBL;                               //~5308I~
                                                                //~5528I~
//****************************************************************//~5528I~
CIDTBL *filegetcidtbl(void);                                    //~5528I~
                                                                //~5528I~
//****************************************************************//~5528I~
void filecidterm(void);                                         //~5528I~
                                                                //~5528I~
//****************************************************************//~5225I~
int filegetcid(PUFILEH Ppfh,int Popt,UCHAR *Ppostfix,UCHAR **Ppcid);//~v0avR~
                                                                //~4C23I~
//****************************************************************
int  filesetcid(PUFILEH Ppfh,PULINEH Pplh,UCHAR *Pdata,UCHAR *Pdbcs,//~v014R~
				UCHAR *Pcid,int *Paddlen,int Psplittotlen);        //~v10zR~

//************************************************************  //~5225I~
int  filecidlrecl(PULINEH Pplh,PUFILEH Ppfh);                   //~5225I~
                                                                //~5225I~
//************************************************************     //~v0cbI~
int  filegetcidlen(PULINEH Pplh,PUFILEH Ppfh,int *Plrecl,int *Ptopcidpos,int *Plastcidpos);//~v0ciI~
                                                                   //~v0c1I~
//************************************************************     //~v0cbI~
int  filecidlrecl2(PULINEH Pplh,PUFILEH Ppfh);                     //~v0cbI~
                                                                   //~v0cbI~
//************************************************************     //~v0cbI~
int  filegetcidlen2(PULINEH Pplh,PUFILEH Ppfh,int *Plrecl,int *Ptopcidpos,int *Plastcidpos);//~v0ciI~
                                                                   //~v0cbI~
//************************************************************     //~v0efI~
int  filegetcidlenc(PULINEH Pplh,PUFILEH Ppfh,int *Plrecl,int *Ptopcidpos,int *Plastcidpos,//~v0efI~
					int *Pcopylen);                                //~v0efI~
                                                                   //~v0dxI~
//************************************************************     //~v0ciI~
int  filecidlrecl3(PULINEH Pplh,PUFILEH Ppfh);                     //~v0ciI~
                                                                   //~v0ciI~
//************************************************************  //~5308I~
//int filecidtypechk(UCHAR *Ptype,int Palias);                     //~v09rR~
CIDTBL *filecidtypechk(UCHAR *Ptype,int Palias);                   //~v09rI~

//************************************************************
UCHAR *filegetcidtype(PUFILEH Ppfh);
                                                                   //~v0avI~
//************************************************************     //~vaw3I~
CIDTBL *filecidtypechkUTF8(PUFILEH Ppfh,UCHAR *Pprefix);           //+vaw3R~
//************************************************************     //~v0ciI~
#ifdef UTF8UCS2                                                    //~va20I~
//int fileiscid(char *Pcidfmt,char *Pcid,char *Pdbcs,int Pcidlen);   //~va20I~//~vav6R~
int fileiscid(PUFILEH Ppfh,char *Pcidfmt,char *Pcid,char *Pdbcs,int Pcidlen);//~vav6I~
#else                                                              //~va20I~
int fileiscid(char *Pcidfmt,char *Pcid,int Pcidlen);               //~v0ciI~
#endif                                                             //~va20I~
