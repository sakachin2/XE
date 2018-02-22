//*CID://+vbi3R~:                             update#=   78;       //+vbi3R~
//*********************************************************************//~v51CI~
//* xekbchkl.h                                                     //~v51CR~
//* dummy func for xekbchk LKED under UNX only                     //~v51CR~
//*********************************************************************//~v51CI~
//vbi3:180211 supprt command history list                          //+vbi3I~
//vba2:170710 add SP cmd to register shortcut path name and use by  sp:xxx//~vba2I~
//vac0:120131 (SMB)node cmd to set volatile password to UFTPHOST   //~vac0I~
//va7K:100904 add SETCP option to cv cmd B2B(change UFHhandle) and SETCP option to EBC cmd.//~va7KI~
//va3d:100206 (LNX)toggle ligature temprary by A+";", change combine key A+"/"-->C+":"//~va3dI~
//va30:100126 combine mode of diacritical marks by A+/(saved to ini)//~va30I~
//va0x:090920!kbd mode change(A+u)                                 //~va0xI~
//v78Z:080708 (3270)sw key assignment by hot key                   //~v78ZI~
//v78r:080326*profile function                                     //~v78rI~
//v783:080227 CUT/PASTE cmd to use another clipboard(save/restore each time)//~v783I~
//v780:080212 syntaxhighlight support                              //~v780I~
//v77F:080204 C+W copy to cmdline(No cmd verb)                     //~v77FI~
//v77E:080203 FW(C+"["/"]")/IW(C+"{"|"}") cmd support              //~v77FI~
//v773:071121*Ctrl+Tab for function that cursor jump between char and hex part//~v773I~
//v76m:070627 find support on =1/=2 filename list panel            //~v76mI~
//v76g:070620 utility panel(3.14:grep and 3.12:compare);f5:open dirlist, dlcmd "^":send//~v76gI~
//v75H:070508 e8("e /f80 p1") command support. lcmd "8" on fname-list and dir-list.//~v75HI~
//v755:070418 add TFLOW cmd                                        //~v755I~
//v74E:070315 BOUNDS cmd support(find,shift-lcmd,paste-lcmd)       //~v74EI~
//v72P:061214 add ic cmd(case insensitive change)                  //~v72PI~
//v715:060221 (LNX)3270 ftp support(hostfile,TSO command)          //~v715I~
//v69J:060712*cap(CAPS LOCK On) support(xe and xeutf)              //~v69JI~
//v690:060418 display file-description support on dir-list panel   //~v690I~
//v670:051224 cmd histry retrieve for each screen(A+F12)           //~v670I~
//v66e:051020 support standard mode cut & paste;                   //~v66eI~
//            A+F6/A+v:range specification, A+F9:copy, A+Ins:paste Ins, A+F8:paste Rep, C+v:paste Del then Ins//~v66eI~
//            A+Del:del+copy to clipboard                          //~v66eI~
//v64v:050708 (LNX)openwith support(! lcmd & ASS cmd)              //~v64vI~
//v61d:050222 support pgtop/pglast for filename list               //~v61dI~
//v592:041031 rsh cmd support                                      //~v592I~
//v57j:040522 sort cmd for dirlist                                 //~v57fI~
//v55N:040318 linetop & lineend for dirlist                        //~v55NI~
//v55n:040218 EXE cmd(execute xe command file)                     //~v55nI~
//v558:040204 new func:path up/down by A+left/right                //~v558I~
//v557:040203 filename list multi-page support                     //~v557I~
//v53m:030928 (LNX)mouse support                                   //~v53mI~
//v53c:030921 alt+w for C&P copy word                              //~v53cI~
//v51C:030713 (LNX)xefunct LKED required for functbl srch to chk pfk used//~v51CI~
//**************************************************************   //~v51CI~
//**************************************************               //~v51CI~
                                                                   //~v51CI~
#define FTFUNC(func)  int func(FUNCPARMS){Ppcw=Ppcw;return 0;}     //~v51CR~
//**************************************************               //~v51CI~
//  FTFUNC(func_up)                                                //~v690R~
//  FTFUNC(func_down)                                              //~v690R~
//  FTFUNC(func_left)                                              //~v690R~
//  FTFUNC(func_right)                                             //~v690R~
//  FTFUNC(func_nexttab_pan)    csr                                //~v51CR~
    FTFUNC(func_nexttab_file)                                      //~v51CI~
//  FTFUNC(func_prevtab_pan)    csr                                //~v51CR~
    FTFUNC(func_prevtab_file)                                      //~v51CR~
    FTFUNC(func_bs_pan)                                            //~v51CI~
    FTFUNC(func_bs_file)                                           //~v51CI~
//  FTFUNC(func_ins)            scr2                               //~v51CR~
    FTFUNC(func_del_pan)                                           //~v51CI~
    FTFUNC(func_del_file)                                          //~v51CI~
    FTFUNC(func_lineup_file)                                       //~v51CI~
    FTFUNC(func_linedown_file)                                     //~v51CI~
    FTFUNC(func_pgup_file)                                         //~v51CI~
    FTFUNC(func_pgup_pan)                                          //~v557I~
    FTFUNC(func_pgdown_file)                                       //~v51CI~
    FTFUNC(func_pgdown_pan)                                        //~v557I~
    FTFUNC(func_pgleft_file)                                       //~v51CI~
    FTFUNC(func_pgright_file)                                      //~v51CI~
    FTFUNC(func_pgtop_pan)                                         //~v61dI~
    FTFUNC(func_pgend_pan)                                         //~v61dI~
//  FTFUNC(func_nextline)       csr                                //~v51CR~
//  FTFUNC(func_prevline)       csr                                //~v51CR~
    FTFUNC(func_exec_pan)                                          //~v51CI~
    FTFUNC(func_exec_file)                                         //~v51CI~
    FTFUNC(func_exec_dir)                                          //~v51CI~
    FTFUNC(func_linetop_pan)                                       //~v51CI~
    FTFUNC(func_linetop_file)                                      //~v51CI~
    FTFUNC(func_linetop_dir)                                       //~v55NI~
    FTFUNC(func_lineend_pan)                                       //~v51CI~
    FTFUNC(func_lineend_file)                                      //~v51CI~
    FTFUNC(func_lineend_dir)                                       //~v55NI~
    FTFUNC(func_filetop_file)                                      //~v51CI~
    FTFUNC(func_fileend_file)                                      //~v51CI~
    FTFUNC(func_nextvalue_pan)                                     //~v51CI~
    FTFUNC(func_prevvalue_pan)                                     //~v51CI~
    FTFUNC(func_dlcmdcut_dir)                                      //~v51CI~
    FTFUNC(func_dlcmdpaste_dir)                                    //~v51CI~
    FTFUNC(func_dlcmdchngsz_dir)                                   //~v51CI~
#ifdef UNX                                                         //~v51CI~
    FTFUNC(func_dlcmduidorsz_dir)                                  //~v51CI~
#endif                                                             //~v51CI~
    FTFUNC(func_dlcmdlfn_dir)   //long filename dispaly mode change//~v51CI~
//  FTFUNC(func_home)          //csr                               //~v51CR~
    FTFUNC(func_splitline_file)                                    //~v51CI~
    FTFUNC(func_join_file)      //join cmd                         //~v51CI~
    FTFUNC(func_insline_file)                                      //~v51CI~
    FTFUNC(func_delline_file)                                      //~v51CI~
    FTFUNC(func_eraseeol_pan)                                      //~v51CI~
    FTFUNC(func_eraseeol_file)                                     //~v51CI~
    FTFUNC(func_erasetol_pan)                                      //~v51CI~
    FTFUNC(func_erasetol_file)                                     //~v51CI~
    FTFUNC(func_cleartol_pan)                                      //~v51CI~
    FTFUNC(func_cleartol_file)                                     //~v51CI~
    FTFUNC(func_help)                                              //~v51CR~
    FTFUNC(func_save_file)                                         //~v51CI~
    FTFUNC(func_quit)                                              //~v51CR~
    FTFUNC(func_exit)                                              //~v51CR~
    FTFUNC(func_term)                                              //~v51CR~
    FTFUNC(func_end_pan)                                           //~v51CI~
    FTFUNC(func_end_file)                                          //~v51CI~
    FTFUNC(func_end_dir)                                           //~v51CI~
    FTFUNC(func_find_file)                                         //~v51CI~
    FTFUNC(func_ifind_file)	//case insecsitive find                //~v51CI~
    FTFUNC(func_rfind_file)	//repeat find                          //~v51CI~
    FTFUNC(func_revrfind_file)	//reverse repeat find              //~v51CI~
    FTFUNC(func_change_file)                                       //~v51CI~
    FTFUNC(func_rchange_file)                                      //~v51CI~
    FTFUNC(func_revrchange_file)                                   //~v51CI~
    FTFUNC(func_cancel_file)                                       //~v51CI~
    FTFUNC(func_cancel_pan)                                        //~v51CI~
    FTFUNC(func_cancel_dir)                                        //~v51CI~
//  FTFUNC(func_splith)     xescr2                                 //~v51CR~
//  FTFUNC(func_splitv)       scr2                                 //~v51CR~
//  FTFUNC(func_swap)         scr2                                 //~v51CR~
    FTFUNC(func_create_file)                                       //~v51CI~
    FTFUNC(func_edit_file)                                         //~v51CI~
    FTFUNC(func_edittext_file)                                     //~v51CI~
    FTFUNC(func_editbin_file)                                      //~v51CI~
    FTFUNC(func_editspf_file)                                      //~v51CI~
    FTFUNC(func_editspfcob_file)                                   //~v51CI~
    FTFUNC(func_editspfcobnum_file)                                //~v51CI~
    FTFUNC(func_editspfcob2_file)                                  //~v51CI~
    FTFUNC(func_editspfcob2num_file)                               //~v51CI~
    FTFUNC(func_editf80_file)                                      //~v75HI~
    FTFUNC(func_browse_file)                                       //~v51CI~
    FTFUNC(func_browsetext_file)                                   //~v51CI~
    FTFUNC(func_browsebin_file)                                    //~v51CI~
    FTFUNC(func_browsespf_file)                                    //~v51CI~
    FTFUNC(func_browsespfcob_file)                                 //~v51CI~
    FTFUNC(func_browsespfcobnum_file)                              //~v51CI~
    FTFUNC(func_browsespfcob2_file)                                //~v51CI~
    FTFUNC(func_browsespfcob2num_file)                             //~v51CI~
    FTFUNC(func_browsef80_file)                                    //~v75HI~
    FTFUNC(func_select)                                            //~v51CI~
    FTFUNC(func_selecttext)                                        //~v51CI~
    FTFUNC(func_selectbin)                                         //~v51CI~
    FTFUNC(func_selectspf)                                         //~v51CI~
    FTFUNC(func_selectspfcob)                                      //~v51CI~
    FTFUNC(func_selectspfcobnum)                                   //~v51CI~
    FTFUNC(func_selectspfcob2)                                     //~v51CI~
    FTFUNC(func_selectspfcob2num)                                  //~v51CI~
    FTFUNC(func_selectf80)                                         //~v75HI~
    FTFUNC(func_retrieveprev)                                      //~v51CR~
    FTFUNC(func_retrieveprevscr)                                   //~v670I~
    FTFUNC(func_retrievenext)                                      //~v51CR~
    FTFUNC(func_retrievenextscr)                                   //~v670I~
    FTFUNC(func_undo_file)                                         //~v51CI~
    FTFUNC(func_redo_file)                                         //~v51CR~
    FTFUNC(func_repline_file)                                      //~v51CI~
//  FTFUNC(func_nextpan)      scr2                                 //~v51CR~
//  FTFUNC(func_prevpan)      scr2                                 //~v51CR~
    FTFUNC(func_dos)                                               //~v51CI~
    FTFUNC(func_locate_file)                                       //~v51CI~
    FTFUNC(func_locate_dir)                                        //~v51CI~
    FTFUNC(func_copy_file)                                         //~v51CI~
    FTFUNC(func_repl_file)                                         //~v51CI~
    FTFUNC(func_hex_file)                                          //~v51CR~
    FTFUNC(func_tabctr_file)                                       //~v51CI~
    FTFUNC(func_reset)                                             //~v51CR~
    FTFUNC(func_char)                                              //~v51CR~
    FTFUNC(func_char_pan)                                          //~v51CI~
    FTFUNC(func_char_file)                                         //~v51CI~
    FTFUNC(func_block_file)                                        //~v51CI~
    FTFUNC(func_copytocb_file)	//save cap dat to cb               //~v51CI~
    FTFUNC(func_lmark_file)      //line mark                       //~v51CI~
    FTFUNC(func_blockrep_file)                                     //~v51CI~
    FTFUNC(func_blockrep_pan)                                      //~v51CI~
    FTFUNC(func_blockdel_file)                                     //~v51CI~
    FTFUNC(func_blockins_file)                                     //~v51CI~
    FTFUNC(func_blockins_pan)                                      //~v51CI~
    FTFUNC(func_blockclear_file)                                   //~v51CI~
    FTFUNC(func_blockcutmove_file)                                 //~v51CI~
    FTFUNC(func_blockclearmove_file)                               //~v51CI~
    FTFUNC(func_stdcpregion_file)                                  //~v66eI~
    FTFUNC(func_stdcppaste_file)                                   //~v66eI~
    FTFUNC(func_stdcppaste_pan)                                    //~v66eI~
    FTFUNC(func_lineexclude_file)                                  //~v51CI~
    FTFUNC(func_lineinclude_file)                                  //~v51CI~
//  FTFUNC(func_csrstep)          //csr                            //~v51CR~
    FTFUNC(func_cid)                                               //~v51CI~
    FTFUNC(func_setscroll)                                         //~v51CI~
    FTFUNC(func_ini)                                               //~v51CI~
    FTFUNC(func_opt)                                               //~v51CI~
    FTFUNC(func_number)                                            //~v51CI~
    FTFUNC(func_draw_pan)                                          //~v51CR~
    FTFUNC(func_draw_file)                                         //~v51CI~
    FTFUNC(func_draw_dir)                                          //~v51CI~
//  FTFUNC(func_cmd)               //xefunc                        //~v51CR~
    FTFUNC(func_version)                                           //~v51CI~
    FTFUNC(func_drop_file)                                         //~v51CI~
    FTFUNC(func_exclude_file)                                      //~v51CI~
    FTFUNC(func_iexclude_file)                                     //~v51CI~
    FTFUNC(func_xx_file)        //reverse excluded                 //~v51CI~
    FTFUNC(func_append_file)                                       //~v51CI~
//  FTFUNC(func_pos_pan)      //csr                                //~v51CR~
    FTFUNC(func_key)                                               //~v51CR~
    FTFUNC(func_submit)                                            //~v51CI~
    FTFUNC(func_hexinput)                                          //~v51CR~
    FTFUNC(func_findnx_file)                                       //~v51CI~
    FTFUNC(func_ifindnx_file)	//case insecsitive find            //~v51CI~
    FTFUNC(func_changenx_file)                                     //~v51CI~
    FTFUNC(func_sort)                                              //~v51CI~
    FTFUNC(func_sort_dir)                                          //~v57fI~
    FTFUNC(func_col)                                               //~v51CI~
    FTFUNC(func_dlcmdrefresh)                                      //~v51CI~
    FTFUNC(func_bc)                                                //~v51CI~
    FTFUNC(func_tc)                                                //~v51CI~
    FTFUNC(func_ppsrch)                                            //~v51CI~
    FTFUNC(func_ppsrchnx)                                          //~v51CI~
    FTFUNC(func_browsehex_file)                                    //~v51CI~
    FTFUNC(func_edithex_file)                                      //~v51CI~
    FTFUNC(func_selecthex_file)                                    //~v51CI~
    FTFUNC(func_cmdrepeat)                                         //~v51CR~
    FTFUNC(func_dbcsconv)                                          //~v51CI~
//  FTFUNC(func_shortcut)          xekbd                           //~v51CR~
//  FTFUNC(func_shortcutquery)       kbd                           //~v51CR~
    FTFUNC(func_renum)                                             //~v51CI~
    FTFUNC(func_rotate)                                            //~v51CI~
    FTFUNC(func_copyword)                                          //~v53cI~
    FTFUNC(func_pathup)                                            //~v558I~
    FTFUNC(func_pathdown)                                          //~v558I~
    FTFUNC(func_execmdfile)                                        //~v55nI~
    FTFUNC(func_rsh)                                               //~v592I~
    FTFUNC(func_desc_dir)                                          //~v690R~
#if defined(W32)||defined(LNX)                                     //~v64vI~
    FTFUNC(func_openwith)                                          //~v64vI~
#endif                                                             //~v64vR~
    FTFUNC(dcmd_xdelete)                                           //~v51CI~
    FTFUNC(dcmd_xcopy)                                             //~v51CI~
    FTFUNC(dcmd_xmove)                                             //~v51CI~
    FTFUNC(dcmd_append)                                            //~v51CI~
    FTFUNC(dcmd_rename)                                            //~v51CI~
    FTFUNC(func_capslock)                                          //~v69JI~
    FTFUNC(func_tso)                                               //~v715I~
    FTFUNC(func_ichange_file)                                      //~v72PI~
    FTFUNC(func_ichangenx_file)                                    //~v72PI~
    FTFUNC(func_bnds)                                              //~v74EI~
    FTFUNC(func_tflow)                                             //~v755I~
    FTFUNC(func_rfind_pan)                                         //~v76gI~
    FTFUNC(func_sendins_dir)                                       //~v76gI~
    FTFUNC(func_sendins_pan)                                       //~v76gI~
    FTFUNC(func_sendrep_dir)                                       //~v76gI~
    FTFUNC(func_sendrep_pan)                                       //~v76gI~
    FTFUNC(func_senddel_dir)                                       //~v76gI~
    FTFUNC(func_sendup_dir)                                        //~v76gI~
    FTFUNC(func_senddown_dir)                                      //~v76gI~
    FTFUNC(func_find_pan)                                          //~v76mI~
    FTFUNC(func_ifind_pan)                                         //~v76mI~
    FTFUNC(func_revrfind_pan)                                      //~v76mI~
    FTFUNC(func_jumpcharhex_file)                                  //~v773I~
	FTFUNC(func_findwordF_file)                                    //~v77FI~
	FTFUNC(func_findwordB_file)                                    //~v77FI~
	FTFUNC(func_ifindwordF_file)                                   //~v77FI~
	FTFUNC(func_ifindwordB_file)                                   //~v77FI~
	FTFUNC(func_copywordcmd_file)                                  //~v77FI~
	FTFUNC(func_syntax)                                            //~v780I~
	FTFUNC(func_cut_file)                                          //~v783I~
	FTFUNC(func_paste_file)                                        //~v783I~
	FTFUNC(func_profile)                                           //~v78rI~
#ifdef FTPSUPP                                                     //~v78ZI~
	FTFUNC(func_tsohotkey)                                         //~v78ZI~
	FTFUNC(func_3270kbd)                                           //~v78ZI~
#endif                                                             //~v78ZI~
#ifdef UTF8SUPPH                                                    //~v90xI~//~va0xI~
	FTFUNC(func_mode);                                             //~v90xR~//~va0xI~
#endif                                                             //~v90xI~//~va0xI~
#ifdef UTF8UCS2                                                    //~va30I~
	FTFUNC(func_optcombine)                                        //~va30I~
	FTFUNC(func_optligature);                                      //~va3dI~
#endif                                                             //~va30I~
	FTFUNC(func_ebc);                                              //~va7KI~
	FTFUNC(func_node);                                             //~vac0I~
	FTFUNC(func_cmdhistu8);                                        //+vbi3I~
//*****************************************                        //~v51CI~
void funcfreecmdstack(void){return;}                               //~v51CI~
int panfunc000optchk(PUCLIENTWE Ppcw,UCHAR *Pcmd,int *Prc){return 0;}//~v51CI~
int mousel_btnproc(KBDKEYINFO *Ppkeyinfo){return 0;}               //~v53mI~
int mousel_funcsrch(PUCLIENTWE Ppcw,UCHAR *Pxy,FUNCTBL **Pppft,FTFUNC **Ppfunc)//~v53mI~
{return 0;}                                                        //~v53mI~
int func_shortpath(PUCLIENTWE Ppcw){return 0;}                     //~vba2I~
