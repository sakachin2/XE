//*CID://+vbh1R~:                             update#=  769;       //~vbh1R~
//*************************************************************    //~v72BI~
//*xetso2.c                                                        //~v72BI~
//**interface to xe3270                                            //~v72BI~
//*************************************************************    //~v72BI~
//vbh1:180129 (Ubuntu 17.10:gcc7.2) compiler warning,sprintf may overflow//~vbh1I~
//vb72:161212 (Win10) missing error.h , use winerror.h             //~vb72I~
//vb30:160411 (LNX)Compiler warning                                //~vb30I~
//vb2F:160229 W32 64 compiler warning                              //~vb2FI~
//vaz8:150109 C4244 except ULPTR and ULONG                         //~vaz8I~
//vafk:120624 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  use ULPTR(unsigned __int64/ULONG)//~vafkI~
//vafc:120607 C4701 warning(used uninitialized variable) by VC6    //~vafcI~
//vaf9:120607 (WTL)Bug found by vs2010exp(used uninitialized variable),avoid warning C4701//~vaf9I~
//va90:110520 ANDROID porting                                      //~va90I~
//va04:090606 expand cmdbuff to include edit cmd for the file with _max_path//~va04I~
//v79p:080824 (BUG)numstd=n(NONUM) cause NUMON condition           //~v79pI~
//v79a:080808 DBCS other than Japanese                             //~v79aI~
//v799:080803 add NFS option to =6.xx cmd                          //~v799I~
//v798:080803 (BUG)after PgUp key,TSO full screen mode panel draw is qureous//~v798I~
//v9@8:080717 3270:fs mode del excluded line                       //~v9@8I~
//v9@6:080717 3270:TSO cmd initial 3270/TSO mode option            //~v9@6I~
//v9@5:080717 3270:TSO FS mode;draw update line only for performance//~v9@5I~
//v9@4:080717 3270:TSO dbcs cursor(2byte reverse)                  //~v9@4I~
//v9@2:080716 3270:3270 TSO mode hotkey assign change A+x->A+q     //~v9@2I~
//v8@Z:080715 3270:TSO keyboard mode by A+q                        //~v8@ZI~
//v8@Y:080711 3270:clear 3270 kbd mode at logoff                   //~v8@YI~
//v793:080715 /Nrr option to reset RCT-newline                     //~v793I~
//v8@X:080711*3270:A+r:newline,A+c:reset                           //~v8@XI~
//v8@W:080711 3270:abridge cmd by Alt+a                            //~v8@WI~
//v8@V:080711 3270:protect screen update when FULLscreen mode      //~v8@VI~
//v8@T:080710 3270:(BUG)GTK charkey(ex ">") scancode matches to PFKey scan code//~v8@TI~
//v8@R:080710 3270:no action allowed when 3270kbd mode             //~v8@RI~
//v8@Q:080710 3270:keey only 1 screen data when FS mode RSH        //~v8@QI~
//v78Z:080708 (3270)sw key assignment by hot key                   //~v78ZI~
//v8@M:080707 3270:convert to uppercase for =6.TSO panel           //~v8@MI~
//v8@K:080701 3270:Action cmd support without action prefix such as ">Home" on TSO remote shell//~v8@KI~
//v8@J:080629 3270:>> as action cmd abridgement                    //~v8@HI~
//v8@H:080629 3270:display cursor position for rsh mode            //~v8@HI~
//v8@F:080629 3270:NUMSTD consideration when SJIS=>EBC translation(SO/SI insert case)//~v8@FI~
//v8@B:080627 3270:submit cmd support by TSO SUBMIT cmd            //~v8@BI~
//v8@s:080621 3270:dbcs conversion support                         //~v8@sI~
//            pass recfm and lrecl,convert at xe3270 the use binary mode transfer//~v8@sI~
//v8@i:080619 TSO:"=6.TSOxx" support                               //~v8@iI~
//v8@h:080619 TSO:rsh logon display initial screen                 //~v8@hI~
//v8@g:080618 subcmd alias Action for tso cmd                      //~v8@gI~
//v72B:061205 3270:like rsh,use =6 panel as TSO terminal screen "tso "tostid TSO"/Exit//~v72BI~
//*************************************************************    //~v72BI~
#include <time.h>                                                  //~v72BI~
#include <stdio.h>                                                 //~v72BI~
#include <stddef.h>                                                //~v72BI~
#include <stdlib.h>                                                //~v72BI~
#include <ctype.h>                                                 //~v72BI~
#include <string.h>                                                //~v72BI~
#ifdef W32                                                         //~v72BI~
#include <io.h>                                                    //~v72BI~
  #ifdef WIN10                                                     //~vb72I~
	#include <winerror.h>                                          //~vb72I~
  #else                                                            //~vb72I~
#include <error.h>                                                 //~v72BI~
  #endif                                                           //~vb72I~
#include <errno.h>                                                 //~v72BI~
#endif                                                             //~v72BI~
#ifdef ARM                                                         //~va90I~
	#include <pthread.h>                                           //~va90I~
#endif                                                             //~va90I~
                                                                   //~v72BI~
//*******************************************************          //~v72BI~
#include <ulib.h>                                                  //~v72BI~
#include <ualloc.h>                                                //~v72BI~
#include <uerr.h>                                                  //~v72BI~
#include <uque.h>                                                  //~v72BI~
#include <ufile.h>                                                 //~v72BI~
#include <ufile3.h>                                                //~v8@BI~
#include <ustring.h>                                               //~v72BI~
#include <uedit.h>                                                 //~v72BI~
#include <uftp.h>                                                  //~v72BI~
#include <utrace.h>                                                //~v72BI~
#include <uparse.h>                                                //~v72BI~
#include <u3270.h>                                                 //~v72BI~
#include <u32702.h>                                                //~v8@BI~
#include <ukbd.h>                                                  //~v78ZI~
#include <ukbdsym.h>                                               //~v78ZI~
                                                                   //~v72BI~
#include "xe.h"                                                    //~v72BI~
#include "xescr.h"                                                 //~v72BI~
#include "xecsr.h"                                                 //~v8@RI~
#include "xefile.h"                                                //~v72BI~
#include "xefile13.h"                                              //~v8@QI~
#include "xefile2.h"                                               //~v8@gI~
#include "xefile6.h"                                               //~v9@5I~
#include "xefunc.h"                                                //~v72BI~
#include "xeftp.h"                                                 //~v72BI~
#include "xesub.h"                                                 //~v72BI~
#include "xedir.h"                                                 //~v72BI~
#include "xe3270.h"                                                //~v72BI~
#include "xetso.h"                                                 //~v72BI~
#include "xeerr.h"                                                 //~v72BI~
#include "xedcmd3.h"                                               //~v72BI~
#include "xefcmd3.h"                                               //~v72BI~
#include "xefcmd6.h"                                               //~v8@FI~
#include "xechar2.h"                                               //~v8@HI~
#include "xefunct.h"                                               //~v8@ZI~
#include "xelcmd.h"                                                //~v9@6I~
#include "xelcmd2.h"                                               //~v9@6I~
                                                                   //~v72BI~
#ifdef FTPSUPP                                                     //~v72BI~
                                                                   //~v72BI~
//**************************************************************** //~v72BI~
#define SWITCH3270TSO "TSO"                                        //~v8@ZI~
static KBD3270 Skbd3270[]={ //normal/shift/alt/ctl                 //~v78ZR~
   {{KEY_PENTR   ,0          ,0          ,0         },{0             ,0            ,0             ,0           },0},//dummy entry for Rctl key//~v8@ZR~
#define KBD3270_RCTLINDEX  1     //changes by rctl option          //~v78ZR~
   {{KEY_ENTER   ,0          ,0          ,0         },{0             ,0            ,0             ,0           },0},//1c0d//~v8@ZR~
#define KBD3270_ENTER      2     //changs by rctl option           //~v78ZI~
// {{KEY_ESC     ,KEY_S_ESC  ,0          ,0         },{"Attn"        ,"SysReq"     ,0             ,0           },0},//011b pcom default//~v8@ZR~
   {{0           ,KEY_S_ESC  ,KEY_A_ESC  ,0         },{0             ,"Attn"       ,"SysReq"      ,0           },0},//011b//~v8@ZR~
   {{KEY_TAB     ,KEY_S_TAB  ,0          ,0         },{"Tab"         ,"BackTab"    ,0             ,0           },0},//0f09/0f00//~v8@ZR~
   {{KEY_BS      ,0          ,0          ,0         },{"Erase"       ,0            ,0             ,0           },0},//0e08;//~v8@ZR~
   {{0           ,0          ,KEY_A_a    ,0         },{0             ,0            ,"Action"      ,0           },K3270F_NOTSO|K3270F_ACTION},////~v8@ZR~
   {{0           ,0          ,KEY_A_c    ,0         },{0             ,0            ,"Reset"       ,0           },0},////~v9@2R~
   {{0           ,0          ,KEY_A_r    ,0         },{0             ,0            ,"NewLine"     ,0           },0},////~v9@2R~
// {{0           ,0          ,KEY_A_s    ,0         },{0             ,0            ,"Sysreq"      ,0           },0},////~v8@ZR~
   {{0           ,0          ,KEY_A_q    ,0         },{0             ,0            ,SWITCH3270TSO ,0           },K3270F_SWTSO},////~v9@2R~
   {{KEY_INS     ,0          ,KEY_A_INS  ,0         },{"ToggleInsert",0            ,"PA(1)"       ,0           },0},//~v8@ZR~
   {{KEY_DEL     ,0          ,0          ,KEY_C_DEL },{"Delete"      ,0            ,0             ,"DeleteWord"},0},//~v8@ZR~
   {{KEY_HOME    ,0          ,KEY_A_HOME ,0         },{"Home"        ,0            ,"PA(2)"       ,0           },0},//~v8@ZR~
   {{KEY_END     ,KEY_S_END  ,KEY_A_END  ,0         },{"EraseEOF"    ,"DeleteField","EraseInput"  ,0           },0},//~v8@ZR~
// {{0           ,KEY_S_LEFT ,KEY_A_LEFT ,0         },{0             ,"Left"       ,"PreviousWord",0           },0},//~v8@ZR~
// {{0           ,KEY_S_RIGHT,KEY_A_RIGHT,0         },{0             ,"Right"      ,"NextWord"    ,0           },0},//~v8@ZR~
// {{0           ,KEY_S_UP   ,0          ,0         },{0             ,"Up"         ,0             ,0           },0},//~v8@ZR~
// {{0           ,KEY_S_DOWN ,0          ,0         },{0             ,"Down"       ,0             ,0           },0},//~v8@ZR~
   {{KEY_LEFT    ,KEY_S_LEFT ,KEY_A_LEFT ,0         },{"Left"        ,"Left"       ,"PreviousWord",0           },0},//~v8@ZR~
   {{KEY_RIGHT   ,KEY_S_RIGHT,KEY_A_RIGHT,0         },{"Right"       ,"Right"      ,"NextWord"    ,0           },0},//~v8@ZR~
   {{KEY_UP      ,KEY_S_UP   ,0          ,0         },{"Up"          ,"Up"         ,0             ,0           },0},//~v8@ZR~
   {{KEY_DOWN    ,KEY_S_DOWN ,0          ,0         },{"Down"        ,"Down"       ,0             ,0           },0},//~v8@ZR~
   {{0           ,0          ,KEY_A_PGUP ,0         },{0             ,0            ,"PA(3)"       ,0           },0},//~v8@ZR~
   {{KEY_F1      ,KEY_S_F1   ,0          ,0         },{"PF(1)"       ,"PF(13)"     ,0             ,0           },0},//~v8@ZR~
   {{KEY_F2      ,KEY_S_F2   ,0          ,0         },{"PF(2)"       ,"PF(14)"     ,0             ,0           },0},//~v8@ZR~
   {{KEY_F3      ,KEY_S_F3   ,0          ,0         },{"PF(3)"       ,"PF(15)"     ,0             ,0           },0},//~v8@ZR~
   {{KEY_F4      ,KEY_S_F4   ,0          ,0         },{"PF(4)"       ,"PF(16)"     ,0             ,0           },0},//~v8@ZR~
   {{KEY_F5      ,KEY_S_F5   ,0          ,0         },{"PF(5)"       ,"PF(17)"     ,0             ,0           },0},//~v8@ZR~
   {{KEY_F6      ,KEY_S_F6   ,0          ,0         },{"PF(6)"       ,"PF(18)"     ,0             ,0           },0},//~v8@ZR~
   {{KEY_F7      ,KEY_S_F7   ,0          ,0         },{"PF(7)"       ,"PF(19)"     ,0             ,0           },0},//~v8@ZR~
   {{KEY_F8      ,KEY_S_F8   ,0          ,0         },{"PF(8)"       ,"PF(20)"     ,0             ,0           },0},//~v8@ZR~
   {{KEY_F9      ,KEY_S_F9   ,0          ,0         },{"PF(9)"       ,"PF(21)"     ,0             ,0           },0},//~v8@ZR~
   {{KEY_F10     ,KEY_S_F10  ,0          ,0         },{"PF(10)"      ,"PF(22)"     ,0             ,0           },0},//~v8@ZR~
   {{KEY_F11     ,KEY_S_F11  ,0          ,0         },{"PF(11)"      ,"PF(23)"     ,0             ,0           },0},//~v8@ZR~
   {{KEY_F12     ,KEY_S_F12  ,0          ,0         },{"PF(12)"      ,"PF(24)"     ,0             ,0           },0}//~v8@ZR~
    };                                                             //~v78ZR~
#define KBD3270ENTNO (sizeof(Skbd3270)/sizeof(KBD3270))            //~v78ZI~
static UCHAR Skeymap3270[256];	//indexed by scan code             //~v78ZI~
                                                                   //~v8@ZI~
static FUNCTBL *Spft3270hotkey;                                    //~v8@ZI~
//**************************************************************** //~v78ZI~
static char *Sactionname[]={                                       //~v8@KR~
                    "Attn",       "Att",       //attention key     //~v8@KR~
                    "BackSpace",  "BS",        //move cursor left (or send ASCII BS)//~v8@KR~
                    "BackTab",    "BT",        //tab to start of previous input field//~v8@KR~
                    "CircumNot",  "Not",       //input "^" in NVT mode, or "￢" in 3270 mode//~v8@KR~
                    "Clear",      "",          //clear screen      //~v8@QR~
 //                 "Connect",          //(host) connect to host   //~v8@KI~
 //                 "CursorSelect",     //Cursor Select AID        //~v8@KI~
                    "DeleteField","DF",        //delete the entire field//~v8@KR~
                    "DeleteWord", "DW",        //delete the current or previous word//~v78ZR~
                    "Delete",     "DC",        //delete character under cursor (or send ASCII DEL)//~v8@KR~
 //                 "Disconnect",       //disconnect from host     //~v8@KI~
                    "Down",       ">D",        //move cursor down  //~v8@KR~
 //                 "Dup",              //duplicate field          //~v8@KI~
                    "Enter",      "",          //Enter AID (or send ASCII CR)//~v8@RR~
                    "EraseEOF",   "EEOF",       //erase to end of current field//~v8@KR~
                    "EraseInput", "EINP",       // erase all input fields//~v8@KR~
                    "Erase",      "ERA",       //erase previous character (or send ASCII BS)//~v8@KR~
 //                 "Execute",          //(cmd) execute a command in a shell//~v8@KI~
                    "FieldEnd",   "FEND",       //move cursor to end of field//~v8@KR~
 //                 "FieldMark",        //mark field               //~v8@KI~
                    "HexString",  "Hex",        //(hex_digits) insert control-character string//~v8@KR~
                    "Home",       ">H",        //move cursor to first input field//~v8@KR~
                    "Insert",     "",          //set insert mode   //~v8@KR~
 //                 "Interrupt",        //send TELNET IP to host   //~v8@KI~
                    "Key",        "",          //(keysym) insert key keysym//~v8@KR~
 //                 "Key",              //(0xxx) insert key with ASCII code xx//~v8@KI~
                    "Left",      ">L",         //move cursor left  //~v8@KR~
 //                 "Left2",            //move cursor left 2 positions//~v8@KI~
 //                 "MonoCase",         //toggle uppercase-only mode//~v8@KI~
                    "MoveCursor","MVC",       //(row, col) move cursor to (row,col)//~v8@TR~
                    "Newline",   "NL",        //move cursor to first field on next line (or send ASCII LF)//~v8@KR~
                    "NextWord",  "NW",          //move cursor to next word//~v78ZR~
                    "PA(",       "",          //(n) Program Attention AID (n from 1 to 3)//~v8@KR~
                    "PA",        "",          //(n) Program Attention AID (n from 1 to 3)//~v8@KR~
                    "PF(",       "",          //(n) Program Function AID (n from 1 to 24)//~v8@KR~
                    "PF",        "",          //(n) Program Function AID (n from 1 to 24)//~v8@KR~
                    "PreviousWord","PW",      //move cursor to previous word//~v78ZR~
 //                 "Quit",             //exit s3270               //~v8@KI~
 //                 "Redraw",           //redraw window            //~v8@KI~
                    "Reset",     "Res",       //reset locked keyboard//~v8@KR~
                    "Right",     ">R",        //move cursor right  //~v8@KR~
 //                 "Right2",           //move cursor right 2 positions//~v8@KI~
 //                 "Script",           //(command[,arg...]) run a script//~v8@KI~
                    "String",    "Str",       //(string) insert string (simple macro facility)//~v8@KR~
                    "SysReq",    "Sys",       //System Request AID //~v8@KR~
                    "Tab",       "",          //move cursor to next input field//~v8@KR~
 //                 "Toggle",           //(option[,set|clear]) toggle an option//~v8@KI~
                    "ToggleInsert","Ins",     //toggle insert mode //~v8@KR~
 //                 "ToggleReverse",    //toggle reverse-input mode//~v8@KI~
                    "Transfer",  "FTP",       //(option=value...) file transfer//~v8@KR~
                    "Up",        ">U",        //move cursor up     //~v8@KR~
                    0                                              //~v8@KI~
                  };                                               //~v8@KI~
//*****                                                            //~v9@5I~
static int Snocmdlog;       //no need to cmdlog                    //~v9@5I~
//**************************************************************** //~v72BI~
int xetso2isvalidactionname(int Popt,char *Pcmd,char *Prepcmd);    //~v8@KR~
int xetso2escstring(int Popt,char *Poptstr,char *Pcmd,char *Pout); //~v8@ZR~
#define XTO2O_STRING   0x01                                        //~v8@ZI~
int xetso2escstring2(int Popt,char *Pinp,int Plen,char *Pout);     //~v8@ZI~
int tso3270tsokbd(int Popt,PUCLIENTWE Ppcw);                       //~v9@5I~
//**************************************************************** //~v72BI~
//**************************************************************** //~v72BI~
// set/reset =6 panel to TSO terminal mode by logon/logoff cmd     //~v72BR~
//*rc   :0                                                         //~v72BI~
//**************************************************************** //~v72BI~
int xetsotsocmdlogon(int Popt,PUCLIENTWE Ppcw,PUFTPHOST Ppuftph)   //~v72BR~
{                                                                  //~v72BI~
    PUFTPHOST puftpho;                                             //~v72BI~
    PUFILEC  pfc;                                                  //~v72BI~
    PUFILEH  pfh;                                                  //~v72BI~
//  char logtext[256];                                             //~v72BI~//+vbh1R~
    char logtext[4096];                                            //~vbh1I~
    int rc;                                                        //~v8@hI~
//*********************************                                //~v72BI~
	pfc=Ppcw->UCWpfc;                                              //~v72BI~
	pfh=pfc->UFCpfh;                                               //~v72BI~
	puftpho=pfh->UFHpuftph;	//old                                  //~v72BR~
	if (Popt & XETSOCMDO_LOGOFF)                                   //~v72BI~
    {                                                              //~v72BI~
    	if (puftpho)                                               //~v72BI~
        {                                                          //~v72BI~
            if (puftpho==Ppuftph)                                  //~v72BI~
            {                                                      //~v72BI~
                pfh->UFHpuftph=0;   //old                          //~v72BR~
                UCBITOFF(pfh->UFHflag6,UFHF6RLOGIN);               //~v72BI~
   				UCBITOFF(pfh->UFHflag8,UFHF8CAPSON); //caps off    //~v8@MR~
   				UCBITOFF(pfh->UFHflag9,UFHF9CAPSONCMD); //caps off //~v8@MI~
        		UCBITOFF(pfh->UFHflag8,UFHF8TSOFSMODE);            //~v8@YI~
  				if (UCBITCHK(Ppcw->UCWflag3,UCWF33270KBD))         //~v8@YR~
                {                                                  //~v8@YI~
  					UCBITOFF(Ppcw->UCWflag3,UCWF33270KBD);  //     //~v8@YI~
    				UCBITON(Ppcw->UCWflag,UCWFWAKEUP|UCWFDRAW);    //~v8@YI~
    			}                                                  //~v8@YI~
                sprintf(logtext,"Exit TSO mode of %s/%s.",         //~v72BR~
                        puftpho->UFTPHipad,puftpho->UFTPHuser);    //~v72BI~
            }                                                      //~v72BI~
            else                                                   //~v72BI~
                sprintf(logtext,"Continue TSO mode of %s/%s(logoff of %s/%s).",//~v72BR~
                        puftpho->UFTPHipad,puftpho->UFTPHuser,Ppuftph->UFTPHipad,Ppuftph->UFTPHuser);//~v72BI~
            dcmdrloginlog(Ppcw,pfh,logtext);                       //~v72BI~
        }                                                          //~v72BI~
        return 0;                                                  //~v72BI~
    }//reset req                                                   //~v72BI~
//logon req                                                        //~v72BI~
	if (puftpho==Ppuftph)   //already TSO mode of the host         //~v72BI~
        sprintf(logtext,"Continue TSO mode of %s/%s.",             //~v72BR~
                            Ppuftph->UFTPHipad,Ppuftph->UFTPHuser);//~v72BI~
    else                                                           //~v72BI~
        if (puftpho)                                               //~v72BR~
            sprintf(logtext,"Now TSO mode of %s/%s(switched from %s/%s).",//~v72BR~
                            Ppuftph->UFTPHipad,Ppuftph->UFTPHuser,puftpho->UFTPHipad,puftpho->UFTPHuser);//~v72BR~
        else                                                       //~v72BI~
            sprintf(logtext,"Now TSO mode of %s/%s.",              //~v72BR~
                            Ppuftph->UFTPHipad,Ppuftph->UFTPHuser);//~v72BI~
    UCBITON(pfh->UFHflag6,UFHF6RLOGIN);                            //~v72BI~
   	UCBITON(pfh->UFHflag8,UFHF8CAPSON); //caps off                 //~v8@MR~
   	UCBITON(pfh->UFHflag9,UFHF9CAPSONCMD); //caps off              //~v8@MI~
	if (Popt & XETSOCMDO_LOGONFS)	//fullscreen mode              //~v72BI~
    {                                                              //~v8@hI~
        UCBITON(pfh->UFHflag8,UFHF8TSOFSMODE);                     //~v72BR~
        strcat(logtext,"(FullScreen mode)");                       //~v9@8R~
    }                                                              //~v8@hI~
    else                                                           //~v72BI~
    {                                                              //~v8@hI~
        UCBITOFF(pfh->UFHflag8,UFHF8TSOFSMODE);                    //~v72BR~
        strcat(logtext,"(Not FullScreen mode)");                   //~v9@8R~
    }                                                              //~v8@hI~
    pfh->UFHpuftph=Ppuftph;  //new                                 //~v72BR~
	dcmdrloginlog(Ppcw,pfh,logtext);                               //~v72BI~
//  Ppcw->UCWparm="Snap";                                          //~v9@8R~
    Ppcw->UCWparm=XE3270_SUBCMD_SNAP;                              //~v9@8R~
    Snocmdlog=1;       //no need to cmdlog                         //~v9@5I~
    rc=xetsotsocmd(Ppcw);                                          //~v8@hI~
    Snocmdlog=0;                                                   //~v9@5I~
    if (!rc)                                                       //~v8@hI~
        uerrmsg("%s",0,                                            //~v8@iR~
            	logtext);                                          //~v8@iR~
	if (Popt & (XETSOCMDO_LOGONFS3270|XETSOCMDO_LOGONFS3270TSO))	//fullscreen mode//~v9@5R~
    {                                                              //~v9@5I~
		if (func_tsohotkey(Ppcw))                                  //~v9@5I~
        	return 4;                                              //~v9@5I~
		if (Popt & XETSOCMDO_LOGONFS3270TSO)	//fullscreen mode  //~v9@5R~
			tso3270tsokbd(0,Ppcw);	//TSO kbd on                   //~v9@5I~
    }                                                              //~v9@5I~
//  return 0;                                                      //~v8@hR~
    return rc;                                                     //~v8@hI~
}//xetsotsocmdlogon                                                //~v72BR~
//**************************************************************** //~v72BI~
// process input when =6 screen is TSO mode                        //~v72BI~
//*rc   :0                                                         //~v72BI~
//**************************************************************** //~v72BI~
int xetsotsocmd(PUCLIENTWE Ppcw)                                   //~v72BI~
{                                                                  //~v72BI~
    PUFTPHOST puftph;                                              //~v72BR~
    PUFILEC  pfc;                                                  //~v72BI~
    PUFILEH  pfh;                                                  //~v72BI~
    PULINEH  plh=NULL,plhn;                                             //~v9@6R~//~vafcR~
    PULINEH  plho,plhe=NULL;                                            //~v9@5R~//~vafcR~
    PSCRDATA  phdr;                                                //~v72BI~
    int rc,opt,datalen,len,reslen=0;                                 //~v72BR~//~vafcR~
    char cmd[MAX_CMDSZ],*pc,*cmdstr,*pc2;                          //~v72BR~
    char cmdrep[MAX_CMDSZ];                                        //~v8@KI~
    char optstr[4];                                                //~v72BI~
//  int csrx,csry,row=0;                                           //~v8@HM~//~vafcR~
    int csrx=0,csry=0,row=0;                                       //~vafcI~
    int errsw,opt2;                                                //~v8@ZR~
    int fsmode=0,opt3=0,opt4;                                      //~v9@8R~
//*********************************                                //~v8@HM~
    opt=0;                                                         //~v72BI~
	pfc=Ppcw->UCWpfc;                                              //~v72BI~
	pfh=pfc->UFCpfh;                                               //~v72BI~
	puftph=pfh->UFHpuftph;	//old                                  //~v72BR~
    if (!UFTPHISTSO(puftph))                                       //~v72BI~
    	return 4;                                                  //~v72BI~
	UPCTRREQ(pfh);	//end of a shot                                //~v8@QI~
    if (UCBITCHK(pfh->UFHflag8,UFHF8TSOFSMODE))                    //~v72BI~
    {                                                              //~v8@QI~
    	fsmode=1;                                                  //~v9@5I~
    	opt=XE3270RSHOPT_FSMODE;                                   //~v72BI~
//      filefreealldataplh(pfh);   //free all plh and undo data    //~v9@5R~
//  	UCBITON(pfh->UFHflag6,UFHF6NOUNDO);  //skip save undo data for performance//~v9@5R~
  		if (UCBITCHK(Ppcw->UCWflag3,UCWF33270KBD))  //             //~v9@8I~
			opt4=FSUO_CLEARLCMD;         //clear lcmd              //~v9@8I~
        else                                                       //~v9@8I~
        	opt4=0;                                                //~v9@8I~
        fileresetundoable(opt4,pfh);   //free all undo data        //~v9@8R~
    }                                                              //~v8@QI~
    sprintf(optstr,"%d",opt);                                      //~v72BI~
    cmdstr=Ppcw->UCWparm;                                          //~v72BM~
  if (!Snocmdlog)       //no need to cmdlog                        //~v9@5I~
	dcmdrloginlog(Ppcw,pfh,cmdstr);	//cmd line on =6 scr with time stamp//~v72BI~
	pc=cmd+u3270sethostuser(puftph,XE3270_SUBCMD_RSH,cmd);         //~v72BR~
  if (Ppcw->UCWkeytype==UCWKT3270KBD)                              //~v78ZI~
    sprintf(pc," \"%s %s %s\"",optstr,XE3270_SUBCMD_ACTION,cmdstr);//~v78ZI~
  else                                                             //~v8@RI~
  if (UCBITCHK(Ppcw->UCWflag3,UCWF33270KBD))  //                   //~v8@RR~
  {                                                                //~v8@RI~
//  if (*cmdstr=='\"')                                             //~v8@ZR~
//  	sprintf(pc," \"%s %s",optstr,cmdstr+1);                    //~v8@ZR~
//  else                                                           //~v8@ZR~
//  	sprintf(pc," \"%s %s\"",optstr,cmdstr);                    //~v8@ZR~
	opt2=((UCBITCHK(Ppcw->UCWflag3,UCWF33270KBD2)!=0)?0:XTO2O_STRING);//~v8@ZR~
    xetso2escstring(opt2,optstr,cmdstr,pc);                        //~v8@ZR~
  }                                                                //~v8@RI~
  else                                                             //~v78ZI~
  if  (rc=xetso2isvalidactionname(0,cmdstr,cmdrep),rc)             //~v8@RR~
  {                                                                //~v8@KI~
  	if (rc==2)	//alias                                            //~v8@KI~
    	sprintf(pc," \"%s %s %s\"",optstr,XE3270_SUBCMD_ACTION,cmdrep);//~v8@KI~
    else                                                           //~v8@KI~
    	sprintf(pc," \"%s %s %s\"",optstr,XE3270_SUBCMD_ACTION,cmdstr);//~v8@KI~
  }                                                                //~v8@KI~
  else                                                             //~v8@KI~
  if (*cmdstr==XE3270_SUBCMD_ACTION2)                              //~v8@HI~
    sprintf(pc," \"%s %s %s\"",optstr,XE3270_SUBCMD_ACTION,cmdstr+1);//~v8@HR~
  else                                                             //~v8@HI~
  {                                                                //~v8@KI~
//   if (*cmdstr=='\"')                                            //~v8@ZR~
//    sprintf(pc," \"%s %s",optstr,cmdstr+1);                      //~v8@ZR~
//   else                                                          //~v8@ZR~
//    sprintf(pc," \"%s %s\"",optstr,cmdstr);                      //~v8@ZR~
   if (!stricmp(cmdstr,XE3270_SUBCMD_SNAP))                        //~v9@8I~
    sprintf(pc," \"%s %s\"",optstr,cmdstr);                        //~v9@8I~
   else                                                            //~v9@8I~
   {                                                               //~v9@8I~
	opt2=((UCBITCHK(Ppcw->UCWflag3,UCWF33270KBD2)!=0)?0:XTO2O_STRING);//~v8@ZR~
    xetso2escstring(opt2,optstr,cmdstr,pc);                        //~v8@ZR~
   }                                                               //~v9@8I~
  }                                                                //~v8@KI~
    opt=U3CRO_TSOMODE;                                             //~v72BI~
//  rc=u3270cmdrequest(U3CRO_UERRMSGIFERR,cmd,(void**)(ULONG)(&phdr),&datalen);//~v72BI~//~vafkR~
    rc=u3270cmdrequest(U3CRO_UERRMSGIFERR,cmd,(void**)(ULPTR)(&phdr),&datalen);//~vafkI~
    if (fsmode)                                                    //~v9@5I~
    {                                                              //~v9@5I~
      plh=UGETQNEXT(UGETQTOP(&pfh->UFHlineque));  // cmdlog line   //~v9@5I~
	  plhe=UGETQEND(&pfh->UFHlineque);				//endline      //~v9@5R~
      if (UGETQCTR(&pfh->UFHlineque)==3)                           //~v9@5I~
          opt3=XETSOUL_ISRT;                                       //~v9@5I~
      else                                                         //~v9@5I~
          plh=UGETQNEXT(plh);                                      //~v9@5I~
    }                                                              //~v9@5I~
    if (phdr)                                                      //~v72BI~
    {                                                              //~v72BI~
      if (!fsmode)                                                 //~v9@5I~
	    plh=UGETQPREV(UGETQEND(&pfh->UFHlineque));	//timestamp line//~v72BI~
        reslen=phdr->SCRlen;                                       //~v72BR~
        csrx=phdr->SCRcurcol;                                      //~v8@HR~
        csry=phdr->SCRcurrow;                                      //~v8@HR~
        pc=phdr->SCRdata;                                          //~v72BI~
        errsw=0;                                                   //~v8@KI~
    }                                                              //~v8@KI~
    else                                                           //~v8@KI~
    {                                                              //~v8@KI~
        pc=ugeterrmsg2();                                          //~v8@KI~
        if (pc)                                                    //~v8@KI~
        {                                                          //~v8@KI~
          if (!fsmode)                                             //~v9@5I~
	    	plh=UGETQPREV(UGETQEND(&pfh->UFHlineque));	//timestamp line//~v8@KI~
//          reslen=strlen(pc);                                     //~v8@KI~//~vb30R~
            reslen=(int)strlen(pc);                                //~vb30I~
        	csrx=0;                                                //~v8@KR~
        	csry=-1;    //no csr display                           //~v8@KR~
        }                                                          //~v8@KI~
        errsw=1;                                                   //~v8@KI~
    }                                                              //~v8@KI~
    if (pc)                                                        //~v8@KI~
    {                                                              //~v8@KI~
        for (;reslen>0;)                                           //~v72BI~
        {                                                          //~v72BI~
          if (errsw)                                               //~v8@KR~
//      	pc2=memchr(pc,';',reslen);                             //~v8@KI~//~vb30R~
        	pc2=memchr(pc,';',(size_t)reslen);                     //~vb30I~
          else                                                     //~v8@KI~
//      	pc2=memchr(pc,'\n',reslen);                            //~v72BR~//~vb30R~
        	pc2=memchr(pc,'\n',(size_t)reslen);                    //~vb30I~
            if (!pc2)                                              //~v72BI~
//          	break;                                             //~v8@KR~
            len=(int)strlen(pc);                                   //~v8@KI~
            else                                                   //~v8@KI~
//          len=(ULONG)pc2-(ULONG)pc;                              //~v72BI~//~vafkR~
//          len=(ULPTR)pc2-(ULPTR)pc;                              //~vafkI~//~vb2FR~
            len=PTRDIFF(pc2,pc);                                   //~vb2FI~
         if (fsmode)                                               //~v9@5I~
         {                                                         //~v9@5I~
         	if (plh->ULHtype!=ULHTDATA)                            //~v9@8R~
            {                                                      //~v9@8R~
            	plhn=UGETQNEXT(plh);                               //~v9@8R~
				xetsoupdateplh(XETSOUL_DELX,Ppcw,plh,0,0);         //~v9@8R~
                plh=plhn;                                          //~v9@8R~
            }                                                      //~v9@8R~
			rc=xetsoupdateplh(opt3,Ppcw,plh,pc,len);               //~v9@5R~
            if (rc)                                                //~v9@5I~
            	break;                                             //~v9@5I~
            if (opt3 & XETSOUL_ISRT)  //insrt                      //~v9@5I~
	            plh=UGETQNEXT(plh);                                //~v9@5I~
            else                                                   //~v9@5I~
    			if (UCBITCHK(plh->ULHflag,ULHFCURCAP))	//current paste block line//~v9@5I~
                {                                                  //~v9@5I~
	    			UCBITOFF(plh->ULHflag,ULHFCURCAP);	//reset reverse//~v9@5I~
    				UCBITON(plh->ULHflag,ULHFDRAW); //redraw for clear hilite//~v9@5I~
                }                                                  //~v9@5I~
         }                                                         //~v9@5I~
         else                                                      //~v9@5I~
         {                                                         //~v9@5I~
            rc=fcmdisrtline(Ppcw,plh,pc,len);                      //~v72BI~
            if (rc)                                                //~v72BI~
            	break;                                             //~v72BI~
            plh=UGETQNEXT(plh);                                    //~v72BI~
         }                                                         //~v9@5I~
//		    if (UCBITCHK(pfh->UFHflag8,UFHF8TSOFSMODE))	//fullscreen mode//~v9@5R~
            if (fsmode)                                            //~v9@5I~
            {                                                      //~v8@HI~
                UCBITON(plh->ULHflag4,ULHF4PROTLINE);              //~v8@VI~
            	if (row==csry)                                     //~v8@HI~
                {                                                  //~v8@QI~
                    plh->ULHupundoctr=pfh->UFHupundoctr; //parm to charcaprev//~v8@QI~
                    plh->ULHupctr=pfh->UFHupctr; //file23 chek logic for reverse//~v8@QI~
                  if (plh->ULHdbcs && *(plh->ULHdbcs+csrx)==DBCS1STCHAR)//~v9@4I~
					charcaprev(plh,csrx,2);//csr postion reverse   //~v9@4I~
                  else                                             //~v9@4I~
                  if (plh->ULHdbcs && *(plh->ULHdbcs+csrx)==DBCS2NDCHAR && csrx>0)//~v9@4I~
					charcaprev(plh,csrx-1,2);//csr postion reverse //~v9@4I~
                  else                                             //~v9@4I~
					charcaprev(plh,csrx,1);//csr postion reverse   //~v8@HI~
    				UCBITON(plh->ULHflag,ULHFDRAW); //redraw for clear hilite//~v9@5I~
                }                                                  //~v8@QI~
                if (!(opt3 & XETSOUL_ISRT))  //rep                 //~v9@5I~
                {                                                  //~v9@5I~
	            	plho=plh;                                      //~v9@5I~
			        plh=UGETQNEXT(plh);                            //~v9@5I~
                	if (plh==plhe)	//eof                          //~v9@5R~
                    {                                              //~v9@5I~
                    	opt3|=XETSOUL_ISRT;                        //~v9@5R~
                        plh=plho;	//isrt after this plh          //~v9@5I~
                    }                                              //~v9@5I~
                }                                                  //~v9@5I~
            	row++;                                             //~v8@HI~
            }                                                      //~v8@HI~
            len++;	//\n                                           //~v72BI~
            reslen-=len;                                           //~v72BI~
            pc+=len;                                               //~v72BR~
        }                                                          //~v72BI~
      if (phdr)                                                    //~v8@KR~
        ufree(phdr);                                               //~v72BI~
        if (fsmode)                                                //~v9@5I~
            if (!(opt3&XETSOUL_ISRT))                              //~v9@5R~
	        	if (plh!=plhe)  //rep                              //~v9@5R~
					xetsoupdateplh(0,Ppcw,plh,0,0);   //del residual all//~v9@5R~
                                                                   //~v9@5I~
    }                                                              //~v72BI~
    pfc->UFCcsrplh=0;	//ignore plh csrline setting               //~v8@gI~
    filesetcsr(Ppcw,0,0,0); //data field,fldtop,reset csr setting  //~v8@gI~
	if (UCBITCHK(pfh->UFHflag8,UFHF8TSOFSMODE))	//fullscreen mode  //~v8@QI~
    {                                                              //~v8@ZI~
    	UCBITOFF(pfh->UFHflag6,UFHF6NOUNDO);  //allow undo for screen update//~v8@QI~
//  	pfc->UFCcurtop=UGETQTOP(&pfh->UFHlineque);                 //~v799R~
    }                                                              //~v8@ZI~
	UPCTRREQ(pfh);	//end of a shot                                //~v8@QI~
    return rc;                                                     //~v72BR~
}//xetsotsocmd                                                     //~v72BI~
//***********************************************                  //~v9@5R~
//*!xetsoupdateline  ******************************                //~v9@5R~
//*update line                                                     //~v9@5R~
//*plh:hdr line when cmdlog                                        //~v9@5R~
//*return:rc                                                       //~v9@5R~
//***********************************************                  //~v9@5R~
int xetsoupdateplh(int Popt,PUCLIENTWE Ppcw,PULINEH Pplh,char *Pdata,int Plen)//~v9@5R~
{                                                                  //~v9@5R~
	PULINEH plh,plhn;                                              //~v9@5R~
    int   delsw;                                                   //~v9@5R~
//****************************                                     //~v9@5R~
	if (Popt & XETSOUL_DELX)  //insert line                        //~v9@8R~
    {                                                              //~v9@8R~
		lcmddelxline(Ppcw,Pplh);                                   //~v9@8R~
		UDEQ(UQUE_ENT,0,Pplh);	//dequed                           //~v9@8I~
		filefreeplh(Pplh,1);                                       //~v9@8I~
        return 0;                                                  //~v9@8R~
    }                                                              //~v9@8R~
	if (!Pdata)	//delete req                                       //~v9@5I~
    {                                                              //~v9@5I~
        delsw=0;                                                   //~v9@5I~
    	for (plh=Pplh;plh;plh=plhn)                                //~v9@5R~
        {                                                          //~v9@5I~
    		plhn=UGETQNEXT(plh);                                   //~v9@5R~
            if (!plhn)                                             //~v9@5R~
                break;                                             //~v9@5I~
			UDEQ(UQUE_ENT,0,plh);	//dequed                       //~v9@8R~
			filefreeplh(plh,1);                                    //~v9@5I~
            delsw=1;                                               //~v9@5I~
        }                                                          //~v9@5I~
        if (delsw)                                                 //~v9@5I~
    		UCBITON(Ppcw->UCWflag,UCWFDRAW);                       //~v9@5I~
        return 0;                                                  //~v9@5I~
    }                                                              //~v9@5I~
	if (Popt & XETSOUL_ISRT)  //insert line                        //~v9@5I~
    {                                                              //~v9@5I~
        return fcmdisrtline(Ppcw,Pplh,Pdata,Plen);                 //~v9@5R~
    }                                                              //~v9@5I~
	if (Popt & XETSOUL_CMDLOG)  //from xedcmd2                     //~v9@5I~
    {                                                              //~v9@5I~
    	plh=UGETQNEXT(Pplh);                                       //~v9@5I~
		if (!UCBITCHK(plh->ULHflag3,ULHF3CMDECHO))	//not 1st tile //~v9@5I~
			return fcmdisrtline(Ppcw,Pplh,Pdata,Plen);  //isrt     //~v9@5I~
    }                                                              //~v9@5I~
    else                                                           //~v9@5I~
    	plh=Pplh;        //line to be updated                      //~v9@5I~
    if (UCBITCHK(plh->ULHflag2,ULHF2EXCLUDED)) //redraw for clear hilite//~v9@6I~
    {                                                              //~v9@6I~
    	UCBITON(plh->ULHflag,ULHFDRAW); //redraw for clear hilite  //~v9@6I~
		UCBITOFF(plh->ULHflag2,ULHF2EXCLUDED); //redraw for clear hilite//~v9@6I~
    }                                                              //~v9@6I~
    if (plh->ULHlen==Plen)                                         //~v9@5I~
    {                                                              //~v9@5I~
    	if (!memcmp(plh->ULHdata,Pdata,(UINT)Plen))	//data not changed//~v9@5I~
    		return 0;		//no need to draw                      //~v9@5I~
    }                                                              //~v9@5I~
    UCBITON(plh->ULHflag,ULHFDRAW); //redraw for clear hilite      //~v9@5I~
	UCBITOFF(plh->ULHflag3,ULHF3CMDECHO);	//no cmdlog line       //~v9@5I~
	if (plh->ULHbufflen<Plen)                                      //~v9@5R~
		if (fileexpandbuff(plh,Plen)==UALLOC_FAILED)		//expand buff//~v9@5R~
            return UALLOC_FAILED;                                  //~v9@5I~
	UCBITOFF(Pplh->ULHflag2,ULHF2TABCHKED|ULHF2TABFOUND);          //~v9@5I~
    memcpy(plh->ULHdata,Pdata,(UINT)Plen);                         //~v9@5I~
    plh->ULHlen=Plen;                                              //~v9@5I~
    if (plh->ULHdbcs)                                              //~v9@5I~
    {                                                              //~v9@8I~
    	filesetdbcstbl(plh->ULHdata,plh->ULHdbcs,Plen,0);//no chk tab//~v9@5I~
    }                                                              //~v9@8I~
    if (filechktabdbcs(plh)==UALLOC_FAILED)                        //~v9@5I~
        return UALLOC_FAILED;                                      //~v9@5I~
    return 0;                                                      //~v9@5R~
}//xetsoupdateplh                                                  //~v9@5R~
//**************************************************************** //~v8@iI~
// cmd change from =6.TSOxx to =6;tso TSOxx logon FS               //~v8@iI~
//*rc   :0:dest is TSO,4:dest err,-1:ignored                       //~v8@iI~
//**************************************************************** //~v8@iI~
int xetsorsh6(int Popt,char *Poutcmd,char *Pincmd)                 //~v8@iI~
{                                                                  //~v8@iI~
	int rc=-1;                                                     //~v8@iI~
    char outcmd[FTP_HOSTNAMELEN+64],*pc,*pco;                      //~v8@iR~
//  char hostnm[FTP_HOSTNAMELEN+1];                                //~v799R~
//  char hostnm[MAXCOLUMN+1];                                      //~v799I~//~va04R~
    char hostnm[MAXPARMSZ+1];                                      //~va04I~
	PUFTPHOST puftph;                                              //~v8@iI~
    char *pc2,*fsopt="FS";                                         //~v9@6R~
    char *pc3,*pc4=0;                                              //~v799R~
//**********************                                           //~v8@iR~
	pco=outcmd;                                                    //~v8@iI~
    *pco++=*Pincmd;                                                //~v8@iI~
    *pco++=';';                                                    //~v8@iI~
    UstrncpyZ(hostnm,Pincmd+2,sizeof(hostnm));                     //~v8@iR~
    if (pc=strpbrk(hostnm," ;"),pc)                                //~v8@iR~
    {                                                              //~v9@6R~
        if (*pc==' ')                                              //~v9@6R~
        {                                                          //~v9@6R~
        	pc2=pc+strspn(pc," ");                                 //~v9@6R~
    		if (pc4=strpbrk(pc2,";"),pc4)	//concatcmd            //~v799R~
            	pc4++;                                             //~v799I~
    		if (pc3=strpbrk(pc2," ;"),pc3)                         //~v799I~
            	*pc3=0;                                            //~v799I~
            if (!stricmp(pc2,"FS3"))                               //~v9@6R~
            	fsopt=pc2;                                         //~v9@6R~
            else                                                   //~v9@6R~
            if (!stricmp(pc2,"FST"))                               //~v9@6R~
            	fsopt=pc2;                                         //~v9@6R~
            else                                                   //~v799I~
            if (!stricmp(pc2,"NFS"))                               //~v799I~
            	fsopt="";                                          //~v799I~
            else                                                   //~v9@6I~
                return errinvalid(pc2);                            //~v9@6I~
        }                                                          //~v9@6R~
        else                                                       //~v799I~
            pc4=pc+1;   //next of ";"                              //~v799R~
    	*pc=0; //hostname end pos                                  //~v799R~
    }                                                              //~v9@6R~
	puftph=uftpnodesrch(hostnm);                                   //~v8@iR~
    if (puftph)                                                    //~v8@iR~
    {                                                              //~v8@iI~
    	if (puftph->UFTPHflag & UFTPHFTSO)    //host is tso        //~v8@iI~
//  		sprintf(pco,"TSO %s: logon FS",hostnm);                //~v9@6R~
    		sprintf(pco,"TSO %s: logon %s",hostnm,fsopt);          //~v9@6R~
        else                                                       //~v8@iI~
    		sprintf(pco,"RSH %s:",hostnm);                         //~v8@iI~
        strcpy(Poutcmd,outcmd);                                    //~v8@iI~
//  	if (pc=strpbrk(Pincmd," ;"),pc)                            //~v799R~
//          strcat(Poutcmd,pc);                                    //~v799R~
	  	if (pc4)                                                   //~v799I~
            sprintf(Poutcmd+strlen(Poutcmd),";%s",pc4);            //~v799R~
        rc=0;                                                      //~v8@iI~
    }                                                              //~v8@iI~
    else                                                           //~v8@iI~
    {                                                              //~v8@iI~
    	uerrmsg("dest:%s is not defined on xehost",0,              //~v8@iR~
        			hostnm);                                       //~v8@iR~
        rc=4;                                                      //~v8@iI~
    }                                                              //~v8@iI~
    return rc;                                                     //~v8@iI~
}//xetsorsh6                                                       //~v8@iI~
//**************************************************************** //~v8@sR~
// set uftph request parm(recfm and lrecl)                         //~v8@sR~
//*rc   :0                                                         //~v8@sR~
//**************************************************************** //~v8@sR~
int xetsosetftpparm(int Popt,PUFTPHOST Ppuftph,/*PUTSOFTPPARM*/ void *Pptsop,void *Pparm)//~v8@sR~
{                                                                  //~v8@sR~
	PUTSOFTPPARM ptsop;                                            //~v8@sI~
    FILEFINDBUF3 *pfstat3,ffb3;                                    //~v8@sI~
    PUFILEH pfh;                                                   //~v8@sI~
    UCHAR   *pfpath;                                               //~v8@sI~
    int rc;                                                        //~v8@sI~
    int numstd=0;                                                  //~v8@FI~
    UFILEH wkfh;                                                   //~v8@FI~
    long  profileflag;                                             //~v8@FI~
//**********************                                           //~v8@sR~
	ptsop=Pptsop;                                                  //~v8@sI~
    memset(ptsop,0,sizeof(UTSOFTPPARM));                           //~v8@sR~
    if (!(Popt & XETSOFTPO_DBCSCONV))	//test 1 by 1              //~v8@sR~
    	return 0;                                                  //~v8@sI~
//  if (!(Ppuftph->UFTPHflag & (UFTPHFCP930|UFTPHFCP939)))	//japanese dbcs//~v79aR~
//  if (!(Ppuftph->UFTPHflag & (UFTPHFCP930|UFTPHFCP939|UFTPHFCPCJK)))	//japanese dbcs//~v79aR~
//  	return 0;                                                  //~v79aR~
    pfstat3=(FILEFINDBUF3*)Pparm;                                  //~v8@sI~
    if (Popt & XETSOFTPO_FPATH)   //by fullpath name               //~v8@sI~
    {                                                              //~v8@sM~
    	if (Popt & XETSOFTPO_CHKPROF)   //by fullpath name         //~v8@FI~
        {                                                          //~v8@FI~
        	memset(&wkfh,0,UFILEHSZ);                              //~v8@FI~
			UCBITON(wkfh.UFHflag7,UFHF7TSO);	//parm to fcmdprofgetfnm//~v8@FR~
			strcpy(wkfh.UFHfilename,Pparm);                        //~v8@FI~
			if (!fcmdprofgetprofile(0,&wkfh,&profileflag))         //~v8@FI~
//        		numstd=(profileflag & FPURO_NUMSTD);               //~v79pR~
          		numstd=((profileflag & FPURO_NUMSTD) && (wkfh.UFHspfpos));//~v79pR~
        }                                                          //~v8@FI~
    	pfpath=(UCHAR*)Pparm;                                      //~v8@sI~
//      if (rc=u3270fstat(Ppuftph,pfpath,&ffb3),rc)	//chk before download because IND$FILE ABDEND 013 then wait infinite//~v8@sR~//~vb30R~
        if (rc=(int)u3270fstat(Ppuftph,pfpath,&ffb3),rc)	//chk before download because IND$FILE ABDEND 013 then wait infinite//~vb30I~
        	return 8;                                              //~v8@sI~
		Popt|=XETSOFTPO_FFB3;   //from fstat3                      //~v8@sI~
        pfstat3=&ffb3;                                             //~v8@sR~
    }                                                              //~v8@sM~
    if (Popt & XETSOFTPO_FFB3)   //from fstat3                     //~v8@sR~
    {                                                              //~v8@sR~
        ptsop->UTSOFPattr=pfstat3->attrFile;    //fix/variable etc //~v8@sR~
        ptsop->UTSOFPsrcattr=pfstat3->srcattr; //lrecl+blksz       //~v8@sR~
    }                                                              //~v8@sR~
    else            //pfh                                          //~v8@sI~
    {                                                              //~v8@sR~
    	pfh=(PUFILEH)Pparm;                                        //~v8@sI~
        ptsop->UTSOFPattr=pfh->UFHattr;    //fix/variable etc      //~v8@sR~
        ptsop->UTSOFPsrcattr=pfh->UFHsrcattr; //lrecl+blksz        //~v8@sR~
    	if (Popt & XETSOFTPO_CHKPROF)   //by fullpath name         //~v8@FI~
        {                                                          //~v8@FI~
        	memset(&wkfh,0,UFILEHSZ);                              //~v8@FM~
			UCBITON(wkfh.UFHflag7,UFHF7TSO);	//parm to fcmdprofgetfnm//~v8@FM~
			strcpy(wkfh.UFHfilename,pfh->UFHfilename);             //~v8@FM~
			if (!fcmdprofgetprofile(0,&wkfh,&profileflag))         //~v8@FM~
//        		numstd=(profileflag & FPURO_NUMSTD);               //~v79pR~
          		numstd=((profileflag & FPURO_NUMSTD) && (wkfh.UFHspfpos));//~v79pR~
        }                                                          //~v8@FI~
        else                                                       //~v8@FI~
        if (UCBITCHK(pfh->UFHflag2,UFHF2SPFNUMOK))                 //~v8@FI~
            numstd=1;                                              //~v8@FI~
    }                                                              //~v8@sR~
  if ((Ppuftph->UFTPHflag & (UFTPHFCP930|UFTPHFCP939|UFTPHFCPCJK)))	//japanese dbcs//~v79aR~
    ptsop->UTSOFPflag|=UTSOFTPF_DBCSCONV;                          //~v8@sI~
    if (numstd)                                                    //~v8@FI~
	    ptsop->UTSOFPflag|=UTSOFTPF_NUMSTD;                        //~v8@FI~
    return 0;                                                      //~v8@sR~
}//xetsosetftpparm                                                 //~v8@sR~
//**************************************************************** //~v8@BI~
// set uftph request parm(recfm and lrecl)                         //~v8@BI~
//*rc   :0                                                         //~v8@BI~
//**************************************************************** //~v8@BI~
int xetsosubmit(int Popt,PUFTPHOST Ppuftph,char *Premotefpath,char *Plocalfnm)//~v8@BR~
{                                                                  //~v8@BI~
    int rc;                                                        //~v8@BR~
    char cmd[MAX_CMDSZ],*pc,*pfnm;                                 //~v8@BR~
    char submitwk[_MAX_PATH];                                      //~v8@BR~
    char submitwkfpath[_MAX_PATH];                                 //~v8@BR~
//**********************                                           //~v8@BI~
    if (Plocalfnm)                                                 //~v8@BR~
    {                                                              //~v8@BI~
		if (xetsoquery(0,Ppuftph,XE3270_QUERY_SUBMITWORK,submitwk))//~v8@BR~
            return 4;                                              //~v8@BI~
		u3270fullpath(Ppuftph,submitwkfpath,submitwk,sizeof(submitwkfpath));//~v8@BI~
    	if (xetsoxcopy(XETSOXCOPY_SETBYTGTF,0,Ppuftph,Plocalfnm,submitwkfpath,DCPY_EXISTING,FILE_NORMAL,0/*uftpparm*/))//~v8@BR~
            return 4;                                              //~v8@BI~
        pfnm=submitwkfpath;                                        //~v8@BI~
    }                                                              //~v8@BI~
    else                                                           //~v8@BI~
    	pfnm=Premotefpath;                                         //~v8@BI~
    pfnm+=Ppuftph->UFTPHhostnmlen+1;                               //~v8@BI~
	pc=cmd+u3270sethostuser(Ppuftph,XE3270_SUBCMD_CMD,cmd);        //~v8@BM~
    sprintf(pc," \"SUB %s\"",pfnm);                                //~v8@BR~
    rc=u3270cmdrequest(U3CRO_UERRMSG,cmd,0,0);                     //~v8@BI~
    if (rc==U3CR_RC_DONE)   //rc for success msg display           //~v8@BI~
        rc=0;                                                      //~v8@BI~
    return rc;                                                     //~v8@BR~
}//xetsosubmit                                                     //~v8@BI~
//**************************************************************** //~v8@BI~
// query xe3270.cfg parm                                           //~v8@BI~
//**************************************************************** //~v8@BI~
int xetsoquery(int Popt,PUFTPHOST Ppuftph,char *Pparm,char *Pvalue)//~v8@BI~
{                                                                  //~v8@BI~
    int rc;                                                        //~v8@BR~
    char cmd[MAX_CMDSZ],*pc,*pmsg;                                 //~v8@BR~
//**********************                                           //~v8@BI~
	pc=cmd+u3270sethostuser(Ppuftph,XE3270_SUBCMD_QUERY,cmd);      //~v8@BI~
    sprintf(pc," %s",Pparm);                                       //~v8@BI~
    rc=u3270cmdrequest(U3CRO_UERRMSG,cmd,0,0);                     //~v8@BI~
    if (rc)                                                        //~v8@BI~
    	return rc;                                                 //~v8@BI~
    pmsg=ugeterrmsg2();		//reponsemsg                           //~v8@BI~
    if (!pmsg)                                                     //~v8@BI~
    	return 4;                                                  //~v8@BI~
    if (memicmp(pmsg,Pparm,strlen(Pparm)))                         //~v8@BR~
    	return 4;			//not found                            //~v8@BI~
    strcpy(Pvalue,pmsg+strlen(Pparm)+1);                           //~v8@BI~
    return 0;                                                      //~v8@BI~
}//xetsoquery                                                      //~v8@BI~
//**************************************************************** //~v8@KI~
// check action name                                               //~v8@KI~
//* rc:1 found,0:not valid action,2:alias replaced                 //~v8@KR~
//**************************************************************** //~v8@KI~
int xetso2isvalidactionname(int Popt,char *Pcmd,char *Prepcmd)     //~v8@KR~
{                                                                  //~v8@KI~
    char *pc,**ppaction,*paction,*palias;                          //~v8@KR~
    int len,lena;                                                  //~v8@KR~
//**********************                                           //~v8@KI~
	pc=Pcmd+strspn(Pcmd," ");                                      //~v8@KI~
    if (*pc=='\"')                                                 //~v8@KI~
    	return 0;		//as String cmd                            //~v8@KI~
    for (ppaction=Sactionname;paction=*ppaction,paction;ppaction++)//~v8@KR~
    {                                                              //~v8@KI~
//  	len=strlen(paction);                                       //~v8@KI~//~vb30R~
    	len=(int)strlen(paction);                                  //~vb30I~
    	if (!memicmp(pc,paction,(UINT)len))                        //~v8@KR~
        	if (!*(pc+len) || *(pc+len)==' '||*(paction+len-1)=='(')//~v8@KR~
            	return 1;                                          //~v8@KI~
//*alias                                                           //~v8@KI~
        ppaction++;                                                //~v8@KI~
		palias=*ppaction;                                          //~v8@KR~
//  	lena=strlen(palias);                                       //~v8@KI~//~vb30R~
    	lena=(int)strlen(palias);                                  //~vb30I~
    	if (*palias && !memicmp(pc,palias,(UINT)lena))             //~v8@KI~
        	if (!*(pc+lena) || *(pc+lena)==' ')                    //~v8@KI~
            {                                                      //~v8@KI~
                sprintf(Prepcmd,"%s %s",paction,pc+lena);          //~v8@KR~
            	return 2;                                          //~v8@KI~
            }                                                      //~v8@KI~
    }                                                              //~v8@KI~
    return 0;                                                      //~v8@KI~
}//xetso2isvalidactionname                                         //~v8@KI~
//**************************************************************** //~v8@MI~
// back to \n from \N by CAPON function                            //~v8@MI~
//**************************************************************** //~v8@MI~
int xetso2escstring(int Popt,char *Poptstr,char *Pcmd,char *Pout)  //~v8@ZR~
{                                                                  //~v8@MI~
    UCHAR *pc,*pcmd;                                               //~v8@ZR~
    int ii,swesc=0;                                                //~v8@MR~
    char cmdwk[MAX_CMDSZ];                                         //~v8@ZI~
//**********************                                           //~v8@MI~
	if (Popt & XTO2O_STRING)	//string enter(not TSO mode)       //~v8@ZI~
    {                                                              //~v8@ZI~
//  	xetso2escstring2(Popt,Pcmd,strlen(Pcmd),cmdwk);            //~v8@ZR~//~vb30R~
    	xetso2escstring2(Popt,Pcmd,(int)strlen(Pcmd),cmdwk);       //~vb30I~
        pcmd=cmdwk;                                                //~v8@ZI~
    }                                                              //~v8@ZI~
    else                                                           //~v8@ZI~
    	pcmd=Pcmd;                                                 //~v8@ZI~
	for (pc=pcmd,ii=(int)strlen(pcmd);ii>0;pc++,ii--)              //~v8@ZR~
    {                                                              //~v8@MI~
    	if (*pc=='\\')                                             //~v8@MI~
        {                                                          //~v8@MI~
        	swesc=!swesc;                                          //~v8@MI~
            continue;                                              //~v8@MI~
        }                                                          //~v8@MI~
        if (!swesc)                                                //~v8@MI~
        	continue;                                              //~v8@MI~
        swesc=0;                                                   //~v8@ZI~
        if (*pc>='A')                                              //~v8@MI~
            *pc=(UCHAR)tolower(*pc);                               //~v8@MI~
    }                                                              //~v8@MI~
    if (*pcmd=='\"')                                               //~v8@ZI~
    	sprintf(Pout," \"%s String \"%s\"  \"",Poptstr,pcmd);      //~v8@ZR~
    else                                                           //~v8@ZI~
    	sprintf(Pout," \"%s String %s\"",Poptstr,pcmd);            //~v8@ZR~
    return 0;                                                      //~v8@MI~
}//xetso2escstr                                                    //~v8@MI~
//**************************************************************** //~v8@ZI~
// edit char input(enclose quote) or replace " to ""               //~v8@ZI~
//**************************************************************** //~v8@ZI~
int xetso2escstring2(int Popt,char *Pinp,int Plen,char *Pout)      //~v8@ZI~
{                                                                  //~v8@ZI~
    UCHAR *pci,*pco;                                               //~v8@ZR~
    int ii;                                                        //~v8@ZI~
//**********************                                           //~v8@ZI~
	if (Plen==1) //SBCS                                            //~v8@ZI~
    {                                                              //~v8@ZI~
    	switch(*Pinp)                                              //~v8@ZI~
        {                                                          //~v8@ZI~
        case ' ':                                                  //~v8@ZI~
        	strcpy(Pout,"\" \"");       //" "                      //~v8@ZI~
            break;                                                 //~v8@ZI~
        case '\\':                                                 //~v8@ZI~
        	strcpy(Pout,"\"\\\\\"");     //"\\"                    //~v8@ZI~
        	break;                                                 //~v8@ZI~
        case '\"':                                                 //~v8@ZI~
        	strcpy(Pout,"\\\"\"");     // \""                      //~v8@ZR~
        	break;                                                 //~v8@ZI~
        default:                                                   //~v8@ZI~
        	sprintf(Pout,"%c",*Pinp);                              //~v8@ZI~
        }                                                          //~v8@ZI~
    }                                                              //~v8@ZI~
    else 	//DBCS                                                 //~v8@ZI~
    {                                                              //~v8@ZI~
    	pco=Pout;                                                  //~v8@ZI~
        *pco++='\"';                                               //~v8@ZI~
		for (ii=0,pci=Pinp;ii<Plen;ii++,pci++)                     //~v8@ZR~
        {                                                          //~v8@ZI~
            switch(*pci)                                           //~v8@ZI~
            {                                                      //~v8@ZI~
            case '\\':                                             //~v8@ZI~
                *pco++='\\';                                       //~v8@ZI~
				if (!(Popt & XTO2O_STRING))	//string enter(not TSO mode),single  for \n etc//~v8@ZI~
                	*pco++='\\';                                   //~v8@ZR~
                break;                                             //~v8@ZI~
	        case '\"':                                             //~v8@ZI~
    	    	*pco++='\\';                                       //~v8@ZI~
    	    	*pco++='\"';                                       //~v8@ZI~
    	    	*pco++='\"';                                       //~v8@ZI~
        		break;                                             //~v8@ZI~
            default:                                               //~v8@ZI~
               *pco++=*pci;                                        //~v8@ZI~
            }                                                      //~v8@ZI~
        }                                                          //~v8@ZI~
        *pco++='\"';                                               //~v8@ZI~
        *pco++=0;                                                  //~v8@ZI~
    }                                                              //~v8@ZI~
    return 0;                                                      //~v8@ZI~
}//xetso2escstr2                                                   //~v8@ZI~
//**************************************************************** //~v78ZI~
// back to \n from \N by CAPON function                            //~v78ZI~
//**************************************************************** //~v78ZI~
int func_tsohotkey(PUCLIENTWE Ppcw)                                //~v78ZI~
{                                                                  //~v78ZI~
    PUFTPHOST puftph;                                              //~v78ZI~
    PUFILEC  pfc;                                                  //~v78ZI~
    PUFILEH  pfh;                                                  //~v78ZI~
//*********************************                                //~v78ZI~
	pfc=Ppcw->UCWpfc;                                              //~v78ZI~
	pfh=pfc->UFCpfh;                                               //~v78ZI~
	puftph=pfh->UFHpuftph;	//old                                  //~v78ZI~
    if (!UCBITCHK(pfh->UFHflag6,UFHF6RLOGIN)                       //~v78ZR~
    ||  !UFTPHISTSO(puftph))                                       //~v78ZR~
    {	                                                           //~v78ZI~
    	uerrmsg("Not logoned to remote TSO",0);                    //~v78ZR~
        return 4;                                                  //~v78ZI~
    }                                                              //~v78ZI~
	if (!UCBITCHK(pfh->UFHflag8,UFHF8TSOFSMODE))	//fullscreen mode//~v78ZR~
    {                                                              //~v78ZI~
    	uerrmsg("Not FullScreen mode TSO RSH",0);                  //~v78ZI~
        return 4;                                                  //~v78ZI~
    }                                                              //~v78ZI~
    if (UCBITCHK(Ppcw->UCWflag3,UCWF33270KBD))  //                 //~v78ZI~
    {                                                              //~v78ZI~
    	UCBITOFF(Ppcw->UCWflag3,UCWF33270KBD);                     //~v78ZI~
    	uerrmsg("reset 3270 keyboard",                             //~v9@8R~
				"3270キーボード 解除");                            //~v9@8R~
    }                                                              //~v78ZI~
    else                                                           //~v78ZI~
    {                                                              //~v78ZI~
    	UCBITON(Ppcw->UCWflag3,UCWF33270KBD);                      //~v78ZI~
      if (UCBITCHK(Ppcw->UCWflag3,UCWF33270KBD2))	//previously TSO mode//~v9@5I~
		uerrmsg("back to TSO keyboard",                            //~v9@8R~
				"TSOキーボード 復帰");                             //~v9@8R~
      else                                                         //~v9@5I~
    	uerrmsg("Now 3270 keyboard",                               //~v9@8R~
				"3270キーボード 設定");                            //~v9@8R~
    	setflddata(Ppcw,CMDLINENO,0,"");          //clear cmdline input//~v8@ZI~
    }                                                              //~v78ZI~
    csrhomepos(0);                                                 //~v8@ZI~
    UCBITON(Ppcw->UCWflag,UCWFWAKEUP|UCWFDRAW);                    //~v78ZI~
    return 0;                                                      //~v78ZI~
}//func_tsohotkey                                                  //~v78ZI~
//**************************************************************** //~v78ZI~
// 3270kbd index tbl init                                          //~v78ZR~
//**************************************************************** //~v78ZI~
UCHAR *xetsosetup3270keymap(void)                                  //~v78ZI~
{                                                                  //~v78ZI~
    PKBD3270 pkbd;                                                 //~v78ZI~
    USHORT key;                                                    //~v78ZI~
    int ii,idx,scan;                                               //~v78ZR~
//*********************************                                //~v78ZI~
	for (idx=0,pkbd=Skbd3270;idx<KBD3270ENTNO;idx++,pkbd++)        //~v78ZR~
    {                                                              //~v78ZI~
    	for (ii=0;ii<4;ii++) //flat/shift/alt/ctl                  //~v78ZR~
        {                                                          //~v78ZI~
    		key=pkbd->K3270key[ii];                                //~v78ZI~
            if (key)                                               //~v78ZI~
            {                                                      //~v78ZI~
            	scan=(int)(key>>8);	//scancode                     //~v78ZR~
//          	Skeymap3270[scan]=(idx+1);                         //~vaz8R~
            	Skeymap3270[scan]=(UCHAR)(idx+1);                  //~vaz8I~
            }                                                      //~v78ZI~
        }                                                          //~v78ZI~
    }                                                              //~v78ZI~
	Spft3270hotkey=functblsrch(FUNCID_TSOHOTKEY);                  //~v8@ZR~
	return Skeymap3270;                                            //~v78ZI~
}//xetsosetup3270keymap                                            //~v78ZI~
//**************************************************************** //~v78ZI~
// chk key assinged to 3270kbd                                     //~v78ZI~
//rc:index to key-action tbl                                       //~v78ZI~
//**************************************************************** //~v78ZI~
int xetsois3270key(int Popt,PUCLIENTWE Ppcw,int Pkeytype,UCHAR *Pscanchar)//~v78ZR~
{                                                                  //~v78ZI~
    PKBD3270 pkbd;                                                 //~v78ZI~
    int rc=0,idx,scan,flags,keyshift,shiftsw,modshift,modalt,modctl;//~v78ZR~
    int key,cposx,cposy,funcnlsw;                                  //~v78ZR~
//  char *paction,cmdbuff[MAXCOLUMN+1];                            //~v78ZR~//~va04R~
    char *paction,cmdbuff[MAXPARMSZ+1];                            //~va04I~
    int e3270sw;                                                   //~v8@ZI~
//*********************************                                //~v78ZI~
    cposx=Ppcw->UCWrcsrx;                                          //~v78ZI~
    cposy=Ppcw->UCWrcsry;                                          //~v78ZI~
    e3270sw=(UCBITCHK(Ppcw->UCWflag3,UCWF33270KBD2)!=0); //emulator mode//~v8@ZI~
    if (Popt & (TI3KO_RCTLENTER|TI3KO_RCTLNEWLINE))	//by rctl key  //~v78ZI~
    {                                                              //~v78ZI~
		rc=KBD3270_RCTLINDEX;                                      //~v78ZI~
	    if (Popt & TI3KO_RCTLNEWLINE)	                           //~v78ZR~
        {                                                          //~v78ZI~
    		rc|=(1)<<KEY3270_FLAGSHIFT;		//newline id by +SHIFT //~v78ZI~
        }                                                          //~v78ZI~
        else			//enter                                    //~v78ZI~
        {                                                          //~v78ZI~
          if(!e3270sw)                                             //~v8@ZI~
        	if (cposy==CMDLINENO                                   //~v78ZI~
            &&  getfldinput(Ppcw,CMDLINENO,0,cmdbuff))  //cmdline input exist//~v78ZI~
            	return 0;                   //process cmd by xe    //~v78ZI~
        }                                                          //~v78ZI~
    }                                                              //~v78ZI~
    else                                                           //~v78ZI~
    {                                                              //~v78ZI~
        if (Pkeytype==UCWKTEXTKEY)                                 //~v78ZR~
        {                                                          //~v78ZR~
            scan=(int)*Pscanchar;                                  //~v78ZR~
            key=scan<<8;                                           //~v78ZR~
        }                                                          //~v78ZR~
        else                                                       //~v78ZR~
        if (Pkeytype==UCWKTSBCS)                                   //~v78ZR~
        {                                                          //~v78ZR~
            scan=(int)*(Pscanchar+1);                              //~v78ZR~
            key=(scan<<8)|*Pscanchar;                              //~v78ZR~
        }                                                          //~v78ZR~
        else                                                       //~v78ZR~
            return 0;                                              //~v78ZR~
        if (key==KEY_ENTER)                                        //~v78ZI~
        	flags=KBD3270_ENTER;	//special entry,function changes by rctl option//~v78ZI~
        else                                                       //~v78ZI~
        {                                                          //~v78ZI~
        	if (flags=Skeymap3270[scan],!flags)                    //~v78ZR~
            {                                                      //~v8@ZI~
        	  if (!e3270sw)    //not emulator mode                 //~v8@ZI~
            	return 0;                                          //~v78ZR~
            }                                                      //~v8@ZI~
        }                                                          //~v78ZI~
        idx=flags & KEY3270_INDEXMASK;                             //~v78ZR~
        keyshift=Ppcw->UCWkeyshift;                                //~v78ZR~
        modshift=(keyshift & (KBDSTF_RIGHTSHIFT|KBDSTF_LEFTSHIFT));//~v78ZR~
        modalt  =(keyshift & (KBDSTF_ALT|KBDSTF_LEFTALT|KBDSTF_RIGHTALT));//~v78ZR~
        modctl  =(keyshift & (KBDSTF_CONTROL|KBDSTF_LEFTCONTROL|KBDSTF_RIGHTCONTROL));//~v78ZR~
        if (!modshift && !modalt && !modctl)                       //~v78ZR~
        {                                                          //~v78ZR~
            shiftsw=0;                                             //~v78ZR~
            switch(key)                                            //~v78ZR~
            {                                                      //~v78ZR~
            case KEY_ENTER:                                        //~v78ZI~
            	funcnlsw=0;                                        //~v78ZI~
                if (UCBITCHK(Gopt,GOPTRCTLENTER))  //use RCTL as enter//~v78ZI~
//                	if (!(Gotheropt & (GOTHERO_RCTLNL|GOTHERO_CLRCTLNL)))//~v793R~
                  	if (!(Gotheropt & (GOTHERO_RCTLNL)))           //~v793I~
                    	funcnlsw=1;		//enter is newline         //~v78ZI~
                if (funcnlsw)                                      //~v78ZI~
    				shiftsw=1;		//newline id by +SHIFT         //~v78ZI~
                else				//func enter                   //~v78ZI~
                {                                                  //~v78ZI~
                  if(!e3270sw)                                     //~v8@ZI~
		        	if (cposy==CMDLINENO                           //~v78ZI~
            		&&  getfldinput(Ppcw,CMDLINENO,0,cmdbuff))  //cmdline input exist//~v78ZI~
            			return 0;                   //process cmd by xe//~v78ZI~
                }                                                  //~v78ZI~
                rc=idx|(shiftsw<<KEY3270_FLAGSHIFT);               //~v78ZI~
                shiftsw=-1;	//avoid paction definition chk         //~v78ZI~
                break;                                             //~v78ZI~
            case KEY_HOME:                                         //~v78ZR~
              if(!e3270sw)                                         //~v8@ZI~
                if (cposy!=CMDLINENO                               //~v78ZR~
                ||  cposx!=gethomepos(0,Ppcw))  //not on home      //~v78ZR~
                    return 0;                   //xe's home function//~v78ZR~
                break;                                             //~v78ZR~
            case KEY_BS:                                           //~v78ZR~
              if(!e3270sw)                                         //~v8@ZI~
                if (cposy==CMDLINENO                               //~v78ZR~
                &&  cposx>gethomepos(0,Ppcw))  //cmd inputpos      //~v78ZR~
                    return 0;                   //xe's BS to edit cmdline//~v78ZR~
                break;                                             //~v78ZR~
            case KEY_DEL:          //del char on the csr           //~v78ZR~
            case KEY_END:          //erase eof                     //~v78ZR~
            case KEY_INS:          //erase eof                     //~v8@RI~
              if(!e3270sw)                                         //~v8@ZI~
                if (cposy==CMDLINENO                               //~v78ZR~
                &&  getfldinput(Ppcw,CMDLINENO,0,cmdbuff))  //cmdline input exist//~v78ZR~
                    return 0;                   //xe's Del to edit cmdline//~v78ZR~
                break;                                             //~v78ZR~
            case KEY_LEFT:         //<-                            //~v8@ZI~
            case KEY_RIGHT:        //->                            //~v8@ZI~
            case KEY_UP:           //A                             //~v8@ZI~
            case KEY_DOWN:         //V                             //~v8@ZI~
                if (!e3270sw)	//not emulator mode                //~v8@ZI~
                    return 0;                                      //~v8@ZI~
                break;                                             //~v8@ZI~
            }                                                      //~v78ZR~
        }                                                          //~v78ZR~
        else                                                       //~v78ZR~
        if ( modshift && !modalt && !modctl)                       //~v78ZR~
            shiftsw=1;                                             //~v78ZR~
        else                                                       //~v78ZR~
        if (!modshift &&  modalt && !modctl)                       //~v78ZR~
            shiftsw=2;                                             //~v78ZR~
        else                                                       //~v78ZR~
        if (!modshift && !modalt &&  modctl)                       //~v78ZR~
            shiftsw=3;                                             //~v78ZR~
        else                                                       //~v78ZR~
            shiftsw=-1;                                            //~v78ZR~
//      if (shiftsw>=0)                                            //~v8@ZR~
        pkbd=Skbd3270+idx-1;                                       //~v9@5I~
        if (shiftsw>=0 && idx>0)                                   //~v8@ZI~
        {                                                          //~v78ZR~
//          pkbd=Skbd3270+idx-1;                                   //~v9@5R~
            paction=pkbd->K3270action[shiftsw];                    //~v78ZR~
            if (paction)   //no action defined for the shift modifier//~v78ZR~
            if (key==pkbd->K3270key[shiftsw])                      //~v8@TI~
                rc=idx|(shiftsw<<KEY3270_FLAGSHIFT);               //~v78ZR~
                                                                   //~v78ZR~
        }                                                          //~v78ZR~
        if (e3270sw)    //emulator mode                            //~v8@ZR~
        {                                                          //~v8@ZR~
        	if (rc)                                                //~v8@ZI~
            {                                                      //~v8@ZI~
            	if (pkbd->K3270flag & K3270F_NOTSO)                //~v8@ZI~
                	rc=-1;                                         //~v8@ZI~
            }                                                      //~v8@ZI~
            else                                                   //~v8@ZI~
            {                                                      //~v8@ZI~
            	if (Pkeytype==UCWKTSBCS)                           //~v8@ZR~
                {                                                  //~v8@ZI~
	        		if (*Pscanchar<' ' && key!=KEY_ESC)	//ctl char //~v8@ZR~
                		rc=-1;                                     //~v8@ZI~
                }                                                  //~v8@ZI~
                else //extkey                                      //~v8@ZI~
                {                                                  //~v8@ZI~
	        		if (modalt||modctl)                            //~v8@ZI~
						if (Spft3270hotkey && key!=Spft3270hotkey->FTkey[0])//~v8@ZR~
                			rc=-1;                                 //~v8@ZR~
				}                                                  //~v8@ZI~
            }                                                      //~v8@ZM~
            if (rc<0)                                              //~v8@ZR~
                uerrmsg("Undefined key for TSO emulation keyboard",//~v8@ZR~
                        "このキーはTSOモード用には使えません");    //~v8@ZR~
        }                                                          //~v8@ZR~
    }                                                              //~v78ZI~
    return rc;                                                     //~v78ZI~
}//xetsois3270key                                                  //~v78ZI~
//**************************************************************** //~v78ZI~
// back to \n from \N by CAPON function                            //~v78ZI~
//**************************************************************** //~v78ZI~
int func_3270kbd(PUCLIENTWE Ppcw)                                  //~v78ZI~
{                                                                  //~v78ZI~
	PKBD3270 pkbd;                                                 //~v78ZI~
    char *paction,*prm;                                            //~v8@RR~
    int flag,idx,rc,shiftsw=0,rc2;                                 //~vaf9R~
//  char actioncmd[MAXCOLUMN*2];                                   //~v8@RI~//~va04R~
//  char actionrepcmd[MAXCOLUMN*2];                                //~v8@WI~//~va04R~
    char actioncmd[MAXPARMSZ*2];                                   //~va04I~
    char actionrepcmd[MAXPARMSZ*2];                                //~va04I~
    int e3270sw;                                                   //~v8@ZI~
//*********************************                                //~v78ZI~
    e3270sw=(UCBITCHK(Ppcw->UCWflag3,UCWF33270KBD2)!=0); //emulator mode//~v8@ZI~
  if (Ppcw->UCWkeytype==UCWKT3270KBD)                              //~v8@ZR~
  {                                                                //~v8@ZI~
    flag=Ppcw->UCWkeydata[0];    //inedx to  Skbd3270              //~v78ZR~
    idx=flag & KEY3270_INDEXMASK;                                  //~v78ZI~
    shiftsw=(flag >> KEY3270_FLAGSHIFT);       //1:shift,2:alt     //~v78ZR~
  }                                                                //~v8@ZI~
  else                                                             //~v8@ZI~
    idx=0;                                                         //~v8@ZI~
    if (idx==KBD3270_RCTLINDEX     //by rctl key                   //~v78ZR~
    ||  idx==KBD3270_ENTER)    //by rctl key                       //~v78ZI~
    {                                                              //~v78ZI~
    	if (shiftsw)    //+SHIFT:NEWLINE                           //~v78ZI~
        	paction="NewLine";                                     //~v78ZI~
        else                                                       //~v78ZI~
        	paction="Enter";                                       //~v78ZI~
    }                                                              //~v78ZI~
    else                                                           //~v78ZI~
    if (Ppcw->UCWkeytype==UCWKTSBCS                                //~v8@ZR~
    ||  Ppcw->UCWkeytype==UCWKTDBCS                                //~v8@ZR~
    )                                                              //~v8@ZI~
    {                                                              //~v8@ZI~
		xetso2escstring2(0,Ppcw->UCWkeydata,Ppcw->UCWkeytype,actioncmd);//~v8@ZR~
        paction=actioncmd;                                         //~v8@ZI~
    }                                                              //~v8@ZI~
    else                                                           //~v8@ZI~
    {                                                              //~v78ZI~
        pkbd=Skbd3270+idx-1;                                       //~v78ZR~
        paction=pkbd->K3270action[shiftsw];                        //~v78ZR~
        if (!paction)                                              //~v78ZR~
            return 8; //internal logic err                         //~v78ZR~
        if (pkbd->K3270flag & K3270F_SWTSO)                        //~v8@ZI~
        {                                                          //~v8@ZI~
    		e3270sw=(UCBITCHK(Ppcw->UCWflag3,UCWF33270KBD2)!=0); //emulator mode//~v8@ZI~
			tso3270tsokbd(e3270sw,Ppcw);                           //~v9@5I~
            return 0;                                              //~v8@ZI~
        }                                                          //~v8@ZI~
        if (pkbd->K3270flag & K3270F_ACTION)                       //~v8@ZI~
        {                                                          //~v8@RI~
            getfldinput(Ppcw,CMDLINENO,0,actioncmd);  //action cmdline input//~v8@RR~
            setflddata(Ppcw,CMDLINENO,0,"");          //clear cmdline input//~v8@RI~
            csrhomepos(0);                                         //~v8@RR~
  			rc2=xetso2isvalidactionname(0,actioncmd,actionrepcmd); //~v8@WI~
            if (rc2==2)    //replaced                              //~v8@WI~
            	paction=actionrepcmd;                              //~v8@WI~
            else                                                   //~v8@WI~
            	paction=actioncmd;                                 //~v8@WR~
        }                                                          //~v8@RI~
    }                                                              //~v78ZI~
    prm=Ppcw->UCWparm;                                             //~v78ZI~
    Ppcw->UCWparm=paction;                                         //~v78ZI~
	rc=xetsotsocmd(Ppcw);                                          //~v78ZR~
    Ppcw->UCWparm=prm;                                             //~v78ZI~
    return rc;                                                     //~v78ZI~
}//func_3270kbd                                                    //~v78ZI~
//**************************************************************** //~v9@5I~
// tsoset3270tsokbd                                                //~v9@5I~
//**************************************************************** //~v9@5I~
int tso3270tsokbd(int Popt,PUCLIENTWE Ppcw)                        //~v9@5I~
{                                                                  //~v9@5I~
    if (Popt & 0x01)    //previously on                            //~v9@5I~
    {                                                              //~v9@5I~
        UCBITOFF(Ppcw->UCWflag3,UCWF33270KBD2);                    //~v9@5I~
        uerrmsg("Reset TSO keyboard",                              //~v9@8R~
                "TSOキーボード 解除");                             //~v9@8R~
                                                                   //~v9@5I~
    }                                                              //~v9@5I~
    else                                                           //~v9@5I~
    {                                                              //~v9@5I~
        UCBITON(Ppcw->UCWflag3,UCWF33270KBD2);                     //~v9@5I~
        uerrmsg("Now TSO Keyboard",                                //~v9@8R~
                "TSOキーボード 設定");                             //~v9@8R~
        setflddata(Ppcw,CMDLINENO,0,"");          //clear cmdline input//~v9@5I~
    }                                                              //~v9@5I~
    csrhomepos(0);                                                 //~v9@5I~
    UCBITON(Ppcw->UCWflag,UCWFWAKEUP|UCWFDRAW);                    //~v9@5I~
    return 0;                                                      //~v9@5I~
}//tso3270tsokbd                                                   //~v9@5I~
#endif	//FTPSUPP                                                  //~v72BI~
