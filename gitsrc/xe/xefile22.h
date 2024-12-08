//*CID://+va81R~:                             update#=   60;       //~va81R~
//**************************************************************** //~v440I~
//xefile22.h                                                       //~v440I~
//**************************************************************** //~v440I~
//va81:100920 (WXEXXE)print ebcfile by ucs for alos wxp **/*** option//~va81I~
//va7M:100905 bin file vhex mode;csr was step down(reason was duplicated code definition)//~va7MI~
//va7k:100821 (BUG)FWF cmd;getword fail on ebc file when delm str input is by utf8.//~va7kI~
//va3T:100322 Hex cmd:add option to zigzag csr move mode HEX [YZ|NZ]//~va3TI~
//va20:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~va20I~
//            file22.c:vhexline display from dd fmt                //~va20I~
//va1c:091030_merge GB18030 support                                //~va1cI~
//v7av:090411 allow dbcs boundary char for FWF/FWB                 //~v7avI~
//v77E:080203 FW(C+"["/"]")/IW(A+"["|"]") cmd support              //~v77EI~
//v773:071121*Ctrl+Tab for function that cursor jump between char and ehx part//~v773I~
//v73n:070117 (BUG)hexmode edit cursor DEL on hex part should back 1 col if data is longer than width//~v73nI~
//v61w:050308 xprint on vhex mode                                  //~v61wI~
//v60v:050201 virtual hex display option(/Mx,HEX on/off,prev HEX is XIN)//~v60vI~
//v59v:041114 (BUG)hex disp mode:display char part column when csr is on hex part//~v59vR~
//v59u:041114 (BUG)hexinput:del cur pos if csr is on later half of byte//~v59vR~
//v53c:030921 alt+w for C&P copy word                              //~v53cI~
//v446:011201 default cols data for hex edit                       //~v446I~
//v445:011201 binary file support for xprint **/***                //~v445I~
//v443:011201 colr on data csr corresponding on csr on hex part    //~v443I~
//v442:011201 skip csr over hex intermidiate space                 //~v442I~
//v441:011130 edit   hex                                           //~v440I~
//v440:011125 browse hex                                           //~v440I~
//**************************************************************** //~v440I~
#define HEXMARGIN   3                                              //~v440R~
#define MAX_HEXBIN_WIDTH  256                                      //~v440I~
//#define UCWREASON_HEXSTEP   0x81    //csr step over intermediate space//~v442I~//~va7MR~
//#define UCWREASON_HEXSTEPDEL   0x82 //delete hex part shift to left//~v73nI~//~va7MR~
//#define UCWREASON_DELEOLGB4    0x83 //join by delete end of line,gb4 case//~va1cR~//~va7MR~
//#define UCWREASON_VHEX1STEP    0x84 //rep/ins on vhex upper line   //~va3TR~//~va7MR~
//#define UCWREASON_VHEX2STEP    0x85 //rep/ins on vhex lower line   //~va3TI~//~va7MR~
//**************************************************************** //~v440I~
//int filehexprint(PUCLIENTWE Ppcw,PULINEH Pplh);                    //~v445I~//~va81R~
int filehexprint(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH Pplh);//+va81R~
#define FHPO_WXPEBC      0x01      //wxp **/***                    //~va81I~
//**************************************************************** //~v445I~
UCHAR *filehexdisplay(PUCLIENTWE Ppcw,UCHAR *Ppdata,int Preslen,   //~v440R~
		int Pdatalen,PULINEH Pplh,int *Phexcsr,int *Pdatacsr);     //~v443I~
//**************************************************************** //~v440I~
int filegethposrange(PUFILEH Ppfh,int Pdatalen,int *Pptop,int *Ppend);//~v446R~
//**************************************************************** //~v440I~
int filecharhexinput(PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH Pplh,    //~v441R~
	    			int Pcsrpos,int *Ppdoffs,int Popcode);         //~v441R~
#define FCHI_HEX            1   //hex input                        //~v441I~
#define FCHI_ODDINS         2   //insert on second byte            //~v441I~
//**************************************************************** //~v53cI~
//int filegetword(PUCLIENTWE Ppcw,PULINEH *Ppplh,int *Ppos);       //~v77ER~
int filegetword(PUCLIENTWE Ppcw,PULINEH *Ppplh,int *Ppos,char *Pdelm);//~v77EI~
#define FGW_DELM_INCLUDE     'i'                                   //~v77ER~
#define FGW_DELM_EXCLUDE     'e'                                   //~v77ER~
#define FGW_DELM_PUNCT       'p'                                   //~v77ER~
#define FGW_DELM_INCLUDEM    'I'    //include multibyte            //~v7avI~
#define FGW_DELM_EXCLUDEM    'E'    //exclude multibyte            //~v7avI~
// multibyte len is Pdelm[1]/Pdelm[3],char follows Pdelm[4]...     //~v7avI~
#define FGW_DELM_MAXLEN      32     //max boundary strlen          //~v7avI~
#define FGW_DELM_STRUCSZ     (4+FGW_DELM_MAXLEN*2+(1+FGW_DELM_MAXLEN*2)*2)     //added ebc string (len+data+dbcs)*1//~va7kR~
//**************************************************************** //~v59uI~
int filegetdatapos(int Phpos,int Phpose,int Poffs,int *Ppdpos,int Popt);//~v59uI~
//**************************************************************** //~v59vI~
int filegethexcsrdpos(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh,int *Pppos);//~v59vR~
//**************************************************************** //~v60vI~
#ifdef UTF8UCS2                                                    //~va20I~
	int filevhexdisplay(int Popt,UCHAR *Pplhdata,UCHAR *Pplhdbcs,UCHAR *Ppsddata,UCHAR *Ppsddbcs,int Plen,int *Ppbuffsz);//~va20I~
#else                                                              //~va20I~
UCHAR *filevhexdisplay(int Popt,UCHAR *Pplhdata,UCHAR *Pplhdbcs,UCHAR *Ppsddata,UCHAR *Ppsddbcs,int Plen);//~v60vR~
#endif                                                             //~va20I~
//**************************************************************** //~v60vI~
//int filecharhexinput_v(UCHAR *Pkeyindata,int Pkeyindatalen,int Poldvalue,int Pmode,int Pvhexmode,UCHAR *Ppnewchar);//~va3TR~
int filecharhexinput_v(PUCLIENTWE Ppcw,UCHAR *Pkeyindata,int Pkeyindatalen,int Poldvalue,int Pmode,int Pvhexmode,UCHAR *Ppnewchar);//~va3TI~
//**************************************************************** //~v61wI~
//int filevhexprint(PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH Pplh,UCHAR *Plinenowk,int Plinenosz);//~v61wI~//~va81R~
int filevhexprint(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH Pplh,UCHAR *Plinenowk,int Plinenosz);//~va81I~
#define FVHPO_WXPEBC     0x01      //wxp **/***                    //~va81I~
//**************************************************************** //~v773I~
int filegethexpos(int Phpos,int Phpose,int Pdataoffs);             //~v773I~
