//CID://+v77fR~:                                                   //+v77fR~
//****************************************************************//~5308I~
//*xefcmd4.h                                                       //~9417R~
//****************************************************************//~5308I~
//v77f:071226*"spl [all] width CRLF" for change display width of text file//+v77fI~
//v75f:070423 SPL/TFLOW:correct err line counter                   //~v75fI~
//v75a:070419 lcmd TFn/":" support                                 //~v75aR~
//v74y:070223 new option to set COLS ON as default  "COLS ON ALL"  //~v74yI~
//v62H:050413 exe cmd label support                                //~v62HI~
//v54Y:040201 "cre/rep/sav/app" support -xall -nxall .a .b         //~v54YI~
//v45x:011219 integrate "num cutoff" cmd to "split" cmd            //~v45xI~
//v11N:990829 COL cmd support                                      //~v11NI~
//**************************************************************** //~v11NI~
void fcmdcolfree(PUFILEC Ppfc);                                    //~v11NR~
//**************************************************************** //~v45xI~
int fcmdsplit(PUCLIENTWE Ppcw);                                    //~v45xI~
//**************************************************************** //+v77fI~
int fcmdchangewidth(int Popt,PUCLIENTWE Ppcw,UFILEH *Ppfh,         //+v77fI~
						PULINEH Pplh1,PULINEH Pplh2,int Pwidth);   //+v77fI~
//**************************************************************** //~v45xI~
//int fcmdgetlabparm(PUCLIENTWE Ppcw,PULINEH *Ppplh1,PULINEH *Ppplh2,int Popt);//~v62HR~
int fcmdgetlabparm(PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH *Ppplh1,PULINEH *Ppplh2,int Popt);//~v62HI~
#define FCGLP_NEXTPLH   0x01      //req return next displayed plh for plh2//~v45xI~
#define FCGLP_SPLITCHK  0x02      //chk if label is on spli line   //~v45xI~
#define FCGLP_0IFNOLAB  0x04      //set 0 if no label is detected  //~v54YI~
//**************************************************************** //~v74yI~
int fcmdinitialcols(PUCLIENTWE Ppcw,PUFILEC Ppfc,PUFILEH Ppfh);    //~v74yI~
//**************************************************************** //~v75aI~
int fcmdtflowlcmd(PUCLIENTWE Ppcw,int Pcmdid,PULINEH Pplh1,PULINEH Pplh2,int Prepeat,int Pbandle,int Pskip);//~v75aR~
//**************************************************************** //~v75fI~
int fcmdresettemperr(int Popt,PUCLIENTWE Ppcw,PULINEH Pplh1,PULINEH Pplh2,int *Pperrctr);//~v75fM~
//**************************************************************** //~v75fI~
int fcmdsettemperr(int Popt,PULINEH Pplh);                         //~v75fI~
