//*CID://+vbg0R~:                             update#=  699;       //+vbg0R~
//*************************************************************    //~v08qI~
//*xefile5.c*                                                      //~v08qI~
//* miscellenious function                                         //~v08qI~
//*************************************************************    //~v08qI~
//vbg0:180123 (BUG)errmsg "conflict recordmode and CPU8" evenif profile record has cplc option,rejected at optopn prechk//+vbg0I~
//vbc0:170814 reject FixedRecordLength mode for CPU8 file(because record Length!=Column width)//~vbc0I~
//vb60:161127 select 1st entry when no filename operand (S [-n] n:line number)//~vb60I~
//vb2E:160229 LNX64 compiler warning                               //~vb2EI~
//vb2j:160129 (LNX)use FN{LC|U8} option translate input filename u8<-->lc regardless A+u kbd mode//~vb2jI~
//vb2g:160124 Select dcmd accept mount option if FN{U8|LC} was not specified//~vb2gI~
//vb2f:160124 (BUG)CP{U8|LC} dose not mean FN{U8|LC}               //~vb2fI~
//vb13:150529 by xuerpck(uerrmsg parm chk)                         //~vb13I~
//vazu:150114 (BUG)partial edit;if save failed,for next save keep UFHelinepos because org file was not changed.//~vazuI~
//vazt:150114 (BUG)"UCHAR UFHpathlen" is invalid when _MAX_PATH>256//~vaztI~
//vazs:150114 (BUG)partial edit;if outfile!=0(save to another file) original file endposition is not changed.=>outfile length did not expand at 2nd save//~vazsI~
//vaz8:150109 C4244 except ULPTR and ULONG                         //~vaz8I~
//vaz5:150107 errmsg "no space" is not valid for partial edit outfile open err by permission//~vaz4I~
//vaz4:150107 (BUG)did not closed out file when partial copy error //~vaz4I~
//vaz0:150105 BUG:offset value is long long for fseek error msg    //~vaz0I~
//vauA:140315 (BUG)u8 membername on dir list by fnu8 option,but fhfilename is treated by lc by env:lc on windows//~vauaI~
//            support select lcmd but not for Select cmd(may specify path, so use FNU8 cmd option for select cmd)//~vauaI~
//van8:131130 (BUG)-ML is confused, EL-COBOL and Lineno;drop EL meaning//~van8I~
//vajq:130815 accept /me for append non-ebc to ebc                 //~vajqI~
//vajh:130812 (BUG)record mode file;tab was replaced to space like as spf fixlrecl file//~vajhI~
//vajg:130807 (BUG)/Mh is not same as EH cmd for RECORD mode file(lrecl is set as UFHwidth)//~vaj6I~
//vaj6:130722 accept -Flrecl without /MR to reset FIXLRECL by -F0 for End cmd//~vaj6I~
//vaj0:130710 localfile:recfm=V support (E /mV F{MFH|F|H})         //~vaj0I~
//vagE:120918 apply cmdline option /U{N|F}{8|L} to also edit/browse cmd//~vagEI~
//vafk:120624 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  use ULPTR(unsigned __int64/ULONG)//~vafkI~
//vaf9:120607 (WTL)Bug found by vs2010exp(used uninitialized variable),avoid warning C4701//~vaf8I~
//vaf8:120607 (WTL)Bug found by vs2010exp(used uninitialized variable)//~vaf8I~
//vaa7:111117 (gcc4.6)Warning:unused-but-set                       //~vaa7I~
//va86:100921 (BUG)Warning "CPU8 ignored" for eh cmd if profile has cpu8 attr.//~va86I~
//va83:100921 (BUG)bseopt didnot clear ebc mode of profile status(xprint work)//~va83I~
//va7R:100907 (EBC:BUG)rep/cut width no CPEB option did'nt set Cvname to profile//~va7RI~
//va7K:100904 add RESET option to cv cmd B2B(change UFHhandle) and CPEB option to RESet cmd.//~va7KI~
//va7t:100823 EBC:handle support to file output(save/rep/..)       //~va7tI~
//va79:100809 cpeb converter parm support                          //~va79I~
//va6S:100724 (BUG) END cmd has no filename parm. cmd flag "/" is avalable from 1st//~va6SI~
//va6Q:100722 Fxx+/MxR is output lrecl for end/save/rep.. input lrecl for copy cmd//~va6QI~
//va6N:100721 add eol when /mET                                    //~va6NI~
//va6J:100721 exclusive chk for eb and /mt, et and /mb             //~va6JI~
//va6H:100719 (BUG) /Mx option rejected for Rep/Save..             //~va6HR~
//va6D:100719 EBC eol 0x15 support                                 //~va6DI~//~va6HR~
//va6B:100716 allow cplc option to eb cmd to chk by bin mode       //~va6BI~//~va6HR~
//va6i:100622 COPY cmd;chk CPxx profile of copy source file        //~va6iI~//~va6HR~
//va6c:100619 add SOSI option -S{i|r|d} to REP/CRE/APP/SAV/COP/MOV cmd//~va6cI~
//va66:100618 add "R"(record mode write) to REP/CRE/SAV cmd        //~va66I~
//va64:100617 (BUG)vhex mode if /mr specified                      //~va64I~
//va61:100602 allow binaly opend file translation;b2l/b2u          //~va61I~
//va60:100602 allow binaly opend file translation;l2b              //~va60I~
//va5Y:100601 tab translation rule of EBC file                     //~va5YI~
//            save: NOTC/TC option is Invalid for ebc file(keep tab 0x05 and 0x09)//~va5YI~
//            rep:  nonEBC->EBC ignore source NOTC/TC option,always translate tab//~va5YI~
//            load:NOTC option is valid for fixLrecl for excep EBC file;tabctr=1,TC as default//~va5YI~
//va5U:100526 update profile by edit cmd with P[0|1] option        //~va5UI~
//va5e:100510 drop eol by /mpr                                     //~va5eI~
//va5d:100510 reset record mode on profile also by f0 parameter    //~va5dI~
//va58:100430 not Va52,but reset UFHmergin when EH mode            //~va58I~
//va55:100425 (BUG)save/rep cmd did not update profile when cplc   //~va55I~
//va52:100415 rejext Fn[-m] option for EH cmd(because display margin attr)//~va52I~
//va51:100415 Record mode file option, /MR                         //~va51R~
//va50:100324 Raw EBCDIC file support for NFS mount                //~va50I~
//va1p:091104_(UTF8)file/dir default encoding option by UTF cmd    //~va1pI~
//va1a:091027_(BUG)=6 panel shouldbe "u" not "U"(not parm but by env)//~va1aI~
//va0C:090721_set wxp work CPxx to the same as source file         //~va00I~
//va0m:090811 reject CPU8/CPLC for bin file                        //~va0mI~
//va00:090510 merge utf8 version(enclosed by UTF8SUPPH)            //~va00I~
//          files encoded by utf8                                  //~va00I~
//            Edit/Browse/end/create/rep/app/save cmd support CPU8/CPLC//~va00I~
//            No Width[C]                                          //~va00I~
//          save option "IE"(ignore translation err)               //~va00I~
//          select cmd chk cpu8/cplc of dir open parm              //~va00I~
//          save CPxx to profile                                   //~va00I~
//          Edit/Browse [CPLC|CPU8|CPAS|] [IE]                     //~va00I~
//v92n:080802 (UTF)add  [cplc|cpu8] option for save cmd            //~v92nI~//~va00I~
//v794:080722 (VC8)valiable initialed validation chk               //~v794I~
//v78w:080402*(UTF8)profile function                               //~v78wI~//~va00M~
//v78r:080326 profile function                                     //~v78rI~
//v783:080227 CUT/PASTE cmd to use another clipboard(save/restore each time)//~v783I~
//v922:080107 (UTF)explicitly display locale file id on hdr line even when not uytf8 env//~v922I~//~va00I~
//v91Q:071227 (UTF)edit cmd width[c] option(width is by column)    //~v91QI~//~va00I~
//v91H:071221 (UTF8)common errmsg not supported under no-utf8 mode //~v91HI~//~va00I~
//v917:071130 (UTF8)assign A+u to switch kbd conversion mode between asis and conv mode//~v917I~//~va00I~
//v90z:071127 (UTF8)OPT MODE {L2U|U2L} cmd for conv kbd input      //~v90zI~//~va00I~
//v90w:071124 (UTF8) MODE command                                  //~v90wI~//~va00I~
//v90u:071116 (UTF8) ignore utf8 mode for so(=6) file              //~v90uI~//~va00I~
//v76X:071107 save option [NB|BK]                                  //~v76XI~
//v90n:071026 (UTF8) utf is option for each file                   //~v90nI~//~va00I~
//v76z:070820 no bkup option to bypass rename at save              //~v76zI~
//v75H:070508 e8("e /f80 p1") command support. lcmd "8" on fname-list and dir-list.//~v75HI~
//v71V:061113 add tabclear option to edit cmd. TC|NTC. set TC on if -F specified.//~v71VI~
//v71L:061104 CAP option save and apply as default or apply TSO only//~v71LI~
//v71K:061103 NONUM/Fxx option for TSO SPF file(reset dfault num fld)//~v71KI~
//v69J:060712 cap(CAPS LOCK On) support                            //~v69JI~
//v690:060418 display file-description support on dir-list panel   //~v690I~
//v668:050824 (BUG)edit -L (listdir option) is not effective by v62x//~v668I~
//v665:050822 (BUG)save cmd abend when invalid option specified with / or - (pc2 not setupped)//~v665I~
//v63e:050429 (BUG)edit cmd "S" option of /MxxS is reject          //~v63eI~
//v62H:050413 exe cmd label support                                //~v62HI~
//v62x:050402 cmd line parameter /Lnn : initial Locate cmd(/L is listdir option)//~v62xI~
//            (/Ln-m option deleted;simply use n-m or /on-m for hex offset)//~v62xI~
//v616:050212 accept -p(protect) option for binfile                //~v616R~
//            p0:not protected margined,p1:protected magined,no p:not margined//~v616I~
//v60v:050201 virtual hex display option(/Mx,HEX on/off)           //~v60vI~
//v60s:050130 support display width change without close current opened//~v60sI~
//v60e:050123 (UNX:BUG)partial edit utempnam r.c chk err(errmsg issues)//~v60eR~
//v59y:041114 set unix mode fpor default save option to remote file//~v59yI~
//v582:040822 (BUG)../ and ..\ is treated as label for rep/cre/app cmd//~v582I~
//v57P:040620 cre/rep/app change deault to ALL when with labal range parm//~v57PI~
//v57y:040605 (BUG)./ and .\ is treated as label for rep/cre/app cmd//~v57yI~
//v57w:040605 (BUG)edit help missing tail option                   //~v57wI~
//v55e:040211 (FTP:BUG)partial edit tempfile should be local file  //~v55eI~
//v559:040201 "cre/rep/sav/app" cmd parm fmt chng  {x | nx} [all | .a .b]//~v559I~
//v54Y:040201 "cre/rep/sav/app" support xall nxall .a .b           //~v54YI~
//v54c:040102 support tail option for edit numrange (nnt-mmt)      //~v54cI~
//v546:040101 (FTP:BUG)partial file edit fail                      //~v546I~
//v48d:020429 (UNX)create partial edit temp file on /tmp for mdos disk//~v48dI~
//v47X:020413 mac file support(eol=0x0d)                           //~v47xI~
//v47T:020406 eol-id change option for cre/rep/app/sav/end cmd     //~v47TI~
//v47v:020316 COBK w/o N is not spf(allow any char in col.1-6;any lrecl)//~v47vI~
//            for cobk,set cid pos default=col73 if cid is not defined(other than //,;;,||)//~v47vI~
//v471:020202 (BUG)dir list disply even if only one wildcard member exist//~v471I~
//v45a:011209 edit cmd help;ec eh etc                              //~v45aI~
//v459:011209 allow file width parm on not last part of /M         //~v459I~
//v44h:011204 cobol naming chng                                    //~v44hI~
//            K:cobol with no num,L:cobol with space,I:spf K,J:spf L//~v44hI~
//            L mean 2 case,/Ml is cob,/Mbl binary lineno attr     //~v44hI~
//            keep remain /Mc(=/Ml).                               //~v44hI~
//            (xe.ini to be deleted)                               //~v44hI~
//v44e:011203 use not x but h for hex display                      //~v44eI~
//v440:011125 browse hex                                           //~v440I~
//v42y:011010 add cmd ek,bk,sk,ekn,bkn,skn                         //~v42xI~
//v42x:011010 col1-6=space cobol by /Mk(change option=cob2-->cobk) //~v42xI~
//v42n:011006 "/P"(no 1 nor 0) of edit cmd means now /p1           //~v42nI~
//v42m:011006 change default protopt for margined file or spf cmd  //~v42mI~
//v41h:010806 option effective sequenc:topline>cmd option>default  //~v41hI~
//v41g:010804 /P{0|1} option for margin protection for edit        //~v41gI~
//v414:010728 EC/ENC/BC/BNC/SC/SNC cmd add for cobol               //~v414I~
//v40u:010617 wild-card support for path name if dir contain only one member.//~v40uI~
//            (replace v143)                                       //~v40uI~
//v19s:000917 LINUX support(Edit cmd parm by also - additionaly /) //~v19sI~
//v185:010128 browse/edit file when only one menmber of dir is optional by /l option(dir list)//~v185I~
//v13q:991108 bin file min width change 10 to 16                   //~v139I~
//v11A:990821 edit option /N(lineno type) is conflict with /N(yes/no) option//~v11AI~
//            change to /Mo(offset),/Ml(lineno). /I is also conflict.//~v11AI~
//v11z:990821 support filename=* (last closed file) on cmd line    //~v11zI~
//v11i:990718 edit cmd help                                        //~v11iI~
//v119:990619 change edit option X-->O(ffset),N-->L(ineno)         //~v119I~
//v110:990606 input range by x____ for alternative of /Nx____      //~v110I~
//v10Y:990606 support input range by hex offset value(/NXxxx-Xxxx) for edit/browsw cmd//~v10YI~
//            (lineno is couted from 1 even if offset!=0)          //~v10YI~
//v10X:990605 hex digit lineno display for binary file             //~v10XI~
//        (default is effective for binary only,for text use opt each time)//~v10XI~
//           (/N option for edit/browse cmd)                       //~v10XI~
//v10L:990424 EN/BN/SN edit/browse command for SPF file specific.(No cid,margin=72,P=1)//~v10LI~
//v10E:990417 another width value save for edit                    //~v10EI~
//v10D:990417 limit screen width function to browse only           //~v10DI~
//v10x:990410 change display width keep is option /mnnS            //~v10xI~
//v10w:990410 display width for eah text and binary                //~v10wI~
//v10u:990406 read mode default is PC and UNIX(write mode is PC if 0d0a found)//~v10uI~
//            m option for mix for read                            //~v10uI~
//v10m:990322 binary mode specification change /Mx-->/Mb,and save width once used//~v10mI~
//            until next explicit specification.(save also to sav file)//~v10mI~
//v10e:981218 e/b cmd display width parm for bin file              //~v10eI~
//v10c:981218 if explicitly text mode specified,request no optbin  //~v10cI~
//v107:981213 use new opt of ufgetsinit for binary chk(del filechkbin)//~v107I~
//v0hK:980418 binary file chk.(reject tab clear)                   //~v0hKI~
//v0f0:971010 long filename support                                //~v0f0I~
//            file5.c/dlcmd4.c:ext search from last                //~v0f0I~
//v0ac:970712 option without -   /Mrw format                       //~v0acI~
//v0ab:970712:write by binaly mode                                 //~v0abI~
//v0aa:970708:default write mode set from read mode                //~v0aaR~
//            default-Read:PC   default Write:PC                   //~v0aaI~
//                    Read:UNIX default Write:UNIX                 //~v0aaI~
//                    Read:TEXT default Write:PC                   //~v0aaI~
//                    PC  -->PC  :0d0a-->0d0a  ,0a-->0a            //~v0abI~
//                    PC  -->UNIX:0d0a-->0a    ,0a-->0a            //~v0abI~
//                    UNIX-->UNIX:0d0a-->0d0a  ,0a-->0a            //~v0abI~
//                    UNIX-->PC  :0d0a-->0d0d0a,0a-->0d0a          //~v0abI~
//                    TEXT-->PC  :0d0a-->0d0a  ,0a-->0d0a          //~v0abI~
//                    TEXT-->UNIX:0d0a-->0a    ,0a-->0a            //~v0abI~
//v09Y:970629:file NULL(0x00) support                              //~v09YI~
//            edit/brows /Mrmode-wmode option mode=PC/UNIX         //~v0acR~
//v095:970405:DPMI version                                         //~v095I~
//            -errno need errno.h(c6 has it in stdlib.h)           //~v095I~
//v08q:961123:edit partial file(continued from v08l)               //~v08qI~
//v08l:961123:edit/browse line range parameter                     //~v08qI~
//*************************************************************    //~v08qI~
#include <time.h>                                                  //~v08qI~
#include <stdio.h>                                                 //~v08qI~
#include <stddef.h>                                                //~v08qI~
#include <stdlib.h>                                                //~v08qI~
#include <ctype.h>                                                 //~v08qI~
#include <string.h>                                                //~v08qI~
#ifdef DOS                                                         //~v08qI~
    #ifdef DPMI					//DPMI version                     //~v095I~
        #include <errno.h>                                         //~v095I~
    #else                       //not DPMI                         //~v095I~
    #endif                      //DPMI or not                      //~v095I~
#else                                                              //~v08qI~
//  #define INCL_BASE                                              //~v08qI~
//  #include <os2.h>                                               //~v08qI~
#endif                                                             //~v08qI~
//*******************************************************          //~v08qI~
#include <ulib.h>                                                  //~v08qI~
#include <uerr.h>                                                  //~v08qI~
#include <uque.h>                                                  //~v08qI~
#include <ustring.h>                                               //~v08qI~
#include <ufile.h>                                                 //~v08qI~
#include <ufile4.h>                                                //~v08qI~
#include <ufile5.h>                                                //~vaj0I~
#include <uedit.h>                                                 //~v08qI~
#include <udbcschk.h>                                              //~v08qI~
#include <uparse.h>                                                //~v559I~
#include <uftp.h>                                                  //~v59yI~
#include <utrace.h>                                                //~vaj0I~
#ifdef UTF8SUPPH                                                   //~va00I~
#include <utf.h>                                                   //~v90nI~//~va00I~
#endif                                                             //~va00I~
                                                                   //~v08qI~
#include "xe.h"                                                    //~v08qI~
#include "xescr.h"                                                 //~v08qI~
#include "xefile.h"                                                //~v08qI~
#include "xefile42.h"                                              //~v41hI~
#include "xefile22.h"                                              //~v440I~
#include "xefile5.h"                                               //~v08qI~
#include "xeerr.h"                                                 //~v08qI~
#include "xefsub.h"                                                //~v08qR~
#include "xesub.h"                                                 //~v08qI~
#include "xefunc.h"                                                //~v47TI~
#include "xefcmd.h"                                                //~v783I~
#include "xefcmd22.h"                                              //~v559I~
#include "xefcmd4.h"                                               //~v54YI~
#include "xelcmd.h"                                                //~v57yR~
#include "xeopt.h"                                                 //~v71LI~
#include "xesyn.h"                                                 //~v78rI~
#include "xefcmd6.h"                                               //~v78rI~
#ifdef UTF8SUPPH                                                   //~va00I~
#include "xeutf.h"                                                 //~v90nI~//~va00I~
#endif                                                             //~va00I~
#include "xeebc.h"                                                 //~va50I~
//*******************************************************          //~v08qI~
#define MIN_WIDTH  16                                              //~v139R~
#define TAIL_OPTION 't'                                            //~v54cI~
#define LANGOPT_UTF8    MODE_UTF8                                  //~v90wR~//~va00I~
#define LANGOPT_UTF8SZ    4                                        //~v90nI~//~va00I~
#define LANGOPT_LOCALE  MODE_LOCALE                                //~v90wR~//~va00I~
#define LANGOPT_LOCALESZ  4                                        //~v90nI~//~va00I~
#define LANGOPT_ASIS    MODE_ASIS                                  //~v78wI~//~va00I~
#define LANGOPT_ASISSZ    4                                        //~v78wI~//~va00I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	#define CPOPT_EBC     'E'                                      //~va50R~
	#define EOLOPT_EBC    'E'                                      //~va6DI~
	#define EOLOPT_EBCS   "E"                                      //~va6DI~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
#define ERRFORBINFILE(pfh,optstr) \
	if (UCBITCHK((pfh)->UFHflag4,UFHF4BIN)) \
			return erroptionforbinfile(optstr,4);                  //~va6JI~
//*******************************************************          //~v60sI~
static int Sswprechk=0;                                            //~v60sI~
static int Sprechkprofileopt=0;	//prechk option to be passed to getprofile//~v78rI~
//*******************************************************          //~v10YI~
//int fileparmxrange(PUFILEH Ppfh,UCHAR *Pstr,ULONG *Ppxranges,ULONG *Ppxrangee);//~vaz0R~
int fileparmxrange(PUFILEH Ppfh,UCHAR *Pstr,FILESZT *Ppxranges,FILESZT *Ppxrangee);//~vaz0I~
int fileerrexclusiveopt(void);                                     //~v47TI~
int fileerrchange2mfh(int Prc);                                    //~vaj0R~
int fileerrlreclforV(int Prc);                                     //~vaj0I~
int fileerrvfmtforR(int Prc);                                      //~vaj0I~
//**************************************************************** //~va6DI~
int fileerrebcdicoptopn(int Popt,char *Pprm)                       //~va6DI~
{                                                                  //~va6DI~
	uerrmsg("/M%s is for ebcdic text file only",0,                 //~va6DI~
             Pprm);                                                //~va6DI~
    return 4;                                                      //~va6DI~
}//fileerrebcdicoptopn                                             //~va6DI~
//**************************************************************** //~v08qI~
// filetempname                                                    //~v08qI~
#ifdef UNX                                                         //~v48dI~
//*(UNX)get temporary file name on /tmp                            //~v48dI~
#else                                                              //~v48dI~
//*get temporary file name on the same dir                         //~v08qI~
#endif                                                             //~v48dI~
//*parm1:pfh                                                       //~v08qI~
//*rc   :0 ok,4 err                                                //~v08qR~
//**************************************************************** //~v08qI~
int filetempname(PUFILEH Ppfh)                                     //~v08qI~
{                                                                  //~v08qI~
#ifdef UNX                                                         //~v48dI~
	int rc;                                                        //~v55eI~
#else                                                              //~v48dI~
  #ifdef FTPSUPP                                                   //~v55eI~
    char fpath[_MAX_PATH];                                         //~v55eI~
  #endif                                                           //~v55eI~
    char *pce,*pcf,*pc0;                                           //~v08qR~
    int  len,ii;                                                   //~v08qI~
#endif                                                             //~v48dI~
//*******************                                              //~v08qI~
#ifdef UNX                                                         //~v48dI~
//  if (!utempnam("/tmp","xepe_",Ppfh->UFHfilename))		//top  //~v55eR~
    rc=utempnam("/tmp","xepe_",Ppfh->UFHfilename)==0;		//top  //~v55eI~
    if (!rc)                                                       //~v55eI~
//      Ppfh->UFHpathlen=(UCHAR)getpathlen(Ppfh->UFHfilename,&Ppfh->UFHlevel,0);//~vaztR~
        Ppfh->UFHpathlen=getpathlen(Ppfh->UFHfilename,&Ppfh->UFHlevel,0);//~vaztI~
//  if (!rc)                                                       //~v60eR~
    if (rc)                                                        //~v60eI~
#else                                                              //~v48dI~
  #ifdef FTPSUPP                                                   //~v55eI~
    ii=100;   //errid                                              //~v55eI~
    if (FILEISREMOTE(Ppfh))                                        //~v55eI~
    {                                                              //~v55eI~
        strcpy(fpath,Ppfh->UFHftpwdfnm);//remote file              //~v55eR~
        Ppfh->UFHpathlen=len=getpathlen(fpath,&Ppfh->UFHlevel,0);//0:dirsw//~v55eR~
        *(fpath+len)=0;                                            //~v55eR~
    	if (utempnam(fpath,"xepe_",Ppfh->UFHfilename))		//top  //~v55eR~
            ii=0; //no errid                                       //~v55eI~
    }                                                              //~v55eI~
   if (ii==100)                                                    //~v55eI~
   {                                                               //~v55eI~
  #endif                                                           //~v55eI~
    pc0=Ppfh->UFHfilename;		//top                              //~v08qR~
    pcf=pc0+(len=Ppfh->UFHpathlen);	//filename top                 //~v08qR~
    if (len<3)	//root                                             //~v08qI~
		pcf++;                                                     //~v08qI~
    len=(int)strlen(pcf);                                          //~v08qI~
    if (len>8)                                                     //~v08qI~
#ifdef UTF8SUPPH                                                   //~va00I~
	    udbcschk_pos2offs(0,pcf,len,8,&len);                       //~va00I~
#else                                                              //~va00R~
    	if (udbcschk2(pcf,7)==1)	//offset 7 is dbcs 1st byte    //~v08qI~
	    	len=7;                                                 //~v08qI~
        else                                                       //~v08qI~
	    	len=8;                                                 //~v08qR~
#endif                                                             //~va00I~
//  pce=strchr(pcf,'.');		//extention delm	               //~v0f0R~
    pce=strrchr(pcf,'.');		//extention delm,search last .     //~v0f0I~
    if (pce)					//for long filename                //~v08qR~
    	pce++;                                                     //~v08qI~
	else                                                           //~v08qI~
    {                                                              //~v08qI~
    	pce=pcf+len;                                               //~v08qI~
    	*pce++='.';                                                //~v08qR~
	}                                                              //~v08qI~
    *pce++='!';                                                    //~v08qI~
    for (ii=1;ii<100;ii++)                                         //~v08qI~
    {                                                              //~v08qI~
        sprintf(pce,"%02d",ii);                                    //~v08qI~
		if (filefind(pc0,0,0,FFNONFMSG|FFNODIRMSG))	//no fullpath,no fstat//~v08qI~
        	break;	//may not exist                                //~v08qI~
    }                                                              //~v08qI~
  #ifdef FTPSUPP                                                   //~v55eI~
   }//ftp temp createed                                            //~v55eI~
  #endif                                                           //~v55eI~
    if (ii>=100)                                                   //~v08qI~
#endif                                                             //~v48dI~
    {                                                              //~v08qI~
		uerrmsg("Temp file cannot be created",                     //~v08qI~
				"一時ファイルを作成出来ません");                   //~v08qI~
		return 4;                                                  //~v08qI~
    }                                                              //~v08qI~
    Ppfh->UFHtype=UFHTTEMPWK;                                      //~v08qR~
#ifdef FTPSUPP                                                     //~v54cI~
    *Ppfh->UFHftpwdfnm=0;	//not now remote file                  //~v546I~
#endif                                                             //~v54cI~
    UCBITOFF(Ppfh->UFHflag6,UFHF6REMOTE);	//not now remote file  //~v546I~
#ifdef UNX                                                         //~v48dI~
	if (UCBITCHK(Ppfh->UFHflag5,UFHF5MDOS))//original is mdos disk //~v48dI~
    {                                                              //~v48dI~
		UCBITOFF(Ppfh->UFHflag5,UFHF5MDOS);                        //~v48dI~
		memset(Ppfh->UFHalias,0,sizeof(Ppfh->UFHalias));	//no alias of mdos file//~v48dI~
    }                                                              //~v48dI~
#endif                                                             //~v48dI~
    return 0;                                                      //~v08qR~
}//filetempname                                                    //~v08qI~
                                                                   //~v08qI~
//**************************************************************** //~v40uI~
// fileoptionprechk                                                //~v40uI~
//*chk option parm;called from pfhsearch(before pfh create)        //~v40uI~
//*parm1:pcw                                                       //~v40uI~
//*rc   :option bit                                                //~v40uI~
//**************************************************************** //~v40uI~
//int fileoptionprechk(PUCLIENTWE Ppcw)                            //~v60sR~
//{                                                                //~v60sR~
//    int ii,opt;                                                  //~v60sR~
//    int retopt=0;                                                //~v60sR~
//    UCHAR *pc;                                                   //~v60sR~
////*******************                                            //~v60sR~
//    if ((ii=Ppcw->UCWopdno-1)<=0)                                //~v60sR~
//        return 0;                                                //~v60sR~
//    pc=Ppcw->UCWopdpot;                                          //~v60sR~
//    for (;pc+=strlen(pc)+1,ii;ii--)                              //~v60sR~
//    {                                                            //~v60sR~
//        if (*pc=='/')                                            //~v60sR~
//            pc++;                                                //~v60sR~
//        if (*pc=='-' && (*(pc+1)<'0'||*(pc+1)>'9'))//- but not -digit//~v60sR~
//            pc++;                                                //~v60sR~
//        if ((*pc>='0' && *pc<='9') || *pc=='-')                  //~v60sR~
//            opt='0';        //numeric value,assume line no       //~v60sR~
//        else                                                     //~v60sR~
//        {                                                        //~v60sR~
//            opt=toupper(*pc);                                    //~v60sR~
//            pc++;                                                //~v60sR~
//        }                                                        //~v60sR~
//        switch(opt)                                              //~v60sR~
//        {                                                        //~v60sR~
//        case 'L':       //lineno                                 //~v60sR~
//            if (!*pc)                                            //~v60sR~
////              opt|=BECMDOPT_LISTDIR;  //dirlist even if one member by wildcard//~v60sR~
//                retopt|=BECMDOPT_LISTDIR;   //dirlist even if one member by wildcard//~v60sR~
//            break;                                               //~v60sR~
//        case 'M':       //Read mode                              //~v60sR~
//            for (;;)                                             //~v60sR~
//            {                                                    //~v60sR~
//                switch(toupper(*pc))                             //~v60sR~
//                {                                                //~v60sR~
//                case 'H':       //HEX display                    //~v60sR~
////                  opt|=BECMDOPT_HEX|BECMDOPT_BIN; //dirlist even if one member by wildcard//~v60sR~
//                    retopt|=BECMDOPT_HEX|BECMDOPT_BIN;  //dirlist even if one member by wildcard//~v60sR~
//                    break;                                       //~v60sR~
//                case 'B':       //UNIX text file                 //~v60sR~
////                  opt|=BECMDOPT_BIN;  //dirlist even if one member by wildcard//~v60sR~
//                    retopt|=BECMDOPT_BIN;   //dirlist even if one member by wildcard//~v60sR~
//                    break;                                       //~v60sR~
//                }//sw in /M                                      //~v60sR~
//                if (!*pc)                                        //~v60sR~
//                    break;                                       //~v60sR~
//                pc++;                                            //~v60sR~
//            }//for                                               //~v60sR~
//            break;                                               //~v60sR~
//        }//opt                                                   //~v60sR~
//    }//for                                                       //~v60sR~
////  return opt;                                                  //~v60sR~
//    return retopt;                                               //~v60sR~
//}//fileoptionprechk                                              //~v60sR~
//int fileoptionprechk(PUCLIENTWE Ppcw,PUFILEH Ppfh,UCHAR Popt,UCHAR Pbinsw,int *Pretopt)//~v75HR~
int fileoptionprechk(PUCLIENTWE Ppcw,PUFILEH Ppfh,UCHAR Popt,int Pbinsw,int *Pretopt)//~v75HI~
{                                                                  //~v60sI~
    int rc,retopt=0;                                               //~v60sI~
//************************                                         //~v60sI~
	memset(Ppfh,0,UFILEHSZ);                                       //~v60sI~
    Sswprechk=1;		//parm to fileoptionchk                    //~v60sI~
	rc=fileoptionchk(Ppcw,Ppfh,Popt,Pbinsw);                       //~v60sR~
    if (Sswprechk==2)	//listdir option detected                  //~v60sI~
		retopt|=BECMDOPT_LISTDIR;   //dirlist even if one member by wildcard//~v60sI~
    Sswprechk=0;		//parm to fileoptionchk                    //~v60sI~
    if (rc)                                                        //~v60sI~
    	return rc;                                                 //~v60sI~
	if (UCBITCHK(Ppfh->UFHflag5,UFHF5HEX))                         //~v60sR~
		retopt|=BECMDOPT_HEX|BECMDOPT_BIN;  //dirlist even if one member by wildcard//~v60sI~
    else                                                           //~v60sI~
	if (UCBITCHK(Ppfh->UFHflag4,UFHF4BIN))                         //~v60sI~
		retopt|=BECMDOPT_BIN;   //dirlist even if one member by wildcard//~v60sI~
	*Pretopt=retopt;                                               //~v60sI~
    return 0;                                                      //~v60sI~
}//fileoptionprechk                                                //~v60sI~
//**************************************************************** //~vaj0I~
// lrecl parm chk for recfm=V                                      //~vaj0I~
// set lrecl(=Vformat type) by minus value                         //~vaj0I~
//**************************************************************** //~vaj0I~
int xefile5getparmlreclV(int Popt,char *Pparm,int *Pplrecl)        //~vaj0R~
{                                                                  //~vaj0I~
	int fmttype,rc,len;                                        //~vaj0R~//~vaj6R~
    char fmtstr[VFMT_MAXLEN+1],*pc;                                //~vaj0I~
//***********************                                          //~vaj0I~
	pc=strchr(Pparm,' ');	//not strz for profile record          //~vaj0I~
    if (pc)                                                        //~vaj0I~
    {                                                              //~vaj0I~
    	len=PTRDIFF(pc,Pparm);                                     //~vaj0I~
        len=min(len,VFMT_MAXLEN);                                  //~vaj0R~
//      UmemcpyZ(fmtstr,Pparm,len);                                //~vb13R~
        UmemcpyZ(fmtstr,Pparm,(size_t)len);                        //~vb13I~
        pc=fmtstr;                                                 //~vaj0I~
    }                                                              //~vaj0I~
    else                                                           //~vaj0I~
    	pc=Pparm;                                                  //~vaj0I~
	rc=ufile5chkvfmt(0,pc,&fmttype);                               //~vaj6R~
    if (!rc)              //don't clear default:RDW                //~vaj0I~
	    *Pplrecl=-fmttype;                                         //~vaj0R~
	UTRACEP("xefile5getparmlreclV parm=%s,rc=%d,fmttype=%d\n",Pparm,rc,fmttype);//~vaj0R~
    return rc;                                                     //~vaj0I~
}//xefile5getparmlreclV                                            //~vaj0R~
//**************************************************************** //~va6QI~
// lrecl parm chk                                                  //~va6QI~
// lrecl=llllmmmm(lrecl+margin)                                    //~va6QI~
//**************************************************************** //~va6QI~
int filegetparmlrecl(int Popt,PUFILEH Ppfh,char *Pparm,int *Pplrecl)//~va6QI~
{                                                                  //~va6QI~
	int fixmargin,fixlrecl,wlen,retlrecl;                          //~va6QI~
    UCHAR *pc,*pc2,*pc3;                                           //~va6QR~
//***********************                                          //~va6QI~
    pc=Pparm;                                                      //~va6QR~
    pc2=pc+1;                                                      //~va6QI~
	if (!xefile5getparmlreclV(0,pc2,Pplrecl))                      //~vaj0I~
    	return 0;                                                  //~vaj0M~
    pc3=strchr(pc2,'-');     //margin delm                         //~va6QI~
    if (pc3)                                                       //~va6QI~
    {                                                              //~va6QI~
        pc3++;                                                     //~va6QI~
        wlen=(int)strlen(pc3);                                     //~va6QI~
        if (!wlen || unumlen(pc3,0,wlen)!=wlen)                    //~va6QI~
            return errinvalid(pc);                                 //~va6QI~
        fixmargin=atoi(pc3);                                       //~va6QI~
//      wlen=(int)((ULONG)pc3-(ULONG)pc2-1);                       //~va6QI~//~vafkR~
        wlen=(int)((ULPTR)pc3-(ULPTR)pc2-1);                       //~vafkI~
    }                                                              //~va6QI~
    else                                                           //~va6QI~
    {                                                              //~va6QI~
        wlen=(int)strlen(pc2);                                     //~va6QI~
        fixmargin=0;                                               //~va6QI~
    }                                                              //~va6QI~
    if (!wlen || unumlen(pc2,0,wlen)!=wlen)                        //~va6QI~
        return errinvalid(pc);                                     //~va6QI~
//  fixlrecl=atol(pc2);                                            //~va6QI~//~vb2ER~
    fixlrecl=(int)atol(pc2);                                       //~vb2EI~
    if (!fixmargin)                                                //~va6QI~
        fixmargin=fixlrecl;                                        //~va6QI~
    else                                                           //~va6QI~
    if (fixlrecl<fixmargin)                                        //~va6QI~
        return errinvalid(pc);                                     //~va6QI~
    retlrecl=(fixlrecl<<16)|fixmargin;                             //~va6QI~
    *Pplrecl=retlrecl;                                             //~va6QI~
    return 0;                                                      //~va6QI~
}//filegetparmlrecl                                                //~va6QI~
//**************************************************************** //~va79I~
// fileoptionchkebcconverter                                       //~va79I~
// chk CPEB=xxxx                                                   //~va79I~
//*rc   :err                                                       //~va79I~
//**************************************************************** //~va79I~
int fileoptionchkebcconverter(int Popt,char *Popd,int Poffs,int *Pphandle)//~va79R~
{                                                                  //~va79I~
	char *pcvname;                                                 //~va79I~
    int handle,rc;                                                 //~va79R~
//****************                                                 //~va79I~
	pcvname=Popd+Poffs;                                            //~va79R~
    if (*pcvname==':'||*pcvname=='='                               //~va79R~
    )                                                              //~va79I~
    	pcvname++;	                                               //~va79R~
    if (*pcvname)                                                  //~va79I~
    {                                                              //~va79I~
        rc=xeebc_createhandle(0,0/*pfh*/,pcvname,&handle);         //~va79R~
        if (rc)                                                    //~va79R~
            return 4;                                              //~va79R~
    }                                                              //~va79I~
    else                                                           //~va79I~
    	handle=0;                                                  //~va79I~
	*Pphandle=handle;                                              //~va79I~
    return 0;                                                      //~va79I~
}//fileoptionchkebcconverter                                       //~va79I~
#ifdef UTF8SUPPH                                                   //~va00I~
//**************************************************************** //~va00I~
// filesaveoptionchkcp                                             //~va00I~
//chk CPxx and -S{r|d|i}                                           //~va6cI~
//*rc   :rc:0:option detected,4:option err,-1:not cp option        //~va00I~
//**************************************************************** //~va00I~
//int filesaveoptionchkcp(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh,char *Pcpopt,int *Ppopt)//~va00R~//~va6QR~
int filesaveoptionchkcp(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh,char *Pcpopt,int *Ppopt,int *Ppint)//~va6QI~
{                                                                  //~va00I~
    int retopt,ch;                                                    //~va00I~//~va6cR~
    char *pc,*pc2;                                                 //~va6cI~
    int swerr;                                                     //~va6cR~
    int swerr2;                                                    //~va6HI~
    int rc2,lrecl;                                                 //~va6QR~
    int handle;                                                    //~va7tI~
//******************                                               //~va00I~
    *Ppint=0;                                                      //~va6NI~
    if (!stricmp(Pcpopt,MODE_UTF8))                                //~va00I~
    {                                                              //~va00I~
        if (UCBITCHK(Ppfh->UFHflag4,UFHF4BIN))//binary mode        //~va00I~
          if (!PFH_ISEBC(Ppfh))                                    //~va61I~
            return erroptionforbinfile(Pcpopt,4);                  //~va00I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
//*CPU8 option to UTF8 file is ignored                             //~va50I~
#else                                                              //~va50I~
      	if (!(Popt & FSOCCO_COPY))	//not copy cmd                 //~va00I~
            if (FILEUTF8MODE(Ppfh))                                //~va00R~
            {                                                      //~va00R~
                uerrmsg("%s option is invalid,File is opend by UTF8 mode",0,//~va00R~
                            Pcpopt);                               //~va00R~
                return 4;                                          //~va00R~
            }                                                      //~va00R~
#endif                                                             //~va50I~
//  	retopt=FSOC_CPU8|FSOC_BK;   //do bkup and restore when conv err//~va7tR~
    	retopt=*Ppopt|FSOC_CPU8|FSOC_BK;   //do bkup and restore when conv err//~va7tI~
        retopt&=~(FSOC_CPLC|FSOC_CPEB);                            //~va6iI~
//  	*Ppopt=*Ppopt|retopt;                                      //~va7tR~
    	*Ppopt=retopt;                                             //~va7tI~
        return 0;                                                  //~va00I~
    }                                                              //~va00I~
    if (!stricmp(Pcpopt,MODE_LOCALE))                              //~va00I~
    {                                                              //~va00I~
        if (UCBITCHK(Ppfh->UFHflag4,UFHF4BIN))//binary mode        //~va00I~
          if (!PFH_ISEBC(Ppfh))                                    //~va61I~
            return erroptionforbinfile(Pcpopt,4);                  //~va00I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
//*CPLC option to LOCAL file is ignored                            //~va50I~
#else                                                              //~va50I~
      	if (!(Popt & FSOCCO_COPY))	//not copy cmd                 //~va00R~
            if (!FILEUTF8MODE(Ppfh))                               //~va00R~
            {                                                      //~va00R~
                uerrmsg("%s option is invalid,File is NOT opend by UTF8 mode",0,//~va00R~
                            Pcpopt);                               //~va00R~
                return 4;                                          //~va00R~
            }                                                      //~va00R~
#endif                                                             //~va50I~
//  	retopt=FSOC_CPLC|FSOC_BK;                                  //~va7tR~
    	retopt=*Ppopt|FSOC_CPLC|FSOC_BK;                           //~va7tI~
        retopt&=~(FSOC_CPEB|FSOC_CPU8);                            //~va6iI~
//  	*Ppopt=*Ppopt|retopt;                                      //~va7tR~
    	*Ppopt=retopt;                                             //~va7tI~
        return 0;                                                  //~va00I~
    }                                                              //~va00I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    if (!stricmp(Pcpopt,MODE_EBC))                                 //~va50I~
    {                                                              //~va50I~
//        if (UCBITCHK(Ppfh->UFHflag4,UFHF4BIN))//binary mode        //~va50I~//~va60R~
//            return erroptionforbinfile(Pcpopt,4);                  //~va50I~//~va60R~
//  	retopt=FSOC_CPEB|FSOC_BK;                                  //~va7tR~
    	retopt=*Ppopt|FSOC_CPEB|FSOC_BK;                           //~va7tI~
        retopt&=~(FSOC_CPLC|FSOC_CPU8);                            //~va6iI~
//  	*Ppopt=*Ppopt|retopt;                                      //~va7tR~
    	*Ppopt=retopt;                                             //~va7tI~
        return 0;                                                  //~va50I~
    }                                                              //~va50I~
    if (USTRHEADIS_IC(Pcpopt,OPTSTR_CODEPAGE))    //icase CP=      //~va7tR~
    {                                                              //~va7tI~
        if (fileoptionchkebcconverter(0,Pcpopt,sizeof(OPTSTR_CODEPAGE)-1,&handle))//~va7tR~
            return 4;   //ebc cfg err                              //~va7tI~
    	retopt=*Ppopt|FSOC_CPEB|FSOC_BK;                           //~va7tI~
        retopt|=FSOC_SETHANDLE(handle)|FSOC_EBCHANDLEP;            //~va7tR~
        retopt&=~(FSOC_CPLC|FSOC_CPU8);                            //~va7tI~
    	*Ppopt=retopt;                                             //~va7tI~
        return 0;                                                  //~va7tI~
    }                                                              //~va7tI~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    if (!stricmp(Pcpopt,MODE_IE))    //ignore cv err cmd option    //~va00R~
    {                                                              //~va00I~
        if (UCBITCHK(Ppfh->UFHflag4,UFHF4BIN))//binary mode        //~va00I~
		  if (!(*Ppopt & FSOC_CPEB))	//not L2B                  //~va60I~
           if (!PFH_ISEBC(Ppfh))                                   //~va61I~
            return erroptionforbinfile(Pcpopt,4);                  //~va00I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
#else                                                              //~va50I~
      	if (Popt & FSOCCO_COPY 	//    copy cmd                     //~va00I~
        ||  !FILEUTF8MODE(Ppfh))                                   //~va00R~
            if (!(*Ppopt & (FSOC_CPU8)))                           //~va00R~
            {                                                      //~va00R~
                uerrmsg("%s option is valid after %s option",      //~va00R~
                        "%s は %s の後に指定してください",         //~va00R~
                            Pcpopt,MODE_UTF8);                     //~va00R~
                return 4;                                          //~va00R~
            }                                                      //~va00R~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
		retopt=FSOC_ERRREP;                                        //~va00R~
		*Ppopt=*Ppopt|retopt;                                      //~va00I~
        return 0;                                                  //~va00I~
    }                                                              //~va00I~
//*-S{r|d|i}                                                       //~va6cI~
    pc=Pcpopt;                                                     //~va6cR~
    if (Popt & FSOCCO_CMDFLAG)	//start by "/" or "-"              //~va6cR~
    {                                                              //~va6cI~
        retopt=0;                                                  //~va6cI~
        swerr2=0;                                                  //~va6HI~
        pc2=pc;                                                    //~va6cR~
        switch(toupper(*pc2))                                      //~va6cI~
        {                                                          //~va6cI~
        case 'S':       //sosi option                              //~va6cI~
            if (UCBITCHK(Ppfh->UFHflag4,UFHF4BIN))//binary mode    //~va6cI~
            {                                                      //~va6cI~
                uerrmsg("%s option is invalid for file opened binary mode",//~va6cI~
                        "バイナリーモードでは %s オプションは無効。",//~va6cI~
                        pc);                                       //~va6cI~
                return 4;                                          //~va6cI~
            }                                                      //~va6cI~
            pc2++;                                                 //~va6cI~
            if (!*pc2)                                             //~va6cI~
                return errinvalid(pc);                             //~va6cI~
            for (;ch=*pc2++,ch;)                                   //~va6cR~
            {                                                      //~va6cI~
            	swerr=0;                                           //~va6cI~
                switch(toupper(ch))                                //~va6cR~
                {                                                  //~va6cI~
                case 'I':       //PC text file                     //~va6cI~
                    if (Popt & FSOCCO_COPY) 	//    copy cmd     //~va6cI~
                    {                                              //~va6cI~
           				if (!PFH_ISEBC(Ppfh))  //!tgt ebc, !m2b    //~va6cI~
                    		swerr=1;                               //~va6cI~
                    }                                              //~va6cI~
                    else                                           //~va6cI~
                    {                                              //~va6cI~
           				if (!(*Ppopt & FSOC_CPEB))  //!tgt ebc, !m2b//~va6cI~
                    		swerr=1;                               //~va6cI~
                    }                                              //~va6cI~
                    if (swerr)                                     //~va6cI~
                    {                                              //~va6cI~
//              		uerrmsg("SOSI:Insert option is for translation to EBCDIC",//~va6cR~//~vb13R~
//                      		"SOSI:挿入 オプションは宛先EBCDICへの変換用",//~va6cR~//~vb13R~
                		uerrmsg("SOSI:Insert option(%s) is for translation to EBCDIC",//~vb13I~
                        		"SOSI:挿入 オプション(%s)は宛先EBCDICへの変換用",//~vb13I~
                        		pc);                               //~va6cI~
                		return 4;                                  //~va6cI~
                    }                                              //~va6cI~
                    retopt|=FSOC_SOSI_INS;                         //~va6cI~
                    break;                                         //~va6cI~
                case 'R':       //UNIX text file                   //~va6cI~
                    retopt|=FSOC_SOSI_REP;                         //~va6cI~
                    break;                                         //~va6cI~
                case 'D':       //Mac  text file                   //~va6cI~
                    if (Popt & FSOCCO_COPY) 	//    copy cmd     //~va6cI~
                    {                                              //~va6cI~
           				if (PFH_ISEBC(Ppfh))  //tgt ebc, m2b       //~va6cI~
                    		swerr=1;                               //~va6cI~
                    }                                              //~va6cI~
                    else                                           //~va6cI~
                    {                                              //~va6cI~
           				if ((*Ppopt & FSOC_CPEB))  //tgt ebc, m2b  //~va6cI~
                    		swerr=1;                               //~va6cI~
                    }                                              //~va6cI~
                    if (swerr)                                     //~va6cI~
                    {                                              //~va6cI~
//              		uerrmsg("SOSI:Delete option is for translation from EBCDIC",//~va6cR~//~vb13R~
//                      		"SOSI:削除 オプションはEBCDICからの変換用",//~va6cR~//~vb13R~
                		uerrmsg("SOSI:Delete option(%s) is for translation from EBCDIC",//~vb13I~
                        		"SOSI:削除 オプション(%s)はEBCDICからの変換用",//~vb13I~
                        		pc);                               //~va6cI~
                		return 4;                                  //~va6cI~
                    }                                              //~va6cI~
                    retopt|=FSOC_SOSI_DEL;                         //~va6cI~
                    break;                                         //~va6cI~
                default:                                           //~va6cI~
                    return errinvalid(pc);                         //~va6cI~
                }                                                  //~va6cI~
            }//for                                                 //~va6cI~
            break;                                                 //~va6cI~
        case 'M':       //mode option                              //~va6HI~
            if (UCBITCHK(Ppfh->UFHflag4,UFHF4BIN))//binary mode    //~va6HI~
            {                                                      //~va6HI~
                uerrmsg("%s option is invalid for file opened binary mode",//~va6HI~
                        "バイナリーモードでは %s オプションは無効。",//~va6HI~
                        pc);                                       //~va6HI~
                return 4;                                          //~va6HI~
            }                                                      //~va6HI~
            for (;*(++pc2);)                                       //~va6HI~
            {                                                      //~va6HI~
                switch(toupper(*pc2))                              //~va6HI~
                {                                                  //~va6HI~
                case 'T':       //PC text file                     //~va6HI~
                    if (retopt & (FSOC_EOL_MAC|FSOC_EOL_RECORD|FSOC_EOL_EBC))//~va6HI~
                        return fileerrexclusiveopt();              //~va6HI~
                    retopt|=FSOC_EOL_PC|FSOC_EOL_UNIX;             //~va6HI~
                    break;                                         //~va6HI~
                case 'P':       //PC text file                     //~va6HI~
                    if (retopt & (FSOC_EOL_UNIX|FSOC_EOL_MAC|FSOC_EOL_RECORD|FSOC_EOL_EBC))//~va6HI~
                        return fileerrexclusiveopt();              //~va6HI~
                    retopt|=FSOC_EOL_PC;                           //~va6HI~
                    break;                                         //~va6HI~
                case 'U':       //UNIX text file                   //~va6HI~
                    if (retopt & (FSOC_EOL_PC|FSOC_EOL_MAC|FSOC_EOL_RECORD|FSOC_EOL_EBC))//~va6HI~
                        return fileerrexclusiveopt();              //~va6HI~
                    retopt|=FSOC_EOL_UNIX;                         //~va6HI~
                    break;                                         //~va6HI~
                case 'M':       //Mac  text file                   //~va6HI~
                    if (retopt & (FSOC_EOL_PC|FSOC_EOL_UNIX|FSOC_EOL_RECORD|FSOC_EOL_EBC))//~va6HI~
                        return fileerrexclusiveopt();              //~va6HI~
                    retopt|=FSOC_EOL_MAC;                          //~va6HI~
                    break;                                         //~va6HI~
                case 'R':       //Mac  text file                   //~va6HI~
                    if (retopt & (FSOC_EOL_PC|FSOC_EOL_UNIX|FSOC_EOL_MAC|FSOC_EOL_EBC))//~va6HI~
                        return fileerrexclusiveopt();              //~va6HI~
                    retopt|=FSOC_EOL_RECORD;                       //~va6HI~
                    break;                                         //~va6HI~
                case  EOLOPT_EBC:      //EBC EOL(0x15)             //~va6HI~
//                    if (!PFH_ISEBC(Ppfh)                         //~va6HR~
//                    ||  UCBITCHK(Ppfh->UFHflag4,UFHF4BIN)        //~va6HR~
//                    )                                            //~va6HR~
//                        return fileerrebcdicoptopn(0,EOLOPT_EBCS);//~va6HR~
                    if (retopt & (FSOC_EOL_PC|FSOC_EOL_UNIX|FSOC_EOL_MAC|FSOC_EOL_RECORD))//~va6HI~
                        return fileerrexclusiveopt();              //~va6HI~
                    retopt|=FSOC_EOL_EBC;                          //~va6HI~
                    break;                                         //~va6HI~
                case 'V':       //recfm=V                          //~vaj0I~
                    if (retopt & (FSOC_EOL_PC|FSOC_EOL_UNIX|FSOC_EOL_MAC|FSOC_EOL_EBC|FSOC_EOL_RECORD))//~vaj0I~
                        return fileerrexclusiveopt();              //~vaj0I~
                    retopt|=FSOC_EOL_RECORDV;                      //~vaj0I~
                    break;                                         //~vaj0I~
                default:                                           //~va6HI~
                    return errinvalid(pc);                         //~va6HI~
                }                                                  //~va6HI~
                if (retopt & (FSOC_EOL_PC|FSOC_EOL_UNIX|FSOC_EOL_MAC|FSOC_EOL_EBC|FSOC_EOL_RECORD))//~vaj0I~
                	if (retopt & FSOC_EOL_RECORDV)                 //~vaj0I~
                		return fileerrexclusiveopt();              //~vaj0I~
            }//for                                                 //~va6HI~
            break;                                                 //~va6HI~
        case 'F':       //lrecl                                    //~va6QI~
    		if (!(Popt & FSOCCO_GETLRECL))	//get lrecl parm       //~va6QI~
            	return -1;                                         //~va6QI~
			rc2=filegetparmlrecl(0,Ppfh,pc2,&lrecl);               //~va6QI~
            if (rc2)                                               //~va6QI~
            	return rc2;                                        //~va6QI~
          if (lrecl<0)                                             //~vaj0I~
          {                                                        //~vaj0I~
          	lrecl=-lrecl;                                          //~vaj0I~
            retopt|=FSOC_RETLRECLV;                                //~vaj0I~
          }                                                        //~vaj0I~
          else                                                     //~vaj0I~
            retopt|=FSOC_RETLRECL;                                 //~va6QI~
            *Ppint=lrecl;                                          //~va6QI~
            break;                                                 //~va6QI~
        default:                                                   //~va6cI~
//  	    return errinvalid(pc);                                 //~va6cI~//~va6HR~
			swerr2=1;                                              //~va6HI~
    		break;                                                 //~va6HR~
        }                                                          //~va6cI~
      if (!swerr2)                                                 //~va6HI~
      {                                                            //~va6HI~
		*Ppopt=*Ppopt|retopt;                                      //~va6cI~
        return 0;                                                  //~va6cI~
      }                                                            //~va6HI~
    }                                                              //~va6cI~
    if ((Popt & FSOCCO_COPY))	//copy cmd                         //~va00R~
    	errinvalid(Pcpopt);                                        //~va00I~
    return -1;                                                     //~va00I~
}//filesaveoptionchkcp                                             //~va00R~
#endif                                                             //~va00I~
//**************************************************************** //~vaj0I~
//*chk change to vfmt=MF(could not create required file header record)//~vaj0I~
//*chk already that vfmt                                           //~vaj0I~
//*chk already that lrecl for record mode                          //~vaj0I~
//**************************************************************** //~vaj0I~
int chknewmode(int Popt,int Pfuncid,PUFILEH Ppfh,int Pretopt,int *Pplrecl)//~vaj0R~
{                                                                  //~vaj0I~
	int rc=0,oldvfmt,newvfmt,newlrecl;                             //~vaj0R~
    int swduperr=0;                                                //~vaj0I~
//***********************                                          //~vaj0I~
	if (Pretopt & FSOC_RETLRECLV)  //-Fvfmt specified              //~vaj0R~
    {                                                              //~vaj0I~
		oldvfmt=Ppfh->UFHvfmt;                                     //~vaj0I~
		newvfmt=*Pplrecl;                                          //~vaj0R~
		if (newvfmt==UFGETS_VFMT_MFH)	//-Fmf                     //~vaj0R~
        {                                                          //~vaj0I~
            if (!UCBITCHK(Ppfh->UFHflag13,UFHF13RV))//read mode is not recfm=V//~vaj0R~
                rc=1;                                              //~vaj0R~
            else                                                   //~vaj0R~
            if (oldvfmt==UFGETS_VFMT_MFH2||oldvfmt==UFGETS_VFMT_MFH4)//~vaj0R~
            {                                                      //~vaj0I~
            	*Pplrecl=oldvfmt;                                  //~vaj0R~
	        	rc=4;	//not change                               //~vaj0R~
            }                                                      //~vaj0I~
            else                                                   //~vaj0R~
                rc=1;                                              //~vaj0R~
        }                                                          //~vaj0I~
        else                                                       //~vaj0I~
        	if (newvfmt==oldvfmt)                                  //~vaj0I~
            	rc=4;	//not change                               //~vaj0R~
    }                                                              //~vaj0I~
    else                                                           //~vaj0I~
    {                                                              //~vaj0I~
    	if (Pretopt & FSOC_EOL_RECORDV)                            //~vaj0I~
      		if (UCBITCHK(Ppfh->UFHflag13,UFHF13RV))                //~vaj0I~
            	rc=4;	//not change                               //~vaj0I~
    }                                                              //~vaj0I~
	if (Pretopt & FSOC_RETLRECL)  //-Flrecl specified              //~vaj0I~
    {                                                              //~vaj0I~
		newlrecl=*Pplrecl;                                         //~vaj0I~
        if (UCBITCHK(Ppfh->UFHflag10,UFHF10RECORD))//read mode is not recfm=V//~vaj0I~
			if (Ppfh->UFHlrecl==(newlrecl>>16)                     //~vaj0R~
            &&  Ppfh->UFHmergin==(newlrecl & 0xffff))              //~vaj0R~
            	rc=4;	//not change                               //~vaj0I~
    }                                                              //~vaj0I~
    if (rc==1)                                                     //~vaj0R~
		rc=fileerrchange2mfh(4/*rc*/);                             //~vaj0R~
    else                                                           //~vaj0I~
    if (rc==4)	//same Fvfmt,v2v, same -Flrecl-argin               //~vaj0R~
    {                                                              //~vaj0I~
    	if (!(Popt & 1)	//filectr=0, FUNCID_END and FUNCID_SAVE with out filename//~vaj0I~
        )                                                          //~vaj0I~
        	swduperr=1;                                            //~vaj0I~
        if (swduperr)                                              //~vaj0I~
    		uerrmsg("Specified -Mmode and -F is same as current setting",//~vaj0R~
        			"指定の -Mmode と -F は現ファイルの設定と同じです");//~vaj0R~
        else                                                       //~vaj0I~
        	rc=0;                                                  //~vaj0I~
    }                                                              //~vaj0I~
    return rc;                                                     //~vaj0R~
}//chknewmode                                                      //~vaj0R~
//**************************************************************** //~v47TI~
// filesaveoptionchk                                               //~v47TI~
//*chk eol option parm for end/sav/cre/rep/app cmd                 //~v47TI~
//*parm1:pcw                                                       //~v47TI~
//*parm2:pfh                                                       //~v47TI~
//*parm3:optional output eol option                                //~v47TR~
//*parm4:optonal filename operand addr                             //~v47TR~
//*rc   :rc                                                        //~v47TI~
//**************************************************************** //~v47TI~
//int filesaveoptionchk(PUCLIENTWE Ppcw,PUFILEH Ppfh,int *Pretopt,UCHAR **Ppfnm)//~v54YR~
int filesaveoptionchk(PUCLIENTWE Ppcw,PUFILEH Ppfh,int *Pretopt,UCHAR **Ppfnm,//~v54YI~
//  			PULINEH *Ppplh1,PULINEH *Ppplh2)                   //~v54YI~//~va66R~
    			PULINEH *Ppplh1,PULINEH *Ppplh2,int *Ppretlrecl)   //~va66I~
{                                                                  //~v47TI~
    FUNCTBL *pft;	//FUNKTBL ptr                                  //~v47TI~
    int ii,opdno,retopt=0,filectr=0;                               //~v47TR~
    int rc;                                                        //~v54YI~
    int labelsw=0;                                                 //~v57PR~
//  UCHAR *pc,*pc2;                                                //~v665R~
    UCHAR *pc,*pc2="";                                             //~v665I~
#ifdef W32                                                         //~v59yI~
    PUFTPHOST puftph;                                              //~v59yI~
#endif                                                             //~va66I~
    int modesw=0;                                                  //~v59yM~
//#endif                                                           //~va66R~
//  int fixmargin,fixlrecl,wlen,retlrecl=0;                        //~va66I~//~va6QR~
    int retlrecl=0;                                                //~va6QI~
//  UCHAR *pc3;                                                    //~va66I~//~va6QR~
    int optchkcp;                                                  //~va6cI~
    int parmlrecl;                                                 //~va6QR~
//*******************                                              //~v47TI~
	if (Pretopt)                                                   //~v47TI~
	    *Pretopt=0;                                                //~v47TR~
    if (Ppfnm)                                                     //~v47TI~
	    *Ppfnm=0;       //output filename ptr                      //~v47TR~
    if (Ppplh1)                                                    //~v54YI~
        *Ppplh1=0;      //for err return                           //~v54YI~
    if (Ppplh2)                                                    //~v54YI~
        *Ppplh2=0;      //for err return                           //~v54YI~
    if (Ppretlrecl)                                                //~va66I~
        *Ppretlrecl=0;                                             //~va66I~
    pft=Ppcw->UCWpfunct;                                           //~v47TI~
    if (!pft)   //::cb etc,internaly called function has no pfunct //~v47TI~
    {                                                              //~v47TI~
    	if (Ppfnm)                                                 //~v47TI~
	    	*Ppfnm=Ppcw->UCWparm;       //output filename ptr      //~v47TI~
        return 0;                                                  //~v47TI~
    }                                                              //~v47TI~
    switch(pft->FTfuncid)                                          //~v47TI~
    {                                                              //~v47TI~
    case FUNCID_CREATE:                                            //~v47TI~
	case FUNCID_REPL:                                              //~v47TI~
	case FUNCID_APPEND:                                            //~v47TI~
	case FUNCID_SAVE:                                              //~v47TI~
	case FUNCID_CUT:         //cut cmd                             //~v783I~
    	break;                                                     //~v47TI~
	case FUNCID_END:                                               //~v47TI~
#ifdef UTF8SUPPH                                                   //~v92nI~//~va00R~
    	if (Ppcw->UCWopdno)                                        //~v92nM~//~va00I~
#else                                                              //~v92nI~//~va00I~
    	if (Ppcw->UCWopdno==1)                                     //~v76XI~
#endif                                                             //~v92nI~//~va00I~
        {                                                          //~v76XI~
		    pc=Ppcw->UCWopdpot;                                    //~v76XI~
#ifdef UTF8SUPPH                                                   //~v92nI~//~va00R~
    	  for (opdno=Ppcw->UCWopdno;opdno>0;opdno--,pc+=strlen(pc)+1)//~v92nI~//~va00R~
          {                                                        //~v92nI~//~va00I~
#endif                                                             //~v92nI~//~va00I~
//          optchkcp=0;                                            //~va6cI~//~va6QR~
            optchkcp=FSOCCO_GETLRECL;                              //~va6QI~
//      	if (CMDFLAGCHK(*pc,0)) // '-' or 2nd '/'               //~va6SR~
        	if (CMDFLAGCHK(*pc,1)) // '-' or 2nd '/'               //~va6SI~
            {                                                      //~va6cI~
	            optchkcp|=FSOCCO_CMDFLAG;                          //~va6cI~
            	pc2=pc+1;                                          //~v76XI~
            }                                                      //~va6cI~
            else                                                   //~v76XI~
            	pc2=pc;                                            //~v76XI~
            if (!stricmp(pc2,"NB"))                                //~v76XR~
                retopt|=FSOC_NB;                                   //~v76XR~
            if (!stricmp(pc2,"BK"))                                //~v76XR~
                retopt|=FSOC_BK;                                   //~v76XR~
#ifdef UTF8SUPPH                                                   //~v92nI~//~va00R~
#ifdef UTF8SUPPH                                                   //~va00I~
//          switch(filesaveoptionchkcp(0,Ppcw,Ppfh,pc2,&retopt))   //~va00R~//~va6cR~
//          switch(filesaveoptionchkcp(optchkcp,Ppcw,Ppfh,pc2,&retopt))//~va6cI~//~va6QR~
			parmlrecl=0;                                           //~va6QI~
            switch(filesaveoptionchkcp(optchkcp,Ppcw,Ppfh,pc2,&retopt,&parmlrecl))//~va6QR~
            {                                                      //~va00I~
            case 0:     //valid CP option                          //~va00I~
            	if (parmlrecl && (retopt & FSOC_RETLRECL))         //~va6QI~
                	retlrecl=parmlrecl;                            //~va6QI~
            	if (parmlrecl && (retopt & FSOC_RETLRECLV))        //~vaj0I~
                	retlrecl=parmlrecl;                            //~vaj0I~
                continue;                                          //~va00I~
            case 4:     //valid CP option                          //~va00I~
                return 4;                                          //~va00I~
            }                                                      //~va00I~
#else                                                              //~va00I~
            if (!stricmp(pc2,MODE_UTF8))                           //~v92nI~//~va00I~
            {                                                      //~va0mI~
                retopt|=FSOC_CPU8;                                 //~v92nI~//~va00I~
            }                                                      //~va0mI~
            else                                                   //~v92nI~//~va00I~
            if (!stricmp(pc2,MODE_LOCALE))                         //~v92nI~//~va00I~
            {                                                      //~va0mI~
                retopt|=FSOC_CPLC;                                 //~v92nI~//~va00I~
            }                                                      //~va0mI~
#endif                                                             //~va00I~
#endif                                                             //~v92nI~//~va00I~
#ifdef UTF8SUPPH                                                    //~v92nI~//~va00R~
          }                                                        //~v92nI~//~va00I~
#endif                                                             //~v92nI~//~va00I~
        }                                                          //~v76XI~
#ifdef UTF8SUPPH                                                   //~va00I~
    	if (FILEUTF8MODE(Ppfh))                                    //~va00I~
        {                                                          //~va00I~
            if (!(retopt & (FSOC_CPU8|FSOC_CPLC)))                 //~va00I~
				retopt|=FSOC_BK;                                   //~va00R~
        }                                                          //~va00I~
#endif                                                             //~va00I~
//  	if (((retopt & FSOC_EOL_RECORD)!=0) ^ ((retopt & FSOC_RETLRECL)!=0))	//one of two//~va6NR~//~vaj6R~
    	if ((retopt & FSOC_EOL_RECORD) && !(retopt & FSOC_RETLRECL))//-MR without -Flrecl//~vaj6R~
        {                                                          //~va6NI~
//      	uerrmsg("Both, /Mr and /F, is required",               //~vaj0R~
//                  "/Mr と /F は両方指定する。");                 //~vaj0R~
        	uerrmsg("-Flrecl is required for -Mr",                 //~vaj6I~
                    "-Mr のときは -Flreclを指定する");             //~vaj6I~
    	    return 4;                                              //~va6NI~
        }                                                          //~va6NI~
    	if (!(retopt & FSOC_EOL_NOTRECORDV) && (retopt & FSOC_RETLRECL))//-Flrecl without /Mx//~vaj6I~
        {                                                          //~vaj6I~
        	uerrmsg("-Flrecl requires -Mx (x!=v)",                 //~vaj6I~
                    "-Flreclを指定するときは -Mx(xはv以外)が必要");//~vaj6I~
    	    return 4; //filesave requires FSOC_EOLxxx to check retlrecl value//~vaj6R~
        }                                                          //~vaj6I~
        if (((retopt & FSOC_EOL_RECORDV)!=0) ^ ((retopt & FSOC_RETLRECLV)!=0))  //one of two//~vaj0R~
        {                                                          //~vaj0R~
            uerrmsg("Both, -Mv and -Fvfmt, is required",           //~vaj0R~
                    "-MV と -Fvfmt は両方指定する。");             //~vaj0R~
            return 4;                                              //~vaj0R~
        }                                                          //~vaj0R~
        if (chknewmode(0/*filctr=0*/,pft->FTfuncid,Ppfh,retopt,&retlrecl))//~vaj0R~
        	return 4;                                              //~vaj0I~
		if (Pretopt)                                               //~v76XI~
	    	*Pretopt=retopt;                                       //~v76XI~
    	if (Ppretlrecl)                                            //~va6NI~
        	*Ppretlrecl=retlrecl;                                  //~va6NI~
    	return 0;                                                  //~v47TR~
    default:                                                       //~v47TI~
    	if (Ppfnm)                                                 //~v47TI~
	    	*Ppfnm=Ppcw->UCWparm;       //output filename ptr      //~v47TI~
    	return 0;                                                  //~v47TI~
    }                                                              //~v47TI~
    opdno=Ppcw->UCWopdno;                                          //~v47TI~
  if (pft->FTfuncid==FUNCID_CUT)                                   //~v783I~
  {                                                                //~v783I~
        filectr=1;                 //no file filename parm,assumed specified.//~v783M~
        if (Ppfnm)                 //0 if called from filesave     //~v783I~
		    *Ppfnm=CUTCMD_2NDCBFNM;      //on workdir              //~v783R~
  }                                                                //~v783I~
  else                                                             //~v783I~
  {                                                                //~v783I~
    if (!opdno)                                                    //~v47TI~
    	return 0;                                                  //~v47TI~
  }                                                                //~v783I~
    pc=Ppcw->UCWopdpot;                                            //~v47TI~
    for (ii=0;ii<opdno;ii++,pc+=strlen(pc)+1)                      //~v47TI~
    {                                                              //~v47TI~
        optchkcp=FSOCCO_GETLRECL;                                  //~va6QI~
    	if (filectr>0)                                             //~v559I~
        {                                                          //~v559I~
//      	optchkcp=0;                                            //~va6cI~//~va6QR~
          	if (*pc=='/'||*pc=='-')                                //~v559I~
            {                                                      //~va6cI~
        		pc2=pc+1;                                          //~v559I~
	            optchkcp|=FSOCCO_CMDFLAG;                          //~va6cI~
            }                                                      //~va6cI~
          	else                                                   //~v559I~
          		pc2=pc;                                            //~v559I~
            if (!stricmp(pc2,"XALL"))                              //~v559I~
            {                                                      //~v559I~
                retopt|=FSOC_XALL;                                 //~v559I~
//              allsw=1;                                           //~v57PR~
                continue;                                          //~v559I~
            }                                                      //~v559I~
            if (!stricmp(pc2,"NXALL"))                             //~v559I~
            {                                                      //~v559I~
                retopt|=FSOC_NXALL;                                //~v559I~
//              allsw=1;                                           //~v57PR~
                continue;                                          //~v559I~
            }                                                      //~v559I~
            if (!stricmp(pc2,"X"))                                 //~v559I~
            {                                                      //~v559I~
                retopt|=FSOC_XALL;                                 //~v559I~
                continue;                                          //~v559I~
            }                                                      //~v559I~
            if (!stricmp(pc2,"NX"))                                //~v559I~
            {                                                      //~v559I~
                retopt|=FSOC_NXALL;                                //~v559I~
                continue;                                          //~v559I~
            }                                                      //~v559I~
            if (!stricmp(pc2,"ALL"))                               //~v559I~
            {                                                      //~v559I~
//              allsw=1;                                           //~v57PR~
                retopt|=FSOC_NXALL|FSOC_XALL;                      //~v57PI~
                continue;                                          //~v559I~
            }                                                      //~v559I~
#ifdef UTF8SUPPH                                                    //~v92nI~//~va00R~
//          switch(filesaveoptionchkcp(0,Ppcw,Ppfh,pc2,&retopt))   //~va00R~//~va6cR~
//          switch(filesaveoptionchkcp(optchkcp,Ppcw,Ppfh,pc2,&retopt))//~va6cI~//~va6QR~
			parmlrecl=0;                                           //~va6QR~
            switch(filesaveoptionchkcp(optchkcp,Ppcw,Ppfh,pc2,&retopt,&parmlrecl))//~va6QR~
            {                                                      //~va00I~
            case 0:     //valid CP option                          //~va00I~
            	if (parmlrecl && (retopt & FSOC_RETLRECL))         //~va6QI~
                	retlrecl=parmlrecl;                            //~va6QI~
            	if (parmlrecl && (retopt & FSOC_RETLRECLV))        //~vaj0I~
                	retlrecl=parmlrecl;                            //~vaj0I~
                continue;                                          //~va00I~
            case 4:     //valid CP option                          //~va00I~
                return 4;                                          //~va00I~
            }                                                      //~va00I~
#endif                                                             //~v92nI~//~va00M~
        }                                                          //~v559I~
        if (CMDFLAGCHK(*pc,filectr)) // '-' or 2nd '/'             //~v559R~
        {                                                          //~v47TI~
            pc2=pc+1;                                              //~v76XI~
            if (filectr>0 || opdno==1) //2nd opd or only one operand//~v76XI~
    			if (pft->FTfuncid==FUNCID_SAVE)                    //~v76XR~
                {                                                  //~v76XI~
                    if (!stricmp(pc2,"NB"))                        //~v76XI~
                    {                                              //~v76XI~
                        retopt|=FSOC_NB;                           //~v76XI~
                        continue;                                  //~v76XI~
                    }                                              //~v76XI~
                    if (!stricmp(pc2,"BK"))                        //~v76XI~
                    {                                              //~v76XI~
                        retopt|=FSOC_BK;                           //~v76XI~
                        continue;                                  //~v76XI~
                    }                                              //~v76XI~
                }                                                  //~v76XI~
#ifdef UTF8SUPPH                                                   //~va00M~
            if (pft->FTfuncid==FUNCID_SAVE)                        //~va00I~
            {                                                      //~va00I~
//              switch(filesaveoptionchkcp(0,Ppcw,Ppfh,pc2,&retopt))//~va00R~//~va6cR~
	            optchkcp|=FSOCCO_CMDFLAG;                          //~va6cI~
                parmlrecl=0;                                       //~va6QI~
//              switch(filesaveoptionchkcp(optchkcp,Ppcw,Ppfh,pc2,&retopt))//~va6cI~//~va6QR~
                switch(filesaveoptionchkcp(optchkcp,Ppcw,Ppfh,pc2,&retopt,&parmlrecl))//~va6QR~
                {                                                  //~va00I~
                case 0:     //valid CP option                      //~va00I~
                    if (parmlrecl && (retopt & FSOC_RETLRECL))     //~va6QI~
                        retlrecl=parmlrecl;                        //~va6QI~
                    if (parmlrecl && (retopt & FSOC_RETLRECLV))    //~vaj0I~
                        retlrecl=parmlrecl;                        //~vaj0I~
                    continue;                                      //~va00I~
                case 4:     //valid CP option                      //~va00I~
                    return 4;                                      //~va00I~
                }                                                  //~va00I~
            }                                                      //~va00I~
#endif                                                             //~va00M~
            switch (toupper(*pc2))                                 //~v47TI~
            {                                                      //~v47TI~
//            case 'M':       //mode option                          //~v47TI~//~va6HR~
//                if (UCBITCHK(Ppfh->UFHflag4,UFHF4BIN))//binary mode//~v47TI~//~va6HR~
//                {                                                  //~v47TI~//~va6HR~
//                    uerrmsg("%s option is invalid for file opened binary mode",//~v47TI~//~va6HR~
//                            "バイナリーモードでは %s オプションは無効。",//~v47TI~//~va6HR~
//                            pc);                                   //~v47TI~//~va6HR~
//                    return 4;                                      //~v47TI~//~va6HR~
//                }                                                  //~v47TI~//~va6HR~
////#ifdef W32                                                       //~va66R~//~va6HR~
//                modesw=1;   //mode parm exist                      //~v59yI~//~va6HR~
////#endif                                                           //~va66R~//~va6HR~
//                for (;*(++pc2);)                                   //~v47TI~//~va6HR~
//                {                                                  //~v47TI~//~va6HR~
//                    switch(toupper(*pc2))                          //~v47TI~//~va6HR~
//                    {                                              //~v47TI~//~va6HR~
//                    case 'P':       //PC text file                 //~v47TI~//~va6HR~
////                      if (retopt & (FSOC_EOL_UNIX|FSOC_EOL_MAC)) //~v47xR~//~va66R~//~va6HR~
//                        if (retopt & (FSOC_EOL_UNIX|FSOC_EOL_MAC|FSOC_EOL_RECORD))//~va66I~//~va6DR~//~va6HR~
//                            return fileerrexclusiveopt();          //~v47TR~//~va6HR~
//                        retopt|=FSOC_EOL_PC;                       //~v47TR~//~va6HR~
//                        break;                                     //~v47TI~//~va6HR~
//                    case 'U':       //UNIX text file               //~v47TI~//~va6HR~
////                      if (retopt & (FSOC_EOL_PC|FSOC_EOL_MAC))   //~v47xR~//~va66R~//~va6HR~
//                        if (retopt & (FSOC_EOL_PC|FSOC_EOL_MAC|FSOC_EOL_RECORD))//~va66I~//~va6DR~//~va6HR~
//                            return fileerrexclusiveopt();          //~v47TR~//~va6HR~
//                        retopt|=FSOC_EOL_UNIX;                     //~v47TR~//~va6HR~
//                        break;                                     //~v47TI~//~va6HR~
//                    case 'M':       //Mac  text file               //~v47xI~//~va6HR~
////                      if (retopt & (FSOC_EOL_PC|FSOC_EOL_UNIX))  //~v47xI~//~va66R~//~va6HR~
//                        if (retopt & (FSOC_EOL_PC|FSOC_EOL_UNIX|FSOC_EOL_RECORD))//~va66I~//~va6DR~//~va6HR~
//                            return fileerrexclusiveopt();          //~v47xI~//~va6HR~
//                        retopt|=FSOC_EOL_MAC;                      //~v47xI~//~va6HR~
//                        break;                                     //~v47xI~//~va6HR~
//                    case 'R':       //Mac  text file               //~va66I~//~va6HR~
//                        if (retopt & (FSOC_EOL_PC|FSOC_EOL_UNIX|FSOC_EOL_MAC))//~va66I~//~va6DR~//~va6HR~
//                            return fileerrexclusiveopt();          //~va66I~//~va6HR~
//                        retopt|=FSOC_EOL_RECORD;                   //~va66I~//~va6HR~
//                        break;                                     //~va66I~//~va6HR~
//                    default:                                       //~v47xI~//~va6HR~
//                        return errinvalid(pc);                     //~v47xI~//~va6HR~
//                    }                                              //~v47TI~//~va6HR~
//                }//for                                             //~v47TI~//~va6HR~
//                break;                                             //~v47TI~//~va6HR~
//            case 'F':       //fixed lrecl                          //~va66I~//~va6QR~
//                if (UCBITCHK(Ppfh->UFHflag4,UFHF4BIN))//binary mode//~va66I~//~va6QR~
//                {                                                  //~va66I~//~va6QR~
//                    uerrmsg("%s option is invalid for file opened binary mode",//~va66I~//~va6QR~
//                            "バイナリーモードでは %s オプションは無効。",//~va66I~//~va6QR~
//                            pc);                                   //~va66I~//~va6QR~
//                    return 4;                                      //~va66I~//~va6QR~
//                }                                                  //~va66I~//~va6QR~
//                pc2++;                                             //~va66I~//~va6QR~
//                pc3=strchr(pc2,'-');     //margin delm             //~va66I~//~va6QR~
//                if (pc3)                                           //~va66I~//~va6QR~
//                {                                                  //~va66I~//~va6QR~
//                    pc3++;                                         //~va66I~//~va6QR~
//                    wlen=(int)strlen(pc3);                         //~va66I~//~va6QR~
//                    if (!wlen || unumlen(pc3,0,wlen)!=wlen)        //~va66I~//~va6QR~
//                        return errinvalid(pc);                     //~va66I~//~va6QR~
//                    fixmargin=atoi(pc3);                           //~va66I~//~va6QR~
//                    wlen=(int)((ULONG)pc3-(ULONG)pc2-1);           //~va66R~//~va6QR~
//                }                                                  //~va66I~//~va6QR~
//                else                                               //~va66I~//~va6QR~
//                {                                                  //~va66I~//~va6QR~
//                    wlen=(int)strlen(pc2);                         //~va66I~//~va6QR~
//                    fixmargin=0;                                   //~va66I~//~va6QR~
//                }                                                  //~va66I~//~va6QR~
//                if (!wlen || unumlen(pc2,0,wlen)!=wlen)            //~va66R~//~va6QR~
//                    return errinvalid(pc);                         //~va66I~//~va6QR~
//                fixlrecl=atol(pc2);                                //~va66I~//~va6QR~
//                if (!fixmargin)                                    //~va66I~//~va6QR~
//                    fixmargin=fixlrecl;                            //~va66R~//~va6QR~
//                else                                               //~va66I~//~va6QR~
//                if (fixlrecl<fixmargin)                            //~va66I~//~va6QR~
//                    return errinvalid(pc);                         //~va66I~//~va6QR~
//                retlrecl=(fixlrecl<<16)|fixmargin;                 //~va66I~//~va6QR~
//                break;                                             //~va66I~//~va6QR~
            default:                                               //~v47TI~
                return errinvalid(pc);                             //~v47TI~
            }                                                      //~v47TI~
        }                                                          //~v47TI~
        else		//not flag option                              //~v47TI~
        {                                                          //~v47TI~
//        if(*pc!='.')      //process label later                  //~v57yR~
          if (*pc!=ULCCMDLABEL   //lebel specified                 //~v57yI~
//        ||  (*(pc+1)=='/'||*(pc+1)=='\\'))                       //~v582R~
          ||  (*(pc+1)=='/'||*(pc+1)=='\\'||*(pc+1)==ULCCMDLABEL)) //~v582R~
          {                                                        //~v54YI~
            if (filectr)                                           //~v47TI~
                return errtoomany();                               //~v47TI~
            filectr++;                                             //~v47TR~
		    if (Ppfnm)                                             //~v47TI~
        	    *Ppfnm=pc;                                         //~v47TR~
          }//not label                                             //~v54YI~
          else                                                     //~v559I~
            labelsw=1;                                             //~v559I~
        }                                                          //~v47TI~
    }                                                              //~v47TI~
    if (labelsw &&  (pft->FTfuncid==FUNCID_SAVE))                  //~v57wI~
    {                                                              //~v57wI~
    	uerrmsg("label is not supported for save cmd",             //~v57wI~
        		"SAVEコマンドでラベルは使えません");               //~v57wI~
        return 4;                                                  //~v57wI~
    }                                                              //~v57wI~
    modesw=retopt & FSOC_EOL_OPT;                                  //~va6HI~
//*  PC/UNIX/MAC/RECORD/RECORDV/EBC                                //~vaj0I~
    if (modesw                                                     //~va66I~
    ||  retlrecl                                                   //~va66I~
    )                                                              //~va66I~
    {                                                              //~va66I~
    	if (pft->FTfuncid==FUNCID_CREATE                           //~va66I~
    	||  pft->FTfuncid==FUNCID_REPL                             //~va66I~
    	||  pft->FTfuncid==FUNCID_APPEND                           //~vajqR~
    	||  (pft->FTfuncid==FUNCID_SAVE && filectr>0)              //~va66I~
        )                                                          //~va66I~
        	;                                                      //~va66I~
        else                                                       //~va66I~
        {                                                          //~va66I~
//      	uerrmsg("/M and /F option is valid for CRE/REP/SAV cmd with filename parameter",//~va66I~//~vaj6R~
//                  "/M と /F オプションは ファイル名指定の CRE/REP/SAV 用です");//~va66I~//~vaj6R~
//      	uerrmsg("/M and /F option is valid for END cmd or CRE/REP/SAV cmd with filename parameter",//~vaj6I~//~vajqR~
//                  "/M と /F オプションは END と ファイル名指定の CRE/REP/SAV 用です");//~vaj6I~//~vajqR~
        	uerrmsg("/M and /F option is valid for END cmd or CRE/REP/APP/SAV cmd with filename parameter",//~vajqI~
                    "/M と /F オプションは END と ファイル名指定の CRE/REP/APP/SAV 用です");//~vajqI~
    	    return 4;                                              //~va66I~
        }                                                          //~va66I~
    }                                                              //~va66I~
    if (chknewmode(filectr!=0,pft->FTfuncid,Ppfh,retopt,&retlrecl))//~vaj0R~
    	return 4;                                                  //~vaj0I~
    if (retopt & FSOC_EOL_RECORDV) // /MV option specified         //~vaj0R~
    {                                                              //~vaj0I~
        if (!retlrecl)                                             //~vaj0R~
        {                                                          //~vaj0R~
            uerrmsg("variable Length Record write, specify record format by /Fvfmt option",//~vaj0R~
                    "可変長レコード出力には -Fvfmt で レコード形式を指定する");//~vaj0R~
            return 4;                                              //~vaj0R~
        }                                                          //~vaj0R~
        if (retopt & FSOC_RETLRECL) //-Flrecl                      //~vaj0I~
            return fileerrlreclforV(4/*rc*/);                      //~vaj0I~
    }                                                              //~vaj0I~
    else                                                           //~vaj0I~
    if (retopt & FSOC_EOL_RECORD) // /MR option specified          //~va66R~
    {                                                              //~va66I~
    	if (!retlrecl)                                             //~va66I~
        {                                                          //~va66I~
	    	uerrmsg("Record mode write, specify record length by /F option",//~va66R~//~vaj0R~
                    "レコードモード出力には /F で レコード長を指定する");//~va66I~
    	    return 4;                                              //~va66I~
        }                                                          //~va66I~
        if (retopt & FSOC_RETLRECLV) //-Flrecl                     //~vaj0I~
			return fileerrvfmtforR(4);                             //~vaj0I~
    }                                                              //~va66I~
    else                                                           //~va66I~
    {                                                              //~va66I~
        if (retlrecl)                                              //~va66I~
        {                                                          //~vaj0I~
//          if (!UCBITCHK(Ppfh->UFHflag10,UFHF10RECORD))           //~va66R~//~vaj6R~
//          {                                                      //~va66R~//~vaj6R~
//              uerrmsg("/F option is for Record mode write",      //~va66R~//~vaj0R~//~vaj6R~
//                      "レコード長オプション(/F)はレコードモード出力用です");//~va66I~//~vaj0I~//~vaj6R~
//              return 4;                                          //~va66R~//~vaj6R~
//          }                                                      //~va66R~//~vaj6R~
            if ((retopt & FSOC_RETLRECL) && !(retopt & FSOC_EOL_NOTRECORDV))//~vaj6R~
            {                                                      //~vaj6I~
        		uerrmsg("-Flrecl option requires -Mx (x!=v)",      //~vaj6R~
                	    "-Flreclを指定するときは -Mx(xはv以外)が必要");//~vaj6I~
                return 4;                                          //~vaj6I~
        	}                                                      //~vaj6I~
            if ((retopt & FSOC_RETLRECLV) && !(retopt & FSOC_EOL_RECORDV))//~vaj6I~
            {                                                      //~vaj6I~
        		uerrmsg("-Fvfmt option requires -Mv",              //~vaj6I~
                	    "-Fvfmt を指定するときは -Mvが必要");      //~vaj6I~
                return 4;                                          //~vaj6I~
        	}                                                      //~vaj6I~
        }                                                          //~vaj0I~
    }                                                              //~va66I~
    if (retopt & (FSOC_SOSI_DEL|FSOC_SOSI_REP|FSOC_SOSI_INS))      //~va6cR~
    {                                                              //~va6cI~
    	if (!(retopt & (FSOC_CPU8|FSOC_CPLC|FSOC_CPEB)))           //~va6cI~
        {                                                          //~va6cI~
            uerrmsg("Specify SOSI option with CPxx translation option",//~va6cI~
                    "SOSI オプションは CPxx 変換オプションのときに使用");//~va6cI~
            return 4;                                              //~va6cI~
        }                                                          //~va6cI~
    }                                                              //~va6cI~
    if (Ppretlrecl)                                                //~va66I~
        *Ppretlrecl=retlrecl;                                      //~va66R~
//    if (labelsw && allsw)                                        //~v57PR~
//            return fcmdlabelerr("All and label is mixed");       //~v57PR~
//    if (labelsw || allsw)                                        //~v57PR~
//        if (!(retopt & (FSOC_NXALL|FSOC_XALL)))                  //~v57PR~
//        {                                                        //~v57PR~
//            uerrmsg("label is avail with X or NX option",        //~v57PR~
//                    "ラベル指定は X か NX オプションで指定します。");//~v57PR~
//            return 4;                                            //~v57PR~
//        }                                                        //~v57PR~
    if (labelsw && !(retopt & (FSOC_NXALL|FSOC_XALL)))             //~v57PI~
        retopt|=(FSOC_NXALL|FSOC_XALL); //default both             //~v57PI~
#ifdef W32                                                         //~v59yM~
    if (!modesw)     //no mode parm exist                          //~v59yM~
    {                                                              //~v59yM~
        if (!UCBITCHK(Ppfh->UFHflag4,UFHF4BIN))//not binary mode   //~v59yM~
          if (opdno)                                               //~v783I~
    		if (uftpisremote(Ppcw->UCWparm,&puftph)) //remote hostname prefix exist//~v59yM~
        		retopt|=FSOC_EOL_UNIX;                             //~v59yM~
    }                                                              //~v59yM~
#endif                                                             //~v59yM~
#ifdef UTF8SUPPH                                                   //~va00I~
    if (FILEUTF8MODE(Ppfh))                                        //~va00I~
    {                                                              //~va00I~
        if (!(retopt & (FSOC_CPU8|FSOC_CPLC)))                     //~va00I~
            retopt|=FSOC_BK;                                       //~va00R~
    }                                                              //~va00I~
#endif                                                             //~va00I~
	if (Pretopt)                                                   //~v47TI~
	    *Pretopt=retopt;                                           //~v47TR~
    if (Ppplh1)                                                    //~v54YI~
    {                                                              //~v54YI~
//  	rc=fcmdgetlabparm(Ppcw,Ppplh1,Ppplh2,FCGLP_SPLITCHK|FCGLP_0IFNOLAB);	//label on split line is err//~v62HR~
    	rc=fcmdgetlabparm(Ppcw,0,Ppplh1,Ppplh2,FCGLP_SPLITCHK|FCGLP_0IFNOLAB);	//label on split line is err//~v62HI~
        if (rc)                                                    //~v54YI~
        	return rc;                                             //~v54YI~
    }                                                              //~v54YI~
    return 0;                                                      //~v47TI~
}//filesaveoptionchk                                               //~v47TI~
#ifdef UTF8SUPPH                                                   //~va00I~
//**************************************************************** //~va00I~
// fileselectutf8optionchk                                         //~va00I~
//*for select cmd; set utf8 option from dirlist open option        //~va00I~
//**************************************************************** //~va00I~
int fileselectutf8optionchk(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh) //~va00I~
#define FSU8OCO_SELECTONLY   0x01  //set SELECTFNxx only           //~vb2gI~
{                                                                  //~va00I~
	PUFILEC pfc;                                                   //~va00I~
//    PUFILEH pfhdir;                                                //~vb2gI~//~vb2jR~
//******************                                               //~va00I~
	if (UCBITCHK(Ppfh->UFHflag4,UFHF4BIN))                         //~va00I~
    	return 0;                                                  //~va00I~
    if (!UCBITCHK(Ppcw->UCWflag2,UCWF2SELECTCMD))   //not select from dirlist//~va00I~
    	return 0;                                                  //~va00I~
    pfc=Ppcw->UCWpfc;                                              //~va00I~
  if (Popt & FSU8OCO_SELECTONLY) //set SELECTFNxx only             //~vb2gI~
  {                                                                //~vb2gI~
//    if (!UCBITCHK(pfc->UFCflag3,UFCF3SELECTDLCMD))  //select cmd not dlcmd//~vb2gI~//~vb2jR~
//    {                                                              //~vb2gI~//~vb2jR~
//        if (!UCBITCHK(Ppfh->UFHflag12,UFHF12FNCMD))                //~vb2gI~//~vb2jR~
//        {                                                          //~vb2gI~//~vb2jR~
//            pfhdir=pfc->UFCpfh;                                    //~vb2gR~//~vb2jR~
//            if (UCBITCHK(pfhdir->UFHflag13,UFHF13SELECTFNU8)       //~vb2gR~//~vb2jR~
//            ||  UCBITCHK(pfhdir->UFHflag12,UFHF12FNU8)             //~vb2gR~//~vb2jR~
//            ||  UCBITCHK(pfhdir->UFHflag14,UFHF14MOUNTU8)          //~vb2gR~//~vb2jR~
//            )                                                      //~vb2gR~//~vb2jR~
//                UCBITON(Ppfh->UFHflag13,UFHF13SELECTFNU8);  //implicit EBC8 by dir option//~vb2gR~//~vb2jR~
//            else                                                   //~vb2gR~//~vb2jR~
//            if (UCBITCHK(pfhdir->UFHflag13,UFHF13SELECTFNLC)       //~vb2gR~//~vb2jR~
//            ||  UCBITCHK(pfhdir->UFHflag12,UFHF12FNLC)             //~vb2gR~//~vb2jR~
//            )                                                      //~vb2gR~//~vb2jR~
//                UCBITON(Ppfh->UFHflag13,UFHF13SELECTFNLC);  //implicit EBC8 by dir option//~vb2gR~//~vb2jR~
//        }                                                          //~vb2gI~//~vb2jR~
//    }                                                              //~vb2gI~//~vb2jR~
//    else                                                           //~vb2gI~//~vb2jR~
    if (UCBITCHK(pfc->UFCflag3,UFCF3SELECTFNU8))     //dirlist is not opened by cpu8/cplc//~vauaI~
        UCBITON(Ppfh->UFHflag13,UFHF13SELECTFNU8);	//implicit EBC8 by dir option//~vauaI~
    else                                                           //~vauaI~
    if (UCBITCHK(pfc->UFCflag3,UFCF3SELECTFNLC))     //dirlist is not opened by cpu8/cplc//~vauaI~
        UCBITON(Ppfh->UFHflag13,UFHF13SELECTFNLC);	//implicit EBC8 by dir option//~vauaI~
    return 0;                                                      //~vb2gR~
  }//select only                                                   //~vb2gI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    if (UCBITCHK(pfc->UFCflag3,UFCF3EBCP))     //dirlist is not opened by cpu8/cplc//~va50R~
    {                                                              //~va50I~
        UCBITON(Ppfh->UFHflag10,UFHF10EBC);	//implicit EBC8 by dir option//~va50I~
    }                                                              //~va50I~
    else                                                           //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    if (!UCBITCHK(pfc->UFCflag2,UFCF2UTF8P))    //dirlist is not opened by cpu8/cplc//~va00R~
    	return 0;                                                  //~va00I~
    if (UCBITCHK(pfc->UFCflag2,UFCF2UTF8))                         //~va00I~
        UCBITON(Ppfh->UFHflag8,UFHF8UTF8);	//as cpu8 option specified//~va00R~
    else                                                           //~va00I~
    {                                                              //~va00I~
        UCBITOFF(Ppfh->UFHflag8,UFHF8UTF8);	//reset profile(dirlist) setting,but accept dirlist open option//~va00I~
    }                                                              //~va00I~
    return 1;                                                      //~va00I~
}//fileselectutf8optionchk                                         //~va00I~
#endif                                                             //~va00I~
//**************************************************************** //~v08lI~
// fileoptionchk                                                   //~v08lI~
//*chk option parm;called from fileload before load                //~v10XR~
//*parm1:pcw                                                       //~v08lI~
//*parm2:pfh                                                       //~v08lI~
//*parm3:option(UFCFBROWSE or not)                                 //~v10DI~
//*parm4:option(01:force /Mb,02:force SPF)                         //~v10LR~
//*rc   :0 ok,4 err                                                //~v08lI~
//**************************************************************** //~v08lI~
//int fileoptionchk(PUCLIENTWE Ppcw,PUFILEH Ppfh,UCHAR Popt,UCHAR Pbinsw)//~v75HR~
int fileoptionchk(PUCLIENTWE Ppcw,PUFILEH Ppfh,UCHAR Popt,int Pbinsw)//~v75HI~
{                                                                  //~v08lI~
    int ii,rc;                                                     //~v08lR~
    long start=0,end=0,numctr=0;                                   //~v08qR~
    UCHAR *pc,*pc0=0;                                              //~vaf9R~
    int wmode;                                                     //~v09YI~
    int opt;                                                       //~v41gR~
    int opt2;                                                      //~v54cI~
    int widthsw=0,wlen,width=0;                                    //~v19sR~
//  ULONG xranges=0,xrangee=0;                                     //~vaz0R~
    FILESZT xranges=0,xrangee=0;                                   //~vaz0I~
    int xrangesw=0;                                                //~v10YI~
    int cobopt=0,cobopt0=0,protopt=0;                              //~v41hR~
    int nocobnumsw=0;                                              //~v42xI~
    int binmerginsw=0;                                             //~v616I~
    int fixlrecl=0,fixmargin;                                      //~vaf9R~
    UCHAR *pc2;                                                    //~v71KI~
    UFILEH fhsv;                                                   //~v78rI~
    long setflag;                                                  //~v78rR~
#ifdef UTF8SUPPH                                                    //~v90nI~//~va00R~
    int utf8opt=0;                                                 //~v90nR~//~va00I~
    int localeutf8mode=0;                                          //~v90uR~//~va00I~
//  int widthcolsw=0;                                              //~v91QI~//~va00R~
#endif                                                             //~v90nI~//~va00I~
    int swrecordmode=0,swlreclparm=0;                              //~va51R~
    #define SWRECORDMODE_VPARM  4                                  //~vaj0I~
    #define SWRECORDMODE_VPROF  5                                  //~vaj0I~
    int swvfmtparm=0;                                              //~vaj0I~
//  int swnotc=0;                                                  //~va51I~//~vaa7R~
    int swtc=0;                                                    //~va5YI~
    int swwritemode=0;                                             //~va6DI~
    int handle=-1;                                                 //~va79I~
    int fnutf8opt=0;                                               //~vagEI~
    int lreclv=UFGETS_VFMT_DEFAULT; //default recfm=V format :rdw  //~vaj0R~
    int lrecl2profile=0;   //update profile lrecl                  //~vaj0I~
    int swmh=0;		// -Mh option                                  //~vaj6R~
//*******************                                              //~v08lI~
    memcpy(&fhsv,Ppfh,sizeof(UFILEH));                             //~v78rI~
    setflag=0;                                                     //~va86I~
    if (Sswprechk)		//no prechk                                //~v78rR~
		Sprechkprofileopt=0;	//prechk option to be passed to getprofile//~v78rI~
    else                                                           //~v78rI~
    {                                                              //~v78rI~
    	fcmdprofgetprofile(Sprechkprofileopt,Ppfh,&setflag);       //~v78rR~
        Ppfh->UFHprofile=(ULONG)setflag;                           //~v78rR~
        if (Ppfh->UFHvfmt)                                         //~vaj0I~
        	lreclv=Ppfh->UFHvfmt;	//use not default(RDW) but profile setting for -Mvr without -Fvfmt//~vaj0I~
    }                                                              //~v78rI~
	UCBITON(Ppfh->UFHflag3,                                        //~v0aaI~
            UFHF3RTEXTPC | UFHF3RBIN |                             //~v0aaI~
//*         UFHF3WTEXTPC | UFHF3WBIN );	//default mode             //~v10uR~
            UFHF3RTEXTUNIX | UFHF3WBIN );	//default mode         //~v10uI~
//  Ppfh->UFHwidth=Gfhwidthtxt;	//default display width for text   //~v10DR~
#ifdef UTF8SUPPH                                                    //~v90uI~//~va00R~
	if (Pbinsw & BESOPT_LOCALE)                                    //~v90uR~//~va00I~
    {                                                              //~v90uI~//~va00I~
		Pbinsw &= ~BESOPT_LOCALE;  //accepted                      //~v90uR~//~va00I~
        localeutf8mode=1;                                          //~v90uR~//~va00I~
    }                                                              //~v90uI~//~va00I~
    else                                                           //~va00I~
	if (Pbinsw & BESOPT_CPLC)       //filefk etc                   //~va00I~
    {                                                              //~va00I~
		Pbinsw &= ~BESOPT_CPLC;  //accepted                        //~va00I~
        localeutf8mode=2;                                          //~va00I~
    }                                                              //~va00I~
    else                                                           //~va00I~//~va0CR~
	if (Pbinsw & BESOPT_CPU8)       //wxp cmd work etc             //~va00I~//~va0CR~
    {                                                              //~va00I~//~va0CR~
		Pbinsw &= ~BESOPT_CPU8;  //accepted                        //~va00I~//~va0CR~
        localeutf8mode=3;                                          //~va00I~//~va0CR~
    }                                                              //~va00I~//~va0CR~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	if (Pbinsw & BESOPT_CPEB)       //wxp cmd work etc             //~va50I~
    {                                                              //~va50I~
		Pbinsw &= ~BESOPT_CPEB;  //accepted                        //~va50I~
        localeutf8mode=4;                                          //~va50I~
    }                                                              //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
	if (Pbinsw & BESOPT_IE)                                        //~va00I~
    {                                                              //~va00I~
		Pbinsw &= ~BESOPT_IE;  //accepted                          //~va00I~
	    UCBITON(Ppfh->UFHflag10,UFHF10UTF8IE);                     //~va00I~
    }                                                              //~va00I~
    else                                                           //~va00I~
    	UCBITOFF(Ppfh->UFHflag10,UFHF10UTF8IE);                    //~va00R~
#endif                                                             //~v90uI~//~va00I~
  if (Pbinsw)                                                      //~v10EI~
  {                                                                //~v10EI~
   if (Pbinsw==BESOPT_F80)                                         //~v75HR~
   {                                                               //~v75HR~
    Ppfh->UFHlrecl=STDSPFLRECL;                                    //~v75HR~
    Ppfh->UFHmergin=STDSPFLRECL;                                   //~v75HR~
    UCBITON(Ppfh->UFHflag2,UFHF2MERGIN);                           //~v75HR~
    UCBITON(Ppfh->UFHflag7,UFHF7FIXLRECL);                         //~v75HR~
	Sprechkprofileopt|=FPURO_LRECL;	//ignore lrecl saved in profile//~va51I~
    Sprechkprofileopt|=FPURO_RECORD|FPURO_RECORDV; //do not set from profile//~vaj0I~
    swlreclparm=1;                                                 //~va51I~
   }                                                               //~v75HR~
   else                                                            //~v75HR~
   if (Pbinsw==BESOPT_SPF)                                         //~v10LI~
   {                                                               //~vaj0I~
//  UCBITON(Ppfh->UFHflag4,UFHF4SPFCMD);                           //~v41hR~
    cobopt0=1;          //numberd file                             //~v41hI~
    Sprechkprofileopt|=FPURO_RECORD|FPURO_RECORDV; //do not set from profile//~vaj0R~
   }                                                               //~vaj0I~
   else                                                            //~v414I~
   if (Pbinsw==BESOPT_SPFCOB)                                      //~v414I~
   {                                                               //~v414I~
//  UCBITON(Ppfh->UFHflag4,UFHF4SPFCMD);                           //~v41hR~
//  UCBITON(Ppfh->UFHflag5,UFHF5COB|UFHF5NOAUTONUM);		//cob file//~v41hR~
    cobopt0=2;          //numberd file without col 72              //~v41hI~
    Sprechkprofileopt|=FPURO_RECORD|FPURO_RECORDV; //do not set from profile//~vaj0I~
   }                                                               //~v414I~
   else                                                            //~v414I~
   if (Pbinsw==BESOPT_SPFCOBNUM)                                   //~v414I~
   {                                                               //~v414I~
//  UCBITON(Ppfh->UFHflag4,UFHF4SPFCMD);                           //~v41hR~
//  UCBITON(Ppfh->UFHflag5,UFHF5COB);		//cob file             //~v41hR~
    cobopt0=3;          //numberd file  cob and col72              //~v41hI~
    Sprechkprofileopt|=FPURO_RECORD|FPURO_RECORDV; //do not set from profile//~vaj0I~
   }                                                               //~v414I~
   else                                                            //~v42yI~
   if (Pbinsw==BESOPT_SPFCOB2)                                     //~v42yI~
   {                                                               //~v42yI~
    	cobopt0=2;          //numberd file without col 72          //~v42yI~
    	nocobnumsw=1;                                              //~v42yI~
    Sprechkprofileopt|=FPURO_RECORD|FPURO_RECORDV; //do not set from profile//~vaj0I~
   }                                                               //~v42yI~
   else                                                            //~v42yI~
   if (Pbinsw==BESOPT_SPFCOB2NUM)                                  //~v42yI~
   {                                                               //~v42yI~
    	cobopt0=3;          //numberd file  cob and col72          //~v42yI~
    	nocobnumsw=1;                                              //~v42yI~
    Sprechkprofileopt|=FPURO_RECORD|FPURO_RECORDV; //do not set from profile//~vaj0I~
   }                                                               //~v42yI~
   else                                                            //~v10LI~
   if (Pbinsw==BESOPT_TEXT)		// /mt                             //~v48dI~
   {                                                               //~v48dI~
		UCBITOFF(Ppfh->UFHflag4,UFHF4BIN);                         //~v48dI~
		UCBITON(Ppfh->UFHflag4,UFHF4TEXT);//explicit text mode     //~v48dI~
	Sprechkprofileopt|=FPURO_LRECL;	//ignore lrecl saved in profile//~vaj0I~
    Sprechkprofileopt|=FPURO_RECORD|FPURO_RECORDV; //do not set from profile//~vaj0I~
   }                                                               //~v48dI~
   else                                                            //~v48dI~
   {                                                               //~v10LI~
	UCBITON(Ppfh->UFHflag4,UFHF4BIN);                              //~v10EI~
    Sprechkprofileopt|=FPURO_LRECL|FPURO_RECORD|FPURO_RECORDV; //do not set from profile//~vaj0R~
	width=(int)Gfhwidth;	//default display width for binary mode//~v10EI~
   	if (Pbinsw==BESOPT_HEX)                                        //~v440R~
    {                                                              //~v440R~
  		if (setflag & FPURO_CP) //profile has codepage attr        //~va86I~
        	UCBITOFF(Ppfh->UFHflag8,UFHF8UTF8|UFHF8UTF8P);  //keep ebc//~va86I~
		UCBITON(Ppfh->UFHflag5,UFHF5HEX);                          //~v440R~
        width=(int)Gfhxwidth;	//default display width            //~v440R~
    }                                                              //~v440R~
   }                                                               //~v10LI~
  }	                                                               //~v10EI~
  else                                                             //~v10EI~
	if (UCBITCHK(Popt,UFCFBROWSE))                                 //~v10DI~
		width=(int)Gfhwidthtxt;	//default display width for browse //~v10DI~
	else                                                           //~v10DI~
		width=(int)Gfhwidthtxtedit;	//default display width for browse//~v10EI~
 if (!Sswprechk)		//not prechk(after profile chk)            //~v794I~
  if (!(setflag & FPURO_CAPS)) //no profile data set               //~v78rI~
  {                                                                //~v78rI~
#ifdef FTPSUPP                                                     //~v71LI~
    if (FILEISTSO(Ppfh))                                           //~v71LR~
    {                                                              //~v71LI~
		if (UCBITCHK(Goptopt,GOPT_CAPLOCK_TSO))                    //~v71LR~
			UCBITON(Ppfh->UFHflag8,UFHF8CAPSON);                   //~v71LI~
    }                                                              //~v71LI~
    else                                                           //~v71LI~
#endif                                                             //~v71LI~
		if (UCBITCHK(Goptopt,GOPT_CAPLOCK_DEFAULT))                //~v71LR~
			UCBITON(Ppfh->UFHflag8,UFHF8CAPSON);                   //~v71LI~
  }                                                                //~v78rI~
	Ppfh->UFHwidth=(USHORT)width;                                  //~v10DI~
//  if ((ii=Ppcw->UCWopdno-1)<=0)                                  //~v41hR~
//  	return 0;                                                  //~v41hR~
  if ((ii=Ppcw->UCWopdno-1)>0)                                     //~v41hI~
  {                                                                //~v41hI~
    pc=Ppcw->UCWopdpot;                                            //~v08lI~
    for (;pc+=strlen(pc)+1,ii;ii--)                                //~v08qR~
    {                                                              //~v08lI~
    	pc0=pc;			//save start addr                          //~v08lI~
    	if (*pc=='/')                                              //~v08lI~
        	pc++;                                                  //~v08lI~
        if (*pc=='-' && (*(pc+1)<'0'||*(pc+1)>'9'))//- but not -digit//~v19sI~
        	pc++;                                                  //~v19sI~
        if (strlen(pc)>=3 && !memicmp(pc,"CAP",3))                 //~v69JM~
        {                                                          //~v69JM~
			UCBITON(Ppfh->UFHflag8,UFHF8CAPSON);                   //~v69JR~
            continue;                                              //~v69JM~
        }                                                          //~v69JM~
//      if (strlen(pc)>=3 && !memicmp(pc,"NOCAP",3))               //~v78rR~
        if (strlen(pc)>=5 && !memicmp(pc,"NOCAP",5))               //~v78rI~
        {                                                          //~v71LI~
			UCBITOFF(Ppfh->UFHflag8,UFHF8CAPSON);                  //~v71LI~
            continue;                                              //~v71LI~
        }                                                          //~v71LI~
        if (strlen(pc)>=5 && !memicmp(pc,"NONUM",5))               //~v71KI~
        {                                                          //~v71KI~
			UCBITON(Ppfh->UFHflag7,UFHF7NONUMOPT);                 //~v71KR~
			Sprechkprofileopt|=(FPURO_NUMSTD|FPURO_NUMCOB|FPURO_LRECL);	//ignore spf profile//~v78rR~
            continue;                                              //~v71KI~
        }                                                          //~v71KI~
        if (strlen(pc)>=2 && !memicmp(pc,"TC",2))                  //~v71VR~
        {                                                          //~v71VI~
  			UCBITOFF(Ppfh->UFHflag8,UFHF8NOTABCLEAR);	//cmd parm deny to tab clear at save//~v71VR~
			UCBITON(Ppfh->UFHflag5,UFHF5DROPTAB);	//tab clear at save//~v71VI~
		    swtc=1;                                                //~va5YI~
            continue;                                              //~v71VI~
        }                                                          //~v71VI~
        if (strlen(pc)>=4 && !memicmp(pc,"NOTC",4))                //~v71VR~
        {                                                          //~v71VI~
  			UCBITON(Ppfh->UFHflag8,UFHF8NOTABCLEAR);	//cmd parm deny to tab clear at save//~v71VR~
			UCBITOFF(Ppfh->UFHflag5,UFHF5DROPTAB);	//tab clear at save//~v71VI~
//  	    swnotc=1;                                              //~va51I~//~vaa7R~
            continue;                                              //~v71VI~
        }                                                          //~v71VI~
        if (strlen(pc)>=2 && !memicmp(pc,"NB",2))                  //~v76zI~
        {                                                          //~v76zI~
  			UCBITON(Ppfh->UFHflag8,UFHF8NOBKSV);	//cmd parm deny to tab clear at save//~v76zI~
            continue;                                              //~v76zI~
        }                                                          //~v76zI~
#ifdef UTF8SUPPH                                                    //~v90nI~//~va00R~
//      if(XEUTF8MODE())                                           //~v91HR~//~va00I~
//      {                                                          //~v91HR~//~va00I~
            if (strlen(pc)==LANGOPT_UTF8SZ && !memicmp(pc,LANGOPT_UTF8,LANGOPT_UTF8SZ))//~v90nR~//~va00I~
            {                                                      //~v90nR~//~va00I~
				if (!XEUTF8MODE())                                 //~v91HI~//~va00I~
                	return errnotsupported(LANGOPT_UTF8 " Option","Non-UTF8 mode");//~v91HI~//~va00I~
                utf8opt='U';                                       //~v90nR~//~va00I~
				Sprechkprofileopt|=FPURO_CP;	//ignore this profile option//~v78wI~//~va00I~
                continue;                                          //~v90nR~//~va00I~
            }                                                      //~v90nR~//~va00I~
            if (strlen(pc)==LANGOPT_LOCALESZ && !memicmp(pc,LANGOPT_LOCALE,LANGOPT_LOCALESZ))//~v90nR~//~va00I~
            {                                                      //~v90nR~//~va00I~
				if (!XEUTF8MODE())                                 //~v91HI~//~va00I~
                	return errnotsupported(LANGOPT_LOCALE " Option","Non-UTF8 mode");//~v91HI~//~va00I~
                utf8opt='L';                                       //~v90nR~//~va00I~
				Sprechkprofileopt|=FPURO_CP;	//ignore this profile option//~v78wI~//~va00I~
                continue;                                          //~v90nR~//~va00I~
            }                                                      //~v90nR~//~va00I~
            if (strlen(pc)==LANGOPT_ASISSZ && !memicmp(pc,LANGOPT_ASIS,LANGOPT_ASISSZ))//~v78wI~//~va00I~
            {                                                      //~v78wI~//~va00I~
				if (!XEUTF8MODE())                                 //~v78wI~//~va00I~
                	return errnotsupported(LANGOPT_ASIS " Option","Non-UTF8 mode");//~v78wI~//~va00I~
                utf8opt='A';                                       //~v78wI~//~va00I~
				Sprechkprofileopt|=FPURO_CP;	//ignore this profile option//~v78wI~//~va00I~
                continue;                                          //~v78wI~//~va00I~
            }                                                      //~v78wI~//~va00I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50M~
        	if (!stricmp(pc,MODE_EBC))    //ignore cv err cmd option//~va50I~
        	{                                                      //~va50I~
				if (xeebc_init(XEEBCIO_CHKCFG,0/*cfgparm output*/))//~va50I~
            		return 4;	//ebc cfg err                      //~va50I~
                utf8opt=CPOPT_EBC;                                 //~va50I~
				Sprechkprofileopt|=FPURO_CP;	//ignore this profile option//~va50I~
            	continue;                                          //~va50I~
        	}                                                      //~va50I~
        	if (USTRHEADIS_IC(pc,OPTSTR_CODEPAGE))    //icase CP=  //~va79R~
        	{                                                      //~va79I~
				if (fileoptionchkebcconverter(0,pc,sizeof(OPTSTR_CODEPAGE)-1,&handle))//~va79R~
            		return 4;	//ebc cfg err                      //~va79I~
                utf8opt=CPOPT_EBC;                                 //~va7tR~
				Sprechkprofileopt|=FPURO_CP|FPURO_CVNAME;	//ignore this profile option//~va79R~
            	continue;                                          //~va79I~
        	}                                                      //~va79I~
#endif //UTF8EBCS raw ebcdic file support                          //~va50M~
    		if (!stricmp(pc,MODE_IE))    //ignore cv err cmd option//~va00R~
    		{                                                      //~va00I~
        		if (UCBITCHK(Ppfh->UFHflag4,UFHF4BIN))//binary mode//~va00I~
            		return erroptionforbinfile(pc,4);              //~va00R~
                UCBITON(Ppfh->UFHflag10,UFHF10UTF8IE);             //~va00I~
                continue;                                          //~va00I~
            }                                                      //~va00I~
            if  (!stricmp(pc,MODE_FNU8))                           //~vagEI~
            {                                                      //~vagEI~
				if (!XEUTF8MODE())                                 //~vagEI~
                	return errnotsupported(MODE_FNU8 " Option","Non-UTF8 mode");//~vagEI~
                fnutf8opt='U';                                     //~vagEI~
				Sprechkprofileopt|=FPURO_FNCP;	//ignore this profile option//~vagEI~
                continue;                                          //~vagEI~
            }                                                      //~vagEI~
            if  (!stricmp(pc,MODE_FNLC))                           //~vagEI~
            {                                                      //~vagEI~
				if (!XEUTF8MODE())                                 //~vagEI~
                	return errnotsupported(MODE_FNLC " Option","Non-UTF8 mode");//~vagER~
                fnutf8opt='L';                                     //~vagEI~
				Sprechkprofileopt|=FPURO_FNCP;	//ignore this profile option//~vagEI~
                continue;                                          //~vagEI~
            }                                                      //~vagEI~
            if  (!stricmp(pc,MODE_FNAS))                           //~vagEI~
            {                                                      //~vagEI~
				if (!XEUTF8MODE())                                 //~vagEI~
                	return errnotsupported(MODE_FNLC " Option","Non-UTF8 mode");//~vagEI~
                fnutf8opt='A';                                     //~vagEI~
				Sprechkprofileopt|=FPURO_FNCP;	//ignore this profile option//~vagEI~
                continue;                                          //~vagEI~
            }                                                      //~vagEI~
//      }                                                          //~v91HR~//~va00I~
#endif                                                             //~v90nI~//~va00I~
        if ((*pc>='0' && *pc<='9') || *pc=='-')                    //~v10wR~
        	opt='0';		//numeric value,assume line no	       //~v08lI~
		else                                                       //~v08lI~
        {                                                          //~v08qI~
	    	opt=toupper(*pc);                                      //~v08qR~
	    	pc++;                                                  //~v08qI~
        }                                                          //~v08qI~
    	switch(opt)                                                //~v08lI~
        {                                                          //~v08lI~
		case 'L':		//lineno                                   //~v08lI~
			if (!*pc)                                              //~v62xI~
            {                                                      //~v668I~
                Sswprechk=2;	//return listdir option specified id//~v668I~
            	break;		//listdir option                       //~v62xI~
            }                                                      //~v668I~
            wlen=(int)strlen(pc);                                  //~v62xI~
            if (unumlen(pc,0,wlen)!=wlen)                          //~v62xI~
				return errinvalid(pc0);                            //~v62xI~
            Ppfh->UFHiline=atol(pc);                               //~v62xI~
			break;                                                 //~v62xI~
//****************                                                 //~va51I~
//* Fn[-m] *                                                       //~va51R~
//****************                                                 //~va51I~
		case 'F':		//fixed lrecl                              //~v71KI~
			if (!xefile5getparmlreclV(0,pc,&lreclv))               //~vaj0R~
            {                                                      //~vaj0I~
            	lreclv=-lreclv;                                    //~vaj0I~
                swvfmtparm=1;                                      //~vaj0I~
                break;                                             //~vaj0I~
            }                                                      //~vaj0I~
        	pc2=strchr(pc,'-');                                    //~v71KI~
            if (pc2)                                               //~v71KI~
            {                                                      //~v71KI~
            	pc2++;                                             //~v71KI~
	            wlen=(int)strlen(pc2);                             //~v71KI~
	            if (!wlen || unumlen(pc2,0,wlen)!=wlen)            //~v71KI~
					return errinvalid(pc0);                        //~v71KI~
                fixmargin=atoi(pc2);                               //~v71KI~
//	            wlen=(int)((ULONG)pc2-(ULONG)pc-1);                //~v71KI~//~vafkR~
  	            wlen=(int)((ULPTR)pc2-(ULPTR)pc-1);                //~vafkI~
            }                                                      //~v71KI~
            else                                                   //~v71KI~
            {                                                      //~v71KI~
	            wlen=(int)strlen(pc);                              //~v71KR~
                fixmargin=0;                                       //~v71KI~
            }                                                      //~v71KI~
            if (!wlen || unumlen(pc,0,wlen)!=wlen)                 //~v71KI~
				return errinvalid(pc0);                            //~v71KI~
//          fixlrecl=atol(pc);                                     //~v71KI~//~vb2ER~
            fixlrecl=(int)atol(pc);                                //~vb2EI~
            if (fixlrecl<fixmargin)                                //~v71KI~
				return errinvalid(pc0);                            //~v71KI~
        	if (fixlrecl)                                          //~v71KI~
            {                                                      //~v71KI~
				Ppfh->UFHlrecl=(USHORT)fixlrecl;                   //~v71KI~
                if (!fixmargin)                                    //~v71KR~
                	fixmargin=fixlrecl;                            //~v71KR~
		    	Ppfh->UFHmergin=(USHORT)fixmargin;                 //~v71KI~
        		UCBITON(Ppfh->UFHflag2,UFHF2MERGIN);  //no drop last space//~v71KI~
				UCBITON(Ppfh->UFHflag7,UFHF7FIXLRECL);             //~v71KM~
            }                                                      //~v71KI~
            else                                                   //~v71KI~
            {                                                      //~va5dI~
				UCBITON(Ppfh->UFHflag7,UFHF7NOFIXOPT); //reset fix //~va5dM~
    			UCBITOFF(Ppfh->UFHflag10,UFHF10RECORD);	//reset profile//~va5dI~
				UCBITOFF(Ppfh->UFHflag7,UFHF7FIXLRECL);            //~va5dI~
        		UCBITOFF(Ppfh->UFHflag2,UFHF2MERGIN);  //no drop last space//~va5dI~
		    	Ppfh->UFHmergin=0;                                 //~va5dI~
				Ppfh->UFHlrecl=0;                                  //~va5dI~
            }                                                      //~va5dI~
			Sprechkprofileopt|=(FPURO_NUMSTD|FPURO_NUMCOB|FPURO_LRECL);	//ignore spf profile//~v78rI~
//          swlreclparm=1;                                         //~va51I~//~va6QR~
            swlreclparm=2;                                         //~va6QI~
			break;                                                 //~v71KI~
//        case 'I':       //lineno                                 //~v11AR~
		case '0':		//lineno                                   //~v08lI~
//            if (opt=='L' && !*pc)                                //~v40uR~
//            {                                                    //~v40uR~
//                UCBITON(Ppfh->UFHflag5,UFHF5LISTDIR);   //dirlist even if one member by wildcard//~v40uR~
//                break;                                           //~v40uR~
//            }                                                    //~v40uR~
//          if (opt=='L' && !*pc)                                  //~v668R~
//          {                                                      //~v668R~
//              Sswprechk=2;	//return listdir option specified id//~v668R~
//              break;                                             //~v668R~
//          }                                                      //~v668R~
            UCBITON(Ppfh->UFHflag4,UFHF4NLINENO);                  //~v119I~
            UCBITOFF(Ppfh->UFHflag4,UFHF4XLINENO);                 //~v119I~
        	if (numctr)                                            //~v08qI~
	        	return errinvalid(pc0);                            //~v08qI~
            numctr++;                                              //~v08qI~
//      	if ((rc=ugetnumrange(pc,&start,&end))>1)               //~v54cR~
			opt2=TAIL_OPTION|UGNR2_NOCASE;                         //~v54cI~
        	if ((rc=ugetnumrange2(opt2,pc,&start,&end))>1)         //~v54cI~
	        	return errinvalid(pc0);                            //~v08lR~
			if (!rc)	//no delm                                  //~v08lI~
            {			//asume it endline                         //~v08lI~
            	end=start;	                                       //~v08lI~
                start=0;                                           //~v08lI~
			}                                                      //~v08lI~
            else                                                   //~v08lI~
            {                                                      //~v08lI~
                if (end && start>end)                              //~v08lR~
    	        	return errinvalid(pc0);                        //~v08lI~
				if (start==1)                                      //~v08lI~
                	start=0;                                       //~v08lI~
			}                                                      //~v08lI~
        	break;                                                 //~v08lI~
//  	case 'X':		//lineno                                   //~v119R~
		case 'O':		//offset                                   //~v119I~
            if (fileparmxrange(Ppfh,pc,&xranges,&xrangee))         //~v110I~
		        return 4;                                          //~v110I~
            if (*pc)    //range specified                          //~v110R~
            	xrangesw=1;                                        //~v110I~
        	break;                                                 //~v110I~
		case 'P':		//protect                                  //~v41gI~
            if (*pc=='0')                                          //~v41hI~
    			protopt=1;                                         //~v41hI~
            else                                                   //~v41hI~
            if (*pc=='1')                                          //~v41hI~
    			protopt=2;                                         //~v41hI~
            else                                                   //~v41gI~
            if (*pc==0)                                            //~v42nR~
    			protopt=2;                                         //~v42nR~
            else                                                   //~v42nR~
	        	return errinvalid(pc0);                            //~v41gI~
        	break;                                                 //~v41gI~
//        case 'N':       //lineno type                            //~v11AR~
//            switch(toupper(*pc))                                 //~v11AR~
//            {                                                    //~v11AR~
////          case 'N':       //binary read,write by text mode     //~v11AR~
//            case 'L':       //lineno                             //~v11AR~
//                UCBITON(Ppfh->UFHflag4,UFHF4NLINENO);            //~v11AR~
//                UCBITOFF(Ppfh->UFHflag4,UFHF4XLINENO);           //~v11AR~
//                break;                                           //~v11AR~
////          case 'X':       //binary read,write by text mode     //~v11AR~
//            case 'O':       //offset                             //~v11AR~
//                UCBITOFF(Ppfh->UFHflag4,UFHF4NLINENO);           //~v11AR~
//                UCBITON(Ppfh->UFHflag4,UFHF4XLINENO);            //~v11AR~
////                pc++;                                          //~v11AR~
////                if (fileparmxrange(Ppfh,pc,&xranges,&xrangee)) //~v11AR~
////                    return 4;                                  //~v11AR~
////                if (*pc)    //range specified                  //~v11AR~
////                    xrangesw=1;                                //~v11AR~
//                break;                                           //~v11AR~
//            default:                                             //~v11AR~
//                return errinvalid(pc);                           //~v11AR~
//            }                                                    //~v11AR~
//            break;                                               //~v11AR~
		case 'M':		//Read mode                                //~v09YR~
            wmode=0;    //read mode at first                       //~v09YI~
            for (;;)                                               //~v09YI~
            {                                                      //~v09YI~
            	switch(toupper(*pc))                               //~v09YI~
                {                                                  //~v09YI~
        		case 'T':		//binary read,write by text mode   //~v0aaR~
//  				UCBITOFF(Ppfh->UFHflag4,UFHF4BIN);             //~v10eI~//~va6JR~
					ERRFORBINFILE(Ppfh,"/Mt");                     //~va6JI~
//                  if (wmode)                                     //~v0acI~//~va6DR~
                    if (wmode||swrecordmode)                       //~va6DI~
                    {                                              //~v47xI~
//  					UCBITOFF(Ppfh->UFHflag3,                   //~v0acI~//~va6NR~
//  	                            UFHF3WBIN | UFHF3WTEXTPC | UFHF3WTEXTUNIX );//~v0acI~//~va6NR~
    					UCBITOFF(Ppfh->UFHflag3,UFHF3WBIN);        //~va6NI~
    					UCBITON(Ppfh->UFHflag3,UFHF3WTEXTPC | UFHF3WTEXTUNIX );//~va6NI~
						UCBITON(Ppfh->UFHflag11,UFHF11WTEXT);      //~va6NM~
    					UCBITOFF(Ppfh->UFHflag6,                   //~v47xI~
		                            UFHF6WTEXTMAC);                //~v47xI~
						UCBITOFF(Ppfh->UFHflag11,UFHF11WTEXTEBC);  //~va6DI~
                        swwritemode=1;                             //~va6DI~
                    }                                              //~v47xI~
                    else                                           //~v0acI~
                    {                                              //~v0acI~
                        wmode=1;                                   //~v0acI~
					UCBITON(Ppfh->UFHflag3,                        //~v0aaR~
                            UFHF3RBIN | UFHF3RTEXTPC | UFHF3RTEXTUNIX );//~v0aaI~
					UCBITOFF(Ppfh->UFHflag3,                       //~v0aaI~
                            UFHF3WBIN | UFHF3WTEXTPC | UFHF3WTEXTUNIX );//~v0aaI~
    					UCBITOFF(Ppfh->UFHflag6,                   //~v47xI~
		                            UFHF6RTEXTMAC|                 //~v47xI~
		                            UFHF6WTEXTMAC);                //~v47xI~
                        swrecordmode=-1;                           //~va6NI~
                    }                                              //~v0acI~
					UCBITON(Ppfh->UFHflag4,UFHF4TEXT);//explicit text mode//~v10cI~
                    break;                                         //~v09YI~
        		case 'P':		//PC text file                     //~v09YI~
//  				UCBITOFF(Ppfh->UFHflag4,UFHF4BIN);             //~v10eI~//~va6JR~
					ERRFORBINFILE(Ppfh,"/Mp");                     //~va6JI~
                                                                   //~va50I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
                    if (wmode||swrecordmode)                       //~va50I~
#else                                                              //~va50I~
                    if (wmode)                                     //~v09YI~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
                    {                                              //~v0aaI~
						UCBITON(Ppfh->UFHflag3,                    //~v0aaR~
                                UFHF3WBIN | UFHF3WTEXTPC);         //~v0aaI~
						UCBITOFF(Ppfh->UFHflag3,UFHF3WTEXTUNIX);   //~v0aaI~
						UCBITOFF(Ppfh->UFHflag6,UFHF6WTEXTMAC);    //~v47xI~
						UCBITOFF(Ppfh->UFHflag11,UFHF11WTEXTEBC);  //~va6DR~
                        swwritemode=1;                             //~va6DI~
                    }                                              //~v0aaI~
                    else                                           //~v09YI~
                    {                                              //~v09YI~
                        wmode=1;                                   //~v0acI~
						UCBITON(Ppfh->UFHflag3,                    //~v0aaR~
                                UFHF3RTEXTPC | UFHF3RBIN |         //~v0aaI~
                                UFHF3WTEXTPC | UFHF3WBIN );        //~v0aaI~
						UCBITOFF(Ppfh->UFHflag3,                   //~v0aaR~
                                UFHF3RTEXTUNIX | UFHF3WTEXTUNIX);  //~v0aaI~
						UCBITOFF(Ppfh->UFHflag6,                   //~v47xI~
								 UFHF6RTEXTMAC | UFHF6WTEXTMAC);   //~v47xI~
                        swrecordmode=-1;	                       //~va51I~
                    }                                              //~v09YI~
					UCBITON(Ppfh->UFHflag4,UFHF4TEXT);//explicit text mode//~v10cI~
                    break;                                         //~v09YI~
        		case 'U':		//UNIX text file                   //~v09YR~
//  				UCBITOFF(Ppfh->UFHflag4,UFHF4BIN);             //~v10eI~//~va6JR~
					ERRFORBINFILE(Ppfh,"/Mu");                     //~va6JI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
                    if (wmode||swrecordmode)                       //~va50I~
#else                                                              //~va50I~
                    if (wmode)                                     //~v09YI~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
                    {                                              //~v0aaI~
						UCBITON(Ppfh->UFHflag3,                    //~v0aaR~
                                UFHF3WBIN | UFHF3WTEXTUNIX);       //~v0aaR~
						UCBITOFF(Ppfh->UFHflag3,UFHF3WTEXTPC);     //~v0aaI~
						UCBITOFF(Ppfh->UFHflag6,UFHF6WTEXTMAC);    //~v47xI~
						UCBITOFF(Ppfh->UFHflag11,UFHF11WTEXTEBC);  //~va6DR~
                        swwritemode=1;                             //~va6DI~
					}                                              //~v0aaI~
                    else                                           //~v09YI~
                    {                                              //~v09YI~
                        wmode=1;                                   //~v0acI~
						UCBITON(Ppfh->UFHflag3,                    //~v0aaR~
                                UFHF3RTEXTUNIX | UFHF3RBIN |       //~v0aaI~
                                UFHF3WTEXTUNIX | UFHF3WBIN );      //~v0aaI~
						UCBITOFF(Ppfh->UFHflag3,                   //~v0aaR~
								 UFHF3RTEXTPC  | UFHF3WTEXTPC );   //~v0aaI~
						UCBITOFF(Ppfh->UFHflag6,                   //~v47xI~
								 UFHF6RTEXTMAC | UFHF6WTEXTMAC);   //~v47xI~
                        swrecordmode=-1;                           //~va51I~
					}                                              //~v09YI~
					UCBITON(Ppfh->UFHflag4,UFHF4TEXT);//explicit text mode//~v10cI~
                    break;                                         //~v09YI~
                case  'M':      //mixed(default)                   //~v47xI~
//  				UCBITOFF(Ppfh->UFHflag4,UFHF4BIN);//text file  //~v47xI~//~va6JR~
					ERRFORBINFILE(Ppfh,"/Mm");                     //~va6JI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
                    if (wmode||swrecordmode)                       //~va50I~
#else                                                              //~va50I~
                    if (wmode)                                     //~v47xI~
#endif                                                             //~va50I~
                    {                                              //~v47xI~
						UCBITON(Ppfh->UFHflag3,                    //~v47xI~
                                UFHF3WBIN                 ); //fwrite//~v47xI~
						UCBITON(Ppfh->UFHflag6,                    //~v47xI~
                                            UFHF6WTEXTMAC ); //write eol=0d//~v47xI~
						UCBITOFF(Ppfh->UFHflag3,UFHF3WTEXTPC       //~v47xI~
						                       |UFHF3WTEXTUNIX); //reset pc/unix write//~v47xI~
						UCBITOFF(Ppfh->UFHflag11,UFHF11WTEXTEBC);  //~va6DR~
                        swwritemode=1;                             //~va6DI~
					}                                              //~v47xI~
                    else                                           //~v47xI~
                    {                                              //~v47xI~
                        wmode=1;                                   //~v47xI~
						UCBITON(Ppfh->UFHflag3,                    //~v47xI~
                                                 UFHF3RBIN | //use fread//~v47xI~
                                                 UFHF3WBIN );//use fwrite//~v47xI~
						UCBITON(Ppfh->UFHflag6,                    //~v47xI~
                                UFHF6RTEXTMAC              |       //~v47xI~
                                UFHF6WTEXTMAC              );      //~v47xI~
						UCBITOFF(Ppfh->UFHflag3,                   //~v47xI~
								 UFHF3RTEXTUNIX| UFHF3WTEXTUNIX |  //~v47xI~
								 UFHF3RTEXTPC  | UFHF3WTEXTPC );   //~v47xI~
                        swrecordmode=-1;                           //~va51I~
					}                                              //~v47xI~
					UCBITON(Ppfh->UFHflag4,UFHF4TEXT);//explicit text mode//~v47xI~
                    break;                                         //~v47xI~
                case  EOLOPT_EBC:      //EBC EOL(0x15)             //~va6DI~
                    if (wmode||swrecordmode)                       //~va6DI~
                    {                                              //~va6DI~
						UCBITON(Ppfh->UFHflag3,UFHF3WBIN); //for eol change warning//~va6DI~
						UCBITON(Ppfh->UFHflag11,UFHF11WTEXTEBC);   //~va6DI~
						UCBITOFF(Ppfh->UFHflag3,UFHF3WTEXTPC|UFHF3WTEXTUNIX); //reset pc/unix write//~va6DI~
						UCBITOFF(Ppfh->UFHflag6,UFHF6WTEXTMAC);    //~va6DI~
                        swwritemode=2;                             //~va6DI~
					}                                              //~va6DI~
                    else                                           //~va6DI~
                    {                                              //~va6DI~
                        wmode=1;                                   //~va6DI~
						UCBITOFF(Ppfh->UFHflag3,UFHF3RTEXTPC|UFHF3RTEXTUNIX); //reset pc/unix write//~va6DI~
						UCBITON(Ppfh->UFHflag11,UFHF11RTEXTEBC|UFHF11WTEXTEBC);//~va6DR~
                        swrecordmode=-1;                           //~va6DI~
//  					UCBITOFF(Ppfh->UFHflag4,UFHF4BIN);//text file//~va6DI~//~va6JR~
						ERRFORBINFILE(Ppfh,"/Me");                 //~va6JR~
						UCBITON(Ppfh->UFHflag4,UFHF4TEXT);//explicit text mode//~va6DI~
					}                                              //~va6DI~
                    break;                                         //~va6DI~
            	case 'R':     //Record mode                        //~va51I~
					ERRFORBINFILE(Ppfh,"/Mr");  //invalid for eb/eh cmd//~vaj0I~
                  if (wmode)                                       //~va5eI~//~va64R~
                  {                                                //~va5eI~
					UCBITON(Ppfh->UFHflag3,UFHF3WBIN); //for eol change warning//~va6DI~
					UCBITOFF(Ppfh->UFHflag6,UFHF6WTEXTMAC ); //write eol=0d//~va5eI~
					UCBITOFF(Ppfh->UFHflag3,UFHF3WTEXTPC|UFHF3WTEXTUNIX); //reset pc/unix write//~va5eI~
        			UCBITOFF(Ppfh->UFHflag11,UFHF11WTEXTEBC); //reset pc/unix write//~vaj0R~
					UCBITON(Ppfh->UFHflag11,UFHF11WRECORD); //drop eol at wrire//~va5eR~
                    swwritemode=1;                                 //~va6DI~
                  }                                                //~va5eI~
                  else                                             //~va5eI~
                  {                                                //~va5eI~
					UCBITOFF(Ppfh->UFHflag6,UFHF6WTEXTMAC ); //write eol=0d//~va51I~
					UCBITOFF(Ppfh->UFHflag3,UFHF3WTEXTPC|UFHF3WTEXTUNIX); //reset pc/unix write//~va51I~
                    swrecordmode=1;                                //~va51I~
                    wmode=1;    //required for /Mr_                //~vaj0I~
                  }                                                //~va5eI~
                    break;                                         //~va64I~
//      		case 'X':		//UNIX text file                   //~v10mR~
        		case 'X':		//virtical hex display option      //~v60vI~
					UCBITON(Ppfh->UFHflag6,UFHF6VHEXPARM);  //virtical hex display//~v60vI~
                    break;                                         //~v60vI~
        		case 'H':		//HEX display                      //~v44eR~
					UCBITON(Ppfh->UFHflag5,UFHF5HEX);              //~v440R~
					UCBITON(Ppfh->UFHflag4,UFHF4BIN);              //~v440R~
                    swmh=1;                                        //~vaj6I~
                    break;                                         //~v440R~
        		case 'B':		//UNIX text file                   //~v10mI~
					if (UCBITCHK(Ppfh->UFHflag4,UFHF4TEXT))        //~va6JI~
						return errconflict("/Mb",0);               //~va6JI~
					UCBITON(Ppfh->UFHflag4,UFHF4BIN);              //~v10eI~
//                  Ppfh->UFHwidth=(USHORT)Gfhwidth;	//default display width//~v10DR~
                	break;                                         //~v10eI~
                case 'K':       //cobol with col1-6=space          //~v42xI~
    				cobopt|=2;                                     //~v42xI~
                    nocobnumsw=1;                                  //~v42xI~
                    break;                                         //~v42xI~
                case 'L':       //lineno column is lineno          //~v11AI~
//  			  	if (!UCBITCHK(Ppfh->UFHflag4,UFHF4BIN))//not binary file//~v44hI~//~van8R~
//                	{                                              //~v44hI~//~van8R~
//  					cobopt|=2;                                 //~v44hI~//~van8R~
//                      break;                                     //~v44hI~//~van8R~
//                	}                                              //~v44hI~//~van8R~
                    UCBITON(Ppfh->UFHflag4,UFHF4NLINENO);          //~v11AI~
                    UCBITOFF(Ppfh->UFHflag4,UFHF4XLINENO);         //~v11AI~
                    break;                                         //~v11AI~
//                case  'M':      //mixed(default)                 //~v47xR~
//                    wmode=1;                                     //~v47xR~
//                    break;                                       //~v47xR~
        		case 'N':		//Numbered file(SPF)               //~v10LI~
//  				UCBITON(Ppfh->UFHflag4,UFHF4SPFCMD);    //forced SPF//~v414R~
    				cobopt|=1;                                     //~v414I~
                	break;                                         //~v10LI~
        		case 'C':		//Numbered file(SPF)               //~v414I~
    				cobopt|=2;                                     //~v414I~
                	break;                                         //~v414I~
				case 'D':		//dir list description display mode//~v690I~
        		    UCBITON(Ppfh->UFHflag7,UFHF7DESC);             //~v690I~
					break;                                         //~v690I~
                case 'O':       //offset type lineno column        //~v11AI~
                    UCBITOFF(Ppfh->UFHflag4,UFHF4NLINENO);         //~v11AI~
                    UCBITON(Ppfh->UFHflag4,UFHF4XLINENO);          //~v11AI~
                    break;                                         //~v11AI~
            	case 'V':     //Variable Length Record             //~vaj0I~
					ERRFORBINFILE(Ppfh,"/Mv");  //invalid for eb/eh cmd//~vaj0I~
                  if (wmode)                                       //~vaj0I~
                  {                                                //~vaj0I~
					UCBITON(Ppfh->UFHflag3,UFHF3WBIN); //for eol change warning//~vaj0I~
					UCBITOFF(Ppfh->UFHflag6,UFHF6WTEXTMAC ); //write eol=0d//~vaj0I~
					UCBITOFF(Ppfh->UFHflag3,UFHF3WTEXTPC|UFHF3WTEXTUNIX); //reset pc/unix write//~vaj0I~
					UCBITOFF(Ppfh->UFHflag11,UFHF11WTEXTEBC); //reset pc/unix write//~vaj0R~
					UCBITON(Ppfh->UFHflag13,UFHF13WV); //write recfm=V//~vaj0I~
                    swwritemode=1;                                 //~vaj0I~
                  }                                                //~vaj0I~
                  else                                             //~vaj0I~
                  {                                                //~vaj0I~
					UCBITOFF(Ppfh->UFHflag6,UFHF6WTEXTMAC ); //write eol=0d//~vaj0I~
					UCBITOFF(Ppfh->UFHflag3,UFHF3WTEXTPC|UFHF3WTEXTUNIX); //reset pc/unix write//~vaj0I~
                    swrecordmode=SWRECORDMODE_VPARM; //parm recfm=V//~vaj0R~
                    wmode=1;    //required for /Mv_                //~vaj0I~
                  }                                                //~vaj0I~
                    break;                                         //~vaj0I~
        		case  0:		//string end                       //~v09YR~
                	break;                                         //~v09YI~
				default:                                           //~v09YI~
                	wlen=(int)strlen(pc);                          //~v10eR~
                  	wlen=unumlen(pc,0,wlen);                       //~v459I~
                    if (!wlen)                                     //~v459I~
			        	return errinvalid(pc0);                    //~v459I~
//                  if (toupper(*(pc+wlen-1))=='S')                //~v63eR~
                    if (toupper(*(pc+wlen))=='S')                  //~v63eI~
                    {                                              //~v459R~
//                      wlen--;                                    //~v63eR~
    	                widthsw=2;		//parm specified keep option//~v10xI~
                    }                                              //~v459R~
                    else                                           //~v10xI~
#ifdef UTF8SUPP   //no Width by Column option                      //~va00I~
                    if (toupper(*(pc+wlen))=='C')                  //~v91QI~//~va00I~
                    {                                              //~v91QI~//~va00I~
    	                widthcolsw=1;		//parm specified keep option//~v91QI~//~va00I~
        	            if (toupper(*(pc+wlen+1))=='S')            //~v91QI~//~va00I~
                        {                                          //~v91QI~//~va00I~
	    	                widthsw=2;		//parm specified keep option//~v91QI~//~va00I~
                            wlen++;                                //~v91QI~//~va00I~
                        }                                          //~v91QI~//~va00I~
                    }                                              //~v91QI~//~va00I~
                    else                                           //~v91QI~//~va00I~
#endif                                                             //~v91QI~//~va00I~
                    {                                              //~v459I~
    	                widthsw=1;		//parm specified           //~v10xI~
                        wlen--;         //parm skip count          //~v459I~
                    }                                              //~v459I~
//                if (unumlen(pc,0,wlen)!=wlen)                    //~v459R~
//  	        	return errinvalid(pc0);                        //~v459R~
                    width=atoi(pc);	//display width                //~v10eR~
                    if (width && width<MIN_WIDTH)                  //~v10wR~
                    {                                              //~v10eI~
						uerrmsg("Too short display width(min=%d)", //~v10eR~
//  							"表示幅が小さ過ぎます(最小=%d)",   //~v10wR~
								"\x95\\示幅が小さ過ぎます(最小=%d)",//~v10wI~
								MIN_WIDTH);                        //~v10eI~
                        return 4;                                  //~v10eI~
                    }                                              //~v10eI~
//                  Ppfh->UFHwidth=(USHORT)width;	//display width//~v10wR~
//                  Gfhwidth=(USHORT)width;	//display width        //~v10wR~
                    pc+=wlen;                                      //~v10eI~
                }                                                  //~v09YI~
                if (!*pc)                                          //~v09YI~
                    break;                                         //~v09YI~
                pc++;                                              //~v09YR~
            }                                                      //~v09YI~
        	break;                                                 //~v09YI~
        default:                                                   //~v08lI~
        	return errinvalid(pc0);                                //~v08lR~
        }                                                          //~v08lI~
    }                                                              //~v08lI~
  }//operand exist                                                 //~v41hM~
    cobopt|=cobopt0;		                                       //~v41hI~
    if (Pbinsw)                                                    //~v78rI~
		Sprechkprofileopt|=(FPURO_NUMSTD|FPURO_NUMCOB|FPURO_LRECL);	//ignore spf profile//~v78rR~
    if (cobopt)                                                    //~v71KR~
    {                                                              //~v414I~
        UCBITOFF(Ppfh->UFHflag5,UFHF5COB|UFHF5COB2|UFHF5NOAUTONUM);//~v78rI~
                    //reset once profile setting                   //~v78rI~
		UCBITON(Ppfh->UFHflag4,UFHF4SPFCMD);                       //~v414I~
		Sprechkprofileopt|=(FPURO_NUMSTD|FPURO_NUMCOB|FPURO_LRECL);	//ignore spf profile//~v78rR~
    	switch(cobopt)                                             //~v414R~
    	{                                                          //~v414R~
	    case 2:         // /Mc                                     //~v414R~
			UCBITON(Ppfh->UFHflag5,UFHF5COB|UFHF5NOAUTONUM);       //~v414R~
            if (nocobnumsw)                                        //~v42xI~
            {                                                      //~v47vI~
				UCBITOFF(Ppfh->UFHflag4,UFHF4SPFCMD);//no more spf file//~v47vI~
				UCBITON(Ppfh->UFHflag5,UFHF5COB2);                 //~v42xI~
                Ppfh->UFHlrecl=fhsv.UFHlrecl;   //reset profile setting//~v78rI~
                Ppfh->UFHmergin=fhsv.UFHmergin;                    //~v78rI~
                Ppfh->UFHspfpos=fhsv.UFHspfpos;                    //~v78rI~
            }                                                      //~v47vI~
	        break;                                                 //~v414R~
    	case 3:         // /Mnc  ,/Mcn                             //~v414R~
			UCBITON(Ppfh->UFHflag5,UFHF5COB);                      //~v414I~
			UCBITOFF(Ppfh->UFHflag5,UFHF5NOAUTONUM);               //~v414I~
            if (nocobnumsw)                                        //~v42xI~
				UCBITON(Ppfh->UFHflag5,UFHF5COB2);                 //~v42xI~
	    }                                                          //~v414R~
        filedefaultspf(Ppfh);                                      //~v41hI~
        if (protopt==1)   		// /P0                             //~v41hI~
            UCBITON(Ppfh->UFHflag3,UFHF3OOMNOPROT);                //~v41hI~
        else                    // /P1                             //~v41hI~
        if (protopt==2)   		// /P1                             //~v41hI~
            UCBITOFF(Ppfh->UFHflag3,UFHF3OOMNOPROT);               //~v41hI~
        else                    // default                         //~v42mI~
            UCBITON(Ppfh->UFHflag3,UFHF3OOMNOPROT);                //~v42mI~
    }                                                              //~v414I~
    else                                                           //~v41hI~
    { //no cob no numbered                                         //~v616I~
        if (protopt)   		// /P option                           //~v41hI~
        {                                                          //~v41hI~
          if (UCBITCHK(Ppfh->UFHflag4,UFHF4BIN))  //open bin with width parm//~v616R~
            binmerginsw=1;                                         //~v616I~
          else  //not bin with width                               //~v616I~
          {                                                        //~v616I~
          if (!Sswprechk)		//no prechk                        //~v78rI~
          {                                                        //~v78rI~
           if (UCBITCHK(Ppfh->UFHflag2,UFHF2MERGIN))  //not set by /F parm//~v71KR~
           {                                                       //~v71KI~
        	  if (protopt==2)         // /P1                       //~v71KI~
            	UCBITOFF(Ppfh->UFHflag3,UFHF3OOMNOPROT);           //~v71KI~
        	else                    // default                     //~v71KI~
            	UCBITON(Ppfh->UFHflag3,UFHF3OOMNOPROT);            //~v71KI~
           }                                                       //~v71KI~
           else                                                    //~v71KI~
           {                                                       //~v71KI~
//          uerrmsg("protect option(%s) is valid only for margined file",0,//~v616R~
            uerrmsg("protect option(%s) is valid for margined file or binary file",0,//~v616R~
                    pc0);                                          //~v41hI~
            return 4;                                              //~v41hI~
           }                                                       //~v71KI~
          }//prechk case not yet set mergin by profile             //~v78rI~
          }                                                        //~v616I~
        }                                                          //~v41hI~
    }                                                              //~v616I~
#ifdef UTF8SUPPH                                                    //~v90nM~//~va00R~
	if (UCBITCHK(Ppfh->UFHflag4,UFHF4BIN))                         //~va0mR~
    {                                                              //~va0mI~
        if  (utf8opt)                                              //~va0mI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
          if (utf8opt!=CPOPT_EBC && utf8opt!='A')                  //~va50R~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//  		return erroptionforbinfile(LANGOPT_UTF8 "|" LANGOPT_LOCALE,4);//~va0mR~//~va6BR~
          if (utf8opt!='L')     //cplc                             //~va6BI~
    		return erroptionforbinfile(LANGOPT_UTF8,4);            //~va6BI~
    }                                                              //~va0mI~
	if (localeutf8mode)                                            //~v90uI~//~va00I~
    {                                                              //~v90uI~//~va00I~
        UCBITOFF(Ppfh->UFHflag8,UFHF8UTF8|UFHF8UTF8P);	//may set by profile//~v78wI~//~va00I~
        UCBITOFF(Ppfh->UFHflag10,UFHF10EBC|UFHF10EBCP);	//may set by profile//~va83I~
	  if (localeutf8mode==1)	//CPAS option                      //~va00I~
      {                                                            //~va00I~//~va0CR~
        if (Gulibutfmode & GULIBUTFENV) //env=utf8 required for =6 file//~v90uI~//~va00I~
//          UCBITON(Ppfh->UFHflag8,UFHF8UTF8|UFHF8UTF8P);                     //~v90uI~//~va00I~//~va0CR~//~va1aR~
            UCBITON(Ppfh->UFHflag8,UFHF8UTF8);                     //~va1aI~
      }                                                            //~va00I~//~va0CR~
      else                                                         //~va00I~//~va0CR~
	  if (localeutf8mode==2)	//CPU8 option                      //~va00I~//~va0CR~
        UCBITON(Ppfh->UFHflag8,UFHF8UTF8P);	//parm                 //~va0CR~
      else                                                         //~va0CI~
	  if (localeutf8mode==3)	//CPU8 option                      //~va0CI~
        UCBITON(Ppfh->UFHflag8,UFHF8UTF8|UFHF8UTF8P);	//utf8 by parm//~va0CI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
      else                                                         //~va50I~
	  if (localeutf8mode==4)	//CPEB option                      //~va50I~
        UCBITON(Ppfh->UFHflag10,UFHF10EBC|UFHF10EBCP);	//ebcdic by parm//~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    }                                                              //~v90uI~//~va00I~
    else                                                           //~v90uI~//~va00I~
    if (utf8opt=='U')                                              //~v90uI~//~va00I~
    {                                                              //~va00I~
//      UCBITON(Ppfh->UFHflag8,UFHF8UTF8);                         //~v922R~//~va00I~
        UCBITON(Ppfh->UFHflag8,UFHF8UTF8|UFHF8UTF8P);              //~v922I~//~va00I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
        UCBITOFF(Ppfh->UFHflag10,UFHF10EBC|UFHF10EBCP);            //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
        UCBITON(Ppfh->UFHflag10,UFHF10CPPROF);  //record to profile//~va00I~
    }                                                              //~va00I~
    else                                                           //~v90uI~//~va00I~
    if (utf8opt=='L')                                              //~v90uR~//~va00I~
    {                                                              //~v922I~//~va00I~
        UCBITOFF(Ppfh->UFHflag8,UFHF8UTF8);                        //~v90uI~//~va00I~
        UCBITON(Ppfh->UFHflag8,UFHF8UTF8P);                        //~v922I~//~va00I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
        UCBITOFF(Ppfh->UFHflag10,UFHF10EBC|UFHF10EBCP);            //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
        UCBITON(Ppfh->UFHflag10,UFHF10CPPROF);  //record to profile//~va00I~
    }                                                              //~v922I~//~va00I~
    else   //no parameter                                          //~v90uI~//~va00I~
    if (utf8opt=='A')                                              //~v78wI~//~va00I~
    {                                                              //~v78wI~//~va00I~
        UCBITOFF(Ppfh->UFHflag8,UFHF8UTF8|UFHF8UTF8P);             //~v78wI~//~va00I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
        UCBITOFF(Ppfh->UFHflag10,UFHF10EBC|UFHF10EBCP);            //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
        UCBITON(Ppfh->UFHflag10,UFHF10CPPROF);  //record to profile//~va00I~
    }                                                              //~v78wI~//~va00I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	else                                                           //~va50I~
    if (utf8opt==CPOPT_EBC)                                        //~va50I~
    {                                                              //~va50I~
        UCBITOFF(Ppfh->UFHflag8,UFHF8UTF8|UFHF8UTF8P);             //~va50I~
        UCBITON(Ppfh->UFHflag10,UFHF10EBC|UFHF10EBCP);             //~va50R~
        UCBITON(Ppfh->UFHflag10,UFHF10CPPROF);  //record to profile//~va50I~
    }                                                              //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    if (fnutf8opt=='U')                                            //~vagEI~
    {                                                              //~vagEI~
        UCBITON(Ppfh->UFHflag12,UFHF12FNU8|UFHF12FNCMD);           //~vagER~
        UCBITOFF(Ppfh->UFHflag12,UFHF12FNLC);  //record to profile //~vagEI~
    }                                                              //~vagEI~
    else                                                           //~vagEI~
    if (fnutf8opt=='L')                                            //~vagEI~
    {                                                              //~vagEI~
        UCBITOFF(Ppfh->UFHflag12,UFHF12FNU8);                      //~vagEI~
        UCBITON(Ppfh->UFHflag12,UFHF12FNLC|UFHF12FNCMD);  //record to profile//~vagER~
    }                                                              //~vagEI~
    else                                                           //~vagEI~
    if (fnutf8opt=='A')                                            //~vagEI~
    {                                                              //~vagEI~
        UCBITOFF(Ppfh->UFHflag12,UFHF12FNU8|UFHF12FNLC);           //~vagEI~
        UCBITON(Ppfh->UFHflag12,UFHF12FNCMD);  //record to profile //~vagEI~
    }                                                              //~vagEI~
	fileselectutf8optionchk(FSU8OCO_SELECTONLY,Ppcw,Ppfh);  //nor dirlist option for select cmd//~vb2gI~
  if (!localeutf8mode)                                             //~va00I~
//***not by BSEOPT_xx                                              //~va50I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
  if (!UCBITCHK(Ppfh->UFHflag10,UFHF10EBCP))	//no expricit CPEB //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
   if (!UCBITCHK(Ppfh->UFHflag8,UFHF8UTF8P))	//no expricit utf/locale(asis)//~v78wI~//~va00I~//~vb2fR~//~vb2gR~
   {                                                               //~v78wI~//~va00I~//~vb2fR~//~vb2gR~
	if (!fileselectutf8optionchk(0,Ppcw,Ppfh))  //nor dirlist option for select cmd//~va00I~
    {                                                              //~va00I~
    if (!(Ppfh->UFHprofile & FPURO_CP))	//no profile data          //~va00I~
//  if ((Gulibutfmode & GULIBUTFFILE)    //file is utf8 as default //~v90zR~//~va00I~
    if (!FILEISTSO(Ppfh))                //tso default is Not UTF8 //~v92nI~//~va00I~
    if (UCBITCHK(Goptopt2,GOPT2_ALLFILEUTF8)                       //~v917R~//~va00I~
    ||  (Gutfmode2 & GUM2_ALLFILEUTF8CLP)                          //~v917I~//~va00I~
//  ||  (Gulibutfmode & GULIBUTFENV)) //env=utf8 required for =6 file//~v90uI~//~va00I~//~va0mR~
    ||   XEUTF8MODE_ENV_FORCE()) //env=utf8 required for =6 file   //~va0mR~
    if (!(Gutfmode2 & GUM2_ALLFILELCCLP))                          //~va1aI~
    if (!UCBITCHK(Goptopt2,GOPT2_ALLFILELOCALE))                   //~va1pI~
        UCBITON(Ppfh->UFHflag8,UFHF8UTF8);                         //~v90uI~//~va00I~
    }                                                              //~va00I~
   }                                                               //~v78wI~//~va00I~//~vb2fR~//~vb2gR~
#endif                                                             //~v90nM~//~va00I~
//	if (Ppcw->UCWopdno<=1)                                         //~v41hI~//~va51R~
//  	return 0;                                                  //~v41hI~//~va51R~
  if (Ppcw->UCWopdno>1)                                            //~va51I~
  {                                                                //~va51I~
    if (widthsw)                                                   //~v10wR~
    {                                                              //~v10wI~
		if (UCBITCHK(Ppfh->UFHflag5,UFHF5HEX))                     //~v440I~
        {                                                          //~v60sI~
            if (width>MAX_HEXBIN_WIDTH)                            //~v440M~
            {                                                      //~v440M~
    			uerrmsg("Max width is %d for HEX display mode",    //~v440M~
        			    "HEXモードの最大幅は %d です。",           //~v440M~
						MAX_HEXBIN_WIDTH);                         //~v440M~
				return 4;                                          //~v440M~
            }                                                      //~v440M~
        }                                                          //~v60sI~
        else                                                       //~v60sI~
        {                                                          //~v60sI~
            if (width>MAXLINEDATA)                                 //~v60sI~
            {                                                      //~v60sI~
    			uerrmsg("Max width is %d",                         //~v60sI~
        			    "最大幅は %d です。",                      //~v60sI~
						MAXLINEDATA);                              //~v60sI~
				return 4;                                          //~v60sI~
            }                                                      //~v60sI~
        }                                                          //~v60sI~
      if (widthsw==2)                                              //~v10xI~
      {                                                            //~v546I~
       if (!Sswprechk)                                             //~v60sR~
       {                                                           //~v60sI~
		if (UCBITCHK(Ppfh->UFHflag4,UFHF4BIN))                     //~v10wI~
		  if (UCBITCHK(Ppfh->UFHflag5,UFHF5HEX))                   //~v440I~
        	Gfhxwidth=(USHORT)width;	//display width of hex mode//~v440I~
          else                                                     //~v440I~
        	Gfhwidth=(USHORT)width;	//display width                //~v10wI~
        else                                                       //~v10wI~
		  if (UCBITCHK(Popt,UFCFBROWSE))                           //~v10EI~
        	Gfhwidthtxt=(USHORT)width;	//display width text mode  //~v10wI~
		  else	                                                   //~v10EI~
        	Gfhwidthtxtedit=(USHORT)width;	//display width text mode//~v10EI~
       }//not prechk                                               //~v60sI~
      }//width==2                                                  //~v546I~
	    UCBITON(Ppfh->UFHflag4,UFHF4WIDTH); //explicit width       //~v11zI~
	}                                                              //~v10DI~
    else                                                           //~v10DI~
		if (UCBITCHK(Ppfh->UFHflag4,UFHF4BIN))                     //~v10DR~
        {                                                          //~v546I~
		  if (UCBITCHK(Ppfh->UFHflag5,UFHF5HEX))                   //~v440R~
        	width=(int)Gfhxwidth;	//default display width        //~v440R~
          else                                                     //~v440R~
        	width=(int)Gfhwidth;	//default display width        //~v10DR~
        }                                                          //~v546I~
    Ppfh->UFHwidth=(USHORT)width;	//display width                //~v10DR~
    if (binmerginsw)    //binfile with /p parm                     //~v616R~
    {                                                              //~v616I~
    	Ppfh->UFHmergin=(USHORT)width;			//width=margin;display boundary//~v616R~
        UCBITON(Ppfh->UFHflag2,UFHF2MERGIN);  //no drop last space //~v616I~
        if (protopt==2)         // /P1                             //~v616I~
            UCBITOFF(Ppfh->UFHflag3,UFHF3OOMNOPROT);               //~v616I~
        else                    // default                         //~v616I~
            UCBITON(Ppfh->UFHflag3,UFHF3OOMNOPROT);                //~v616I~
    }                                                              //~v616I~
    if (xrangesw)                                                  //~v10YI~
    {	                                                           //~v10YI~
		if (start||end)                                            //~v10YI~
        {                                                          //~v10YI~
    		uerrmsg("line range and offset range is exclusive",    //~v10YI~
        			"行範囲とヘキサ位置範囲は両方指定できません"); //~v10YR~
			return 4;                                              //~v10YI~
        }                                                          //~v10YI~
//      Ppfh->UFHslinepos=(long)xranges;                           //~vaz0R~
        Ppfh->UFHslinepos=xranges;                                 //~vaz0I~
//      Ppfh->UFHelinepos=(long)xrangee;                           //~vaz0R~
        Ppfh->UFHelinepos=xrangee;                                 //~vaz0I~
		UCBITON(Ppfh->UFHflag4,UFHF4XRANGE);    //notify to fileload//~v10YI~
    }                                                              //~v10YI~
//  if (!UCBITCHK(Ppfh->UFHflag,UFHFNEW))                          //~v09YR~
//  {                                                              //~v09YR~
    	Ppfh->UFHsline=start;                                      //~v08lI~
    	Ppfh->UFHeline=end;                                        //~v08lI~
//  }                                                              //~v09YR~
  }//opdno>1                                                       //~va51I~
  if (UCBITCHK(Ppfh->UFHflag5,UFHF5HEX)) //hhex                    //~va58I~
  {                                                                //~va58I~
	if (!UCBITCHK(Ppfh->UFHflag4,UFHF4WIDTH) //no explicit width   //~va58R~
    &&   UCBITCHK(Ppfh->UFHflag7,UFHF7FIXLRECL)                    //~va58I~
    )                                                              //~va58I~
      if (!swmh || !Ppfh->UFHwidth)	//if -Mh reset recordmode      //~vaj6I~
        Ppfh->UFHwidth=Ppfh->UFHlrecl;  //accept lrecl as width    //~va58I~
    UCBITOFF(Ppfh->UFHflag2,UFHF2MERGIN);  //no drop last space    //~va58I~
	UCBITOFF(Ppfh->UFHflag7,UFHF7FIXLRECL);                        //~va58I~
	UCBITOFF(Ppfh->UFHflag10,UFHF10RECORD);	//default for ebc file //~va58I~
	UCBITOFF(Ppfh->UFHflag13,UFHF13RV);		//read recfm=V         //~vaj0I~
	Ppfh->UFHlrecl=0;                                              //~va58I~
	Ppfh->UFHmergin=0;                                             //~va58I~
  }                                                                //~va58I~
  else                                                             //~va58I~
  {                                                                //~va58I~
	if (!swrecordmode)  //no expricitparm                          //~va51I~
    {                                                              //~va51I~
    	if (UCBITCHK(Ppfh->UFHflag10,UFHF10RECORD))	//from profile //~va51I~
        	swrecordmode=2;                                        //~va51I~
        else                                                       //~va51I~
    	if (UCBITCHK(Ppfh->UFHflag13,UFHF13RV))	//from profile     //~vaj0I~
        	swrecordmode=SWRECORDMODE_VPROF;    	//5:read recfm=V by profile//~vaj0R~
        else                                                       //~vaj0I~
    		if (UCBITCHK(Ppfh->UFHflag10,UFHF10EBC)	//EBC file     //~va51I~
            &&  UCBITCHK(Ppfh->UFHflag7,UFHF7FIXLRECL)             //~va51R~
            &&	Ppfh->UFHlrecl	//fixlrecl, by maybe E8 cmd        //~va51I~
            )                                                      //~va51I~
            {                                                      //~va51I~
	        	swrecordmode=3;                                    //~va51I~
				UCBITON(Ppfh->UFHflag10,UFHF10RECORD);	//default for ebc file//~va51I~
				UCBITOFF(Ppfh->UFHflag13,UFHF13RV);		//reset recfm=V//~vaj0I~
				UCBITOFF(Ppfh->UFHflag6,UFHF6WTEXTMAC ); //reset default setting//~va51I~
				UCBITOFF(Ppfh->UFHflag3,UFHF3WTEXTPC|UFHF3WTEXTUNIX); //reset pc/unix write//~va51I~
            }                                                      //~va51I~
            else                                                   //~va6DI~
    		if (UCBITCHK(Ppfh->UFHflag10,UFHF10EBC))	//EBC file //~va6DR~
            {                                                      //~va6DI~
			  	if (!UCBITCHK(Ppfh->UFHflag4,UFHF4BIN))            //~va6DR~
                {                                                  //~va6DI~
					UCBITOFF(Ppfh->UFHflag3,UFHF3RTEXTPC|UFHF3RTEXTUNIX); //reset pc/unix write//~va6DI~
					UCBITON(Ppfh->UFHflag11,UFHF11RTEXTEBC); //reset pc/unix write//~va6DR~
					if (!swwritemode)                              //~va6DR~
						UCBITON(Ppfh->UFHflag11,UFHF11WTEXTEBC); //reset pc/unix write//~va6DI~
                }                                                  //~va6DI~
            }                                                      //~va6DI~
    }                                                              //~va51I~
    else                                                           //~va51I~
    {                                                              //~va51I~
        if (swrecordmode<0) //M[P|U|M]                             //~va51I~
        {                                                          //~va51I~
			UCBITOFF(Ppfh->UFHflag10,UFHF10RECORD);                //~va51I~
			UCBITOFF(Ppfh->UFHflag13,UFHF13RV);                    //~vaj0I~
            if (!swlreclparm)                                      //~va51I~
            {                                                      //~va51I~
        		UCBITOFF(Ppfh->UFHflag2,UFHF2MERGIN);  //no drop last space//~va51I~
				UCBITOFF(Ppfh->UFHflag7,UFHF7FIXLRECL);            //~va51I~
				UCBITON(Ppfh->UFHflag7,UFHF7NOFIXOPT); //reset fix //~va51I~
	        	Ppfh->UFHlrecl=0;                                  //~va51I~
			    Ppfh->UFHmergin=0;                                 //~va51I~
            }                                                      //~va6QI~
#ifdef AAA                                                         //~va6NI~
				if ( !Sswprechk                                    //~va6DR~
				&&   UCBITCHK(Ppfh->UFHflag11,UFHF11RTEXTEBC)      //~va6DR~
    			&&   ( !UCBITCHK(Ppfh->UFHflag10,UFHF10EBC)	//EBC file//~va6DR~
//*                  || UCBITCHK(Ppfh->UFHflag4,UFHF4BIN) /Me rest F4bin//~va6DR~
                     )                                             //~va6DI~
                )                                                  //~va6DI~
					return fileerrebcdicoptopn(0,EOLOPT_EBCS);     //~va6DI~
#endif                                                             //~va6NI~
//          }                                                      //~va51I~//~va6QR~
        }                                                          //~va51I~
        else                                                       //~va51I~
        if (swrecordmode==SWRECORDMODE_VPARM)//4                   //~vaj0R~
        {                                                          //~vaj0I~
			UCBITON(Ppfh->UFHflag13,UFHF13RV);                     //~vaj0I~
			UCBITOFF(Ppfh->UFHflag10,UFHF10RECORD);//reset profile //~vaj0I~
		    Sprechkprofileopt|=FPURO_LRECL;	//ignore lrecl         //~vaj0I~
        }                                                          //~vaj0I~
        else                                                       //~vaj0I~
        {                                                          //~vaj0I~
			UCBITON(Ppfh->UFHflag10,UFHF10RECORD);                 //~va51I~
			UCBITOFF(Ppfh->UFHflag13,UFHF13RV);   //reset profile  //~vaj0I~
        }                                                          //~vaj0I~
		Sprechkprofileopt|=FPURO_RECORD;	//ignore recordmode saved in profile//~va51I~
    }                                                              //~va51I~
	if (swrecordmode==SWRECORDMODE_VPARM||swrecordmode==SWRECORDMODE_VPROF)//~vaj0I~
    {                                                              //~vaj0I~
        if (!(  UCBITCHK(Ppfh->UFHflag6,UFHF6WTEXTMAC)             //~vaj0I~
		     || UCBITCHK(Ppfh->UFHflag3,UFHF3WTEXTPC|UFHF3WTEXTUNIX)//~vaj0I~
		     || UCBITCHK(Ppfh->UFHflag11,(UFHF11WTEXT|UFHF11WTEXTEBC))//~vaj0I~
			 || UCBITCHK(Ppfh->UFHflag11,UFHF11WRECORD) //drop eol at wrire//~vaj0I~
             )                                                     //~vaj0I~
        )                                                          //~vaj0I~
			UCBITON(Ppfh->UFHflag13,UFHF13WV);//write recfm=V      //~vaj0I~
      	if (!UCBITCHK(Ppfh->UFHflag11,UFHF11WRECORD))	//-Mvr output record mode//~vaj0R~
        	if (swlreclparm) 	//F parm is not Vfmt               //~vaj0R~
            	return fileerrlreclforV(4/*rc*/);                  //~vaj0R~
        UCBITOFF(Ppfh->UFHflag2,UFHF2MERGIN);                      //~vaj0I~
		UCBITOFF(Ppfh->UFHflag7,UFHF7FIXLRECL);                    //~vaj0I~
		UCBITOFF(Ppfh->UFHflag7,UFHF7NOFIXOPT);                    //~vaj0I~
        Ppfh->UFHlrecl=0;                                          //~vaj0R~
        Ppfh->UFHmergin=0;                                         //~vaj0I~
		if (swrecordmode==SWRECORDMODE_VPARM)                      //~vaj0I~
//      	Ppfh->UFHvfmt=lreclv;                                  //~vaz8R~
        	Ppfh->UFHvfmt=(UCHAR)lreclv;                           //~vaz8I~
    }//recfm=V                                                     //~vaj0I~
    else                                                           //~vaj0I~
	if (swrecordmode>0)  //readmode=P/U/M is not specified         //~va51R~
    {                                                              //~va51I~
        if (!(  UCBITCHK(Ppfh->UFHflag6,UFHF6WTEXTMAC)             //~va6NI~
		     || UCBITCHK(Ppfh->UFHflag3,UFHF3WTEXTPC|UFHF3WTEXTUNIX)//~va6NI~
		     || UCBITCHK(Ppfh->UFHflag11,(UFHF11WTEXT|UFHF11WTEXTEBC))//~va6NR~
			 || UCBITCHK(Ppfh->UFHflag13,UFHF13WV)//write recfm=V  //~vaj0I~
             )                                                     //~va6NI~
        )                                                          //~va6NI~
			UCBITON(Ppfh->UFHflag11,UFHF11WRECORD); //drop eol at wrire//~va6NI~
#ifdef AAA  //NO TAB included in line                              //~va51I~
  		if (swnotc)                                                //~va51R~
        {                                                          //~va51I~
    		uerrmsg("Record mode and \"NOTC\" parameter is inconsistent",//~va51R~
        			"レコードモード指定と\"NOTC\"パラメータは矛盾します");//~va51I~
            return 4;                                              //~va51I~
        }                                                          //~va51I~
#endif                                                             //~va51I~
      	if (!UCBITCHK(Ppfh->UFHflag13,UFHF13WV))	//-Mvr output record mode//~vaj0I~
        	if (swvfmtparm) 	//F parm is Vfmt                   //~vaj0I~
            	return fileerrvfmtforR(4/*rc*/);                   //~vaj0I~
        if (UCBITCHK(Ppfh->UFHflag7,UFHF7NOFIXOPT))                //~va51I~
        {                                                          //~va51I~
    		uerrmsg("Record mode and \"F\" parameter(LRECL=0) is inconsistent",//~va51R~
        			"レコードモード指定と\"F\"パラメータ(LRECL=0)が矛盾します");//~va51R~
            return 4;                                              //~va51I~
        }                                                          //~va51I~
	    if (Ppfh->UFHwidth && Ppfh->UFHwidth!=Ppfh->UFHlrecl)      //~va51R~
        {                                                          //~va51I~
			if (UCBITCHK(Ppfh->UFHflag4,UFHF4WIDTH)) //explicit width//~va51I~
            {                                                      //~va51I~
	            uerrmsg("Width(%d) parm is inconsistent with record mode",//~va51R~
                    "レコードモードで\x95\\示幅(%d)は指定不可",    //~va51R~
                        Ppfh->UFHwidth);                           //~va51R~
	            return 4;                                          //~va51I~
            }                                                      //~va51I~
        }	                                                       //~va51R~
        if (!swlreclparm   //reset BIN/HHEX mode value             //~va51R~
		&&  !UCBITCHK(Ppfh->UFHflag7,UFHF7FIXLRECL))               //~va51R~
        {                                                          //~va51I~
        	Ppfh->UFHlrecl=STDSPFLRECL;	//default 80               //~va51I~
		    Ppfh->UFHmergin=STDSPFLRECL;                           //~va51I~
        	UCBITON(Ppfh->UFHflag2,UFHF2MERGIN);  //no drop last space//~va51I~
			UCBITON(Ppfh->UFHflag7,UFHF7FIXLRECL);                 //~va51I~
			UCBITOFF(Ppfh->UFHflag7,UFHF7NOFIXOPT); //reset fix    //~va51I~
        }                                                          //~va51I~
        Ppfh->UFHwidth=Ppfh->UFHlrecl;  //reset BIN/HHEX mode value//~va51I~
//        if (UCBITCHK(Ppfh->UFHflag5,UFHF5HEX)) //hhex              //~va51I~//~va58R~
//            Ppfh->UFHmergin=0;  //avoid HEX part is protected      //~va51R~//~va58R~
    }                                                              //~va51I~
    if (UCBITCHK(Ppfh->UFHflag11,UFHF11WRECORD))	//output record mode//~va6QR~
    	if (!UCBITCHK(Ppfh->UFHflag10,UFHF10RECORD))	//not record mode read//~va6QR~
        {                                                          //~va6QI~
            if (swlreclparm!=2||!fixlrecl)                         //~va6QR~
	        	Ppfh->UFHlreclout=STDSPFLRECL;	//default 80       //~va6QI~
            else                                                   //~va6QI~
//      		Ppfh->UFHlreclout=fixlrecl;                        //~vaz8R~
        		Ppfh->UFHlreclout=(USHORT)fixlrecl;                //~vaz8I~
            lrecl2profile=Ppfh->UFHlreclout;	//update profile   //~vaj0R~
        }                                                          //~va6QI~
    if (UCBITCHK(Ppfh->UFHflag13,UFHF13WV))	//output record mode   //~vaj0I~
    {                                                              //~vaj0I~
    	if (!UCBITCHK(Ppfh->UFHflag13,UFHF13RV))	//not record mode read//~vaj0I~
        {                                                          //~vaj0I~
        	if (lreclv==UFGETS_VFMT_MFH)                           //~vaj0I~
				return fileerrchange2mfh(4/*rc*/);                 //~vaj0R~
//      	Ppfh->UFHvfmt=lreclv;            // /Mxv               //~vaz8R~
        	Ppfh->UFHvfmt=(UCHAR)lreclv;            // /Mxv        //~vaz8I~
            lrecl2profile=lreclv;                                  //~vaj0I~
        }                                                          //~vaj0I~
    }                                                              //~vaj0I~
  }//!HHEX                                                         //~va58I~
#ifdef UTF8EBCD   //raw ebcdic file support                        //~va50R~//~va51I~
    if (UCBITCHK(Ppfh->UFHflag10,UFHF10EBC))//EBC file             //~va50R~
    {                                                              //~va50R~
//#ifndef AAA  //NO TAB included in line,always tarnslate 0x09(ASCII) and 0x05(EBC)                               //~va51I~//~va5YR~
//        if (swnotc)                                                //~va51R~//~va5YR~
//        {                                                          //~va50R~//~va5YR~
//            uerrmsg("\"NOTC\" parameter is inconsistent with %s,forced \"TC\"(tab clear)",//~va50R~//~va5YR~
//                    "\"NOTC\"パラメータは %sでは不可,\"TC\"(tab clear)",//~va50R~//~va5YR~
//                    MODE_EBC);                                     //~va50R~//~va5YR~
//            return 4;                                              //~va50R~//~va5YR~
//        }                                                          //~va50R~//~va5YR~
//        UCBITOFF(Ppfh->UFHflag8,UFHF8NOTABCLEAR);                  //~va51I~//~va5YR~
//        UCBITON(Ppfh->UFHflag5,UFHF5DROPTAB);   //tab clear at save//~va50R~//~va5YR~
//#else                                                              //~va51I~//~va5YR~
//        if (!swnotc)                                               //~va51I~//~va5YR~
//            UCBITON(Ppfh->UFHflag5,UFHF5DROPTAB);   //tab clear at save//~va51I~//~va5YR~
//#endif                                                             //~va51I~//~va5YR~
        if (swtc)                                                  //~va5YI~
        {                                                          //~va5YI~
            uerrmsg("\"TC\" parameter is inconsistent with %s",    //~va5YI~
                    "\"TC\"パラメータは %sでは不可",               //~va5YI~
                    MODE_EBC);                                     //~va5YI~
            return 4;                                              //~va5YI~
        }                                                          //~va5YI~
        UCBITON(Ppfh->UFHflag8,UFHF8NOTABCLEAR);                   //~va5YI~
        UCBITOFF(Ppfh->UFHflag5,UFHF5DROPTAB);   //tab clear at save//~va5YI~
    }                                                              //~va50R~
#endif //UTF8EBCD raw ebcdic file support                          //~va50R~
  if (!Sswprechk)		//not prechk(after profile chk)            //+vbg0I~
  {                                                                //+vbg0I~
    if (UCBITCHK(Ppfh->UFHflag8,UFHF8UTF8))                        //~vbc0I~
    {                                                              //~vbc0I~
    	if (UCBITCHK(Ppfh->UFHflag10,UFHF10RECORD))	//record mode read//~vbc0I~
        {                                                          //~vbc0I~
            uerrmsg("Record mode and CPU8 mode is inconsistent",   //~vbc0I~
                    "レコードモードは CPU8 モードでは使えません"); //~vbc0I~
            return 4;                                              //~vbc0I~
        }                                                          //~vbc0I~
    }                                                              //~vbc0I~
  }                                                                //+vbg0I~
	if (UCBITCHK(Ppfh->UFHflag7,UFHF7FIXLRECL))                    //~v71VI~
#ifdef UTF8EBCD   //raw ebcdic file support                        //~va5YI~
      if (!UCBITCHK(Ppfh->UFHflag10,UFHF10EBC))//not EBC file      //~va5YI~
#endif                                                             //~va5YI~
      if (!UCBITCHK(Ppfh->UFHflag10,UFHF10RECORD))//tabskip=1 for record mode(F7FIXLRECL is also on)//~vajhI~
  		if (!UCBITCHK(Ppfh->UFHflag8,UFHF8NOTABCLEAR))	//cmd parm deny to tab clear at save//~v71VR~
			UCBITON(Ppfh->UFHflag5,UFHF5DROPTAB);	//tab clear at save//~v71VI~
#ifdef UTF8SUPP   //no Width by Column option                       //~v91QI~//~va00R~
    if (widthcolsw)                                                //~v91QI~//~va00I~
    {                                                              //~v91QI~//~va00I~
		if (UCBITCHK(Ppfh->UFHflag4,UFHF4BIN)                      //~v91QI~//~va00I~
        ||  !UCBITCHK(Ppfh->UFHflag8,UFHF8UTF8))                   //~v91QI~//~va00I~
        {	                                                       //~v91QI~//~va00I~
        	uerrmsg("C option for width is for UTF8 Text file only",0);//~v91QI~//~va00I~
            return 4;                                              //~v91QI~//~va00I~
        }                                                          //~v91QI~//~va00I~
		UCBITON(Ppfh->UFHflag9,UFHF9WIDTHC);                       //~v91QI~//~va00I~
    }                                                              //~v91QI~//~va00I~
#endif                                                             //~v91QI~//~va00I~
//    if (UCBITCHK(Ppfh->UFHflag5,UFHF5HEX)) //hhex                  //~va52I~//~va58R~
//    {                                                              //~va52I~//~va58R~
//        if (Ppfh->UFHmergin)                                       //~va52I~//~va58R~
//        {                                                          //~va52I~//~va58R~
//            uerrmsg("Margined file is not displayed by Horizontal HEX mode",//~va52I~//~va58R~
//                    "マージン指定ファイルは横HEX\x95\\示できません");//~va52I~//~va58R~
//            return 4;                                              //~va52I~//~va58R~
//        }                                                          //~va52I~//~va58R~
//    }                                                              //~va52I~//~va58R~
	if (handle>=0)                                                 //~va79I~
    	Ppfh->UFHhandle=handle;	//ebc  converter parm              //~va79I~
    if (!Sswprechk)		//no prechk                                //~va51R~
    {                                                              //~va5UI~
    	if (lrecl2profile)   	// /MxR or /MxV                    //~vaj0I~
        {                                                          //~vaj0I~
		  	if (!UCBITCHK(Ppfh->UFHflag5,UFHF5HEX)) //hhex is temporary status//~vaj0I~
            {                                                      //~vaj0I~
			  	if (UCBITCHK(Ppfh->UFHflag13,UFHF13WV)) //hhex is temporary status//~vaj0I~
                	opt2=FUPO_RECORDV;                             //~vaj0I~
                else                                               //~vaj0I~
                {                                                  //~vaj0I~
                	opt2=FUPO_RECORD;                              //~vaj0I~
                    lrecl2profile<<=16;	//lrecl and margin         //~vaj0I~
                }                                                  //~vaj0I~
    			fileupdateprofilelrecl(opt2,Ppcw,Ppfh,0/*pfnm*/,lrecl2profile);//~vaj0I~
            }                                                      //~vaj0I~
        }                                                          //~vaj0I~
        else                                                       //~vaj0I~
//      if ((swrecordmode && swrecordmode!=2)||swlreclparm)   //reset record mode when /Mx parm//~vaj0R~
        if ((swrecordmode && swrecordmode!=2 && swrecordmode!=SWRECORDMODE_VPROF)||swlreclparm)   //reset record mode when /Mx parm//~vaj0I~
		  if (!UCBITCHK(Ppfh->UFHflag5,UFHF5HEX)) //hhex is temporary status//~va58I~
//  		fileupdateprofilelrecl(0,Ppcw,Ppfh);                   //~va51I~//~va64R~
//  		fileupdateprofilelrecl(0,Ppcw,Ppfh,0);                 //~va64I~//~va66R~
    		fileupdateprofilelrecl(0,Ppcw,Ppfh,0/*pfnm*/,0/*lreclparm*/);//~va66I~
        if (protopt)                                               //~va5UI~
        {                                                          //~va5UI~
    		fcmdprofupdaterecord(FPURO_OOMNOPROT,Ppfh->UFHfilename,0/*strval*/,(protopt==2),0/*int value2*/);//~va5UI~
        }                                                          //~va5UI~
                                                                   //~va5UI~
    }                                                              //~va5UI~
    return 0;                                                      //~v08lI~
}//fileoptionchk                                                   //~v08lI~
//**************************************************************** //~va51I~
// fileupdateprofilelrecl                                          //~va51I~
//	update LRECL/RECORD mode of profilerecord                      //~va51I~
//return:2:no update,0:cpas,1:cpu8,-1,cplc                         //~va51I~
//**************************************************************** //~va51I~
//int fileupdateprofilelrecl(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh)  //~va51I~//~va64R~
//int fileupdateprofilelrecl(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh,char *Pfnm)//~va64I~//~va66R~
int fileupdateprofilelrecl(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh,char *Pfnm,int Plreclparm)//~va66I~
{                                                                  //~va51I~
	int recordmode,lrecl=0,margin,rc,parmv;                        //~vaf8R~
//  int sweol;                                                     //~va64I~//~va66R~
    char *pfnm;                                                    //~va64R~
    int opt;                                                       //~vaj0I~
//*************************                                        //~va51I~
//    if (Popt & FUPO_FCMD    //called from fcmd                     //~va64R~//~va66R~
//    &&  (   UCBITCHK(Ppfh->UFHflag3,UFHF3WTEXTUNIX|UFHF3WTEXTPC)   //~va64I~//~va66R~
//           || UCBITCHK(Ppfh->UFHflag6,UFHF6WTEXTMAC)               //~va64I~//~va66R~
//        )                                                          //~va64I~//~va66R~
//    )                                                              //~va64I~//~va66R~
//        sweol=1;                                                   //~va64I~//~va66R~
//    else                                                           //~va64I~//~va66R~
//        sweol=0;                                                   //~va64I~//~va66R~
    if (Pfnm)                                                      //~va64I~
    	pfnm=Pfnm;                                                 //~va64I~
    else                                                           //~va64I~
        pfnm=Ppfh->UFHfilename;                                    //~va64I~
  if (Popt & FUPO_RECORDV)                                         //~vaj0I~
  	recordmode=2;                                                  //~vaj0I~
  else                                                             //~vaj0I~
  if (Popt & FUPO_RECORD)                                          //~va66I~
  	recordmode=1;                                                  //~vaj0M~
  else                                                             //~va66I~
  if (Popt & FUPO_EOL)                                             //~va66I~
  	recordmode=0;                                                  //~va66I~
  else                                                             //~va66I~
  {                                                                //~va66I~
    if (UCBITCHK(Ppfh->UFHflag13,UFHF13WV))                        //~vaj0R~
	  	recordmode=2;                                              //~vaj0I~
    else                                                           //~vaj0I~
//  if (UCBITCHK(Ppfh->UFHflag10,UFHF10RECORD))                    //~vaj0R~
    if (UCBITCHK(Ppfh->UFHflag11,UFHF11WRECORD))                   //~vaj0R~
    {                                                              //~va64I~
//    if (sweol)	                                               //~va64I~//~va66R~
//      recordmode=0;                                              //~va64I~//~va66R~
//    else                                                         //~va64I~//~va66R~
        recordmode=1;                                              //~va51R~
    }                                                              //~va64I~
    else                                                           //~va51R~
        recordmode=0;                                              //~va51R~
  }                                                                //~va66I~
  if (Plreclparm)                                                  //~va66I~
  	parmv=Plreclparm;                                              //~va66I~
  else                                                             //~va6NI~
  if (Popt & FUPO_FCMD)  //fcmd REP/CRE                            //~va6NI~
  	parmv=Plreclparm;                                              //~va6NI~
  else                                                             //~va66I~
  {                                                                //~va66I~
    if (recordmode==2)                                             //~vaj0I~
    	parmv=Ppfh->UFHvfmt;                                       //~vaj0I~
    else                                                           //~vaj0I~
    if (UCBITCHK(Ppfh->UFHflag7,UFHF7NOFIXOPT))                    //~va51R~
        parmv=0;                                                   //~va51R~
    else                                                           //~va51R~
	if (UCBITCHK(Ppfh->UFHflag7,UFHF7FIXLRECL))                    //~va51I~
    {                                                              //~va51I~
//    if (sweol)                                                   //~va64R~//~va66R~
  	  if (Popt & FUPO_EOL)	//record mode was reset                //~va66I~
        parmv=0;                                                   //~va64I~
      else                                                         //~va64I~
      {                                                            //~va64I~
        lrecl=Ppfh->UFHlrecl;                                      //~va51R~
        margin=Ppfh->UFHmergin;                                    //~va51I~
        parmv=(lrecl<<16)|margin;                                  //~va51R~
      }                                                            //~va64I~
    }                                                              //~va51I~
    else                                                           //~va51I~
//  	return 0;                                                  //~va51I~//~va6NR~
        parmv=0;                                                   //~va6NI~
  }                                                                //~va66I~
    rc=(recordmode<<16) | lrecl;                                   //~va51R~
    if (recordmode==2)                                             //~vaj0R~
        opt=FPURO_RECORDV;                                         //~vaj0I~
    else                                                           //~vaj0I~
        opt=FPURO_RECORD;                                          //~vaj0I~
    if (!(Popt & FUPO_CHKONLY))                                    //~va51R~
//  	fcmdprofupdaterecord(FPURO_RECORD,Ppfh->UFHfilename,0/*strval*/,recordmode,parmv);//~va51R~//~va64R~
//    	fcmdprofupdaterecord(FPURO_RECORD,pfnm,0/*strval*/,recordmode,parmv);//~va64I~//~vaj0R~
//    	fcmdprofupdaterecord(opt,pfnm,0/*strval*/,recordmode,parmv);//~vb13R~
      	fcmdprofupdaterecord((ULONG)opt,pfnm,0/*strval*/,recordmode,parmv);//~vb13I~
    return rc;                                                     //~va51I~
}//fileupdateprofilelrecl                                          //~va51I~
#ifdef UTF8SUPPH                                                   //~va00R~
//**************************************************************** //~va00I~
// fileupdateprofile                                               //~va00I~
//	update profilerecord                                           //~va00I~
//return:2:no update,0:cpas,1:cpu8,-1,cplc                         //~va00I~
//**************************************************************** //~va00I~
int fileupdateprofile(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh)       //~va00I~
{                                                                  //~va00I~
	int intval=2;                                                  //~va00I~
    int handle=0;                                                  //~va79I~
    int intval2;                                                   //~vagEI~
//*************************                                        //~va00I~
  if (Popt & FUPO_RCMD) //reset CMD or cv cmd width reset option   //~va7KI~
  {                                                                //~va7KI~
    intval=-2;  //set EBCDIC                                       //~va7KI~
    handle=Ppfh->UFHhandle;                                        //~va7KI~
  }                                                                //~va7KI~
  else                                                             //~va7KI~
  {                                                                //~va7KI~
    if (!(Popt & FUPO_CHKONLY))                                    //~vagEI~
    {                                                              //~vagEI~
		if (UCBITCHK(Ppfh->UFHflag12,UFHF12FNCMD))                 //~vagEI~
        {                                                          //~vagEI~
            if (UCBITCHK(Ppfh->UFHflag12,UFHF12FNU8))              //~vagER~
                intval2=1;  //FNU8;                                //~vagER~
            else                                                   //~vagER~
            if (UCBITCHK(Ppfh->UFHflag12,UFHF12FNLC))              //~vagER~
                intval2=-1; //FNU8;                                //~vagER~
            else                                                   //~vagEI~
            	intval2=0;       //clear(ASIS)                     //~vagEI~
            fcmdprofupdaterecord(FPURO_FNCP,Ppfh->UFHfilename,0/*strval*/,intval2,0/*intval2*/);//~vagER~
        }                                                          //~vagEI~
    }                                                              //~vagEI~
    if (!UCBITCHK(Ppfh->UFHflag10,UFHF10CPPROF))   //not propagated from DIR//~va00R~
        return intval;                                             //~va00R~
    if (UCBITCHK(Ppfh->UFHflag8,UFHF8UTF8P))                       //~va00R~
    {                                                              //~va00R~
        if (UCBITCHK(Ppfh->UFHflag8,UFHF8UTF8))                    //~va00R~
            intval=1;   //set CPU8                                 //~va00R~
        else                                                       //~va00R~
            intval=-1;  //set CPLC                                 //~va00R~
    }                                                              //~va00R~
    else                                                           //~va00I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    if (UCBITCHK(Ppfh->UFHflag10,UFHF10EBCP))                      //~va50I~
    {                                                              //~va50I~
    	intval=-2;  //set EBCDIC                                   //~va50I~
        handle=Ppfh->UFHhandle;                                    //~va79I~
    }                                                              //~va50I~
    else                                                           //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    	intval=0;  //set CPAS                                      //~va00I~
    if (intval==2)                                                 //~va00I~
        return intval;                                             //~va00R~
  }                                                                //~va7KI~
    if (!(Popt & FUPO_CHKONLY))                                    //~va00I~
//  	fcmdprofupdaterecord(FPURO_CP,Ppfh->UFHfilename,0/*strval*/,intval,0/*intval2*/);//~va00R~//~va79R~
    	fcmdprofupdaterecord(FPURO_CP,Ppfh->UFHfilename,0/*strval*/,intval,handle);//~va79I~
    return intval;                                                 //~va00R~
}//fileupdateprofile                                               //~va00I~
//**************************************************************** //~va00I~
// fileupdateprofilesave                                           //~va00I~
//	update profilerecord for save/rep/cre/app cmd                  //~va00I~
//return:2:no update,0:cpas,1:cpu8,-1,cplc                         //~va00I~
//**************************************************************** //~va00I~
//int fileupdateprofilesave(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh,int Psaveopt,char *Pfnm)//~va00I~//~va66R~
int fileupdateprofilesave(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh,int Psaveopt,char *Pfnm,int Plreclparm)//~va66I~
{                                                                  //~va00I~
	int intval=2;                                                  //~va00I~
    int opt;                                                       //~va66I~
    int handle=0;                                                  //~va79I~
//*************************                                        //~va00I~
    if (Psaveopt & FSOC_CPU8)                                      //~va00I~
    	intval=1;   //set CPU8                                     //~va00I~
    else                                                           //~va00I~
    if (Psaveopt & FSOC_CPLC)                                      //~va00I~
            intval=-1;  //set CPLC                                 //~va00I~
    else                                                           //~va00I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    if (Psaveopt & FSOC_CPEB)                                      //~va50I~
    {                                                              //~va7tI~
    	intval=-2;  //set CPEB                                     //~va50I~
        handle=0;                                                  //~va7tI~
    	if (Psaveopt & FSOC_EBCHANDLEP)                            //~va7tI~
    		handle=FSOC_GETHANDLE(Psaveopt);                       //~va7tR~
    }                                                              //~va7tI~
    else                                                           //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    {                                                              //~va00I~
    	intval=fileupdateprofile(FUPO_CHKONLY,Ppcw,Ppfh);          //~va00I~
        if (intval==2)  //not specified                            //~va00I~
        {                                                          //~va5eI~
        	if (UCBITCHK(Ppfh->UFHflag8,UFHF8UTF8))	//by env       //~va00I~
		    	intval=1;   //set CPU8                             //~va00I~
            else                                                   //~va55I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
        	if (UCBITCHK(Ppfh->UFHflag10,UFHF10EBC)) //source file is ebc//~va50I~
            {                                                      //~va79I~
		    	intval=-2;   //set EBC                             //~va50I~
        		handle=Ppfh->UFHhandle;                            //~va79I~
            }                                                      //~va79I~
            else                                                   //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
		    	intval=-1;   //set CPLC                            //~va55I~
        }                                                          //~va5eI~
        else                                                       //~va7RI~
        if (intval==-2)  //EBC                                     //~va7RI~
        	handle=Ppfh->UFHhandle;	//from current file            //~va7RI~
    }                                                              //~va00I~
//  if (intval==2)                                                 //~va00I~//~va6NR~
//      return intval;                                             //~va00R~//~va6NR~
  if (intval!=2)                                                   //~va6NI~
//  fcmdprofupdaterecord(FPURO_CP,Pfnm,0/*strval*/,intval,0/*intval2*/);//~va00R~//~va79R~
    fcmdprofupdaterecord(FPURO_CP,Pfnm,0/*strval*/,intval,handle); //~va79I~
//  if (Popt & FUPO_FCMD)  //fcmd REP/CRE                          //~va64I~//~va6NR~
    if (Popt & (FUPO_FCMD|FUPO_ECMD))  //fcmd REP/CRE              //~va6NI~
    {                                                              //~va66I~
//  	fileupdateprofilelrecl(Popt,Ppcw,Ppfh,Pfnm);               //~va64R~//~va66R~
		opt=Popt;                                                  //~va66I~
    	if (Psaveopt & FSOC_EOL_RECORDV)                           //~vaj0I~
        	opt|=FUPO_RECORDV;                                     //~vaj0I~
        else                                                       //~vaj0I~
    	if (Psaveopt & FSOC_EOL_RECORD)                            //~va66I~
        	opt|=FUPO_RECORD;                                      //~va66I~
        else                                                       //~va66I~
//  	if (Psaveopt & (FSOC_EOL_MAC|FSOC_EOL_PC|FSOC_EOL_UNIX))   //~va66R~//~va6NR~
    	if (Psaveopt & (FSOC_EOL_MAC|FSOC_EOL_PC|FSOC_EOL_UNIX|FSOC_EOL_EBC))//~va6NI~
        	opt|=FUPO_EOL;                                         //~va66I~
    	fileupdateprofilelrecl(opt,Ppcw,Ppfh,Pfnm,Plreclparm);     //~va66R~
    }                                                              //~va66I~
    return intval;                                                 //~va00R~
}//fileupdateprofilesave                                           //~va00I~
//**************************************************************** //~vaj6I~
// fileupdateprofilesave_cut                                       //~vaj6I~
//	update profilerecord of ::CB2 for cut cmd                      //~vaj6I~
//**************************************************************** //~vaj6I~
int fileupdateprofilesave_cut(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh)//~vaj6R~
{                                                                  //~vaj6I~
	int intval;                                                    //~vaj6I~
    int opt;                                                       //~vaj6I~
    int handle=0;                                                  //~vaj6I~
//*************************                                        //~vaj6I~
    if (UCBITCHK(Ppfh->UFHflag8,UFHF8UTF8))	//by env               //~vaj6I~
		intval=1;   //set CPU8                                     //~vaj6I~
    else                                                           //~vaj6I~
    if (UCBITCHK(Ppfh->UFHflag10,UFHF10EBC)) //source file is ebc  //~vaj6I~
    {                                                              //~vaj6I~
		intval=-2;   //set EBC                                     //~vaj6I~
        handle=Ppfh->UFHhandle;                                    //~vaj6I~
    }                                                              //~vaj6I~
    else                                                           //~vaj6I~
	   	intval=-1;   //set CPLC                                    //~vaj6I~
    fcmdprofupdaterecord(FPURO_CP,Ppfh->UFHfilename,0/*strval*/,intval,handle);//~vaj6R~
    opt=0;//recordmode from pfh flag                               //~vaj6R~
    fileupdateprofilelrecl(opt,Ppcw,Ppfh,NULL/*Pfnm,from pfh*/,0/*set from pfh*/);//~vaj6R~
    return 0;                                                      //~vaj6I~
}//fileupdateprofilesave                                           //~vaj6I~
#endif  //UTF8SUPPH                                                //~va00R~
//**************************************************************** //~v10YI~
// fileparmxrange                                                  //~v10YI~
//*get xrange parm                                                 //~v10YI~
//*parm1:pfh                                                       //~v110R~
//*parm2:string                                                    //~v110I~
//*parm3:from value                                                //~v110R~
//*parm4:to value                                                  //~v110R~
//*rc   :0 ok,4 err                                                //~v10YI~
//**************************************************************** //~v10YI~
//int fileparmxrange(PUFILEH Ppfh,UCHAR *Pstr,ULONG *Ppxranges,ULONG *Ppxrangee)//~vaz0R~
int fileparmxrange(PUFILEH Ppfh,UCHAR *Pstr,FILESZT *Ppxranges,FILESZT *Ppxrangee)//~vaz0I~
{                                                                  //~v10YI~
	int rc;                                                        //~v10YI~
//  long xranges,xrangee;                                          //~vaz0R~
    FILESZT xranges,xrangee;                                       //~vaz0I~
    int opt2;                                                      //~v54cI~
//******************                                               //~v10YI~
    UCBITOFF(Ppfh->UFHflag4,UFHF4NLINENO);                         //~v110I~
    UCBITON(Ppfh->UFHflag4,UFHF4XLINENO);                          //~v110I~
    if (!*Pstr)    //range specified                               //~v110I~
    	return 0;                                                  //~v110I~
	opt2=TAIL_OPTION|UGNR2_NOCASE|UGNR2_HEX;                       //~v54cI~
//  if ((rc=ugetxnumrange(Pstr,&xranges,&xrangee))<0               //~v54cR~
//  if ((rc=ugetnumrange2(opt2,Pstr,&xranges,&xrangee))<0          //~vaz0R~
    if ((rc=ugetnumrange2XFILESZ(opt2,Pstr,&xranges,&xrangee))<0   //~vaz0I~
    ||   (!xranges && !xrangee))                                   //~v10YI~
        return errinvalid(Pstr);                                   //~v10YI~
    if (!rc)    //no delm                                          //~v10YI~
    {           //asume it endline                                 //~v10YI~
        xrangee=xranges;                                           //~v10YI~
        xranges=0;                                                 //~v10YI~
    }                                                              //~v10YI~
    else                                                           //~v10YI~
        if (xrangee && xranges>xrangee)                            //~v10YI~
            return errinvalid(Pstr);                               //~v10YI~
//  *Ppxranges=(ULONG)xranges;                                     //~vaz0R~
    *Ppxranges=xranges;                                            //~vaz0I~
//  *Ppxrangee=(ULONG)xrangee;                                     //~vaz0R~
    *Ppxrangee=xrangee;                                            //~vaz0I~
	return 0;                                                      //~v10YI~
}//fileparmxrange                                                  //~v10YI~
//**************************************************************** //~v08qI~
// filepartialcopy                                                 //~v08qR~
//*file partial copy                                               //~v08qR~
//*parm1:option 0:copy up to UFHslinepos,1:copy from UFHelinepos to eof//~v08qR~
//*parm2:source pfh                                                //~v08qR~
//*parm3:target pfh                                                //~v08qR~
//*rc   :0 ok,4 err,8 openerr                                      //~vaz4R~
//**************************************************************** //~v08qI~
int filepartialcopy(int Popt,PUFILEH Ppfhsrc,PUFILEH Ppfhdest)     //~v08qR~
{                                                                  //~v08qI~
//#define IOSZ (((MAXLINEDATA*8)/512)*512)                         //~vaz4R~
#define IOSZ (((GFILEBUFFSZ)/4096)*4096)                           //~vaz4I~
//  long maxlen;                                                   //~vaz0R~
    FILESZT maxlen;                                                //~vaz0I~
    size_t reqlen,readlen;                                         //~v08qI~
    int rc;                                                        //~v08qR~
    char *mode;                                                    //~v08qI~
    int wbinsw;                                                    //~v0abI~
//  int xrangesws=0;                                               //~vaz0R~
    FILESZT xrangesws=0;                                           //~vaz0I~
//*******************                                              //~v08qI~
	if ((UCBITCHK(Ppfhsrc->UFHflag4,UFHF4XRANGE))!=0)              //~v110R~
    	xrangesws=Ppfhsrc->UFHslinepos;                            //~v10YR~
                                                                   //~v10YI~
	wbinsw=UCBITCHK(Ppfhsrc->UFHflag3,UFHF3WBIN);                  //~v0abI~
//  if (!Popt)	//first half                                       //~vazsR~
    if (!(Popt & FPCO_2ND))	//first half                           //~vazsI~
    {                                                              //~v08qI~
		if (!filereopen(Ppfhsrc,"rb"))	//seek to first line,return null fh//~v08qR~
        	return 4;                                              //~v08qR~
//  	if (Ppfhsrc->UFHsline)	//start line specified             //~v10YR~
		if (Ppfhsrc->UFHsline || xrangesws)	//start line specified //~v10YI~
            mode="wb";                                             //~v08qI~
        else                                                       //~v08qI~
		  if (wbinsw)                                              //~v0abI~
            mode="wb";			//write partial(from start) by bin mode//~v0abI~
          else                                                     //~v0abI~
            mode="w";                                              //~v08qI~
		if (!(Ppfhdest->UFHhfile=fileopen(Ppfhdest->UFHfilename,mode)))//binary open//~v08qR~
        {                                                          //~v08qR~
			if (Ppfhdest->UFHtype==UFHTTEMPWK)                     //~v08qR~
	            uerrmsg("%s(Partial edit work file) Open error(%d)",//~v08qR~
    	                "%s(部分編集ワークファイル) オープン失敗(%d)",//~v08qR~
        	            Ppfhdest->UFHfilename,errno);              //~v08qR~
//      	return 4;                                              //~vaz4R~
        	return 8; //openerr                                    //~vaz4I~
        }                                                          //~v08qR~
//  	if (Ppfhsrc->UFHsline)	//start line specified             //~v10YR~
		if (Ppfhsrc->UFHsline || xrangesws)	//start line specified //~v10YI~
        {                                                          //~v08qI~
    		maxlen=Ppfhsrc->UFHslinepos;                           //~v08qR~
    		while(maxlen)                                          //~v08qR~
            {                                                      //~v08qR~
            	if (maxlen>IOSZ)                                   //~v08qR~
                	reqlen=IOSZ;                                   //~v08qR~
    			else                                               //~v08qR~
                	reqlen=(size_t)maxlen;                         //~v08qR~
    			if(fileread(Ppfhsrc,Gfilebuff,reqlen,&readlen))//read to Gfilebuff//~v08qR~
                {                                                  //~vaz4I~
					fileclose(Ppfhdest->UFHfilename,Ppfhdest->UFHhfile);//~vaz4I~
                	return 4;                                      //~v08qR~
                }                                                  //~vaz4I~
    			maxlen=maxlen-(long)reqlen;                        //~v08qR~
    			if (filewrite(Ppfhdest,Gfilebuff,reqlen))          //~v08qR~
                {                                                  //~vaz4I~
					fileclose(Ppfhdest->UFHfilename,Ppfhdest->UFHhfile);//~vaz4I~
                	return 4;                                      //~v08qR~
                }                                                  //~vaz4I~
            }//up to before start line                             //~v08qR~
//  		if (!filereopen(Ppfhdest,"a"))	//text append mode     //~v0abR~
    		if (wbinsw)                                            //~v0abI~
                mode="ab";			//write partial(from start) by bin mode//~v0abI~
            else                                                   //~v0abI~
                mode="a";                                          //~v0abI~
    		if (!filereopen(Ppfhdest,mode))	//text append mode     //~v0abI~
            	return 4;                                          //~v08qR~
        }//start line used                                         //~v08qI~
	}                                                              //~v08qI~
    else	//copy after end line                                  //~v08qR~
    {                                                              //~v08qI~
    	Ppfhdest->UFHelinepos=ufgetpos(Ppfhdest->UFHhfile);//new copy position//~v08qI~
		if (!filereopen(Ppfhdest,"ab"))	//bynary append mode       //~v08qR~
//      	return 4;                                              //~vaz4R~
        	return 8; //openerr                                    //~vaz4I~
	    if (fileseek(Ppfhsrc,Ppfhsrc->UFHelinepos,SEEK_SET))       //~v08qR~
    		return 4;                                              //~v08qI~
		rc=0;                                                      //~v08qI~
		while(!rc)                                                 //~v08qR~
        {                                                          //~v08qI~
			if((rc=fileread(Ppfhsrc,Gfilebuff,IOSZ,&readlen))>1)//err not eof//~v08qI~
            {                                                      //~vaz4I~
				fileclose(Ppfhdest->UFHfilename,Ppfhdest->UFHhfile);//~vaz4I~
            	return 4;                                          //~v08qI~
            }                                                      //~vaz4I~
			if (rc)	//eof                                          //~v08qI~
            	if (*(Gfilebuff+readlen-1)==0x1a)                  //~v08qI~
                	readlen--; 	//once drop eof,later add by option//~v08qI~
			if (filewrite(Ppfhdest,Gfilebuff,readlen))             //~v08qR~
            {                                                      //~vaz4I~
				fileclose(Ppfhdest->UFHfilename,Ppfhdest->UFHhfile);//~vaz4I~
            	return 4;                                          //~v08qR~
            }                                                      //~vaz4I~
        }                                                          //~v08qI~
//    if (Popt & FPCO_SELF)	//save to original file                //~vazuR~
//  	Ppfhsrc->UFHelinepos=Ppfhdest->UFHelinepos;//next copy pos,set later at rename success//~vazuR~
    }                                                              //~v08qI~
    return 0;                                                      //~v08qI~
}//filepartialcopy                                                 //~v08qR~
//**************************************************************** //~v11iI~
// fileedithelp                                                    //~v11iI~
//*edit/browse/select help                                         //~v11iI~
//*parm1:'B':browse,'E':edit,'S':select                            //~v11iI~
//*rc   :0 ok,4 err                                                //~v11iI~
//**************************************************************** //~v11iI~
int fileedithelp(int Pcmdid)                                       //~v11iR~
{                                                                  //~v11iI~
	UCHAR *wopt;                                                   //~v11iR~
	UCHAR *wopt2;                                                  //~v616I~
    UCHAR opts[MAXCOLUMN];                                         //~v71KR~
//************                                                     //~v11iI~
	if (Pcmdid=='B')	//browse                                   //~v11iI~
    {                                                              //~v616I~
        wopt2="";                                                  //~v616I~
    	wopt="";                                                   //~v11iI~
    }                                                              //~v616I~
    else                                                           //~v11iI~
    {                                                              //~v616I~
//      wopt2="[p[0|1]]";                                          //~v69JR~
//      wopt2="[p[0|1]] [cap]";                                    //~v71LR~
//      wopt2="[p[0|1]] [CAP|NOCAP]";                              //~v71VR~
//      wopt2="[p[0|1]] [CAP|NOCAP] [TC|NOTC]";                    //~v76zR~
        wopt2="[p[0|1]] [CAP|NOCAP] [TC|NOTC] [NB]";               //~v76zI~
//  	wopt="[m|p|u]";                                            //~v47xR~//~va5eR~
//  	wopt="[m|p|u|r]";                                          //~vaj0R~
    	wopt="[m|p|u|t|e|r|v]";  //write opt                       //~vaj0I~
    }                                                              //~v616I~
    strcpy(opts,wopt2);                                            //~v71KI~
//  strcat(opts," [NONUM] [Fn[-m]]");                              //~v71LR~//~vajhR~
    strcat(opts," [NONUM] [F{n[-m]|vfmt}]");                       //~vajhI~
#ifdef UTF8SUPPH                                                    //~v90nI~//~va00R~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
//  strcat(opts," [" LANGOPT_UTF8 "|" LANGOPT_LOCALE "|" LANGOPT_ASIS "|" MODE_EBC "] ...Hit Esc-key\n");//~va50I~//~va79R~
//  strcat(opts," [" LANGOPT_UTF8 "|" LANGOPT_LOCALE "|" LANGOPT_ASIS "|" MODE_EBC "[:converter]] ...Hit Esc-key\n");//~va79R~//~vagER~
    strcat(opts," [" LANGOPT_UTF8 "|" LANGOPT_LOCALE "|" LANGOPT_ASIS "|" MODE_EBC "[:converter] [" MODE_IE "] [" MODE_FNU8 "|" MODE_FNLC "|" MODE_FNAS "]...Hit Esc-key\n");//~vagER~
#else                                                              //~va50I~
    strcat(opts," [" LANGOPT_UTF8 "|" LANGOPT_LOCALE "|" LANGOPT_ASIS "] ...Hit Esc-key\n");//~v78wR~//~va00I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
#endif                                                             //~v90nI~//~va00I~
    wopt2=opts;                                                    //~v71KI~
//  uerrmsg("{%c|%cB|%cN} {file|dir} [[n]-[m]]  [/M[p|u|t|b|n|c|k]%s[o|l][width[s]]]",0,//~v45aR~
//  		Pcmdid,Pcmdid,Pcmdid,wopt);                            //~v45aI~
//  uerrmsg("%c[B|C|H|I|J|K|L|N] {file|dir} [p] [[o][n]-[m]] [/M[m|p|u|t]%s[b|c|h|k][n][o|L][width[s]]]",0,//~v57wR~
//  uerrmsg("%c[B|C|H|I|J|K|L|N] {file|dir} [p] [[o][n[t]]-[m[t]]] [/M[m|p|u|t]%s[b|c|h|k][n][o|L][width[s]]]",0,//~v62xR~
//  uerrmsg("%c[B|C|H|I|J|K|L|N] {file|dir} [p] [L] [Ln] [[o][n[t]]-[m[t]]] [/M[m|p|u|t]%s[b|c|h|k][n][o|L][width[s]]]",0,//~v616R~
//  uerrmsg("%c[B|C|H|I|J|K|L|N] {file|dir} %s [L] [Ln] [[o][n[t]]-[m[t]]] [/M[m|p|u|t]%s[b|c|h|k][n][o|L][width[s]]]",0,//~v60vR~
#ifdef UTF8SUPP //no Width[C]                                       //~v91QI~//~va00R~
  if (Pcmdid=='S')	//select                                       //~vb60I~
    uerrmsg("%c[B|C|H|I|J|K|L|N] [file|dir|-lineno] %s [L] [Ln] [[o][n[t]]-[m[t]]] [/M[m|p|u|t]%s[b|c|h|k][n][o|L][x][width[c][s]]]",0,//~vb60I~
  else                                                             //~vb60I~
    uerrmsg("%c[B|C|H|I|J|K|L|N] {file|dir} %s [L] [Ln] [[o][n[t]]-[m[t]]] [/M[m|p|u|t]%s[b|c|h|k][n][o|L][x][width[c][s]]]",0,//~v91QI~//~va00I~
#else                                                              //~v91QI~//~va00I~
//  uerrmsg("%c[B|C|H|I|J|K|L|N] {file|dir} %s [L] [Ln] [[o][n[t]]-[m[t]]] [/M[m|p|u|t]%s[b|c|h|k][n][o|L][x][width[s]]]",0,//~v78rR~//~va5eR~
//  uerrmsg("%c[B|C|H|I|J|K|L|N] {file|dir} %s [L] [Ln] [[o][n[t]]-[m[t]]] [/M[m|p|u|t|r]%s[b|c|h|k][n][o|L][x][width[s]]]",0,//~vaj0R~
    uerrmsg("%c[B|C|H|I|J|K|L|N] {file|dir} %s [L] [Ln] [[o][n[t]]-[m[t]]] [/M[m|p|u|t|e|r|v]%s[b|c|h|k][n][o|L][x][width[s]]]",0,//~vaj0I~
#endif                                                             //~v91QI~//~va00I~
//  		Pcmdid,wopt);                                          //~v616R~
    		Pcmdid,wopt2,wopt);                                    //~v78rR~
    return 4;                                                      //~v11iI~
}//fileedithelp                                                    //~v11iI~
//**************************************************************** //~v47TI~
// fileerrexclusiveopt                                             //~v47TI~
//*edit/browse/select help                                         //~v47TI~
//*parm1:'B':browse,'E':edit,'S':select                            //~v47TI~
//*rc   :0 ok,4 err                                                //~v47TI~
//**************************************************************** //~v47TI~
int fileerrexclusiveopt(void)                                      //~v47TI~
{                                                                  //~v47TI~
//************                                                     //~v47TI~
    uerrmsg("multiple EOL option used.",                           //~v47TI~
			"EOL オプションが複数指定されている。");               //~v47TI~
    return 4;                                                      //~v47TI~
}//fileerrexclusiveopt                                             //~v47TI~
//**************************************************************** //~vaj0I~
int fileerrchange2mfh(int Prc)                                     //~vaj0I~
{                                                                  //~vaj0I~
//************                                                     //~vaj0I~
	uerrmsg("Couldn\'t newly change to VariableRecordFormat of %s",//~vaj0I~
    		"新たに可変長レコードタイプ: %s に設定することは出来ません",//~vaj0I~
            VFMT_MFH);                                             //~vaj0I~
	return Prc;                                                    //~vaj0I~
}//fileerrchangetomfh                                              //~vaj0I~
//**************************************************************** //~vaj0I~
int fileerrlreclforV(int Prc)                                      //~vaj0I~
{                                                                  //~vaj0I~
//************                                                     //~vaj0I~
	uerrmsg("For variable length record, specify not length but format by /F parm",//~vaj0I~
    		"可変長レコードモードでは\"F\"パラメータでレコード長でなくレコード形式を指定する");//~vaj0I~
	return Prc;                                                    //~vaj0I~
}//fileerrlreclforV                                                //~vaj0I~
//**************************************************************** //~vaj0I~
int fileerrvfmtforR(int Prc)                                       //~vaj0I~
{                                                                  //~vaj0I~
//************                                                     //~vaj0I~
	uerrmsg("For fixed length record file, specify not format but length by /F parm",//~vaj0I~
    		"固定長レコードモードでは\"F\"パラメータで可変長形式ではなくレコード長を指定する");//~vaj0I~
	return Prc;                                                    //~vaj0I~
}//fileerrlreclforV                                                //~vaj0I~
