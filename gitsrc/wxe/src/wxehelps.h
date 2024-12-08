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
#define  SIDH_BEEP                "�G���[�̂Ƃ��r�[�v"
#define  SIDH_BEEP_E              "Beep when error"
#define  SIDH_BGCOLOR             "3�F�~�b�N�X"
#define  SIDH_BGCOLOR_E           "3 color mix"
#define  SIDH_BLUE                "��"
#define  SIDH_BLUE_E              "Blue"
/*#define  SIDH_CHARSET             "CharSet:�����\���̏ꍇSJIS���w�肷��B\n" \
                                  "Windows�̔łɂ���Č��ʂɈႢ���L��悤�ł��B\n" \
                                  "���{��DOS�r������(x01)��\������ꍇother 254��\n" \
                                  "�����Ă݂Ă��������B\n" \
                                  "�O�������ł�other��CharSet�ԍ��w�肪������������܂���B"
*/                                                                 //~v77DI~
//#define  SIDH_CHARSET             "CharSet:����\x95\\���̏ꍇSJIS���w�肷��B\n"//~va75R~
#define  SIDH_CHARSET             "�t�H���g�p�����Z�b�g�B\n" \
                                  "���{��̏ꍇDefault��SJIS���w�肷��B\n" \
                                  "���{��DOS�r������(x01)��\x95\\������ꍇother 254��\n" \
                                  "�����Ă݂Ă��������B\n" \
                                  "��������ł�ACP���ǂ��ł��傤�B\n"/*~v77DI~*/\
                                  "���̑��̊O����ł� other ����I��ł��������B\n"/*~v77DI~*/\
                                  "DCCS<->SBCS�̕ύX�̏ꍇ wxe �����X�^�[�g���Ă��������B"//~va78R~
//#define  SIDH_CHARSET_E           "Use SJIS for Japanese DBCS.\n"//~va75R~
#define  SIDH_CHARSET_E           "Font charset.\n" \
                                  "Use Deafult or SJIS for Japanese.\n" \
                                  "If Japanese DOS line-drawing char(0x01 etc) is used,\n" \
                                  "try Other-254.\n" \
                                  "ACP may be proper for Western-Europe language.\n" \
                                  "Select from other listbox for the other foreign language.\n" \
                                  "Restart wxe when changed charset between DBCS and SBCS language." \
//#define  SIDH_COLORBOX            "�F�T���v���\��"               //~v77DR~
#define  SIDH_COLORBOX            "�F�T���v��\x95\\��"             //~v77DR~
#define  SIDH_COLORBOX_E          "Color mix sample display window"
#define  SIDH_COLW                "�����Ԃ̕��B"
#define  SIDH_COLW_E              "Width of char cell"
//#define  SIDH_CSANSI              "ANSI:�����\���Ȃ�"            //~v77DR~
#define  SIDH_CSANSI              "ANSI:����\x95\\���Ȃ�"          //~v77DR~
#define  SIDH_CSANSI_E            "ANSI(No Japanese DBCCS mode)"
#define  SIDH_CSDEFAULT           "�ȗ��l"
#define  SIDH_CSDEFAULT_E         "Default"
#define  SIDH_CSOTHER             "���̑��B�t�H���g�X�^�C���Ƃ̑g�ݍ��킹��\n" \
                                  "���ʂ�CodeSet���g�p����Ƃ�EditBox��\n" \
                                  "CodeSet�ԍ����w�肷��B(WINGDI.H �Q��)\n" \
                                  "128:(��)SJIS�A129:(��)�n���O���A134:(��)GB2312�A136:(��)BIG5"//~v79zI~
#define  SIDH_CSOTHER_E           "Check and specify CodePage to EditBox\n" \
                                  "See WINGDI.H .\n" \
                                  "128:(J) SJIS, 129:(K) Hangul, 134:(C) GB2312, 136:(C) BIG5"//~v79zI~
//#define  SIDH_CSSJIS              "�����\���̏ꍇSJIS���w�肷��" //~v77DR~
#define  SIDH_CSSJIS              "����\x95\\���̏ꍇSJIS���w�肷��"//~v77DR~
#define  SIDH_CSSJIS_E            "Japanese DBCS by SJIS"
//#define  SIDH_FONTBOX             "�t�H���g�X�^�C���A�T�C�Y�T���v���\��"//~v77DR~
#define  SIDH_FONTBOX             "�t�H���g�X�^�C���A�T�C�Y�T���v��\x95\\��"//~v77DR~
#define  SIDH_FONTBOX_E           "Sample font display window"
#define  SIDH_FONTH               "�t�H���g�̍���"
#define  SIDH_FONTH_E             "Font height"
#define  SIDH_FONTSTYLE           "�t�H���g��"
#define  SIDH_FONTSTYLE_E         "Font face name"
#define  SIDH_FONTW               "�t�H���g�̕�"
#define  SIDH_FONTW_E             "Font width"
#define  SIDH_FORMGRP             "�p���֘A"
#define  SIDH_FORMGRP_E           "Form parameters"
#define  SIDH_FORMSIZE            "�p���T�C�Y"
#define  SIDH_FORMSIZE_E          "Select form size"
/*#define  SIDH_FREECSR             "�J�[�\������ʒ[�ɒB�����Ƃ��X�N�������邩�ۂ�\n" \
                                  "�`�F�b�N����ƃX�N�������Ȃ��B"
*/                                                                 //~v77DI~
#define  SIDH_FREECSR             "�J�[\x83\\������ʒ[�ɒB�����Ƃ��X�N�������邩�ۂ�\n" \
                                  "�`�F�b�N����ƃX�N�������Ȃ��B" //~v77DI~
#define  SIDH_FREECSR_E           "Scroll(check off) or Wrap(check on)\n" \
                                  "when curser reached to edge of screen."  
#define  SIDH_FULLPAGE            "�t�@�C������܂���WWScrPrt Off�̂Ƃ��̉�ʈ����^n" \
                                  "�c/���Ƃ��p����t�Ɉ���B"
#define  SIDH_FULLPAGE_E          "Ignore font height-width rate and fill whole page,\n" \
                                  "for file print or hardcopy with WWScrPrt off."  
#define  SIDH_GREEN               "��"
#define  SIDH_GREEN_E             "Green"
#define  SIDH_LANDSCAPE           "�p�������L�ň������"
#define  SIDH_LANDSCAPE_E         "Landscape setting(Not tall but wide)"
#define  SIDH_MARGINBOTTOM        "���}�[�W���B�P�ʂ�mm"
#define  SIDH_MARGINBOTTOM_E      "Bottom margin by mm"
#define  SIDH_MARGINGRP           "Left(��),Right(�E),Top(��),Bottom(��)�B�P�ʂ�mm"
#define  SIDH_MARGINGRP_E         "Left,Right,Top,Bottom mergin, unit is mm"
#define  SIDH_MARGINLEFT          "���}�[�W���B�P�ʂ�mm"
#define  SIDH_MARGINLEFT_E        "Left margin by mm."
#define  SIDH_MARGINRIGHT         "�E�}�[�W���B�P�ʂ�mm"
#define  SIDH_MARGINRIGHT_E       "Right margin by mm"
#define  SIDH_MARGINTOP           "��}�[�W���B�P�ʂ�mm"
#define  SIDH_MARGINTOP_E         "Top margin by mm"
#define  SIDH_OTHERCHARSET        "Other��I�������Ƃ�CodeSetNumber���w�肷��"
#define  SIDH_OTHERCHARSET_E      "Enter CodePage when Other is checked"
/*#define  SIDH_PREVIEW             "Preview����Preview��\���A���̉���\n" \
                                  "�t�@�C�����A�Ő��A�t�@�C���s���A\n" \
                                  "�t�@�C���Œ��s�̌����A�ł̍s���A������\��"
*/                                                                 //~v77DI~
#define  SIDH_PREVIEW             "Preview����Preview��\x95\\���A���̉���\n" \
                                  "�t�@�C�����A�Ő��A�t�@�C���s���A\n" \
                                  "�t�@�C���Œ��s�̌����A�ł̍s���A������\x95\\��"//~v77DR~
#define  SIDH_PREVIEW_E           "File name,page count,file line count,\n" \
                                  "column of the longest line,\n" \
                                  "max column and lines of page are displayed."
//#define  SIDH_PREVIEWBOX          "Preview�\����"                //~v77DR~
#define  SIDH_PREVIEWBOX          "Preview\x95\\����"              //~v77DR~
#define  SIDH_PREVIEWBOX_E        "Preview display window"
#define  SIDH_PREVIEWFILENAME     "Preview�t�@�C����"
#define  SIDH_PREVIEWFILENAME_E   "Current filename"
#define  SIDH_PREVIEWGRP          "Preview�v���{�^���O���[�v"
#define  SIDH_PREVIEWGRP_E        "Preview buttons"
#define  SIDH_PREVIEWMAXCOLROW    "�P�y�[�W�̍s���A�s��"
#define  SIDH_PREVIEWMAXCOLROW_E  "Line length and line count of a page"
#define  SIDH_PREVIEWMAXLRECL     "�t�@�C���s���A�ő�s��"
#define  SIDH_PREVIEWMAXLRECL_E   "File line count and max line length"
#define  SIDH_PREVIEWNEXT         "���̕ł�Preview"
#define  SIDH_PREVIEWNEXT_E       "Preview next page"
#define  SIDH_PREVIEWPAGENO       "Preview����Ŕԍ���EditBox�ɓ��͂���B"
#define  SIDH_PREVIEWPAGENO_E     "Enter page number to be previewed"
#define  SIDH_PREVIEWPREV         "�O�̕ł�Preview"
#define  SIDH_PREVIEWPREV_E       "Preview previous page"
#define  SIDH_PREVIEWPRTSCR       "��ʃv�����g��Preview"
#define  SIDH_PREVIEWPRTSCR_E     "Preview hardcopy print"
#define  SIDH_PRINT2P             "2��/�P�����,�E��EditBox�ɕŊԂ̌������w��"
#define  SIDH_PRINT2P_E           "Print 2 page per 1 sheet. Intermediate columns may be set"
#define  SIDH_PRINT2PSPACE        "2��/�P������̎��̍��E�ŊԂ̌���"
#define  SIDH_PRINT2PSPACE_E      "Enter intemediate column space of 2 page when 2p is checked"
#define  SIDH_PRINTCAN            "�ݒ��j���B����͂��Ȃ�"
#define  SIDH_PRINTCAN_E          "Exit without saving setup value,print is not done"
#define  SIDH_PRINTCELLH          "�s�Ԃ̍���"
#define  SIDH_PRINTCELLH_E        "Height of char cell"
#define  SIDH_PRINTCELLW          "�����Ԃ̕�"
#define  SIDH_PRINTCELLW_E        "Width of char cell"  
#define  SIDH_PRINTCOLCTR         "��s�̌���,0 �̎��t�@�C���̍Œ��s����\n" \
                                  "Col/Row by Cell-H/W ���`�F�b�N����Ă��鎞��\n" \
                                  "�����Ō��肳�ꂽ�����ȓ��̏ꍇ�ɗL��"
#define  SIDH_PRINTCOLCTR_E       "Max column of the page.\n" \
                                  "Length of the longest line of the file is used if 0 specified.\n" \
                                  "If \"Col/Row by Cell-H/W\" is checked on,\n" \
                                  "this value is effective when that is smaller than it." 
#define  SIDH_PRINTFILETIME       "Header�s�Ƀt�@�C���̃^�C���X�^���v�����"
#define  SIDH_PRINTFILETIME_E     "Print file time stamp on the header line"
#define  SIDH_PRINTFONTGRP        "�t�H���g�֘A"
#define  SIDH_PRINTFONTGRP_E      "Font parameters"
#define  SIDH_PRINTFONTH          "�t�H���g�̍���"
#define  SIDH_PRINTFONTH_E        "Font height"
#define  SIDH_PRINTFONTSTYLE      "�t�H���g��"
#define  SIDH_PRINTFONTSTYLE_E    "Font face name"
#define  SIDH_PRINTFONTW          "�t�H���g�̕�"
#define  SIDH_PRINTFONTW_E        "Font width"
#define  SIDH_PRINTFOOTER         "Footer�s�i�Ŕԍ��j�����"
#define  SIDH_PRINTFOOTER_E       "Print footer line(page seq number)"
#define  SIDH_PRINTGO             "�t�@�C�����"
#define  SIDH_PRINTGO_E           "Print file"
#define  SIDH_PRINTHEADER         "Header�s�i�t�@�C�����j�����"
#define  SIDH_PRINTHEADER_E       "Print header line(file name)"
#define  SIDH_PRINTLINESEQ        "�s�ԍ������[�Ɉ������"
#define  SIDH_PRINTLINESEQ_E      "Print line number on the left of page"
/*#define  SIDH_PRINTMAXCELLH       "Col/Row by Cell-H/W ��Off�̂Ƃ� Col��Row�� 0 �̂Ȃ�\n" \
                                  "�ł̍s���A�������t�@�C���̍ő包���ACell�̏c���䂩��\n" \
                                  "���肵�����̑傫���͌����A�s�����猈�߂���B\n" \
                                  "�t�@�C���̍ő包�����������ƕ������傫���Ȃ肷����\n" \
                                  "���Ƃ�����̂�Cell�̍����ł���ɏ����ݒ肷��B\n" \
                                  "Col/Row by Cell-H/W�� Off ���� Col=Row=0 �̎��ɋ@�\����B\n" \
                                  "�l 0 �͐��������̈Ӗ��B"
*/                                                                 //~v77DI~
#define  SIDH_PRINTMAXCELLH       "Col/Row by Cell-H/W ��Off�̂Ƃ� Col��Row�� 0 �̂Ȃ�\n" \
                                  "�ł̍s���A�������t�@�C���̍ő包���ACell�̏c���䂩��\n" \
                                  "���肵�����̑傫���͌����A�s�����猈�߂���B\n" \
                                  "�t�@�C���̍ő包�����������ƕ������傫���Ȃ肷����\n" \
                                  "���Ƃ�����̂�Cell�̍����ł���ɏ����ݒ肷��B\n" \
                                  "Col/Row by Cell-H/W�� Off ���� Col=Row=0 �̎��ɋ@\x94\\����B\n" \
                                  "�l 0 �͐��������̈Ӗ��B"        //~v77DI~
#define  SIDH_PRINTMAXCELLH_E     "Limit the cell height for the case Col and Row is 0\n" \
                                  "to protect too large font is used for the file\n" \
                                  "with small max-column value.\n" \
                                  "Effective only when Col/Row by Cell-H/W is off."
#define  SIDH_PRINTOK             "�ݒ��ۑ��B����͂��Ȃ�"
#define  SIDH_PRINTOK_E           "Save setup value without print"
#define  SIDH_PRINTROWCOLBYCELL   "�ł̍s���A������Cell-H,Cell-W�ݒ�l�Ō��߂�"
#define  SIDH_PRINTROWCOLBYCELL_E "Determines max columns and max lines of print\n" \
                                  "page by width and height of text box(cell)." 
#define  SIDH_PRINTROWCTR         "��ł̍s��\n" \
                                  "0 �̎�Column,�p���̃T�C�Y/����,�t�H���g�c���䂩��v�Z\n" \
                                  "Col/Row by Cell-H/W ���`�F�b�N����Ă��鎞�͂�����\n" \
                                  "���肳�ꂽ�����ȓ��̏ꍇ�ɗL��"
#define  SIDH_PRINTROWCTR_E       "Max line of the page.\n" \
                                  "If 0 is specified,it is determined by form size,\n" \
                                  "form orientation and font height-width rate.\n" \
                                  "If \"Col/Row by Cell-H/W\" is checked on,this value\n" \
                                  "is effective when that is smaller than it." 
#define  SIDH_PRINTTIMESTAMP      "Footer�Ɍ��ݎ��������"
#define  SIDH_PRINTTIMESTAMP_E    "Print current time on the footer line"
#define  SIDH_PRTSCRGO            "��ʈ��"
#define  SIDH_PRTSCRGO_E          "Print hardcopy"
#define  SIDH_RED                 "��"
#define  SIDH_RED_E               "Red"
#define  SIDH_ROWH                "�s�Ԃ̍���"
#define  SIDH_ROWH_E              "Height of char cell"
#define  SIDH_SCROLLCTR           "�}�E�X���{�^���ɂ����̃X�N���[����"
#define  SIDH_SCROLLCTR_E         "Scroll line count by mouse middle button"
#define  SIDH_SCROLLTIMER         "�}�E�X���{�^������ʂ̒[�ł��̎��Ԃ̂R�{�����������\n" \
                                  "�X�N���[�����J�n���A���̎��ԊԊu�ŃX�N���[���𑱂���B\n" \
                                  "0.1�b�P�ʂŎw�肷��B"
#define  SIDH_SCROLLTIMER_E       "Scroll start when mouse left button is pushed while\n" \
                                  "3 times of this interval.\n" \
                                  "Scroll is done at each time of this interval.\n" \
                                  "unit is 1/10 sec."
#define  SIDH_TRUETYPE            "�w��̃t�H���g����TrueType�̃t�H���g���L��Ύg�p�����B"
#define  SIDH_TRUETYPE_E          "TrueType is used if the fontface has it"
/*#define  SIDH_USEACCKEY           "�A�N�Z�����[�^�[:File�v���_�E�����j���[���ȉ��̃L�[�ŃV���[�g�J�b�g\n" \
                                  "xe �R�}���h\"OPT CCFUNC ON\"�ɂ��@�\��D�悵�����Ƃ��́ACheck���͂�������\n" \
                                  "Shift+Ctrl+�����L�[�̓A�N�Z�����[�^�[��Check�ɂ�����炸Ctrl+�����L�[��\n" \
                                  "�����R�[�h����������xe�ɓ͂��̂�CCFUNC�ݒ�ɏ]���B\n" \
                                  "  Ctrl+\"A\":���O�����ĕۑ�\n" \
                                  "  Ctrl+\"C\":�R�s�[(Cut&Paste)\n" \
                                  "  Ctrl+\"E\":explorer�N��\n" \
                                  "  Ctrl+\"H\":PrtScr(��ʈ��)\n" \
                                  "  Ctrl+\"I\":�\��t��(Cut&Paste �}�����[�h)\n" \
                                  "  Ctrl+\"L\":�N���A�[(Cut&Paste)\n" \
                                  "  Ctrl+\"M\":DOS���N��\n" \
                                  "  Ctrl+\"N\":�V�K�t�@�C��\n" \
                                  "  Ctrl+\"O\":�t�@�C�����J��\n" \
                                  "  Ctrl+\"P\":���\n" \
                                  "  Ctrl+\"R\":�\��t��(Cut&PAste �u�����[�h)\n" \
                                  "  Ctrl+\"S\":�ۑ�\n" \
                                  "  Ctrl+\"T\":�؂���(Cut&Paste)\n" \
                                  "  Ctrl+\"V\":Preview(Page�ݒ�)\n" \
                                  "  Ctrl+\"X\":�I��\n" \
                                  "  Ctrl+\"Z\":About�\��"
*/                                                                 //~v77DI~
#define  SIDH_USEACCKEY           "�A�N�Z�����[�^�[:File�v���_�E�����j���[���ȉ��̃L�[�ŃV���[�g�J�b�g\n" \
                                  "xe �R�}���h\"OPT CCFUNC ON\"�ɂ��@\x94\\��D�悵�����Ƃ��́ACheck���͂�������\n" \
                                  "Shift+Ctrl+�����L�[�̓A�N�Z�����[�^�[��Check�ɂ�����炸Ctrl+�����L�[��\n" \
                                  "�����R�[�h����������xe�ɓ͂��̂�CCFUNC�ݒ�ɏ]���B\n" \
                                  "  Ctrl+\"A\":���O�����ĕۑ�\n" \
                                  "  Ctrl+\"C\":�R�s�[(Cut&Paste)\n" \
                                  "  Ctrl+\"E\":explorer�N��\n" \
                                  "  Ctrl+\"H\":PrtScr(��ʈ��)\n" \
                                  "  Ctrl+\"I\":\x93\\��t��(Cut&Paste �}�����[�h)\n" \
                                  "  Ctrl+\"L\":�N���A�[(Cut&Paste)\n" \
                                  "  Ctrl+\"M\":DOS���N��\n" \
                                  "  Ctrl+\"N\":�V�K�t�@�C��\n" \
                                  "  Ctrl+\"O\":�t�@�C�����J��\n" \
                                  "  Ctrl+\"P\":���\n" \
                                  "  Ctrl+\"R\":\x93\\��t��(Cut&PAste �u�����[�h)\n" \
                                  "  Ctrl+\"S\":�ۑ�\n" \
                                  "  Ctrl+\"T\":�؂���(Cut&Paste)\n" \
                                  "  Ctrl+\"V\":Preview(Page�ݒ�)\n" \
                                  "  Ctrl+\"X\":�I��\n" \
                                  "  Ctrl+\"Z\":About\x95\\��"     //~v77DR~
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
#define  SIDH_USEMETAKEY          "MenuKey :Alt Key�Ƃ̑g�ݍ��킹�ɂ�郁�j���[�I����L���ɂ���\n" \
                                  "  Alt+\"F\":�t�@�C��\n" \
                                  "  Alt+\"E\":�ҏW\n" \
                                  "  Alt+\"S\":�ݒ�\n" \
                                  "  Alt+\"P\":����ݒ�\n" \
                                  "  Alt+\"H\":�w���v"             //~6A31R~
#define  SIDH_USEMETAKEY_E        "Select menu by conbination with Alt Key\n" \
                                  "  Alt+\"F\":File\n" \
                                  "  Alt+\"E\":Edit\n" \
                                  "  Alt+\"S\":Setup\n" \
                                  "  Alt+\"P\":Preview\n" \
                                  "  Alt+\"H\":Help"
/*#define  SIDH_USERCTL             "�ECtrl�L�[�����s�L�[�Ƃ��Ďg��\n" \
                                  "�`�F�b�N�����Enter�L�[�͉��s�݂̂̋@�\�ɂȂ�B"
*/                                                                 //~v77DI~
#define  SIDH_USERCTL             "�ECtrl�L�[�����s�L�[�Ƃ��Ďg��\n" \
                                  "�`�F�b�N�����Enter�L�[�͉��s�݂̂̋@\x94\\�ɂȂ�B"//~v77DR~
#define  SIDH_USERCTL_E           "Use Right-Ctrl as execute key.\n" \
                                  "When checked,Enter key act as CRLF function"
#define  SIDH_WWSCRPRT            "PrtScr(Hardcopy)��Video��ʑS�̂ƃA�v���P�[�V������ʂƂ�\n" \
                                  "��ƃt�H���g�̏c�����ێ����Ĉ���BOff�̏ꍇ�c�����������\n" \
                                  "�p���ɂ��킹�Ĉ���B"
#define  SIDH_WWSCRPRT_E          "For PrtScr(HardCopy),keep the rate of application\n" \
                                  "window size and sceen size on paper.\n" \
                                  "If WWScrPrt is off,vertical or horizontal size is expanded\n" \
                                  "to paper boundary."
//#define  SIDH_RULER               "�`�F�b�N����Ə\���J�[�\���̐F�ƂȂ�B\n�\���J�[�\���ݒ��S+C+F1,F2,F3�g�p�B"//~v740R~
//#define  SIDH_RULER_E             "If On,Color is accepted as Ruler(Crosshair) Color.\nToggle key is S+C+F1,F2,F3"//~v740R~
//#define  SIDH_RULER               "�`�F�b�N����Ə\���J�[�\���̐F�ƂȂ�B\n�\���J�[�\���p�L�[��\"RulerKey\"�Őݒ�B"//~v77DR~
#define  SIDH_RULER               "�`�F�b�N�����\x8f\\���J�[\x83\\���̐F�ƂȂ�B\n\x8f\\���J�[\x83\\���p�L�[��\"RulerKey\"�Őݒ�B"//~v77DR~
#define  SIDH_RULER_E             "If On,Color is accepted as Ruler(Crosshair) Color.\nSpecify trigger key by \"RukeyKey\"."//~v740I~
//#define  SIDH_RULERKEY            "�\���J�[�\���\���g���K�[�L�[�̐ݒ�B\nShift+Ctrl+�Ŏg�p����3�̃L�[���w��B\n��B\"123\" \"QWE\" \"F10,F11,F13\"�B"//~v77DR~
#define  SIDH_RULERKEY            "\x8f\\���J�[\x83\\��\x95\\���g���K�[�L�[�̐ݒ�B\nShift+Ctrl+�Ŏg�p����3�̃L�[���w��B\n��B\"123\" \"QWE\" \"F10,F11,F13\"�B"//~v77DR~
#define  SIDH_RULERKEY_E          "Specify 3 trigger key used with Shift-Ctrl- for ruler trigger key.\nex) \"123\" \"QWS\" \"F10,F11,F12\"."//~v740R~
#define  SIDH_QEXIT               "�m�F�_�C�A���O������Exit����B" //~v73yI~
#define  SIDH_QEXIT_E             "Quiet(without confirmation dialog) Exit"//~v73yI~
#define  SIDH_LIGATURE            "���K�`���[������\nUTF8�t�@�C���ŃA���r�A��Ȃǌ������Ȃ��ƈӖ��s���ƂȂ錾��Ŏ����Ă݂�"//~va3gI~
#define  SIDH_LIGATURE_E          "Try Ligature\nfor UTF8 file of langauge requires char combinination such as Arabic."//~va3gI~
