//*CID://+vb81R~:                             update#=  275;       //~vb81R~
//*************************************************************
//*xedlcmd.c                                                    //~5715R~
//**dir line cmd                                                //~5715R~
//*************************************************************
//vb81:170206 trap for edit panel lcmd input ignored case if !NOTRACE//~vb81I~
//vb7f:170109 FTP:not found msg if deleded undelsavefile           //~vb7fI~
//vb7e:170108 FTP crash by longname                                //~vb7eI~
//vb7c:170106 longname support; del on root file(xmove to undeldir fails)//~vb7cI~
//vb75:170103 rc=4(err) of ufilewildexp was not chked for too long filename//~vb75I~
//vb31:160418 (LNX64)Compiler warning                              //~vb31I~
//vb30:160411 (LNX)Compiler warning                                //~vb30I~
//vb12:150528 (BUG)crash when invalid cmd on dirlist for Win/Lnx/Android//~vb12I~
//vax2:140626 (BUG)renameoverflow flag was not cleared at fld oveflow(once over flow,reenter "c" dlcmd",overflow did not clear ts fld)//~vax2I~
//vawv:140610 (W32UNICODE)for ftp,enclose utf8 membname on UDHname //~vawvI~
//vawq:140608 expand renamefld fo also expand mask                 //~vawqI~
//vamJ:131121 (BUG)"%"/"$" cmd could not cut after cmd end         //~vamJI~
//vamz:131103 display cmd function description at typed            //~vamzI~
//vamy:131103 add dlcmd "$"(async version of "%")                  //~vamyI~
//vafk:120624 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  use ULPTR(unsigned __int64/ULONG)//~vafkI~
//vaf9:120607 (WTL)Bug found by vs2010exp(used uninitialized variable),avoid warning C4701//~vaf9I~
//vaa4:110520 ANDROID Send command/dlcmd                           //~vaa4I~
//va0J:090930_(BUG)dlcmd string is not cleared by space cmd        //~va0JI~
//va00:090510 merge utf8 version(enclosed by UTF8SUPPH)            //~va00I~
//          files encoded by utf8,option cplc/cpu8                 //~va00I~
//v8@s:080621 3270:dbcs conversion support                         //~v8@sI~
//            pass recfm and lrecl,convert at xe3270 the use binary mode transfer//~v8@sI~
//v92h:080505 (UTF)new dlcmd "[":cplc, "]":cpu8 option for edit/browse//~v92hI~//~va00I~
//v78K:080506*(BUG)dlcmd help missing "&"                          //~v78KI~
//v76g:070620 utility panel(3.14:grep and 3.12:compare);f5:open dirlist, dlcmd "^":send//~v76gI~
//v75Q:070512 dlcmd "g":keep input on errored line                 //~v75QI~
//v75N:070509 (BUG) time stamp area is not used for dlcmd "#"/"g"/"="//~v75NI~
//v75M:070509 "="(compare) lcmd support. 1st file is line with cmd option on Enter'ed screen.//~v75MI~
//v75J:070509 "g"(grep) dlcmd support                              //~v75JI~
//v75H:070508 e8("e /f80 p1") command support as. lcmd "8" on fname-list and dir-list.//~v75HR~
//v75G:070508 dlcmd "3" support like as on filename panael         //~v75GI~
//v71o:061020 3270:wildcard mask support for dlcmd copy            //~v71oI~
//v71g:061014 3270:copy/move support                               //~v71gI~
//v71e:061011 3270:Rename/delete support                           //~v71eI~
//v690:060418 display file-description support on dir-list panel   //~v690I~
//v68h:060330 (BUG:WXE)root selection required as dnd target dir   //~v68hI~
//v68c:060329 (BUG:WXE)dnd select hdrline ;issued root is not processed errmsg//~v68cI~
//v685:060322 dnd support "file copy into the dir slected" and even in inter-split-screen.//~v685I~
//v66c:051011 (BUG)afte 0/z rejected vy opt delz off,err flag remain and later 0/z cmd rejected even after opt delz on//~v66cI~
//v66b:051011 (BUG)dirlist del cmd may faile(ftprc initialize missing)//~v66bI~
//v662:050863 &(spawn) linecmd support(async version of #)         //~v662I~
//v64v:050708 (LNX)openwith support                                //~v64vI~
//v64a:050618 (LNX)xxe support                                     //~v64aI~
//v645:050617 OPT DELZ ON/OFF;option to prohibit dlcmd z/0;default is on//~v645R~
//v63n:050510 (LNX)revese  mouse selected line on dirlist          //~v63nI~
//v63j:050507 (WXE)dragdrop remote file support                    //~v63jI~
//v63h:050504 (WXE)support DragOut                                 //~v63hI~
//v62i:050319 process ftp delete sequentaily from bottom of dirlist for sync with undel entry creation//~v62iI~
//v62h:050316 ftp undel support                                    //~v62hI~
//v609:050102 (FTP)for performance,multiple file delete at once from dirlist//~v609I~
//v59e:041107 add "#" lcmd:submit for localfile/rsh for remotefile //~v59eI~
//v58h:040905 (BUG)rename fld by %cmd prevent long filename display//~v57dI~
//v57d:040517 for safety;protect del/rename/move for path dir from cur dir//~v57dI~
//v55v:040229 (W32)v55u for W32 console xe(dlcmd "!":openwith)     //~v55vI~
//v54E:040121 (BUG)abend when err dlcmd pending on the plh which is deleted by unexpand cmd//~v54EI~
//v54u:040113 expand % cmd input area to time stamp field          //~v54uI~
//v54s:040112 (BUG)abend,to be cleared freed dlcmd entry           //~v54sI~
//v54b:040102 dirlist;allow more parm over date filed for open cmd parm//~v54bI~
//v51W:030810 dir lcmd %:apply cmd with filename parm as %.        //~v51WI~
//v50G:030201 add cmd "et"/"bt"/"st" for e/b/s /mt                 //~v50GI~
//v47Q:020330 leave "s" as old fashion and use "o" for edit/browse wit patm//~v47QI~
//v47P:020330 dlcmd "s" support option specification               //~v47PI~
//v44t:011206 dlcmd "I":/Mcn,"J":/Mkn                              //~v44tI~
//v44g:011204 new dlcmd 'K':/Mk(cob with no num),'N':/Mn(spf),'L':/Mc//~v44gI~
//v44f:011204 new dlcmd 'H'/'h'(h:follow edit/browse open mode,'H':reverse)//~v44fI~
//v41c:010804 limit del etc. update function on browse dirlist     //~v41cI~
//v182:001209 long filename display on dirlist(over attr fld)      //~v182I~
//v10v:990326 chng browse binary mode:"2" -->"1",and add "2" as edit binary mode//~v10vR~
//v10s:990404 move csr to split scr for view/vieedit               //~v10sI~
//v10p:990326 new dlcmd "2";browse binary mode                     //~v10pI~
//v0hm:980215 pend/err lcmd reset by double Esc or typed RESET     //~v0hmI~
//v0f9:971017 UFCFLFN flag for lfn(common to os2/w95/gcc/dos)      //~v0f9I~
//v0f3:971012 long filename support                                //~v0f3I~
//            input long rename field(dlcmd.c)                     //~v0f3I~
//v09l:970518:csr wait mark in dlcmd or cmd processing             //~v09lI~
//v09b:970510:disk free space display                              //~v09bI~
//            -reject attr/rename/move for root dir(dlcmd.c)       //~v09bR~
//v095:970405:DPMI version                                         //~v095I~
//            -\ of dbcs 2nd byte                                  //~v095I~
//v07u:960916:chk printcmd string where xprint is used             //~v07uR~
//v07s:960825:new ulib.h/ulibdef.h(no need base def by os2.h)      //~v07sI~
//            to speed up compile,drop include(caused by WIN95 modify)//~v07sI~
//v07g:960707:printed msg on dir list                              //~v07gI~
//v07e:960629:dir lcmd copy(PF10 and PF11)                         //~v07eI~
//            rensmasv for also copy                               //~v07eI~
//            copy target clear by space key                       //~v07eI~
//v069:960224:linenosz changeable for edit/browse               //~v069I~
//v060:960204:add dir lcmd "z","0"(undeletable delete)          //~v060I~
//v05S:960131:force delete r-only from dlcmd("/" cmd)           //~v05SI~
//v05D:960105:move deleted line chk to xedlcmd from xechar      //~v05DI~
//v05u:951202:undelete dlcmd(rename when delete)                //~v05uI~
//v05t:951202:(BUG)retype dlcmd lcmdin1<->lcmdin2,shuld clear attr or//~v05rI~
//            rename fld input                                  //~v05rI~
//v05r:951126:dlcmd cursor                                      //~v05rI~
//v05j:951114:move dlcmd                                        //~v05fI~
//v05f:951111:(BUG)invalid dlcmd cleared(treated competed) after enter key//~v058I~
//v058:951022:print forward sequential                          //~v058I~
//v058:951022:print forward sequential                          //~v058I~
//v051:951014:print dlcmd                                       //~v051I~
//v04j:951007:update id for edit saved file on dir list         //~v04jR~
//v04d:950930:malloc/calloc rc chk for dos                      //~v04dI~
//v04b:950924:expand all dlcmd(>)                               //~v04bI~
//v04a:950924:process dir lcmd from last to be able to del empty dir//~v04aI~
//v046:950923:view dir lcmd                                     //~v046I~
//v045:950918:clear errmsg when lcmd input/clear                //~v045I~
//v043:950917:cur dir lcmd(.)                                   //~v043I~
//v042:950916:xcopy  cmd,copy line cmd                          //~v042I~
//v030:950906:attrib cmd                                        //~v030I~
//v03x:950902:addr err lcmd to pend cmd to always set err       //~v03xI~
//            if not,err lcnmd hiddden by page scroll           //~v03xI~
//v03u:950827:bug;ULHFLINECMD(lcmd reg sw) reset by xechar ignore//~v03uI~
//            lcmd input from other side of same pfc.           //~v03uI~
//            so move lcmd stack to pfh from pfc.(alt of v03q)  //~v03uI~
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <ualloc.h>                                             //~5318I~

#ifdef WXE                                                         //~v63jI~
	#include <dos.h>                                               //~v63jI~
#endif                                                             //~v63jI~
#ifdef DOS
#else
//  #define INCL_BASE                                              //~v07sR~
//  #include <os2.h>                                               //~v07sR~
#endif
//*******************************************************
#include <ulib.h>
#include <uerr.h>
#include <uque.h>
#include <ufile.h>                                              //~5318R~
#include <ufile3.h>                                                //~v71gI~
#include <ufemsg.h>                                                //~v63jI~
                                                                   //~v609I~
#ifdef FTPSUPP                                                     //~v609I~
	#include <uftp.h>                                              //~v609R~
	#include <ufile1f.h>                                           //~v609I~
	#include <u3270.h>                                             //~v71gI~
#endif                                                             //~v609I~
#include <ufilew.h>                                                //~vawvI~
#include <utrace.h>                                                //~vawvI~
                                                                //~5318I~
#include "xe.h"
#include "xescr.h"                                              //~5715R~
#include "xecsr.h"                                                 //~v09lI~
#include "xefile.h"                                             //~5715I~
#include "xefile2.h"
#include "xefsub.h"                                                //~v0f9I~
#include "xepan.h"                                              //~5716I~
#include "xedir.h"                                              //~5716R~
#include "xedir2.h"                                             //~5731I~
                                                                   //~v76gI~
#define  XEGBL_DLCMD                                               //~v76gI~
#include "xedlcmd.h"                                            //~5716I~
                                                                   //~v76gI~
#include "xedlcmd2.h"                                           //~5806I~
#include "xedlcmd3.h"                                           //~5820I~
#include "xedlcmd4.h"                                           //~v05uI~
#include "xedlcmd6.h"                                              //~v51WI~
#include "xefunc.h"
#include "xeerr.h"                                              //~v03xI~
#include "xeftp.h"                                                 //~v63jI~
#include "xesub.h"                                                 //~vaf0I~
//*******************************************************
typedef struct _FTPDELQE {                                         //~v609R~
					UQUEE         FDQEqe;                          //~v609R~
                    int           FDQEflag;                        //~v62iR~
#define FDQEFDIRCONF              0x01    //intercepted by dir del confirmation//~v62iR~
#define FDQEFCALLED               0x02    //del called             //~v62iI~
#define FDQEFUNDELSAVEENTRY       0x04    //saved entry for undel  //~vb7fI~
                    int           FDQErc;                          //~v62iI~
                    UDLCMD       *FDQEplc;                         //~v609R~
#ifdef FTPSUPP                                                     //~v62iI~
                    PUFTPHOST     FDQEpuftph;                      //~v62hR~
#endif                                                             //~v62iI~
//                  PUFTPMULTIDEL FDQEpfmd;                        //~v62hR~
                    void         *FDQEpfmd;                        //~v62hI~
                    int           FDQElen;                         //~v609R~
                    char         *FDQEpfpath;                      //~v609R~
                    char         *FDQEpundoname;   //rename for undo//~v62hI~
                  } FTPDELQE,*PFTPDELQE;                           //~v609I~
#define FTPDELQESZ (sizeof(FTPDELQE))                              //~v609I~
//*******************************************************          //~v609I~
		DLCMDFUNC dlcmddndselect;                                  //~v63hI~
//*******************************************************          //~v63hI~
//#define DLCRSVINITV       0,0,0                                  //~v75JR~
#define DLCRSVINITV       0,0,0,0,{0,0,0}                          //~v75JI~
static UDLCMD Scmdlist[]={                                      //~5715R~
				{'A',UDLCTLINEINP1|UDLCTERRBRW,0,0,dlcmdattrib,DLCRSVINITV},				//attr//~v41cR~
//#define UDLCINDEX_BROWSE 1      //index of Scmdlist              //~v47PR~
				{'B',UDLCTDISPLAY,0,0,dlcmdbrowse,DLCRSVINITV},	//browse    //~v042M~
    			{'C',UDLCTLINEINP2,0,0,dlcmdcopymove,DLCRSVINITV},				//copy//~v05jR~
//  			{'D',UDLCTERRBRW,0,0,dlcmddelete,DLCRSVINITV},	//delete//~v57dR~
//    			{'D',UDLCTERRBRW|UDLCTERRPATH,0,0,dlcmddelete,DLCRSVINITV}, //delete//~v609R~
      			{'D',UDLCTERRBRW|UDLCTERRPATH,0,UDLCT2DELCMD,dlcmddelete,DLCRSVINITV},  //delete//~v609R~
//#define UDLCINDEX_EDIT   4      //index of Scmdlist              //~v47PR~
				{'E',UDLCTDISPLAY,0,0,dlcmdedit  ,DLCRSVINITV},	//edit      //~v042M~
				{'F',0,0,0,	dlcmdfree  ,DLCRSVINITV},	//edit              //~v046I~
    			{UDLCCMD_GREPUPPER,UDLCTLINEINP2|UDLCTMASK,0,0,dlcmdgrep,DLCRSVINITV},			//open//~v75MR~
				{'H',UDLCTDISPLAY,0,0,dlcmdhex  ,DLCRSVINITV},	//hex display mode//~v44fI~
				{'I',UDLCTDISPLAY,0,0,dlcmdspfcobnum,DLCRSVINITV},	//spfcob with col1-6:seqno//~v44tI~
				{'J',UDLCTDISPLAY,0,0,dlcmdspfcobspace,DLCRSVINITV},	//spfcob with col1-6:space//~v44tI~
				{'K',UDLCTDISPLAY,0,0,dlcmdcobspace,DLCRSVINITV},	//cob with col1-6:space//~v44gI~
				{'L',UDLCTDISPLAY,0,0,dlcmdcobnum,DLCRSVINITV},	//cob with col1-6:seqno//~v44gI~
//  			{'M',UDLCTLINEINP2|UDLCTERRBRW,0,0,dlcmdcopymove,DLCRSVINITV},	//move//~v57dR~
    			{'M',UDLCTLINEINP2|UDLCTERRBRW|UDLCTERRPATH,0,0,dlcmdcopymove,DLCRSVINITV},	//move//~v57dI~
				{'N',UDLCTDISPLAY,0,0,dlcmdspf,DLCRSVINITV},	//numbered file//~v44gI~
    			{'O',UDLCTDISPLAY|UDLCTLINEINP2|UDLCTMASK,0,0,dlcmdopen,DLCRSVINITV},			//open//~v47QI~
				{'P',0          ,0,0,dlcmdprint,DLCRSVINITV},	//print     //~v051I~
//  			{'R',UDLCTLINEINP2|UDLCTMASK|UDLCTERRBRW,0,0,dlcmdrename,DLCRSVINITV},				//rename//~v57dR~
    			{'R',UDLCTLINEINP2|UDLCTMASK|UDLCTERRBRW|UDLCTERRPATH,0,0,dlcmdrename,DLCRSVINITV},	//rename//~v57dI~
//  			{'S',UDLCTDISPLAY,},			//edit/browse      //~v47PR~
//  			{'S',UDLCTDISPLAY|UDLCTLINEINP2|UDLCTMASK,0,0,dlcmdselect},			//edit/browse//~v47QR~
    			{'S',UDLCTDISPLAY,0,0,dlcmdselect,DLCRSVINITV},			//edit/browse//~v47QI~
//#ifdef WXE                                                       //~v63nR~
#if defined(WXE)||defined(LNX)                                     //~v63nI~
    			{UDLCCMD_DNDSELECT,UDLCTDISPLAY,0,0,dlcmddndselect,DLCRSVINITV},			//edit/browse//~v63hR~
#endif                                                             //~v63hI~
    			{'T',UDLCTDISPLAY,0,0,dlcmdselecttext,DLCRSVINITV},			//edit/browse//~v50GI~
				{'U',UDLCTERRBRW,0,0,dlcmdundelete,DLCRSVINITV},//undelete     //~v41cR~
				{'V',0          ,0,0,dlcmdviewb,DLCRSVINITV},	//view browse//~v046R~
				{'W',0          ,0,0,dlcmdviewe,DLCRSVINITV},	//view edit //~v046R~
				{'X',UDLCTNOPAIR,0,0,dlcmdexclude,DLCRSVINITV},//dir exclude//~v042M~
				{'Y',UDLCTNOPAIR,0,0,dlcmdunexclude,DLCRSVINITV},//dir unexclude//~v042M~
//  			{'Z',UDLCTERRBRW,0,0,dlcmddeletez,DLCRSVINITV},	//delete w/o undel//~v57dR~
//  			{'Z',UDLCTERRBRW|UDLCTERRPATH,0,0,dlcmddeletez,DLCRSVINITV},	//delete w/o undel//~v609R~
//  			{'Z',UDLCTERRBRW|UDLCTERRPATH,0,UDLCT2DELCMD,dlcmddeletez,DLCRSVINITV},	//delete w/o undel//~v645R~
    			{'Z',UDLCTERRBRW|UDLCTERRPATH,0,(UDLCT2DELCMD|UDLCT2DELZCMD),dlcmddeletez,DLCRSVINITV},	//delete w/o undel//~v645I~
//  			{'0',UDLCTERRBRW,0,0,dlcmddeletezr,DLCRSVINITV},//delete ronly w/o undel//~v57dR~
//  			{'0',UDLCTERRBRW|UDLCTERRPATH,0,0,dlcmddeletezr,DLCRSVINITV},//delete ronly w/o undel//~v609R~
//  			{'0',UDLCTERRBRW|UDLCTERRPATH,0,UDLCT2DELCMD,dlcmddeletezr,DLCRSVINITV},//delete ronly w/o undel//~v645R~
    			{'0',UDLCTERRBRW|UDLCTERRPATH,0,(UDLCT2DELCMD|UDLCT2DELZCMD),dlcmddeletezr,DLCRSVINITV},//delete ronly w/o undel//~v645I~
	    		{'1',UDLCTDISPLAY,0,0,dlcmdbrowse2,DLCRSVINITV},	//browse binary//~v10vR~
	    		{'2',UDLCTDISPLAY,0,0,dlcmdedit2,DLCRSVINITV},	//edit binary  //~v10vR~
	    		{'3',UDLCTDISPLAY,0,0,dlcmdbinbe3,DLCRSVINITV},	//browse or edit binary according to panel//~v75GI~
	    		{UDLCCMD_EDITF80,UDLCTDISPLAY,0,0,dlcmdeditf80,DLCRSVINITV},	//browse or edit binary according to panel//~v75HI~
#ifdef UTF8SUPPH                                                   //~v92hI~//~va00I~
	    		{UDLCCMD_CPLC,UDLCTDISPLAY,0,0,dlcmdedit3,DLCRSVINITV},	//browse or edit binary according to panel//~v92hR~//~va00I~
	    		{UDLCCMD_CPU8,UDLCTDISPLAY,0,0,dlcmdedit3,DLCRSVINITV},	//browse or edit binary according to panel//~v92hR~//~va00I~
#endif                                                             //~v92hI~//~va00I~
				{'-',UDLCTLINEINP2|UDLCTMASK,0,0,dlcmdexpand,DLCRSVINITV},//dir expand//~5807R~
    			{'>',UDLCTLINEINP2|UDLCTMASK,0,0,dlcmdexpandall,DLCRSVINITV},//dir expand//~v04bR~
				{'+',UDLCTNOPAIR,0,0,dlcmdunexpand,DLCRSVINITV},//dir unexpand//~5806R~
//  			{':',UDLCTNOPAIR,0,0,dlcmdpath    ,DLCRSVINITV},//dir unexpand//~v57dR~
    			{':',UDLCTNOPAIR|UDLCTERRPATH,0,0,dlcmdpath    ,DLCRSVINITV},//dir unexpand//~v57dI~
				{'.',UDLCTNOPAIR,0,0,dlcmdcd      ,DLCRSVINITV},//set cur dir//~v043R~
//  			{'/',UDLCTERRBRW,0,0,dlcmddeleter,DLCRSVINITV},	//delete ronly//~v57dR~
//  			{'/',UDLCTERRBRW|UDLCTERRPATH,0,0,dlcmddeleter,DLCRSVINITV},	//delete ronly//~v609R~
    			{'/',UDLCTERRBRW|UDLCTERRPATH,0,UDLCT2DELCMD,dlcmddeleter,DLCRSVINITV}, //delete ronly//~v609R~
    			{'%',UDLCTLINEINP2|UDLCTMASK,0,0,dlcmdappcmd,DLCRSVINITV},	//apply cmd//~v51WR~
    			{'#',UDLCTLINEINP2|UDLCTMASK,0,0,dlcmdsubrshcmd,DLCRSVINITV},	//submit/rsh//~v59eR~
    			{UDLCCMD_COMPARE,UDLCTLINEINP2|UDLCTMASK,0,0,dlcmdcompare,DLCRSVINITV},			//open//~v75MR~
				{UDLCCMD_SEND   ,0          ,0,0,dlcmdsend,DLCRSVINITV},	//print//~v76gI~
#ifndef DOS                                                        //~v662I~
    			{'&',UDLCTLINEINP2|UDLCTMASK,0,0,dlcmdspawn,DLCRSVINITV},	//spawn//~v662I~
#endif                                                             //~v662I~
//#fdef W32                                                        //~v64vR~
#if defined(W32) || defined(LNX)                                   //~v64vI~
				{'!',0          ,0,0,dlcmdopenwith,DLCRSVINITV},	//open with app association//~v55vI~
				{UDLCCMD_APPASYNC,UDLCTLINEINP2|UDLCTMASK,0,0,dlcmdappasync,DLCRSVINITV},	//open with app association//~vamyR~//~vamzR~
#endif                                                             //~v55vI~
				{0,0,0,0,0,DLCRSVINITV}};				//terminator
static	UDLCMD Slcmd[MAXCMDLINE];	//result of line cmd inmput //~5715R~
static	int   Scmdno;           	//cmd count
//static	UDLCMD *Splcselect;			//plc when 'S'(select)     //~v47PR~
static  PUCLIENTWE Spcwview;		//viewb/viewe scr pcw          //~v10sI~
static  UCHAR Sorgcmdid=0;    		//input lower/upper cmdid      //~v54bR~
#ifdef FTPSUPP                                                     //~v609I~
    static 	UQUEH Sftpdelqh;                                       //~v609I~
//  static 	PUFTPMULTIDEL Spftpmultidel;                           //~v62iR~
//  static 	PUFTPMULTIRENAME Spftpmultirename;                     //~v62iR~
#endif                                                             //~v609I~
//**************
int dlcotherclient(PUCLIENTWE Ppcwc,PUCLIENTWE Ppcwo);          //~5715R~
int dlcsavepend(PUCLIENTWE Ppcw,UDLCMD *Pplc,int Pctr);         //~5715R~
int dlcresultset(int Prc,UDLCMD *Pplcc,UDLCMD *Pplcd);          //~5715R~
int dlcproc(PUCLIENTWE Ppcw);                                   //~5715R~
int dlccallfunc(PUCLIENTWE Ppcw,PUDLCMD Pplc1,PUDLCMD Pplc2);   //~5723R~
int dlcgetlinecmd(PULINEH Pplh,UDLCMD *Pplcmd);                 //~5715R~
int dlclinenocomp(const void*,const void*);//sort func          //~5715R~
UDLCMD *dlcsrchcmdtbl(UCHAR Pcmd);                              //~5716I~
void dlcprinted(PUCLIENTWE Ppcw,UDLCMD *Pplc);                     //~v07gR~
int dlcrooterr(void);                                              //~v09bI~
int dlcverberr(void);                                              //~v10pI~
int dlccleardeleted(PUFILEH Ppfh);                                 //~v54sI~
int dlcerrrecord(char Pcmd);                                       //~v57dI~
#ifdef FTPSUPP                                                     //~v609I~
//  int dlcftpmultidel(PUCLIENTWE Ppcw,PUFTPHOST Ppuftph);         //~v62iR~
	int dlcftpmultidel(PUCLIENTWE Ppcw,PFTPDELQE Ppfdqe);          //~v62iR~
	int dlcftpaddentry(PUCLIENTWE Ppcw,PUFTPHOST Ppuftph,UDLCMD *Pplc);//~v609I~
	int dlcftpfree(PUCLIENTWE Ppcw);                               //~v609I~
#endif                                                             //~v609I~
//#ifdef WXE                                                       //~v64aR~
#ifdef WXEXXE                                                      //~v64aI~
//int dlcmddndremotecopy(int Popt,char *Pfpathremote,char *Pfpathwd,PUFILEH Ppfh,PUFTPHOST Ppuftph,PUDIRLH Ppdh,char *Pfpathlocal);//~v63jR~//~vb7eR~
int dlcmddndremotecopy(int Popt,char *Pfpathremote,char *Pfpathwd,size_t Pbuffsz,PUFILEH Ppfh,PUFTPHOST Ppuftph,PUDIRLH Ppdh,char *Pfpathlocal);//~vb7eI~
#endif                                                             //~v63jI~
int dlcerrmixed(char Pcmd);                                        //~v75JI~
//int dlcsamechk(PUCLIENTWE Ppcw,UCHAR Pcmdid,PUDLCMD *pPplc1,PUDLCMD *Ppplc2);//~v75MR~
int dlcsamechk(PUCLIENTWE Ppcw,UCHAR Pcmdid,PUDLCMD *pPplc1,PUDLCMD *Ppplc2,int *Pplinecnt);//~v75MI~
void dlcfuncdescription(int Pcmd);                                 //~vamzI~
//****************************************************************
// dir linecmd process                                          //~5715R~
//*parm :pcw                                                    //~5715I~
//*ret  :rc (1:pend cmd,4:err)                                  //~5715R~
//****************************************************************
int dlcmdmain(PUCLIENTWE Ppcw)                                  //~5715R~
{
	PUFILEC pfc;
	PULINEH plh;
	PUFILEH  pfh;                                               //~5723M~
	UDLCMD   *plc;                                              //~5715R~
	int i,rc;
//********************	
	pfc=Ppcw->UCWpfc;
//    if (UCBITCHK(pfc->UFCflag,UFCFDEDIT))                        //~v47PR~
//        Splcselect=&Scmdlist[UDLCINDEX_EDIT];   //edit           //~v47PR~
//    else                                                         //~v47PR~
//        Splcselect=&Scmdlist[UDLCINDEX_BROWSE]; //browse         //~v47PR~
	pfh=pfc->UFCpfh;                                            //~5723M~
	UPCTRREQ(pfh);	//for first time sw of batch process        //~5813I~
//first format chk
	dlccleardeleted(pfh);                                          //~v54sI~
	Scmdno=pfh->UFHcmdlinectr;                                  //~v03uR~
	for (i=0,plc=Slcmd;i<Scmdno;i++,plc++)
	{
		plh=pfh->UFHcmdline[i];                                 //~v03uR~
		if (dlcgetlinecmd(plh,plc))                             //~5715R~
			dlcresultset(4,plc,0);                              //~5715R~
		plc->UDLCplh=plh;                                       //~5715R~
		plc->UDLCindex=i;                                       //~5715R~
		plc->UDLCsplitid=Ppcw->UCWsplitid;	//chk at lcmdmove   //~5715R~
		if (UCBITCHK(pfc->UFCflag,UFCFDEDIT))                      //~v44fI~
			UCBITON(plc->UDLCflag,UDLCEDIT);	//dir list is edit mode//~v44fI~
    	if (Sorgcmdid==(UCHAR)toupper(Sorgcmdid))                  //~v44fI~
    	  if (Sorgcmdid!=(UCHAR)tolower(Sorgcmdid))	//low!=high    //~v75MI~
			UCBITON(plc->UDLCflag,UDLCUPPER);	//upper case cmd   //~v44fI~
	}
  	qsort(Slcmd,(UINT)Scmdno,sizeof(UDLCMD),dlclinenocomp); //sort by lineno//~5715R~
	Spcwview=0;		//viewb/viewe scr pcw                          //~v10sI~
	dlcproc(Ppcw);                                              //~5715R~
#ifdef FTPSUPP                                                     //~v609M~
	dlcftpfree(Ppcw);                                              //~v609I~
#endif                                                             //~v609M~
//*copy pending lcmd to malloc area for file copy cmd etc
	rc=dlcsavepend(Ppcw,Slcmd,Scmdno);                          //~5715R~
    if (!rc)	//all success                                      //~v10sR~
    	if (Spcwview)	//viewb/viewe called                       //~v10sI~
        {                                                          //~v10sI~
    		((PUFILEC)(scrgetcw(0)->UCWpfc))->UFCcsrplh=0;	//ignore dir list scr csr//~v10sR~
            csrrestore(Spcwview);   //swap active                  //~v10sR~
		}                                                          //~v10sI~
	if (rc==1)		//commnad pending 
		rc=max(rc,dlcotherclient(Ppcw,scrgetcw(-1)));//process both client//~5715R~
	if (rc>=4)		//cmd err
		if (!UCBITCHK(Gprocstatus,GPROCSCSRSET))                //~5826I~
			if (pfh->UFHcmdlinectr)                             //~v05rR~
				filesetcsr(Ppcw,pfh->UFHcmdline[pfh->UFHcmdlinectr-1],0,0);//top line of err/pend,fldtop//~v05rI~
	UPCTRREQ(pfh);	//view edit screen save case                //~v04jR~
    csrsetwait(0);      //reset wait mode csr                      //~v09lI~
	return rc;
}//dlcmdmain                                                    //~5715R~
	
//**************************************************************** //~v10sI~
//*callback from viewb/viewe to save split screen pcw              //~v10sI~
//*parm1  :PUFILEC to be saved                                     //~v10sI~
//*rc   :                                                          //~v10sI~
//**************************************************************** //~v10sI~
void dlcsaveviewpcw(void)                                          //~v10sR~
{                                                                  //~v10sI~
//*********************                                            //~v10sI~
	Spcwview=scrgetcw(0);	//curr top(viewb/viewe) pcw            //~v10sR~
    return;                                                        //~v10sR~
}//dlcsaveviewpcw(PUCLIENTWE Ppcw)                                 //~v10sI~
//****************************************************************
// dlcsavepend                                                  //~5715R~
//*save pending lcmd
//*parm1  :PUFILEC tobe saved
//*parm2  :process completed UDLCMD start addr                  //~5715R~
//*parm3  :UDLCMD count                                         //~5715R~
//*rc   :
//****************************************************************
int dlcsavepend(PUCLIENTWE Ppcw,UDLCMD *Pplc,int Pctr)          //~5715R~
{
	PUFILEH pfh;                                                //~v03uR~
	PULINEH plh;
	UDLCMD   *plcpend,*plc;                                     //~5715R~
	int i,j,rc;
//*********************	
	pfh=((PUFILEC)Ppcw->UCWpfc)->UFCpfh;                        //~v03uR~
	if (!pfh->UFHpvlcmd)	//first time                        //~v03uR~
    {                                                           //~v04dI~
		pfh->UFHpvlcmd=UALLOCM(UDLCMDSZ*MAXCMDLINE);            //~v04dR~
        UALLOCCHK(pfh->UFHpvlcmd,8);    //return if malloc err  //~v04dI~
    }                                                           //~v04dI~
	plcpend=pfh->UFHpvlcmd;	//pending cmd UDLCMD save area      //~v03uR~
	pfh->UFHpendctr=0;				//clear pending lcmd        //~v03uR~
	rc=0;
	for (i=0,j=0,plc=Pplc;i<Pctr;i++,plc++)
	{
		plh=plc->UDLCplh;                                       //~5715R~
        if (!plh)       //plh deleted by unexpand etc              //~v54EI~
            continue;                                              //~v54EI~
		UCBITON(plh->ULHflag,ULHFDRAW);			//redraw line
//  	if (!plc->UDLCcmd)  //cmd cleared                          //~v75MI~,//~v75QR~
//      	continue;                                              //~v75MI~,//~v75QR~
		if (UCBITCHK(plc->UDLCflag,UDLCFCOMP))                  //~5715R~
		{
			UCBITOFF(plh->ULHflag,ULHFLINECMD|ULHFLCMDERR);
			memset(plh->ULHlinecmd,0,sizeof(plh->ULHlinecmd));  //~5721R~
			continue;
		}
		UCBITON(plh->ULHflag,ULHFLCMDERR);		//for csr set at xefile2
		pfh->UFHpendctr++;				//countup pending lcmd  //~v03xR~
		plc->UDLCsplitid=Ppcw->UCWsplitid;	//chk at lcmdmove   //~v03xR~
		if (UCBITCHK(plc->UDLCflag,UDLCFPEND))                  //~v03xM~
		{                                                       //~v03xM~
			memcpy(plcpend++,plc,UDLCMDSZ);	//save for file cmd proc//~5715R~
			rc=max(1,rc);                                       //~5715R~
		}
		else
			rc=4;
		pfh->UFHcmdline[j++]=plh;                               //~v03uR~
	}
	pfh->UFHcmdlinectr=j;                                       //~v03uR~
	UCBITON(pfh->UFHflag2,UFHF2LCMDCOMP); //processed           //~v03uR~
	return rc;
}//dlcsavepend                                                  //~5715R~
                                                                   //~v0hmI~
//**************************************************************** //~v0hmI~
// dlcmdreset                                                      //~v0hmI~
//*clear pending lcmd by reset key                                 //~v0hmI~
//*parm1  :pcw                                                     //~v0hmI~
//*parm2  :pfh                                                     //~v0hmI~
//*rc     :reset cmdno                                             //~v0hmI~
//**************************************************************** //~v0hmI~
int dlcmdreset(PUCLIENTWE Ppcw,PUFILEH Ppfh)                       //~v0hmI~
{                                                                  //~v0hmI~
	int ii,cmdno;                                                  //~v0hmI~
    PULINEH plh,*pplh;                                             //~v0hmI~
    PUDIRLH pdh;                                                   //~vawqI~
//*********************                                            //~v0hmI~
	Ppfh->UFHpendctr=0;				//clear pending lcmd           //~v0hmI~
	cmdno=Ppfh->UFHcmdlinectr;                                     //~v0hmR~
	pplh=Ppfh->UFHcmdline;                                         //~v0hmI~
	for (ii=0;ii<cmdno;ii++,pplh++)                                //~v0hmI~
    {                                                              //~v0hmI~
		plh=*pplh;                                                 //~v0hmI~
        if (!plh)                                                  //~v63hI~
            continue;                                              //~v63hI~
		UCBITON(plh->ULHflag,ULHFDRAW);			//redraw line      //~v0hmI~
		UCBITOFF(plh->ULHflag,ULHFLINECMD|ULHFLCMDERR);            //~v0hmI~
		memset(plh->ULHlinecmd,0,ULHLINENOSZ);                     //~v0hmI~
        pdh=UGETPDH(plh);                                          //~vawqI~
		if (UCBITCHK(pdh->UDHflag,UDHFLCMDIN2))                    //~vawqI~
        {                                                          //~vawqI~
			dirsetflddata(Ppcw,plh,PANL310RENAME,"");              //~vawqI~
        }                                                          //~vawqI~
        UCBITOFF(pdh->UDHflag,UDHFLCMDIN1|UDHFLCMDIN2|UDHFDDSETUP);//~vawqI~
	}                                                              //~v0hmI~
	Ppfh->UFHcmdlinectr=0;                                         //~v0hmR~
	UCBITON(Ppfh->UFHflag2,UFHF2LCMDCOMP); //processed             //~v0hmR~
	return cmdno;                                                  //~v0hmI~
}//dlcmdreset                                                      //~v0hmI~
//**************************************************************** //~v63hI~
// set line cmd internaly                                          //~v63hI~
//*parm1  :pcw                                                     //~v63hI~
//*parm2  :pfh                                                     //~v63hI~
//*rc     :rc                                                      //~v63hI~
//**************************************************************** //~v63hI~
int dlcmdsetlcmd(PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH Pplh,char Plcmd)//~v63hR~
{                                                                  //~v63hI~
	int newlcmdsw;                                                 //~v63hI~
//*********************                                            //~v63hI~
	newlcmdsw=!UCBITCHK(Pplh->ULHflag,ULHFLINECMD);                //~v63hI~
	if (newlcmdsw)//line cmd registration not yest for this pfh    //~v63hI~
        if (Ppfh->UFHcmdlinectr>=MAXCMDLINE)//linecmd ctr          //~v63hI~
        {                                                          //~v63hI~
            uerrmsg("Line cmd max line is %d",                     //~v63hI~
                    "行コマンドは最大 %d 行まで入力できます",      //~v63hI~
                    MAXCMDLINE);                                   //~v63hI~
            return 4;                                              //~v63hI~
        }                                                          //~v63hI~
	memset(Pplh->ULHlinecmd,0,ULHLINENOSZ);                        //~v63hI~
	*Pplh->ULHlinecmd=Plcmd;  //drag and drop selected line        //~v63hI~
	UCBITON(Pplh->ULHflag,ULHFDRAW);		//req redraw           //~v63hI~
	UCBITOFF(Ppfh->UFHflag2,UFHF2LCMDCOMP);//need command process  //~v63hI~
	UCBITOFF(Pplh->ULHflag,ULHFLCMDERR);//reset err lcmd           //~v63hI~
	UCBITOFF(Pplh->ULHflag3,ULHF3ERRLINE);//reset err line         //~v63hI~
	if (newlcmdsw)//line cmd registration not yest for this pfh    //~v63hI~
	{                                                              //~v63hI~
		UCBITON(Pplh->ULHflag,ULHFLINECMD);//line cmd input        //~v63hI~
		Ppfh->UFHcmdline[Ppfh->UFHcmdlinectr++]=Pplh;	//save cmd line//~v63hI~
	}                                                              //~v63hI~
    return 0;                                                      //~v63hI~
}//dlcmdsetlcmd                                                    //~v63hR~
//#ifdef WXE                                                       //~v63nR~
#if defined(WXE)||defined(LNX)                                     //~v63nI~
int dlcmddndselect(PUCLIENTWE Ppcw,PUDLCMD Pplc,PUDLCMD Pplcdummy) //~v63hI~
{                                                                  //~v63hI~
	return 0;	//nop                                              //~v63hI~
}                                                                  //~v63hI~
#endif                                                             //~v63hI~
//#ifdef WXE                                                       //~v63nR~
#if defined(WXE)||defined(LNX)                                     //~v63nI~
//**************************************************************** //~v63hI~
// dlcmddndset                                                     //~v63hI~
//*set drag and drop selected line lcmd input                      //~v63hI~
//*parm1  :pcw                                                     //~v63hI~
//*parm2  :pfh                                                     //~v63hI~
//*rc     :rc                                                      //~v63hI~
//**************************************************************** //~v63hI~
int dlcmddndset(PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH Pplh1,PULINEH Pplh2)//~v63hR~
{                                                                  //~v63hI~
    PUSCRD  psd;                                                   //~v63jI~
	PULINEH plh,plh1,plh2;                                         //~v63hI~
//    PUDIRLH pdh;                                                 //~v68hR~
    int rc;                                                        //~v63hI~
//*********************                                            //~v63hI~
    psd=Ppcw->UCWpsd;                                              //~v63jI~
	UCBITON(psd->USDflag2,USDF2DRAW);		//redraw hdr line to clear errmsg//~v63jI~
	if (Pplh1->ULHlinenor>Pplh2->ULHlinenor)                       //~v63hI~
		plh1=Pplh2,plh2=Pplh1;                                     //~v63hI~
    else                                                           //~v63hI~
		plh1=Pplh1,plh2=Pplh2;                                     //~v63hI~
    for (plh=plh1;plh;plh=UGETQNEXT(plh))                          //~v63hI~
    {                                                              //~v63hI~
//      if (plh->ULHtype!=ULHTDATA) //file data                    //~v68cR~
//          continue;                                              //~v68cR~
      if (plh->ULHtype==ULHTDATA) //file data                      //~v68cI~
      {                                                            //~v68cI~
//        pdh=UGETPDH(plh);                                        //~v68hR~
//        if (!pdh->UDHlevel) //rootdir                            //~v68hR~
//            return ufileroot(pdh->UDHname,4);                    //~v68hR~
		rc=dlcmdsetlcmd(Ppcw,Ppfh,plh,UDLCCMD_DNDSELECT);  //drag and drop selected line//~v63hR~
    	if (rc)                                                    //~v63hR~
    		return rc;                                             //~v63hR~
      }                                                            //~v68cI~
        if (plh==plh2)                                             //~v63hI~
        	break;                                                 //~v63hI~
    }                                                              //~v63hI~
	filesetcsr(Ppcw,Pplh2,0,0);//last selected line,lcmd field     //~v63jI~
    return 0;                                                      //~v63hI~
}//dlcmddndset                                                     //~v63hI~
//**************************************************************** //~v63hI~
// dlcmddndreset                                                   //~v63hI~
//*clear drag and drop selected line                               //~v63hI~
//*parm1  :pcw                                                     //~v63hI~
//*parm2  :pfh                                                     //~v63hI~
//*rc     :reset sount                                             //~v63hI~
//**************************************************************** //~v63hI~
int dlcmddndreset(PUCLIENTWE Ppcw)                                 //~v63hR~
{                                                                  //~v63hI~
	int ii,cmdno,resetctr=0;                                       //~v63hI~
    PULINEH plh,*pplh;                                             //~v63hI~
    PUFILEH pfh;                                                   //~v63hI~
//*********************                                            //~v63hI~
	pfh=UGETPFHFROMPCW(Ppcw);                                      //~v63hI~
	cmdno=pfh->UFHcmdlinectr;                                      //~v63hR~
	pplh=pfh->UFHcmdline;                                          //~v63hR~
	for (ii=0;ii<cmdno;ii++,pplh++)                                //~v63hI~
    {                                                              //~v63hI~
		plh=*pplh;                                                 //~v63hI~
    	if (!plh)                                                  //~v63hI~
        	continue;                                              //~v63hI~
		if (*plh->ULHlinecmd!=UDLCCMD_DNDSELECT)  //drag and drop selected line//~v63hR~
        	continue;                                              //~v63hI~
		UCBITON(plh->ULHflag,ULHFDRAW);			//redraw line      //~v63hI~
		UCBITOFF(plh->ULHflag,ULHFLINECMD|ULHFLCMDERR);            //~v63hI~
		memset(plh->ULHlinecmd,0,ULHLINENOSZ);                     //~v63hI~
        *pplh=0;	//reset select cmd                             //~v63hI~
        resetctr++;                                                //~v63hI~
	}                                                              //~v63hI~
    if (resetctr==cmdno)	//no remaining cmd                     //~v63hI~
    {                                                              //~v63hI~
		UCBITON(pfh->UFHflag2,UFHF2LCMDCOMP); //processed          //~v63hR~
		pfh->UFHcmdlinectr=0;                                      //~v63hI~
    }                                                              //~v63hI~
	return resetctr;                                               //~v63hI~
}//dlcmddndreset                                                   //~v63hI~
//**************************************************************** //~v63hI~
// dlcmddndgetpendctr                                              //~v64vR~
//*count selected file count                                       //~v64vR~
//*rc     :reset sount                                             //~v63hI~
//**************************************************************** //~v63hI~
//int dlcmddndgetpendctr(PUCLIENTWE Ppcw,PUFILEH Ppfh)             //~v685R~
int dlcmddndgetpendctr(PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH *Ppplh)//~v685I~
{                                                                  //~v63hI~
	int ii,cmdno,pendctr=0;                                        //~v63hI~
    PULINEH plh,*pplh;                                             //~v63hI~
//*********************                                            //~v63hI~
	cmdno=Ppfh->UFHcmdlinectr;                                     //~v63hI~
	pplh=Ppfh->UFHcmdline;                                         //~v63hI~
	for (ii=0;ii<cmdno;ii++,pplh++)                                //~v63hI~
    {                                                              //~v63hI~
		plh=*pplh;                                                 //~v63hI~
    	if (!plh)                                                  //~v63hI~
        	continue;                                              //~v63hI~
		if (*plh->ULHlinecmd==UDLCCMD_DNDSELECT)  //drag and drop selected line//~v63hI~
        {                                                          //~v685I~
        	if (Ppplh)                                             //~v685I~
            	*Ppplh=plh;	//used for dnd copyfile target line    //~v685I~
        	pendctr++;                                             //~v63hI~
        }                                                          //~v685I~
	}                                                              //~v63hI~
    return pendctr;                                                //~v63hI~
}//dlcmddndgetpendctr;                                             //~v63hI~
//#ifdef WXE                                                       //~v64aR~
#ifdef WXEXXE                                                      //~v64aI~
//**************************************************************** //~v63hI~
// dlcmddndsetuplist                                               //~v63hR~
//*dodragdrop parameter setup(drop file list)                      //~v63hR~
//*rc     :rc                                                      //~v63jR~
//**************************************************************** //~v63hI~
int dlcmddndsetuplist(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh,char *Pbuff,int *Pplen)//~v63jR~
{                                                                  //~v63hI~
	int ii,cmdno,totlen=0,len,setfileno=0;                         //~v63hR~
    char *pbuff,fpath[_MAX_PATH];                                  //~v63hI~
    char fpathdnd[_MAX_PATH];                                      //~v63jI~
    PULINEH plh,*pplh;                                             //~v63hI~
    PUDIRLH    pdh;                                                //~v63hI~
    PUFTPHOST puftph;                                              //~v63jI~
//*********************                                            //~v63hI~
	pbuff=Pbuff;                                                   //~v63hI~
	cmdno=Ppfh->UFHcmdlinectr;                                     //~v63hI~
	pplh=Ppfh->UFHcmdline;                                         //~v63hI~
    puftph=(PUFTPHOST)(Ppfh->UFHpuftph);  //ftp cb                 //~v63jR~
    if (puftph)                                                    //~v63jI~
        if (xeftpgetdndwd(fpathdnd))	//mkdir failed             //~v63jI~
        	return 4;                                              //~v63jI~
	for (ii=0;ii<cmdno;ii++,pplh++)                                //~v63hI~
    {                                                              //~v63hI~
		plh=*pplh;                                                 //~v63hI~
    	if (!plh)                                                  //~v63hI~
        	continue;                                              //~v63hI~
		if (*plh->ULHlinecmd!=UDLCCMD_DNDSELECT)  //drag and drop selected line//~v63hR~
        	continue;                                              //~v63hI~
	    pdh=UGETPDH(plh);                                          //~v63hI~
    	if (dlcgetfullname(pdh,fpath))                             //~v63hR~
        	continue;                                              //~v63hI~
	    if (pdh->UDHattr & FILE_DIRECTORY)                         //~v71oI~
        {                                                          //~vaa4I~
          if (Popt & DLCMDDND_NODIR)    //err if directory         //~vaa4I~
          {                                                        //~vaa4I~
            uerrmsg("Directory is not supported",0);               //~vaa4I~
            return 4;                                              //~vaa4I~
          }                                                        //~vaa4I~
          else                                                     //~vaa4I~
//  		dlcmdappendwildcard(0,Ppfh,pdh,fpath);	//0:no appen MEMB_ALL//~v71oI~//~vb7cR~
    		if (dlcmdappendwildcard(0,Ppfh,pdh,fpath,(int)sizeof(fpath)))	//0:no appen MEMB_ALL//~vb7cI~
	            return 4;                                          //~vb7cI~
        }                                                          //~vaa4I~
        if (puftph) //remote file                                  //~v63jI~
//	        dlcmddndremotecopy(Popt,fpath,fpathdnd,Ppfh,puftph,pdh,fpath);//~v63jR~//~vb7eR~
  	        dlcmddndremotecopy(Popt,fpath,fpathdnd,sizeof(fpathdnd),Ppfh,puftph,pdh,fpath);//~vb7eI~
        len=(int)strlen(fpath);                                    //~v63hI~
        if (pbuff)     //setup req                                 //~v63hI~
        {                                                          //~v63hI~
        	memcpy(pbuff,fpath,(UINT)len);                         //~v63hI~
            pbuff+=len;                                            //~v63hI~
          if (Popt & DLCMDDND_SETEOL)    //err if directory        //~vaa4I~
            *pbuff++='\n';                                         //~vaa4I~
          else                                                     //~vaa4I~
            *pbuff++=0;                                            //~v63hI~
        }                                                          //~v63hI~
        setfileno++;                                               //~v63hI~
        totlen+=len+1;                                             //~v63hI~
	}                                                              //~v63hI~
    if (Pplen)                                                     //~v63hI~
	    *Pplen=totlen;                                             //~v63hI~
    return 0;                                                      //~v63hI~
}//dlcmddndsetuplist                                               //~v63hI~
//**************************************************************** //~v63jI~
//!dlcmdmdndremotecopy                                             //~v63jI~
//copy remote file to work dir and return the fpathname            //~v63jI~
//(root is already rejected at dnd selection)                      //~v63jI~
//**************************************************************** //~v63jI~
//int dlcmddndremotecopy(int Popt,char *Pfpathremote,char *Pfpathwd,PUFILEH Ppfh,PUFTPHOST Ppuftph,PUDIRLH Ppdh,char *Pfpathlocal)//~v63jR~//~vb7eR~
int dlcmddndremotecopy(int Popt,char *Pfpathremote,char *Pfpathwd,size_t Pbuffsz,PUFILEH Ppfh,PUFTPHOST Ppuftph,PUDIRLH Ppdh,char *Pfpathlocal)//~vb7eI~
{                                                                  //~v63jI~
    int opt,dirsw,pathlen;                                         //~v63jI~
    UCHAR  *pc,fpathlocal[_MAX_PATH];                              //~v63jR~
    UCHAR  lastname[DSN_MAXLEN],dsnparent[DSN_MAXLEN];             //~v71oR~
    int rc;                                                        //~v71gI~
//******************                                               //~v63jI~
  	opt=XEFTP_GRC_PARMDIR;                                         //~v63jI~
  	opt|=XEFTP_GRC_FPATH;	//for TSO,do fsta by fpath             //~v8@sR~
    dirsw=Ppdh->UDHattr & FILE_DIRECTORY;                          //~v63jI~
    if (dirsw)                                                     //~v63jI~
    	opt|=XEFTP_GRC_SUBDIR|XEFTP_GRC_SUBDIRCOPY;	//copy dir and subdir//~v63jR~
    if (Popt & DLCMDDND_REMOTECOPY)                                //~v63jI~
//   	if (xeftpgetremotecopy(opt,Pfpathremote,Ppuftph,Pfpathwd)) //~v71gR~
//     	if (rc=xeftpgetremotecopy(opt,Pfpathremote,Ppuftph,Pfpathwd),rc)//~v8@sR~
//     	if (rc=xeftpgetremotecopy(opt,Pfpathremote,Ppuftph,Pfpathwd,Pfpathremote),rc)//~v8@sR~//~vb7eR~
       	if (rc=xeftpgetremotecopy(opt,Pfpathremote,Ppuftph,Pfpathwd,Pbuffsz,Pfpathremote),rc)//~vb7eI~
        {                                                          //~v71gI~
          if (!(UFTPHISTSO(Ppuftph) && rc==DCPY_RC_NOTCOPY))//invalid membername//~v71gI~
    		return 4;                                              //~v63jR~
        }                                                          //~v71gI~
//  pathlen=strlen(Pfpathwd);                                      //~v63jI~//~vb30R~
    pathlen=(int)strlen(Pfpathwd);                                 //~vb30I~
    pc=fpathlocal;                                                 //~v63jR~
    memcpy(pc,Pfpathwd,(UINT)pathlen);                             //~v63jI~
    pc+=pathlen;                                                   //~v63jI~
    *pc++=DIR_SEPC;                                                //~v63jR~
  if (UFTPHISTSO(Ppuftph))                                         //~v71gR~
  {                                                                //~v71gR~
    rc=u3270parsedsn(U3PD_DROPQUOTE|U3PD_DROPHOSTID|U3PL_DROPWILDORMEMBER,Pfpathremote,dsnparent,lastname);		//membername//~v71oR~
    if (rc & U3PD_RC_MEMBER)	//member specified                 //~v71gR~
    	if (rc & U3PD_RC_WILD)	//member wildcard                  //~v71gI~
		    sprintf(pc,"%s%c%s",dsnparent,DIR_SEPC,lastname);      //~v71gI~
        else                                                       //~v71gI~
		    strcpy(pc,lastname);                                   //~v71gR~
    else                                                           //~v71gI~
    	if (rc & U3PD_RC_WILD)	//dsn wildcard                     //~v71gI~
		    sprintf(pc,"%s.%s",dsnparent,lastname);                //~v71gR~
        else                                                       //~v71gI~
		    strcpy(pc,dsnparent);                                  //~v71gR~
  }                                                                //~v71gI~
  else                                                             //~v71gI~
  {                                                                //~v71oI~
    strcpy(pc,Ppdh->UDHname);                                      //~v63jR~
    pathlen=PATHLEN(Pfpathremote);                                 //~v71oI~
    if (pathlen>0 && WILDCARD(Pfpathremote+pathlen))               //~v71oR~
    {                                                              //~v71oI~
        pc+=strlen(pc);                                            //~v71oI~
        *pc++=DIR_SEPC; //local seperator                          //~v71oI~
        strcpy(pc,Pfpathremote+pathlen);                           //~v71oR~
    }                                                              //~v71oI~
  }                                                                //~v71oI~
    strcpy(Pfpathlocal,fpathlocal);                                //~v63jI~
    return 0;                                                      //~v63jI~
}//dlcmdmdndremotecopy                                             //~v63jR~
#endif                                                             //~v63hR~
#endif //WXE or LNX                                                //~v63nI~
//**************************************************************** //~v54sI~
// dlccleardeleted                                                 //~v54sI~
//*clear deleted plh entry                                         //~v54sI~
//*rc     :none                                                    //~v54sI~
//**************************************************************** //~v54sI~
int dlccleardeleted(PUFILEH Ppfh)                                  //~v54sI~
{                                                                  //~v54sI~
	int ii,jj,cmdno;                                               //~v54sI~
    PULINEH plh,*pplhi,*pplho;                                     //~v54sI~
//*********************                                            //~v54sI~
	cmdno=Ppfh->UFHcmdlinectr;                                     //~v54sI~
	pplho=pplhi=Ppfh->UFHcmdline;                                  //~v54sI~
	for (ii=0,jj=0;ii<cmdno;ii++,pplhi++)                          //~v54sI~
    {                                                              //~v54sI~
		plh=*pplhi;                                                //~v54sI~
        if (!plh)                                                  //~v54sI~
        	continue;                                              //~v54sI~
        *pplho++=plh;                                              //~v54sI~
        jj++;                                                      //~v54sI~
	}                                                              //~v54sI~
	Ppfh->UFHcmdlinectr=jj;                                        //~v54sI~
    return jj;                                                     //~v54sR~
}//dlccleardeleted                                                 //~v54sI~
//**************************************************************** //~vb81I~
// dlccleardeleted                                                 //~vb81I~
//*clear deleted plh entry                                         //~vb81I~
//*rc     :none                                                    //~vb81I~
//**************************************************************** //~vb81I~
int dlcsrchplh(int Popt,PUFILEH Ppfh,PULINEH Pplh)                 //~vb81I~
{                                                                  //~vb81I~
	int ii,jj=-1,cmdno;                                            //~vb81I~
    PULINEH plh,*pplh;                                             //~vb81I~
//*********************                                            //~vb81I~
	cmdno=Ppfh->UFHcmdlinectr;                                     //~vb81I~
	pplh=Ppfh->UFHcmdline;                                         //~vb81I~
	for (ii=0;ii<cmdno;ii++)                                       //~vb81R~
    {                                                              //~vb81I~
		plh=*pplh++;                                               //~vb81R~
        if (plh==Pplh)                                             //~vb81I~
        {                                                          //~vb81I~
        	jj=ii;                                                 //~vb81I~
        	break;                                                 //~vb81I~
        }                                                          //~vb81I~
	}                                                              //~vb81I~
    UTRACEP("%s:rc=index=%d,plh=%p\n",UTT,jj,Pplh);                //+vb81R~
    return jj;                                                     //~vb81I~
}//dlcsrchplh                                                      //~vb81I~
//**************************************************************** //~v54EI~
// dlcclearplcdeleted                                              //~v54EI~
//*clear plh of plc when deleted from pfh list                     //~v54EI~
//*rc     :none                                                    //~v54EI~
//**************************************************************** //~v54EI~
int dlcclearplcdeleted(PULINEH Pplh)                               //~v54EI~
{                                                                  //~v54EI~
	UDLCMD   *plc;                                                 //~v54EI~
	int ii,jj;                                                     //~v54EI~
//*********************                                            //~v54EI~
	for (ii=0,jj=0,plc=Slcmd;ii<Scmdno;ii++,plc++)                 //~v54EI~
	{                                                              //~v54EI~
		if (plc->UDLCplh==Pplh)                                    //~v54EI~
        {                                                          //~v54EI~
        	jj++;                                                  //~v54EI~
			plc->UDLCplh=0;	                                       //~v54EI~
        }                                                          //~v54EI~
    }                                                              //~v54EI~
    return jj;                                                     //~v54EI~
}//dlcclearplcdeleted                                              //~v54EI~
//****************************************************************
// dlcotherclient                                               //~5715R~
//*process lcmd paired with other client 
//*rc   :0
//****************************************************************
int dlcotherclient(PUCLIENTWE Ppcwc,PUCLIENTWE Ppcwo)           //~5715R~
{
	PUFILEH pfhc,pfho;                                          //~v03uR~
	UDLCMD   *plc,*plco;                                        //~5715R~
	int rc;
//*********************	
	if (!Ppcwo || Ppcwo->UCWtype!=UCWTDIR)                      //~5715R~
		return 0;		//no split status or not file client
	pfhc=((PUFILEC)Ppcwc->UCWpfc)->UFCpfh;	//my client .       //~v03uI~
	pfho=((PUFILEC)Ppcwo->UCWpfc)->UFCpfh;	//other client .    //~v03uI~
    if (pfhc==pfho)    //same file                              //~v03uI~
		return 0;		//no need process                       //~v03uI~
	if (!UCBITCHK(pfho->UFHflag2,UFHF2LCMDCOMP) //not yet processed//~v03uR~
	||  !pfho->UFHpendctr)	//no pending commnad line           //~v03uR~
		return 0;	//need change active client and process
//upctr                                                         //~5723I~
	UPCTRREQ(pfho);	//for first time sw of batch process        //~v03uR~
//*combine 2 pending commnad
	plc=Slcmd;
//  memcpy(plc,pfhc->UFHpvlcmd,(UINT)UDLCMDSZ*pfhc->UFHpendctr);//~v03uR~//~vb30R~
    memcpy(plc,pfhc->UFHpvlcmd,UDLCMDSZ*(size_t)pfhc->UFHpendctr); //~vb30R~
	plco=plc+=pfhc->UFHpendctr;	//for other current             //~v03uR~
//  memcpy(plc,pfho->UFHpvlcmd,(UINT)UDLCMDSZ*pfho->UFHpendctr);//other//~v03uR~//~vb30R~
    memcpy(plc,pfho->UFHpvlcmd,UDLCMDSZ*(size_t)pfho->UFHpendctr);//other//~vb30R~
	Scmdno=pfhc->UFHpendctr+pfho->UFHpendctr;                   //~v03uR~
//  if (pfcc->UFCpfh==pfco->UFCpfh)	//same file                 //~v03uR~
//    	qsort(Slcmd,(UINT)Scmdno,sizeof(UDLCMD),dlclinenocomp);//sort//~v03uR~
	dlcproc(Ppcwc);                                             //~5715R~
#ifdef FTPSUPP                                                     //~v609I~
	dlcftpfree(Ppcwc);                                             //~v609R~
#endif                                                             //~v609I~
	scrfulldraw(Ppcwc);                                         //~5126I~
	if ((rc=dlcsavepend(Ppcwo,plco,pfho->UFHpendctr))>=4)       //~v03xR~
		uerrmsg("Error on another screen",                      //~v03xI~
				"もう一方の画面に誤りあり");                    //~v03xI~
	rc=max(rc,dlcsavepend(Ppcwc,Slcmd,pfhc->UFHpendctr));       //~v03uR~
	return rc;
}//otherclient
//****************************************************************
// linecmd process
//*rc   :0
//****************************************************************
int dlcproc(PUCLIENTWE Ppcw)                                    //~5715R~
{
//  UDLCMD   *plc,*plcn=0,*plcp=0,*plcxp;                       //~v058R~//~vaf9R~
    UDLCMD   *plc,*plcn=0,*plcp=0,*plcxp=0;                        //~vaf9I~
	UDLCMD   *plcac=0;		//for % cmd                            //~v51WI~//~vaf9R~
	UDLCMD   *plcgreplast=NULL,*plcgrep1st=NULL;		//for % cmd            //~v75JR~//~vaf9R~
	int acctr=0,acrc=0;                                            //~v51WI~
    int grepctr=0;                                                 //~v75JR~
    int compctr=0;                                                 //~v75MI~
	int ii,disp=0,nodisp=0,xpctr=0,xprc=0,brerrsw=0,nobrmode;      //~v41cR~
#ifdef FTPSUPP                                                     //~v609R~
	int ftprc=0;                                                   //~v66bR~
    PUFILEH pfh;                                                   //~v609I~
#endif                                                             //~v609R~
    PUFILEC pfc;                                                   //~v41cI~
//static int Sgrepctr;                                             //~v76gR~
//static int Scompctr;                                             //~v76gR~
//*********************	
//mix chk                                                       //~5716I~
	pfc=Ppcw->UCWpfc;                                              //~v41cI~
#ifdef FTPSUPP                                                     //~v609R~
	pfh=pfc->UFCpfh;                                               //~v609I~
#endif                                                             //~v609I~

    
	
	nobrmode=UCBITCHK(pfc->UFCflag,UFCFDEDIT);   //dir list by edit cmd//~v41cI~
                                                                   //~v41cI~
	for (ii=0,plc=Slcmd;ii<Scmdno;ii++,plc++)                   //~v04aR~
	{                                                           //~5716I~
      	if (!nobrmode)   //dir list by edit cmd                    //~v41cI~
			if (UCBITCHK(plc->UDLCtype,UDLCTERRBRW))	//err when brose mode//~v41cI~
                brerrsw=1;                                         //~v41cI~
    	if (UCBITCHK(plc->UDLCflag,UDLCFERR))//already err      //~v05fR~
    		continue;                                           //~v05fR~
		if (!plc->UDLCcmd)                                      //~5722R~
        {                                                       //~v03xM~
			dlcresultset(0,plc,0);                              //~v03xM~
        	continue;                                           //~5722I~
		}                                                       //~v03xM~
		if (plc->UDLCcmd==UDLCCMD_GREPUPPER)  //grep cmd           //~v75JR~
        {                                                          //~v75JI~
        	if (!grepctr)                                          //~v75JI~
            {                                                      //~v75JI~
//  			if (dlcsamechk(Ppcw,UDLCCMD_GREPUPPER,&plcgreplast,&plcgrep1st))//reverse process sequence//~v75MR~
    			if (dlcsamechk(Ppcw,UDLCCMD_GREPUPPER,&plcgreplast,&plcgrep1st,0))//reverse process sequence//~v75MI~
//              	return 4;                                      //~v75MR~
					return dlcresultset(4,plc,0);                  //~v75MI~
//              Sgrepctr++;	//redirectfile suffix                  //~v76gR~
                Ggrepctr++;	//redirectfile suffix                  //~v76gI~
            }                                                      //~v75JI~
//          plc->UDLCparm1=(UCHAR)Sgrepctr;                        //~v76gR~
            plc->UDLCparm1=(UCHAR)Ggrepctr;                        //~v76gI~
            if (plc==plcgreplast)                                  //~v75JI~
            	UCBITON(plc->UDLCflag,UDLCFLAST);                  //~v75JR~
            else                                                   //~v75JI~
            	UCBITOFF(plc->UDLCflag,UDLCFLAST);                 //~v75JI~
            if (plc==plcgrep1st)                                   //~v75JI~
            	UCBITON(plc->UDLCflag,UDLCF1ST);                   //~v75JI~
            else                                                   //~v75JI~
            	UCBITOFF(plc->UDLCflag,UDLCF1ST);                  //~v75JI~
            grepctr++;                                             //~v75JI~
        }                                                          //~v75JI~
        else                                                       //~v75MI~
		if (plc->UDLCcmd==UDLCCMD_COMPARE)  //"=" cmd              //~v75MI~
        {                                                          //~v75MI~
        	if (!compctr)                                          //~v75MI~
            {                                                      //~v75MI~
//              Scompctr++;	//redirectfile suffix                  //~v76gR~
                Gcompctr++;	//redirectfile suffix                  //~v76gI~
            	compctr=2;	//input parm as max line cnt           //~v75MI~
				if (dlcsamechk(Ppcw,plc->UDLCcmd,&plcgrep1st,&plcgreplast,&compctr))//1st file is aboove line//~v75MR~
					return dlcresultset(4,plc,0);                  //~v75MI~
//  	        plcgrep1st->UDLCparm1=(UCHAR)Scompctr;             //~v76gR~
    	        plcgrep1st->UDLCparm1=(UCHAR)Gcompctr;             //~v76gI~
//  	        plcgreplast->UDLCparm1=(UCHAR)Scompctr;            //~v76gR~
		        plcgreplast->UDLCparm1=(UCHAR)Gcompctr;            //~v76gI~
                if (compctr==1)	//on one line                      //~v75MR~
					plcgreplast=0;		//chk file specified on rename fld//~v75MR~
            }                                                      //~v75MI~
        }                                                          //~v75MI~
		if (plc->UDLCtype & UDLCTDISPLAY)	//display cmd       //~5722I~
        {                                                       //~5716I~
            disp=1;                                             //~5716M~
         	if (nodisp)                                         //~5716I~
            {                                                   //~v058I~
				dlcresultset(4,plc,plcp);                       //~v058I~
                break;                                          //~v058I~
            }                                                   //~v058I~
            plcp=plc;                                           //~5716I~
        }                                                       //~5716I~
        else                                                    //~5716I~
        {                                                       //~5716I~
            nodisp=1;                                           //~5716M~
         	if (disp)                                           //~5716I~
            {                                                   //~v058I~
				dlcresultset(4,plc,plcp);                       //~v058I~
            	break;                                          //~5716I~
            }                                                   //~v058I~
            plcp=plc;                                           //~5716I~
        }                                                       //~5716I~
		if (plc->UDLCcmd=='P'	//print cmd                     //~v058I~
//      &&  !Gprintcmd)	//use xprint                               //~v07uR~
        &&  UCBITCHK(Gprocstatus,GPROCSXPRINT))//use xprint        //~v07uI~
        {                                                       //~v058I~
        	plcxp=plc;	//last print file(print start)          //~v058I~
        	xpctr++;                                            //~v058I~
            if (dlcmdxpflist(Ppcw,plc,xpctr))                   //~v058R~
            {                                                   //~v058I~
            	xprc=4;                                         //~v058I~
				dlcresultset(4,plc,plcp);                       //~v058I~
                break;                                          //~v058I~
			}                                                   //~v058I~
        }                                                       //~v058I~
//  	if (plc->UDLCcmd==DLCMD_APPCMD)	//apply cmd                //~v59eR~
    	if (plc->UDLCcmd==DLCMD_APPCMD 	//apply cmd                //~v59eI~
    	||  plc->UDLCcmd==DLCMD_APPASYNC 	//apply cmd async($)   //~vamzR~
		||  plc->UDLCcmd==DLCMD_SUBRSH)	//submit/rsh               //~v59eI~
        {                                                          //~v51WI~
        	plcac=plc;	//last print file(print start)             //~v51WI~
        	acctr++;                                               //~v51WI~
            if (dlcmdaclist(Ppcw,plc,acctr))	//write cmd string to temp cmd file//~v51WI~
            {                                                      //~v51WI~
            	acrc=4;                                            //~v51WI~
				dlcresultset(4,plc,plcp);                          //~v51WI~
                break;                                             //~v51WI~
			}                                                      //~v51WI~
        }                                                          //~v51WI~
#ifdef FTPSUPP                                                     //~v609R~
        if (FILEISREMOTE(pfh))                                     //~v609R~
        {                                                          //~v609R~
          if (!FILEISTSO(pfh))	//not TSO file                     //~v71eI~
          {                                                        //~v71eI~
    		if (UCBITCHK(plc->UDLCtype2,UDLCT2DELCMD))	//err when brose mode//~v609R~
            	if (ftprc=dlcftpaddentry(Ppcw,pfh->UFHpuftph,plc),ftprc)//~v609R~
                	return ftprc;                                  //~v609R~
          }                                                        //~v71eI~
        }                                                          //~v609R~
#endif                                                             //~v609R~
	}                                                           //~5716I~
    if (brerrsw)                                                   //~v41cI~
    {                                                              //~v41cI~
    	uerrmsg("\"admruz0/\" is not avail when browse mode",      //~v41cI~
    	        "\"admruz0/\" は\x95\\示モードでは不可");          //~v41cI~
		return 4;                                                  //~v41cI~
	}                                                              //~v41cI~
    if (disp && nodisp)                                         //~5716I~
    {                                                           //~5716I~
    	uerrmsg("Browse/Edit and others cannot be mixed",       //~5716I~
//      		"表示/編集とそれ以外を混在出来ません");            //~v095R~
        		"\x95\\示/編集とそれ以外を混在出来ません");        //~v095R~
		return 4;                                               //~v058R~
	}                	                                        //~5716I~
//notify to xedlcmd3                                            //~v058I~
    if (xpctr)                                                  //~v058I~
    {                                                           //~v058I~
    	if (dlcmdxpflist(Ppcw,plcxp,0))	//close stdin,print when plcxp//~v058R~
           	xprc=4;                                             //~v058I~
    	if (xprc)                                               //~v058I~
			return 4;                                           //~v058I~
    }                                                           //~v058I~
//for %cmd                                                         //~v51WI~
    if (acctr)                                                     //~v51WI~
    {                                                              //~v51WI~
    	if (dlcmdaclist(Ppcw,plcac,0))	//0:last call,close cmd file//~v51WI~
           	acrc=4;                                                //~v51WI~
    	if (acrc)                                                  //~v51WI~
			return 4;                                              //~v51WI~
    }                                                              //~v51WI~
//#ifdef FTPSUPP                                                   //~v62iR~
//    if (UGETQCTR(&Sftpdelqh))                                    //~v62iR~
//        if ((ftprc=dlcftpmultidel(Ppcw,pfh->UFHpuftph))==UALLOC_FAILED)//~v62iR~
//            return ftprc;                                        //~v62iR~
//#endif                                                           //~v62iR~
                                                                //~5716I~
//	for (i=0;i<Scmdno;i++)                                      //~v04aR~
  	for (ii=Scmdno-1;ii>=0;ii--)                                //~v04aI~
	{
		plc=Slcmd+ii;                                           //~v04aR~
		if (UCBITCHK(plc->UDLCflag,UDLCFERR))	//already err detected//~5715R~
			continue;
		if (!plc->UDLCcmd)                                      //~5722I~
        	continue;                                           //~5722I~
		switch(plc->UDLCtype & (UDLCTPOSCMD | UDLCTNEEDPOS))	//pair cmd?//~5716R~
		{
		case UDLCTNOPAIR:                                       //~5715R~
			if (plc->UDLCcmd==UDLCCMD_COMPARE)  //grep cmd         //~v75MI~
            {                                                      //~v75MI~
            	if (plc==plcgrep1st)                               //~v75MR~
                {                                                  //~v75MI~
					if (dlccallfunc(Ppcw,plcgrep1st,plcgreplast))  //~v75MR~
						return 4;                                  //~v75MI~
                }                                                  //~v75MI~
            }                                                      //~v75MI~
            else                                                   //~v75MI~
			if (dlccallfunc(Ppcw,plc,0))                        //~5723R~
				return 4;                                       //~5721R~
			if (plc->UDLCcmd=='P')	//!!!premise:process from last //~v07gI~
			                        //xprint indirect file write from first//~v07gI~
            	dlcprinted(Ppcw,plc);	//printed flag on          //~v07gR~
			break;
		case UDLCTPOSCMD:	//pair cmd dest                     //~5715R~
			if (plcn)
			{
				if (dlccallfunc(Ppcw,plc,plcn))//plc update     //~5723I~
					return 4;
				plcn=0;
			}
			else
            {                                                   //~5315I~
                if (plcp)                                       //~5315I~
					return dlcresultset(4,plc,0);               //~5715R~
				plcp=plc;
			}                                                   //~5315I~
			break;
		case UDLCTNEEDPOS:	//pair cmd                          //~5715R~
			if (plcp)	//pos cmd already detected
			{
				if (dlccallfunc(Ppcw,plcp,plc))	//plcp update   //~5723I~
					return 4;
				plcp=0;	//pos cmd processed
			}
			else		//not yet pos cmd found
				plcn=plc;	//for next pos cmd
			break;
		}//switch by type
	}//all line cmd
//xprint from stdin                                             //~v058I~
//for g cmd                                                        //~v75JI~
	if (plcp)
		UCBITON(plcp->UDLCflag,UDLCFPEND);                      //~5715R~
	if (plcn)		//pos cmd not found(need cmd ptr pending)
		UCBITON(plcn->UDLCflag,UDLCFPEND);                      //~5715R~

#ifdef FTPSUPP                                                     //~v609I~
	if (ftprc)                                                     //~v609I~
	    return ftprc;                                              //~v609I~
#endif                                                             //~v609I~
	return 0;	
}//dlcproc                                                      //~5715R~

//**************************************************************** //~v75JI~
// dlcsamechk                                                      //~v75JI~
//   chk lcmd is all same                                          //~v75JI~
//*rc   :0                                                         //~v75JI~
//**************************************************************** //~v75JI~
//int dlcsamechk(PUCLIENTWE Ppcw,UCHAR Pcmdid,PUDLCMD *Ppplc1,PUDLCMD *Ppplc2)//~v75MR~
int dlcsamechk(PUCLIENTWE Ppcw,UCHAR Pcmdid,PUDLCMD *Ppplc1,PUDLCMD *Ppplc2,int *Pplinecnt)//~v75MI~
{                                                                  //~v75JI~
//  UDLCMD   *plc,*plc1=0,*plc2;                                   //~v75JR~//~vaf9R~
    UDLCMD   *plc,*plc1=0,*plc2=NULL;                              //~vaf9I~
    int ii;                                                        //~v75JI~
    int maxline,linecnt=0;                                         //~v75MI~
//**************                                                   //~v75JI~
	if (Pplinecnt)                                                 //~v75MI~
    	maxline=*Pplinecnt;                                        //~v75MI~
    else                                                           //~v75MI~
    	maxline=0;                                                 //~v75MI~
    for (ii=0,plc=Slcmd;ii<Scmdno;ii++,plc++)                      //~v75JI~
    {                                                              //~v75JI~
    	if (UCBITCHK(plc->UDLCflag,UDLCFERR))//already err         //~v75JI~
    		continue;                                              //~v75JI~
		if (!plc->UDLCcmd)                                         //~v75JI~
        	continue;                                              //~v75JI~
        if (plc->UDLCcmd!=Pcmdid)   //grep cmd                     //~v75JI~
            return dlcerrmixed(Pcmdid);                            //~v75JI~
        plc2=plc;                                                  //~v75JI~
        if (!plc1)                                                 //~v75JI~
        	plc1=plc;                                              //~v75JI~
        linecnt++;                                                 //~v75MI~
    }                                                              //~v75JI~
    if (Ppplc1)                                                    //~v75JI~
    	*Ppplc1=plc1;                                              //~v75JI~
    if (Ppplc2)                                                    //~v75JI~
    	*Ppplc2=plc2;                                              //~v75JI~
    if (maxline && linecnt>maxline)                                //~v75MI~
    {                                                              //~v75MI~
        uerrmsg("too many selected line for '%c' cmd(max=%d)",0,   //~v75MR~
					Pcmdid,maxline);                               //~v75MR~
                                                                   //~v75MI~
		return 4;                                                  //~v75MI~
    }                                                              //~v75MI~
	if (Pplinecnt)                                                 //~v75MI~
    	*Pplinecnt=linecnt;                                        //~v75MI~
    return 0;                                                      //~v75JI~
}//dlcsamechk                                                      //~v75JI~
//****************************************************************//~5723I~
// dlccallfunc                                                  //~5723I~
//*rc   :0                                                      //~5723I~
//****************************************************************//~5723I~
int dlccallfunc(PUCLIENTWE Ppcw,PUDLCMD Pplc1,PUDLCMD Pplc2)    //~5723R~
{                                                               //~5723I~
	PUFILEH pfh;                                                //~5723I~
    int rc;                                                     //~5723I~
    UDLCFUNC *dlcfunc;                                          //~5731R~
//*********************	                                        //~5723I~
    Ppcw->UCWreason=0;          //parm init(first use at dlcmddeleter)//~v05SI~
	if (!(dlcfunc=Pplc1->UDLCpfunc))	//not defined           //~5731R~
    	rc=4;                                                   //~5731I~
	else                                                        //~5731I~
    {                                                              //~v09lI~
	    csrsetwait(1);      //set wait mode csr if now not wait    //~v09lI~
		rc=(dlcfunc)(Ppcw,Pplc1,Pplc2);                         //~5731R~
    }                                                              //~v09lI~
	if (dlcresultset(rc,Pplc1,Pplc2))                           //~5723I~
		return rc;                                              //~5723I~
	pfh=UGETPFH(Pplc1->UDLCplh);                                //~5723I~
	UCBITOFF(pfh->UFHflag,UFHFUPCTRREQ);	//this time updated //~5723I~
    if (Pplc2)                                                  //~5723I~
    {                                                           //~5723I~
		pfh=UGETPFH(Pplc2->UDLCplh);                            //~5723I~
		UCBITOFF(pfh->UFHflag,UFHFUPCTRREQ);//this time updated //~5723I~
	}                                                           //~5723I~
    return 0;                                                   //~5723I~
}//dlccallfunc                                                  //~5723I~
                                                                //~5723I~
//********************************************************************
//*cmd process result chk
//*if rc=2,continue to next line                                   //~v75QI~
//*parm1:rc
//*parm2:singlecmd
//*parm3:pair dest cmd
//*retrn:same as input r.c
//********************************************************************
int dlcresultset(int Prc,UDLCMD *Pplcc,UDLCMD *Pplcd)           //~5715R~
{	
	UCHAR result;                                               //~5129I~
//*************
	switch(Prc)                                                 //~5129I~
	{                                                           //~5129I~
	case 0:                                                     //~5129I~
		result=UDLCFCOMP;                                       //~5715R~
		break;                                                  //~5129I~
	case 1:                                                     //~5129I~
		result=UDLCFPEND;                                       //~5715R~
		break;                                                  //~5129I~
	default:                                                    //~5129I~
		result=UDLCFERR;                                        //~5715R~
		break;                                                  //~5129I~
	}                                                           //~5129I~
	UCBITON(Pplcc->UDLCflag,result);                            //~5715R~
	if (Pplcd)                                                  //~5129R~
		UCBITON(Pplcd->UDLCflag,result);                        //~5715R~
    if (Prc==2) //rc of err but continue                           //~v75QI~
        return 0;                                                  //~v75QI~
	return Prc;
}//dlcresultset                                                 //~5715R~
//********************************************************************
//*getlinecmd
//* get line cmd text(drop preceding space) and return length
//* parm1 :pcw
//* parm2 :plh                                                  //~5311R~
//* parm3 :UDLCMD structure addr                                //~5715R~
//* retrn :0:ok,4 err cmd
//********************************************************************
int dlcgetlinecmd(PULINEH Pplh,UDLCMD *Pplcmd)                  //~5715R~
{
	int cmdlen;                                                 //~v069R~
	UCHAR *inplcmd;                                             //~v069R~
	UDLCMD *plc;                                                //~5715R~
	PUDIRLH pdh;                                                   //~v57dI~
//*****************
	pdh=UGETPDH(Pplh);                                             //~v57dR~
    inplcmd=Pplh->ULHlinecmd;                                   //~5311I~
	memset(Pplcmd,0,sizeof(UDLCMD));                            //~5715R~
//drop preceding space
//	for (ii=0,pc=inplcmd;ii<ULHLINENOSZ-1;ii++,pc++)            //~v069R~
//		if (*pc!=' ')                                           //~v069R~
//			break;                                              //~v069R~
//get command verb
//	strncpy(inplcmd,pc,ULHLINENOSZ);                            //~v069R~
	if (*inplcmd==' ')                                          //~v069I~
    	*inplcmd=0;                                             //~v069I~
    *(inplcmd+1)=0;                                             //~v069I~
    cmdlen=(int)strlen(inplcmd);                                //~5715I~
	if (!cmdlen)
		return 0;
	if (cmdlen!=1)
        return errlcmd();                                       //~v03xI~
//chk command verb
    Sorgcmdid=*inplcmd;     //parm to dlcmdmain to get upper case id//~v44fI~
	plc=dlcsrchcmdtbl(*inplcmd);                                //~5716I~
	if (!plc)                                                   //~5716R~
//      return errlcmd();                                          //~v10pR~
		return dlcverberr();                                       //~v10pI~
    if (UCBITCHK(plc->UDLCtype,UDLCTERRPATH))   //cmd type:err cmd on path rec//~v57dI~
    {                                                              //~v57dI~
        if (pdh->UDHtype==UDHTPARENT)                              //~v57dI~
            return dlcerrrecord(*inplcmd);                         //~v57dI~
    }                                                              //~v57dI~
//  if (plc->UDLCcmd=='S')	//select                               //~v47PR~
//  	*Pplcmd=*Splcselect;	//copy structure,browse or edit    //~v47PR~
//  else                                                           //~v47PR~
		*Pplcmd=*plc;	//copy structure                        //~5721R~

	return 0;
}//dlcgetlinecmd                                                //~5715R~
//**********************************************************************//~5716I~
//* search lcmd tbl                                             //~5716I~
//* parm1:1 byte line command                                   //~5716I~
//* return:plc(null if err)                                     //~5716I~
//**********************************************************************//~5716I~
UDLCMD *dlcsrchcmdtbl(UCHAR Pcmd)                               //~5716I~
{                                                               //~5716I~
	UCHAR cmdid;                                                //~5716I~
	UDLCMD *plc;                                                //~5716I~
//*****************                                             //~5716I~
	cmdid=(UCHAR)toupper(Pcmd);                                 //~5716I~
	for(plc=Scmdlist;plc->UDLCcmd;plc++)                        //~5716M~
		if (cmdid==plc->UDLCcmd)                                //~5716M~
			return plc;                                         //~5716I~
	return 0;                                                   //~5716I~
}//dlcsrchcmdtbl                                                //~5716I~
                                                                //~5716I~
//**********************************************************************
//* file name compare for sort
//*  return code: -1: ent1<ent2
//*                0: ent1=ent2
//*                1: ent1>ent2
//**********************************************************************
int dlclinenocomp(const void *Pent1,const void *Pent2)          //~5715R~
{
	long rc;
	PULINEH plh1,plh2;
//*****************
//  plh1=((UDLCMD*)(ULONG)Pent1)->UDLCplh;                         //~v54bR~//~vafkR~
    plh1=((UDLCMD*)(ULPTR)Pent1)->UDLCplh;                         //~vafkI~
//  plh2=((UDLCMD*)(ULONG)Pent2)->UDLCplh;                         //~v54bR~//~vafkR~
    plh2=((UDLCMD*)(ULPTR)Pent2)->UDLCplh;                         //~vafkI~
	if (plh1->ULHtype==ULHTEXCLUDE)
		plh1=UGETQNEXT(plh1);
	if (plh2->ULHtype==ULHTEXCLUDE)
		plh2=UGETQNEXT(plh2);
	rc=plh1->ULHlinenor - plh2->ULHlinenor;
    if (rc<0)                                                   //~5428R~
        return -1;                                              //~5428I~
    else                                                        //~5428R~
    	if (rc>0)                                               //~5428I~
            return  1;                                          //~5428I~
	return (plh1->ULHsuffix - plh2->ULHsuffix);
}//dlclinenocomp                                                //~5715R~
                                                                //~5223I~
//**********************************************************************//~5716I~
//* line cmd field event(full/clear)                            //~5716I~
//* parm 1:pcw                                                  //~5716I~
//* parm 2:UFLD                                                 //~5716I~
//* parm 3:data                                                 //~5716I~
//* parm 4:event id(0:full/1:clear)                             //~5716I~
//* ret   :rc                                                   //~5716I~
//**********************************************************************//~5716I~
int dlcmdfe(PUCLIENTWE Ppcw,UFLDE *Ppfle,UCHAR *Pdata,int Peventid)//~5716R~
{                                                               //~5716I~
	UDLCMD *plc;                                                //~5716I~
	PULINEH plh;                                                //~5716R~
	PUFILEC pfc;                                                   //~v41cI~
#ifdef OS2                                                         //~v0f3I~
	PUFILEH pfh;                                                   //~v0f3I~
#endif                                                             //~v0f3I~
	PUFLD   pfld;                                               //~5716R~
	PUDIRLH pdh;                                                //~5716R~
    PUPANELL ppl;                                               //~5716I~
	PUSCRD  psd;                                                //~v045I~
//*****************                                             //~5716I~
	if (Ppcw->UCWrcsry<=CMDLINENO)                              //~5716I~
    	return 0;					//ignore,next tab           //~5716R~
    if (Ppfle->UFLfieldno)			//not cmd input field       //~5716I~
    	return 0;					//ignore,next tab           //~5716I~
    pfc=Ppcw->UCWpfc;                                              //~v41cI~
	psd=Ppcw->UCWpsd;                                           //~v045I~
	UCBITON(psd->USDflag2,USDF2DRAW);   //clear err msg         //~v045I~
    ppl=&((PUPANELC)Ppcw->UCWppc)->UPCline[Ppcw->UCWrcsry];     //~5716R~
    pfld=ppl->UPLpfld;                                          //~5716I~
	plh=(Ppcw->UCWpsd+Ppcw->UCWrcsry)->USDbuffc;                //~5716I~
    pdh=UGETPDH(plh);                                           //~5716R~
	UCBITOFF(plh->ULHflag,ULHFLCMDERR);                         //~5716I~
	UCBITOFF(pdh->UDHflag,UDHFMASK);//reset rename              //~v05uR~
	UCBITOFF(pdh->UDHflag4,UDHF4APPCMD|UDHF4APPCMDASYNC);//rename field is %/$ cmd;for cut after executed//~vamJI~
                                                                //~v05uI~
	if (UCBITCHK(pdh->UDHflag,UDHFMASK2))//rename/undel pend    //~v05uI~
    {                                                           //~v05uI~
	    dirsavename(plh,"");    //free move target              //~v05uI~
		UCBITOFF(pdh->UDHflag,UDHFMASK2);//rename/undel pend    //~v05uI~
    }                                                           //~v05uI~
	if (!Peventid)	//field full                                //~5716R~
    {                                                           //~5716I~
		if (!(plc=dlcsrchcmdtbl(*Pdata)))		//search cmd    //~5716I~
        {                                                       //~5716I~
			UCBITON(plh->ULHflag,ULHFLCMDERR);                  //~5716I~
//            uerrmsg("Invalid,Use one of \"abcdefmprsuvwxyz02>+-/:.\"",//~v10pR~
//                    "無効なコマンド文字(\"abcdefmprsuvwxyz02>+-/:.\")");//~v10pR~
//            return 4;                                            //~v10pR~
			return dlcverberr();                                   //~v10pI~
        }                                                       //~5716I~
		dlcfuncdescription(plc->UDLCcmd);                          //~vamzI~
		if (UCBITCHK(plc->UDLCtype,UDLCTERRPATH))	//cmd type:err cmd on path rec//~v57dI~
            if (pdh->UDHtype==UDHTPARENT)                          //~v57dI~
	        {                                                      //~v57dI~
				UCBITON(plh->ULHflag,ULHFLCMDERR);                 //~v57dI~
				return dlcerrrecord(*Pdata);                       //~v57dI~
    	    }                                                      //~v57dI~
      	if (!UCBITCHK(pfc->UFCflag,UFCFDEDIT))   //dir list by edit cmd//~v41cR~
			if (UCBITCHK(plc->UDLCtype,UDLCTERRBRW))	//err when brose mode//~v41cR~
            {                                                      //~v41cI~
				UCBITON(plh->ULHflag,ULHFLCMDERR);                 //~v41cI~
  				return errbrowsemode();                            //~v41cI~
            }                                                      //~v41cI~
			if (UCBITCHK(plc->UDLCtype2,UDLCT2DELZCMD))	//del cmd widthout undoability//~v645I~
            {                                                      //~v645I~
		        if (UCBITCHK(Gopt5,GOPT5DLCZOFF))                  //~v645I~
		        {                                                  //~v645I~
//  				dlcresultset(4,plc,0);//plc is static area,dont change DLCflag//~v66cR~
        			uerrmsg("to use line cmd \"z\" or \"0\",set-up is required using \"OPT DELZ\" cmd.",//~v645I~
            				"行コマンド \"z\",\"0\"を使用可\x94\\にするには\"OPT DELZ\" コマンドで設定が必要です");//~v645R~
					return 4;                                      //~v645I~
        		}                                                  //~v645I~
            }                                                      //~v645I~
      	if (UCBITCHK(UGETPDH(plh)->UDHupdatetype,UDHUTNOTEXIST))//~v05DI~
			if (plc->UDLCcmd!='U')	//undo for deleted          //~v05uR~
           	{                                                   //~v05DI~
            	*plh->ULHlinecmd=' ';	//clear input           //~v05DR~
  			   	uerrmsg("Deleted entry",                        //~v05DI~
            			"削除済行");                            //~v05DI~
  				return 4;                                       //~v05DI~
  			}                                                   //~v05DI~
    	if (UCBITCHK(plc->UDLCtype,UDLCTLINEINP1))	//attr      //~5716R~
        {                                                       //~5716I~
            if (!pdh->UDHlevel)                                    //~v09bI~
            	return dlcrooterr();                               //~v09bI~
//      	if (UCBITCHK(pdh->UDHflag,UDHFLCMDIN2))                //~v182R~
        		UCBITOFF(pdh->UDHflag,UDHFLCMDIN2|UDHFDDSETUP); //~v05rI~
        	UCBITON(pdh->UDHflag,UDHFLCMDIN1);                  //~5731R~
			dirsetflddata(Ppcw,plh,PANL310ATTR,"");             //~5807R~
            pandirprot(pfld,PANDPINP1);	//for csr move          //~5813I~
        }                                                       //~5716I~
        else                                                    //~5716I~
	    	if (UCBITCHK(plc->UDLCtype,UDLCTLINEINP2))	//rename//~5807R~
	        {                                                   //~5716I~
                if (!pdh->UDHlevel)                                //~v09bM~
    				if (plc->UDLCcmd=='R'	//rename               //~v09bI~
    				||  plc->UDLCcmd=='M')  //move                 //~v09bI~
                    	return dlcrooterr();                       //~v09bR~
//  			UCBITOFF(pdh->UDHflag,UDHFPRINTED); //drop printed //~v58hR~
    			UCBITOFF(pdh->UDHflag,(UDHFPRINTED|UDHFAPPCMDSTR)); //drop printed//~v58hR~
//          	if (UCBITCHK(pdh->UDHflag,UDHFLCMDIN1))            //~v182R~
		        	UCBITOFF(pdh->UDHflag,UDHFLCMDIN1|UDHFDDSETUP);//~v05rI~
	        	UCBITON(pdh->UDHflag,UDHFLCMDIN2);              //~5731R~
		    	if (UCBITCHK(plc->UDLCtype,UDLCTMASK))	//file mask//~5807I~
                {                                               //~5813I~
                                                                   //~v182I~
    			 if (plc->UDLCcmd=='O')    //open cmd              //~v54bR~
    		        pandirprot(pfld,PANDPINP2);	//input available also on timestamp fld//~v54bI~
                 else                                              //~v54uI~
    			 if (plc->UDLCcmd=='%')    //open cmd              //~v54uI~
                 {                                                 //~vamJI~
    		        pandirprot(pfld,PANDPINP2);	//input available also on timestamp fld//~v54uI~
					UCBITON(pdh->UDHflag4,UDHF4APPCMD);//rename field is %/$ cmd;for cut after executed//~vamJI~
                 }                                                 //~vamJI~
                 else                                              //~v54bI~
    			 if (plc->UDLCcmd==UDLCCMD_APPASYNC)               //~vamyI~
                 {                                                 //~vamJI~
    		        pandirprot(pfld,PANDPINP2);	//input available also on timestamp fld//~vamyI~
					UCBITON(pdh->UDHflag4,UDHF4APPCMDASYNC);//rename field is %/$ cmd;for cut after executed//~vamJI~
                 }                                                 //~vamJI~
                 else                                              //~vamyI~
    			 if (plc->UDLCcmd=='#'                             //~v75NI~
				 ||  plc->UDLCcmd==UDLCCMD_GREPUPPER               //~v75NI~
				 ||  plc->UDLCcmd==UDLCCMD_COMPARE                 //~v75NI~
                 )                                                 //~v75NI~
    		        pandirprot(pfld,PANDPINP2);	//input available also on timestamp fld//~v75NI~
                 else                                              //~v75NI~
                 {                                                 //~v54bI~
#ifdef UNX                                                         //~v182I~
    			  if (plc->UDLCcmd!='R')                           //~v182I~
#else  //!UNX                                                      //~v182M~
#ifdef OS2                                                         //~v0f3I~
				  pfh=UGETPFH(plh);                                //~v0f3I~
    			  if (plc->UDLCcmd!='R'                            //~v0f3R~
				  || !UCBITCHK(pfh->UFHflag4,UFHF4LFN))//not hpfs rename//~v0f3I~
#else                                                              //~v0f3I~
    			  if (plc->UDLCcmd!='R'                            //~v0f9R~
				  || !UCBITCHK(Gopt4,GOPT4W95VFAT))//vfat support  //~v0f9R~
#endif                                                             //~v0f3I~
#endif //!UNX                                                      //~v182I~
		        	UCBITON(pdh->UDHflag,UDHFMASK);             //~5807I~
//    		        pandirprot(pfld,PANDPINP3);	//for csr move  //~5813I~//~vawqR~
    		        pandirprot(pfld,PANDPINP2);	//for csr move     //~vawqI~
                 }//not Open cmd                                   //~v54bI~
				}                                               //~5813I~
                else                                            //~5813I~
    		        pandirprot(pfld,PANDPINP2);	//for csr move  //~5813I~
				if (UCBITCHK(pdh->UDHupdatetype,UDHUTCOPYO))//rename/undel pend//~v07eM~
			    {                                                  //~v07eM~
				    dirsavename(plh,"");    //free copy target     //~v07eM~
					UCBITOFF(pdh->UDHupdatetype,UDHUTCOPYO);//clear also saved name//~v07eM~
		        	UCBITOFF(pdh->UDHflag,UDHFDDSETUP);            //~v07eM~
			    }                                                  //~v07eM~
				dirsetflddata(Ppcw,plh,PANL310RENAME,"");       //~5807R~
			    UCBITOFF(pdh->UDHflag2,UDHF2RENAMEOVF);    //draw timestamp//~vax2I~
       		}                                                   //~5716I~
	        else                                                //~5716I~
		    {                                                   //~5813I~
			    if (UCBITCHK(pdh->UDHflag,UDHFLCMDIN1|UDHFLCMDIN2))	//for scroll//~v05rR~
				    UCBITOFF(pdh->UDHflag,UDHFLCMDIN1|UDHFLCMDIN2|UDHFDDSETUP);	//for scroll//~v05rI~
    		    pandirprot(pfld,PANDPPROT);	//for csr move      //~5813I~
			}                                                   //~5813R~
	}                                                           //~5813I~
	else			//fld clear                                 //~5716I~
    {                                                           //~5813I~
//  	if (UCBITCHK(pdh->UDHupdatetype,UDHUTCOPYO))//rename/undel pend//~v07eI~//~va0JR~
    	if (UCBITCHK(pdh->UDHupdatetype,UDHUTCOPYO) //rename/undel pend//~va0JI~
    	||  UCBITCHK(pdh->UDHflag,UDHFAPPCMDSTR)                   //~va0JI~
        )                                                          //~va0JI~
		{                                                          //~v07eI~
			dirsavename(plh,"");    //free copy target             //~v07eI~
			UCBITOFF(pdh->UDHupdatetype,UDHUTCOPYO);//clear also saved name//~v07eI~
//  	   	UCBITOFF(pdh->UDHflag,UDHFDDSETUP);                    //~v07gR~
			dirsetflddata(Ppcw,plh,PANL310RENAME,"");              //~v07eI~
		}                                                          //~v07eI~
//      UCBITOFF(pdh->UDHflag,UDHFLCMDIN1|UDHFLCMDIN2|UDHFDDSETUP|UDHFPRINTED);//~v58hR~
        UCBITOFF(pdh->UDHflag,UDHFLCMDIN1|UDHFLCMDIN2|UDHFDDSETUP|UDHFPRINTED|UDHFAPPCMDSTR);//~v58hR~
    	pandirprot(pfld,PANDPPROT);	//for csr move              //~5813I~
	}                                                           //~5813I~
    return 0;					//ignore,next tab               //~5716I~
}//dlcmdfe                                                      //~5716R~
//**********************************************************************//~5813I~
//* dlcmdupctr                                                  //~5813I~
//* parm 1:plh                                                  //~5813I~
//* ret   :rc 1:new ctr, 0:same level as prev                   //~5813I~
//**********************************************************************//~5813I~
int dlcmdupctr(PULINEH Pplh)                                    //~5813I~
{                                                               //~5813I~
	PUFILEH pfh;                                                //~5813I~
	PUDIRLH pdh;                                                   //~v690I~
    int rc;                                                     //~5813I~
//*******************                                           //~5813I~
	pfh=UGETPFH(Pplh);                                          //~5813I~
    pdh=UGETPDH(Pplh);                                             //~v690I~
	if (UCBITCHK(pfh->UFHflag,UFHFUPCTRREQ))//new level         //~5813I~
	{                                                           //~5813M~
    	rc=1;                                                   //~5813I~
		UCBITOFF(pfh->UFHflag,UFHFUPCTRREQ);	//upctr updated //~5813I~
		pfh->UFHupctr++;					//upctr up          //~5813M~
    }                                                           //~5813M~
    else                                                        //~5813I~
    	rc=0;		//same level as prev                        //~5813I~
    Pplh->ULHupctr=pfh->UFHupctr;		//latest update line.   //~5813I~
    UCBITON(pdh->UDHflag2,UDHF2REFRESH);    //description refresh required//~v690I~
	return rc;                                                  //~5813I~
}//dlcmdupctr                                                   //~5813I~
                                                                   //~v07gI~
//**************************************************************** //~v07gI~
// dlcprinted                                                      //~v07gI~
//*prepare for printed msg                                         //~v07gI~
//*parm1  :pcw                                                     //~v07gR~
//*parm2  :plc                                                     //~v07gI~
//*rc   :                                                          //~v07gI~
//**************************************************************** //~v07gI~
void dlcprinted(PUCLIENTWE Ppcw,UDLCMD *Pplc)                      //~v07gR~
{                                                                  //~v07gI~
	PUDIRLH pdh;                                                   //~v07gI~
	PULINEH plh;                                                   //~v07gI~
//*********************	                                           //~v07gI~
	plh=Pplc->UDLCplh;                                             //~v07gR~
    pdh=UGETPDH(plh);                                              //~v07gR~
	if (UCBITCHK(pdh->UDHupdatetype,UDHUTCOPYO))//rename/undel pend//~v07gI~
	{                                                              //~v07gI~
		dirsavename(plh,"");    //free copy target                 //~v07gI~
		UCBITOFF(pdh->UDHupdatetype,UDHUTCOPYO);//clear also saved name//~v07gI~
		dirsetflddata(Ppcw,plh,PANL310RENAME,"");//clear long name over time stamp//~v07gI~
	}                                                              //~v07gI~
	UCBITOFF(pdh->UDHflag,UDHFDDSETUP); //draw rename,time stamp   //~v07gI~
	UCBITON(pdh->UDHflag,UDHFPRINTED); //draw peinted              //~v07gI~
	return;                                                        //~v07gI~
}//dlcprinted                                                      //~v07gI~
#ifdef FTPSUPP                                                     //~v609I~
//**************************************************************** //~v609R~
// create ftp delete file name entry                               //~v609R~
// called by lineno sequence                                       //~v62iI~
//*rc    :1:added,0:not target(dir entry)                          //~v609R~
//**************************************************************** //~v609R~
int dlcftpaddentry(PUCLIENTWE Ppcw,PUFTPHOST Ppuftph,UDLCMD *Pplc) //~v609I~
{                                                                  //~v609R~
    PUDIRLH pdh;                                                   //~v609R~
    PFTPDELQE pfdqe;                                               //~v609I~
    char fpath[_MAX_PATH];                                         //~v609I~
    int len;                                                       //~v62hR~
//*********************                                            //~v609R~
	pdh=UGETPDH(Pplc->UDLCplh);                                    //~v609R~
	if (pdh->UDHtype==UDHTFILE)	//not dir                          //~v609R~
    {                                                              //~v609I~
//  	hostnmlen=Ppuftph->UFTPHhostnmlen;                         //~v62hR~
        dlcgetfullname(pdh,fpath);                                 //~v609I~
//      len=strlen(fpath)-hostnmlen-1;                             //~v62hR~
//      len=strlen(fpath);                                         //~v62hI~//~vb30R~
        len=(int)strlen(fpath);                                    //~vb30I~
    	pfdqe=(PFTPDELQE)UALLOCC(1,FTPDELQESZ);                    //~v609R~
        UALLOCCHK(pfdqe,UALLOC_FAILED);                            //~v609I~
        pfdqe->FDQEflag=0;                                         //~v62iR~
        pfdqe->FDQEplc=Pplc;                                       //~v609I~
        pfdqe->FDQEpuftph=Ppuftph;                                 //~v62hI~
        pfdqe->FDQElen=len;                                        //~v609I~
        pfdqe->FDQEpfpath=umalloc((UINT)(len+1));                  //~v609R~
        UALLOCCHK(pfdqe->FDQEpfpath,UALLOC_FAILED);                //~v609R~
//      strcpy(pfdqe->FDQEpfpath,fpath+hostnmlen+1);               //~v62hR~
        strcpy(pfdqe->FDQEpfpath,fpath);                           //~v62hI~
		UENQ(UQUE_END,&Sftpdelqh,pfdqe);                           //~v609M~
        UCBITON(Pplc->UDLCflag,UDLCFFTPDEL);                       //~v609R~
    }                                                              //~v609I~
    else	//dir entry                                            //~v62iI~
    {                                                              //~v62iI~
	    pfdqe=UGETQEND(&Sftpdelqh);                                //~v62iI~
        if (pfdqe)                                                 //~v62iI~
        	pfdqe->FDQEflag|=FDQEFDIRCONF;	//partial execution list end//~v62iR~
    }                                                              //~v62iI~
    return 0;                                                      //~v609I~
}//dlcftpdelentry                                                  //~v609R~
//**************************************************************** //~v609I~
// create ftp delete file name entry                               //~v609I~
// called by reverse sequence of dir list                          //~v62iI~
//*rc    :1:added,0:not target(dir entry)                          //~v609I~
//**************************************************************** //~v609I~
//int dlcftpmultidel(PUCLIENTWE Ppcw,PUFTPHOST Ppuftph)            //~v62iR~
int dlcftpmultidel(PUCLIENTWE Ppcw,PFTPDELQE Ppfdqe)               //~v62iR~
{                                                                  //~v609I~
    PUDIRLH pdh;                                                   //~v609I~
    PUFTPHOST puftph=NULL;                                              //~v62iI~//~vaf9R~
    PUFTPMULTIDEL pfmd,pfmd0;                                      //~v62iR~
    PUFTPMULTIRENAME pfmr,pfmr0;                                   //~v62iR~
    PFTPDELQE pfdqe;                                               //~v609I~
	UDLCMD *plc;                                                   //~v609I~
    int rc=0,delctr,ii;                                            //~v62iR~
    int renamectr=0,len;                                           //~v62hR~
    ULONG attr;                                                    //~v609I~
    char undoname[_MAX_PATH],*pundoname;                           //~v62hI~
//*********************                                            //~v609I~
//  delctr=UGETQCTR(&Sftpdelqh);                                   //~v609I~//~vb31R~
    delctr=(int)UGETQCTR(&Sftpdelqh);                              //~vb31I~
    if (!delctr)                                                   //~v609I~
    	return 0;                                                  //~v609I~
//  pfmd=pfmd0=umalloc((UINT)(delctr*UFTPMULTIDELSZ));             //~v62iR~//~vb30R~
    pfmd=pfmd0=umalloc((size_t)delctr*UFTPMULTIDELSZ);             //~vb30I~
    UALLOCCHK(pfmd,UALLOC_FAILED);                                 //~v609I~
    delctr=0;                                                      //~v62hI~
//  for (pfdqe=(PFTPDELQE)UGETQTOP(&Sftpdelqh);pfdqe;pfdqe=UGETQNEXT(pfdqe))//~v62iR~
    for (pfdqe=Ppfdqe;pfdqe;pfdqe=UGETQPREV(pfdqe))                //~v62iR~
    {                                                              //~v609I~
        if (pfdqe!=Ppfdqe && pfdqe->FDQEflag & FDQEFDIRCONF)//intercepted by dir del confirmation//~v62iR~
            break;                                                 //~v62iM~
        puftph=pfdqe->FDQEpuftph;                                  //~v62iI~
    	plc=pfdqe->FDQEplc;                                        //~v609I~
		pdh=UGETPDH(plc->UDLCplh);                                 //~v609R~
#ifdef W32UNICODE                                                  //~vawvI~
		{                                                          //~vawvI~
			char *pc;                                              //~vawvI~
            int udlen;                                             //~vawvI~
			pc=pfdqe->FDQEpfpath;                                  //~vawvR~
            udlen=strlen(pc);                                      //~vawvI~
			if (IS_MEM_UDSTR(pc,udlen))                            //~vawvI~
	    	{                                                      //~vawvI~
				STRIP_UDSTR(pc,udlen,pc/*out*/,NULL/*outlen*/);    //~vawvI~
        		UTRACED("strip name",pc,strlen(pc));               //~vawvI~
    		}                                                      //~vawvI~
        }                                                          //~vawvI~
#endif                                                             //~vawvI~
        if (plc->UDLCcmd=='D'                                      //~v62hI~
        ||  plc->UDLCcmd=='/')  //undoable                         //~v62hI~
        {                                                          //~v62hI~
            if (!(rc=dlcmdftpundelprechk(pfmd->UFMDpfpath=pfdqe->FDQEpfpath,undoname)))//undoable//~v62hR~
            {                                                      //~v62hI~
//  	    	len=strlen(undoname);                              //~v62hI~//~vb30R~
    	    	len=(int)strlen(undoname);                         //~vb30I~
		        pundoname=umalloc((UINT)len+1);                    //~v62hR~
        		UALLOCCHK(pundoname,UALLOC_FAILED);                //~v62hI~
                strcpy(pundoname,undoname);                        //~v62hI~
		        pfdqe->FDQEpundoname=pundoname;                    //~v62hI~
                renamectr++;                                       //~v62hI~
        		pfdqe->FDQEflag |= FDQEFCALLED;  //del requested   //~v62iI~
                continue;                                          //~v62hI~
            }                                                      //~v62hI~
            else                                                   //~v62hI~
            {                                                      //~v62hI~
            	if (rc>1)                                          //~v62hI~
                	return rc;                                     //~v62hI~
                pfdqe->FDQEflag|=FDQEFUNDELSAVEENTRY;   //saved entry for undel,DEQ required not to del at term//~vb7fI~
            }                                                      //~v62hI~
        }                                                          //~v62hI~
        attr=pdh->UDHattr;                                         //~v609I~
        pfdqe->FDQEpfmd=pfmd; 	//chain                            //~v609I~
//  	pfmd->UFMDpfpath=pfdqe->FDQEpfpath;                        //~v62hR~
    	pfmd->UFMDpfpath=pfdqe->FDQEpfpath+puftph->UFTPHhostnmlen+1;//~v62iR~
    	pfmd->UFMDattr=attr;                                       //~v609I~
    	pfmd->UFMDparm=pfdqe;	//back chain                       //~v609I~
        pfmd->UFMDrc=0;                                            //~vb7fI~
        pfmd++;                                                    //~v609I~
        delctr++;                                                  //~v62hI~
        pfdqe->FDQEflag |= FDQEFCALLED;  //del requested           //~v62iI~
    }                                                              //~v609I~
//  csrsetwait(1);      //set wait mode csr if now not wait        //~v62iR~
    rc=0;                                                          //~v62hI~
  if (delctr)                                                      //~v62hI~
  {                                                                //~v62iI~
    rc=uftpmultidel(0,puftph,pfmd0,delctr,0);                      //~v62iR~
    for (ii=0,pfmd=pfmd0;ii<delctr;ii++,pfmd++)                    //~v62iI~
    {                                                              //~v62iI~
    	pfdqe=pfmd->UFMDparm;	//back chain                       //~v62iI~
        pfdqe->FDQErc=pfmd->UFMDrc;                                //~v62iI~
        if (!pfdqe->FDQErc)                                        //~vb7fR~
        	if (pfdqe->FDQEflag & FDQEFUNDELSAVEENTRY)   //saved entry for undel,DEQ required not to del at term//~vb7fI~
            	dlcmdftpclearundelsaveDeleted(pfdqe->FDQEpfpath);  //~vb7fR~
    }                                                              //~v62iI~
  }                                                                //~v62iI~
    ufree(pfmd0);                                                  //~v62iM~
//rename for undelete                                              //~v62hI~
    if (renamectr)                                                 //~v62hR~
    {                                                              //~v62hI~
//      pfmr=pfmr0=umalloc((UINT)(renamectr*UFTPMULTIRENAMESZ));   //~v62iR~//~vb30R~
        pfmr=pfmr0=umalloc((size_t)renamectr*UFTPMULTIRENAMESZ);   //~vb30I~
    	UALLOCCHK(pfmr,UALLOC_FAILED);                             //~v62hI~
        for (pfdqe=Ppfdqe;pfdqe;pfdqe=UGETQPREV(pfdqe))            //~v62iR~
        {                                                          //~v62hI~
    	    if (pfdqe!=Ppfdqe && pfdqe->FDQEflag & FDQEFDIRCONF)//intercepted by dir del confirmation//~v62iR~
	            break;                                             //~v62iI~
        	puftph=pfdqe->FDQEpuftph;                              //~v62iI~
            pundoname=pfdqe->FDQEpundoname;                        //~v62hI~
            if (!pundoname)                                        //~v62hI~
            	continue;                                          //~v62hI~
            plc=pfdqe->FDQEplc;                                    //~v62hI~
            pdh=UGETPDH(plc->UDLCplh);                             //~v62hI~
            attr=pdh->UDHattr;                                     //~v62hI~
            pfdqe->FDQEpfmd=pfmr;   //chain                        //~v62hI~
            pfmr->UFMRpfpath=pfdqe->FDQEpfpath+puftph->UFTPHhostnmlen+1;//~v62iR~
            pfmr->UFMRpnewname=pfdqe->FDQEpundoname;               //~v62hI~
            pfmr->UFMRattr=attr;                                   //~v62hI~
            pfmr->UFMRparm=pfdqe;   //back chain                   //~v62hI~
	        pfmd->UFMDrc=0;                                        //~vb7fI~
            pfmr++;                                                //~v62hI~
        }                                                          //~v62hI~
    	rc+=uftpmultirename(0,puftph,pfmr0,renamectr,0);           //~v62iR~
        for (ii=0,pfmr=pfmr0;ii<renamectr;ii++,pfmr++)             //~v62iI~
        {                                                          //~v62iI~
            pfdqe=pfmr->UFMRparm;   //back chain                   //~v62iI~
            pfdqe->FDQErc=pfmr->UFMRrc;                            //~v62iI~
        }                                                          //~v62iI~
	    ufree(pfmr0);                                              //~v62iI~
    }                                                              //~v62hI~
    return rc;                                                     //~v609I~
}//dlcftpmultidel                                                  //~v609R~
//**************************************************************** //~v609I~
// search result and return rc                                     //~v609R~
//*rc                                                              //~v609R~
//**************************************************************** //~v609I~
int dlcftpmultdelgetrc(PUCLIENTWE Ppcw,UDLCMD *Pplc)               //~v609R~
{                                                                  //~v609I~
	PULINEH plh;                                                   //~v62iI~
    PFTPDELQE pfdqe;                                               //~v609I~
    PUDIRLH pdh;                                                   //~v62hI~
    int rc;                                                        //~v609I~
    char *newname;                                                 //~v62hI~
//*********************                                            //~v609I~
	for (pfdqe=(PFTPDELQE)UGETQTOP(&Sftpdelqh);pfdqe;pfdqe=UGETQNEXT(pfdqe))//~v609I~
    {                                                              //~v609I~
    	if (Pplc==pfdqe->FDQEplc)                                  //~v609I~
        	break;                                                 //~v609R~
    }                                                              //~v609I~
    if (!pfdqe)                                                    //~v609I~
    	return 128;                                                //~v609I~
    plh=Pplc->UDLCplh;                                             //~v62iI~
	if (!(pfdqe->FDQEflag & FDQEFCALLED))	//not del requested    //~v62iI~
    	if ((rc=dlcftpmultidel(Ppcw,pfdqe))==UALLOC_FAILED)        //~v62iR~
        	return rc;                                             //~v62iI~
    newname=pfdqe->FDQEpundoname;                                  //~v62hI~
  	if (newname)                                                   //~v62hI~
    {                                                              //~v62hI~
        pdh=UGETPDH(plh);                                          //~v62iR~
//      pfmr=pfdqe->FDQEpfmd;                                      //~v62iR~
//      if (pfmr)                                                  //~v62iR~
//      {                                                          //~v62iR~
//          rc=pfmr->UFMRrc;                                       //~v62iR~
            rc=pfdqe->FDQErc;                                      //~v62iI~
            if (!rc)                                               //~v62hR~
                rc+=dlcmdftpundelprep(Ppcw,pdh,pfdqe->FDQEpfpath,newname);//~v62hR~
//      }                                                          //~v62iR~
//      else                                                       //~v62iR~
//          rc=16;                                                 //~v62iR~
    }                                                              //~v62hI~
    else                                                           //~v62hI~
    {                                                              //~v62hI~
//  pfmd=pfdqe->FDQEpfmd;                                          //~v62iR~
//  if (pfmd)                                                      //~v62iR~
//  rc=pfmd->UFMDrc;                                               //~v62iR~
//  else                                                           //~v62iR~
//  rc=16;                                                         //~v62iR~
        rc=pfdqe->FDQErc;                                          //~v62iI~
    }                                                              //~v62hI~
    return rc;                                                     //~v609R~
}//dlcftpmultidelgetrc                                             //~v62iR~
//**************************************************************** //~v609I~
// create ftp delete file name entry                               //~v609I~
//*rc    :1:added,0:not target(dir entry)                          //~v609I~
//**************************************************************** //~v609I~
int dlcftpfree(PUCLIENTWE Ppcw)                                    //~v609I~
{                                                                  //~v609I~
    PFTPDELQE pfdqe;                                               //~v609I~
//****************************                                     //~v609I~
	while(pfdqe=(PFTPDELQE)udeq(UQUE_TOP,&Sftpdelqh,0),pfdqe)	//entry exist//~v609I~
    {                                                              //~v609I~
    	if (pfdqe->FDQEpfpath)                                     //~v609R~
        	ufree(pfdqe->FDQEpfpath);                              //~v609R~
    	if (pfdqe->FDQEpundoname)                                  //~v62hI~
        	ufree(pfdqe->FDQEpundoname);                           //~v62hI~
		ufree(pfdqe);                                              //~v609I~
    }                                                              //~v609I~
//    if (Spftpmultidel)                                           //~v62iR~
//    {                                                            //~v62iR~
//        ufree(Spftpmultidel);                                    //~v62iR~
//        Spftpmultidel=0;                                         //~v62iR~
//    }                                                            //~v62iR~
//    if (Spftpmultirename)                                        //~v62iR~
//    {                                                            //~v62iR~
//        ufree(Spftpmultirename);                                 //~v62iR~
//        Spftpmultirename=0;                                      //~v62iR~
//    }                                                            //~v62iR~
    return 0;                                                      //~v609I~
}//dlcftpfree                                                      //~v609I~
#endif                                                             //~v609I~
//**************************************************************** //~v09bI~
// dlcrooterr                                                      //~v09bI~
//*err msg for not vail for root                                   //~v09bI~
//*parm  :none                                                     //~v09bI~
//*rc    :4                                                        //~v09bI~
//**************************************************************** //~v09bI~
int dlcrooterr(void)                                               //~v09bI~
{                                                                  //~v09bI~
//*********************                                            //~v09bI~
   	uerrmsg("Not vail for root dir",                               //~v09bI~
			"ルートディレクトリーには不可");                       //~v09bI~
	return 4;                                                      //~v09bI~
}//dlcrooterr                                                      //~v09bI~
//**************************************************************** //~v10pI~
// dlcverberr                                                      //~v10pI~
//*err msg for verb err                                            //~v10pI~
//*parm  :none                                                     //~v10pI~
//*rc    :4                                                        //~v10pI~
//**************************************************************** //~v10pI~
int dlcverberr(void)                                               //~v10pI~
{                                                                  //~v10pI~
//*********************                                            //~v10pI~
//#ifdef W32                                                       //~v64vR~
#if defined(W32) || defined(LNX)                                   //~v64vI~
  #ifdef UTF8SUPPH                                                 //~v92hI~//~va00I~
//  uerrmsg("Invalid,Use one of \"%s%c%c%s\"",                     //~v92hI~//~va00I~//~vb12R~
    uerrmsg("Invalid,Use one of \"%s%c%c%c%s\"",                   //~vb12I~
//			"無効コマンド(\"%s%c%c%s\")",                          //~v92hR~//~va00I~//~vamyR~
			"無効コマンド(\"%s%c%c%c%s\")",                        //~vamyI~
    			"abcdefghHiIjJkKlLmnNoOprstuvwxyz01238>+-/=^:.!%#&",//~v92hR~//~va00I~
    			UDLCCMD_APPASYNC,                                  //~vamyI~
    			UDLCCMD_CPLC,UDLCCMD_CPU8,                         //~v92hI~//~va00I~
                " F6 F10 F11");                                    //~v92hI~//~va00I~
  #else                                                            //~v92hI~//~va00I~
	uerrmsg("Invalid,Use one of \"%s\"",                           //~v55vI~
			"無効コマンド(\"%s\")",                                //~v55vI~
//  			"abcdefhHiIjJkKlLmnNoOprstuvwxyz012>+-/:.!%(F6F10F11)");//~v59eR~
//  			"abcdefhHiIjJkKlLmnNoOprstuvwxyz012>+-/:.!%#(F6F10F11)");//~v75GR~
//  			"abcdefhHiIjJkKlLmnNoOprstuvwxyz0123>+-/:.!%# F6 F10 F11");//~v75HR~
//  			"abcdefhHiIjJkKlLmnNoOprstuvwxyz01238>+-/:.!%# F6 F10 F11");//~v75JR~
//  			"abcdefghHiIjJkKlLmnNoOprstuvwxyz01238>+-/:.!%# F6 F10 F11");//~v75MR~
//  			"abcdefghHiIjJkKlLmnNoOprstuvwxyz01238>+-/=:.!%# F6 F10 F11");//~v76gR~
//  			"abcdefghHiIjJkKlLmnNoOprstuvwxyz01238>+-/=^:.!%# F6 F10 F11");//~v78KR~
    			"abcdefghHiIjJkKlLmnNoOprstuvwxyz01238>+-/=^:.!%#& F6 F10 F11");//~v78KI~
  #endif                                                           //~v92hI~//~va00I~
#else                                                              //~v55vI~
	uerrmsg("Invalid,Use one of \"%s\"",                           //~v10vR~
			"無効コマンド(\"%s\")",                                //~v10vR~
//  			"abcdefhHiIjJkKlLmnNoOprstuvwxyz012>+-/:.(F6F10F11)");//~v51WR~
//  			"abcdefhHiIjJkKlLmnNoOprstuvwxyz012>+-/:.%(F6F10F11)");//~v59eR~
//  			"abcdefhHiIjJkKlLmnNoOprstuvwxyz012>+-/:.%#(F6F10F11)");//~v75GR~
//  			"abcdefhHiIjJkKlLmnNoOprstuvwxyz0123>+-/:.%# F6 F10 F11");//~v75HR~
//  			"abcdefhHiIjJkKlLmnNoOprstuvwxyz01238>+-/:.%# F6 F10 F11");//~v75JR~
//  			"abcdefghHiIjJkKlLmnNoOprstuvwxyz01238>+-/:.%# F6 F10 F11");//~v75MR~
//  			"abcdefghHiIjJkKlLmnNoOprstuvwxyz01238>+-/=:.%# F6 F10 F11");//~v76gR~
  #ifndef DOS                                                      //~v78KI~
    			"abcdefghHiIjJkKlLmnNoOprstuvwxyz01238>+-/=^:.%# F6 F10 F11");//~v76gI~
  #else                                                            //~v78KI~
    			"abcdefghHiIjJkKlLmnNoOprstuvwxyz01238>+-/=^:.%#& F6 F10 F11");//~v78KI~
  #endif                                                           //~v78KI~
#endif                                                             //~v55vI~
	return 4;                                                      //~v10pI~
}//dlcrooterr                                                      //~v10pI~
//**************************************************************** //~v57dI~
// dlcerrrecord                                                    //~v57dI~
//*cmd err for path record                                         //~v57dI~
//*parm  :cmd                                                      //~v57dI~
//*rc    :4                                                        //~v57dI~
//**************************************************************** //~v57dI~
int dlcerrrecord(char Pcmd)                                        //~v57dI~
{                                                                  //~v57dI~
//*********************                                            //~v57dI~
	uerrmsg("%c is invalid for path line.",                        //~v57dI~
			"%c は経路行には無効です。",                           //~v57dI~
            Pcmd);                                                 //~v57dI~
	return 4;                                                      //~v57dI~
}//dlcerrrecord                                                    //~v57dI~
//**************************************************************** //~v75JI~
// dlcerrmixed                                                     //~v75JI~
//*parm  :cmd                                                      //~v75JI~
//*rc    :4                                                        //~v75JI~
//**************************************************************** //~v75JI~
int dlcerrmixed(char Pcmd)                                         //~v75JI~
{                                                                  //~v75JI~
//*********************                                            //~v75JI~
	uerrmsg("'%c' is mixed with other cmd.",                       //~v75MR~
			"'%c' は他のコマンドと混在できません。",               //~v75MR~
            Pcmd);                                                 //~v75JI~
	return 4;                                                      //~v75JI~
}//dlcerrmixed                                                     //~v75JI~
//**************************************************************** //~vamzI~
void dlcfuncdescription(int Pcmd)                                  //~vamzI~
{                                                                  //~vamzI~
	char *pdesce="",*pdescj="";                                    //~vamzR~
//*********************                                            //~vamzI~
	switch(Pcmd)                                                   //~vamzI~
    {                                                              //~vamzI~
	case 'A':                                                      //~vamzI~
        pdesce="a : Attribute";                                    //~vamzI~
        pdescj="a : 属性設定(Attribut)";                           //~vamzI~
		break;                                                     //~vamzI~
	case 'B':                                                      //~vamzI~
        pdesce="b : Browse";                                       //~vamzI~
        pdescj="b : \x95\\示(Browse)";                             //~vamzI~
		break;                                                     //~vamzI~
    case 'C':                                                      //~vamzI~
        pdesce="c : Copy";                                         //~vamzI~
        pdescj="c : 複写(Copy)";                                   //~vamzI~
		break;                                                     //~vamzI~
    case 'D':                                                      //~vamzI~
        pdesce="d : Delete";                                       //~vamzI~
        pdescj="d : 削除(Delete)";                                 //~vamzI~
		break;                                                     //~vamzI~
	case 'E':                                                      //~vamzI~
        pdesce="e : Edit";                                         //~vamzI~
        pdescj="e : 編集(Edit)";                                   //~vamzI~
		break;                                                     //~vamzI~
	case 'F':                                                      //~vamzI~
        pdesce="f : Free(End) viewed screen,update is saved.";     //~vamzI~
        pdescj="f : View画面の終了、編集画面の変更は保存される(Free)";//~vamzI~
		break;                                                     //~vamzI~
    case UDLCCMD_GREPUPPER:                                        //~vamzI~
        pdesce="g : Grep search in the file or directory.";        //~vamzI~
        pdescj="g : ファイル、ディレクトリー内のGrepサーチ";       //~vamzI~
		break;                                                     //~vamzI~
	case 'H':                                                      //~vamzI~
        pdesce="h : Open file by Hex mode.";                       //~vamzI~
        pdescj="h : Hexモードで開く";                              //~vamzI~
		break;                                                     //~vamzI~
	case 'I':                                                      //~vamzI~
        pdesce="i : Open SPF COBOL file as COL.1-6 is lineno.";    //~vamzI~
        pdescj="i : Col.1-6行番号、SPF-COBOLファイルとして開く";   //~vamzI~
		break;                                                     //~vamzI~
	case 'J':                                                      //~vamzI~
        pdesce="j : Open SPF COBOL file as COL.1-6 is space.";     //~vamzI~
        pdescj="j : Col.1-6スペース、SPF-COBOLファイルとして開く"; //~vamzI~
		break;                                                     //~vamzI~
	case 'K':                                                      //~vamzI~
        pdesce="k : Open COBOL file as COL.1-6 is space.";         //~vamzI~
        pdescj="k : Col.1-6スペースのCOBOLファイルとして開く";     //~vamzI~
		break;                                                     //~vamzI~
	case 'L':                                                      //~vamzI~
        pdesce="L : Open COBOL file as COL.1-6 is lineno.";        //~vamzI~
        pdescj="L : Col.1-6行番号のCOBOLファイルとして開く";       //~vamzI~
		break;                                                     //~vamzI~
    case 'M':                                                      //~vamzI~
        pdesce="m : Move";                                         //~vamzI~
        pdescj="m : 移動(Move)";                                   //~vamzI~
		break;                                                     //~vamzI~
	case 'N':                                                      //~vamzI~
        pdesce="n : Open SPF file(col.73-80 is lineno).";          //~vamzI~
        pdescj="n : COL73-80行番号の行番号付き(SPF)ファイルとして開く";//~vamzI~
		break;                                                     //~vamzI~
    case 'O':                                                      //~vamzI~
        pdesce="o : Open with Edit/Browse cmd parameter.";         //~vamzR~
        pdescj="o : パラメータ指定でファイルを開く(Open)";         //~vamzI~
		break;                                                     //~vamzI~
	case 'P':                                                      //~vamzI~
        pdesce="p : Print";                                        //~vamzI~
        pdescj="p : 印刷(Print)";                                  //~vamzI~
		break;                                                     //~vamzI~
    case 'R':                                                      //~vamzI~
        pdesce="r : Rename";                                       //~vamzI~
        pdescj="r : 改名(Rename)";                                 //~vamzI~
		break;                                                     //~vamzI~
    case 'S':                                                      //~vamzI~
        pdesce="s : Select";                                       //~vamzI~
        pdescj="s : 選択(Select)";                                 //~vamzI~
		break;                                                     //~vamzI~
    case UDLCCMD_DNDSELECT:                                        //~vamzI~
        pdesce="_ : Select for Drag&Drop.";                        //~vamzI~
        pdescj="_ : ドラッグ&ドロップのための選択";                //~vamzI~
		break;                                                     //~vamzI~
    case 'T':                                                      //~vamzI~
        pdesce="t : Open width text forced.";                      //~vamzI~
        pdescj="t : テキストモードで開く";                         //~vamzI~
		break;                                                     //~vamzI~
	case 'U':                                                      //~vamzI~
        pdesce="u : Undo for Renamed/Deleted/Moved.";              //~vamzI~
        pdescj="u : Rename/Delete/Move を戻す(Undo)";              //~vamzI~
		break;                                                     //~vamzI~
	case 'V':                                                      //~vamzI~
        pdesce="v : Browse open on the split panel.";              //~vamzI~
        pdescj="v : 画面分割して \x95\\示(Browse)";                //~vamzR~
		break;                                                     //~vamzI~
	case 'W':                                                      //~vamzI~
        pdesce="w : Edit open on the split panel.";                //~vamzI~
        pdescj="w : 画面分割して \x95\\示(Edit)";                  //~vamzR~
		break;                                                     //~vamzI~
	case 'X':                                                      //~vamzI~
        pdesce="x : Hide member of the directory.";                //~vamzI~
        pdescj="x : メンバーを非\x95\\示(eXclude)";                //~vamzI~
		break;                                                     //~vamzI~
	case 'Y':                                                      //~vamzI~
        pdesce="y : display hidden member.";                       //~vamzI~
        pdescj="y : 非\x95\\示を再\x95\\示";                       //~vamzI~
		break;                                                     //~vamzI~
    case 'Z':                                                      //~vamzI~
        pdesce="z : Delete without undeletability.";               //~vamzI~
        pdescj="z : 削除戻しなしの削除 ";                          //~vamzI~
		break;                                                     //~vamzI~
    case '0':                                                      //~vamzI~
        pdesce="0 : Delete without undeletability(even for Read-only)";//~vamzI~
        pdescj="0 : 削除戻しなしの(読取専用でも)削除";             //~vamzR~
		break;                                                     //~vamzI~
	case '1':                                                      //~vamzI~
        pdesce="1 : Browse as binary file.";                       //~vamzI~
        pdescj="1 : バイナリーモード\x95\\示";                     //~vamzI~
		break;                                                     //~vamzR~
	case '2':                                                      //~vamzI~
        pdesce="2 : Edit as binary file.";                         //~vamzI~
        pdescj="2 : バイナリーモード編集";                         //~vamzI~
		break;                                                     //~vamzI~
	case '3':                                                      //~vamzI~
        pdesce="3 : Open as binary file(Edit or Browse).";         //~vamzI~
        pdescj="3 : バイナリーモードで開く";                       //~vamzI~
		break;                                                     //~vamzI~
	case UDLCCMD_EDITF80:                                          //~vamzI~
        pdesce="8 : Open with FixedLRECL=80.";                     //~vamzI~
        pdescj="8 : 固定長LRECL=80で開く";                         //~vamzI~
		break;                                                     //~vamzI~
	case UDLCCMD_CPLC:                                             //~vamzI~
        pdesce="[ : Open with CPLC.";                              //~vamzI~
        pdescj="[ : CPLC オプションで開く";                        //~vamzI~
		break;                                                     //~vamzI~
	case UDLCCMD_CPU8:                                             //~vamzI~
        pdesce="] : Open with CPU8.";                              //~vamzI~
        pdescj="] : CPU8 オプションで開く";                        //~vamzR~
		break;                                                     //~vamzI~
	case '-':                                                      //~vamzI~
        pdesce="- : Expand the directory.";                        //~vamzI~
        pdescj="- : メンバーの展開\x95\\示";                       //~vamzI~
		break;                                                     //~vamzI~
    case '>':                                                      //~vamzI~
        pdesce="> : Expand also all sub directory.";               //~vamzI~
        pdescj="> : サブディレクトリーも展開";                     //~vamzI~
		break;                                                     //~vamzI~
	case '+':                                                      //~vamzI~
        pdesce="+ : Hide members of the directory.";               //~vamzI~
        pdescj="+ : メンバー展開を戻す";                           //~vamzI~
		break;                                                     //~vamzI~
    case ':':                                                      //~vamzI~
        pdesce=": : Display path only.";                           //~vamzI~
        pdescj=": : 経路のみを\x95\\示";                           //~vamzI~
		break;                                                     //~vamzI~
	case '.':                                                      //~vamzI~
        pdesce=". : Set current directory.";                       //~vamzI~
        pdescj=". : この行から現行デレクトリーを設定";             //~vamzI~
		break;                                                     //~vamzI~
    case '/':                                                      //~vamzI~
//      pdesce="/ : Delete even for Read-only.";                   //~vb75R~
//      pdescj="/ : 読取専用でも削除";                             //~vb75R~
        pdesce="/ : Delete even for Read-only/Too-long-name.";     //~vb75I~
        pdescj="/ : 読取専用/長すぎるパス名でも削除";              //~vb75I~
		break;                                                     //~vamzI~
    case '%':                                                      //~vamzI~
        pdesce="% : Execute \"rename-field-cmd this-file sunchronously\".";//~vamzR~
        pdescj="% : \"コマンド(改名欄) ファイル(行)\"を同期実行";  //~vamzR~
		break;                                                     //~vamzI~
    case '#':                                                      //~vamzI~
        pdesce="# : Execute this file with parameter in the rename-field synchronously.";//~vamzR~
        pdescj="# : このファイルを改名欄のパラメータで同期実行";   //~vamzR~
		break;                                                     //~vamzI~
    case UDLCCMD_COMPARE:                                          //~vamzI~
        pdesce="= : Compare two files/directories using tool xfc,xdc.";//~vamzI~
        pdescj="= : xfc/xdcを使用したファイル/ディレクトリー照合"; //~vamzI~
		break;                                                     //~vamzI~
	case UDLCCMD_SEND:                                             //~vamzI~
        pdesce="^ : Send the filename.";                           //~vamzI~
        pdescj="^ : ファイル名転送";                               //~vamzR~
		break;                                                     //~vamzI~
    case '&':                                                      //~vamzI~
        pdesce="& : Execute this file asynchronously.";            //~vamzI~
        pdescj="& : このファイルを改名欄のパラメータで非同期実行"; //~vamzR~
		break;                                                     //~vamzI~
	case '!':                                                      //~vamzI~
        pdesce="! : Open by extension associated program.";        //~vamzI~
        pdescj="! : \"拡張子の関連付けに従ったアプリケーションで開く";//~vamzI~
		break;                                                     //~vamzI~
	case UDLCCMD_APPASYNC:                                         //~vamzI~
        pdesce="$ : Execute \"rename-field-cmd this-file\" asynchronously.";//~vamzI~
        pdescj="$ : \"コマンド(改名欄) ファイル(行)\"を非同期実行";//~vamzR~
		break;                                                     //~vamzI~
    }                                                              //~vamzI~
	uerrmsg(pdesce,pdescj);                                        //~vamzR~
}//dlcfuncdescription                                              //~vamzI~
