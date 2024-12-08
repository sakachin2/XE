//CID://+vbd7R~:     update#=     121                              //+vbd7R~
//*******************************************************       //~v06lI~
//vbd7:171119 "SEL all" support on file panel                      //+vbd7I~
//va7P:100906 (BUG)"invalid codepage" msg at cap copy; cb_stat contains codepage which is not valid now//~va7PI~
//            because cfg CONVERTER was changed between ICU and others.//~va7PI~
//            ignore it when save case(capsavedata,capsavedataword) because prev line is cleared imediately.//~va7PI~
//va00:090510 merge utf8 version(enclosed by UTF8SUPPH)            //~va00I~
//          wxe/xxe clipboard data conversion                      //~va00I~
//v77E:080203 FW(C+"["/"]")/IW(A+"["|"]") cmd support              //~v77EI~
//v69Z:060726 (WXEXXE)sync C&P between PFkey and mouse operation.(update enable/disable menu by also Key operation)//~v66ZI~
//v66f:051021 support standard mode cut & paste,assign Ctrl+v for stream insert.(split xecap.c to xecap2.c)//~v66fI~
//                     None   OpenBlock  ClosedBlock   OpenRegion ClosedRegion//~v66fI~
//            C+v    RgnIns   NoBlockErr BlockClearRep OpenRgnErr RgnDel+Ins//~v66fI~
//            A+Ins  BlockIns NoBlockErr GetBlock+Ins  OpenRgnErr RgnDel+Ins//~v66fI~
//            A+Rep  BlockRep NoBlockErr GetBlock+Rep  OpenRgnErr RgnDel+Ins//~v66fI~
//v641:050614 (LNX)xxe support                                     //~v641I~
//v500:020929 (WXE)scr cut/paste                                   //~v500I~
//v155:000318 numeric calc func                                    //~v155I~
//v06t:960406:cmd so screen:append cmd result                         //~v06tI~
//v06l:960317:rearange key for no num option                    //~v06lI~
//           -REPL/CREATE after line range closed               //~v06lI~
//*******************************************************          //~v66fI~
//Sblockstat                                                       //~v66fI~
#define SBLOCKCLOSED	        0x01    //start and block closed   //~v66fI~
#define SBLOCKMODE          0x02    //block mode(not line mode)    //~v66fI~
#define SBLOCKSAVED        0x04    //copyed to clip boad           //~v66fI~
//Sblockstat2                                                      //~v66fI~
#define SBLOCK2LINEMARK     0x01    //line mark operation flag     //~v66fI~
#define SBLOCK2SAVEDATA     0x02    //savedata  operation flag     //~v66fI~
#define SBLOCK2WORDCOPY     0x04    //word copy mode               //~v66fI~
#define SBLOCK2STDREGION    0x08    //standard cut & paste region type//~v66fI~
//*******************************************************       //~5220I~
void capreset(int Popt);                                        //~5220I~
                                                                   //~v155I~
//*******************************************************          //~v155I~
void capresetcalc(PUCLIENTWE Ppcw);                                //~v155I~
                                                                //~5123I~
//*******************************************************       //~5126I~
void capsavecsrpos(PUCLIENTWE Ppcw);                            //~5126I~
                                                                //~5126I~
//*******************************************************       //~5126I~
void caplinechk(PUCLIENTWE Ppcw,PULINEH Pplh);                  //~5126R~
                                                                //~5123I~
//*******************************************************       //~5123I~
int capblockchk(PUCLIENTWE Ppcw,PULINEH Pplh,int *Ppoffs);      //~5123R~
                                                                //~v06lI~
//*******************************************************             //~v06tI~
void capfcmdi(PUCLIENTWE Ppcw,PULINEH Pplh,int Pverbopt);             //~v06tI~
                                                                      //~v06tI~
//*******************************************************       //~v06lI~
int capfcmdi3(PUCLIENTWE Ppcw,char Prepcre);                    //~v06lI~
                                                                   //~v155I~
//*******************************************************          //~v155I~
int cap_savecalcinfo(PUCLIENTWE Ppcw,PULINEH Pplh1,PULINEH Pplt2,int Ppos1,int Ppos2);//~v155R~
                                                                   //~v155I~
//*******************************************************          //~v155I~
int cap_getcalcprevinfo(PUCLIENTWE *Pppcw,PULINEH *Ppplh1,PULINEH *Ppplh2,int *Pppos1,int *Pppos2);//~v155R~
                                                                   //~v155I~
//*******************************************************          //~v155I~
int cap_getcalccurinfo(PUCLIENTWE Ppcw,PULINEH *Ppplh1,PULINEH *Ppplh2,int *Pppos1,int *Pppos2);//~v155I~
                                                                   //~v500I~
//*******************************************************          //~v500I~
int capsavedata(PUCLIENTWE Ppcw);                                  //~v500R~
                                                                   //~v500I~
//#ifdef WXE                                                       //~v641R~
#ifdef WXEXXE                                                      //~v641I~
//*******************************************************          //~v500I~
int capchkcsrpos(int Prow,int Pcol,PUCLIENTWE *Pppcw);             //~v500I~
void capgetxestat(char *Ppstat1,char *Ppstat2);                    //~v69ZR~
#endif                                                             //~v500I~
//*******************************************************          //~v77EI~
int capgetmouseword(int Popt,PUCLIENTWE Ppcw,PULINEH *Ppplh,int *Pppos,int *Pplen);//~v77EM~
//*******************************************************          //~v66fI~
//PUFILEH capgetpfh(PUCLIENTWE Ppcw);                                //~v66fI~//~va7PR~
//*******************************************************          //~v66fI~
PUFILEH capgetdata(PUCLIENTWE Ppcw,PULINEH *Ppplh1,PULINEH *Ppplh2);//~v66fI~
//*******************************************************          //~v66fI~
int capgetpoint(PUCLIENTWE Ppcw,PULINEH *Ppplh,int *Pppos);        //~v66fI~
//*******************************************************          //~v66fI~
int capnoblockerr(void);                                           //~v66fM~
#ifdef UTF8SUPPH                                                   //~va00I~
//*******************************************************          //~va00I~
int xecapcvcb(int Popt,char *Pdata,int Pdatalen,char *Poutdata,int *Ppoutlen);//~va00I~
#define CCVCBO_F2L       0x01	//clipboard to locale code         //~va00I~
#define CCVCBO_L2F       0x02	//clipboard to locale code         //~va00I~
#endif                                                             //~va00I~
int capselectallfilecmd(PUCLIENTWE Ppcw,PUFILEH Ppfh);             //+vbd7I~
