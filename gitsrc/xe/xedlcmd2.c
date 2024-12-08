//*CID://+vbBvR~:                             update#=  260;       //~vbBvR~
//*************************************************************
//*xedlcmd2.c
//* each dir line cmd process                                   //~5731R~
//* browse(b)/browse binary(2)/edit(e)/expand(-)/reduce(+)/exclude(x)/display(y)///~v10kR~
//* cur dir(.)/expandall(>)/free(f)/view(v)/view edit(w)        //~v04lR~
//* toggle size display byte count<-->line count                   //~v10rI~
//*************************************************************
//vbBv:241121 S+F1(Dir refresh) dose not clear when file mask specified and it has no members.//~vbBvI~
//vbq5:200516 (Bug)dir sort /ot is err                             //~vbq5I~
//vbq1:200418 "-" dlcmd sort option chk more(/ot[ is not err)      //~vbq1I~
//vb7a:170104 msg errtoolong for filename is errtoolongpath        //~vb7aI~
//vb2E:160229 LNX64 compiler warning                               //~vb2EI~
//vb2s:160206 (Win)target err msg if slinkerr                      //~vb2sI~
//vb2i:160129 (BUG)open dlcmd ignored parameter for dir entry      //~vb2iI~
//vb2g:160124 Select dcmd accept mount option if FN{U8|LC} was not specified//~vb2gI~
//vb16:151221 (Bug of vawp) dirlist expand("-",">") cmd fails if no filemask on rename fld//~vb16I~
//vawy:140612 (W32UNICODE:LNX)dlcmd "." complete msg was by dbcs   //~vawyI~
//vawp:140607 (BUG)ddfmt display err for expand1 wildcard          //~vawpI~
//vavJ:140403 (BUG)UDH alias was not set for path;dlcgetfullnamealias failed.//~vavJI~
//vavH:140403 (W32UNICODE)set UTF8 option of parm filename for xdc/xfc because cmd prompt translate to locale//~vavHI~
//vav7:140405 (BUG)use alias when not LFN for select on dirlist    //~vav7I~
//vauA:140315 (BUG)u8 membername on dir list by fnu8 option,but fhfilename is treated by lc by env:lc on windows//~vauAI~
//vand:131203 reduce udirlist size. name max is 256,slinkname max=_MAX_PATH=4096 on suse64. change to malloc slinkname.//~vandI~
//van3:131127 support select of invalid(wildcard) name entry on dir list//~van3I~
//vamA:131104 % parm of % dlcd; enclose filename if space embedding(when %\*.c etc enclose all)//~vamAI~
//vamx:131030 (BUG) err when filename contains "("/")"             //~vamxI~
//vaix:130623 no access to target for junction to file             //~vaixI~
//            (it is created by junction.exe, but usually junction is directory junction)//~vaixI~
//vait:130610 Junction/symlink support                             //~vaitM~
//            dlcmd2:use target for jnction to file                //~vaitM~
//vafk:120624 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  use ULPTR(unsigned __int64/ULONG)//~vafkI~
//vafc:120607 C4701 warning(used uninitialized variable) by VC6    //~vafcI~
//vaf9:120607 (WTL)Bug found by vs2010exp(used uninitialized variable),avoid warning C4701//~vaf9I~
//vaa0:110705 wildcard member display on dirlist,but disallow delete lcmd//~vaa0I~
//va0G:090725!rename fld by codetype                               //~va0GI~
//va09:090628 (BUG)no member error for "sor n" on dirlist when after "sort t-"//~va09I~
//va00:090510 merge utf8 version(enclosed by UTF8SUPPH)            //~va00I~
//          rename/move.. by filename of the codepage              //~va00I~
//          files encoded by utf8,option cplc/cpu8                 //~va00I~
//          select cmd chk cpu8/cplc of dir open parm              //~va00I~
//v92h:080505 (UTF)new dlcmd "[":cplc, "]":cpu8 option for edit/browse//~v92hI~//~va00I~
//v77v:080117*xuerpchk(uerrmsg parameter chk)                      //~v77vI~
//v77p:080107*accept lcmd "b"/"e" for dir on dirlist               //~v77pI~
//v923:080107 (UTF)apply codepage option for dirlist be cmd        //~v923I~//~va00I~
//v75J:070509 "g"(grep) dlcmd support                              //~v75JI~
//v75H:070508 e8("e /f80 p1") command support. lcmd "8" on fname-list and dir-list.//~v75HR~
//v75G:070508 dlcmd "3" support like as on filename panael         //~v75GI~
//v732:061227 (LNX:BUG)dirlist line count display(F6) wait for slink special file//~v732I~
//v731:061226 filesize>4GB support                                 //~v731I~
//v72r:061129 3270:initialy lineno display for TSO SPF             //~v72rI~
//v72a:061120 support line count display by spf info               //~v72aI~
//v71t:061022 display err msg when refresh cmd on dirlist for the case TSO err etc//~v71tI~
//v71j:061017 3270:undel lcmd support                              //~v71jI~
//v71a:061005 3270:dirlist:display filesize if once downloaded from localfile//~v71aI~
//v717:060926 3270:dirlist support                                 //~v717I~
//v690:060418 display file-description support on dir-list panel   //~v690I~
//v61e:050223 use cmd verb not /M parm for filename list(no parm is better)//~v61eI~
//v60r:050130 (BUG)2nd time refresh dose not refresh subdir        //~v60rI~
//            because 1st refresh change expandid:"-" to dirid:"+".//~v60rI~
//v59W:041211 (BUG)dirlist lineno is displayed as 0 after sort     //~v59WI~
//v59N:041121 (BUG)of v58t;prev sort option remains in rename fld when sort twice//~v59MI~
//v59M:041121 sort on dir list parameter change sor [[{/|-}o]{n|s|t}[-]]//~v59MI~
//v59c:041107 % lcmd:remote support(use rsh)                       //~v59cI~
//v58t:040926 (BUG)sort cmd ignore filemask previously specified   //~v58tI~
//v57j:040522 sort cmd for dirlist                                 //~v57jI~
//v57f:040521 dirlist sort;dlcmd "-" with /ox option:x:Size,t:Time,n:Name//~v57fI~
//v57c:040517 (BUG)refresh dose not update curr dir                //~v57cI~
//v57b:040517 (BUG)refresh fail when cur dir is deleted            //~v57bI~
//v57a:040517 (BUG)refresh fail when same filename is deleted(rename fld not eq filename)//~v57aI~
//v568:040402 (WXE:BUG)ignore association for dir(force open by xe)//~v568I~
//v55U:040321 (WXE)openwith when dblclick on filenamelist/dirlist if associated//~v55UI~
//v54r:040108 (FTP)dlcmd "." set cur dir support                   //~v54rI~
//v54m:040105 (FTP)update dir list file time when once browsed     //~v54mI~
//v540:031223 (WIN,UNX)set dir sepc on ufh                         //~v540I~
//v53Z:031223 (WIN,UNX)ftp support;no vfat alias(always long)      //~v53ZI~
//v50G:030201 add cmd "et"/"bt"/"st" for e/b/s /mt                 //~v50GI~
//v485:020427 (BUG)refresh dirlist err when expandied subdir is deleted//~v485I~
//v47Q:020330 leave "s" as old fashion and use "o" for edit/browse wit patm//~v47QI~
//v47P:020330 dlcmd "s" support option specification               //~v47PI~
//v47a:020223 (BUG)S+f1(refresh) issue err file not found          //~v47aI~
//             when dirname is expanded by S+f11(long filename display)//~v47aI~
//v44t:011206 dlcmd "I":/Mcn,"J":/Mkn                              //~v44gI~
//v44g:011204 new dlcmd 'K':/Mk(cob with no num),'N':/Mn(spf),'L':/Mc//~v44fI~
//v44f:011204 new dlcmd 'H'/'h'(h:follow edit/browse open mode,'H':reverse)//~v44fI~
//v20Q:001111 (BUG)dir list reflesh ignore filename mask           //~v20QI~
//v19V:000928 LINUX support("*" mean all member,"*.*" require intermediate ".";//~v19VI~
//            under windows those are same effect)                 //~v19VI~
//            udirlist use ufileeditname(of windows logic),so no bad effect but correct//~v19VI~
//v19a:000903 LINUX support(dir path seperator)                    //~v19aI~
//v196:000902 LINUX support(drop drive func;uchdrive/ugetdrive)    //~v196I~
//v184:001210 (BUG)clear mask when dirlist expand reduced(+)       //~v184I~
//v152:000311 dir-list REFresh cmd                                 //~v152I~
//v10v:990326 chng browse binary mode:"2" -->"1",and add "2" as edit binary mode//~v10vI~
//v10t:990404 csr restore after view split end                     //~v10tI~
//v10s:990404 move csr to split scr for view/vieedit               //~v10sI~
//v10r:990327 display lineno on dir list,accum size/line cnt to dir line//~v10rI~
//v10p:990326 new dlcmd "2";browse binary mode                     //~v10pI~
//v10k:990322 (BUG)after select cmd for new file on dirlist,end with no update//~v10kI~
//            or cancel update file cause deletion of parent dir plh.//~v10kI~
//            So locate cmd faile and move csr to last entry.      //~v10kI~
//v0g1:971207 print parm by short filename option(opt plfn on/off) //~v0g1I~
//v0fr:971109 dir list sort by fully for longname                  //~v0frI~
//v0fp:971108 split dlcmd2-->dlcmd5.c                              //~v0fpI~
//v0fn:971103 (GCC:W32)dirlist merge by shortname                  //~v0fnI~
//v0fm:971103 new function to set filename and alias to ufh        //~v0fmI~
//v0fk:971103 set alias also when re-expand filename change        //~v0fkI~
//v0ff:971019 (w95/GCC)dir sort seq is by alias                    //~v0ffI~
//v0fd:971018 (w95/GCC)udhname is long or short,but only one of them is needed.//~v0fdI~
//v09A:970531:(BUG)abend when dir line deleted which is on top of screen//~v09AI~
//            of splitted                                          //~v09AI~
//v09z:970425:dir upctr tell to parent dir list                    //~v09zI~
//            so enq when also browse(it may be dir)               //~v09zI~
//v09w:970524:Select cmd support on dir list                       //~v09vI~
//            update pdh line timstamp/size(search function)       //~v09vI~
//v09v:970524:(BUG)-dlcmdresetdata:filefind rc chk bug             //~v09vI~
//                  line data will not be updated                  //~v09vI~
//                 -dlcmdfree:dont deq now,it need until dlcmddeqpfc//~v09vI~
//                 (dlcmdddeqpfc call dlcmdresetdata if qued)      //~v09vI~
//v09h:970517:(BUG)dirgetflddata need size=strlen + 1,expand mask invalid//~v09hI~
//v09b:970510:disk free space display                              //~v09bI~
//            -req update free space info at edit from dirlist(dlcmd2.c)//~v09bI~
//v091:970104:(BUG) of v085 loop(next plh no setup by continue)    //~v091I~
//v08l:961123:edit/browse line range parameter                     //~v08lI~
//v085:961024:W95 VC                                               //~v085I~
//            free destroy free area(need UGETQNEXT before ufree)  //~v085I~
//v082:961001:(BUG)expand type change to dir even if expanded before re-expand//~v082I~
//            so keep type around re-expand.                       //~v082I~
//            (additional to v07m,for also path dir)               //~v082I~
//v07s:960825:new ulib.h/ulibdef.h(no need base def by os2.h)      //~v07sI~
//            to speed up compile,drop include(caused by WIN95 modify)//~v07sI~
//v07m:960714:(BUG)expand type change to dir even if expanded before re-expand//~v07mI~
//            so keep type around re-expand.                       //~v07mI~
//v05U:960203:(BUG)need full draw when entry deleted            //~v05UI~
//v05P:960120:(BUG)-(expand) dose'nt update tyep,caused "it is dir" msg//~v05PI~
//            for type is file on list (but actualy dir)        //~v05PI~
//v05L:960113:err not dir msg for dlcmd                         //~v05LI~
//v05K:960107:path id(:) for also edit/bowse dir                //~v05KI~
//v05H:960106:update time stamp when expand("-"/">") file       //~v05HI~
//v05G:960105:update time stamp of dir list when edit saved(add to v04j)//~v05GI~
//            change interface of dlcgetfullname(plc-->pdh parm)//~v05GI~
//v05F:960105:rename save field realloc each time(undeleted file may//~v05FI~
//            re-moved to long path name)                       //~v05FI~
//v05z:951224:(BUG)del and re-create and expand dir list,remain D flag//~v05zI~
//v05r:951126:dlcmd cursor                                      //~v05rI~
//v05q:951126:MOVE flag on memver of dir                        //~v05qI~
//v05o:951125:dlcmd dir delete woth confirmation support        //~v05oI~
//v04l:951008:free view/edit screen when delete                 //~v04lI~
//v04j:951007:update id for edit(W or E) saved file on dir list //~v04jR~
//v04d:950930:malloc/calloc rc chk for dos                      //~v04dI~
//v04b:950924:expand all dlcmd(>)                               //~v04bI~
//v04a:950924:process dir lcmd from last to be able to del empty dir//~v048I~
//            no need to reverse for browse/edit                //~v048I~
//v048:950924:dir renum from current line(performance)          //~v048I~
//v046:950923:view dir lcmd                                     //~v046I~
//v043:950917:cur dir lcmd(.)                                   //~5917I~
//v030:950903:save mask data for "-" and " "(cancel expand)     //~5903R~
//v03y:950903:pfh path name length for dir entry matching       //~5903I~
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#ifdef DOS
#else
    #ifdef W32                                                     //~v71aI~
		#include <io.h>                                            //~v71aI~
    #endif                                                         //~v71aI~
//  #define INCL_BASE                                              //~v07sR~
//  #include <os2.h>                                               //~v07sR~
#endif
//*******************************************************
#include <ulib.h>
#include <uerr.h>
#include <ualloc.h>
#include <uque.h>
#include <ustring.h>
#include <ufile.h>
#include <uparse.h>                                                //~v10pI~
#include <uftp.h>                                                  //~v717I~
#include <u3270.h>                                                 //~v71aI~
#include <utrace.h>                                                //~vaa0I~
#include <ufilew.h>                                                //~vavHI~
#include <utf.h>                                                   //~vawyI~
#include <ufemsg.h>                                                //~vb7aI~

#include "xe.h"
#include "xescr.h"
#include "xefile.h"
#include "xefile2.h"                                            //~5812I~
#include "xefsub.h"     //ufilesetfhfilename                       //~v0fnI~
#include "xepan.h"
#include "xedir.h"
#include "xedir2.h"                                             //~5731I~
#include "xedir3.h"                                                //~vb2sI~
#include "xedlcmd.h"                                            //~v05oM~
#include "xedlcmd2.h"                                           //~v05oM~
#include "xedlcmd3.h"                                           //~v05oI~
#include "xedlcmd5.h"                                              //~v0fpI~
#include "xefunc.h"
#include "xefunct.h"                                               //~v61eI~
#include "xedcmd.h"                                             //~5917M~
#include "xecsr.h"                                              //~v046I~
#include "xeerr.h"                                              //~5731I~
#include "xesub.h"                                              //~5903I~
#include "xetso.h"                                                 //~v717I~
#ifdef UTF8SUPPH                                                    //~v923I~//~va00R~
	#include "xeopt.h"                                             //~v923I~//~va00I~
#endif                                                             //~v923I~//~va00I~
#include "xefsubw.h"                                               //~vavHI~
#include "xeutf.h"                                                 //~vawyI~
//*******************************************************
static int Sexpandallsw;                                           //~v19VR~
static int Sexpandallerr;                                          //~v19VR~
static int Srefreshsw=0;                                           //~v485I~
#if defined(W32) || defined(DPMI)                                  //~v0g1I~
    static char Saliassw;                                          //~v0g1I~
#endif                                                             //~v0g1I~
static int Sfilejuctiontarget;                                     //~vaitR~
//*******************************************************       //~v04bI~
//int dlcmdotherbecmd(PUCLIENTWE Ppcw,PUDLCMD Pplc,char *Pmode);   //~v75JR~
int dlcmdotherbecmdfuncid(PUCLIENTWE Ppcw,PUDLCMD Pplc,int Pfuncidb,int Pfuncide);//~v61eR~
                                                                   //~v184I~
int dlcmdexpand1(PUCLIENTWE Ppcw,PULINEH Pplh,
                        UCHAR *Pdirname,UCHAR *Pfilemask);
int dlcmdsetszorlcsub(PUCLIENTWE Ppcw,PULINEH Pplh,int Popt,LONG Pdirlineno);//~v10rR~
//int dlcmdbinbe(PUCLIENTWE Ppcw,PUDLCMD Pplc,int Pbeopt);         //~v44fR~
int dlcmdbinbe(PUCLIENTWE Ppcw,PUDLCMD Pplc,int Pbeopt,char *Pmode);//~v44fI~
int dlcmdbinbefuncid(PUCLIENTWE Ppcw,PUDLCMD Pplc,int funcid);     //~v61eR~
int dlcmdrefreshsub(PUCLIENTWE Ppcw,PULINEH Pplh,PUDIRLH Ppdh);    //~v152R~
int dlcmdgetexpopt(char *Pparm,int *Ppsortopt);                    //~v57fR~
//int dlcgetfullnamefilejunctiontarget(PUDIRLH Ppdh,UCHAR *Pfname);  //~vaitR~//~vb2sR~
int dlcgetfullnamealias2(PUDIRLH Ppdh,UCHAR *Pfname);              //~vavJI~
//**************************************************************** //~v47PI~
// dlcmdselect                                                     //~v47PI~
// process select dlcmd                                            //~v47PI~
//*rc   :0                                                         //~v47PI~
//**************************************************************** //~v47PI~
int dlcmdselect(PUCLIENTWE Ppcw,PUDLCMD Pplc,PUDLCMD Pplcdummy)    //~v47PI~
{                                                                  //~v47QI~
    int   editsw;                                                  //~v47QI~
//*******************                                              //~v47QI~
    editsw=UCBITCHK(Pplc->UDLCflag,UDLCEDIT)!=0;  //edit or browse //~v47QI~
	return dlcmdbinbe(Ppcw,Pplc,editsw,"");	// /Mx                 //~v47QI~
}//dlcmdselect                                                     //~v47QI~
//**************************************************************** //~v50GI~
// dlcmdselecttext                                                 //~v50GI~
// process select dlcmd                                            //~v50GI~
//*rc   :0                                                         //~v50GI~
//**************************************************************** //~v50GI~
int dlcmdselecttext(PUCLIENTWE Ppcw,PUDLCMD Pplc,PUDLCMD Pplcdummy)//~v50GI~
{                                                                  //~v50GI~
    int   editsw;                                                  //~v50GI~
//*******************                                              //~v50GI~
    editsw=UCBITCHK(Pplc->UDLCflag,UDLCEDIT)!=0;  //edit or browse //~v50GI~
//  return dlcmdbinbe(Ppcw,Pplc,editsw," /Mt");	// /Mx             //~v61eR~
    if (editsw)                                                    //~v61eI~
    	return dlcmdbinbefuncid(Ppcw,Pplc,FUNCID_EDITTEXT);	// /Mx //~v61eR~
    else                                                           //~v61eI~
    	return dlcmdbinbefuncid(Ppcw,Pplc,FUNCID_BROWSETEXT);	// /Mx//~v61eR~
}//dlcmdselecttext                                                 //~v50GI~
//**************************************************************** //~v47QI~
// dlcmdopen                                                       //~v47QI~//~vbq1R~
// process open dlcmd                                              //~v47QI~
//*rc   :0                                                         //~v47QI~
//**************************************************************** //~v47QI~
int dlcmdopen(PUCLIENTWE Ppcw,PUDLCMD Pplc,PUDLCMD Pplcdummy)      //~v47QI~
{                                                                  //~v47PI~
    PULINEH plh;                                                   //~v47PI~
    PUDIRLH pdh;                                                   //~v47PI~
    int  rc;                                                       //~v47QR~
    UCHAR  modeparm[80];                                           //~v47PI~
//*******************                                              //~v47PI~
//  editsw=UCBITCHK(Pplc->UDLCflag,UDLCEDIT)!=0;  //edit or browse //~v47QR~
    plh=Pplc->UDLCplh;                                             //~v47PI~
    pdh=UGETPDH(plh);                                              //~v47PI~
//  if (pdh->UDHtype==UDHTFILE)                                    //~v47PI~//~vb2iR~
//  {                                                              //~v47PI~//~vb2iR~
        *modeparm=' ';                                             //~v47PI~
    	if (dirgetflddata(Ppcw,plh,PANL310RENAME,modeparm+1)<0)  //fld len//~v47PR~
        	return 4;   //internal logic err                       //~v47PI~
//  }                                                              //~v47PI~//~vb2iR~
//  else                                                           //~v47PI~//~vb2iR~
//  	*modeparm=0;                                               //~v47PI~//~vb2iR~
//  rc=dlcmdbinbe(Ppcw,Pplc,editsw,modeparm);	// /Mx             //~v47QR~
	rc=dlcmdotherbecmd(Ppcw,Pplc,modeparm);	// /Mx                 //~v47QI~
    if (rc)                                                        //~v47PI~
    {                                                              //~v47PI~
		dirsetflderr(Ppcw,plh,PANL310RENAME);//reverse err fld     //~v47PI~
    	return rc;                                                 //~v47PI~
    }                                                              //~v47PI~
	UCBITOFF(pdh->UDHflag,UDHFLCMDIN2|UDHFDDSETUP);//set pro at ddsetup//~v47PR~
    filesetcsr(Ppcw,plh,PANL310LINENO,0);//set csr                 //~v47PI~
	return rc;                                                     //~v47PI~
}//dlcmdopen                                                       //~v47QR~
//****************************************************************
// dlcmdbrowse
// process browse dlcmd
//*rc   :0
//****************************************************************
int dlcmdbrowse(PUCLIENTWE Ppcw,PUDLCMD Pplc,PUDLCMD Pplcdummy)
{
    UCHAR  fullpathname[_MAX_PATH];
    int rc;
#ifdef UTF8SUPPH                                                    //~v923I~//~va00R~
    PUFILEC pfc;                                                   //~v923I~//~va00I~
#endif                                                             //~v923I~//~va00I~
//*******************
#ifdef UTF8SUPPH                                                    //~v923I~//~va00R~
    pfc=Ppcw->UCWpfc;                                              //~v923I~//~va00I~
    if (UCBITCHK(pfc->UFCflag2,UFCF2UTF8P))                        //~v923I~//~va00I~
		return dlcmdbinbe(Ppcw,Pplc,0/*browse*/,"");	//specify cp option//~v923R~//~va00I~
#endif                                                             //~v923I~//~va00I~
//  if (dlcgetfullname(UGETPDH(Pplc->UDLCplh),fullpathname))    //~v05GR~//~vaitR~
    if (dlcgetfullnamefilejunctiontarget(UGETPDH(Pplc->UDLCplh),fullpathname))//~vaitI~
        return 4;                                               //~5721I~
    Ppcw->UCWparm=fullpathname;
    rc=func_browse_file2(Ppcw,0);   //filename only                //~v08lR~
    Ppcw->UCWparm=0;        //worked
//  if (!rc)                                                    //~v048R~
//      dlcfifo(Ppcw);                                          //~v048R~
    if (rc)                                                        //~v09zI~
        return rc;                                                 //~v09zI~
    rc=dlcmdeditenq(Ppcw,Pplc); //once deq from previous dir list  //~v09zI~
    return rc;                                                  //~5721R~
}//dlcmdbrowse

//**************************************************************** //~v10pR~
// dlcmdbrowse by bin mode                                         //~v10vR~
//**************************************************************** //~v10pR~
int dlcmdbrowse2(PUCLIENTWE Ppcw,PUDLCMD Pplc,PUDLCMD Pplcdummy)   //~v10pR~
{                                                                  //~v10vI~
//  return dlcmdbinbe(Ppcw,Pplc,0);                                //~v44fR~
//  return dlcmdbinbe(Ppcw,Pplc,0," /Mb");      //browsw parm      //~v61eR~
    return dlcmdbinbefuncid(Ppcw,Pplc,FUNCID_BROWSEBIN);      //browsw parm//~v61eR~
}//dlcmdbrowse2                                                    //~v10vI~
//**************************************************************** //~v10vI~
// dlcmdedit by bin mode                                           //~v10vI~
//**************************************************************** //~v10vI~
int dlcmdedit2(PUCLIENTWE Ppcw,PUDLCMD Pplc,PUDLCMD Pplcdummy)     //~v10vI~
{                                                                  //~v10vI~
//  return dlcmdbinbe(Ppcw,Pplc,1);                                //~v44fR~
//  return dlcmdbinbe(Ppcw,Pplc,1," /Mb");		//edit parm        //~v61eR~
    return dlcmdbinbefuncid(Ppcw,Pplc,FUNCID_EDITBIN);		//edit parm//~v61eR~
}//dlcmdedit2                                                      //~v10vI~
#ifdef UTF8SUPPH                                                    //~v92hM~//~va00R~
//**************************************************************** //~v92hM~//~va00I~
// dlcmdedit with utf8 option                                      //~v92hM~//~va00I~
//**************************************************************** //~v92hM~//~va00I~
int dlcmdedit3(PUCLIENTWE Ppcw,PUDLCMD Pplc,PUDLCMD Pplcdummy)     //~v92hI~//~va00I~
{                                                                  //~v92hM~//~va00I~
    char *popt;                                                    //~v92hM~//~va00I~
    int rc;                                                        //~v92hM~//~va00I~
//****************                                                 //~v92hM~//~va00I~
	if (Pplc->UDLCcmd==UDLCCMD_CPU8)                               //~v92hM~//~va00I~
    	popt=" " MODE_UTF8;                                        //~v92hR~//~va00I~
    else                                                           //~v92hM~//~va00I~
	if (Pplc->UDLCcmd==UDLCCMD_CPLC)                               //~v92hM~//~va00I~
    	popt=" " MODE_LOCALE;                                      //~v92hR~//~va00I~
    else                                                           //~v92hM~//~va00I~
        return 4;                                                  //~v92hM~//~va00I~
	rc=dlcmdotherbecmd(Ppcw,Pplc,popt);	// /Mx                     //~v92hM~//~va00I~
    return rc;                                                     //~v92hM~//~va00I~
}//dlcmdedit3                                                      //~v92hI~//~va00I~
#endif                                                             //~v92hM~//~va00I~
//**************************************************************** //~v75GI~
// dlcmdbinbe3                                                     //~v75GI~
// bin edit/brows according to dir panel mode                      //~v75GI~
//**************************************************************** //~v75GI~
int dlcmdbinbe3(PUCLIENTWE Ppcw,PUDLCMD Pplc,PUDLCMD Pplcdummy)    //~v75GI~
{                                                                  //~v75GI~
    int   editsw;                                                  //~v75GI~
//*******************                                              //~v75GI~
    editsw=UCBITCHK(Pplc->UDLCflag,UDLCEDIT)!=0;  //edit or browse //~v75GI~
    if (editsw)                                                    //~v75GI~
		return dlcmdedit2(Ppcw,Pplc,Pplcdummy);                    //~v75GI~
    else                                                           //~v75GI~
		return dlcmdbrowse2(Ppcw,Pplc,Pplcdummy);                  //~v75GI~
}//dlcmdbinbe3                                                     //~v75GI~
//**************************************************************** //~v75HI~
// dlcmdeditf80                                                    //~v75HI~
// edit with f80 option                                            //~v75HI~
//**************************************************************** //~v75HI~
int dlcmdeditf80(PUCLIENTWE Ppcw,PUDLCMD Pplc,PUDLCMD Pplcdummy)   //~v75HI~
{                                                                  //~v75HI~
    int   editsw;                                                  //~v75HI~
//*******************                                              //~v75HI~
    editsw=UCBITCHK(Pplc->UDLCflag,UDLCEDIT)!=0;  //edit or browse //~v75HI~
    if (editsw)                                                    //~v75HI~
    	return dlcmdbinbefuncid(Ppcw,Pplc,FUNCID_EDITF80);	// /Mx //~v75HI~
    else                                                           //~v75HI~
    	return dlcmdbinbefuncid(Ppcw,Pplc,FUNCID_BROWSEF80);	// /Mx//~v75HI~
}//dlcmdeditf80                                                    //~v75HI~
//**************************************************************** //~v10vI~
// dlcmdbinbe                                                      //~v10vI~
// process browse/edit bynaly mode for dlcmd                       //~v10vI~
//parm1:pcw                                                        //~v10vI~
//parm2:plc                                                        //~v10vI~
//parm3:0:browse,1:edit                                            //~v10vI~
//parm4:parm string on /M                                          //~v44fI~
//*rc   :0                                                         //~v10vI~
//**************************************************************** //~v10vI~
int dlcmdbinbe(PUCLIENTWE Ppcw,PUDLCMD Pplc,int Pbeopt,char *Pmode)//~v44fR~
{                                                                  //~v10pR~
    UCHAR  fullpathname[_MAX_PATH];                                //~v10pR~
//#ifdef UTF8SUPP                                                    //~v923I~//~vauAR~
    PUFILEC pfc;                                                   //~v923M~//~va00I~
#ifdef UTF8SUPP                                                    //~vauAI~
    UCHAR  fnameq[_MAX_PATH+32];                                   //~v923M~//~va00I~
    UCHAR *pcp;                                                    //~v923M~//~va00I~
#else                                                              //~v923I~//~va00I~
    UCHAR  fnameq[_MAX_PATH+16];                                   //~v10pI~
#endif                                                             //~v923I~//~va00I~
    PUDIRLH pdh;                                                   //~v10vI~
    int rc;                                                        //~v10pI~
    UINT len;                                                      //~v10pI~
//*******************                                              //~v10pI~
    pdh=UGETPDH(Pplc->UDLCplh);                                    //~v10vI~
//  if (dlcgetfullname(pdh,fullpathname))                          //~v10vR~//~vaitR~
    if (dlcgetfullnamefilejunctiontarget(pdh,fullpathname))        //~vaitI~
        return 4;                                                  //~v10pI~
  if (Pplc->UDLCcmd!='S')   //not select cmd                       //~v47QR~
    if (pdh->UDHtype!=UDHTFILE)                                    //~v10vI~
      if (Pplc->UDLCcmd!='B'                                       //~v77pI~
      &&  Pplc->UDLCcmd!='E'                                       //~v77pR~
      &&  Pplc->UDLCcmd!='O')   //not edit/browse/Open             //~v77pI~
        return errdir(fullpathname);                               //~v10vR~
//  len=strlen(fullpathname);                                      //~v10pR~//~vb2ER~
    len=(UINT)strlen(fullpathname);                                //~vb2EI~
    if (uparsein(fullpathname,fnameq,sizeof(fnameq),0,'\"'))//enclosed if space embedding//~v10pI~
//      len=strlen(fnameq);         //dir name                     //~v10pR~//~vb2ER~
        len=(UINT)strlen(fnameq);         //dir name               //~vb2EI~
//  strcpy(fnameq+len," /Mb");  //binary option                    //~v44fR~
//#ifdef UTF8SUPP                                                    //~v923M~//~vauAR~
    pfc=Ppcw->UCWpfc;                                              //~v923M~//~va00I~
#ifdef UTF8SUPP                                                    //~vauAI~
    if (UCBITCHK(pfc->UFCflag2,UFCF2UTF8P))                        //~v923M~//~va00I~
    {                                                              //~v923M~//~va00I~
        if (UCBITCHK(pfc->UFCflag2,UFCF2UTF8))                     //~v923M~//~va00I~
            pcp=" " MODE_UTF8;                                     //~v923M~//~va00I~
        else                                                       //~v923M~//~va00I~
            pcp=" " MODE_LOCALE;                                   //~v923M~//~va00I~
        strcpy(fnameq+len,pcp);                                    //~v923I~//~va00I~
        len+=strlen(pcp);                                          //~v923I~//~va00I~
    }                                                              //~v923M~//~va00I~
#endif                                                             //~v923M~//~va00I~
    strcpy(fnameq+len,Pmode);   // /M parm                         //~v44fI~
    Ppcw->UCWparm=fnameq;                                          //~v10pR~
#ifdef UTF8SUPPH                                                   //~va00I~
	UCBITON(Ppcw->UCWflag2,UCWF2SELECTCMD);	//parm to fileoptionchk//~va00I~
#endif                                                             //~va00I~
    UCBITON(pfc->UFCflag3,UFCF3SELECTDLCMD);                       //~vb2gI~
    if (UCBITCHK(pdh->UDHflag3,UDHF3U8UTF))                        //~vauAI~
    	UCBITON(pfc->UFCflag3,UFCF3SELECTFNU8);                    //~vauAR~
    else                                                           //~vauAI~
    if (UCBITCHK(pdh->UDHflag3,UDHF3U8LC))                         //~vauAI~
    	UCBITON(pfc->UFCflag3,UFCF3SELECTFNLC);                    //~vauAR~
  if (Pbeopt)                                                      //~v10vI~
    rc=func_edit_file2(Ppcw,1); //filename with option /Mb         //~v10vI~
  else                                                             //~v10vI~
    rc=func_browse_file2(Ppcw,1);   //filename with option /Mb     //~v10pR~
#ifdef UTF8SUPPH                                                   //~va00I~
	UCBITOFF(Ppcw->UCWflag2,UCWF2SELECTCMD);                       //~va00I~
#endif                                                             //~va00I~
    UCBITOFF(pfc->UFCflag3,UFCF3SELECTDLCMD);                      //~vb2gI~
    UCBITOFF(pfc->UFCflag3,(UFCF3SELECTFNU8|UFCF3SELECTFNLC));     //~vauAR~
    Ppcw->UCWparm=0;        //worked                               //~v10pI~
    if (rc)                                                        //~v10pI~
        return rc;                                                 //~v10pI~
    rc=dlcmdeditenq(Ppcw,Pplc); //once deq from previous dir list  //~v10pI~
    return rc;                                                     //~v10pI~
}//dlcmdbbinbe                                                     //~v10vR~
//**************************************************************** //~v61eI~
// dlcmdbinbefunid                                                 //~v61eR~
// process browse/edit binaly mode for dlcmd                       //~v61eI~
//parm1:pcw                                                        //~v61eI~
//parm2:plc                                                        //~v61eI~
//parm3:browse/edit func addr                                      //~v61eI~
//*rc   :0                                                         //~v61eI~
//**************************************************************** //~v61eI~
int dlcmdbinbefuncid(PUCLIENTWE Ppcw,PUDLCMD Pplc,int Pfuncid)     //~v61eR~
{                                                                  //~v61eI~
#ifdef UTF8SUPP                                                    //~v923I~//~va00R~
    PUFILEC pfc;                                                   //~v923I~//~va00I~
    UCHAR  fnameq[_MAX_PATH+32];                                   //~v923M~//~va00I~
    UCHAR  fullpathname[_MAX_PATH+32];                             //~v923M~//~va00I~
    UCHAR *pcp;                                                    //~v923M~//~va00I~
    int len;                                                       //~v923M~//~va00I~
#else                                                              //~v923I~//~va00I~
    UCHAR  fullpathname[_MAX_PATH];                                //~v61eI~
#endif                                                             //~v923I~//~va00I~
    PUDIRLH pdh;                                                   //~v61eI~
    int rc,opdnosv;                                                //~v61eR~
    FUNCTBL *pft,*pftsv;                                           //~v61eI~
    char *potsv,*parmsv;                                           //~v61eI~
    FTFUNC *pfunc;                                                 //~v61eI~
//*******************                                              //~v61eI~
    pdh=UGETPDH(Pplc->UDLCplh);                                    //~v61eI~
//  if (dlcgetfullname(pdh,fullpathname))                          //~v61eI~//~vaitR~
    if (dlcgetfullnamefilejunctiontarget(pdh,fullpathname))        //~vaitI~
        return 4;                                                  //~v61eI~
  	if (Pplc->UDLCcmd!='S')   //not select cmd                     //~v61eI~
    	if (pdh->UDHtype!=UDHTFILE)                                //~v61eI~
        	return errdir(fullpathname);                           //~v61eI~
    pft=functblsrch(Pfuncid);                                      //~v61eI~
    if (!pft)                                                      //~v61eI~
    	return 8;                                                  //~v61eI~
    pftsv=Ppcw->UCWpfunct;                                         //~v61eR~
    parmsv=Ppcw->UCWparm;                                          //~v61eI~
    potsv=Ppcw->UCWopdpot;                                         //~v61eI~
    opdnosv=Ppcw->UCWopdno;                                        //~v61eI~
                                                                   //~v61eI~
    Ppcw->UCWpfunct=pft;                                           //~v61eR~
#ifdef UTF8SUPP                                                    //~v923I~//~va00R~
    pfc=Ppcw->UCWpfc;                                              //~v923I~//~va00I~
  if (UCBITCHK(pfc->UFCflag2,UFCF2UTF8P))                          //~v923I~//~va00I~
  {                                                                //~v923I~//~va00I~
    if (UCBITCHK(pfc->UFCflag2,UFCF2UTF8))                         //~v923I~//~va00I~
        pcp=" " MODE_UTF8;                                         //~v923I~//~va00I~
    else                                                           //~v923I~//~va00I~
        pcp=" " MODE_LOCALE;                                       //~v923I~//~va00I~
    len=strlen(fullpathname);                                      //~v923I~//~va00I~
    strcpy(fullpathname+len+1,pcp+1);   // /M parm                 //~v923I~//~va00I~
    if (uparsein(fullpathname,fnameq,sizeof(fnameq),0,'\"'))//enclosed if space embedding//~v923I~//~va00I~
        len=strlen(fnameq);         //dir name                     //~v923I~//~va00I~
    strcpy(fnameq+len,pcp);   // /M parm                           //~v923I~//~va00I~
    Ppcw->UCWparm=fnameq;                                          //~v923I~//~va00I~
	Ppcw->UCWopdpot=fullpathname;  //same as before parse out      //~v923I~//~va00I~
	Ppcw->UCWopdno=2;        //no other parm                       //~v923I~//~va00I~
  }                                                                //~v923I~//~va00I~
  else                                                             //~v923I~//~va00I~
  {                                                                //~v923I~//~va00I~
#endif                                                             //~v923I~//~va00I~
    Ppcw->UCWparm=fullpathname;                                    //~v61eR~
	Ppcw->UCWopdpot=fullpathname;  //same as before parse out      //~v61eR~
	Ppcw->UCWopdno=1;        //no other parm                       //~v61eI~
#ifdef UTF8SUPP                                                    //~v923I~//~va00R~
  }                                                                //~v923I~//~va00I~
#endif                                                             //~v923I~//~va00I~
                                                                   //~v61eI~
    pfunc=pft->FTfunc[UCWTDIR];                                    //~v61eI~
#ifdef UTF8SUPPH                                                   //~va00I~
	UCBITON(Ppcw->UCWflag2,UCWF2SELECTCMD);	//parm to fileoptionchk//~va00I~
#endif                                                             //~va00I~
    rc=pfunc(Ppcw);                                                //~v61eR~
#ifdef UTF8SUPPH                                                   //~va00I~
	UCBITOFF(Ppcw->UCWflag2,UCWF2SELECTCMD);                       //~va00I~
#endif                                                             //~va00I~
                                                                   //~v61eI~
    Ppcw->UCWpfunct=pftsv;                                         //~v61eR~
    Ppcw->UCWparm=parmsv;                                          //~v61eI~
    Ppcw->UCWopdpot=potsv;                                         //~v61eI~
    Ppcw->UCWopdno=opdnosv;                                        //~v61eI~
    if (rc)                                                        //~v61eI~
        return rc;                                                 //~v61eI~
    rc=dlcmdeditenq(Ppcw,Pplc); //once deq from previous dir list  //~v61eI~
    return rc;                                                     //~v61eI~
}//dlcmdbbinbefuncid                                               //~v61eR~
//****************************************************************
// dlcmdedit
// process browse dlcmd
//*rc   :0
//****************************************************************
int dlcmdedit(PUCLIENTWE Ppcw,PUDLCMD Pplc,PUDLCMD Pplcdummy)
{
    UCHAR  fullpathname[_MAX_PATH];
    int rc;
#ifdef UTF8SUPPH                                                    //~v923I~//~va00R~
    PUFILEC pfc;                                                   //~v923I~//~va00I~
#endif                                                             //~v923I~//~va00I~
//*******************
#ifdef UTF8SUPPH                                                    //~v923I~//~va00R~
    pfc=Ppcw->UCWpfc;                                              //~v923I~//~va00I~
    if (UCBITCHK(pfc->UFCflag2,UFCF2UTF8P))                        //~v923I~//~va00I~
		return dlcmdbinbe(Ppcw,Pplc,1/*edit*/,"");	//specify cp option//~v923R~//~va00I~
#endif                                                             //~v923I~//~va00I~
//  if (dlcgetfullname(UGETPDH(Pplc->UDLCplh),fullpathname))    //~v05GR~//~vaitR~
    if (dlcgetfullnamefilejunctiontarget(UGETPDH(Pplc->UDLCplh),fullpathname))//~vaitI~
        return 4;                                               //~5721I~
    Ppcw->UCWparm=fullpathname;
    rc=func_edit_file2(Ppcw,0); //parm is file name only           //~v08lR~
    Ppcw->UCWparm=0;        //worked
    if (rc)                                                     //~v04jI~
        return rc;                                              //~v04jI~
//  if (!rc)                                                    //~v048R~
//      dlcfifo(Ppcw);                                          //~v048R~
    return dlcmdeditenq(Ppcw,Pplc); //once deq from previous dir list//~v04jR~
}//dlcmdedit                                                    //~v04jR~

//****************************************************************//~5723I~
// dlcfifo                                                      //~5723I~
// change order to FIFO                                         //~5723I~
//*parm  :dir list pcw                                          //~5723R~
//*ret   :none                                                  //~5723I~
//****************************************************************//~5723I~
//void dlcfifo(PUCLIENTWE Ppcw)                                 //~v048R~
//{                                                             //~v048R~
//    PUCLIENTWE pcw;                                           //~v048R~
//  PUFILEH pfh;                                                //~v048R~
//*******************                                           //~5723I~
//  pcw=scrgetcw(0);    //current top pcw                       //~v048R~
//  pfh=((PUFILEC)(Ppcw->UCWpfc))->UFCpfh;  //dir pfh           //~v048R~
//  if (UCBITCHK(pfh->UFHflag,UFHFUPCTRREQ))//first time after exec_file//~v048R~
//      UCBITON(pcw->UCWflag,UCWFWAKEUP+UCWFDRAW);//re-init     //~v048R~
//  else                                                        //~v048R~
//  {                                                           //~v048R~
//      pcw=scrdeqcw(Ppcw->UCWsplitid,0,0);//no free,deq top    //~v048R~
//      screnqcw(Ppcw->UCWsplitid,pcw,UQUE_BEF,Ppcw);//after dir//~v048R~
//  }                                                           //~v048R~
//}//dlcfifo                                                    //~v048R~
                                                                //~v04jI~
//****************************************************************//~v046I~
// dlcmdviewb                                                   //~v046I~
// process view browse(v) dlcmd                                 //~v046I~
//*rc   :0                                                      //~v046I~
//****************************************************************//~v046I~
int dlcmdviewb(PUCLIENTWE Ppcw,PUDLCMD Pplc,PUDLCMD Pplcdummy)  //~v046I~
{                                                               //~v046I~
    UCHAR  fullpathname[_MAX_PATH];                             //~v046I~
    int rc;                                                     //~v046I~
    int splitsw;                                                   //~v10tI~
    PUCLIENTWE pcw2;                                            //~v046I~
//*******************                                           //~v046I~
//  if (dlcmdviewscrswap1(Ppcw,Pplc,fullpathname,&pcw2))           //~v10tR~
    if ((splitsw=dlcmdviewscrswap1(Ppcw,Pplc,fullpathname,&pcw2))>=4)//~v10tI~
        return 4;                                               //~v046I~
    pcw2->UCWparm=fullpathname;                                 //~v046I~
    rc=func_browse_file2(pcw2,0);   //filename only                //~v08lR~
    pcw2->UCWparm=0;        //worked                            //~v046R~
    if (rc)                                                     //~v046I~
        return rc;                                              //~v046I~
    dlcsaveviewpcw();   //save viewb pcw to swap at last           //~v10sM~
    if (splitsw)                                                   //~v10tI~
    {                                                              //~v10tI~
        scrpopup(pcw2,0);   //pop menu to top                      //~v10tR~
        panpopup(pcw2);     //free top                             //~v10tI~
    }                                                              //~v10tI~
    if (dlcmdviewscrswap2(Ppcw,Pplc))                           //~v046R~
        return 4;                                               //~v046I~
    return 0;                                                   //~v046I~
}//dlcmdviewb                                                   //~v046I~
                                                                //~v046I~
//****************************************************************//~v046I~
// dlcmdviewe                                                   //~v046I~
// process view browse(v) dlcmd                                 //~v046I~
//*rc   :0                                                      //~v046I~
//****************************************************************//~v046I~
int dlcmdviewe(PUCLIENTWE Ppcw,PUDLCMD Pplc,PUDLCMD Pplcdummy)  //~v046I~
{                                                               //~v046I~
    UCHAR  fullpathname[_MAX_PATH];                             //~v046I~
    int rc;                                                     //~v046I~
    int splitsw;                                                   //~v10tI~
    PUCLIENTWE pcw2;                                            //~v046I~
//*******************                                           //~v046I~
//  if (dlcmdviewscrswap1(Ppcw,Pplc,fullpathname,&pcw2))           //~v10tR~
    if ((splitsw=dlcmdviewscrswap1(Ppcw,Pplc,fullpathname,&pcw2))>=4)//~v10tI~
        return 4;                                               //~v046I~
    pcw2->UCWparm=fullpathname;                                 //~v046I~
    rc=func_edit_file2(pcw2,0); //parm is filename only            //~v08lR~
    pcw2->UCWparm=0;        //worked                            //~v046R~
    if (rc)                                                     //~v046I~
        return rc;                                              //~v046I~
    dlcsaveviewpcw();   //save viewb pcw to swap at last           //~v10sM~
    if (splitsw)                                                   //~v10tI~
    {                                                              //~v10tI~
        scrpopup(pcw2,0);   //pop menu to top                      //~v10tI~
        panpopup(pcw2);     //free top                             //~v10tI~
    }                                                              //~v10tI~
    if (dlcmdviewscrswap2(Ppcw,Pplc))                           //~v046R~
        return 4;                                               //~v046I~
    return 0;                                                   //~v046I~
}//dlcmdviewe                                                   //~v046I~
//**************************************************************** //~v44fR~
// dlcmdhex                                                        //~v44fR~
// hex display                                                     //~v44fR~
//*rc   :0                                                         //~v44fR~
//**************************************************************** //~v44fR~
int dlcmdhex(PUCLIENTWE Ppcw,PUDLCMD Pplc,PUDLCMD Pplcdummy)       //~v44fR~
{                                                                  //~v44fR~
//	return dlcmdotherbecmd(Ppcw,Pplc," /Mh");	//browse/edit cmd parm//~v61eR~
  	return dlcmdotherbecmdfuncid(Ppcw,Pplc,FUNCID_BROWSEHEX,FUNCID_EDITHEX);	//browse/edit cmd parm//~v61eR~
}//dlcmdhex                                                        //~v44fR~
//**************************************************************** //~v44gR~
// dlcmdcobnum                                                     //~v44gR~
// cobol with col1-6:seqno                                         //~v44gR~
//*rc   :0                                                         //~v44gR~
//**************************************************************** //~v44gR~
int dlcmdcobnum(PUCLIENTWE Ppcw,PUDLCMD Pplc,PUDLCMD Pplcdummy)    //~v44gR~
{                                                                  //~v44gR~
//  return dlcmdotherbecmd(Ppcw,Pplc," /Mc");	//browse/edit cmd parm//~v61eR~
    return dlcmdotherbecmdfuncid(Ppcw,Pplc,FUNCID_BROWSESPFCOB,FUNCID_EDITSPFCOB);	//browse/edit cmd parm//~v61eR~
}//dlcmdcobnum                                                     //~v44gR~
//**************************************************************** //~v44gR~
// dlcmdcobnum                                                     //~v44gR~
// cobol with col1-6:space                                         //~v44gR~
//*rc   :0                                                         //~v44gR~
//**************************************************************** //~v44gR~
int dlcmdcobspace(PUCLIENTWE Ppcw,PUDLCMD Pplc,PUDLCMD Pplcdummy)  //~v44gR~
{                                                                  //~v44gR~
//	return dlcmdotherbecmd(Ppcw,Pplc," /Mk");	//browse/edit cmd parm//~v61eR~
  	return dlcmdotherbecmdfuncid(Ppcw,Pplc,FUNCID_BROWSESPFCOB2,FUNCID_EDITSPFCOB2);	//browse/edit cmd parm//~v61eR~
}//dlcmdcobspace                                                   //~v44gR~
//**************************************************************** //~v44tI~
// dlcmdspfcobnum                                                  //~v44tI~
// cobol with col1-6:seqno                                         //~v44tI~
//*rc   :0                                                         //~v44tI~
//**************************************************************** //~v44tI~
int dlcmdspfcobnum(PUCLIENTWE Ppcw,PUDLCMD Pplc,PUDLCMD Pplcdummy) //~v44tI~
{                                                                  //~v44tI~
//  return dlcmdotherbecmd(Ppcw,Pplc," /Mcn");	//browse/edit cmd parm//~v61eR~
    return dlcmdotherbecmdfuncid(Ppcw,Pplc,FUNCID_BROWSESPFCOBNUM,FUNCID_EDITSPFCOBNUM);	//browse/edit cmd parm//~v61eR~
}//dlcmdspfcobnum                                                  //~v44tI~
//**************************************************************** //~v44tI~
// dlcmdspfcobnum                                                  //~v44tI~
// cobol with col1-6:space                                         //~v44tI~
//*rc   :0                                                         //~v44tI~
//**************************************************************** //~v44tI~
int dlcmdspfcobspace(PUCLIENTWE Ppcw,PUDLCMD Pplc,PUDLCMD Pplcdummy)//~v44tI~
{                                                                  //~v44tI~
//	return dlcmdotherbecmd(Ppcw,Pplc," /Mkn");	//browse/edit cmd parm//~v61eR~
	return dlcmdotherbecmdfuncid(Ppcw,Pplc,FUNCID_BROWSESPFCOB2NUM,FUNCID_EDITSPFCOB2NUM);	//browse/edit cmd parm//~v61eR~
}//dlcmdspfcobspace                                                //~v44tI~
//**************************************************************** //~v44gR~
// dlcmdspf                                                        //~v44gR~
// spf                                                             //~v44gR~
//*rc   :0                                                         //~v44gR~
//**************************************************************** //~v44gR~
int dlcmdspf(PUCLIENTWE Ppcw,PUDLCMD Pplc,PUDLCMD Pplcdummy)       //~v44gR~
{                                                                  //~v44gR~
//	return dlcmdotherbecmd(Ppcw,Pplc," /Mn");	//browse/edit cmd parm//~v61eR~
  	return dlcmdotherbecmdfuncid(Ppcw,Pplc,FUNCID_BROWSESPF,FUNCID_EDITSPF);	//browse/edit cmd parm//~v61eR~
}//dlcmdspf                                                        //~v44gR~
//**************************************************************** //~v75JI~
// get cmd browse/edit is by upper case                            //~v75JI~
//*rc   :1 edit,0:browse                                           //~v75JI~
//**************************************************************** //~v75JI~
int dlcmdbecmdid(PUCLIENTWE Ppcw,PUDLCMD Pplc)                     //~v75JI~
{                                                                  //~v75JI~
    int  editsw;                                                   //~v75JI~
//*******************                                              //~v75JI~
//dtermin browse or edit                                           //~v75JI~
    if (UCBITCHK(Pplc->UDLCflag,UDLCEDIT))  //dir list is edit mode//~v75JI~
		if (UCBITCHK(Pplc->UDLCflag,UDLCUPPER))	//upper case cmd   //~v75JI~
        	editsw=0;				//reverse mode                 //~v75JI~
        else                                                       //~v75JI~
        	editsw=1;                                              //~v75JI~
    else      								//browse dirlist       //~v75JI~
		if (UCBITCHK(Pplc->UDLCflag,UDLCUPPER))	//upper case cmd   //~v75JI~
        	editsw=1;             //reverse mode                   //~v75JI~
        else                                                       //~v75JI~
        	editsw=0;                                              //~v75JI~
    return editsw;                                                 //~v75JI~
}//dlcmdbecmdid                                                    //~v75JI~
//**************************************************************** //~v44fR~
// for cmd browse/edit is by upper case                            //~v44fR~
//*rc   :0                                                         //~v44fR~
//**************************************************************** //~v44fR~
int dlcmdotherbecmd(PUCLIENTWE Ppcw,PUDLCMD Pplc,char *Pmode)      //~v44fR~
{                                                                  //~v44fR~
    int  editsw;                                                   //~v44fR~
//*******************                                              //~v44fR~
//dtermin browse or edit                                           //~v44fR~
    if (UCBITCHK(Pplc->UDLCflag,UDLCEDIT))  //dir list is edit mode//~v44fR~
		if (UCBITCHK(Pplc->UDLCflag,UDLCUPPER))	//upper case cmd   //~v44fR~
        	editsw=0;				//reverse mode                 //~v44fR~
        else                                                       //~v44fR~
        	editsw=1;                                              //~v44fR~
    else      								//browse dirlist       //~v44fR~
		if (UCBITCHK(Pplc->UDLCflag,UDLCUPPER))	//upper case cmd   //~v44fR~
        	editsw=1;             //reverse mode                   //~v44fR~
        else                                                       //~v44fR~
        	editsw=0;                                              //~v44fR~
	return dlcmdbinbe(Ppcw,Pplc,editsw,Pmode);	// /Mx             //~v44fI~
}//dlcmdotherbecmd                                                 //~v44fR~
//**************************************************************** //~v61eI~
// for case sensitive cmd browse/edit by func addr parm            //~v61eI~
//*rc   :0                                                         //~v61eI~
//**************************************************************** //~v61eI~
int dlcmdotherbecmdfuncid(PUCLIENTWE Ppcw,PUDLCMD Pplc,int Pfuncidb,int Pfuncide)//~v61eR~
{                                                                  //~v61eI~
    int  editsw;                                                   //~v61eI~
    int funcid;                                                    //~v61eI~
//*******************                                              //~v61eI~
//dtermin browse or edit                                           //~v61eI~
    if (UCBITCHK(Pplc->UDLCflag,UDLCEDIT))  //dir list is edit mode//~v61eI~
		if (UCBITCHK(Pplc->UDLCflag,UDLCUPPER))	//upper case cmd   //~v61eI~
        	editsw=0;				//reverse mode                 //~v61eI~
        else                                                       //~v61eI~
        	editsw=1;                                              //~v61eI~
    else      								//browse dirlist       //~v61eI~
		if (UCBITCHK(Pplc->UDLCflag,UDLCUPPER))	//upper case cmd   //~v61eI~
        	editsw=1;             //reverse mode                   //~v61eI~
        else                                                       //~v61eI~
        	editsw=0;                                              //~v61eI~
    if (editsw)                                                    //~v61eI~
    	funcid=Pfuncide;                                           //~v61eI~
    else                                                           //~v61eI~
    	funcid=Pfuncidb;                                           //~v61eI~
	return dlcmdbinbefuncid(Ppcw,Pplc,funcid);	//call browse func //~v61eR~
}//dlcmdotherbecmdfuncid                                           //~v61eR~
//****************************************************************//~v046I~
// dlcmddeqpfc                                                  //~v046I~
//*deq pfc from pdh and re-draw plh                             //~v046I~
//*parm1:pfc                                                       //~v09wR~
//*return:none                                                  //~v046I~
//****************************************************************//~v046I~
void dlcmddeqpfc(PUFILEC Ppfc)                                     //~v09wR~
{                                                               //~v046I~
    PUQUEH  pqh;                                                //~v046I~
    PUDIRLH pdh;                                                //~v046I~
    PULINEH plh;                                                //~v046I~
//  PULINEH plhprev;                                               //~v10kR~
    PUFILEH pfh;                                                   //~v09bI~
    PUCLIENTWE pcw;                                                //~v09bI~
//*******************                                           //~v046I~
    if (pqh=UGETQHDR(Ppfc),pqh)         //qhdr addr on pdh      //~v046R~
    {                                                           //~v046I~
        UDEQ(UQUE_ENT,pqh,Ppfc);        //deq from view lcmd pdh//~v046R~
//      pdh=(PUDIRLH)(PVOID)((ULONG)pqh-offsetof(UDIRLH,UDHviewqh));//~v046I~//~vafkR~
        pdh=(PUDIRLH)(PVOID)((ULPTR)pqh-offsetof(UDIRLH,UDHviewqh));//~vafkI~
        plh=UGETDIRPLH(pdh);                                    //~v046I~
        pfh=UGETPFH(plh);                                          //~v54mI~
        UCBITON(plh->ULHflag,ULHFDRAW); //to clear viewed sign  //~v046I~
        if (UCBITCHK(Ppfc->UFCflag,UFCFENDSAVE))    //saved at end//~v04jI~
        {                                                       //~v05GI~
            dlcmdresetdata(pdh);                                //~v05GI~
            dlcmdupctr(plh);                                    //~v04jI~
//          pfh=UGETPFH(plh);                                      //~v54mR~
            pcw=pfh->UFHbrowsepcw[0];                              //~v09bR~
            if (pcw)                                               //~v09bI~
                dlcfsiupdate(pcw); //update free space info        //~v09bI~
            pcw=pfh->UFHbrowsepcw[1];                              //~v09bR~
            if (pcw)                                               //~v09bI~
                dlcfsiupdate(pcw); //update free space info        //~v09bI~
        }                                                       //~v05GI~
#ifdef FTPSUPP                                                     //~v54mI~
        else                                                       //~v54mI~
            if (FILEISREMOTE(pfh))                                 //~v54mI~
              if (FILEISTSO(pfh)==0)                               //~v71aI~
        	    dirresetftpfiletime(pdh,pfh);                      //~v54mI~
#endif                                                             //~v54mI~
//no need to delete(not isrted if new at start)                    //~v10kI~
//        else                                                     //~v10kR~
//            if (UCBITCHK(Ppfc->UFCflag,UFCFCANNEWF))    //saved at end//~v10kR~
//            {                                                    //~v10kR~
//                plhprev=UGETQPREV(plh);                          //~v10kR~
//                dlcdelentry(plh,plhprev); //update free space info//~v10kR~
//                dirrenum(plhprev);  //lineno renumber after this line//~v10kR~
//            }                                                    //~v10kR~
    }                                                           //~v046I~
    return;                                                        //~v09wI~
}//dlcmddeqpfc                                                  //~v046I~
                                                                //~v046I~
//****************************************************************//~v05GI~
// dlcmdresetdata                                               //~v05GR~
//*reset information for updated file                           //~v05GI~
//*parm :pdh                                                    //~v05GI~
//*return:rc                                                    //~v05GI~
//****************************************************************//~v05GI~
int dlcmdresetdata(PUDIRLH Ppdh)                                //~v05GI~
{                                                               //~v05GI~
    FILEFINDBUF3  fstat3;                                       //~v05GI~
    int rc;                                                     //~v05PI~
    UCHAR  fullpathname[_MAX_PATH];                             //~v05GI~
//  ULONG oldsz;                                                   //~v731R~
    FILESZT oldsz;                                                 //~v731I~
    int   swexpanded;                                              //~v60rI~
#ifdef FTPSUPP                                                     //~v71aI~
    PUFILEH pfh;                                                   //~v71aI~
    PULINEH plh;                                                   //~v71aI~
#endif                                                             //~v71aI~
//**********                                                    //~v05GI~
#ifdef FTPSUPP                                                     //~v71aI~
	plh=UGETDIRPLH(Ppdh);                                          //~v71aI~
	pfh=UGETPFH(plh);                                              //~v71aI~
    if (FILEISTSO(pfh))                                            //~v71aI~
    {                                                              //~v71jI~
		UCBITOFF(Ppdh->UDHflag,UDHFDDSETUP);	//request line make//~v71jI~
    	return 0;  //size/timestamp is already set at save         //~v71aI~
    }                                                              //~v71jI~
#endif                                                             //~v71aI~
    if (dlcgetfullname(Ppdh,fullpathname))                      //~v05GI~//~vaitR~
        return 4;                                               //~v05GI~
    rc=filefind(fullpathname,0,&fstat3,FFNODIRMSG);             //~v05PR~
//  if (!rc && rc!=16)  //not file nor dir                         //~v09vR~
    if (rc && rc!=16)   //not file nor dir                         //~v09vI~
        return 4;                                               //~v05GI~
    if (UCBITCHK(Ppdh->UDHupdatetype,UDHUTNOTEXIST))               //~v10rI~
        oldsz=0;                                                   //~v10rI~
    else                                                           //~v10rI~
        oldsz=Ppdh->UDHsize;                                       //~v10rR~
    swexpanded=(Ppdh->UDHtype==UDHTDIREXP); //dirserdatasub2 may change UDHtype//~v60rI~
    dirsetdatasub2(Ppdh,&fstat3);                               //~v05GR~
    if (Ppdh->UDHtype==UDHTDIR)	//yet dir                          //~v60rI~
	    if (swexpanded)                                            //~v60rI~
			Ppdh->UDHtype=UDHTDIREXP; 		//recover              //~v60rI~
    dlcmdresetparentsz(Ppdh,DLCPSZ_SZ,Ppdh->UDHsize-oldsz,0);//update parent sz//~v10rR~
    return rc;  //normal file or dir                            //~v05PR~
}//dlcmdresetdata                                               //~v05GI~
                                                                //~v05GI~
//****************************************************************//~v05oI~
// dlcmdfree                                                    //~v05oI~
// clear view screen                                            //~v05oI~
//*rc   :rc                                                     //~v05oI~
//****************************************************************//~v05oI~
int dlcmdfree(PUCLIENTWE Ppcw,PUDLCMD Pplc,PUDLCMD Pplcdummy)   //~v05oI~
{                                                               //~v05oI~
    PULINEH plh;                                                //~v05oI~
    PUDIRLH pdh;                                                //~v05oM~
    PUFILEC pfc;                                                //~v05oM~
//*******************                                           //~v05oI~
    plh=Pplc->UDLCplh;                                          //~v05oI~
    pdh=UGETPDH(plh);                                           //~v05oI~
//  if (!(pfc=UDEQ(UQUE_TOP,&pdh->UDHviewqh,0)))    //enqued pfc   //~v09vR~
    if (!(pfc=UGETQTOP(&pdh->UDHviewqh)))   //top pfc              //~v09vI~
    {                                                           //~v05oM~
        uerrmsg("It is not viewed",                             //~v05oM~
                "View されていません");                         //~v05oM~
        return 4;                                               //~v05oM~
    }                                                           //~v05oM~
    return dlcmdfreesub(Ppcw,pfc);                              //~v05oI~
}//dlcmdfree                                                    //~v05oI~
                                                                //~v05oI~
//****************************************************************//~v046I~
// dlcmdfreesub                                                 //~v05oR~
// clear view screen                                            //~v046I~
//parm1:pcw                                                     //~v05oI~
//parm2:pfc                                                     //~v05oI~
//*rc   :rc                                                     //~v046I~
//****************************************************************//~v046I~
int dlcmdfreesub(PUCLIENTWE Ppcw,PUFILEC Ppfc)                  //~v05oR~
{                                                               //~v046I~
    PUCLIENTWE pcw;                                             //~v046I~
    int rc;                                                     //~v04lI~
//*******************                                           //~v046I~
    pcw=Ppfc->UFCpcw;                                           //~v05oR~
    Gscrcurclient=pcw->UCWsplitid;  //enq to top of that split  //~v046I~
    scrpopup(pcw,0);    //popup to top                          //~v046R~
    if (pcw->UCWtype==UCWTFILE)                                 //~v04lI~
        rc=func_end_file(pcw);                                  //~v04lR~
    else                                                        //~v04lI~
        rc=func_end_dir(pcw);                                   //~v04lI~
    if (rc)                                                     //~v04lI~
        return rc;                                              //~v04lR~
    csrrestore(Ppcw);   //restore previous cursor pos           //~v046I~
    return 0;                                                   //~v046I~
}//dlcmdfreesub                                                 //~v05oR~
                                                                //~v046I~
//****************************************************************//~5917I~
// dlcmdcd                                                      //~5917I~
// set current dir                                              //~5917I~
//*ret   :rc                                                    //~5917I~
//****************************************************************//~5917I~
int dlcmdcd(PUCLIENTWE Ppcw,PUDLCMD Pplc,PUDLCMD Pplcdummy)     //~5917I~
{                                                               //~5917I~
    PULINEH plh;                                                //~5917I~
    PUDIRLH pdh;                                                //~5917I~
#ifdef FTPSUPP                                                     //~v54rI~
    PUFILEH pfh;                                                   //~v54rR~
#endif                                                             //~v54rI~
    int pathlen;                                                //~5917I~
    UCHAR   dirname[_MAX_PATH]; //fullpath name                 //~5917R~
//****************************                                  //~5917I~
    plh=Pplc->UDLCplh;                                          //~5917I~
#ifdef FTPSUPP                                                     //~v54rI~
    pfh=UGETPFH(plh);                                              //~v54rI~
#endif                                                             //~v54rI~
    pdh=UGETPDH(plh);                                           //~5917I~
    if (dlcgetfullname(pdh,dirname))                            //~v05GR~
        return 4;                                               //~5917I~
    if (pdh->UDHtype==UDHTFILE)                                 //~5917M~
    {                                                           //~5917I~
#ifdef FTPSUPP                                                     //~v71aI~
      if (FILEISTSO(pfh))                                          //~v71aI~
    	u3270parentdsn(U3PL_PARENTORDROPMEMBER,dirname,dirname);//0:parent path//~v71aI~
      else                                                         //~v71aI~
      {                                                            //~v71aI~
#endif                                                             //~v71aI~
        pathlen=PATHLEN(dirname);                               //~5917I~
        *(dirname+pathlen)=0;                                   //~5917I~
        if (!ROOTDIR(dirname))                                  //~5917I~
           *(dirname+pathlen-1)=0;                              //~5917I~
#ifdef FTPSUPP                                                     //~v71aI~
      }                                                            //~v71aI~
#endif                                                             //~v71aI~
    }                                                           //~5917I~
    Ppcw->UCWopdpot=            //single parm                      //~v091I~
    Ppcw->UCWparm=dirname;                                      //~5917I~
#ifdef FTPSUPP                                                     //~v54rI~
  if (!FILEISREMOTE(pfh))                                          //~v54rI~
#endif                                                             //~v54rI~
#ifndef UNX                                                        //~v196I~
    if (dcmd_drive(Ppcw))   //use only drive letter on UCWparm  //~5917R~
        return 4;                                               //~5917I~
#endif //! UNX                                                     //~v196I~
    filesetcsr(Ppcw,plh,PANL310LINENO,0);//set csr              //~v05rI~
    return dcmd_cd(Ppcw);                                       //~5917I~
}//dlcmdcd                                                      //~5917I~
                                                                //~5917I~
//****************************************************************//~v04bI~
// dlcmdexpandall                                               //~v04bI~
// process expandall(>) dlcmd                                   //~v04bI~
//*ret   :rc                                                    //~v04bI~
//****************************************************************//~v04bI~
int dlcmdexpandall(PUCLIENTWE Ppcw,PUDLCMD Pplc,PUDLCMD Pplcdummy)//~v04bI~
{                                                               //~v04bI~
    int rc;                                                     //~v04bI~
#ifdef FTPSUPP                                                     //~v71aI~
    PUFILEC pfc;                                                   //~v71aI~
    PUFILEH pfh;                                                   //~v71aI~
#endif                                                             //~v71aI~
//****************************                                  //~v04bI~
#ifdef FTPSUPP                                                     //~v71aI~
    pfc=Ppcw->UCWpfc;                                              //~v71aI~
    pfh=pfc->UFCpfh;                                               //~v71aI~
    if (FILEISTSO(pfh))                                            //~v71aI~
        return errnotsupported(">(ExpandAll)","TSO PDS");          //~v71aR~
#endif                                                             //~v71aI~
    Sexpandallsw=1;                                             //~v04bI~
    Sexpandallerr=0;                                            //~v04bI~
    rc=dlcmdexpand(Ppcw,Pplc,Pplcdummy);                        //~v04bI~
    Sexpandallsw=0;                                             //~v04bI~
    if (!rc)                                                    //~v04bI~
        if (Sexpandallerr)                                      //~v04bR~
            ubell();                                            //~v04bI~
    return rc;                                                  //~v04bI~
}//dlcmdexpandall                                               //~v04bI~
//**************************************************************** //~v152I~
// refresh cmd                                                     //~v152I~
//*ret   :rc                                                       //~v152I~
//**************************************************************** //~v152I~
int func_dlcmdrefresh(PUCLIENTWE Ppcw)                             //~v152I~
{                                                                  //~v152I~
    PUFILEC pfc;                                                   //~v152I~
    PUFILEH pfh;                                                   //~v152I~
    PULINEH plh,plh0;                                              //~v152I~
    PUDIRLH pdh;                                                   //~v152I~
    int rc=0;                                                      //~v152I~
    int level,levelmax,levelf;                                     //~v152R~
//****************************                                     //~v152I~
    pfc=Ppcw->UCWpfc;                                              //~v152I~
    pfh=pfc->UFCpfh;                                               //~v152I~
    plh0=UGETQTOP(&pfh->UFHlineque);                               //~v152I~
    levelf=pfh->UFHlevel;                                          //~v152I~
//get lowest level                                                 //~v152I~
    for (plh=plh0,levelmax=levelf;plh;plh=UGETQNEXT(plh))          //~v152R~
    {                                                              //~v152I~
        if (plh->ULHtype!=ULHTDATA) //file data                    //~v152I~
            continue;                                              //~v152I~
        pdh=UGETPDH(plh);                                          //~v152I~
        UCBITON(pdh->UDHflag2,UDHF2REFRESH);//description may re-read//~v690R~
        level=(int)pdh->UDHlevel;                                  //~v152R~
        if (pdh->UDHtype==UDHTDIREXP                               //~v152R~
        &&  level>levelmax      //srch lowest                      //~v152I~
        &&  !UCBITCHK(pdh->UDHflag,UDHFEXCLUDED))//not excluded    //~v152I~
            levelmax=(int)pdh->UDHlevel;                           //~v152R~
    }                                                              //~v152I~
//expand from lowest                                               //~v152I~
    for (level=levelmax;level>=levelf;level--)                     //~v152R~
    {                                                              //~v152I~
        for (plh=plh0;plh;plh=UGETQNEXT(plh))                      //~v152R~
        {                                                          //~v152I~
            if (plh->ULHtype!=ULHTDATA) //file data                //~v152I~
                continue;                                          //~v152I~
            pdh=UGETPDH(plh);                                      //~v152I~
            if (UCBITCHK(pdh->UDHflag,UDHFEXCLUDED))//excluded     //~v152I~
                continue;                                          //~v152I~
            if ((int)pdh->UDHlevel!=level)                         //~v152R~
                continue;                                          //~v152I~
            if (level==levelf                                      //~v152R~
            ||  pdh->UDHtype==UDHTDIREXP)                          //~v152I~
                if (rc=dlcmdrefreshsub(Ppcw,plh,pdh),rc)           //~v152R~
                {                                                  //~v485I~
//                  break;                                         //~v485R~
					rc=0;		//ignore deleted                   //~v485I~
                    continue;                                      //~v485I~
                }                                                  //~v485I~
        }                                                          //~v152I~
        if (rc)                                                    //~v152I~
            break;                                                 //~v152I~
    }                                                              //~v152I~
    UCBITON(Ppcw->UCWflag,UCWFDRAW);    //full redraw              //~v152I~
    dirrenum(plh0); //lineno renumber from next of this line       //~v152I~
    return rc;                                                     //~v152I~
}//func_dlcmdrefresh                                               //~v152I~
//****************************************************************//~v04bI~
// dlcmdexpand                                                  //~v04bI~
// process expand dlcmd                                         //~v04bI~
//*ret   :rc                                                    //~v04bI~
//****************************************************************//~v04bI~
int dlcmdexpand(PUCLIENTWE Ppcw,PUDLCMD Pplc,PUDLCMD Pplcdummy) //~v04bI~
{                                                               //~v04bI~
    PULINEH plh;                                                //~v04bI~
    PUFILEH pfh;                                                //~v04bI~
    PUDIRLH pdh;                                                //~v04bI~
    UCHAR   dirname[_MAX_PATH]; //for udirlist                  //~v04bI~
//  UCHAR   filemask[PANL310MASKLEN]; //getflddata                 //~v09hR~
//  UCHAR   filemask[PANL310MASKLEN+1]; //getflddata               //~v57fR~
    UCHAR   filemask[_MAX_PATH]; //getflddata                      //~v57fI~
    int parentsw;                                               //~v05KI~
//  ULONG  oldsz;                                                  //~v731R~
     FILESZT oldsz;                                                //~v731I~
     LONG  oldlc;                                                  //~v10rI~
//****************************                                  //~v04bI~
    plh=Pplc->UDLCplh;                                          //~v04bI~
    pfh=UGETPFH(plh);                                           //~v04bI~
    pdh=UGETPDH(plh);                                           //~v04bI~
    if (pdh->UDHtype==UDHTFILE)                                 //~v04bI~
    {                                                           //~v05HI~
        dirsetflddata(Ppcw,plh,PANL310RENAME,"");               //~v05HI~
        return  dlcmdresetdata(pdh);                            //~v05HI~
    }                                                           //~v05HI~
    if (dlcgetfullname(pdh,dirname))                            //~v05GR~
        return 4;                                               //~v04bI~
//  if (dirgetflddata(Ppcw,plh,PANL310RENAME,filemask)<0)  //fld len//~v47aR~//~va00R~
#ifdef W32UNICODE                                                  //~vawpI~
//  if (!dirgetflddata_l2f(DGFDL2FO_UD,Ppcw,plh,PANL310RENAME,filemask,NULL/*swl2f*/))//len=0//~vawpI~//~vb16R~
    if (dirgetflddata_l2f(DGFDL2FO_UD,Ppcw,plh,PANL310RENAME,filemask,NULL/*swl2f*/)<0)//len=0//~vb16I~
#else                                                              //~vawpI~
    if (BYUTF8_dirgetflddata(Ppcw,plh,PANL310RENAME,filemask)<0)  //fld len//~va00I~
#endif                                                             //~vawpI~
        return 4;   //internal logic err                           //~v47aR~
    oldsz=pdh->UDHsize; //save for parent size update              //~v10rI~
    oldlc=plh->ULHlinenow;//save for parent linecnt update         //~v10rI~
    if (Sexpandallsw)                                           //~v04bI~
        dlcmdlvlclear(Ppcw,pdh,1,0);//force clear under the level//~v05oR~
    else                                                        //~v04bI~
    {                                                              //~v57fI~
        if (UCBITCHK(pdh->UDHflag,UDHFEXCLUDED))//excluded      //~v04bR~
            if (dlcmdunexclude(Ppcw,Pplc,Pplcdummy))            //~v04bR~
                return 4;                                       //~v04bR~
    }                                                              //~v57fI~
    parentsw=(pdh->UDHtype==UDHTPARENT);                        //~v05KI~
    if (dlcmdexpand1(Ppcw,plh,dirname,filemask))                //~v04bI~
        return 4;                                               //~v04bI~
    if (parentsw)                   //expand set direxpand id   //~v05KI~
    {                                                              //~vbq5I~
        UTRACEP("%s:set UDHTPARENT dhname=%s\n",UTT,pdh->UDHname); //~vbq5I~
        pdh->UDHtype=UDHTPARENT;    //recov parent id           //~v05KI~
    }                                                              //~vbq5I~
    if (pdh->UDHlevel<=pfh->UFHlevel)   //path up               //~v04bI~
        dlcchngfh(Ppcw,pfh,pdh,dirname);//change pfh filename   //~v04bR~
    dlcmdsetszorlc(Ppcw,plh,UCBITCHK(pdh->UDHflag2,UDHF2DISPLC)!=0);//1:lc,0:sz//~v10rI~
    dlcmdresetparentsz(pdh,DLCPSZ_SZ|DLCPSZ_LC,                    //~v10rR~
                        pdh->UDHsize-oldsz,plh->ULHlinenow-oldlc);//update parent sz//~v10rI~
    UCBITON(Ppcw->UCWflag,UCWFDRAW);    //full redraw           //~v04bI~
    filesetcsr(Ppcw,plh,PANL310LINENO,0);//set csr              //~v04bI~
    dirrenum(plh);  //lineno renumber from next of this line    //~v04bI~
    return 0;                                                   //~v04bI~
}//dlcmdexpand                                                  //~v04bI~
//**************************************************************** //~v57jR~
// dlcmdexpandbysort                                               //~v57jR~
// process dirlist sort cmd                                        //~v57jR~
//*ret   :rc                                                       //~v57jR~
//**************************************************************** //~v57jR~
int dlcmdexpandbysort(PUCLIENTWE Ppcw,char *Psortopt)              //~v57jR~
{                                                                  //~v57jR~
    PUFILEC pfc;                                                   //~v57jR~
    PUFILEH pfh;                                                   //~v57jR~
    PULINEH plh,plhp=NULL;                                              //~v57jR~//~vafcR~
    PUDIRLH pdh,pdhp=NULL;                                              //~v57jR~//~vafcR~
    UCHAR   dirname[_MAX_PATH]; //for udirlist                     //~v57jR~
    UCHAR   filemask[_MAX_PATH+8]; //for udirlist                  //~v58tI~
    char *pc;                                                      //~v59MI~
//****************************                                     //~v57jR~
  	pfc=Ppcw->UCWpfc;                                              //~v57jR~
  	pfh=pfc->UFCpfh;                                               //~v57jR~
#ifdef FTPSUPP                                                     //~v71aI~
    if (FILEISTSO(pfh))                                            //~v71aI~
        return errnotsupported("SORt","TSO PDS");                  //~v71aI~
#endif                                                             //~v71aI~
	for (plh=UGETQTOP(&pfh->UFHlineque);plh;plh=UGETQNEXT(plh))    //~v57jR~
	{                                                              //~v57jR~
		if (plh->ULHtype!=ULHTDATA)	//file data                    //~v57jR~
            continue;                                              //~v57jR~
    	pdh=UGETPDH(plh);                                          //~v57jR~
        if (pdh->UDHtype==UDHTPARENT)                              //~v57jR~
        {                                                          //~v57jR~
        	plhp=plh;	//parent plh for size/time search          //~v57jR~
            pdhp=pdh;                                              //~v57jR~
        }                                                          //~v57jR~
        else                                                       //~v57jR~
        	break;                                                 //~v57jR~
    }                                                              //~v57jR~
    if (dlcgetfullname(pdhp,dirname))                              //~v57jR~
        return 4;                                                  //~v57jR~
    if (UCBITCHK(pdhp->UDHflag,UDHFEXCLUDED))//excluded            //~v57jR~
    {                                                              //~v57jR~
    	uerrmsg("path excluded",0);                                //~v57jR~
        return 4;                                                  //~v57jR~
    }                                                              //~v57jR~
    if (UCBITCHK(pdhp->UDHflag2,UDHF2MASKNAME)                     //~v58tI~
    &&  !UCBITCHK(pdhp->UDHupdatetype,UDHUTNOTEXIST)               //~v58tI~
    &&  pdhp->UDHrenamesv && *pdhp->UDHrenamesv)                   //~v58tR~
    {                                                              //~v59MI~
      if (pdhp->UDHsortopt)   //previous sort option               //~v59NR~
      {                                                            //~v59NR~
          pc=strrchr(pdhp->UDHrenamesv,' ');                       //~v59NR~
          if (pc && *(pc+1)=='/' && *(pc+2)=='o')                  //~v59NR~
          {                                                        //~v59NR~
              *pc=0;                                               //~v59NR~
#ifdef UTF8SUPPH                                                   //~va00R~
              pc=pdhp->UDHrenamesvbyutf8;                          //~va00R~
              if (pc)	//utf8 code exist                          //~va00R~
              {                                                    //~va00R~
		          pc=strrchr(pc,' ');   //clear also utf8 code     //~va00I~
                  if (pc)                                          //~va00I~
                  	*pc=0;                                         //~va00I~
              }                                                    //~va00I~
#endif                                                             //~va00I~
//            sprintf(filemask,"%s %s",pdhp->UDHrenamesv,Psortopt);//~v59NR~//~va00R~
            if (*Psortopt)                                         //~va09R~
              sprintf(filemask,"%s %s",PDH_UDHrenamesv(pdhp),Psortopt);//~va00I~
            else                                                   //~va09I~
              sprintf(filemask,"%s",PDH_UDHrenamesv(pdhp));        //~va09I~
          }                                                        //~v59NR~
          else                                                     //~v59NR~
              sprintf(filemask,"%s",Psortopt);                     //~v59NR~
      }                                                            //~v59NR~
      else                                                         //~v59NR~
//      sprintf(filemask,"%s %s",pdhp->UDHrenamesv,Psortopt);      //~v58tR~//~va00R~
        sprintf(filemask,"%s %s",PDH_UDHrenamesv(pdhp),Psortopt);  //~va00I~
    }                                                              //~v59NR~
    else                                                           //~v58tI~
    	strcpy(filemask,Psortopt);                                 //~v58tI~
//  if (dlcmdexpand1(Ppcw,plhp,dirname,Psortopt))                  //~v58tR~
    if (dlcmdexpand1(Ppcw,plhp,dirname,filemask))                  //~v58tI~
        return 4;                                                  //~v57jR~
    UTRACEP("%s:set UDHTPARENT to pdhp dhname=%s\n",UTT,pdhp->UDHname);//~vbq5I~
    pdhp->UDHtype=UDHTPARENT;    //recov parent id                 //~v57jR~
	dirrenum(plhp);                                                //~v59WI~
    UCBITON(Ppcw->UCWflag,UCWFDRAW);    //full redraw              //~v57jR~
    return 0;                                                      //~v57jR~
}//dlcmdexpandbysort                                               //~v57jR~
//**************************************************************** //~v152I~
// dlcmdrefreshsub                                                 //~v152R~
// expand by refresh cmd                                           //~v152R~
//*ret   :rc                                                       //~v152I~
//**************************************************************** //~v152I~
int dlcmdrefreshsub(PUCLIENTWE Ppcw,PULINEH Pplh,PUDIRLH Ppdh)     //~v152R~
{                                                                  //~v152I~
    UCHAR   dirname[_MAX_PATH]; //for udirlist                     //~v152I~
//  UCHAR   filemask[PANL310MASKLEN+1]; //getflddata               //~v47aR~
    UCHAR   filemask[_MAX_PATH]; //for udirlist                    //~v47aI~
    int parentsw;                                                  //~v152I~
//  ULONG  oldsz;                                                  //~v731R~
     FILESZT oldsz;                                                //~v731I~
     LONG  oldlc;                                                  //~v152I~
//****************************                                     //~v152I~
    if (dlcgetfullname(Ppdh,dirname))                              //~v152I~
        return 4;                                                  //~v152I~
    oldsz=Ppdh->UDHsize; //save for parent size update             //~v152I~
    oldlc=Pplh->ULHlinenow;//save for parent linecnt update        //~v152I~
    parentsw=(Ppdh->UDHtype==UDHTPARENT);                          //~v152R~
//  if (dlcmdexpand1(Ppcw,Pplh,dirname,""))                        //~v20QR~
//  if (dirgetflddata(Ppcw,Pplh,PANL310RENAME,filemask)<0)  //fld len//~v47aR~
//      return 4;   //internal logic err                           //~v47aR~
    if (UCBITCHK(Ppdh->UDHflag2,UDHF2MASKNAME)                     //~v47aR~
    &&  !UCBITCHK(Ppdh->UDHupdatetype,UDHUTNOTEXIST)               //~v57aI~
    &&  Ppdh->UDHrenamesv && *Ppdh->UDHrenamesv)                   //~v47aR~
//  	strcpy(filemask,Ppdh->UDHrenamesv);                        //~v47aR~//~va00R~
        strcpy(filemask,PDH_UDHrenamesv(Ppdh));                    //~va00R~
    else                                                           //~v47aI~
    	*filemask=0;                                               //~v47aI~
    Srefreshsw=1;                                                  //~v485I~
    if (dlcmdexpand1(Ppcw,Pplh,dirname,filemask))                  //~v20QI~
    {                                                              //~v485I~
    	Srefreshsw=0;                                              //~v485I~
    	if (parentsw)                   //expand set direxpand id  //~v57bI~
        {                                                          //~vbq5I~
	        UTRACEP("%s:set UDHTPARENT dhname=%s\n",UTT,Ppdh->UDHname);//~vbq5I~
        	Ppdh->UDHtype=UDHTPARENT;   //recov parent id          //~v57bI~
        }                                                          //~vbq5I~
        return 4;                                                  //~v152I~
    }                                                              //~v485I~
    Srefreshsw=0;                                                  //~v485I~
    dlcmdresetdata(Ppdh);			//set new data(it may be mkdir'ed after del)//~v57cM~
    UCBITOFF(Ppdh->UDHupdatetype,UDHUTNOTEXIST);    //clear del/move/rename//~v57cM~
    if (parentsw)                   //expand set direxpand id      //~v152I~
    {                                                              //~vbq5I~
	    UTRACEP("%s:set UDHTPARENT dhname=%s\n",UTT,Ppdh->UDHname);//~vbq5I~
        Ppdh->UDHtype=UDHTPARENT;   //recov parent id              //~v152R~
    }                                                              //~vbq5I~
    dlcmdsetszorlc(Ppcw,Pplh,UCBITCHK(Ppdh->UDHflag2,UDHF2DISPLC)!=0);//1:lc,0:sz//~v152I~
    dlcmdresetparentsz(Ppdh,DLCPSZ_SZ|DLCPSZ_LC,                   //~v152I~
                        Ppdh->UDHsize-oldsz,Pplh->ULHlinenow-oldlc);//update parent sz//~v152I~
    return 0;                                                      //~v152I~
}//dlcmdrefreshsub                                                 //~v152R~
//****************************************************************//~v04bI~
// dlcmdexpand1                                                 //~v04bI~
// process expand 1 directory                                   //~v04bI~
//*parm1:pcw                                                    //~v04bI~
//*parm2:plh                                                    //~v04bI~
//*parm3:dir name                                               //~v04bI~
//*parm4:file selection mask                                    //~v04bI~
//*ret   :rc                                                    //~v04bI~
//****************************************************************//~v04bI~
int dlcmdexpand1(PUCLIENTWE Ppcw,PULINEH Pplh,                  //~v04bI~
                        UCHAR *Pdirname,UCHAR *Pfilemask)       //~v04bI~
{                                                               //~v04bI~
    PUDIRLIST pudirlist;                                        //~v04bI~
    PUDIRLH pdh;                                                //~v04bI~
    PUFILEH pfh;                                                   //~v0frI~
    PULINEH plhn,plhw,plh;                                      //~v04bR~
    int     filectr,len,len2,pathlen;                           //~v04bR~
    int refresherrsw=0;                                            //~v57bI~
    int opt;                                                       //~v57fI~
    UCHAR   filemask[_MAX_PATH]; //for udirlist                    //~v57fI~
    int sortopt;                                                   //~v57fI~
#ifdef FTPSUPP                                                     //~v71aI~
    int membopt;                                                   //~v71aI~
#endif                                                             //~v71aI~
	int swFileMask=0;                                              //~vbBvI~
//****************************                                  //~v04bI~
    pdh=UGETPDH(Pplh);                                          //~v04bI~
    pfh=UGETPFH(Pplh);                                             //~v0frI~
    strcpy(filemask,Pfilemask);                                    //~v57fI~
    if (dlcmdgetexpopt(filemask,&sortopt))                         //~v57fM~
        return 4;   //internal logic err                           //~v57fM~
//  if (sortopt!=pdh->UDHsortopt)                                  //~v57jR~
    if (sortopt!=pdh->UDHsortopt||sortopt)//changed or not by name //~v57jR~
    {                                                              //~v57fI~
        dlcmdlvlclear(Ppcw,pdh,1,0);//force clear under the level  //~v57fI~
        pdh->UDHsortopt=(UCHAR)sortopt;                            //~v57jR~
    }                                                              //~v57fI~
#ifdef FTPSUPP                                                     //~v71aI~
  if (FILEISTSO(pfh))                                              //~v71aI~
  {                                                                //~v71aI~
    if (*filemask)  //mask specified                               //~v71aI~
    {                                                              //~v71aI~
    	if (pdh->UDHattr & FILE_DIRECTORY)                         //~v71aI~
        	membopt=1;                                             //~v71aI~
        else                                                       //~v71aI~
        	membopt=0;                                             //~v71aI~
  		if (u3270concatfilename(membopt,Pdirname,filemask,Pdirname)<0)//~v71aR~
    		return 4;                                              //~v71aR~
    }                                                              //~v71aI~
  }                                                                //~v71aI~
  else                                                             //~v71aI~
  {                                                                //~v71aI~
#endif                                                             //~v71aI~
    len=(int)strlen(Pdirname);                                  //~v04bI~
//  len2=(int)strlen(Pfilemask);                                   //~v57fR~
    len2=(int)strlen(filemask);                                    //~v57fI~
    if (len2)   //mask input len                                //~v04bI~
    {                                                           //~v04bI~
    	swFileMask=1;                                              //~vbBvI~
        if ((len+len2+1)>=_MAX_PATH)                            //~v04bI~
//          return errtoolong();                                   //~vb7aR~
            return ufileTooLongFullpathName(4/*rc*/);              //~vb7aI~
        if (pdh->UDHlevel)                                      //~v04bI~
//          *(Pdirname+len++)='\\';                                //~v19aR~
//          *(Pdirname+len++)=DIR_SEPC;                            //~v540R~
            *(Pdirname+len++)=pfh->UFHdirsepc;                     //~v540I~
//      strcpy(Pdirname+len,Pfilemask);                            //~v57fR~
        strcpy(Pdirname+len,filemask);                             //~v57fI~
        len+=len2;                                              //~v04bI~
    }                                                           //~v04bI~
    else                                                        //~v04bI~
    {                                                           //~v04bI~
        if ((len+4+1)>=_MAX_PATH)                               //~v04bI~
//          return errtoolong();                                   //~vb7aR~
            return ufileTooLongFullpathName(4/*rc*/);              //~vb7aI~
        if (pdh->UDHlevel)                                      //~v04bI~
        {                                                          //~v540I~
//          strcpy(Pdirname+len,"\\*.*");                          //~v19aR~
//          strcpy(Pdirname+len,DIR_SEPS "*.*");                   //~v19VR~
//          strcpy(Pdirname+len,DIR_SEPS DIR_ALLMEMB);             //~v540R~
            *(Pdirname+len)=pfh->UFHdirsepc;                       //~v540I~
            strcpy(Pdirname+len+1,DIR_ALLMEMB);                    //~v540I~
        }                                                          //~v540I~
        else    //root                                          //~v04bI~
//          strcpy(Pdirname+len,"*.*");                            //~v19VR~
            strcpy(Pdirname+len,DIR_ALLMEMB);                      //~v19VI~
    }                                                           //~v04bI~
#ifdef FTPSUPP                                                     //~v71aI~
  }                                                                //~v71aI~
#endif                                                             //~v71aI~
//  dirsetflddata(Ppcw,Pplh,PANL310RENAME,Pfilemask);  //drop pre space//~v04bM~//~va00R~
//  BYUTF8_dirsetflddata(Ppcw,Pplh,PANL310RENAME,Pfilemask);  //drop pre space//~va00I~//~va0GR~
    dirsetflddata(Ppcw,Pplh,PANL310RENAME,Pfilemask);  //drop pre space//~va0GI~//~vawpR~
//  dirsetflddataDDFMT2(Ppcw,Pplh,PANL310RENAME,Pfilemask);  //drop pre space//~vawpR~
//  filectr=dirgetlist(pfh,Pdirname,0,&pudirlist);//name seq       //~v57fR~
	opt=pdh->UDHsortopt<<8;                                        //~v57fI~
    filectr=dirgetlist(pfh,Pdirname,(UINT)opt,&pudirlist);//name seq//~v57jR~
    if (filectr<0)  //err                                       //~v04bI~
    {                                                           //~v04bI~
//    if (Srefreshsw)                                              //~v71tR~
      if (Srefreshsw                                               //~v71tI~
      &&  UCBITCHK(pdh->UDHupdatetype,UDHUTNOTEXIST))              //~v71tR~
      {                                                            //~v485I~
		ugeterrmsg();           //clear notfound msg               //~v485I~
//    	return 1;	//no errmsg                                    //~v57bR~
        pudirlist=0;                                               //~v57bI~
        filectr=0;  //parm to lvlmerge(avoid abend)                //~v57bI~
        refresherrsw=1;                                            //~v57bI~
      }                                                            //~v485I~
      else                                                         //~vbBvI~
      {                                                            //~v57bI~
      	if (Srefreshsw                                             //+vbBvI~
      	&&  swFileMask)                                            //+vbBvI~
      	{                                                          //+vbBvI~
        	UTRACEP("%s:refresh filemask=%s not found, level clear\n",UTT,filemask);//+vbBvI~
	        dlcmdlvlclear(Ppcw,pdh,1,0);    //clear all child      //+vbBvI~
	    }                                                          //+vbBvI~
        dirsetflderr(Ppcw,Pplh,PANL310RENAME);//reverse err fld //~v04bI~
        return 4;                                               //~v04bI~
      }                                                            //~v57bI~
    }                                                           //~v04bR~
    pdh->UDHtype=UDHTDIREXP;                                    //~v04bM~
    UCBITOFF(Pplh->ULHflag,ULHFHLDIRTYPE);//highlight of parent unexp//~v05KR~
    UCBITOFF(pdh->UDHflag,UDHFLCMDIN2|UDHFMASK|UDHFDDSETUP);    //~v04bM~
    UCBITON(pdh->UDHflag2,UDHF2MASKNAME);                          //~v47aI~
//  if (dirsavename(Pplh,Pfilemask))                            //~v05FR~//~va00R~
//  if (BYUTF8_dirsavename(Pplh,Pfilemask))                        //~va0GR~
    if (dirsavename(Pplh,Pfilemask))                               //~va0GR~//~vawpR~
//  if (dirsavenameDDFMT2(0,Pplh,Pfilemask))                       //~vawpR~
#ifdef UTF8SUPPH                                                    //~v75JI~//~va00R~
	{                                                              //~v75JI~//~va00I~
  		if (pudirlist)                                             //~v75JI~//~va00I~
//  		ufree(pudirlist);                               //~v75JI~//~va00I~//~vandR~
    		UDIRLIST_FREE(pudirlist);                              //~vandI~
        return 4;                                                  //~v75JI~//~va00I~
    }                                                              //~v75JI~//~va00I~
#else                                                              //~v75JI~//~va00I~
        return 4;                                               //~v05FI~
#endif                                                             //~v75JI~//~va00I~
//enq file data                                                 //~v04bI~
    plhn=UGETQNEXT(Pplh);   //stopper for expand all            //~v04bI~
    dlclvlmerge(Ppcw,pdh,pudirlist,filectr);                    //~v04bI~
    pathlen=PATHLEN(Pdirname);                                  //~v04bI~
    if (Sexpandallsw)   //expand all cmd                        //~v04bI~
    {                                                           //~v04bI~
        plhw=plhn;  //compile warning                           //~v04bR~
        for (plh=UGETQNEXT(Pplh);plh!=plhn;plh=plhw)    //all entry//~v04bR~
        {                                                       //~v04bI~
            pdh=UGETPDH(plh);                                   //~v04bI~
            plhw=UGETQNEXT(plh);    //next before insert        //~v04bI~
            if (pdh->UDHtype==UDHTFILE)                         //~v04bI~
                continue;                                       //~v04bI~
            strcpy(Pdirname+pathlen,pdh->UDHname);              //~v04bR~
            if (dlcmdexpand1(Ppcw,plh,Pdirname,Pfilemask))//ignore err//~v04bR~
            {                                                   //~v04bI~
//avoid input   UCBITON(pdh->UDHflag,UDHFLCMDIN2|UDHFMASK); //rename cmd input//~v04bR~
                Sexpandallerr=1;                                //~v04bR~
            }                                                   //~v04bI~
            if (*Pfilemask)                                        //~v47aI~
                UCBITON(pdh->UDHflag,UDHFMASK); //rename cmd input //~v47aI~
        }                                                       //~v04bI~
    }                                                           //~v04bI~
  if (pudirlist)                                                   //~v57bI~
//  ufree(pudirlist);                                           //~v04bI~//~vandR~
    UDIRLIST_FREE(pudirlist);                                      //~vandI~
#ifdef FTPSUPP                                                     //~v71aI~
  if (FILEISTSO(pfh))                                              //~v71aI~
    u3270parentdsn(0,Pdirname,Pdirname);//0:parent path            //~v71aI~
  else                                                             //~v71aI~
  {                                                                //~v71aI~
#endif                                                             //~v71aI~
    *(Pdirname+pathlen)=0;   //file name on pfh       //~v04bR~
    if (!ROOTDIR(Pdirname))                                     //~v04bI~
        *(Pdirname+pathlen-1)=0;   //file name on pfh          //~v04bI~
#ifdef FTPSUPP                                                     //~v71aI~
  }                                                                //~v71aI~
#endif                                                             //~v71aI~
    if (refresherrsw)                                              //~v57bI~
    	return 1;                                                  //~v57bI~
    return 0;                                                   //~v04bR~
}//dlcmdexpand1                                                 //~v04bI~
                                                                //~v04bI~
//**************************************************************** //~v57fM~
// dlcmdgetexpopt                                                  //~v57fM~
// get expand sort option                                          //~v57fM~
//*ret   :rc                                                       //~v57fM~
//**************************************************************** //~v57fM~
int dlcmdgetexpopt(char *Pparm,int *Ppsortopt)                     //~v57fM~
{                                                                  //~v57fM~
    char    *posparm,*pflagparm[1],*psortopt;                      //~v57jR~
    char   pot[MAXCOLUMN],*ppot,*pc;                               //~v57jR~
    int sortopt,opdno,reversesw=0;                                 //~v57fM~
    PUPODELMTBL pdelmt;                                            //~v57fM~
//****************************                                     //~v57fM~
	*Ppsortopt=UDHSONAME;                                          //~v57fM~
    if (!*Pparm)                                                   //~v57fM~
    	return 0;                                                  //~v57fM~
    ppot=pot;                                                      //~v57fM~
    if (uparsecmd(UPCMD_DROPQ,Pparm,&opdno,&ppot,0,&pdelmt))       //~v57fM~
        return 4;                                                  //~v57fM~
	if (uparsegetopt(UPGO_NOCASE|UPGO_ERRMSG|UPGO_FLAGUNIX|UPGO_FLAGDOS|UPGO_NOSPLIT,//~v57fM~
						pot,&opdno,"o",&posparm,pflagparm)) //drop /o option value//~v57fM~
    	return 4;                                                  //~v57fM~
    psortopt=pflagparm[0];                                         //~v57fM~
    if (!psortopt)	//no /o option                                 //~v57fM~
    {                                                              //~v57fM~
        if (pdelmt->upoquate=='\''                                 //~v57fM~
        ||  pdelmt->upoquate=='\"')                                //~v57fM~
    		strcpy(Pparm,ppot);	//drop quate                       //~v57fM~
    	return 0;                                                  //~v57fM~
    }                                                              //~v57fM~
    if (Sexpandallsw)                                              //~v57fM~
    {                                                              //~v57fM~
    	uerrmsg("sort option(%s) is supported only for \"-\" cmd", //~v57fM~
        		"\x83\\ートオプション(%s)は\"-\"コマンドで使用できます。",//~v57jR~
                psortopt);                                         //~v57fM~
        return 4;                                                  //~v57fM~
    }                                                              //~v57fM~
    sortopt=*psortopt;                                             //~v57fM~
    pc=psortopt;                                                   //~v57jR~
//  if (sortopt=='-')   //reverse                                  //~v59MR~
//  {                                                              //~v59MR~
//      reversesw=1;                                               //~v59MR~
//      sortopt=*(psortopt+1);                                     //~v59MR~
//      pc++;                                                      //~v59MR~
//  }                                                              //~v59MR~
    switch(toupper(sortopt))                                       //~v57fM~
    {                                                              //~v57fM~
    case 'N':                                                      //~v57fM~
    	sortopt=UDHSONAME;                                         //~v57fM~
    	break;                                                     //~v57fM~
    case 'T':                                                      //~v57fM~
    	sortopt=UDHSOTIME;                                         //~v57fM~
    	break;                                                     //~v57fM~
    case 'S':                                                      //~v57fM~
    	sortopt=UDHSOSIZE;                                         //~v57fM~
    	break;                                                     //~v57fM~
    default:                                                       //~v57fM~
        if (sortopt)                                               //~v57fM~
    	    uerrmsg("invalid sort option(%c)",                     //~v57fM~
	                "\x83\\ートオプションエラー(%c)",              //~v57jR~
	                    sortopt);                                  //~v57fM~
        else                                                       //~v57fM~
    	    uerrmsg("invalid sort option(null)",                   //~v57fM~
//                  "\x83\\ートオプションエラー(null)",            //~v77vR~
                    "\x83\\ートオプションエラー(null)");           //~v77vI~
//                      sortopt);                                  //~v77vR~
        return 4;                                                  //~v57fM~
    }                                                              //~v57fM~
    pc++;                                                          //~v57jR~
    if (*pc=='-')   	// "/os-" patern                           //~v57jR~
    {                                                              //~vbq1I~
    	reversesw=1;                                               //~v57jR~
        if (*(pc+1))                                               //~vbq1I~
        {                                                          //~vbq1I~
	    	uerrmsg("invalid sort option(%s)",                     //~vbq1I~
	                "\x83\\ートオプションエラー(%s)",              //~vbq1I~
	                    psortopt);                                 //~vbq1I~
	        return 4;                                              //~vbq1I~
        }                                                          //~vbq1I~
    }                                                              //~vbq1I~
    else                                                           //~vbq1I~
    if (*pc)                                                       //~vbq5I~
    {                                                              //~vbq1I~
    	uerrmsg("invalid sort option(%s)",                         //~vbq1I~
	                "\x83\\ートオプションエラー(%s)",              //~vbq1I~
	                    psortopt);                                 //~vbq1I~
	    return 4;                                                  //~vbq1I~
    }                                                              //~vbq1I~
    if (reversesw)                                                 //~v57fM~
        if (sortopt)                                               //~v57fM~
        	sortopt=sortopt|UDHSOREVERSE;                          //~v57fM~
    *Ppsortopt=sortopt;                                            //~v57fM~
    strcpy(Pparm,posparm);                                         //~v57fM~
    return 0;                                                      //~v57fM~
}//dlcmdgetexpopt                                                  //~v57fM~
//****************************************************************//~5806I~
// dlcmdunexpand                                                //~5806I~
// unexpand(drop all child)                                     //~5813R~
//*ret   :rc                                                    //~5806I~
//****************************************************************//~5806I~
int dlcmdunexpand(PUCLIENTWE Ppcw,PUDLCMD Pplc,PUDLCMD Pplcdummy)//~5806I~
{                                                               //~5806I~
    PULINEH plh;                                                //~5806R~
    PUDIRLH pdh;                                                //~5806R~
//****************************                                  //~5806I~
    plh=Pplc->UDLCplh;                                          //~5806I~
    pdh=UGETPDH(plh);                                           //~5806I~
    switch(pdh->UDHtype)                                        //~5806I~
    {                                                           //~5806I~
    case UDHTDIREXP:                                            //~5812I~
    case UDHTPARENT:                                            //~5813I~
        break;                                                  //~5806I~
    case UDHTDIR:                                               //~v05LI~
        return 4;                                               //~v05LM~
    default:        //file/dir                                  //~5813R~
        return errnotdir();                                     //~v05LI~
    }                                                           //~5806I~
    UCBITON(Ppcw->UCWflag,UCWFDRAW);    //full redraw           //~5807I~
    dirsavename(plh,"");    //clear rename fld                     //~v184I~
    UCBITOFF(pdh->UDHflag,UDHFDDSETUP); //re-setup                 //~v184I~
    filesetcsr(Ppcw,plh,PANL310LINENO,0);//set csr              //~5812I~
    if (pdh->UDHtype==UDHTPARENT)   //not path                  //~v05KR~
        UCBITON(plh->ULHflag,ULHFHLDIRTYPE);//highlight         //~v05KI~
    else                                                        //~v05KI~
    {                                                              //~vbq5I~
        UTRACEP("%s:set UDHTDIR dhname=%s\n",UTT,pdh->UDHname);    //~vbq5I~
        pdh->UDHtype=UDHTDIR;                                   //~v05KR~
    }                                                              //~vbq5I~
    dlcmdlvlclear(Ppcw,pdh,1,0);    //force clear under the level//~v05oR~
    dirrenum(plh);  //lineno renumber after this line           //~v048R~
    return 0;                                                   //~5806I~
}//dlcmdunexpand                                                //~5806I~
                                                                //~5806I~
//****************************************************************//~5813I~
// dlcmdpath                                                    //~5813I~
// drop all brother                                             //~5813I~
//*ret   :rc                                                    //~5813I~
//****************************************************************//~5813I~
int dlcmdpath(PUCLIENTWE Ppcw,PUDLCMD Pplc,PUDLCMD Pplcdummy)   //~5813I~
{                                                               //~5813I~
    PULINEH plh;                                                //~5813I~
    PUFILEH pfh;                                                   //~v540I~
    PUDIRLH pdh;                                                //~5813I~
    int     len,len2;                                           //~5819I~
    UCHAR   dirname[_MAX_PATH];                                 //~5819I~
//  UCHAR   filemask[PANL310MASKLEN]; //getflddata                 //~v09hR~
//  UCHAR   filemask[PANL310MASKLEN+1]; //getflddata               //~v57fR~
    UCHAR   filemask[_MAX_PATH]; //getflddata                      //~v57fI~
//****************************                                  //~5813I~
    plh=Pplc->UDLCplh;                                          //~5813I~
    pfh=UGETPFH(plh);                                              //~v540I~
    pdh=UGETPDH(plh);                                           //~5813I~
    switch(pdh->UDHtype)                                        //~5813I~
    {                                                           //~5813I~
    case UDHTDIREXP:                                            //~5813I~
    case UDHTDIR:                                               //~5813I~
    case UDHTPARENT:                                            //~v05KI~
        if (!pdh->UDHlevel)//root                               //~5813I~
            return 4;                                           //~5813I~
//      if (UGETPDH(plhw)->UDHtype==UDHTPARENT)                 //~v05KR~
//      {                                                       //~v05KR~
//          uerrmsg("Already on the path",                      //~v05KR~
//                  "既に経路上にあります");                    //~v05KR~
//          return 4;                                           //~v05KR~
//      }//for the case intermediate path is expanded(-)        //~v05KR~
        break;                                                  //~5813I~
    default:        //file/path                                 //~5813I~
        return errnotdir();                                     //~v05LR~
    }                                                           //~5813I~
    if (dlcgetfullname(pdh,dirname))                            //~v05GR~
        return 4;                                               //~5819I~
//  if ((len2=dirgetflddata(Ppcw,plh,PANL310RENAME,filemask))<0)  //ufhfilename//~5826R~//~va00R~
    if ((len2=BYUTF8_dirgetflddata(Ppcw,plh,PANL310RENAME,filemask))<0)  //ufhfilename//~va00I~
        return 4;   //internal logic err                        //~5819I~
    if (len2)   //mask input len                                //~5819I~
    {                                                           //~5819I~
        len=(int)strlen(dirname);                               //~5819I~
        if ((len+len2+1)>=_MAX_PATH)                            //~5819I~
//          return errtoolong();                                   //~vb7aR~
            return ufileTooLongFullpathName(4/*rc*/);              //~vb7aI~
//      *(dirname+len++)='\\';                                     //~v19aR~
//      *(dirname+len++)=DIR_SEPC;                                 //~v540R~
        *(dirname+len++)=pfh->UFHdirsepc;                          //~v540I~
        strcpy(dirname+len,filemask);                           //~5819I~
    }                                                           //~5819I~
    UCBITON(Ppcw->UCWflag,UCWFDRAW);    //full redraw           //~5813I~
    filesetcsr(Ppcw,plh,PANL310LINENO,0);//set csr              //~5813I~
    dlcchngfh(Ppcw,UGETPFH(plh),pdh,dirname);                   //~5819I~
    UTRACEP("%s:set UDHTPARENT dhname=%s\n",UTT,pdh->UDHname);     //~vbq5I~
    pdh->UDHtype=UDHTPARENT;    //set on also the line          //~v05KI~
    do                                                          //~5813I~
    {                                                           //~5813I~
        dlcmdlvlclear(Ppcw,pdh,0,0);    //clear brother only    //~v05oR~
        pdh=pdh->UDHdirptr;                                     //~5813I~
	    UTRACEP("%s:set UDHTPARENT dhname=%s\n",UTT,pdh->UDHname); //~vbq5I~
        pdh->UDHtype=UDHTPARENT;                                //~5813I~
        plh=UGETDIRPLH(pdh);        //re-draw dir id            //~5813I~
    } while(pdh->UDHlevel);                                     //~5813I~
    dirrenum(plh);  //lineno renumber from changed path         //~v048R~
    return 0;                                                   //~5813I~
}//dlcmdpath                                                    //~5813I~
                                                                //~5813I~
//****************************************************************//~5806I~
// dlcmdexclude                                                 //~5806I~
// process exclude dlcmd(un-display)                            //~5806I~
//*ret    :rc                                                   //~5806I~
//****************************************************************//~5806I~
int dlcmdexclude(PUCLIENTWE Ppcw,PUDLCMD Pplc,PUDLCMD Pplcdummy)//~5806I~
{                                                               //~5806I~
    PULINEH plh,plht,plh0;                                      //~5806I~
    PUDIRLH pdh;                                                //~5806I~
    PUFILEC pfc;                                                //~5806I~
    int level;                                                  //~5806R~
//****************************                                  //~5806I~
    pfc=Ppcw->UCWpfc;                                           //~5806I~
    plht=pfc->UFCcurtop;                                        //~5806I~
    plh0=Pplc->UDLCplh;                                         //~5806I~
    pdh=UGETPDH(plh0);                                          //~5806I~
    switch(pdh->UDHtype)                                        //~5806I~
    {                                                           //~5806I~
    case UDHTDIREXP:                                            //~5812I~
    case UDHTPARENT:                                            //~v05KI~
        if (UCBITCHK(pdh->UDHflag,UDHFEXCLUDED))                //~5806I~
            return 4;                                           //~5806I~
        break;                                                  //~5806I~
    case UDHTDIR:                                               //~v05LI~
        return 4;                                               //~v05LI~
    default:        //file/parent                               //~5806I~
        return errnotdir();                                     //~v05LI~
    }                                                           //~5806I~
    UCBITON(Ppcw->UCWflag,UCWFDRAW);    //full redraw           //~5807I~
    UCBITON(pdh->UDHflag,UDHFEXCLUDED);                         //~5819R~
    UCBITON(plh0->ULHflag,ULHFHLDIRTYPE);//highlight            //~5819I~
    filesetcsr(Ppcw,plh0,PANL310LINENO,0);//set csr             //~5812R~
    level=pdh->UDHlevel;        //my dir level                  //~5807R~
    for (plh=plh0;plh=UGETQNEXT(plh),plh;)                      //~5807R~
    {                                                           //~5806I~
        if ((int)UGETPDH(plh)->UDHlevel<=level) //higher or same//~5815R~
            break;                                              //~5806I~
        UCBITON(plh->ULHflag2,ULHF2EXCLUDED);   //out of display//~5806R~
        if (plh==plht)                                          //~5806I~
            pfc->UFCcurtop=plh0;                                //~5806I~
    }                                                           //~5806I~
    return 0;                                                   //~5806I~
}//dlcmdexclude                                                 //~5806I~
                                                                //~5806I~
//****************************************************************//~5806I~
// dlcmdunexclude                                               //~5806I~
// process unexclude dlcmd(re-display)                          //~5806I~
//*ret    :rc                                                   //~5806I~
//****************************************************************//~5806I~
int dlcmdunexclude(PUCLIENTWE Ppcw,PUDLCMD Pplc,PUDLCMD Pplcdummy)//~5806I~
{                                                               //~5806I~
    PULINEH plh;                                                //~5806R~
    PUDIRLH pdh;                                                //~5806R~
//****************************                                  //~5806I~
    plh=Pplc->UDLCplh;                                          //~5806I~
    pdh=UGETPDH(plh);                                           //~5806I~
    switch(pdh->UDHtype)                                        //~5806I~
    {                                                           //~5806I~
    case UDHTDIREXP:                                            //~5812I~
    case UDHTDIR:                                               //~5806I~
    case UDHTPARENT:                                            //~v05KI~
        if (!UCBITCHK(pdh->UDHflag,UDHFEXCLUDED))               //~5806I~
            return 4;                                           //~5806I~
        break;                                                  //~5806I~
    default:        //file                                      //~v05LR~
        return errnotdir();                                     //~v05LI~
    }                                                           //~5806I~
    UCBITON(Ppcw->UCWflag,UCWFDRAW);    //full redraw           //~5807I~
    UCBITOFF(pdh->UDHflag,UDHFEXCLUDED);                        //~5806I~
    UCBITOFF(plh->ULHflag,ULHFHLDIRTYPE);//highlight            //~5819I~
    filesetcsr(Ppcw,plh,PANL310LINENO,0);//set csr              //~5812I~
    dlcunexsub(pdh);    //recursive                             //~5806I~
    return 0;                                                   //~5806I~
}//dlcmdunexclude                                               //~v05LR~
//**************************************************************** //~v10rI~
// display filesiez or line count                                  //~v10rR~
//*parm1:pcw                                                       //~v10rI~
//*parm2:plh                                                       //~v10rI~
//*parm3:opt 1:linecount,0:size                                    //~v10rI~
//*ret   :rc                                                       //~v10rI~
//**************************************************************** //~v10rI~
int dlcmdsetszorlc(PUCLIENTWE Ppcw,PULINEH Pplh,int Popt)          //~v10rR~
{                                                                  //~v10rI~
    PULINEH plh;                                                   //~v10rR~
    PUDIRLH pdh,pdh0;                                              //~v10rR~
//#ifdef FTPSUPP                                                   //~v71tI~,//~v72aR~
//    PUFILEH pfh;                                                 //~v71jI~,//~v72aR~
//#endif                                                           //~v71tI~,//~v72aR~
    LONG    dirlc;                                                 //~v10rR~
//  ULONG   dirsz;                                                 //~v731R~
    FILESZT dirsz;                                                 //~v731I~
    int     levelc;                                                //~v10rI~
//****************************                                     //~v10rI~
    pdh0=pdh=UGETPDH(Pplh);                                        //~v10rR~
    plh=Pplh;                                                      //~v10rI~
//#ifdef FTPSUPP                                                   //+v71tM~,//~v72aR~
//    pfh=UGETPFH(Pplh);                                           //~v71jI~,//~v72aR~
//    if (FILEISTSO(pfh))                                          //~v71jI~,//~v72aR~
//        return 0;                                                //~v71jI~,//~v72aR~
//#endif                                                           //~v71jI~,//~v72aR~
    if (pdh->UDHtype==UDHTFILE)                                    //~v10rI~
    {                                                              //~v10rI~
        if (dlcmdsetszorlcsub(Ppcw,plh,Popt,0))                    //~v10rR~
            return 4;                                              //~v10rI~
        return 0;                                                  //~v10rI~
    }                                                              //~v10rI~
//dir                                                              //~v10rI~
    levelc=pdh->UDHlevel+1;     //child level                      //~v10rI~
    for (dirlc=0,dirsz=0;;)                                        //~v10rR~
    {                                                              //~v10rI~
        if (!(plh=UGETQNEXT(plh)))                                 //~v10rR~
            break;                                                 //~v10rI~
        pdh=UGETPDH(plh);                                          //~v10rI~
        if ((int)pdh->UDHlevel<levelc)  //same as parent           //~v10rR~
            break;                                                 //~v10rI~
        if ((int)pdh->UDHlevel>levelc)  //child of brother         //~v10rR~
            continue;                                              //~v10rI~
        if (UCBITCHK(pdh->UDHupdatetype,UDHUTNOTEXIST))            //~v10rI~
            continue;                                              //~v10rI~
        if (pdh->UDHtype==UDHTFILE)                                //~v10rI~
        {                                                          //~v10rI~
            if (dlcmdsetszorlcsub(Ppcw,plh,Popt,0))                //~v10rR~
                return 4;                                          //~v10rI~
            dirlc+=plh->ULHlinenow;                                //~v10rI~
            dirsz+=pdh->UDHsize;                                   //~v10rI~
            continue;                                              //~v10rI~
        }                                                          //~v10rI~
        if (dlcmdsetszorlc(Ppcw,plh,Popt))  //recursive            //~v10rR~
            return 4;                                              //~v10rI~
        dirlc+=plh->ULHlinenow;                                    //~v10rI~
        dirsz+=pdh->UDHsize;                                       //~v10rI~
    }                                                              //~v10rI~
    pdh0->UDHsize=dirsz;        //dir total of displayed line      //~v10rR~
    if (dlcmdsetszorlcsub(Ppcw,Pplh,Popt,dirlc))                   //~v10rR~
        return 4;                                                  //~v10rI~
    return 0;                                                      //~v10rI~
}//dlcmdsetszorlc                                                  //~v10rR~
//**************************************************************** //~v10rI~
// toggle file size display option                                 //~v10rI~
//*parm1:pcw                                                       //~v10rI~
//*parm2:plh                                                       //~v10rI~
//*parm3:opt 1:linecount,0:size                                    //~v10rI~
//*parm4:input dir level total lineno                              //~v10rI~
//*ret   :rc                                                       //~v10rI~
//**************************************************************** //~v10rI~
int dlcmdsetszorlcsub(PUCLIENTWE Ppcw,PULINEH Pplh,int Popt,LONG Pdirlineno)//~v10rR~
{                                                                  //~v10rI~
    PUDIRLH pdh;                                                   //~v10rI~
    UCHAR   fpathnm[_MAX_PATH];                                    //~v10rI~
    int prevst,getlcsw;                                            //~v10rI~
//****************************                                     //~v10rI~
    if (UCBITCHK(Pplh->ULHflag2,ULHF2EXCLUDED))                    //~v10rR~
        return 0;                                                  //~v10rI~
    pdh=UGETPDH(Pplh);                                             //~v10rI~
    prevst=UCBITCHK(pdh->UDHflag2,UDHF2DISPLC);                    //~v10rI~
    getlcsw=0;                                                     //~v10rI~
    if (Popt)   //disp by lc                                       //~v10rI~
    {                                                              //~v10rI~
        if (!prevst)    //curr size mode                           //~v10rI~
        {                                                          //~v10rI~
            UCBITOFF(pdh->UDHflag,UDHFDDSETUP); //rewrite          //~v10rI~
            UCBITON(pdh->UDHflag2,UDHF2DISPLC);                    //~v10rI~
            UCBITON(Pplh->ULHflag,ULHFDRAW); //redraw              //~v10rI~
        }                                                          //~v10rI~
        if (pdh->UDHtype!=UDHTFILE ||                              //~v10rI~
            !UCBITCHK(pdh->UDHflag2,UDHF2LCGOTTEN)) //not yet lc gotten or update required//~v10rI~
        {                                                          //~v10rI~
            getlcsw=1;                                             //~v10rI~
            UCBITOFF(pdh->UDHflag,UDHFDDSETUP); //rewrite          //~v10rI~
            UCBITON(Pplh->ULHflag,ULHFDRAW); //redraw              //~v10rI~
        }                                                          //~v10rI~
                                                                   //~v10rI~
    }                                                              //~v10rI~
    else    //disp by size                                         //~v10rI~
    {                                                              //~v10rI~
        if (prevst) //curr lc mode                                 //~v10rI~
        {                                                          //~v10rI~
            UCBITOFF(pdh->UDHflag,UDHFDDSETUP); //rewrite          //~v10rI~
            UCBITOFF(pdh->UDHflag2,UDHF2DISPLC);                   //~v10rI~
            UCBITON(Pplh->ULHflag,ULHFDRAW); //redraw              //~v10rI~
        }                                                          //~v10rI~
    }//by size                                                     //~v10rI~
    if (!getlcsw)                                                  //~v10rI~
        return 0;                                                  //~v10rI~
//line ctr update                                                  //~v10rI~
    if (pdh->UDHtype!=UDHTFILE)                                    //~v10rI~
        Pplh->ULHlinenow=Pdirlineno;                               //~v10rR~
    else                                                           //~v10rI~
    {                                                              //~v10rI~
#ifdef FTPSUPP                                                     //~v72aI~
	  if (pdh->UDHattr & FILE_TSO)	//tso file                     //~v72aI~
      {                                                            //~v72aI~
//      if (pdh->UDHattr & FILE_SPF)	//spf info exist           //~v72rR~
//      	Pplh->ULHlinenow=pdh->UDHslinksize;                    //~v72rR~
//      else                                                       //~v72rR~
//      if (!(pdh->UDHattr & FILE_SPF))	//spf info exist           //~v72rR~
//      {                                                          //~v72rR~
//      	Pplh->ULHlinenow=0;                                    //~v72rR~
//      	uerrmsg("No SPF information exist",0);                 //~v72rR~
//      }                                                          //~v72rR~
        return 0;	//no set LCGOTTEN                              //~v72rI~
      }                                                            //~v72aI~
      else                                                         //~v72aI~
      {                                                            //~v72aI~
#endif                                                             //~v72aI~
        if (dlcgetfullname(pdh,fpathnm))                           //~v10rR~
            return 4;                                              //~v10rR~
#ifdef FTPSUPP                                                     //~v732I~
    	if (pdh->UDHattr & FILE_SPECIAL)                           //~v732I~
	        return 0;	//no set LCGOTTEN                          //~v732I~
#endif                                                             //~v732I~
        if (subgetfilelc(GETLC_FPATHINP,fpathnm,(ULONG*)(void*)(&Pplh->ULHlinenow)))//~v10rR~
            return 4;                                              //~v10rR~
#ifdef FTPSUPP                                                     //~v72aI~
      }                                                            //~v72aI~
#endif                                                             //~v72aI~
    }                                                              //~v10rI~
    UCBITON(pdh->UDHflag2,UDHF2LCGOTTEN);                          //~v10rI~
    return 0;                                                      //~v10rI~
}//dlcmdsetszorlcsub                                               //~v10rR~
//**************************************************************** //~v10rI~
// update size on parent                                           //~v10rI~
//*parm1:pdh of dir/file                                           //~v10rR~
//*parm2:update opt;2:lc,1:size,3:both                             //~v10rR~
//*parm3:size to be added                                          //~v10rR~
//*parm4:linecnt to be added                                       //~v10rR~
//*rc   :1:updated,0:no parent updated                             //~v10rI~
//**************************************************************** //~v10rI~
//int dlcmdresetparentsz(PUDIRLH Ppdh,int Popt,ULONG Paddsz,LONG Paddlc)//~v731R~
int dlcmdresetparentsz(PUDIRLH Ppdh,int Popt,FILESZT Paddsz,LONG Paddlc)//~v731I~
{                                                                  //~v10rI~
    PULINEH plh;                                                   //~v10rR~
    PUFILEH pfh;                                                   //~v10rI~
    PUDIRLH pdh;                                                   //~v10rI~
    LONG    addlc;                                                 //~v10rI~
    int rc,chngsw;                                                 //~v10rR~
    UCHAR   fhlvl;                                                 //~v10rI~
//****************************                                     //~v10rI~
    plh=UGETDIRPLH(Ppdh);    //cur level                           //~v10rI~
    pfh=UGETPFH(plh);                                              //~v10rI~
//#ifdef FTPSUPP                                                     //~v71jR~,//~v72rR~
//    if (FILEISTSO(pfh))                                            //~v71jI~,//~v72rR~
//        return 0;                                                  //~v71jI~,//~v72rR~
//#endif                                                             //~v71jI~,//~v72rR~
    fhlvl=pfh->UFHlevel;                                           //~v10rI~
    if (UCBITCHK(Ppdh->UDHflag2,UDHF2LCGOTTEN))                    //~v10rI~
        addlc=Paddlc;                                              //~v10rI~
    else                                                           //~v10rI~
        addlc=0;                                                   //~v10rI~
    rc=0;                                                          //~v10rI~
    for (pdh=Ppdh;;)                                               //~v10rI~
    {                                                              //~v10rI~
        if (!(pdh=pdh->UDHdirptr))  //parent                       //~v10rI~
            break;                                                 //~v10rI~
        if (pdh->UDHlevel<fhlvl)    //parent of cur file dir       //~v10rI~
            break;                                                 //~v10rI~
        plh=UGETDIRPLH(pdh);    //cur level                        //~v10rR~
        chngsw=0;                                                  //~v10rI~
        if (Popt & DLCPSZ_SZ)                                      //~v10rI~
        {                                                          //~v10rI~
            pdh->UDHsize+=Paddsz;                                  //~v10rI~
            chngsw=1;                                              //~v10rI~
        }                                                          //~v10rI~
        if (Popt & DLCPSZ_LC)                                      //~v10rI~
            if (UCBITCHK(pdh->UDHflag2,UDHF2LCGOTTEN))             //~v10rR~
            {                                                      //~v10rI~
                plh->ULHlinenow+=addlc;                            //~v10rR~
                chngsw=1;                                          //~v10rI~
            }                                                      //~v10rI~
        if (chngsw)                                                //~v10rI~
        {                                                          //~v10rI~
            rc=1;                                                  //~v10rI~
            UCBITOFF(pdh->UDHflag,UDHFDDSETUP); //request line make//~v10rR~
            UCBITON(plh->ULHflag,ULHFDRAW);                        //~v10rR~
        }                                                          //~v10rI~
    }                                                              //~v10rI~
    return rc;                                                     //~v10rI~
}//dlcmdresetparentsz                                              //~v10rI~
//****************************************************************//~5806I~
// dlcmdlvlclear                                                //~v05oR~
// clear entry on the dir level                                 //~5806I~
//*parm1:pcw                                                    //~5806I~
//*parm2:pdh of dir                                             //~5806I~
//*parm3:option 1:clear the all child                           //~5819R~
//*             2:clear the all child and itself                //~v05oR~
//*             0:all brother                                   //~5819R~
//*parm4:action 0:del entry                                     //~v05oI~
//*             1:flag deleted                                  //~v05oI~
//*             2:drop view                                     //~v05qI~
//*             3:flag moved                                    //~v05qI~
//*rc   :none                                                   //~5806I~
//****************************************************************//~5806I~
void dlcmdlvlclear(PUCLIENTWE Ppcw,PUDIRLH Ppdh,int Popt,int Paction)//~v05oR~
{                                                               //~5806I~
    PULINEH plh,plh0;                                           //~5813R~
    PULINEH plhn;                                                  //~v085I~
    PUDIRLH pdh,pdh0;                                           //~v05oR~
    int level,childsw=0;                                          //~5813R~//~vaf9R~
//****************************                                  //~5806I~
    if (!Popt)                                                  //~5819R~
    {                                                           //~5813I~
        childsw=0;              //direct child id               //~5813I~
        pdh=Ppdh->UDHdirptr;    //parent                        //~5813I~
    }                                                           //~5813I~
    else                                                        //~5813I~
        pdh=Ppdh;                                               //~5813I~
    level=pdh->UDHlevel+1;      //clear 1 level under the line of dir//~5813R~
    pdh0=pdh;                   //start pdh                     //~v05oI~
    plh0=UGETDIRPLH(pdh);       //start plh                     //~5813R~
//  for (plh=plh0;plh=UGETQNEXT(plh),plh;)                         //~v085R~
//  for (plh=UGETQNEXT(plh0);plh;)                                 //~v091R~
    for (plhn=UGETQNEXT(plh0);plh=plhn,plh;)                       //~v091R~
    {                                                           //~5806I~
        plhn=UGETQNEXT(plh);    //over plh ufree                   //~v085I~
        pdh=UGETPDH(plh);                                       //~5806I~
        if ((int)pdh->UDHlevel<level)   //higher                //~5815R~
            break;                  //loop out                  //~5813R~
        if ((int)pdh->UDHlevel>level)   //lower(child)          //~5815R~
        {                                                       //~5819I~
            if (!Popt && childsw)   //req brother clear and my child//~5819R~
                    continue;       //dont del                  //~5813I~
        }                                                       //~5819I~
        else                        //same level                //~5813I~
        {                                                       //~5819I~
            if (!Popt)              //req brother               //~5819R~
            {                                                   //~5813I~
                if (pdh==Ppdh)      //myself                    //~5813I~
                {                                               //~5813I~
                    childsw=1;      //dont del my child         //~5813I~
                    continue;       //dont del myself           //~5813I~
                }                                               //~5813I~
                childsw=0;          //del child                 //~5815I~
            }                                                   //~5819I~
        }                                                       //~5819I~
        switch(Paction)                                         //~v05oR~
        {                                                       //~v05oI~
        case 0:                                                 //~v05oI~
            dlcdelentry(plh,plh0);                                 //~v09AR~
            break;                                              //~v05oI~
        case 1:                                                 //~v05oI~
            dlcmddelflag(Ppcw,plh,pdh); //set del flag          //~v05oM~
            break;                                              //~v05oI~
        case 2:                                                 //~v05oI~
            dlcmddelview(Ppcw,pdh); //drop view                 //~v05oI~
            break;                                              //~v05oI~
        case 3:                                                 //~v05qM~
            dlcmdmoveflag(Ppcw,plh,pdh,UDHUTMOVEOCHILD);    //moved child flag on//~v05LR~
            break;                                              //~v05qI~
        }                                                       //~v05oI~
//      plh=plhn;   //next line                                    //~v091R~
    }                                                           //~5806I~
    if (Popt==2)    //del dir                                   //~5819I~
        switch(Paction)                                         //~v05oI~
        {                                                       //~v05oI~
        case 0:                                                 //~v05oI~
            dlcdelentry(plh0,UGETQPREV(plh0));                     //~v09AR~
            break;                                              //~v05oI~
        case 1:                                                 //~v05oI~
            dlcmddelflag(Ppcw,plh0,pdh0);   //set del flag      //~v05oM~
            break;                                              //~v05oI~
        case 2:                                                 //~v05oI~
            dlcmddelview(Ppcw,pdh0);    //drop view             //~v05oI~
            break;                                              //~v05oI~
        case 3:                                                 //~v05qM~
            dlcmdmoveflag(Ppcw,plh0,pdh0,0);//not move child    //~v05LR~
            break;                                              //~v05qI~
        }                                                       //~v05oI~
    return;                                                     //~5806I~
}//dlcmdlvlclear                                                //~v05oR~
                                                                //~5819I~
//*************************************************************    //~v55UI~
//*for lineselect by mouse                                         //~v55UI~
//*parm2:optional fpath output                                     //~v568I~
//*parm3:optional pdh output                                       //~v568I~
//*************************************************************    //~v55UI~
//int dlcgetdirlistfname(PUCLIENTWE Ppcw,char *Pfpath)             //~v568R~
int dlcgetdirlistfname(PUCLIENTWE Ppcw,char *Pfpath,PUDIRLH *Pppdh)//~v568R~
{                                                                  //~v55UI~
    PUSCRD  psd;                                                   //~v55UI~
    PULINEH    plh;                                                //~v55UI~
    PUDIRLH    pdh;                                                //~v568I~
//***********************                                          //~v55UI~
    if (Ppcw->UCWtype!=UCWTDIR)                                    //~v55UI~
        return 4;                                                  //~v55UI~
    if (!CSRONFILELINE(Ppcw))                                      //~v55UI~
        return 4;                                                  //~v55UI~
    psd=Ppcw->UCWpsd;                                              //~v55UI~
    psd+=Ppcw->UCWrcsry;                                           //~v55UI~
    plh=psd->USDbuffc;                                             //~v55UI~
    if (!plh)                                                      //~v55UI~
        return 4;                                                  //~v55UI~
    if (plh->ULHtype==ULHTHDR)                                     //~v55UI~
        return 4;                                                  //~v55UI~
    pdh=UGETPDH(plh);                                              //~v568I~
    if (Pppdh)                                                     //~v568I~
        *Pppdh=pdh;                                                //~v568I~
    if (Pfpath)                                                    //~v55UI~
    {                                                              //~v568I~
//      if (dlcgetfullname(UGETPDH(plh),Pfpath))                   //~v568R~
        if (dlcgetfullname(pdh,Pfpath))                            //~v568R~
            return 4;                                              //~v55UI~
    }                                                              //~v568I~
    return 0;                                                      //~v55UI~
}//dlcgetdirlistfname                                              //~v55UI~
#ifdef W32                                                         //~vaitI~
//**************************************************************** //~vaitI~
// junction to file is openerr=13,use targetname                   //~vaitI~
//**************************************************************** //~vaitI~
char *dlcChkJunctionToFile(PUDIRLH Ppdh,char *Ptarget)             //~vaitR~
{                                                                  //~vaitI~
	char *ptarget=NULL;                                            //~vaitI~
    FILEFINDBUF3 ffb3;                                             //~vaitI~
    ULONG srcattr;                                                 //~vaitI~
    char target[_MAX_PATH];                                        //~vaitI~
//*****************************                                    //~vaitI~
  if (Gufile_opt & GFILEOPT_J2FBYTARGETFNM)                   //~v6k7I~//~vaixI~
    if (FILE_MODEISNTFS_JUNCTION2FILE(Ppdh->UDHattr))              //~vaitR~
    {                                                              //~vaitI~
        ptarget=Ppdh->UDHslink;                                    //~vaitR~
        srcattr=Ppdh->UDHslinkattr;                                //~vaitI~
        for (;;)                                                   //~vaitI~
        {                                                          //~vaitI~
        	if (!ptarget)                                          //~vaitI~
            	break;                                             //~vaitI~
            if (!*ptarget)                                         //~vaitR~
            {                                                      //~vaitI~
                ptarget=NULL;                                      //~vaitR~
                break;                                             //~vaitI~
            }                                                      //~vaitI~
            for (;;)                                               //~vaitI~
            {                                                      //~vaitI~
                UTRACEP("dlcChkJunctionToFile ptarget=%s,srcattr=%x\n",ptarget,srcattr);//~vaitR~
                if (!FILE_MODEISNTFS_JUNCTION(srcattr))            //~vaitR~
                    break;                                         //~vaitR~
                if (ufstat(ptarget,&ffb3))  //not found            //~vaitR~
                    break;                                         //~vaitR~
                strcpy(target,ffb3.slink);                         //~vaitR~
                ptarget=target; //ufstat clear ffb3 at start       //~vaitI~
                srcattr=ffb3.srcattr;                              //~vaitR~
            }                                                      //~vaitI~
            break;                                                 //~vaitI~
        }                                                          //~vaitI~
    }                                                              //~vaitI~
    if (ptarget)                                                   //~vaitI~
    	strcpy(Ptarget,ptarget);                                   //~vaitI~
    UTRACEP("dlcChkJunctionToFile return target=%s\n",ptarget);    //~vaitR~
    return ptarget;                                                //~vaitI~
}                                                                  //~vaitI~
#endif                                                             //~vaitI~
//****************************************************************//~5813M~
// dlcgetfullname                                               //~5813M~
// get fullpath filename of dir member                          //~5813M~
//*parm1 :pdh                                                   //~v05GR~
//*parm2 :output file name                                      //~5813M~
//*ret   :rc: 4:wildname with multiple member(UNX only)            //~vaa0R~
//****************************************************************//~5813M~
int dlcgetfullname(PUDIRLH Ppdh,UCHAR *Pfname)                  //~v05GR~
{                                                               //~5813M~
    PUDIRLH pdh;                                                //~5813M~
    UCHAR *pc;                                                  //~5813M~
    UCHAR *name;                                                   //~v0g1I~
    UINT   ulen,utlen,utleno,delmlen;                           //~5813M~
    PUFILEH pfh;                                                   //~v53ZI~
    PULINEH plh;                                                   //~v53ZI~
#ifdef UNX                                                         //~vaa0I~
	int swwildmultiple=0;                                          //~vaa0I~
#endif                                                             //~vaa0I~
#ifdef W32                                                         //~vaitI~
    char target[_MAX_PATH];                                        //~vaitI~
#endif                                                             //~vaitI~
//*******************                                           //~5813M~
    plh=UGETDIRPLH(Ppdh);                                          //~v53ZI~
    pfh=UGETPFH(plh);                                              //~v53ZI~
#ifdef FTPSUPP                                                     //~v717M~
    if (FILEISTSO(pfh))                                            //~v717M~
    	return xetsodlcgetfullname(pfh,Ppdh,Pfname);               //~v717M~
#endif                                                             //~v717M~
#ifdef W32                                                         //~vaitM~
    if (Sfilejuctiontarget)	//to update dirlist after save         //~vaitR~
        if (name=dlcChkJunctionToFile(Ppdh,target),name)           //~vaitR~
        {                                                          //~vaitR~
            strcpy(Pfname,name);                                   //~vaitR~
            return 0;                                              //~vaitR~
        }                                                          //~vaitR~
#endif                                                             //~vaitM~
#ifdef LNX                                                         //~vawyI~
    if (Ppdh->UDHflag3 & UDHF3U8UTF)      //memberbname is utf8    //~vawyI~
	{                                                              //~vawyI~
        int opt,len;                                               //~vawyI~
        char *pdddata,*pdddbcs,wkct[_MAX_PATH],*pu8;               //~vawyI~
		opt=XEUTFSLCFEO_FILENAME|XEUTFSLCFEO_DDFMT;   //parameter is ddfmt//~vawyI~
    	if ((pdddata=Ppdh->UDHnameddfmt))                          //~vawyI~
        {                                                          //~vawyI~
    		len=Ppdh->UDHnameddfmtlen;                             //~vawyI~
        	UTRACED("membname by ddfmt for utf8",pdddata,len*2);   //~vawyI~
            pdddbcs=pdddata+len;                                   //~vawyI~
//          memset(wkct,XEUTFCT_UTF8,len);                    //~vaunI~//~vawyI~//~vb2gR~
            memset(wkct,XEUTFCT_UTF8,(size_t)len);                 //~vb2gI~
            pu8=Ppdh->UDHname;                                     //~vawyI~
//  		xeutf_savelcctforerrmsg(opt,pu8,strlen(pu8),pdddata,pdddbcs,wkct,len);//~vawyI~//~vb2gR~
    		xeutf_savelcctforerrmsg(opt,pu8,(int)strlen(pu8),pdddata,pdddbcs,wkct,len);//~vb2gI~
        }                                                          //~vawyI~
    }                                                              //~vawyI~
#endif                                                             //~vawyI~
    *(pc=Pfname)=0;                                             //~5813M~
    utlen=1;                                                    //~5813M~
    for (pdh=Ppdh;pdh;pdh=pdh->UDHdirptr)   //hierarchy         //~v05GR~
    {                                                           //~5813M~
#ifdef UNX                                                         //~vaa0I~
    	if (pdh->UDHattr & FILE_WILDNAME_MULTIPLE)                 //~vaa0I~
        {                                                          //~vaa0I~
            UTRACEP("dlcgetfullname wildmultiple name=%s\n",pdh->UDHname);//~vaa0R~
        	swwildmultiple=1;                                      //~vaa0I~
        }                                                          //~vaa0I~
#endif                                                             //~vaa0I~
        delmlen=(UINT)(pdh->UDHlevel && utlen!=1);              //~5813M~
        utleno=utlen;                   //save old len          //~5813M~
//      ulen=strlen(pdh->UDHname);                                 //~v0g1R~
#if defined(W32) || defined(DPMI)                                  //~v0g1I~
#ifdef W32                                                         //~v53ZI~
      if (FILEISREMOTE(pfh))                                       //~v53ZR~
        name=pdh->UDHname;      //use long filename                //~v53ZI~
      else                                                         //~v53ZI~
#endif                                                             //~v53ZI~
	#ifdef W32                                                     //~van3M~
    	if (FILE_IS_WILDNAMEER(pdh->UDHattr))	//wildname with valid alias//~van3I~
        	return dlcerrwildname(pdh);                            //~van3I~
        else                                                       //~van3I~
    	if (FILE_IS_WILDNAME(pdh->UDHattr))	//wildname with valid alias//~van3M~
            name=pdh->UDHalias;                                    //~van3M~
        else                                                       //~van3M~
    #endif                                                         //~van3M~
        if (Saliassw)                                              //~v0g1I~
        {                                                          //~vavJI~
          if (Saliassw==2)//only for tha path of YD fmt            //~vavJI~
          {                                                        //~vavJI~
          	if (strchr(pdh->UDHname,UD_NOTLC))                     //~vavJI~
	            name=pdh->UDHalias;                                //~vavJI~
            else                                                   //~vavJI~
	            name=pdh->UDHname;                                 //~vavJI~
          }                                                        //~vavJI~
          else                                                     //~vavJI~
            name=pdh->UDHalias;                                    //~v0g1R~
            if (!*name)	//root has no alias was set                //~vavJI~
	            name=pdh->UDHname;                                 //~vavJI~
        }                                                          //~vavJI~
        else                                                       //~v0g1I~
#endif  //W32||DPMI                                                //~v0g1I~
#ifdef W32                                                         //~vav7I~
        if (!UCBITCHK(pfh->UFHflag4,UFHF4LFN))  //hpfs drive       //~vav7I~
            name=pdh->UDHalias;                                    //~vav7I~
        else                                                       //~vav7I~
#endif                                                             //~vav7I~
            name=pdh->UDHname;                                     //~v0g1R~
//      ulen=strlen(name);                                         //~v0g1I~//~vb2ER~
        ulen=(UINT)strlen(name);                                   //~vb2EI~
        if (utlen+=ulen+delmlen,utlen>=_MAX_PATH)               //~5813M~
//          return errtoolong();                                   //~vb7aR~
            return ufileTooLongFullpathName(4/*rc*/);              //~vb7aI~
        memmove(pc+ulen+delmlen,pc,utleno);                     //~5813M~
//      memcpy(pc,pdh->UDHname,ulen);   //insert parent dir name   //~v0g1R~
        memcpy(pc,name,ulen);   //insert parent dir name           //~v0g1I~
        if (!pdh->UDHlevel) //root                              //~5813M~
            break;                                              //~5813M~
        if (utleno!=1)  //not first time                        //~5813M~
//          *(pc+ulen)='\\';                                       //~v19aR~
//          *(pc+ulen)=DIR_SEPC;                                   //~v540R~
            *(pc+ulen)=pfh->UFHdirsepc;                            //~v540I~
    }                                                           //~5813M~
#ifdef UNX                                                         //~vaa0I~
	if (swwildmultiple)                                            //~vaa0I~
		return errwildnamemultiple(0,Pfname);                      //~vaa0R~
#endif                                                             //~vaa0I~
    return 0;                                                   //~5813M~
}//dlcgetfullname                                               //~5813M~
//**************************************************************** //~v59cI~
// dlcgetfullnameenclose                                           //~v59cI~
// get fullpath filename of dir member and enclose by dquote if space containing//~v59cI~
//*parm1 :pdh                                                      //~v59cI~
//*parm2 :output file name                                         //~v59cI~
//*ret   :rc:1 enclosed,2:enclosed with strip UD or alias used by for UD str                                                       //~v59cI~//~vavHR~
//**************************************************************** //~v59cI~
//int dlcgetfullnameenclose(PUDIRLH Ppdh,UCHAR *Pfname)              //~v59cI~//~vavHR~
int dlcgetfullnameenclose(int Popt,PUDIRLH Ppdh,UCHAR *Pfname)     //~vavHI~
{                                                                  //~v59cI~
	char fnmwk[_MAX_PATH+2];                                       //~v59cI~
    int rc,len;                                                    //~v59cI~
#ifdef W32UNICODE                                                  //~vavHI~
    int swud=0,stripud=0,swalias=0;                                //~vavHR~
#endif                                                             //~vavHI~
//*******************                                              //~v59cI~
  if (Ppdh)                                                        //~vamAI~
  {                                                                //~vamAI~
	rc=dlcgetfullname(Ppdh,Pfname);                                //~v59cI~
    if (rc)                                                        //~v59cI~
    	return rc;                                                 //~v59cI~
#ifdef W32UNICODE                                                  //~vavJI~
	if (Popt & DLCGFEO_ALIAS)                                      //~vavHI~
    {                                                              //~vavHI~
	    swud=strchr(Pfname,UD_NOTLC)!=NULL;                        //~vavHI~
        if (swud)                                                  //~vavHI~
        {                                                          //~vavHI~
			rc=dlcgetfullnamealias2(Ppdh,Pfname);                   //~vavHI~//~vavJR~
    		if (rc)                                                //~vavHI~
    			return rc;                                         //~vavHI~
            swalias=1;                                             //~vavHI~
        }                                                          //~vavHI~
    }                                                              //~vavHI~
#endif                                                             //~vavJI~
  }                                                                //~vamAI~
#ifdef W32UNICODE                                                  //~vavHI~
    swud=strchr(Pfname,UD_NOTLC)!=NULL;                            //~vavHR~
	if (!((Popt & DLCGFEO_ENCUD) && swud))                         //~vavHI~
#endif                                                             //~vavHI~
    if (!strchr(Pfname,' '))                                       //~v59cI~
    if (!strchr(Pfname,'('))                                       //~vamxR~
    if (!strchr(Pfname,')'))                                       //~vamxR~
    	return 0;                                                  //~v59cI~
    len=(int)strlen(Pfname);                                       //~v59NR~
    *fnmwk='"';                                                    //~v59cI~
#ifdef W32UNICODE                                                  //~vavHI~
  if ((Popt & DLCGFEO_STRIPUD) && swud)                            //~vavHI~
  {                                                                //~vavHI~
	fsubw_stripUDCT(0,Pfname,len,fnmwk+1,sizeof(fnmwk)-2,NULL/*Poutct*/,0/*Poutctsz*/,&len);//~vavHR~
    stripud=1;                                                     //~vavHI~
  }                                                                //~vavHI~
  else                                                             //~vavHI~
#endif                                                             //~vavHI~
    memcpy(fnmwk+1,Pfname,(UINT)len);                              //~v59cI~
    *(fnmwk+1+len)='"';                                            //~v59cI~
    memcpy(Pfname,fnmwk,(UINT)(len+2));                            //~v59cI~
    *(Pfname+len+2)=0;                                             //~v59cI~
#ifdef W32UNICODE                                                  //~vavHI~
  if (stripud)	                                                   //~vavHI~
  	return 2;                                                      //~vavHI~
#endif                                                             //~vavHI~
  if (Ppdh)                                                        //~vamAI~
  {                                                                //~vavHI~
#ifdef W32UNICODE                                                  //~vavHI~
	if (swalias)                                                   //~vavHI~
    	return 2;                                                  //~vavHI~
#endif                                                             //~vavHI~
    return 0;                                                      //~v59cI~
  }                                                                //~vavHI~
  else                                                             //~vamAI~
    return 1;// enclosed;rc of when Ppdh=NULL                      //~vamAI~
}//dlcgetfullnameenclose                                           //~v75JR~
                                                                //~5813M~
#if defined(W32) || defined(DPMI)                                  //~v0g1I~
//**************************************************************** //~v0g1I~
// dlcgetfullnamealias                                             //~v0g1I~
// get fullpath filename of dir member by alias                    //~v0g1I~
//*parm1 :pdh                                                      //~v0g1I~
//*parm2 :output file name                                         //~v0g1I~
//*ret   :rc                                                       //~v0g1I~
//**************************************************************** //~v0g1I~
int dlcgetfullnamealias(PUDIRLH Ppdh,UCHAR *Pfname)                //~v0g1I~
{                                                                  //~v0g1I~
    int rc;                                                        //~v0g1I~
//*******************                                              //~v0g1I~
    Saliassw=1;                                                    //~v0g1I~
    rc=dlcgetfullname(Ppdh,Pfname);                                //~v0g1I~
    Saliassw=0;                                                    //~v0g1I~
    return rc;                                                     //~v0g1I~
}//dlcgetfullnamealias                                             //~v0g1I~
//**************************************************************** //~vavJI~
// dlcgetfullnamealias                                             //~vavJI~
// get fullpath filename by alias for the path is UD fmt           //~vavJI~
//**************************************************************** //~vavJI~
int dlcgetfullnamealias2(PUDIRLH Ppdh,UCHAR *Pfname)               //~vavJI~
{                                                                  //~vavJI~
    int rc;                                                        //~vavJI~
//*******************                                              //~vavJI~
    Saliassw=2;                                                    //~vavJI~
    rc=dlcgetfullname(Ppdh,Pfname);                                //~vavJI~
    Saliassw=0;                                                    //~vavJI~
    return rc;                                                     //~vavJI~
}//dlcgetfullnamealias2                                            //~vavJI~
#endif                                                             //~v0g1I~
//**************************************************************** //~vb2sI~
int dlcslinkerrmsg(int Popt,PUDIRLH Ppdh,int Prc)                  //~vb2sI~
{                                                                  //~vb2sI~
	char *pname;                                                   //~vb2sI~
#ifdef W32                                                         //~vb2sI~
    PULINEH plh;                                                   //~vb2sI~
    PUFILEH pfh;                                                   //~vb2sI~
#endif                                                             //~vb2sI~
//*****************                                                //~vb2sI~
#ifdef W32                                                         //~vb2sI~
	plh=UGETDIRPLH(Ppdh);                                          //~vb2sI~
	pfh=UGETPFH(plh);                                              //~vb2sI~
    if (!UCBITCHK(pfh->UFHflag4,UFHF4LFN))  //hpfs drive           //~vb2sI~
        pname=Ppdh->UDHalias;                                      //~vb2sR~
    else                                                           //~vb2sI~
#endif                                                             //~vb2sI~
        pname=Ppdh->UDHname;                                       //~vb2sR~
	uerrmsg("%s has invalid slink target.",                        //~vb2sR~
	    	    "%s のリンク先の設定に誤りがあります。",           //~vb2sR~
            pname);                                                //~vb2sI~
    if (!UCBITCHK(Gdir3status,GDIR3SLFN))	//display long         //~vb2sI~
		uerrmsgcat("Confirm it by Shift+F11",                      //~vb2sI~
	    	    "Shift+F11 で確認してください");                   //~vb2sI~
    return Prc;                                                    //~vb2sI~
}//dlcslinkerrmsg                                                  //~vb2sI~
//**************************************************************** //~vaitI~
// dlcgetfullnameorgjunction                                       //~vaitI~
//   for update dirlist after save junction to file                //~vaitI~
//**************************************************************** //~vaitI~
int dlcgetfullnamefilejunctiontarget(PUDIRLH Ppdh,UCHAR *Pfname)   //~vaitR~
{                                                                  //~vaitI~
    int rc;                                                        //~vaitI~
//*******************                                              //~vaitI~
    if (XEDIR_PDHSLINKERR(Ppdh))                                   //~vb2sI~
		return dlcslinkerrmsg(0,Ppdh,4);                           //~vb2sI~
    Sfilejuctiontarget=1;	//not return file junction target      //~vaitR~
    rc=dlcgetfullname(Ppdh,Pfname);                                //~vaitI~
    Sfilejuctiontarget=0;                                          //~vaitR~
    return rc;                                                     //~vaitI~
}//dlcgetfullnamefilejunction                                      //~vaitI~
