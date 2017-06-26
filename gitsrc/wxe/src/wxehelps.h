//*CID://+va78R~:                             update#=  186;       //~va78R~
//***********************************************************************//~v73tI~
//va78:100807 restart required wheb sbcs<->dbcs charset changed at setup dialog//~va78I~
//va75:100806 (BUG:WXE)force eng to errmsg when charset changed on setupdialog//~va75I~
//va3g:100207 try ligature for also wxe(write ucs string at once) for arabic etc//~va3gI~
//v79z:080916 DBCS tbl for C and K of CJK                          //~v79zI~
//v77D:080129*report by M.J(warning by vc2005:C4005:dup #define, C4129:invalid \\)//~v77DI~
//v740:070201 (WXE/XXE)kde dose not report keypress event for S+C+F1;so use keyup event//~v740I~
//            so support specify trigger key on setupdialog        //~v740I~
//v73y:070128-(WXE/XXE)Quiet-exit support                          //~v73yI~
//v73t:070125 cross-hair ruler support by Shift+Ctl+lbuton         //~v73tI~
//***********************************************************************//~v73tI~
//string for dialog box help                                       //~v73tI~
//***********************************************************************//~v73tI~
#define  SIDH_BEEP                "エラーのときビープ"
#define  SIDH_BEEP_E              "Beep when error"
#define  SIDH_BGCOLOR             "3色ミックス"
#define  SIDH_BGCOLOR_E           "3 color mix"
#define  SIDH_BLUE                "青"
#define  SIDH_BLUE_E              "Blue"
/*#define  SIDH_CHARSET             "CharSet:漢字表示の場合SJISを指定する。\n" \
                                  "Windowsの版によって効果に違いが有るようです。\n" \
                                  "日本語DOS罫線文字(x01)を表示する場合other 254も\n" \
                                  "試してみてください。\n" \
                                  "外国文字ではotherのCharSet番号指定が効くかもしれません。"
*/                                                                 //~v77DI~
//#define  SIDH_CHARSET             "CharSet:漢字\x95\\示の場合SJISを指定する。\n"//~va75R~
#define  SIDH_CHARSET             "フォント用文字セット。\n" \
                                  "日本語の場合DefaultかSJISを指定する。\n" \
                                  "日本語DOS罫線文字(x01)を\x95\\示する場合other 254も\n" \
                                  "試してみてください。\n" \
                                  "西欧言語ではACPが良いでしょう。\n"/*~v77DI~*/\
                                  "その他の外国語では other から選んでください。\n"/*~v77DI~*/\
                                  "DCCS<->SBCSの変更の場合 wxe をリスタートしてください。"//~va78R~
//#define  SIDH_CHARSET_E           "Use SJIS for Japanese DBCS.\n"//~va75R~
#define  SIDH_CHARSET_E           "Font charset.\n" \
                                  "Use Deafult or SJIS for Japanese.\n" \
                                  "If Japanese DOS line-drawing char(0x01 etc) is used,\n" \
                                  "try Other-254.\n" \
                                  "ACP may be proper for Western-Europe language.\n" \
                                  "Select from other listbox for the other foreign language.\n" \
                                  "Restart wxe when changed charset between DBCS and SBCS language." \
//#define  SIDH_COLORBOX            "色サンプル表示"               //~v77DR~
#define  SIDH_COLORBOX            "色サンプル\x95\\示"             //~v77DR~
#define  SIDH_COLORBOX_E          "Color mix sample display window"
#define  SIDH_COLW                "文字間の幅。"
#define  SIDH_COLW_E              "Width of char cell"
//#define  SIDH_CSANSI              "ANSI:漢字表示なし"            //~v77DR~
#define  SIDH_CSANSI              "ANSI:漢字\x95\\示なし"          //~v77DR~
#define  SIDH_CSANSI_E            "ANSI(No Japanese DBCCS mode)"
#define  SIDH_CSDEFAULT           "省略値"
#define  SIDH_CSDEFAULT_E         "Default"
#define  SIDH_CSOTHER             "その他。フォントスタイルとの組み合わせで\n" \
                                  "特別なCodeSetを使用するときEditBoxに\n" \
                                  "CodeSet番号を指定する。(WINGDI.H 参照)\n" \
                                  "128:(日)SJIS、129:(韓)ハングル、134:(中)GB2312、136:(中)BIG5"//~v79zI~
#define  SIDH_CSOTHER_E           "Check and specify CodePage to EditBox\n" \
                                  "See WINGDI.H .\n" \
                                  "128:(J) SJIS, 129:(K) Hangul, 134:(C) GB2312, 136:(C) BIG5"//~v79zI~
//#define  SIDH_CSSJIS              "漢字表示の場合SJISを指定する" //~v77DR~
#define  SIDH_CSSJIS              "漢字\x95\\示の場合SJISを指定する"//~v77DR~
#define  SIDH_CSSJIS_E            "Japanese DBCS by SJIS"
//#define  SIDH_FONTBOX             "フォントスタイル、サイズサンプル表示"//~v77DR~
#define  SIDH_FONTBOX             "フォントスタイル、サイズサンプル\x95\\示"//~v77DR~
#define  SIDH_FONTBOX_E           "Sample font display window"
#define  SIDH_FONTH               "フォントの高さ"
#define  SIDH_FONTH_E             "Font height"
#define  SIDH_FONTSTYLE           "フォント名"
#define  SIDH_FONTSTYLE_E         "Font face name"
#define  SIDH_FONTW               "フォントの幅"
#define  SIDH_FONTW_E             "Font width"
#define  SIDH_FORMGRP             "用紙関連"
#define  SIDH_FORMGRP_E           "Form parameters"
#define  SIDH_FORMSIZE            "用紙サイズ"
#define  SIDH_FORMSIZE_E          "Select form size"
/*#define  SIDH_FREECSR             "カーソルが画面端に達したときスクロルするか否か\n" \
                                  "チェックするとスクロルしない。"
*/                                                                 //~v77DI~
#define  SIDH_FREECSR             "カー\x83\\ルが画面端に達したときスクロルするか否か\n" \
                                  "チェックするとスクロルしない。" //~v77DI~
#define  SIDH_FREECSR_E           "Scroll(check off) or Wrap(check on)\n" \
                                  "when curser reached to edge of screen."  
#define  SIDH_FULLPAGE            "ファイル印刷またはWWScrPrt Offのときの画面印刷で^n" \
                                  "縦/横とも用紙一杯に印刷。"
#define  SIDH_FULLPAGE_E          "Ignore font height-width rate and fill whole page,\n" \
                                  "for file print or hardcopy with WWScrPrt off."  
#define  SIDH_GREEN               "緑"
#define  SIDH_GREEN_E             "Green"
#define  SIDH_LANDSCAPE           "用紙を横広で印刷する"
#define  SIDH_LANDSCAPE_E         "Landscape setting(Not tall but wide)"
#define  SIDH_MARGINBOTTOM        "下マージン。単位はmm"
#define  SIDH_MARGINBOTTOM_E      "Bottom margin by mm"
#define  SIDH_MARGINGRP           "Left(左),Right(右),Top(上),Bottom(下)。単位はmm"
#define  SIDH_MARGINGRP_E         "Left,Right,Top,Bottom mergin, unit is mm"
#define  SIDH_MARGINLEFT          "左マージン。単位はmm"
#define  SIDH_MARGINLEFT_E        "Left margin by mm."
#define  SIDH_MARGINRIGHT         "右マージン。単位はmm"
#define  SIDH_MARGINRIGHT_E       "Right margin by mm"
#define  SIDH_MARGINTOP           "上マージン。単位はmm"
#define  SIDH_MARGINTOP_E         "Top margin by mm"
#define  SIDH_OTHERCHARSET        "Otherを選択したときCodeSetNumberを指定する"
#define  SIDH_OTHERCHARSET_E      "Enter CodePage when Other is checked"
/*#define  SIDH_PREVIEW             "Preview窓にPreviewを表示、その下に\n" \
                                  "ファイル名、頁数、ファイル行数、\n" \
                                  "ファイル最長行の桁数、頁の行数、桁数を表示"
*/                                                                 //~v77DI~
#define  SIDH_PREVIEW             "Preview窓にPreviewを\x95\\示、その下に\n" \
                                  "ファイル名、頁数、ファイル行数、\n" \
                                  "ファイル最長行の桁数、頁の行数、桁数を\x95\\示"//~v77DR~
#define  SIDH_PREVIEW_E           "File name,page count,file line count,\n" \
                                  "column of the longest line,\n" \
                                  "max column and lines of page are displayed."
//#define  SIDH_PREVIEWBOX          "Preview表示窓"                //~v77DR~
#define  SIDH_PREVIEWBOX          "Preview\x95\\示窓"              //~v77DR~
#define  SIDH_PREVIEWBOX_E        "Preview display window"
#define  SIDH_PREVIEWFILENAME     "Previewファイル名"
#define  SIDH_PREVIEWFILENAME_E   "Current filename"
#define  SIDH_PREVIEWGRP          "Preview要求ボタングループ"
#define  SIDH_PREVIEWGRP_E        "Preview buttons"
#define  SIDH_PREVIEWMAXCOLROW    "１ページの行長、行数"
#define  SIDH_PREVIEWMAXCOLROW_E  "Line length and line count of a page"
#define  SIDH_PREVIEWMAXLRECL     "ファイル行数、最大行長"
#define  SIDH_PREVIEWMAXLRECL_E   "File line count and max line length"
#define  SIDH_PREVIEWNEXT         "次の頁をPreview"
#define  SIDH_PREVIEWNEXT_E       "Preview next page"
#define  SIDH_PREVIEWPAGENO       "Previewする頁番号をEditBoxに入力する。"
#define  SIDH_PREVIEWPAGENO_E     "Enter page number to be previewed"
#define  SIDH_PREVIEWPREV         "前の頁をPreview"
#define  SIDH_PREVIEWPREV_E       "Preview previous page"
#define  SIDH_PREVIEWPRTSCR       "画面プリントをPreview"
#define  SIDH_PREVIEWPRTSCR_E     "Preview hardcopy print"
#define  SIDH_PRINT2P             "2頁/１枚印刷,右のEditBoxに頁間の桁数を指定"
#define  SIDH_PRINT2P_E           "Print 2 page per 1 sheet. Intermediate columns may be set"
#define  SIDH_PRINT2PSPACE        "2頁/１枚印刷の時の左右頁間の桁数"
#define  SIDH_PRINT2PSPACE_E      "Enter intemediate column space of 2 page when 2p is checked"
#define  SIDH_PRINTCAN            "設定を破棄。印刷はしない"
#define  SIDH_PRINTCAN_E          "Exit without saving setup value,print is not done"
#define  SIDH_PRINTCELLH          "行間の高さ"
#define  SIDH_PRINTCELLH_E        "Height of char cell"
#define  SIDH_PRINTCELLW          "文字間の幅"
#define  SIDH_PRINTCELLW_E        "Width of char cell"  
#define  SIDH_PRINTCOLCTR         "一行の桁数,0 の時ファイルの最長行桁数\n" \
                                  "Col/Row by Cell-H/W がチェックされている時は\n" \
                                  "そこで決定された桁数以内の場合に有効"
#define  SIDH_PRINTCOLCTR_E       "Max column of the page.\n" \
                                  "Length of the longest line of the file is used if 0 specified.\n" \
                                  "If \"Col/Row by Cell-H/W\" is checked on,\n" \
                                  "this value is effective when that is smaller than it." 
#define  SIDH_PRINTFILETIME       "Header行にファイルのタイムスタンプを印刷"
#define  SIDH_PRINTFILETIME_E     "Print file time stamp on the header line"
#define  SIDH_PRINTFONTGRP        "フォント関連"
#define  SIDH_PRINTFONTGRP_E      "Font parameters"
#define  SIDH_PRINTFONTH          "フォントの高さ"
#define  SIDH_PRINTFONTH_E        "Font height"
#define  SIDH_PRINTFONTSTYLE      "フォント名"
#define  SIDH_PRINTFONTSTYLE_E    "Font face name"
#define  SIDH_PRINTFONTW          "フォントの幅"
#define  SIDH_PRINTFONTW_E        "Font width"
#define  SIDH_PRINTFOOTER         "Footer行（頁番号）を印刷"
#define  SIDH_PRINTFOOTER_E       "Print footer line(page seq number)"
#define  SIDH_PRINTGO             "ファイル印刷"
#define  SIDH_PRINTGO_E           "Print file"
#define  SIDH_PRINTHEADER         "Header行（ファイル名）を印刷"
#define  SIDH_PRINTHEADER_E       "Print header line(file name)"
#define  SIDH_PRINTLINESEQ        "行番号を左端に印刷する"
#define  SIDH_PRINTLINESEQ_E      "Print line number on the left of page"
/*#define  SIDH_PRINTMAXCELLH       "Col/Row by Cell-H/W がOffのとき ColやRowが 0 のなら\n" \
                                  "頁の行数、桁数をファイルの最大桁数、Cellの縦横比から\n" \
                                  "決定し文字の大きさは桁数、行数から決められる。\n" \
                                  "ファイルの最大桁数が小さいと文字が大きくなりすぎる\n" \
                                  "ことがあるのでCellの高さでこれに上限を設定する。\n" \
                                  "Col/Row by Cell-H/Wが Off かつ Col=Row=0 の時に機能する。\n" \
                                  "値 0 は制限無しの意味。"
*/                                                                 //~v77DI~
#define  SIDH_PRINTMAXCELLH       "Col/Row by Cell-H/W がOffのとき ColやRowが 0 のなら\n" \
                                  "頁の行数、桁数をファイルの最大桁数、Cellの縦横比から\n" \
                                  "決定し文字の大きさは桁数、行数から決められる。\n" \
                                  "ファイルの最大桁数が小さいと文字が大きくなりすぎる\n" \
                                  "ことがあるのでCellの高さでこれに上限を設定する。\n" \
                                  "Col/Row by Cell-H/Wが Off かつ Col=Row=0 の時に機\x94\\する。\n" \
                                  "値 0 は制限無しの意味。"        //~v77DI~
#define  SIDH_PRINTMAXCELLH_E     "Limit the cell height for the case Col and Row is 0\n" \
                                  "to protect too large font is used for the file\n" \
                                  "with small max-column value.\n" \
                                  "Effective only when Col/Row by Cell-H/W is off."
#define  SIDH_PRINTOK             "設定を保存。印刷はしない"
#define  SIDH_PRINTOK_E           "Save setup value without print"
#define  SIDH_PRINTROWCOLBYCELL   "頁の行数、桁数をCell-H,Cell-W設定値で決める"
#define  SIDH_PRINTROWCOLBYCELL_E "Determines max columns and max lines of print\n" \
                                  "page by width and height of text box(cell)." 
#define  SIDH_PRINTROWCTR         "一頁の行数\n" \
                                  "0 の時Column,用紙のサイズ/向き,フォント縦横比から計算\n" \
                                  "Col/Row by Cell-H/W がチェックされている時はそこで\n" \
                                  "決定された桁数以内の場合に有効"
#define  SIDH_PRINTROWCTR_E       "Max line of the page.\n" \
                                  "If 0 is specified,it is determined by form size,\n" \
                                  "form orientation and font height-width rate.\n" \
                                  "If \"Col/Row by Cell-H/W\" is checked on,this value\n" \
                                  "is effective when that is smaller than it." 
#define  SIDH_PRINTTIMESTAMP      "Footerに現在時刻を印刷"
#define  SIDH_PRINTTIMESTAMP_E    "Print current time on the footer line"
#define  SIDH_PRTSCRGO            "画面印刷"
#define  SIDH_PRTSCRGO_E          "Print hardcopy"
#define  SIDH_RED                 "赤"
#define  SIDH_RED_E               "Red"
#define  SIDH_ROWH                "行間の高さ"
#define  SIDH_ROWH_E              "Height of char cell"
#define  SIDH_SCROLLCTR           "マウス中ボタンによる一回のスクロール量"
#define  SIDH_SCROLLCTR_E         "Scroll line count by mouse middle button"
#define  SIDH_SCROLLTIMER         "マウス左ボタンを画面の端でこの時間の３倍押し続けると\n" \
                                  "スクロールを開始し、この時間間隔でスクロールを続ける。\n" \
                                  "0.1秒単位で指定する。"
#define  SIDH_SCROLLTIMER_E       "Scroll start when mouse left button is pushed while\n" \
                                  "3 times of this interval.\n" \
                                  "Scroll is done at each time of this interval.\n" \
                                  "unit is 1/10 sec."
#define  SIDH_TRUETYPE            "指定のフォント名にTrueTypeのフォントが有れば使用される。"
#define  SIDH_TRUETYPE_E          "TrueType is used if the fontface has it"
/*#define  SIDH_USEACCKEY           "アクセラレーター:Fileプルダウンメニューを以下のキーでショートカット\n" \
                                  "xe コマンド\"OPT CCFUNC ON\"による機能を優先したいときは、Checkをはずすこと\n" \
                                  "Shift+Ctrl+文字キーはアクセラレーターのCheckにかかわらずCtrl+文字キーと\n" \
                                  "同じコードが生成されxeに届くのでCCFUNC設定に従う。\n" \
                                  "  Ctrl+\"A\":名前をつけて保存\n" \
                                  "  Ctrl+\"C\":コピー(Cut&Paste)\n" \
                                  "  Ctrl+\"E\":explorer起動\n" \
                                  "  Ctrl+\"H\":PrtScr(画面印刷)\n" \
                                  "  Ctrl+\"I\":貼り付け(Cut&Paste 挿入モード)\n" \
                                  "  Ctrl+\"L\":クリアー(Cut&Paste)\n" \
                                  "  Ctrl+\"M\":DOS窓起動\n" \
                                  "  Ctrl+\"N\":新規ファイル\n" \
                                  "  Ctrl+\"O\":ファイルを開く\n" \
                                  "  Ctrl+\"P\":印刷\n" \
                                  "  Ctrl+\"R\":貼り付け(Cut&PAste 置換モード)\n" \
                                  "  Ctrl+\"S\":保存\n" \
                                  "  Ctrl+\"T\":切り取り(Cut&Paste)\n" \
                                  "  Ctrl+\"V\":Preview(Page設定)\n" \
                                  "  Ctrl+\"X\":終了\n" \
                                  "  Ctrl+\"Z\":About表示"
*/                                                                 //~v77DI~
#define  SIDH_USEACCKEY           "アクセラレーター:Fileプルダウンメニューを以下のキーでショートカット\n" \
                                  "xe コマンド\"OPT CCFUNC ON\"による機\x94\\を優先したいときは、Checkをはずすこと\n" \
                                  "Shift+Ctrl+文字キーはアクセラレーターのCheckにかかわらずCtrl+文字キーと\n" \
                                  "同じコードが生成されxeに届くのでCCFUNC設定に従う。\n" \
                                  "  Ctrl+\"A\":名前をつけて保存\n" \
                                  "  Ctrl+\"C\":コピー(Cut&Paste)\n" \
                                  "  Ctrl+\"E\":explorer起動\n" \
                                  "  Ctrl+\"H\":PrtScr(画面印刷)\n" \
                                  "  Ctrl+\"I\":\x93\\り付け(Cut&Paste 挿入モード)\n" \
                                  "  Ctrl+\"L\":クリアー(Cut&Paste)\n" \
                                  "  Ctrl+\"M\":DOS窓起動\n" \
                                  "  Ctrl+\"N\":新規ファイル\n" \
                                  "  Ctrl+\"O\":ファイルを開く\n" \
                                  "  Ctrl+\"P\":印刷\n" \
                                  "  Ctrl+\"R\":\x93\\り付け(Cut&PAste 置換モード)\n" \
                                  "  Ctrl+\"S\":保存\n" \
                                  "  Ctrl+\"T\":切り取り(Cut&Paste)\n" \
                                  "  Ctrl+\"V\":Preview(Page設定)\n" \
                                  "  Ctrl+\"X\":終了\n" \
                                  "  Ctrl+\"Z\":About\x95\\示"     //~v77DR~
#define  SIDH_USEACCKEY_E         "Accelerator :short cut of pull down menu.\n" \
                                  "Reset check when you want to use function key by \"OPT CCFUNC ON\".\n" \
                                  "Shift+Ctrk+char combination reaches to xe even if Accelerator check is ON,\n" \
                                  "and follows on CCFUNC option.\n" \
                                  "  Ctrl+\"A\":SaveAs\n" \
                                  "  Ctrl+\"C\":Copy(Cut&Paste)\n" \
                                  "  Ctrl+\"E\":start Explorer\n" \
                                  "  Ctrl+\"H\":PrtScr(Hardcopy)\n" \
                                  "  Ctrl+\"I\":Paste(Cut&Paste Insert mode)\n" \
                                  "  Ctrl+\"L\":Clear(Cut&Paste)\n" \
                                  "  Ctrl+\"M\":open DOS prompt screen\n" \
                                  "  Ctrl+\"N\":New file\n" \
                                  "  Ctrl+\"O\":Open file\n" \
                                  "  Ctrl+\"P\":Print file\n" \
                                  "  Ctrl+\"R\":Paste(Cut&PAste Replace mode)\n" \
                                  "  Ctrl+\"S\":Save\n" \
                                  "  Ctrl+\"T\":Cut(Cut&Paste)\n" \
                                  "  Ctrl+\"V\":Preview(PageSetup)\n" \
                                  "  Ctrl+\"X\":Exit\n" \
                                  "  Ctrl+\"Z\":About\n"           //~6A31R~
#define  SIDH_USEMETAKEY          "MenuKey :Alt Keyとの組み合わせによるメニュー選択を有効にする\n" \
                                  "  Alt+\"F\":ファイル\n" \
                                  "  Alt+\"E\":編集\n" \
                                  "  Alt+\"S\":設定\n" \
                                  "  Alt+\"P\":印刷設定\n" \
                                  "  Alt+\"H\":ヘルプ"             //~6A31R~
#define  SIDH_USEMETAKEY_E        "Select menu by conbination with Alt Key\n" \
                                  "  Alt+\"F\":File\n" \
                                  "  Alt+\"E\":Edit\n" \
                                  "  Alt+\"S\":Setup\n" \
                                  "  Alt+\"P\":Preview\n" \
                                  "  Alt+\"H\":Help"
/*#define  SIDH_USERCTL             "右Ctrlキーを実行キーとして使う\n" \
                                  "チェックするとEnterキーは改行のみの機能になる。"
*/                                                                 //~v77DI~
#define  SIDH_USERCTL             "右Ctrlキーを実行キーとして使う\n" \
                                  "チェックするとEnterキーは改行のみの機\x94\\になる。"//~v77DR~
#define  SIDH_USERCTL_E           "Use Right-Ctrl as execute key.\n" \
                                  "When checked,Enter key act as CRLF function"
#define  SIDH_WWSCRPRT            "PrtScr(Hardcopy)でVideo画面全体とアプリケーション画面との\n" \
                                  "比とフォントの縦横比を保持して印刷。Offの場合縦か横か一方を\n" \
                                  "用紙にあわせて印刷。"
#define  SIDH_WWSCRPRT_E          "For PrtScr(HardCopy),keep the rate of application\n" \
                                  "window size and sceen size on paper.\n" \
                                  "If WWScrPrt is off,vertical or horizontal size is expanded\n" \
                                  "to paper boundary."
//#define  SIDH_RULER               "チェックすると十字カーソルの色となる。\n十字カーソル設定はS+C+F1,F2,F3使用。"//~v740R~
//#define  SIDH_RULER_E             "If On,Color is accepted as Ruler(Crosshair) Color.\nToggle key is S+C+F1,F2,F3"//~v740R~
//#define  SIDH_RULER               "チェックすると十字カーソルの色となる。\n十字カーソル用キーは\"RulerKey\"で設定。"//~v77DR~
#define  SIDH_RULER               "チェックすると\x8f\\字カー\x83\\ルの色となる。\n\x8f\\字カー\x83\\ル用キーは\"RulerKey\"で設定。"//~v77DR~
#define  SIDH_RULER_E             "If On,Color is accepted as Ruler(Crosshair) Color.\nSpecify trigger key by \"RukeyKey\"."//~v740I~
//#define  SIDH_RULERKEY            "十字カーソル表示トリガーキーの設定。\nShift+Ctrl+で使用する3個のキーを指定。\n例。\"123\" \"QWE\" \"F10,F11,F13\"。"//~v77DR~
#define  SIDH_RULERKEY            "\x8f\\字カー\x83\\ル\x95\\示トリガーキーの設定。\nShift+Ctrl+で使用する3個のキーを指定。\n例。\"123\" \"QWE\" \"F10,F11,F13\"。"//~v77DR~
#define  SIDH_RULERKEY_E          "Specify 3 trigger key used with Shift-Ctrl- for ruler trigger key.\nex) \"123\" \"QWS\" \"F10,F11,F12\"."//~v740R~
#define  SIDH_QEXIT               "確認ダイアログ無しでExitする。" //~v73yI~
#define  SIDH_QEXIT_E             "Quiet(without confirmation dialog) Exit"//~v73yI~
#define  SIDH_LIGATURE            "リガチャーを試す\nUTF8ファイルでアラビア語など結合しないと意味不明となる言語で試してみる"//~va3gI~
#define  SIDH_LIGATURE_E          "Try Ligature\nfor UTF8 file of langauge requires char combinination such as Arabic."//~va3gI~
