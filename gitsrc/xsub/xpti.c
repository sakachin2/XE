#include <time.h>                                                  //~0416I~
#include <stdio.h>                                                 //~0416I~
#include <stdlib.h>                                                //~0416I~
#include <ctype.h>                                                 //~0416I~
#include <string.h>                                                //~0416I~
#include <ncurses.h>                                               //~0416I~
#include <term.h>                                                  //~0416I~
//*******************************************************          //~0416I~
#include "ulib.h"       //@@@@                                     //~0416I~
#include "uviol.h"       //@@@@                                    //~0416I~
//*******************************************************          //~0416I~
int prntstr(char *Pname,char *Pstr);                               //~0416M~
int prntcurses(void);                                              //~0416M~
//*******************************************************          //~0416I~
int main(int parmc,char **parmp)                                   //~0416I~
 {                                                                 //~0416I~
//******************************************************           //~0416I~
    uviol_init(0);                                                 //~0416I~
    uviol_term();                                                  //~0416I~
    printf("\n");                                                  //~0416R~
    prntcurses();                                                  //~0416R~
	return 0;                                                      //~0416I~
}//main                                                            //~0416I~
//******************************************************           //~0416I~
int prntcurses(void)                                               //~0416I~
{                                                                  //~0416I~
#define PRNTSTR(keyname) prntstr(#keyname,keyname);                //~0416I~
//********************                                             //~0416I~
PRNTSTR( back_tab                       ) // Strings[0]            //~0416I~
PRNTSTR( bell                           ) // Strings[1]            //~0416I~
PRNTSTR( carriage_return                ) // Strings[2]            //~0416I~
PRNTSTR( change_scroll_region           ) // Strings[3]            //~0416I~
PRNTSTR( clear_all_tabs                 ) // Strings[4]            //~0416I~
PRNTSTR( clear_screen                   ) // Strings[5]            //~0416I~
PRNTSTR( clr_eol                        ) // Strings[6]            //~0416I~
PRNTSTR( clr_eos                        ) // Strings[7]            //~0416I~
PRNTSTR( column_address                 ) // Strings[8]            //~0416I~
PRNTSTR( command_character              ) // Strings[9]            //~0416I~
PRNTSTR( cursor_address                 ) // Strings[10]           //~0416I~
PRNTSTR( cursor_down                    ) // Strings[11]           //~0416I~
PRNTSTR( cursor_home                    ) // Strings[12]           //~0416I~
PRNTSTR( cursor_invisible               ) // Strings[13]           //~0416I~
PRNTSTR( cursor_left                    ) // Strings[14]           //~0416I~
PRNTSTR( cursor_mem_address             ) // Strings[15]           //~0416I~
PRNTSTR( cursor_normal                  ) // Strings[16]           //~0416I~
PRNTSTR( cursor_right                   ) // Strings[17]           //~0416I~
PRNTSTR( cursor_to_ll                   ) // Strings[18]           //~0416I~
PRNTSTR( cursor_up                      ) // Strings[19]           //~0416I~
PRNTSTR( cursor_visible                 ) // Strings[20]           //~0416I~
PRNTSTR( delete_character               ) // Strings[21]           //~0416I~
PRNTSTR( delete_line                    ) // Strings[22]           //~0416I~
PRNTSTR( dis_status_line                ) // Strings[23]           //~0416I~
PRNTSTR( down_half_line                 ) // Strings[24]           //~0416I~
PRNTSTR( enter_alt_charset_mode         ) // Strings[25]           //~0416I~
PRNTSTR( enter_blink_mode               ) // Strings[26]           //~0416I~
PRNTSTR( enter_bold_mode                ) // Strings[27]           //~0416I~
PRNTSTR( enter_ca_mode                  ) // Strings[28]           //~0416I~
PRNTSTR( enter_delete_mode              ) // Strings[29]           //~0416I~
PRNTSTR( enter_dim_mode                 ) // Strings[30]           //~0416I~
PRNTSTR( enter_insert_mode              ) // Strings[31]           //~0416I~
PRNTSTR( enter_secure_mode              ) // Strings[32]           //~0416I~
PRNTSTR( enter_protected_mode           ) // Strings[33]           //~0416I~
PRNTSTR( enter_reverse_mode             ) // Strings[34]           //~0416I~
PRNTSTR( enter_standout_mode            ) // Strings[35]           //~0416I~
PRNTSTR( enter_underline_mode           ) // Strings[36]           //~0416I~
PRNTSTR( erase_chars                    ) // Strings[37]           //~0416I~
PRNTSTR( exit_alt_charset_mode          ) // Strings[38]           //~0416I~
PRNTSTR( exit_attribute_mode            ) // Strings[39]           //~0416I~
PRNTSTR( exit_ca_mode                   ) // Strings[40]           //~0416I~
PRNTSTR( exit_delete_mode               ) // Strings[41]           //~0416I~
PRNTSTR( exit_insert_mode               ) // Strings[42]           //~0416I~
PRNTSTR( exit_standout_mode             ) // Strings[43]           //~0416I~
PRNTSTR( exit_underline_mode            ) // Strings[44]           //~0416I~
PRNTSTR( flash_screen                   ) // Strings[45]           //~0416I~
PRNTSTR( form_feed                      ) // Strings[46]           //~0416I~
PRNTSTR( from_status_line               ) // Strings[47]           //~0416I~
PRNTSTR( init_1string                   ) // Strings[48]           //~0416I~
PRNTSTR( init_2string                   ) // Strings[49]           //~0416I~
PRNTSTR( init_3string                   ) // Strings[50]           //~0416I~
PRNTSTR( init_file                      ) // Strings[51]           //~0416I~
PRNTSTR( insert_character               ) // Strings[52]           //~0416I~
PRNTSTR( insert_line                    ) // Strings[53]           //~0416I~
PRNTSTR( insert_padding                 ) // Strings[54]           //~0416I~
PRNTSTR( key_backspace                  ) // Strings[55]           //~0416I~
PRNTSTR( key_catab                      ) // Strings[56]           //~0416I~
PRNTSTR( key_clear                      ) // Strings[57]           //~0416I~
PRNTSTR( key_ctab                       ) // Strings[58]           //~0416I~
PRNTSTR( key_dc                         ) // Strings[59]           //~0416I~
PRNTSTR( key_dl                         ) // Strings[60]           //~0416I~
PRNTSTR( key_down                       ) // Strings[61]           //~0416I~
PRNTSTR( key_eic                        ) // Strings[62]           //~0416I~
PRNTSTR( key_eol                        ) // Strings[63]           //~0416I~
PRNTSTR( key_eos                        ) // Strings[64]           //~0416I~
PRNTSTR( key_f0                         ) // Strings[65]           //~0416I~
PRNTSTR( key_f1                         ) // Strings[66]           //~0416I~
PRNTSTR( key_f10                        ) // Strings[67]           //~0416I~
PRNTSTR( key_f2                         ) // Strings[68]           //~0416I~
PRNTSTR( key_f3                         ) // Strings[69]           //~0416I~
PRNTSTR( key_f4                         ) // Strings[70]           //~0416I~
PRNTSTR( key_f5                         ) // Strings[71]           //~0416I~
PRNTSTR( key_f6                         ) // Strings[72]           //~0416I~
PRNTSTR( key_f7                         ) // Strings[73]           //~0416I~
PRNTSTR( key_f8                         ) // Strings[74]           //~0416I~
PRNTSTR( key_f9                         ) // Strings[75]           //~0416I~
PRNTSTR( key_home                       ) // Strings[76]           //~0416I~
PRNTSTR( key_ic                         ) // Strings[77]           //~0416I~
PRNTSTR( key_il                         ) // Strings[78]           //~0416I~
PRNTSTR( key_left                       ) // Strings[79]           //~0416I~
PRNTSTR( key_ll                         ) // Strings[80]           //~0416I~
PRNTSTR( key_npage                      ) // Strings[81]           //~0416I~
PRNTSTR( key_ppage                      ) // Strings[82]           //~0416I~
PRNTSTR( key_right                      ) // Strings[83]           //~0416I~
PRNTSTR( key_sf                         ) // Strings[84]           //~0416I~
PRNTSTR( key_sr                         ) // Strings[85]           //~0416I~
PRNTSTR( key_stab                       ) // Strings[86]           //~0416I~
PRNTSTR( key_up                         ) // Strings[87]           //~0416I~
PRNTSTR( keypad_local                   ) // Strings[88]           //~0416I~
PRNTSTR( keypad_xmit                    ) // Strings[89]           //~0416I~
PRNTSTR( lab_f0                         ) // Strings[90]           //~0416I~
PRNTSTR( lab_f1                         ) // Strings[91]           //~0416I~
PRNTSTR( lab_f10                        ) // Strings[92]           //~0416I~
PRNTSTR( lab_f2                         ) // Strings[93]           //~0416I~
PRNTSTR( lab_f3                         ) // Strings[94]           //~0416I~
PRNTSTR( lab_f4                         ) // Strings[95]           //~0416I~
PRNTSTR( lab_f5                         ) // Strings[96]           //~0416I~
PRNTSTR( lab_f6                         ) // Strings[97]           //~0416I~
PRNTSTR( lab_f7                         ) // Strings[98]           //~0416I~
PRNTSTR( lab_f8                         ) // Strings[99]           //~0416I~
PRNTSTR( lab_f9                         ) // Strings[100]          //~0416I~
PRNTSTR( meta_off                       ) // Strings[101]          //~0416I~
PRNTSTR( meta_on                        ) // Strings[102]          //~0416I~
PRNTSTR( newline                        ) // Strings[103]          //~0416I~
PRNTSTR( pad_char                       ) // Strings[104]          //~0416I~
PRNTSTR( parm_dch                       ) // Strings[105]          //~0416I~
PRNTSTR( parm_delete_line               ) // Strings[106]          //~0416I~
PRNTSTR( parm_down_cursor               ) // Strings[107]          //~0416I~
PRNTSTR( parm_ich                       ) // Strings[108]          //~0416I~
PRNTSTR( parm_index                     ) // Strings[109]          //~0416I~
PRNTSTR( parm_insert_line               ) // Strings[110]          //~0416I~
PRNTSTR( parm_left_cursor               ) // Strings[111]          //~0416I~
PRNTSTR( parm_right_cursor              ) // Strings[112]          //~0416I~
PRNTSTR( parm_rindex                    ) // Strings[113]          //~0416I~
PRNTSTR( parm_up_cursor                 ) // Strings[114]          //~0416I~
PRNTSTR( pkey_key                       ) // Strings[115]          //~0416I~
PRNTSTR( pkey_local                     ) // Strings[116]          //~0416I~
PRNTSTR( pkey_xmit                      ) // Strings[117]          //~0416I~
PRNTSTR( print_screen                   ) // Strings[118]          //~0416I~
PRNTSTR( prtr_off                       ) // Strings[119]          //~0416I~
PRNTSTR( prtr_on                        ) // Strings[120]          //~0416I~
PRNTSTR( repeat_char                    ) // Strings[121]          //~0416I~
PRNTSTR( reset_1string                  ) // Strings[122]          //~0416I~
PRNTSTR( reset_2string                  ) // Strings[123]          //~0416I~
PRNTSTR( reset_3string                  ) // Strings[124]          //~0416I~
PRNTSTR( reset_file                     ) // Strings[125]          //~0416I~
PRNTSTR( restore_cursor                 ) // Strings[126]          //~0416I~
PRNTSTR( row_address                    ) // Strings[127]          //~0416I~
PRNTSTR( save_cursor                    ) // Strings[128]          //~0416I~
PRNTSTR( scroll_forward                 ) // Strings[129]          //~0416I~
PRNTSTR( scroll_reverse                 ) // Strings[130]          //~0416I~
PRNTSTR( set_attributes                 ) // Strings[131]          //~0416I~
PRNTSTR( set_tab                        ) // Strings[132]          //~0416I~
PRNTSTR( set_window                     ) // Strings[133]          //~0416I~
PRNTSTR( tab                            ) // Strings[134]          //~0416I~
PRNTSTR( to_status_line                 ) // Strings[135]          //~0416I~
PRNTSTR( underline_char                 ) // Strings[136]          //~0416I~
PRNTSTR( up_half_line                   ) // Strings[137]          //~0416I~
PRNTSTR( init_prog                      ) // Strings[138]          //~0416I~
PRNTSTR( key_a1                         ) // Strings[139]          //~0416I~
PRNTSTR( key_a3                         ) // Strings[140]          //~0416I~
PRNTSTR( key_b2                         ) // Strings[141]          //~0416I~
PRNTSTR( key_c1                         ) // Strings[142]          //~0416I~
PRNTSTR( key_c3                         ) // Strings[143]          //~0416I~
PRNTSTR( prtr_non                       ) // Strings[144]          //~0416I~
PRNTSTR( char_padding                   ) // Strings[145]          //~0416I~
PRNTSTR( acs_chars                      ) // Strings[146]          //~0416I~
PRNTSTR( plab_norm                      ) // Strings[147]          //~0416I~
PRNTSTR( key_btab                       ) // Strings[148]          //~0416I~
PRNTSTR( enter_xon_mode                 ) // Strings[149]          //~0416I~
PRNTSTR( exit_xon_mode                  ) // Strings[150]          //~0416I~
PRNTSTR( enter_am_mode                  ) // Strings[151]          //~0416I~
PRNTSTR( exit_am_mode                   ) // Strings[152]          //~0416I~
PRNTSTR( xon_character                  ) // Strings[153]          //~0416I~
PRNTSTR( xoff_character                 ) // Strings[154]          //~0416I~
PRNTSTR( ena_acs                        ) // Strings[155]          //~0416I~
PRNTSTR( label_on                       ) // Strings[156]          //~0416I~
PRNTSTR( label_off                      ) // Strings[157]          //~0416I~
PRNTSTR( key_beg                        ) // Strings[158]          //~0416I~
PRNTSTR( key_cancel                     ) // Strings[159]          //~0416I~
PRNTSTR( key_close                      ) // Strings[160]          //~0416I~
PRNTSTR( key_command                    ) // Strings[161]          //~0416I~
PRNTSTR( key_copy                       ) // Strings[162]          //~0416I~
PRNTSTR( key_create                     ) // Strings[163]          //~0416I~
PRNTSTR( key_end                        ) // Strings[164]          //~0416I~
PRNTSTR( key_enter                      ) // Strings[165]          //~0416I~
PRNTSTR( key_exit                       ) // Strings[166]          //~0416I~
PRNTSTR( key_find                       ) // Strings[167]          //~0416I~
PRNTSTR( key_help                       ) // Strings[168]          //~0416I~
PRNTSTR( key_mark                       ) // Strings[169]          //~0416I~
PRNTSTR( key_message                    ) // Strings[170]          //~0416I~
PRNTSTR( key_move                       ) // Strings[171]          //~0416I~
PRNTSTR( key_next                       ) // Strings[172]          //~0416I~
PRNTSTR( key_open                       ) // Strings[173]          //~0416I~
PRNTSTR( key_options                    ) // Strings[174]          //~0416I~
PRNTSTR( key_previous                   ) // Strings[175]          //~0416I~
PRNTSTR( key_print                      ) // Strings[176]          //~0416I~
PRNTSTR( key_redo                       ) // Strings[177]          //~0416I~
PRNTSTR( key_reference                  ) // Strings[178]          //~0416I~
PRNTSTR( key_refresh                    ) // Strings[179]          //~0416I~
PRNTSTR( key_replace                    ) // Strings[180]          //~0416I~
PRNTSTR( key_restart                    ) // Strings[181]          //~0416I~
PRNTSTR( key_resume                     ) // Strings[182]          //~0416I~
PRNTSTR( key_save                       ) // Strings[183]          //~0416I~
PRNTSTR( key_suspend                    ) // Strings[184]          //~0416I~
PRNTSTR( key_undo                       ) // Strings[185]          //~0416I~
PRNTSTR( key_sbeg                       ) // Strings[186]          //~0416I~
PRNTSTR( key_scancel                    ) // Strings[187]          //~0416I~
PRNTSTR( key_scommand                   ) // Strings[188]          //~0416I~
PRNTSTR( key_scopy                      ) // Strings[189]          //~0416I~
PRNTSTR( key_screate                    ) // Strings[190]          //~0416I~
PRNTSTR( key_sdc                        ) // Strings[191]          //~0416I~
PRNTSTR( key_sdl                        ) // Strings[192]          //~0416I~
PRNTSTR( key_select                     ) // Strings[193]          //~0416I~
PRNTSTR( key_send                       ) // Strings[194]          //~0416I~
PRNTSTR( key_seol                       ) // Strings[195]          //~0416I~
PRNTSTR( key_sexit                      ) // Strings[196]          //~0416I~
PRNTSTR( key_sfind                      ) // Strings[197]          //~0416I~
PRNTSTR( key_shelp                      ) // Strings[198]          //~0416I~
PRNTSTR( key_shome                      ) // Strings[199]          //~0416I~
PRNTSTR( key_sic                        ) // Strings[200]          //~0416I~
PRNTSTR( key_sleft                      ) // Strings[201]          //~0416I~
PRNTSTR( key_smessage                   ) // Strings[202]          //~0416I~
PRNTSTR( key_smove                      ) // Strings[203]          //~0416I~
PRNTSTR( key_snext                      ) // Strings[204]          //~0416I~
PRNTSTR( key_soptions                   ) // Strings[205]          //~0416I~
PRNTSTR( key_sprevious                  ) // Strings[206]          //~0416I~
PRNTSTR( key_sprint                     ) // Strings[207]          //~0416I~
PRNTSTR( key_sredo                      ) // Strings[208]          //~0416I~
PRNTSTR( key_sreplace                   ) // Strings[209]          //~0416I~
PRNTSTR( key_sright                     ) // Strings[210]          //~0416I~
PRNTSTR( key_srsume                     ) // Strings[211]          //~0416I~
PRNTSTR( key_ssave                      ) // Strings[212]          //~0416I~
PRNTSTR( key_ssuspend                   ) // Strings[213]          //~0416I~
PRNTSTR( key_sundo                      ) // Strings[214]          //~0416I~
PRNTSTR( req_for_input                  ) // Strings[215]          //~0416I~
PRNTSTR( key_f11                        ) // Strings[216]          //~0416I~
PRNTSTR( key_f12                        ) // Strings[217]          //~0416I~
PRNTSTR( key_f13                        ) // Strings[218]          //~0416I~
PRNTSTR( key_f14                        ) // Strings[219]          //~0416I~
PRNTSTR( key_f15                        ) // Strings[220]          //~0416I~
PRNTSTR( key_f16                        ) // Strings[221]          //~0416I~
PRNTSTR( key_f17                        ) // Strings[222]          //~0416I~
PRNTSTR( key_f18                        ) // Strings[223]          //~0416I~
PRNTSTR( key_f19                        ) // Strings[224]          //~0416I~
PRNTSTR( key_f20                        ) // Strings[225]          //~0416I~
PRNTSTR( key_f21                        ) // Strings[226]          //~0416I~
PRNTSTR( key_f22                        ) // Strings[227]          //~0416I~
PRNTSTR( key_f23                        ) // Strings[228]          //~0416I~
PRNTSTR( key_f24                        ) // Strings[229]          //~0416I~
PRNTSTR( key_f25                        ) // Strings[230]          //~0416I~
PRNTSTR( key_f26                        ) // Strings[231]          //~0416I~
PRNTSTR( key_f27                        ) // Strings[232]          //~0416I~
PRNTSTR( key_f28                        ) // Strings[233]          //~0416I~
PRNTSTR( key_f29                        ) // Strings[234]          //~0416I~
PRNTSTR( key_f30                        ) // Strings[235]          //~0416I~
PRNTSTR( key_f31                        ) // Strings[236]          //~0416I~
PRNTSTR( key_f32                        ) // Strings[237]          //~0416I~
PRNTSTR( key_f33                        ) // Strings[238]          //~0416I~
PRNTSTR( key_f34                        ) // Strings[239]          //~0416I~
PRNTSTR( key_f35                        ) // Strings[240]          //~0416I~
PRNTSTR( key_f36                        ) // Strings[241]          //~0416I~
PRNTSTR( key_f37                        ) // Strings[242]          //~0416I~
PRNTSTR( key_f38                        ) // Strings[243]          //~0416I~
PRNTSTR( key_f39                        ) // Strings[244]          //~0416I~
PRNTSTR( key_f40                        ) // Strings[245]          //~0416I~
PRNTSTR( key_f41                        ) // Strings[246]          //~0416I~
PRNTSTR( key_f42                        ) // Strings[247]          //~0416I~
PRNTSTR( key_f43                        ) // Strings[248]          //~0416I~
PRNTSTR( key_f44                        ) // Strings[249]          //~0416I~
PRNTSTR( key_f45                        ) // Strings[250]          //~0416I~
PRNTSTR( key_f46                        ) // Strings[251]          //~0416I~
PRNTSTR( key_f47                        ) // Strings[252]          //~0416I~
PRNTSTR( key_f48                        ) // Strings[253]          //~0416I~
PRNTSTR( key_f49                        ) // Strings[254]          //~0416I~
PRNTSTR( key_f50                        ) // Strings[255]          //~0416I~
PRNTSTR( key_f51                        ) // Strings[256]          //~0416I~
PRNTSTR( key_f52                        ) // Strings[257]          //~0416I~
PRNTSTR( key_f53                        ) // Strings[258]          //~0416I~
PRNTSTR( key_f54                        ) // Strings[259]          //~0416I~
PRNTSTR( key_f55                        ) // Strings[260]          //~0416I~
PRNTSTR( key_f56                        ) // Strings[261]          //~0416I~
PRNTSTR( key_f57                        ) // Strings[262]          //~0416I~
PRNTSTR( key_f58                        ) // Strings[263]          //~0416I~
PRNTSTR( key_f59                        ) // Strings[264]          //~0416I~
PRNTSTR( key_f60                        ) // Strings[265]          //~0416I~
PRNTSTR( key_f61                        ) // Strings[266]          //~0416I~
PRNTSTR( key_f62                        ) // Strings[267]          //~0416I~
PRNTSTR( key_f63                        ) // Strings[268]          //~0416I~
PRNTSTR( clr_bol                        ) // Strings[269]          //~0416I~
PRNTSTR( clear_margins                  ) // Strings[270]          //~0416I~
PRNTSTR( set_left_margin                ) // Strings[271]          //~0416I~
PRNTSTR( set_right_margin               ) // Strings[272]          //~0416I~
PRNTSTR( label_format                   ) // Strings[273]          //~0416I~
PRNTSTR( set_clock                      ) // Strings[274]          //~0416I~
PRNTSTR( display_clock                  ) // Strings[275]          //~0416I~
PRNTSTR( remove_clock                   ) // Strings[276]          //~0416I~
PRNTSTR( create_window                  ) // Strings[277]          //~0416I~
PRNTSTR( goto_window                    ) // Strings[278]          //~0416I~
PRNTSTR( hangup                         ) // Strings[279]          //~0416I~
PRNTSTR( dial_phone                     ) // Strings[280]          //~0416I~
PRNTSTR( quick_dial                     ) // Strings[281]          //~0416I~
PRNTSTR( tone                           ) // Strings[282]          //~0416I~
PRNTSTR( pulse                          ) // Strings[283]          //~0416I~
PRNTSTR( flash_hook                     ) // Strings[284]          //~0416I~
PRNTSTR( fixed_pause                    ) // Strings[285]          //~0416I~
PRNTSTR( wait_tone                      ) // Strings[286]          //~0416I~
PRNTSTR( user0                          ) // Strings[287]          //~0416I~
PRNTSTR( user1                          ) // Strings[288]          //~0416I~
PRNTSTR( user2                          ) // Strings[289]          //~0416I~
PRNTSTR( user3                          ) // Strings[290]          //~0416I~
PRNTSTR( user4                          ) // Strings[291]          //~0416I~
PRNTSTR( user5                          ) // Strings[292]          //~0416I~
PRNTSTR( user6                          ) // Strings[293]          //~0416I~
PRNTSTR( user7                          ) // Strings[294]          //~0416I~
PRNTSTR( user8                          ) // Strings[295]          //~0416I~
PRNTSTR( user9                          ) // Strings[296]          //~0416I~
PRNTSTR( orig_pair                      ) // Strings[297]          //~0416I~
PRNTSTR( orig_colors                    ) // Strings[298]          //~0416I~
PRNTSTR( initialize_color               ) // Strings[299]          //~0416I~
PRNTSTR( initialize_pair                ) // Strings[300]          //~0416I~
PRNTSTR( set_color_pair                 ) // Strings[301]          //~0416I~
PRNTSTR( set_foreground                 ) // Strings[302]          //~0416I~
PRNTSTR( set_background                 ) // Strings[303]          //~0416I~
PRNTSTR( change_char_pitch              ) // Strings[304]          //~0416I~
PRNTSTR( change_line_pitch              ) // Strings[305]          //~0416I~
PRNTSTR( change_res_horz                ) // Strings[306]          //~0416I~
PRNTSTR( change_res_vert                ) // Strings[307]          //~0416I~
PRNTSTR( define_char                    ) // Strings[308]          //~0416I~
PRNTSTR( enter_doublewide_mode          ) // Strings[309]          //~0416I~
PRNTSTR( enter_draft_quality            ) // Strings[310]          //~0416I~
PRNTSTR( enter_italics_mode             ) // Strings[311]          //~0416I~
PRNTSTR( enter_leftward_mode            ) // Strings[312]          //~0416I~
PRNTSTR( enter_micro_mode               ) // Strings[313]          //~0416I~
PRNTSTR( enter_near_letter_quality      ) // Strings[314]          //~0416I~
PRNTSTR( enter_normal_quality           ) // Strings[315]          //~0416I~
PRNTSTR( enter_shadow_mode              ) // Strings[316]          //~0416I~
PRNTSTR( enter_subscript_mode           ) // Strings[317]          //~0416I~
PRNTSTR( enter_superscript_mode         ) // Strings[318]          //~0416I~
PRNTSTR( enter_upward_mode              ) // Strings[319]          //~0416I~
PRNTSTR( exit_doublewide_mode           ) // Strings[320]          //~0416I~
PRNTSTR( exit_italics_mode              ) // Strings[321]          //~0416I~
PRNTSTR( exit_leftward_mode             ) // Strings[322]          //~0416I~
PRNTSTR( exit_micro_mode                ) // Strings[323]          //~0416I~
PRNTSTR( exit_shadow_mode               ) // Strings[324]          //~0416I~
PRNTSTR( exit_subscript_mode            ) // Strings[325]          //~0416I~
PRNTSTR( exit_superscript_mode          ) // Strings[326]          //~0416I~
PRNTSTR( exit_upward_mode               ) // Strings[327]          //~0416I~
PRNTSTR( micro_column_address           ) // Strings[328]          //~0416I~
PRNTSTR( micro_down                     ) // Strings[329]          //~0416I~
PRNTSTR( micro_left                     ) // Strings[330]          //~0416I~
PRNTSTR( micro_right                    ) // Strings[331]          //~0416I~
PRNTSTR( micro_row_address              ) // Strings[332]          //~0416I~
PRNTSTR( micro_up                       ) // Strings[333]          //~0416I~
PRNTSTR( order_of_pins                  ) // Strings[334]          //~0416I~
PRNTSTR( parm_down_micro                ) // Strings[335]          //~0416I~
PRNTSTR( parm_left_micro                ) // Strings[336]          //~0416I~
PRNTSTR( parm_right_micro               ) // Strings[337]          //~0416I~
PRNTSTR( parm_up_micro                  ) // Strings[338]          //~0416I~
PRNTSTR( select_char_set                ) // Strings[339]          //~0416I~
PRNTSTR( set_bottom_margin              ) // Strings[340]          //~0416I~
PRNTSTR( set_bottom_margin_parm         ) // Strings[341]          //~0416I~
PRNTSTR( set_left_margin_parm           ) // Strings[342]          //~0416I~
PRNTSTR( set_right_margin_parm          ) // Strings[343]          //~0416I~
PRNTSTR( set_top_margin                 ) // Strings[344]          //~0416I~
PRNTSTR( set_top_margin_parm            ) // Strings[345]          //~0416I~
PRNTSTR( start_bit_image                ) // Strings[346]          //~0416I~
PRNTSTR( start_char_set_def             ) // Strings[347]          //~0416I~
PRNTSTR( stop_bit_image                 ) // Strings[348]          //~0416I~
PRNTSTR( stop_char_set_def              ) // Strings[349]          //~0416I~
PRNTSTR( subscript_characters           ) // Strings[350]          //~0416I~
PRNTSTR( superscript_characters         ) // Strings[351]          //~0416I~
PRNTSTR( these_cause_cr                 ) // Strings[352]          //~0416I~
PRNTSTR( zero_motion                    ) // Strings[353]          //~0416I~
PRNTSTR( char_set_names                 ) // Strings[354]          //~0416I~
PRNTSTR( key_mouse                      ) // Strings[355]          //~0416I~
PRNTSTR( mouse_info                     ) // Strings[356]          //~0416I~
PRNTSTR( req_mouse_pos                  ) // Strings[357]          //~0416I~
PRNTSTR( get_mouse                      ) // Strings[358]          //~0416I~
PRNTSTR( set_a_foreground               ) // Strings[359]          //~0416I~
PRNTSTR( set_a_background               ) // Strings[360]          //~0416I~
PRNTSTR( pkey_plab                      ) // Strings[361]          //~0416I~
PRNTSTR( device_type                    ) // Strings[362]          //~0416I~
PRNTSTR( code_set_init                  ) // Strings[363]          //~0416I~
PRNTSTR( set0_des_seq                   ) // Strings[364]          //~0416I~
PRNTSTR( set1_des_seq                   ) // Strings[365]          //~0416I~
PRNTSTR( set2_des_seq                   ) // Strings[366]          //~0416I~
PRNTSTR( set3_des_seq                   ) // Strings[367]          //~0416I~
PRNTSTR( set_lr_margin                  ) // Strings[368]          //~0416I~
PRNTSTR( set_tb_margin                  ) // Strings[369]          //~0416I~
PRNTSTR( bit_image_repeat               ) // Strings[370]          //~0416I~
PRNTSTR( bit_image_newline              ) // Strings[371]          //~0416I~
PRNTSTR( bit_image_carriage_return      ) // Strings[372]          //~0416I~
PRNTSTR( color_names                    ) // Strings[373]          //~0416I~
PRNTSTR( define_bit_image_region        ) // Strings[374]          //~0416I~
PRNTSTR( end_bit_image_region           ) // Strings[375]          //~0416I~
PRNTSTR( set_color_band                 ) // Strings[376]          //~0416I~
PRNTSTR( set_page_length                ) // Strings[377]          //~0416I~
PRNTSTR( display_pc_char                ) // Strings[378]          //~0416I~
PRNTSTR( enter_pc_charset_mode          ) // Strings[379]          //~0416I~
PRNTSTR( exit_pc_charset_mode           ) // Strings[380]          //~0416I~
PRNTSTR( enter_scancode_mode            ) // Strings[381]          //~0416I~
PRNTSTR( exit_scancode_mode             ) // Strings[382]          //~0416I~
PRNTSTR( pc_term_options                ) // Strings[383]          //~0416I~
PRNTSTR( scancode_escape                ) // Strings[384]          //~0416I~
PRNTSTR( alt_scancode_esc               ) // Strings[385]          //~0416I~
PRNTSTR( enter_horizontal_hl_mode       ) // Strings[386]          //~0416I~
PRNTSTR( enter_left_hl_mode             ) // Strings[387]          //~0416I~
PRNTSTR( enter_low_hl_mode              ) // Strings[388]          //~0416I~
PRNTSTR( enter_right_hl_mode            ) // Strings[389]          //~0416I~
PRNTSTR( enter_top_hl_mode              ) // Strings[390]          //~0416I~
PRNTSTR( enter_vertical_hl_mode         ) // Strings[391]          //~0416I~
#ifdef __INTERNAL_CAPS_VISIBLE                                     //~0416I~
PRNTSTR( termcap_init2                  ) // Strings[392]          //~0416I~
PRNTSTR( termcap_reset                  ) // Strings[393]          //~0416I~
PRNTSTR( linefeed_if_not_lf             ) // Strings[394]          //~0416I~
PRNTSTR( backspace_if_not_bs            ) // Strings[395]          //~0416I~
PRNTSTR( other_non_function_keys        ) // Strings[396]          //~0416I~
PRNTSTR( arrow_key_map                  ) // Strings[397]          //~0416I~
PRNTSTR( acs_ulcorner                   ) // Strings[398]          //~0416I~
PRNTSTR( acs_llcorner                   ) // Strings[399]          //~0416I~
PRNTSTR( acs_urcorner                   ) // Strings[400]          //~0416I~
PRNTSTR( acs_lrcorner                   ) // Strings[401]          //~0416I~
PRNTSTR( acs_ltee                       ) // Strings[402]          //~0416I~
PRNTSTR( acs_rtee                       ) // Strings[403]          //~0416I~
PRNTSTR( acs_btee                       ) // Strings[404]          //~0416I~
PRNTSTR( acs_ttee                       ) // Strings[405]          //~0416I~
PRNTSTR( acs_hline                      ) // Strings[406]          //~0416I~
PRNTSTR( acs_vline                      ) // Strings[407]          //~0416I~
PRNTSTR( acs_plus                       ) // Strings[408]          //~0416I~
PRNTSTR( memory_lock                    ) // Strings[409]          //~0416I~
PRNTSTR( memory_unlock                  ) // Strings[410]          //~0416I~
PRNTSTR( box_chars_1                    ) // Strings[411]          //~0416I~
#endif /* __INTERNAL_CAPS_VISIBLE */                               //~0416I~
    return 0;                                                      //~0416I~
}//prntcurses                                                      //~0416I~
//******************************************************           //~0416I~
int prntstr(char *Pname,char *Pstr)                                //~0416I~
{                                                                  //~0416I~
	char hexbuff[32],charbuff[16],*pci,*pco;                       //~0416R~
    int ii,len;                                                    //~0416I~
//********************	                                           //~0416I~
    if (!Pstr)                                                     //~0416R~
    {                                                              //~0416I~
    	hexbuff[0]=0;                                              //~0416I~
    	strcpy(charbuff,"null ptr");                               //+0416R~
    }                                                              //~0416I~
    else                                                           //~0416I~
    {                                                              //~0416I~
		len=strlen(Pstr);                                          //~0416I~
        if (len>8)                                                 //~0416R~
        {                                                          //~0416I~
            if (*Pstr==0x1b)                                       //~0416I~
				printf("%-32s:@ ( ^[%s )\n",Pname,Pstr+1);         //~0416R~
            else                                                   //~0416I~
				printf("%-32s:@ ( %s )\n",Pname,Pstr);             //~0416R~
            return 0;                                              //~0416I~
        }                                                          //~0416I~
	    pci=Pstr;                                                  //~0416I~
        pco=hexbuff;                                               //~0416R~
        for (ii=0;ii<len;ii++,pci++,pco+=2)                        //~0416R~
            sprintf(pco,"%02X",*pci);                              //~0416R~
        pci=Pstr;                                                  //~0416R~
        pco=charbuff;                                              //~0416R~
        for (ii=0;ii<len;ii++,pci++,pco++)                         //~0416R~
            if (*pci<' ' || *pci>=0x7f)                            //~0416R~
                *pco='.';                                          //~0416R~
            else                                                   //~0416R~
                *pco=*pci;                                         //~0416R~
        *pco=0;                                                    //~0416I~
    }                                                              //~0416I~
	printf("%-32s:%-16s ( %-8s )\n",Pname,hexbuff,charbuff);       //~0416I~
    return 0;                                                      //~0416I~
}//prntstr                                                         //~0416I~
