//*CID://+vbvwR~:                             update#=  396;       //~vbvwR~
//*************************************************************    //~v0hqI~
//*xefile7.c                                                       //~v0hqI~
//**drop,tab clear,func key file edit                              //~v0ifR~
//*************************************************************    //~v0hqI~
//vbvz:221203 (Bug)=0.1;missing set string terminater null         //~vbvzI~
//vbvw:221203 =0.1 comment by Japanese                             //~vbvwI~
//vbvv:221203 =0.1 comment for user command                        //~vbvvI~
//vbvt:221202 =0.2/=0.3 display code itself for default box char for japanese//~vbvtI~
//vbvs:221202 (BUG)find cmd fai for =0.2(ULHdbcs setup required)   //~vbvsI~
//vbvr:221201 (BUG)whe deleted line of =0.2, it key is cleared and changed to cmd mode//~vbvrI~
//vbvp:221201 (BUG)FTkey index is not valid by Protected line(Fixed key assign)//~vbvpI~
//vbvo:221201 show sample for sc cmd of =0.1                       //~vbvoI~
//vbvn:221201 (BUG)=0.1 shortcutkey cause err "not alphnum"        //~vbvnI~
//vbvm:221130 show alias sample line to 0.1 panel                  //~vbvmI~
//vbvi:221130 (BUG)FTFLINECHSET:x20 is duplicated with DTUDUPACMD  //~vbviI~
//vbvh:221130 =0.2; clear key did not update xe.ini                //~vbvhI~
//vbvf:221129 drop japanese comment for =0.2/0.3 when english mode //~vbvfI~
//vbvd:221125 on 0.2/0.3 display hex/sjis string by utf8 avoiding line err(lineno green)//~vbvdI~
//vbvb:221125 opt 0.2/0.3 as utf8 file for utf8 graphic char display//~vbvbI~
//vb82:170206 (BUG)64bit ptr size(filefk)                          //~vb82I~
//vb50:160827 accept S+A/C+extended key                            //~vb50I~
//vb2E:160229 LNX64 compiler warning                               //~vb2EI~
//vb2D:160221 LNX compiler warning                                 //~vb2DI~
//vb2A:160212 fkt;protect buff overflow                            //~vb2AI~
//vagb:120824 (BUG)func NULLCHAR is not written to ini             //~vafgI~
//vafk:120624 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  use ULPTR(unsigned __int64/ULONG)//~vafkI~
//vafc:120607 C4701 warning(used uninitialized variable) by VC6    //~vafcI~
//vaf9:120607 (WTL)Bug found by vs2010exp(used uninitialized variable),avoid warning C4701//~vaf9I~
//va79:100809 cpeb converter parm support                          //~va79I~
//va6r:000623 flag for menuopt a/b/c for ligature chk              //~va6rI~
//va50:100324 Raw EBCDIC file support for NFS mount                //~va50I~
//va0a:090629 (BUG)ABEND when alias cmd save(strspn beyond ULHlen) //~va0aI~
//            (BUG)for save shortcut key select text from end when contains trailer space//~va0aI~
//v79z:080916 DBCS tbl for C and K of CJK                          //~v79zI~
//v756:070418 set cmd verb for 0.2 panel even if not cmd only      //~v71PI~
//v71P:061107 enable cmd verb change on =0.2 panel                 //~v71PI~
//v705:060727 graphic char setup by external file(2 string for opt linech on/off)//~v705I~
//v69Y:060722 add A+"=" to virtical line for 101 keyboard (scancode=13, "^" on japanese kbd)//~v69YI~
//v699:060428 (BUG)opt 0.2 save report error for ctl+char key. And on 0.2 scr, A+char and C+char is not accepted//~v699I~
//v67C:051228 support alias cmd(save in ini file using shortcut key table position ":")//~v67CI~
//v54X:040201 del nx all performance tuning                        //~v54XI~
//v505:021007 add comment of short cut for menu-A                  //~v505I~
//v48f:020504 more key for macro function(not only PFn but also A+q,A+a and 1 byte char)//~v48fI~
//v47V:020407 (BUG)opt 0.2 key assign list comment colomn position err//~v47VI~
//v45K:011229 (BUG)dup key assign is not listed by menu 0.2        //~v45KI~
//v44v:011206 display alias cmd in func list                       //~v44vI~
//v44u:011206 (LNX) func japanesename conv to euc for ini file     //~v44uI~
//                  display funcname japanese for opt 0.2          //~v44uI~
//v40K:010714 option to insert comment line for drop excluded cmd(dro x|nx rep)//~v40KI~
//v0ji:980722 tab for key cmd(0.1)                                 //~v0jiI~
//v0jh:980722 reject char key for key assign change                //~v0jhI~
//v0jg:980722 scroll page to err line for fkey/pfkey               //~v0jgI~
//v0jf:980722 move csr to top-of-line after press for fkey panel   //~v0jfI~
//v0je:980722 allow s+ for alternative of Shift+ for key assign in ini//~v0jeI~
//v0jd:980722 fix ctrl+2(null char),drop from ini and assign chng screen//~v0jdI~
//v0ja:980721 change define value by change opt start from 0.0     //~v0jaI~
//v0j9:980721 (BUG)filesk double line enque when re-display        //~v0j9I~
//v0j8:980720 (BUG)no fkctt stopper,use entno                      //~v0j8I~
//v0ix:980718 key assign by key press                              //~v0ixI~
//v0iw:980718 pfk cmd support(del 0.5,cmd change by ini only)      //~v0iwI~
//v0im:980625 pfk cmd support(optk1 and optk2)                     //~v0imI~
//v0ih:980621 pfk cmd support(pfk table)                           //~v0ihI~
//v0if:980620 pfk cmd support                                      //~v0ifI~
//v0ic:980607 label support for DROP cmd                           //~v0icI~
//v0hq:980316 add DROP cmd(del all line XON/XOFF)                  //~v0hqI~
//*************************************************************    //~v0hqI~
#include <time.h>                                                  //~v0hqI~
#include <stdio.h>                                                 //~v0hqI~
#include <stddef.h>                                                //~v0hqI~
#include <stdlib.h>                                                //~v0hqI~
#include <ctype.h>                                                 //~v0hqI~
#include <string.h>                                                //~v0hqI~
#ifdef DOS                                                         //~v0hqI~
    #ifdef DPMI					//DPMI version                     //~v0hqI~
        #include <errno.h>                                         //~v0hqI~
    #else                       //not DPMI                         //~v0hqI~
    #endif                      //DPMI or not                      //~v0hqI~
#else                                                              //~v0hqI~
//  #define INCL_BASE                                              //~v0hqI~
//  #include <os2.h>                                               //~v0hqI~
#endif                                                             //~v0hqI~
//*******************************************************          //~v0hqI~
#include <ulib.h>                                                  //~v0hqI~
#include <ualloc.h>                                                //~v0hqI~
#include <uerr.h>                                                  //~v0hqI~
#include <uque.h>                                                  //~v0hqI~
#include <ufile.h>                                                 //~v0hqI~
#include <ustring.h>                                               //~v0imI~
#include <uparse.h>                                                //~v0jgI~
#include <ucvext.h>                                                //~va79I~
#include <ucvebc.h>                                                //~va50I~
#include <ucvebc4.h>                                               //~va79I~
#include <utrace.h>                                                //~vb50I~
#include <utf.h>                                                   //~vbvbI~
#include <udbcschk.h>                                              //~vbvwR~
                                                                   //~v0hqI~
#include "xe.h"                                                    //~v0hqI~
#include "xescr.h"                                                 //~v0hqI~
#include "xekbd.h"                                                 //~v0ixM~
#include "xefile.h"                                                //~v0hqI~
#include "xefile12.h" 	//filesetlineerr                           //~v0ihI~
#include "xefile2.h"	//multdraw                                 //~v0hqI~
#include "xefile7.h"                                               //~v0hqI~
#include "xefunc.h"                                                //~v0ihR~
#include "xefunct.h"                                               //~v0imI~
#include "xelcmd.h"                                                //~v0hqI~
#include "xelcmd2.h"    //lcmddel                                  //~v0hqI~
#include "xefcmd22.h"   //fcmdscrollpage                           //~v0jgI~
#include "xefcmd3.h"   //fcmdscrollpage                            //~v0jiI~
#include "xeundo.h"                                                //~v0hqI~
#include "xepan.h"                                                 //~v0ixI~
#include "xegbl.h"                                                 //~v44uI~
#include "xefile6.h"                                               //~vbvsI~
#include "xeutf.h"                                                 //~vbvwI~
#include "xeopt.h"                                                 //~vbvsR~
//*******************************************************          //~v0hqI~
#define NOCMDID '_'                                                //~v0imR~
#define CMDDELM '/'                                                //~v0imI~
#define SHORTCUTID  "sc,"   //prefix of shortcut key definition    //~v48fR~
#define SHORTCUTIDSZ 3      //prefix of shortcut key definition    //~v48fI~
#ifndef KKK                                                        //~vb50I~
	#define ALIASID     "Alias  :" //prefix of alias cmd definition//~vb50I~
	#define ALIASIDSZ   8                                          //~vb50I~
#else                                                              //~vb50I~
#define ALIASID     "Alias:" //prefix of alias cmd definition      //~v67CR~
#define ALIASIDSZ   6		                                       //~v67CR~
#endif                                                             //~vb50I~
#define ALIASCMT    '*'   //comment id                             //~v67CI~
#define NOTFIXCMDID '+'   //commandverb changable                  //~v71PI~
//#define GRAPH_ENGLISH "(E)"                                      //~vbvfR~
//*******************************************************          //~v0imI~
	static UQUEH Sqhalct;                                          //~v67CR~
//*******************************************************          //~v67CI~
int filefkctline(PUFILEH Ppfh,PULINEH Pplh,int Popt);              //~v0imR~
int filefkctlineft(PUFILEH Ppfh,PULINEH Pplh,int Popt);            //~v0imR~
int filefksaveft(PUCLIENTWE Ppcw,PUFILEH Ppfh,int Popt);           //~v0imI~
int filekeynameerr(void);                                          //~v0ihI~
int fileoptlreclerr(void);                                         //~v0imI~
int fileoptfuncnmerr(void);                                        //~v0imI~
#ifndef KKK                                                        //~vb50I~
int filekeyassign(int Popt,PWORKFT Ppwft0,int Pentno,PWORKFT Ppwft,KEYTBL *Ppkt,int Pshift);//~vb50I~
#define FKAO_SHIFTAC    0x01 //S+AC                                //~vb50I~
#else                                                              //~vb50I~
int filekeyassign(PWORKFT Ppwft0,int Pentno,PWORKFT Ppwft,KEYTBL *Ppkt,int Pshift);//~v0imR~
#endif                                                             //~vb50I~
int filecmdvassign(PWORKFT Ppwft0,PWORKFT Ppwft,UCHAR Pcmdv[2][4]);//~v0iwR~,//~v71PR~
int fileoptkeyoverflow(void);                                      //~v0imI~
int fileoptcmdfmterr(void);                                        //~v0imI~
//int fileoptdupcmdv(void);                                        //~v71PR~
int fileoptdupcmdv(char *Pverb);                                   //~v71PI~
#ifndef KKK                                                        //~vb50I~
int fileoptdupassign(char *Pkeyname);                              //~vb50I~
#else                                                              //~vb50I~
int fileoptdupassign(void);                                        //~v0imI~
#endif                                                             //~vb50I~
int fileoptfixederr(void);                                         //~v0ixI~
int filefkctlineshortcut(PUFILEH Ppfh);                            //~v48fI~
int filefksaveshortcut(PULINEH Pplh,UCHAR *Pdata);                 //~v48fI~
int filefkctlinealias(PUFILEH Ppfh);                               //~v67CR~
int filefksavealias(PULINEH Pplh,UQUEH *Ppqhalct);                 //~v67CR~
int filesetupscktalias(UQUEH *Ppqhalct);                           //~v67CR~
int filekeyclear(PWORKFT Ppwft0,int Pentno,PWORKFT Ppwft,PFUNCTBL Ppft,int PidxKey);//~vbvhI~
static int SswByUTF8=0x02;                                         //~vbvbR~
static char *ScommentGC[]={"***** LineChr : output hex code itself or UTF8 string for u-xxxx.",//~vbvwR~
#ifdef LNX                                                         //~vbvfI~
						   "*****         : hex code is for CP437, 2\'nd code of after // is by +Shift key combination.",//~vbvwR~
						   "*****         : You can change it by ::xelchlnx.ini.xxx, xxx is langID such as ja_JP. Check it by locale cmd.",//~vbvtR~
#else                                                              //~vbvfI~
						   "*****         : hex code is for Shift-JIS, 2\'nd code of after // is by +Shift key combination.",//~vbvwR~
						   "*****         : You can change it by ::xelchwin.ini.",//~vbvtI~
#endif                                                             //~vbvfI~
                            0                                      //~vbvbI~
};                                                                 //~vbvbI~
static char *ScommentGC_JP[]={"***** 罫線文字: ヘキサコードをそのままか、u-xxxx はUTF8コードに変えて出力",//~vbvwR~
#ifdef LNX                                                         //~vbvwI~
						      "*****         : ヘキサコードは 日本語環境では EUC-JP。//の後の2番目のコードは +Shift(シフトキー) で出力",//~vbvwR~
						      "*****         : 設定変更は ::xelchlnx.ini.xxx, xxx は ja_JPなどの言語環境で locale コマンドで調べられます",//~vbvwI~
#else                                                              //~vbvwI~
						      "*****         : ヘキサコードは 日本語環境では Shift-JIS。//の後の2番目のコードは +Shift(シフトキー) で出力",//~vbvwR~
                              "*****         : 設定変更は ::xelchwin.iniを作成してください",//~vbvwR~
#endif                                                             //~vbvwI~
                            0};                                    //~vbvwI~
static char *ScommentAlias[]={"********** Alias command sample **********",//~vbvmI~
                              "********   Alias  :sl1 e %1 ;x all; f \"#error\"; del x all # select lines including #error; use like as \"sl1 file1\".",//~vbvmR~
                              "********       Use it like as \"sl1 file1\" on command input line.",//~vbvvI~
                              "********   Alias  :*sl1 e %1 ;x all; i error; del x all #this is comment line",//~vbvmR~
                              0};                                  //~vbvmI~
static char *ScommentAlias_JP[]={"********** Alias コマンドの例 **********",//~vbvwI~
                              "********   Alias  :sl1 e %1 ;x all; f \"#error\"; del x all # select lines including #error; use like as \"sl1 file1\".",//~vbvwI~
                              "********       コマンド入力行 \"sl1 file1\" の様に入力して使用します",//~vbvwI~
                              "********   Alias  :*sl1 e %1 ;x all; i error; del x all #this is comment line",//~vbvwI~
                              0};                                  //~vbvwI~
static char *ScommentSC[]={"********** shortcut command sample **********",//~vbvoI~
                              "********   sc,0   :cd w:\\AndroidStudioProjects\\BluetoothChat18\\app\\src\\main; e . # comment",//~vbvoR~
                              "********       Press Alt+a then 0, text string is put at the cursor position.",//~vbvoR~
                              "********       Pressing Alt+q then key 0 will show the text string. Next key 0 puts it at the cursor position.",//~vbvvR~
                              "********   sc,1   :e %1; f %2    # open and find word",//~vbvoR~
                              "********       Input \"file1 \'Key Word\'\" on command input line, Press Al+q then 1, \"e file1; f \'Key Word\'\" is put.",//~vbvoR~
                              0};                                  //~vbvoI~
static char *ScommentSC_JP[]={"********** ショートカット コマンドの例 **********",//~vbvwI~
                              "********   sc,0   :cd w:\\AndroidStudioProjects\\BluetoothChat18\\app\\src\\main; e . # comment",//~vbvwI~
                                "********       Alt+a の後 0 を押すと、設定の文字列がカー\x83\\ル位置に出力されます",//~vbvwR~
                                "********       Alt+q の後では文字列が\x95\\示されます、続けて 0 を押すとカー\x83\\ル位置に文字列が出力されます",//~vbvwR~
                              "********   sc,1   :e %1; f %2    # open and find word",//~vbvwI~
                              "********       コマンド入力行に \"file1 \'Key Word\'\" を入力した状態で操作すると \"e file1; f \'Key Word\'\" となります",//~vbvwI~
                              0};                                  //~vbvwI~
static char *ScommentUC[]={"********** user command. You can assign command sequence to key combinations. *********",//~vbvvR~
                              "********       If string end with \";\", it is executed else put on command input line.",//~vbvvI~
                              "********       %n (n:1-->9), %@ (remaining %n), %* (current file), %^ (opened other side of split screen).",//~vbvwR~
                              "********   e.g) S+A+F9 :=6; grep  -in %1 *.c;    # search word in current directory.",//~vbvvR~
                              "********          Input \"KeyWord\" on command input line, then press S+A+F9. to execute the grep command.",//~vbvwR~
                              0};                                  //~vbvvI~
static char *ScommentUC_JP[]={"********** ユーザーコマンド。 既定で空いているキーにコマンドを定義できます *********",//~vbvwR~
                              "********       文字列の最後が \";\" なら直ぐに実行し、そうでなければコマンド入力行に出力されます",//~vbvwR~
                              "********       %n (n:1-->9), %@ (残りの %n), %* (現在開いているファイル), %^ (分割画面の他方で開いているファイル)が使えます",//~vbvwR~
                              "********   例) S+A+F9 :=6; grep  -in %1 *.c;    # search word in current directory.",//~vbvwR~
                              "********          コマンド入力行に \"KeyWord\" と入力し、S+A+F9 を押すと grep を実行します",//~vbvwR~
                              0};                                  //~vbvwI~
//static int SswByUTF8=0;	//TODO test                            //~vbvbR~
//**************************************************************** //~v67CI~
//* free alct(<--kbdterm)                                          //~v67CI~
//**************************************************************** //~v67CI~
void file7term(void)                                               //~v67CR~
{                                                                  //~v67CI~
	uqufree(&Sqhalct);	//free old                                 //~v67CI~
    return;                                                        //~v67CI~
}//file7term                                                       //~v67CI~
//**************************************************************** //~vbvbI~
int cvFuncNameS2F(char *Pputf8,char *Ppsjis,int Plen)              //~vbvbR~
{                                                                  //~vbvbI~
	int opt=0,outlen;                                              //~vbvbR~
    utfcvl2f(opt,Pputf8,Ppsjis,0/*init offs*/,Plen,0/*out choftbl*/,0/*out dbcstbl*/,0/*chklen*/,&outlen/*outlen*/,0/*pcharcnt*/,0/*char width*/);//~vbvbR~
    UTRACED("sjis",Ppsjis,Plen);                                   //~vbvwI~
    UTRACED("utf8",Pputf8,outlen);                                 //~vbvwI~
    return outlen;                                                 //~vbvbR~
}                                                                  //~vbvbI~
//**************************************************************** //~vbvoI~
//int putComment(char **Pcmts,PULINEH *PpplhPrev)                    //~vbvoI~//~vbvwR~
int putComment(int Popt,char **Pcmts,PULINEH *PpplhPrev)           //~vbvwI~
{                                                                  //~vbvoI~
	int ii,lrecl;                                                  //~vbvoR~
    int u8len;                                                     //~vbvwR~
    PULINEH plhprev=*PpplhPrev,plh;                                //~vbvoI~
    char *pcmt;                                                    //~vbvwR~
    UCHAR *pco;                                                    //~vbvwI~
#ifdef LNX     //local is EUC                                      //~vbvwI~
    char wks2e[MAXCOLUMN+1];                                       //~vbvwI~
    int euclen;                                                    //~vbvwI~
#endif                                                             //~vbvwI~
    //*********************                                        //~vbvwI~
    for (ii=0;;ii++)                                               //~vbvoI~
    {                                                              //~vbvoI~
        if (!Pcmts[ii])                                            //~vbvoI~
            break;                                                 //~vbvoI~
        lrecl=(int)strlen(Pcmts[ii]);                              //~vbvoI~
        pcmt=Pcmts[ii];                                            //~vbvwI~
      	if (Popt & 0x01)	//cv S2F required                      //~vbvwI~
      	{                                                          //~vbvwI~
#ifdef LNX     //local is EUC                                      //~vbvwI~
      		ushift2euc(pcmt,0/*dbcsi*/,lrecl,wks2e/*out*/,0/*outdbcst*/,&euclen/*poutlen*/,0/*Popt*/);	//sjis-->euc//~vbvwI~
            lrecl=euclen;                                          //~vbvwI~
            pcmt=wks2e;                                            //~vbvwI~
#endif                                                             //~vbvwI~
    		xeutf_cvdata(0,pcmt,lrecl,&pco,&u8len); //local is SJIS//~vbvwR~
            pcmt=(char*)pco;                                       //~vbvwR~
            lrecl=u8len;                                           //~vbvwI~
      	}                                                          //~vbvwI~
        else                                                       //~vbvwR~
        {                                                          //~vbvwR~
#ifdef LNX     //local is EUC, required to s2e                     //~vbvwR~
			if (!XE_NOT_ISDBCSJ_OR_N9())                           //~vbvwR~
            {                                                      //~vbvwI~
      			ushift2euc(pcmt,0/*dbcsi*/,lrecl,wks2e/*out*/,0/*outdbcst*/,&euclen/*poutlen*/,0/*Popt*/);	//sjis-->euc//~vbvwR~
            	lrecl=euclen;                                      //~vbvwR~
            	pcmt=wks2e;                                        //~vbvwR~
            }                                                      //~vbvwI~
#else                                                              //~vbvwR~
            ;                                                      //~vbvwR~
#endif                                                             //~vbvwR~
        }                                                          //~vbvwR~
        plh=filealloclh(ULHTDATA,lrecl);                           //~vbvoI~
        UALLOCCHK(plh,UALLOC_FAILED);//return when storage shortage//~vbvoI~
        UENQENT(UQUE_AFT,plhprev,plh);                             //~vbvoI~
        plh->ULHlinenor=plhprev->ULHlinenor+1;                     //~vbvoI~
//      memcpy(plh->ULHdata,Pcmts[ii],(UINT)lrecl);                //~vbvoI~//~vbvwR~
        memcpy(plh->ULHdata,pcmt,(UINT)lrecl);                     //~vbvwI~
        UTRACED("ULHdata",plh->ULHdata,lrecl);                     //~vbvoI~
        UCBITON(plh->ULHflag4,ULHF4PROTLINE);   //protected(change line attr)//~vbvoI~
        plhprev=plh;                                               //~vbvoI~
    }                                                              //~vbvoI~
    *PpplhPrev=plhprev;                                            //~vbvoR~
    return 0;                                                      //~vbvoI~
}                                                                  //~vbvoI~
//**************************************************************** //~v40KR~
// filedropinsertcmt                                               //~v40KR~
//*insert comment line for dropped lines                           //~v40KR~
//*parm1:pcw                                                       //~v40KR~
//*parm2:pfh                                                       //~v40KR~
//*parm3:drop x or drop nx id                                      //~v40KR~
//*parm4:top plh to be deleted                                     //~v40KR~
//*rc   :0                                                         //~v40KR~
//**************************************************************** //~v40KR~
int filedropinsertcmt(PUCLIENTWE Ppcw,PUFILEH Ppfh,int Popt,PULINEH Pplh,int Pdelctr)//~v40KR~
{                                                                  //~v40KR~
    PULINEH plhprev,plh;                                           //~v40KR~
    int rc,len;                                                    //~v40KR~
    char wkcmt[80];                                                //~v40KR~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    int swebcfile;                                                 //~va50I~
    int handle;                                                    //~va79I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//*********************************                                //~v40KR~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    swebcfile=PFH_ISEBC(Ppfh);                                     //~va50I~
    handle=Ppfh->UFHhandle;                                        //~va79I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    plhprev=UGETQPREV(Pplh);                                       //~v40KR~
    if (Popt==DFOPT_X)  //                                         //~v40KR~
    {                                                              //~v40KI~
        rc=fcmdisrtline(Ppcw,plhprev,Pplh->ULHdata,71);            //~v40KR~
        plh=UGETQNEXT(plhprev);                                    //~v40KI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
//      *(plh->ULHdata+1)=*plh->ULHdata=UCVEBC_CONSTC(swebcfile,'!');//~va50R~//~va79R~
//      *(plh->ULHdata+1)=*plh->ULHdata=UCVEBC_CONSTC(swebcfile,handle,'!');//~va79I~//~vb2DR~
        *(plh->ULHdata+1)=*plh->ULHdata=(UCHAR)UCVEBC_CONSTC(swebcfile,handle,'!');//~vb2DI~
#else                                                              //~va50I~
        *plh->ULHdata='!';                                         //~v40KI~
        *(plh->ULHdata+1)='!';                                     //~v40KI~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    }                                                              //~v40KI~
    else                                                           //~v40KR~
    {                                                              //~v40KR~
        len=sprintf(wkcmt,"!!--- %4d line(s) deleted -----",Pdelctr);//~v40KR~
        rc=fcmdisrtline(Ppcw,plhprev,wkcmt,len);                   //~v40KR~
    }                                                              //~v40KR~
    return rc;                                                     //~v40KR~
}//filedropinsertcmt                                               //~v40KR~
//**************************************************************** //~v0hqI~
// filedrop                                                        //~v0hqI~
//*drop all flaged line                                            //~v0hqI~
//*parm1:pcw                                                       //~v0hqI~
//*parm2:pfh                                                       //~v0hqI~
//*parm3:option 1:del xon,2:del xoff                               //~v0hqI~
//*parm4:start plh                                                 //~v0icI~
//*parm5:next of end plh                                           //~v0icI~
//*rc   :0                                                         //~v0hqI~
//**************************************************************** //~v0hqI~
int filedrop(PUCLIENTWE Ppcw,PUFILEH Ppfh,int Popt,PULINEH Pplh1,PULINEH Pplh2)//~v0icR~
{                                                                  //~v0hqI~
	PUQUEH qh;                                                     //~v0hqI~
	PULINEH plh,plh1,plh2=0,plhprev;                               //~vaf9R~
	PULINEH plh1st=0;                                              //~v0hqI~
    int delctr=0,delctr2=0,repsw=0;                                //~v40KR~
    int rc;                                                        //~v0hqI~
    int delopt,doxeditsw;                                          //~v54XI~
//*********************************                                //~v0hqI~
	if (Popt & DFOPT_REP)                                          //~v40KR~
    {                                                              //~v40KR~
    	repsw=1;                                                   //~v40KR~
        Popt &= ~DFOPT_REP;                                        //~v40KR~
    }                                                              //~v40KR~
  if (Pplh1)                                                       //~v0icI~
    plh=Pplh1;                                                     //~v0icI~
  else                                                             //~v0icI~
  {                                                                //~v0icI~
	qh=&(Ppfh->UFHlineque);                                        //~v0hqI~
	plh=(PULINEH)UGETQTOP(qh);                                     //~v0hqI~
  }                                                                //~v0icI~
    UPCTRREQ(Ppfh);         //write at save                        //~v0hqI~
    switch(Popt)                                                   //~v0hqI~
    {                                                              //~v0hqI~
    case 1:					//del xon                              //~v0hqI~
        while(plh)                                                 //~v0hqI~
        {                                                          //~v0hqI~
            if (plh->ULHtype==ULHTEXCLUDE)                         //~v0hqI~
            {                                                      //~v0hqI~
                if (!plh1st)                                       //~v0hqI~
                    plh1st=plh;     //1st changed                  //~v0hqI~
                delctr+=(int)plh->ULHlinenow;                      //~v0hqI~
                if (repsw)                                         //~v40KI~
                {                                                  //~v40KI~
					rc=filedropinsertcmt(Ppcw,Ppfh,Popt,plh,0);    //~v40KR~
                	if (rc)                                        //~v40KR~
                    	return rc;                                 //~v40KR~
                }                                                  //~v40KM~
                plhprev=UGETQPREV(plh);                            //~v0hqI~
                rc=lcmddel(Ppcw,plh,plh,1,0,1);//1line del,no csr set,not lcmd//~v40KR~
                if (rc)                                            //~v40KR~
                    return rc;                                     //~v40KR~
                plh=plhprev;	//cotinue from prev line           //~v0hqI~
            }                                                      //~v0hqI~
            plh=UGETQNEXT(plh);                                    //~v0hqI~
            if (plh==Pplh2) //reached to next of end plh           //~v0icI~
                break;                                             //~v0icI~
        }//all plh                                                 //~v0hqI~
        break;                                                     //~v0hqI~
    case 2:			//del xoff                                     //~v0hqI~
    	plh1=0;                                                    //~v0hqI~
        doxeditsw=0;                                               //~v54XI~
        while(plh)                                                 //~v0hqI~
        {                                                          //~v0hqI~
            if (plh->ULHtype==ULHTDATA                             //~v0hqI~
            &&  plh!=Pplh2         //if reached to next of end plh,do del//~v0icI~
            &&  !UCBITCHK(plh->ULHflag2,ULHF2EXCLUDED))	//displayed data line//~v0hqI~
            {                                                      //~v0hqI~
                if (!plh1)                                         //~v0hqI~
                	plh1=plh;                                      //~v0hqI~
                delctr++;                                          //~v0hqI~
                delctr2++;                                         //~v40KR~
                plh2=plh;       //prev line                        //~v0hqI~
			}                                                      //~v0hqI~
            else	//hdr or excluded                              //~v0hqI~
            	if (plh1)		//display line already started     //~v0hqI~
                {                                                  //~v0hqI~
                    if (!plh1st)                                   //~v0hqI~
                        plh1st=plh1;     //1st changed             //~v0hqR~
	                if (repsw)                                     //~v40KR~
    	            {                                              //~v40KR~
						rc=filedropinsertcmt(Ppcw,Ppfh,Popt,plh1,delctr2);//~v40KR~
                        delctr2=0;                                 //~v40KI~
    			        if (rc)                                    //~v40KR~
            		        return rc;                             //~v40KR~
                    }                                              //~v40KR~
                    plhprev=UGETQPREV(plh1);                       //~v0hqI~
//                  rc=lcmddel(Ppcw,plh1,plh2,1,0,1);//1line del,no csr set,not lcmd//~v54XI~
					delopt=LCDEL_NOTFROMMAIN;                      //~v54XI~
                  	if (!repsw)                                    //~v54XR~
                    {                                              //~v54XI~
						doxeditsw=1;                               //~v54XI~
						delopt|=LCDEL_BYDELNXALL;	//do editxline later//~v54XI~
                    }                                              //~v54XI~
                    rc=lcmddel(Ppcw,plh1,plh2,1,0,delopt);//1line del,no csr set,not lcmd//~v54XI~
                    if (rc)                                        //~v0hqI~
                        return rc;                                 //~v0hqI~
                    if (plh==Pplh2) //reached to next of end plh   //~v0icI~
                        break;                                     //~v0icI~
                    plh=plhprev;                                   //~v0hqI~
                    plh1=0;                                        //~v0hqI~
                }                                                  //~v0hqI~
            plh=UGETQNEXT(plh);                                    //~v0hqI~
        }//all plh                                                 //~v0hqI~
		if (doxeditsw)                                             //~v54XI~
			lcmdexcfromxall2(Ppcw,0,0);	//update excluded counter all//~v54XI~
    }//switch                                                      //~v0hqI~
    UPCTRREQ(Ppfh);         //write at save                        //~v0hqI~
    if (plh1st)                                                    //~v0hqI~
		filesetmultdraw(Ppcw);                                     //~v0hqI~
    uerrmsg("%d line deleted",                                     //~v0hqI~
    		"%d 行削除",                                           //~v0hqI~
            delctr);                                               //~v0hqI~
	return 0;                                                      //~v0hqI~
}//filedrop                                                        //~v0hqI~
                                                                   //~v0ifI~
//**************************************************************** //~v0ifI~
//* function key change by edit cmd                                //~v0ifI~
//* parm1 :pcw                                                     //~v0ifI~
//* parm2 :option  '2':key cmd,'3':key and func, '4':func and key  //~v0imR~
//* retrn:rc                                                       //~v0ifI~
//**************************************************************** //~v0ifI~
int filefk(PUCLIENTWE Ppcw,int Popt)                               //~v0imR~
{                                                                  //~v0ifI~
static UCHAR *Sfkhdr[4]={                                          //~v0imR~
//  			"*** Top of Fn-cmd List ",                         //~v48fR~
//  			"*** Top of Short-Cut Key List ; sc(enter)= ",     //~v67CR~
//  			"*** Top of Short-Cut-Key/Alias-Cmd List ; sc(enter)= ",//~vbvsR~
//              "*** Top of Key Assignment List ",                 //~vbvsR~
//              "*** Top of Key and Function List"                 //~vbvsR~
    			"********** Top of Short-Cut-Key/Alias-Cmd List ; sc(enter)= ",//~vbvsI~
                "********** Top of Key Assignment List ",          //~vbvsI~
                "********** Top of Key and Function List"          //~vbvsI~
                ,0                                                 //~v54XI~
                       };                                          //~v0imI~
static UCHAR *Sfktrailer[4]={                                      //~v0imR~
//  			"*** End of Fn-cmd List",                          //~v48fR~
//    			"*** End of Short-Cut Key List ; sc(query)= ",     //~v67CR~
//    			"*** End of Short-Cut-Key/Alias-Cmd List ; sc(query)= ",//~vbvsR~
//  			"*** End of Key Assignment List ",                 //~vbvsR~
//  			"*** End of Key and Function List "                //~vbvsR~
      			"********** End of Short-Cut-Key/Alias-Cmd List ; sc(query)= ",//~vbvsI~
    			"********** End of Key Assignment List ",          //~vbvsI~
    			"********** End of Key and Function List "         //~vbvsI~
                ,0                                                 //~v54XI~
                       };                                          //~v0imI~
	PUCLIENTWE 	pcw;                                               //~v0ifI~
	PUFILEH		pfh;                                               //~v0ifI~
	PULINEH    	plh,plht;                                          //~v0ihR~
	UQUEH      *pqh;                                               //~v0ifI~
	UCHAR fnm[FKF_OPTFNM_OPTPOS+2];                                //~v0imI~
    int rc;                                                        //~v0ifI~
    int protlen=0;                                                   //~v0imI~//~vafcR~
    UCHAR *ph,*pt;                                                 //~v0imI~
    UCHAR sckeynm1[32];	//"A+"(2)+size of KTnamee+space+null       //~v505R~
    UCHAR sckeynm2[32];	//"A+"(2)+size of KTnamee+space+null       //~v505R~
	FUNCTBL *pft1,*pft2;                                           //~v505R~
    char *pc;                                                      //~v505I~
    USHORT keycode;                                                //~v505R~
    int len;                                                       //~v505I~
    int binopt;                                                    //~vbvsI~
//*****************                                                //~v0ifI~
	pft1=functblsrch(FUNCID_SHORTCUT);                             //~v505I~
	pft2=functblsrch(FUNCID_SHORTCUTQUERY);                        //~v505I~
    *sckeynm1=0;                                                   //~v505I~
    *sckeynm2=0;                                                   //~v505I~
    if (pft1)                                                      //~v505I~
    {                                                              //~v505I~
    	keycode=pft1->FTkey[0];                                    //~v505I~
        pc=kbdgetname(keycode,0);	//get keyname                  //~v505I~
        len=(int)strlen(pc);                                       //~v505I~
        memcpy(sckeynm1,pc,(UINT)len);                             //~v505R~
        *(sckeynm1+len++)=' ';                                     //~v505I~
        *(sckeynm1+len)=0;                                         //~v505I~
    }                                                              //~v505I~
    if (pft2)                                                      //~v505I~
    {                                                              //~v505I~
    	keycode=pft2->FTkey[0];                                    //~v505I~
        pc=kbdgetname(keycode,0);	//get keyname                  //~v505I~
        len=(int)strlen(pc);                                       //~v505I~
        memcpy(sckeynm2,pc,(UINT)len);                             //~v505I~
        *(sckeynm2+len++)=' ';                                     //~v505I~
        *(sckeynm2+len)=0;                                         //~v505I~
    }                                                              //~v505I~
                                                                   //~v505I~
	strcpy(fnm,FKF_OPTFNM);                                        //~v0imI~
    *(fnm+FKF_OPTFNM_OPTPOS)=(UCHAR)Popt;                          //~v0imR~
    *(fnm+FKF_OPTFNM_OPTPOS+1)=0;                                  //~v0imI~
	Ppcw->UCWparm=fnm;                                             //~v0imM~
	if (rc=func_edit_file3(Ppcw,Popt),rc)	//parm is file name only//~v0imR~
    	return rc;                                                 //~v0ifI~
	pcw=scrgetcw(0);	//active client                            //~v0ifI~
    pfh=((PUFILEC)(pcw->UCWpfc))->UFCpfh;                          //~v0ifI~
    if (UGETQCTR(&pfh->UFHlineque)>2)	//re-display               //~v0j9I~
    	return 0;                                                  //~v0j9I~
    UTRACEP("%s:FHtype=%d\n",UTT,pfh->UFHtype);                    //~vbvsR~
    ph=Sfkhdr[Popt-FILEFK_OPTKCMD];                                //~v0jaR~
    pt=Sfktrailer[Popt-FILEFK_OPTKCMD];                            //~v0jaR~
    switch (Popt)                                                  //~v0imI~
    {                                                              //~v0imI~
    case FILEFK_OPTKCMD:                                           //~v0jaR~
		pfh->UFHlrecl =FKF_LRECL1;                                 //~v0imR~
        pfh->UFHmergin=FKF_LRECL1;                                 //~v0imR~
    	protlen=FKF_PROTLEN1;                                      //~v0imI~
        pcw->UCWmenuopt=PANMOPARMFK_KCMD;   //0.1 Fn cmd           //~v0jiI~
    	break;                                                     //~v0imI~
    case FILEFK_OPTKLIST:                                          //~v0jaR~
		pfh->UFHlrecl =FKF_LRECL2;                                 //~v0imR~
        pfh->UFHmergin=FKF_MARGIN2;                                //~v0imR~
    	protlen=FKF_PROTLEN2;                                      //~v0imI~
        if (SswByUTF8)                                             //~vbvbI~
    		UCBITON(pfh->UFHflag8,UFHF8UTF8); //0.3                //~vbvbR~
    	break;                                                     //~v0imI~
    case FILEFK_OPTFKEY:                                           //~v0jaR~
		pfh->UFHlrecl =FKF_LRECL3;                                 //~v0imR~
        pfh->UFHmergin=FKF_MARGIN3;                                //~v0imR~
	    UCBITON(pfh->UFHflag2,UFHF2MERGIN); 	//protect mergin   //~v0imI~
        if (SswByUTF8)                                             //~vbvbI~
	    	UCBITON(pfh->UFHflag8,UFHF8UTF8); //0.3                //~vbvbR~
    	protlen=FKF_PROTLEN3;                                      //~v0imR~
        pcw->UCWmenuopt=PANMOPARMFK_FKEY;                          //~v0jaR~
    	break;                                                     //~v0imI~
//  case FILEFK_OPT05:                                             //~v0iwR~
//  	pfh->UFHlrecl =FKF_LRECL4;                                 //~v0iwR~
//      pfh->UFHmergin=FKF_MARGIN4;                                //~v0iwR~
//      UCBITON(pfh->UFHflag2,UFHF2MERGIN); 	//protect mergin   //~v0iwR~
//  	protlen=FKF_PROTLEN4;                                      //~v0iwR~
//  	break;                                                     //~v0iwR~
	}                                                              //~v0imI~
    UCBITON(pfh->UFHflag11,UFHF11FILEFK);                          //~va6rI~
    pfh->UFHprotlen=(UCHAR)protlen;                                //~v0imR~
	pqh=&pfh->UFHlineque;                                          //~v0ifI~
	plht=UGETQTOP(pqh);                                            //~v0ihR~
    UCBITON(plht->ULHflag4,ULHF4PROTLINE);	//protected(change line attr)//~v0ihR~
	memcpy(plht->ULHdata,ph,strlen(ph));	//except last null     //~v0imR~
    if (Popt==FILEFK_OPTKCMD)                                      //~v505I~
		memcpy(plht->ULHdata+strlen(ph),sckeynm1,strlen(sckeynm1));	//except last null//~v505R~
	plh=UGETQEND(pqh);                                             //~v0ifI~
    UCBITON(plh->ULHflag4,ULHF4PROTLINE);	//protected(change line attr)//~v0ifR~
	memcpy(plh->ULHdata,pt,strlen(pt));	//except last null         //~v0imR~
    if (Popt==FILEFK_OPTKCMD)                                      //~v505I~
		memcpy(plh->ULHdata+strlen(pt),sckeynm2,strlen(sckeynm2));	//except last null//~v505R~
    if (Popt==FILEFK_OPTFKEY)                                      //~v705I~
		funct2getfnm(plh->ULHdata+strlen(pt),50);	//set linech filename max area size is 50 byte//~v705I~
    if (Popt==FILEFK_OPTFKEY)                                      //~v0jaR~
//  ||  Popt==FILEFK_OPT05)                                        //~v0iwR~
		rc=filefkctlineft(pfh,plht,Popt);                          //~v0imR~
    else                                                           //~v0imI~
    {                                                              //~v48fI~
		rc=filefkctline(pfh,plht,Popt);                            //~v0imR~
        if (!rc)                                                   //~v48fI~
            if (Popt==FILEFK_OPTKCMD)                              //~v48fI~
				rc=filefkctlineshortcut(pfh);                      //~v48fI~
    }                                                              //~v48fI~
	plh->ULHlinenor=((PULINEH)UGETQPREV(plh))->ULHlinenor+1;       //~v0ihI~
    binopt=FCU8EO_IE;                                              //~vbvsI~
    filechkutf8encoding(0,Ppcw,binopt,pfh);	//chk each line utf8 code(IE mode)//~vbvsI~
    filesetlocaleid(pfh);    //set locale id on hdr line           //~vbvsI~
    return rc;                                                     //~v0imR~
}//filefk                                                          //~v0ifI~
                                                                   //~v0ifI~
//**************************************************************** //~v0ihI~
//* function key line data setup     0.1 & 0.3                     //~v0ihI~//~vbvbR~
//* parm1 :pfh                                                     //~v0imR~
//* parm2 :plh to enq after                                        //~v0imR~
//* parm3 :option type '1'(Fn-cmd)/'3'(Key and Func)               //~v48fR~
//* retrn:rc UALLOC_FAILED                                         //~v0ihR~
//**************************************************************** //~v0ihI~
int filefkctline(PUFILEH Ppfh,PULINEH Pplh,int Popt)               //~v0imR~
{                                                                  //~v0ihI~
    PFKCTT  pfkctt;                                                //~v0ihR~
    PFKCT   pfkct;                                                 //~v0ihI~
    KEYTBL  *pkt;                                                  //~v0ihI~
    FUNCTBL *pft;                                                  //~v0ihM~
    PULINEH plh,plhprev;                                           //~v0ihI~
    UCHAR *pc;                                                     //~v0ihR~
    UCHAR keyline[FKF_LRECL1],delm;                                //~v0imR~
    int   len,lrecl,rc,shiftid,protlen,lreclmax;                   //~v0imR~
    int   mergin;                                                  //~v0imI~
    int ii;                                                        //~v0j8R~
    int lchlen;                                                    //~v705I~
    int u8len;                                                     //~vbvbI~
    int swNotJP;                                                   //~vbvfI~
//*****************                                                //~v0ihI~
    swNotJP=XE_NOT_ISDBCSJ_OR_N9();                                //~vbvfI~
    protlen=Ppfh->UFHprotlen;                                      //~v0imR~
    lreclmax=Ppfh->UFHlrecl;                                       //~v0imI~
    mergin=Ppfh->UFHmergin;                                        //~v0imI~
    if (rc=kbdgetfkct(&pfkctt),rc)                                 //~v0ihR~
    	return rc;                                                 //~v0ihI~
	pfkct=pfkctt->FKCTTpfkct;                                      //~v0ihR~
	plhprev=Pplh;                                                  //~v0ihR~
 if (Popt==FILEFK_OPTKCMD)                                         //+vbvwI~
 {                                                                 //+vbvwI~
  if (swNotJP)                                                     //~vbvwI~
	putComment(0,ScommentUC,&plhprev);                               //~vbvvI~//~vbvwR~
  else                                                             //~vbvwI~
  	putComment(0,ScommentUC_JP,&plhprev);                          //~vbvwR~
 }                                                                 //+vbvwI~
//  for (;;pfkct++)                                                //~v0j8R~
    for (ii=(int)pfkctt->FKCTTentno;ii;pfkct++,ii--)               //~v0j8I~
    {                                                              //~v0ihI~
        if (!(pkt=pfkct->FKCTpkt))                                 //~v0j8R~
        	break;                                                 //~v0j8R~
    	pft=pfkct->FKCTpft_pcmd;                                   //~v0ihR~
        shiftid=pfkct->FKCTshift;                                  //~v0ihI~
        UTRACEP("%s:FTnamee=%s,FKCTkey=x%x,FKCTshift=%d,FTnamee=%s\n",UTT,pft->FTnamee,pfkct->FKCTkey,shiftid,pkt->KTnamee);//~vbvwR~
       	memset(keyline,' ',(UINT)lreclmax);                        //~v0imR~
#ifndef KKK                                                        //~vb50I~
  	  	if (UCBITCHK(pfkct->FKCTflag,FKCTFSHIFTAC))	//S+A,S+C      //~vb50R~
      	{                                                          //~vb50R~
        	keyline[0]=*Gkeyshiftname[1];                          //~vb50R~
         	keyline[1]='+';                                        //~vb50R~
      	}                                                          //~vb50I~
        if (shiftid)                                               //~vb50I~
        {                                                          //~vb50I~
            keyline[2]=*Gkeyshiftname[shiftid];                    //~vb50I~
            keyline[3]='+';                                        //~vb50I~
        }                                                          //~vb50I~
        pc=pkt->KTnamee;                                           //~vb50I~
        len=(int)strlen(pc);                                       //~vb50I~
        if (len>protlen-5)                                         //~vb50I~
            len=protlen-5;                                         //~vb50I~
        memcpy(keyline+4,pc,(UINT)len);                            //~vb50I~
#else                                                              //~vb50I~
        if (shiftid)                                               //~v0ihR~
        {                                                          //~v0ihI~
            keyline[0]=*Gkeyshiftname[shiftid];                    //~v0ihR~
            keyline[1]='+';                                        //~v0ihI~
        }                                                          //~v0ihI~
        pc=pkt->KTnamee;                                           //~v0ihR~
        len=(int)strlen(pc);                                       //~v0ihI~
        if (len>protlen-3)                                         //~v0imR~
            len=protlen-3;                                         //~v0imR~
        memcpy(keyline+2,pc,(UINT)len);                            //~v0ihI~
#endif                                                             //~vb50M~
        delm=':';                                                  //~v0imI~
        if (UCBITCHK(pfkct->FKCTflag,FKCTFFIX))                    //~v0imI~
    	    delm='*';                                              //~v0imI~
        else                                                       //~v0imI~
  	      if (UCBITCHK(pfkct->FKCTflag,FKCTFSHIFT))                //~v0imR~
    	    	delm=';';                                          //~v0imR~
    	keyline[protlen-1]=delm;                                   //~v0imR~
        lrecl=protlen;                                             //~v0imR~
        UTRACEP("%s:FKCTflag=0x%x,Popt=%c,pft=%p\n",UTT,pfkct->FKCTflag,Popt,pft);//~vbvbR~//~vbvwR~
//****                                                             //~v0ihI~
        if (UCBITCHK(pfkct->FKCTflag,FKCTFPFT|FKCTFNONPFK))	//func not ass to pfk//~v0imI~
        {                                                          //~v0ihR~
            if (Popt==FILEFK_OPTKCMD)                              //~v0jaR~
            {                                                      //~vbvwI~
		        UTRACEP("%s:continue by Popt=1\n",UTT);            //~vbvwI~
                continue;   //cmd line only when opt=0.2           //~v0imI~
            }                                                      //~vbvwI~
            if (pft)	//assigned                                 //~v0ihI~
            {                                                      //~v0ihI~
                pc=pft->FTcmd;                                     //~v0ihR~
                len=(int)strlen(pc);                               //~v0ihR~
                memcpy(keyline+lrecl,pc,(UINT)len);                //~v0ihR~
//              lrecl+=sizeof(pft->FTcmd);                         //~v0iwI~//~vb2DR~
                lrecl+=(int)sizeof(pft->FTcmd);                    //~vb2DI~
                *(keyline+lrecl-1)='/';                            //~v0iwR~
                pc=pft->FTcmda;                                    //~v0iwI~
                len=(int)strlen(pc);                               //~v0iwI~
                memcpy(keyline+lrecl,pc,(UINT)len);                //~v0iwI~
                memcpy(keyline+lrecl+sizeof(pft->FTcmda),"## ",2); //~v0iwR~
//              lrecl+=sizeof(pft->FTcmda)+3;                      //~v0iwR~//~vb2DR~
                lrecl+=(int)sizeof(pft->FTcmda)+3;                 //~vb2DI~
                pc=pft->FTnamee;                                   //~v0ihR~
                len=(int)strlen(pc);                               //~v0ihR~
//            if (SswByUTF8 && pft->FTfuncid>FUNCID_GRAPHCHAR)     //~vbvdR~
//  			u8len=funct2printlcdata(0,keyline+lrecl,pc,len);   //~vbvdR~
//            else                                                 //~vbvdR~
                memcpy(keyline+lrecl,pc,(UINT)len);                //~v0ihR~
//      		UTRACED("keyline",keyline,sizeof(keyline));        //~vbvoR~
                if (pft->FTfuncid>FUNCID_GRAPHCHAR                 //~v705R~
//              &&  UCBITCHK(pft->FTflag,FTFLINECHSET))	//linech file setup//~v705R~//~vbviR~
                &&  UCBITCHK(pft->FTflag2,FTF2LINECHSET))	//linech file setup//~vbviI~
                {                                                  //~v705R~
//            	    funct2getlinechstr(0,pft,keyline+lrecl+FTNAMEGRAPHHEXPOS);//~v705R~//~vb2AR~
//            	    funct2getlinechstr(0,pft,keyline+lrecl+FTNAMEGRAPHHEXPOS,(int)sizeof(keyline)-(lrecl+FTNAMEGRAPHHEXPOS));//~vb2AI~//~vbvdR~
              	    funct2getlinechstr(0|SswByUTF8,pft,keyline+lrecl+FTNAMEGRAPHHEXPOS,(int)sizeof(keyline)-(lrecl+FTNAMEGRAPHHEXPOS));//~vbvdR~
                }                                                  //~v705R~
//              lrecl+=2+sizeof(pft->FTnamee);                     //~v0imR~//~vb2DR~
                lrecl+=2+(int)sizeof(pft->FTnamee);                //~vb2DI~
        		UTRACEP("%s:FTnamee=%s\n",UTT,pft->FTnamee);      //~vbvbR~//~vbvdR~
//      		UTRACED("keyline",keyline,sizeof(keyline));        //~vbvoR~
              if (pft->FTfuncid>FUNCID_GRAPHCHAR                   //~v705I~
//            &&  UCBITCHK(pft->FTflag,FTFLINECHSET))	//linech file setup//~v705R~//~vbviR~
              &&  UCBITCHK(pft->FTflag2,FTF2LINECHSET))	//linech file setup//~vbviI~
              {                                                    //~v705I~
//            	lchlen=funct2getlinechstr(1,pft,keyline+lrecl+2);  //~v705R~//~vb2AR~
//            	lchlen=funct2getlinechstr(1,pft,keyline+lrecl+2,(int)sizeof(keyline)-(lrecl+2));//~vb2AI~//~vbvbR~
              	lchlen=funct2getlinechstr(1|SswByUTF8,pft,keyline+lrecl+2,(int)sizeof(keyline)-(lrecl+2));//~vbvbI~
//            	lrecl+=2+max(lchlen,sizeof(pft->FTnamej));         //~v705I~//~vb2DR~
              	lrecl+=2+max(lchlen,(int)sizeof(pft->FTnamej));    //~vb2DI~
//      		UTRACED("GRAPHCHAR & FTF2LINECHSET keyline",keyline,sizeof(keyline));//~vbvbR~//~vbvoR~
              }                                                    //~v705I~
              else                                                 //~v705I~
              {                                                    //~v705I~
//#ifdef LNX                                                         //~v44uR~//~vbvfR~
////              if ((Gunxflag & (GUNX_EUC|GUNX_KON))==(GUNX_EUC|GUNX_KON)) //under kon//~v79zR~//~vbvfR~
//                if (XE_ISDBCSKONJ())    //Japanese                 //~v79zR~//~vbvfR~
//#else                                                              //~v44uR~//~vbvfR~
//                if (UCBITCHK(Gscrstatus,GSCRSDBCS))                //~v0ihR~//~vbvfR~
//#endif                                                             //~v44uR~//~vbvfR~
                if (!swNotJP)                                      //~vbvfI~
                {                                                  //~v0ihR~
                    pc=pft->FTnamej;                               //~v0ihR~
                    len=(int)strlen(pc);                           //~v0ihR~
                  if (SswByUTF8)                                   //~vbvbI~
                  {                                                //~vbvbI~
                    u8len=cvFuncNameS2F(keyline+lrecl+2,pc,len);   //~vbvbM~
                    lrecl+=2+u8len;                                //~vbvbM~
                  }                                                //~vbvbI~
                  else                                             //~vbvbI~
                  {                                                //~vbvbI~
                    memcpy(keyline+lrecl+2,pc,(UINT)len);          //~v0ihR~
//                  lrecl+=2+sizeof(pft->FTnamej);                 //~v0ihR~//~vb2DR~
                    lrecl+=2+(int)sizeof(pft->FTnamej);            //~vb2DI~
                  }                                                //~vbvbI~
                }                                                  //~v0ihR~
//      		UTRACED("!(GRAPHCHAR & FTF2LINECHSET) keyline",keyline,sizeof(keyline));//~vbvbR~//~vbvoR~
              }//no linech file                                    //~v705I~
            }                                                      //~v0ihI~
        }                                                          //~v0ihR~
        else	//may have cmd                                     //~v0ihI~
        {                                                          //~v0ihI~
        	if (len=pfkct->FKCTcmdlen,len)                         //~v0ihR~
            {                                                      //~v0ihI~
	        	pc=pfkct->FKCTpft_pcmd;                            //~v0ihR~
                if (Popt==FILEFK_OPTKCMD)                          //~v0jaR~
                {                                                  //~v0imI~
                    if (len>lreclmax-protlen)                      //~v0imR~
                        len=lreclmax-protlen;                      //~v0imR~
                    memcpy(keyline+protlen,pc,(UINT)len);          //~v0imR~
                    lrecl=protlen+len;                             //~v0imR~
                }                                                  //~v0imI~
                else                                               //~v0imI~
                {                                                  //~v0imI~
                    if (len>lreclmax-mergin-4)                     //~v0iwR~
                        len=lreclmax-mergin-4;                     //~v0iwR~
                    memcpy(keyline+mergin+1,";; ",3);              //~v0iwR~
                    memcpy(keyline+mergin+4,pc,(UINT)len);         //~v0iwR~
                    lrecl=mergin+4+len;                            //~v0iwR~
                }                                                  //~v0imI~
            }                                                      //~v0ihI~
//      	UTRACED("FKCTFOFT and FKCTFNOPFK off keyline",keyline,sizeof(keyline));//~vbvoR~
		}                                                          //~v0ihI~
        if (Popt==FILEFK_OPTKLIST)                                 //~v0jaR~
        {                                                          //~v0iwI~
            if (*(keyline+protlen)==' ')                           //~v0imI~
            {                                                      //~v0imI~
                memset(keyline+protlen,NOCMDID,3);                 //~v0imR~
                if (lrecl==protlen)                                //~v0imI~
                	lrecl+=3;                                      //~v0imI~
			}                                                      //~v0imI~
            if (*(keyline+protlen+4)==' ')                         //~v0iwI~
            {                                                      //~v0iwI~
                *(keyline+protlen+3)='/';                          //~v0iwI~
                memset(keyline+protlen+4,NOCMDID,3);               //~v0iwI~
                if (lrecl==protlen+3)                              //~v0iwI~
                	lrecl+=4;                                      //~v0iwI~
			}                                                      //~v0iwI~
        }                                                          //~v0iwI~
        plh=filealloclh(ULHTDATA,lrecl);                           //~v0ihR~
        UALLOCCHK(plh,UALLOC_FAILED);//return when storage shortage//~v0ihI~
        UENQENT(UQUE_AFT,plhprev,plh);                             //~v0ihI~
        plh->ULHlinenor=plhprev->ULHlinenor+1;                     //~v0ihM~
        memcpy(plh->ULHdata,keyline,(UINT)lrecl);                  //~v0ihR~
//      UTRACED("ULHdata",plh->ULHdata,lrecl);               //~vbvbI~//~vbvoR~
        plhprev=plh;                                               //~v0ihM~
    }                                                              //~v0ihR~
    return 0;                                                      //~v0ihR~
}//filefkctline                                                     //~v0ihR~//~vbvwR~
//**************************************************************** //~v48fI~
//* function key line data setup for sgortcut key                  //~v48fI~
//* parm1 :pfh                                                     //~v48fI~
//* retrn:rc UALLOC_FAILED                                         //~v48fI~
//**************************************************************** //~v48fI~
int filefkctlineshortcut(PUFILEH Ppfh)                             //~v48fI~
{                                                                  //~v48fI~
	UQUEH   *pqh;                                                  //~v48fI~
    PSCKT   psckt;                                                 //~v48fI~
    PULINEH plh,plhprev;                                           //~v48fI~
    UCHAR *pc;                                                     //~v48fI~
    UCHAR keyline[FKF_LRECL1];                                     //~v48fI~
    int   ii,len,lrecl,protlen,lreclmax;                           //~v48fR~
    int rc;                                                        //~v67CI~
    int swNotJP;                                                   //~vbvwI~
//*****************                                                //~v48fI~
    protlen=Ppfh->UFHprotlen;                                      //~v48fI~
    lreclmax=Ppfh->UFHlrecl;                                       //~v48fI~
	pqh=&(Ppfh->UFHlineque);                                       //~v48fR~
	plh=(PULINEH)UGETQEND(pqh);                                    //~v48fR~
	plhprev=UGETQPREV(plh);     //add after this                   //~v48fI~
    swNotJP=XE_NOT_ISDBCSJ_OR_N9();                                //~vbvwI~
  if (swNotJP)                                                     //~vbvwI~
	rc=putComment(0,ScommentSC,&plhprev);                            //~vbvoR~//~vbvwR~
  else                                                             //~vbvwI~
	rc=putComment(0,ScommentSC_JP,&plhprev);                       //~vbvwR~
    if (rc)	//UALLOC_FAILED                                        //~vbvoI~
    	return rc;                                                 //~vbvoI~
    for (ii=0,psckt=Gkbdsckt;ii<SCKTMAXNO;ii++,psckt++)            //~v48fI~
    {                                                              //~v48fI~
        if (!isalnum(SCKTTOP+ii))                                  //~v48fR~
        	continue;                                              //~v48fI~
       	memset(keyline,' ',(UINT)lreclmax);                        //~v48fI~
#ifndef KKK                                                        //~vb50I~
        sprintf(keyline,"%s%c   :",SHORTCUTID,SCKTTOP+ii);         //~vb50I~
#else                                                              //~vb50I~
        sprintf(keyline,"%s%c :",SHORTCUTID,SCKTTOP+ii);           //~v48fR~
#endif                                                             //~vb50I~
    	keyline[protlen]=' ';                                      //~v48fI~
        lrecl=protlen;                                             //~v48fI~
        if (len=psckt->SCKTcmdlen,len)                             //~v48fI~
        {                                                          //~v48fI~
            pc=psckt->SCKTcmd;                                     //~v48fI~
            if (len>lreclmax-protlen)                              //~v48fI~
                len=lreclmax-protlen;                              //~v48fI~
            memcpy(keyline+protlen,pc,(UINT)len);                  //~v48fI~
            lrecl=protlen+len;                                     //~v48fI~
        }                                                          //~v48fI~
        plh=filealloclh(ULHTDATA,lrecl);                           //~v48fI~
        UALLOCCHK(plh,UALLOC_FAILED);//return when storage shortage//~v48fI~
        UENQENT(UQUE_AFT,plhprev,plh);                             //~v48fI~
        plh->ULHlinenor=plhprev->ULHlinenor+1;                     //~v48fI~
        memcpy(plh->ULHdata,keyline,(UINT)lrecl);                  //~v48fI~
        plhprev=plh;                                               //~v48fI~
    }                                                              //~v48fI~
	if (rc=filefkctlinealias(Ppfh),rc)                             //~v67CR~
    	return rc;                                                 //~v67CI~
    return 0;                                                      //~v48fI~
}//kbdfkctlineshortcut                                             //~v48fR~
//**************************************************************** //~v0ihI~
//* function key change by edit cmd for Fn-cmd/KeyList  0.1        //~v0jdR~//~vbvwR~
//* parm1 :pfh                                                     //~v0imR~
//* retrn:rc UALLOC_FAILED or errline exist                        //~v0ihR~
//**************************************************************** //~v0ihI~
int filefksave(PUFILEH Ppfh)                                       //~v0ihI~
{                                                                  //~v0ihI~
	PUCLIENTWE pcw;                                                //~v0imI~
	PULINEH    	plh,plherr=0;                                      //~v0imR~
	KEYTBL     *pkt;                                               //~v0ihI~
    UCHAR keyname[FKF_PROTLEN2+1];                                 //~v0imR~
    UCHAR *pc;                                                     //~v0jeR~
    int errsw,delinssw=0,entno,rc,protlen,fkopt;                   //~v0imR~
    int cmdlen,lrecl,shift,index,ii,maxlrecl;                      //~v0imR~
    PFKCTT		pfkctt;                                            //~v0ihI~
    PFKCT		pfkct0,pfkct;                                      //~v0ihI~
    PULINEH     *plhtbl;                                           //~v0ihR~
    UQUEH   qhalctnew;                                             //~v67CI~
    int rc2;                                                       //~v67CI~
#ifndef KKK                                                        //~vb50I~
    int swSAC;                                                     //~vb50I~
#endif                                                             //~vb50I~
//*****************                                                //~v0ihI~
	pcw=Ppfh->UFHeditpcw;                                          //~v0imI~
    fkopt=Ppfh->UFHalias[FKF_OPTFNM_OPTPOS];	//0.2->'2',0.3->'3'//~v0imR~
    if (fkopt==FILEFK_OPTFKEY)                                     //~v0jaR~
//  ||  fkopt==FILEFK_OPT05)                                       //~v0iwR~
        return filefksaveft(pcw,Ppfh,fkopt);                       //~v0imR~
	kbdgetfkct(&pfkctt);                                           //~v0ihR~
    pfkct0=pfkctt->FKCTTpfkct;                                     //~v0ihI~
    if (!(entno=pfkctt->FKCTTentno))                               //~v0ihI~
    	return 0;                                                  //~v0ihI~
//  plhtbl=UALLOCC((UINT)(entno<<2),1);                            //~v0ihR~//~vb82R~
    plhtbl=UALLOCC((size_t)entno*PTRSZ,1);                         //~vb82R~
    UALLOCCHK(plhtbl,UALLOC_FAILED);                               //~v0ihI~
	plh=UGETQTOP(&Ppfh->UFHlineque);                               //~v0ihR~
    protlen=Ppfh->UFHprotlen;                                      //~v0imR~
    maxlrecl=Ppfh->UFHlrecl;                                       //~v0imI~
    *(keyname+protlen)=0;                                          //~v0imI~
    memset(&qhalctnew,0,sizeof(qhalctnew));	//temporaly queue hdr  //~v67CR~
    for (;plh;plh=UGETQNEXT(plh))                                  //~v0ihI~
    {                                                              //~v0ihI~
        errsw=0;                                                   //~v0ihI~
    	if (plh->ULHtype!=ULHTDATA)                                //~v0ihI~
        	continue;                                              //~v0ihI~
		if (UCBITCHK(plh->ULHflag4,ULHF4PROTLINE))	//protected(change line attr)//~v0ihI~
        {                                                          //~vbvmI~
//          UTRACED("protoline ULHdata=",plh->ULHdata,plh->ULHlen);//~vbvoR~
        	continue;                                              //~v0ihI~
        }                                                          //~vbvmI~
		lrecl=plh->ULHlen;                                         //~v0ihI~
        pc=plh->ULHdata;                                           //~v0imI~
		if (lrecl<protlen || lrecl>maxlrecl)                       //~v0imR~
			errsw=fileoptlreclerr();                               //~v0imI~
        else                                                       //~v0ihI~
        {	                                                       //~v0ihI~
//            if (*pc==' ')                                        //~v0jeR~
//                shift=0;                                         //~v0jeR~
//            else                                                 //~v0jeR~
//            {                                                    //~v0jeR~
//                shiftch=(UCHAR)toupper(*pc);                     //~v0jeR~
//                for (shift=1;shift<4;shift++)                    //~v0jeR~
//                    if (shiftch==*Gkeyshiftname[shift])          //~v0jeR~
//                        break;                                   //~v0jeR~
//                if (shift==4)                                    //~v0jeR~
//                {                                                //~v0jeR~
//                    filekeynameerr();                            //~v0jeR~
//                    errsw=1;                                     //~v0jeR~
//                }                                                //~v0jeR~
//            }                                                    //~v0jeR~
//            if (!errsw)                                          //~v0jeR~
//            {                                                    //~v0jeR~
               if (!memcmp(pc,ALIASID,ALIASIDSZ))                  //~v67CR~
                    errsw=filefksavealias(plh,&qhalctnew);         //~v67CR~
               else                                                //~v67CI~
               {                                                   //~v67CI~
//              memcpy(keyname,pc+2,(UINT)(protlen-2));            //~v0jeR~
                memcpy(keyname,pc,(UINT)protlen);                  //~v0jeR~
                *(keyname+protlen)=0;                              //~v0jeR~
                if (*keyname==' ')                                 //~v0ihI~
                    strcpy(keyname,keyname+strspn(keyname," "));   //~v0ihR~
                if (*keyname==':')                                 //~v0imI~
                	*(keyname+1)=0;                                //~v0imI~
                else                                               //~v0imI~
	                if (pc=strpbrk(keyname," :"),pc)               //~v0imR~
    	                *pc=0;                                     //~v0imR~
                if (!memcmp(keyname,SHORTCUTID,SHORTCUTIDSZ))      //~v48fI~
//                  errsw=filefksaveshortcut(plh,plh->ULHdata+protlen-3);//~vbvnR~
                    errsw=filefksaveshortcut(plh,plh->ULHdata); //sc,_//~vbvnR~
                else                                               //~v48fI~
//              if (kbdsrchktbyname(keyname,&pkt),!pkt) //not found//~v0jeR~
#ifndef KKK                                                        //~vb50I~
                if (swSAC=xekbdchkSAC(XEKBDCKSACO_SRCHNONSAC,keyname,&pkt,&shift),!pkt) //not found//~vb50R~
#else                                                              //~vb50I~
                if (shift=kbdsrchktbyname(keyname,&pkt),!pkt) //not found//~v0jeI~
#endif                                                             //~vb50I~
                {                                                  //~v0ihI~
                    errsw=1;                                       //~v0ihI~
            		filekeynameerr();                              //~v0ihI~
				}                                                  //~v0ihI~
                else                                               //~v0ihI~
#ifndef KKK                                                        //~vb50I~
                if ((index=kbdfkctsrch((swSAC ? KFKCSO_SHIFTAC : 0),pkt,shift))==-1)//~vb50I~
#else                                                              //~vb50I~
                if ((index=kbdfkctsrch(pkt,shift))==-1)            //~v0ihR~
#endif                                                             //~vb50I~
                {                                                  //~v0ihR~
                    uerrmsg2("FKCT destroyed-1",0);                //~v0ihR~
                    errsw=1;                                       //~v0ihR~
                }                                                  //~v0ihR~
                else                                               //~v0ihR~
                if (UCBITCHK((pfkct0+index)->FKCTflag,FKCTFPFT))   //~v0imI~
                {                                                  //~v0ihR~
                    if (fkopt==FILEFK_OPTKCMD)                     //~v0jaR~
                    {                                              //~v0imI~
                        uerrmsg2("Already assigned to other function",//~v0imR~
                                "機\x94\\キーとして割当済");       //~v0imR~
                        errsw=1;        //func assigned            //~v0imR~
                    }                                              //~v0imI~
                }                                                  //~v0ihR~
                else                                               //~v0ihR~
                if (UCBITCHK((pfkct0+index)->FKCTflag,FKCTFNONPFK))//~v0imR~
                {                                                  //~v0ihI~
                    if (fkopt==FILEFK_OPTKCMD)                     //~v0jaR~
                    {                                              //~v0imI~
                    	uerrmsg2("Not Fn-Key",                     //~v0imR~
                        	    "Fn キーのみコマンドキーとして使用可");//~v0imR~
                    	errsw=1;        //func assigned            //~v0imR~
                    }                                              //~v0imI~
                }                                                  //~v0ihI~
                else                                               //~v0ihI~
                if (plhtbl[index])                                 //~v0ihR~
                {                                                  //~v0ihR~
#ifndef KKK                                                        //~vb50R~
                	fileoptdupassign(keyname);                     //~vb50I~
#else                                                              //~vb50I~
                	fileoptdupassign();                            //~v0imI~
#endif                                                             //~vb50I~
                    errsw=1;        //dup                          //~v0ihR~
                }                                                  //~v0ihR~
                else                                               //~v0ihR~
                    plhtbl[index]=plh;                             //~v0ihR~
               }//not alias                                        //~v67CI~
//            }//errsw                                             //~v0jeR~
        }//lrecl ok                                                //~v0ihI~
        if (errsw)                                                 //~v0ihI~
        {                                                          //~v0ihI~
        	filesetlineerr(plh);	//lineno fld reverse hilight   //~v0ihI~
            if (!plherr)                                           //~v0imR~
            {                                                      //~v0imI~
            	plherr=plh;                                        //~v0imI~
                fcmdscrollpage(pcw,plherr);                        //~v0jgI~
				filesetcsr(pcw,plherr,0,0);	//set csr,fldtop       //~v0imI~
            }                                                      //~v0imI~
		}                                                          //~v0ihI~
	}//loop                                                        //~v0ihI~
    if (plherr)                                                    //~v0imR~
        rc=4;                                                      //~v0ihI~
    else                                                           //~v0ihI~
    {                                                              //~v0ihI~
//*repl cmd                                                        //~v0ihI~
        for (ii=0,pfkct=pfkct0;ii<entno;ii++,pfkct++)              //~v0ihR~
        {                                                          //~v0ihR~
            plh=plhtbl[ii];                                        //~v0ihR~
    	    UTRACEP("%s:ii=%d,plh=%p\n",UTT,ii,plh);               //~vbvwR~
            if (UCBITCHK(pfkct->FKCTflag,FKCTFPFT|FKCTFNONPFK)) //func not ass to pfk//~v0imI~
            {                                                      //~vbvwI~
                UTRACEP("%s:continue by FKCTFPFT or FKCTFNOPFK\n",UTT);//~vbvwI~
                continue;                                          //~v0imI~
            }                                                      //~vbvwI~
            if (plh)        //not deleted                          //~v0ihR~
            {                                                      //~v0imI~
    	        UTRACED("ULHdata",plh->ULHdata,plh->ULHlen);       //~vbvwI~
        		pc=plh->ULHdata;                                   //~v0imI~
                cmdlen=plh->ULHlen;                                //~v0imI~
        		cmdlen-=(int)umemrspnc(pc,' ',(UINT)cmdlen);       //~v0imR~
                cmdlen-=protlen;                                   //~v0imI~
			}                                                      //~v0imI~
            else            //deleted                              //~v0ihR~
                cmdlen=0;                                          //~v0ihR~
            if (cmdlen<=0)        //deleted   or nullified         //~v0imR~
            {                                                      //~v0ihR~
                if (pc=pfkct->FKCTpft_pcmd,pc)                     //~v0ihR~
                {                                                  //~v0ihR~
                    ufree(pc);                                     //~v0ihR~
                    pfkct->FKCTpft_pcmd=0;                         //~v0ihR~
                    delinssw=1;                                    //~v0ihR~
                }                                                  //~v0ihR~
                pfkct->FKCTcmdlen=0;                               //~v0ihR~
                continue;                                          //~v0ihR~
            }                                                      //~v0ihR~
            if (plh->ULHupctr)          //updated                  //~v0ihR~
            {                                                      //~v0ihR~
                if (pc=pfkct->FKCTpft_pcmd,pc)                     //~v0ihR~
                {                                                  //~v0ihR~
                    ufree(pc);                                     //~v0ihR~
                    pfkct->FKCTpft_pcmd=0;                         //~v0ihR~
                    pfkct->FKCTcmdlen=0;                           //~v0ihR~
                }                                                  //~v0ihR~
                else                                               //~v0ihR~
                    delinssw=1;                                    //~v0ihR~
                if (cmdlen>FKF_MAXCMDLEN)                          //~v0ihR~
                    cmdlen=FKF_MAXCMDLEN;                          //~v0ihR~
//              pc=UALLOCM((UINT)cmdlen);                          //~v48fR~
                pc=UALLOCC(1,(UINT)cmdlen+1);                      //~v48fI~
                if (!pc)                                           //~v0ihR~
                {                                                  //~v0ihI~
				    ufree(plhtbl);                                 //~v0ihR~
					return UALLOC_FAILED;                          //~v0ihR~
				}                                                  //~v0ihI~
                pfkct->FKCTpft_pcmd=pc;                            //~v0ihR~
                pfkct->FKCTcmdlen=(USHORT)cmdlen;                  //~v0ihR~
                memcpy(pc,plh->ULHdata+protlen,(UINT)cmdlen);      //~v0imR~
                *(pc+cmdlen)=0;                                    //~vbvzI~
                UTRACEP("%s:pfkct=%p,FKCTpft_pcmd=%s,FKCTkey=x%x,FKCTshift=%d,FKCTflag=x%x,KTnamee=%s,FKCTfuncid=%d\n",UTT,pfkct,pc,pfkct->FKCTkey,pfkct->FKCTshift,pfkct->FKCTflag,pfkct->FKCTpkt->KTnamee,pfkct->FKCTfuncid);//~vbvwR~
            }//updated                                             //~v0ihR~
        }//loop                                                    //~v0ihR~
//update alias cmd                                                 //~v67CI~
        if (rc2=filesetupscktalias(&qhalctnew),rc2)	//reset sckt alias entry//~v67CR~
        	return rc2;                                            //~v67CI~
        uqufree(&Sqhalct);	//remaining when err                   //~v67CI~
        Sqhalct=qhalctnew;	//reset alias tbl                      //~v67CR~
        memset(&qhalctnew,0,sizeof(qhalctnew));	//avoid free q     //~v67CR~
        if (delinssw)                                              //~v0ihR~
            kbdsetfkcmd();                                         //~v0ihR~
		uerrmsg2("Option Change Accepted",                         //~v0imI~
				 "変更受付");                                      //~v0imI~
        rc=0;                                                      //~v0ihI~
	}//no errchk                                                   //~v0ihI~
    ufree(plhtbl);                                                 //~v0ihI~
    uqufree(&qhalctnew);	//remaining when err                   //~v67CR~
    return rc;                                                     //~v0ihR~
}//filefksave                                                      //~v0ihI~
//**************************************************************** //~v48fI~
//* accept shortcut key change                                     //~v48fI~
//* parm1 :plh                                                     //~v48fI~
//* parm2 :1 byte shortcut key char start addr                     //~v48fI~
//* retrn:rc UALLOC_FAILED or errline exist                        //~v48fI~
//**************************************************************** //~v48fI~
int filefksaveshortcut(PULINEH Pplh,UCHAR *Pdata)                  //~v48fI~
{                                                                  //~v48fI~
	PSCKT  psckt;                                                  //~v48fI~
    UCHAR *pc,*newcmd;                                             //~v48fI~
    int sckey;                                                     //~v48fI~
    int cmdlen,len;                                                //~v48fI~
//*****************                                                //~v48fI~
    if (!Pplh->ULHupctr)          //updated                        //~v48fI~
    	return 0;                                                  //~v48fI~
//  sckey=*Pdata;                                                  //~vbvnR~
    sckey=*(Pdata+FKF_POS_SHORTCUTKEY);                            //~vbvnI~
    if (!isalnum(sckey))                                           //~v48fI~
    {                                                              //~v48fI~
    	uerrmsg("ShortCut Key is to be alnum",0);                  //~v48fR~
        return 4;                                                  //~v48fI~
    }                                                              //~v48fI~
    psckt=Gkbdsckt+(sckey-SCKTTOP);                                //~v48fI~
//  pc=Pdata+3;                                                    //~vbvnR~
    pc=Pdata+FKF_PROTLEN1;                                         //~vbvnI~
//  cmdlen=Pplh->ULHlen-(int)((ULONG)Pdata-(ULONG)Pplh->ULHdata)-3;//~v48fR~//~vafkR~
//  cmdlen=Pplh->ULHlen-(int)((ULPTR)Pdata-(ULPTR)Pplh->ULHdata)-3;//~vbvnR~
    cmdlen=Pplh->ULHlen-FKF_PROTLEN1;                              //~vbvnI~
    if (cmdlen>0)                                                  //~v48fI~
    {                                                              //~v48fI~
//  	len=(int)umemrspnc(pc,' ',(UINT)cmdlen);                   //~v48fI~//~va0aR~
  	 	len=(int)umemspnc(pc,' ',(UINT)cmdlen);                    //~va0aI~
    	cmdlen-=len;                                               //~v48fI~
	    pc+=len;                                                   //~v48fI~
    }                                                              //~v48fI~
    newcmd=pc;                                                     //~v48fI~
    if (cmdlen<0)                                                  //~v48fI~
    	cmdlen=0;                                                  //~v48fI~
    if (cmdlen>FKF_MAXCMDLEN)                                      //~v48fI~
        cmdlen=FKF_MAXCMDLEN;                                      //~v48fI~
                                                                   //~v48fI~
    if (pc=psckt->SCKTcmd,pc)                                      //~v48fI~
    {                                                              //~v48fI~
        ufree(pc);                                                 //~v48fI~
        psckt->SCKTcmd=0;                                          //~v48fI~
    }                                                              //~v48fI~
    psckt->SCKTcmdlen=(USHORT)cmdlen;                              //~v48fR~
    if(cmdlen)                                                     //~v48fI~
    {                                                              //~v48fI~
        pc=UALLOCC(1,(UINT)cmdlen+1);                              //~v48fI~
        UALLOCCHK(pc,UALLOC_FAILED);//return when storage shortage //~v48fI~
    	psckt->SCKTcmd=pc;                                         //~v48fI~
        memcpy(pc,newcmd,(UINT)cmdlen);                            //~v48fI~
    }                                                              //~v48fI~
    return 0;                                                      //~v48fI~
}//filefksaveshortcut                                              //~v48fI~
//**************************************************************** //~v0imM~
//* key assign line data setup;list 0.2                            //~v705R~
//* parm1 :pfh                                                     //~v0imM~
//* parm2 :plh to enq after                                        //~v0imM~
//* retrn:rc UALLOC_FAILED                                         //~v0imM~
//**************************************************************** //~v0imM~
int filefkctlineft(PUFILEH Ppfh,PULINEH Pplh,int Popt)             //~v0imR~
{                                                                  //~v0imM~
    WORKFTHDR wfth;                                                //~v0imR~
    PWORKFT   pwft;                                                //~v0imR~
    KEYTBL  *pkt,*pkt2;                                            //~v0imR~
    FUNCTBL *pft;                                                  //~v0imM~
    PULINEH plh,plhprev;                                           //~v0imM~
    UCHAR *pc,*pcl,flag;                                           //~v0imR~
    UCHAR keyline[MAXCOLUMN+1],delm;                               //~v0imR~
    int   len,lrecl,rc,shiftid=0,ii,entno/*cmdonlysw*/;              //~v756R~//~vafcR~
    USHORT key;                                                    //~v0imI~
    int lchlen;                                                    //~v705I~
#ifndef KKK                                                        //~vb50I~
    int swshiftAC;                                                 //~vb50I~
#endif                                                             //~vb50I~
	int u8len;                                                     //~vbvbI~
    int sw1stGC=0;                                                 //~vbvbI~
    int expandedByUtf8=0;                                          //~vbvdI~
    int swNotJP;                                                   //~vbvfR~
    int swDeleted;                                                 //~vbvhI~
//*****************                                                //~v0imM~
	if (rc=funcgetwfth(1,&wfth),rc)	//get full copy of work funct  //~v0imR~
    	return rc;                                                 //~v0imM~
    swNotJP=XE_NOT_ISDBCSJ_OR_N9();                                //~vbvfR~
    pwft=wfth.WFTHpwft;                                            //~v0imI~
    entno=wfth.WFTHentno;                                          //~v0imR~
	plhprev=Pplh;                                                  //~v0imM~
    *(keyline+sizeof(keyline)-1)=0;                                //~v0imI~
    pft=Gfunctbl;                                                  //~v0imI~
	for (;entno;entno--,pwft++,pft++)                              //~v0imR~
    {                                                              //~v0imM~
//      if (pft->FTfuncid==FUNCID_REDO)                            //~vafgR~
//          continue;                                              //~vafgR~
//      if (pft->FTfuncid==FUNCID_NULLCHAR)                        //~vafgR~
//          continue;                                              //~vafgR~
//      if (pft->FTfuncid>=FUNCID_GRAPHCHAR)                       //~v0iwR~
//          if (Popt==FILEFK_OPT05)                                //~v0iwR~
//              continue;                                          //~v0iwR~
        if (pft->FTfuncid>FUNCID_GRAPHCHAR && !sw1stGC)   //output comment line//~vbvbI~
        {                                                          //~vbvbI~
            sw1stGC=1;                                             //~vbvbI~
//            for (ii=0;;ii++)                                     //~vbvoR~
//            {                                                    //~vbvoR~
//                if (!ScommentGC[ii])                             //~vbvoR~
//                    break;                                       //~vbvoR~
//                lrecl=(int)strlen(ScommentGC[ii]);               //~vbvoR~
//                memcpy(keyline,ScommentGC[ii],(UINT)lrecl);      //~vbvoR~
//                plh=filealloclh(ULHTDATA,lrecl);                 //~vbvoR~
//                UALLOCCHK(plh,UALLOC_FAILED);//return when storage shortage//~vbvoR~
//                UENQENT(UQUE_AFT,plhprev,plh);                   //~vbvoR~
//                plh->ULHlinenor=plhprev->ULHlinenor+1;           //~vbvoR~
//                memcpy(plh->ULHdata,keyline,(UINT)lrecl);        //~vbvoR~
//                UTRACED("ULHdata",plh->ULHdata,lrecl);       //~vbvbR~//~vbvoR~
//                UCBITON(plh->ULHflag4,ULHF4PROTLINE);   //protected(change line attr)//~vbvoR~
//                plhprev=plh;                                     //~vbvoR~
//            }                                                    //~vbvoR~
          if (swNotJP)                                             //~vbvwI~
			rc=putComment(0,ScommentGC,&plhprev);                    //~vbvoI~//~vbvwR~
          else                                                     //~vbvwI~
			rc=putComment(1,ScommentGC_JP,&plhprev);               //~vbvwR~
    		if (rc)	//UALLOC_FAILED                                //~vbvoI~
    			return rc;                                         //~vbvoI~
//          continue;                                              //~vbvbI~//~vbvfR~
        }                                                          //~vbvbI~
        if (pft->FTfuncid>FUNCID_GRAPHCHAR)                        //~vbvfR~
        {                                                          //~vbvfR~
//          UTRACEP("%s,Gotherstatus=0x%x, NOT_ISDBCS_OR_Np=%d\n",UTT,Gotherstatus,XE_NOT_ISDBCSJ_OR_N9());//~vbvfR~
            if (!swNotJP && (pft->FTflag & FTFEONLY))              //~vbvfR~
            {                                                      //~vbvfR~
                continue;                                          //~vbvfR~
            }                                                      //~vbvfR~
            if (swNotJP && (pft->FTflag & FTFJONLY))               //~vbvfR~
            {                                                      //~vbvfR~
                continue;                                          //~vbvfR~
            }                                                      //~vbvfR~
        }                                                          //~vbvfR~
		for (ii=0;ii<FTMAXKEY;ii++)	//all asigned key              //~v0imR~
		{                                                          //~v0imI~
        	pkt2=0;                                                //~v0imI~
        	for (;;) 		//until pkt2=0                         //~v0imI~
            {                                                      //~v0imI~
                swDeleted=0;                                       //~vbvhI~
                pcl=keyline;                                       //~v0imR~
                memset(keyline,' ',(UINT)(sizeof(keyline)-1));     //~v0imR~
//func name                                                        //~v0imM~
                pc=pft->FTnamee;                                   //~v0imR~
                len=(int)strlen(pc);                               //~v0imR~
//            if (SswByUTF8 && pft->FTfuncid>FUNCID_GRAPHCHAR)     //~vbvdR~
//  			funct2printlcdata(0,pcl,pc,len);                   //~vbvdR~
//            else                                                 //~vbvdR~
                memcpy(pcl,pc,(UINT)len);                          //~v0imR~
    			expandedByUtf8=0;                                  //~vbvdI~
                if (pft->FTfuncid>FUNCID_GRAPHCHAR                 //~v705I~
//              &&  UCBITCHK(pft->FTflag,FTFLINECHSET))	//linech file setup//~v705R~//~vbviR~
                &&  UCBITCHK(pft->FTflag2,FTF2LINECHSET))	//linech file setup//~vbviI~
                {                                                  //~v705I~
//            		funct2getlinechstr(0,pft,pcl+FTNAMEGRAPHHEXPOS);//~v705R~//~vb2AR~
//            		funct2getlinechstr(0,pft,pcl+FTNAMEGRAPHHEXPOS,(int)sizeof(keyline)-(int)PTRDIFF(pcl+FTNAMEGRAPHHEXPOS,keyline));//~vb2AI~//~vbvdR~
              		u8len=funct2getlinechstr(0|SswByUTF8,pft,pcl+FTNAMEGRAPHHEXPOS,(int)sizeof(keyline)-(int)PTRDIFF(pcl+FTNAMEGRAPHHEXPOS,keyline));//~vbvdR~
    	            UTRACEP("%s:keyline after FTnamee u8len=%d,pcl=%p\n",UTT,u8len,pcl);//~vbvdI~
                    if (u8len>6)                                   //~vbvdR~
                    {                                              //~vbvdI~
//                  	pcl+=u8len-6+1;	//1 space                  //~vbvdR~//~vbvtR~
//  					expandedByUtf8=u8len-6+1;                  //~vbvdI~//~vbvtR~
    					expandedByUtf8=u8len-6;                    //~vbvtI~
                    	pcl+=expandedByUtf8;                       //~vbvtR~
                    }                                              //~vbvdI~
    	            UTRACEP("%s:=0.2 keyline after FTnamee u8len=%d,pcl=%p\n",UTT,u8len,pcl);//~vbvdR~
                }                                                  //~v705I~
                UTRACED("keyline after FTnamee",keyline,sizeof(keyline));//~vbvpR~
                UTRACEP("%s:keyline after pkt2=%p,FTcmd=%s,FTcmda=%s\n",UTT,pkt2,pft->FTcmd,pft->FTcmda);//~vbvpR~
                pcl+=sizeof(pft->FTnamee);                         //~v0imR~
//              if (Popt==FILEFK_OPT04)                            //~v0iwR~
//              {                                                  //~v0iwR~
//key name                                                         //~v0imM~
					if (pkt2)                                      //~v0imI~
                    	pkt=pkt2;                                  //~v0imI~
                    else                                           //~v0imI~
                    {                                              //~v0imI~
                		UTRACEP("%s:ii=%d,WFTkey[ii]=0x%x\n",UTT,ii,pwft->WFTkey[ii]);//~vbvfR~
//              		UTRACED("workft",pwft,sizeof(WORKFT));     //~vbvoR~
                        if (!(key=pwft->WFTkey[ii]))               //~v0imR~
                        {                                          //~v0imI~
                            if (ii)                                //~v0imI~
	                            break;                             //~v0imR~
                            pkt=0;                                 //~v0imI~
						}                                          //~v0imI~
                        else                                       //~v0imI~
                        {                                          //~vbvhI~
                            if (key==FTDELETEDKEY)                 //~vbvhI~
                            {                                      //~vbvhI~
                                swDeleted=1;                       //~vbvhI~
                                pkt=0;	                           //~vbvhI~
        		        		UTRACEP("%s:deletedKey\n",UTT);    //~vbvhI~
                            }                                      //~vbvhI~
                            else                                   //~vbvhI~
	                        if ((shiftid=kbdsrchkt(key,&pkt))==4)  //~v0imR~
//  	                        continue;    cause loop            //~v0imR~//~vbvhR~
    	                        break;                             //~vbvhI~
                        }                                          //~vbvhI~
                    }                                              //~v0imI~
    	            UTRACEP("%s:=0.2 shiftid=%d,ii=%d,pkt=%p\n",UTT,shiftid,ii,pkt);//~vbvfR~
                    delm=':';                                      //~v0imI~
                    if (pkt)                                       //~v0imI~
                    {                                              //~v0imI~
                        flag=pwft->WFTkflag[ii];                   //~v0imR~
	    	            UTRACEP("%s:=0.2 pkt!=0 WFTflag=0x%x\n",UTT,flag);//~vbvfI~
                        if (shiftid==3                             //~v0imR~
//                      &&  UCBITCHK(flag,KTCTLDUP1))   //duplicated key//~v45KR~
                        &&  UCBITCHK(pkt->KTflag[3],KTCTLDUP1))   //duplicated key//~v45KI~
//                          pkt2=kbdsrchdupkt(pkt);                //~v69YR~
                            pkt2=kbdsrchdupkt(pkt,shiftid);        //~v69YI~
                        else                                       //~v69YI~
                        if (shiftid==2   	//alt                  //~v69YR~
                        &&  UCBITCHK(pkt->KTflag[2],KTALTDUP1))   //duplicated key//~v69YR~
                            pkt2=kbdsrchdupkt(pkt,shiftid);        //~v69YI~
#ifndef KKK                                                        //~vb50I~
						swshiftAC=0;                               //~vb50I~
            		  if (shiftid==2||shiftid==3)	//Alt or Ctl   //~vb50I~
                      {                                            //~vb50I~
	            		if (UCBITCHK(pft->FTkflag[ii],FTSHIFT))    //~vb50I~
    	         			swshiftAC=1;                           //~vb50I~
            		  }                                            //~vb50I~
                      else                                         //~vb50I~
#endif                                                             //~vb50I~
                        if (UCBITCHK(flag,FTSHIFT))                //~v0imR~
                            shiftid=1;          //shift            //~v0imR~
                        if (UCBITCHK(flag,FTFIX))                  //~v0imR~
                            delm='*';                              //~v0imR~
                        else                                       //~v0imR~
                            if (UCBITCHK(flag,FTSHIFT))            //~v0imR~
                                delm=';';                          //~v0imR~
    	                *pcl++=delm;                               //~v0imI~
#ifndef KKK                                                        //~vb50M~
						pcl+=2;                                    //~vb50R~
          			  if (swshiftAC)                               //~vb50I~
                      {                                            //~vb50I~
						xekbdsetSAC(XEKBDSACO_NOSTRZ,shiftid,pkt,pcl-2);//~vb50R~
	                    pcl+=2;                                    //~vb50R~
                      }                                            //~vb50I~
                      else                                         //~vb50I~
#endif                                                             //~vb50M~
                      {                                            //~vb50I~
                        if (shiftid)                               //~v0imR~
                        {                                          //~v0imR~
                            *pcl++=*Gkeyshiftname[shiftid];        //~v0imR~
                            *pcl++='+';                            //~v0imR~
                        }                                          //~v0imR~
                        else                                       //~v0imR~
                            pcl+=2;                                //~v0imR~
                    	pc=pkt->KTnamee;                           //~v0imR~
                    	len=(int)strlen(pc);                       //~v0imR~
                    	memcpy(pcl,pc,(UINT)len);                  //~v0imR~
                      }                                            //~vb50I~
                    }                                              //~v0imI~
                    else                                           //~v0imI~
                    if (swDeleted)                                 //~vbvhI~
                    {                                              //~vbvhI~
    	                *pcl++=delm;                               //~vbvhI~
                    }                                              //~vbvhI~
                    else                                           //~vbvhI~
                    if (!*pft->FTcmd)                              //~vbvrR~
                    {                                              //~vbvrI~
    	                *pcl++=delm;                               //~vbvrI~
                		UTRACEP("%s:No key and no cmd\n",UTT);     //~vbvrI~
                    }                                              //~vbvrI~
                    else                                           //~vbvrI~
                    {                                              //~v0imI~
//                      if (cmdonlysw=UCBITCHK(pft->FTflag,FTFCMDONLY),cmdonlysw)//~v756R~
//                      {                                          //~v756R~
                          if (UCBITCHK(pft->FTflag2,FTF2FIXEDVERB))//~v71PR~
                        	delm='*';	//line prot                //~v0imI~
                          else                                     //~v71PM~
							delm=NOTFIXCMDID;  //"+";command verb changable//~v71PM~
//                      }                                          //~v756R~
    	                *pcl++=delm;                               //~v0imI~
//                      if (cmdonlysw)                             //~v756R~
//                      {                                          //~v756R~
						  if (delm==NOTFIXCMDID)  //command verb changable//~v71PI~
                        	*(pcl++)=' ';                          //~v71PI~
                          else                                     //~v71PI~
                        	*(pcl++)='(';                          //~v0imR~
//                          memcpy(pcl,pwft->WFTcmd,strlen(pwft->WFTcmd));//~v0iwR~
//                          memcpy(pcl,pft->FTcmd,strlen(pft->FTcmd));//~v71PR~
                            memcpy(pcl,pwft->WFTcmd,strlen(pwft->WFTcmd));//~v71PI~
//                      	*(pcl+3)=')';                          //~v44vR~
                        	*(pcl+3)='/';                          //~v44vI~
                            memcpy(pcl+4,pft->FTcmda,strlen(pft->FTcmda));//~v44vI~
                            memcpy(pcl+4,pwft->WFTcmda,strlen(pwft->WFTcmda));//~v71PI~
						  if (delm==NOTFIXCMDID)  //command verb changable//~v71PI~
                        	*(pcl+7)=' ';                          //~v71PI~
                          else                                     //~v71PI~
                        	*(pcl+7)=')';                          //~v44vI~
                            pcl++;                                 //~v47VI~
                			UTRACED("keyline after cmd set",keyline,sizeof(keyline));//~vbvpI~
//                      }                                          //~v756R~
//                      else                                       //~v756R~
//                      {                                          //~v756R~
//                      	memset(pcl,NOCMDID,FKF_MARGIN3-FKF_PROTLEN3);//~v756R~
//                          pcl+=2;                                //~v756R~
//      				}                                          //~v756R~
					}                                              //~v0imI~
#ifndef KKK                                                        //~vb50M~
                    pcl=keyline+Ppfh->UFHmergin; //=FKF_MARGIN3    //~vb50R~
    				pcl+=expandedByUtf8;                           //~vbvdI~
#else                                                              //~vb50I~
                    pcl+=sizeof(pkt->KTnamee)-1;                   //~v0ixR~
#endif                                                             //~vb50M~
//              }                                                  //~v0iwR~
//              else    //cmd verb change                          //~v0iwR~
//              {                                                  //~v0iwR~
//                  ii=FTMAXKEY;    //break by key                 //~v0iwR~
//                  *pcl++=':';                                    //~v0iwR~
//cmd verb                                                         //~v0imM~
//                  if (UCBITCHK(pft->FTflag,FTFDUPACMD))          //~v0iwR~
//                      delm='*';           //protect line         //~v0iwR~
//                  else                                           //~v0iwR~
//                      delm=' ';           //noprotect line       //~v0iwR~
//                  len=(int)strlen(pwft->WFTcmd);                 //~v0iwR~
//                  if (len)                                       //~v0iwR~
//                      memcpy(pcl,pwft->WFTcmd,(UINT)len);        //~v0iwR~
//                  else                                           //~v0iwR~
//                      memset(pcl,NOCMDID,(UINT)(sizeof(pwft->WFTcmd)-1));//~v0iwR~
//                  pcl+=sizeof(pwft->WFTcmd)-1;                   //~v0iwR~
//                  *pcl++=CMDDELM;                                //~v0iwR~
//                  len=(int)strlen(pwft->WFTcmda);                //~v0iwR~
//                  if (len)                                       //~v0iwR~
//                      memcpy(pcl,pwft->WFTcmda,(UINT)len);       //~v0iwR~
//                  else                                           //~v0iwR~
//                      memset(pcl,NOCMDID,(UINT)(sizeof(pwft->WFTcmda)-1));//~v0iwR~
//                  pcl+=sizeof(pwft->WFTcmda)-1;                  //~v0iwR~
//              }                                                  //~v0iwR~
//func desc(J)                                                     //~v0imM~
//              UTRACED("before //",keyline,sizeof(keyline));      //~vbvoR~
                UTRACEP("%s:pcl=%p\n",UTT,pcl);                    //~vbvdR~
              if (pft->FTfuncid>FUNCID_GRAPHCHAR                   //~v705R~
//            &&  UCBITCHK(pft->FTflag,FTFLINECHSET))	//linech file setup//~v705R~//~vbviR~
              &&  UCBITCHK(pft->FTflag2,FTF2LINECHSET))	//linech file setup//~vbviI~
              {                                                    //~v705I~
                memset(pcl,'/',2);                                 //~v705I~
                pcl+=2;                                            //~v705I~
//            	lchlen=funct2getlinechstr(1,pft,pcl);              //~v705R~//~vb2AR~
//            	lchlen=funct2getlinechstr(1,pft,pcl,sizeof(keyline)-(int)PTRDIFF(pcl,keyline));//~vb2AI~//~vb2DR~
//            	lchlen=funct2getlinechstr(1,pft,pcl,(int)sizeof(keyline)-(int)PTRDIFF(pcl,keyline));//~vb2DI~//~vbvbR~
              	lchlen=funct2getlinechstr(1|SswByUTF8,pft,pcl,(int)sizeof(keyline)-(int)PTRDIFF(pcl,keyline));//~vbvbI~
//            	pcl+=max(lchlen,sizeof(pft->FTnamej));             //~v705R~//~vb2DR~
              	pcl+=max(lchlen,(int)sizeof(pft->FTnamej));        //~vb2DI~
              }                                                    //~v705I~
              else                                                 //~v705I~
              {                                                    //~v705I~
//#ifdef LNX                                                         //~v44uR~//~vbvfR~
////              if ((Gunxflag & (GUNX_EUC|GUNX_KON))==(GUNX_EUC|GUNX_KON)) //under kon//~v79zR~//~vbvfR~
//                if (XE_ISDBCSKONJ())    //Japanese                 //~v79zR~//~vbvfR~
//#else                                                              //~v44uR~//~vbvfR~
//                if (UCBITCHK(Gscrstatus,GSCRSDBCS))                //~v0imR~//~vbvfR~
//#endif                                                             //~v44uR~//~vbvfR~
               if (!swNotJP && !(pft->FTflag & FTFEONLY))          //~vbvfR~
                {                                                  //~v0imR~
                    memset(pcl,'/',2);                             //~v0imR~
                    pcl+=2;                                        //~v0imR~
                    pc=pft->FTnamej;                               //~v0imR~
                    len=(int)strlen(pc);                           //~v0imR~
                  if (SswByUTF8)                                   //~vbvbI~
                  {                                                //~vbvbI~
                    u8len=cvFuncNameS2F(pcl,pc,len);               //~vbvbM~
                    pcl+=u8len;                                    //~vbvbM~
                  }                                                //~vbvbI~
                  else                                             //~vbvbI~
                  {                                                //~vbvbI~
                    memcpy(pcl,pc,(UINT)len);                      //~v0imR~
                    pcl+=sizeof(pft->FTnamej);                     //~v0imR~
                  }                                                //~vbvbI~
                 }//swNotJP                                        //~vbvfI~
              }                                                    //~v705I~
//              lrecl=(int)((ULONG)pcl-(ULONG)keyline);            //~v0imR~//~vafkR~
                lrecl=(int)((ULPTR)pcl-(ULPTR)keyline);            //~vafkI~
                plh=filealloclh(ULHTDATA,lrecl);                   //~v0imR~
                UALLOCCHK(plh,UALLOC_FAILED);//return when storage shortage//~v0imR~
                UENQENT(UQUE_AFT,plhprev,plh);                     //~v0imR~
                plh->ULHlinenor=plhprev->ULHlinenor+1;             //~v0imR~
                memcpy(plh->ULHdata,keyline,(UINT)lrecl);          //~v0imR~
//              UTRACED("ULHdata",plh->ULHdata,lrecl);       //~vbvbI~//~vbvoR~
                if (delm=='*')                                     //~v0imR~
                    UCBITON(plh->ULHflag4,ULHF4PROTLINE);   //protected(change line attr)//~v0imR~
                plhprev=plh;                                       //~v0imR~
				if (!pkt2)                                         //~v0imI~
                	break;                                         //~v0imI~
				if (pkt==pkt2)	//2 dup of ctl+                    //~v45KI~
                	break;                                         //~v45KI~
        	}//twice for ctldup                                    //~v0imI~
		}//ii:all ftkey                                            //~v0imR~
    }//loop for pwft                                               //~v0imR~
    return 0;                                                      //~v0imM~
}//filefkctlineft                                                  //~v0imI~
                                                                   //~v0imI~
//**************************************************************** //~v0ixI~
//* key assignment chnage by pressed key                           //~v0ixI~
//* parm1 :pcw                                                     //~v0ixI~
//* parm2 :0:expkeysw                                              //~v0ixR~
//* parm3 :key                                                     //~v0ixR~
//* parm4 :shift press sw                                          //~v0ixI~
//* retrn :-1:not avail for key assign 0:file updated 4:file update err//~v0ixI~
//*        UALLOC_FAILED                                           //~v0ixI~
//**************************************************************** //~v0ixI~
int filesetassign(PUCLIENTWE Ppcw,int Pextkeysw,USHORT Pkey,int Pshiftkeysw)//~v0ixR~
{                                                                  //~v0ixI~
	KEYTBL  *pkt;                                                  //~v0ixI~
    int shiftid,recoff;                                            //~v0ixR~
	PUFILEH  pfh;                                                  //~v0ixI~
	PUFILEC  pfc;                                                  //~v0ixI~
	PULINEH  plh;                                                  //~v0ixI~
    UCHAR *pc;                                                     //~v0ixI~
    UCHAR wkkeynm[FKF_MARGIN3-FKF_PROTLEN3];                       //~v0ixI~
//********************                                             //~v0ixI~
    if (shiftid=kbdsrchkt(Pkey,&pkt),!pkt)   //not defined         //~v0ixR~
        return -1;                   //continue process            //~v0ixI~
	if (!Pextkeysw)		//char key                                 //~v0ixI~
		if (UCBITCHK(pkt->KTflag[3],KTCHARKEY))	//not ext key      //~v0ixI~
          if (shiftid<2)    //not C+ nor A+                        //~v699I~
        	return -1;					//continue process         //~v0ixI~
    if (Pshiftkeysw)                                               //~v0ixI~
	    if (!shiftid && UCBITCHK(pkt->KTflag[1],KTSHIFTDUP))       //~v0ixI~
        	shiftid=1;                                             //~v0ixI~
    if (UCBITCHK(pkt->KTflag[shiftid],KTFIXED))                    //~v0ixI~
    	return -1;                                                 //~v0ixI~
	pfc=Ppcw->UCWpfc;                                              //~v0ixR~
	pfh=pfc->UFCpfh;                                               //~v0ixI~
    recoff=pfc->UFCleft+Ppcw->UCWrcsrx-(int)Ppcw->UCWlinenosz;//confirmed CSRONFILEDATA//~v0ixR~
    if (recoff<FKF_PROTLEN3 || recoff>=FKF_MARGIN3)                //~v0ixR~
    	return -1;                                                 //~v0ixI~
	if (!(plh=((PUSCRD)(Ppcw->UCWpsd)+Ppcw->UCWrcsry)->USDbuffc))  //~v0ixI~
		return 4;  				//err                              //~v0ixI~
    if (plh->ULHtype!=ULHTDATA)                                    //~v0ixI~
		return 4;				//err                              //~v0ixI~
    if (UCBITCHK(plh->ULHflag4,ULHF4PROTLINE))  //protected(change line attr)//~v0ixI~
		return fileoptfixederr();                                  //~v0ixI~
    memset(wkkeynm,' ',FKF_MARGIN3-FKF_PROTLEN3);                  //~v0ixR~
#ifndef KKK                                                        //~vb50M~
  if ((shiftid==2||shiftid==3)                                     //~vb50I~
  &&  Pshiftkeysw)                                                 //~vb50I~
  {                                                                //~vb50I~
	xekbdsetSAC(XEKBDSACO_NOSTRZ,shiftid,pkt,wkkeynm);             //~vb50R~
  }                                                                //~vb50I~
  else                                                             //~vb50I~
#endif                                                             //~vb50M~
  {                                                                //~vb50I~
    if (shiftid)                                                   //~v0ixI~
    {                                                              //~v0ixI~
        wkkeynm[0]=*Gkeyshiftname[shiftid];                        //~v0ixR~
        wkkeynm[1]='+';                                            //~v0ixR~
    }                                                              //~v0ixI~
    memcpy(wkkeynm+2,pkt->KTnamee,strlen(pkt->KTnamee));           //~v0ixR~
  }                                                                //~vb50I~
    pc=plh->ULHdata+FKF_PROTLEN3;                                  //~v0ixM~
    if (!memicmp(wkkeynm,pc,FKF_MARGIN3-FKF_PROTLEN3))             //~v0ixI~
    	return 0;                                                  //~v0ixI~
	UPCTRREQ(pfh);//next time updatectr up                         //~v0ixM~
    if (undoupdate(Ppcw,plh,UUHTREP)==UALLOC_FAILED) //reset flag CURFOUND//~v0ixM~
    	return UALLOC_FAILED;                                      //~v0ixM~
    memcpy(pc,wkkeynm,FKF_MARGIN3-FKF_PROTLEN3);                   //~v0ixI~
	UPCTRREQ(pfh);//next time updatectr up                         //~v0ixI~
//  filesetcsr(Ppcw,plh,1,max(0,FKF_PROTLEN3-pfc->UFCleft));	//set csr,fldtop//~v0jfR~
    filesetcsr(Ppcw,plh,0,0);                                      //~v0jfI~
    return 0;                                                      //~v0ixI~
}//filesetassign                                                   //~v0ixI~
//**************************************************************** //~v0imI~
//* key assignment chnage save    0.2                              //~v0jgR~
//* parm1 :pfh                                                     //~v0imI~
//* parm2 :opt                                                     //~v0imI~
//* retrn:rc UALLOC_FAILED or errline exist                        //~v0imI~
//**************************************************************** //~v0imI~
int filefksaveft(PUCLIENTWE Ppcw,PUFILEH Ppfh,int Popt)            //~v0imR~
{                                                                  //~v0imI~
	WORKFTHDR  wfth;                                               //~v0imR~
	PULINEH    	plh,plherr=0;                                      //~v0imR~
	KEYTBL     *pkt;                                               //~v0imI~
    UCHAR linedata[MAXCOLUMN+1];                                   //~v0imR~
    UCHAR cmdv[2][4];                                              //~v0iwR~,//~v71PR~
    UCHAR *pc,*pc2;                                                //~v0jeR~
    UCHAR *pc3;                                                    //~vbvfI~
    int errsw,rc,mergin,protlen,jj;                                //~v0iwR~
    int lrecl,shift,index;                                         //~v0iwR~
    int cmdlen,cmdfmterr,ii;                                       //~v0iwI~,//~v71PR~
    PFUNCTBL    pft;                                               //~v0imR~
    PFUNCTBL    pfto=0;                                            //~vbvhI~
    PWORKFT    pwft,pwft0;                                         //~v0imR~
#ifndef KKK                                                        //~vb50I~
    int swshiftAC;                                                 //~vb50R~
#endif                                                             //~vb50I~
	int pftKeyCtr=0;                                               //~vbvhI~
    int lenByUTF8;                                                 //~vbvdI~
    int swProtLine;                                                //~vbvpI~
//*****************                                                //~v0imI~
    UPCTRREQ(Ppfh);         //reset ULHF3ERRLINE at next update lien//~v0ixI~
	if (rc=funcgetwfth(2,&wfth),rc)	//copy of fixed key            //~v0imR~
		return rc;                                                 //~v0imR~
    pwft0=wfth.WFTHpwft;                                           //~v0imR~
    mergin=Ppfh->UFHmergin;                                        //~v0imI~
    protlen=Ppfh->UFHprotlen;                                      //~v0imI~
	plh=UGETQTOP(&Ppfh->UFHlineque);                               //~v0imM~
    *(linedata+mergin)=0;                                          //~v0imI~
    UTRACEP("%s:mergin=%d,protlen=%d\n",UTT,mergin,protlen);       //~vbvfI~
    for (;plh;plh=UGETQNEXT(plh))                                  //~v0imR~
    {                                                              //~v0imR~
        errsw=0;                                                   //~v0imR~
        if (*plh->ULHdata=='(')                                    //~vbvfR~
        {                                                          //~vbvfR~
        	UTRACEP("%s:GraphChar\n",UTT);                         //~vbvfR~
        }                                                          //~vbvfR~
        if (plh->ULHtype!=ULHTDATA)                                //~v0imR~
            continue;                                              //~v0imR~
//      if (UCBITCHK(plh->ULHflag4,ULHF4PROTLINE))  //protected(change line attr)//~vbvpR~
//          continue;                                              //~vbvpR~
        if (*plh->ULHdata==ALIASCMT)                               //~vbvpI~
            continue;                                              //~vbvpI~
        swProtLine=UCBITCHK(plh->ULHflag4,ULHF4PROTLINE);          //~vbvpI~
        lrecl=plh->ULHlen;                                         //~v0imR~
        UTRACED("ULHdata",plh->ULHdata,lrecl);                     //~vbvdR~
        UTRACED("ULHdbcs",plh->ULHdbcs,lrecl);                     //~vbvdR~
        for (errsw=1;errsw;)                                       //~v0imR~
        {                                                          //~v0imR~
            if (lrecl<mergin)                                      //~v0imR~
            {                                                      //~v0imR~
                fileoptlreclerr();                                 //~v0imR~
                break;                                             //~v0imR~
            }                                                      //~v0imR~
//          memcpy(linedata,plh->ULHdata,(UINT)mergin);            //~vbvdR~
            pc2=memchr(plh->ULHdata+mergin,'/',(UINT)(lrecl-mergin));//~vbvdI~
            if (pc2)                                               //~vbvdI~
            	lenByUTF8=PTRDIFF(pc2,plh->ULHdata)-mergin;        //~vbvdI~
            else                                                   //~vbvdI~
            	lenByUTF8=lrecl-mergin;                            //~vbvdR~
            UmemcpyZ(linedata,plh->ULHdata,(UINT)(mergin+lenByUTF8));//~vbvdR~
            if (pc=strchr(linedata,' '),pc)                        //~v0imR~
                *pc=0;                                             //~v0imR~
			else                                                   //~v0imI~
            	*(linedata+protlen-1)=0;                           //~v0imI~
    		UTRACED("linedata",linedata,sizeof(linedata));         //~vbvdR~
    		UTRACEP("%s:pc=%p,lenByUTF8=%d,protlen=%d,linedata=%s\n",UTT,pc,lenByUTF8,protlen,linedata);//~vbvdR~
            if (!(pft=functblsrchbyname(linedata)))                //~v0imR~
            {                                                      //~v0imR~
                fileoptfuncnmerr();                                //~v0imR~
                break;                                             //~v0imR~
            }                                                      //~v0imR~
            if (pft!=pfto)                                         //~vbvhI~
            {                                                      //~vbvhI~
            	pftKeyCtr=0;	                                   //~vbvhI~
                pfto=pft;                                          //~vbvhI~
            }                                                      //~vbvhI~
            else                                                   //~vbvhI~
            	pftKeyCtr++;                                       //~vbvhR~
    		UTRACEP("%s:pftKeyCtr=%d,pft=%p,pfto=%p,swProtline=x%x\n",UTT,pftKeyCtr,pft,pfto,swProtLine);//~vbvpR~
//  		UTRACED("FTkey",pft->FTkey,sizeof(pft->FTkey));        //~vbvoR~
			if (swProtLine)                                        //~vbvpI~
            	break;                                             //~vbvpI~
//          index=(int)(((ULONG)pft-(ULONG)Gfunctbl)/sizeof(FUNCTBL));//~v0imI~//~vafkR~
            index=(int)(((ULPTR)pft-(ULPTR)Gfunctbl)/sizeof(FUNCTBL));//~vafkI~
            pwft=pwft0+index;                                      //~v0imI~
//          if (Popt==FILEFK_OPT04)                                //~v0iwR~
//          {                                                      //~v0iwR~
//key chk                                                          //~v0imI~
                pc=linedata+protlen;                               //~v0imR~
    		UTRACEP("%s:pc=%s\n",UTT,pc);                          //~vbvfI~
            for (pc3=pc-1;pc3<linedata+mergin;pc3++)               //~vbvfI~
            {                                                      //~vbvfI~
                if (*pc3==NOTFIXCMDID     //'+' cmd                //~vbvfI~
                ||  *pc3==':'             // key                   //~vbvfI~
                ||  *pc3==';'             // shift                 //~vbvfI~
                ||  *pc3=='*'             // fixed                 //~vbvfI~
                )                                                  //~vbvfI~
                {                                                  //~vbvfI~
    				UTRACEP("%s:protlen separator pc3=%s\n",UTT,pc3);//~vbvfI~
                    pc=pc3+1;                                      //~vbvfI~
                    break;                                         //~vbvfI~
                }                                                  //~vbvfI~
            }                                                      //~vbvfI~
            if (*(pc-1)!=NOTFIXCMDID)  //command verb changable    //~v71PI~
            {                                                      //~v71PI~
            //* not '+'                                            //~vbvfI~
//              for (jj=FKF_MARGIN3-FKF_PROTLEN3;jj;jj--,pc++)     //~v0imR~//~vbvfR~
//              {                                                  //~vbvfR~
//                  if (*pc==NOCMDID)                              //~v0imI~//~vbvfR~
//                  	*pc=' ';                                   //~v0imI~//~vbvfR~
//              }                                                  //~vbvfR~
//              pc=linedata+protlen;                               //~v0imI~//~vbvfR~
	    		UTRACEP("%s:pc=%s\n",UTT,pc);                      //~vbvfI~
                pc+=strspn(pc," ");                                //~v0imR~
	    		UTRACEP("%s: after strsppn pc=%s\n",UTT,pc);       //~vbvfI~
//                if (*(pc+1)!='+')                                //~v0jeR~
//                    shift=0;                                     //~v0jeR~
//                else                                             //~v0jeR~
//                {                                                //~v0jeR~
//                    shiftch=(UCHAR)toupper(*pc);                 //~v0jeR~
//                    for (shift=1;shift<4;shift++)                //~v0jeR~
//                        if (shiftch==*Gkeyshiftname[shift])      //~v0jeR~
//                            break;                               //~v0jeR~
//                    if (shift==4)                                //~v0jeR~
//                    {                                            //~v0jeR~
//                        filekeynameerr();                        //~v0jeR~
//                        break;                                   //~v0jeR~
//                    }                                            //~v0jeR~
//                    pc+=2;                                       //~v0jeR~
//                }                                                //~v0jeR~
//              if (!(pc2=strchr(pc,' ')))                         //~v0jeR~
//              	pc2=pc+sizeof(pkt->KTnamee)-1;                 //~v0jeR~
              if (pc2=strchr(pc,' '),pc2)                          //~v0jeR~
                *pc2=0;                                            //~v0imR~
	    		UTRACEP("%s: after pc2 liedata=%s,pc=%s\n",UTT,linedata,pc);//~vbvdR~
                if (strlen(pc))		//key not deleted              //~v0imI~
                {                                                  //~v0imI~
//                  if (kbdsrchktbyname(pc,&pkt),!pkt) //not found //~v0jeR~
#ifndef KKK                                                        //~vb50I~
    				swshiftAC=0;                                   //~vb50I~
					xekbdchkSAC(0,pc,&pkt,&shift);                 //~vb50R~
  					if (shift)	//2 or 3  or err(-1)               //~vb50I~
  					{                                              //~vb50I~
                    	if (!pkt)	//S+AC on char key             //~vb50I~
                        	break;                                 //~vb50I~
    					swshiftAC=FKAO_SHIFTAC;                    //~vb50R~
    					UTRACEP("%s:S+modifier=%d\n",UTT,shift);   //~vb50R~
  					}                                              //~vb50I~
  					else                                           //~vb50I~
#endif                                                             //~vb50I~
                    if (shift=kbdsrchktbyname(pc,&pkt),!pkt) //not found//~v0jeI~
                    {                                              //~v0imR~
                        filekeynameerr();                          //~v0imR~
                        break;                                     //~v0imR~
                    }                                              //~v0imR~
//              	if (shift!=2	//char key or not alt+         //~v699R~
                	if (shift<2 	//noshift or with shift(not a+ nor C+)//~v699I~
    	    		&&  UCBITCHK(pkt->KTflag[2],KTCHARKEY))        //~v0jhR~
                    {                                              //~v0jhI~
                        filekeynameerr();                          //~v0jhI~
                        break;                                     //~v0jhI~
                    }                                              //~v0jhI~
#ifndef KKK                                                        //~vb50I~
                    if (filekeyassign(swshiftAC,pwft0,wfth.WFTHentno,pwft,pkt,shift))//~vb50I~
#else                                                              //~vb50I~
                    if (filekeyassign(pwft0,wfth.WFTHentno,pwft,pkt,shift))//~v0imR~
#endif                                                             //~vb50I~
                        break;                                     //~v0imR~
                }//not erased                                      //~v0imI~
                else                                               //~vbvhI~
                {                                                  //~vbvhI~
                    if (filekeyclear(pwft0,wfth.WFTHentno,pwft,pft,pftKeyCtr))//~vbvhI~
                    	break;                                     //~vbvhI~
                }                                                  //~vbvhI~
            }//key assign                                          //~v0iwR~,//~v71PR~
            else        //cmd assign                               //~v0iwR~,//~v71PR~
            {                                                      //~v0iwR~,//~v71PR~
//cmd chk                                                          //~v0imI~,//~v71PR~
                pc=linedata+protlen;                               //~v0iwR~,//~v71PR~
                jj=0;   //cmd/cmda                                 //~v0iwR~,//~v71PR~
                cmdlen=0;                                          //~v0iwR~,//~v71PR~
                cmdfmterr=0;                                       //~v0iwR~,//~v71PR~
                memset(cmdv,0,sizeof(cmdv));                       //~v0iwR~,//~v71PR~
                for (ii=FKF_MARGIN4-FKF_PROTLEN4;ii;ii--,pc++)     //~v0iwR~,//~v71PR~
                {                                                  //~v0iwR~,//~v71PR~
                    if (*pc==' ')                                  //~v0iwR~,//~v71PR~
                        continue;                                  //~v0iwR~,//~v71PR~
                    if (*pc==CMDDELM)                              //~v0iwR~,//~v71PR~
                    {                                              //~v0iwR~,//~v71PR~
                        if (++jj>=2)                               //~v0iwR~,//~v71PR~
                        {                                          //~v0iwR~,//~v71PR~
                            cmdfmterr=1;                           //~v0iwR~,//~v71PR~
                            break;                                 //~v0iwR~,//~v71PR~
                        }                                          //~v0iwR~,//~v71PR~
                        cmdlen=0;                                  //~v0iwR~,//~v71PR~
                        continue;                                  //~v0iwR~,//~v71PR~
                    }                                              //~v0iwR~,//~v71PR~
                    if (*pc==NOCMDID)                              //~v0iwR~,//~v71PR~
                        continue;                                  //~v0iwR~,//~v71PR~
                    if (*pc<' ' || *pc>'z')                        //~v0iwR~,//~v71PR~
                    {                                              //~v0iwR~,//~v71PR~
                        cmdfmterr=1;                               //~v0iwR~,//~v71PR~
                        break;                                     //~v0iwR~,//~v71PR~
                    }                                              //~v0iwR~,//~v71PR~
                    if (cmdlen>=sizeof(pwft->WFTcmd)-1)            //~v0iwR~,//~v71PR~
                    {                                              //~v0iwR~,//~v71PR~
                        cmdfmterr=1;                               //~v0iwR~,//~v71PR~
                        break;                                     //~v0iwR~,//~v71PR~
                    }                                              //~v0iwR~,//~v71PR~
                    cmdv[jj][cmdlen++]=*pc;                        //~v0iwR~,//~v71PR~
                }                                                  //~v0iwR~,//~v71PR~
                if (!*cmdv[0] && *cmdv[1])                         //~v0iwR~,//~v71PR~
                    cmdfmterr=1;                                   //~v0iwR~,//~v71PR~
                if (cmdfmterr)                                     //~v0iwR~,//~v71PR~
                {                                                  //~v0iwR~,//~v71PR~
                    fileoptcmdfmterr();                            //~v0iwR~,//~v71PR~
                    break;                                         //~v0iwR~,//~v71PR~
                }                                                  //~v0iwR~,//~v71PR~
                if (filecmdvassign(pwft0,pwft,cmdv))               //~v0iwR~,//~v71PR~
                    break;                                         //~v0iwR~,//~v71PR~
            }//cmd assign                                          //~v0iwR~,//~v71PR~
            errsw=0;    //break with normal                        //~v0imR~
        }//err chk                                                 //~v0imR~
		if (swProtLine)                                            //~vbvpI~
        	continue;                                              //~vbvpI~
        if (errsw)                                                 //~v0imR~
        {                                                          //~v0imR~
            filesetlineerr(plh);    //lineno fld reverse hilight   //~v0imR~
            if (!plherr)                                           //~v0imI~
            {                                                      //~v0imI~
            	plherr=plh;                                        //~v0imR~
                fcmdscrollpage(Ppcw,plherr);                       //~v0jgR~
				filesetcsr(Ppcw,plherr,0,0);	//set csr,fldtop   //~v0imI~
			}                                                      //~v0imI~
        }                                                          //~v0imR~
    }//loop                                                        //~v0imR~
    rc=0;                                                          //~v0imI~
    if (plherr)                                                    //~v0imR~
        rc=4;                                                      //~v0imI~
    else                                                           //~v0imI~
		if (rc=funcputwfth(&wfth,Popt),rc)	//copy of fixed key    //~v0imR~
	        rc=4;                                                  //~v0imI~
    ufree(pwft0);                                                  //~v0imR~
    return rc;                                                     //~v0imI~
}//filefksaveft                                                    //~v0imR~
//**************************************************               //~v0imI~
//*chk key assign                                                  //~v0imI~
//*parm1:pwft top                                                  //~v0imR~
//*parm2:pwft entryno                                              //~v0imI~
//*parm3:pwft current                                              //~v0imR~
//*parm4:pkt                                                       //~v0imR~
//*parm5:shift id(0-3)                                             //~v0imR~
//*ret :rc                                                         //~v0imI~
//**************************************************               //~v0imI~
#ifndef KKK                                                        //~vb50I~
int filekeyassign(int Popt,PWORKFT Ppwft0,int Pentno,PWORKFT Ppwft,KEYTBL *Ppkt,int Pshift)//~vb50I~
#else                                                              //~vb50I~
int filekeyassign(PWORKFT Ppwft0,int Pentno,PWORKFT Ppwft,KEYTBL *Ppkt,int Pshift)//~v0imR~
#endif                                                             //~vb50I~
{                                                                  //~v0imI~
	PWORKFT pwft;                                                  //~v0imI~
    PFUNCTBL pft1,pft2;                                            //~v0imI~
    USHORT key,key2;                                               //~v0imR~
    int ii,jj,kk,ll,shiftdup0,shiftdup,ejonly1,ejonly2;            //~v0imR~
//*********************************                                //~v0imI~
    for (ii=0;ii<FTMAXKEY;ii++)	//serch free entry                 //~v0imI~
    	if (!Ppwft->WFTkey[ii])	//not used                         //~v0imR~
            break;                                                 //~v0imI~
    if (ii==FTMAXKEY)	//no free entry                            //~v0imI~
    {                                                              //~v0imI~
        fileoptkeyoverflow();                                      //~v0imI~
        return 4;                                                  //~v0imI~
	}                                                              //~v0imI~
    jj=ii; 			//free entry                                   //~v0imI~
//duplicate chk in keytbl                                          //~v0imR~
    shiftdup0=UCBITCHK(Ppkt->KTflag[Pshift],KTSHIFTDUP);           //~v0imR~
	key=Ppkt->KTkey[Pshift];                                       //~v0imI~
    UTRACEP("%s:key=x%x,Pshift=%d\n",UTT,key,Pshift);              //~vbvhI~
//  UTRACED("%pkt",Ppkt,sizeof(KEYTBL));                           //~vbvoR~
    for (ii=0;ii<jj;ii++)                                          //~v0imI~
    {                                                              //~v0imI~
		if (key==Ppwft->WFTkey[ii])                                //~v0imR~
        {                                                          //~v0imI~
    		shiftdup=UCBITCHK(Ppwft->WFTkflag[ii],FTSHIFT);        //~v0imR~
    		if ((shiftdup && shiftdup0)                            //~v40KR~
    		||  (!shiftdup && !shiftdup0))                         //~v40KR~
				return 0;                                          //~v0imR~
		}                                                          //~v0imI~
	}                                                              //~v0imI~
#ifndef KKK                                                        //~vb50I~
  	if (Popt & FKAO_SHIFTAC)	//width shift key                  //~vb50I~
    	shiftdup0=KTSHIFTDUP;                                      //~vb50I~
#endif                                                             //~vb50I~
//duplicate chk in wft                                             //~v0imI~
    for (pwft=Ppwft0,kk=0;kk<Pentno;kk++,pwft++)                   //~v0imR~
    {                                                              //~v0imR~
        for (ii=0;ii<FTMAXKEY;ii++)                                //~v0imR~
        {                                                          //~v0imR~
            if (!(key2=pwft->WFTkey[ii]))                          //~v0imR~
                break;                                             //~v0imR~
            if (key2!=key)                                         //~v0imR~
                continue;                                          //~v0imR~
            shiftdup=UCBITCHK(pwft->WFTkflag[ii],FTSHIFT);         //~v0imR~
            if ((shiftdup && shiftdup0)                            //~v40KR~
            ||  (!shiftdup && !shiftdup0))                         //~v40KR~
            {                                                      //~v0imI~
            	pft2=(PFUNCTBL)Gfunctbl+kk;                        //~v0imR~
//              pft1=(PFUNCTBL)Gfunctbl+((ULONG)Ppwft-(ULONG)Ppwft0)/sizeof(WORKFT);//~v0imR~//~vafkR~
                pft1=(PFUNCTBL)Gfunctbl+((ULPTR)Ppwft-(ULPTR)Ppwft0)/sizeof(WORKFT);//~vafkI~
				ejonly1=UCBITCHK(pft1->FTflag,FTFEONLY|FTFJONLY);  //~v0imI~
				ejonly2=UCBITCHK(pft2->FTflag,FTFEONLY|FTFJONLY);  //~v0imI~
				if (!(ejonly1 & ejonly2)                           //~v0imI~
				&&   ((ejonly1 | ejonly2)==(FTFEONLY|FTFJONLY)))   //~v0imI~
                	continue;                                      //~v0imI~
				for (ll=0;ll<UCWMAXTYPE;ll++)                      //~v0imI~
					if (pft1->FTfunc[ll] && pft2->FTfunc[ll])//screen type duplicated//~v0imI~
		            	break;                                     //~v0imI~
				if (ll!=UCWMAXTYPE)	//not duplicated screen type   //~v0imI~
#ifndef KKK                                                        //~vb50I~
	                return fileoptdupassign(kbdgetname(key,shiftdup0));//~vb50I~
#else                                                              //~vb50I~
	                return fileoptdupassign();                     //~v0imR~
#endif                                                             //~vb50R~
            }                                                      //~v0imI~
        }                                                          //~v0imR~
    }//all wft                                                     //~v0imR~
	Ppwft->WFTkey[jj]=key;                                         //~v0imR~
//  UTRACED("Ppwft",Ppwft,sizeof(WORKFT));                         //~vbvoR~
    if (shiftdup0)                                                 //~v0imR~
		UCBITON(Ppwft->WFTkflag[jj],FTSHIFT);                      //~v0imR~
	else                                                           //~v0imI~
		UCBITOFF(Ppwft->WFTkflag[jj],FTSHIFT);                     //~v0imI~
	return 0;                                                      //~v0imI~
}//filekeyassign                                                   //~v0imR~
//**************************************************               //~vbvhI~
//*key erased                                                      //~vbvhI~
//*ret :rc                                                         //~vbvhI~
//**************************************************               //~vbvhI~
int filekeyclear(PWORKFT Ppwft0,int Pentno,PWORKFT Ppwft,PFUNCTBL Ppft,int PidxKey)//~vbvhI~
{                                                                  //~vbvhI~
    UTRACEP("%s:before FTnamee=%s,idxKey=%d,WFTkey=x%x\n",UTT,Ppft->FTnamee,PidxKey,Ppwft->WFTkey[PidxKey]);//~vbvhR~
//  UTRACED("Ppwft",Ppwft,sizeof(WORKFT));                         //~vbvoR~
	Ppwft->WFTkey[PidxKey]=Ppft->FTkey[PidxKey];                   //~vbvhR~
    UCBITON(Ppwft->WFTkflag[PidxKey],FTDELETED);                   //~vbvhM~
    UTRACEP("%s:after FTnamee=%s,idxKey=%d,WFTkey=x%x,pfwt=%p\n",UTT,Ppft->FTnamee,PidxKey,Ppwft->WFTkey[PidxKey],Ppwft);//~vbvhR~
//  UTRACED("Ppwft",Ppwft,sizeof(WORKFT));                         //~vbvoR~
	return 0;                                                      //~vbvhI~
}//filekeyassign                                                   //~vbvhI~
//**************************************************               //~v0imI~
//*cmd verb assign                                                 //~v0imI~
//*parm1:top WFT                                                   //~v0imI~
//*parm2:current WFT                                               //~v0imI~
//*parm3:cmd string                                                //~v0imI~
//*ret :rc                                                         //~v0imI~
//**************************************************               //~v0imI~
int filecmdvassign(PWORKFT Ppwft0,PWORKFT Ppwft,UCHAR Pcmdv[2][4])//~v0iwR~,//~v71PR~
{                                                                //~v0iwR~,//~v71PR~
    PWORKFT pwft;                                                //~v0iwR~,//~v71PR~
    UCHAR   cmdv[4];                                             //~v0iwR~,//~v71PR~
    int ii,dupsw=0;                                              //~v0iwR~,//~v71PR~
//*********************************                              //~v0iwR~,//~v71PR~
    for (ii=0;ii<2;ii++)                                         //~v0iwR~,//~v71PR~
    {                                                            //~v0iwR~,//~v71PR~
        memcpy(cmdv,Pcmdv[ii],4);                                //~v0iwR~,//~v71PR~
        if (!*cmdv)                                              //~v0iwR~,//~v71PR~
            continue;                                            //~v0iwR~,//~v71PR~
        for (pwft=Ppwft0;pwft!=Ppwft;pwft++)                     //~v0iwR~,//~v71PR~
        {                                                        //~v0iwR~,//~v71PR~
            if (!stricmp(pwft->WFTcmd,cmdv))    //dup            //~v0iwR~,//~v71PR~
                break;                                           //~v0iwR~,//~v71PR~
            if (!stricmp(pwft->WFTcmda,cmdv))   //dup            //~v0iwR~,//~v71PR~
                break;                                           //~v0iwR~,//~v71PR~
        }                                                        //~v0iwR~,//~v71PR~
        if (pwft!=Ppwft)                                         //~v0iwR~,//~v71PR~
        {                                                        //~v0iwR~,//~v71PR~
            dupsw=1;                                             //~v0iwR~,//~v71PR~
            break;                                               //~v0iwR~,//~v71PR~
        }                                                        //~v0iwR~,//~v71PR~
    }                                                            //~v0iwR~,//~v71PR~
    if (dupsw)                                                   //~v0iwR~,//~v71PR~
    {                                                            //~v0iwR~,//~v71PR~
        fileoptdupcmdv(Pcmdv[ii]);                                        //~v0iwR~,//~v71PR~
        return 4;                                                //~v0iwR~,//~v71PR~
    }                                                            //~v0iwR~,//~v71PR~
    memcpy(Ppwft->WFTcmd,Pcmdv[0],4);                            //~v0iwR~,//~v71PR~
    memcpy(Ppwft->WFTcmda,Pcmdv[1],4);                           //~v0iwR~,//~v71PR~
    UTRACEP("%s:WFTcmd=%s,WFTkey[0]=x%x,[1]=x%x,[2]=x%x,[3]=x%x\n",UTT,Ppwft->WFTcmd,Ppwft->WFTkey[0],Ppwft->WFTkey[1],Ppwft->WFTkey[2],Ppwft->WFTkey[3]);//~vbvwR~
    return 0;                                                    //~v0iwR~,//~v71PR~
}//filecmdvassign                                                //~v0iwR~,//~v71PR~
//**************************************************************** //~v67CM~
//* function key line data setup for alias cmd                     //~v67CM~
//* parm1 :pfh                                                     //~v67CM~
//* retrn:rc UALLOC_FAILED                                         //~v67CM~
//**************************************************************** //~v67CM~
int filefkctlinealias(PUFILEH Ppfh)                                //~v67CM~
{                                                                  //~v67CM~
	UQUEH   *pqh,*pqhalct;                                         //~v67CM~
    PALCT   palct;                                                 //~v67CM~
    PULINEH plh,plhprev;                                           //~v67CM~
    UCHAR keyline[FKF_LRECL1];                                     //~v67CM~
    int   len,cmdlen,lrecl,protlen,lreclmax;                       //~v67CM~
//  int ii;                                                        //~vbvoR~
    int rc;                                                        //~vbvoI~
    int swNotJP;                                                   //~vbvwI~
//*****************                                                //~v67CM~
    swNotJP=XE_NOT_ISDBCSJ_OR_N9();                                //~vbvwI~
	pqhalct=&Sqhalct;                                              //~v67CM~
    protlen=Ppfh->UFHprotlen;                                      //~v67CM~
    lreclmax=Ppfh->UFHlrecl;                                       //~v67CM~
	pqh=&(Ppfh->UFHlineque);                                       //~v67CM~
	plh=(PULINEH)UGETQEND(pqh);                                    //~v67CM~
	plhprev=UGETQPREV(plh);     //add after this                   //~v67CM~
//    for (ii=0;;ii++)                                             //~vbvoR~
//    {                                                            //~vbvoR~
//        if (!ScommentAlias[ii])                                  //~vbvoR~
//            break;                                               //~vbvoR~
//        lrecl=(int)strlen(ScommentAlias[ii]);                    //~vbvoR~
//        memcpy(keyline,ScommentAlias[ii],(UINT)lrecl);           //~vbvoR~
//        plh=filealloclh(ULHTDATA,lrecl);                         //~vbvoR~
//        UALLOCCHK(plh,UALLOC_FAILED);//return when storage shortage//~vbvoR~
//        UENQENT(UQUE_AFT,plhprev,plh);                           //~vbvoR~
//        plh->ULHlinenor=plhprev->ULHlinenor+1;                   //~vbvoR~
//        memcpy(plh->ULHdata,keyline,(UINT)lrecl);                //~vbvoR~
//        UTRACED("ULHdata",plh->ULHdata,lrecl);                   //~vbvoR~
//        UCBITON(plh->ULHflag4,ULHF4PROTLINE);   //protected(change line attr)//~vbvoR~
//        plhprev=plh;                                             //~vbvoR~
//    }                                                            //~vbvoR~
  if (swNotJP)                                                     //~vbvwI~
	rc=putComment(0,ScommentAlias,&plhprev);                         //~vbvoI~//~vbvwR~
  else                                                             //~vbvwI~
	rc=putComment(0,ScommentAlias_JP,&plhprev);                    //~vbvwR~
    if (rc)	//UALLOC_FAILED                                        //~vbvoI~
    	return rc;                                                 //~vbvoI~
    memset(keyline,' ',(UINT)lreclmax);                            //~v67CM~
    memcpy(keyline,ALIASID,ALIASIDSZ);                             //~v67CM~
    keyline[protlen]=' ';                                          //~v67CM~
    for (palct=UGETQTOP(pqhalct);;)                                //~v67CM~
    {                                                              //~v67CM~
        lrecl=protlen;                                             //~v67CM~
        if(palct)                                                  //~v67CM~
        {                                                          //~v67CM~
            cmdlen=palct->ALCTcmdlen;                              //~v67CM~
            if (cmdlen>lreclmax-protlen)                           //~v67CM~
                len=lreclmax-protlen;                              //~v67CM~
            else                                                   //~v67CM~
                len=cmdlen;                                        //~v67CM~
            memcpy(keyline+protlen,palct->ALCTcmd,(UINT)len);      //~v67CM~
        }                                                          //~v67CM~
        else                          //add 1 dummy line           //~v67CM~
        	len=0;                                                 //~v67CM~
        lrecl=protlen+len;                                         //~v67CM~
        plh=filealloclh(ULHTDATA,lrecl);                           //~v67CM~
        UALLOCCHK(plh,UALLOC_FAILED);//return when storage shortage//~v67CM~
        UENQENT(UQUE_AFT,plhprev,plh);                             //~v67CM~
        plh->ULHlinenor=plhprev->ULHlinenor+1;                     //~v67CM~
        memcpy(plh->ULHdata,keyline,(UINT)lrecl);                  //~v67CM~
        plhprev=plh;                                               //~v67CM~
        if(!palct)  	//add last dummy entry                     //~v67CM~
        	break;                                                 //~v67CM~
        palct=UGETQNEXT(palct);                                    //~v67CM~
    }                                                              //~v67CM~
    return 0;                                                      //~v67CM~
}//filefkctlinealias                                               //~v67CM~
//**************************************************************** //~v67CM~
//* setup alias cmd tbl(<--kdbrfkct<--ini3),after edit fkct        //~v67CM~
//* retrn:rc UALLOC_FAILED                                         //~v67CM~
//**************************************************************** //~v67CM~
int filesetupalct(void)                                            //~v67CM~
{                                                                  //~v67CM~
    PALCT   palct;                                                 //~v67CM~
    PSCKT   psckt;                                                 //~v67CM~
    UCHAR *pc,*pce,*pc2,*pcmd;                                     //~v67CM~
    int   len,cmdlen=0,rc=0;                                       //~v699R~
//*****************                                                //~v67CM~
	uqufree(&Sqhalct);	//free old                                 //~v67CM~
    psckt=Gkbdsckt+(SCKTALIAS-SCKTTOP);                            //~v67CM~
    for (pc=psckt->SCKTcmd,pce=pc+psckt->SCKTcmdlen;pc<pce;pc+=cmdlen+1)//~v67CM~
    {                                                              //~v67CM~
	    cmdlen=(int)strlen(pc);                                    //~v699R~
//      palct=ucalloc(1,(UINT)(ALCTSZ+cmdlen+1));                  //~v699R~//~vb2DR~
        palct=ucalloc(1,(UINT)((int)ALCTSZ+cmdlen+1));             //~vb2DI~
        UALLOCCHK(palct,UALLOC_FAILED);//return when storage shortage//~v67CM~
        pcmd=palct->ALCTcmd;                                       //~v67CR~
        memcpy(pcmd,pc,(UINT)(cmdlen));                            //~v67CM~
        pc2=strchr(pc,' ');                                        //~v67CM~
        if (pc2)                                                   //~v67CM~
//        	len=(int)((ULONG)pc2-(ULONG)pc);                       //~v699R~//~vafkR~
        	len=(int)((ULPTR)pc2-(ULPTR)pc);                       //~vafkI~
        else                                                       //~v67CM~
        	len=cmdlen;                                            //~v67CM~
        if (len>3)                                                 //~v67CM~
        	len=3;                                                 //~v67CM~
        memcpy(palct->ALCTcmdverb,pc,(UINT)len);                   //~v699R~
        palct->ALCTcmdlen=cmdlen;                                  //~v67CM~
        if (filesrchalct(palct->ALCTcmdverb,0))                    //~v67CI~
        {                                                          //~v67CM~
            rc=4;                                                  //~v67CM~
        	uerrmsg("%s is duplicated command alias",0,            //~v67CM~
					palct->ALCTcmdverb);                           //~v67CM~
        }                                                          //~v67CM~
        UENQ(UQUE_END,&Sqhalct,palct);                             //~v67CM~
    }                                                              //~v67CM~
    return rc;                                                     //~v67CM~
}//filesetupalct                                                   //~v67CM~
//**************************************************************** //~v67CI~
//* setup sckt for alias to write at term                          //~v67CR~
//* retrn:rc UALLOC_FAILED                                         //~v67CI~
//**************************************************************** //~v67CI~
int filesetupscktalias(UQUEH *Ppqhalct)                            //~v67CR~
{                                                                  //~v67CI~
    PSCKT   psckt;                                                 //~v67CI~
    PALCT   palct;                                                 //~v67CI~
    UCHAR *pc,*pcmd;                                               //~v67CI~
    int   len;                                                     //~v67CI~
//*****************                                                //~v67CI~
    psckt=Gkbdsckt+(SCKTALIAS-SCKTTOP);                            //~v67CI~
    if (psckt->SCKTcmd)                                            //~v67CI~
    	ufree(psckt->SCKTcmd);	//free old                         //~v67CR~
    for (palct=UGETQTOP(Ppqhalct),len=0;palct;palct=UGETQNEXT(palct))//~v67CI~
    {                                                              //~v67CI~
    	len+=palct->ALCTcmdlen+1;                                  //~v67CI~
    }                                                              //~v67CI~
    if (!len)                                                      //~v67CI~
	    return 0;                                                  //~v67CI~
    pcmd=umalloc((UINT)len);                                       //~v67CI~
    UALLOCCHK(pcmd,UALLOC_FAILED);//return when storage shortage   //~v67CI~
    psckt->SCKTcmd=pcmd;                                           //~v67CI~
    psckt->SCKTcmdlen=(USHORT)len;                                 //~v699R~
    for (palct=UGETQTOP(Ppqhalct),pc=pcmd;palct;palct=UGETQNEXT(palct))//~v67CI~
    {                                                              //~v67CI~
    	len=palct->ALCTcmdlen;                                     //~v67CI~
        memcpy(pc,palct->ALCTcmd,(UINT)len);                       //~v67CI~
        pc+=len;                                                   //~v67CI~
        *pc++=0;                                                   //~v67CI~
    }                                                              //~v67CI~
    UTRACED("pcmd",pcmd,len);                                      //~vbvwI~
    return 0;                                                      //~v67CI~
}//filesetupscktalias                                              //~v67CI~
//**************************************************************** //~v67CM~
//* accept alias cmd key change                                    //~v67CM~
//* parm1 :plh                                                     //~v67CM~
//* parm2 :quehdr to enq ALCT                                      //~v67CI~
//* retrn:rc UALLOC_FAILED or err(dup with org cmd or alias)       //~v67CI~
//**************************************************************** //~v67CM~
int filefksavealias(PULINEH Pplh,UQUEH *Ppqhalct)                  //~v67CI~
{                                                                  //~v67CM~
    UCHAR *pcmd,*palctcmd,*pc;                                     //~v67CR~
    int cmdlen,skip,len;                                           //~v67CR~
    UCHAR verb[4];                                                 //~v67CM~
    FUNCTBL *pft;                                                  //~v67CM~
    PALCT palct;                                                   //~v67CI~
//*****************                                                //~v67CM~
	pcmd=Pplh->ULHdata+ALIASIDSZ;                                  //~v67CM~
    cmdlen=Pplh->ULHlen-ALIASIDSZ;                                 //~va0aI~
    if (cmdlen<=0)                                                 //~va0aI~
    	return 0;                                                  //~va0aI~
//  skip=(int)strspn(pcmd," \t");                                  //~v699R~//~va0aR~
//  skip=(int)ustrnspn(pcmd," \t",cmdlen);                         //~va0aR~//~vb2DR~
//  skip=(int)ustrnspn(pcmd," \t",(size_t)cmdlen);                 //~vb2DI~//~vb2ER~
    skip=(int)ustrnspn(pcmd," \t",(UINT)cmdlen);                   //~vb2EI~
    pcmd+=skip;                                                    //~v67CM~
    cmdlen=Pplh->ULHlen-(ALIASIDSZ+skip);                          //~v67CM~
    cmdlen-=(int)umemrspn(pcmd," \t",(UINT)cmdlen);	//drop trailer space//~v699R~
    if (!cmdlen)                                                   //~v67CM~
    	return 0;                                                  //~v67CM~
    pc=strchr(pcmd,' ');                                           //~v67CM~
    if (!pc)                                                       //~v67CM~
    	len=cmdlen;                                                //~v67CM~
    else                                                           //~v67CM~
//    	len=(int)((LONG)pc-(ULONG)pcmd);                           //~v699R~//~vafkR~
    	len=(int)((ULPTR)pc-(ULPTR)pcmd);                          //~vafkR~
    if (len>3)                                                     //~v67CM~
    	len=3;                                                     //~v67CM~
    memcpy(verb,pcmd,(UINT)len);                                   //~v67CM~
    *(verb+len)=0;                                                 //~v67CM~
    if (*verb!=ALIASCMT)//not comment                              //~v67CR~
    {                                                              //~v67CI~
        if (pft=functblsrchbycmd(verb),pft)                        //~v67CI~
        {                                                          //~v67CI~
            uerrmsg("Alias \"%s\" is already used by function %s",0,//~v67CI~
                    verb,pft->FTnamee);                            //~v67CI~
            return 4;                                              //~v67CI~
        }                                                          //~v67CI~
        if (filesrchalct(verb,Ppqhalct)) //dup alias chk           //~v67CR~
        {                                                          //~v67CI~
            uerrmsg("Alias \"%s\" is duplicated",0,                //~v67CI~
                    verb);                                         //~v67CI~
            return 4;                                              //~v67CI~
        }                                                          //~v67CI~
    	if (len==cmdlen)	//no alias defined(key only)           //~v67CI~
        {                                                          //~v67CI~
            uerrmsg("no cmd defined for key \"%s\"",0,             //~v67CI~
                    verb);                                         //~v67CI~
            return 4;                                              //~v67CI~
        }                                                          //~v67CI~
    }                                                              //~v67CI~
//  palct=ucalloc(1,(UINT)(ALCTSZ+cmdlen+1));                      //~v699R~//~vb2DR~
    palct=ucalloc(1,(UINT)((int)ALCTSZ+cmdlen+1));                 //~vb2DI~
    UALLOCCHK(palct,UALLOC_FAILED);//return when storage shortage  //~v67CI~
    palctcmd=palct->ALCTcmd;                                       //~v67CR~
    strcpy(palct->ALCTcmdverb,verb);                               //~v67CI~
    memcpy(palctcmd,pcmd,(UINT)cmdlen);                            //~v67CR~
    palct->ALCTcmdlen=cmdlen;                                      //~v67CI~
    UENQ(UQUE_END,Ppqhalct,palct);                                 //~v67CI~
    return 0;                                                      //~v67CM~
}//filefksavealias                                                 //~v67CM~
//**************************************************************** //~v67CM~
//* search alct entry                                              //~v67CM~
//* p2:alctq:default is Sqhalct                                    //~v67CR~
//* retrn:alct                                                     //~v67CI~
//**************************************************************** //~v67CM~
PALCT filesrchalct(char *Pcmd,UQUEH *Ppqhalct)                     //~v67CI~
{                                                                  //~v67CM~
    PALCT   palct;                                                 //~v67CM~
    UQUEH   *pqh;                                                  //~v67CR~
//*****************                                                //~v67CM~
	if (!(pqh=Ppqhalct))                                           //~v67CR~
    	pqh=&Sqhalct;                                              //~v67CR~
    if (*Pcmd==ALIASCMT)                                           //~v67CI~
        return 0;                                                  //~v67CI~
    for (palct=UGETQTOP(pqh);palct;palct=UGETQNEXT(palct))         //~v67CI~
    {                                                              //~v67CM~
	    if (!stricmp(Pcmd,palct->ALCTcmdverb))                     //~v67CM~
        	return palct;                                          //~v67CM~
    }                                                              //~v67CM~
    return 0;                                                      //~v67CM~
}//filesrchalct                                                    //~v67CM~
//**************************************************************** //~v0ihI~
//* errmsg                                                         //~v0ihI~
//* parm1 :none                                                    //~v0ihI~
//* retrn:4                                                        //~v0ihI~
//**************************************************************** //~v0ihI~
int filekeynameerr(void)                                           //~v0ihI~
{                                                                  //~v0ihI~
	uerrmsg2("Invalid Key name",                                   //~v0ihI~
				"キー名エラー");                                   //~v0ihR~
    return 4;                                                      //~v0ihI~
}//filekeynameerr                                                  //~v0ihI~
//**************************************************************** //~v0imI~
//* errmsg                                                         //~v0imI~
//* parm1 :none                                                    //~v0imI~
//* retrn:4                                                        //~v0imI~
//**************************************************************** //~v0imI~
int fileoptlreclerr(void)                                          //~v0imI~
{                                                                  //~v0imI~
	uerrmsg2("Inavalid Recrd length",                              //~v0imI~
             "レコード長エラー");                                  //~v0imI~
	return 4;                                                      //~v0imI~
}//fileoptlreclerr                                                 //~v0imI~
//**************************************************************** //~v0imI~
//* errmsg                                                         //~v0imI~
//* parm1 :none                                                    //~v0imI~
//* retrn:4                                                        //~v0imI~
//**************************************************************** //~v0imI~
int fileoptfuncnmerr(void)                                         //~v0imI~
{                                                                  //~v0imI~
	uerrmsg2("Function name err",                                  //~v0imI~
             "機\x94\\名エラー");                                  //~v0imI~
	return 4;                                                      //~v0imI~
}//fileoptfuncnmerr                                                //~v0imI~
//**************************************************************** //~v0imI~
//* errmsg                                                         //~v0imI~
//* parm1 :none                                                    //~v0imI~
//* retrn:4                                                        //~v0imI~
//**************************************************************** //~v0imI~
int fileoptfixederr(void)                                          //~v0imI~
{                                                                  //~v0imI~
	uerrmsg2("This key is fixed",                                  //~v0imI~
             "このキーは割当変更出来ません");                      //~v0imI~
	return 4;                                                      //~v0imI~
}//fileoptfixederr                                                 //~v0imI~
//**************************************************************** //~v0imI~
//* errmsg                                                         //~v0imI~
//* parm1 :none                                                    //~v0imI~
//* retrn:4                                                        //~v0imI~
//**************************************************************** //~v0imI~
int fileoptkeyoverflow(void)                                       //~v0imI~
{                                                                  //~v0imI~
	uerrmsg2("Max assignment is %d key",                           //~v0imI~
             "最大割当数は %d キー",                               //~v0imI~
             FTMAXKEY);                                            //~v0imI~
	return 4;                                                      //~v0imI~
}//fileoptkeyoverflow                                              //~v0imI~
//**************************************************************** //~v0imI~
//* errmsg                                                         //~v0imI~
//* parm1 :none                                                    //~v0imI~
//* retrn:4                                                        //~v0imI~
//**************************************************************** //~v0imI~
int fileoptcmdfmterr(void)                                         //~v0imI~
{                                                                  //~v0imI~
	uerrmsg2("Command verb format err",                            //~v0imI~
             "コマンド指定の誤り");                                //~v0imI~
	return 4;                                                      //~v0imI~
}//fileoptcmdfmterr                                                //~v0imI~
//**************************************************************** //~v0imI~
//* errmsg                                                         //~v0imI~
//* parm1 :none                                                    //~v0imI~
//* retrn:4                                                        //~v0imI~
//**************************************************************** //~v0imI~
//int fileoptdupcmdv(void)                                         //~v71PR~
int fileoptdupcmdv(char *Pverb)                                    //~v71PI~
{                                                                  //~v0imI~
//	uerrmsg2("Duplicated command verb",                            //~v71PR~
//             "重複コマンド");                                    //~v71PR~
	uerrmsg2("Duplicated command verb(%s)",                        //~v71PI~
             "重複コマンド(%s)",                                   //~v71PI~
				Pverb);                                            //~v71PI~
	return 4;                                                      //~v0imI~
}//fileoptdupcmdv                                                  //~v0imI~
//**************************************************************** //~v0imI~
//* errmsg                                                         //~v0imI~
//* parm1 :none                                                    //~v0imI~
//* retrn:4                                                        //~v0imI~
//**************************************************************** //~v0imI~
#ifndef KKK                                                        //~vb50I~
int fileoptdupassign(char *Pkeyname)                               //~vb50R~
#else                                                              //~vb50I~
int fileoptdupassign(void)                                         //~v0imI~
#endif                                                             //~vb50I~
{                                                                  //~v0imI~
#ifndef KKK                                                        //~vb50I~
	uerrmsg2("Duplicated assign(%s)",                              //~vb50I~
             "重複割当(%s)",                                       //~vb50I~
                Pkeyname);                                         //~vb50I~
#else                                                              //~vb50I~
	uerrmsg2("Duplicated assign",                                  //~v0imI~
             "重複割当");                                          //~v0imI~
#endif                                                             //~vb50I~
	return 4;                                                      //~v0imI~
}//fileoptdupassign                                                //~vb50R~
