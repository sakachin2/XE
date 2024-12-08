//*CID://+va1BR~:                             update#=   16;       //~v69DR~//~va00R~//~va1BR~
//****************************************************************
//xefile2.h
//****************************************************************
//va1B:091112 (UTF8)hdrline codetype ftrom cmd buff if avail       //~va1BI~
//va00:090510 merge utf8 version(enclosed by UTF8SUPPH)            //~va00I~
//          header line filename cv f2l                            //~va00I~
//v69D:060708 split xefile2 to xefile23(func_draw_file,setlineattr)//~v69DI~
//v53g:030923 (BUG)for xprint **;lineno shift like as screen       //~v53gI~
//v53e:030923 (BUG)for xprint **;lineno may changed lineno to hex offset//~v53eI~
//            after once displayed(plhlineno is set previous fmt)  //~v53eI~
//v445:011201 binary file support for xprint **/***                //~v445I~
//v40h:010526 xprint **;like as print screen                       //~v40hI~
//v0k0:980919 (BUG)miss line re-display for f/y lcmd when excluded is top line//~v0k0I~
//v0hf:980130 performance tuning                                   //~v0hvI~
//            draw only after deleted/inserted line                //~v0hvI~
//v0av:970720-fixed lrecl support(mergin support,MAXLEN=nn[N])     //~v0avI~
//           -expand pre chk(split file2 to file6)                 //~v0avI~
//v06y:960407:protect edit so file when iit is used by cmd result     //~v06yI~
//            (cmd edit identification only by PANMOCMD)              //~v06yI~
//				move fileregist to file.c                             //~v06yI~
//v069:960224:linenosz changeable for edit/browse               //~v069I~
//*v03f:950731:scroll value err revese(common rtn with xefile2) //~v03fI~
//*950618 v020 filewakeup rtn share with dir                    //~v020I~
//****************************************************************
void fileufldinit(PUCLIENTWE Ppcw);                             //~v069R~
                                                                //~v03fI~
//****************************************************************
PUCLIENTWE filepopup(PUCLIENTWE Ppcw);

//****************************************************************//~5223I~
void filesetcsr(PUCLIENTWE Ppcw,PULINEH Pplh,int Pfldno,int Poffs);
                                                                //~5118I~
//****************************************************************//~5118I~
void filesetmultdraw(PUCLIENTWE Ppcw);                          //~5118R~
                                                                //~v020I~
//****************************************************************//~v020I~
int filewakeup(PUCLIENTWE Ppcw);                                //~v020I~
                                                                //~v020I~
//**************************************************************//~v03fR~
void filecmdlinedisp(PUCLIENTWE Ppcw,PUSCRD Ppsd);              //~v03fR~
                                                                   //~v0hvI~
//**************************************************************** //~v0hvM~
void filesetdrawstart(PUCLIENTWE Ppcw,PULINEH Pplh,int Pmultiopt); //~v0hvR~
#define DRAW_MULT     0x01     // multi-screen redraw              //~v0hvR~
#define DRAW_ISRT     0x02     // draw by isrt(no need to draw after end of line//~v0hvR~
                                                                   //~v0k0I~
//**************************************************************** //~v0k0I~
void filesetfulldraw(PUCLIENTWE Ppcw);                             //~v0k0I~
                                                                   //~v40hI~
//**************************************************************** //~v40hI~
//int fileinitialeditlineno(PUFILEH Ppfh,PULINEH Pplh,char *Pwklineno);//~v53eR~
//int fileeditlineno(PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH Pplh,char *Pwklineno);//~v53gR~
int fileeditlineno(PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH Pplh,char *Pwklineno,int Plinenosz,int Popt);//~v53gR~
#define FELN_SHIFT  0x01                                           //~v53gR~
#define FELN_SETCMD 0x02                                           //~v53gI~
                                                                   //~v445I~
//**************************************************************** //~v445I~
int filecolsprint(PUCLIENTWE Ppcw,UCHAR *Ppout,int Plinenosz,int Plinesz);//~v445R~
//**************************************************************** //~v69DI~
void vsplitshift(PUCLIENTWE Ppcw);                                 //~v69DI~
//**************************************************************** //~v69DI~
void filecolsdisp(PUCLIENTWE Ppcw,PUSCRD Ppsd,int Pfullsw,UCHAR Pprotattr,UCHAR Pprotattr_r);//~v69DI~
//**************************************************************** //~va00I~
#ifdef UTF8SUPPH                                                   //~va00I~
	int fileutf8vsplithdrattr(int Popt,PUCLIENTWE Ppcw,PUSCRD Ppsd,PUFILEH Ppfh,int Pcsrposdisp);//~va00I~
    #define FUVSHAO_CHNGWIDTH     0x01                             //~va00M~
#endif //UTF8SUPPH                                                 //~va00I~
