//*CID://+vbi3R~:                            update#=  123;        //~vbi3R~
//*************************************************************
//* xeini3.c
//*************************************************************
//vbi3:180211 supprt command history list                          //~vbi3I~
//vb5g:160918 (LNX-CONS:BUG)inigetopt cleared NP char              //~vb5gI~
//vb5f:160918 (XXE:BUG)inigetopt cleared combine altch initialized by xeopt.h//~vb5fI~
//vb5b:160913 additional to vb54, DBCS space altch is changable by TAB cmd//~vb5bI~
//vb54:160903 TAB cmd new option to set altch; TAB {on|off} [altch1 [altch2]]//~vb54I~
//vb4r:160811 (XXE) v4f for XXE((ULIB:v6Ei)specify ligature on/off,combine on/of line by line(used for edit/filename  panel))//~vb4rI~
//vb4n:160808 (LNX)UNPR char was lost when change to split mode    //~vb4nI~
//vb2E:160229 LNX64 compiler warning                               //~vb2EI~
//vb06:150313 (BUG)others for \\.\; change strategy(del vb03 to vb05),set to UFHfilename without \\.\ ;//~vb06R~
//vb05:150313 (BUG)others for \\.\(inisave cur dir)                //~vb05I~
//vafs:120630 by ulib:v6h0(_MAX_PATH:4096) inifilesize was changed;use old value(save fullpath name upto the size)//~vafsI~
//vafc:120607 C4701 warning(used uninitialized variable) by VC6    //~vafcI~
//va70:000701 LP64 option support. at first chk PTR sz(ini file comaptibility)//~va70I~
//va6G:100719 "xe *" err when ?mx option appended(all enclosed by quotation by the reson of space embeding)//~va6GR~
//va3s:100219 simple split mode like as windows. single write combining char when split mode.//~va3sI~
//            visibility depends to curses. user select split or combine mode.//~va3sI~
//            shadow is another option by opt cmd                  //~va3sI~
//va3h:100207 try ligature for also win32 console version          //~va3hI~
//va3e:100207 (LNX)Console version:to display combine char is not stable. add 3rd option to set unprintable. by A+":"//~va3eI~
//va0x:090920!kbd mode change(A+u)                                 //~va0xI~
//v7ab:081107 (Win)remote filename convention support(\\ipaddr\...)//~v7abI~
//v792:080714 (BUG) rctl option is lost in 2nd session             //~v792I~
//v779:071207 (UTF)do not clear locale info on inifile for xeu(v91d)//~v779I~
//v76g:070620 utility panel(3.14:grep and 3.12:compare);f5:open dirlist, dlcmd "^":send//~v76gI~
//v74E:070315 BOUNDS cmd support                                   //~v71vI~
//v71v:061022 not fixed(PAGE) scroll type for =0.1/2/3             //~v71vI~
//v64t:050705 (XXE)xxe support;different ini save file name from console mode xe_save_.gtk//~v64tI~
//v64p:050624 (LNX)xxe support;bypass restore msg(gxe set always -r)//~v64pI~
//v60n:050129 (BUG)EOLchar not saved to ini,save also FOLDchar also.//~v60nI~
//v60k:050129 (BUG)GOPT4XLINENO is not recovered even if changed by "S" option//~v60kI~
//v56s:040410 (WXE)clear init restore dir to avoid err msg each start time of WXE//~v56SI~
//            (WXE implicitly specify /R option)                   //~v56SI~
//v55j:040215 (LNX)use ctl+char as alternative of Shift+xx         //~v55jI~
//v55c:040208 (WXE)distingush L-CTL/R-CTL & report R-CTL           //~v55cI~
//v54S:040125 add opt cmd:beep on/off                              //~v54SI~
//v50M:030208 dos cmd;save/restore buffsz parm to ini file         //~v50MI~
//v50d:021215 (WXE)skip pwd restore msg                            //~v50dI~
//v509:021207 uchdir interface changed by udirwalk performance tuning//~v509I~
//v48f:020504 more key for macro function(not only PFn but also A+q,A+a and 1 byte char)//~v48fI~
//v47X:020413 mac file support(eol=0x0d) /Mm                       //~v47XI~
//v47w:020317 (BUG)/ek cmd not saved for last file edit option "xe *"//~v47wI~
//v44m:011204 option of upper/lower hex code display               //~v44mI~
//v440:011125 browse hex                                           //~v440I~
//v43z:011124 7bit dump mode initial value is on for AIX           //~v43zI~
//v43y:011122 7bit dump mode                                       //~v43yI~
//v41e:010804 xe * (last edit file) support for cobol              //~v41eI~
//v40f:010522 AIX support:no pragma pack supported                 //~v40fR~
//v20y:001028 new function:filename selection on menu 1/2 name list//~v20yR~
//v20s:001015 (BUG)err msg of color change N/A when XE!SAVE! not exist.//~v20sI~
//v19g:000904 LINUX support(XE!SAVE!-->xe_save_; ! has mean to bash)//~v19gR~
//v196:000902 LINUX support(drop drive func;uchdrive/ugetdrive)    //~v196I~
//v11T:990905 (BUG of v11z):int size cause version unmatch with dos and others//~v11TI~
//v11A:990821 edit option /N(lineno type) is conflict with /N(yes/no) option//~v11AI~
//v11z:990821 support filename=* (last closed file) on cmd line    //~v11zI~
//v11y:990821 support /R option to restore previous default drv/directory//~v11yI~
//v10X:990605 hex digit lineno display for binary file             //~v10XI~
//v10E:990417 another width value save for edit                    //~v10EI~
//v10w:990410 display width for eah text and binary                //~v10wI~
//v10m:990322 binary mode specification change /Mx-->/Mb,and save width once used//~v10mI~
//            until next explicit specification.(save also to sav file)//~v10mI~
//v0ij:980625 pfk cmd support(save to ini)                         //~v0ijI~
//v0g1:971207 print parm by short filename option(opt plfn on/off) //~v0g1I~
//v0f0:971010 long filename support                                //~v0f0I~
//            win95 alias dir list option                          //~v0f0I~
//v09e:970517:update  line search by *u (identify by offset==-1)   //~v09eI~
//            (inserch acronym between fcmd parm and cmd stack)    //~v09eI~
//v086:961024:it can be share xe!save! file(int size)              //~v086I~
//v085:961024:W95 VC                                               //~v085I~
//v07s:960825:new ulib.h/ulibdef.h(no need base def by os2.h)      //~v07sI~
//            to speed up compile,drop include(caused by WIN95 modify)//~v07sI~
//v075:960608:color option                                         //~v075I~
//v06H:960421:(BUG of v064)effect disappear when twice restarted   //~v06HR~
//            tabdisplay flag,nocid flag,tab ctr need set to also ini variable//~v06HR~
//            move saveini to ini3.c                               //~v06HR~
//v06z:960407:stdout work last used seqno save to xe!SAVE!            //~v06zI~
//v06n:960320:menu option 6(cmd) support                        //~v06nI~
//v069:960224:linenosz changeable for edit/browse(save/restore linenosz)//~6224I~
//v065:960217:save also cmd history to XE!SAVE!                 //~6217I~
//v064:960217:split inifile for Ginitscroll/Giniopt_/Ginifiletabskip
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
//*************************************************************
#ifdef DOS
#else
//  #define INCL_BASE                                              //~v07sR~
//  #include <os2.h>                                               //~v07sR~
#endif
//*******************************************************
#include <ulib.h>
#include <uque.h>
#include <ualloc.h>
#include <uerr.h>
#include <ufile.h>                                              //~6225I~
#include <ustring.h>                                               //~v7abI~
#include <utrace.h>                                                //~vafcI~
//#include <ufilew.h>                                                //~vb05I~//~vb06R~

#include "xe.h"
#include "xescr.h"
#include "xefile.h"
#include "xefcmd2.h"
#include "xefcmd23.h"                                              //~v74ER~
#include "xesub.h"
#include "xeini3.h"
#include "xefunc2.h"                                            //~6217I~
#include "xekbd.h"                                                 //~v0ijI~
#include "xepan.h"                                                 //~v20yI~
#include "xepan2.h"                                                //~v76gI~
#include "xepan22.h"                                               //~v20yI~
#include "xeopt.h"                                                 //~v44mI~
#include "xefunc.h"                                                //~v50MI~
#include "xedcmd2.h"                                               //~v50MI~
//*******************************************************
#ifdef UNX                                                         //~v19gI~
  #ifdef XXE                                                       //~v64tI~
	#define INISAVEFILE "xe_save_.xxe"                             //~v64tI~
  #else                                                            //~v64tI~
	#define INISAVEFILE "xe_save_"                                 //~v19gI~
  #endif                                                           //~v64tI~
#else                                                              //~v19gI~
	#define INISAVEFILE "XE!SAVE!"                                 //~v19gR~
#endif                                                             //~v19gI~
#ifdef LNX                                                         //~vafsI~
	#define INI_MAX_PATH  _MAX_PATH_FOR_INIFILE     //to keep xe_SAVE_ file size//~vafsI~
#else                                                              //~vafsI~
    #define INI_MAX_PATH  _MAX_PATH                                //~vb5gR~
#endif                                                             //~vafsI~
//*******************************************************
typedef struct _UINISAVE {              //option save
                    UCHAR   opt;        //for Gopt
                    UCHAR   opt2;       //for Gopt2
                    UCHAR   opt3;       //for Gopt3
                    UCHAR   opt4;       //for Gopt4                //~v0g1R~
                    UCHAR   linenoszb;  //for Glinenoszb        //~6224R~
                    UCHAR   linenosze;  //for Glinenosze        //~6224I~
                    UCHAR   linenoszc;  //for Glinenoszc        //~v06nI~
                    UCHAR   lastsono ;  //for Gllastsono              //~v06zI~
//                  long    filetabskip;//for Gfiletabskip         //~va70R~
                    INT4    filetabskip;//for Gfiletabskip         //~va70I~
//                  long    initscroll[4]; //for Ginitscroll       //~va70R~
                    INT4    initscroll[4]; //for Ginitscroll       //~va70I~
                    UCHAR   pallassigntbl[PAL_MAXENTRY*2];//pallette no assign tbl//~v075I~
                    UCHAR   rsv2[2];    //pdding                   //~v0ijR~
#define versionflag         rsv2[0]         //pdding               //~v0ijR~
#define SAVEVER_FKCT 0x01                   //fkct saved           //~v0ijR~
#define SAVEVER_2NDH 0x02                   //2nd hdr saved        //~v10mI~
#define SAVEVER_V103 0x04   //Chng dir,last file etc               //~v11yI~
#define SAVEVER_FLST 0x08   //file name list for menu 1/2          //~v20yI~
#define SAVEVER_SCKT 0x10   //shortcutkey saved                    //~v48fI~
#define SAVEVER_UTIL 0x20   //utility panel data                   //~v76gI~
#define SAVEVER_UIS4 0x40   //Use UINISAVE4                        //~v7abI~
#define opt5                rsv2[1]         //Gopt5                //~v55jI~
                    UCHAR   pallette[16]; //color reg assign tbl for pallete no//~v075I~
                } UINISAVE;
#define UINISAVESZ (sizeof(UINISAVE))
                                                                   //~v10mI~
#ifdef AIX                                                         //~v40fR~
#else                                                              //~v40fR~
#pragma pack(1)                                                    //~v10mI~
#endif                                                             //~v40fR~
typedef struct _UINISAVE2 {             //option save2             //~v10mI~
                    USHORT  fhwidth;     //binary file display width//~v10wR~
                    USHORT  fhwidthtxt;  //text file display width //~v10wI~
                    USHORT  fhwidthtxtedit;//text file display width//~v10EI~
//                  UCHAR   rsv[250];                              //~v440R~
                    USHORT  fhxwidth;//hex mode width              //~v440I~
//                  UCHAR   rsv[248];                              //~v44mR~
                    UCHAR   optflag;                               //~v44mR~
//                  UCHAR   rsv[247];                              //~v47XR~
                    UCHAR   UIS2lastfflag6;                        //~v47XI~
//                  UCHAR   rsv[246];                              //~v50MR~
                    UCHAR   UIS2cmdbuffsz_row;                     //~v50MR~
                    UCHAR   UIS2cmdbuffsz_col;                     //~v50MR~
//                  UCHAR   rsv[244];                              //~v60nR~
                    UCHAR   UIS2eolid;                             //~v60nI~
                    UCHAR   UIS2eolcontid;                         //~v60nI~
//                  UCHAR   rsv[242];                              //~v71vR~
//                  UCHAR   rsv[2];                                //~v779R~
                    UCHAR   optflag2;  //Goptopt2                  //~v779I~
//                  UCHAR   rsv[1];                                //~v779I~//~va3eR~
                    UCHAR   optflag3;  //Goptopt3                  //~va3eR~
//                  long    UIS2scrollfkt;  //Ginitscroll[4]       //~va70R~
                    INT4    UIS2scrollfkt;  //Ginitscroll[4]       //~va70I~
//                  UCHAR   rsv2[236];                             //~v779I~
                    UCHAR   UIS2localecode[32];                    //~v779I~
//                  UCHAR   rsv2[204];                             //~va3sR~
//                  long    UIS2combaltch;  //Goptcombaltch        //~va70R~
                    INT4    UIS2combaltch;  //Goptcombaltch        //~va70I~
//                  UCHAR   rsv2[200];                             //~vb54R~
//                  INT4    UIS2tabaltch[2];                       //~vb5bR~
                    INT4    UIS2tabaltch[3];                       //~vb5bI~
//                  UCHAR   rsv2[192];                             //~vb5bR~
                    UCHAR   rsv2[188];                             //~vb5bI~
                } UINISAVE2;                                       //~v10mI~
#define UINISAVE2SZ (sizeof(UINISAVE2))                            //~v10mI~
                                                                   //~v10mI~
typedef struct _UINISAVE3 {             //option save3             //~v11yR~
                    UCHAR   UIS3acr[4];             //acronym      //~v11yR~
//                  UCHAR   UIS3dir[_MAX_PATH];     //curr dir     //~v11yI~//~vafsR~
                    UCHAR   UIS3dir[INI_MAX_PATH];     //curr dir  //~vafsI~
//                  UCHAR   UIS3lastfnm[_MAX_PATH];     //curr dir //~v11zI~//~vafsR~
                    UCHAR   UIS3lastfnm[INI_MAX_PATH];     //curr dir//~vafsI~
                    UCHAR   UIS3lastfmode;     //edit/browse       //~v11zI~
                    UCHAR   UIS3lastfflag3;                        //~v11zI~
                    UCHAR   UIS3lastfflag4;                        //~v11zI~
//                  UCHAR   rsv;                                   //~v41eR~
                    UCHAR   UIS3lastfflag5;                        //~v41eI~
                    USHORT  UIS3lastfwidth;                        //~v11TR~
                } UINISAVE3;                                       //~v11yI~
#define UINISAVE3SZ (sizeof(UINISAVE3))                            //~v11yI~
                                                                   //~v11yI~
typedef struct _UINISAVE4 {             //option save3             //~v7abI~
                    UCHAR   UIS4acr[4];             //acronym      //~v7abI~
//                  UCHAR   UIS4cdUNC[_MAX_PATH];     //curr dir   //~v7abI~//~vafsR~
                    UCHAR   UIS4cdUNC[INI_MAX_PATH];     //curr dir//~vafsI~
                    UCHAR   UIS4rsv[512];     //curr dir           //~v7abI~
                } UINISAVE4;                                       //~v7abI~
#define UINISAVE4SZ (sizeof(UINISAVE4))                            //~v7abI~
                                                                   //~v7abI~
#ifdef AIX                                                         //~v40fR~
#else                                                              //~v40fR~
#pragma pack()                                                     //~v10mI~
#endif                                                             //~v40fR~
//*******************************************************
static UCHAR Ssavefile[]=WORKDIRPATHID INISAVEFILE;                //~v54SR~
static UCHAR Sfileid[]=INISAVEFILE "\x01\xff";                     //~v54SR~
static UCHAR Scurdir[_MAX_PATH];                                   //~v11yR~
static UCHAR ScdUNC[_MAX_PATH];	//UNCpath once set by CD cmd       //~v7abI~
static UCHAR Slastfnm[_MAX_PATH];                                  //~v11zI~
static UCHAR Slastfmode=0;    //'E'(edit) or 'B'(browse)           //~v54SR~
static UCHAR Slastfflag3=0;   //UFHflag3                           //~v54SR~
static UCHAR Slastfflag4=0;   //UFHflag4                           //~v54SR~
static UCHAR Slastfflag5=0;   //UFHflag5                           //~v54SR~
static UCHAR Slastfflag6=0;   //UFHflag6                           //~v54SR~
static int   Slastfwidth=0;   //UFHflag4                           //~v54SR~
//*******************************************************       //~6224I~
int iniacronymwrite(FILE *Pfh);                                 //~6224I~
int iniacronymchk(char *Pfile,FILE *Pfh);                       //~6224I~
void inisave(void);                                                //~v06HR~
//****************************************************************
// inisaveopt
// save option and FIND word
//* parm  :none
//* ret   :rc
//****************************************************************
int inisaveopt(void)
{
    UCHAR fpath[_MAX_PATH];                                        //~v54SR~
    FILE *fh;
    UINISAVE  saveopt;
    UINISAVE2  saveopt2;                                           //~v10mI~
    UINISAVE3  saveopt3;                                           //~v11yI~
    UINISAVE4  saveopt4;                                           //~v7abI~
//  UINT  len;                                                     //~vb2ER~
    size_t len;                                                    //~vb2EI~
    int rc=0;
    int pathlen;                                                   //~vafsI~
//*********************************
//  if (!UCBITCHK(Gprocstatus,GPROCSINIUPDATE))//need write ini at term//~6217R~
//      return 0;                                               //~6217R~
    if (filefind(Ssavefile,fpath,0,FFNONFMSG)>4)//no need fstat3   //~v54SR~
        return 8;   //rc=4 not found
    if (!(fh=fileopen(fpath,"wb")))                                //~v54SR~
        return 12;
//*fileid
    rc=iniacronymwrite(fh);                                     //~6224R~
//*option
    if (!rc)
    {
        memset(&saveopt,0,UINISAVESZ);                                //~v06zR~
        memset(&saveopt2,0,UINISAVE2SZ);                           //~v10mI~
        UCBITON(saveopt.versionflag,SAVEVER_FKCT);  //fkct save version//~v0ijI~
        UCBITON(saveopt.versionflag,SAVEVER_2NDH);  //fkct save version//~v10mI~
        UCBITON(saveopt.versionflag,SAVEVER_V103);  //CD,last file etc//~v11yI~
        UCBITON(saveopt.versionflag,SAVEVER_FLST);  //filename list//~v20yI~
        UCBITON(saveopt.versionflag,SAVEVER_SCKT);  //shortcut key //~v48fI~
        UCBITON(saveopt.versionflag,SAVEVER_UTIL);  //utility panel data//~v76gI~
        UCBITON(saveopt.versionflag,SAVEVER_UIS4);  //use UINISAVE4 data//~v7abI~
        saveopt.opt=(UCHAR)(Giniopt & GOPTTABDISPLAY);//except exe parm
        if (UCBITCHK(Gopt4,GOPT4RCTLCMD))	//to be write to inifile//~v55cR~
        {                                                          //~v792I~
	        if (UCBITCHK(Gopt,GOPTRCTLENTER))//effective at next session//~v55cR~
	        	UCBITON(saveopt.opt,GOPTRCTLENTER);//effective at next session//~v55cI~
        }                                                          //~v792I~
        else                                                       //~v792I~
		if (Gotheropt & GOTHERO_SVOPTRCTL) 	//rctl on at start     //~v792I~
	        UCBITON(saveopt.opt,GOPTRCTLENTER);//effective at next session ignor /nr cmd line option//~v792I~
        saveopt.opt2=(UCHAR)(Giniopt2 & GOPT2NOCID);//except exe parm
//      saveopt.opt3=(UCHAR)(Gopt3 & (GOPT3UNDELFREE|GOPT3UNDELLEAVE));//~v0f0R~
        saveopt.opt3=(UCHAR)(Gopt3 &                               //~v0f0I~
             (GOPT3UNDELFREE|GOPT3UNDELLEAVE|GOPT3W95ALIAS));      //~v0f0I~
        saveopt.opt4=(UCHAR)(Gopt4 &                               //~v0g1I~
//            GOPT4W95ALIASP);                                     //~v10XR~
                            (GOPT4XLINENO                          //~v10XI~
                            |GOPT47BIT                             //~v43yR~
                            |GOPT47BITCMD                          //~v43zR~
                            |GOPT4NOBEEP                           //~v54SI~
                            |GOPT4NOBEEPCMD                        //~v54SI~
                            |GOPT4W95ALIASP));                     //~v10XI~
        saveopt.opt5=Gopt5;                                        //~v55jI~
        saveopt.linenoszb=Glinenoszb;                           //~6224R~
        saveopt.linenosze=Glinenosze;                           //~6224I~
        saveopt.linenoszc=Glinenoszc;                           //~v06nI~
        saveopt.lastsono =Glastsono ;                                 //~v06zI~
        saveopt.filetabskip=(long)Ginifiletabskip;//ignore exe parm//~v086R~
        saveopt.initscroll[0]=(long)Ginitscroll[0];                //~v086R~
        saveopt.initscroll[1]=(long)Ginitscroll[1];                //~v086R~
        saveopt.initscroll[2]=(long)Ginitscroll[2];                //~v086R~
        saveopt.initscroll[3]=(long)Ginitscroll[3];                //~v086R~
        memcpy(saveopt.pallassigntbl,Gpallassigntbl,sizeof(Gpallassigntbl));//~v075R~
        memcpy(saveopt.pallette,Gpallette,16); //color reg assign tbl for pallete no//~v075I~
        len=fwrite(&saveopt,1,UINISAVESZ,fh);
        if (len!=UINISAVESZ)
            rc=16;
    }
//*fileid   for structer version change                         //~6224I~
    if (!rc)                                                    //~6224I~
        rc=iniacronymwrite(fh); //middle acronym                //~6224I~
//*find word
    if (!rc)
        rc=fcmdwfparm(fh);      //write find word
    if (!rc)                                                       //~v09eI~
        rc=iniacronymwrite(fh); //middle acronym                   //~v09eI~
//*command history
    if (!rc)                                                    //~6217R~
        rc=funcwcmdstack(fh);   //write cmd stack               //~6217R~
    if (!rc)
        rc=iniacronymwrite(fh); //last acronym                  //~6224I~
//*fkey cmd                                                        //~v0ijI~
    if (!rc)                                                       //~v0ijI~
        rc=kbdwfkct(fh);    //write func key cmd tbl               //~v0ijI~
    if (!rc)                                                       //~v48fI~
        rc=kbdwsckt(fh);    //write shortcut key tbl               //~v48fI~
//2nd hdr                                                          //~v10mM~
    if (!rc)                                                       //~v10mM~
        rc=iniacronymwrite(fh);                                    //~v10mI~
    if (!rc)                                                       //~v10mM~
    {                                                              //~v10mM~
        saveopt2.fhwidth=Gfhwidth;                                 //~v10mM~
        saveopt2.fhwidthtxt=Gfhwidthtxt;                           //~v10wI~
        saveopt2.fhwidthtxtedit=Gfhwidthtxtedit;                   //~v10EI~
        saveopt2.fhxwidth=Gfhxwidth;                               //~v440I~
        saveopt2.optflag=Goptopt;                                  //~v44mR~
        saveopt2.optflag2=Goptopt2;                                //~v779I~
        saveopt2.optflag3=Goptopt3;                                //~va3eI~
        saveopt2.UIS2lastfflag6=Slastfflag6;                       //~v47XI~
        saveopt2.UIS2cmdbuffsz_row=(UCHAR)Gcmdbuffsz_row;          //~v50MR~
        saveopt2.UIS2cmdbuffsz_col=(UCHAR)Gcmdbuffsz_col;          //~v50MR~
        saveopt2.UIS2eolid=(UCHAR)Gopteol;                         //~v60nI~
        saveopt2.UIS2eolcontid=(UCHAR)Gopteolcont;                 //~v60nI~
        saveopt2.UIS2scrollfkt=(long)Ginitscroll[4];               //~v71vR~
        strncpy(saveopt2.UIS2localecode,Glocalecode,sizeof(saveopt2.UIS2localecode));//~v779I~
#ifdef UTF8UCS2                                                    //~va3sI~
//	#ifdef LNX                                                     //~vb4rR~
  	#if defined(LNX) && !defined(XXE)                              //~vb4rI~
        saveopt2.UIS2combaltch=(Goptcombaltch & 0xffff)|(GoptcombaltchNP<<16);     //UNPR char + split mode(ITSELF etc)//~vb4nR~
    #else                                                          //~vb4nR~
        saveopt2.UIS2combaltch=Goptcombaltch;                      //~va3sI~
    #endif                                                         //~vb4nR~
#endif                                                             //~va3sI~
        memcpy(saveopt2.UIS2tabaltch,Gopttabaltch,sizeof(Gopttabaltch));//~vb54R~
        len=fwrite(&saveopt2,1,UINISAVE2SZ,fh);                    //~v10mM~
        if (len!=UINISAVE2SZ)                                      //~v10mM~
            rc=16;                                                 //~v10mM~
    }                                                              //~v10mM~
    if (!rc)                                                       //~v0ijI~
        rc=iniacronymwrite(fh); //last acronym                     //~v0ijI~
    if (!rc)                                                       //~v11yI~
    {                                                              //~v11yI~
        strcpy(saveopt3.UIS3acr,"CD=");                            //~v11yR~
//      memcpy(saveopt3.UIS3dir,Scurdir,sizeof(saveopt3.UIS3dir)); //~v11yI~//~vafsR~
        UstrncpyZ(saveopt3.UIS3dir,Scurdir,sizeof(saveopt3.UIS3dir));//~vafsI~
        if (strlen(Scurdir)>=sizeof(saveopt3.UIS3dir))             //~vafsI~
        {                                                          //~vafsI~
        	pathlen=PATHLEN(Scurdir);                              //~vafsI~
        	if (pathlen>0)                                         //~vafsI~
            	*(saveopt3.UIS3dir+pathlen-1)=0;	//cut path in the save area//~vafsI~
        }                                                          //~vafsI~
//      memcpy(saveopt3.UIS3lastfnm,Slastfnm,sizeof(saveopt3.UIS3lastfnm));//~v11zI~//~vafsR~
        UstrncpyZ(saveopt3.UIS3lastfnm,Slastfnm,sizeof(saveopt3.UIS3lastfnm));//~vafsI~
        if (strlen(Slastfnm)>=sizeof(saveopt3.UIS3lastfnm))        //~vafsI~
        {                                                          //~vafsI~
        	pathlen=PATHLEN(Slastfnm);                             //~vafsI~
        	if (pathlen>0)                                         //~vafsI~
            	*(saveopt3.UIS3lastfnm+pathlen-1)=0;	//cut path in the save area//~vafsI~
        }                                                          //~vafsI~
        saveopt3.UIS3lastfmode=Slastfmode;                         //~v11zI~
        saveopt3.UIS3lastfflag3=Slastfflag3;                       //~v11zI~
        saveopt3.UIS3lastfflag4=Slastfflag4;                       //~v11zI~
        saveopt3.UIS3lastfflag5=Slastfflag5;                       //~v41eI~
        saveopt3.UIS3lastfwidth=(USHORT)Slastfwidth;               //~v11TR~
        len=fwrite(&saveopt3,1,UINISAVE3SZ,fh);                    //~v11yI~
        if (len!=UINISAVE3SZ)                                      //~v11yI~
            rc=16;                                                 //~v11yI~
    }                                                              //~v11yI~
    if (!rc)                                                       //~v11yI~
        rc=iniacronymwrite(fh); //last acronym                     //~v11yI~
//filename list for menu 1/2                                       //~v20yI~
    if (!rc)                                                       //~v20yI~
        rc=pan300wstack(fh);    //write filename list              //~v20yI~
    if (!rc)                                                       //~v20yI~
        rc=iniacronymwrite(fh); //last acronym                     //~v20yI~
    if (!rc)                                                       //~v76gI~
        rc=panutiliniput(fh);   //read filename list               //~v76gI~
    if (!rc)                                                       //~v76gI~
        rc=iniacronymwrite(fh); //last acronym                     //~v76gI~
    if (!rc)                                                       //~v7abI~
    {                                                              //~v7abI~
    	memset(&saveopt4,0,UINISAVE4SZ);                           //~v7abR~
        strcpy(saveopt4.UIS4acr,"SV4");                            //~v7abI~
//      memcpy(saveopt4.UIS4cdUNC,ScdUNC,sizeof(saveopt4.UIS4cdUNC));//~v7abR~//~vafsR~
        UstrncpyZ(saveopt4.UIS4cdUNC,ScdUNC,sizeof(saveopt4.UIS4cdUNC));//~vafsI~
        if (strlen(ScdUNC)>=sizeof(saveopt4.UIS4cdUNC))            //~vafsI~
        {                                                          //~vafsI~
        	pathlen=PATHLEN(ScdUNC);                               //~vafsI~
        	if (pathlen>0)                                         //~vafsI~
            	*(saveopt4.UIS4cdUNC+pathlen-1)=0;	//cut path in the save area//~vafsR~
        }                                                          //~vafsI~
        len=fwrite(&saveopt4,1,UINISAVE4SZ,fh);                    //~v7abR~
        if (len!=UINISAVE4SZ)                                      //~v7abR~
            rc=16;                                                 //~v7abI~
    }                                                              //~v7abI~
    if (!rc)                                                       //~v7abI~
        rc=iniacronymwrite(fh); //last acronym                     //~v7abI~
    if (rc)
        uerrmsg("%s write err",
                "%s 出力エラー",
                fpath);                                            //~v54SR~
    fileclose(fpath,fh);                                           //~v54SR~
    fcmdbndstfree(); //free bndstbl                                //~v74ER~
    return rc;
}//inisaveopt
//**************************************************************** //~v11yI~
// inisavecd                                                       //~v11yI~
// save default drive change,cur directory change to restore by /R option//~v11yI~
//* parm1 :fullpath name                                           //~v11yR~
//* ret   :none                                                    //~v11yR~
//**************************************************************** //~v11yI~
void inisavecd(UCHAR *Pfullpath)                                   //~v11yR~
{                                                                  //~v11yI~
//*********************************                                //~v11yI~
    strncpy(Scurdir,Pfullpath,sizeof(Scurdir)-1);                  //~v11yR~
#ifdef WINREMOTESUPP     //\\xxx\yy support                        //~v7abI~
    if (WIN_ISREMOTEPATH(Pfullpath))                               //~v7abR~
    	UstrncpyZ(ScdUNC,Pfullpath,sizeof(ScdUNC)-1);              //~v7abI~
#endif                                                             //~v7abI~
    return;                                                        //~v11yI~
}//inisavecd                                                       //~v11yR~
//**************************************************************** //~v11zI~
// inisavelastfile                                                 //~v11zR~
// save last closed filename for "XE *"                            //~v11zI~
//* parm1 :pfc                                                     //~v11zR~
//* ret   :none                                                    //~v11zI~
//**************************************************************** //~v11zI~
void inisavelastfile(PUFILEC Ppfc)                                 //~v11zR~
{                                                                  //~v11zI~
    PUFILEH pfh;                                                   //~v11zI~
//*********************************                                //~v11zI~
    pfh=Ppfc->UFCpfh;                                              //~v11zI~
    switch(pfh->UFHtype)                                           //+vbi3R~
    {                                                              //~vbi3I~
    case UFHTCLIPBOARD:          //clipboard file in work dir      //~vbi3I~
    case UFHTKFI      :          //key func ini file in work dir   //~vbi3I~
    case UFHTSTDOUT   :          //first opened as cmd stdout      //~vbi3I~
    case UFHTTEMPWK   :          //TEMP work for partial edit etc  //~vbi3I~
    case UFHTTEMPWK2  :          //TEMP work for filenamelist find support//~vbi3I~
    case UFHTCMDHIST  :          //TEMP work for filenamelist find support//~vbi3I~
        return;                                                    //~vbi3I~
    }                                                              //~vbi3I~
    if (UCBITCHK(Ppfc->UFCflag,UFCFBROWSE)) //not browse mode      //~v11zR~
        Slastfmode='B';                                            //~v11zI~
    else                                                           //~v11zI~
        Slastfmode='E';                                            //~v11zI~
    strncpy(Slastfnm,pfh->UFHfilename,sizeof(Slastfnm)-1);         //~v11zR~
    Slastfflag3=pfh->UFHflag3;                                     //~v11zI~
    Slastfflag4=pfh->UFHflag4;                                     //~v11zI~
    Slastfflag5=pfh->UFHflag5;                                     //~v41eI~
    Slastfflag6=pfh->UFHflag6;                                     //~v47XI~
    Slastfwidth=pfh->UFHwidth;                                     //~v11zI~
    return;                                                        //~v11zI~
}//inisavelastfnm                                                  //~v11zI~
//****************************************************************
// inigetopt
// save option and FIND word
//* ret   :rc
//****************************************************************
int inigetopt(void)                                                //~v11yR~
{
    UCHAR fpath[_MAX_PATH];                                        //~v54SR~
    FILE *fh;
    UINISAVE  saveopt={0};                                         //~vafcR~
    UINISAVE2  saveopt2;                                           //~v10mI~
    UINISAVE3  saveopt3;                                           //~v11yI~
    UINISAVE4  saveopt4;                                           //~v7abR~
//  UINT  len;                                                     //~vb2ER~
    size_t  len;                                                   //~vb2EI~
    int rc=0;
//*********************************
    inisave();      //save for err return                          //~v06HR~
    if (filefind(Ssavefile,fpath,0,FFNONFMSG)>=4)//no need fstat3  //~v54SR~
        return 8;   //rc=4 not found
    if (!(fh=fileopen(fpath,"rb")))                                //~v54SR~
        return 12;
    rc=iniacronymchk(fpath,fh);  //top acronym                     //~v54SR~
//*option
    if (!rc)                                                    //~6224I~
    {                                                           //~6224I~
        len=fread(&saveopt,1,UINISAVESZ,fh);                    //~6224R~
        if (len!=UINISAVESZ)                                    //~6224R~
            rc=16;                                              //~6224R~
    }                                                           //~6224I~
    if (!rc)
    {
        Gopt =(UCHAR)(Gopt  & ~GOPTTABDISPLAY);  //clear other than saved bit
        Gopt =(UCHAR)(Gopt  |  saveopt.opt);
        Gopt2=(UCHAR)(Gopt2 & ~GOPT2NOCID);
        Gopt2=(UCHAR)(Gopt2 | saveopt.opt2);
//      Gopt3=(UCHAR)(Gopt3 & ~(GOPT3UNDELFREE|GOPT3UNDELLEAVE));  //~v0f0R~
        Gopt3=(UCHAR)(Gopt3 &                                      //~v0f0I~
                    ~(GOPT3UNDELFREE|GOPT3UNDELLEAVE|GOPT3W95ALIAS));//~v0f0I~
        Gopt3=(UCHAR)(Gopt3 | saveopt.opt3);
        if (UCBITCHK(saveopt.opt4,GOPT47BITCMD))	//set by cmd   //~v43zR~
        	UCBITOFF(Gopt4,GOPT47BIT);	//once reset of xegbl      //~v43zR~
        if (UCBITCHK(saveopt.opt4,GOPT4NOBEEPCMD))	//set by cmd   //~v54SI~
        	UCBITOFF(Gopt4,GOPT4NOBEEP);	//reset ini file effect//~v54SI~
        if (saveopt.opt5 & GOPT5XLINENOS)	//changed by cmd       //~v60kI~
	        Gopt4=(UCHAR)(Gopt4 & ~GOPT4XLINENO);//reset xegbl default setting//~v60kI~
        Gopt4=(UCHAR)(Gopt4 | saveopt.opt4);                       //~v0g1I~
        Gopt5=saveopt.opt5;                                        //~v55jI~
        if (saveopt.opt & GOPTRCTLENTER)                           //~v792I~
			Gotheropt|=GOTHERO_SVOPTRCTL;	//saveopt rctl on      //~v792R~
        Glinenoszb=saveopt.linenoszb;                           //~6224I~
        Glinenosze=saveopt.linenosze;                           //~6224I~
        Glinenoszc=saveopt.linenoszc;                           //~v06nI~
        Glastsono =saveopt.lastsono ;                                 //~v06zI~
        Gfiletabskip=(int)saveopt.filetabskip;                     //~v086R~
        Ginitscroll[0]=(int)saveopt.initscroll[0];                 //~v086R~
        Ginitscroll[1]=(int)saveopt.initscroll[1];                 //~v086R~
        Ginitscroll[2]=(int)saveopt.initscroll[2];                 //~v086R~
        Ginitscroll[3]=(int)saveopt.initscroll[3];                 //~v086R~
        memcpy(Gpallassigntbl,saveopt.pallassigntbl,sizeof(Gpallassigntbl));//~v075R~
        memcpy(Gpallette,saveopt.pallette,16); //color reg assign tbl for pallete no//~v075I~
		Gpallette[0]=0;		//black is fixed,for prev version save file//~v20sI~
        rc=iniacronymchk(fpath,fh);  //middle acronym              //~v54SR~
    }
//*find word                                                    //~6224M~
    if (!rc)                                                    //~6224I~
        rc=fcmdrfparm(fh);      //read find word                //~6224M~
    if (!rc)                                                       //~v09eI~
        rc=iniacronymchk(fpath,fh);  //end acronym                 //~v54SR~
//*command history
    if (!rc)                                                    //~6217R~
        rc=funcrcmdstack(fh);   //read cmd stack                //~6217R~
    if (!rc)
        rc=iniacronymchk(fpath,fh);  //end acronym                 //~v54SR~
//*fkey cmd                                                        //~v0ijI~
    if (UCBITCHK(saveopt.versionflag,SAVEVER_FKCT)) //fkct save version//~v0ijI~
    {                                                              //~v0ijI~
        if (!rc)                                                   //~v0ijR~
            rc=kbdrfkct(fh);    //read cmd stack                   //~v0ijR~
        if (!rc)                                                   //~v48fI~
		    if (UCBITCHK(saveopt.versionflag,SAVEVER_SCKT)) //fkct save version//~v48fI~
            	rc=kbdrsckt(fh);    //read shortcut key tbl        //~v48fI~
        if (!rc)                                                   //~v0ijR~
            rc=iniacronymchk(fpath,fh);  //end acronym             //~v54SR~
    }                                                              //~v0ijI~
//*2nd hdr                                                         //~v10mM~
    if (!rc)                                                       //~v10wR~
        if (UCBITCHK(saveopt.versionflag,SAVEVER_2NDH)) //fkct save version//~v10mM~
        {                                                          //~v10mM~
            len=fread(&saveopt2,1,UINISAVE2SZ,fh);                 //~v10mM~
            if (len!=UINISAVE2SZ)                                  //~v10mM~
                rc=16;                                             //~v10mM~
            else                                                   //~v10mM~
            {                                                      //~v10mM~
                Gfhwidth=saveopt2.fhwidth;                         //~v10mM~
                Gfhwidthtxt=saveopt2.fhwidthtxt;                   //~v10wI~
                Gfhwidthtxtedit=saveopt2.fhwidthtxtedit;           //~v10EI~
                if (saveopt2.fhxwidth)                             //~v440R~
                	Gfhxwidth=saveopt2.fhxwidth;                   //~v440I~
                Goptopt=saveopt2.optflag;                          //~v44mR~
       			Goptopt2=saveopt2.optflag2;                        //~v779I~
       			Goptopt3=saveopt2.optflag3;                        //~va3eI~
#ifdef UTF8UCS2                                                    //~va3sM~
#ifdef W32                                                         //~vb2EI~
        	  if (saveopt2.UIS2combaltch)                          //~vb2EI~
#else                                                              //~vb5fI~
  	#ifdef XXE                                                     //~vb5fI~
        	  if (saveopt2.UIS2combaltch)                          //~vb5fI~
    #endif                                                         //~vb5fI~
#endif                                                             //~vb2EI~
        		Goptcombaltch=saveopt2.UIS2combaltch;              //~va3sM~
//              if (saveopt2.UIS2tabaltch)                         //~vb5bR~
		        	memcpy(Gopttabaltch,saveopt2.UIS2tabaltch,sizeof(Gopttabaltch));//~vb54R~
//	#ifdef LNX                                                     //~vb4rR~
  	#if defined(LNX) && !defined(XXE)                              //~vb4rI~
//        		Goptcombaltch&=0xffff;	//split mode               //~vb4nR~//~vb5gR~
    			if (Goptcombaltch >>16)                            //~vb4nR~
    				GoptcombaltchNP=(Goptcombaltch >>16);          //~vb4nR~
          		Goptcombaltch&=0xffff;	//split mode               //~vb5gI~
    #endif                                                         //~vb4nR~
#endif                                                             //~va3sM~
#ifdef UTF8SUPPH                                                   //~v91sI~//~va0xI~
                xeopt2init();                                      //~v91sI~//~va0xI~
#endif                                                             //~v91sI~//~va0xI~
                Slastfflag6=saveopt2.UIS2lastfflag6;               //~v47XI~
        		Gcmdbuffsz_row=(UCHAR)saveopt2.UIS2cmdbuffsz_row;  //~v50MR~
        		Gcmdbuffsz_col=(UCHAR)saveopt2.UIS2cmdbuffsz_col;  //~v50MR~
		        Gopteol=saveopt2.UIS2eolid;                        //~v60nR~
        		Gopteolcont=saveopt2.UIS2eolcontid;                //~v60nI~
        		if (saveopt2.UIS2scrollfkt)	//at first of version upt this is 0(invalid)//~v71vR~
	        		Ginitscroll[4]=(int)saveopt2.UIS2scrollfkt;    //~v71vI~
                strncpy(Glocalecode,saveopt2.UIS2localecode,sizeof(Glocalecode));//~v779I~
				optsetdisplayeolid();	//set display char         //~v60nI~
				optsetdisplayeolcontid();	//set display char     //~v60nI~
                rc=iniacronymchk(fpath,fh);  //end acronym         //~v54SR~
            }                                                      //~v10mM~
        }                                                          //~v10mM~
//*3rd hdr                                                         //~v11yI~
    if (!rc)                                                       //~v11yI~
        if (UCBITCHK(saveopt.versionflag,SAVEVER_V103)) //cd       //~v11yI~
        {                                                          //~v11yI~
            len=fread(&saveopt3,1,UINISAVE3SZ,fh);                 //~v11yI~
            if (len!=UINISAVE3SZ)                                  //~v11yI~
                rc=16;                                             //~v11yI~
            else                                                   //~v11yI~
            {                                                      //~v11yI~
//              memcpy(Scurdir,saveopt3.UIS3dir,sizeof(Scurdir));  //~v11yI~//~vafsR~
                UstrncpyZ(Scurdir,saveopt3.UIS3dir,sizeof(Scurdir));//~vafsI~
//              memcpy(Slastfnm,saveopt3.UIS3lastfnm,sizeof(Slastfnm));//~v11zI~//~vafsR~
                UstrncpyZ(Slastfnm,saveopt3.UIS3lastfnm,sizeof(Slastfnm));//~vafsI~
                Slastfmode=saveopt3.UIS3lastfmode;                 //~v11zI~
                Slastfflag3=saveopt3.UIS3lastfflag3;               //~v11zI~
                Slastfflag4=saveopt3.UIS3lastfflag4;               //~v11zR~
                Slastfflag5=saveopt3.UIS3lastfflag5;               //~v41eI~
                Slastfwidth=(int)saveopt3.UIS3lastfwidth;          //~v11TR~
                rc=iniacronymchk(fpath,fh);  //end acronym         //~v54SR~
            }                                                      //~v11yI~
        }                                                          //~v11yI~
    if (!rc)                                                       //~v20yI~
        if (UCBITCHK(saveopt.versionflag,SAVEVER_FLST)) //filename list//~v20yI~
        {                                                          //~v20yI~
        	rc=pan300rstack(fh);   //read filename list            //~v20yI~
//          if (rc)                                                //~v76gR~
            if (!rc)                                               //~v76gI~
                rc=iniacronymchk(fpath,fh);  //end acronym         //~v54SR~
        }                                                          //~v20yI~
    if (!rc)                                                       //~v76gI~
        if (UCBITCHK(saveopt.versionflag,SAVEVER_UTIL)) //filename list//~v76gI~
        {                                                          //~v76gI~
        	rc=panutiliniget(fh);   //read filename list           //~v76gI~
            if (!rc)                                               //~v76gR~
                rc=iniacronymchk(fpath,fh);  //end acronym         //~v76gI~
        }                                                          //~v76gI~
//*4th hdr                                                         //~v7abI~
    if (!rc)                                                       //~v7abI~
        if (UCBITCHK(saveopt.versionflag,SAVEVER_UIS4)) //4th struc//~v7abI~
        {                                                          //~v7abI~
            len=fread(&saveopt4,1,UINISAVE4SZ,fh);                 //~v7abI~
            if (len!=UINISAVE4SZ)                                  //~v7abI~
                rc=16;                                             //~v7abI~
            else                                                   //~v7abI~
            {                                                      //~v7abI~
//              memcpy(ScdUNC,saveopt4.UIS4cdUNC,sizeof(ScdUNC));  //~v7abI~//~vafsR~
                UstrncpyZ(ScdUNC,saveopt4.UIS4cdUNC,sizeof(ScdUNC));//~vafsI~
                if (*ScdUNC)                                       //~v7abI~
	        		uchdir(0,ScdUNC);		//save path as current dir of "\:"//~v7abR~
                rc=iniacronymchk(fpath,fh);  //end acronym         //~v7abI~
            }                                                      //~v7abI~
        }                                                          //~v7abI~
    if (rc)
        uerrexit("%s is version unmatch,delete it and restart", //~6224R~
                 "%s のバージョンが違います,削除して再開して下さい",//~6224R~
                 fpath);                                           //~v54SR~
    fileclose(fpath,fh);                                           //~v54SR~
    inisave();      //save for write at term(out of exe parm efect)
    return 0;
}//inigetopt
//**************************************************************** //~v11zI~
// inigetlastfile                                                  //~v11zR~
// save last closed filename for "XE *"                            //~v11zI~
//* parm1 :cmd string output area (filename and opt)               //~v11zR~
//* ret   :mode(E/B)                                               //~v11zR~
//**************************************************************** //~v11zI~
UCHAR inigetlastfile(UCHAR *Pcmdstr)                               //~v11zR~
{                                                                  //~v11zI~
    int len;                                                       //~v11zI~
    UCHAR *pc,*pcm;                                                //~v11zI~
    UCHAR mopt[32];                                                //~v11AR~
//*********************************                                //~v11zI~
    len=(int)strlen(Slastfnm);                                     //~v11zI~
  if (strchr(Slastfnm,' '))	//space embedding                      //~va6GI~
  {                                                                //~va6GI~
  	pc=Pcmdstr;                                                    //~va6GI~
    *pc++='\"';                                                    //~va6GI~
    memcpy(pc,Slastfnm,(UINT)len);                                 //~va6GI~
    pc+=len;                                                       //~va6GI~
    *pc++='\"';                                                    //~va6GI~
  }                                                                //~va6GI~
  else                                                             //~va6GI~
  {                                                                //~va6GI~
    memcpy(Pcmdstr,Slastfnm,(UINT)len);                            //~v11zR~
    pc=Pcmdstr+len;                                                //~v11zI~
  }                                                                //~va6GI~
//setup /M option                                                  //~v11zI~
    pcm=mopt;                                                      //~v11zI~
    memset(mopt,0,sizeof(mopt));                                   //~v11zR~
    if (UCBITCHK(Slastfflag4,UFHF4BIN))                            //~v11zI~
        *pcm++='B';     //bin mode                                 //~v11zI~
    else                                                           //~v11zI~
    if (UCBITCHK(Slastfflag5,UFHF5COB))                            //~v41eI~
    {                                                              //~v41eI~
      if (UCBITCHK(Slastfflag5,UFHF5COB2))	//cobk                 //~v47wI~
        *pcm++='K';     ///ek                                      //~v47wI~
      else                                                         //~v47wI~
        *pcm++='C';     //SPF mode                                 //~v41eI~
    	if (!UCBITCHK(Slastfflag5,UFHF5NOAUTONUM))                 //~v41eI~
	        *pcm++='N';     //col 72 is also num fld               //~v41eI~
    }                                                              //~v41eI~
    else                                                           //~v41eI~
    if (UCBITCHK(Slastfflag4,UFHF4SPFCMD))                         //~v11zI~
        *pcm++='N';     //SPF mode                                 //~v11zI~
//  else                                                           //~v41eR~
    if (UCBITCHK(Slastfflag4,UFHF4TEXT))                           //~v11zI~
    {                                                              //~v11zI~
        if (UCBITCHK(Slastfflag3,UFHF3RTEXTPC|UFHF3RTEXTUNIX)==(UFHF3RTEXTPC|UFHF3RTEXTUNIX))//~v11zI~
            *pcm++='T';                                            //~v11zI~
        else                                                       //~v11zI~
        if (UCBITCHK(Slastfflag3,UFHF3RTEXTPC))                    //~v11zI~
            *pcm++='P';                                            //~v11zI~
        else                                                       //~v11zI~
        if (UCBITCHK(Slastfflag3,UFHF3RTEXTUNIX))                  //~v11zI~
            *pcm++='U';                                            //~v11zI~
        else                                                       //~v47XI~
        if (UCBITCHK(Slastfflag6,UFHF6RTEXTMAC))                   //~v47XI~
            *pcm++='M';                                            //~v47XI~
                                                                   //~v11zI~
        if (UCBITCHK(Slastfflag3,UFHF3WTEXTPC|UFHF3WTEXTUNIX)==(UFHF3WTEXTPC|UFHF3WTEXTUNIX))//~v11zI~
            *pcm++='T';                                            //~v11zI~
        else                                                       //~v11zI~
        if (UCBITCHK(Slastfflag3,UFHF3WTEXTPC))                    //~v11zI~
            *pcm++='P';                                            //~v11zI~
        else                                                       //~v11zI~
        if (UCBITCHK(Slastfflag3,UFHF3WTEXTUNIX))                  //~v11zI~
            *pcm++='U';                                            //~v11zI~
        else                                                       //~v47XI~
        if (UCBITCHK(Slastfflag6,UFHF6WTEXTMAC))                   //~v47XI~
            *pcm++='M';                                            //~v47XI~
    }                                                              //~v11zI~
                                                                   //~v11zI~
//setup lineno type                                                //~v11AI~
    if (UCBITCHK(Slastfflag4,UFHF4XLINENO)) //lineno type=offset   //~v11AI~
        *pcm++='O';     //offset                                   //~v11AI~
    else                                                           //~v11AI~
    if (UCBITCHK(Slastfflag4,UFHF4NLINENO)) //lineno type=lineno   //~v11AI~
        *pcm++='L';     //lineno                                   //~v11AI~
                                                                   //~v11AI~
//setup width                                                      //~v11AI~
    if (UCBITCHK(Slastfflag4,UFHF4WIDTH))   //explicit width       //~v11zI~
        pcm+=sprintf(pcm,"%d",Slastfwidth);                        //~v11zI~
    if (*mopt)                                                     //~v11zI~
        pc+=sprintf(pc," /M%s",mopt);                              //~v11zI~
//edit cmdline parm                                                //~v11zI~
    *pc=0;                                                         //~v11zI~
    return Slastfmode;                                             //~v11zR~
}//inigetlastfnm                                                   //~v11zI~
//**************************************************************** //~v11yI~
// inirestcd                                                       //~v11yI~
// restore default drive change,cur directory by /R option         //~v11yI~
//* parm  :none                                                    //~v11yI~
//* ret   :none                                                    //~v11yI~
//**************************************************************** //~v11yI~
void inirestcd(void)                                               //~v11yI~
{                                                                  //~v11yI~
    int rc=0;                                                      //~v11yI~
//#ifdef W32                                                         //~vb05I~//~vb06R~
//    char wkfpath[_MAX_PATH],*pfnm;                                 //~vb05I~//~vb06R~
//#endif                                                             //~vb05I~//~vb06R~
//*********************************                                //~v11yI~
    if (*Scurdir)                                                  //~v11yM~
    {                                                              //~v11yI~
//#ifdef W32                                                         //~vb05I~//~vb06R~
//        pfnm=Scurdir;                                              //~vb05I~//~vb06R~
//        if (IS_RESERVED_NAME(Scurdir))                             //~vb05I~//~vb06R~
//        {                                                          //~vb05I~//~vb06R~
//            strcpy(wkfpath,Scurdir);                               //~vb05R~//~vb06R~
//            pfnm=wkfpath;   //filename for uchdir                  //~vb05I~//~vb06R~
//            strcpy(Scurdir,Scurdir+RESERVED_NAMEID_CTR);    //for uchdir msg//~vb05I~//~vb06R~
//        }                                                          //~vb05I~//~vb06R~
//        else                                                       //~vb05I~//~vb06R~
//        {                                                          //~vb05I~//~vb06R~
//            ufullpath(wkfpath,Scurdir,sizeof(wkfpath));            //~vb05I~//~vb06R~
//            if (IS_RESERVED_NAME(wkfpath))                         //~vb05I~//~vb06R~
//                pfnm=wkfpath;                                      //~vb05I~//~vb06R~
//        }                                                          //~vb05I~//~vb06R~
//#endif                                                             //~vb05I~//~vb06R~
#ifndef UNX                                                        //~v196I~
        if (*Scurdir!=ugetdrive())      //current drive letter(upper case)//~v11yR~
            rc=uchdrive(*Scurdir);                                 //~v11yR~
#endif //!UNX                                                      //~v196I~
//      rc+=uchdir(Scurdir);                                       //~v509R~
//#ifdef W32                                                         //~vb05I~//~vb06R~
//        rc+=uchdir(0,pfnm);                                        //~vb05I~//~vb06R~
//#else                                                              //~vb05I~//~vb06R~
//        rc+=uchdir(0,Scurdir);                                     //~vb05I~//~vb06R~
//#endif                                                             //~vb05I~//~vb06R~
        rc+=uchdir(0,Scurdir);                                     //~vb06I~
        if (!rc)                                                   //~v11yI~
//#ifdef WXE                                                       //~v64pR~
#ifdef WXEXXE                                                      //~v64pI~
            ;                                                      //~v50dI~
#else                                                              //~v50dI~
            uerrmsg("Restore DfltDrv/CurDir(%s)",                  //~v11yR~
                    "省略時Drv/現行Dir復元(%s)",Scurdir);          //~v11yR~
#endif                                                             //~v50dI~
        else                                                       //~v11yI~
        {                                                          //~v56SI~
            uerrmsg("Restore DfltDrv/CurDir Failed(%s)",           //~v11yI~
                    "省略時Drv/現行Dir復元失敗(%s)",Scurdir);      //~v11yI~
//#ifdef WXE                                                       //~v64pR~
#ifdef WXEXXE                                                      //~v64pI~
        	*Scurdir=0;		//clear restore dir to avoid errmsg at next time also//~v56SI~
#endif                                                             //~v56SI~
        }                                                          //~v56SI~
    }                                                              //~v11yI~
    return;                                                        //~v11yI~
}//inirestcd                                                       //~v11yI~
//**************************************************               //~v06HR~
//*inisave                                                         //~v06HR~
//* save parm after ini processed                                  //~v06HR~
//*parm:none                                                       //~v06HR~
//*ret  :none                                                      //~v06HR~
//**************************************************               //~v06HR~
void inisave(void)                                                 //~v06HR~
{                                                                  //~v06HR~
//*********************************                                //~v06HR~
    Giniopt=Gopt;                                                  //~v06HR~
    Giniopt2=Gopt2;                                                //~v06HR~
//  Giniopt3=Gopt3;                                                //~v06HR~
    Ginifiletabskip=Gfiletabskip;                                  //~v06HR~
}//inisave                                                         //~v06HR~
                                                                   //~v06HR~
//****************************************************************//~6224I~
// iniacronymwrite                                              //~6224I~
// write acronym for version matching                           //~6224I~
//* parm  :none                                                 //~6224I~
//* ret   :rc                                                   //~6224I~
//****************************************************************//~6224I~
int iniacronymwrite(FILE *Pfh)                                  //~6224I~
{                                                               //~6224I~
//  UINT  len;                                                  //~6224I~//~vb2ER~
    size_t len;                                                    //~vb2EI~
//*********************************                             //~6224I~
    len=fwrite(Sfileid,1,sizeof(Sfileid)-1,Pfh);                //~6224I~
    if (len!=sizeof(Sfileid)-1)                                 //~6224I~
        return 16;                                              //~6224R~
    return 0;                                                   //~6224I~
}//iniacronymwrite                                              //~6224I~
                                                                //~6224I~
//****************************************************************//~6224I~
// iniacronymchk                                                //~6224I~
// chk acronym for version matching                             //~6224I~
//* parm  :none                                                 //~6224I~
//* ret   :rc                                                   //~6224I~
//****************************************************************//~6224I~
int iniacronymchk(char *Pfile,FILE *Pfh)                        //~6224I~
{                                                               //~6224I~
//  UINT  len;                                                  //~6224I~//~vb2ER~
    size_t len;                                                    //~vb2EI~
    char  buff[sizeof(Sfileid)];                                //~6224I~
//*********************************                             //~6224I~
    UTRACEP("iniacronymchk pos=%lx\n",ftell(Pfh));                 //~vafsR~
    len=fread(buff,1,sizeof(Sfileid)-1,Pfh);                    //~6224I~
    if (len!=(sizeof(Sfileid)-1)                                //~6224I~
    || memcmp(buff,Sfileid,sizeof(Sfileid)-1))  //invalid       //~6224I~
    {                                                           //~6224I~
        fileclose(Pfile,Pfh);                                   //~6224I~
        return 16;                                              //~6224I~
    }                                                           //~6224I~
    return 0;                                                   //~6224I~
}//iniacronymchk                                                //~6224R~
