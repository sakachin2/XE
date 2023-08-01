//*CID://+vby6R~:                             update#=   69;       //+vby6R~
//*************************************************************
//*xefile13.c*                                                     //~v0d5R~
//**fileregist,filefree,fileclosefree(2),fncomp                    //~v0d5R~
//*************************************************************
//vby6:230402 (ARM)adjust by4; go around by shortname and change to uri at ulib(ufile1l)//+vby6I~
//vby4:230402 (ARM)shared resource support by //shareName defined by SP(ShortPath) cmd.//~vby4I~
//vb79:170104 parsefname chk buffsz                                //~vb79I~
//v9@8:080717 3270:fs mode del excluded line                       //~v9@8I~
//v9@5:080717 3270:TSO FS mode;draw update line only for performance//~v9@5I~
//v74y:070223 new option to set COLS ON as default  "COLS ON ALL"  //~v74yI~
//v748:070212 (BUG)ABEND by UFCcurtop plh is dequed(if c&p done when screen split and ::cb is displayed not topline hdr)//~v748I~
//v731:061226 filesize>4GB support                                 //~v731I~
//v71v:061022 not fixed(PAGE) scroll type for =0.1/2/3             //~v71vI~
//v62x:050402 cmd line parameter /Lnn : initial Locate cmd(/L is listdir option)//~v62xI~
//            (/Ln-m option deleted;simply use n-m or /on-m for hex offset)//~v62xI~
//v61c:050221 set open parm to filename list to reopen by same option//~v61cI~
//v60v:050201 virtual hex display option(/Mx,HEX on/off)           //~v60vI~
//v58m:040918 (BUG)for large file,lineno column is displayed by length=9 when lineno>=10000000(8 digit)//~v58mI~
//v585:040823 cap performance up;skip undo data save when clipboard repl//~v585I~
//v57L:040619 (FTP:BUG)not found msg for tmp file when canceled new file//~v57LI~
//v578:040516 (FTP:BUG)temp local file remains,should be deleted   //~v578I~
//v553:040202 (FTP)filename compre by case sensitive               //~v553I~
//v48e:020501 (UNX)mdos file name is 8.3 case insensitive          //~v48eI~
//v48c:020429 (UNX)edit/browse mdos disk support                   //~v48cI~
//v47v:020316 COBK w/o N is not spf(allow any char in col.1-6;any lrecl)//~v47vI~
//v42z:011010 cobol linenosz=5 for small file                      //~v42zI~
//v41o:010820 cobol UFCleft=6                                      //~v41oI~
//v41n:010820 more over v40Y(lineno column sz)                     //~v41nI~
//v41m:010820 cobol linenosz=6                                     //~v41mI~
//v20D:001103 LINUX support:filename compare is case sensitive     //~v20DI~
//v20y:001028 new function:filename selection on menu 1/2 name list//~v20yI~
//v173:000430 ajust linenosz when num XON/XOFF                     //~v173I~
//v155:000318 numeric calc func                                    //~v155I~
//v10X:990605 hex digit lineno display for binary file             //~v10XI~
//v0ig:980620 (BUG)abend when start line specified                 //~v0igI~
//v0if:980620 pfk cmd support(set linenosz/scrollsz)               //~v0ifR~
//v0fs:971109 (BUG)fullpath fail when select cmd with quatation    //~v0fsI~
//v0d6:970831 linenosz default 7 for spf file                      //~v0d6R~
//v0d5:970831 split xefile13 from xefile,fileregist etc.           //~v0d5I~
//v0ct:970814 RENUM(NUM reset) Force option for spf file           //~v0ctI~
//v0cn:970813 RENUM undo support(move filerenum from xefile to xefile12)//~v0cnI~
//v0cl:970811 spf NUM field support                                //~v0clI~
//v0bd:970726 split line size redundancy for split line update     //~v0bdI~
//v0bb:970726 limit tabctr max 12,and tab expand limit chk         //~v0bbI~
//v0ba:970726 split xefile,xefile12(save)                          //~v0baI~
//v0b9:970725 (BUG)cid for long line(multiline record) has to set at last line//~v0b9I~
//v0b2:970723 split uparse fro ustring to uparse.c                 //~v0b2I~
//v0av:970720-fixed lrecl support                                  //~v0avI~
//           -filetoplinecid/filegetcid return rc                  //~v0avI~
//v0al:970713 split msg for first record not last                  //~v0alI~
//v0ai:970712 renum for split line(same lineno)                    //~v0aiI~
//v0ae:970712 do not long line cut at save                         //~v0aeI~
//v0ad:970712 assign same lineno to split line                     //~v0adI~
//v0ab:970712:write by binaly mode                                 //~v0abI~
//v0aa:970707:default write mode set from read mode                //~v0aaI~
//v0a1:970705:NULL data accept as 0x00.and change str___ to mem___ //~v0a1I~
//v09Z:970702:(BUG)drop boundary 1 byte when over max-len*>2       //~v09ZI~
//v09Y:970629:file NULL(0x00) support                              //~v09YI~
//            bynaly read using ufgets                             //~v09YI~
//            optionchk need before open for binaly mode open      //~v09YI~
//            open by "rb"                                         //~v09YI~
//v09X:970629:.ini tab display char parm                           //~v09XI~
//v09U:970628:display unprintable char by 0x0e(J) or 0x16(E)       //~v09FI~
//v09F:970614:CID postfix support                                  //~v09FI~
//v09w:970524:Select cmd support on dir list                       //~v09wI~
//            isrt pdh if no entry at open by select               //~v09wI~
//v09r:970521:arbitaly CID type by first line                      //~v09rI~
//            -filegetcid parm 0:always chk first line,2 chk if sline==0//~v09rI~
//v09g:970517:shift linenosz by line number of file.               //~v09gI~
//v09a:970503:space imbedding filename support(last space is not supported)//~v09aI~
//            -cmd Edit/Brows:enclosed file name                   //~v09aI~
//v095:970405:DPMI version                                         //~v095I~
//            -errno need errno.h(c6 has it in stdlib.h)           //~v095I~
//            -\ of dbcs 2nd byte                                  //~v095I~
//v08q:961123:edit partial file(continued from v08l)               //~v08lI~
//v08l:961123:edit/browse line range parameter                     //~v08lI~
//v08c:961104:(BUG)capreset must be executed before plh free       //~v08cI~
//                 must be call not from deqcw but from end/cancel //~v08cI~
//v085:961024:W95 VC                                               //~v085I~
//v081:960906:(BUG)free err when storage shortage at dirload       //~v081I~
//v07s:960825:new ulib.h/ulibdef.h(no need base def by os2.h)      //~v07sI~
//            to speed up compile,drop include(caused by WIN95 modify)//~v07sI~
//v074:960602:num reset cmd(renumber line number)                  //~v074I~
//v06z:960407:stdout work last used seqno save to xe!SAVE!            //~v06zI~
//            xe.h ini3.c dcmd2.c file.c dcmd2.h                      //~v06zI~
//v06y:960407:protect edit so file when iit is used by cmd result     //~v06yI~
//            (cmd edit identification only by PANMOCMD)              //~v06yI~
//v06t:960406:cmd so screen:append cmd result                         //~v06tI~
//v06s:960330:(BUG)eof is dropped when edit after load by browse      //~v06sI~
//v06n:960320:menu option 6(cmd) support                        //~v06nI~
//v05v:951203:(BUG)find all offset table shared,it must be for each pfh//~v05vI~
//v04k:951007:(BUG)v03o close after load when browse.edit for same file//~v04kI~
//            can not reopen to save because hfile is null(errno=12//~v04kI~
//            ENULLFCB).drop v03o.leave ini cmd err when browsing.//~v04kI~
//            xefile.c                                          //~v04kI~
//v04j:951007:update id for edit saved file on dir list         //~v04jR~
//v04d:950930:malloc/calloc rc chk for dos                      //~v04dI~
//v03y:950903:pfh path name length for dir entry matching       //~v03yI~
//v03u:950827:bug;ULHFLINECMD(lcmd reg sw) reset by xechar ignore//~v03uI~
//            lcmd input from other side of same pfc.           //~v03uI~
//            so move lcmd stack to pfh from pfc.(alt of v03q)  //~v03uI~
//*v03o:950820:xe.ini open err rc=9 when ini cmd under xe.ini browsing//~v03oI~
//*v03l:950817:bug,dont strupr for DBCS filename,it cause (デ-->ェ)//~v03lI~
//*v037:950723:pcw enq to target option to display FIFO seq for dir//~v037I~
//*v030:950709:dir proc avail flag on by 2nd line version id    //~v030I~
//*v020:950628:release(protect dir display)                     //~v020I~
//*           :csr home when steal                              //~v020I~
//*v020:950624:dir support(move End/Cancel from xefcmd.c)       //~v020M~
//*v020:950611:dir support(find err if dir)                     //~v020I~
//************************************************************* //~v020I~
//*v014:950624:bug:when save not displayed line after copy file //~v020I~
//*v012:950611:fixed CID                                        //~5611I~
//************************************************************* //~5611I~
//*950527 endof line lineno 2 up bug                            //~5527I~
//*950424 always save cap data                                  //~5424I~
//*950118 popup previous edit/browse scr                        //~5118R~
//*950102 tab display by space for screen print                 //~5118I~
//*941214 first open at write when new file                     //~5102I~
//*941204 cancel cmd
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
#include <ufile2.h>                                                //~v0ctI~
#include <uparse.h>                                                //~v0fsI~
#include <utrace.h>                                                //~v9@8I~
#ifdef FTPSUPP                                                     //~v578I~
	#include <uftp.h>                                              //~v578R~
#endif                                                             //~v578I~
                                                                //~5318I~
#include "xe.h"
#include "xescr.h"
#include "xefile.h"
#include "xefile13.h"                                              //~v0d5I~
#include "xefile2.h"                                               //~v0ctI~
#include "xefile3.h"                                               //~v0ctI~
#include "xedir.h"                                                 //~v0d5I~
#include "xecsr.h"                                              //~v020I~
#include "xecap.h"                                                 //~v0ctI~
#include "xepan.h"                                                 //~v0ctI~
#include "xepan22.h"                                               //~v20yI~
#include "xeundo.h"                                                //~v0ctI~
#include "xefcmd4.h"                                               //~v74yI~
#include "xesub.h"                                                 //~v0d5I~
#ifdef FTPSUPP                                                     //~v578I~
	#include "xeftp.h"                                             //~v578I~
#endif                                                             //~v578I~
//****************************************************************
#define SPFLINENOSZ 8                                              //~v20DR~
//****************************************************************//~v04dI~
//!fileplhfail                                                  //~v04dI~
//* file close free the return UALLOC_FAILED                    //~v04dI~
//*parm1:pfh                                                    //~v04dI~
//*retrn:UALLOC_FAILED                                          //~v04dI~
//****************************************************************//~v04dI~
int fileplhfail(PUFILEH Ppfh)                                   //~v04dI~
{                                                               //~v04dI~
//***************                                               //~v04dI~
	fileclosefree2(Ppfh);                                       //~v04dI~
	return UALLOC_FAILED;                                       //~v04dI~
}//fileplhfail                                                  //~v04dI~
                                                                //~v04dI~
//****************************************************************
// fileclosefree
//*close and free UFILEH/ULINEH
//*parm:UFILEC                                                  //~5118R~
//*rc   :open count
//****************************************************************
int fileclosefree(PUFILEC Ppfc)                                 //~5118R~
{
    PUFILEH pfh;                                                //~5118I~
    PUCLIENTWE pcw;                                                //~v08cI~
//****************************
	pcw=Ppfc->UFCpcw;		//mother                               //~v08cI~
    if (pcw==Gcappcw)   //current block pcw                        //~v08cI~
		capreset(0);    //crear Gcappcw                            //~v08cI~
    capresetcalc(pcw);      //reset tc cmd opd1 block              //~v155I~
    if (pcw==Gcapcbpcw) //clipboard pcw                            //~v08cI~
		Gcapcbpcw=0;    //crear hidden pcw                         //~v08cI~
	pfh=Ppfc->UFCpfh;                                           //~5118R~
	if (UCBITCHK(Ppfc->UFCflag,UFCFBROWSE))	//browse mode       //~5118R~
		pfh->UFHbrowsepcw[Gscrcurclient]=0;                     //~5118I~
	else                                                        //~5118I~
		pfh->UFHeditpcw=0;                                      //~5118I~
                                                                //~5118I~
	return fileclosefree2(pfh);	//close and free pfh            //~v04dI~
}//fileclosefree
                                                                //~5502I~
//****************************************************************//~v04dI~
//!fileclosefree2                                                  //~v0ctR~
//*close and free UFILEH/ULINEH                                 //~v04dI~
//*parm:UFILEH                                                  //~v04dI~
//*rc   :open count                                             //~v04dI~
//****************************************************************//~v04dI~
int fileclosefree2(PUFILEH Ppfh)                                //~v04dI~
{                                                               //~v04dI~
	int  	openctr;                                            //~v04dI~
#ifdef UNX                                                         //~v48eI~
	int  	procctr;                                               //~v48cI~
#endif                                                             //~v48eI~
//****************************                                  //~v04dI~
    if (Ppfh->UFHtype==UFHTDIR)   //dir type pfh                   //~v081I~
    	return dirclosefree2(Ppfh);                                //~v081I~
                                                                   //~v081I~
	if (openctr=--Ppfh->UFHopenctr,openctr)		//other open client exist//~v04dR~
		return openctr;                                         //~v04dI~
	if (Ppfh->UFHhfile)                                         //~v04dR~
    {                                                              //~v48cI~
		fileclose(Ppfh->UFHfilename,Ppfh->UFHhfile);//fclose    //~v04dR~
#ifdef UNX                                                         //~v48cI~
		if (UCBITCHK(Ppfh->UFHflag5,UFHF5MDOS))//original is mdos disk//~v48cI~
			uxdelete(Ppfh->UFHalias,FILE_NORMAL,UXDELNOMSG,        //~v48cR~
						&procctr,&procctr,&procctr);//del not copy backed temp//~v48cI~
#endif                                                             //~v48cI~
    }                                                              //~v48cI~
#ifdef FTPSUPP                                                     //~v578M~
    if (FILEISREMOTE(Ppfh))                                        //~v578I~
    {                                                              //~v71vI~
      if (!UCBITCHK(Ppfh->UFHflag,UFHFNEW))//creted local copy     //~v57LI~
      {                                                            //~v71vI~
       if (!UCBITCHK(Ppfh->UFHflag,UFHFWRITEERR))  //xeftpsave not failed once//~v71vI~
        xeftpdelwd(0,Ppfh->UFHftpwdfnm);                           //~v578I~
      }                                                            //~v71vI~
    }                                                              //~v71vI~
#endif                                                             //~v578M~
//line data                                                     //~v04dI~
	filefree(Ppfh);			//free all plh                      //~v04dR~
//undo data                                                     //~v04dI~
	undofreeuuh(Ppfh);			//free all data                 //~v04dR~
    filefreepfh(Ppfh);           //deq and free pfh             //~v04dR~
	return 0;                                                   //~v04dI~
}//fileclosefree2                                               //~v04dI~
                                                                //~v04dI~
//****************************************************************
//!fncomp                                                          //~v0ctR~
//*file name compare for uqscan
//*parm1:que element ptr
//*parm2:search key(file name)
//*rc   :0:match, 1:request forward search(UGETQNEXT)           //~4C19R~
//****************************************************************
int fncomp(PUQUEE Ppfnqe,PVOID Ppfname)
{
#ifdef UNX                                                         //~v48eI~
    PUFILEH pfh;                                                   //~v48eI~
#else                                                              //~v553I~
    #ifdef FTPSUPP                                                 //~v553I~
	    PUFILEH pfh;                                               //~v553I~
    #endif                                                         //~v553I~
#endif                                                             //~v48eI~
//**********************************                               //~v48eI~
//retrn 0 if match ,1 if unmatch                                //~4C19I~
#ifdef UNX                                                         //~v20DI~
//  return strcmp(Ppfname,((PUFILEH)(PVOID)Ppfnqe)->UFHfilename)!=0;//~v48eR~
    pfh=(PUFILEH)(PVOID)Ppfnqe;                                    //~v48eI~
    if (UCBITCHK(pfh->UFHflag5,UFHF5MDOS))//mdos disk              //~v48eR~
		return stricmp(Ppfname,pfh->UFHfilename)!=0;               //~v48eI~
    else                                                           //~v48eI~
		return strcmp(Ppfname,pfh->UFHfilename)!=0;                //~v48eI~
                                                                   //~v48eI~
#else  //!UNX                                                      //~v20DI~
  #ifdef FTPSUPP                                                   //~v553I~
    pfh=(PUFILEH)(PVOID)Ppfnqe;                                    //~v553I~
    if (FILEISREMOTE(pfh))                                         //~v553I~
		return strcmp(Ppfname,pfh->UFHfilename)!=0;                //~v553I~
    else                                                           //~v553I~
  #endif                                                           //~v553I~
	return stricmp(Ppfname,((PUFILEH)(PVOID)Ppfnqe)->UFHfilename)!=0;//~4C19R~
#endif //!UNX                                                      //~v20DI~
}//fncomp                                                     //~4C17R~
//#ifdef ARMXXE                                                    //~vby4R~//+vby6R~
////****************************************************************//~vby4R~//+vby6R~
//int fncompDoc(PUQUEE Ppfnqe,PVOID Ppfname)                       //~vby4R~//+vby6R~
//{                                                                //~vby4R~//+vby6R~
//    PUFILEH pfh;                                                 //~vby4R~//+vby6R~
////**********************************                             //~vby4R~//+vby6R~
////retrn 0 if match ,1 if unmatch                                 //~vby4R~//+vby6R~
//    pfh=(PUFILEH)(PVOID)Ppfnqe;                                  //~vby4R~//+vby6R~
//    return strcmp(Ppfname,pfh->UFHfpathDoc)!=0;                  //~vby4R~//+vby6R~
//                                                                 //~vby4R~//+vby6R~
//}//fncompDoc                                                     //~vby4R~//+vby6R~
//#endif //ARMXXE                                                  //~vby4R~//+vby6R~
//****************************************************************
//!filefree                                                        //~v0ctR~
//*free all ULINEH entry
//*parm1:PUFILEH
//*void
//****************************************************************
void filefree(PUFILEH Ppfh)
{
	UQUEH   *pqh;
	PULINEH plh;
//******************
	pqh=&Ppfh->UFHlineque;
	while (plh=UDEQ(UQUE_TOP,pqh,0),plh)	//dequed
		filefreeplh(plh,1);
	return;
}//filefree
//**************************************************************** //~v585I~
//!filefreealldataplh                                              //~v585I~
//*free all ULINEH entry                                           //~v585I~
//*parm1:PUFILEH                                                   //~v585I~
//*void                                                            //~v585I~
//**************************************************************** //~v585I~
void filefreealldataplh(PUFILEH Ppfh)                              //~v748R~
{                                                                  //~v585I~
	UQUEH   *pqh;                                                  //~v585I~
	PULINEH plh,plhs,plhe;                                         //~v585I~
    PUFILEC pfc;                                                   //~v748I~
    PUCLIENTWE pcw;                                                //~v748I~
//******************                                               //~v585I~
	undofreeuuh(Ppfh);			//free all data                    //~v585I~
	pqh=&Ppfh->UFHlineque;                                         //~v585I~
	plhs=UGETQTOP(pqh);                                            //~v585I~
	plhe=UGETQEND(pqh);                                            //~v585I~
    if (!plhs)                                                     //~v585I~
        return;                                                    //~v585I~
	UTRACEP("@@@1 %s:add %c reset ctr cmdlinectr=%d\n",UTT,Ppfh->UFHcmdlinectr);//~v9@8I~
    Ppfh->UFHcmdlinectr=0;                                         //~v748I~
    for (;plh=UGETQNEXT(plhs),plh!=plhe;)                          //~v585I~
    {                                                              //~v585I~
		UDEQ(UQUE_ENT,pqh,plh);	//dequed                           //~v585I~
		filefreeplh(plh,1);                                        //~v585I~
    }                                                              //~v585I~
	if ((pcw=Ppfh->UFHbrowsepcw[0]),pcw)                               //~v748R~
    {                                                              //~v748I~
        pfc=pcw->UCWpfc;                                           //~v748I~
		pfc->UFCcurtop=plhs;                                       //~v748R~
		pfc->UFCcsrplh=0;                                          //~v748R~
        filesetfulldraw(pcw);   //clear UFCdrawplh;                //~v748I~
                                                                   //~v748I~
    }                                                              //~v748I~
	if ((pcw=Ppfh->UFHbrowsepcw[1]),pcw)                               //~v748R~
    {                                                              //~v748I~
        pfc=pcw->UCWpfc;                                           //~v748I~
		pfc->UFCcurtop=plhs;                                       //~v748I~
		pfc->UFCcsrplh=0;                                          //~v748I~
        filesetfulldraw(pcw);   //clear UFCdrawplh;                //~v748I~
    }                                                              //~v748I~
	if ((pcw=Ppfh->UFHeditpcw),pcw)                                    //~v748R~
    {                                                              //~v748I~
        pfc=pcw->UCWpfc;                                           //~v748I~
		pfc->UFCcurtop=plhs;                                       //~v748R~
		pfc->UFCcsrplh=0;                                          //~v748R~
        filesetfulldraw(pcw);   //clear UFCdrawplh;                //~v748I~
    }                                                              //~v748I~
	return;                                                        //~v585I~
}//filefreeallplhdata                                              //~v585I~
//**************************************************************** //~v9@5I~
//!fileresetundoable                                               //~v9@5R~
//*free all undo data                                              //~v9@5I~
//*parm1:PUFILEH                                                   //~v9@5I~
//*void                                                            //~v9@5I~
//**************************************************************** //~v9@5I~
void fileresetundoable(int Popt,PUFILEH Ppfh)                      //~v9@5R~
{                                                                  //~v9@5I~
//******************                                               //~v9@5I~
	undofreeuuh(Ppfh);			//free all data                    //~v9@5I~
  	UCBITON(Ppfh->UFHflag6,UFHF6NOUNDO);  //skip save undo data for performance//~v9@5R~
    if (Popt & FSUO_CLEARLCMD)                                     //~v9@8I~
		undoclearplcmdall(0,Ppfh);   //clear all lcmd              //~v9@8I~
	return;                                                        //~v9@5I~
}//fileresetundoable                                               //~v9@5R~
//****************************************************************    //~v06yM~
//!fileregist                                                      //~v0ctR~
//*file clientwe and set field def                                    //~v06yM~
//*parm1:pcw                                                       //~v0d5R~
//*parm2:panel id                                                  //~v0d5I~
//*parm3:pfh                                                       //~v0d5R~
//*parm4:editso sw                                                 //~v0d5I~
//*rc   :pcw or 0 if storage shortage                                 //~v06yM~
//****************************************************************    //~v06yM~
PUCLIENTWE fileregist(PUCLIENTWE Ppcw,int Ppanelid,PUFILEH Ppfh,int Peditsosw)//~v0d5R~
{                                                                     //~v06yM~
	PUFILEC pfc;                                                      //~v06yM~
	PULINEH plh,plhe;                                              //~v62xR~
	PUCLIENTWE pcw;                                                   //~v06yM~
	PUPANELC ppc;                                                     //~v06yM~
    UCHAR    *scrollid;                                               //~v06yM~
//    long actlineno;                                              //~v173R~
//    int digitno;                                                 //~v173R~
//    ULONG    lineoffs;                                           //~v173R~
    int linenosz;                                                  //~v173I~
    long iline;                                                    //~v62xI~
//*******************                                                 //~v06yM~
//*UFILEC init                                                        //~v06yM~
	pfc=UALLOCC(1,UFILECSZ);                                          //~v06yM~
    UALLOCCHK(pfc,0);   //return 0 if storage shortage                //~v06yM~
    memcpy(pfc->UFCcbid,UFCCBID,4);     //set acronym                 //~v06yM~
	if (Ppanelid==PANFBROWSE)                                         //~v06yM~
		pfc->UFCflag=UFCFBROWSE;			//browse                  //~v06yM~
	pfc->UFCpfh=Ppfh;                                                 //~v06yM~
	if (UCBITCHK(Ppfh->UFHflag6,UFHF6VHEXPARM))  //virtical hex display parm specified//~v60vI~
    {                                                              //~v60vI~
		UCBITOFF(Ppfh->UFHflag6,UFHF6VHEXPARM);  //virtical hex display parm specified//~v60vI~
		UCBITON(pfc->UFCflag2,UFCF2VHEX); //virtical hex display mode//~v60vR~
    }                                                              //~v60vI~
//  pfc->UFCcurtop=UGETQTOP(&Ppfh->UFHlineque);                    //~v62xR~
    plh=UGETQTOP(&Ppfh->UFHlineque);                               //~v62xI~
    plhe=UGETQEND(&Ppfh->UFHlineque);                              //~v62xI~
    for (iline=Ppfh->UFHiline;iline>0 && plh!=plhe;iline--)        //~v62xR~
    	plh=UGETQNEXT(plh);                                        //~v62xI~
    if (plh==plhe)                                                 //~v62xR~
		plh=UGETQPREV(UGETQEND(&Ppfh->UFHlineque));                //~v62xI~
	pfc->UFCcurtop=plh;                                            //~v62xI~
	if (!(ppc=pangetpc(Ppanelid)))                                    //~v06yM~
    {                                                                 //~v06yM~
    	ufree(pfc);                                                   //~v06yM~
    	return 0;  		//storage shortage                            //~v06yM~
    }                                                                 //~v06yM~
	pcw=scrregist(UCWTFILE,ppc);//display width;                      //~v06yM~
    if (!pcw)    //return 0 if storage shortage                       //~v06yM~
    {                                                                 //~v06yM~
    	ufree(pfc);                                                   //~v06yM~
        panfreepc(ppc);                                               //~v06yM~
    	return 0;  		//storage shortage                            //~v06yM~
    }                                                                 //~v06yM~
	pcw->UCWpfc=pfc;                                                  //~v06yM~
	pfc->UFCpcw=pcw;            //for view cmd                        //~v06yM~
  if (Peditsosw)                                                   //~v0d5R~
  {                                                                   //~v06yM~
    pcw->UCWmenuopt=PANMOCMD;	//for filesetscrollsz,dcmd_system     //~v06yM~
    pcw->UCWlinenosz=Glinenoszc;                                      //~v06yM~
  }                                                                   //~v06yM~
  else	                                                              //~v06yM~
// if (Ppfh->UFHtype==UFHTKFI)	//ke func ini file                 //~v0ifR~
//  	pcw->UCWlinenosz=ULHLINENOSZ;	//full 8 char              //~v0ifR~
// else                                                            //~v0ifR~
	if (Ppanelid==PANFBROWSE)                                         //~v06yM~
    	pcw->UCWlinenosz=Glinenoszb;                                  //~v06yM~
	else                                                              //~v06yM~
    	pcw->UCWlinenosz=Glinenosze;                                  //~v06yM~
//shift by actual lineno                                           //~v09gI~
	if (pcw->UCWlinenosz)                                          //~v09gI~
    {                                                              //~v09gI~
//      if (UCBITCHK(Ppfh->UFHflag2,UFHF2SPFNUMOK)                 //~v173R~
//      && Ppfh->UFHlrecl==STDSPFLRECL)                            //~v173R~
//        pcw->UCWlinenosz=SPFLINENOSZ;                            //~v173R~
//      else                                                       //~v173R~
//      {                                                          //~v173R~
//       if (UCBITCHK(Ppfh->UFHflag4,UFHF4XLINENO))                //~v173R~
//       {                                                         //~v173R~
//            for (lineoffs=Ppfh->UFHsize,digitno=0;lineoffs;digitno++)//~v173R~
//                lineoffs>>=4;                                    //~v173R~
//            digitno=(((digitno+1)>>1)<<1);  //evenno             //~v173R~
//            digitno++;                      //delm               //~v173R~
//            if (digitno>=ULHLINENOSZ)                            //~v173R~
//                digitno=ULHLINENOSZ-1;  //max 7                  //~v173R~
//            if (digitno>pcw->UCWlinenosz)                        //~v173R~
//                pcw->UCWlinenosz=(char)digitno;                  //~v173R~
//       }//hex offset lineno                                      //~v173R~
//       else                                                      //~v173R~
//       {                                                         //~v173R~
////      actlineno=UGETQCTR(&Ppfh->UFHlineque+Ppfh->UFHsline);    //~v173R~
//        actlineno=UGETQCTR(&Ppfh->UFHlineque)+Ppfh->UFHsline;    //~v173R~
//        if (actlineno)                                           //~v173R~
//        {                                                        //~v173R~
//            for (digitno=1;actlineno;digitno++)                  //~v173R~
//                actlineno/=10;                                   //~v173R~
//            if (digitno>pcw->UCWlinenosz)                        //~v173R~
//                pcw->UCWlinenosz=(char)digitno;                  //~v173R~
//        }                                                        //~v173R~
//       }//normal lineno                                          //~v173R~
//      }//spf or else                                             //~v173R~
        linenosz=filecalclinenosz(Ppfh);                           //~v173I~
        if (linenosz>(int)pcw->UCWlinenosz)                        //~v173R~
            pcw->UCWlinenosz=(char)linenosz;                       //~v173I~
	}                                                              //~v09gI~
                                                                   //~v09gI~
	filewakeup(pcw);			//init USCRD                          //~v06yM~
	csrhomepos(0);			//move csr to 1st fld of current active   //~v06yM~
//scroll default opt                                                  //~v06yM~
  if (Peditsosw)                                                   //~v0d5R~
	scrollid=filegetscrollid(Ginitscroll[GSCROLLCMD]);	//page        //~v06yM~
  else                                                                //~v06yM~
  if (Ppfh->UFHtype==UFHTKFI)	//ke func ini file                 //~v71vI~
    scrollid=filegetscrollid(Ginitscroll[GSCROLLFKT]);	//for =0.1/2/3 common//~v71vI~
  else                                                             //~v71vI~
	if (UCBITCHK(pfc->UFCflag,UFCFBROWSE))			//browse          //~v06yM~
		scrollid=filegetscrollid(Ginitscroll[GSCROLLBROWSE]);	//page//~v06yM~
	else                                                              //~v06yM~
// 	  if (Ppfh->UFHtype==UFHTKFI)	//ke func ini file             //~v71vR~
//  	scrollid=filegetscrollid(UPCSCROLLPAGE);	//unconditionaly page//~v71vR~
//    else                                                         //~v71vR~
		scrollid=filegetscrollid(Ginitscroll[GSCROLLEDIT]);	//default half//~v06yM~
	filesetscrollsz(pcw,scrollid);                                    //~v06yM~
                                                                   //~v41oI~
	fileinitialleft(pfc,Ppfh);       //cobol initial fcleft        //~v41oR~
                                                                   //~v20yI~
//  pan300stack(pcw,Ppfh); //stack filename for filelist on menu 1/2//~v61cR~
    pan300stack(pcw,Ppfh,Ppcw); //stack filename for filelist on menu 1/2//~v61cR~
	fcmdinitialcols(pcw,pfc,Ppfh);       //cols on initial option process//~v74yR~
	return pcw;                                                       //~v06yM~
}//fileregist                                                         //~v06yM~
                                                                      //~v06yM~
//**************************************************************** //~v173I~
// filecalclinenosz                                                //~v173I~
//*calc linenosz by filesize/lineno                                //~v173I~
//*parm1:pfh                                                       //~v173I~
//*rc   :0 or new lineno                                           //~v173I~
//**************************************************************** //~v173I~
int filecalclinenosz(PUFILEH Ppfh)                                 //~v173I~
{                                                                  //~v173I~
    long    actlineno;                                             //~v173I~
    int 	digitno,linenosz=0;                                    //~v173I~
//  ULONG   lineoffs;                                              //~v731R~
    FILESZT lineoffs;                                              //~v731I~
//**********************                                           //~v173I~
    if (UCBITCHK(Ppfh->UFHflag2,UFHF2SPFNUMOK)                     //~v173I~
    && Ppfh->UFHlrecl==STDSPFLRECL)                                //~v173I~
    {                                                              //~v41mI~
      if (UCBITCHK(Ppfh->UFHflag5,UFHF5COB))                       //~v41mI~
      {                                                            //~v42zI~
  		actlineno=((PULINEH)UGETQEND(&Ppfh->UFHlineque))->ULHlinenor;//~v42zI~
        if (actlineno<=1000)  //last hdrline is 1000               //~v42zR~
          linenosz=SPFCOBNUMFLDLEN; //5+|  cobol num fld len for small file//~v42zI~
        else                                                       //~v42zI~
        linenosz=SPFCOBNUMFLDLEN+1; //6+|  cobol num fld len       //~v41nR~
      }                                                            //~v42zI~
      else                                                         //~v41mI~
        linenosz=SPFLINENOSZ;                                      //~v173I~
    }                                                              //~v41mI~
    else                                                           //~v173I~
    {                                                              //~v173I~
       if (UCBITCHK(Ppfh->UFHflag4,UFHF4XLINENO))                  //~v173I~
       {                                                           //~v173I~
      		for (lineoffs=Ppfh->UFHsize,digitno=0;lineoffs;digitno++)//~v173I~
            	lineoffs>>=4;                                      //~v173I~
            digitno=(int)((((UINT)(digitno+1))>>1)<<1);	//evenno   //~v47vR~
            digitno++;                      //delm                 //~v173I~
//          if (digitno>=ULHLINENOSZ)                              //~v58mR~
//          	digitno=ULHLINENOSZ-1;	//max 7                    //~v58mR~
            if (digitno>ULHLINENOSZ)                               //~v58mI~
            	digitno=ULHLINENOSZ;	//max 8 with delm          //~v58mI~
        	linenosz=digitno;                                      //~v173I~
       }//hex offset lineno                                        //~v173I~
       else                                                        //~v173I~
       {                                                           //~v173I~
//      	actlineno=UGETQCTR(&Ppfh->UFHlineque)+Ppfh->UFHsline;  //~v41nR~
  			actlineno=((PULINEH)UGETQEND(&Ppfh->UFHlineque))->ULHlinenor;//~v41nR~
        	if (actlineno)                                         //~v173I~
        	{                                                      //~v173I~
            	for (digitno=1;actlineno;digitno++)                //~v173I~
                	actlineno/=10;                                 //~v173I~
    	        if (digitno>ULHLINENOSZ)                           //~v58mR~
        	    	digitno=ULHLINENOSZ;	//max 8 with delm      //~v58mR~
        		linenosz=digitno;                                  //~v173I~
			}                                                      //~v173I~
       }//normal lineno                                            //~v173I~
	}//spf or else                                                 //~v173I~
    return linenosz;                                               //~v173I~
}//filecalclinenosz                                                //~v173I~
//**************************************************************** //~v41oI~
// fileinitialleft                                                 //~v41oI~
//*set UFCleft initial value                                       //~v41oI~
//*parm1:pfc                                                       //~v41oI~
//*parm2:pfh                                                       //~v41oI~
//*rc   :0:Ufcleft not set,1:UFCleft set                           //~v41oI~
//**************************************************************** //~v41oI~
int fileinitialleft(PUFILEC Ppfc,PUFILEH Ppfh)                     //~v41oI~
{                                                                  //~v41oI~
    int 	rc=0;                                                  //~v41oI~
//**********************                                           //~v41oI~
    if (!UCBITCHK(Ppfc->UFCflag,UFCFBROWSE))                       //~v41oR~
    {                                                              //~v553I~
      if (UCBITCHK(Ppfh->UFHflag5,UFHF5COB2)  	//cobk(col.1-6 is not seqno)//~v47vI~
      && UCBITCHK(Ppfh->UFHflag5,UFHF5NOAUTONUM))  //col.72-80 is not seqno.//~v47vI~
        {                                                          //~v47vI~
            Ppfc->UFCleft=SPFCOBNUMFLDLEN; //6 cobol num fld len   //~v47vI~
            rc=1;                                                  //~v47vI~
        }                                                          //~v47vI~
      else                                                         //~v47vI~
        if (UCBITCHK(Ppfh->UFHflag2,UFHF2SPFNUMOK)                 //~v41oR~
        && Ppfh->UFHlrecl==STDSPFLRECL)                            //~v41oR~
            if (UCBITCHK(Ppfh->UFHflag5,UFHF5COB))                 //~v41oR~
            {                                                      //~v41oR~
              Ppfc->UFCleft=SPFCOBNUMFLDLEN; //6 cobol num fld len //~v41oR~
                rc=1;                                              //~v41oR~
            }                                                      //~v41oR~
    }//not browse                                                  //~v553I~
    return rc;                                                     //~v41oI~
}//filecalclinenosz                                                //~v41oI~
//**************************************************************** //~v0fsI~
// filefnquate                                                     //~v0fsI~
//*filename quatation drop and set both edge                       //~v0fsI~
//*parm1:filename string                                           //~v0fsR~
//*rc   :0 no quatation,1:quatation reset                          //~v0fsI~
//**************************************************************** //~v0fsI~
int filefnquate(char *Pfnm)                                        //~v0fsR~
{                                                                  //~v0fsI~
    UCHAR wkfnm[_MAX_PATH];                                        //~v0fsI~
    UCHAR *pc;                                                     //~v0fsR~
    int pos,len;                                                   //~v0fsI~
	int rc;                                                        //~v0fsI~
//*********************************                                //~v0fsI~
	pc=Pfnm;                                                       //~v0fsR~
  	if (!pc)                                                       //~v0fsI~
    	return 0;                                                  //~v0fsI~
//	rc=uparsefname(1,pc,wkfnm,&pos,&len);//cut operand             //~vb79R~
  	rc=uparsefname(1,pc,wkfnm,&pos,(int)sizeof(wkfnm),&len);//cut operand//~vb79I~
    if (rc!=4)		//no quatation detected                        //~v0fsI~
    	return 0;                                                  //~v0fsI~
    *pc++='"';                                                     //~v0fsI~
    memcpy(pc,wkfnm,(UINT)len);                                    //~v0fsI~
    pc+=len;                                                       //~v0fsI~
    *pc++='"';                                                     //~v0fsI~
    len=pos-(len+2);                                               //~v0fsI~
    if (len>0)                                                     //~v0fsI~
    	memset(pc,' ',(UINT)len);                                  //~v0fsR~
	return 1;		//quatation detecte                            //~v0fsI~
}//filefnquate                                                     //~v0fsI~
                                                                   //~v0fsI~
//**************************************************************** //~v09YI~
//!filelinemallocerr                                               //~v0ctR~
//*malloc failed at line create                                    //~v09YI~
//*parm1:line no                                                   //~v09YI~
//*rc   :UALLOC_FAILED                                             //~v09YI~
//**************************************************************** //~v09YI~
int filelinemallocerr(long Plineno)                                //~v09YI~
{                                                                  //~v09YI~
//*******************                                              //~v09YI~
	uerrmsg("Storage shortage at line %ld",                        //~v09YI~
			"%ld 行目で記憶域不足",                                //~v09YI~
			Plineno);                                              //~v09YI~
	return UALLOC_FAILED;                                          //~v09YI~
}//filelinemallocerr                                               //~v09YI~
