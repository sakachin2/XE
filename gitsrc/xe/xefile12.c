//CID://+vbmjR~:                         Update#=  668             //~vbmjR~
//*************************************************************
//*xefile12.c*                                                     //~v0baR~
//**save,renum-->xefile15                                          //~v0duR~//~va6FR~
//*************************************************************
//vbmj:180812 request "Force" option to save updated at other session.//~vbmjI~
//vb7n:170117 move filename position to last on errmsg for longname//~vb7nI~
//vb31:160418 (LNX64)Compiler warning                              //~vb31I~
//vb30:160411 (LNX)Compiler warning                                //~vb30I~
//vazu:150114 (BUG)partial edit;if save failed,for next save keep UFHelinepos because org file was not changed.//~vazuI~
//vazt:150114 (BUG)"UCHAR UFHpathlen" is invalid when _MAX_PATH>256//~vaztI~
//vazs:150114 (BUG)partial edit;if outfile!=0(save to another file) original file endposition is not changed.=>outfile length did not expand at 2nd save//~vazsI~
//vazj:150113 chk header record validity for recfm=MF              //~vaziI~
//vazg:150112 (BUG)lrecl overflow chk was not done                 //~vazgI~
//vazc:150111 (BUG)did not closed out file when fwrite for not partial copy(additional to vaz4)//~vazcR~
//vaz8:150109 C4244 except ULPTR and ULONG                         //~vaziM~
//vaz5:150107 errmsg "no space" is not valid for partial edit outfile open err by permission//~vaz5I~
//vaz0:150105 BUG:offset value is long long for fseek error msg    //~vaz0I~
//vaz2:150106 set filename on partial file output err(there is no space)//~vaz2I~
//vamF:131119 (BUG)"xpr **/***" fails by "input fmt err" for vhex utf,fold at 0x0a for lc file.//~vamFI~
//vak5:130816 compiler warning;set but not used                    //~vak5I~
//vajr:130818 lrecl adjust for save recfm=F even when save to itself(outfile==0) for utf8 file//~vajrI~
//vajf:130807 xpr **;print hex part by ascii because cp930/cp939 differ for small letter//~vajfI~
//vajb:130804 vhdr len for utf8 code len                           //~vajbI~
//vaj2:130721 (BUG)END /Mt;write eol of UNIX                       //~vaj2I~
//vaj0:130710 localfile:recfm=V support (E /mV F{MFH|RDW|FD|HD|F|H})//~vaj0I~
//vafk:120624 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  use ULPTR(unsigned __int64/ULONG)//~vafkI~
//vafc:120607 C4701 warning(used uninitialized variable) by VC6    //~vafcI~
//vaf9:120607 (WTL)Bug found by vs2010exp(used uninitialized variable),avoid warning C4701//~vaf9I~
//vaa7:111117 (gcc4.6)Warning:unused-but-set                       //~vaa7I~
//va87:100924 (WXE)wxp cmd;**/*** vhex print corespondency of upper and lower line//~va87I~
//va81:100920 (WXEXXE)print ebcfile by ucs for alos wxp **/*** option//~va81I~
//va7L:100905 undo support for EBC SETCP cmd                       //~va7LI~
//va7t:100823 EBC:handle support to file output(save/rep/..)       //~va7tI~
//va6Q:100722 Fxx+/MxR is output lrecl and not input lrecl         //~va6QI~
//va6P:100721 (BUG) last long record is not expanded(case of /MxR) //~va6PI~
//va6N:100721 add eol when /mET                                    //~va6NI~
//va6F:100719 split xefile15 from xefile12                         //~va6FI~//~va6DR~
//va6D:100719 EBC eol 0x15 support                                 //~va6DR~
//va68:100618 expand when LRECL is changed for record mode         //~va68I~
//va66:100618 add "R"(record mode write) to REP/CRE/SAV cmd        //~va66I~
//va5Y:100601 tab translation rule of EBC file                     //~va5YI~
//            save: NOTC/TC option is Invalid for ebc file(keep tab 0x05 and 0x09)//~va5YI~
//            rep:  nonEBC->EBC ignore source NOTC/TC option,always translate tab//~va5YI~
//            load:NOTC option is valid for fixLrecl for excep EBC file;tabctr=1,TC as default//~va5YI~
//va5e:100510 drop eol by /mpr                                     //~va5eI~
//va56:100426 (BUG)set profile also for END cpxx cmd               //~va50I~
//va53:100419 num setr/seti should chk margin/lrecl overflow       //~va53I~
//va50:100324 Raw EBCDIC file support for NFS mount                //~va50I~
//va36:100203 (BUG)can not save to itself if file update was whole undoed after once saved//~va36I~
//va2c:091224 (BUG)filesave use prev line dbcstbl for spf utf8 file(harmfull only for ucs2 version)//~va20I~
//va20:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~va20I~
//                  cvwrite for save/xprint                        //~va20I~
//                  :ddmemcmp                                      //~va20I~
//va1E:091116 optionaly(default) keep original value when UTF8 code err at load//~va1EI~
//va0m:090811 reject CPU8/CPLC for bin file                        //~va0mI~
//va00:090510 merge utf8 version(enclosed by UTF8SUPPH)            //~va00I~
//          files encoded by utf8                                  //~va00I~
//          save option "IE"(ignore translation err)               //~va0mI~
//v92n:080802 (UTF)add  [cplc|cpu8] option for save cmd            //~v92nI~//~va00I~
//v78A:080419 (BUG) spf num clear missing dbcs tbl clear           //~v78AI~
//v78z:080419 (BUG of v73b) spf num on col 80 cleared by obtabdbcs //~v78zI~
//v78u:080329 (BUG)ABEND at save for short line if the file is fixded lrecl and notabclear//~v78uI~
//v76X:071107 save option [NB|BK]                                  //~v76XI~
//v76x:070820 keep bkup by rename for the case abend at save       //~v76xI~
//v75p:070426 FIXLRECL(/Fxx option specified):expand at save if short//~v75pI~
//v73b:070109*(BUG)spf renum force leave dbcs 1st byte at EOL(col80)//~v73bI~
//v739:070109 (BUG)num clear required obtabdbcs process            //~v739I~
//v72n:061127 3270:spf cmd to update spf info                      //~v72nI~
//v71Z:061114 v71Y miss set version number in the following case   //~v71ZI~
//            for SPF err file opened by en,update then "renum force" because SPFNUMOK set by renum at undo.//~v71ZI~
//v71Y:061113 keep spf version number over renum force;(currently reset all renumed if spferr at loadtime)//~v71YI~
//v71R:061111 3270:check after save by reloading and keep result in workdir if save fail//~v71RI~
//v71M:061106 (3270:BUG)msg "file updated from at downloaded tim" is issuend because ind$FILE cut traling space.//~v71MI~
//v71h:061014 (BUG)ABEND when save by pcd==0;to be checked not upundoctr but upctr//~v71hI~
//v719:061004 dirlist DSN list support                             //~v719I~
//v716:060926 3270:"listds" cmd to chk file exist/dsorg            //~v716I~
//v710:060916 (BUG)tmp file remains in xeftpwd by save cmd with remotefile operand.//~v710I~
//v70k:060803 for safety tab chk at save if ULHdbcs gotten(tab may rep to space)//~v70kI~
//v70c:060731 (WXEXXE:BUG)cb is not written by the reason of file updated from read time by the other process. and alloc area not freed at termination.//~v70cI~
//v656:050726 (XXE)xxe support;WXP cmd                             //~v656I~
//v630:050426 grep support  as dos cmd(for edit screen flag line and search by rfind for *L)//~v630I~
//v62n:050321 (BUG)ftpsave rc is ignored                           //~v62nI~
//v625:050309 vhex mode support for wxp **/***(line split no consideration)//~v625I~
//v624:050309 vhex mode support for xpr **/***(line split consideration)//~v624I~
//v623:050309 (BUG)xpr *** lineno size should be refrect current size for gauge line//~v623I~
//v61x:050308 xprint for binfile(rep to "." from crlf etc ctlchar) //~v61xI~
//v61w:050308 xprint on vhex mode                                  //~v61wI~
//v61g:050226 diffrrent errmsg for cobnum fld err                  //~v61gI~
//v60u:050201 xpr cmd;add -tabon option to write tab display char(default istaboff)//~v60uI~
//v60f:050123 (UNX:BUG)rc clear missing after copy success after rename fail by filesystem diffresnnt//~v60fR~
//v57P:040620 cre/rep/app change deault to ALL when with labal range parm//~v57PI~
//v57N:040619 (FTP:BUG)partial edit fail(rename fail because file system diffence)//~v57NI~
//v57M:040619 (FTP:BUG)partial edit cut 2nd part                   //~v57MI~
//v57K:040619 (FTP:BUG)append cmd dose not append but copy only    //~v57KI~
//v576:040513 (FTP:BUG)if u edit same filename except case,        //~v576I~
//            another file name is  save back to remote.so use tempdir//~v576I~
//v574:040509 (FTP:BUG)remote new file save fail by not found      //~v574I~
//v54Y:040201 "cre/rep/sav/app" support xall nxall .a .b           //~v54YI~
//v54U:040125 move updatechk sub to xefsub(used by OS/2 DOS)       //~v54UI~
//v54p:040106 (FTP)uftpisremote interface changed                  //~v54pI~
//v54d:040103 split xefile.c to xefile.c xefile14.c                //~v54dI~
//v546:040101 (FTP:BUG)partial file edit fail                      //~v546I~
//v543:031230 timestamp update chk before save                     //~v543I~
//v53U:031109 (WIN,UNX)ftp support                                 //~v53UI~
//v53g:030923 (BUG)for xprint **;lineno shift like as screen       //~v53gI~
//v53e:030923 (BUG)for xprint **;lineno may changed lineno to hex offset//~v53eI~
//            after once displayed(plhlineno is set previous fmt)  //~v53eI~
//v53d:030923 option seti/setr without renum                       //~v53dI~
//v50t:030112 (BUG)mac eolid=4 but eollen=1,offset calc miss       //~v50tI~
//v506:021019 add "set" option for renum cmd;set num fld on specified colomn//~v506I~
//v48c:020429 (UNX)edit/browse mdos disk support                   //~v48cI~
//v47Y:020415 skip eol chnge write after save cmd with eol option  //~v47YI~
//v47X:020413 mac file support(eol=0x0d) /Mm                       //~v47XI~
//v47T:020406 eol-id change option for cre/rep/app/sav/end cmd     //~v47TI~
//v47L:020330 do save of not updated file if eol-id chnge specified//~v47LI~
//v47A:020321 renum and num clear for cobk                         //~v47AI~
//v47v:020316 COBK w/o N is not spf(allow any char in col.1-6;any lrecl)//~v45vI~
//            for cobk,set cid pos default=col73 if cid is not defined(other than //,;;,||)//~v45vI~
//            COBK with N is spf but col1-6 is ant value           //~v45vI~
//v45x:011219 integrate "num cutoff" cmd to "split" cmd            //~v45uI~
//            (move filecutoff to fcmd4)                           //~v45uI~
//v45u:011216 num cutoff cmd to split continued line               //~v45uI~
//v44i:011204 (BUG of v42x)remain "cob2" on errmsg                 //~v44iI~
//v445:011201 binary file support for xprint **/***                //~v445I~
//v436:011018 (BUG)copy data cut when contain tab and not once displayed//~v436I~
//v430:011010 (BUG)invalid lrecl not reset when cob has no num(col1,col73)//~v430I~
//v42v:011009 option to allow cob num fld is all space             //~v42vI~
//v42u:011009 clear the num fld;spf=col73,cob=col1,cobn=col1+col73 //~v42uI~
//v42t:011009 keep COB status over num clear                       //~v42uR~
//v42s:011009 NOAUTONUM status should not be changed by num clear cmd.//~v42sR~
//v42r:011009 (BUG)num clear ignored at save                       //~v42rI~
//v42i:011002 set spfnum at save for suffix overflow line to avoid line update flag(*u search)//~v42iI~
//v425:010922 (BUG)col 72 cleared by renum twice for cob w/o num.  //~v425I~
//v422:010918 (BUG)spf long record written after topline cid err at save is corrected//~v422I~
//            This is by v413                                      //~v422I~
//            For topline deleted case,keep previous margin/spfpos value//~v422I~
//v420:010918 cob fld num clear option;num clear cob               //~v420I~
//v416:010728 accept clear for without col72 num fld case          //~v416I~
//v413:010728 (BUG)when cid topline is erased for spf file,filegetcid call//~v413I~
//            at filesave destroy spflen;write max length record   //~v413I~
//v412:010728 (BUG)col-72 renumed for cob witout n option          //~v412I~
//v40W:010722 set spfnum(cob) after isrt topline cid(cob)          //~v40WI~
//v40U:010722 cobol support:allow col-72-80 is all space for cobol input//~v40UI~
//v40T:010722 (BUG)cob num fld is not renumed when fld erased but num is same as prev//~v40TI~
//v40S:010722 (BUG)offset change cause renum(bug of logic by xlineno display)//~v40SI~
//v40F:010709 COB support:num clear(clear col72-80)                //~v40FI~
//v40E:010709 COB support:renum                                    //~v40ER~
//v40o:010603 print lcmd when **/***(scr print)                    //~v40oI~
//v40k:010526 screen current print("***")                          //~v40kR~
//v40h:010526 xprint **;like as print screen                       //~v40hI~
//v20P:001111 allow topline upctr init value when no line at load time//~v20PI~
//v20v:001022 option to tab clear when file output                 //~v20vI~
//v17g:000507 (BUG)fclose abend when pf4 after partile file update.//~v17gI~
//v178:000430 renum support for lineno hex mode                    //~v178I~
//v13j:991029 (BUG)It should not be end when close err by disk space shortage.//~v13jI~
//            chk also close err(flush err) at save then notify and wait.//~v13jI~
//v11t:990813 rename target wild card support                      //~v11tI~
//v10Y:990606 support input range by hex offset value(/NXxxx-Xxxx) for edit/browsw cmd//~v10YI~
//            (lineno is couted from 1 even if offset!=0)          //~v10YI~
//v10A:990411 (BUG)splitupctr clear miss.following aplit is trated as all updated//~v10AI~
//v10z:990411 (BUG)pos of cid for split last line is too far.      //~v10zI~
//            it should consider prev split continued line length. //~v10zI~
//            (But probrem remain in the case cid is spritted or on prev line,//~v10zI~
//            new cid dose not replace but added.)                 //~v10zI~
//v108:981213 binary mode extit(no crlf process)                   //~v108I~
//v104:981212 no csr move when renum                               //~v104I~
//v103:981212 (BUG)for binaly file edit,last 0d0a is added         //~v103I~
//            0d0a is added at end of file eveif input has no 0d0a //~v103I~
//            skip add only when thatline is at end of file,if moved to other//~v103I~
//            position,\d0a is added.                              //~v103I~
//v102:981212 (BUG)for binaly file edit,redunt byte write occur.   //~v102I~
//            For the case tab containing line is over 999,last char is doubly written//~v102I~
//v0im:980625 pfk cmd support(optk1 and optk2)                     //~v0imI~
//v0if:980620 pfk cmd support(fmt chk and update c.b)              //~v0ifI~
//v0ib:980530 v0i9 cotinued for other than file copy               //~v0ibI~
//v0ia:980530 add APPend cmd                                       //~v0iaI~
//v@@@:980227 test trap for tab clear-->del                        //~v@@@R~
//v0fq:971109 new file by select cmd has alias but it is temporary name//~v0fqI~
//            it may duplicated alias name.                        //~v0fqI~
//            dont created new pdh if new,isrt at end file if new file.//~v0fqI~
//v0fm:971103 new function to set filename and alias to ufh        //~v0fmI~
//v0eL:970927 (BUG)renum for spf need boundar dbcs/tab             //~v0eLI~
//v0e8:970915 (BUG)need expand before valid spf line chk           //~v0e7I~
//v0e7:970915 (BUG)need chk also valid spfnum for renum.           //~v0e7I~
//v0du:970909 for performance,use flag once chked spfnumok         //~v0duI~
//            set on when chked,reset when line update or insert.  //~v0duI~
//v0cz:970818 null cid //+NONE~R                                   //~v0czI~
//v0cw:970818 drop tab(change to space) at write for spf file      //~v0cwI~
//v0ct:970814 RENUM(NUM reset) Force option for spf file           //~v0ctI~
//v0cq:970814 display version number at time of load,+1 at save.   //~v0cqI~
//v0co:970813 undo set ver even if pfh set only case               //~v0coI~
//v0cn:970813 RENUM undo support(move filerenum from xefile to xefile12)//~v0cnI~
//v0cm:970812 NUM VER subcmd(reset spf version)                    //~v0cmI~
//            use ULF2CIDCLEAR for also version update only        //~v0cmI~
//v0cl:970811 spf NUM field support                                //~v0clI~
//v0ba:970726 split xefile,xefile12(save)                          //~v0baI~
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#ifdef DOS
    #ifdef DPMI					//DPMI version                     //~v095I~
        #include <errno.h>                                         //~v095I~
    #else                       //not DPMI                         //~v095I~
    #endif                      //DPMI or not                      //~v095I~
#else
//  #define INCL_BASE                                              //~v07sR~
//  #include <os2.h>                                               //~v07sR~
#endif
//*******************************************************
#include <ulib.h>
#include <ualloc.h>
#include <uerr.h>
#include <uque.h>
#include <ufile.h>                                              //~5318I~
#include <ufile2.h>
#include <ufile3.h>                                                //~v57NI~
#include <ufile5.h>                                                //~vaj0I~
#include <uparse.h>                                                //~v0b2R~
#include <uedit.h>                                                 //~v0clI~
#include <ustring.h>                                               //~v40FI~
#include <uftp.h>                                                  //~v54pI~
#ifdef UTF8UCS2                                                    //~va20I~
#include <udbcschk.h>                                              //~va20I~
#include <utf22.h>                                                 //~va20I~
#endif                                                             //~va20I~
#include <ucvebc.h>                                                //~va50I~
#include <utrace.h>                                                //~vamFI~
                                                                //~5318I~
#include "xe.h"
#include "xescr.h"
#include "xescr2.h"                                                //~v53UI~
#include "xefile.h"
#include "xefile12.h"                                              //~v0clI~
#include "xefile14.h"                                              //~v54dI~
#include "xefile2.h"                                               //~v40hI~
#include "xefile22.h"                                              //~v445I~
#include "xefile4.h"                                            //~4C23R~
#include "xefile5.h"                                               //~v08qI~
#include "xefile6.h"                                               //~v0e7I~
#include "xefile7.h"    //filefksave                               //~v0ifI~
#include "xedir.h"    //filefksave                                 //~v716I~
#include "xefcmd.h"                                                //~v0iaI~
#include "xefsub.h"                                             //~5318I~
#include "xesub.h"                                              //~5318I~
#include "xeundo.h"                                                //~v0clI~
#include "xeopt.h"                                                 //~v506I~
#ifdef FTPSUPP                                                     //~v53UI~
	#include "xeftp.h"                                             //~v53UR~
	#include "xetso.h"                                             //~v716I~
#endif                                                             //~v53UI~
#ifdef UTF8SUPPH                                                   //~va1EI~
	#include "xeutf.h"                                             //~va1EI~
#endif                                                             //~va1EI~
#ifdef UTF8UCS2                                                    //~va20I~
	#include "xecap2.h"                                            //~va20I~
	#include "xesub2.h"                                            //~va20I~
#endif                                                             //~va20I~
#include "xeebc.h"                                                 //~va50I~
//*******************************************************
int filecloseerr(PUFILEH Ppfh);                                    //~v13jI~
//int filepartialouterr(void);                                     //~vaz2R~
int filepartialouterr(PUFILEH Ppfh);                               //~vaz2I~
int chkmfhheader(PUFILEH Ppfh,int Ppartialsw);                     //~vaziI~
//****************************************************************
// filesave
//*write file                                                   //~v020R~
//*parm1:option end(1) or save(0) or append cmd(3)                 //~v0iaR~
//*      0x10 :bandle used for rep/cre                             //~v0ibI~
//*parm2:file hdr                                               //~5128I~
//*parm3:plh write start                                        //~5128I~
//*parm4:plh write end(or PUCLIENTWE when screen page print)       //~v40kR~
//*parm5:output filename(fullpath)                              //~5128R~
//*rc   :0-ok 4:file load err
//****************************************************************
//int filesave(int Pendsw,PUFILEH Ppfh,PULINEH Pplh1,PULINEH Pplh2,UCHAR *Poutfile)//~v445R~
int filesave(PUCLIENTWE Ppcw,int Pendsw,PUFILEH Ppfh,PULINEH Pplh1,PULINEH Pplh2,UCHAR *Poutfile)//~v445I~
{
	UFILEH  ufhout;                                                //~v08qR~
	PUFILEC pfc;                                                   //~v61wI~
//  PUCLIENTWE scrpcw;	//for prt screen case only                 //~v445R~
	int     rc,len,wlen,cidexplen;                              //~5130R~
	UCHAR   *pcf,*pct,*pcw,*pcd;                                //~5102R~
	LONG    lineno=0;
	LONG    sline,eline;                                           //~v08qI~
	PULINEH plh;
	PUFILEH pfh;                                                //~5128I~
	UCHAR   *cid;
	FILEFINDBUF3 fstat3;     				//output from DosFindxxxx//~v020I~
    int partialsw,procctr;                                         //~v08qR~
    int writebinsw,wpcsw;                                          //~v0abR~
    int sweolebc;                                                  //~va6DI~
    int wmacsw;                                                    //~v47XI~
//  int splitupctr=0,splitupctrlast,swfollow;                      //~v0b9I~//~vafcR~
    int splitupctr=0,splitupctrlast=0,swfollow;                    //~vafcI~
    int spfsw;                                                     //~v0cwI~
    int fixlrecl;                                                  //~v75pI~
    int spflen;                                                    //~v0czI~
    int appendsw;                                                  //~v0iaI~
    int bandlesw;                                                  //~v0ibI~
//  int prtscrsw,prtpagesw,maxline,wrtline=0;                      //~v40kR~//~vaf9R~
    int prtscrsw,prtpagesw,maxline=0,wrtline=0;                    //~vaf9I~
    int prttabsw;                                                  //~v60uI~
    int noeolsw;		//skip eol write                           //~v103I~
    int binfsw,hexbinsw;         //binfilesw                       //~v445R~
    int splittotlen=0;  //len up to previous                       //~v10AR~
//  int xrangeswe=0;                                               //~vaz0R~
    FILESZT xrangeswe=0;                                           //~vaz0I~
    FILE *fhreopen;                                                //~v13jI~
    int droptabsw;                                                 //~v20vI~
//  int linenosz;                                                  //~v625R~
    int linenoszw;	//write len                                    //~v53gI~
    int saveopt=0;                                                 //~v47TI~
    int newsavesw;                                                 //~v546R~
    int ffmsgopt;                                                  //~v574I~
    int  xallsw,nxallsw;                                           //~v54YI~
    char *eolchngid=0;                                             //~v47LR~
//  char wklineno[ULHLINENOSZ+1];                                  //~v624R~
    char wklineno[ULHLINENOSZ+2];                                  //~v624I~
    char *pelocalfnm;                                              //~v546I~
    char *poutfnm;                                                 //~v574I~
    char bkupfnm[_MAX_PATH];                                       //~v76xR~
    int rc2;                                                       //~v716I~
#ifdef FTPSUPP                                                     //~v57KI~
    int  appendremotesw=0;                                           //~v57KI~//~vaf9R~
#endif                                                             //~v57KI~
    int vhexmodesw;                                                //~v61wR~
    int vhexlineidsw;                                              //~v625I~
//#ifdef WXE                                                       //~v656R~
#ifdef WXEXXE                                                      //~v656I~
//  int wxpcmdsw;                                                  //~v625R~//~vaa7R~
#endif                                                             //~v625R~
    int setfstatsw;                                                //~v719I~
    int bkupopt=0;                                                 //~v76XI~
#ifdef UTF8SUPPH                                                   //~v903I~//~va00I~
	int cvwopt;                                                    //~v92nI~//~va00I~
    int cverr=0;                                                   //~va0mI~
	UCHAR   dbcswk[GFILEBUFFSZ],*pcdw;                             //~va1EI~
    int dbcstblen=0;                                               //~va1EI~
#endif                                                             //~v903I~//~va00I~
#ifdef UTF8UCS2                                                    //~va20I~
    int igncverrsw,swutf8file,tdopt;                               //~va20R~
#endif                                                             //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    int swebcfile,opteol;                                          //~va50R~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
	int lreclparm=0;                                                 //~va66I~//~vaf9R~
	int swlrecladjust=0;		//save to another file             //~va68I~
    int optprof=0;                                                 //~va6QR~
    int swupdate=0;                                                //~va6QI~
    int swebcwxpwk;                                                //~va81I~
//  int xphandle;                                                  //~vak5R~
    int optxp;                                                     //~va81R~
    int modechng=0;                                                //~vaj0I~
    int swcut;                                                     //~vaj0I~
    int swrecordfile;                                              //~vamFI~
    int optpc;                                                     //~vazsI~
    int swforce;                                                   //~vbmjI~
//****************************
	pfc=Ppcw->UCWpfc;                                              //~v61wI~
    bandlesw=(Pendsw & FSENDSW_BANDLE); //chk bandle used          //~v0ibI~
    Pendsw &= ~FSENDSW_BANDLE;          //chked no more use        //~v0ibI~
    prtscrsw=(Pendsw & FSENDSW_PRTSCR); //chk print screen req     //~v40hI~
    Pendsw &= ~FSENDSW_PRTSCR;          //chked no more use        //~v40hI~
    prtpagesw=(Pendsw & FSENDSW_PRTPAGE); //chk print screen req   //~v40kI~
    Pendsw &= ~FSENDSW_PRTPAGE;          //chked no more use       //~v40kI~
    prttabsw=(Pendsw & FSENDSW_PRTTAB); //chk print tab display char req//~v60uI~
    Pendsw &= ~FSENDSW_PRTTAB;          //chked no more use        //~v60uI~
#ifdef UTF8UCS2                                                    //~va20I~
    igncverrsw=(Pendsw & FSENDSW_IGNCVER); //chk print tab display char req//~va20I~
    Pendsw &= ~FSENDSW_IGNCVER;          //chked no more use       //~va20I~
#endif                                                             //~va20I~
    swcut=(Pendsw & FSENDSW_CUT); //filesave by CUT cmd            //~vaj0I~
    Pendsw &= ~FSENDSW_CUT;                                        //~vaj0I~
//  vhexmodesw=UCBITCHK(pfc->UFCflag2,UFCF2VHEX);                  //~v624R~
    vhexmodesw=UCBITCHK(pfc->UFCflag2,UFCF2VHEX)!=0;	//1 or 0   //~v624I~
    vhexlineidsw=vhexmodesw;                                       //~v625I~
//#ifdef WXE                                                       //~v656R~
#ifdef WXEXXE                                                      //~v656I~
//  wxpcmdsw=(Pendsw & FSENDSW_WXP); //chk print tab display char req//~v625M~//~vaa7R~
    Pendsw &= ~FSENDSW_WXP;          //chked no more use           //~v625M~
//  if (wxpcmdsw)                                                  //~v625I~//~va87R~
//  	vhexlineidsw=0;				//no set lineid at top of line //~v625I~//~va87R~
#endif                                                             //~v625M~
    swforce=0;  //for compiler warning                             //+vbmjI~
    if (prtpagesw)                                                 //~v40kI~
    {                                                              //~v40kI~
//  	scrpcw=(PUCLIENTWE)(ULONG)Pplh2;                           //~v445R~
//      maxline=scrpcw->UCWheight-scrpcw->UCWfilehdrlineno;        //~v445R~
        maxline=Ppcw->UCWheight-Ppcw->UCWfilehdrlineno;            //~v445I~
//      Pplh2=0;                                                   //~v445R~
    	xallsw=0;                                                  //~v54YI~
    	nxallsw=0;                                                 //~v54YI~
    }                                                              //~v40kI~
    else                                                           //~v47TI~
    {                                                              //~v54YI~
//  	filesaveoptionchk(Ppcw,Ppfh,&saveopt,0);                   //~v54YR~
#ifdef UTF8SUPPH                                                   //~va0mI~
        rc2=                                                       //~va0mI~
#endif                                                             //~va0mI~
//  	filesaveoptionchk(Ppcw,Ppfh,&saveopt,0,0,0);               //~v54YI~//~va66R~
    	filesaveoptionchk(Ppcw,Ppfh,&saveopt,0,0,0,&lreclparm);    //~va66I~
#ifdef UTF8SUPPH                                                   //~va0mI~
        if (rc2)                                                   //~va0mI~
            return rc2;                                            //~va0mI~
#endif                                                             //~va0mI~
    	xallsw=(saveopt & FSOC_XALL); //write excluded all line    //~v54YI~
    	nxallsw=(saveopt & FSOC_NXALL); //write excluded all line  //~v54YI~
    	swforce=((unsigned)saveopt & FSOC_FORCE)!=0; //force write for SAVE/END cmd//~vbmjR~
        if (saveopt & FSOC_NB)                                     //~v76XI~
            bkupopt|=FBRO_NB;                                      //~v76XI~
        else                                                       //~v76XI~
        if (saveopt & FSOC_BK)                                     //~v76XI~
            bkupopt|=FBRO_BK;                                      //~v76XI~
    }                                                              //~v54YI~
                                                                   //~v08qI~
    if (Pplh1)  //repl or create                                   //~v08qI~
//      partialsw=sline=eline=0;  //do not partial file copy       //~v08qR~//~vb31R~
        partialsw=(int)(sline=eline=0);  //do not partial file copy//~vb31I~
    else                                                           //~v08qI~
    {                                                              //~v08qI~
        sline=Ppfh->UFHsline;                                      //~v08qR~
    	eline=Ppfh->UFHeline;                                      //~v08qR~
        partialsw=(sline || eline);                                //~v08qR~
        if (UCBITCHK(Ppfh->UFHflag4,UFHF4XRANGE))   //it may be xrange parm//~v10YR~
        {                                                          //~v10YI~
        	partialsw=1;                                           //~v10YI~
            xrangeswe=Ppfh->UFHelinepos;	//write after end offset//~v10YI~
        }                                                          //~v10YI~
    }                                                              //~v08qI~
	if (Poutfile)		//save to same file                     //~5128I~
	{                                                           //~5128I~
		memcpy(&ufhout,Ppfh,UFILEHSZ);                             //~v08qR~
        if (saveopt & FSOC_EOL_RECORD)  // /MR option for cmd      //~va66I~
        {                                                          //~va66I~
//          if (!UCBITCHK(Ppfh->UFHflag10,UFHF10RECORD))//need whe -Mrx + "S -Mr"//~vaj0R~
     	   		ufhout.UFHflag11|=UFHF11WRECORD;	//record mode write//~va66I~
            if (lreclparm)                                         //~va66I~
            {                                                      //~va66I~
            	ufhout.UFHlreclout=		//for the case org file is not record mode//~va6QI~
//          	ufhout.UFHlrecl=(lreclparm>>16);                   //~va66R~//~vb30R~
            	ufhout.UFHlrecl=(USHORT)(lreclparm>>16);           //~vb30I~
//          	ufhout.UFHmergin=(lreclparm&0xffff);               //~va66R~//~vb30R~
            	ufhout.UFHmergin=(USHORT)(lreclparm&0xffff);       //~vb30I~
                UCBITON(ufhout.UFHflag7,UFHF7FIXLRECL);            //~va66R~
            }                                                      //~va66I~
            UCBITOFF(ufhout.UFHflag13,UFHF13WV);	//reset recfm=V write//~vaj0I~
        }                                                          //~va66I~
        else                                                       //~va66I~
        if (saveopt & FSOC_EOL_RECORDV)  // /MV option for cmd     //~vaj0I~
        {                                                          //~vaj0I~
     	   	ufhout.UFHflag13|=UFHF13WV;	//record mode write        //~vaj0R~
            if (lreclparm)                                         //~vaj0I~
//          	ufhout.UFHvfmt=lreclparm;                          //~vaz8R~
            	ufhout.UFHvfmt=(UCHAR)lreclparm;                   //~vaz8I~
     	   	UCBITOFF(ufhout.UFHflag11,UFHF11WRECORD);	//reset record mode write//~vaj0I~
        }                                                          //~vaj0I~
        else                                                       //~vaj0I~
        {                                                          //~va66I~
//          if (UCBITCHK(ufhout.UFHflag10,UFHF10RECORD))	//read RECORD,no need set write option//~va66R~//~va6QR~
            {                                                      //~va66I~
//      		if (saveopt & (FSOC_EOL_MAC|FSOC_EOL_PC|FSOC_EOL_UNIX))//~va66I~//~va6DR~
        		if (saveopt & (FSOC_EOL_MAC|FSOC_EOL_PC|FSOC_EOL_UNIX|FSOC_EOL_EBC))//~va6DI~
                {                                                  //~va66I~
                    if (saveopt & FSOC_EOL_EBC)                    //~va6DI~
                        UCBITON(ufhout.UFHflag11,UFHF11WTEXTEBC);  //~va6DI~
                    else                                           //~va6DI~
                    if (saveopt & FSOC_EOL_MAC)                    //~va66I~
                        UCBITON(ufhout.UFHflag6,UFHF6WTEXTMAC);    //~va66R~
                    else                                           //~va66I~
                    if (saveopt & FSOC_EOL_PC)                     //~va66I~
                        UCBITON(ufhout.UFHflag3,UFHF3WTEXTPC);     //~va66R~
                    else                                           //~va66I~
                        UCBITON(ufhout.UFHflag3,UFHF3WTEXTUNIX);   //~va66R~
          			UCBITON(ufhout.UFHflag6,UFHF6EOLCHNG);//       //~va66R~
//  	           	UCBITOFF(ufhout.UFHflag10,UFHF10RECORD);	//read RECORD,no need set write option//~va66R~//~va6QR~
 		           	UCBITOFF(ufhout.UFHflag11,UFHF11WRECORD);	//read RECORD,no need set write option//~va6QI~
                	UCBITOFF(ufhout.UFHflag7,UFHF7FIXLRECL);       //~va66I~
		            UCBITOFF(ufhout.UFHflag13,UFHF13WV);	//reset recfm=V write//~vaj0I~
            		ufhout.UFHlrecl=0;                             //~va66I~
            		ufhout.UFHmergin=0;                            //~va66I~
                }                                                  //~va66I~
                else    //keep record mode                         //~va68I~
                if (lreclparm)            //lrecl may changed      //~va68I~
                {                                                  //~va68I~
		          if (UCBITCHK(Ppfh->UFHflag13,UFHF13RV))	//for read V,change vfmt//~vaj0I~
//                  ufhout.UFHvfmt=lreclparm;                      //~vaz8R~
                    ufhout.UFHvfmt=(UCHAR)lreclparm;               //~vaz8I~
                  else                                             //~vaj0I~
//                  ufhout.UFHlrecl=(lreclparm>>16);               //~va68I~//~vb30R~
                    ufhout.UFHlrecl=(USHORT)(lreclparm>>16);       //~vb30I~
//                  ufhout.UFHmergin=(lreclparm&0xffff);           //~va68I~//~vb30R~
                    ufhout.UFHmergin=(USHORT)(lreclparm&0xffff);   //~vb30I~
                    UCBITON(ufhout.UFHflag7,UFHF7FIXLRECL);        //~va68I~
                }                                                  //~va68I~
            }                                                      //~va66I~
        }                                                          //~va66I~
//  	strcpy(ufhout.UFHfilename,Poutfile);                       //~v0fmR~
        ufilesetfhfilename(&ufhout,Poutfile);                      //~v0fmI~
		pfh=&ufhout;                                               //~v08qR~
//      pfh->UFHpathlen=(UCHAR)getpathlen(pfh->UFHfilename,    //get path len//~vaztR~
        pfh->UFHpathlen=getpathlen(pfh->UFHfilename,    //get path len//~vaztI~
								&pfh->UFHlevel,		//dir level //~v03yI~
                              	0);//dir sw                     //~v03yI~
        if (swcut)                                                 //~vaj0I~
        	fileadjustfh4cut(0,Ppcw,pfh,saveopt);                  //~vaj0R~
	}                                                           //~5128I~
	else				//save to same file                     //~5128I~
	{                                                           //~5128I~
		pfh=Ppfh;                                               //~5128I~
//  	if (pfh->UFHupctr==pfh->UFHupctrsave)	//same as saved //~5128R~//~va6QR~
//  	{                                                       //~5128R~//~va6QR~
//        if (saveopt & (FSOC_EOL_PC|FSOC_EOL_UNIX))               //~v47XR~
//        if (saveopt & (FSOC_EOL_PC|FSOC_EOL_UNIX|FSOC_EOL_MAC))  //~v47XI~//~va66R~
//        if (saveopt & (FSOC_EOL_PC|FSOC_EOL_UNIX|FSOC_EOL_MAC|FSOC_EOL_RECORD))//~va66I~//~va6DR~
//        if (saveopt & (FSOC_EOL_PC|FSOC_EOL_UNIX|FSOC_EOL_MAC|FSOC_EOL_RECORD|FSOC_EOL_EBC))//~vaj0R~
          if (saveopt & (FSOC_EOL_PC|FSOC_EOL_UNIX|FSOC_EOL_MAC|FSOC_EOL_RECORD|FSOC_EOL_EBC|FSOC_EOL_RECORDV))//~vaj0I~
//*                                                   //  eolchng by end cmd option//~va6QI~
          {                                                        //~v47TI~
          	if (saveopt & FSOC_EOL_EBC)                            //~va6DI~
            	eolchngid="EBC file";                              //~va6DI~
            else                                                   //~va6DI~
          	if (saveopt & FSOC_EOL_MAC)                            //~v47XI~
            	eolchngid="Mac file";                              //~v47XI~
            else                                                   //~v47XI~
          	if (saveopt & FSOC_EOL_PC && saveopt & FSOC_EOL_UNIX)  //~vaj2I~
            	eolchngid="Text file";                             //~vaj2I~
            else                                                   //~vaj2I~
          	if (saveopt & FSOC_EOL_PC)                             //~v47TI~
            	eolchngid="PC file";                               //~v47TI~
            else                                                   //~v47TI~
          	if (saveopt & FSOC_EOL_RECORD)                         //~va66I~
            {                                                      //~vaj0I~
            	eolchngid="RecordMode";                            //~vaj0R~
                modechng=1;                                        //~vaj0I~
            }                                                      //~vaj0I~
            else                                                   //~va66I~
          	if (saveopt & FSOC_EOL_RECORDV)                        //~vaj0I~
            {                                                      //~vaj0I~
            	if (UCBITCHK(pfh->UFHflag13,UFHF13RV))  //-Mv to -Mv with different vfmt//~vaj0R~
            		eolchngid="new V format";                      //~vaj0I~
                else                                               //~vaj0I~
            		eolchngid="recfm=V";                           //~vaj0R~
                modechng=1;                                        //~vaj0I~
            }                                                      //~vaj0I~
            else                                                   //~vaj0I~
            	eolchngid="Unix file";                             //~v47TI~
//          UCBITOFF(pfh->UFHflag6,UFHF6EOLCHNG);//skip eol chng write at save//~v47YI~//~va6QI~
          	if (saveopt & FSOC_EOL_RECORD)	//end cmd with /mr     //~va6QI~
            {                                                      //~va6QI~
            	if (!UCBITCHK(pfh->UFHflag10,UFHF10RECORD))	//edit of not record mode//~va6QI~
                {                                                  //~va6QI~
     	   			pfh->UFHflag11|=UFHF11WRECORD;	//record mode write//~va6QI~
                	UCBITON(pfh->UFHflag7,UFHF7FIXLRECL);          //~va6QR~
    				UCBITOFF(pfh->UFHflag7,UFHF7NOFIXOPT);         //~va6QI~
					UCBITON(pfh->UFHflag6,UFHF6EOLCHNG);//skip eol chng write at save//~va6QI~
                }                                                  //~va6QI~
            	pfh->UFHlreclout=		//allow to change lrecl    //~va6QI~
//          	pfh->UFHlrecl=(lreclparm>>16);                     //~va6QI~//~vb30R~
            	pfh->UFHlrecl=(USHORT)(lreclparm>>16);             //~vb30I~
//          	pfh->UFHmergin=(lreclparm&0xffff);                 //~va6QI~//~vb30R~
            	pfh->UFHmergin=(USHORT)(lreclparm&0xffff);         //~vb30I~
            	UCBITOFF(pfh->UFHflag13,UFHF13WV);	//reset wrtte  recfm=V//~vaj0R~
            }                                                      //~va6QI~
            else                                                   //~va6QI~
          	if (saveopt & FSOC_EOL_RECORDV)	//end cmd with /mv     //~vaj0I~
            {                                                      //~vaj0I~
            	if (!UCBITCHK(pfh->UFHflag13,UFHF13RV))	//edit of not record mode//~vaj0I~
                {                                                  //~vaj0I~
     	   			pfh->UFHflag13|=UFHF13WV;	//recfm=V mode write//~vaj0I~
                	UCBITOFF(pfh->UFHflag7,UFHF7FIXLRECL);         //~vaj0I~
    				UCBITOFF(pfh->UFHflag7,UFHF7NOFIXOPT);         //~vaj0I~
                }                                                  //~vaj0I~
//          	pfh->UFHvfmt=lreclparm;	//new vfmt                 //~vaz8R~
            	pfh->UFHvfmt=(UCHAR)lreclparm;	//new vfmt         //~vaz8I~
				UCBITON(pfh->UFHflag6,UFHF6EOLCHNG);//even when 13RV,vfmt changed(reject at f5 if vfmt is same)//~vaj0I~
     	   		UCBITOFF(pfh->UFHflag11,UFHF11WRECORD);	//record mode write//~vaj0I~
            }                                                      //~vaj0I~
            else	//eol specified                                //~vaj0I~
            {                                                      //~va6QI~
            	if (UCBITCHK(pfh->UFHflag10,UFHF10RECORD))	//edit of record mode//~va6QI~
                {                                                  //~va6QI~
					UCBITON(pfh->UFHflag6,UFHF6EOLCHNG);//skip eol chng write at save//~va6QI~
                }                                                  //~va6QI~
                else                                               //~vaj0I~
            	if (UCBITCHK(pfh->UFHflag13,UFHF13RV))	//recfm=V  //~vaj0I~
					UCBITON(pfh->UFHflag6,UFHF6EOLCHNG);//skip eol chng write at save//~vaj0I~
          		if (saveopt & FSOC_RETLRECL) 	//-Flrecl specified//~vaj0R~
                {                                                  //~vaj0R~
            		pfh->UFHlreclout=		//allow to change lrecl//~vaj0R~
//          		pfh->UFHlrecl=(lreclparm>>16);                 //~vaj0R~//~vb30R~
            		pfh->UFHlrecl=(USHORT)(lreclparm>>16);         //~vb30I~
//          		pfh->UFHmergin=(lreclparm&0xffff);             //~vaj0R~//~vb30R~
            		pfh->UFHmergin=(USHORT)(lreclparm&0xffff);     //~vb30I~
                    if (!pfh->UFHlrecl)                            //~vaj0R~
                    {                                              //~vaj0R~
                		UCBITOFF(pfh->UFHflag7,UFHF7FIXLRECL);     //~vaj0R~
    					UCBITON(pfh->UFHflag7,UFHF7NOFIXOPT);      //~vaj0R~
                    }                                              //~vaj0R~
                    else                                           //~vaj0I~
                    {                                              //~vaj0I~
                		UCBITON(pfh->UFHflag7,UFHF7FIXLRECL);      //~vaj0I~
    					UCBITOFF(pfh->UFHflag7,UFHF7NOFIXOPT);     //~vaj0I~
                    }                                              //~vaj0I~
                }                                                  ///~vaj0R~
            	UCBITOFF(pfh->UFHflag11,UFHF11WRECORD);	           //~va6QI~
            	UCBITOFF(pfh->UFHflag13,UFHF13WV);                 //~vaj0I~
            }                                                      //~va6QI~
          }                                                        //~v47TI~
          else                                                     //~v47LI~
          if (!pfh->UFHupctr && UCBITCHK(pfh->UFHflag6,UFHF6EOLCHNG))////~v47LR~
//*                                                   //  eolchng by edit cmd option//~va6QI~
          {                                                        //~v47LI~
            if (UBITCHKALL(pfh->UFHflag3,UFHF3WTEXTPC|UFHF3WTEXTUNIX))//~va6NR~
            	eolchngid="Text file";                             //~va6NI~
            else                                                   //~va6NI~
            if (UCBITCHK(pfh->UFHflag11,UFHF11WTEXTEBC))           //~va6DI~
            	eolchngid="EBC file";                              //~va6DI~
            else                                                   //~va6DI~
            if (UCBITCHK(pfh->UFHflag6,UFHF6WTEXTMAC))             //~v47XI~
            	eolchngid="Mac file";                              //~v47XI~
            else                                                   //~v47XI~
            if (UCBITCHK(pfh->UFHflag3,UFHF3WTEXTPC))              //~v47LR~
            	eolchngid="PC file";                               //~v47LR~
            else                                                   //~v47LI~
            if (UCBITCHK(pfh->UFHflag11,UFHF11WRECORD))            //~va5eI~
            {                                                      //~vaj0I~
                modechng=1;                                        //~vaj0I~
            	eolchngid="RecordMode";                            //~va5eI~
            }                                                      //~vaj0I~
            else                                                   //~va6NI~
            if (UCBITCHK(pfh->UFHflag13,UFHF13WV))                 //~vaj0I~
            {                                                      //~vaj0I~
                modechng=1;                                        //~vaj0I~
            	eolchngid="recfm=V";                               //~vaj0R~
            }                                                      //~vaj0I~
            else                                                   //~vaj0I~
            	eolchngid="Unix file";                             //~v47LR~
          }                                                        //~v47LI~
    	if (pfh->UFHupctr==pfh->UFHupctrsave)	//same as saved    //~va6QI~
    	{                                                          //~va6QI~
          if (eolchngid)                                           //~va6QI~
            optprof=FUPO_ECMD;    //end cmd ,update lrecl of profile/~va6QR~//~va6QI~
          else                                                     //~v47TI~
		  {					//not (noupdate and eol chnge req by edit parm)//~v47LI~
            if (UCBITCHK(pfh->UFHflag11,UFHF11EBCSETCP)            //~va7LR~
            &&  pfh->UFHhandle!=pfh->UFHhandleorg)                 //~va7LI~
				fileupdateprofile(FUPO_RCMD,Ppcw,pfh);                           //~va7KI~//~va7LI~
			uerrmsg("%s is not Updated",                        //~5128R~
					"%s は未更新",                              //~5128R~
					pfh->UFHfilename);                          //~5128R~
			return 0;                                           //~5128R~
          }                                                        //~v47LI~
   		}                                                      //~5128R~//~va36R~
        else   //updated                                           //~va36I~
        {                                                          //~va36I~
            swupdate=1;                                            //~va6QI~
          	if (eolchngid)                                         //~va6QI~
            	optprof=FUPO_ECMD;    //end cmd ,update lrecl of profile/~va6QR~//~va6QI~
			if (!pfh->UFHupctr	//back to original                 //~va36I~
			&&  pfh->UFHupctrsave==-1	//once saved               //~va36I~
			&&  (Pendsw & 0x01)		//not Save cmd but End cmd     //~va36I~
            )                                                      //~va36I~
            {                                                      //~va36I~
         		if (!scrconfirmchk(GSCRCONFSAVE))   //not yet confirmed//~va36I~
            	{                                                  //~va36I~
                	uerrmsg("Wholly Undone, but once saved. Use same key to force save(Override previous Save),or Esc to cancel",//~va36R~
                        	"全変更は戻されたが一度保存しています。続行(前の保存は上書き)する時は再入力,Escで取消");//~va36I~
                    return 1;                                      //~va36I~
            	}                                                  //~va36I~
            }                                                      //~va36I~
        }                                                          //~va36I~
       if (!UCBITCHK(pfh->UFHflag8,UFHF8NOUPDCHK))//force save (::cb at term)//~v70cR~
       {                                                           //~v70cI~
//       if (!scrconfirmchk(GSCRCONFSAVE))   //not yet confirmed   //~v543R~//~vbmjR~
         if (!swforce)   //not yet confirmed                       //~vbmjI~
//          if (xeftpsave(XEFTPSO_UPDATECHKONLY,Ppcw,pfh))//updated//~v54UR~
//          if (xefsubupdatechk(Ppcw,pfh))//updated                //~v716R~
            if (rc2=xefsubupdatechk(Ppcw,pfh),rc2)//updated        //~v716I~
            {                                                      //~v543R~
              UCBITON(pfh->UFHflag,UFHFWRITEERR); //dont delete at closefree to manual chk later//~v71RR~
              if (rc2>0)	//not tso err                          //~v716I~
//              uerrmsg("File is updated after load,Use same key to force save,or Esc to cancel",//~v543R~//~vbmjR~
//                      "ファイルが読み込み時から変更されています。続行する時は再入力,Escで取消");//~v543R~//~vbmjR~
                uerrmsg("File is updated after load,Specify \"/Force\" to SAVe/END cmd,or Esc-Key to Cancel",//~vbmjR~
                        "ファイルが読み込み時から変更されています。強行するにSAVe/END コマンドで \"/Force\"を指定, Escキーで取消");//~vbmjR~
                return 8;                                          //~v543R~
            }                                                      //~v543R~
        }                                                          //~v70cI~
    	if (partialsw)                                             //~v08qM~
        {                                                          //~v08qM~
			memcpy(&ufhout,Ppfh,UFILEHSZ);                         //~v08qM~
        	filetempname(&ufhout);                                 //~v08qM~
            UCBITOFF(ufhout.UFHflag6,UFHF6REMOTE);//for filetempname,but should be off for filereopen//~v57MI~
			pfh=&ufhout;	//write to temp file                   //~v08qI~
		}                                                          //~v08qM~
		if (pfh->UFHtype==UFHTKFI)	//ke func ini file             //~v0ifR~
        {                                                          //~v0imR~
        	if (rc=filefksave(pfh),rc)                             //~v0ifR~
            	return rc;                                         //~v0ifI~
    		UCBITON(pfh->UFHflag,UFHFUPCTRREQ);	//next time updatectr up//~v0imR~
    		pfh->UFHupctrsave=pfh->UFHupctr;		//upctr when saved//~v0imR~
            return 0;                                              //~v0imR~
        }                                                          //~v0imR~
#ifdef FTPSUPP                                                     //~v53UI~
        else                                                       //~v53UI~
		if (pfh->UFHtype==UFHTHOSTS)	//ftp hosts file           //~v53UI~
        {                                                          //~v53UI~
        	if (rc=xeftphostsget(Ppcw,pfh),rc)                     //~v53UR~
            	return rc;                                         //~v53UI~
        }                                                          //~v53UI~
#endif                                                             //~v53UI~
//*out to same file                                                //~va6DI~
	}                                                           //~5128I~
    if (chkmfhheader(pfh,partialsw))                               //~vaziI~
    	return 4;                                                  //~vaziI~
	UCBITON(pfh->UFHflag,UFHFUPCTRREQ);	//next time updatectr up//~5128R~
                                                                   //~v0avI~
	if (!Poutfile)		//save to same file                        //~v20PI~
    	UCBITON(pfh->UFHflag5,UFHF5TLUCTR);	//request id to filetoplineuctr//~v20PR~
//  spfsw=UCBITCHK(pfh->UFHflag2,UFHF2SPFNUMOK);                   //~v422R~
//  spflen=pfh->UFHlrecl;                                          //~v422R~
    if (filegetcid(pfh,2,0,&cid))//chk hdr line if sline==0,if err //~v0avM~
    {                                                              //~v20PI~
	    UCBITOFF(pfh->UFHflag5,UFHF5TLUCTR);	//request id to filetoplineuctr//~v20PI~
    	return 4;				//topline cid header err           //~v0avM~
    }                                                              //~v20PI~
    UCBITOFF(pfh->UFHflag5,UFHF5TLUCTR);	//request id to filetoplineuctr//~v20PI~
                                                                   //~v0avI~
    writebinsw=(UCBITCHK(pfh->UFHflag3,UFHF3WBIN)!=0)*FILE_OPEN_BIN;//~v0abI~
    sweolebc=UCBITCHK(pfh->UFHflag11,UFHF11WTEXTEBC);              //~va6DR~
    wpcsw=(UCBITCHK(pfh->UFHflag3,UFHF3WBIN|UFHF3WTEXTPC)          //~v47TR~
    		==(UFHF3WBIN|UFHF3WTEXTPC));//write pc eol by bin mode //~v47TR~
    wmacsw=UCBITCHK(pfh->UFHflag3,UFHF3WBIN)                       //~v47XI~
           &&UCBITCHK(pfh->UFHflag6,UFHF6WTEXTMAC);	//mac eol write//~v47XR~
    if (saveopt & FSOC_EOL_PC)                                     //~v47TI~
    {                                                              //~v47XI~
    	wmacsw=0;                                                  //~v47XI~
#ifdef UNX                                                         //~vaj2I~
      if (!(saveopt & FSOC_EOL_UNIX))	//not Mt                   //~vaj2I~
#endif                                                             //~vaj2I~
        wpcsw=1;                                                   //~v47TI~
        sweolebc=0;                                                //~va6DI~
    }                                                              //~v47XI~
    if (saveopt & FSOC_EOL_MAC)                                    //~v47XI~
    {                                                              //~v47XI~
        wmacsw=1;                                                  //~v47XI~
        wpcsw=0;                                                   //~v47XI~
        sweolebc=0;                                                //~va6DI~
    }                                                              //~v47XI~
    if (saveopt & FSOC_EOL_UNIX)                                   //~v47TI~
    {                                                              //~v47XI~
    	wmacsw=0;                                                  //~v47XI~
#ifndef UNX                                                        //~vaj2I~
      if (!(saveopt & FSOC_EOL_PC))	//not Mt                       //~vaj2I~
#endif                                                             //~vaj2I~
        wpcsw=0;                                                   //~v47TI~
        sweolebc=0;                                                //~va6DI~
    }                                                              //~v47XI~
    if (saveopt & FSOC_EOL_EBC)                                    //~va6DI~
    {                                                              //~va6DI~
    	wmacsw=0;                                                  //~va6DI~
        wpcsw=0;                                                   //~va6DI~
        sweolebc=1;                                                //~va6DI~
    }                                                              //~va6DI~
    spfsw=UCBITCHK(pfh->UFHflag2,UFHF2SPFNUMOK);                   //~v422R~
    spflen=pfh->UFHlrecl;                                          //~v422R~
    if (UCBITCHK(pfh->UFHflag13,UFHF13WV))//write lrecl=V          //~vaj0R~
    	fixlrecl=0; //do not expand record by space                //~vaj0I~
    else                                                           //~vaj0I~
    if (UCBITCHK(pfh->UFHflag11,UFHF11WRECORD)                     //~va6QI~
    &&  !UCBITCHK(pfh->UFHflag10,UFHF10RECORD)                     //~va6QR~
    )                                                              //~va6QI~
        fixlrecl=pfh->UFHlreclout;                                 //~va6QR~
    else                                                           //~va6QI~
    if (UCBITCHK(pfh->UFHflag7,UFHF7FIXLRECL)                      //~v75pI~
    && !UCBITCHK(pfh->UFHflag7,UFHF7NOFIXOPT))                     //~v75pI~
    	fixlrecl=pfh->UFHlrecl;                                    //~v75pI~
    else                                                           //~v75pI~
    	fixlrecl=0;                                                //~v75pI~
    *bkupfnm=0;                                                    //~v76xI~
	if (Poutfile)                                                  //~va68I~
		swlrecladjust=1;		//save to another file             //~va68I~
    else                                                           //~vajrI~
    	if (FILEUTF8MODE(Ppfh))	                                   //~vajrI~
			swlrecladjust=1;		//no space padding and adjust at fsub cvwrite//~vajrI~
  if (partialsw)                                                   //~v08qI~
  {                                                                //~v13jI~
  	rc=filepartialcopy(0,Ppfh,pfh);                                //~v08qI~
  			//open Ppfh="rb",pfh="wb",copy then reopen pfh="w+"    //~v08qI~
    if (rc)                                                        //~v13jI~
//    	filepartialouterr();                                       //~vaz2R~
      if (rc!=8)    //not outfile openerr                          //~vaz5I~
      	filepartialouterr(pfh);                                    //~vaz2I~
  }                                                                //~v13jI~
  else                                                             //~v08qI~
	if (Poutfile || UCBITCHK(pfh->UFHflag,UFHFNEW))                //~v08qR~
    {                                                              //~v0iaI~
//  	rc=filefindopen(pfh->UFHfilename,&fstat3,-1,&pfh->UFHhfile,FFMSG);//"w" open//~v0abR~
//  	rc=filefindopen(pfh->UFHfilename,&fstat3,writebinsw+FILE_OPEN_OUT,&pfh->UFHhfile,FFMSG);//"w" open//~v0iaR~
        appendsw=FILE_OPEN_APPEND*(Pendsw==FCMDFOAPP);             //~v0iaI~
    	ffmsgopt=FFNONFMSG;	//no notfound msgrequired              //~v574R~
        poutfnm=pfh->UFHfilename;                                  //~v574I~
#ifdef  FTPSUPP                                                    //~v574I~
        appendremotesw=appendsw;                                   //~v57KI~
	    if (FILEISREMOTE(pfh))//remote output by rep/cre/save      //~v574I~
        {                                                          //~v57KI~
        	poutfnm=pfh->UFHftpwdfnm;	//output open temp file    //~v574I~
            appendsw=0; //write to local temp                      //~v57KI~
        }                                                          //~v57KI~
#endif                                                             //~v574I~
#ifdef UNX                                                         //~v48cI~
//  	rc=filefindopen(pfh->UFHfilename,&fstat3,appendsw+writebinsw+FILE_OPEN_OUT,&pfh->UFHhfile,FFMSG,pfh->UFHalias);//"w" open//~v574R~
//  	rc=filefindopen(poutfnm,&fstat3,appendsw+writebinsw+FILE_OPEN_OUT,&pfh->UFHhfile,ffmsgopt,pfh->UFHalias);//"w" open//~v576R~
    	rc=filefindopen(poutfnm,&fstat3,appendsw+writebinsw+FILE_OPEN_OUT,&pfh->UFHhfile,ffmsgopt,pfh->UFHalias,0);//"w" open//~v576I~
#else                                                              //~v48cI~
//  	rc=filefindopen(pfh->UFHfilename,&fstat3,appendsw+writebinsw+FILE_OPEN_OUT,&pfh->UFHhfile,FFMSG);//"w" open//~v574R~
  #ifdef  FTPSUPP                                                  //~v576I~
    	rc=filefindopen(poutfnm,&fstat3,appendsw+writebinsw+FILE_OPEN_OUT,&pfh->UFHhfile,ffmsgopt,0);//"w" open,local file open for remote//~v576I~
  #else                                                            //~v576I~
    	rc=filefindopen(poutfnm,&fstat3,appendsw+writebinsw+FILE_OPEN_OUT,&pfh->UFHhfile,ffmsgopt);//"w" open//~v574I~
  #endif                                                           //~v576I~
#endif                                                             //~v48cI~
    }                                                              //~v0iaI~
	else
    {                                                              //~v76xI~
      if (writebinsw)                                              //~v0abI~
//  	rc=!filereopen(pfh,"wb");		//once close,reopen bin mode write//~v76xR~
//  	rc=!filebkupreopen(0,pfh,"wb",bkupfnm);		//once close,reopen bin mode write//~v76XR~
    	rc=!filebkupreopen(bkupopt,pfh,"wb",bkupfnm);		//once close,reopen bin mode write//~v76XI~
      else                                                         //~v0abI~
//  	rc=!filereopen(pfh,"w");		//once close               //~v76xR~
//  	rc=!filebkupreopen(0,pfh,"w",bkupfnm);		//once close   //~v76XR~
    	rc=!filebkupreopen(bkupopt,pfh,"w",bkupfnm);		//once close//~v76XI~
    }                                                              //~v76xI~
	if (rc)					//once close 
	{
  		UCBITON(pfh->UFHflag,UFHFWRITEERR);	//flag err          //~5128R~
		return 4;
	}
                                                                   //~v08qI~
  	UCBITOFF(pfh->UFHflag,UFHFWRITEERR);	//reset flag err    //~v03yI~
	if (sline)	//first  half copy to temp or other file           //~v08qI~
    	lineno=sline-1;	//for ULHlinenow                           //~v08qI~
//  if (pfh->UFHsline) //first line not loaded                     //~v09rR~
//  	cid=filegetcid(pfh,1);	//do not chk first line            //~v09rR~
//  else                                                           //~v09rR~
//  cid=filegetcid(pfh,0);	//get changeid when close,chk first line//~v09rR~
//  cid=filegetcid(pfh,2,0);	//chk hdr line if sline==0         //~v0avR~
	if (!(plh=Pplh1))	//full write                            //~5128I~
		plh=UGETQTOP(&pfh->UFHlineque);		//top entry         //~5128R~
    binfsw=                                                        //~v445I~
    noeolsw=UCBITCHK(pfh->UFHflag4,UFHF4BIN);	//bynary mode      //~v108I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    if (!noeolsw)   //not Bin file                                 //~va50I~
    {                                                              //~va50I~
    	if (UCBITCHK(pfh->UFHflag11,UFHF11WRECORD))                //~va5eI~
	    	noeolsw=1;		//no write EOL if not write mode!=P or U//~va5eI~
        else                                                       //~va5eI~
    	if (UCBITCHK(pfh->UFHflag13,UFHF13WV))                     //~vaj0R~
	    	noeolsw=1;		//no write EOL if not write mode!=P or U//~vaj0R~
        else                                                       //~vaj0R~
    	if (UCBITCHK(pfh->UFHflag10,UFHF10RECORD))                 //~va50I~
        {                                                          //~va50I~
            if (!(  UCBITCHK(pfh->UFHflag3,UFHF3WTEXTPC|UFHF3WTEXTUNIX)//~va50I~
            	  ||UCBITCHK(pfh->UFHflag11,UFHF11WTEXTEBC)        //~va6DI~
            	  ||UCBITCHK(pfh->UFHflag6,UFHF6WTEXTMAC)          //~va50I~
			     )                                                 //~va50I~
               )                                                   //~va50I~
			  if (!UCBITCHK(pfh->UFHflag6,UFHF6EOLCHNG))//skip eol chng write at save//~va6QI~
	    		noeolsw=1;		//no write EOL if not write mode!=P or U//~va50I~
        }                                                          //~va50I~
    }                                                              //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    hexbinsw=UCBITCHK(pfh->UFHflag5,UFHF5HEX);	//bynary mode with hex display//~v445R~
                                                                   //~v20vI~
	droptabsw=UCBITCHK(pfh->UFHflag5,UFHF5DROPTAB);//no tab clear at save//~v20vI~
#ifdef UTF8UCS2                                                    //~va20I~
    swutf8file=FILEUTF8MODE(pfh);                                  //~va20I~
#endif                                                             //~va20I~
#ifdef UTF8EBCD                                                    //~va50I~
    swebcfile=PFH_ISEBC(pfh);                                      //~va50I~
	if (saveopt & FSOC_CPEB) //to ebc                              //~va50I~
    {                                                              //~va5YI~
      if (Poutfile && !swebcfile)	           //nonEBC =>EBC      //~va5YR~
//      droptabsw=1;                                               //~va50I~//~va5YR~
        droptabsw=0;                                               //~va5YI~
    }                                                              //~va5YI~
#endif                                                             //~va50I~
//* save for print screen *****************************            //~v40kR~
    if (prtscrsw)	//screen print                                 //~v40hI~
    {                                                              //~v40hI~
    	swebcwxpwk=swebcfile;                                      //~va81R~
//      xphandl=ppfh->UFHhandle;                                   //~vak5R~
//  	linenosz=ULHLINENOSZ;                                      //~v625R~
    	linenoszw=Ppcw->UCWlinenosz;                               //~v53gI~
        if (prtpagesw)                                             //~v445I~
        {                                                          //~v445I~
			if (Ppcw->UCWfilehdrlineno>FILEHDRLINENO)	//gauge required//~v445I~
            {                                                      //~v445I~
//          	if (vhexmodesw)                                    //~v625R~
            	if (vhexlineidsw)                                  //~v625I~
                	*Gfilebuff='*';	//id of not data line          //~v624I~
//              len=80;                                            //~v445I~//~va81R~
                len=Ppcw->UCWwidth;                                //~va81I~
//              len=filecolsprint(Ppcw,Gfilebuff,linenosz,len);    //~v623R~
//              len=filecolsprint(Ppcw,Gfilebuff,linenoszw,len);   //~v624R~
//              len=filecolsprint(Ppcw,Gfilebuff+vhexmodesw,linenoszw,len);//~v625R~
                len=filecolsprint(Ppcw,Gfilebuff+vhexlineidsw,linenoszw,len);//~v625I~
			    if (swebcwxpwk)                                    //~va81R~
                {                                                  //~va81I~
//                  ucvebc_a2bfld(0,xphandle,Gfilebuff,Gfilebuff,len+vhexlineidsw-1);//~va81R~//~vajfR~
                    *(Gfilebuff+len+vhexlineidsw-1)=EBC_NL;        //~va81R~
                                                                   //~va81I~
                }                                                  //~va81I~
//          	if (rc=filewrite(pfh,Gfilebuff,(size_t)len),rc)    //~v624R~
//          	if (rc=filewrite(pfh,Gfilebuff,(size_t)(len+vhexmodesw)),rc)//~v625R~
            	if (rc=filewrite(pfh,Gfilebuff,(size_t)(len+vhexlineidsw)),rc)//~v625I~
            		return rc;                                     //~v445I~
            }                                                      //~v445I~
        }                                                          //~v445I~
        swrecordfile=UCBITCHK(pfh->UFHflag10,UFHF10RECORD)||UCBITCHK(pfh->UFHflag13,UFHF13RV);//~vamFI~
        for (;plh;plh=UGETQNEXT(plh))                              //~v40kR~
        {                                                          //~v40hI~
        	if (prtpagesw)                                         //~v40kI~
            	if (wrtline>=maxline)                              //~v40kI~
                	break;                                         //~v40kI~
            if (plh->ULHtype==ULHTDATA) //file data                //~v40hI~
            {                                                      //~v40hI~
                if (!plh->ULHdbcs) //not displayed                 //~v40hI~
                    if (filechktabdbcs(plh)==UALLOC_FAILED)//expand data len//~v40hI~
                        return UALLOC_FAILED;                      //~v40hI~
    	        len=plh->ULHlen;                                   //~v40hI~
#ifdef UTF8UCS2                                                    //~va20I~
                len=min(len,GFILEBUFFSZ);                          //~va20I~
                memcpy(Gfilebuff,plh->ULHdata,(UINT)len);          //~va20I~
                memcpy(dbcswk,plh->ULHdbcs,(UINT)len);             //~va20I~
              	if (binfsw)	//binfile printscr                     //~va20I~
                {                                                  //~va81I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
			      if (!swebcwxpwk)                                 //~va81R~
                	tabdisplayforxpr(0,plh,Gfilebuff,dbcswk,len);//rep ctl-char to "."//~va50I~
#else                                                              //~va50I~
                	tabdisplayforxpr(Gfilebuff,dbcswk,len);//rep ctl-char to "."//~va20I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
                }                                                  //~va81I~
              	else                                               //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
              	if (swebcfile)     //write tab display char        //~va50R~
                {                                                  //~va81I~
			      if (!swebcwxpwk)                                 //~va81R~
                	tabdisplayforxpr(TDXPO_TEXT,plh,Gfilebuff,dbcswk,len);//rep ctl-char to "."//~va50I~
                }                                                  //~va81I~
                else                                               //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50M~
              	if (prttabsw)     //write tab display char         //~va20I~
                {                                                  //~va20I~
                    tdopt=binfsw|FILETDO_PRINT;                    //~va20I~
                	if (swutf8file)                                //~va20I~
	                	tdopt|=FILETDO_UTF8;                       //~va20R~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
                	tabdisplay(plh,Gfilebuff,dbcswk,len,tdopt);    //~va50I~
#else                                                              //~va50I~
                	tabdisplay(Gfilebuff,dbcswk,len,tdopt);        //~va20R~
#endif //UTF8EBCS raw ebcdic file support                          //~va50I~
                }                                                  //~va20I~
                else                                               //~vamFR~
                if (swrecordfile) //except ebc,recfm=R/V           //~vamFR~
                {                                                  //~vamFR~
                    UTRACEP("filesave xpr recordfile\n");          //~vamFR~
                    tabdisplayforxprrecord(0,plh,Gfilebuff,dbcswk,len);//rep 0d/0a//~vamFR~
                }                                                  //~vamFR~
                                                                   //~va20I~
#else                                                              //~va20I~
//!UTF8UCS2                                                        //~va50I~
                len=min(len,GFILEBUFFSZ*2);                        //~v445I~
                memcpy(Gfilebuff,plh->ULHdata,(UINT)len);          //~v445R~
              if (binfsw)	//binfile printscr                     //~v61xI~
                tabdisplayforxpr(Gfilebuff,plh->ULHdbcs,len);//rep ctl-char to "."//~v61xI~
              else                                                 //~v61xI~
              if (prttabsw)     //write tab display char           //~v60uI~
                tabdisplay(Gfilebuff,plh->ULHdbcs,len,binfsw);     //~v445I~
#endif                                                             //~va20I~
		        pcf=Gfilebuff;                                     //~v445I~
            }                                                      //~v40hI~
            else                                                   //~v40hI~
            {                                                      //~v445I~
    	        len=80;                                            //~v40hI~
		        pcf=plh->ULHdata;                                  //~v445I~
			    if (swebcwxpwk)                                    //~va81R~
                {                                                  //~va81I~
//                  ucvebc_a2bfld(0,xphandle,pcf,Gfilebuff,len);   //~va81R~//~vajfR~
//                  memcpy(Gfilebuff,pcf,len);                     //~vajfI~//~vb30R~
                    memcpy(Gfilebuff,pcf,(size_t)len);             //~vb30I~
		        	pcf=Gfilebuff;                                 //~va81I~
                }                                                  //~va81I~
            }                                                      //~v445I~
            if (UCBITCHK(plh->ULHflag2,ULHF2EXCLUDED))             //~v40kI~
            	continue;                                          //~v40kI~
//          if (*plh->ULHlineno)                                   //~v53eR~
//          {                                                      //~v53eR~
//          	memcpy(wklineno,plh->ULHlineno,(UINT)linenosz);    //~v53eR~
//  			if (UCBITCHK(plh->ULHflag,ULHFLINECMD))//line cmd input//~v53gR~
//              {                                                  //~v53gR~
//  				memset(wklineno,' ',(UINT)(linenosz-1));       //~v53gR~
//  				memcpy(wklineno,plh->ULHlinecmd,strlen(plh->ULHlinecmd));//~v53gR~
//              }                                                  //~v53gR~
//          }                                                      //~v53eR~
//          else                                                   //~v53gR~
//  	    if (plh->ULHtype!=ULHTDATA)	//file data                //~v53gR~
//          	memcpy(wklineno,plh->ULHlineno,(UINT)linenosz);    //~v53gR~
//          else                                                   //~v53gR~
//          	fileinitialeditlineno(pfh,plh,wklineno);           //~v53eR~
//          	fileeditlineno(Ppcw,pfh,plh,wklineno);             //~v53gR~
//          	fileeditlineno(Ppcw,pfh,plh,wklineno,linenoszw,FELN_SHIFT|FELN_SETCMD);//~v624R~
//          if (vhexmodesw)                                        //~v625R~
            if (vhexlineidsw)                                      //~v625I~
            {                                                      //~v624I~
	            if (plh->ULHtype==ULHTDATA) //file data            //~v624I~
    	            *wklineno='0';	//id of data line              //~v624I~
                else                                               //~v624I~
    	            *wklineno='*';	//id of not data line          //~v624I~
            }                                                      //~v624I~
//          fileeditlineno(Ppcw,pfh,plh,wklineno+vhexmodesw,linenoszw,FELN_SHIFT|FELN_SETCMD);//~v625R~
            fileeditlineno(Ppcw,pfh,plh,wklineno+vhexlineidsw,linenoszw,FELN_SHIFT|FELN_SETCMD);//~v625I~
			if (swebcwxpwk)                                        //~va81I~
            {                                                      //~va81I~
			    swebcwxpwk=1;                                      //~va81I~
//              ucvebc_a2bfld(0,xphandle,wklineno,wklineno,linenoszw+vhexlineidsw);//~va81R~//~vajfR~
            }                                                      //~va81I~
//          if (rc=filewrite(pfh,wklineno,(size_t)linenosz),rc)    //~v53gR~
//          if (rc=filewrite(pfh,wklineno,(size_t)linenoszw),rc)   //~v624R~
//          if (rc=filewrite(pfh,wklineno,(size_t)(linenoszw+vhexmodesw)),rc)//~v625R~
            if (rc=filewrite(pfh,wklineno,(size_t)(linenoszw+vhexlineidsw)),rc)//~v625I~
            	return rc;                                         //~v40hI~
//          pcf=plh->ULHdata;                                      //~v445R~
//          if (hexbinsw && pcf==Gfilebuff)                        //~v445I~//~va81R~
            if (hexbinsw                                           //~va81I~
            &&  plh->ULHtype==ULHTDATA) //file data                //~va81I~
            {                                                      //~va81I~
//  			len=filehexprint(Ppcw,plh);                        //~v445R~//~va81R~
				optxp=0;                                           //~va81I~
    	  		if (swebcwxpwk)                                    //~va81I~
                	optxp|=FHPO_WXPEBC;                            //~va81I~
    			len=filehexprint(optxp,Ppcw,pfh,plh);              //~va81I~
            }                                                      //~va81I~
#ifdef UTF8UCS2                                                    //~va20M~
            if (plh->ULHtype==ULHTDATA) //file data                //~va20I~
            {                                                      //~va20I~
			  if (swebcwxpwk)                                      //~va81I~
              {                                                    //~va81I~
            	rc=filecvwrite_ebcxpwk(0,pfh,pcf,(size_t)len);     //~va81I~
                if (rc==1)      	//eol(0x15) rep ocuured        //~va81R~
                	rc=0;                                          //~va81I~
              }                                                    //~va81I~
              else                                                 //~va81I~
              {                                                    //~va81I~
				cvwopt=saveopt;                                    //~va20R~
//          	rc=filecvwrite(cvwopt,pfh,plh,pcf,len,dbcswk,len); //~va20R~//~vb30R~
            	rc=filecvwrite(cvwopt,pfh,plh,pcf,(size_t)len,dbcswk,len);//~vb30I~
                if (rc==FCWRC_CVERR)                               //~va20I~
                {                                                  //~va20I~
    				if (igncverrsw)                                //~va20I~
                    {                                              //~va20I~
                    	rc=0;                                      //~va20I~
                    }                                              //~va20I~
                }                                                  //~va20I~
              }                                                    //~va81I~
            }                                                      //~va20I~
            else                                                   //~va20I~
            	rc=filewrite(pfh,pcf,(size_t)len);                 //~va20I~
            if (rc)                                                //~va20I~
#else                                                              //~va20M~
            if (rc=filewrite(pfh,pcf,(size_t)len),rc)              //~v40hI~
#endif                                                             //~va20M~
            	return rc;                                         //~v40hR~
    	  if (swebcwxpwk)                                          //~va81I~
          {                                                        //~va81I~
            if (rc=filewrite(pfh,EBC_NL_STR,1),rc)                 //~va81I~
                return rc;                                         //~va81I~
          }                                                        //~va81I~
          else                                                     //~va81I~
          {                                                        //~va81I~
            if (rc=filewrite(pfh,"\n",1),rc)                       //~v40hR~
                return rc;                                         //~v40hI~
          }                                                        //~va81I~
            wrtline++;                                             //~v40kI~
            if (vhexmodesw                                         //~v61wR~
            &&  plh->ULHtype==ULHTDATA) //file data                //~v61wI~
            {                                                      //~v61wI~
//  			filevhexprint(Ppcw,pfh,plh,wklineno,linenoszw);    //~v624R~
//  			filevhexprint(Ppcw,pfh,plh,wklineno,linenoszw+vhexmodesw);//~v625R~
//  			filevhexprint(Ppcw,pfh,plh,wklineno,linenoszw+vhexlineidsw);//~v625I~//~va81R~
				optxp=0;                                           //~va81R~
    	  		if (swebcwxpwk)                                    //~va81I~
                	optxp|=FVHPO_WXPEBC;                           //~va81R~
    			filevhexprint(optxp,Ppcw,pfh,plh,wklineno,linenoszw+vhexlineidsw);//~va81R~
	            wrtline+=2;                                        //~v61wI~
            }                                                      //~v61wI~
            if (Pplh2 && plh==Pplh2)    //partial write            //~v40hI~
                break;                                             //~v40hI~
		}//while plh                                               //~v40hI~
	}//prt scr                                                     //~v40hI~
	else                                                           //~v40hI~
//normal save ***************                                      //~v40hI~
	while(plh)								//all line
	{
		if (plh->ULHtype==ULHTDATA)	//file data
		{
		    if (xallsw) 	//write x line                         //~v54YR~
              if (nxallsw)                                         //~v57PI~
                	bandlesw=0;	//write                            //~v57PI~
              else                                                 //~v57PI~
				if (UCBITCHK(plh->ULHflag2,ULHF2EXCLUDED))         //~v54YI~
                	bandlesw=0;	//write                            //~v54YI~
                else                                               //~v54YI~
                	bandlesw=1;	//skip write                       //~v54YI~
            else                                                   //~v54YI~
            	if (nxallsw)                                       //~v54YR~
                {                                                  //~v54YI~
					if (UCBITCHK(plh->ULHflag2,ULHF2EXCLUDED))     //~v54YI~
    	            	bandlesw=1;	//skip write                   //~v54YI~
        	        else                                           //~v54YI~
            	    	bandlesw=0;	//write                        //~v54YI~
                }//nxallsw                                         //~v54YI~
          if (!bandlesw || UCBITCHK(plh->ULHflag4,ULHF4SELECTED))  //~v0ibI~
          {//not bandle used or selected at bandle use             //~v0ibI~
			++lineno;                                           //~5128R~
//  		if (!Poutfile)		//save to same file; update for grep//~v630R~
				plh->ULHlinenow=lineno;                         //~5128I~
//expand tab for not displayed line to drop tab                    //~v20vI~
//          if (droptabsw && !plh->ULHdbcs)	//not displayed        //~v436R~
            if (!plh->ULHdbcs)	//not displayed                    //~v436I~
              if (droptabsw || plh->ULHupctr) 	//updtaed          //~v436I~
        		if (filechktabdbcs(plh)==UALLOC_FAILED)//expand data len//~v20vI~
            		return UALLOC_FAILED;                          //~v20vI~
		  	len=plh->ULHlen;
			pcf=plh->ULHdata;                                   //~5130I~
			pcd=plh->ULHdbcs;	//dbcs/tab tbl                  //~5130I~
			if (cid)                                            //~5130R~
			{                                                   //~5130I~
                if (UCBITCHK(plh->ULHflag2,ULHF2SPLIT1|ULHF2SPLIT2))//~v0b9I~
                {                                                  //~v0b9I~
                    if (splitupctr<plh->ULHupctr)                  //~v0b9R~
	                    splitupctr=plh->ULHupctr;                  //~v0b9I~
	                if (UCBITCHK(plh->ULHflag2,ULHF2SPLIT1))//continued//~v0b9I~
                    {                                              //~v10zI~
	                    swfollow=1;		//bypass setcid            //~v0b9I~
                        splittotlen+=len;   //len up to prev line  //~v10zI~
                    }                                              //~v10zI~
	                else                                           //~v0b9I~
                    {                                              //~v0b9I~
	                    swfollow=2;		//restore upctr            //~v0b9I~
	                    splitupctrlast=plh->ULHupctr;              //~v0b9I~
	                    plh->ULHupctr=splitupctr;	//newest;      //~v0b9I~
                    }                                              //~v0b9I~
                }                                                  //~v0b9I~
                else                                               //~v0b9I~
                {                                                  //~v0b9I~
                	splitupctr=0;                                  //~v0b9I~
                    swfollow=0;			//call setcid              //~v0b9I~
                    splittotlen=0;  	//call setcid              //~v10zI~
                }                                                  //~v0b9I~
              if (swfollow!=1)			//not continued line       //~v0b9I~
//  			if (filesetcid(pfh,plh,Gfilebuff,Gfilebuff2,len,cid,&cidexplen)) //chng cid//~v014R~
//  			if (rc=filesetcid(pfh,plh,Gfilebuff,Gfilebuff2,cid,&cidexplen),rc) //chng cid//~v10zR~
    			if (rc=filesetcid(pfh,plh,Gfilebuff,Gfilebuff2,cid,&cidexplen,splittotlen),rc) //chng cid//~v10zI~
				{                                               //~5130I~
                	if (rc==UALLOC_FAILED)	//storage shortage  //~v04dI~
                    	return UALLOC_FAILED;	                //~v04dI~
					len+=cidexplen;                             //~5130I~
					pcf=Gfilebuff;	                            //~5130R~
					pcd=Gfilebuff2;		//dbcs tbl              //~5130R~
				}//sata copyed                                  //~5130I~
              if (swfollow==2)			//cont last line           //~v0b9I~
              {                                                    //~v10zI~
	            plh->ULHupctr=splitupctrlast;//restore             //~v0b9I~
                splitupctr=0;	                                   //~v10AI~
                splittotlen=0;                                     //~v10zI~
			  }	                                                   //~v10zI~
			}                                                   //~5130I~
//set updated line lineno of spf file                              //~v0czI~
			if ((spfsw//spf file                                   //~v42iR~
            &&  plh->ULHupctr   //updated                          //~v0czI~
            &&  !UCBITCHK(plh->ULHflag,ULHFCIDCLEAR) //update is cid clear only//~v0czR~
            &&  !UCBITCHK(plh->ULHflag4,ULHF4REPRENUM) //update is not renum only//~v71ZI~
            &&  !UCBITCHK(plh->ULHflag3,ULHF3SETSPFVER)) //update is ver set only//~v42iR~
			||UCBITCHK(plh->ULHflag4,ULHF4SETSPFVER2))//suffixoverflow//~v42iR~
            {                                                      //~v0czI~
                wlen=plh->ULHlen;   //save over filesetspfnum      //~v0czI~
                plh->ULHlen=len;    //may expanded                 //~v0czI~
                if (pcf!=Gfilebuff) //no cid added                 //~v0czI~
                {	                                               //~v0czI~
                	memcpy(Gfilebuff,pcf,(UINT)wlen);              //~v0czR~
					pcf=Gfilebuff;                                 //~v0czI~
//  				pcd=0;		//dbcs tbl                         //~va2cR~
                  if (!pcd)  //once expanded(when tabclear option,expanded at save before)//~va2cR~
                	memset(Gfilebuff2,0,(UINT)wlen);               //~va2cR~
                  else                                             //~va2cR~
                	memcpy(Gfilebuff2,pcd,(UINT)wlen);             //~va2cR~
    				pcd=Gfilebuff2;		//dbcs tbl                 //~va2cR~
                }                                                  //~v0czI~
//              filesetspfnum(pfh,plh,pcf,0,0);//no dbcs set,ver from pfh//~v71YR~
//              filesetspfnum(pfh,plh,pcf,0,SETSPFNUM_ATSAVE);//no dbcs set,ver from pfh//~v73bR~
//              filesetspfnum(pfh,plh,pcf,0,-1,SETSPFNUM_ATSAVE);//no dbcs set,ver from pfh//~va2cR~
                filesetspfnum(pfh,plh,pcf,pcd,-1,SETSPFNUM_ATSAVE);//no dbcs set,ver from pfh//~va2cR~
                len=spflen;                                        //~v0czI~
                plh->ULHlen=wlen;   //restore over filesetspfnum   //~v0czI~
            }                                                      //~v0czR~
//set updated line lineno of spf file                              //~v75pI~
//          if (len<fixlrecl)                                      //~v75pI~//~va68R~
            if ((len<fixlrecl)                                     //~va68I~
			&&  !swlrecladjust		//filecvwrite will expand      //~va68I~
            )                                                      //~va68I~
            {                                                      //~v75pI~
                if (pcf!=Gfilebuff) //no cid added                 //~v75pI~
                {                                                  //~v75pI~
                	memcpy(Gfilebuff,pcf,(UINT)len);               //~v75pI~
                  if (!pcd)  //once expanded(when tabclear option,expanded at save before)//~v78uR~
                	memset(Gfilebuff2,0,(UINT)len);                //~v78uM~
                  else                                             //~v78uM~
                	memcpy(Gfilebuff2,pcd,(UINT)len);              //~v75pI~
					pcf=Gfilebuff;      //write from Gfilebuff     //~v75pI~
					pcd=Gfilebuff2;		//dbcs tbl                 //~v75pI~
                }                                                  //~v75pI~
                wlen=fixlrecl-len;                                 //~v75pI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
                UCVEBC_memset_space(swebcfile,pcf+len,(UINT)wlen); //~va50I~
#else                                                              //~va50I~
                memset(pcf+len,' ',(UINT)wlen);                    //~v75pI~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
                memset(pcd+len,0,(UINT)wlen);                      //~v75pI~
                len+=wlen;                                         //~v75pI~
            }//fix lrecl                                           //~v75pI~
            else                                                   //~va6PI~
            if (fixlrecl>0 && len>fixlrecl)                                      //~va6PR~//~va6QR~
				swlrecladjust=1;		//wexpand if record mode at fsub//~va6PI~
                                                                   //~va6PI~
                                                                   //~v0czI~
		  if (!noeolsw)			//text mode                        //~v108R~
           if (!UCBITCHK(pfh->UFHflag10,UFHF10RECORD))	//not by the reason of Read Record Mode//~va6QI~
            if (UCBITCHK(plh->ULHflag4,ULHF4NOEOL))//has no eol    //~v103I~
				if (UGETQNEXT(plh)==UGETQEND(&pfh->UFHlineque))	//last data line//~v103I~
                	noeolsw=1;		//skip write eol               //~v103I~
//drop tab                                                         //~v20vI~
                                                                   //~v103I~
			do			//while(len)
			{
				pcw=pct=Gfilebuff;			//	write area
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
				dbcstblen=0;    //id of no dbcs data               //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
#ifdef UTF8SUPPH                                                   //~va1EI~
				pcdw=dbcswk;                                       //~va1EI~
#endif                                                             //~va1EI~
//  			if (UCBITCHK(plh->ULHflag2,ULHF2TABFOUND)//tab detected//~v70kR~
    			if ((UCBITCHK(plh->ULHflag2,ULHF2TABFOUND)//tab detected//~v70kI~
//  			     ||plh->ULHupundoctr!=0)              //once updated//~v71hR~
    			     ||(plh->ULHupctr!=0 && pcd))     //once updated,pcd chk is for safety//~v71hR~
				&&  !droptabsw	//no tab clear at save             //~v20vR~
				&&  !spfsw)//tab detected                          //~v0cwI~
                {                                                  //~va1EI~
//*change tab char for display to normal tab
//  				for(wlen=0;len;len--,pcf++,pcd++)              //~v102R~
    				for(wlen=0;len && wlen<MAXLINEDATA ;len--,pcf++,pcd++)//~v102I~
					{
//*no TABCHAR is set on dbcstbl of ebcfile                         //~va50I~
						if (*pcd==TABCHAR)                      //~5102R~
						{
							*pct++=TABCHAR;
							wlen++;
#ifdef UTF8SUPPH                                                   //~va1EI~
							*pcdw++=TABCHAR;                       //~va1EI~
#endif                                                             //~va1EI~
						}
						else
							if (*pcd!=TABPADCHAR)               //~5102R~
							{
								*pct++=*pcf;
								wlen++;
#ifdef UTF8SUPPH                                                   //~va1EI~
								*pcdw++=*pcd;                      //~va1EI~
#endif                                                             //~va1EI~
							}
//  					if (wlen==MAXLINEDATA)                     //~v102R~
//  						break;                                 //~v102R~
					}
#ifdef UTF8SUPPH                                                   //~va1EI~
//                	dbcstblen=(int)((ULONG)pcdw-(ULONG)dbcswk);    //~va1EI~//~vafkR~
                	dbcstblen=(int)((ULPTR)pcdw-(ULPTR)dbcswk);    //~vafkI~
#endif                                                             //~va1EI~
                }                                                  //~va1EI~
				else	//no tab
				{
					len-=(wlen=min(len,MAXLINEDATA));
					memcpy(pct,pcf,(UINT)wlen);
                    pcf+=wlen;  //next write data start         //~5107I~
#ifdef UTF8SUPPH                                                   //~va1EI~
					if (pcd)                                       //~va1EI~
                    {                                              //~va1EI~
						memcpy(pcdw,pcd,(UINT)wlen);	//for translation back//~va1EI~
                        dbcstblen=wlen;                            //~va1EI~
                    }                                              //~va1EI~
#endif                                                             //~va1EI~
				}
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
				opteol=0;                                          //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
				if (!len)
                if (!UCBITCHK(plh->ULHflag2,ULHF2SPLIT1))//not splitted rec//~v0aeI~
                if (!noeolsw)	//no skip eol write                //~v103I~
                {                                                  //~v0abI~
#ifdef FTPSUPP                                                     //~v71MI~
                  if (FILEISTSO(pfh))                              //~v71MI~
                  {                                                //~v71MI~
                    for (;wlen>0 && *(pcw+wlen-1)==' ';)           //~v71MR~
                    	wlen--;                                    //~v71MI~
                  }                                                //~v71MI~
#endif                                                             //~v71MI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
					opteol=FSOC_EOL1;                              //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
                  if (sweolebc)                                    //~va6DI~
					*(pcw+wlen++)=EBC_NL;                          //~va6DI~
                  else                                             //~va6DI~
                  if (wmacsw)                                      //~v47XI~
					*(pcw+wlen++)=0x0d;                            //~v47XI~
                  else                                             //~v47XI~
                  {                                                //~v47XI~
                  	if (wpcsw)                                     //~v0abI~
                    {                                              //~va50I~
						*(pcw+wlen++)=0x0d;                        //~v0abR~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
					opteol=FSOC_EOL2;                              //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
                    }                                              //~va50I~
					*(pcw+wlen++)='\n';
                  }                                                //~v47XI~
                }                                                  //~v0abI~

#ifdef UTF8SUPPH                                                   //~v92nI~//~va00R~
				cvwopt=saveopt;                                          //~v92nI~//~va00I~//~va0mR~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
				cvwopt|=opteol;                                    //~va50I~
				if (swlrecladjust)		//save to another file     //~va68R~
					cvwopt|=FSOC_ADJLRECL;	//adjust lrecl if record mode//~va68R~
                cvwopt|=FSOC_FILESAVE;  //write VHDR if recfm=V    //~vajbI~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//    		  	if (rc=filecvwrite(cvwopt,pfh,plh,pcw,(size_t)wlen),rc)//~v92nR~//~va00R~//~va1ER~
	  		  	if (rc=filecvwrite(cvwopt,pfh,plh,pcw,(size_t)wlen,dbcswk,dbcstblen),rc)//~va1EI~
#else                                                              //~v92nI~//~va00I~
	  		  	if (rc=filewrite(pfh,pcw,(size_t)wlen),rc)         //~v08qR~
#endif                                                             //~va00I~
  				{
//  				uerrmsg("%s write err",                        //~v08qR~
//duplicated				"%s 出力エラー",                       //~v08qR~
//msg by filewrite  		pfh->UFHfilename);                     //~v08qR~
#ifdef UTF8SUPPH                                                   //~va0mM~
  				  if (rc==FCWRC_CVERR)                             //~va0mM~
                  	cverr++;                                       //~va0mM~
                  else                                             //~va0mM~
#endif                                                             //~va0mM~
				  {                                                //~va0mI~
					if (!partialsw && !Poutfile)                   //~v08qI~
                    {                                              //~vazgI~
  				   	  if (rc==FCWRC_VOVF)	//Vfmt lrecl over      //~vazgI~
	    				uerrmsgcat("; %s may be corrupted, but original is saved as renamed file on the same dir.",//~vazgI~
    		           			"; %s は壊れていますが 元ファイルが別名で同じフォルダーに保存されています!",//~vazgI~
            	            	pfh->UFHfilename);                 //~vazgI~
                      else                                         //~vazgI~
	    				uerrmsg("%s write err(file incomplete),Save to other drive!",//~v13jR~
    		           			"%s 出力エラー(ファイルが不完全),他のドライブへ保存要!",//~v13jR~
            	            	pfh->UFHfilename);                 //~v08qI~
                    }                                              //~vazgI~
					if (Poutfile)                                  //~vazcR~
                    {                                              //~vaz8I~
                    	UTRACEP("filesave close by fwrite err fnm=%s\n",pfh->UFHfilename);//~vaz8I~
						fclose(pfh->UFHhfile);//bypass close err msg//~vazcR~
                    }                                              //~vaz8I~
  					UCBITON(pfh->UFHflag,UFHFWRITEERR);	//flag err//~5128R~
  					return rc;
                  }                                                //~va0mI~
  				}
			}while(len);
          }//not bandle used or selected at bandle use             //~v0ibI~
		}//ULHDATA                                                 //~v0ibR~
		if (Pplh2 && plh==Pplh2)	//partial write             //~5128I~
			break;                                              //~5128I~
		plh=UGETQNEXT(plh);
	}	
//  if (eline)	//write last half to temp or other file            //~v10YR~
    if (eline || xrangeswe)	//write last half to temp or other file//~v10YI~
    {                                                              //~vazsI~
    	optpc=FPCO_2ND;	//2nd part copy                            //~vazsI~
		if (!Poutfile)		//save to same file                    //~vazsI~
	    	optpc|=FPCO_SELF;	//save to original file            //~vazsI~
//    	if (filepartialcopy(1,Ppfh,pfh))//reopen pfh with "wb+" then copy//~vazsR~
      	if (filepartialcopy(optpc,Ppfh,pfh))//reopen pfh with "wb+" then copy//~vazsI~
        {                                                          //~v08qI~
  			UCBITON(pfh->UFHflag,UFHFWRITEERR);	//flag err         //~v08qI~
//			return 4;                                              //~v13jR~
//  		return filepartialouterr();                            //~vaz2R~
      		if (rc==8)    //not outfile openerr                    //~vaz5I~
            	return 8;                                          //~vaz5I~
    		return filepartialouterr(pfh);                         //~vaz2I~
		}                                                          //~v08qI~
    }                                                              //~vazsI~
//  fileeofwrite(pfh);				//write EOF                    //~v13jR~
  if (!(saveopt & FSOC_EOL_MAC))                                   //~v47XI~
    if (fileeofwrite(pfh))				//write EOF                //~v13jI~
    	return filecloseerr(pfh);                                  //~v13jI~
#ifdef UTF8SUPPH                                                   //~va0mI~
	if (cverr)	//trans err                                        //~va0mI~
    {                                                              //~va0mI~
      if (swebcfile		//from ebc                                 //~va50R~
      ||  (saveopt & FSOC_CPEB) //to ebc                           //~va50R~
      )                                                            //~va50I~
      {                                                            //~va5YI~
        uerrmsgcat("EBCDIC translation err.(%d/%d lines), replaced to substitution char. Profile will be updated by \"-%s\".",//~va50R~//~va5YR~
                	"EBCDIC 変換エラー(%d/%d)。代替文字に置換出力。\"%s\" オプションでプロファイルが更新されます",//~va50R~//~va5YR~
                	cverr,lineno,MODE_IE);                         //~va50I~//~va5YR~
      }                                                            //~va5YI~
      else                                                         //~va50I~
	  if (Gutfmode2 & GUM2_KEEPIFCVERR)   //cv err byte is kept untranslated//~va1EI~
        uerrmsgcat("%d/%d  lines contain invalid UTF8 code, error chars are written as it is if \"-%s\" option used.",//~va1ER~
                	"%d/%d行 UTF8変換エラー, \"-%s\"オプションを指定すればエラー文字はそのままで出力。",//~va1ER~
                	cverr,lineno,MODE_IE);                         //~va1EI~
      else                                                         //~va1EI~
        uerrmsgcat("translation err.(%d/%d), Use \"-%s\" option to ignore error.",//~va0mR~
                	"変換エラー(%d/%d)。,エラーを無視するには \"-%s\"オプションを指定する ",//~va0mR~
                	cverr,lineno,MODE_IE);                         //~va0mR~
    }                                                              //~va0mI~
#endif                                                             //~va0mI~
	if (Poutfile)		//other same file                       //~5128R~
    {                                                              //~v13jI~
      rc=                                                          //~v13jI~
		fileclose(pfh->UFHfilename,pfh->UFHhfile);              //~5128I~
	  	if (rc)                                                    //~v13jI~
	    	return filecloseerr(pfh);                              //~v13jI~
        else                                                       //~v13jI~
			pfh->UFHhfile=0;                                       //~v13jI~
#ifdef UNX                                                         //~v48cI~
		if (UCBITCHK(pfh->UFHflag5,UFHF5MDOS))//original is mdos disk//~v48cI~
        	rc=fileclose_mdos(pfh->UFHfilename,pfh->UFHalias);     //~v48cI~
#endif                                                             //~v48cI~
#ifdef UTF8SUPPH                                                   //~va0mI~
		if (cverr)	//trans err                                    //~va0mI~
    	{                                                          //~va0mI~
    		rc=12;                                                 //~va0mI~
    	}                                                          //~va0mI~
#endif                                                             //~va0mI~
#ifdef FTPSUPP                                                     //~v543R~
		if (!rc)                                                   //~v543R~
        {                                                          //~vaj0I~
	    	if (FILEISREMOTE(pfh))//remote output by rep/cre/save  //~v543R~
            {                                                      //~v57KI~
//      	    rc=xeftpsave(0,Ppcw,pfh);//0:no rep chk            //~v57KR~
            	if (appendremotesw)                                //~v57KI~
                	appendremotesw=XEFTPSO_APPEND;                 //~v57KI~
                appendremotesw|=XEFTPSO_DELTEMP;   //delete temp local file//~v710I~
                appendremotesw|=XEFTPSO_OUTFILE;   //not write to itself//~v72nI~
            	if (Pplh1||xallsw||nxallsw)          //rep/cre     //~v72nR~
                	appendremotesw|=XEFTPSO_OUTPARTIAL;            //~v72nR~
        		rc=xeftpsave(appendremotesw,Ppcw,pfh);             //~v57KI~
            }                                                      //~v57KI~
        	if (swcut)                                             //~vaj0I~
        		fileadjustfh4cut(FACO_PROFILE,Ppcw,pfh,0/*saveopt*/);//~vaj0I~
        }                                                          //~vaj0I~
#endif                                                             //~v543R~
	}                                                              //~v13jI~
    else                                                        //~5128I~
//!Poutfile                                                        //~v62nI~
	{                                                           //~5128I~
        rc=0;   //init                                             //~v62nI~
    	if (partialsw)                                             //~v08qI~
        {                                                          //~v08qI~
		    pelocalfnm=FILELOCALCOPYNAME(Ppfh);                    //~v546I~
          rc=                                                      //~v13jI~
			fileclose(pfh->UFHfilename,pfh->UFHhfile);//temp file  //~v08qR~
          	if (rc)                                                //~v13jI~
//  			return filepartialouterr();                        //~vaz2R~
    			return filepartialouterr(pfh);                     //~vaz2I~
//  		fileclose(Ppfh->UFHfilename,Ppfh->UFHhfile);//source file//~v546R~
    		fileclose(pelocalfnm,Ppfh->UFHhfile);//source file     //~v546I~
			Ppfh->UFHhfile=0;                                      //~v08qR~
#ifdef UNX                                                         //~v48cM~
		  if (UCBITCHK(Ppfh->UFHflag5,UFHF5MDOS))//original is mdos disk//~v48cI~
          {                                                        //~v48cI~
        	rc=fileclose_mdos(Ppfh->UFHfilename,pfh->UFHfilename);//mdos<=partial temp//~v48cI~
			uxdelete(Ppfh->UFHalias,FILE_NORMAL,UXDELNOMSG,        //~v48cI~
						&procctr,&procctr,&procctr);//mdos temp    //~v48cI~
          }                                                        //~v48cI~
          else                                                     //~v48cI~
          {                                                        //~v48cI~
#endif                                                             //~v48cM~
//  		rc=uxdelete(Ppfh->UFHfilename,FILE_NORMAL,UXDELNOMSG,  //~v546R~
    		rc=uxdelete(pelocalfnm,FILE_NORMAL,UXDELNOMSG,         //~v546I~
						&procctr,&procctr,&procctr);//source file  //~v08qR~
			if (rc)	//source delete faile                          //~v08qR~
				uxdelete(pfh->UFHfilename,FILE_NORMAL,UXDELNOMSG,  //~v08qI~
							&procctr,&procctr,&procctr);//del temp //~v08qI~
            else                                                   //~v08qI~
            {                                                      //~v57NI~
//  			rc=urename(pfh->UFHfilename,Ppfh->UFHfilename,0);  //~v546R~
    			rc=urename(pfh->UFHfilename,pelocalfnm,0);         //~v546I~
                if (rc)//rename mey fail if filesystem differed    //~v57NI~
                {                                                  //~v60fR~
                  rc=                                              //~v60fR~
                    uxcopy(pfh->UFHfilename,pelocalfnm,0,0);       //~v57NI~
                    if (!rc)                                       //~v60fR~
                    {                                              //~vazuI~
						ugeterrmsg();   //clear filesystem unmatch errmsg by urename//~v60fR~
						Ppfh->UFHelinepos=pfh->UFHelinepos;//next 2nd half pos//~vazuI~
                    }                                              //~vazuI~
                }                                                  //~v60fR~
                else                                               //~vazuI~
					Ppfh->UFHelinepos=pfh->UFHelinepos;//next 2nd harlf pos//~vazuI~
            }                                                      //~v57NI~
#ifdef UNX                                                         //~v48cI~
          }//not mdos disk partial                                 //~v48cI~
#endif                                                             //~v48cI~
        	pfh=Ppfh;//reopen source later                         //~v08qI~
            if (rc)                                                //~v08qI~
            {                                                      //~v08qI~
	  			UCBITON(pfh->UFHflag,UFHFWRITEERR);	//flag err     //~v08qI~
				return 4;                                          //~v08qI~
			}                                                      //~v08qI~
		}                                                          //~v08qI~
//  	pfh->UFHupctrsave=pfh->UFHupctr;		//upctr when saved //~v13jR~
	newsavesw=0;                                                   //~v53UI~
	if (UCBITCHK(pfh->UFHflag,UFHFNEW))			//new now          //~v0fqI~
    {                                                              //~v0fqI~
//  	UCBITOFF(pfh->UFHflag,UFHFNEW);		//not new now          //~v62nR~
	  if (!FILEISREMOTE(pfh))//win/gcc;setup alias for new file    //~v574I~
    	ufilesetfhfilename(pfh,pfh->UFHfilename);                  //~v0fqI~
        newsavesw=1;                                               //~v53UI~
	}                                                              //~v0fqI~
		if (!Pendsw)                                            //~5128I~
        {                                                          //~v13jI~
#ifdef UTF8SUPPH                                                   //~va0mI~
		  if (cverr)	//trans err                                //~va0mI~
    	  	filebkupreopen(FBRO_RESTORE,pfh,0,bkupfnm);		//delete bkup//~va0mI~
#endif                                                             //~va0mI~
		  if (UCBITCHK(pfh->UFHflag3,UFHF3RBIN))                   //~v0abI~
           fhreopen=                                               //~v13jR~
			filereopen(pfh,"rb");//once close and reopen           //~v0abI~
          else                                                     //~v0abI~
           fhreopen=                                               //~v13jR~
			filereopen(pfh,"r");					//once close and reopen//~5128R~
          if (!fhreopen)                                           //~v13jR~
	    	return filecloseerr(pfh);                              //~v13jI~
		}                                                          //~v13jI~
        else                                                       //~v13jI~
		  if (pfh->UFHhfile)  //if partial,already closed          //~v17gI~
          {                                                        //~v53UI~
			if (fileclose(pfh->UFHfilename,pfh->UFHhfile))         //~v13jI~
		    	return filecloseerr(pfh);                          //~v13jI~
          	else                                                   //~v13jI~
				pfh->UFHhfile=0;                                   //~v13jI~
#ifdef UTF8SUPPH                                                   //~va0mM~
			if (cverr)	//trans err                                //~va0mM~
    	  		filebkupreopen(FBRO_RESTORE,pfh,0,bkupfnm);		//delete bkup//~va0mM~
#endif                                                             //~va0mM~
          }//hfile                                                 //~v53UI~
    	  filebkupreopen(FBRO_DELETE,pfh,0,bkupfnm);		//delete bkup//~v76xI~
#ifdef UTF8SUPPH                                                   //~va0mM~
		if (cverr)	//trans err                                    //~va0mM~
    	{                                                          //~va0mM~
	    	return 18;                                             //~va0mI~
    	}                                                          //~va0mM~
#endif                                                             //~va0mM~
//  	pfh->UFHupctrsave=pfh->UFHupctr;		//upctr when saved //~v62nR~
#ifdef UNX                                                         //~v48cI~
//      rc=0;                                                      //~v62nR~
		if (UCBITCHK(pfh->UFHflag5,UFHF5MDOS))//original is mdos disk//~v48cR~
          if (!partialsw)                                          //~v48cI~
        	rc=fileclose_mdos(pfh->UFHfilename,pfh->UFHalias);     //~v48cI~
      if (!rc)                                                     //~v48cI~
      {                                                            //~v53UI~
#endif                                                             //~v48cI~
#ifdef FTPSUPP                                                     //~v543R~
		if (FILEISREMOTE(Ppfh))                                    //~v543R~
        	rc=xeftpsave(0,Ppcw,Ppfh);                             //~v57KR~
        if (!rc)//ftpsave rc                                       //~v54UI~
        {                                                          //~v54UI~
#endif                                                             //~v543R~
//      if (newsavesw || !Pendsw)   //new saved by save cmd        //~v719R~
    	setfstatsw=(newsavesw || !Pendsw);  //new saved by save cmd//~v719I~
#ifdef FTPSUPP                                                     //~v719I~
    	if (UCBITCHK(Ppfh->UFHflag7,UFHF7TSO))	//tso bin mode is explicitly by cmd operand to save same mode//~v719I~
            setfstatsw=1;   //setlocal fstat to update dirlist     //~v719I~
#endif                                                             //~v719I~
        if (setfstatsw)                                            //~v719I~
        {                                                          //~v543R~
#ifdef FTPSUPP                                                     //~v716I~
    	 if (UCBITCHK(Ppfh->UFHflag7,UFHF7TSO)	//spf info exist,it was updated tspspfupdate//~v72nI~
         &&  (Ppfh->UFHattr & FILE_SPF))                           //~v72nI~
         {                                                         //~v72nI~
			xetsodlcmdsetlocal(pfc,0,Ppfh);	//pdh=0,get by pfc if enqued tp dirlist//~v72nI~
         }                                                         //~v72nI~
         else                                                      //~v72nI~
         {                                                         //~v72nI~
    	  if (UCBITCHK(Ppfh->UFHflag7,UFHF7TSO))	//tso bin mode is explicitly by cmd operand to save same mode//~v716I~
          {                                                        //~v719I~
            memset(&fstat3,0,sizeof(fstat3));                      //~v719I~
//          fstat3.attrFile=Ppfh->UFHattr;  //xetsolocalfstat do reverse operation//~v72nR~
            rc=(int)xetsolocalfstat(Ppfh,&fstat3);                 //~v716I~
          }                                                        //~v719I~
          else                                                     //~v716I~
#endif                                                             //~v716I~
            rc=(int)ufstat(Ppfh->UFHfilename,&fstat3);             //~v54UR~
            if (!rc)                                               //~v543R~
            {                                                      //~v719I~
                filesetfstat(Ppfh,&fstat3);                        //~v543R~
#ifdef FTPSUPP                                                     //~v719I~
    	  		if (UCBITCHK(Ppfh->UFHflag7,UFHF7TSO))	//tso bin mode is explicitly by cmd operand to save same mode//~v719I~
					xetsodlcmdsetlocal(pfc,0,Ppfh);	//pdh=0,get by pfc if enqued tp dirlist//~v719I~
#endif                                                             //~v719I~
            }                                                      //~v719I~
#ifdef FTPSUPP                                                     //~v72nI~
    	 }//TSO & SPF                                              //~v72nI~
#endif                                                             //~v72nI~
        }                                                          //~v543R~
//      if (!rc)                                                   //~v54UR~
//      {                                                          //~v54UR~
		if (!UCBITCHK(Gprocstatus,GPROCSTERM))//not CB at termination//~5228I~
        {                                                          //~v53UI~
          if (eolchngid)                                           //~v47LR~
           if (swupdate)                                           //~va6QI~
			uerrmsg("%s was save by %s EOL id",                    //~va6QI~
					"%s を %s 行末IDで保管",                       //~va6QI~
					pfh->UFHfilename,eolchngid);                   //~va6QI~
           else                                                    //~va6QI~
           {                                                       //~vaj0I~
           if (modechng)                                           //~vaj0I~
			uerrmsg("%s is not updated,but save as %s",            //~vaj0I~
					"%s 未更新ファイルを %s で保存",               //~vaj0I~
					pfh->UFHfilename,eolchngid);                   //~vaj0I~
           else                                                    //~vaj0I~
			uerrmsg("%s is not updated,but save by %s EOL id",     //~v47TR~
					"%s 未更新ファイルを %s 行末IDで保存",         //~v47TR~
					pfh->UFHfilename,eolchngid);                   //~v47LR~
           }                                                       //~vaj0I~
          else                                                     //~v47LI~
          {                                                        //~v53UI~
#ifdef FTPSUPP                                                     //~v53UI~
			if (pfh->UFHtype==UFHTHOSTS)	//ftp hosts file       //~v53UI~
            	uerrmsg("FTP hosts data updated",                  //~v53UI~
						"ホストテーブルを更新しました");           //~v53UI~
            else                                                   //~v53UI~
#endif                                                             //~v53UI~
//  		uerrmsg("%s was Saved",                             //~5228R~//~vb7nR~
//  				"%s は保管されました",                      //~5228R~//~vb7nR~
    		uerrmsg("Saved:%s",                                    //~vb7nI~
    				"保管されました:%s",                           //~vb7nI~
					pfh->UFHfilename);                          //~5228R~
          }                                                        //~v53UI~
        }//gprocsterm                                              //~v53UI~
        pfh->UFHupctrsave=pfh->UFHupctr;        //upctr when saved //~v62nI~
    	UCBITOFF(pfh->UFHflag,UFHFNEW);		//not new now          //~v62nI~
        if (pfh->UFHtype==UFHTCLIPBOARD)	//clipboard saved      //~va20I~
			capcbstatw(0,Ppcw,pfh);			//update ::cb filestatus//~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
//  	if (Pendsw & FSENDSW_END)                                  //~va50R~//~va7tR~
    	if (Pendsw & FSENDSW_END                                   //~va7tI~
        ||  !Poutfile 		//same file, update at fileout if filename specified//~va7tR~
        )                                                          //~va7tI~
        {                                                          //~va7LI~
//      	if (saveopt & (FSOC_CPLC|FSOC_CPU8|FSOC_CPEB))         //~va50I~//~va6QR~
        	if (saveopt & (FSOC_CPLC|FSOC_CPU8|FSOC_CPEB|FSOC_EOL_OPT))//~va6QI~
            {                                                      //~va6QI~
//  			fileupdateprofilesave(0,Ppcw,pfh,saveopt,pfh->UFHfilename);//~va50I~//~va66R~
//  			fileupdateprofilesave(0,Ppcw,pfh,saveopt,pfh->UFHfilename,0);//~va66I~//~va6QR~
//  			fileupdateprofilesave(optprof,Ppcw,pfh,saveopt,pfh->UFHfilename,0);//~vaj0R~
    			fileupdateprofilesave(optprof,Ppcw,pfh,saveopt,pfh->UFHfilename,lreclparm);//pass /MR:lrecl+margin,/MV:vfmt//~vaj0I~
            }                                                      //~va6QI~
            else                                                   //~va7LI~
            if (UCBITCHK(pfh->UFHflag11,UFHF11EBCSETCP)            //~va7LI~
            &&  pfh->UFHhandle!=pfh->UFHhandleorg)                 //~va7LI~
				fileupdateprofile(FUPO_RCMD,Ppcw,pfh);             //~va7LI~
        }//END to itself                                           //~va7LI~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
#ifdef FTPSUPP                                                     //~v53UI~
        }//xeftpsave !rc                                           //~v543R~
#endif                                                             //~v53UI~
#ifdef UNX                                                         //~v53UI~
	  }//mdos !rc                                                  //~v53UI~
#endif                                                             //~v53UI~
//!Poutfile                                                        //~v62nI~
	}                                                           //~5128I~
//  if (spfsw)                                                     //~v@@@R~
//  	if (UCBITCHK(Gopt3,GOPT3TESTEXIT|GOPT3TESTABEND))//abend by double Esc//~v@@@R~
//  	    uerrexit("tab will clear at save",0);                  //~v@@@R~
//  return 0;                                                      //~v62nR~
    return rc;                                                     //~v62nI~
}//filesave
//***************************************************************************//~vaj0M~
//*adjust save to CB2 of CUT cmd                                   //~vaj0M~
//***************************************************************************//~vaj0M~
int fileadjustfh4cut(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh,int Psaveopt)//~vaj0R~
{                                                                  //~vaj0M~
//***********************************                              //~vaj0M~
	if (Popt & FACO_OPEN)	//from fileload                        //~vaj0I~
    {                                                              //~vaj0I~
//  	Ppfh->UFHtype=UFHTCLIPBOARD2;  //*** keep UFHtype=0 to save to profile//~vaj0I~
    }                                                              //~vaj0I~
    else                                                           //~vaj0I~
	if (Popt & FACO_PROFILE)	//update profile                   //~vaj0I~
    {                                                              //~vaj0I~
		fileupdateprofilesave_cut(0,Ppcw,Ppfh);                    //~vaj0I~
    }                                                              //~vaj0I~
    else	//from filesave                                        //~vaj0R~
    {                                                              //~vaj0I~
        if (UCBITCHK(Ppfh->UFHflag13,UFHF13RV))                    //~vaj0R~
        {                                                          //~vaj0R~
            if (Ppfh->UFHvfmt==UFGETS_VFMT_MFH2                    //~vaj0R~
            ||  Ppfh->UFHvfmt==UFGETS_VFMT_MFH4)                   //~vaj0R~
                Ppfh->UFHvfmt=UFGETS_VFMT_DEFAULT;  //rdw          //~vaj0R~
            UCBITON(Ppfh->UFHflag13,UFHF13WV);      //for the case open by -Mvx//~vaj0I~
            UCBITOFF(Ppfh->UFHflag11,UFHF11WRECORD);               //~vaj0I~
        }                                                          //~vaj0R~
        else                                                       //~vaj0I~
        if (UCBITCHK(Ppfh->UFHflag10,UFHF10RECORD))                //~vaj0I~
        {                                                          //~vaj0I~
            UCBITON(Ppfh->UFHflag11,UFHF11WRECORD);	//for the case open by -Mrx//~vaj0I~
            UCBITOFF(Ppfh->UFHflag13,UFHF13WV);                    //~vaj0I~
        }                                                          //~vaj0I~
        else                                                       //~vaj0I~
        {                                                          //~vaj0I~
            UCBITOFF(Ppfh->UFHflag11,UFHF11WRECORD);	//for the case open by -Mxv/-Mxr//~vaj0I~
            UCBITOFF(Ppfh->UFHflag13,UFHF13WV);                    //~vaj0I~
        }                                                          //~vaj0I~
	    *Ppfh->UFHcid=0;	//no cid                               //~vaj0I~
	    Ppfh->UFHcidtype=UFHCIDTYPEERR;                            //~vaj0I~
		Ppfh->UFHwidth=0;   //force line width=999                 //~v10FI~//~vaj0I~
        UCBITOFF(Ppfh->UFHflag,UFHFCIDON);                         //~vaj0I~
        UCBITON(Ppfh->UFHflag,UFHFCIDOFF);                         //~vaj0I~
    }                                                              //~vbmjR~
    strncpy(Ppfh->UFHalias,CUTCMD_2NDCBFNM,sizeof(Ppfh->UFHalias)-1);  //~5224I~//~vaj0I~//~vbmjI~
    UCBITON(Ppfh->UFHflag13,UFHF13CB2);                            //~vaj0I~
    return 0;                                                      //~vaj0M~
}//adjustfh4cut                                                    //~vaj0M~
//**************************************************************** //~v13jI~
//*parm :close err                                                 //~v13jI~
//*rc   :4                                                         //~v13jI~
//**************************************************************** //~v13jI~
int filecloseerr(PUFILEH Ppfh)                                     //~v13jI~
{                                                                  //~v13jI~
  	UCBITON(Ppfh->UFHflag,UFHFWRITEERR);	//flag err             //~v13jI~
    uerrmsg("%s Close failed(disk space shortage?),Save to other drive!",//~v13jR~
            "%s クローズ失敗(ディスクスペース不足?),他のドライブへ保存要!",//~v13jR~
            Ppfh->UFHfilename);                                    //~v13jR~
	return 4;                                                      //~v13jI~
}//filecloseerr                                                    //~v13jI~
//**************************************************************** //~v13jI~
//*parm :close err                                                 //~v13jI~
//*rc   :4                                                         //~v13jI~
//**************************************************************** //~v13jI~
//int filepartialouterr(void)                                      //~vaz2R~
int filepartialouterr(PUFILEH Ppfh)                                //~vaz2I~
{                                                                  //~v13jI~
    char *pfnm;                                                    //~vaz2I~
//*******************                                              //~vaz2I~
//  uerrmsg("Output to temp file for partial edit failed.(no space?).Save to other drive!",//~vaz2R~
//          "部分編集のための一時ファイルの出力エラー(スペース不足?),他のドライブへ保存要!");//~vaz2R~
    pfnm=Ppfh->UFHfilename;                                        //~vaz2R~
    uerrmsg("Output to temp file(%s) for partial edit failed.(no space?).Save to other drive!",//~vaz2I~
            "部分編集のための一時ファイル(%s)の出力エラー(スペース不足?),他のドライブへ保存要!",//~vaz2I~
            pfnm);                                                 //~vaz2I~
	return 4;                                                      //~v13jI~
}//filepartialouterr                                               //~v13jI~
//**************************************************************** //~vaziI~
//*chk header record validity for RECFM=V fmt=MFH                  //~vaziI~
//**************************************************************** //~vaziI~
int chkmfhheader(PUFILEH Ppfh,int Ppartialsw)                      //~vaziI~
{                                                                  //~vaziI~
    int rc=0,len=0,lenok=0;                                        //~vaziR~
    char vfmt,*pfmttype=0;                                         //~vaziR~
    PULINEH plh;                                                   //~vaziR~
//*******************                                              //~vaziI~
    vfmt=Ppfh->UFHvfmt;                                            //~vaziI~
    if (vfmt==UFGETS_VFMT_MFH2 || vfmt==UFGETS_VFMT_MFH4)          //~vaziI~
    {                                                              //~vaziI~
		if (!(Ppartialsw && (Ppfh->UFHsline || Ppfh->UFHslinepos)))	//did not contains header record//~vaziR~
        {                                                          //~vaziI~
			plh=UGETQTOP(&Ppfh->UFHlineque);		//top entry    //~vaziR~
        	plh=UGETQNEXT(plh);                                    //~vaziI~
        	len=plh->ULHlen;                                       //~vaziI~
		    if (vfmt==UFGETS_VFMT_MFH2)                            //~vaziI~
            {                                                      //~vaziI~
            	lenok=0x7e;                                        //~vaziI~
                pfmttype="MaxLRECL<4096";                          //~vaziI~
            }                                                      //~vaziI~
            else                                                   //~vaziI~
            {                                                      //~vaziI~
            	lenok=0x7c;                                        //~vaziI~
                pfmttype="MaxLRECL>=4096";                         //~vaziI~
            }                                                      //~vaziI~
            if (len!=lenok)                                        //~vaziI~
	        	rc=4;                                              //~vaziI~
        }                                                          //~vaziI~
    }                                                              //~vaziI~
    if (rc)                                                        //~vaziI~
        uerrmsg("Header record length error(%d!=%d(type=%s)) for MicroFocus RECFM=V File",//~vaziR~
        		"MicroFocus RECFM=V ファイルのヘッダーレコード長(%d)エラー(!=%d(type=%s))",//~vaziR~
            	len,lenok,pfmttype);                               //~vaziR~
    UTRACEP("chkmfheader rc=%d,len=%d\n",rc,len);                  //~vaziR~
    return rc;                                                     //~vaziI~
}//chkmfhheader                                                    //~vaziI~
