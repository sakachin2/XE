//*CID://+vbEnR~:                             update#=   48;       //~vbEnR~
//****************************************************************
//xefile6.h
//****************************************************************
//vbEn:251201 (W32 bug)under combinemode;u-309a(handakuten such as for katakana-Po) is not shown as split mode even when csr is on//~vbEnI~
//             set celldraw always if utf8 file contains unicode   //~vbEnI~
//vamF:131119 (BUG)"xpr **/***" fails by "input fmt err" for vhex utf,fold at 0x0a for lc file.//~vamFI~
//va81:100920 (WXEXXE)print ebcfile by ucs for alos wxp **/*** option//~va81I~
//va80:100917 (WXEXXE)print ebcfile by ucs                         //~va80I~
//va79:100809 cpeb converter parm support                          //~va79I~
//va6c:100619 add SOSI option -S{i|r|d} to REP/CRE/APP/SAV/COP/MOV cmd//~va6cI~
//va5L:100523 (w)xpr cmd;print SO/SI by "?"                        //~va5LI~
//va50:100324 Raw EBCDIC file support for NFS mount                //~va50I~
//va46:100331 not use ctrl char for tab and tab padding,but use xff as default//~va46I~
//va20:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~va20I~
//va00:090510 merge utf8 version(enclosed by UTF8SUPPH)            //~va00I~
//          files encoded by utf8                                  //~va00I~
//          ignore translation err for utility result file(parm to edit_file2)//~va00I~
//v8@2:080529 save tabctr in profile                               //~v8@2I~
//v71U:061112 (BUG)accept insert in short(<mergin) record of margined file//~v66fI~
//            even if result is over margin but overflow is space only//~v66fI~
//v66f:051021 support standard mode cut & paste,assign Ctrl+v for stream insert.(split xecap.c to xecap2.c)//~v66fI~
//                     None   OpenBlock  ClosedBlock   OpenRegion ClosedRegion//~v66fI~
//            C+v    RgnIns   NoBlockErr BlockClearRep OpenRgnErr RgnDel+Ins//~v66fI~
//            A+Ins  BlockIns NoBlockErr GetBlock+Ins  OpenRgnErr RgnDel+Ins//~v66fI~
//            A+Rep  BlockRep NoBlockErr GetBlock+Rep  OpenRgnErr RgnDel+Ins//~v66fI~
//v61x:050308 xprint for binfile(rep to "." from crlf etc ctlchar) //~v61xI~
//v50j:021230 cv cmd:ajust conv err pos by tab expand              //~v50jI~
//v50f:021229 (BUG)tab disappear by cv cmd                         //~v50fI~
//v20U:001119 display tab and dbcs space when binary mode          //~v20UI~
//v0hJ:980418 support "tab clear" cmd                              //~v0hJI~
//v0ev:970922 abondan /v0ep/v0er/v0es/v0eu;                        //~v0evI~
//            use filetabexp2(expand in mergin only)               //~v0evI~
//v0bz:970728 if last is tab,expandlen over mergin cause expand err.//~v0bzI~
//            but it can be cut in mergin and set cid on normal pos.//~v0bzI~
//v0b3:970723 clear tab when shift,it is easy to expectate.        //~v0b3I~
//v0av:970720-fixed lrecl support(mergin support,MAXLEN=nn[N])     //~v0avI~
//           -expand pre chk                                       //~v0avI~
//****************************************************************
int filechktabdbcs(PULINEH Pplh);                               //~5102I~
//**************************************************************** //~va6cI~
int filechktabdbcs2(int Popt,int Pcopyopt,PULINEH Pplh);           //~va6cI~
#define FCTDO_COPYFILE     0x01    //fcmd copy/move                //~va6cI~
                                                                //~5102I~
//**************************************************************** //~va20I~
//**************************************************************** //~va00I~
#ifdef UTF8SUPPH                                                   //~va00I~
int filechkutf8encoding(int Popt,PUCLIENTWE Ppcw,int Pbinsw,PUFILEH Ppfh);//~va00R~
#define FCU8EO_NOMSG         0x01                                  //~va00I~
#define FCU8EO_IE            0x02  //ignore f2l err                //~va00I~
#endif                                                             //~va00I~
//****************************************************************//~5102I~
int filetabexp(int Preexpsw,PULINEH Pplh,int Pcol,int *Plen);   //~5102I~
                                                                   //~v0evI~
//**************************************************************** //~v0evI~
int fileimtabexp(PULINEH Pplh,int Pcol,int *Pplen,int Pmergin);    //~v0evI~

//**************************************************************** //~v0avI~
#ifdef UTF8UCS2                                                    //~va20I~
int filegettabexplen(PULINEH Pplh,int Pcol,char *Padddata,char *Padddbcs/*dd fmt for u8 file*/,//~va20I~
#else                                                              //~va20I~
int filegettabexplen(PULINEH Pplh,int Pcol,char *Padddata,         //~v0b3I~
#endif                                                             //~va20I~
					int Paddlen,int Pdellen,int Plen);             //~v0bzI~
//**************************************************************** //~v66fI~
int filegettabexplenofmargined(int Popt,int Pmargin,PULINEH Pplh,int Pcol,char *Padddata,//~v66fI~
#ifdef UTF8UCS2                                                    //~va20I~
					char *Padddbcs,                                //~va20I~
#endif                                                             //~va20I~
					int Paddlen,int Pdellen,int Plen,int *Ppaddlen);//~v66fI~
//**************************************************************** //~v0avI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
int tabdisplay(PULINEH Pplh,UCHAR *Pdata,UCHAR *Pdbcs,int Plen,int Pbinsw);//~va50I~
#else                                                              //~va50I~
int tabdisplay(UCHAR *Pdata,UCHAR *Pdbcs,int Plen,int Pbinsw);     //~v20UR~
#endif //UTF8EBCS raw ebcdic file support                          //~va50I~
#ifdef UTF8UCS2                                                    //~va20I~
	#define FILETDO_BINSWMASK     0xff                             //~va20I~
#ifdef UTF8UCS2                                                    //~va20I~
	#define FILETDO_UTF8        0x0100 //file is cpu8              //~va20R~
	#define FILETDO_PRINT       0x0200 //tabdisplay for file print //~va20I~
	#define FILETDO_PRINTGUI    0x0400 //tabdisplay for file print //~va46I~
	#define FILETDO_NONASCII    0x0800 //return !=0 if detected non asdcii unicode in utf8 file//+vbEnR~
#endif                                                             //~va20I~
#endif                                                             //~va20I~
//**************************************************************** //~v61xI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
int tabdisplayforxpr(int Popt,PULINEH Pplh,UCHAR *Pdata,UCHAR *Pdbcs,int Plen);//~va50R~
#define TDXPO_TEXT        0x01                                         //~va50I~//~va5LR~
#define TDXPO_TEXTFILE    0x02       //not scr print               //~va5LI~
#define TDXPO_EBCBYUCS    0x04       //set dd fmt to print line for ebcfile//~va80I~
#define TDXPO_EBCSPLITCHK 0x08       //line may sprit by page width for ebc file//~va80I~
#define TDXPO_WXPWK       0x10       //print for **/*** option     //~va81I~
#else                                                              //~va50I~
int tabdisplayforxpr(UCHAR *Pdata,UCHAR *Pdbcs,int Plen);          //~v61xI~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
#ifdef UTF8UCS2                                                    //~va20I~
int tabdisplayforxpru8(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Plen);//~va20I~
#endif                                                             //~va20I~
//**************************************************************** //~vamFI~
int tabdisplayforxprrecord(int Popt,PULINEH Pplh,UCHAR *Pdata,UCHAR *Pdbcs,int Plen);//~vamFI~
//**************************************************************** //~va80I~
int tabdisplayforxprebcbyucs(int Popt,int Phandle,PULINEH Pplh,UCHAR *Pdata,UCHAR *Pdbcs,int Poffs,int Plen);//~va80R~
                                                                   //~v0avI~
//**************************************************************** //~v0b3I~
void filetabclear(PULINEH Pplh);                                   //~v0b3I~
                                                                   //~v0hJI~
//**************************************************************** //~v0hJM~
int filetabclearall(PUCLIENTWE Ppcw);                              //~v0hJM~
                                                                   //~v50fI~
//**************************************************************** //~v50fI~
int filetabrestore(PUFILEH Ppfh,PULINEH Pplh,UCHAR *Poutbuff,int Poutbufflen,int *Poutlen);//~v50fR~
#define FTRRC_TABDETECTED    1                                     //~v50fI~
#define FTRRC_NOTABDETECTED  2                                     //~v50fI~
#define FTRRC_NOTYETEXPANDED 3                                     //~v50fI~
#define FTRRC_BUFFOVERFLOW   4                                     //~v50fI~
                                                                   //~v50jI~
//**************************************************************** //~v50jI~
//int filetgettabexplensub(int Pbinsw,char *Pdata,int Plen);       //~v8@2R~
int filetgettabexplensub(int Pbinsw,char *Pdata,int Plen,int Ptabskip);//~v8@2I~
//**************************************************************** //~v66fI~
int filepfhchktabdbcs(PUFILEH Ppfh);                               //~v66fR~
//**************************************************************** //~va20I~
#ifdef UTF8UCS2                                                    //~va20I~
	int filecvl2dd(int Popt,PUFILEH Ppfh,PULINEH Pplh);            //~va20R~
	int filechktabdbcsreset(int Popt,PUFILEH Ppfh,PULINEH Pplh);   //~va20I~
	int filecvdd2l(int Popt,PUFILEH Ppfh,PULINEH Pplh);            //~va20I~
//  int filecvaftercopy(int Popt,PUFILEH Ppfh,PULINEH Pplh);       //~va20I~//~va79R~
    int filecvaftercopy(int Popt,PUFILEH Ppfh,PULINEH Pplh,PUFILEH Ppfhs);//~va79R~
	#define FCVACO_DD2L   0x01                                     //~va20I~
	#define FCVACO_L2DD   0x02                                     //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	#define FCVACO_B2     0x04     //souce is ebc                  //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
#endif                                                             //~va20I~
