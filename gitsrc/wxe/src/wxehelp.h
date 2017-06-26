//*CID://+va3gR~:                             update#=   13;       //+va3gR~
//********************************************************         //~4311I~
//va3g:100207 try ligature for also wxe(write ucs string at once) for arabic etc//+va3gI~
//v71A:061030 (WXE)Use HtmlHelp;Winhelp is deprecated at Vista;XP english ersion cannot read .hlp by the readson of codepage unsupported//~v71AI~
//v62W:050422 (WXE)maximum cell height definition for small doc    //~v62WI~
//v55G:040315 (WXE)Beep option on setup dialog                     //~v55FI~
//v55F:040314 (WXE)english help                                    //~v55FI~
//v55D:040309 (WXE)popup help for dialog control                   //~4311I~
//********************************************************         //~4311I~
//#define GETCTXID(dbcssw,id) (dbcssw?id:id##_E)                   //~v71AR~
#define GETCTXID(dbcssw,id) (dbcssw?S##id:S##id##_E)               //~v71AM~
//********************************************************         //~v55FI~
#define     IDH_FONTH   481 //Font-H                               //~4310I~
#define     IDH_FONTW   482 //Font-W                               //~4310I~
#define     IDH_ROWH    483 //Row-H                                //~4310I~
#define     IDH_COLW    484 //Col-W                                //~4310I~
#define     IDH_FONTSTYLE   485 //Font-Style                       //~4310I~
#define     IDH_TRUETYPE    486 //TrueType                         //~4310I~
#define     IDH_FONTBOX 535 //FontSample                           //~4311I~
#define     IDH_BGCOLOR 533 //BGColorGroup                         //~4311I~
#define     IDH_RED 487 //Red                                      //~4310I~
#define     IDH_GREEN   488 //Green                                //~4310I~
#define     IDH_BLUE    489 //Blue                                 //~4310I~
#define     IDH_COLORBOX    534 //BGColorSample                    //~4311I~
#define     IDH_SCROLLCTR   490 //ScrollCtr                        //~4310I~
#define     IDH_SCROLLTIMER 491 //ScrollTimer                      //~4310I~
#define     IDH_CHARSET 536 //CharsetGroup                         //~4311I~
#define     IDH_CSDEFAULT   497 //Charset-Default                  //~4310I~
#define     IDH_CSANSI  498 //Charset-ANSI                         //~4310I~
#define     IDH_CSSJIS  499 //Charset-SJIS                         //~4310I~
#define     IDH_CSOTHER 500 //Charset-Other                        //~4310I~
#define     IDH_OTHERCHARSET    492 //Other-Charset                //~4310I~
#define     IDH_USEMETAKEY  493 //UseMetakey                       //~4310I~
#define     IDH_USEACCKEY   494 //UseAccelerator                   //~4310I~
#define     IDH_USERCTL 495 //UseRctl                              //~4310I~
#define     IDH_FREECSR 496 //Freecsr                              //~4310I~
#define     IDH_FORMGRP 537 //FormGroup                            //~4311I~
#define     IDH_FORMSIZE    501 //FormSize                         //~4310I~
#define     IDH_LANDSCAPE   502 //LandScape                        //~4310I~
#define     IDH_MARGINGRP   538 //MarginGroup                      //~4311I~
#define     IDH_MARGINLEFT  503 //MarginLeft                       //~4310I~
#define     IDH_MARGINRIGHT 504 //MarginRight                      //~4310I~
#define     IDH_MARGINTOP   505 //MarginTop                        //~4310I~
#define     IDH_MARGINBOTTOM    506 //MarginBottom                 //~4310I~
#define     IDH_PRINTFONTGRP    539 //PrintFontGroup               //~4311I~
#define     IDH_PRINTFONTSTYLE  507 //PrintFontStyle               //~4310I~
#define     IDH_PRINTFONTH  508 //PrintFontHeight                  //~4310I~
#define     IDH_PRINTFONTW  509 //PrintFontWidth                   //~4310I~
#define     IDH_PRINTCELLH  510 //PrintCellHight                   //~4310I~
#define     IDH_PRINTCELLW  511 //PrintCellWidth                   //~4310I~
#define     IDH_PRINTROWCOLBYCELL   512 //PrintRowColByCell        //~4310I~
#define     IDH_PRINTCOLCTR 513 //PrintColumnCount                 //~4310I~
#define     IDH_PRINTROWCTR 514 //PrintRowCount                    //~4310I~
#define     IDH_PRINTLINESEQ    515 //PrintLineSeq                 //~4310I~
#define     IDH_PRINT2P 516 //Print2P                              //~4310I~
#define     IDH_PRINT2PSPACE    517 //Print2PSpace                 //~4310I~
#define     IDH_PRINTHEADER 518 //PrintHeader                      //~4310I~
#define     IDH_PRINTFILETIME   519 //PrintFileTime                //~4310I~
#define     IDH_PRINTFOOTER 520 //PrintFooter                      //~4310I~
#define     IDH_PRINTTIMESTAMP  521 //PrintTimestamp               //~4310I~
#define     IDH_WWSCRPRT    522 //PrintWWScrPrt                    //~4310I~
#define     IDH_FULLPAGE    523 //PrintFullpage                    //~4310I~
#define     IDH_PREVIEWBOX  540 //PreviewBox                       //~4311I~
#define     IDH_PREVIEWFILENAME 541 //PreviewFilename              //~4311I~
#define     IDH_PREVIEWPAGENO   524 //PreviewpageNo                //~4310I~
#define     IDH_PREVIEWMAXLRECL 542 //PreviewMaxLRECL              //~4311I~
#define     IDH_PREVIEWMAXCOLROW    543 //PreviewMaxColRow         //~4311I~
#define     IDH_PREVIEWGRP  544 //PreviewGroup                     //~4311I~
#define     IDH_PREVIEW	532	//Preview                              //~4310I~
#define     IDH_PREVIEWNEXT 525 //PreviewNextPage                  //~4310I~
#define     IDH_PREVIEWPREV 526 //PreviewPrevPage                  //~4310I~
#define     IDH_PREVIEWPRTSCR   527 //PreviwPrtScr                 //~4310I~
#define     IDH_PRINTGO 528 //PrintGo                              //~4310I~
#define     IDH_PRTSCRGO    529 //PrtScrGo                         //~4310I~
#define     IDH_PRINTOK 530 //PrintOK                              //~4310I~
#define     IDH_PRINTCAN    531 //PrintCancel                      //~4310I~
#define     IDH_JAPANESE	1	//Japanese                         //~v55FI~
#define     IDH_ENGLISH	200	//English                              //~v55FI~
#define     IDH_FONTH_E 603 //Font-H(E)                            //~v55FI~
#define     IDH_FONTW_E 604 //Font-W(E)                            //~v55FI~
#define     IDH_ROWH_E  605 //ROW-H(E)                             //~v55FI~
#define     IDH_COLW_E  606 //Col-W(E)                             //~v55FI~
#define     IDH_FONTSTYLE_E 607 //Font-Style(E)                    //~v55FI~
#define     IDH_TRUETYPE_E  608 //TrueType(E)                      //~v55FI~
#define     IDH_FONTBOX_E   609 //FontSample(E)                    //~v55FI~
#define     IDH_BGCOLOR_E   610 //BGColorGroup(E)                  //~v55FI~
#define     IDH_RED_E   611 //Red(E)                               //~v55FI~
#define     IDH_GREEN_E 612 //Green(E)                             //~v55FI~
#define     IDH_BLUE_E  613 //Blue(E)                              //~v55FI~
#define     IDH_COLORBOX_E    614 //BGColorSample(E)               //~v55FR~
#define     IDH_SCROLLCTR_E 615 //ScrollCtr(E)                     //~v55FI~
#define     IDH_SCROLLTIMER_E   616 //ScrollTimer(E)               //~v55FI~
#define     IDH_CHARSET_E   617 //CharsetGroup(E)                  //~v55FI~
#define     IDH_CSDEFAULT_E 618 //Charset-Default(E)               //~v55FI~
#define     IDH_CSANSI_E    619 //Charset-ANSI(E)                  //~v55FI~
#define     IDH_CSSJIS_E    620 //Charset-SJIS(E)                  //~v55FI~
#define     IDH_CSOTHER_E   622 //Chaeset-Other(E)                 //~v55FI~
#define     IDH_OTHERCHARSET_E  623 //Charset-Anyother(E)          //~v55FI~
#define     IDH_USEMETAKEY_E    625 //UseMetakey(E)                //~v55FI~
#define     IDH_USEACCKEY_E 624 //UseAccelerator(E)                //~v55FI~
#define     IDH_USERCTL_E   626 //UseRctl(E)                       //~v55FI~
#define     IDH_FREECSR_E   627 //Freecsr(E)                       //~v55FI~
#define     IDH_FORMGRP_E   628 //FromGroup(E)                     //~v55FI~
#define     IDH_FORMSIZE_E  629 //FormSize(E)                      //~v55FI~
#define     IDH_LANDSCAPE_E 630 //LandScape(E)                     //~v55FI~
#define     IDH_MARGINGRP_E 631 //MarginGroup(E)                   //~v55FI~
#define     IDH_MARGINLEFT_E    632 //MarginLeft(E)                //~v55FI~
#define     IDH_MARGINRIGHT_E   633 //MarginRight(E)               //~v55FI~
#define     IDH_MARGINTOP_E 634 //MarginTop(E)                     //~v55FI~
#define     IDH_MARGINBOTTOM_E  635 //MarginBottom(E)              //~v55FI~
#define     IDH_PRINTFONTGRP_E  636 //PrintFontGroup(E)            //~v55FI~
#define     IDH_PRINTFONTSTYLE_E    637 //PrintFontStyle(E)        //~v55FI~
#define     IDH_PRINTFONTH_E    638 //PrintFontHeight(E)           //~v55FI~
#define     IDH_PRINTFONTW_E    639 //PrintFontWidth(E)            //~v55FI~
#define     IDH_PRINTCELLH_E    640 //PrintCellHeight(E)           //~v55FI~
#define     IDH_PRINTCELLW_E    641 //PrintCellWidth(E)            //~v55FI~
#define     IDH_PRINTROWCOLBYCELL_E 642 //PrintRowColByCell(E)     //~v55FI~
#define     IDH_PRINTCOLCTR_E   643 //PrintColumnCount(E)          //~v55FI~
#define     IDH_PRINTROWCTR_E    644 //PrintRowCount(E)            //~v55FR~
#define     IDH_PRINTLINESEQ_E  645 //PrintLineSeq(E)              //~v55FI~
#define     IDH_PRINT2P_E   646 //Print2P(E)                       //~v55FI~
#define     IDH_PRINT2PSPACE_E  647 //Print2PSpace(E)              //~v55FI~
#define     IDH_PRINTHEADER_E   648 //PrintHeader(E)               //~v55FI~
#define     IDH_PRINTFILETIME_E 649 //PrintFileTime(E)             //~v55FI~
#define     IDH_PRINTFOOTER_E   650 //PrintFooter(E)               //~v55FI~
#define     IDH_PRINTTIMESTAMP_E    651 //Printtimestamp(E)        //~v55FI~
#define     IDH_WWSCRPRT_E 652 //PrintWWScrPrt(E)                  //~v55FR~
#define     IDH_FULLPAGE_E 653 //PrintFullpage(E)                  //~v55FR~
#define     IDH_PREVIEWBOX_E    654 //PreviewBox(E)                //~v55FI~
#define     IDH_PREVIEWFILENAME_E   655 //PreviewFilename(E)       //~v55FI~
#define     IDH_PREVIEWPAGENO_E 656 //PreviewPageNo(E)             //~v55FI~
#define     IDH_PREVIEWMAXLRECL_E   657 //PreviewMaxLRECL(E)       //~v55FI~
#define     IDH_PREVIEWMAXCOLROW_E  658 //PreviewMaxColRow(E)      //~v55FI~
#define     IDH_PREVIEWGRP_E    659 //PreviewGroup(E)              //~v55FI~
#define     IDH_PREVIEW_E   660 //Preview(E)                       //~v55FI~
#define     IDH_PREVIEWNEXT_E   661 //PreviewNextPage(E)           //~v55FI~
#define     IDH_PREVIEWPREV_E   662 //PreviewPrevPage(E)           //~v55FI~
#define     IDH_PREVIEWPRTSCR_E 663 //PreviewPrtScr(E)             //~v55FI~
#define     IDH_PRINTGO_E   664 //PrintGo(E)                       //~v55FI~
#define     IDH_PRTSCRGO_E  665 //PrtScrGo(E)                      //~v55FI~
#define     IDH_PRINTOK_E   666 //PrintOK(E)                       //~v55FI~
#define     IDH_PRINTCAN_E  667 //PrintCancel(E)                   //~v55FI~
#define     IDH_BEEP	621	//Beep                                 //~v55FI~
#define     IDH_BEEP_E	668	//Beep(E)                              //~v55FI~
#define     IDH_PRINTMAXCELLH    695 //PrintCellHight max          //~v62WR~
#define     IDH_PRINTMAXCELLH_E  696 //PrintCellHight max          //~v62WR~
#define     IDH_LIGATURE    697 //Ligature                         //+va3gR~
#define     IDH_LIGATURE_E  698 //Ligature(E)                      //+va3gR~
