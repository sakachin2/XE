//CID://+v5meR~:                                                   //~v5meR~
//******************************************************           //~v5g6I~
// ukbdsym.h                                                       //~v5g6I~
//******************************************************           //~v5g6I~
//v5me:080229 (LNX:BUG)Ctrl+} 1b7d-->2b7d                          //~v5meI~
//v5m4:080203 find word support(key define Ctrl+Brace("{","}")     //~v5m4I~
//v5im:060722*101 kbd support(for line drawing char '^' is '=' on 101 kbd)//~v5imI~
//v5g6:050613 (XXE)xxe support                                     //~v5g6I~
//******************************************************           //~v5g6I~
//*doskeycode definition *******************************           //~v5g6I~
//******************************************************           //~v5g6I~
#define KEY_NOTUSE  0    	 //*treate special key e0xx as ext key xx//~5216R~
#define KEY_PENTRID 0xe0 	 //*treate special key e0xx as ext key xx//~5216I~

#define KEY_BS      0x0e08  //*
#define KEY_S_BS    0x0e08	//*
#define KEY_A_BS    0x0e00
#define KEY_C_BS    0x0e7f	//*

#define KEY_TAB     0x0f09  //*
#define KEY_S_TAB   0x0f00
#define KEY_A_TAB   0xa500
#define KEY_C_TAB   0x9400

#define KEY_ENTER   0x1c0d  //*
#define KEY_S_ENTER 0x1c0d	//*
#define KEY_A_ENTER 0x1c00
#define KEY_C_ENTER 0x1c0a	//*

#define KEY_SPACE   0x3920  //*                                    //~v5g6I~
#define KEY_S_SPACE 0x3920	//*                                    //~v5g6I~
#define KEY_A_SPACE 0x3920                                         //~v5g6I~
#define KEY_C_SPACE 0x3920	//*                                    //~v5g6I~
                                                                   //~v5g6I~
#define KEY_INS     0x5200
#define KEY_S_INS   0x5200
#define KEY_A_INS   0xa200
#define KEY_C_INS   0x9200

#define KEY_DEL     0x5300
#define KEY_S_DEL   0x5300
#define KEY_A_DEL   0xa300
#define KEY_C_DEL   0x9300

#define KEY_LEFT    0x4b00
#define KEY_S_LEFT  0x4b00
#define KEY_A_LEFT  0x9b00
#define KEY_C_LEFT  0x7300

#define KEY_HOME    0x4700
#define KEY_S_HOME  0x4700
#define KEY_A_HOME  0x9700
#define KEY_C_HOME  0x7700

#define KEY_END     0x4f00
#define KEY_S_END   0x4f00
#define KEY_A_END   0x9f00
#define KEY_C_END   0x7500

#define KEY_UP      0x4800
#define KEY_S_UP    0x4800
#define KEY_A_UP    0x9800
#define KEY_C_UP    0x8d00

#define KEY_DOWN    0x5000
#define KEY_S_DOWN  0x5000
#define KEY_A_DOWN  0xa000
#define KEY_C_DOWN  0x9100

#define KEY_PGUP    0x4900
#define KEY_S_PGUP  0x4900
#define KEY_A_PGUP  0x9900
#define KEY_C_PGUP  0x8400

#define KEY_PGDN    0x5100
#define KEY_S_PGDN  0x5100
#define KEY_A_PGDN  0xa100
#define KEY_C_PGDN  0x7600

#define KEY_RIGHT   0x4d00
#define KEY_S_RIGHT 0x4d00
#define KEY_A_RIGHT 0x9d00
#define KEY_C_RIGHT 0x7400

#define KEY_ESC     0x011b	//*
#define KEY_S_ESC   0x011b	//*
#define KEY_A_ESC   0x0100
//#define KEY_C_ESC   0x011b  //*                                  //~v0ioR~
#define KEY_C_ESC   KEY_NOTUSE                                     //~v0ioI~

#define KEY_F1      0x3b00
#define KEY_S_F1    0x5400
#define KEY_A_F1    0x6800
#define KEY_C_F1    0x5e00

#define KEY_F2      0x3c00
#define KEY_S_F2    0x5500
#define KEY_A_F2    0x6900
#define KEY_C_F2    0x5f00

#define KEY_F3      0x3d00
#define KEY_S_F3    0x5600
#define KEY_A_F3    0x6a00
#define KEY_C_F3    0x6000

#define KEY_F4      0x3e00
#define KEY_S_F4    0x5700
#define KEY_A_F4    0x6b00
#define KEY_C_F4    0x6100

#define KEY_F5      0x3f00
#define KEY_S_F5    0x5800
#define KEY_A_F5    0x6c00
#define KEY_C_F5    0x6200

#define KEY_F6      0x4000
#define KEY_S_F6    0x5900
#define KEY_A_F6    0x6d00
#define KEY_C_F6    0x6300

#define KEY_F7      0x4100
#define KEY_S_F7    0x5a00
#define KEY_A_F7    0x6e00
#define KEY_C_F7    0x6400

#define KEY_F8      0x4200
#define KEY_S_F8    0x5b00
#define KEY_A_F8    0x6f00
#define KEY_C_F8    0x6500

#define KEY_F9      0x4300
#define KEY_S_F9    0x5c00
#define KEY_A_F9    0x7000
#define KEY_C_F9    0x6600

#define KEY_F10     0x4400
#define KEY_S_F10   0x5d00
#define KEY_A_F10   0x7100
#define KEY_C_F10   0x6700

#define KEY_F11     0x8500
#define KEY_S_F11   0x8700
#define KEY_A_F11   0x8b00
#define KEY_C_F11   0x8900

#define KEY_F12     0x8600
#define KEY_S_F12   0x8800
#define KEY_A_F12   0x8c00
#define KEY_C_F12   0x8a00
                                                                //~5216R~
//*for graphic char input                                       //~5215I~
                                                                //~5215I~
#define KEY_P0    		KEY_NOTUSE      //10-key 0              //~5216I~
#define KEY_S_P0    	KEY_NOTUSE      //10-key 0              //~5216I~
#define KEY_A_P0    	KEY_NOTUSE          //10-key 0          //~5216I~
#define KEY_C_P0    	0x9200          //10-key 0              //~5216I~
                                                                //~5216I~
#define KEY_P1    		KEY_NOTUSE      //10-key 1              //~5216I~
#define KEY_S_P1    	KEY_NOTUSE      //10-key 1              //~5216I~
#define KEY_A_P1    	KEY_NOTUSE          //10-key 1          //~5216I~
#define KEY_C_P1    	0x7500          //10-key 1              //~5216I~
                                                                //~5216I~
#define KEY_P2    		KEY_NOTUSE      //10-key 2              //~5216I~
#define KEY_S_P2    	KEY_NOTUSE      //10-key 2              //~5216I~
#define KEY_A_P2    	KEY_NOTUSE          //10-key 2          //~5216I~
#define KEY_C_P2    	0x9100          //10-key 2              //~5216I~
                                                                //~5216I~
#define KEY_P3    		KEY_NOTUSE      //10-key 3              //~5216I~
#define KEY_S_P3    	KEY_NOTUSE      //10-key 3              //~5216I~
#define KEY_A_P3    	KEY_NOTUSE          //10-key 3          //~5216I~
#define KEY_C_P3    	0x7600          //10-key 3              //~5216I~
                                                                //~5216I~
#define KEY_P4    		KEY_NOTUSE      //10-key 4              //~5216I~
#define KEY_S_P4    	KEY_NOTUSE      //10-key 4              //~5216I~
#define KEY_A_P4    	KEY_NOTUSE          //10-key 4          //~5216I~
#define KEY_C_P4    	0x7300          //10-key 4              //~5216I~
                                                                //~5216I~
#define KEY_P5    		KEY_NOTUSE      //10-key 5              //~5216I~
#define KEY_S_P5    	KEY_NOTUSE      //10-key 5              //~5216I~
#define KEY_A_P5    	KEY_NOTUSE          //10-key 5          //~5216I~
#define KEY_C_P5    	0x8f00          //10-key 5              //~5216I~
                                                                //~5216I~
#define KEY_P6    		KEY_NOTUSE      //10-key 6              //~5216I~
#define KEY_S_P6    	KEY_NOTUSE      //10-key 6              //~5216I~
#define KEY_A_P6    	KEY_NOTUSE          //10-key 6          //~5216I~
#define KEY_C_P6    	0x7400          //10-key 6              //~5216I~
                                                                //~5216I~
#define KEY_P7   		KEY_NOTUSE      //10-key 7              //~5216I~
#define KEY_S_P7   		KEY_NOTUSE      //10-key 7              //~5216I~
#define KEY_A_P7   		KEY_NOTUSE          //10-key 7          //~5216I~
#define KEY_C_P7   		0x7700          //10-key 7              //~5216I~
                                                                //~5216I~
#define KEY_P8    		KEY_NOTUSE      //10-key 8              //~5216I~
#define KEY_S_P8    	KEY_NOTUSE      //10-key 8              //~5216I~
#define KEY_A_P8    	KEY_NOTUSE          //10-key 8          //~5216I~
#define KEY_C_P8    	0x8d00          //10-key 8              //~5216I~
                                                                //~5216I~
#define KEY_P9    		KEY_NOTUSE      //10-key 9              //~5216I~
#define KEY_S_P9    	KEY_NOTUSE      //10-key 9              //~5216I~
#define KEY_A_P9    	KEY_NOTUSE          //10-key 9          //~5216I~
#define KEY_C_P9    	0x8400          //10-key 9              //~5216I~
                                                                //~5216I~
#define KEY_PPLUS	 	KEY_NOTUSE      //10-key +              //~5216R~
#define KEY_S_PPLUS	 	KEY_NOTUSE      //10-key +              //~5216R~
#define KEY_A_PPLUS	 	0x4E00          //10-key +              //~5215I~
#define KEY_C_PPLUS	 	0x9000          //10-key +              //~5215I~
                                                                //~5215I~
#define KEY_PMINUS 		KEY_NOTUSE      //10-key -              //~5216R~
#define KEY_S_PMINUS 	KEY_NOTUSE      //10-key -              //~5216R~
#define KEY_A_PMINUS 	0x4A00          //10-key -              //~5215I~
#define KEY_C_PMINUS 	0x8e00          //10-key -              //~5215I~
                                                                //~5215I~
#define KEY_PDIVIDE_CHK 0xe02f          //10-key / treate as char//~5501R~
#define KEY_PDIVIDE 	KEY_NOTUSE      //10-key /              //~5501I~
#define KEY_S_PDIVIDE 	KEY_NOTUSE      //10-key /              //~5216R~
#define KEY_A_PDIVIDE 	0xA400          //10-key /              //~5215I~
#define KEY_C_PDIVIDE 	0x9500          //10-key /              //~5215I~
                                                                //~5215I~
#define KEY_PMULTIPLY 	KEY_NOTUSE      //10-key *              //~5216R~
#define KEY_S_PMULTIPLY KEY_NOTUSE      //10-key *              //~5216R~
#define KEY_A_PMULTIPLY 0x3700          //10-key *              //~5215I~
#define KEY_C_PMULTIPLY 0x9600          //10-key *              //~5215I~
                                                                //~5215I~
#define KEY_PPERIOD 	KEY_NOTUSE      //10-key .              //~5216R~
#define KEY_S_PPERIOD 	KEY_NOTUSE      //10-key .              //~5216R~
#define KEY_A_PPERIOD 	KEY_NOTUSE          //10-key .          //~5216R~
#define KEY_C_PPERIOD 	0x9300          //10-key .              //~5215I~
                                                                //~5215I~
#define KEY_PCOMMA  	KEY_NOTUSE      //10-key .              //~5216R~
#define KEY_S_PCOMMA   	KEY_NOTUSE      //10-key .              //~5216R~
#define KEY_A_PCOMMA   	KEY_NOTUSE          //10-key .          //~5216R~
#define KEY_C_PCOMMA  	KEY_NOTUSE          //10-key .          //~5216R~
                                                                //~5215I~
#define KEY_PENTR   0xe00d	//*                                 //~5215M~
#define KEY_S_PENTR 0xe00d	//*                                 //~5215M~
#define KEY_A_PENTR 0xa600                                      //~5215M~
#define KEY_C_PENTR 0xe00a	//*                                 //~5215M~

//*Alt+char **                                                  //~5502I~
//*1st line                                                     //~5502I~
#define KEY_A_1   		0x7800                                  //~5502R~
#define KEY_A_2   		0x7900                                  //~5502R~
#define KEY_A_3   		0x7a00                                  //~5502R~
#define KEY_A_4   		0x7b00                                  //~5502R~
#define KEY_A_5   		0x7c00                                  //~5502R~
#define KEY_A_6   		0x7d00                                  //~5502R~
#define KEY_A_7   		0x7e00                                  //~5502R~
#define KEY_A_8   		0x7f00                                  //~5502R~
#define KEY_A_9   		0x8000                                  //~5502R~
#define KEY_A_0   		0x8100                                  //~5502R~
#define KEY_A_MINUS   	0x8200                                  //~5502R~
#define KEY_A_HAT   	0x8300                                  //~5502R~
#define KEY_A_EQUAL   	0x8300    //on 101 kbd                     //~v5imI~
#define KEY_A_YEN   	KEY_NOTUSE                              //~5506I~
//*2nd line                                                     //~5502I~
#define KEY_A_q   		0x1000                                  //~5502R~
#define KEY_A_w   		0x1100                                  //~5502R~
#define KEY_A_e   		0x1200                                  //~5502R~
#define KEY_A_r   		0x1300                                  //~5502R~
#define KEY_A_t   		0x1400                                  //~5502R~
#define KEY_A_y   		0x1500                                  //~5502R~
#define KEY_A_u   		0x1600                                  //~5502R~
#define KEY_A_i   		0x1700                                  //~5502R~
#define KEY_A_o   		0x1800                                  //~5502R~
#define KEY_A_p   		0x1900                                  //~5502R~
#define KEY_A_ACCNT		0x1a00                                  //~5502R~
#define KEY_A_LMP 		0x1b00                                  //~5502R~
#define KEY_A_LBRACE	0x1b00   //A+S+[=A+{                       //+v5meI~
                                                                //~5502I~
//*3rd line                                                     //~5502I~
#define KEY_A_a   		0x1e00                                  //~5502R~
#define KEY_A_s   		0x1f00                                  //~5502R~
#define KEY_A_d   		0x2000                                  //~5502R~
#define KEY_A_f   		0x2100                                  //~5502R~
#define KEY_A_g   		0x2200                                  //~5502R~
#define KEY_A_h   		0x2300                                  //~5502R~
#define KEY_A_j   		0x2400                                  //~5502R~
#define KEY_A_k   		0x2500                                  //~5502R~
#define KEY_A_l   		0x2600                                  //~5502R~
#define KEY_A_SEMICOLON 0x2700                                  //~5502R~
#define KEY_A_COLON 	0x2800                                  //~5502R~
#define KEY_A_RMP 		0x2b00                                  //~5502R~
#define KEY_A_RBRACE	0x2b00    //A+S+]=A+}                      //+v5meI~
                                                                //~5502I~
//*4th line                                                     //~5502I~
#define KEY_A_z   		0x2c00                                  //~5502R~
#define KEY_A_x   		0x2d00                                  //~5502R~
#define KEY_A_c   		0x2e00                                  //~5502R~
#define KEY_A_v   		0x2f00                                  //~5502R~
#define KEY_A_b   		0x3000                                  //~5502R~
#define KEY_A_n   		0x3100                                  //~5502R~
#define KEY_A_m   		0x3200                                  //~5502R~
#define KEY_A_COMMA 	0x3300                                  //~5502R~
#define KEY_A_PERIOD	0x3400                                  //~5502R~
#define KEY_A_SLASH 	0x3500                                  //~5502R~
#define KEY_A_BSLASH	KEY_NOTUSE                              //~5506I~
                                                                //~5502I~
//*Ctl+char **                                                  //~5506I~
//*1st line                                                     //~5506I~
#define KEY_C_1   		KEY_NOTUSE                              //~5506R~
#define KEY_C_2   		0x0300                                  //~5506I~
#define KEY_C_3   		KEY_NOTUSE                              //~5506R~
#define KEY_C_4   		KEY_NOTUSE                              //~5506R~
#define KEY_C_5   		KEY_NOTUSE                              //~5506R~
#define KEY_C_6   		0x071e                                  //~5506I~
#define KEY_C_7   		KEY_NOTUSE                              //~5506R~
#define KEY_C_8   		KEY_NOTUSE                              //~5506R~
#define KEY_C_9   		KEY_NOTUSE                              //~5506R~
#define KEY_C_0   		KEY_NOTUSE                              //~5506R~
#define KEY_C_MINUS   	0x0c1f                                  //~5506I~
#define KEY_C_HAT   	KEY_NOTUSE                              //~5506R~
#define KEY_C_EQUAL   	KEY_NOTUSE                                 //~v5imI~
#define KEY_C_YEN   	0x7d1c                                  //~5506I~
//*2nd line                                                     //~5506I~
#define KEY_C_q   		0x1011                                  //~5506I~
#define KEY_C_w   		0x1117                                  //~5506I~
#define KEY_C_e   		0x1205                                  //~5506I~
#define KEY_C_r   		0x1312                                  //~5506I~
#define KEY_C_t   		0x1414                                  //~5506I~
#define KEY_C_y   		0x1519                                  //~5506I~
#define KEY_C_u   		0x1615                                  //~5506I~
#define KEY_C_i   		0x1709                                  //~5506I~
#define KEY_C_o   		0x180f                                  //~5506I~
#define KEY_C_p   		0x1910                                  //~5506I~
#define KEY_C_ACCNT		KEY_NOTUSE                              //~5506R~
#define KEY_C_LMP 		0x1b1b                                  //~5506I~
#define KEY_C_LBRACE	0x1b7b     //left brace "{" scan=1a    S+C+@ on 107jp, S+C+[ on 101//~v5m4I~
//#define KEY_C_RBRACE	0x1b7d     //left brace "}" scan=1b    S+C+[ on 107jp, S+C+] on 101//~v5meR~
                                                                //~5506I~
//*3rd line                                                     //~5506I~
#define KEY_C_a   		0x1e01                                  //~5506I~
#define KEY_C_s   		0x1f13                                  //~5506I~
#define KEY_C_d   		0x2004                                  //~5506I~
#define KEY_C_f   		0x2106                                  //~5506I~
#define KEY_C_g   		0x2207                                  //~5506I~
#define KEY_C_h   		0x2308                                  //~5506I~
#define KEY_C_j   		0x240a                                  //~5506I~
#define KEY_C_k   		0x250b                                  //~5506I~
#define KEY_C_l   		0x260c                                  //~5506I~
#define KEY_C_SEMICOLON KEY_NOTUSE                              //~5506R~
#define KEY_C_COLON 	KEY_NOTUSE                              //~5506R~
#define KEY_C_RMP 		0x2b1d                                  //~5506I~
#define KEY_C_RBRACE	0x2b7d     //left brace "}" scan=1b    S+C+[ on 107jp, S+C+] on 101//~v5meI~
                                                                //~5506I~
//*4th line                                                     //~5506I~
#define KEY_C_z   		0x2c1a                                  //~5506I~
#define KEY_C_x   		0x2d18                                  //~5506I~
#define KEY_C_c   		0x2e03                                  //~5506I~
#define KEY_C_v   		0x2f16                                  //~5506I~
#define KEY_C_b   		0x3002                                  //~5506I~
#define KEY_C_n   		0x310e                                  //~5506I~
#define KEY_C_m   		0x320d                                  //~5506I~
#define KEY_C_COMMA 	KEY_NOTUSE                              //~5506R~
#define KEY_C_PERIOD	KEY_NOTUSE                              //~5506R~
#define KEY_C_SLASH 	KEY_NOTUSE                              //~5506R~
#define KEY_C_BSLASH	0x731c                                  //~5506I~
                                                                //~5506I~
                                                                //~5502I~
