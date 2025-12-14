//*CID://+vbj2R~:                             update#=  208;       //~vbj2R~
//***************************************************************************//~v59zI~
//vbj2:180424 popup menu on cmd history list                       //~vbj2I~
//vbd2:171114 (Wxe)Add SelectAll menuitem                          //~vbd2I~
//var8:140127 gtk3 suppott                                         //~var8I~
//vam7:130929 add print with ligature                              //~vam7I~
//va1M:091121 (LNX)ligature support;keep monospace for english lagature; Arabian ? I don't know.//~va1MI~
//v740:070201 (WXE/XXE)kde dose not report keypress event for S+C+F1;so use keyup event//~v740I~
//            so support specify trigger key on setupdialog        //~v740I~
//v73y:070128-(WXE/XXE)Quiet-exit support                          //~v73yI~
//v71x:061023 (XXE)it take time to download for DND and Application HUNG occurs//~v71xI~
//            aftwer completed using user msg to download,issue begindrag//~v71xI~
//v685:060322 dnd support "file copy into the dir slected" and even in inter-split-screen.//~v685I~
//v66r:051025 (XXE) for v66m for WXE                               //~v66rI~
//v667:050823 (XXE)add printer selection dropdown list(effective only for CUPS)//~v667I~
//vXXE:050611 new for XXE                                          //~v59zI~
//***************************************************************************//~v59zI~
// gxeres.h                                                        //~v59zI~
//***************************************************************************//~v59zI~
//#define FRAME_WINDOW_KEY  "FrameWindowKey"		//to get framewindow handle//~vXXER~
//**** object id                                                   //~v59zI~
#define STRID_MAINWINDOW           "maindraw"                      //~vXXER~
#define STRID_FILE                 "file"                          //~vXXER~
#define STRID_FILE_NEW             "new"                           //~vXXER~
#define STRID_FILE_OPEN            "open"                          //~vXXER~
#define STRID_FILE_SAVE            "save"                          //~vXXER~
#define STRID_FILE_SAVEAS          "saveas"                        //~vXXER~
#define STRID_FILE_PRINT           "print"                         //~vXXER~
#define STRID_FILE_PRTSCR          "prtscr"                        //~vXXER~
#define STRID_FILE_PREVIEW         "preview"                       //~vXXER~
#define STRID_FILE_HOME            "home"                          //~vXXEI~
#define STRID_FILE_TERMINAL        "terminal"                      //~vXXEI~
#define STRID_FILE_EXIT            "exit"                          //~vXXER~
#define STRID_EDIT                 "edit"                          //~vXXER~
#define STRID_EDIT_SELECTALL       "selectall"                     //~vbd2I~
#define STRID_EDIT_CUT             "cut"                           //~vXXER~
#define STRID_EDIT_COPY            "copy"                          //~vXXER~
#define STRID_EDIT_CLEAR           "clear"                         //~vXXER~
#define STRID_EDIT_PASTE           "paste_insert"                  //~vXXER~
#define STRID_EDIT_PASTE_REP       "paste_replace"                 //~vXXER~
#define STRID_EDIT_PASTE_V         "paste_V"                       //~v667R~
                                                                   //~vbj2I~
#define STRID_CHL_EXE_CLOSED       "x:Exec on Under"               //~vbj2I~
#define STRID_CHL_EXE_CURRENT      "X:     on Current"             //~vbj2I~
#define STRID_CHL_EXE_SPLIT        "y:     on Split"               //+vbj2R~
#define STRID_CHL_SET_CLOSED       "s:Set on Under"                //~vbj2I~
#define STRID_CHL_SET_CURRENT      "S:    on Current"              //~vbj2I~
#define STRID_CHL_SET_SPLIT        "t:    on Split"                //~vbj2I~
                                                                   //~vbj2I~
#define STRID_SETUP                "setup"                         //~vXXER~
//#define STRID_SETUP_DIALOG         "setupdialog"                 //~var8R~
#define STRID_PAGE_SETUP           "preview2"                      //~vXXER~
//#define STRID_PAGE_SETUP_DIALOG    "previewdialog"               //~var8R~
#define STRID_HELP                 "help2"                         //~vXXER~
#ifndef OPTGTK3                                                    //~var8R~
#else   //OPTGTK3                                                  //~var8R~
#define STRID_HELPDOC              "helpdoc"                       //~var8R~
#define STRID_VERSION              "version"                       //~var8R~
#endif                                                             //~var8R~
//** toolbar **                                                    //~vXXEI~
#define STRTBID_TOOLBAR                "toolbar1"                  //~v66rI~
#define STRTBID_FILE_SAVE              "button_save"               //~vXXER~
#define STRTBID_EDIT_END               "button_end"                //~vXXER~
#define STRTBID_EDIT_CANCEL            "button_cancel"             //~vXXER~
#define STRTBID_FILE_PRINT             "button_print"              //~vXXER~
#define STRTBID_FILE_HOME              "button_home"               //~vXXER~
#define STRTBID_FILE_TERMINAL          "button_terminal"           //~vXXER~
#define STRTBID_EDIT_CUT               "button_cut"                //~vXXER~
#define STRTBID_EDIT_COPY              "button_copy"               //~vXXER~
#define STRTBID_EDIT_CLEAR             "button_clear"              //~vXXER~
#define STRTBID_EDIT_PASTE             "button_pasteins"           //~vXXER~
#define STRTBID_EDIT_PASTE_REP         "button_pasterep"           //~vXXER~
#define STRTBID_EDIT_PASTE_V           "button_pasteV"             //~v667I~
//option dlg                                                       //~vXXEI~
#define STRIDC_SPIN_ROWH           "option_spinbutton_rowh"        //~vXXER~
#define STRIDC_SPIN_COLW           "option_spinbutton_colw"        //~vXXER~
#define STRIDC_SPIN_SCROLLCTR      "option_spinbutton_scrollctr"   //~vXXER~
#define STRIDC_SPIN_SCROLLTIMER    "option_spinbutton_interval"    //~vXXER~
#define STRIDC_CHECK_USEACT        "option_chkbutton_acc"          //~vXXER~
#define STRIDC_CHECK_USEMK         "option_chkbutton_menu"         //~vXXER~
#define STRIDC_CHECK_LIGATURE      "option_chkbutton_ligature"     //~va1MI~
#define STRIDC_CHECK_RCTL          "option_chkbutton_Rctl"         //~vXXER~
#define STRIDC_CHECK_FREECSR       "option_chkbutton_freecsr"      //~vXXER~
#define STRIDC_CHECK_BEEP          "option_chkbox_beep"            //~vXXER~
#define STRIDC_CHECK_QEXIT         "option_chkbox_qexit"           //~v73yI~
#define STRIDC_ENTRY_FONTNAME      "option_entry_current_font"     //~vXXEI~
#define STRIDC_STATIC_COLORBOX     "option_drawingarea_colorsample"//~vXXEI~
#define STRIDC_EDIT_HEIGHT         "option_entry_fonth"            //~vXXER~
#define STRIDC_EDIT_WIDTH          "option_entry_fontw"            //~vXXER~
#define STRIDC_EDIT_RULERKEY       "option_entry_rulerkey"         //~v740R~
//print dlg                                                        //~vXXEI~
#define STRIDC_ENTRY_PFONTNAME  "page_entry_current_font"          //~vXXER~
#define STRIDC_COMBO_FORM       "combo1"                           //~vXXER~
#define STRIDC_COMBOENTRY_FORM  "page_combo_form"                  //~vXXEI~
#define STRIDC_COMBO_PRINTER    "combo2"                           //~v667R~
#define STRIDC_COMBOENTRY_PRINTER "page_combo_printer"             //~v667I~
#define STRIDC_CHECK_LANDSCAPE  "page_chkbutton_landscape"         //~vXXEM~
#define STRIDC_SPIN_LEFT        "page_spin_left"                   //~vXXEM~
#define STRIDC_SPIN_TOP         "page_spin_top"                    //~vXXEM~
#define STRIDC_SPIN_RIGHT       "page_spin_right"                  //~vXXEM~
#define STRIDC_SPIN_BOTTOM      "page_spin_bottom"                 //~vXXEM~
#define STRIDC_LABEL_DEFMARGIN  "page_label_default_margin"        //~vXXER~
#define STRIDC_EDIT_FONTSTYLE   "page_entry_current_font"          //~vXXEM~
#define STRIDC_EDIT_PFONTSZH    "page_entry_fonth"                 //~vXXEM~
#define STRIDC_EDIT_PFONTSZW    "page_entry_fontw"                 //~vXXEM~
#define STRIDC_SPIN_PROWH       "page_spinbutton_cellh"            //~vXXEM~
#define STRIDC_SPIN_PCOLW       "page_spinbutton_cellw"            //~vXXEM~
#define STRIDC_SPIN_MAXCOLROW   "page_spinbutton_cellhmax"         //~vXXEM~
#define STRIDC_CHECK_PFONTSZ    "page_chkbutton_bycellhw"          //~vXXEM~
#define STRIDC_SPIN_COL         "page_spin_col"                    //~vXXEM~
#define STRIDC_SPIN_ROW         "page_spin_row"                    //~vXXEM~
#define STRIDC_CHECK_LINENUMBER "page_chkbutton_lineno"            //~vXXEM~
#define STRIDC_CHECK_HEADER     "page_chkbutton_header"            //~vXXEM~
#define STRIDC_CHECK_FOOTER     "page_chkbutton_footer"            //~vXXEM~
#define STRIDC_CHECK_WWSCRPRT   "page_chkbutton_wwscrprt"          //~vXXEM~
#define STRIDC_CHECK_2P         "page_chkbutton_2p"                //~vXXEM~
#define STRIDC_SPIN_2P          "page_spinbutton_2pinterval"       //~vXXEM~
#define STRIDC_CHECK_FILETIME   "page_chkbutton_filetime"          //~vXXEM~
#define STRIDC_CHECK_SYSTIME    "page_chkbutton_systime"           //~vXXEM~
#define STRIDC_CHECK_FULLPAGE   "page_chkbutton_fullpage"          //~vXXEM~
#define STRIDC_CHECK_PRINTLIGATURE  "page_chkbutton_ligature"      //~vam7R~
#define STRIDC_LABEL_FILENAME   "page_label_filename"              //~vXXEM~
#define STRIDC_SPIN_CURPAGE     "page_spinbutton_curpage"          //~vXXEM~
#define STRIDC_LABEL_MAXPAGE    "page_label_pageno"                //~vXXEM~
#define STRIDC_LABEL_COLS       "page_label_cols"                  //~vXXEM~
#define STRIDC_PREVIEW          "page_button_preview_print"        //~vXXEM~
#define STRIDC_PREVIEW_NEXTPAGE "page_button_np"                   //~vXXEM~
#define STRIDC_PREVIEW_PREVPAGE "page_button_pp"                   //~vXXEM~
#define STRIDC_PREVIEWPRTSCR    "page_button_preview_prtscr"       //~vXXEM~
#define STRIDC_PRINTRANGE       "page_entry_pagerange"             //~vXXEI~
#define STRIDC_PRINT            "page_button_print"                //~vXXEM~
#define STRIDC_PRTSCR           "page_button_prtscr"               //~vXXEM~
#define STRIDC_PREVIEW_AREA     "page_preview_area"                //~vXXEM~
                                                                   //~vXXEI~
#define ID_MAINWINDOW         1                                    //~vXXER~
#define ID_FILE               2                                    //~vXXER~
#define ID_FILE_NEW           3                                    //~vXXER~
#define ID_FILE_OPEN          4                                    //~vXXER~
#define ID_FILE_SAVE          5                                    //~vXXER~
#define ID_FILE_SAVEAS        6                                    //~vXXER~
#define ID_FILE_PRINT         7                                    //~vXXER~
#define ID_FILE_PRTSCR        8                                    //~vXXER~
#define ID_FILE_PREVIEW       9                                    //~vXXER~
#define ID_FILE_HOME         10                                    //~vXXEI~
#define ID_FILE_TERMINAL     11                                    //~vXXEI~
#define ID_FILE_EXIT         12                                    //~vXXER~
#define ID_EDIT              21                                    //~vXXER~
#define ID_EDIT_CUT          22                                    //~vXXER~
#define ID_EDIT_COPY         23                                    //~vXXER~
#define ID_EDIT_CLEAR        24                                    //~vXXER~
#define ID_EDIT_PASTE        25                                    //~vXXER~
#define ID_EDIT_PASTE_REP    26                                    //~vXXER~
#define ID_EDIT_PASTE_V      27                                    //~v667I~
#define ID_EDIT_SELECTALL    28                                    //~vbd2I~
#define ID_SETUP             31                                    //~vXXER~
#define ID_PAGE_SETUP        32                                    //~vXXER~
#define ID_HELP              41                                    //~vXXER~
#define ID_EDIT_CANCEL       50                                    //~vXXER~
#define ID_EDIT_END          51                                    //~vXXER~
#define ID_FILE_OPENWITH     52                                    //~vXXER~
#define ID_FILE_SAVE2        53                                    //~vXXER~
#define ID_FILE_PRINT2       54                                    //~vXXER~
#define ID_EDIT_COPY2        55                                    //~vXXER~
#define ID_EDIT_CUT2         56                                    //~vXXER~
#define ID_EDIT_PASTE2       57                                    //~vXXER~
#define ID_HELPXE            59                                    //~vXXER~
#define ID_FILE_DNDCOPY      60                                    //~v685I~
#define ID_FILE_DNDDRAGOUTSETUP      61                            //~v71xI~
#define ID_SCREEN_DRAW               62                            //~v71xI~
#define ID_CHL_EXE_CLOSED     71                                   //~vbj2I~
#define ID_CHL_EXE_CURRENT    72                                   //~vbj2I~
#define ID_CHL_EXE_SPLIT      73                                   //~vbj2I~
#define ID_CHL_SET_CLOSED     74                                   //~vbj2I~
#define ID_CHL_SET_CURRENT    75                                   //~vbj2I~
#define ID_CHL_SET_SPLIT      76                                   //~vbj2I~
//option dlg                                                       //~vXXEI~
#define IDC_SPIN_ROWH        101                                   //~vXXER~
#define IDC_SPIN_COLW        102                                   //~vXXER~
#define IDC_SPIN_SCROLLCTR   103                                   //~vXXER~
#define IDC_SPIN_SCROLLTIMER 104                                   //~vXXER~
#define IDC_CHECK_USEACT     105                                   //~vXXER~
#define IDC_CHECK_USEMK      106                                   //~vXXER~
#define IDC_CHECK_RCTL       107                                   //~vXXER~
#define IDC_CHECK_FREECSR    108                                   //~vXXER~
#define IDC_CHECK_BEEP       109                                   //~vXXER~
#define IDC_EDIT_HEIGHT      110                                   //~vXXEI~
#define IDC_EDIT_WIDTH       111                                   //~vXXEI~
#define IDC_CHECK_QEXIT      112                                   //~v73yI~
//print dlg                                                        //~vXXER~
#define IDC_EDIT_FORM        201                                   //~vXXEI~
#define IDC_CHECK_LANDSCAPE  202                                   //~vXXEI~
#define IDC_SPIN_LEFT        203                                   //~vXXEI~
#define IDC_SPIN_TOP         204                                   //~vXXEI~
#define IDC_SPIN_RIGHT       205                                   //~vXXEI~
#define IDC_SPIN_BOTTOM      206                                   //~vXXEI~
#define IDC_EDIT_FONTSTYLE   208                                   //~vXXEI~
#define IDC_EDIT_PFONTSZH    209                                   //~vXXEI~
#define IDC_EDIT_PFONTSZW    210                                   //~vXXEI~
#define IDC_SPIN_PROWH       211                                   //~vXXER~
#define IDC_SPIN_PCOLW       212                                   //~vXXER~
#define IDC_SPIN_MAXCOLROW   213                                   //~vXXEI~
#define IDC_CHECK_PFONTSZ    214                                   //~vXXEI~
#define IDC_SPIN_COL         215                                   //~vXXEI~
#define IDC_SPIN_ROW         216                                   //~vXXEI~
#define IDC_CHECK_LINENUMBER 217                                   //~vXXEI~
#define IDC_CHECK_HEADER     218                                   //~vXXEI~
#define IDC_CHECK_FOOTER     219                                   //~vXXEI~
#define IDC_CHECK_WWSCRPRT   220                                   //~vXXEI~
#define IDC_CHECK_2P         221                                   //~vXXEI~
#define IDC_SPIN_2P          222                                   //~vXXEI~
#define IDC_CHECK_FILETIME   223                                   //~vXXEI~
#define IDC_CHECK_SYSTIME    224                                   //~vXXEI~
#define IDC_CHECK_FULLPAGE   225                                   //~vXXEI~
#define IDC_LABEL_FILENAME   226                                   //~vXXEI~
#define IDC_SPIN_CURPAGE     227                                   //~vXXER~
#define IDC_LABEL_MAXPAGE    228                                   //~vXXEI~
#define IDC_LABEL_COLS       230                                   //~vXXEI~
#define IDC_PREVIEW          231                                   //~vXXEI~
#define IDC_PREVIEW_NEXTPAGE 232                                   //~vXXEI~
#define IDC_PREVIEW_PREVPAGE 233                                   //~vXXEI~
#define IDC_PREVIEWPRTSCR    234                                   //~vXXEI~
#define IDC_PRINT            235                                   //~vXXEI~
#define IDC_PRTSCR           236                                   //~vXXEI~
#define IDC_CHECK_PRINTLIGATURE 237                                //~vam7R~
//Accelerator key                                                  //~vXXEI~
#define ACCKEYID_FILE_NEW       'n'                                //~vXXER~
#define ACCKEYID_FILE_OPEN      'o'                                //~vXXER~
#define ACCKEYID_FILE_SAVE      's'                                //~vXXER~
#define ACCKEYID_FILE_SAVEAS    'a'                                //~vXXER~
#define ACCKEYID_FILE_PRINT     'p'                                //~vXXER~
#define ACCKEYID_FILE_PRTSCR    'h'                                //~vXXER~
//#define ACCKEYID_FILE_PREVIEW   'v'                              //~v667R~
#define ACCKEYID_FILE_HOME      'e'                                //~vXXER~
#define ACCKEYID_FILE_TERMINAL  'm'                                //~vXXER~
#define ACCKEYID_FILE_EXIT      'x'                                //~vXXER~
#define ACCKEYID_EDIT_SELECTALL 'a'                                //~vbd2R~
#define ACCKEYID_EDIT_CUT       't'                                //~vXXER~
#define ACCKEYID_EDIT_COPY      'c'                                //~vXXER~
#define ACCKEYID_EDIT_CLEAR     'l'                                //~vXXER~
#define ACCKEYID_EDIT_PASTE     'i'                                //~vXXER~
#define ACCKEYID_EDIT_PASTE_REP 'r'                                //~vXXER~
#define ACCKEYID_EDIT_PASTE_V   'v'                                //~v667I~
                                                                   //~v59zI~
#ifndef XXE                                                        //~v59zI~
#define IDD_ABOUTBOX                    100
#define IDR_MAINFRAME                   128
#define IDI_MAINFRAME                   128
#define IDR_WXETYPE                     129
#define IDD_SETUP                       130
#define IDR_FLOATING                    131
#define IDB_HALFBOX                     133
#define IDB_HBAR                        134
#define IDD_PAGE_SETUP                  135
#define IDR_MAINFRAME_DYN               136
#define IDB_COPY                        136
#define IDB_CUT                         138
#define IDB_PASTE_INS                   140
#define IDB_SAVE                        141
#define IDB_PRINT                       143
#define IDB_END                         144
#define IDB_PASTE_REP                   146
#define IDB_PASTE_V                     147                        //~v667I~
#define IDB_CANCEL                      148
#define IDB_CLEAR                       149
#define IDB_EXPLORER                    151
#define IDB_DOS                         152
#define IDC_SPIN_HEIGHT                 1005
#define IDC_SPIN_WIDTH                  1006
#define IDC_COMBO_STYLE                 1009
#define IDC_SLIDER_RED                  1015
#define IDC_SLIDER_GREEN                1016
#define IDC_SLIDER_BLUE                 1017
#define IDC_EDIT_RED                    1018
#define IDC_EDIT_GREEN                  1019
#define IDC_EDIT_BLUE                   1020
#define IDC_RADIO_DEFAULT               1021
#define IDC_RADIO_ANSI                  1022
#define IDC_RADIO_SJIS                  1023
#define IDC_CHECK_TTFONT                1024
#define IDC_STATIC_FONTBOX              1030
#define IDC_EDIT_SCROLLCTR              1031
#define IDC_COMBO1                      1034
#define IDC_RADIO_PORTRATE              1035
#define IDC_RADIO_LANDSCAPE             1036
#define IDC_FOOTER                      1046
#define IDC_STATIC_PREVIEW              1052
#define IDC_RADIO_OTHER                 1069
#define IDC_EDIT_OTHER                  1070
#define IDC_EDIT_SCROLLTIMER            1074
#define IDC_CHECK1                      1076
#define IDC_EDIT_PFONTSZ                1077
#define IDC_SPIN_PFONTSZ                1078
#define IDC_SPIN_PFONTSZH               1078
//#define IDC_SPIN_ROW                    1080                     //~v740R~
#define IDC_SPIN_PFONTSZW               1082
#define IDC_EDIT_CELLSZH                1084
#define IDC_EDIT_CELLSZW                1085
#define IDC_SPIN_CELLSZH                1086
#define IDC_SPIN_CELLSZW                1087
#define IDC_STATIC_FONTH                1089
#define IDC_STATIC_FONTW                1090
#define IDC_STATIC_ROWH                 1091
#define IDC_STATIC_COLW                 1092
#define IDC_STATIC_FONTSTYLE            1093
#define IDC_STATIC_BGCOLOR              1094
#define IDC_STATIC_SCROLLCTR            1095
#define IDC_STATIC_CHARSET              1096
#define IDC_STATIC_INTVL                1097
#define IDC_STATIC_SECOND               1098
#define IDC_STATIC_RED                  1099
#define IDC_STATIC_GREEN                1100
#define IDC_STATIC_BLUE                 1101
#define IDC_STATIC_FORM                 1102
#define IDC_STATIC_SIZE                 1103
#define IDC_STATIC_MARGIN               1104
#define IDC_STATIC_LEFT                 1105
#define IDC_STATIC_RIGHT                1106
#define IDC_STATIC_TOP                  1107
#define IDC_STATIC_BOTTOM               1108
#define IDC_STATIC_FONT                 1109
#define IDC_STATIC_STYLE                1110
#define IDC_STATIC_CELLH                1111
#define IDC_STATIC_CELLW                1112
#define IDC_STATIC_COL                  1113
#define IDC_STATIC_ROW                  1114
#define IDC_STATIC_PREVIEWGRP           1115
#define IDC_EDIT_CELLSZH_MAX            1117
#define IDC_SPIN_CELLSZH_MAX            1118
#define IDC_STATIC_MAXCELLH             1119
#define IDC_FONT                        32771
#endif                                                             //~v59zR~
