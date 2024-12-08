//CID://+vbBuR~:                                      Update#=  353//~vbBuR~
//****************************************************************
//xefile.h                                                         //~v10LR~
//****************************************************************
//vbBu:241119 Edit/Browse /Mz option for ebc file to accept 0x0d15 as EOL//~vbBuI~
//vby6:230402 (ARM)adjust by4; go around by shortname and change to uri at ulib(ufile1l)//~vby6I~
//vby4:230402 (ARM)shared resource support by //shareName defined by SP(ShortPath) cmd.//~vby4I~
//vbv9:221124 add cid type apl for extension=.apl                  //~vbv9I~
//vbv6:221121 support unicode cid (length>2)                       //~vbv6I~
//vbr3:200620 ARM:sdcard permission chk                            //~vbr3I~
//vbi3:180211 supprt command history list                          //~vbi3I~
//vb88:170216 stop lcmd "i" continue mode by cut&paste             //~vb7kI~
//vb7k:170115 dir list;gree attr overflow to "=Rep" when dirname is too long//~vb7kI~
//vb2n:160201 (W32)use FN{LC|U8} option translate input filename u8<-->lc regardless A+u kbd mode(like as (LNX)b2j)//~vb2nI~
//vb2h:160129 display filename encoding type on hdr/trailer linet at ufcleft//~vb2hI~
//vb2g:160124 Select dcmd accept mount option if FN{U8|LC} was not specified//~vb2gI~
//vb2e:160122 (LNX)convert filename according IOCHARSET mount option//~vb2eI~
//vb06:150313 (BUG)others for "\\.\"; change strategy(del vb03 to vb05),set to UFHfilename without \\.\ ;//~vb06R~
//vazt:150114 (BUG)"UCHAR UFHpathlen" is invalid when _MAX_PATH>256//~vaztI~
//vaz0:150105 BUG:offset value is long long for fseek error msg    //~vaz0I~
//vava:140410 (Win)unicode support(UD fmt string)                  //~vavaI~
//vav2:140401 (BUG)on UNC dirlist,localte cmd fail by invalid path //~vav2I~
//vauA:140315 (BUG)u8 membername on dir list by fnu8 option,but fhfilename is treated by lc by env:lc on windows//~vauAI~
//            support select lcmd but not for Select cmd(may specify path, so use FNU8 cmd option for select cmd)//~vauAI~
//vau7:140303 keep ddfmt on pfh(yet remains dbcs and lcname)       //~vau7I~
//vaj0:130710 localfile:recfm=V support (E /mV F{MFH|F|H})         //~vaj0I~
//vagE:120918 apply cmdline option /U{N|F}{8|L} to also edit/browse cmd//~vagEI~
//vag2:120811 REDo suupport                                        //~vag2I~
//vag1:120724 (Axe)warning no write permisson from unod for sdcard(permission 075)//~vag1I~
//		      sdcard group is sdcard_rm and manifest permission set application groupid to it//~vag1I~
//vafk:120624 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  use ULPTR(unsigned __int64/ULONG)//~vafkI~
//vac1:120204 (SMB)smb node support                                //~vac1I~
//va8w:101209 SPLIT/TFLOW:delete so/si when join dbcs string       //~va8wI~
//va87:100924 (WXE)wxp cmd;**/*** vhex print corespondency of upper and lower line//~va87I~
//va7L:100905 undo support for EBC SETCP cmd                       //~va7LI~
//va7A:100829 (WXE:EBC)handle support for mouse cap                //~va7AI~
//va79:100809 cpeb converter parm support                          //~va79I~
//va6Q:100722 Fxx+/MxR is output lrecl and not input lrecl         //~va6QI~
//va6N:100721 add eol when /mET                                    //~va6NI~
//va6D:000719 EBC eol 0x15 support                                 //~va6DI~
//va6r:000623 flag for menuopt a/b/c for ligature chk              //~va6rI~
//va6c:100619 add SOSI option -S{i|r|d} to REP/CRE/APP/SAV cmd     //~va6cI~
//va5s:100514 display hdr line filename by dd fmt                  //~va5sI~
//va5e:100510 drop eol by /mpr                                     //~va5eI~
//va51:100415 Record mode file option                              //~va51R~
//va50:100324 Raw EBCDIC file support for NFS mount                //~va50I~
//va20:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~va20I~
//va1B:091112 (UTF8)hdrline codetype ftrom cmd buff if avail       //~va1BI~
//va1e:091101_(UTF8) retry by lc for f2l err at load if no CPU8 option specified//~va1eI~
//va0C:090721_set wxp work CPxx to the same as source file         //~va0CI~
//va00:090510 merge utf8 version(enclosed by UTF8SUPPH)            //~va00I~
//          linedata is locale encoding                            //~va00I~
//          header line filename cv f2l                            //~va00I~
//          save CPxx to profile                                   //~va00I~
//          Copy:CPxx option  COPy/MOVe fnm [CPU8] [IE]            //~va00I~
//          Edit/Browse [CPLC|CPU8|CPAS|] [IE]                     //~va00I~
//          ignore translation err for utility result file(parm to edit_file2)//~va00I~
//v79U:081028 CID append mode                                      //~v79UI~
//v79y:080915 (BUG)syntaxh position invalid when copy line between different tabctr//~v79yI~
//v79e:080818 (BUG)remains csr pos reverse when Hhex+Vhex display mode//~v79eI~
//v8@M:080707 3270:convert to uppercase for =6.TSO panel           //~v8@MI~
//v78S:080606 continuede insert line mode by lcmd "i"              //~v78SI~
//v8@2:080529 save tabctr in profile                               //~v8@2I~
//v78y:080413 performance down by v74r("del x all" is slow)        //~v78yI~
//v78r:080326 profile function                                     //~v78rI~
//v786:080301 (SYNH)"ENTERU":update line only option               //~v786I~
//v780:080212 syntaxhighlight support                              //~v780I~
//v90j:071021 (BUG) full-draw by lineno size change when split scr(sholuld chk for each file)//~v90jI~
//v76z:070820 no bkup option to bypass rename at save              //~v76zI~
//v76m:070627 find support on =1/=2 filename list panel            //~v76mI~
//v75F:070508 (BUG of v61a)cols type is reset to default after S+F11 twice(off+on)//~v75FI~
//            force to default only when operand specified(not toggle case)//~v75FI~
//v75f:070423 SPL/TFLOW:correct err line counter                   //~v75fI~
//v74E:070315 BOUNDS cmd support                                   //~v74EI~
//v745:070209 (BUG)lcmd matching err csr postion err when UFCleft!=0//~v745I~
//v731:061226 filesize>4GB support                                 //~v731I~
//v72B:061205 3270:like rsh,use =6 panel as TSO terminal screen "tso "tostid TSO"/Exit//~v72BI~
//v72n:061127 3270:spf cmd to update spf info                      //~v72nI~
//v72d:061123 (BUG)reversed csr pos on guage line is not reset by csr move for 2nd split screen//~v72dI~
//v71Z:061114 v71Y miss set version number in the following case   //~v71VI~
//            for SPF err file opened by en,update then "renum force" because SPFNUMOK set by renum at undo.//~v71VI~
//v71V:061113 add tabclear option to edit cmd. TC|NTC. set TC on if -F specified.//~v71VI~
//v71K:061103 NONUM option for TSO SPF file(reset dfault num fld)  //~v71KI~
//v71H:061103 (3270)for RECFM=F,set UFHlrecl                       //~v71HI~
//v70z:060904 3270 ftp support                                     //~v70zI~
//v70c:060731 (WXEXXE:BUG)cb is not written by the reason of file updated from read time by the other process. and alloc area not freed at termination.//~v70cI~
//v69J:060712 cap(CAPS LOCK On) support                            //~v69JI~
//v690:060418 display file-description support on dir-list panel   //~v690I~
//v66e:051020 support standard mode cut & paste;                   //~v66eI~
//            A+F6/A+v:range specification, A+F9:copy, A+Ins:paste Ins, A+F8:paste Rep, C+v:paste Del then Ins//~v66eI~
//            Del/BackSpace:delete range, A+Del:del+copy to clipboard//~v66eI~
//v632:050427 find cmd;support grepline search by *G               //~v632I~
//v630:050426 grep support  as dos cmd(for edit screen flag line and search by rfind for *L)//~v630I~
//v62x:050402 cmd line parameter /Lnn : initial Locate cmd(/L is listdir option)//~v62cI~
//v62c:050312 multireverse option by single foundctr(continuous chk is no problem)//~v62cI~
//v62b:050312 for -m[n] option of find cmd;assign mfwtbl for each pfh to avoid copy and copyback each time//~v62bI~
//v62a:050311 -m option of find cmd to keep previous reverse       //~v62aI~
//v621:050308 (WXE:BUG)scr-resize dose not reset dirlist expanded for not current displayed page//~v621I~
//v60v:050201 virtual hex display option(/Mx,HEX on/off)           //~v60vI~
//v60s:050130 support display width change without close current opened//~v60sI~
//v60j:050129 (BUG)csr pos is invalid for pair/same search after tabctr changed//~v60jI~
//            same thing is for all filechktabdbcs user;so reset at tabctr change time//~v60jI~
//v59T:041207 dirlist resizeing                                    //~v59TI~
//v59g:041107 rsh:set MOCMD screen as rlogin                       //~v59gI~
//v585:040823 cap performance up;skip save undo data and clear all undo data when clear cb//~v585I~
//v57H:040612 (BUG)tc cmd;no err set if one of two opd is valid for 2 opd type//~v57HI~
//v576:040513 (FTP:BUG)if u edit same filename except case,        //~v576I~
//            another file name is  save back to remote.so use tempdir//~v576I~
//v56r:040410 (BUG)column field "(",")" is cleared by wakeup       //~v56rI~
//v55P:040318 (UNX)update permission warning                       //~v55PI~
//v558:040204 new func:path up/down by A+left/right                //~v558I~
//v54R:040125 find cmd:max record pos search by max pos parm       //~v54RI~
//v54y:040118 (WXE)wxp cmd support(send file to wxe for print by wxe)//~v54yI~
//v54p:040106 (FTP)uftpisremote interface changed                  //~v54pI~
//v54m:040105 (FTP)update dir list file time when once browsed     //~v54mI~
//v54f:040104 (FTP)DIR_SEPx for ftp                                //~v54fI~
//v54d:040103 split xefile.c to xefile.c xefile14.c                //~v54dI~
//v542:031223 (WIN,UNX)remote file edit/save                       //~v542I~
//v540:031223 (WIN,UNX)set dir sepc on ufh                         //~v540I~
//v53U:031109 (WIN,UNX)ftp support                                 //~v53UI~
//v53Q:031103 ftp support(4 byte udirlist attr for ! UNX);ulib:v59e//~v53QI~
//v53d:030923 option seti/setr without renum                       //~v53dI~
//v523:030817 expand max dir lcmd 40-->200 for not DOS native      //~v51qI~
//v51q:030607 option to browse ebcdic file                         //~v51qI~
//v50t:030112 (BUG)mac eolid=4 but eollen=1,offset calc miss       //~v50tI~
//v496:020617 find *L (search lineserch result;for after == lcmd)  //~v496I~
//v48c:020429 (UNX)edit/browse mdos disk support                   //~v48cI~
//v47X:020413 mac file support(eol=0x0d)                           //~v47XI~
//v47L:020330 do save of not updated file if eol-id chnge specified//~v47LI~
//v447:011201 (BUG)abend when cols type over 3 byte                //~v447I~
//v440:011125 browse hex                                           //~v440I~
//v42v:011009 option to allow cob num fld is all space             //~v42vI~
//v42r:011009 (BUG)num clear ignored at save                       //~v42rI~
//v42i:011002 set spfnum at save for suffix overflow line to avoid line update flag(*u search)//~v42iI~
//v41q:010830 no split msg when out of line range for partial file edit//~v41qI~
//v414:010728 EC/ENC/BC/BNC/SC/SNC cmd add for cobol               //~v414I~
//v40F:010709 COB support:num clear(clear col72-80)                //~v40FI~
//v40E:010709 COB support:renum                                    //~v40EI~
//v40D:010709 COB support:cid tobcob                               //~v40DI~
//v40A:010707 LINUX:mdir support                                   //~v40AI~
//v40u:010617 wild-card support for path name if dir contain only one member.//~v40uI~
//            (replace v143)                                       //~v40uI~
//v40p:010603 add x *= (exclude same as above line)                //~v40pI~
//v40f:010522 AIX support:no pragma pack supported                 //~v40fR~
//v20v:001022 topcid line option to tab clear when file output     //~v20vI~
//v20t:001022 Source update ctr support on CID line                //~v20tI~
//v19X:000928 LINUX support(save uid/gid on UFILEH/UDIRH)          //~v19XI~
//v19W:000928 LINUX support(4 bye attr for also UFILEH)            //~v19WI~
//v190:000902 LINUX support(CRLF)                                  //~v190I~
//v185:010128 browse/edit file when only one menmber of dir is optional by /l option(dir list)//~v20vI~
//v13d:991023 *\ support for filecmd(save/repl/create/append/copy/move/ini)//~v11NI~
//v11N:990829 COL cmd support                                      //~v11NI~
//v11z:990821 support filename=* (last closed file) on cmd line    //~v11zI~
//v11x:990821 support "CD *";set to current file directory         //~v11xI~
//v10Y:990606 support input range by hex offset value(/NXxxx-Xxxx) for edit/browsw cmd//~v10YI~
//v10X:990605 hex digit lineno display for binary file             //~v10LR~
//v10L:990424 EN/BN/SN edit/browse command for SPF file specific.(No cid,margin=72,P=1)//~v10LR~
//v10k:990322 (BUG)after select cmd for new file on dirlist,end with no update//~v10kI~
//            or cancel update file cause deletion of parent dir plh.//~v10kI~
//            So locate cmd faile and move csr to last entry.      //~v10kI~
//v10e:981218 e/b cmd display width parm for bin file              //~v10eI~
//v10c:981218 if explicitly text mode specified,request no optbin  //~v107I~
//v107:981213 use new opt of ufgetsinit for binary chk(del filechkbin)//~v107I~
//v103:981212 (BUG)for binaly file edit,last 0d0a is added         //~v103I~
//            0d0a is added at end of file eveif input has no 0d0a //~v103I~
//            skip add only when thatline is at end of file,if moved to other//~v103I~
//            position,\d0a is added.                              //~v103I~
//v0im:980625 pfk cmd support(optk1 and optk2)                     //~v0imI~
//v0if:980620 pfk cmd support                                      //~v0ifI~
//v0ib:980530 v0i9 cotinued for other than file copy               //~v0ibI~
//v0ia:980530 add APPend cmd                                       //~v0iaI~
//v0hf:980130 performance tuning                                   //~v0hfI~
//            draw only after deleted/inserted line                //~v0hfI~
//v0fq:971109 new file by select cmd has alias but it is temporary name//~v0fqI~
//            it may duplicated alias name.                        //~v0fqI~
//            dont created new pdh if new,isrt at end file if new file.//~v0fqI~
//v0fc:971018 vfat flag should be on ufh not but ufc because uddname created by it//~v0fcI~
//v0fb:971018 UFHshortname for W95/GCC for path display on dirlist //~v0fbI~
//v0f9:971017 UFCFLFN flag for lfn(common to os2/w95/gcc/dos)      //~v0f9I~
//v0f0:971010 long filename support                                //~v0f0I~
//            file.h    ;maxfilename,fs=hpfs drive id              //~v0f0I~
//v0eq:970920 optionaize to update oom.default is prohibit         //~v0eqI~
//v0du:970909 for performance,use flag once chked spfnumok         //~v0duI~
//            set on when chked,reset when line update or insert.  //~v0duI~
//v0dr:970908 change flag SPFNUMOK+SPFNUMERR-->SPFNUM,drop SPFNUMOK//~v0drI~
//v0d7:970831 csr wrap(not pageshift) for 80 byte spf file         //~v0d7I~
//v0d5:970831 split xefile13 from xefile,fileregist etc.           //~v0d5I~
//v0ct:970814 RENUM(NUM reset) Force option for spf file           //~v0ctI~
//v0cn:970813 RENUM undo support                                   //~v0cnI~
//v0cm:970812 NUM VER subcmd(reset spf version)                    //~v0cmI~
//v0cl:970811 NUM field support                                    //~v0clI~
//v0cb:970802 split allow for long rec even if at out of mergin    //~v0cbI~
//            EOL   allow for long rec even if at out of mergin    //~v0cbI~
//            if mergin=cidpos=topcidpos remain cid                //~v0cbI~
//            else same as no mergin specified                     //~v0cbI~
//v0c2:970728 simple principle.do not touch/move out of mergin     //~v0baI~
//            if mergin not specified,last space is not dropped    //~v0baI~
//v0ba:970726 split xefile,xefile11(load),xefile12(save)           //~v0baI~
//v0az:970720 errline reverse display                              //~v0azI~
//v0av:970720 fixed lrecl support                                  //~v0avI~
//v0ab:970712:write by binaly mode                                 //~v0abI~
//v0aa:970707:default write mode set from read mode                //~v0aaI~
//v09Y:970629:file NULL(0x00) support                              //~v09YI~
//            read/write mode                                      //~v09YI~
//v09F:970614:CID postfix support                                  //~v09FI~
//v09w:970524:Select cmd support on dir list                       //~v09wI~
//            update pdh line timstamp/size                        //~v09wI~
//v09r:970521:arbitaly CID type by first line                      //~v09rI~
//v09e:970517:update  line search by *u (identify by offset==-1)   //~v09eI~
//v08l:961123:edit/browse line range parameter                     //~v08lI~
//v08f:961106:performance up                                       //~v08fI~
//            only once redraw for previous update/previous undo   //~v08fI~
//v074:960602:num reset cmd(renumber line number)                  //~v074I~
//v06C:960407:CID pos default for num=4                               //~v06uI~
//v06y:960407:protect edit so file when iit is used by cmd result     //~v06uI~
//            (cmd edit identification only by PANMOCMD)              //~v06uI~
//v06u:960406:cmd so screen:lineno color for input cmd echo line      //~v06uI~
//v06t:960406:cmd so screen:append cmd result                         //~v06tI~
//v06n:960320:menu option 6(cmd) support                        //~v06nI~
//v06h:960310:support Copy/Move file by ALt+a                   //~v06hI~
//v05v:951203:(BUG)find all offset table shared,it must be for each pfh//~v046I~
//v04j:951007:update id for edit saved file on dir list         //~v046I~
//v046:950923:view dir lcmd(enq pfc to pdh)                     //~v046I~
//v03y:950903:pfh path name length for dir entry matching       //~v03yI~
//*v03u:950827:bug;ULHFLINECMD(lcmd reg sw) reset by xechar ignore//~v03uI~
//            lcmd input from other side of same pfc.           //~v03uI~
//            so move lcmd stack to pfh from pfc.               //~v03uI~
//*v020:950610:dir support                                      //~5610R~
//*v011:950610:reset reverse when double ESC                    //~5610I~
//****************************************************************//~5610I~
//#define EOLID2LEN(eolid) ( (eolid)==4 ? 1 : (eolid) )              //~v50tR~//~vbBuR~
#define EOLID2LEN_NOTZ(eolid) ( (eolid)>2 ? 1 : (eolid) )          //+vbBuR~
#define EOLID2LEN(eolid) ( (eolid)==UFGETS_EOLID_EBCZ ? 2 : EOLID2LEN_NOTZ(eolid))//~vbBuI~
#define IS_VHEXMODE(pcw) ( ((pcw)->UCWpfc) ? ( ((PUFILEC)((pcw)->UCWpfc))->UFCflag2 & UFCF2VHEX ) \
										   :0 )                    //~v60vI~
//*DATA TYPE *******************************
//** line data ctl ****************************************
#define COLUMNDISPPOSDIR 4       //" Rep"                          //~vb7kI~
#define MAXCIDTBL       9   //cid table max                        //~v09rI~
#define FILEHDRLINENO   2                                       //~v020R~
#define ULHLINENOSZ     8
#define ULHLINENOSZ0    0   //no lineno display                 //~v046R~
#define ULHLINENOSZ1    1   //no lcmd input avail               //~v046I~
#define ULHLINENOSZ5    5   //for num 4                               //~v06uI~
//#define MAXFILENAME    12                                        //~v0f0R~
#define MAXFILENAME    (MAXFILENAMEZ-1) //except term null         //~v0f0I~
#ifdef DOSDOS                                                      //~v51qI~
#define MAXCMDLINE      40                                      //~v03uM~
#else                                                              //~v51qI~
#define MAXCMDLINE     200                                         //~v51qI~
#endif                                                             //~v51qI~
                                                                   //~v0clI~
#define MAXCOLSTYPNM    7                                          //~v78rI~
                                                                   //~v78rI~
#define SPFNUMFLDLEN    8   //spf lineno fld len                   //~v0clI~
#define SPFNUMLNOPOS    0   //spf lineno fld                       //~v0clI~
#define SPFNUMLNOLEN    4   //spf lineno fld                       //~v0clI~
#define SPFNUMSNOPOS    4   //spf subno fld                        //~v0clI~
#define SPFNUMSNOLEN    2   //spf subno fld                        //~v0clI~
#define SPFNUMVERPOS    6   //spf version                          //~v0clI~
#define SPFNUMVERLEN    2   //spf version                          //~v0clI~
#define SPFNUMMAXVER   99   //max version                          //~v0clI~
#define SPFNUMMAXSUF   99   //max suffix                           //~v0cuR~
#define STDSPFLRECL    80   //standard spf file lrecl              //~v0d7I~
#define SPFCOBNUMFLDLEN 6   //cobol num fld len                    //~v40EI~
                                                                //~v03uI~
#ifdef AIX                                                         //~v40fR~
#else                                                              //~v40fR~
#pragma pack(1)    /* Force byte alignment */                      //~v10LI~
#endif                                                             //~v40fR~
typedef struct _ULHCI  {                                           //~v780I~
                            int   ULHcibufflen;                    //~v780R~
                            int   ULHcidatalen;  //net style+color+last eol//~v780R~
                            UCHAR ULHcidata[1];  //+1,for last eol //~v780R~
                        } ULHCI,*PULHCI;                           //~v780I~
#define ULHCISZ sizeof(ULHCI)                                      //~v780I~
#define ULHCI_DATALEN(len) (len+len)	//except EOL               //~v780R~
#define ULHCI_EOLDATASZ    (sizeof(((PULHCI)0)->ULHcidata))	//+EOL //~v780I~
#define ULHCI_DATAHDR(len) (ULHCI_DATALEN(len)+ULHCI_EOLDATASZ)	//+EOL//~v780R~
#define ULHCI_BUFFLEN(len) (ULHCISZ+ULHCI_DATALEN(len))	//contains last EOL//~v780R~
#define ULHCI_READLEN(len) (ULHCI_BUFFLEN(len)-sizeof(((PULHCI)0)->ULHcibufflen))	//read last EOL//~v780R~
                                                                   //~v10LI~
typedef struct _ULINEH {
                        UQUEE  ULHqelem;
                        UCHAR  ULHcbid[4];      //acronym       //~5105I~
#define ULHCBID         "ULH"                  //acronym        //~5124R~
                        UCHAR  ULHtype;
#define ULHTDATA        'D'                     //file data
#define ULHTHDR         'H'                     //header line
#define ULHTEXCLUDE     'X'                     //for excluded line
#define ULHTDMYLCMD     'L'                     //dummy for lcmd input//~5122I~
                        UCHAR  ULHflag;
#define ULHFLINECMD     0x80                    //input on line hdr
#define ULHFCURCAP      0x40        //current copyed block      //~5422I~
#define ULHFDIRLFLDERR  0x40        //highlight dir list field  //~v020I~
#define ULHFCURFOUND    0x20        //current find cmd found line
#define ULHFDRAW        0x10        //updated(clear after once display)
#define ULHFLCMDERR     0x08        //line cmd err
#define ULHFCIDCLEAR    0x04        //update reason is cid clear only//~5225R~
#define ULHFBLOCK       0x02        //block defined             //~5225I~
#define ULHFHLDIRTYPE   0x02        //highlight entry id mark   //~v020R~
#define ULHFMOVE        0x01        //inserted by move lcmd     //~5131I~
                        UCHAR  ULHflag2;
#define ULHF2MFOUND     0x80        //multiple found word on the line
#define ULHF2EXCLUDED   0x40        //excluded line
#define ULHF2TABCHKED   0x20        //once tab checked
#define ULHF2TABFOUND   0x10        //once tab detected
#define ULHF2DELETED    0x08        //deleted but prepair for undo
#define ULHF2INSERT     0x04        //inserted line
#define ULHF2SPLIT1     0x02        //line splited              //~5107I~
#define ULHF2SPLIT2     0x01        //post of splited           //~5107I~
                        UCHAR  ULHflag3;        //              //~5514R~
#define ULHF3TEMPLCMD   0x80  //temporaly lcmd for fcmd and cut & paste//~v06hI~
#define ULHF3CMDECHO    0x40  //menu 6,cmd echo line                  //~v06uI~
#define ULHF3CURUPDATE  0x20  //redraw control,current update line //~v45vR~
#define ULHF3CURUNDO    0x10  //redraw control,current undo line   //~v08fI~
#define ULHF3ERRLINE    0x08  //some err,lineno hilight            //~v0azI~
#define ULHF3SETSPFVER  0x04  //spf version set only               //~v0cmR~
#define ULHF3SPFNUMOK   0x02  //spf numfield chked then ok         //~v0duI~
#define ULHF3SPFNUMERR  0x01  //spf numfield chked then err        //~v0duI~
                        UCHAR  ULHflag4;       //rsv               //~v0ibR~
#define ULHF4SELECTED   0x01  //selected for rep/cre cmd           //~v0ibR~
#define ULHF4PROTLINE   0x02  //update protected line              //~v0ifI~
#define ULHF4NOEOL      0x04  //line end without EOL               //~v103I~
#define ULHF4XSAMEHDR   0x08  //excluded hdr for same above lines  //~v40pI~
#define ULHF4SETSPFVER2 0x10  //set required at save               //~v42iI~
#define ULHF4GREP       0x20  //grep searched lined                //~v632I~
#define ULHF4REPRENUM   0x40  //update is renum only;skip spf version reset//~v71VI~
#define ULHF4TEMPERR    0x80  //temporary err flag in this upctr   //~v75fI~
                        UCHAR  ULHeolid;        //end of line id length//~v10YR~
//                      UCHAR  ULHrsv[1];       //rsv              //~v50tR~
                        UCHAR  ULHeolidid;      //eodid itself     //~v50tR~
                        UCHAR  ULHspfver;       //spf upctr        //~v0clR~
                        LONG   ULHlinenor;      //line no at load
                        LONG   ULHlinenow;      //line no at write
                        int    ULHsuffix;       //inserted
                        int    ULHlen;          //actual data len
                        int    ULHbufflen;      //buffer size
                        int    ULHtabskip;      //count at expand//~5422M~
                        int    ULHupctr;        //update count for undo
                        int    ULHupundoctr;    //result of undo//~5105R~
                        int    ULHrevctr;       //reverse display ctl ctr//~5422R~
                        USHORT ULHrevoffs;      //reverse display fld offset//~5422R~
#define ULHULFOUND      0xffff                  //update line search result//~v09eI~
#define ULHULFOUNDL     0xfffe                  //*l search result line//~v496I~
#define ULHOFFSLINEID   0xfff0                  //special value if ">"//~v745I~
                        USHORT ULHrevlen;       //reverse display fld length//~5422R~
                        int    ULHerrctr;       //ULHF3ERRLINE set/reset ctl//~v57HI~
                        UCHAR *ULHdata;         //line data
                        UCHAR *ULHdbcs;         //dbcs id tbl
                        UCHAR  ULHlinecmd[ULHLINENOSZ]; //cmd on line-no
                        UCHAR  ULHlineno[ULHLINENOSZ];  //char line-no
//                      ULONG  ULHoffs;        //line offset for bin file//~vaz0R~
                        FILESZT ULHoffs;        //line offset for bin file//~vaz0I~
//                      UCHAR  ULHrsv[3];                          //~v79eR~
                        UCHAR  ULHflag5;                           //~v79eI~
#define ULHF5DRAWHEX    0x80  //redraw to reset csr pos reverse in hex display mode//~v79eI~
#ifdef UTF8SUPPH                                                   //~va00R~
	#define ULHF5LOADCV       0x40  //utf8 encoding chk at load    //~va00R~
	#define ULHF5LOADCVUTF8   0x20  //contains utf8 code at load time//~va00I~
	#define ULHF5LOADCVERR    0x10  //f2l err at load              //~va00R~
	#define ULHF5COPYCVF2L    0x08  //f2l required for copy cmd    //~va00I~
	#define ULHF5COPYCVL2F    0x04  //noconversion for copy to utf8 file//~va00I~
  #ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
	#define ULHF5COPYCVB2     0x02  //copy source is encoded by ebc//~va50I~
	#define ULHF5COPYCMD      0x01  //not lcmd but fcmd            //~va50I~
  #endif //UTF8EBCD raw ebcdic file support                        //~va50I~
#endif                                                             //~va00I~
//                      UCHAR  ULHrsv[2];                          //~v79eI~//~va87R~
                        UCHAR  ULHflag6;                           //~va87I~
#define ULHF6WXPWKDATA         0x01     //wxp **/*** cmd work file data line//~va87I~
#define ULHF6WXPWKVHEX         0x02     //wxp **/*** cmd work file vhex line//~va87I~
#define ULHF6EBCDBCSCONCAT1    0x04     //split/tflow join dropped intermediate si//~va8wI~
#define ULHF6EBCDBCSCONCAT2    0x08     //split/tflow join dropped intermediate so//~va8wI~
#define ULHF6CHLCPU8CMD        0x10     //CmdHistoryList:utf8 cmd string//~vbi3I~
                        UCHAR  ULHrsv[1];                          //~va87I~
                        UCHAR  ULHsynflag;     //see xesyn.h for EQU definition//~v780I~
                        int    ULHsynlineno;   //line seqno written to source-highlignt//~v786R~
                        PULHCI ULHci;          //style,color data  //~v780R~
#ifdef UTF8UCS2                                                    //~va20I~
                        UCHAR  ULHvhexcsrlinetype;                 //~va20I~
//                      UCHAR  ULHrev[3];                          //~va20I~//~vaj0R~
                        UCHAR  ULHmflinetype;                      //~vaj0I~
                        UCHAR  ULHrev[2];                          //~vaj0I~
#endif                                                             //~va20I~
                        int    ULHuscentryno;//CmdHistoryList search key of USCMD entry//~vbi3R~
                        } ULINEH;
typedef ULINEH *PULINEH;
#define ULINEHSZ (sizeof(ULINEH))
//*file data control hdr  ****************************************
typedef struct _UFILEH {                        //file hdr
                        UQUEE   UFHqelem;
                        UCHAR   UFHcbid[4];     //acronym       //~5105I~
#define UFHCBID         "UFH"                                   //~5124R~
                        UCHAR   UFHfilename[_MAX_PATH];         //~4C19R~
#if defined(W32) || defined(DPMI)                                  //~v0fbR~
                        UCHAR   UFHshortname[_MAX_PATH];           //~v0fbR~
#endif                                                             //~v0fbR~
//                      UCHAR   UFHalias[16];   //alias in work dir//~v48cR~
#ifdef UNX                                                         //~v48cI~
	#define UFHALIASSZ 32 		//used for also mdos disk tempname //~v48cR~
#else                                                              //~v48cI~
	#define UFHALIASSZ 16                                          //~v48cI~
#endif                                                             //~v48cI~
#ifdef FTPSUPP                                                     //~v542I~
                        UCHAR   UFHftpwdfnm[_MAX_PATH];	//ftp local work file name//~v542R~
#endif                                                             //~v542I~
//#ifdef ARMXXE                                                      //~vby4R~//~vby6R~
//                        UCHAR   UFHfpathDoc[_MAX_PATH];            //~vby4R~//~vby6R~
//#endif                                                             //~vby4R~//~vby6R~
                        UCHAR   UFHalias[UFHALIASSZ];   //alias in work dir//~v48cI~
                        UCHAR   UFHcid[12];     //cid for chk line copy//~v020R~
                        UCHAR   UFHcidDDfmt[4];     //for utf8 file utf8 cid by dd fmt, UFHcid is utf8 string//~vbv6R~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
                        UCHAR   UFHcidebc[12];  //cid by ebcdic    //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
                        FILE   *UFHhfile;
                        FTIME   UFHfiletime;
                        FDATE   UFHfiledate;
//                      ULONG   UFHsize;                           //~v731R~
                        FILESZT UFHsize;                           //~v731I~
                        UCHAR   UFHflag;
#define UFHFUPCTRREQ    0x01                    //upctr count up req
#define UFHFWRITEERR    0x02                    //write err
#define UFHFNEW         0x04                    //new file
#define UFHFWORKDIRFILE 0x08                    //work dir file //~5224I~
#define UFHFUNDOCTRREQ  0x10                    //undoctr up req
#define UFHFCIDON       0x20                    //explicit on cmd//~5308R~
#define UFHFCIDOFF      0x40                    //explicit off cmd//~5311R~
#define UFHFEOFEXIST    0x80                    //EOF exist at load//~5502I~
                        UCHAR   UFHflag2;   //v011              //~5610I~
#define UFHF2RESETPASTE 0x01                //v011 reset paste reverse//~5610I~
#define UFHF2FIXEDCID   0x02                //v012 fixed cid    //~5611I~
#define UFHF2LCMDCOMP   0x04                //input lcmd processed//~v03uI~
#define UFHF2HDRLINECID 0x08                //cid by header line   //~v09rI~
#define UFHF2MERGIN     0x10                //maergin parm specified//~v0baI~
#define UFHF2MERGINCID  0x20                //mergin=cpos          //~v0cbI~
#define UFHF2SPFNUMOK   0x40                //spf num ok file at load time//~v0drR~
#define UFHF2SPFNUMERR  0x80                //spf num file err     //~v0d7R~
                        UCHAR   UFHtype;                        //~5127R~
#define UFHTCLIPBOARD   'C'     //clipboard file in work dir    //~5224I~
#define UFHTKFI         'K'     //key func ini file in work dir    //~v0ifI~
#define UFHTDIR         'D'     //directory                     //~v020I~
#define UFHTSTDOUT      'S'     //first opened as cmd stdout          //~v06uR~
#define UFHTTEMPWK      'T'     //TEMP work for partial edit etc   //~v08lI~
#define UFHTTEMPWK2     't'     //TEMP work for filenamelist find support//~v76mI~
#ifdef FTPSUPP                                                     //~v53UI~
  	#define UFHTHOSTS   'H'     //host name file for ftp           //~v53UR~
#endif                                                             //~v53UI~
//#ifdef WXE                                                       //~v632R~
#ifdef WXEXXE                                                      //~v632I~
  	#define UFHTWXPWK   'P'     //wxp work                         //~v54yR~
#endif                                                             //~v54yI~
#define UFHTCMDHIST     'M'     //command history                  //~vbi3I~
                        UCHAR   UFHcidtype;     //cid type      //~5308R~
#define UFHCIDTYPEC     1       //for c,cpp,h,hpp etc           //~5310R~
#define UFHCIDTYPEASM   2       //for asm                       //~5310R~
#define UFHCIDTYPEDOC   3       //for .doc,read.me              //~5528I~
//#define UFHCIDTYPEAPL 4       //for .apl                         //~vbv9R~
#define UFHCIDTYPEOTHER (MAXCIDTBL+1) //by header line(not predefined)//~v09rR~
#define UFHCIDTYPEERR   0xff    //not defined ext type          //~5310R~
                        int     UFHpathlen;     //path name length //~vaztI~
                        UCHAR   UFHlevel; //file or dir level   //~v020R~
//                      UCHAR   UFHpathlen;     //path name length //~vaztR~
                        UCHAR   UFHrsv1[1];                        //~vaztI~
//                      UCHAR   UFHrsv1[2];     //boundary         //~v09rR~
                        UCHAR   UFHcidpos;      //CID position     //~v09rI~
                        UCHAR   UFHdirsepc;     //dir sepc "\" or "/"//~v540R~
#ifdef UNX                                                         //~v19WR~
//                      UCHAR   UFHrsv2[3];     //padding          //~v540R~
                        dev_t   UFHfsid   ;     //userid           //~v19XI~
                        uid_t   UFHuid    ;     //userid           //~v19XM~
                        gid_t   UFHgid    ;     //userid           //~v19XM~
                        ULONG   UFHattr   ;     //attr at load time//~v19WR~
#else  //!UNX                                                      //~v19WR~
//                      UCHAR   UFHattr   ;     //attr at load time//~v53QR~
                        ULONG   UFHattr   ;     //4 byte attr for ftp support//~v53QI~
#endif //!UNX                                                      //~v19WR~
#ifdef FTPSUPP                                                     //~v55PI~
                        ULONG   UFHsrcattr;     //slink source attr//~v55PR~
//                                              //lrecl+blksize for TSO file//~v72nI~
#endif //FTPSUPP                                                   //~v55PI~
                        UCHAR   UFHcidlen;      //CID len 9-11     //~v09FI~
//                      UCHAR   UFHrsv1[3];     //boundary         //~v09YR~
                        UCHAR   UFHflag3;       //file Read/Write mode//~v09YI~
#define UFHF3RBIN       0x80                    //read by "rb"     //~v0aaR~
#define UFHF3RTEXTPC    0x40                    //accept crlf as end of line//~v09YI~
#define UFHF3RTEXTUNIX  0x20                    //accept lf as end of line//~v09YI~
#define UFHF3WBIN       0x08                    //read by "rb"     //~v0aaI~
#define UFHF3WTEXTPC    0x04                    //write crlf for UNIX file//~v0aaR~
#define UFHF3WTEXTUNIX  0x02                    //write cr for PC file//~v0aaR~
#define UFHF3OOMNOPROT  0x01                    //oom update avail //~v0eqI~
                        UCHAR   UFHflag4;                          //~v0f0I~
#define UFHF4LFN        0x80                    //long file name dir list//~v0fcR~
#define UFHF4BIN        0x40                    //binaly file      //~v0hfI~
#define UFHF4TEXT       0x20                    //explicitly text mode specified//~v10cR~
#define UFHF4SPFCMD     0x10                    //force SPF by EN/BN cmd//~v10LI~
#define UFHF4XLINENO    0x08    //lineno display by hex offset     //~v10XR~
#define UFHF4NLINENO    0x04    //lineno display by hex offset     //~v10XI~
#define UFHF4XRANGE     0x02    //offset range parm specified      //~v10YI~
#define UFHF4WIDTH      0x01    //width parm specified             //~v11zI~
//                      UCHAR   UFHrsv1[3];     //boundary         //~v0ifR~
                        UCHAR   UFHprotlen;//protected fieldsz from col1 for func key//~v0ifI~
//                      UCHAR   UFHrsv1[2];     //boundary         //~v0avR~
                        UCHAR   UFHspfver;      //spf version      //~v0clR~
                        UCHAR   UFHspfpos;      //spf number field pos//~v0clR~
                        USHORT  UFHmergin;      //max data field length//~v0avI~
                        USHORT  UFHlrecl;       //max lrecl        //~v0avI~
                        USHORT  UFHlreclout;    // by Fxx of /MxR mode//~va6QI~
                        USHORT  UFHwidth;       //display width    //~v10eI~
                                                                   //~v20tI~
                        UCHAR   UFHflag5;                          //~v20tI~
#define UFHF5TLUCTR     0x01    //topline update ctr specified     //~v20tI~
#define UFHF5DROPTAB    0x02    //drop tab at save                 //~v20vI~
//#define UFHF5LISTDIR    0x04    //dirlist display by /l option   //~v40uR~
#ifdef UNX                                                         //~v40AI~
	#define UFHF5MDOS   0x04    //mdos disk file                   //~v40AI~
#endif                                                             //~v40AI~
#define UFHF5COB        0x08    //cobol file by cid hdr            //~v40DI~
#define UFHF5NOAUTONUM  0x10    //no update number fld(set by num clear cmd)//~v40FI~
#define UFHF5NUMCLEARED 0x20    //num clear cmd entered once       //~v42rI~
#define UFHF5COB2       0x40    //cobol file with all space num fld//~v42vI~
#define UFHF5HEX        0x80    //display hex                      //~v440I~
//                      UCHAR   UFHrsv5   ;     //boundary         //~v47LR~
                        UCHAR   UFHflag6  ;                        //~v47LI~
#define UFHF6EOLCHNG    0x80    //eol change occur explicitly(by edit parm)//~v47LI~
#define UFHF6RTEXTMAC   0x40    //read as mac file(eol=0d)         //~v47XI~
#define UFHF6WTEXTMAC   0x20    //write as mac file(eol=0d)        //~v47XI~
#define UFHF6REMOTE     0x10    //ftp remote file                  //~v53UI~
#define UFHF6NOUNDO     0x08    //parm to undo;skip undodata save  //~v585I~
#define UFHF6RLOGIN     0x04    //PANMOCMD for rsh                 //~v59gI~
#define UFHF6VHEXPARM   0x02    // /Mx specified at open(move to UFCFHEX later)//~v60vI~
#define UFHF6RESIZE     0x01    //WXE:resize occured               //~v621I~
                        USHORT  UFHtluctr;      //cid topline update ctr at load//~v20tI~
                        UCHAR   UFHflag7  ;                        //~v66eI~
#define UFHF7REGIONCB   0x08    //::cb,data is stream mode(reagion mode)//~v66eI~
#define UFHF7DESC       0x04    //display file description on dirlist//~v690I~
#define UFHF7NTFS       0x02    //NTFS filesystem                  //~v690I~
#define UFHF7TSO        0x01    //TSO file                         //~v70zI~
#define UFHF7PDSMEMBER  0x10    //TSO PDS MEMBER file              //~v70zI~
#define UFHF7FIXLRECL   0x20    //lrecl cannot exceed UFHlrecl     //~v71HI~
#define UFHF7NONUMOPT   0x40    //option specified to reset 72-80 number fld for TSO file//~v71KI~
#define UFHF7NOFIXOPT   0x80    //option specified to reset UFHF77FIXLRECL for TSO file//~v71KR~
//                      UCHAR   UFHrsv7[3];     //boundary         //~v69JR~
                        UCHAR   UFHflag8;                          //~v69JI~
#define UFHF8CAPSON     0x01    //Caps on for this file            //~v69JI~
#define UFHF8NOUPDCHK   0x02    //no chk the file is updated by the other process//~v70cI~
#define UFHF8NOTABCLEAR 0x04    //option specified to reset UFHF5DROPTAB//~v71VI~
#define UFHF8TSOSPF     0x08    //PDS with LRECFM=Fx LRECL=80 file //~v72nI~
#define UFHF8TSOFSMODE  0x10    //cmd panel is TSO full screen mode//~v72BI~
#define UFHF8NOBKSV     0x20    //bypass rename for abend at save  //~v76zI~
//#ifdef UTF8SUPP                                                    //~v8@MI~//~va00R~
#ifdef UTF8SUPPH                                                   //~va00I~
	#define UFHF8UTF8   0x40    //opened by utf8-encoded file      //~v8@MI~
    #define UFHF8UTF8P  0x80    //opened by utf8-encoded file(by Edit cmd explicit parm)//~v8@MI~
#endif                                                             //~v8@MI~
//                      UCHAR   UFHrsv8[2];     //boundary         //~v90jR~
                        UCHAR   UFHlinenosw; //lineno fld display width//~v90jI~
//                      UCHAR   UFHrsv8;     //boundary            //~v78yR~
                        UCHAR   UFHflag9;                          //~v78yI~
//#ifdef UTF8SUPP                                                    //~v78yI~//~va00R~
#ifdef UTF8SUPPH                                                   //~va00I~
	#define UFHF9HDRLC  0x01    //hdr filename contains locale code//~v78yI~
	#define UFHF9HDRU8  0x02    //hdr filenae  contains utf8 code  //~v78yI~
	#define UFHF9HDRASC 0x04    //hdr filename is all ascii        //~v78yI~
//  #define UFHF9WIDTHC 0x08    //edit width parm is by column for utf8 file//~v78yI~//~va00R~
#endif                                                             //~v78yI~
#define UFHF9CAPSONCMD  0x80    //Caps on for this file also for cmd input line//~v8@MI~
#define UFHF9CIDAPPEND  0x40    //cid append mode                  //~v79UI~
#define UFHF9CIDAPPENDN 0x20    //no cid append mode               //~v79UI~
#ifdef ARM                                                         //~vag1I~
#define UFHF9SDCARD     0x10    //file is on sdcard path           //~vag1I~
#define UFHF9SDNOTGRANT 0x08    //write permission not granted     //~vbr3R~
#endif                                                             //~vag1I~
#ifdef FTPSUPP                                                     //~v54pI~
                        UCHAR   UFHrsv11[2];    //boundary align   //~vag2I~
                        void*   UFHpuftph;    //ftphost ptr        //~v54pR~
#ifndef UTF8SUPPH                                                  //~va00I~
                        UCHAR   UFHrsv9[2];     //boundary         //~v72nI~//~va00R~
#else                                                              //~va00I~
                        UCHAR   UFHflag10;                         //~va00I~
#ifdef UTF8SUPPH                                                   //~va00I~
	#define UFHF10UTF8LOADERR       0x01           //CPU8 file loaded with error UTF8 code replaced to "?"//~va00I~
	#define UFHF10UTF8SAVEERR       0x02           //cvl2f err at save//~va00I~
	#define UFHF10CPPROF            0x04           //record ro profile//~va00R~
	#define UFHF10UTF8COPYERR       0x08           //cvf2l err at copy cmd//~va00I~
	#define UFHF10UTF8IE            0x10           //option to ignore utf8 conversion err//~va00I~
#endif                                                             //~va00I~
                                                                   //~va50I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	#define UFHF10EBC               0x20           //edbcdic file  //~va50I~
	#define UFHF10EBCP              0x40           //ebc by explicit cmd parm//~va50I~
	#define  PFH_ISEBC(pfh)   \
    	(UCBITCHK((pfh)->UFHflag10,UFHF10EBC)!=0)   //return 1 or 0                  //~va50I~//~va51R~
	#define  PLH_ISEBC(plh)   PFH_ISEBC(UGETPFH(plh))              //~va50I~
#endif //UTF8EBCS raw ebcdic file support                          //~va50I~
	#define UFHF10RECORD            0x80           //record mode(No EOL char)//~va51I~
                        UCHAR   UFHflag11;                         //~va00I~
	#define UFHF11WRECORD           0x01           //drop eol at write//~va5eI~
	#define UFHF11FILEFK            0x02           //3 filefk panel//~va6rI~
	#define UFHF11RTEXTEBC          0x04           //input file's eol is ebc NL(0x15)//~va6DI~
	#define UFHF11WTEXTEBC          0x08           //output eol is ebc NL(0x15)//~va6DI~
	#define UFHF11WTEXT             0x10           // /MxT         //~va6NI~
	#define UFHF11EBCSETCP          0x20           // ebcdic codepage was changed//~va7LI~
	#define UFHF11WXPPRTSCRVHEX     0x40           // wxp work file for wxp **/*** cmd//~va87R~
	#define UFHF11RTEXTEBCZ         0x80           //allow input file's eol is ebc CR(0x0d)+NL(0x15)//~vbBuI~
#endif                                                             //~va00I~
                        UCHAR   UFHspfvv;      //TSO PDS dir SPF info:vv//~v72nI~
                        UCHAR   UFHspfmm;      //TSO PDS dir SPF info:mm//~v72nI~
                        USHORT  UFHspfinitline;//TSO PDS dir SPF info:initial line count//~v72nI~
                        FDATE   UFHspfcredate; //TSO PDS dir SPF info:creation date//~v72nI~
#endif                                                             //~v54pR~
                        USHORT  UFHmaxlinewidth;//max line width   //~v54RI~
                        USHORT  UFHmaxlrecl;    //max record len(sumed splitted line)//~v54RI~
                        UQUEH   UFHlineque;     //line data queue
                        UQUEH   UFHundoque;     //undo que
                        UQUEH   UFHredoque;     //redo que         //~vag2I~
                        PUCLIENTWE UFHeditpcw;  //edit pcw      //~5118I~
                        PUCLIENTWE UFHbrowsepcw[2];//browse pcw //~5118R~
                        int     UFHupctrsave;   //update ctr when saved
                        int     UFHupctrgrep;   //update ctr when saved//~v630I~
                        int     UFHupctr;       //update ctr for undo
                        int     UFHundoctr;     //undo ctr(include x)
                        int     UFHupundoctr;   //update/undo ctr//~5105I~
                        int     UFHfindctr;     //find cmd ctr for dsply
//                      int     UFHfindctrms;   //multi reverse start//~v62cR~
//                      int     UFHfindctrme;   //multi reverse end//~v62cR~
                        int     UFHopenctr;     //open count
//*lcmd stack                                                   //~v03uI~
                        int       UFHcmdlinectr;//lcmd stack ctr//~v03uI~
                        int       UFHpendctr;   //pending lcmd saved ctr//~v03uI~
                        int       UFHmfwtindex;//USHORT count in UFHmfwtbl;//~v62bR~
                        USHORT   *UFHmfwtbl;    //find all table//~v046I~
                        PVOID     UFHpvlcmd;    //pending lcmd ULCMD tbl//~v03uI~
                        PULINEH   UFHcmdline[MAXCMDLINE];//lcmd inpt line//~v03uI~
                        LONG    UFHsline;       //read start line  //~v08lI~
                        LONG    UFHeline;       //read end line    //~v08lI~
                        LONG    UFHiline;       //initial locate linenumber(edit /Lnn parm)//~v62xR~
//                      long    UFHslinepos;    //seek value of end line//~vaz0R~
                        FILESZT UFHslinepos;    //seek value of end line//~vaz0I~
//                      long    UFHelinepos;    //seek value of end line//~vaz0R~
                        FILESZT UFHelinepos;    //seek value of end line//~vaz0I~
                        int     UFHbndscol1;    //left boundary col//~v74EI~
                        int     UFHbndscol2;    //right boundary col//~v74EI~
                        UCHAR   UFHlinenowk[8]; //linesw+edit patern//~v53dI~
                        ULONG   UFHprofile;     //flag from profile record//~v78rI~
                        UCHAR   UFHcolstype[MAXCOLSTYPNM+1];//profile data//~v78rI~
                        UCHAR   UFHtabskip;     //tabctr           //~v8@2I~
//                      UCHAR   UFHrsv10[3];                       //~v8@2I~//~vac1R~
                        UCHAR   UFHflag12;                         //~vac1I~
	#define UFHF12SMB           0x01               // remote destination is samba//~vac1I~
	#define UFHF12RWIN          0x02               // remote destination is windows by smbclient//~vac1R~
	#define UFHF12FNU8          0x04               //assme CPU8 for filename at first//~vagER~
	#define UFHF12FNLC          0x08               //assme CPLC for filename at first//~vagER~
	#define UFHF12FNCMD         0x10               //specified FNLC or FNU8 option//~vagEI~
//                      UCHAR   UFHrsv10[2];                       //~vac1I~//~vaj0R~
                        UCHAR   UFHflag13;                         //~vaj0I~
	#define UFHF13RV            0x01               //variable record format Read//~vaj0I~
	#define UFHF13WV            0x02               //variable record format Write//~vaj0R~
	#define UFHF13CB2           0x04               //clipboard file//~vaj0I~
	#define UFHF13SELECTFNU8    0x08	    //select dlcmd:member name is determined fnu8 on dirlist//~vauAI~
	#define UFHF13SELECTFNLC    0x10	    //select dlcmd:member name is determined fnlc on dirlist//~vauAI~
#ifdef W32                                                         //~vav2I~
	#define UFHF13REMOTEUNC     0x20	    //\\server\share UNC file//~vav2I~
#ifdef W32UNICODE                                                  //~vavaI~
	#define UFHF13SUBCHFNAME    0x40	    //membername has subchar//~vavaI~
#endif                                                             //~vavaI~
#endif                                                             //~vav2I~
#ifdef W32                                                         //~vb06I~
	#define UFHF13RESERVEDNAME  0x80	    //To prepend \\.\ to filename is required//~vb06I~
#endif                                                             //~vb06I~
                        UCHAR   UFHvfmt;			//recfm=V record header format//~vaj0R~
                        UCHAR   UFHflag14;                         //~vb2eI~
#ifdef LNX                                                         //~vb2nI~
#define UFHF14MOUNTU8         0x01	    //ufullpathCP detected mountoption iocharset:UTF8(including not defined default)//~vb2eR~
#define UFHF14MOUNTU8CV       0x02	    //l2f translation done     //~vb2eI~
#endif                                                             //~vb2nI~
#define UFHF14FN_ENCODED_UTF8 0x04	    //filename(not path) encoding is aftually utf8//~vb2hR~
#define UFHF14CIDU8           0x08      //cid is by utf8 code for utf8 file,it is set on UFHcidDDfmt[4]//~vbv6R~
#define UFHF14CIDU8SBCS       0x10      //cid utf8 sbcs(1 column)  //~vbv6I~
#define UFHF14CID2BYTE        0x20      //2byte cid prefix(utf8 locale)//~vbv6I~
#ifdef ARMXXE                                                      //~vby4I~
	#define UFHF14DOCUMENT    0x40                                 //~vby4I~
	#define PFH_ISDOCUMENT(pfh)   (UCBITCHK((pfh)->UFHflag14,UFHF14DOCUMENT)!=0)//~vby4I~
#endif                                                             //~vby4I~
                        UCHAR   UFHrsv14[3];                       //~vb2eI~
                        PULINEH UFHplhlcmdi;       //plh isrted by lcmd i//~v78SR~
                        int     UFHplhlcmdi_upundoctr; //if changed set UFHplhlcmdi=0//~vb7kI~
//*syntax highlight                                                //~v780I~
                        ULONG   UFHsynflag;     //syntaxHL ctl //see xesyn.h for flag EQU define//~v780I~
#define MAX_SYNTYPE     7                                          //~v780I~
                        UCHAR   UFHsyntype[MAX_SYNTYPE+1]; //syntax highlight lang type//~v780R~
#ifdef UTF8SUPPH                                                   //~v90rI~//~va00I~
                        int     UFHhdrnamewidth;    //header line filename width//~v90rR~//~va00I~
                        int     UFHhdrnamepos;      //stratpos of long filenamepath//~v90rI~//~va00I~
                        UCHAR  *UFHhdrnameattr;     //header line filename attr tbl;0:ascii,1:utf8,2:locale converted//~v90rI~//~va00I~
                        UCHAR  *UFHhdrnamebyu8;     //header line filename by mixed str//~va5sI~
                        int     UFHfilenamebylclen;//filename by localecode from cmdbuff//~va1BR~
                        			//*UD id was stripped status   //~vavaI~
                        UCHAR  *UFHfilenamecodetype;     //codetype//~va1BI~
                        UCHAR  *UFHfilenamebylc;         //lc name after ct//~va1BI~
#endif                                                             //~v90rI~//~va00I~
                        int     UFHhandle;		//ebcdic converter handle//~va79I~
                        int     UFHhandleorg;	//saved at 1st codepage change//~va7LI~
#ifdef UNX                                                         //~va8wI~
                        ino_t   UFHinode;                          //~va8wI~
#endif                                                             //~va8wI~
#ifdef LNX				                                           //~vau7I~
                        int     UFHfilenameddlen;      //ddfmt len //~vau7I~
                        UCHAR  *UFHfilenamedddata;     //ddfmt data//~vau7I~
                        UCHAR  *UFHfilenamedddbcs;     //ddfmt dbcs//~vau7I~
                        UCHAR  *UFHfilenameddct;       //ddfmt ct  //~vau7I~
#endif                                                             //~vau7I~
#ifdef W32UNICODE                                                  //~vavaI~
                        int     UFHfilenameddlen;      //ddfmt len //~vavaI~
                        UCHAR  *UFHfilenamedddata;     //ddfmt data//~vavaI~
                        			//*UD id was stripped status   //~vavaI~
                        UCHAR  *UFHfilenamedddbcs;     //ddfmt dbcs//~vavaI~
                        UCHAR  *UFHfilenameddct;       //ddfmt ct  //~vavaI~
#endif                                                             //~vavaI~
//#ifdef ARMXXE                                                      //~vby4I~//~vby6R~
//                        int     UFHdocumentPrefixLen; //up to next of %3A or ":"//~vby4R~//~vby6R~
//                        char    UFHshortpath[_MAX_PATH];           //~vby4R~//~vby6R~
//#endif                                                             //~vby4I~//~vby6R~
                        } UFILEH;
typedef UFILEH *PUFILEH;
#define UFILEHSZ (sizeof(UFILEH))
//*file client control          *********************************
typedef struct _UFILEC {                        //file cwe
                        UQUEE     UFCqelem;     //vie q element //~v046I~
                        UCHAR     UFCcbid[4];                   //~5105I~
#define UFCCBID         "UFC"                                   //~5124R~
                        UCHAR     UFCtype;      //type          //~v020I~
#define UFCTFILE        'F'                     //file browse/edit//~v020I~
#define UFCTDIRL        'D'                     //dir list      //~v020I~
                        UCHAR     UFCflag;      //
#define UFCFBROWSE      0x01                    //browse mode
//#define UFCFLCMDCOMP  0x02                    //input lcmd processed//~v03uR~
#define UFCFISRTDRAW    0x02                    //draw by line insertd//~v0hfI~
#define UFCFDFILE       0x04                    //dir list for filer//~v020I~
#define UFCFDEDIT       0x08                    //dir list from edit//~v020I~
#define UFCFENDSAVE     0x10                    //edit ended saving file//~v046I~
#define UFCFENQEDIT     0x20                    //enq to UDHviewqh by Edit lcmd//~v046I~
//#define UFCFSTDOUT    0x40                    //opened as cmd stdout//~v06uR~
#define UFCFENQSELNEW   0x40                    //new file by select cmd//~v0fqI~
//#define UFCFCANNEWF   0x80                    //new file canceld //~v10kR~
                        UCHAR     UFCpendfcmd;  //pending fcmd  //~v06hR~
//                      UCHAR     UFCfiller[1]; //                 //~v440R~
                        UCHAR     UFCflag2;     //                 //~v440I~
//#define UFCFHEX         0x01                    //hex browse mode//~v60vR~
#define UFCF2VHEX       0x01                    //virtual hex display mode//~v60vI~
#define UFCF2EBC2ASC    0x02                    //browse as ebcdic file(display after convert to ascii)//~v51qR~
#define UFCF2PPCRESET   0x04                    //PPCRESET done    //~v56rR~
#define UFCF2VHEXINCOMP 0x08                    //vhex display incomplete for lowest line//~v60vI~
#define UFCF2RESIZE     0x10	    //WXE:resize occured           //~v621I~
#define UFCF2NOTDEFCOLS 0x20	    //not default cols line        //~v75FI~
#ifdef UTF8SUPPH                                                   //~va00I~
#define UFCF2UTF8       0x40	    //lang:utf8 mode opened        //~va00I~
#define UFCF2UTF8P      0x80	    //edit cmd parm specified cplc/cpu8 option//~va00I~
#endif  //UTF8SUPPH                                                //~va00I~
                        UCHAR     UFCflag3;    //                  //~va50I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
#define UFCF3EBC                0x01	    //ebcdic dir           //~va50R~
#define UFCF3EBCP               0x02	    //edit cmd parm specified CPEB//~va50R~
#define UFCF3SELECTFNU8         0x04	    //select dlcmd:member name is determined fnu8 on dirlist//~vauAI~
#define UFCF3SELECTFNLC         0x08	    //select dlcmd:member name is determined fnlc on dirlist//~vauAI~
#define UFCF3SELECTDLCMD        0x10	    //select dlcmd,not select cmd//~vb2gI~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
                        UCHAR     UFCrsv3[3];                      //~va50R~
                        UFILEH   *UFCpfh;       //UFILEH ptr
                        PULINEH   UFCcurtop;    //current plh
                        PULINEH   UFCcsrplh;    //set csr req plh
                        PULINEH   UFCdrawplh;   //re-draw start plh//~v0hfI~
                        int       UFCmaxline;   //displayed plh ctr//~4C29R~
                        int       UFCvhexplhctr;   //0 or displayed plh ctr when vhex mode//~v60vR~
                        int       UFCvhexplhctrcsr;//csr plh line offset when vhex mode//~v60vI~
                        int       UFCcsrfldno;  //set csr req fldno//~4C29I~
                        int       UFCcsroffs;   //set csr offs in fld//~5223I~
                        int       UFCprevwidth; //previous width for vsplit//~5423R~
                        int       UFCscrolldisp; //previous width for vsplit//~5423I~
                        int       UFCcsrposdisp;    //csr pos display pos//~5423I~
                        int       UFCleft;      //start column
                        int       UFCexpandlen;  //dirlist resize expand len//~v59TI~
                        PVOID     UFCpcw;       //pcw           //~v046I~
                        int       UFCcolsdatalen;//cols datalen    //~v11NI~
                        int       UFCcolscsrpos; //old cursor position on gauge line//~v72dI~
                        UCHAR    *UFCcolsdata;  //for COL cmd,gauge data//~v11NR~
//                      UCHAR     UFCcolstype[4];//for COL cmd,cols type//~v447R~
//#define MAXCOLSTYPNM    7                                        //~v78rR~
                        UCHAR     UFCcolstype[MAXCOLSTYPNM+1];//for COL cmd,cols type//~v447R~
                        char     *UFCdeepestpath; //for path up/down ctl//~v558I~
                        int       UFCcsrline;    //current file csr line//~vbi3R~
                        int       UFCcsrlineold; //current file csr line//~vbi3I~
                        } UFILEC;
typedef UFILEC *PUFILEC;
#define UFILECSZ (sizeof(UFILEC))
                                                                   //~v10LI~
#ifdef AIX                                                         //~v40fR~
#else                                                              //~v40fR~
#pragma pack()                                                     //~v10LI~
#endif                                                             //~v40fR~
                                                                   //~v10LI~
//****************************************************************
                                                                   //~vafkI~
//#define  UGETPFH(plh)                                            //~vafkR~
//  ((PUFILEH)((ULONG)(((PULINEH)(plh))->ULHqelem.UQqhdr)-offsetof(UFILEH,UFHlineque)))//~5224R~//~vafkR~
#define  UGETPFH(plh)   \
    ((PUFILEH)((ULPTR)(((PULINEH)(plh))->ULHqelem.UQqhdr)-offsetof(UFILEH,UFHlineque)))//~vafkI~
#define  UGETPFHFROMPCW(pcw)    \
    (  (pcw)->UCWpfc ?  UGETPFHFROMPCW_UNCOND(pcw)  :0 )           //~va7AI~
#define  UGETPFHFROMPCW_UNCOND(pcw)    \
    (((PUFILEC)(pcw->UCWpfc))->UFCpfh)                             //~v11xI~
#define  UPCTRREQ(pfh)  \
    (UCBITON(((PUFILEH)(pfh))->UFHflag,UFHFUPCTRREQ|UFHFUNDOCTRREQ))//~5224I~
#define  FILEISREMOTE(pfh)   \
    (UCBITCHK((pfh)->UFHflag6,UFHF6REMOTE))                        //~v53UI~
#ifdef W32                                                         //~vav2I~
	#define  FILEISREMOTEUNC(pfh)   \
    	(UCBITCHK((pfh)->UFHflag13,UFHF13REMOTEUNC))               //~vav2I~
#endif                                                             //~vav2I~
#define  FILE_ISSMB(pfh)   \
    (UCBITCHK((pfh)->UFHflag12,UFHF12SMB))                         //~vac1R~
#ifdef FTPSUPP                                                     //~v70zI~
	#define  FILEISTSO(pfh)   \
    	(UCBITCHK((pfh)->UFHflag7,UFHF7TSO)!=0)                    //~v70zR~
	#define  FILETSOLRECL(pfh)   \
    	(pfh->UFHsrcattr>>16)                                      //~v72nI~
	#define  FILETSOBLKSZ(pfh)   \
    	(pfh->UFHsrcattr & 0xffff)                                 //~v72nI~
#endif                                                             //~v70zI~
#ifdef FTPSUPP                                                     //~v542I~
	#define  FILELOCALCOPYNAME(pfh)   ((FILEISREMOTE(pfh)) \
                       ?(pfh)->UFHftpwdfnm:(pfh)->UFHfilename)     //~v542I~
#else                                                              //~v542I~
	#define  FILELOCALCOPYNAME(pfh)   (pfh)->UFHfilename;          //~v542I~
#endif                                                             //~v542I~
#ifdef W32                                                         //~v54fI~
	#define  FILEPATHLEN(pfh,path)   \
    			(FILEISREMOTE(pfh)?FTP_PATHLEN(path):PATHLEN(path))//~v54fI~
#else                                                              //~v54fI~
	#define  FILEPATHLEN(pfh,path)   \
    			PATHLEN(path)                                      //~v54fI~
#endif                                                             //~v54fI~
#ifdef FTPSUPP                                                     //~v54mI~
	#define  FILEISSLINK(attr)  \
            (S_ISLNK(FILE_GETMODE((attr))))                        //~v54mI~
#endif                                                             //~v54mI~
#ifdef UTF8SUPPH                                                   //~va00I~
	#define  FILEUTF8MODE(pfh)   \
    	(UCBITCHK((pfh)->UFHflag8,UFHF8UTF8))                      //~va00I~
#endif                                                             //~va00I~
#ifdef UTF8UCS2                                                    //~va20I~
	#define  PLHUTF8MODE(plh)   \
    	(UCBITCHK(( UGETPFH(plh) )->UFHflag8,UFHF8UTF8))           //~va20I~
#endif                                                             //~va20I~
                                                                   //~v780I~
#define  FILECHKDBCSTB(plh)  \
			   {                             \
            	if (!(plh)->ULHdbcs)         \
					if (filechktabdbcs(plh)==UALLOC_FAILED) \
        				return UALLOC_FAILED;               \
            }                                                      //~v780R~
#define  FILECHKTABCHNG(plh,pfhtabskip)  \
			{                             \
            	if ((plh)->ULHtabskip!=(pfhtabskip))         \
					if (filechktabdbcs(plh)==UALLOC_FAILED) \
        				return UALLOC_FAILED;               \
            }                                                      //~v79yI~
//****************************************************************//~5128I~
void fileinit(void);
//****************************************************************
void fileterm(void);
//**************************************************************** //~v0imI~
int func_edit_file3(PUCLIENTWE Ppcw,int Popt);                     //~v0imI~
//**************************************************************** //~v08lI~
int func_edit_file2(PUCLIENTWE Ppcw,int Poptopd);                  //~v08lI~
//*edit/browse internal function call option                       //~v76mI~
#define FEBFIO_OPD          0x01	//operand exist other than filename//~v76mI~
#define FEBFIO_TEMP2      0x0100	//temp file do not satack to filename list//~v76mR~
#ifdef UTF8SUPPH                                                   //~va00I~
#define FEBFIO_UTF8IE     0x0200	//ignore utf8 trans err        //~va00I~
#define FEBFIO_CPU8       0x0400	//force cpu8                   //~va0CI~
#define FEBFIO_CPLC       0x0800	//force cplc                   //~va0CI~
#define FEBFIO_RETRY      0x1000	//retry by CPLC for CPU8 err   //~va1eI~
#endif                                                             //~va00I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
#define FEBFIO_CPEB       0x2000	//force CPEB                   //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
#ifdef LNX                                                         //~vb2eI~
	#define FEBFIO_MOUNTU8    0x4000     //mount option iocharset=utf8 specified or as default//~vb2eI~
	#define FEBFIO_MOUNTU8CV  0x8000     //mount option iocharset=utf8 specified or as default//~vb2eI~
#endif                                                             //~vb2eI~
//**************************************************************** //~v08lI~
int func_browse_file2(PUCLIENTWE Ppcw,int Poptopd);                //~v08lI~
//***********************************************************
PULINEH filealloclh(UCHAR Ptype,int Pdatalen);
//*******************************************************
int  fileexpandbuff(PULINEH Pplh,int Plen);                     //~v046R~
//****************************************************************
void filefreeplh(PULINEH Pplh,int Popt);
//****************************************************************
//#define FILE_OPEN_BIN     0x0100                                 //~v576R~
//#define FILE_OPEN_APPEND  0x0200       //append mode open        //~v576R~
//#define FILE_OPEN_OUT     0x007f                                 //~v576R~
//#define FILE_NOSPLITMSG   0x1000       //no split msg by filegetline//~v576R~
//#ifdef UNX                                                       //~v576R~
//int filefindopen(UCHAR *Ppfile,FILEFINDBUF3 *Ppfstat3,int Popt,  //~v576R~
//                FILE** Pphfile,int Pmsgopt,UCHAR *Ptempalias);   //~v576R~
//#else                                                            //~v576R~
//int filefindopen(UCHAR *Ppfile,FILEFINDBUF3 *Ppfstat3,int Popt,  //~v576R~
//                FILE** Pphfile,int Pmsgopt);                     //~v576R~
//#endif                                                           //~v576R~
//                                                                 //~v576R~
//****************************************************************//~5125I~
int filesrchpfh(UCHAR *Ppfile,UCHAR *Pfullpath,PUFILEH *Pppfh); //~5125I~
//**************************************************************** //~v11NI~
//int filesrchpfh2(PUCLIENTWE Ppcw,UCHAR *Ppfile,UCHAR *Pfullpath,PUFILEH *Pppfh);//~v60sR~
int filesrchpfh2(PUCLIENTWE Ppcw,UCHAR *Ppfile,UCHAR *Pfullpath,PUFILEH *Pppfh,UCHAR Popt);//~v60sR~
//**************************************************************** //~vb2eI~
int filesrchpfhCP(int Pcpopt,PUCLIENTWE Ppcw,UCHAR *Ppfile,UCHAR *Pfullpath,PUFILEH *Pppfh,UCHAR Popt,int *Ppcprc);//~vb2eI~
#define FSPFHCPO_PFH2             0x01            //call filesrchpfh2//~vb2eI~
#ifdef LNX                                                         //~vb2nI~
#define FSPFHCPO_NOCHKMOUNT       0x02            //no mountchk    //~vb2eI~
#endif                                                             //~vb2nI~
                                                                   //~vb2eI~
#ifdef LNX                                                         //~vb2nI~
#define FSPFHCPRC_MOUNTU8       0x01           		//device iocharset is utf8//~vb2eR~
#define FSPFHCPRC_MOUNTU8CV     0x02           		//filename translated to u8//~vb2eI~
#endif                                                             //~vb2nI~
//*******************************************************       //~5223I~
void fileresetfindctr(void);                                    //~5223I~
//*******************************************************          //~v60jI~
//int fileresettabctr(void);                                       //~v8@2R~
int fileresettabctr(int Popt,PUFILEH Ppfh,int tabctr);             //~v8@2I~
//****************************************************************//~v03uI~
void filefreepfh(PUFILEH Ppfh);                                 //~v03uI~
//****************************************************************    //~v06nI~
int fileeditso(PUCLIENTWE Ppcw);                                      //~v06tR~
//**************************************************************** //~v0baI~
int fileclosefree2(PUFILEH Ppfh);                                  //~v0baI~
